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

7.18, reverse traversing order when generating type definition codes

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
