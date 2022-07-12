modify CMakeLists.txt
1. add boost library path
2. add new Files IntentHellper.cpp, Type.cpp

```
diff --git a/CMakeLists.txt b/CMakeLists.txt
index 1584640..f2643f6 100644
--- a/CMakeLists.txt
+++ b/CMakeLists.txt
@@ -27,8 +27,10 @@ if (NOT WIN32)
 endif ()
 
 find_package (BISON REQUIRED)
+find_package (Boost REQUIRED)
+
 bison_target (for90 src/grammar/for90.y ${CMAKE_CURRENT_BINARY_DIR}/for90.cpp)
-include_directories (${CMAKE_SOURCE_DIR}/src/grammar/)
+include_directories (${CMAKE_SOURCE_DIR}/src/grammar/ /usr/local/include/)
 
 set (CPPS
   src/main.cpp  
@@ -42,9 +44,11 @@ set (CPPS
   src/grammar/simple_lexer.cpp  
   src/parser/attribute.cpp  
   src/parser/Function.cpp  
-  src/parser/Intent.cpp  
-  src/parser/parser.cpp  
-  src/parser/scanner.cpp  
+  src/parser/Intent.cpp
+  src/parser/IntentHelper.cpp
+  src/parser/Type.cpp
+  src/parser/parser.cpp
+  src/parser/scanner.cpp
   src/parser/tokenizer.cpp  
   src/parser/Variable.cpp  
   src/target/gen_common.cpp  
```
******

modify src/getopt2.cpp to fix problem:goto crossing variable initialization
```
diff --git a/src/getopt2.cpp b/src/getopt2.cpp
index b8956f9..ddc848a 100755
--- a/src/getopt2.cpp
+++ b/src/getopt2.cpp
@@ -90,12 +90,13 @@ int _getopt_impl(int argc, char * const argv[], const char * optstring, const st
 			return false;
 		}
 	};
+    bool is_option_field;
 	if (!cached_ops.empty()) {
 		optname = cached_ops.front();
 		cached_ops.pop();
 		goto HANDLE_CACHED;
 	}
-	bool is_option_field = test_option(argv[optind]);
+	is_option_field = test_option(argv[optind]);
 	if ((!is_option_field) || argv[optind][1] == '\0') {
 		// begin with no dash or only a single dash
 		// ERROR finish processing
```


modify src/target/gen_exp.cpp
```
121c121
<       for each (ParseNode * var in exp.child)
---
>       for (ParseNode * var : exp.child)
```

comment out line 22-26 in src/parser/Intent.cpp
```
/*
std::string get_intent_name(TokenMeta_T intent_id) {
	return TokenMeta::get_enum_table().from_value(intent_id);
}
*/
```

delete line 41 in src/target/gen_config.h
```
       , { "null()", "null" }
```

append after line 100 in src/target/gen_exp.cpp
```
    else if (exp.token_equals(TokenMeta::PNULL))
    {
        exp.get_what() = "NULL";
    }
```

******
*Defect: the first line ending with '&' should not be preceeded by blank. The second line after, if beginning with '&', should not followed immediately by any blank*
'&' continuation, modify src/grammer/simple_lexer.cpp
1. add an `if` condition before original `if (new_line_p + FORTRAN_CONTINUATION_SPACE < s.size())` in line 84, the old `if` condition should become `else if`
2. in function `static char get_complete_char()`, add a condition when `s[p]` is '&', right before the last `else` condition
> Notice, the following is output by command `git diff src/grammar/simple_lexer.cpp`, `@@ -84,7 +84,19 @@ static bool check_continuation(char & return_char) {` means
> in function `static bool check_continuation(char & return_char)` and content in old file from line 84 to line 84+7(denoted by -84,7) was changed to that in new file from line 84 to line 84+19(denoted by +84,19).
```
diff --git a/src/grammar/simple_lexer.cpp b/src/grammar/simple_lexer.cpp
index 9d585f3..7df6ef2 100755
--- a/src/grammar/simple_lexer.cpp
+++ b/src/grammar/simple_lexer.cpp
@@ -84,7 +84,19 @@ static bool check_continuation(char & return_char) {
 	int new_line_p = p + 1;
 	int continuation_symbol_p = -1;
 	bool valid_continuation = false;
-	if (new_line_p + FORTRAN_CONTINUATION_SPACE < s.size())
+    if(s[p-1] == '&')
+    {
+        while(s[new_line_p++]==' ');
+        continuation_symbol_p = new_line_p - 1;
+        if(s[continuation_symbol_p] == '&'){
+            p = new_line_p;
+        }else{
+            p = continuation_symbol_p;
+        }
+        return_char = s[p++];
+        return true;
+    }
+    else if (new_line_p + FORTRAN_CONTINUATION_SPACE < s.size())
 	{
 		// begin with 5 blanks(or numbers which are label, although useless)
 		bool valid_label = std::accumulate(s.begin() + new_line_p, s.begin() + new_line_p + FORTRAN_CONTINUATION_SPACE, true, [](bool r, char y) {
@@ -220,6 +232,10 @@ static char get_complete_char() {
 		return_char = s[p++];
 		sc.newline_marker = false;
 	}
+    else if (s[p] == '&' && (s[p+1] == '\n' || s[p+1] == '\r')){
+        p++;
+        goto BEGINNING;
+    }
 	else {
 		if (!sc.in_format_stmt)
 		{
```