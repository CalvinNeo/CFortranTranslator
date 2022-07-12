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
%token /*_YY_OP*/ YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS YY_EXPONENT YY_PLET YY_PNULL YY_CDATA
%token /*_YY_TYPE*/ YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR /* Lead to error YY_OPERATOR_UNARY */ YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE YY_FORMAT_STMT YY_COMMENT
%token /*_YY_CONTROL_FLOW*/ YY_LABEL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_EXIT YY_CYCLE YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT 
%token /*_YY_DELIM*/ YY_TYPE YY_ENDTYPE YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA
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
		| inner_variable
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
			
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
		| YY_CDATA argtable '/' argtable '/'
		    {
		 	ARG_OUT exp1 = YY2ARG($2);
         	ARG_OUT exp2 = YY2ARG($4);
         	std::string rule;
         	if(exp1.length()==1)
         	{
         	}
         	else
         	{
         	    ParseNode * middle;
		        for (int i = 0; i < exp2.length(); i++)
                {
                    ParseNode & lelem = exp1.get(i);
                    ParseNode & relem = exp2.get(i);
				    ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s;" });
					ParseNode outcome = gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, lelem, relem, opnew);
					if(middle.())
                }
         	}
			ParseNode opnew = gen_token(Term{ TokenMeta::Let, rule });
			$$ = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
			update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
			CLEAN_DELETE($1, $2, $3, $4, $5);
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

	function_decl : dummy_function_iden _optional_function YY_WORD '(' paramtable ')' _optional_result at_least_one_end_line suite _optional_endfunction
			{
				ARG_OUT variable_function = YY2ARG($3); // function name
				// enumerate parameter list 
				ARG_OUT paramtable = YY2ARG($5);
				ARG_OUT variable_result = YY2ARG($7); // result variable
				ARG_OUT suite = YY2ARG($9);

				ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flattened parameter list with all keyvalue elements
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
				$$ = RETURN_NT(newnode);

				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($10));
				CLEAN_DELETE($1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
			}	
		| dummy_function_iden _optional_function YY_WORD at_least_one_end_line suite _optional_endfunction
			{
				ARG_OUT variable_function = YY2ARG($3); // function name
				ARG_OUT suite = YY2ARG($5);

				ParseNode kvparamtable = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				ParseNode void_return = gen_token(Term{ TokenMeta::UnknownVariant, "" });
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
				$$ = RETURN_NT(newnode);

				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_DELETE($1, $2, $3, $4, $5, $6);
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
