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
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include <tuple>
#include "../tokenizer.h"
#include "../attribute.h"
#include "../parser.h"
#include "../gen_config.h"
#include "../Function.h"
#include "../codegen.h"


// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
#define YYLEX advanced_yylex()
// static is necessary, or will cause lnk
static char codegen_buf[MAX_CODE_LENGTH];

/* update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) */
void update_pos(ParseNode & current) {
	if (current.child.size() == 0) {
		/* do nothing */
		current.fs.parse_pos = 0;
		current.fs.parse_line = 0;
		current.fs.parse_len = 0;
		current.fs.line_pos = 0;
	}
	else if (current.child.size() == 1) {
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = current.get(0).fs.parse_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.child.size(); i++)
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
%token /*_YY_OP*/ YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS
%token /*_YY_TYPE*/ YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE YY_FORMAT_STMT YY_COMMENT
%token /*_YY_CONTROL*/ YY_LABEL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_EXIT YY_CYCLE YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT 
%token /*_YY_DELIM*/ YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA
%token /*_YY_DESCRIBER*/ YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_ENTRY YY_DIMENSION YY_ARRAYINITIAL_START YY_ARRAYINITIAL_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND YY_SAVE
%token /*_YY_TYPEDEF*/ YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T
%token /*_YY_COMMAND*/ YY_WRITE YY_READ YY_PRINT YY_CALL  YY_STOP YY_PAUSE YY_RETURN


%left YY_EQV YY_NEQV
%left YY_OROR
%left YY_ANDAND
%right YY_NOT
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%right YY_NEG YY_POS
%left '+' '-' 
%left '*' '/' 
%right YY_POWER /* x**y**z -> x**(y**z) */

%start fortran_program

%%

	crlf_or_not : YY_CRLF
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1)); 
				CLEAN_RIGHT($1);
			}
		|
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Nop, "" }));
				update_pos(YY2ARG($$));
			}
		
	at_least_one_end_line : YY_CRLF
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| at_least_one_end_line YY_CRLF
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
		| semicolon
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| at_least_one_end_line semicolon
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}

	semicolon : ';'
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Semicolon, ";" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
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
				CLEAN_RIGHT($1);
			}
		|
			{
				$$ = RETURN_NT(gen_dummy());
				update_pos(YY2ARG($$));
			}

	variable_desc_elem : YY_INTENT '(' YY_IN ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| YY_INTENT '(' YY_OUT ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}

		| YY_INTENT '(' YY_INOUT ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| YY_DIMENSION '(' dimen_slice ')'
			{
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ARG_IN dimen_slice = YY2ARG($3);
				ParseNode attr = gen_variabledesc_from_dimenslice(dimen_slice);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }, attr);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| YY_DIMENSION '(' exp ')'
			{
				/* define array like a(1) */
				ARG_IN exp_to = YY2ARG($3);

				ParseNode slice = promote_exp_to_slice(exp_to);

				ParseNode attr = gen_variabledesc_from_dimenslice(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }, attr);

				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| YY_OPTIONAL
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_PARAMETER
			{
				/* const value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_SAVE
			{
				/* static value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
				
	variable_desc : ',' variable_desc_elem variable_desc
			{
				ParseNode variable_elem = YY2ARG($2);
				ParseNode variable_desc = YY2ARG($3);
				/* target code of slice depend on context */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				/* merge attrs */
				newnode.setattr(variable_elem.attr->clone());
				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		|
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
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
				ARG_IN integer = YY2ARG($1);
				sscanf(integer.to_string().c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| YY_LEN '=' exp
			{
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				ARG_IN integer = YY2ARG($1);
				sscanf(integer.to_string().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	literal : YY_FLOAT
			{
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此YY2ARG($1)全部来自lex程序 */
				ARG_IN lit = YY2ARG($1);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.to_string() }));// float number
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_INTEGER
			{
				ARG_IN lit = YY2ARG($1);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.to_string() }));// int number
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_STRING
			{
				// replace `'` with `"`
				ARG_IN lit = YY2ARG($1);
				std::string s = lit.to_string().substr(1, lit.to_string().size() - 2);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_TRUE
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_FALSE
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_COMPLEX
            {
				ARG_IN lit = YY2ARG($1);
				string strcplx = lit.to_string();
				auto splitter = strcplx.find_first_of('_', 0);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}

		| error '\n'
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($2);
			}

	variable : YY_WORD
			{
				ARG_IN lit = YY2ARG($1);
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.to_string() });
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
	/*
		R618 section - subscript is subscript
			or subscript - triplet
			or vector - subscript
		R619 subscript - triplet is[subscript] : [subscript] [: stride]
		R620 stride is scalar - int - expr
		R621 vector - subscript is int - expr
	*/
	slice : exp ':' exp
			{
				/* arr[from : to] */
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN exp2 = YY2ARG($3);
				/* target code of slice depend on context */
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to : step] */
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN exp2 = YY2ARG($3);
				ARG_IN exp3 = YY2ARG($5);
				/* target code of slice depend on context */
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2, exp3));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
				CLEAN_RIGHT($1, $2, $3, $4, $5);
			}
		| ':'
			{
				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ARG_IN lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.to_string() }, from);
				ARG_IN ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.to_string() }, to);
				/* target code of slice depend on context */
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}

	keyvalue : exp '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				/* array_builder is exp */
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_keyvalue_from_exp(YY2ARG($1), YY2ARG($3)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	argtable : exp
			{
				/* argtable is used in function call */
				ARG_IN exp = YY2ARG($1);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.to_string()}, exp);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| argtable ',' exp
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN argtable = YY2ARG($1);
				$$ = RETURN_NT(gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	dimen_slice : slice 
			{
				/* 1d array */
				/* arr[from : to] */
				/* target code of slice depend on context */
				ARG_IN slice = YY2ARG($1);
				// only 1 slice
				$$ = RETURN_NT(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| dimen_slice ',' slice
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ARG_IN slice = YY2ARG($3);
				ARG_IN dimen_slice = YY2ARG($1);
				$$ = RETURN_NT(gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| dimen_slice ',' exp
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ARG_IN exp = YY2ARG($3);
				ARG_IN dimen_slice = YY2ARG($1);
				$$ = RETURN_NT(gen_flattern(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| argtable ',' slice
			{
				ARG_IN slice = YY2ARG($3);
				ARG_IN argtable = YY2ARG($1);
				ParseNode newnode = ParseNode();
				if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE)
				{
					newnode = gen_flattern(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				}
				else {
					print_error("Illegal dimen_slice", argtable);
				}
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	function_array_body : variable '(' paramtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ARG_IN callable_head = YY2ARG($1);
				ARG_IN argtable = YY2ARG($3);
				ParseNode newnode = gen_function_array(callable_head, argtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| type_name '(' paramtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ARG_IN callable_head = YY2ARG($1);
				ARG_IN argtable = YY2ARG($3);
				ParseNode newnode = gen_function_array(callable_head, argtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
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
				CLEAN_RIGHT($1);
			}

	exp : function_array 
			{
				/* function call OR array index */
				ARG_IN function_array = YY2ARG($1);
				$$ = $1;
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, function_array.to_string()}, function_array));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				//CLEAN_RIGHT($1);
			}
		| array_builder
			{
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ARG_IN array_builder_elem = YY2ARG($1);
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
			
		| exp '(' exp ')'
			{
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s(%s)", TokenMeta::NT_EXPRESSION, exp1, exp2, gen_token(Term{TokenMeta::OperatorCall, ""})));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| '(' exp ')' 
			{
				/* `function_array` rule has priority over this rule  */
				ARG_IN exp = YY2ARG($2);
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				$$ = RETURN_NT(gen_promote("( %s )", TokenMeta::NT_EXPRESSION, exp, gen_token(Term{ TokenMeta::LB, "" })));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp '+' exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s + %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp '-' exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s - %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp '*' exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s * %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp '/' exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s / %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_POWER exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("power(%s, %s)", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
        | '-' %prec YY_NEG exp 
			{
				ARG_IN exp1 = YY2ARG($2);
				ARG_IN op = YY2ARG($1);
				$$ = RETURN_NT(gen_promote("(-%s)", TokenMeta::NT_EXPRESSION, exp1, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
        | '+' %prec YY_NEG exp 
			{
				ARG_IN exp1 = YY2ARG($2);
				ARG_IN op = YY2ARG($1);
				$$ = RETURN_NT(gen_promote("%s", TokenMeta::NT_EXPRESSION, exp1, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
		| exp YY_NEQ exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s != %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_NEQV exp 
			{
				// xor
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s ^ %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_EQ exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s == %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_EQV exp 
			{
				// nor
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("!(%s ^ %s)", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_ANDAND exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s && %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_OROR exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s || %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| YY_NOT exp 
			{
				ARG_IN exp1 = YY2ARG($2);
				ARG_IN op = YY2ARG($1);
				$$ = RETURN_NT(gen_promote("!(%s)", TokenMeta::NT_EXPRESSION, exp1, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
		| exp YY_GT exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s > %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_GE exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s >= %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| exp YY_LE exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s <= %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
			}
		| exp YY_LT exp 
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s < %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| hidden_do
			{
				ARG_IN hidden_do = YY2ARG($1);
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, hidden_do.to_string() }, hidden_do));
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| literal 
            { 
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| variable
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}

	stmt : exp 
			{
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加YY2ARG($1)位stmt节点的唯一的儿子
				*/
				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| var_def 
			{
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
        | compound_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
        | output_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| input_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| dummy_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| let_stmt
			{
				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| common_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| YY_FORMAT_STMT
			{
				$$ = RETURN_NT(gen_format(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_COMMENT
			{ 
				ARG_IN comment = YY2ARG($1);
				$$ = RETURN_NT(gen_token(Term{TokenMeta::Comments, "/*" + comment.to_string() + "*/"}));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| control_stmt
			{
				$$ = $1;
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
				CLEAN_RIGHT($1);
			}
		| stop_stmt 
			{
				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_CONTINUE
			{
				$$ = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}		
		| YY_RETURN
			{
				$$ = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}			
		| jump_stmt
			{
				$$ = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}

    output_stmt : write
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| print
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}

	input_stmt : read
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
				CLEAN_RIGHT($1);
			}
		| YY_EXIT
			{
				$$ = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_GOTO YY_INTEGER
			{
				ARG_IN line = YY2ARG($2);
				$$ = RETURN_NT(gen_token(Term{TokenMeta::Goto, "goto " + line.to_string() + ";\n"}));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}

	pause_stmt : YY_PAUSE literal
			{
				ARG_IN lit = YY2ARG($2);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.to_string() + ");system(\"pause\")" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
		| YY_PAUSE
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "system(\"pause\")" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
	stop_stmt : YY_STOP literal
		{
			ARG_IN lit = YY2ARG($2);
			$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.to_string() + ");\nsystem(\"pause\")" }));
			update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
			CLEAN_RIGHT($1, $2);
		}
	| YY_STOP
		{
			$$ = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "system(\"pause\")" }));
			update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			CLEAN_RIGHT($1);
		}

	let_stmt : exp '=' exp
			{
				ARG_IN exp1 = YY2ARG($1);
				ARG_IN op = YY2ARG($2);
				ARG_IN exp2 = YY2ARG($3);
				$$ = RETURN_NT(gen_promote("%s = %s", TokenMeta::NT_EXPRESSION, exp1, exp2, op));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	dummy_stmt : YY_IMPLICIT YY_NONE
			{
				// dummy stmt
				$$ = RETURN_NT(gen_dummy());
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}

	labeled_stmt : YY_LABEL stmt
			{
				ARG_IN label = YY2ARG($1); // TokenMeta::Label
				ARG_IN stmt = YY2ARG($2);
				if (stmt.fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{
					log_format_index(label.to_string(), stmt.get(0)); 
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , "LABEL FORMAT GENERATED IN REGEN_SUITE" }, label, stmt);// do not print format stmt
					$$ = RETURN_NT(newnode);
				}
				else {
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , "LABEL GENERATED IN REGEN_SUITE" }, label, stmt);
					$$ = RETURN_NT(newnode);
				}
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}

	suite : labeled_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}
		| labeled_stmt end_of_stmt suite
			{
				ARG_IN labeled_stmt = YY2ARG($1);
				ARG_IN suite = YY2ARG($3);				
				$$ = RETURN_NT(gen_merge(labeled_stmt, suite, "%s\n%s", TokenMeta::NT_SUITE));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
				
		| stmt end_of_stmt suite
			{
				ARG_IN stmt = YY2ARG($1); 
				ARG_IN suite = YY2ARG($3);
				$$ = RETURN_NT(gen_flattern(stmt, suite, "%s\n%s", TokenMeta::NT_SUITE));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| stmt
			{
				ARG_IN stmt = YY2ARG($1); 
				$$ = RETURN_NT(gen_promote("%s\n", TokenMeta::NT_SUITE, stmt));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
				
		| interface_decl
			{
				$$ = RETURN_NT(gen_promote("", TokenMeta::NT_SUITE, YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| interface_decl end_of_stmt suite
			{
				$$ = RETURN_NT(gen_flattern(YY2ARG($1), YY2ARG($3), "%s%s", TokenMeta::NT_SUITE));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	_optional_device : '*'
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::META_NONTERMINAL, "-1" })); // -1 stands for stdin/stdout, and will be translated at read/write stmt
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_INTEGER
			{
				ARG_IN integer = YY2ARG($1);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::META_NONTERMINAL, integer.to_string() }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
	_optional_formatter : '*'
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_INTEGER
			{
				// use format stmt at line YY2ARG($1) to format
				ARG_IN integer = YY2ARG($1);
				std::string location_label = integer.to_string();
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| YY_STRING
			{
				// replace `'` with `"`
				ARG_IN s = YY2ARG($1);
				string modified = "\"" + s.to_string().substr(1, s.to_string().size() - 2) + "\"";
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER, modified }));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
	/**
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
	**/
	io_info : '(' _optional_device ',' _optional_formatter ')'
			{
				ARG_IN _optional_device = YY2ARG($2);
				ARG_IN _optional_formatter = YY2ARG($4);
				/* target code of io_info depend on context, can be either iostream/cstdio */
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
				CLEAN_RIGHT($1, $2, $3, $4, $5);
			}
		| _optional_formatter ','
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" });
				ARG_IN _optional_formatter = YY2ARG($1);
				/* target code of io_info depend on context */
				ParseNode _optional_device = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}


    write : YY_WRITE io_info paramtable 
			{
				ARG_IN io_info = YY2ARG($2);
				ARG_IN argtable = YY2ARG($3);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, "WRITE GENERATED IN REGEN_SUITE" }, io_info, argtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	print : YY_PRINT io_info paramtable
			{
				ARG_IN io_info = YY2ARG($2);
				ARG_IN argtable = YY2ARG($3);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, "PRINT GENERATED IN REGEN_SUITE" }, io_info, argtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}


	read: YY_READ io_info paramtable
			{
				ARG_IN io_info = YY2ARG($2);
				ARG_IN argtable = YY2ARG($3);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, "READ GENERATED IN REGEN_SUITE" }, io_info, argtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	type_name : YY_INTEGER_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_FLOAT_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_STRING_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_COMPLEX_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_BOOL_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
        | YY_CHARACTER_T 
			{
				$$ = RETURN_NT(gen_type(YY2ARG($1)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}

    type_spec : type_name '(' type_selector ')'
			{
				// now translated in pre_map
				$$ = RETURN_NT(gen_type(YY2ARG($1), YY2ARG($3)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| type_name '*' YY_INTEGER
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($2, $3);
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
				CLEAN_RIGHT($1, $3);
			}
		| '/' '/'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
		|
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$));
			}

	common_stmt : YY_COMMON _blockname_or_none paramtable
			{
				ARG_IN blockname = YY2ARG($2);
				ARG_IN paramtable = YY2ARG($3);
				$$ = RETURN_NT(gen_common(blockname, paramtable));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

    var_def : type_spec variable_desc YY_DOUBLECOLON paramtable
			{
				/* array decl */
				ARG_IN type_spec = YY2ARG($1);
				ARG_IN variable_desc = YY2ARG($2);
				ARG_IN paramtable = YY2ARG($4);

				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $3, $4);
			}
		| type_spec variable_desc paramtable
			{
				/* array decl */
				ARG_IN type_spec = YY2ARG($1);
				ARG_IN variable_desc = YY2ARG($2);
				ARG_IN paramtable = YY2ARG($3);

				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		/* no shift-reduce confliction */
		| YY_DIMENSION paramtable
			{
				// array decl 
				ARG_IN paramtable = YY2ARG($2);
				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
				ParseNode variable_desc = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(variable_desc, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
			
    
	pure_paramtable : keyvalue
			{
				ARG_IN paramtable_elem = YY2ARG($1);
				ParseNode newnode = gen_paramtable(paramtable_elem);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| pure_paramtable ',' keyvalue
			{
				ARG_IN paramtable_elem = YY2ARG($3);
				ARG_IN paramtable = YY2ARG($1);
				ParseNode newnode = gen_paramtable(paramtable_elem, paramtable);
				$$ = RETURN_NT(newnode);
				CLEAN_RIGHT($1, $2, $3);
			}				
		| pure_paramtable ',' exp
			{
				ARG_IN paramtable_elem = YY2ARG($3);
				ARG_IN paramtable = YY2ARG($1);
				ParseNode newnode = gen_paramtable(promote_exp_to_keyvalue(paramtable_elem), paramtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		| argtable ',' keyvalue
			{
				ARG_IN paramtable_elem = YY2ARG($3);
				ARG_IN paramtable = YY2ARG($1);
				ParseNode newnode = gen_paramtable(paramtable_elem, paramtable);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
		|
			{
				/* no params */
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
				/* something like `abs(i), i=1,4` */
				/*
				R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
				R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
				■ scalar - int - expr[, scalar - int - expr]
				*/
				ARG_IN argtable = YY2ARG($2);
				ARG_IN index = YY2ARG($4);
				ARG_IN from = YY2ARG($6);
				ARG_IN to = YY2ARG($8);
				$$ = RETURN_NT(gen_hiddendo(argtable, index, from, to));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($9));
			}

	array_builder_elem : YY_ARRAYINITIAL_START paramtable YY_ARRAYINITIAL_END
			{
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				$$ = RETURN_NT(gen_array_from_paramtable(YY2ARG($2)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
			/*
		| YY_ARRAYINITIAL_START hidden_do YY_ARRAYINITIAL_END
			{
				// give generate stmt 
				ARG_IN hidden_do = YY2ARG($2);
				$$ = RETURN_NT(gen_array_from_hiddendo(hidden_do));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}
			*/

	/* array_builder can accept mixed */
	array_builder : array_builder_elem
			{
				ARG_IN array_builder_elem = YY2ARG($1);
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}

	
	_optional_construct_name : YY_WORD ':'
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($2);
			}
		|
			{
				$$ = RETURN_NT(gen_dummy());
				update_pos(YY2ARG($$));
			}
	
	if_stmt : _optional_construct_name YY_IF '(' exp ')' stmt 
			{
				ARG_IN exp = YY2ARG($4);
				ARG_IN stmt_true = YY2ARG($6);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "" }, exp, stmt_true, gen_dummy(), gen_dummy());
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line /* must have \n */ suite YY_ENDIF
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN suite_true = YY2ARG($6);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "IF GENERATED IN REGEN_SUITE" }, exp, suite_true, gen_dummy(), gen_dummy());
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite YY_ELSE at_least_one_end_line suite YY_ENDIF
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN suite_true = YY2ARG($6);
				ARG_IN suite_else = YY2ARG($9);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "IF GENERATED IN REGEN_SUITE" }, exp, suite_true, gen_dummy(), suite_else);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($10));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite elseif_stmt YY_ENDIF
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN suite_true = YY2ARG($6);
				ARG_IN elseif = YY2ARG($7);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "IF GENERATED IN REGEN_SUITE" }, exp, suite_true, elseif, gen_dummy());
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($8));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite elseif_stmt YY_ELSE at_least_one_end_line suite YY_ENDIF
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN suite_true = YY2ARG($6);
				ARG_IN elseif = YY2ARG($7);
				ARG_IN suite_else = YY2ARG($10);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "IF GENERATED IN REGEN_SUITE" }, exp, suite_true, elseif, suite_else);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($11));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11);
			}

	elseif_stmt : YY_ELSEIF exp YY_THEN at_least_one_end_line suite
			{
				ARG_IN exp = YY2ARG($2);
				ARG_IN suite_true = YY2ARG($5);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, "ELSEIF GENERATED IN REGEN_SUITE" }, exp, suite_true, gen_dummy());
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
				CLEAN_RIGHT($1, $2, $3, $4, $5);
			}

		| YY_ELSEIF exp YY_THEN at_least_one_end_line suite elseif_stmt
			{
				ARG_IN exp = YY2ARG($2);
				ARG_IN suite_true = YY2ARG($5);
				ARG_IN elseif = YY2ARG($6);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, "ELSEIF GENERATED IN REGEN_SUITE" }, exp, suite_true, elseif);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
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
				ARG_IN suite = YY2ARG($4);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, "DO-BARE GENERATED IN REGEN_SUITE" }, suite);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($5));
				CLEAN_RIGHT($1, $2, $3, $4, $5);
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
				ARG_IN loop_variable = YY2ARG($4);
				ARG_IN exp_from = YY2ARG($6);
				ARG_IN exp_to = YY2ARG($8);
				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER , "1" });
				ARG_IN step = gen_token(Term{ TokenMeta::NT_EXPRESSION , from.to_string()}, from);
				ARG_IN suite = YY2ARG($10);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, "DO-RANGE GENERATED IN REGEN_SUITE" }, loop_variable, exp_from, exp_to, step, suite);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($12));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12);
			}
		| _optional_construct_name YY_DO _optional_label_construct variable '=' exp ',' exp ',' exp at_least_one_end_line suite crlf_or_not YY_ENDDO
			{
				ARG_IN loop_variable = YY2ARG($4);
				ARG_IN exp_from = YY2ARG($6);
				ARG_IN exp_to = YY2ARG($8);
				ARG_IN step = YY2ARG($10);
				ARG_IN suite = YY2ARG($12);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, "DO-RANGE GENERATED IN REGEN_SUITE" }, loop_variable, exp_from, exp_to, step, suite);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($14));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14);
			}
		| _optional_construct_name YY_DOWHILE exp at_least_one_end_line suite crlf_or_not YY_ENDDO
			{
				ARG_IN exp = YY2ARG($3);
				ARG_IN suite = YY2ARG($5);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, "DO-WHILE GENERATED IN REGEN_SUITE" }, exp, suite);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
			}
	
	select_stmt : _optional_construct_name YY_SELECT YY_CASE '(' exp ')' at_least_one_end_line case_stmt YY_ENDSELECT
			{
				ARG_IN select = YY2ARG($2);
				ARG_IN exp = YY2ARG($5);
				ARG_IN case_stmt = YY2ARG($8);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_SELECT, "SELECT GENERATED IN REGEN_SUITE" }, exp, case_stmt);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($9));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9);
			}

	case_stmt_elem : YY_CASE '(' dimen_slice ')' at_least_one_end_line suite
			{
				// one case
				ARG_IN dimen_slice = YY2ARG($3);
				ARG_IN suite = YY2ARG($6); 

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, "CASE GENERATED IN REGEN_SUITE" }, dimen_slice, suite); 
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
			}
		| YY_CASE '(' argtable ')' at_least_one_end_line suite
			{
				// one case
				ARG_IN dimen_slice = YY2ARG($3);
				ARG_IN suite = YY2ARG($6);

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, "CASE GENERATED IN REGEN_SUITE" }, dimen_slice, suite); // Yes, empty string
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
			}

	case_stmt : case_stmt_elem
			{
				ARG_IN case_stmt_elem = YY2ARG($1);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "CASE GENERATED IN REGEN_SUITE" }, case_stmt_elem);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
	case_stmt : case_stmt_elem case_stmt
			{
				ARG_IN case_stmt_elem = YY2ARG($1);
				ARG_IN case_stmt = YY2ARG($2);
				ParseNode newnode = gen_flattern(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($2));
				CLEAN_RIGHT($1, $2);
			}
	
	_optional_result : YY_RESULT '(' variable ')'
			{
				$$ = $3;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($4));
				CLEAN_RIGHT($1, $2, $4);
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
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ARG_IN variable_function = YY2ARG($3); // function name
				/* enumerate paramtable */
				ARG_IN paramtable = YY2ARG($5);
				ARG_IN variable_result = YY2ARG($7); // result variable
				ARG_IN suite = YY2ARG($9);

				$$ = RETURN_NT(gen_function(variable_function, paramtable, variable_result, suite));
				YYSTYPE XXX = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($10));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
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

    program : YY_PROGRAM _optional_name at_least_one_end_line suite YY_ENDPROGRAM _optional_name
			{
				ParseNode & suite = YY2ARG($4);
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.to_string() }, suite));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($6));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6);
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
		// R1101 main-program is [ program-stmt ]
		//	[ specification-part ]
		//	[ execution-part ]
		//	[ internal-subprogram-part ]
		//	end-program-stmt 
		| stmt
			{
				ARG_IN stmt = YY2ARG($1); 
				$$ = RETURN_NT(gen_promote("%s\n", TokenMeta::NT_SUITE, stmt));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| labeled_stmt
			{
				$$ = $1;
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
			}		
		| YY_END
			{
				$$ = RETURN_NT(gen_dummy());
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}		


	wrappers : wrapper
			{
				ARG_IN wrapper = YY2ARG($1);
				sprintf(codegen_buf, "%s", wrapper.to_string().c_str());
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) }, wrapper);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($1));
				CLEAN_RIGHT($1);
			}
		| wrapper at_least_one_end_line wrappers
			{
				ARG_IN wrapper = YY2ARG($1);
				ARG_IN wrappers = YY2ARG($3);
				sprintf(codegen_buf, "%s\n%s", wrapper.to_string().c_str(), wrappers.to_string().c_str());
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) }, wrapper, wrappers);
				flattern_bin_inplace(newnode, true);
				$$ = RETURN_NT(newnode);
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				CLEAN_RIGHT($1, $2, $3);
			}

	interface_decl : YY_INTERFACE _optional_name at_least_one_end_line wrappers crlf_or_not YY_ENDINTERFACE _optional_name
			{
				$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, YY2ARG($4).to_string()}, YY2ARG($4)));
				update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($7));
				CLEAN_RIGHT($1, $2, $3, $4, $5, $6, $7);
			}

	fortran_program : wrappers
			{
				gen_fortran_program(YY2ARG($1));
			}


%%

void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), YY2ARG(yylval));
}
int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
