## inquire
```shell
program main
 implicit none
 logical alive
          inquire(file="xx",exist=alive)
          if(.not.alive) then 
            write(*,*) "no"
           endif
end program
```
1.`gen_config.h`
line 106 add
```shell
    , { "forinquire", { { "unit", "int", "" }, { "file", "string", "" }, { "iostat", "int", "" }, { "err", "forlabel", "" }, { "exist", "bool", ""} } }
```
2.`gen_config.h`
line 82 add

```shell
    , { "inquire", "forinquire" }
```
3.`forfilesys.h`
add include line
`#include "io.h"`
and function declaration:
```shell
void forinquire(foroptional<int> unit, foroptional<std::string> file, foroptional<int> iostat, foroptional<forlabel> err, bool &exist);
```

4.`forfilesys.cpp`
add function:
```shell
void forinquire(foroptional<int> unit, foroptional<std::string> file, foroptional<int> iostat, foroptional<forlabel> err, bool &exist) {
	if (!forfilesys_inited) flush_fileno();
	bool result;
	result = (access(file.get().c_str(), 0)==0);
	exist = result;
}
```
todo:
parameter "recl" 

## float
can not print float value in `forwritefree()`

`forstdio.h`
add inline function in `struct IOFormat`
line 400

```shell
// free format
// write free step 2
inline void _forwritefree_one(FILE* f, float x) {
	fprintf(f, "%f", x);
};
```
## fullR,singR,fullI,singI,singL
the same expression:
real(fullR)::k=2.0
real(kind=8)::k=2.0

singR singI singL: kind=4
fullR fullI: kind=8

1.add 5 TOKEN  in `for90.y`
line108: add `YY_SINGR YY_FULLR YY_SINGI YY_FULLI YY_SINGL`after YY_KIND

```shell
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
		| YY_SINGR
		    {
			    int kind = 4;
		        ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
			}
		| YY_FULLR
		    {
			    int kind = 8;
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
			}
		| YY_SINGI
		   {
			    int kind = 4;
		        ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
			}
		| YY_FULLI
	       {
			    int kind = 8;
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
			}
		| YY_SINGL
		   {
			    int kind = 4;
		        ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1);
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
```

2.`tokenizer.cpp`
add 5 KeywordMeta between "kind" and "call"
```shell
	, KeywordMeta{ "kind"
		, TokenMeta::META_ANY
		, YY_KIND
	}
	, KeywordMeta{ "singr"
	    , TokenMeta::META_ANY
	    , YY_SINGR
	}
	, KeywordMeta{ "fullr"
		, TokenMeta::META_ANY
		, YY_FULLR
	}
	, KeywordMeta{ "singi"
		, TokenMeta::META_ANY
		, YY_SINGI
	}
	, KeywordMeta{ "fulli"
		, TokenMeta::META_ANY
		, YY_FULLI
    }
	, KeywordMeta{ "singl"
		, TokenMeta::META_ANY
		, YY_SINGL
	}
	, KeywordMeta{ "call"
		, TokenMeta::META_ANY
		, YY_CALL
	}
```

