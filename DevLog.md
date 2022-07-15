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
******

implement `character(256)`and `character*(256)`

> By Li Xiaoxun

add rule to `type_spec`

```
type_spec: type_name '(' type_selector ')'
{
// now translated in pre_map
$$ = RETURN_NT(gen_type(YY2ARG($1),YY2ARG($3)));
update_pos(YY2ARG($$),YY2ARG($1),YY2ARG($4));
CLEAN_DELETE($1,$2,$3,$4);
}
| type_name '*' '(' type_selector ')'
{
// now translated in pre_map
$$ = RETURN_NT(gen_type(YY2ARG($1),YY2ARG($4)));
update_pos(YY2ARG($$),YY2ARG($1),YY2ARG($5));
CLEAN_DELETE($1,$2,$3,$4,$5);
}
```

add rule to `type_selector`

```
		| exp
			{
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				ARG_OUT integer = YY2ARG($1);
				sscanf(integer.get_what().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
			}
```

******
7.12 17:00
implement `data a\1,2\`

1. add a rule for `let_stmt`

```yacas
		| YY_DATA argtable '\\' argtable '\\'
		    {
				ARG_OUT exp1 = YY2ARG($2);
				ARG_OUT exp2 = YY2ARG($4);
				bool initialized = false;
				ParseNode newGroup;
				for(int i = 0; i < exp2.length(); i++)
				{
				    ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
				    ParseNode lelem;
				    if(exp1.length() == exp2.length())
				    {
				        lelem = exp1.get(i);
				    }
				    else
				    {
				        lelem = exp1;
				        lelem.get_what().append("[").append(std::to_string(i)).append("]");
				    }

				    ParseNode newToken = gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, lelem, exp2.get(i), opnew);
				    if(initialized)
				    {
				        ParseNode link = gen_token(Term{ TokenMeta::Let, "%s;%s" });
				        newGroup = gen_promote(link.get_what(), TokenMeta::NT_EXPRESSION, newGroup, newToken, link);
				    }else
				    {
				        newGroup = newToken;
				        initialized = true;
				    }
				}
				$$ = RETURN_NT(newGroup);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
				CLEAN_DELETE($1, $2, $3, $4, $5);
		    }
```

2.  file `gen_exp.cpp`, in function `regen_exp()`, right before the last `else` condition

   ```cpp
   	else {
   		print_error("error exp: ", exp);
   	}
   ```

   Add an `else if`condition

   ```cpp
       else if (exp.token_equals(TokenMeta::NT_ARGTABLE_PURE))
       {
       }
   ```

3. *TODO*

   - when  change rule to  `		| YY_DATA argtable '\\' argtable '\\'`, report error

     ```
     Error : syntax error, unexpected YY_CRLF
     (line 4:0, index = 24, len = 1), current token is CRLF(id = -1000) : "
     ```
   - element in `/ /` can not be array, e.g., `data a,b,c/1,2,(1,2,3)/` is not supported



```

/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
struct car
{
	double speed = 0.0;
};

int main()
{
	double car = 0.0;
	car car1 = car(INOUT(1.0));
	return 0;
}
[NT](NT_WRAPPERS) 
	[NT](NT_PROGRAM_EXPLICIT) 
		[NT](NT_SUITE) 
			[NT]( NT_DERIVED_TYPE )
				[T](META_WORD) car
				[NT](NT_SUITE) 
					[NT](NT_VARIABLEDEFINESET) 
						[NT](NT_VARIABLEDEFINE) 
							[T](Float_Decl) double
							[T](NT_VARIABLEDESC) 
							[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) speed
								[T](UnknownVariant) speed
								[T](NT_VARIABLEINITIALDUMMY) 
					[T](NT_STATEMENT) 
			[NT](NT_VARIABLEDEFINESET) 
				[NT](NT_VARIABLEDEFINE) 
					[T](META_WORD) car
					[T](NT_VARIABLEDESC) 
					[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) car1
						[T](UnknownVariant) car1
						[NT](NT_FUCNTIONARRAY) 
							[T](UnknownVariant) car
							[NT](NT_ARGTABLE_PURE) 1.0
								[T](Float) 1.0
			[T](NT_STATEMENT) 
