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

