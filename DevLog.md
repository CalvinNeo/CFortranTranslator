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

Modify file `gen_exp.cpp`, add following code fragment in function `regen_exp()`, right after the `else if `condition: `else if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY))`

```cpp
        // derived type construction, NOTICE: such approach will be exclusive with the original usage, i.e., variable or function followed by `(argtable)`
        if (get_type(get_context().current_module, exp.get(0).get_what().c_str()) != nullptr) {
            string array_str = "{";
            array_str.append(exp.get(1).get_what());
            array_str.append("}");
            exp.fs.CurrentTerm = Term{TokenMeta::NT_FUCNTIONARRAY, array_str};
            return;//immediate return
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

******

**CONTINUE** 7.12 17:00
implement `data a/1,2/`

> grammar of data refer to [DATA](https://docs.oracle.com/cd/E19957-01/805-4939/6j4m0vn85/index.html), the `[[,] nlist / clist /] ...` part in syntax `DATA nlist / clist / [[,] nlist / clist /] ...` is not implemented here.
>
> to be specific about the implementation here:
>
> e.g., data a,b,c /1,2,3/
>
> a,b,c... can be replaced by variable like `a`, array element like `a(0)`, and implied DO lists
>
> 1,2,3 can be replaced by literal or symbolic name of a constant, optionally preceded by a nonzero, unsigned integer literal (usage of symbolic name of such constant is not implemented here, although it is part of the syntax in the doc), which denotes the repetition times of the literal, e.g., `4*5` is equivalent to `5,5,5,5`

1. in `for90.y`, append after rule `let_stmt: ...exp '=' exp`, the old rule `| YY_DATA argtable '\\' argtable '\\'`should be deleted now.

   ```yacc
   		| YY_DATA nlists '/' clists '/'
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
   				        lelem = exp1.get(0);
   				        lelem.get_what().append("(").append("INOUT("+std::to_string(i+1)+")").append(")");
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
       nlists_elem : variable
               {
                   //printf("in nlists_elem:variable\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
           | function_array_body
               {
                   //printf("in nlists_elem:function_array_body\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
           | hidden_do
               {
                   //printf("in nlists_elem:hidden_do\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
   
       // nlists derived from argtable
       nlists : nlists_elem
               {
                   //printf("in nlists:nlists_elem\n");
               	ARG_OUT exp = YY2ARG($1);
               	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
               	$$ = RETURN_NT(newnode);
               	update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               	CLEAN_DELETE($1);
               }
           | nlists ',' nlists_elem
               {
                   //printf("in nlists:nlists, nlists_elem\n");
   				ARG_OUT exp = YY2ARG($3);
   				ARG_OUT argtable = YY2ARG($1);
   #ifdef USE_REUSE
   				ParseNode * newnode = new ParseNode();
   				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
   				$$ = newnode;
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($2);
   				CLEAN_REUSE($1, $3);
   #else
   				$$ = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($1, $2, $3);
   #endif
               }
   
       c_in_clist : literal
               {
                   //printf("in c_in_clist:literal\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
           | YY_WORD
               {
                   //printf("in c_in_clist:YY_WORD\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
       r_in_clist : YY_INTEGER
               {
                   //printf("in r_in_clist:YY_INTEGER\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
   
   
       clists_elem : c_in_clist
               {
                   //printf("in clists_elem:c_in_clist\n");
                   $$ = $1;
                   update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               }
   
       // clists derived from argtable
       clists : clists_elem
               {
                   //printf("in clists:clists_elem\n");
               	ARG_OUT exp = YY2ARG($1);
               	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
               	$$ = RETURN_NT(newnode);
               	update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
               	CLEAN_DELETE($1);
               }
           | clists ',' clists_elem
               {
                   //printf("in clists:clists, clists_elem\n");
   				ARG_OUT exp = YY2ARG($3);
   				ARG_OUT argtable = YY2ARG($1);
   #ifdef USE_REUSE
   				ParseNode * newnode = new ParseNode();
   				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
   				$$ = newnode;
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($2);
   				CLEAN_REUSE($1, $3);
   #else
   				$$ = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($1, $2, $3);
   #endif
               }
           | r_in_clist '*' c_in_clist
               {
                   //printf("in clists:r_in_clist * c_in_clist\n");
   				ARG_OUT r = YY2ARG($1);
   				int times = std::stoi(r.get_what());
   				ARG_OUT c = YY2ARG($3);
   
   				ParseNode * newnode = new ParseNode();
               	*newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , c.get_what()}, c);
   
   #ifdef USE_REUSE
                   for(int i = 1; i < times; i++)
                   {
                     ParseNode * container = new ParseNode();
                     ParseNode *exp = new ParseNode(c);
   				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
   				  newnode = container;
                   }
   				$$ = newnode;
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($2);
   				CLEAN_REUSE($1, $3);
   #else
                   for(int i = 1; i < times; i++)
                   {
                     ParseNode *exp = new ParseNode(c);
   				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                   }
   				$$ = RETURN_NT(newnode);
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   				CLEAN_DELETE($1, $2, $3);
   #endif
               }
           | clists ',' r_in_clist '*' c_in_clist
               {
                   //printf("in clists:clists ',' r_in_clist '*' c_in_clist\n");
   				ARG_OUT argtable = YY2ARG($1);
   				ARG_OUT r = YY2ARG($3);
   				int times = std::stoi(r.get_what());
   				ARG_OUT c = YY2ARG($5);
   
   				ParseNode * newnode = new ParseNode();
   				*newnode = argtable;
   #ifdef USE_REUSE
                   for(int i = 0; i < times; i++)
                   {
                     ParseNode * container = new ParseNode();
                     ParseNode *exp = new ParseNode(c);
   				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
   				  newnode = container;
                   }
   				$$ = newnode;
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
   				CLEAN_DELETE($2, $4);
   				CLEAN_REUSE($1, $3, $5);
   #else
                   for(int i = 0; i < times; i++)
                   {
                     ParseNode *exp = new ParseNode(c);
   				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                   }
   				$$ = RETURN_NT(newnode);
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
   				CLEAN_DELETE($1, $2, $3, $4, $5);
   #endif
               }
   ```

2. in `gen_exp.cpp`, in function `regen_exp()`, right before the last `else` condition( the previous line `else if (exp.token_equals(TokenMeta::NT_ARGTABLE_PURE)){}` is not used and could be deleted now)

   ```cpp
   	else {
   		print_error("error exp: ", exp);
   	}
   ```

   Add an `else if`condition

   ```cpp
       else if (exp.token_equals(TokenMeta::META_WORD))
       {
       }
   ```

3. Test case

   ```fortran
   program ex
     data b/3, 4*8/
   end program
   ```

   output

   ```shell
   "~/CFortranTranslator/cmake-build-debug/CFortranTranslator" -Ff ../demos/2.for --tree
   /**********************************************************************/
   /* File:                                                              */
   /* Author:                                                            */
   /* This codes is generated by CFortranTranslator                      */
   /* CFortranTranslator is published under GPL license                  */
   /* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
   /**********************************************************************/
   #include "../for90std/for90std.h" 
   #define USE_FORARRAY 
   int main()
   {
   	double b(INOUT(1)) = 0.0;
   	double b(INOUT(2)) = 0.0;
   	double b(INOUT(3)) = 0.0;
   	double b(INOUT(4)) = 0.0;
   	double b(INOUT(5)) = 0.0;
   	b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8;
   	
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
   int main()
   {
   	double b(INOUT(1)) = 0.0;
   	double b(INOUT(2)) = 0.0;
   	double b(INOUT(3)) = 0.0;
   	double b(INOUT(4)) = 0.0;
   	double b(INOUT(5)) = 0.0;
   	b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8;
   	
   	return 0;
   }
   	[NT](NT_PROGRAM_EXPLICIT) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8;
   
   
   		[NT](NT_SUITE) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8;
   
   
   			[NT](NT_STATEMENT) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8;
   				[NT](NT_EXPRESSION) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8;b(INOUT(5)) = 8
   					[NT](NT_EXPRESSION) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8;b(INOUT(4)) = 8
   						[NT](NT_EXPRESSION) b(INOUT(1)) = 3;b(INOUT(2)) = 8;b(INOUT(3)) = 8
   							[NT](NT_EXPRESSION) b(INOUT(1)) = 3;b(INOUT(2)) = 8
   								[NT](NT_EXPRESSION) b(INOUT(1)) = 3
   									[T](UnknownVariant) b(INOUT(1))
   									[T](META_INTEGER or Int) 3
   									[T](Let) %s = %s
   								[NT](NT_EXPRESSION) b(INOUT(2)) = 8
   									[T](UnknownVariant) b(INOUT(2))
   									[T](META_INTEGER or Int) 8
   									[T](Let) %s = %s
   								[T](Let) %s;%s
   							[NT](NT_EXPRESSION) b(INOUT(3)) = 8
   								[T](UnknownVariant) b(INOUT(3))
   								[T](META_INTEGER or Int) 8
   								[T](Let) %s = %s
   							[T](Let) %s;%s
   						[NT](NT_EXPRESSION) b(INOUT(4)) = 8
   							[T](UnknownVariant) b(INOUT(4))
   							[T](META_INTEGER or Int) 8
   							[T](Let) %s = %s
   						[T](Let) %s;%s
   					[NT](NT_EXPRESSION) b(INOUT(5)) = 8
   						[T](UnknownVariant) b(INOUT(5))
   						[T](META_INTEGER or Int) 8
   						[T](Let) %s = %s
   					[T](Let) %s;%s
   			[T](NT_STATEMENT) 
   Cost time:1
   
   Process finished with exit code 0
   
   ```

   ********

   remove unnecessary implicit variable check

   change `gen_exp.cpp`

   ```shell
   diff --git a/src/target/gen_exp.cpp b/src/target/gen_exp.cpp
   index e87f7bb..822f648 100755
   --- a/src/target/gen_exp.cpp
   +++ b/src/target/gen_exp.cpp
   @@ -68,7 +68,7 @@ void regen_exp(FunctionInfo *finfo, ParseNode &exp) {
            }
            // END derived type construction
            if (exp.get(0).token_equals(TokenMeta::NT_DERIVED_TYPE)/*car%speed(2)*/
   -            || exp.get(0).token_equals(TokenMeta::UnknownVariant))/*car(2)%speed, car(2)*/ {
   +            || (exp.get(0).token_equals(TokenMeta::UnknownVariant) && exp.father->token_equals(TokenMeta::NT_DERIVED_TYPE)))/*car(2)%speed, ~~car(2)~~*/ {
                regen_exp(finfo, exp.get(0));
            }
            regen_function_array(finfo, exp);
   
   ```

   the `if` condition was added when implementing `inner-variable` with array, but the condition`exp.get(0).token_equals(TokenMeta::UnknownVariant))`will affect all `function_array_body`, but we want only `car(2)%speed` to be affected, so here we add another condition `exp.father->token_equals(TokenMeta::NT_DERIVED_TYPE)` so that a function call like `xx(b)` will not enter `regen_exp(finfo, exp.get(0));` in the `if` body.

******

7.18, reserve traversing order when generating type definition codes

change `gen_program.cpp`, in function`gen_fortran_program()`

```shell
diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
index f80c4c8..dfceb05 100755
--- a/src/target/gen_program.cpp
+++ b/src/target/gen_program.cpp
@@ -136,20 +136,11 @@ void gen_fortran_program(const ParseNode & wrappers) {
 		//}
 	}
 
-	for (std::pair<std::string, TypeInfo *> pair : get_context().types)
+	for (TypeInfo * tinfo : get_context().types_vec)
 	{
-		ParseNode& wrapper = *pair.second->node;
-		if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
-		{
-			ParseNode& variable_type = wrapper.get(0);
-			//ParseNode& suite = wrapper.get(1);
-			TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
 			regen_derived_type_2(tinfo);
 			codes += tinfo->node->get_what();
-			//codes += "struct " + variable_type.get_what() + "\n";
-			//codes += suite.get_what();
 			codes += "\n";
-		}
 	}
 
 	// main program code
```

change `add_type()`, in file `Type.cpp`

```shell
diff --git a/src/parser/Type.cpp b/src/parser/Type.cpp
index 1f08799..5f5ff4b 100755
--- a/src/parser/Type.cpp
+++ b/src/parser/Type.cpp
@@ -27,6 +27,7 @@ TypeInfo * add_type(std::string module_name, std::string type_name, const TypeIn
 	}
 	else {
 		get_context().types[fullname] = tinfo;
+        get_context().types_vec.push_back(tinfo);
 	}
 	tinfo->local_name = type_name;
 	return tinfo;
```

change `TranslateContext` definition in `context.h`

```shell
diff --git a/src/parser/context.h b/src/parser/context.h
index e03544a..3f4068c 100755
--- a/src/parser/context.h
+++ b/src/parser/context.h
@@ -30,6 +30,7 @@ struct TranslateContext {
 	std::map < std::string, VariableInfo * > variables;
 	std::map < std::string, FunctionInfo * > functions;
 	std::map < std::string, TypeInfo* > types;
+    std::vector <TypeInfo* > types_vec;
 	std::map<std::string, std::vector<KeywordParamInfo>> func_kwargs;
 	ParseNode program_tree;
 	std::string global_code;
```



Rationale: 

After modification, the for loop will traverse the elements of `get_context().types_vec` in the order they were added. Because of the implementation of `add_type()` (in file `src/parser/Type.cpp` line 20), the map `get_context().types` is filled but the adding order does not persist. For that reason, we need to define a vector variable to keep that order of calling `add_type()`, so traversing this new vector will promise the same order.

Test Case

```fortran
type apple
end type apple
type car
end type car
program ex
end program
```

output

```shell

/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
struct apple
{
	
};

struct car
{
	
};

int main()
{
	
	return 0;
}

Cost time:0

Process finished with exit code 0
```

******

7.21 open conversion

Test case

```fortran
program main
  open(unit=10, file="hello.txt")
  write(10,*)"xx"
end program
```

Because the argument able for `open()` does not contain any normal argument, so the normal argument list would be empty, this line in  function `regen_function_array()`

```cpp
		argtable_str += make_str_list(normal_args.begin(), normal_args.end(), [&](string p) {...}
```

would result in an empty string. In that case, the remaining part should not start with a tailing `", "` which is only necessary when there is something non-empty being preceding. For that reason, the assignment of variable `string tail` should be conditional by the emptiness of string `argtable_str`.

Modification:

in file `gen_callable.cpp`

```sh
diff --git a/src/target/gen_callable.cpp b/src/target/gen_callable.cpp
index a03438a..6f967ae 100755
--- a/src/target/gen_callable.cpp
+++ b/src/target/gen_callable.cpp
@@ -155,7 +155,7 @@ void regen_function_array(FunctionInfo * finfo, ParseNode & callable) {
 		*	if exist kwargs, must add `,` delimer between arguments
 		*	if not exist, mustn't add `,`, use `)` enclose whole argument list directly
 		***************/
-		string tail = ", ";
+		string tail = argtable_str.empty()?"":", ";
 		// generated code of kwargs
 		if (map_func != get_context().func_kwargs.end()) {
 			std::vector<KeywordParamInfo> & params = map_func->second;
```

> By Zhang Wenqi

in file `gen_config.h`, correct the typo error, line 96, column 152-158, from `_WS("unkonwn")` to `_WS("unknown")`

in file `forfilesys.cpp`, change the `doreplace` option to true for `new` and `unknown` status.

```sh
diff --git a/for90std/forfilesys.cpp b/for90std/forfilesys.cpp
index 5c5c05c..e6d9d2c 100644
--- a/for90std/forfilesys.cpp
+++ b/for90std/forfilesys.cpp
@@ -112,7 +112,7 @@ void foropenfile(int unit, foroptional<int> iostat, foroptional<forlabel> err, f
 	transform(s.begin(), s.end(), s.begin(), to_lower);
 	if (s == "new") {
 		docreate = true;
-		doreplace = false;
+		doreplace = true;
 	}else if(s == "replace"){
 		docreate = true;
 		doreplace = true;
@@ -128,7 +128,7 @@ void foropenfile(int unit, foroptional<int> iostat, foroptional<forlabel> err, f
 	else {
 		// unknown
 		docreate = true;
-		doreplace = false;
+		doreplace = true;
 	}
 
 	s = action.value_or("readwrite");
```



Output after modification

```sh
Cost time:0
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
int main()
{
	foropenfile(10, None, None, SS("hello.txt"), SS("unkonwn"), SS("sequential"), None, None, None, SS("rewind"), SS("readwrite"), None, None);
	forwritefree(get_file(10), SS("xx"));
	
	
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
int main()
{
	foropenfile(10, None, None, SS("hello.txt"), SS("unkonwn"), SS("sequential"), None, None, None, SS("rewind"), SS("readwrite"), None, None);
	forwritefree(get_file(10), SS("xx"));
	
	
	return 0;
}
	[NT](NT_PROGRAM_EXPLICIT) ;



		[NT](NT_SUITE) ;



			[NT](NT_STATEMENT) ;
				[NT](NT_FUCNTIONARRAY) 
					[T](UnknownVariant) open
					[NT](NT_PARAMTABLE_PURE) unit, file
						[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) unit
							[T](UnknownVariant) unit
							[T](META_INTEGER or Int) 10
						[NT](NT_VARIABLE_ENTITY or NT_KEYVALUE) file
							[T](UnknownVariant) file
							[T](META_STRING or String) "hello.txt"
			[NT](NT_WRITE_STMT) 
				[NT](META_NONTERMINAL) 
					[T](META_ANY) 10
					[T](NT_AUTOFORMATTER) 
				[NT](NT_ARGTABLE_PURE) "xx"
					[T](META_STRING or String) "xx"
			[T](NT_STATEMENT) 
	[NT](NT_SUITE) 

		[T](NT_STATEMENT) 

Process finished with exit code 0

```

- [x] Compile && Run

```sh
▶ touch hello.txt
▶ g++ ../for90std/* main.cpp -Wall -DPOSIX -g -O3 -fpermissive -fPIC -std=c++17 -v
▶ ./a.out
▶ cat hello.txt                                                                       
xx

```

******
real,dimension a = 1.0
> By Zhang Wenqi

- [ ] TODO

  Add after review...



******
```fortran
  implicit real(kind=8) (a-z)
```

1. Add rules in `src/grammar/for90.y`, behind `implicit_stmt : YY_IMPLICIT YY_NONE{...}| YY_IMPLICIT type_name '(' paramtable ')'{...}`

   ```
   		| YY_IMPLICIT type_spec '(' paramtable ')'
   			{
   				// dummy stmt
   				ParseNode & type_name = YY2ARG($2);
   				ParseNode & paramtable = YY2ARG($4);
   				ParseNode newnode = gen_token(Term{ TokenMeta::ConfigImplicit, "" }, type_name, paramtable);
   				$$ = RETURN_NT(newnode);
   				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
   				CLEAN_DELETE($1, $2, $3, $4, $5);
   			}
   ```

2. modify `gen_stmt.cpp` to generate complete `type_decl`

   ```cpp
   diff --git a/src/target/gen_stmt.cpp b/src/target/gen_stmt.cpp
   index 1fbcc23..e5beb43 100755
   --- a/src/target/gen_stmt.cpp
   +++ b/src/target/gen_stmt.cpp
   @@ -332,6 +332,11 @@ std::string regen_stmt(FunctionInfo * finfo, ParseNode & stmt) {
    	else if (stmt.token_equals(TokenMeta::ConfigImplicit))
    	{
    		ParseNode & type_decl = stmt.get(0);
   +        type_decl.get_token() += 100; /* from type decl to type */
   +        promote_type(type_decl,get_variabledesc_attr(type_decl));
   +        type_decl.get_token() -= 100; /* from type to type decl */
   +
   +
    		ParseNode & paramtable = stmt.get(1);
    		for (ParseNode * rangeptr : paramtable)
    		{
   
   ```

3. change in file `Intent.h`, a bug before fork

   ```cpp
   diff --git a/src/parser/Intent.h b/src/parser/Intent.h
   index aa59a99..b2b76e9 100755
   --- a/src/parser/Intent.h
   +++ b/src/parser/Intent.h
   @@ -204,7 +204,7 @@ namespace TokenMeta {
    		ADD_ENUM(Int16, -335), ADD_ENUM(Int16_Decl, Int16 - 100),
    		ADD_ENUM(Int32, -336), ADD_ENUM(Int32_Decl, Int32 - 100),
    		ADD_ENUM(Int64, -337), ADD_ENUM(Int64_Decl, Int64 - 100),
   -		ADD_ENUM(LongDouble, -338), ADD_ENUM(LongDouble_Decl, Int64 - 100),
   +		ADD_ENUM(LongDouble, -338), ADD_ENUM(LongDouble_Decl, LongDouble - 100),
    		ADD_ENUM(Implicit_Decl, -499),
    
    		// Flow-Control
   
   ```

Test Case

```fortran
program main
  implicit real(kind=8) (a-z)
  lalala=009
end program
```

output

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
int main()
{
	long double lalala = 0.0;
	lalala = 009;
	
	return 0;
}
```

******

module(7.31 corrected)

1. modify ` for90.y`, add rules for module

   ```
   diff --git a/src/grammar/for90.y b/src/grammar/for90.y
   index 51fa698..fda86b7 100755
   --- a/src/grammar/for90.y
   +++ b/src/grammar/for90.y
   @@ -104,7 +104,7 @@ using namespace std;
    %token /*_YY_OP*/ YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS YY_EXPONENT YY_PLET YY_PNULL
    %token /*_YY_TYPE*/ YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR /* Lead to error YY_OPERATOR_UNARY */ YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE YY_FORMAT_STMT YY_COMMENT
    %token /*_YY_CONTROL_FLOW*/ YY_LABEL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_EXIT YY_CYCLE YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT 
   -%token /*_YY_DELIM*/ YY_TYPE YY_ENDTYPE YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA
   +%token /*_YY_DELIM*/ YY_TYPE YY_ENDTYPE YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA YY_PROCEDURE, YY_CONTAINS
    %token /*_YY_DESCRIBER*/ YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_ENTRY YY_DIMENSION YY_ARRAYBUILDER_START YY_ARRAYBUILDER_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND YY_SAVE YY_ALLOCATABLE YY_TARGET YY_POINTER
    %token /*_YY_TYPEDEF*/ YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T YY_DOUBLE_T
    %token /*_YY_COMMAND*/ YY_WRITE YY_READ YY_PRINT YY_CALL  YY_STOP YY_PAUSE YY_RETURN
   @@ -547,7 +547,7 @@ using namespace std;
    
    	argtable : exp
    			{
   -				// argtable is used in function call 
   +				// argtable is used in function call
    				ARG_OUT exp = YY2ARG($1);
    				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
    				$$ = RETURN_NT(newnode);
   @@ -1074,7 +1074,7 @@ using namespace std;
    				insert_comments(YY2ARG($$));
    				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
    			}
   -		| 
   +		|
    			{
    				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
    				update_pos(YY2ARG($$));
   @@ -1556,6 +1556,40 @@ using namespace std;
    				CLEAN_DELETE($1, $2, $3);
    #else
    				CLEAN_DELETE($1, $2, $3);
   +#endif
   +			}
   +		| YY_CONTAINS at_least_one_end_line function_decls at_least_one_end_line
   +			{
   +				ARG_OUT func_decls = YY2ARG($3);
   +				$$ = RETURN_NT(gen_suite(func_decls, gen_dummy()));
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
   +#ifdef USE_REUSE
   +				CLEAN_DELETE($1, $2, $3);
   +#else
   +				CLEAN_DELETE($1, $2, $3);
   +#endif
   +			}
   +
   +	function_decls : function_decl
   +			{
   +				ARG_OUT func_decl = YY2ARG($1);
   +				$$ = RETURN_NT(gen_suite(func_decl, gen_dummy()));
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
   +#ifdef USE_REUSE
   +				CLEAN_DELETE($1);
   +#else
   +				CLEAN_DELETE($1);
   +#endif
   +			}
   +		| function_decls at_least_one_end_line function_decl
   +			{
   +				ARG_OUT func_decl = YY2ARG($3);
   +				ARG_OUT suite = YY2ARG($1);
   +				$$ = RETURN_NT(gen_suite(func_decl, suite));
   +#ifdef USE_REUSE
   +				CLEAN_DELETE($1, $2, $3);
   +#else
   +				CLEAN_DELETE($1, $2, $3);
    #endif
    			}
    
   @@ -2273,7 +2307,7 @@ using namespace std;
    				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
    			}
    
   -	function_decl : dummy_function_iden _optional_function YY_WORD '(' paramtable ')' _optional_result at_least_one_end_line suite _optional_endfunction
   +	function_decl : dummy_function_iden _optional_function YY_WORD '(' paramtable ')' _optional_result at_least_one_end_line suite _optional_endfunction _optional_name
    			{
    				ARG_OUT variable_function = YY2ARG($3); // function name
    				// enumerate parameter list 
   @@ -2285,10 +2319,10 @@ using namespace std;
    				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
    				$$ = RETURN_NT(newnode);
    
   -				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($10));
   -				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($11));
   +				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11);
    			}	
   -		| dummy_function_iden _optional_function YY_WORD at_least_one_end_line suite _optional_endfunction
   +		| dummy_function_iden _optional_function YY_WORD at_least_one_end_line suite _optional_endfunction _optional_name
    			{
    				ARG_OUT variable_function = YY2ARG($3); // function name
    				ARG_OUT suite = YY2ARG($5);
   @@ -2298,8 +2332,8 @@ using namespace std;
    				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
    				$$ = RETURN_NT(newnode);
    
   -				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
   -				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
   +				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7);
    			}
    	_optional_name : YY_WORD
    			{
   @@ -2312,6 +2346,22 @@ using namespace std;
    				update_pos(YY2ARG($$));
    			}
    
   +	_optional_endmodule : YY_ENDMODULE
   +			{
   +				$$ = $1;
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
   +			}
   +		| YY_END
   +			{
   +				$$ = $1;
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
   +			}
   +		| YY_END YY_MODULE
   +			{
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
   +			}
   +
    	_optional_endprogram : YY_ENDPROGRAM
    			{
    				$$ = $1;
   @@ -2328,6 +2378,13 @@ using namespace std;
    				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
    			}
    
   +       module : YY_MODULE _optional_name at_least_one_end_line suite _optional_endmodule _optional_name
   +			{
   +				ParseNode & suite = YY2ARG($4);
   +				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_MODULE, $2->get_what() }, suite));
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
   +				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
   +			}
           program : YY_PROGRAM _optional_name at_least_one_end_line suite _optional_endprogram _optional_name
    			{
    				ParseNode & suite = YY2ARG($4);
   @@ -2341,6 +2398,11 @@ using namespace std;
    				$$ = $1;
    				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
    			}
   +		| module
   +		    {
   +				$$ = $1;
   +				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
   +		    }
    		| function_decl
    			{
    				$$ = $1;
   
   ```

2. add NT enum in `Intent.h`

   ```cpp
   diff --git a/src/parser/Intent.h b/src/parser/Intent.h
   index aa59a99..12472d7 100755
   --- a/src/parser/Intent.h
   +++ b/src/parser/Intent.h
    		// Flow-Control
   @@ -359,6 +359,7 @@ namespace TokenMeta {
    		ADD_ENUM(NT_ALLOCATE_STMT, -2050),
    		ADD_ENUM(NT_DEFINED_OPERATOR, -2051),
    		ADD_ENUM(NT_DERIVED_TYPE, -2052),
   +        ADD_ENUM(NT_MODULE, -2053),
    
    		ADD_ENUM(NT_DUMMY, -9999),
    		/***************************************
   
   ```

   

3. add keywords in `tokenizer.cpp`

   ```cpp
   diff --git a/src/parser/tokenizer.cpp b/src/parser/tokenizer.cpp
   index aa67c91..64c134e 100755
   --- a/src/parser/tokenizer.cpp
   +++ b/src/parser/tokenizer.cpp
   @@ -235,6 +235,14 @@ const vector<KeywordMeta> keywords = {
    		, TokenMeta::META_ANY
    		, YY_MODULE
    	}
   +    , KeywordMeta{"procedure"
   +            , TokenMeta::META_ANY
   +            , YY_PROCEDURE
   +    }
   +    , KeywordMeta{"contains"
   +            , TokenMeta::META_ANY
   +            , YY_CONTAINS
   +    }
    	, KeywordMeta{"block"
    		, TokenMeta::META_ANY
    		, YY_BLOCK
   ```

4. process module wrapper in `gen_program.cpp`

   ```cpp
   diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
   index dfceb05..9a01fe3 100755
   --- a/src/target/gen_program.cpp
   +++ b/src/target/gen_program.cpp
   @@ -34,6 +34,18 @@ void gen_fortran_program(const ParseNode & wrappers) {
    	FunctionInfo * program_info = add_function("", "program", FunctionInfo());
    	ParseNode script_program = gen_token(Term{ TokenMeta::NT_SUITE , "" });
    
   +    typedef struct module_info{
   +        bool is_set = false;
   +        std::string module_name;
   +        std::string module_code;
   +        FunctionInfo * outer_info = nullptr;
   +        ParseNode script_outer = gen_token(Term{ TokenMeta::NT_SUITE , "" });
   +        std::vector<ParseNode *> func_decls_in_module;
   +    }ModuleInfo;
   +
   +    ModuleInfo minfo;
   +
   +
    	for (ParseNode * wrapper_ptr : get_context().program_tree)
    	{
    		ParseNode & wrapper = *wrapper_ptr;
   @@ -62,6 +74,24 @@ void gen_fortran_program(const ParseNode & wrappers) {
    			*************/
    			FunctionInfo * finfo = add_function(get_context().current_module, variable_function.get_what(), FunctionInfo{});
    		}
   +        else if (wrapper.token_equals(TokenMeta::NT_MODULE))
   +        {
   +            minfo.is_set=true;
   +            minfo.outer_info = add_function("","module",FunctionInfo{});
   +            minfo.module_name = wrapper.get_what();
   +            ModuleInfo &minfo_alias = minfo;
   +            for (int j = 0; j < wrapper.get(0).length(); j++)
   +            {
   +                ParseNode &node = wrapper.get(0).get(j);
   +                if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
   +                {
   +                    minfo_alias.func_decls_in_module.push_back(&node);
   +                    add_function("", node.get(1).get_what(),FunctionInfo{});
   +                }
   +                else
   +                    minfo_alias.script_outer.addchild(wrapper.get(0).get(j));
   +            }
   +        }
    		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
    		{
    			get_context().current_module = "";
   @@ -97,8 +127,28 @@ void gen_fortran_program(const ParseNode & wrappers) {
    			//regen_function_1(tinfo, wrapper);
    		}
    	}
   -	// main program code
   -	regen_suite(program_info, script_program);
   +    if(minfo.is_set)
   +    {
   +
   +        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
   +        if (!func_decls_in_module.empty())
   +        {
   +            for (ParseNode *nodeptr:func_decls_in_module)
   +            {
   +                ParseNode &node = *nodeptr;
   +                ParseNode & variable_function = node.get(1);
   +                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
   +                regen_function_1(finfo, node);
   +            }
   +        }
   +    }
   +
   +    // main program code
   +    regen_suite(program_info, script_program);
   +    if(minfo.is_set)
   +    {
   +        regen_suite(minfo.outer_info,minfo.script_outer);
   +    }
    
    	// regen common definition
    	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
   @@ -135,6 +185,26 @@ void gen_fortran_program(const ParseNode & wrappers) {
    		//	codes += "\n";
    		//}
    	}
   +    if(minfo.is_set)
   +    {
   +
   +        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
   +        if (!func_decls_in_module.empty())
   +        {
   +            for (ParseNode *nodeptr:func_decls_in_module)
   +            {
   +                ParseNode &node = *nodeptr;
   +                ParseNode & variable_function = node.get(1);
   +                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
   +                regen_function_2(finfo);
   +                codes += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
   +                codes += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";
   +                codes += finfo->node->get_what();
   +                codes += "\n";
   +                codes += "#endif\n";
   +            }
   +        }
   +    }
    
    	for (TypeInfo * tinfo : get_context().types_vec)
    	{
   @@ -146,7 +216,13 @@ void gen_fortran_program(const ParseNode & wrappers) {
    	// main program code
    	regen_all_variables_decl_str(program_info, script_program);
    	main_code = tabber(script_program.get_what());
   -	sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
   +    sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
   +    if(minfo.is_set)
   +    {
   +        regen_all_variables_decl_str(minfo.outer_info,minfo.script_outer);
   +        minfo.module_code = minfo.script_outer.get_what();
   +        sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n%s", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str(), main_code.c_str());
   +    }
    	codes += string(codegen_buf);
    
    	// forward declarations
   @@ -155,7 +231,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
    		FunctionInfo * finfo;
    		std::tie(std::ignore, finfo) = pr;
    		std::string name = finfo->local_name;
   -		if (name != "program" && name != "")
   +		if (name != "program" && name != "" && name!="module")
    		{
    			forward_decls += gen_function_signature(finfo);
    			forward_decls += ";\n";
   ```

5. modify `gen_suite.cpp`, so that a function declaration can appear in a suite

   ```cpp
   diff --git a/src/target/gen_suite.cpp b/src/target/gen_suite.cpp
   index fe2bebb..341b6b9 100755
   --- a/src/target/gen_suite.cpp
   +++ b/src/target/gen_suite.cpp
   @@ -295,6 +295,8 @@ ParseNode gen_suite(const ParseNode & item, const ParseNode & list) {
    	*	including normal stmt node
    	* 3) interface_decl
    	*	including NT_INTERFACE node
   +	* 4) function_decl
   +	*	including NT_FUNCTIONDECLARE node
    	********************/
    	ParseNode newnode;
    	if (list.token_equals(TokenMeta::NT_DUMMY))
   @@ -304,6 +306,11 @@ ParseNode gen_suite(const ParseNode & item, const ParseNode & list) {
    			// case 3, interface_decl
    			newnode = gen_promote("", TokenMeta::NT_SUITE, item);
    		}
   +        else if(item.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
   +        {
   +            // case 4, function_decl
   +            newnode = gen_promote("", TokenMeta::NT_SUITE, item);
   +        }
    		else if (item.token_equals(TokenMeta::NT_SUITE)){
    			// case 1, labeled_stmts
    			newnode = item;
   @@ -320,6 +327,11 @@ ParseNode gen_suite(const ParseNode & item, const ParseNode & list) {
    			// case 3, interface_decl
    			newnode = gen_flatten(item, list, "%s%s", TokenMeta::NT_SUITE);
    		}
   +        else if(item.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
   +        {
   +            // case 4, function_decl
   +            newnode = gen_flatten(item, list, "%s%s", TokenMeta::NT_SUITE);
   +        }
    		else if (item.token_equals(TokenMeta::NT_SUITE)) {
    			// case 1, labeled_stmts
    			newnode = gen_merge(item, list, "%s\n%s", TokenMeta::NT_SUITE);
   
   ```

Test case

```fortran
module main
  integer a = 4
  contains
  subroutine fff
  end subroutine
end module
```

Output

```cpp
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
void fff();
#ifndef main
#define main
void fff()
{
	
	return ;
}

#endif
#ifndef main
#define main
int a = 4;

#endif

```



> step 1 and 4 are hard to trace, so here attach the complete files for sake of copy-paste

- `for90.y`

  ```
  /*
  *   Calvin Neo
  *   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
  *
  *   This program is free software; you can redistribute it and/or modify
  *   it under the terms of the GNU General Public License as published by
  *   the Free Software Foundation; either version 2 of the License, or
  *   (at your option) any later version.
  *
  *   This program is distributed in the hope that it will be useful,
  *   but WITHOUT ANY WARRANTY; without even the implied warranty of
  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *   GNU General Public License for more details.
  *
  *   You should have received a copy of the GNU General Public License along
  *   with this program; if not, write to the Free Software Foundation, Inc.,
  *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
  
  %{
  #include <cstdio>
  #include <string>
  #include <sstream>
  #include <iostream>
  #include <stdarg.h>
  #include <tuple>
  #include <stdint.h>
  #include "../parser/attribute.h"
  #include "../parser/parser.h"
  #include "../target/gen_common.h"
  #include "../parser/Function.h"
  
  
  void yyerror(const char* s); 
  
  #ifdef USE_LEX
  int pure_yylex(void);
  void set_buff(const std::string & code);
  void release_buff();
  #else
  #include "simple_lexer.h"
  #endif
  
  #define YYDEBUG 1
  #define YYERROR_VERBOSE
  #define YYINITDEPTH 2000
  
  // update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) 
  void update_pos(ParseNode & current) {
  	if (current.length() == 0) {
  		// do nothing 
  		current.fs.parse_pos = 0;
  		current.fs.parse_line = 0;
  		current.fs.parse_len = 0;
  		current.fs.line_pos = 0;
  	}
  	else if (current.length() == 1) {
  		current.fs.parse_pos = current.get(0).fs.parse_pos;
  		current.fs.parse_line = current.get(0).fs.parse_line;
  		current.fs.parse_len = current.get(0).fs.parse_len;
  		current.fs.line_pos = current.get(0).fs.line_pos;
  	}
  	else {
  		int tot_len = 0;
  		for (int i = 0; i < current.length(); i++)
  		{
  			tot_len += current.get(i).fs.parse_len;
  		}
  		current.fs.parse_pos = current.get(0).fs.parse_pos;
  		current.fs.parse_line = current.get(0).fs.parse_line;
  		current.fs.parse_len = tot_len;
  		current.fs.line_pos = current.get(0).fs.line_pos;
  	}
  }
  void update_pos(ParseNode & current, const ParseNode & start, const ParseNode & end) {
  	// if replace $$ with newnode then need to update_pos
  	if (start.fs.parse_len == 0) {
  		current.fs.parse_pos = end.fs.parse_pos;
  		current.fs.parse_line = end.fs.parse_line;
  		current.fs.parse_len = end.fs.parse_len;
  		current.fs.line_pos = end.fs.line_pos;
  	}
  	else if (end.fs.parse_len == 0) {
  		current.fs.parse_pos = start.fs.parse_pos;
  		current.fs.parse_line = start.fs.parse_line;
  		current.fs.parse_len = start.fs.parse_len;
  		current.fs.line_pos = start.fs.line_pos;
  	}
  	else {
  		current.fs.parse_pos = start.fs.parse_pos;
  		current.fs.parse_line = start.fs.parse_line;
  		current.fs.parse_len = end.fs.parse_len + end.fs.parse_pos - start.fs.parse_pos;
  		current.fs.line_pos = start.fs.line_pos;
  	}
  }
  using namespace std;
  %}
  
  %debug
  // %glr-parser
  //%define api.value.type union
  
  %token /*_YY_VOID*/ YY_IGNORE_THIS YY_CRLF
  %token /*_YY_OP*/ YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS YY_EXPONENT YY_PLET YY_PNULL
  %token /*_YY_TYPE*/ YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR /* Lead to error YY_OPERATOR_UNARY */ YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE YY_FORMAT_STMT YY_COMMENT
  %token /*_YY_CONTROL_FLOW*/ YY_LABEL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_EXIT YY_CYCLE YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT 
  %token /*_YY_DELIM*/ YY_TYPE YY_ENDTYPE YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA YY_PROCEDURE, YY_CONTAINS
  %token /*_YY_DESCRIBER*/ YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_ENTRY YY_DIMENSION YY_ARRAYBUILDER_START YY_ARRAYBUILDER_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND YY_SAVE YY_ALLOCATABLE YY_TARGET YY_POINTER
  %token /*_YY_TYPEDEF*/ YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T YY_DOUBLE_T
  %token /*_YY_COMMAND*/ YY_WRITE YY_READ YY_PRINT YY_CALL  YY_STOP YY_PAUSE YY_RETURN
  %token /*_YY_CONFIG*/ YY_CONFIG_IMPLICIT
  %token /*_YY_SYSFUNCTION*/ YY_ALLOCATE
  
  
  /******************* 
  * TODO: As it's appeared in `exp` rules,
  * we must assign priority to `YY_OPERATOR`
  * inorder to avoid shift-reduce conflict.
  * According to fortran, unary operators have highest priority,
  * while binary operators have lowest priority.
  * ref http://krsna.lamost.org/popular/fortran/8.htm
  * Error on For3d14.for
  *******************/
  // %left YY_OPERATOR
  
  %left YY_EQV YY_NEQV
  %left YY_OROR
  %left YY_ANDAND
  %right YY_NOT
  %left YY_EQ YY_NEQ
  %left YY_GT YY_GE YY_LE YY_LT
  %right YY_NEG YY_POS
  %left '+' '-' 
  %left '*' '/' 
  /******************* 
  * YY_POWER is right associative
  * x**y**z -> x**(y**z) 
  *******************/
  %right YY_POWER 
  // %right YY_OPERATOR_UNARY // Error on For3d14.for
  //%nonassoc '=' 
  //%nonassoc YY_PLET
  
  %start fortran_program
  
  %%
  
  	crlf_or_not : YY_CRLF
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1)); 
  				CLEAN_DELETE($1);
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Nop, "" }));
  				update_pos(YY2ARG($$));
  			}
  		
  	at_least_one_end_line : end_of_stmt
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| at_least_one_end_line end_of_stmt
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  
  	semicolon : ';'
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Semicolon, ";" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
  	end_of_stmt : YY_CRLF
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| semicolon
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	dummy_function_iden : YY_RECURSIVE
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$));
  			}
  
  	variable_desc_elem : YY_INTENT '(' YY_IN ')'
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(in)
  				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| YY_INTENT '(' YY_OUT ')'
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(out)
  				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  
  		| YY_INTENT '(' YY_INOUT ')'
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(inout)
  				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| YY_DIMENSION '(' paramtable ')'
  			{
  				// if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' 
  				// if is array reduce immediately and goto `var_def` 
  				// do not parse array slices here because this is difficult 
  				ARG_OUT dimen_slice = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| YY_DIMENSION '(' exp ')'
  			{
  				// define array like a(1)
  				ARG_OUT exp_to = YY2ARG($3);
  
  				ParseNode slice = promote_exp_to_slice(exp_to);
  				ParseNode dimen_slice = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		
  		| YY_DIMENSION 
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		
  		| YY_OPTIONAL
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // optional
  				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_PARAMETER
  			{
  				// const value
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // const
  				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_SAVE
  			{
  				// static value 
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // static
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_ALLOCATABLE
  			{
  				/* allocatable value */
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // allocatable
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_TARGET
  			{
  				// target value
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // target
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_POINTER
  			{
  				// target value
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // pointer
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  				
  	variable_desc : ',' variable_desc_elem variable_desc
  			{
  				ParseNode variable_elem = YY2ARG($2);
  				ParseNode variable_desc = YY2ARG($3);
  				// target code of slice depend on context
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
  				// merge attrs 
  				newnode.setattr(variable_elem.attr->clone());
  				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
  				// TODO do not add child
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		|
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
  				newnode.setattr(new VariableDescAttr());
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$));
  			}
  	/*
  	*	(3) The suffix “ - spec” is used consistently for specifiers, such as keyword actual arguments and
  	*		input / output statement specifiers.It also is used for type declaration attribute specifications(for
  	*			example, “array - spec” in R512), and in a few other cases.
  	*			(4) When reference is made to a type parameter, including the surrounding parentheses, the term
  	*		“selector” is used.See, for example, “length - selector”(R507) and “kind - selector”(R505).
  	*/
  	type_selector : YY_KIND '=' YY_INTEGER
  			{
  				int kind;
  				ARG_OUT integer = YY2ARG($3);
  				sscanf(integer.get_what().c_str(), "%d", &kind);
  
  				/* type size */
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  		| YY_LEN '=' exp
  			{
  				// though use std::string
  				// still need to initialize the string to YY_LEN
  				int len;
  				ARG_OUT integer = YY2ARG($3);
  				sscanf(integer.get_what().c_str(), "%d", &len);
  
  				/* string length */
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
  				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
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
  	literal : YY_FLOAT
  			{
  				// all arguments under `literal` rule is directly from tokenizer
  				ARG_OUT lit = YY2ARG($1);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.get_what() })); // float number
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_INTEGER YY_EXPONENT YY_INTEGER
  			{
  				ARG_OUT base = YY2ARG($1);
  				ARG_OUT expo = YY2ARG($3);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Float,  base.get_what() + "e" + expo.get_what() })); // float number
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  		| YY_INTEGER
  			{
  				ARG_OUT lit = YY2ARG($1);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.get_what() })); // int number
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_STRING
  			{
  				// replace `'` with `"`
  				ARG_OUT lit = YY2ARG($1);
  				std::string s = lit.get_what().substr(1, lit.get_what().size() - 2);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_TRUE
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_FALSE
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_COMPLEX
              {
  				ARG_OUT lit = YY2ARG($1);
  				string strcplx = lit.get_what();
  				auto splitter = strcplx.find_first_of('_', 0);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
  		| error '\n'
  			{
  				$$ = $1;
  				print_error("exp parse error");
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($2);
  			}
  
      variable : YY_WORD
              {
                  ARG_OUT lit = YY2ARG($1);
                  ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.get_what() });
                  $$ = RETURN_NT(newnode);
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
                  CLEAN_DELETE($1);
              }
          | inner_variable
              {
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
  
  	/******************
  	*	R618 section - subscript is subscript
  			or subscript - triplet
  			or vector - subscript
  	*	R619 subscript - triplet is[subscript] : [subscript] [: stride]
  	*	R620 stride is scalar - int - expr
  	*	R621 vector - subscript is int - expr
  	******************/
  	slice : exp ':' exp
  			{
  				// arr[from : to]
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT exp2 = YY2ARG($3);
  				// target code of slice depend on context
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp ':' exp ':' exp
  			{
  				// arr[from : to : step]
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT exp2 = YY2ARG($3);
  				ARG_OUT exp3 = YY2ARG($5);
  				// target code of slice depend on context
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2, exp3));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  			}
  		| ':'
  			{
  				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
  				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
  				ParseNode lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.get_what() }, from);
  				ParseNode ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.get_what() }, to);
  				// target code of slice depend on context
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| '*'
  			{
  				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
  				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
  				ParseNode lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.get_what() }, from);
  				ParseNode ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.get_what() }, to);
  				// target code of slice depend on context
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
  
  	keyvalue : exp '=' exp
  			{
  				// initial value is required in parse tree because it can be an non-terminal `exp` 
  				// non-array initial values 
  				// array_builder is exp 
  				ARG_OUT exp2 = YY2ARG($3);
  				$$ = RETURN_NT(gen_keyvalue_from_exp(YY2ARG($1), YY2ARG($3)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  
  		|   exp YY_PLET YY_PNULL '(' ')'
  			{
  				ARG_OUT exp2 = YY2ARG($3);
  				$$ = RETURN_NT(gen_keyvalue_from_exp(YY2ARG($1), YY2ARG($3)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  		|	exp YY_PLET exp
  			{
  				ARG_OUT exp2 = YY2ARG($3);
  				std:string str = exp2.get_what();
  				exp2.get_what()=std::string("&")+std::string("(")+exp2.get_what()+std::string(")");
  				$$ = RETURN_NT(gen_keyvalue_from_exp( YY2ARG($1),exp2));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  	argtable : exp
  			{
  				// argtable is used in function call
  				ARG_OUT exp = YY2ARG($1);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| argtable ',' exp
  			{
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT argtable = YY2ARG($1);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  
  	dimen_slice : slice 
  			{
  				/******************
  				* 1d array
  				* arr[from : to]
  				* target code of slice depend on context
  				******************/ 
  				ARG_OUT slice = YY2ARG($1);
  				// only 1 slice
  				$$ = RETURN_NT(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| dimen_slice ',' slice
  			{
  				/******************
  				* multi dimension array
  				* arr[from:to, from:to, ...]
  				* target code of slice depend on context
  				******************/
  				ARG_OUT dimen_slice = YY2ARG($1);
  				ARG_OUT slice = YY2ARG($3);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  		| dimen_slice ',' exp
  			{
  				/******************
  				* multi dimension array
  				* arr[from:to, index, ...]
  				* target code of slice depend on context
  				******************/
  				ARG_OUT dimen_slice = YY2ARG($1);
  				ARG_OUT exp = YY2ARG($3);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  		| argtable ',' slice
  			{
  				ARG_OUT argtable = YY2ARG($1);
  				ARG_OUT slice = YY2ARG($3);
  				if (!argtable.token_equals(TokenMeta::NT_ARGTABLE_PURE))
  				{
  					print_error("Illegal dimen_slice", argtable);
  				}
  				// IMPORTANT: can't promote here, or `s(i, 1:j)` cause error, ref `regen_slice`
  				//newnode = gen_flatten(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  
  	function_array_body : variable '(' paramtable ')'
  			{
  				// function call OR array index 
  				// NOTE that array index can be A(1:2, 3:4)
  				ARG_OUT callable_head = YY2ARG($1);
  				ARG_OUT argtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| type_name '(' paramtable ')'
  			{
  				// function call OR array index 
  				// NOTE that array index can be A(1:2, 3:4) 
  				ARG_OUT callable_head = YY2ARG($1);
  				ARG_OUT argtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  
  	function_array : function_array_body
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_CALL function_array_body
  			{
  				$$ = $2;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_CALL variable
  			{
  				/******************
  				* call-stmt
  				* function call can omit trailing `()` if there's no arguments
  				* e.g.
  				*	```
  				*	call func
  				*	```
  				* `func` is not a variable, but a function
  				* SHOULDN"T GENERATE VARDEF FOR `func`
  				*******************/
  				ARG_OUT callable_head = YY2ARG($2);
  				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }
  					, callable_head, gen_token(Term{TokenMeta::NT_ARGTABLE_PURE, ""}) );
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  
  	exp : function_array 
  			{
  				/******************
  				* this is sth callable, maybe array section(NT_DIMENSLICE) or function
  				******************/
  				ARG_OUT function_array = YY2ARG($1);
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| array_builder
  			{
  				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
  				ARG_OUT array_builder_elem = YY2ARG($1);
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| '(' exp ')' 
  			{
  				// `function_array` rule MUST have priority over this rule 
  				ARG_OUT exp = YY2ARG($2);
  				ParseNode opnew = gen_token(Term{ TokenMeta::LB, "( %s )" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp '+' exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Add, "%s + %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp '-' exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Minus, "%s - %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp '*' exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Multiply, "%s * %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp '/' exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Divide, "%s / %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_POWER exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Power, "power(%s, %s)" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
          | '-' %prec YY_NEG exp 
  			{
  				ARG_OUT exp1 = YY2ARG($2);
  				ARG_OUT op = YY2ARG($1);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Neg, "(-%s)" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
          | '+' %prec YY_POS exp 
  			{
  				ARG_OUT exp1 = YY2ARG($2);
  				ARG_OUT op = YY2ARG($1);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Pos, "%s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		| exp YY_NEQ exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::NEQ, "%s != %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_NEQV exp 
  			{
  				// xor
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::NEQV, "%s ^ %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_EQ exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::EQ, "%s == %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_EQV exp 
  			{
  				// nor
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::EQV, "!(%s ^ %s)" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_ANDAND exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::AndAnd, "%s && %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_OROR exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "%s || %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| YY_NOT exp 
  			{
  				ARG_OUT exp1 = YY2ARG($2);
  				ARG_OUT op = YY2ARG($1);
  				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "!(%s)" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		| exp YY_GT exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::GT, "%s > %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_GE exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::GE, "%s >= %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_LE exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::LE, "%s <= %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  			}
  		| exp YY_LT exp 
  			{
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::LT, "%s < %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| exp YY_OPERATOR exp
  			{
  				// TODO may have error priority 
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				const string & op_name = op.get_what();
  				auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == op_name; });
  				if (keyword_iter != keywords.end())
  				{
  					// this is a keyword
  				}
  				else {
  					fatal_error("self-defined operator is not supported", op);
  				}
  				ParseNode opnew = gen_token(Term{ keyword_iter->token, "%s " + op_name + " %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| hidden_do
  			{
  				ARG_OUT hidden_do = YY2ARG($1);
  				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, hidden_do.get_what() }, hidden_do));
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| literal 
              {
  				/******************
  				* shouldn't promote literals to NT_EXPRESSION, 
  				*	because it can bring trouble to hardcoded dealt values
  				* e.g.
  				* when generating NT_SLICE, we can set a default lower bound UBOUND_DELTA_STR = `1`, 
  				*	and we hard code the UBOUND_DELTA_STR
  				*	if we promote  literals to NT_EXPRESSION, we should write
  				*	`gen_token(Term{TokenMeta::NT_EXPRESSION, UBOUND_DELTA_STR}, gen_token(Term{TokenMeta::Int, UBOUND_DELTA_STR}))`
  				*	it's not elegant
  				******************/
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		//| integer_promoted
  		//	{
  		//		$$ = $1;
  		//		update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  		//	}
  		| variable
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		// inner_variable is variable, omit the rule
  		//| inner_variable
  		//	{
  		//		$$ = $1;
  		//		update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  		//	}
  			
      inner_variable : variable '%' YY_WORD
              {
              
                  ARG_OUT t = YY2ARG($1);
                  ARG_OUT v = YY2ARG($3);
                  ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                  $$ = RETURN_NT(newnode);
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
                  CLEAN_DELETE($1, $2, $3);
              }
          | function_array_body '%' YY_WORD
              {
                  ARG_OUT t = YY2ARG($1);
                  ARG_OUT v = YY2ARG($3);
                  ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                  $$ = RETURN_NT(newnode);
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
                  CLEAN_DELETE($1, $2, $3);
              }
          | inner_variable '%' YY_WORD
              {
                  ARG_OUT t = YY2ARG($1);
                  ARG_OUT v = YY2ARG($3);
                  ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                  $$ = RETURN_NT(newnode);
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
                  CLEAN_DELETE($1, $2, $3);
              }
  
  
  	stmt : exp 
  			{
  				/******************
  				* formerly, considering `stmt` are completed by `\n` or certain mark like `end do(enddo)`
  				* so `stmt` is used to have a list of children
  				* however, now,
  				******************/
  				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG($1)));
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| var_def 
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
          | compound_stmt
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
          | io_stmt
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| implicit_stmt
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| let_stmt
  			{
  				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG($1)));
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| common_stmt
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_FORMAT_STMT
  			{
  				ARG_OUT format = YY2ARG($1);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.to_string() + "\"" }, format);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_COMMENT
  			{ 
  				ARG_OUT comment = YY2ARG($1);
  				$$ = RETURN_NT(gen_comment(comment.get_what()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| control_stmt
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| allocate_stmt
  			{
  				$$ = $1;
  				insert_comments(YY2ARG($$));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
  				update_pos(YY2ARG($$));
  			}
  			
  	control_stmt : pause_stmt 
  			{
  				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| stop_stmt 
  			{
  				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_CONTINUE
  			{
  				$$ = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}		
  		| YY_RETURN
  			{
  				$$ = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}			
  		| jump_stmt
  			{
  				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
      io_stmt : write
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| print
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| read
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	compound_stmt : if_stmt 
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| do_stmt 
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| select_stmt
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	jump_stmt : YY_CYCLE
  			{
  				$$ = RETURN_NT(gen_token(Term{TokenMeta::Continue, "continue;"}));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_EXIT
  			{
  				$$ = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_GOTO YY_INTEGER
  			{
  				ARG_OUT line = YY2ARG($2);
  				$$ = RETURN_NT(gen_token(Term{TokenMeta::Goto, line.get_what() }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  
  	pause_stmt : YY_PAUSE literal
  			{
  				ARG_OUT lit = YY2ARG($2);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.get_what() + ");stop()" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		| YY_PAUSE
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop()" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
  	stop_stmt : YY_STOP literal
  			{
  				ARG_OUT lit = YY2ARG($2);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop(" + lit.get_what() + ");" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		| YY_STOP
  			{
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop();" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  
  	let_stmt : exp YY_PLET YY_PNULL '(' ')'
  			{
  			    //printf("in rule =>");
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  			}
  
  		|	exp YY_PLET exp
  			{
  			    //printf("in rule =>");
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s =&(%s)" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  		| exp '=' exp
  			{
  			    //printf("in rule =");
  				ARG_OUT exp1 = YY2ARG($1);
  				ARG_OUT op = YY2ARG($2);
  				ARG_OUT exp2 = YY2ARG($3);
  				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
  				$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| YY_DATA nlists '/' clists '/'
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
  				        lelem = exp1.get(0);
  				        lelem.get_what().append("(").append("INOUT("+std::to_string(i+1)+")").append(")");
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
      nlists_elem : variable
              {
                  //printf("in nlists_elem:variable\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
          | function_array_body
              {
                  //printf("in nlists_elem:function_array_body\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
          | hidden_do
              {
                  //printf("in nlists_elem:hidden_do\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
  
      // nlists derived from argtable
      nlists : nlists_elem
              {
                  //printf("in nlists:nlists_elem\n");
              	ARG_OUT exp = YY2ARG($1);
              	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
              	$$ = RETURN_NT(newnode);
              	update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              	CLEAN_DELETE($1);
              }
          | nlists ',' nlists_elem
              {
                  //printf("in nlists:nlists, nlists_elem\n");
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT argtable = YY2ARG($1);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
              }
  
      c_in_clist : literal
              {
                  //printf("in c_in_clist:literal\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
          | YY_WORD
              {
                  //printf("in c_in_clist:YY_WORD\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
      r_in_clist : YY_INTEGER
              {
                  //printf("in r_in_clist:YY_INTEGER\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
  
  
      clists_elem : c_in_clist
              {
                  //printf("in clists_elem:c_in_clist\n");
                  $$ = $1;
                  update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              }
  
      // clists derived from argtable
      clists : clists_elem
              {
                  //printf("in clists:clists_elem\n");
              	ARG_OUT exp = YY2ARG($1);
              	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
              	$$ = RETURN_NT(newnode);
              	update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
              	CLEAN_DELETE($1);
              }
          | clists ',' clists_elem
              {
                  //printf("in clists:clists, clists_elem\n");
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT argtable = YY2ARG($1);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
  				$$ = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
              }
          | r_in_clist '*' c_in_clist
              {
                  //printf("in clists:r_in_clist * c_in_clist\n");
  				ARG_OUT r = YY2ARG($1);
  				int times = std::stoi(r.get_what());
  				ARG_OUT c = YY2ARG($3);
  
  				ParseNode * newnode = new ParseNode();
              	*newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , c.get_what()}, c);
  
  #ifdef USE_REUSE
                  for(int i = 1; i < times; i++)
                  {
                    ParseNode * container = new ParseNode();
                    ParseNode *exp = new ParseNode(c);
  				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
  				  newnode = container;
                  }
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2);
  				CLEAN_REUSE($1, $3);
  #else
                  for(int i = 1; i < times; i++)
                  {
                    ParseNode *exp = new ParseNode(c);
  				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                  }
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
              }
          | clists ',' r_in_clist '*' c_in_clist
              {
                  //printf("in clists:clists ',' r_in_clist '*' c_in_clist\n");
  				ARG_OUT argtable = YY2ARG($1);
  				ARG_OUT r = YY2ARG($3);
  				int times = std::stoi(r.get_what());
  				ARG_OUT c = YY2ARG($5);
  
  				ParseNode * newnode = new ParseNode();
  				*newnode = argtable;
  #ifdef USE_REUSE
                  for(int i = 0; i < times; i++)
                  {
                    ParseNode * container = new ParseNode();
                    ParseNode *exp = new ParseNode(c);
  				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
  				  newnode = container;
                  }
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($2, $4);
  				CLEAN_REUSE($1, $3, $5);
  #else
                  for(int i = 0; i < times; i++)
                  {
                    ParseNode *exp = new ParseNode(c);
  				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                  }
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  #endif
              }
  
  	implicit_stmt : YY_IMPLICIT YY_NONE
  			{
  				// dummy stmt
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		| YY_IMPLICIT type_name '(' paramtable ')'
  			{
  				// dummy stmt
  				ParseNode & type_name = YY2ARG($2);
  				ParseNode & paramtable = YY2ARG($4);
  				ParseNode newnode = gen_token(Term{ TokenMeta::ConfigImplicit, "" }, type_name, paramtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  			}
  
  	labeled_stmts : YY_LABEL stmt
  			{
  				ARG_OUT label = YY2ARG($1); // TokenMeta::Label
  				ARG_OUT stmt = YY2ARG($2);
  				if (stmt.token_equals(TokenMeta::NT_FORMAT))
  				{
  					//log_format_index(label.get_what(), stmt.get(0)); 
  					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL FORMAT GENERATED IN REGEN_SUITE") }, label, stmt);
  					// do not generate target code of format stmt
  					$$ = RETURN_NT(newnode);
  				}
  				else {
  					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL GENERATED IN REGEN_SUITE") }, label, stmt);
  					$$ = RETURN_NT(newnode);
  				}
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  
  	allocate_stmt : YY_ALLOCATE '(' paramtable ')'
  			{
  				ARG_OUT paramtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ALLOCATE_STMT, "" }, paramtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  
  	suite : labeled_stmts
  			{
  				// NT_FORMAT or other stmt node
  				ARG_OUT labeled_stmts = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(labeled_stmts, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| labeled_stmts end_of_stmt suite
  			{
  
  				ARG_OUT labeled_stmts = YY2ARG($1);
  				ARG_OUT suite = YY2ARG($3);
  				$$ = RETURN_NT(gen_suite(labeled_stmts, suite));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  				
  		| stmt
  			{
  				ARG_OUT stmt = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(stmt, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| stmt end_of_stmt suite
  			{
  				ARG_OUT stmt = YY2ARG($1);
  				ARG_OUT suite = YY2ARG($3);
  				$$ = RETURN_NT(gen_suite(stmt, suite));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  				
  		| interface_decl
  			{
  				// NT_INTERFACE
  				ARG_OUT interf = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(interf, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| interface_decl end_of_stmt suite
  			{
  				ARG_OUT interf = YY2ARG($1);
  				ARG_OUT suite = YY2ARG($3);
  				$$ = RETURN_NT(gen_suite(interf, suite));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  				
  		| type_decl
  			{
  				// NT_DERIVED_TYPE
  				ARG_OUT type_decl = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(type_decl, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| type_decl end_of_stmt suite
  			{
  				ARG_OUT type_decl = YY2ARG($1);
  				ARG_OUT suite = YY2ARG($3);
  				$$ = RETURN_NT(gen_suite(type_decl, suite));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  		| YY_CONTAINS at_least_one_end_line function_decls at_least_one_end_line
  			{
  				ARG_OUT func_decls = YY2ARG($3);
  				$$ = RETURN_NT(gen_suite(func_decls, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  
  	function_decls : function_decl
  			{
  				ARG_OUT func_decl = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(func_decl, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1);
  #else
  				CLEAN_DELETE($1);
  #endif
  			}
  		| function_decls at_least_one_end_line function_decl
  			{
  				ARG_OUT func_decl = YY2ARG($3);
  				ARG_OUT suite = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(func_decl, suite));
  #ifdef USE_REUSE
  				CLEAN_DELETE($1, $2, $3);
  #else
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  
  	_optional_device : '*'
  			{	/******************
  				* An asterisk identifies particular processor-dependent external units that are preconnected for formatted sequential access (9.4.4.2).
  				*==================
  				* -1 stands for stdin/stdout, depending it's in whether a read or a write stmt, ref gen_io.cpp
  				******************/
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, "-1" })); // 
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_INTEGER
  			{
  				ARG_OUT integer = YY2ARG($1);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, integer.get_what() }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  	_optional_formatter : '*'
  			{
  				/******************
  				* an asterisk (*) which indicates list-directed formatting (10.8).
  				******************/
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_INTEGER
  			{
  				// use format stmt at line YY2ARG($1) to format
  				ARG_OUT integer = YY2ARG($1);
  				std::string location_label = integer.get_what();
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_STRING
  			{
  				/******************
  				* C++ only allows strings wrapped by `"`,
  				*	replace `'` string with `"`
  				******************/
  				ARG_OUT s = YY2ARG($1);
  				string modified = "\"" + s.get_what().substr(1, s.get_what().size() - 2) + "\"";
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER, modified }));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  	/******************
  	*	9.4.1 Control information list
  	*	The io-control-spec-list is a control information list that includes:
  	*	(1) A reference to the source or destination of the data to be transferred
  	*	(2) Optional specification of editing processes
  	*	(3) Optional specification to identify a record
  	*	(4) Optional specification of exception handling
  	*	(5) Optional return of status
  	*	(6) Optional record advancing specification
  	*	(7) Optional return of number of characters read
  	*	The control information list governs the data transfer.
  	*	R912 io-control-spec is [ UNIT = ] io-unit
  	*	or [ FMT = ] format
  	*	or [ NML = ] namelist-group-name
  	*	or REC = scalar-int-expr
  	*	or IOSTAT = scalar-default-int-variable
  	*	or ERR = label
  	*	or END = label
  	*	or ADVANCE = scalar-default-char-expr
  	*	or SIZE = scalar-default-int-variable
  	*	or EOR = label
  	******************/
  	io_info : '(' _optional_device ',' _optional_formatter ')'
  			{
  				/******************
  				* target code of io_info depend on context
  				*	can be either iostream/cstdio
  				******************/
  				ARG_OUT _optional_device = YY2ARG($2);
  				ARG_OUT _optional_formatter = YY2ARG($4);
  				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  			}
  		| _optional_formatter ','
  			{				
  				/******************
  				* target code of io_info depend on context
  				*	can be either iostream/cstdio
  				******************/
  				ParseNode _optional_device = gen_token(Term{TokenMeta::META_INTEGER, "-1"});
  				ARG_OUT _optional_formatter = YY2ARG($1);
  				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  
  
      write : YY_WRITE io_info paramtable 
  			{
  				ARG_OUT io_info = YY2ARG($2);
  				ARG_OUT argtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, WHEN_DEBUG_OR_EMPTY("WRITE GENERATED IN REGEN_SUITE") }, io_info, argtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  	print : YY_PRINT io_info paramtable
  			{
  				ARG_OUT io_info = YY2ARG($2);
  				ARG_OUT argtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, WHEN_DEBUG_OR_EMPTY("PRINT GENERATED IN REGEN_SUITE") }, io_info, argtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  
  	read : YY_READ io_info paramtable
  			{
  				ARG_OUT io_info = YY2ARG($2);
  				ARG_OUT argtable = YY2ARG($3);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, WHEN_DEBUG_OR_EMPTY("READ GENERATED IN REGEN_SUITE") }, io_info, argtable);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  	type_name : YY_INTEGER_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_FLOAT_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_DOUBLE_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_STRING_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_COMPLEX_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_BOOL_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
          | YY_CHARACTER_T 
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($1)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| YY_TYPE '(' YY_WORD ')'
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($3)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		/*| YY_TYPE '(' YY_WORD ')' ',' YY_TARGET
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($3)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  		| YY_TYPE '(' YY_WORD ')' ',' YY_POINTER
  			{
  				$$ = RETURN_NT(gen_type(YY2ARG($3), YY2ARG($6)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}*/
  
      type_spec : type_name '(' type_selector ')'
  			{
  				// now translated in pre_map
  				$$ = RETURN_NT(gen_type(YY2ARG($1), YY2ARG($3)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| type_name '*' YY_INTEGER
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2, $3);
  			}
  		| type_name '*' '(' '*' ')'
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($2, $3);
  			}
  		| type_name
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	_blockname_or_none : '/' YY_WORD '/'
  			{
  				$$ = $2;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $3);
  			}
  		| '/' '/'
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		|
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$));
  			}
  
  	common_stmt : YY_COMMON _blockname_or_none paramtable
  			{
  				ARG_OUT blockname = YY2ARG($2);
  				ARG_OUT paramtable = YY2ARG($3);
  				$$ = RETURN_NT(gen_common(blockname, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
      var_def : type_spec variable_desc YY_DOUBLECOLON paramtable
  			{
  				// TODO: Here may be a shift-reduce confliction, because `variable_desc` can be empty,
  				// when confronting ',', both reducing to variable_desc or shifting may make sense.
  				ARG_OUT type_spec = YY2ARG($1);
  				ARG_OUT variable_desc = YY2ARG($2);
  				ARG_OUT paramtable = YY2ARG($4);
  				// get_variabledesc_attr(const_cast<ParseNode &>(variable_desc)).slice.value()
  				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| type_spec variable_desc paramtable
  			{
  				ARG_OUT type_spec = YY2ARG($1);
  				ARG_OUT variable_desc = YY2ARG($2);
  				ARG_OUT paramtable = YY2ARG($3);
  
  				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		/*| YY_TYPE '(' YY_WORD ')' variable_desc paramtable
  			{
  				ARG_OUT type_spec = YY2ARG($3);
  				ARG_OUT variable_desc = YY2ARG($5);
  				ARG_OUT paramtable = YY2ARG($6);
  
  				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}*/
  		| variable_desc_elem paramtable
  			{
  				ARG_OUT variable_desc_elem = YY2ARG($1);
  				ARG_OUT paramtable = YY2ARG($2);
  				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
  				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc_elem, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  		// no shift-reduce confliction 
  				/*
  		| YY_DIMENSION paramtable
  			{
  				// array decl 
  				ARG_OUT paramtable = YY2ARG($2);
  				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
  				ParseNode variable_desc = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN ") });
  				set_variabledesc_attr(variable_desc, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
  				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  			*/
  
  	var_defs : var_def
  			{
  				ARG_OUT var_def = YY2ARG($1);
  				ParseNode newnode = gen_promote("%s", TokenMeta::TypeDef, var_def);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| var_def at_least_one_end_line var_defs
  			{
  				ARG_OUT var_def = YY2ARG($1);
  				ARG_OUT var_defs = YY2ARG($3);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, var_def, var_defs, "%s\n%s", TokenMeta::TypeDef);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_REUSE($1, $3);
  				CLEAN_DELETE($2);
  #else
  				$$ = RETURN_NT(gen_flatten(var_def, var_defs, "%s\n%s", TokenMeta::TypeDef));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  			
  	_optional_endtype : YY_ENDTYPE
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END YY_TYPE
  			{
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  			}
  			
  	type_decl : YY_TYPE YY_WORD at_least_one_end_line suite _optional_endtype _optional_name
  			{
  				ARG_OUT variable_type = YY2ARG($2); // function name
  				ARG_OUT suite = YY2ARG($4);
  				//$$ = RETURN_NT(gen_suite(suite, gen_dummy()));
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_DERIVED_TYPE, "" }, variable_type, suite));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  			
  	pure_paramtable : keyvalue
  			{
  				ARG_OUT paramtable_elem = YY2ARG($1);
  				ParseNode newnode = gen_pure_paramtable(paramtable_elem);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| pure_paramtable ',' keyvalue
  			{
  				ARG_OUT paramtable_elem = YY2ARG($3);
  				ARG_OUT paramtable = YY2ARG($1);
  				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
  				$$ = RETURN_NT(newnode);
  				CLEAN_DELETE($1, $2, $3);
  			}				
  		| pure_paramtable ',' exp
  			{
  				ARG_OUT paramtable_elem = YY2ARG($3);
  				ARG_OUT paramtable = YY2ARG($1);
  				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		| argtable ',' keyvalue
  			{
  				ARG_OUT paramtable_elem = YY2ARG($3);
  				ARG_OUT paramtable = YY2ARG($1);
  				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  		|
  			{
  				// empty list
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$));
  			}
  
  	paramtable : pure_paramtable
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| argtable
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| dimen_slice
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  	
  	hidden_do : '(' argtable ',' variable '=' exp ',' exp ')'
  			{
  				/******************
  				* implied do is something like `(abs(i), i=1,4)`
  				*==================
  				* Standard
  					R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
  					R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
  					■ scalar - int - expr[, scalar - int - expr]
  				******************/
  				ARG_OUT argtable = YY2ARG($2);
  				ARG_OUT index = YY2ARG($4);
  				ARG_OUT from = YY2ARG($6);
  				ARG_OUT to = YY2ARG($8);
  				$$ = RETURN_NT(gen_hiddendo(argtable, index, from, to));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($9));
  			}
  
  	array_builder_elem : YY_ARRAYBUILDER_START paramtable YY_ARRAYBUILDER_END
  			{
  				// give initial value 
  				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
  				$$ = RETURN_NT(gen_arraybuilder_from_paramtable(YY2ARG($2)));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  			}
  
  	// array_builder can accept mixed 
  	array_builder : array_builder_elem
  			{
  				ARG_OUT array_builder_elem = YY2ARG($1);
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	
  	_optional_construct_name : YY_WORD ':'
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($2);
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$));
  			}
  
  	//_optional_then : YY_THEN
  	//	|
  
  	if_stmt : _optional_construct_name YY_IF '(' exp ')' stmt
  			{
  				// one line if
  				// `IF (e) st` where
  				// st can be any executable statement, except a DO block, IF, ELSE IF, ELSE, END IF, END, or another logical IF statement.
  				ARG_OUT exp = YY2ARG($4);
  				ARG_OUT stmt_true = YY2ARG($6);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "" }, exp, stmt_true, gen_dummy(), gen_dummy());
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  		| _optional_construct_name YY_IF '(' exp ')' YY_INTEGER ','  YY_INTEGER ',' YY_INTEGER
  			{
  				// Arithmetic if
  				// `IF (e) s1, s2, s3`, where
  				// s1, s2, s3 are labels
  			}
  		| _optional_construct_name YY_IF '(' exp ')' YY_THEN at_least_one_end_line /* must have \n */ suite YY_ENDIF
  			{
  				ARG_OUT exp = YY2ARG($4);
  				ARG_OUT suite_true = YY2ARG($8);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), gen_dummy());
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($9));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9);
  			}
  		| _optional_construct_name YY_IF '(' exp ')' YY_THEN at_least_one_end_line suite YY_ELSE at_least_one_end_line suite YY_ENDIF
  			{
  				ARG_OUT exp = YY2ARG($4);
  				ARG_OUT suite_true = YY2ARG($8);
  				ARG_OUT suite_else = YY2ARG($11);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), suite_else);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($12));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12);
  			}
  		| _optional_construct_name YY_IF '(' exp ')' YY_THEN at_least_one_end_line suite elseif_stmt YY_ENDIF
  			{
  				ARG_OUT exp = YY2ARG($4);
  				ARG_OUT suite_true = YY2ARG($8);
  				ARG_OUT elseif = YY2ARG($9);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, gen_dummy());
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($10));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
  			}
  		| _optional_construct_name YY_IF '(' exp ')' YY_THEN at_least_one_end_line suite elseif_stmt YY_ELSE at_least_one_end_line suite YY_ENDIF
  			{
  				ARG_OUT exp = YY2ARG($4);
  				ARG_OUT suite_true = YY2ARG($8);
  				ARG_OUT elseif = YY2ARG($9);
  				ARG_OUT suite_else = YY2ARG($12);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, suite_else);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($13));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13);
  			}
  
  	elseif_stmt : YY_ELSEIF '(' exp ')' YY_THEN at_least_one_end_line suite
  			{
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT suite_true = YY2ARG($7);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy());
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7);
  			}
  
  		| YY_ELSEIF '(' exp ')' YY_THEN at_least_one_end_line suite elseif_stmt
  			{
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT suite_true = YY2ARG($7);
  				ARG_OUT elseif = YY2ARG($8);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($8));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8);
  			}
  
  	_optional_label_construct : YY_INTEGER
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$));
  			}
  
  	do_stmt : _optional_construct_name YY_DO at_least_one_end_line suite crlf_or_not YY_ENDDO
  			{
  				ARG_OUT suite = YY2ARG($4);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, WHEN_DEBUG_OR_EMPTY("DO-BARE GENERATED IN REGEN_SUITE") }, suite);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
  				CLEAN_DELETE($1, $2, $3, $4, $5);
  			}
  		| _optional_construct_name YY_DO _optional_label_construct variable '=' exp ',' exp at_least_one_end_line suite crlf_or_not YY_ENDDO
  			{
  				YYSTYPE X1 = $1;
  				YYSTYPE X2 = $2;
  				YYSTYPE X3 = $3;
  				YYSTYPE X4 = $4;
  				YYSTYPE X5 = $5;
  				YYSTYPE X6 = $6;
  				YYSTYPE X7 = $7;
  				YYSTYPE X8 = $8;
  				YYSTYPE X9 = $9;
  				YYSTYPE X10 = $10;
  				YYSTYPE X11 = $11;
  				YYSTYPE X12 = $12;
  				ARG_OUT loop_variable = YY2ARG($4);
  				ARG_OUT exp_from = YY2ARG($6);
  				ARG_OUT exp_to = YY2ARG($8);
  				ParseNode step = gen_token(Term{ TokenMeta::META_INTEGER , UBOUND_DELTA_STR });
  				ARG_OUT suite = YY2ARG($10);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($12));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12);
  			}
  		| _optional_construct_name YY_DO _optional_label_construct variable '=' exp ',' exp ',' exp at_least_one_end_line suite crlf_or_not YY_ENDDO
  			{
  				ARG_OUT loop_variable = YY2ARG($4);
  				ARG_OUT exp_from = YY2ARG($6);
  				ARG_OUT exp_to = YY2ARG($8);
  				ARG_OUT step = YY2ARG($10);
  				ARG_OUT suite = YY2ARG($12);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE-STEP GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($14));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14);
  			}
  		| _optional_construct_name YY_DOWHILE exp at_least_one_end_line suite crlf_or_not YY_ENDDO
  			{
  				ARG_OUT exp = YY2ARG($3);
  				ARG_OUT suite = YY2ARG($5);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, WHEN_DEBUG_OR_EMPTY("DO-WHILE GENERATED IN REGEN_SUITE") }, exp, suite);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  	
  	select_stmt : _optional_construct_name YY_SELECT YY_CASE '(' exp ')' at_least_one_end_line case_stmt YY_ENDSELECT
  			{
  				ARG_OUT select = YY2ARG($2);
  				ARG_OUT exp = YY2ARG($5);
  				ARG_OUT case_stmt = YY2ARG($8);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_SELECT, WHEN_DEBUG_OR_EMPTY("SELECT GENERATED IN REGEN_SUITE") }, exp, case_stmt);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($9));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9);
  			}
  
  	case_stmt_elem : YY_CASE '(' dimen_slice ')' at_least_one_end_line suite
  			{
  				// one case
  				ARG_OUT dimen_slice = YY2ARG($3);
  				ARG_OUT suite = YY2ARG($6); 
  
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  		| YY_CASE '(' argtable ')' at_least_one_end_line suite
  			{
  				// one case
  				ARG_OUT dimen_slice = YY2ARG($3);
  				ARG_OUT suite = YY2ARG($6);
  
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite); 
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  		| YY_CASE YY_DEFAULT at_least_one_end_line suite
  			{
  				ARG_OUT suite = YY2ARG($4);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $3, $4);
  			}
  		| YY_CASE '(' YY_DEFAULT ')' at_least_one_end_line suite
  			{
  				ARG_OUT suite = YY2ARG($6);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  
  
  	case_stmt : case_stmt_elem
  			{
  				ARG_OUT case_stmt_elem = YY2ARG($1);
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, case_stmt_elem);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  	case_stmt : case_stmt_elem case_stmt
  			{
  				ARG_OUT case_stmt_elem = YY2ARG($1);
  				ARG_OUT case_stmt = YY2ARG($2);
  				ParseNode newnode = gen_flatten(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				CLEAN_DELETE($1, $2);
  			}
  	
  	_optional_result : YY_RESULT '(' variable ')'
  			{
  				$$ = $3;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
  				CLEAN_DELETE($1, $2, $4);
  			}
  		|
  			{
  				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$));
  			}
  
  	_optional_function : YY_FUNCTION
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_SUBROUTINE
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	_optional_endfunction : YY_ENDFUNCTION
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_ENDSUBROUTINE
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  
  	function_decl : dummy_function_iden _optional_function YY_WORD '(' paramtable ')' _optional_result at_least_one_end_line suite _optional_endfunction _optional_name
  			{
  				ARG_OUT variable_function = YY2ARG($3); // function name
  				// enumerate parameter list 
  				ARG_OUT paramtable = YY2ARG($5);
  				ARG_OUT variable_result = YY2ARG($7); // result variable
  				ARG_OUT suite = YY2ARG($9);
  
  				ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flattened parameter list with all keyvalue elements
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
  				$$ = RETURN_NT(newnode);
  
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($11));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11);
  			}	
  		| dummy_function_iden _optional_function YY_WORD at_least_one_end_line suite _optional_endfunction _optional_name
  			{
  				ARG_OUT variable_function = YY2ARG($3); // function name
  				ARG_OUT suite = YY2ARG($5);
  
  				ParseNode kvparamtable = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
  				ParseNode void_return = gen_token(Term{ TokenMeta::UnknownVariant, "" });
  				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
  				$$ = RETURN_NT(newnode);
  
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7);
  			}
  	_optional_name : YY_WORD
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		|
  			{
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$));
  			}
  
  	_optional_endmodule : YY_ENDMODULE
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END YY_MODULE
  			{
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  			}
  
  	_optional_endprogram : YY_ENDPROGRAM
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| YY_END YY_PROGRAM
  			{
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
  			}
  
         module : YY_MODULE _optional_name at_least_one_end_line suite _optional_endmodule _optional_name
  			{
  				ParseNode & suite = YY2ARG($4);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_MODULE, $2->get_what() }, suite));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
         program : YY_PROGRAM _optional_name at_least_one_end_line suite _optional_endprogram _optional_name
  			{
  				ParseNode & suite = YY2ARG($4);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.get_what() }, suite));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
  			}
  
  	wrapper : program
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| module
  		    {
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  		    }
  		| function_decl
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		| type_decl
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}
  		// R1101 main-program is [ program-stmt ]
  		//	[ specification-part ]
  		//	[ execution-part ]
  		//	[ internal-subprogram-part ]
  		//	end-program-stmt 
  		| stmt
  			{
  				ARG_OUT stmt = YY2ARG($1);
  				$$ = RETURN_NT(gen_suite(stmt, gen_dummy()));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| labeled_stmts
  			{
  				$$ = $1;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  			}		
  		| YY_END
  			{
  				$$ = RETURN_NT(gen_dummy());
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}		
  
  
  	wrappers : wrapper
  			{
  				ARG_OUT wrapper = YY2ARG($1);
  				ParseNode newnode = gen_promote("%s", TokenMeta::NT_WRAPPERS, wrapper);
  				$$ = RETURN_NT(newnode);
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
  				CLEAN_DELETE($1);
  			}
  		| wrapper at_least_one_end_line wrappers
  			{
  				ARG_OUT wrapper = YY2ARG($1);
  				ARG_OUT wrappers = YY2ARG($3);
  #ifdef USE_REUSE
  				ParseNode * newnode = new ParseNode();
  				reuse_flatten(*newnode, wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS);
  				$$ = newnode;
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_REUSE($1, $3);
  				CLEAN_DELETE($2);
  #else
  				$$ = RETURN_NT(gen_flatten(wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
  				CLEAN_DELETE($1, $2, $3);
  #endif
  			}
  
  	interface_decl : YY_INTERFACE _optional_name at_least_one_end_line wrappers crlf_or_not YY_ENDINTERFACE _optional_name
  			{
  				ARG_OUT wrappers = YY2ARG($4);
  				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
  				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
  				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7);
  			}
  
  	fortran_program : wrappers
  			{
  				gen_fortran_program(YY2ARG($1));
  			}
  
  
  %%
  void update_yylval(Term & current_term) {
  	get_tokenizer_state().CurrentTerm = current_term;
  	ParseNode newnode{ TokenizerState(get_tokenizer_state()) , nullptr, nullptr };
  	yylval = RETURN_NT(newnode);
  }
  void yyerror(const char* s)
  {
  	// fprintf(stderr, "%s", s);
  	print_error(string(s), YY2ARG(yylval));
  }
  int parse(std::string code) {
  #ifdef USE_YACC
  #ifdef USE_LEX
  	get_tokenizer_context().load_code = set_buff;
  	get_tokenizer_context().unload_code = release_buff;
  #else
  	get_tokenizer_context().load_code = [&](const std::string & _code) {
  		get_simpler_context().reset();
  		get_simpler_context().code = _code;
  		get_tokenizer_state().parse_line = 1;
  	};
  	get_tokenizer_context().unload_code = []() {
  	
  	};
  #endif
  	get_tokenizer_context().load_code(code);
  	yyparse();
  	get_tokenizer_context().unload_code();
  #endif
  	return 0;
  }
  
  ```

- `gen_program.cpp`

  ```cpp
  /*
  *   Calvin Neo
  *   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
  *
  *   This program is free software; you can redistribute it and/or modify
  *   it under the terms of the GNU General Public License as published by
  *   the Free Software Foundation; either version 2 of the License, or
  *   (at your option) any later version.
  *
  *   This program is distributed in the hope that it will be useful,
  *   but WITHOUT ANY WARRANTY; without even the implied warranty of
  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *   GNU General Public License for more details.
  *
  *   You should have received a copy of the GNU General Public License along
  *   with this program; if not, write to the Free Software Foundation, Inc.,
  *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
  
  #include "gen_common.h"
  
  /*
  R202 program-unit is main-program
  	or external-subprogram (in gen_function.cpp)
  	or module (not supported)
  	or block-data
  */
  
  void gen_fortran_program(const ParseNode & wrappers) {
  	std::string codes;
  	std::string main_code;
  	get_context().program_tree = wrappers;
  
  	FunctionInfo * program_info = add_function("", "program", FunctionInfo());
  	ParseNode script_program = gen_token(Term{ TokenMeta::NT_SUITE , "" });
  
      typedef struct module_info{
          bool is_set = false;
          std::string module_name;
          std::string module_code;
          FunctionInfo * outer_info = nullptr;
          ParseNode script_outer = gen_token(Term{ TokenMeta::NT_SUITE , "" });
          std::vector<ParseNode *> func_decls_in_module;
      }ModuleInfo;
  
      ModuleInfo minfo;
  
  
  	for (ParseNode * wrapper_ptr : get_context().program_tree)
  	{
  		ParseNode & wrapper = *wrapper_ptr;
  		if (wrapper.token_equals(TokenMeta::NT_SUITE))
  		{
  			for (int j = 0; j < wrapper.length(); j++)
  			{
  				script_program.addchild(wrapper.get(j));
  			}
  		}
  		else if (wrapper.token_equals(TokenMeta::NT_PROGRAM_EXPLICIT))
  		{
  			for (int j = 0; j < wrapper.get(0).length(); j++)
  			{
  				script_program.addchild(wrapper.get(0).get(j));
  			}
  		}
  		else if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
  		{
  			get_context().current_module = "";
  			ParseNode & variable_function = wrapper.get(1);
  			/************
  			* IMPORTANT
  			* MUST call `add_function` to all functions
  			*	, before actually call `regen_function` or `regen_vardef` to any of the functions
  			*************/
  			FunctionInfo * finfo = add_function(get_context().current_module, variable_function.get_what(), FunctionInfo{});
  		}
          else if (wrapper.token_equals(TokenMeta::NT_MODULE))
          {
              minfo.is_set=true;
              minfo.outer_info = add_function("","module",FunctionInfo{});
              minfo.module_name = wrapper.get_what();
              ModuleInfo &minfo_alias = minfo;
              for (int j = 0; j < wrapper.get(0).length(); j++)
              {
                  ParseNode &node = wrapper.get(0).get(j);
                  if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
                  {
                      minfo_alias.func_decls_in_module.push_back(&node);
                      add_function("", node.get(1).get_what(),FunctionInfo{});
                  }
                  else
                      minfo_alias.script_outer.addchild(wrapper.get(0).get(j));
              }
          }
  		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
  		{
  			get_context().current_module = "";
  			ParseNode& variable_type = wrapper.get(0);
  			TypeInfo* tinfo = add_type(get_context().current_module, variable_type.get_what(), TypeInfo{});
  		}
  		else if (wrapper.token_equals(TokenMeta::NT_DUMMY))
  		{
  			// YY_END
  		}
  		else {
  			print_error("Unexpected wrappers");
  		}
  	}
  
  	// regen all subprogram's step 1: generate subprogram's code
  	// create function, generate function body
  	get_context().current_module = "";
  	for (ParseNode * wrapper_ptr : get_context().program_tree)
  	{
  		ParseNode & wrapper = *wrapper_ptr;
  		if(wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
  		{
  			ParseNode & variable_function = wrapper.get(1);
  			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
  			regen_function_1(finfo, wrapper);
  		}
  		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
  		{
  			ParseNode& variable_type = wrapper.get(0);
  			TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
  			regen_derived_type_1(tinfo, wrapper);
  			//regen_function_1(tinfo, wrapper);
  		}
  	}
      if(minfo.is_set)
      {
  
          std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
          if (!func_decls_in_module.empty())
          {
              for (ParseNode *nodeptr:func_decls_in_module)
              {
                  ParseNode &node = *nodeptr;
                  ParseNode & variable_function = node.get(1);
                  FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
                  regen_function_1(finfo, node);
              }
          }
      }
  
      // main program code
      regen_suite(program_info, script_program);
      if(minfo.is_set)
      {
          regen_suite(minfo.outer_info,minfo.script_outer);
      }
  
  	// regen common definition
  	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
  	// if you move this code block under the "regen all subprogram's step 2" block, errors will occur when processing file *For3d14.for*
  	std::string common_decls;
  	for (std::map<std::string, CommonBlockInfo *>::value_type & pr : get_context().commonblocks)
  	{
  		string s = gen_common_definition(pr.first).get_what();
  		common_decls += s;
  	}
  
  	// regen all subprogram's step 2: generate subprogram's code
  	// generate function signature
  	for (ParseNode * wrapper_ptr : get_context().program_tree)
  	{
  		ParseNode & wrapper = *wrapper_ptr;
  		if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
  		{
  			ParseNode & variable_function = wrapper.get(1);
  			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
  			regen_function_2(finfo);
  			codes += finfo->node->get_what();
  			codes += "\n";
  		}
  		//else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
  		//{
  		//	ParseNode& variable_type = wrapper.get(0);
  		//	//ParseNode& suite = wrapper.get(1);
  		//	TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
  		//	regen_derived_type_2(tinfo);
  		//	codes += tinfo->node->get_what();
  		//	//codes += "struct " + variable_type.get_what() + "\n";
  		//	//codes += suite.get_what();
  		//	codes += "\n";
  		//}
  	}
      if(minfo.is_set)
      {
  
          std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
          if (!func_decls_in_module.empty())
          {
              for (ParseNode *nodeptr:func_decls_in_module)
              {
                  ParseNode &node = *nodeptr;
                  ParseNode & variable_function = node.get(1);
                  FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
                  regen_function_2(finfo);
                  codes += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
                  codes += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";
                  codes += finfo->node->get_what();
                  codes += "\n";
                  codes += "#endif\n";
              }
          }
      }
  
  	for (TypeInfo * tinfo : get_context().types_vec)
  	{
  			regen_derived_type_2(tinfo);
  			codes += tinfo->node->get_what();
  			codes += "\n";
  	}
  
  	// main program code
  	regen_all_variables_decl_str(program_info, script_program);
  	main_code = tabber(script_program.get_what());
      sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
      if(minfo.is_set)
      {
          regen_all_variables_decl_str(minfo.outer_info,minfo.script_outer);
          minfo.module_code = minfo.script_outer.get_what();
          sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n%s", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str(), main_code.c_str());
      }
  	codes += string(codegen_buf);
  
  	// forward declarations
  	std::string forward_decls;
  	forall_function_in_module("", [&](std::pair<std::string , FunctionInfo * > pr) {
  		FunctionInfo * finfo;
  		std::tie(std::ignore, finfo) = pr;
  		std::string name = finfo->local_name;
  		if (name != "program" && name != "" && name!="module")
  		{
  			forward_decls += gen_function_signature(finfo);
  			forward_decls += ";\n";
  		}
  	});
  
  
  	/************
  	* PROGRAM STRUCTURE
  	*
  	* common blocks
  	* forward function decls
  	* function definitions
  	* the `main` program
  	*************/
  	codes = forward_decls + codes;
  	codes = common_decls + codes;
  
  	get_context().program_tree.get_what() = codes;
  }
  ```


******

8.1 add `struct` support in module

modify only `src/target/gen_program.cpp`

```shell
diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
index 9a01fe3..60a0dd3 100755
--- a/src/target/gen_program.cpp
+++ b/src/target/gen_program.cpp
@@ -41,6 +41,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
         FunctionInfo * outer_info = nullptr;
         ParseNode script_outer = gen_token(Term{ TokenMeta::NT_SUITE , "" });
         std::vector<ParseNode *> func_decls_in_module;
+        std::vector<ParseNode *> type_decls_in_module;
     }ModuleInfo;
 
     ModuleInfo minfo;
@@ -86,8 +87,15 @@ void gen_fortran_program(const ParseNode & wrappers) {
                 if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
                 {
                     minfo_alias.func_decls_in_module.push_back(&node);
-                    add_function("", node.get(1).get_what(),FunctionInfo{});
+                    add_function(minfo_alias.module_name, node.get(1).get_what(),FunctionInfo{});
                 }
+                else if (node.token_equals(TokenMeta::NT_DERIVED_TYPE))
+                {
+                    minfo_alias.type_decls_in_module.push_back(&node);
+                    add_type(minfo_alias.module_name, node.get(0).get_what(),TypeInfo{});
+                }
+                /* function and type definition individually processed in `minfo`,
+                 * code other than those goes to `script_outer` and will be `regen_suite`ed */
                 else
                     minfo_alias.script_outer.addchild(wrapper.get(0).get(j));
             }
@@ -127,9 +135,10 @@ void gen_fortran_program(const ParseNode & wrappers) {
 			//regen_function_1(tinfo, wrapper);
 		}
 	}
+
+    /* function and type collected from inside module is treated as normal outermost definition, but with assigned module name*/
     if(minfo.is_set)
     {
-
         std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
         if (!func_decls_in_module.empty())
         {
@@ -137,10 +146,20 @@ void gen_fortran_program(const ParseNode & wrappers) {
             {
                 ParseNode &node = *nodeptr;
                 ParseNode & variable_function = node.get(1);
-                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
+                FunctionInfo * finfo = get_function(minfo.module_name, variable_function.get_what());
                 regen_function_1(finfo, node);
             }
         }
+        std::vector<ParseNode *> &type_decls_in_module = minfo.type_decls_in_module;
+        if(!type_decls_in_module.empty())
+        {
+            for(ParseNode *nodeptr:type_decls_in_module)
+            {
+                ParseNode & variable_type = nodeptr->get(0);
+                TypeInfo *tinfo = get_type(minfo.module_name,variable_type.get_what());
+                regen_derived_type_1(tinfo, *nodeptr);
+            }
+        }
     }
 
     // main program code
@@ -162,6 +181,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
 
 	// regen all subprogram's step 2: generate subprogram's code
 	// generate function signature
+    assert( get_context().current_module == "");
 	for (ParseNode * wrapper_ptr : get_context().program_tree)
 	{
 		ParseNode & wrapper = *wrapper_ptr;
@@ -187,7 +207,6 @@ void gen_fortran_program(const ParseNode & wrappers) {
 	}
     if(minfo.is_set)
     {
-
         std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
         if (!func_decls_in_module.empty())
         {
@@ -209,11 +228,21 @@ void gen_fortran_program(const ParseNode & wrappers) {
 	for (TypeInfo * tinfo : get_context().types_vec)
 	{
 			regen_derived_type_2(tinfo);
-			codes += tinfo->node->get_what();
-			codes += "\n";
-	}
+            if(minfo.is_set && std::find(minfo.type_decls_in_module.begin(), minfo.type_decls_in_module.end(),tinfo->node)!=minfo.type_decls_in_module.end())
+            {/**/
+                codes += "#ifndef "+minfo.module_name+"_"+tinfo->local_name+"\n";
+                codes += "#define "+minfo.module_name+"_"+tinfo->local_name+"\n";
+                codes += tinfo->node->get_what();
+                codes += "\n";
+                codes += "#endif\n";
+            }else
+            {
+                codes += tinfo->node->get_what();
+                codes += "\n";
+            }
+    }
 
-	// main program code
+    // main program code
 	regen_all_variables_decl_str(program_info, script_program);
 	main_code = tabber(script_program.get_what());
     sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
```


Test case

```fortran
module main
 type car
 end type car
end module main
type bat
end type bat
```

output

```cpp
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
#ifndef main_car
#define main_car
struct car
{
	
};

#endif
struct bat
{
	
};

#ifndef main
#define main


#endif
```

> file after modification (for copy&paste)

```cpp
/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"

/*
R202 program-unit is main-program
	or external-subprogram (in gen_function.cpp)
	or module (not supported)
	or block-data
*/

void gen_fortran_program(const ParseNode & wrappers) {
	std::string codes;
	std::string main_code;
	get_context().program_tree = wrappers;

	FunctionInfo * program_info = add_function("", "program", FunctionInfo());
	ParseNode script_program = gen_token(Term{ TokenMeta::NT_SUITE , "" });

    typedef struct module_info{
        bool is_set = false;
        std::string module_name;
        std::string module_code;
        FunctionInfo * outer_info = nullptr;
        ParseNode script_outer = gen_token(Term{ TokenMeta::NT_SUITE , "" });
        std::vector<ParseNode *> func_decls_in_module;
        std::vector<ParseNode *> type_decls_in_module;
    }ModuleInfo;

    ModuleInfo minfo;


	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.token_equals(TokenMeta::NT_SUITE))
		{
			for (int j = 0; j < wrapper.length(); j++)
			{
				script_program.addchild(wrapper.get(j));
			}
		}
		else if (wrapper.token_equals(TokenMeta::NT_PROGRAM_EXPLICIT))
		{
			for (int j = 0; j < wrapper.get(0).length(); j++)
			{
				script_program.addchild(wrapper.get(0).get(j));
			}
		}
		else if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			get_context().current_module = "";
			ParseNode & variable_function = wrapper.get(1);
			/************
			* IMPORTANT
			* MUST call `add_function` to all functions
			*	, before actually call `regen_function` or `regen_vardef` to any of the functions
			*************/
			FunctionInfo * finfo = add_function(get_context().current_module, variable_function.get_what(), FunctionInfo{});
		}
        else if (wrapper.token_equals(TokenMeta::NT_MODULE))
        {
            minfo.is_set=true;
            minfo.outer_info = add_function("","module",FunctionInfo{});
            minfo.module_name = wrapper.get_what();
            ModuleInfo &minfo_alias = minfo;
            for (int j = 0; j < wrapper.get(0).length(); j++)
            {
                ParseNode &node = wrapper.get(0).get(j);
                if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
                {
                    minfo_alias.func_decls_in_module.push_back(&node);
                    add_function(minfo_alias.module_name, node.get(1).get_what(),FunctionInfo{});
                }
                else if (node.token_equals(TokenMeta::NT_DERIVED_TYPE))
                {
                    minfo_alias.type_decls_in_module.push_back(&node);
                    add_type(minfo_alias.module_name, node.get(0).get_what(),TypeInfo{});
                }
                /* function and type definition individually processed in `minfo`,
                 * code other than those goes to `script_outer` and will be `regen_suite`ed */
                else
                    minfo_alias.script_outer.addchild(wrapper.get(0).get(j));
            }
        }
		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		{
			get_context().current_module = "";
			ParseNode& variable_type = wrapper.get(0);
			TypeInfo* tinfo = add_type(get_context().current_module, variable_type.get_what(), TypeInfo{});
		}
		else if (wrapper.token_equals(TokenMeta::NT_DUMMY))
		{
			// YY_END
		}
		else {
			print_error("Unexpected wrappers");
		}
	}

	// regen all subprogram's step 1: generate subprogram's code
	// create function, generate function body
	get_context().current_module = "";
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if(wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_1(finfo, wrapper);
		}
		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		{
			ParseNode& variable_type = wrapper.get(0);
			TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
			regen_derived_type_1(tinfo, wrapper);
			//regen_function_1(tinfo, wrapper);
		}
	}

    /* function and type collected from inside module is treated as normal outermost definition, but with assigned module name*/
    if(minfo.is_set)
    {
        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
        if (!func_decls_in_module.empty())
        {
            for (ParseNode *nodeptr:func_decls_in_module)
            {
                ParseNode &node = *nodeptr;
                ParseNode & variable_function = node.get(1);
                FunctionInfo * finfo = get_function(minfo.module_name, variable_function.get_what());
                regen_function_1(finfo, node);
            }
        }
        std::vector<ParseNode *> &type_decls_in_module = minfo.type_decls_in_module;
        if(!type_decls_in_module.empty())
        {
            for(ParseNode *nodeptr:type_decls_in_module)
            {
                ParseNode & variable_type = nodeptr->get(0);
                TypeInfo *tinfo = get_type(minfo.module_name,variable_type.get_what());
                regen_derived_type_1(tinfo, *nodeptr);
            }
        }
    }

    // main program code
    regen_suite(program_info, script_program);
    if(minfo.is_set)
    {
        regen_suite(minfo.outer_info,minfo.script_outer);
    }

	// regen common definition
	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
	// if you move this code block under the "regen all subprogram's step 2" block, errors will occur when processing file *For3d14.for*
	std::string common_decls;
	for (std::map<std::string, CommonBlockInfo *>::value_type & pr : get_context().commonblocks)
	{
		string s = gen_common_definition(pr.first).get_what();
		common_decls += s;
	}

	// regen all subprogram's step 2: generate subprogram's code
	// generate function signature
    assert( get_context().current_module == "");
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_2(finfo);
			codes += finfo->node->get_what();
			codes += "\n";
		}
		//else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		//{
		//	ParseNode& variable_type = wrapper.get(0);
		//	//ParseNode& suite = wrapper.get(1);
		//	TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
		//	regen_derived_type_2(tinfo);
		//	codes += tinfo->node->get_what();
		//	//codes += "struct " + variable_type.get_what() + "\n";
		//	//codes += suite.get_what();
		//	codes += "\n";
		//}
	}
    if(minfo.is_set)
    {
        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
        if (!func_decls_in_module.empty())
        {
            for (ParseNode *nodeptr:func_decls_in_module)
            {
                ParseNode &node = *nodeptr;
                ParseNode & variable_function = node.get(1);
                FunctionInfo * finfo = get_function(minfo.module_name, variable_function.get_what());
                regen_function_2(finfo);
                codes += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
                codes += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";
                codes += finfo->node->get_what();
                codes += "\n";
                codes += "#endif\n";
            }
        }
    }

	for (TypeInfo * tinfo : get_context().types_vec)
	{
			regen_derived_type_2(tinfo);
            if(minfo.is_set && std::find(minfo.type_decls_in_module.begin(), minfo.type_decls_in_module.end(),tinfo->node)!=minfo.type_decls_in_module.end())
            {/**/
                codes += "#ifndef "+minfo.module_name+"_"+tinfo->local_name+"\n";
                codes += "#define "+minfo.module_name+"_"+tinfo->local_name+"\n";
                codes += tinfo->node->get_what();
                codes += "\n";
                codes += "#endif\n";
            }else
            {
                codes += tinfo->node->get_what();
                codes += "\n";
            }
    }

    // main program code
	regen_all_variables_decl_str(program_info, script_program);
	main_code = tabber(script_program.get_what());
    sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
    if(minfo.is_set)
    {
        regen_all_variables_decl_str(minfo.outer_info,minfo.script_outer);
        minfo.module_code = minfo.script_outer.get_what();
        sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n%s", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str(), main_code.c_str());
    }
	codes += string(codegen_buf);

	// forward declarations
	std::string forward_decls;
	forall_function_in_module("", [&](std::pair<std::string , FunctionInfo * > pr) {
		FunctionInfo * finfo;
		std::tie(std::ignore, finfo) = pr;
		std::string name = finfo->local_name;
		if (name != "program" && name != "" && name!="module")
		{
			forward_decls += gen_function_signature(finfo);
			forward_decls += ";\n";
		}
	});


	/************
	* PROGRAM STRUCTURE
	*
	* common blocks
	* forward function decls
	* function definitions
	* the `main` program
	*************/
	codes = forward_decls + codes;
	codes = common_decls + codes;

	get_context().program_tree.get_what() = codes;
}
```

**patch**: an extra modification

```shell
diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
index 60a0dd3..4c5e474 100755
--- a/src/target/gen_program.cpp
+++ b/src/target/gen_program.cpp
@@ -214,7 +214,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
             {
                 ParseNode &node = *nodeptr;
                 ParseNode & variable_function = node.get(1);
-                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
+                FunctionInfo * finfo = get_function(minfo.module_name, variable_function.get_what());
                 regen_function_2(finfo);
                 codes += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
                 codes += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";

```

> Now `add_function()` is called with `module_name` of word after module keyword, so `get_function() ` for function decl nodes in module should be called with (explicitly) the module name, i.e., `minfo.module_name`



****** 
8.3 `use` statement and `module procedure` directive implemented
1. `for90.y`: add rule `YY_USE YY_WORD` that constitutes `stmt`, i.e., `YY_USE YY_WORD` is parsed as a statement; add rule `YY_MODULE YY_PROCEDURE YY_WORD` to right side of `wrapper`; modify processing of `interface_decl`; 
   ```shell
   diff --git a/src/grammar/for90.y b/src/grammar/for90.y
index 4e8cb67..7c24d4a 100755
--- a/src/grammar/for90.y
+++ b/src/grammar/for90.y
@@ -655,7 +655,7 @@ using namespace std;
 
 	function_array_body : variable '(' paramtable ')'
 			{
-				// function call OR array index 
+				// function call OR array index
 				// NOTE that array index can be A(1:2, 3:4)
 				ARG_OUT callable_head = YY2ARG($1);
 				ARG_OUT argtable = YY2ARG($3);
@@ -1011,7 +1011,14 @@ using namespace std;
 				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
 				CLEAN_DELETE($1);
 			}
-		| var_def 
+		| YY_USE YY_WORD
+
+			{
+				$$ = RETURN_NT(gen_promote("#include \"%s.h\"", TokenMeta::NT_USE, YY2ARG($2)));
+				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
+				CLEAN_DELETE($1,$2);
+			}
+		| var_def
 			{
 				$$ = $1;
 				insert_comments(YY2ARG($$));
@@ -2413,6 +2420,11 @@ using namespace std;
 				$$ = $1;
 				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
 		    }
+		| YY_MODULE YY_PROCEDURE YY_WORD
+		    {
+				$$ = $3;
+				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
+		    }
 		| function_decl
 			{
 				$$ = $1;
@@ -2477,7 +2489,7 @@ using namespace std;
 	interface_decl : YY_INTERFACE _optional_name at_least_one_end_line wrappers crlf_or_not YY_ENDINTERFACE _optional_name
 			{
 				ARG_OUT wrappers = YY2ARG($4);
-				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
+				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, $2->get_what()}, wrappers));
 				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
 				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7);
 			}
   ```
2. `Function.h`: add 2 member to `struct FunctionInfo`. `use_stmts` collects occurrence of use statement; `func_alias` records the alias function name, i.e., overloaded function.
   ```shell
   diff --git a/src/parser/Function.h b/src/parser/Function.h
index c56463b..c631399 100755
--- a/src/parser/Function.h
+++ b/src/parser/Function.h
@@ -47,6 +47,8 @@ struct FunctionInfo {
 	ParseNode * suite;
 	ParseNode * node;
 	TokenMeta_T implicit_type_config[256];
+    std::vector<ParseNode *> use_stmts;
+    std::vector < std::string> func_alias;
 	FunctionInfo() {
 		std::fill_n(implicit_type_config, 256, TokenMeta::Double_Decl);
 		for (char i = 'i'; i <= 'n'; i++)
   ```
3. add enum in `Intent.h` for `NT_USE` statement
   ```shell
   diff --git a/src/parser/Intent.h b/src/parser/Intent.h
index 12472d7..8d97029 100755
--- a/src/parser/Intent.h
+++ b/src/parser/Intent.h
@@ -360,6 +360,7 @@ namespace TokenMeta {
 		ADD_ENUM(NT_DEFINED_OPERATOR, -2051),
 		ADD_ENUM(NT_DERIVED_TYPE, -2052),
         ADD_ENUM(NT_MODULE, -2053),
+        ADD_ENUM(NT_USE, -2054),
 
 		ADD_ENUM(NT_DUMMY, -9999),
 		/***************************************
   ```
4. `codegen.h`: add new function declaration
   ```shell
   diff --git a/src/target/codegen.h b/src/target/codegen.h
index fe3f965..b320ce1 100755
--- a/src/target/codegen.h
+++ b/src/target/codegen.h
@@ -96,6 +96,7 @@ ParseNode gen_implicit_type(FunctionInfo * finfo, std::string name);
 ParseNode require_format_index(FunctionInfo * finfo, std::string format_index);
 void get_full_paramtable(FunctionInfo * finfo);
 std::string gen_function_signature(FunctionInfo * finfo, int style = 0);
+std::vector<std::string> gen_func_alias_signature(FunctionInfo * finfo);
 std::string gen_paramtable_str(FunctionInfo * finfo, const std::vector<std::string> & paramtable_info, bool with_name = true);
 
 // var def
   ```

5. now it is allowed to refer to function defined somewhere else (probably in other file) via `use module_name` statement, so the condition of function existence in `regen_function_array()` should be loosened, which now regard any new function name as defined as long as `use_stmts` of current procedure unit is non empty. As a result, `check_implicit_variable()` will not be called for that function name. **The coarse decision may lead to future bug or crash.**
   modify `gen_callable.cpp`:
   ```shell
   diff --git a/src/target/gen_callable.cpp b/src/target/gen_callable.cpp
index 6f967ae..9e55606 100755
--- a/src/target/gen_callable.cpp
+++ b/src/target/gen_callable.cpp
@@ -76,8 +76,18 @@ void regen_function_array(FunctionInfo * finfo, ParseNode & callable) {
 
 		}
 		else {
-			// variable
-			check_implicit_variable(finfo, head_name);
+            /*TODO: Finer granularity to decide whether function was defined in a module of other file.
+             * Need information cross files and/or conversions.
+             * Current policy is loose, i.e., if `use *` is present, then function of whatever name is
+             * regarded presented/defined somewhere else.
+             * The sequela is that `check_implicit_variable(finfo, head_name);` here
+             * will be called only if no `use *` statement
+             * is encountered.*/
+            if(finfo->use_stmts.empty())
+            {
+                // variable
+                check_implicit_variable(finfo, head_name);
+            }
 		}
 		string argtable_str;
 		/**************
   ```
6. `gen_function.cpp`:
   modification 6.1: function `get_full_paramtable()` will be called at the end of `regen_suite()` indirectly through `regen_all_variables()`, in the case of subroutine, function declaration in interface block is also a variable in parameter table, which will be processed in  `get_full_paramtable()` and generate function declaration for the function inside interface block, as an example:
   ```fortran
   subroutine proc(a, b, fun)
	interface
		function fun(x,y) result (fun_result)
			integer,intent(in)::x, y
			integer::fun_result
		end function
	end interface
	integer,intent(in)::a, b
	print *, fun(a, b) 
   end subroutine
   ```
   but when the function declaration in interface block is not a variable in outer code unit, the function will not be generated, which is specific to module structure with no paramtable syntactically.
   
   modification 6.2: due to `module procedure`, a function may have more than one name, so we should generate all definitions with each alias name in `regen_function_2()`. For that purpose, a new function that generates signature of each alias name and returns a vector of various signatures is defined. In coordination with that, we iterate the returned vector in `regen_function_2()` and augment the original function body with new bodies of overloaded functions.
   
   ```shell
   diff --git a/src/target/gen_function.cpp b/src/target/gen_function.cpp
index 0141d85..014f37e 100755
--- a/src/target/gen_function.cpp
+++ b/src/target/gen_function.cpp
@@ -104,6 +104,58 @@ void get_full_paramtable(FunctionInfo * finfo) {
 			print_error("parameter is not defined: " + param_name);
 		}
 	}
+    /**
+     * the code above helps generate function_decl inside another subroutine
+     * (nested function, which is a variable in another outer function), e.g.,
+     * ```fortran
+     * subroutine proc(a, b, fun)
+     *   interface
+	 *     function fun(x,y) result (fun_result)
+	 *	     integer,intent(in)::x, y
+	 *	     integer::fun_result
+	 *     end function
+	 *   end interface
+	 *   integer,intent(in)::a, b
+	 *   print *, fun(a, b)
+     * end subroutine
+     * ```
+     * the `fun` will be traversed as a variable in paramtable.
+     *
+     * following code helps generate function_decl in interface but not in the subprogram/code unit paramtable,
+     * the scenario is specific to interface inside module. A module cannot have paramtable, so the function
+     * cannot be generated through `regen_function()` call as before.
+     * e.g.,
+     * ```fortrean
+     * module ma
+     *   interface
+     *     function fun(x,y) result(fun_result)
+     *       integer, intent(in)::x,y
+     *       integer::fun_result
+     *     end function
+     *   end interface
+     * end module
+     * ```
+     * here we capture the inner function_decl and call `regen_function()` for it, mimicking the behavior above.
+     */
+    if(!get_context().current_module.empty())
+    {
+        for(VariableInfo *vinfo: finfo->funcdesc.declared_variables)
+        {
+            if (vinfo->type.token_equals(TokenMeta::Function)) {
+                // function declared in an interface block
+                ParseNode *funcdef_node = vinfo->vardef_node;
+                FunctionInfo *interface_finfo = add_function(get_context().current_module,
+                                                             vinfo->local_name,
+                                                             FunctionInfo{});
+                regen_function(interface_finfo, *funcdef_node); // regen interface function
+                if (funcdef_node->attr != nullptr) {
+                    vinfo->type = gen_type(Term{TokenMeta::Function, gen_function_signature(interface_finfo, 1)});
+                } else {
+                    print_error("Invalid interface: " + funcdef_node->get_what());
+                }
+            }
+        }
+    }
 	return;
 }
 
@@ -189,6 +241,8 @@ void regen_function_2(FunctionInfo * finfo) {
 
 	// gen signature
 	std::string signature = gen_function_signature(finfo);
+    std::vector<std::string> signatures_for_alias = gen_func_alias_signature(finfo);
+
 
 	// generate function code 
 	sprintf(codegen_buf, "%s\n{\n%s\treturn %s;\n}\n"
@@ -196,6 +250,15 @@ void regen_function_2(FunctionInfo * finfo) {
 		, tabber(oldsuite.to_string()).c_str() // code
 		, (finfo->is_subroutine() ? "" : finfo->result_name.c_str()) // add return stmt if not function
 	);
+    for(std::string sig:signatures_for_alias)
+    {
+        sprintf(codegen_buf, "%s\n%s\n{\n%s\treturn %s;\n}\n"
+                , codegen_buf
+                , sig.c_str()
+                , tabber(oldsuite.to_string()).c_str() // code
+                , (finfo->is_subroutine() ? "" : finfo->result_name.c_str()) // add return stmt if not function
+        );
+    }
 	decl_node.get_what() = string(codegen_buf);
 }
 
@@ -208,6 +271,32 @@ void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node) {
 	return;
 }
 
+std::vector<std::string> gen_func_alias_signature(FunctionInfo * finfo) {
+    bool is_subroutine = finfo->result_name.empty();
+    std::string result_type_str;
+    VariableInfo * result_vinfo = get_variable(get_context().current_module, finfo->local_name, finfo->result_name);
+    if (is_subroutine)
+    {
+        // subroutine
+        result_type_str = "void";
+    }
+    else {
+        result_type_str = gen_qualified_typestr(result_vinfo->type, result_vinfo->desc, false);
+    }
+
+    std::vector<std::string> res = std::vector<std::string>();
+    for(const std::string& func_alias:finfo->func_alias){
+        // forward declaration
+        std::string paramtblstr = gen_paramtable_str(finfo, finfo->funcdesc.paramtable_info, true);
+        sprintf(codegen_buf, "%s %s(%s)"
+                , result_type_str.c_str() // return value type, "void" if subroutine
+                , func_alias.c_str() // function name
+                , paramtblstr.c_str() // parameter list
+        );
+        res.emplace_back(codegen_buf);
+    }
+    return res;
+}
 std::string gen_function_signature(FunctionInfo * finfo, int style) {
 	bool is_subroutine = finfo->result_name == "";
 	std::string result_type_str;
   ```
7. `gen_program.cpp`:
   modification 7.1: change `FunctionInfo` structure, module name becomes "<module_name after MODULE keyword>", function local name becomes `""` (empty string). Besides, whenever processing code for module, the `get_context().current_module` is set to module name, and reset to empty string on leaving procesing. In that way, `minfo.module_name` is never explicitly used when calling `get_variable()` or `get_function()`. In the meantime, the conditionnal in forward declarations generation should be omitted (`name!="module"`, since `"module"` is substituted by empty string). 
   
   modification 7.2: if it is empty in `int main(){}`, there is no need to generate the function, which is often the case when a module file is encountered. So only if `!script_program.get_what().empty()` after trimming, the part of code will be appended to `codes`.
   
   modification 7.3: when generating forward declarations, check finction alias names, generate them together with the original one.
   
   modification 7.4: traverse the collected `use_stmts` and generate corresponding `#include *` directives.
   ```shell
   diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
index 60a0dd3..9e1a46d 100755
--- a/src/target/gen_program.cpp
+++ b/src/target/gen_program.cpp
@@ -18,6 +18,7 @@
 */
 
 #include "gen_common.h"
+#include <boost/algorithm/string.hpp>
 
 /*
 R202 program-unit is main-program
@@ -78,21 +79,22 @@ void gen_fortran_program(const ParseNode & wrappers) {
         else if (wrapper.token_equals(TokenMeta::NT_MODULE))
         {
             minfo.is_set=true;
-            minfo.outer_info = add_function("","module",FunctionInfo{});
+            minfo.outer_info = add_function(wrapper.get_what(),"",FunctionInfo{});
             minfo.module_name = wrapper.get_what();
             ModuleInfo &minfo_alias = minfo;
+            get_context().current_module = minfo.module_name;
             for (int j = 0; j < wrapper.get(0).length(); j++)
             {
                 ParseNode &node = wrapper.get(0).get(j);
                 if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
                 {
                     minfo_alias.func_decls_in_module.push_back(&node);
-                    add_function(minfo_alias.module_name, node.get(1).get_what(),FunctionInfo{});
+                    add_function(get_context().current_module, node.get(1).get_what(),FunctionInfo{});
                 }
                 else if (node.token_equals(TokenMeta::NT_DERIVED_TYPE))
                 {
                     minfo_alias.type_decls_in_module.push_back(&node);
-                    add_type(minfo_alias.module_name, node.get(0).get_what(),TypeInfo{});
+                    add_type(get_context().current_module, node.get(0).get_what(),TypeInfo{});
                 }
                 /* function and type definition individually processed in `minfo`,
                  * code other than those goes to `script_outer` and will be `regen_suite`ed */
@@ -139,6 +141,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
     /* function and type collected from inside module is treated as normal outermost definition, but with assigned module name*/
     if(minfo.is_set)
     {
+        get_context().current_module = minfo.module_name;
         std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
         if (!func_decls_in_module.empty())
         {
@@ -146,7 +149,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
             {
                 ParseNode &node = *nodeptr;
                 ParseNode & variable_function = node.get(1);
-                FunctionInfo * finfo = get_function(minfo.module_name, variable_function.get_what());
+                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
                 regen_function_1(finfo, node);
             }
         }
@@ -156,18 +159,21 @@ void gen_fortran_program(const ParseNode & wrappers) {
             for(ParseNode *nodeptr:type_decls_in_module)
             {
                 ParseNode & variable_type = nodeptr->get(0);
-                TypeInfo *tinfo = get_type(minfo.module_name,variable_type.get_what());
+                TypeInfo *tinfo = get_type(get_context().current_module,variable_type.get_what());
                 regen_derived_type_1(tinfo, *nodeptr);
             }
         }
     }
 
     // main program code
+    get_context().current_module = "";
     regen_suite(program_info, script_program);
     if(minfo.is_set)
     {
+        get_context().current_module = minfo.module_name;
         regen_suite(minfo.outer_info,minfo.script_outer);
     }
+    get_context().current_module = "";
 
 	// regen common definition
 	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
@@ -207,6 +213,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
 	}
     if(minfo.is_set)
     {
+        get_context().current_module = minfo.module_name;
         std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
         if (!func_decls_in_module.empty())
         {
@@ -225,6 +232,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
         }
     }
 
+    get_context().current_module = "";
 	for (TypeInfo * tinfo : get_context().types_vec)
 	{
 			regen_derived_type_2(tinfo);
@@ -246,27 +254,75 @@ void gen_fortran_program(const ParseNode & wrappers) {
 	regen_all_variables_decl_str(program_info, script_program);
 	main_code = tabber(script_program.get_what());
     sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
+    main_code = codegen_buf;
+    boost::trim(script_program.get_what());
+    if(!script_program.get_what().empty())
+        codes+=main_code;
     if(minfo.is_set)
     {
+        get_context().current_module = minfo.module_name;
         regen_all_variables_decl_str(minfo.outer_info,minfo.script_outer);
         minfo.module_code = minfo.script_outer.get_what();
-        sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n%s", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str(), main_code.c_str());
+        sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str());
     }
 	codes += string(codegen_buf);
 
 	// forward declarations
+    get_context().current_module = "";
 	std::string forward_decls;
 	forall_function_in_module("", [&](std::pair<std::string , FunctionInfo * > pr) {
 		FunctionInfo * finfo;
 		std::tie(std::ignore, finfo) = pr;
 		std::string name = finfo->local_name;
-		if (name != "program" && name != "" && name!="module")
+		if (name != "program" && name != "")
 		{
 			forward_decls += gen_function_signature(finfo);
 			forward_decls += ";\n";
 		}
-	});
+        if(!finfo->func_alias.empty())
+        {
+            for(std::string sig: gen_func_alias_signature(finfo))
+            {
+                forward_decls += sig;
+                forward_decls += ";\n";
+            }
+        }
+    });
+
+    get_context().current_module = minfo.module_name;
+    forall_function_in_module(get_context().current_module, [&](std::pair<std::string , FunctionInfo * > pr) {
+        FunctionInfo * finfo;
+        std::tie(std::ignore, finfo) = pr;
+        std::string name = finfo->local_name;
+        if (name != "program" && name != "")
+        {
+            forward_decls += gen_function_signature(finfo);
+            forward_decls += ";\n";
+            if(!finfo->func_alias.empty())
+            {
+                for(std::string sig: gen_func_alias_signature(finfo))
+                {
+                    forward_decls += sig;
+                    forward_decls += ";\n";
+                }
+            }
+        }
+    });
+    get_context().current_module = "";
 
+    /*construct use statements, i.e., `#include "module name"` after conversion*/
+    std::string use_statements;
+    for(ParseNode* incl:program_info->use_stmts){
+        use_statements += incl->get_what();
+        use_statements += "\n";
+    }
+    for(ParseNode* incl:minfo.outer_info->use_stmts){
+        use_statements += "#ifndef " + minfo.module_name + "\n";
+        use_statements += "#define " + minfo.module_name + "\n";
+        use_statements += incl->get_what();
+        use_statements += "\n";
+        use_statements += "#endif\n";
+    }
 
 	/************
 	* PROGRAM STRUCTURE
@@ -276,6 +332,7 @@ void gen_fortran_program(const ParseNode & wrappers) {
 	* function definitions
 	* the `main` program
 	*************/
+    codes = use_statements + codes;
 	codes = forward_decls + codes;
 	codes = common_decls + codes;
 
   ```
8. `gen_stmt.cpp`:
   8.1: in function `regen_stmt()` add rule for processing `YY_WORD` in `stmt` (the new rule added in `for90.y`), the time `regen_stmt()`is called (by `regen_suite()`), the function declarations (whether outside program or inside module structure) have been collected and registered, which means we can find then through appropriate `get_function()`. After the target function (e.g., `show_int`) is found, the alias name is recorded in `func_alias` (see modification 2) and will be referred in `gen_func_alias_signature(FunctionInfo * finfo)` (see modification 6.2).
   8.2: in function `regen_stmt()`, when `NT_USE` is encountered, record it in `use_stmts` (see modification 2) for future use (see modification 7.4). 
   ```shell
   diff --git a/src/target/gen_stmt.cpp b/src/target/gen_stmt.cpp
index e5beb43..d6fe4cd 100755
--- a/src/target/gen_stmt.cpp
+++ b/src/target/gen_stmt.cpp
@@ -274,6 +274,14 @@ std::string regen_stmt(FunctionInfo * finfo, ParseNode & stmt) {
 				vinfo->entity_variable = gen_vardef_from_default(vinfo->type, "");
 				vinfo->vardef_node = &wrapper;
 			}
+            else if(wrapper.token_equals(TokenMeta::META_WORD))
+            {
+                FunctionInfo *target_finfo =  get_function(get_context().current_module, wrapper.get_what());
+                if(target_finfo!= nullptr)
+                {
+                    target_finfo->func_alias.push_back(stmt.get_what());
+                }
+            }
 		}
 	}
 	else if (stmt.token_equals(TokenMeta::NT_DERIVED_TYPE)) {
@@ -329,6 +337,10 @@ std::string regen_stmt(FunctionInfo * finfo, ParseNode & stmt) {
 		newsuitestr += stmt.get_what();
 		newsuitestr += '\n';
 	}
+    else if (stmt.token_equals(TokenMeta::NT_USE)) {
+        if(std::find(finfo->use_stmts.begin(), finfo->use_stmts.end(),&stmt)==finfo->use_stmts.end())
+            finfo->use_stmts.push_back(&stmt);
+    }
 	else if (stmt.token_equals(TokenMeta::ConfigImplicit))
 	{
 		ParseNode & type_decl = stmt.get(0);

   ```
9. `gen_type.cpp`
   modification (see comment):
    ```shell
    diff --git a/src/target/gen_type.cpp b/src/target/gen_type.cpp
index cd6ebca..36616ac 100755
--- a/src/target/gen_type.cpp
+++ b/src/target/gen_type.cpp
@@ -197,7 +197,15 @@ void regen_type(ParseNode & type_decl, FunctionInfo * finfo, VariableInfo * vinf
 	else if (type_decl.token_equals(TokenMeta::Function_Decl))
 	{
 		// generate `std::function`
-		type_decl.get_what() = gen_function_signature(finfo, 1);
+
+        /* the assignment will be rewritten later in `gen_full_paramtble()`.
+         * In addition, the `FunctionInfo` struct of the function type is
+         * introduced later, the `finfo` here is of the function to which the
+         * variable in question belongs.
+         * Might be a bug. So we comment out this line here, hoping that
+         * the signature will be effectively generated in `gen_full_paramtble()`*/
+		//type_decl.get_what() = gen_function_signature(finfo, 1);
+
 		type_decl.get_token() = TokenMeta::Function;
 	}
 	else {

    ```
    

test case
```fortran 
    module ma
    implicit none
    interface show
    module procedure  show_int
    module procedure  show_character
    end interface

    contains
    subroutine show_int(n)
    implicit none
    integer,intent(in)::n
    write(*,"('n=',i3)")n
    end subroutine show_int

    subroutine show_character(str)
    implicit none
    character(len=4),intent(in)::str
    write(*,"('str=',A)")str
    end subroutine show_character

    end module
```

output
```cpp
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
void show_character(const string & str);
void show(const string & str);
void show_int(const int & n);
void show(const int & n);
#ifndef ma_show_character
#define ma_show_character
void show_character(const string & str)
{
	forwrite(stdout, IOFormat{"str=%s\n", 0}, str);
	
	return ;
}

void show(const string & str)
{
	forwrite(stdout, IOFormat{"str=%s\n", 0}, str);
	
	return ;
}

#endif
#ifndef ma_show_int
#define ma_show_int
void show_int(const int & n)
{
	forwrite(stdout, IOFormat{"n=%3d\n", 0}, n);
	
	return ;
}

void show(const int & n)
{
	forwrite(stdout, IOFormat{"n=%3d\n", 0}, n);
	
	return ;
}

#endif
#ifndef ma
#define ma


#endif

```

source code is available on `https://github.com/YHN-ice/CFortranTranslator`, the modifications is much more precise in github's commit history detail (side by side diff).

**patch**, `use` statement in `function_decl` (both outer most definition and inside module/after `contains` statement) should also be collected
10. modify `gen_program.cpp`:
   ```shell
   diff --git a/src/target/gen_program.cpp b/src/target/gen_program.cpp
index 9e1a46d..87be12d 100755
--- a/src/target/gen_program.cpp
+++ b/src/target/gen_program.cpp
@@ -324,6 +324,45 @@ void gen_fortran_program(const ParseNode & wrappers) {
         use_statements += "#endif\n";
     }
 
+    /* collect `use statement` inside function (outermost and after contains stmt in module) */
+    /* outermost */
+    for (ParseNode * wrapper_ptr : get_context().program_tree) {
+        ParseNode &wrapper = *wrapper_ptr;
+        if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE)) {
+            ParseNode &variable_function = wrapper.get(1);
+            FunctionInfo *finfo = get_function(get_context().current_module, variable_function.get_what());
+            for(ParseNode* incl: finfo->use_stmts)
+            {
+                use_statements+=incl->get_what();
+                use_statements+="\n";
+            }
+        }
+    }
+    /* function declared inside module */
+    if(minfo.is_set)
+    {
+        get_context().current_module = minfo.module_name;
+        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
+        if (!func_decls_in_module.empty())
+        {
+            for (ParseNode *nodeptr:func_decls_in_module)
+            {
+                ParseNode &node = *nodeptr;
+                ParseNode & variable_function = node.get(1);
+                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
+                for(ParseNode* incl: finfo->use_stmts)
+                {
+                    use_statements += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
+                    use_statements += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";
+                    use_statements += incl->get_what();
+                    use_statements += "\n";
+                    use_statements += "#endif\n";
+                }
+            }
+        }
+        get_context().current_module = "";
+    }
+
 	/************
 	* PROGRAM STRUCTURE
 	*
   ```
test case
```fortran
    module ma
    use bee
    implicit none
    interface show
      subroutine fun
      end subroutine
    end interface
    contains
    function fff
    use ccc
    end function

    end module
```

output
```cpp
/**********************************************************************/
/* File:                                                              */
/* Author:                                                            */
/* This codes is generated by CFortranTranslator                      */
/* CFortranTranslator is published under GPL license                  */
/* refer to https://github.com/CalvinNeo/CFortranTranslator/ for more */
/**********************************************************************/
#include "../for90std/for90std.h" 
#define USE_FORARRAY 
void fff();
void fun();
#ifndef ma
#define ma
#include "bee.h"
#endif
#ifndef ma_fff
#define ma_fff
#include "ccc.h"
#endif
#ifndef ma_fff
#define ma_fff
void fff()
{
	
	return ;
}

#endif
#ifndef ma
#define ma

#endif
```