Process finished with exit code 0
```

******

7.15 `type(car)::car1=car(1.0,4.23)`

No need to change`for90.y`.

Modify file `gen_exp.cpp`, add following code fragment in function `regen_exp()`, right after the `else if `condition: `else if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY))`

```cpp
        // derived type construction
        if (get_type(get_context().current_module, exp.get(0).get_what().c_str()) != nullptr) {
            string array_str = "{";
            array_str.append(exp.get(1).get_what());
            array_str.append("}");
            exp.fs.CurrentTerm = Term{TokenMeta::NT_FUCNTIONARRAY, array_str};
            return;
        }
        // END derived type construction
```

after modification the file should look like

```cpp
...
    } else if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY)) {
        // derived type construction
        if (get_type(get_context().current_module, exp.get(0).get_what().c_str()) != nullptr) {
            string array_str = "{";
            array_str.append(exp.get(1).get_what());
            array_str.append("}");
            exp.fs.CurrentTerm = Term{TokenMeta::NT_FUCNTIONARRAY, array_str};
            return;
        }
        // END derived type construction
        if (exp.get(0).token_equals(TokenMeta::NT_DERIVED_TYPE)/*car%speed(2)*/
            || exp.get(0).token_equals(TokenMeta::UnknownVariant))/*car(2)%speed, car(2)*/ {
            regen_exp(finfo, exp.get(0));
        }
        regen_function_array(finfo, exp);
    } else if (exp.token_equals(TokenMeta::NT_HIDDENDO)) {
        regen_hiddendo_exprex(finfo, exp);
    } else if (exp.token_equals(TokenMeta::Comments)) {

    } else if (exp.token_equals(TokenMeta::NT_ARRAYBUILDER_LIST)) {
        regen_arraybuilder(finfo, exp);
    } else if (exp.token_equals(TokenMeta::NT_DERIVED_TYPE)) {

        parse_inner_variable(finfo, exp);

    } else if (exp.token_equals(TokenMeta::NT_VARIABLEDEFINESET)) {
    } else if (exp.token_equals(TokenMeta::NT_STATEMENT)) {
    } else if (exp.token_equals(TokenMeta::NT_ARGTABLE_PURE)) {
    } else {
        print_error("error exp: ", exp);
    }
}

VariableInfo *get_vinfo(FunctionInfo *finfo, ParseNode &exp) {
...
```

Test case

```fortran
program ex
  type car
    real speed
    real size
  end type car
  type(car)::car1=car(1.0,4.23)
end program
```

output after conversion

```cpp
Cost time:1
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
struct car
{
	double size = 0.0;
	double speed = 0.0;
	
};

int main()
{
	car car1 = {1.0, 4.23};
	
	return 0;
}
[NT](NT_WRAPPERS) /**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
struct car
{
	double size = 0.0;
	double speed = 0.0;
	
};

int main()
{
	car car1 = {1.0, 4.23};
	
	return 0;
}
	[NT](NT_PROGRAM_EXPLICIT) 



		[NT](NT_SUITE) 



			[NT]( NT_DERIVED_TYPE ) 
				[T](META_WORD) car
				[NT](NT_SUITE) 



					[NT](NT_VARIABLEDEFINESET) 
						[NT](NT_VARIABLEDEFINE) 
							[T](Float_Decl) double
							[T](NT_VARIABLEDESC) 
							[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) speed
								[T](UnknownVariant) speed
								[T](NT_VARIABLEINITIALDUMMY) 
					[NT](NT_VARIABLEDEFINESET) 
						[NT](NT_VARIABLEDEFINE) 
							[T](Float_Decl) double
							[T](NT_VARIABLEDESC) 
							[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) size
								[T](UnknownVariant) size
								[T](NT_VARIABLEINITIALDUMMY) 
					[T](NT_STATEMENT) 
			[NT](NT_VARIABLEDEFINESET) 
				[NT](NT_VARIABLEDEFINE) 
					[T](META_WORD) car
					[T](NT_VARIABLEDESC) 
					[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) car1
						[T](UnknownVariant) car1
						[NT](NT_FUCNTIONARRAY) 
							[T](UnknownVariant) car
							[NT](NT_ARGTABLE_PURE) 1.0, 4.23
								[T](Float) 1.0
								[T](Float) 4.23
			[T](NT_STATEMENT) 

Process finished with exit code 0
```

