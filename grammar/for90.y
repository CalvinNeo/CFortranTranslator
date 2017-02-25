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
void update_pos(YYSTYPE & current) {
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
void update_pos(YYSTYPE & current, const YYSTYPE & start, const YYSTYPE & end) {
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

%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%right YY_NEG YY_POS
%left '+' '-' 
%left '*' '/' 
%right YY_POWER /* x**y**z -> x**(y**z) */
%right YY_NOT

%start fortran_program

%%

	crlf_or_not : YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$, $1, $1);
			}
		|
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
				update_pos($$);
			}

	at_least_one_end_line : YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$, $1, $1);
			}
		| at_least_one_end_line YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$, $1, $2);
			}
		| semicolon
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$, $1, $1);
			}
		| at_least_one_end_line semicolon
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$, $1, $2);
			}

	semicolon : ';'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}

	end_of_stmt : YY_CRLF
		| semicolon

	dummy_function_iden : YY_RECURSIVE
		|

	variable_desc_elem : YY_INTENT '(' YY_IN ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| YY_INTENT '(' YY_OUT ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $4);
			}

		| YY_INTENT '(' YY_INOUT ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| YY_DIMENSION '(' dimen_slice ')'
			{
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				const ParseNode & dimen_slice = $3;
				ParseNode attr = gen_variabledesc_from_dimenslice(dimen_slice);
				newnode.addchild(attr); // def slice
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| YY_DIMENSION '(' exp ')'
			{
				/* define array like a(1) */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				ParseNode slice = ParseNode();
				const ParseNode & exp_to = $3;
				ParseNode & exp_from = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER, "1" }));

				slice.addchild(exp_from); // slice from 1
				slice.addchild(exp_to); // slice to

				ParseNode attr = gen_variabledesc_from_dimenslice(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				newnode.addchild(attr); // def slice

				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| YY_OPTIONAL
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| YY_PARAMETER
			{
				/* const value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| YY_SAVE
			{
				/* static value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
				
	variable_desc : ',' variable_desc_elem
			{
				$$ = $2;
				update_pos($$, $1, $2);
			}
		| ',' variable_desc_elem variable_desc
			{
				ParseNode variable_elem = $2;
				ParseNode variable_desc = $3;
				/* target code of slice depend on context */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				/* merge attrs */
				newnode.setattr(variable_elem.attr->clone());
				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		|
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				$$ = newnode;
				update_pos($$);
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
				sscanf($3.to_string().c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none);
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		| YY_LEN '=' exp
			{
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf($3.to_string().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				$$ = newnode;
				update_pos($$, $1, $3);
			}

	literal : YY_FLOAT
			{
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				$$ = gen_token(Term{ TokenMeta::Float, $1.to_string() });// float number
			}
		| YY_INTEGER
			{
				$$ = gen_token(Term{ TokenMeta::Int, $1.to_string() });// int number
			}
		| YY_STRING
			{
				// replace `'` with `"`
				std::string s = $1.to_string().substr(1, $1.to_string().size() - 2);
				$$ = gen_token(Term{ TokenMeta::String, "\"" + s + "\"" }); // string
			}
		| YY_TRUE
			{
				$$ = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
		| YY_FALSE
			{
				$$ = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
        | YY_COMPLEX
            {
				string strcplx = $1.to_string();
				auto splitter = strcplx.find_first_of('_', 0);
				$$ = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}

		| error '\n'

	variable : YY_WORD
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, $1.to_string() });// variant
				$$ = newnode;
				update_pos($$, $1, $1);
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
				const ParseNode & exp1 = $1;
				const ParseNode & exp2 = $3;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2);
				update_pos($$, $1, $3);
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to : step] */
				const ParseNode & exp1 = $1;
				const ParseNode & exp2 = $3;
				const ParseNode & exp3 = $5;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2, exp3);
				update_pos($$, $1, $5);
			}
		| ':'
			{
				const ParseNode & lb = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				const ParseNode & ub = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				/* target code of slice depend on context */
				$$ = gen_slice(lb, ub);
				update_pos($$, $1, $1);
			}

	keyvalue : exp '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				/* array_builder is exp */
				const ParseNode & exp2 = $3;
				$$ = gen_keyvalue_from_exp($1, $3);
				update_pos($$, $1, $3);
			}

	argtable : exp
			{
				/* argtable is used in function call */
				const ParseNode & exp = $1;
				ParseNode newnode = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| argtable ',' exp
			{
				const ParseNode & exp = $3;
				const ParseNode & argtable = $1;
				$$ = gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				update_pos($$, $1, $3);
			}

	dimen_slice : slice 
			{
				/* 1d array */
				/* arr[from : to] */
				/* target code of slice depend on context */
				const ParseNode & slice = $1;
				// only 1 slice
				$$ = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
				update_pos($$, $1, $1);
			}
		| dimen_slice ',' slice
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				const ParseNode & slice = $3;
				const ParseNode & dimen_slice = $1;
				$$ = gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				update_pos($$, $1, $3);
			}
		| dimen_slice ',' exp
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				const ParseNode & exp = $3;
				const ParseNode & dimen_slice = $1;
				$$ = gen_flattern(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				update_pos($$, $1, $3);
			}
		| argtable ',' slice
			{
				const ParseNode & slice = $3;
				const ParseNode & argtable = $1;
				ParseNode newnode = ParseNode();
				switch (argtable.fs.CurrentTerm.token) {
					case TokenMeta::NT_ARGTABLE_PURE:
					//case TokenMeta::NT_DIMENSLICE:
					//case TokenMeta::NT_PARAMTABLE_PURE:
					//case TokenMeta::NT_PARAMTABLE_DIMENSLICE:
						newnode = gen_flattern(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
						break;
					default:
						print_error("Illegal dimen_slice", argtable);
				}
				$$ = newnode;
				update_pos($$, $1, $3);
			}

	function_array_body : variable '(' paramtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				const ParseNode & callable_head = $1;
				const ParseNode & argtable = $3;
				ParseNode newnode = gen_function_array(callable_head, argtable);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| type_name '(' paramtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				const ParseNode & callable_head = $1;
				const ParseNode & argtable = $3;
				ParseNode newnode = gen_function_array(callable_head, argtable);
				$$ = newnode;
				update_pos($$, $1, $4);
			}

	function_array : function_array_body
			{
				$$ = $1;
			}
		| YY_CALL function_array_body
			{
				$$ = $2;
			}

	exp : function_array 
			{
				/* function call OR array index */
				const ParseNode & function_array = $1;
				$$ = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos($$, $1, $1);
			}
		| array_builder
			{
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				const ParseNode & array_builder_elem = $1;
				$$ = $1;
				update_pos($$, $1, $1);
			}
			
		| exp '(' exp ')'
			{
				/* hyper-function or multi-dimension array like A(2)(3)  */
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s(%s)");
			}
		| '(' exp ')' 
			{
				/* `function_array` rule has priority over this rule  */
				const ParseNode & exp = $2;
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				$$ = gen_exp(exp, op, "( %s )");
				update_pos($$, $1, $3);
			}
		| exp '+' exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos($$, $1, $3);
			}
		| exp '-' exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos($$, $1, $3);
			}
		| exp '*' exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos($$, $1, $3);
			}
		| exp '/' exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos($$, $1, $3);
			}
		| exp YY_POWER exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos($$, $1, $3);
			}
        | '-' %prec YY_NEG exp 
			{
				const ParseNode & exp1 = $2;
				const ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "(-%s)");
				update_pos($$, $1, $2);
			}
        | '+' %prec YY_NEG exp 
			{
				const ParseNode & exp1 = $2;
				const ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "%s");
				update_pos($$, $1, $2);
			}
		| exp YY_NEQ exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos($$, $1, $3);
			}
		| exp YY_NEQV exp 
			{
				// xor
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos($$, $1, $3);
			}
		| exp YY_EQ exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos($$, $1, $3);
			}
		| exp YY_EQV exp 
			{
				// nor
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "!(%s ^ %s)");
				update_pos($$, $1, $3);
			}
		| exp YY_ANDAND exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos($$, $1, $3);
			}
		| exp YY_OROR exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos($$, $1, $3);
			}
		| YY_NOT exp 
			{
				const ParseNode & exp1 = $2;
				const ParseNode & op = $1;
				$$ = gen_exp(exp1, op, "!(%s)");
				update_pos($$, $1, $2);
			}
		| exp YY_GT exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos($$, $1, $3);
			}
		| exp YY_GE exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos($$, $1, $3);
			}
		| exp YY_LE exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos($$, $1, $3);
			}
		| exp YY_LT exp 
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos($$, $1, $3);
			}
		| hidden_do
			{
				const ParseNode & hidden_do = $1;
				$$ = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos($$, $1, $1);
			}
		| literal 
            { 
				$$ = $1;
				update_pos($$, $1, $1);
			}
		| variable
			{
				$$ = $1;
				update_pos($$, $1, $1);
			}

	label : YY_LABEL
		{
			$$ = gen_label($1);
			update_pos($$, $1, $1);
		}

	stmt : exp 
			{
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				$$ = gen_stmt($1, "%s;");
				update_pos($$, $1, $1);
			}
		| var_def 
			{
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				$$ = gen_stmt($1, "%s");
				update_pos($$, $1, $1);
			}
        | compound_stmt
			{
				$$ = $1;
			}
        | output_stmt
			{
				$$ = $1;
			}
		| input_stmt
			{
				$$ = $1;
			}
		| dummy_stmt
			{
				$$ = $1;
			}
		| let_stmt
			{
				$$ = gen_stmt($1);
				update_pos($$, $1, $1);
			}
		| jump_stmt
			{
				$$ = gen_stmt($1);
				update_pos($$, $1, $1);
			}

		| common_stmt
			{
				$$ = $1;
				update_pos($$, $1, $1);
			}
		| YY_FORMAT_STMT
			{
				$$ = gen_format($1);
				update_pos($$, $1, $1);
			}
		| YY_COMMENT
			{
				$$ = gen_token(Term{TokenMeta::Comments, "/*" + $1.to_string() + "*/"});
				update_pos($$, $1, $1);
			}
		| pause_stmt 
		| stop_stmt 
		| YY_CONTINUE
			{
				$$ = gen_token(Term{TokenMeta::Comments, "nop();"});
				update_pos($$, $1, $1);
			}
		| YY_END
			{
				$$ = gen_token(Term{TokenMeta::META_ANY, ""});
				update_pos($$, $1, $1);
			}
				
		| 
			{
				$$ = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos($$);
			}
			


    output_stmt : write
		| print

	input_stmt : read

	compound_stmt : if_stmt 
		| do_stmt 
		| select_stmt

	jump_stmt : YY_CYCLE
			{
				$$ = gen_token(Term{TokenMeta::META_ANY, "continue;"});
				update_pos($$, $1, $1);
			}
		| YY_EXIT
			{
				$$ = gen_token(Term{TokenMeta::META_ANY, "break;"});
				update_pos($$, $1, $1);
			}
		| YY_GOTO YY_INTEGER
			{
				$$ = gen_token(Term{TokenMeta::Goto, "goto " + $2.to_string() + ";\n"});
				update_pos($$, $1, $2);
			}

	pause_stmt : YY_PAUSE literal
			{
				const ParseNode & lit = $2;
				$$ = gen_token(Term{ TokenMeta::META_ANY, "printf(" + lit.to_string() + ");\nsystem(\"pause\");\n" });
				update_pos($$, $1, $2);
			}
		| YY_PAUSE
			{
				$$ = gen_token(Term{ TokenMeta::META_ANY, "system(\"pause\");\n" });
				update_pos($$, $1, $1);
			}
	stop_stmt : YY_STOP literal
		{
			const ParseNode & lit = $2;
			$$ = gen_token(Term{ TokenMeta::META_ANY, "printf(" + lit.to_string() + ");\nsystem(\"pause\");\n" });
			update_pos($$, $1, $2);
		}
	| YY_STOP
		{
			$$ = gen_token(Term{ TokenMeta::META_ANY, "system(\"pause\");\n" });
			update_pos($$, $1, $1);
		}

	let_stmt : exp '=' exp
			{
				const ParseNode & exp1 = $1;
				const ParseNode & op = $2;
				const ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos($$, $1, $3);
			}

	dummy_stmt : YY_IMPLICIT YY_NONE
			{
				// dummy stmt
				$$ = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos($$, $1, $2);
			}

	suite : label stmt
			{
				const ParseNode & label = $1; // TokenMeta::Label
				const ParseNode & stmt = $2;
				if (stmt.child.size() > 0 && stmt.get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{
					log_format_index(label.to_string(), stmt);
					$$ = gen_token(Term{TokenMeta::Nop, ""}); // do not print format stmt
				}
				else {
					sprintf(codegen_buf, "%s\n%s", label.to_string().c_str(), stmt.to_string().c_str());
					ParseNode & newnode = gen_token(Term{ TokenMeta::NT_SUITE , string(codegen_buf) });
					newnode.addchild(label);
					newnode.addchild(stmt);
					$$ = newnode;
				}
				update_pos($$, $1, $2);
			}
		| label stmt end_of_stmt suite
			{
				const ParseNode & label = $1; 
				const ParseNode & stmt = $2;
				const ParseNode & suite = $4;				
				if (stmt.child.size() > 0 && stmt.get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{
					log_format_index(label.to_string(), stmt);
					$$ = suite; // do not print format stmt
				}
				else {
					sprintf(codegen_buf, "%s\n%s\n%s", label.to_string().c_str(), stmt.to_string().c_str(), suite.to_string().c_str());
					ParseNode & newnode = gen_token(Term{ TokenMeta::NT_SUITE , string(codegen_buf) });
					newnode.addchild(label);
					newnode.addchild(stmt);
					for (int i = 0; i < suite.child.size(); i++)
					{
						newnode.addchild(suite.get(i));
					}
					$$ = newnode;
				}
				update_pos($$, $1, $2);
			}
				
		| stmt end_of_stmt suite
			{
				const ParseNode & stmt = $1; 
				const ParseNode & suite = $3;
				$$ = gen_flattern(stmt, suite, "%s\n%s", TokenMeta::NT_SUITE);
				update_pos($$, $1, $3);
			}
		| stmt
			{
				const ParseNode & stmt = $1; // TokenMeta::NT_LABEL
				$$ = gen_promote("%s\n", TokenMeta::NT_SUITE, stmt);
				update_pos($$, $1, $1);
			}
				
		| interface_decl
			{
				$$ = gen_promote("", TokenMeta::NT_SUITE, $1);
				update_pos($$, $1, $1);
			}
		| interface_decl end_of_stmt suite
			{
				$$ = gen_flattern($1, $3, "%s%s", TokenMeta::NT_SUITE);
				update_pos($$, $1, $3);
			}
			

	_optional_comma : ','
		|
	_optional_device : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
		| YY_INTEGER
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, $1.to_string() };
			}
	_optional_formatter : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
		| YY_INTEGER
			{
				// use format stmt at line $1 to format
				require_format_index($1.to_string());
			}
		| YY_STRING
			{
				// replace `'` with `"`
				string modified = "\"" + $1.to_string().substr(1, $1.to_string().size() - 2) + "\"";
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}

	io_info : '(' _optional_device ',' _optional_formatter ')'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" });
				const ParseNode & _optional_device = $2;
				const ParseNode & _optional_formatter = $4;
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode.addchild(_optional_device); // _optional_device
				newnode.addchild(_optional_formatter); // _optional_formatter
				$$ = newnode;
				update_pos($$, $1, $5);
			}
		| _optional_formatter _optional_comma
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" });
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				const ParseNode & _optional_formatter = $1;
				/* target code of io_info depend on context */
				newnode.addchild(_optional_device); // _optional_device
				newnode.addchild(_optional_formatter); // _optional_formatter
				$$ = newnode;
				update_pos($$, $1, $2);
			}


    write : YY_WRITE io_info paramtable 
			{
				const ParseNode & io_info = $2;
				const ParseNode & argtable = $3;
				$$ = gen_write(io_info, argtable);
				update_pos($$, $1, $3);
			}

	print : YY_PRINT io_info paramtable
			{
				const ParseNode & io_info = $2;
				const ParseNode & argtable = $3;
				$$ = gen_print(io_info, argtable);
				update_pos($$, $1, $3);
			}


	read: YY_READ io_info paramtable
			{
				const ParseNode & io_info = $2;
				const ParseNode & argtable = $3;
				$$ = gen_read(io_info, argtable);
				update_pos($$, $1, $3);
			}

	type_name : YY_INTEGER_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}
        | YY_FLOAT_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}
        | YY_STRING_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}
        | YY_COMPLEX_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}
        | YY_BOOL_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}
        | YY_CHARACTER_T 
			{
				$$ = gen_type($1);
				update_pos($$, $1, $1);
			}

    type_spec : YY_INTEGER_T '(' type_selector ')'
			{
				// now translated in pre_map
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_FLOAT_T '(' type_selector ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_STRING_T '(' type_selector ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_COMPLEX_T '(' type_selector ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_BOOL_T '(' type_selector ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_CHARACTER_T '(' type_selector ')'
			{
				ParseNode newnode = gen_type($1);
				int len;
				sscanf($3.to_string().c_str(), "%d", &len);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				update_pos($$, $1, $4);
			}
		| type_name '*' YY_INTEGER
			{
				$$ = $1;
				update_pos($$, $1, $3);
			}
		| type_name
			{
				$$ = $1;
				update_pos($$, $1, $1);
			}

	_blockname_or_none : '/' variable '/'
			{
				$$ = $2;
				update_pos($$, $1, $3);
			}
		| '/' '/'
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				$$ = newnode;
				update_pos($$, $1, $2);
			}
		|
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				$$ = newnode;
				update_pos($$);
			}

	common_stmt : YY_COMMON _blockname_or_none paramtable
			{
				const ParseNode & blockname = $2;
				const ParseNode & paramtable = $3;
				$$ = gen_common(blockname, paramtable);
				update_pos($$, $1, $3);
			}

    var_def : type_spec variable_desc YY_DOUBLECOLON paramtable
			{
				/* array decl */
				const ParseNode & type_spec = $1;
				const ParseNode & variable_desc = $2;
				const ParseNode & paramtable = $4;

				$$ = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos($$, $1, $4);
			}
		| type_spec variable_desc paramtable
			{
				/* array decl */
				const ParseNode & type_spec = $1;
				const ParseNode & variable_desc = $2;
				const ParseNode & paramtable = $3;

				$$ = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos($$, $1, $3);
			}
		| YY_DIMENSION paramtable
			{
				/* array decl */
				const ParseNode & paramtable = $2;
				ParseNode & type_spec = gen_token(Term {TokenMeta::Implicit_Def, ""});
				ParseNode variable_desc = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(variable_desc, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				$$ = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos($$, $1, $2);
			}

    
	pure_paramtable : keyvalue
			{
				const ParseNode & paramtable_elem = $1;
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| pure_paramtable ',' keyvalue
			{
				const ParseNode & paramtable_elem = $3;
				const ParseNode & paramtable = $1;
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				$$ = newnode;
				update_pos($$, $1, $3);
			}				
		| pure_paramtable ',' exp
			{
				const ParseNode & paramtable_elem = $3;
				const ParseNode & paramtable = $1;
				ParseNode & newnode = gen_paramtable(promote_exp_to_keyvalue(paramtable_elem), paramtable);
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		| argtable ',' keyvalue
			{
				const ParseNode & paramtable_elem = $3;
				const ParseNode & paramtable = $1;
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		|
			{
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				$$ = newnode;
				update_pos($$);
			}

	paramtable : pure_paramtable
		| argtable
		| dimen_slice
	
	hidden_do : '(' argtable ',' variable '=' exp ',' exp ')'
			{
				/* something like `abs(i), i=1,4` */
				/*
				R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
				R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
				■ scalar - int - expr[, scalar - int - expr]
				*/
				const ParseNode & exp = $2;
				const ParseNode & index = $4;
				const ParseNode & from = $6;
				const ParseNode & to = $8;
				$$ = gen_hiddendo(exp, index, from, to);
				update_pos($$, $1, $9);
			}

	array_builder_elem : YY_ARRAYINITIAL_START paramtable YY_ARRAYINITIAL_END
			{
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				$$ = gen_array_from_paramtable($2);
				update_pos($$, $1, $3);
			}
		| YY_ARRAYINITIAL_START hidden_do YY_ARRAYINITIAL_END
			{
				/* give generate stmt */
				const ParseNode & hidden_do = $2;
				$$ = gen_array_from_hiddendo(hidden_do);
				update_pos($$, $1, $3);
			}

	/* array_builder can accept mixed */
	array_builder : array_builder_elem
			{
				const ParseNode & array_builder_elem = $1;
				if (array_builder_elem.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
				{
					$$ = array_builder_elem;
				}
				else {
					$$ = gen_promote("%s", TokenMeta::NT_ARRAYBUILDER, array_builder_elem); // array_builder_elem
				}
				gen_arraybuilder_str($$);
				update_pos($$, $1, $1);
			}

	
	_optional_construct_name : YY_WORD ':'
		|
	

	_yy_endif : YY_ENDIF


	if_stmt : _optional_construct_name YY_IF '(' exp ')' stmt 
			{
				const ParseNode & exp = $4;
				ParseNode  stmt_true = $6;
				$$ = gen_if_oneline(exp, stmt_true);
				update_pos($$, $1, $6);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line /* must have \n */ suite _yy_endif
			{
				const ParseNode & exp = $3;
				ParseNode  suite_true = $6; 
				$$ = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos($$, $1, $7);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite YY_ELSE at_least_one_end_line suite _yy_endif
			{
				const ParseNode & exp = $3;
				ParseNode  suite_true = $6; 
				ParseNode  suite_else = $9; 
				$$ = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos($$, $1, $10);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite elseif_stmt _yy_endif
			{
				const ParseNode & exp = $3;
				ParseNode  suite_true = $6;
				ParseNode  elseif = $7;
				$$ = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos($$, $1, $8);
			}
		| _optional_construct_name YY_IF exp YY_THEN at_least_one_end_line suite elseif_stmt YY_ELSE at_least_one_end_line suite _yy_endif
			{
				const ParseNode & exp = $3;
				ParseNode  suite_true = $6;
				ParseNode  elseif = $7;
				ParseNode  suite_else = $10;
				$$ = gen_if(exp, suite_true, elseif, suite_else);
				update_pos($$, $1, $11);
			}

	elseif_stmt : YY_ELSEIF exp YY_THEN at_least_one_end_line suite
			{
				const ParseNode & exp = $2;
				ParseNode  suite_true = $5;
				$$ = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos($$, $1, $5);
			}

		| YY_ELSEIF exp YY_THEN at_least_one_end_line suite elseif_stmt
			{
				const ParseNode & exp = $2;
				ParseNode  suite_true = $5;
				ParseNode  elseif = $6;
				$$ = gen_elseif(exp, suite_true, elseif);
				update_pos($$, $1, $6);
			}

	_yy_enddo : YY_ENDDO
	_optional_label_construct : YY_INTEGER
		|
	do_stmt : _optional_construct_name YY_DO at_least_one_end_line suite crlf_or_not _yy_enddo
			{
				ParseNode  suite = $4; 
				$$ = gen_do(suite);
				update_pos($$, $1, $5);
			}
		| _optional_construct_name YY_DO _optional_label_construct variable '=' exp ',' exp at_least_one_end_line suite crlf_or_not _yy_enddo
			{
				const ParseNode & loop_variable = $4;
				const ParseNode & exp_from = $6;
				const ParseNode & exp_to = $8;
				const ParseNode & step = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode  suite = $10; 
				$$ = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos($$, $1, $12);
			}
		| _optional_construct_name YY_DO _optional_label_construct variable '=' exp ',' exp ',' exp at_least_one_end_line suite crlf_or_not _yy_enddo
			{
				const ParseNode & loop_variable = $4;
				const ParseNode & exp1 = $6;
				const ParseNode & exp2 = $8;
				const ParseNode & exp3 = $10;
				ParseNode  suite = $12;
				$$ = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos($$, $1, $14);
			}
		| _optional_construct_name YY_DOWHILE exp at_least_one_end_line suite crlf_or_not _yy_enddo
			{
				const ParseNode & exp = $3;
				ParseNode  suite = $5; 
				$$ = gen_do_while(exp, suite);
				update_pos($$, $1, $6);
			}
	
	_yy_endselect :  YY_ENDSELECT

	_optional_lbrace : 
		| '('
	_optional_rbrace : 
		| ')'
	select_stmt : _optional_construct_name YY_SELECT YY_CASE _optional_lbrace exp _optional_rbrace at_least_one_end_line case_stmt _yy_endselect
			{
				const ParseNode & select = $2;
				const ParseNode & exp = $5;
				const ParseNode & case_stmt = $8;
				$$ = gen_select(exp, case_stmt);
				update_pos($$, $1, $9);
			}
	case_stmt_elem : YY_CASE _optional_lbrace dimen_slice _optional_rbrace at_least_one_end_line suite
			{
				// one case
				const ParseNode & dimen_slice = $3;
				ParseNode suite = $6; 
				$$ = gen_case(dimen_slice, suite);
				update_pos($$, $1, $6);
			}
	case_stmt : case_stmt_elem
			{
				const ParseNode & case_stmt_elem = $1;
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem); // case_stmt_elem
				$$ = newnode;
				update_pos($$, $1, $1);
			}
	case_stmt : case_stmt_elem case_stmt
			{
				const ParseNode & case_stmt_elem = $1;
				const ParseNode & case_stmt = $2;
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem, false /* add to the front of the vector */); // case_stmt_elem
				$$ = newnode;
				update_pos($$, $1, $2);
			}
	
	_optional_result : YY_RESULT '(' variable ')'
			{
				$$ = $3;
				update_pos($$, $1, $4);
			}
		|
			{
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				$$ = newnode;
				update_pos($$);
			}

	_optional_function : YY_FUNCTION
		| YY_SUBROUTINE

	_yy_endfunction : YY_ENDFUNCTION
		| YY_ENDSUBROUTINE
		| YY_RETURN

	function_decl : dummy_function_iden _optional_function variable '(' paramtable ')' _optional_result at_least_one_end_line suite _yy_endfunction
			{
				/* fortran90 does not declare type of arguments in function declaration statement*/
				const ParseNode & variable_function = $3; // function name
				/* enumerate paramtable */
				const ParseNode & paramtable = $5;
				const ParseNode & variable_result = $7; // result variable
				const ParseNode & suite = $9;

				$$ = gen_function(variable_function, paramtable, variable_result, suite);
				update_pos($$, $1, $10);
			}
	
	_optional_name : YY_WORD
		|

	_yy_endprogram :  YY_ENDPROGRAM

    program : suite
			// R1101 main-program is [ program-stmt ]
			//	[ specification-part ]
			//	[ execution-part ]
			//	[ internal-subprogram-part ]
			//	end-program-stmt 
			{
				ParseNode  suite = $1;
				$$ = gen_program(suite);
				update_pos($$, $1, $1);
			}
		| YY_PROGRAM _optional_name at_least_one_end_line suite _yy_endprogram _optional_name
			{
				ParseNode  suite = $4;
				$$ = gen_program_explicit(suite);
				update_pos($$, $1, $6);
			}
		| YY_PROGRAM _optional_name at_least_one_end_line _yy_endprogram _optional_name
			{
				$$ = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos($$, $1, $5);
			}

	wrapper : program
		| function_decl

	wrappers : wrapper
			{
				const ParseNode & wrapper = $1;
				ParseNode newnode = ParseNode();
				newnode.addchild(wrapper); // wrapper
				sprintf(codegen_buf, "%s", wrapper.to_string().c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| wrapper at_least_one_end_line wrappers
			{
				ParseNode newnode = ParseNode();
				const ParseNode & wrapper = $1;
				const ParseNode & wrappers = $3;
				newnode.addchild(wrapper); // wrapper
				newnode.addchild(wrappers); // wrappers
				sprintf(codegen_buf, "%s\n%s", wrapper.to_string().c_str(), wrappers.to_string().c_str());
				newnode = flattern_bin_right(newnode);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				$$ = newnode;
				update_pos($$, $1, $3);
			}

	_yy_endinterface :  YY_ENDINTERFACE
	interface_decl : YY_INTERFACE _optional_name at_least_one_end_line wrappers crlf_or_not _yy_endinterface _optional_name
			{
				$$ = gen_interface($4);
				update_pos($$, $1, $7);
			}

	fortran_program : wrappers
			{
				gen_fortran_program($1);
			}


%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), yylval);
}
int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
