# step 1

define the token value in `Intent.h`

```h
		ADD_ENUM(PLET, 460),
```

and, `IntentHelper.cpp` might need change too

```cpp
	,{ 460, "PLET" }
```

# step 2
add term definition in tokenizer.cpp

```cpp
, KeywordMeta{"=>"
			, TokenMeta::PLET
			, YY_PLET
	}
```
# step 3 
finally we can modify the yacc file

```yacas
// add token just defined in tokenizer.cpp
%token /*_YY_OP*/ ...YY_PLET
//...
//then modify the rule of let_stmt, we need '=>' as well as '=' to be recognized as assignment

	let_stmt : exp YY_PLET exp
			{
			    //printf("in rule =>");
				ARG_OUT exp1 = YY2ARG($1);
				ARG_OUT op = YY2ARG($2);
				ARG_OUT exp2 = YY2ARG($3);
				//this is the only place that differ
				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s =& %s" });
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
```



# step 4 *most important*

we need `=>` to be generated as a whole token of length 2, rather than two token

add some tweak besides the processing of `==`

```cpp
	else if (ch == '=')
	{
		res += ch;
		ch2 = pull_complete_char();
		// "=="
		if (ch2 == '=')//= followed by =
		{
			res += ch2;
		}
		else if (ch2 == '>') {// we need = follow by >
			//printf("gotcha.");
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
```



# Done 🎉🎉🎉

TODO:

if `car1`is a pointer as in `type(car),pointer::car1`, then there is no way to determine it is a pointer when we later access its member in `car1%speed`, which should be `car1.speed` if `car1` was previously defined as a non-pointer, or `car1->speed` if `car1` was a pointer.

We can't get the information of variable definition(which could be miles or pages before) when accessing its member a long while later... actually, *CFortranTranslater* even convert a variable without it having been defined. TAT

