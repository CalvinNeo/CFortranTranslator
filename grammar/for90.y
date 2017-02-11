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
// static is necessary, or will cause lnk
static char codegen_buf[MAX_CODE_LENGTH];
using namespace std;
%}

%debug

%token /*_YY_VOID*/ YY_REQ_MORE YY_CRLF
%token /*_YY_OP*/ YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS
%token /*_YY_TYPE*/ YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token /*_YY_CONTROL*/ YY_LABEL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT
%token /*_YY_DELIM*/ YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE YY_COMMON YY_DATA
%token /*_YY_DESCRIBER*/ YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_ENTRY YY_DIMENSION YY_ARRAYINITIAL_START YY_ARRAYINITIAL_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND
%token /*_YY_TYPEDEF*/ YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T
%token /*_YY_COMMAND*/ YY_WRITE YY_READ YY_PRINT YY_CALL YY_FORMAT


%left '='
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
	crlf : YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
		| ';'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}
		|
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}

	block_name_crlf : YY_WORD YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
		| YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
		|
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}

	dummy_function_iden : YY_RECURSIVE
		|

	variable_desc_elem : YY_INTENT '(' YY_IN ')'
			{
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $4);
			}
		| YY_INTENT '(' YY_OUT ')'
			{
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $4);
			}

		| YY_INTENT '(' YY_INOUT ')'
			{
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $4);
			}
		| YY_DIMENSION '(' dimen_slice ')'
			{
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
				ParseNode * dimen = new ParseNode(gen_variabledesc_from_dimenslice($3));
				newnode->addchild(dimen); // def slice
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $4);
			}
		| YY_DIMENSION '(' exp ')'
			{
				/* define array like a(1) */
				ParseNode * newnode = new ParseNode();
				ParseNode slice = ParseNode();
				ParseNode & exp_to = $3;
				ParseNode & exp_from = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER, "1" }));

				slice.addchild(new ParseNode(exp_from)); // slice from 1
				slice.addchild(new ParseNode(exp_to)); // slice to

				ParseNode * dimen = new ParseNode(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				newnode->addchild(dimen); // def slice

				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $4);
			}
		| YY_OPTIONAL
			{
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $1);
			}
		| YY_PARAMETER
			{
				/* const value */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none);
				$$ = *newnode;
				update_pos($$, $1, $1);
			}
				
	variable_desc : ',' variable_desc_elem
			{
				$$ = $2;
				update_pos($$, $1, $2);
			}
		| ',' variable_desc_elem variable_desc
			{
				ParseNode * variable_iden = & $3;
				ParseNode & variable_iden_1 = $2;
				/* target code of slice depend on context */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
				/* merge attrs */
				newnode.attr = variable_iden_1.attr->clone();
				dynamic_cast<VariableDescAttr *>(newnode.attr)->merge(*dynamic_cast<VariableDescAttr *>(variable_iden->attr));
				// TODO do not add child
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		|
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	typecast_spec : YY_KIND '=' YY_INTEGER
			{
				int kind;
				sscanf($3.fs.CurrentTerm.what.c_str(), "%d", &kind);

				/* type size */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // kind
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, kind);
				$$ = *newnode;
				update_pos($$, $1, $3);
			}
		| YY_LEN '=' exp
			{
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf($3.fs.CurrentTerm.what.c_str(), "%d", &len);

				/* string length */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // len
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len);
				$$ = *newnode;
				update_pos($$, $1, $3);
			}

	literal : YY_FLOAT
			{
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				$$ = gen_token(Term{ TokenMeta::Float, $1.fs.CurrentTerm.what });// float number
			}
		| YY_INTEGER
			{
				$$ = gen_token(Term{ TokenMeta::Int, $1.fs.CurrentTerm.what });// int number
			}
		| YY_STRING
			{
				// replace `'` with `"`
				$$ = gen_token(Term{ TokenMeta::String, "\"" + $1.fs.CurrentTerm.what.substr(1, $1.fs.CurrentTerm.what.size() - 2) + "\"" }); // string
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
				string strcplx = $1.fs.CurrentTerm.what;
				auto splitter = strcplx.find_first_of('_', 0);
				$$ = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}

		| error '\n'

	variable : YY_WORD
			{
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, $1.fs.CurrentTerm.what }), nullptr);// variant
				$$ = newnode;
				update_pos($$, $1, $1);
			}
	
	slice : exp ':' exp
			{
				/* arr[from : to] */
				ParseNode & exp1 = $1;
				ParseNode & exp2 = $3;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2);
				update_pos($$, $1, $3);
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to : step] */
				ParseNode & exp1 = $1;
				ParseNode & exp2 = $3;
				ParseNode & exp3 = $5;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2, exp3);
				update_pos($$, $1, $5);
			}
		| ':'
			{
				ParseNode & lb = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				ParseNode & ub = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				/* target code of slice depend on context */
				$$ = gen_slice(lb, ub);
				update_pos($$, $1, $1);
			}

	dimen_slice : slice 
			{
				/* 1d array */
				/* arr[from : to] */
				/* target code of slice depend on context */
				ParseNode & slice = $1;
				// only 1 slice
				$$ = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
				update_pos($$, $1, $1);
			}
		| slice ',' dimen_slice
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ParseNode & slice = $1;
				ParseNode & dimen_slice = $3;
				// gen_dimenslice(slice, dimen_slice);
				$$ = gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE);
				update_pos($$, $1, $3);
			}
		| exp
			{
				/* argtable is used in function call */
				ParseNode & exp = $1;
				$$ = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				update_pos($$, $1, $1);
			}
         | exp ',' paramtable
			{
				ParseNode & exp = $1;
				ParseNode & argtable = $3;
				ParseNode newnode = ParseNode();
				switch (argtable.fs.CurrentTerm.token) {
					case TokenMeta::NT_ARGTABLE_PURE:
					case TokenMeta::NT_DIMENSLICE:
					case TokenMeta::NT_PARAMTABLE:
					case TokenMeta::NT_PARAMTABLE_DIMENSLICE:
						newnode = gen_paramtable(exp, argtable);
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
				ParseNode & callable_head = $1;
				ParseNode & argtable = $3;
				ParseNode newnode = gen_function_array(callable_head, argtable);
				$$ = newnode;
				update_pos($$, $1, $4);
			}
		| type_nospec '(' paramtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode & callable_head = $1;
				ParseNode & argtable = $3;
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
				ParseNode & function_array = $1;
				$$ = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos($$, $1, $1);
			}
				
		| array_builder
			{
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = $1;
				$$ = $1;
				update_pos($$, $1, $1);
			}
			
		| exp '(' exp ')'
			{
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s(%s)");
			}
		| '(' exp ')' 
			{
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = $2;
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				$$ = gen_exp(exp, op, "( %s )");
				update_pos($$, $1, $3);
			}
		| exp '+' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos($$, $1, $3);
			}
		| exp '-' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos($$, $1, $3);
			}
		| exp '*' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos($$, $1, $3);
			}
		| exp '/' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos($$, $1, $3);
			}
		| exp YY_POWER exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos($$, $1, $3);
			}
        | '-' %prec YY_NEG exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "(-%s)");
				update_pos($$, $1, $2);
			}
        | '+' %prec YY_NEG exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "%s");
				update_pos($$, $1, $2);
			}
		| exp YY_NEQ exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos($$, $1, $3);
			}
		| exp YY_NEQV exp 
			{
				// xor
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos($$, $1, $3);
			}
		| exp YY_EQ exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos($$, $1, $3);
			}
		| exp YY_EQV exp 
			{
				// nor
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "!(%s == %s)");
				update_pos($$, $1, $3);
			}
		| exp YY_ANDAND exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos($$, $1, $3);
			}
		| exp YY_OROR exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos($$, $1, $3);
			}
		| YY_NOT exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op, "!(%s)");
				update_pos($$, $1, $2);
			}
		| exp YY_GT exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos($$, $1, $3);
			}
		| exp YY_GE exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos($$, $1, $3);
			}
		| exp YY_LE exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos($$, $1, $3);
			}
		| exp YY_LT exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos($$, $1, $3);
			}
		| hidden_do
			{
				ParseNode & hidden_do = $1;
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


	_crlf_semicolon: crlf
		| ';' crlf

	semicolon : ';'
			{
				$$ = $1;
			}
		|
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}

	label : YY_LABEL
		{
			$$ = gen_label($1);
			update_pos($$, $1, $1);
		}

	stmt : exp _crlf_semicolon
			{
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				$$ = gen_stmt($1, "%s ;");
				update_pos($$, $1, $2);
			}
		| var_def _crlf_semicolon
			{
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				$$ = gen_stmt($1, "%s ");
				update_pos($$, $1, $2);
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
		| semicolon YY_CRLF
			{
				ParseNode & xx = $1;
				update_pos($$, $1, $2);
			}
		| label
			{
				update_pos($$, $1, $1);
			}
		| common_stmt
			{
				$$ = $1;
			}


    output_stmt : write _crlf_semicolon
		| print _crlf_semicolon

	input_stmt : read _crlf_semicolon

	compound_stmt : if_stmt 
		| do_stmt 
		| select_stmt

	jump_stmt : YY_CONTINUE _crlf_semicolon
		| YY_BREAK _crlf_semicolon
		| YY_GOTO YY_INTEGER _crlf_semicolon
			{
				$$ = gen_token(Term{TokenMeta::Goto, "goto " + $1.fs.CurrentTerm.what + ";\n"});
				update_pos($$, $1, $3);
			}

	let_stmt : exp '=' exp _crlf_semicolon
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos($$);
			}

	dummy_stmt : YY_IMPLICIT YY_NONE crlf
			{
				// dummy stmt
				$$ = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos($$, $1, $3);
			}

	suite : stmt
			{
				$$ = gen_promote("%s\n", TokenMeta::NT_SUITE, $1);
				update_pos($$, $1, $1);
			}
		| stmt suite
			{
				$$ = gen_flattern($1, $2, "%s\n%s", TokenMeta::NT_SUITE);;
				update_pos($$, $1, $2);
			}
		| interface_decl
			{
				$$ = gen_promote("", TokenMeta::NT_SUITE, $1);
				update_pos($$, $1, $1);
			}
		| interface_decl suite
			{
				$$ = gen_flattern($1, $2, "%s%s", TokenMeta::NT_SUITE);
				update_pos($$, $1, $2);
			}


	_optional_lbrace : 
		| '('
	_optional_rbrace : 
		| ')'
	_optional_comma : ','
		|
	_optional_device : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
		| YY_INTEGER
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, $1.fs.CurrentTerm.what };
			}
	_optional_formatter : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
		| YY_INTEGER
			{
				// use format stmt at line $1 to format
				require_format_index($1.fs.CurrentTerm.what);
			}
		| YY_STRING
			{
				// replace `'` with `"`
				string modified = "\"" + $1.fs.CurrentTerm.what.substr(1, $1.fs.CurrentTerm.what.size() - 2) + "\"";
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}

	io_info : '(' _optional_device ',' _optional_formatter ')'
			{
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				ParseNode & _optional_device = $2;
				ParseNode & _optional_formatter = $4;
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode.addchild(new ParseNode(_optional_device)); // _optional_device
				newnode.addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				$$ = newnode;
				update_pos($$, $1, $5);
			}
		| _optional_formatter _optional_comma
			{
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				ParseNode & _optional_formatter = $1;
				/* target code of io_info depend on context */
				newnode.addchild(new ParseNode(_optional_device)); // _optional_device
				newnode.addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				$$ = newnode;
				update_pos($$, $1, $2);
			}


    write : YY_WRITE io_info paramtable 
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_write(io_info, argtable);
				update_pos($$, $1, $3);
			}

	print : YY_PRINT io_info paramtable
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_print(io_info, argtable);
				update_pos($$, $1, $3);
			}


	read: YY_READ io_info paramtable
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_read(io_info, argtable);
				update_pos($$, $1, $3);
			}

	type_nospec : YY_INTEGER_T 
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

    type_spec : YY_INTEGER_T '(' typecast_spec ')'
			{
				// now translated in pre_map
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_FLOAT_T '(' typecast_spec ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_STRING_T '(' typecast_spec ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_COMPLEX_T '(' typecast_spec ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_BOOL_T '(' typecast_spec ')'
			{
				$$ = gen_type($1, $3);
				update_pos($$, $1, $4);
			}
        | YY_CHARACTER_T '(' typecast_spec ')'
			{
				ParseNode newnode = gen_type($1);
				int len;
				sscanf($3.fs.CurrentTerm.what.c_str(), "%d", &len);
				set_variabledesc_attr(&newnode, boost::none, boost::none, boost::none, boost::none, len);
				update_pos($$, $1, $4);
			}
		| type_nospec '*' YY_INTEGER
			{
				// $$ = gen_type($1, $3);
				update_pos($$, $1, $3);
			}
		| type_nospec

	_blockname_or_none : '/' variable '/'
			{
				$$ = $2;
				update_pos($$, $1, $3);
			}
		| '/' '/'
			{
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				$$ = newnode;
				update_pos($$, $1, $2);
			}
		|
			{
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				$$ = newnode;
			}

	common_stmt : YY_COMMON _blockname_or_none paramtable
			{
				ParseNode & blockname = $2;
				ParseNode & paramtable = $3;
				$$ = gen_common(blockname, paramtable);
				update_pos($$, $1, $3);
			}

    var_def : type_spec variable_desc YY_DOUBLECOLON paramtable
			{
				/* array decl */
				ParseNode & type_spec = $1;
				ParseNode & variable_desc = $2;
				ParseNode & paramtable = $4;

				$$ = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos($$, $1, $4);
			}
		| type_spec variable_desc paramtable
			{
				/* array decl */
				ParseNode & type_spec = $1;
				ParseNode & variable_desc = $2;
				ParseNode & paramtable = $3;

				$$ = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos($$, $1, $3);
			}

    keyvalue : variable
			{ 
				// useless reduction
				/* paramtable is used in function decl */
			}
        | exp '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode & exp2 = $3;
				$$ = gen_keyvalue_from_exp($1, $3);
				update_pos($$, $1, $3);
			}

		| exp '=' array_builder
			{
				// array initial values 
				// 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 
				$$ = gen_keyvalue_from_arraybuilder($1, $3);
				update_pos($$, $1, $3);
			} 


	paramtable_elem : dimen_slice
			{
				// from rule ` dimen_slice : exp ',' paramtable `
			}
		| keyvalue
			{
			}

	paramtable : paramtable_elem
			{
				ParseNode & paramtable_elem = $1;
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| paramtable_elem ',' paramtable
			{
				ParseNode & paramtable_elem = $1;
				ParseNode & paramtable = $3;
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				$$ = newnode;
				update_pos($$, $1, $3);
			}
		|
			{
				/* no params */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
				$$ = newnode;
				update_pos($$);
			}

	_generate_stmt : exp ',' variable '=' exp ',' exp
			{
				/* something like `abs(i), i=1,4` */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_HIDDENDO, "" }), nullptr);
				newnode.addchild(new ParseNode($1)); // exp
				newnode.addchild(new ParseNode($3)); // index variable
				newnode.addchild(new ParseNode($5)); // exp_from
				newnode.addchild(new ParseNode($7)); // exp_to
				$$ = newnode;
				update_pos($$, $1, $7);
			}
		
	hidden_do : '(' _generate_stmt ')'
			{
				/* something like `abs(i), i=1,4` */
				ParseNode & _generate_stmt = $2;
				$$ = gen_hiddendo(_generate_stmt);
				update_pos($$, $1, $3);
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
				$$ = gen_array_from_hiddendo($2);
				update_pos($$, $1, $3);
				// rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule because \
				// these two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict 
				// so either that `variable '(' dimen_slice ')'` is an `exp`
			}

	/* array_builder can accept mixed */
	array_builder : array_builder_elem
			{
				ParseNode & array_builder_elem = $1;
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
		/* | array_builder_elem ',' array_builder
			{
				ParseNode & array_builder_elem = $1;
				ParseNode & array_builder = $3;
				print_error("nested arraybuilder is not supported");
				//ParseNode & array_builder_elem = $1;
				//ParseNode & array_builder = $3;
				//if (array_builder_elem.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
				//{
				//	$$ = gen_merge(array_builder_elem, array_builder, "", TokenMeta::NT_ARRAYBUILDER);
				//}
				//else {
				//	$$ = gen_flattern(array_builder_elem, array_builder, "", TokenMeta::NT_ARRAYBUILDER);
				//}
				//update_pos($$, $1, $3);

			}
		*/

	_yy_endif : YY_END YY_IF
		| YY_ENDIF

	/* _optional_then : YY_THEN
		|
		removed because of conflict with YY_THEN(i don't know why)
	*/

	if_stmt : YY_IF exp YY_THEN crlf suite _yy_endif crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; 
				$$ = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos($$, $1, $7);
			}
		| YY_IF exp YY_THEN crlf suite YY_ELSE crlf suite _yy_endif crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; 
				ParseNode & suite_else = $8; 
				$$ = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos($$, $1, $10);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt _yy_endif crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5;
				ParseNode & elseif = $6;
				$$ = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos($$, $1, $8);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite _yy_endif crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5;
				ParseNode & elseif = $6;
				ParseNode & suite_else = $9;
				$$ = gen_if(exp, suite_true, elseif, suite_else);
				update_pos($$, $1, $11);
			}
		|  YY_IF exp YY_THEN stmt
			{
				ParseNode & exp = $2;
				ParseNode & stmt_true = $4; 
				$$ = gen_if_oneline(exp, stmt_true);
				update_pos($$, $1, $4);
			}
		| YY_IF exp stmt
			{
				ParseNode & exp = $2;
				ParseNode & stmt_true = $3;
				$$ = gen_if_oneline(exp, stmt_true);
				update_pos($$, $1, $3);
			}

	elseif_stmt : YY_ELSEIF exp YY_THEN crlf suite
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5;
				$$ = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos($$, $1, $5);
			}

		| YY_ELSEIF exp YY_THEN crlf suite elseif_stmt
			{
				ParseNode & exp = $2;
				ParseNode & suite_true = $5;
				ParseNode & elseif = $6;
				$$ = gen_elseif(exp, suite_true, elseif);
				update_pos($$, $1, $6);
			}

	_yy_enddo : YY_END YY_DO
		| YY_ENDDO

	do_stmt : YY_DO crlf suite _yy_enddo crlf
			{
				ParseNode & suite = $3; 
				$$ = gen_do(suite);
				update_pos($$, $1, $5);
			}
		| YY_DO variable '=' exp ',' exp crlf suite _yy_enddo crlf
			{
				ParseNode & loop_variable = $2;
				ParseNode & exp_from = $4;
				ParseNode & exp_to = $6;
				ParseNode & step = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = $8; 
				$$ = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos($$, $1, $10);
			}
		| YY_DO variable '=' exp ',' exp ',' exp crlf suite _yy_enddo crlf
			{
				ParseNode & loop_variable = $2;
				ParseNode & exp1 = $4;
				ParseNode & exp2 = $6;
				ParseNode & exp3 = $8;
				ParseNode & suite = $10;
				$$ = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos($$, $1, $12);
			}
		| YY_DOWHILE exp crlf suite _yy_enddo crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite = $4; 
				$$ = gen_do_while(exp, suite);
				update_pos($$, $1, $6);
			}
	
	_yy_endselect : YY_END YY_SELECT
		| YY_ENDSELECT

	select_stmt : YY_SELECT YY_CASE _optional_lbrace exp _optional_rbrace crlf case_stmt _yy_endselect crlf
			{
				ParseNode & select = $1;
				ParseNode & exp = $4;
				ParseNode & case_stmt = $7;
				$$ = gen_select(exp, case_stmt);
				update_pos($$, $1, $9);
			}
	case_stmt_elem : YY_CASE _optional_lbrace dimen_slice _optional_rbrace crlf suite
			{
				// one case
				ParseNode & dimen_slice = $3;
				ParseNode & suite = $6; 
				$$ = gen_case(dimen_slice, suite);
				update_pos($$, $1, $6);
			}
	case_stmt : case_stmt_elem
			{
				ParseNode & case_stmt_elem = $1;
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_CASES, "" }), nullptr);
				newnode.addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				$$ = newnode;
				update_pos($$, $1, $1);
			}
	case_stmt : case_stmt_elem case_stmt
			{
				ParseNode & case_stmt_elem = $1;
				ParseNode & case_stmt = $2;
				ParseNode newnode = ParseNode(case_stmt);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode.addchild(new ParseNode(case_stmt_elem), false /* add to the front of the vector */); // case_stmt_elem
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
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				$$ = newnode;
				update_pos($$);
			}

	_optional_function : YY_FUNCTION
		| YY_SUBROUTINE

	function_decl : dummy_function_iden _optional_function variable '(' paramtable ')' _optional_result crlf suite YY_END _optional_function crlf
			{
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode & variable_function = $3; // function name
				/* enumerate paramtable */
				ParseNode & paramtable = $5;
				ParseNode & variable_result = $7; // result variable
				ParseNode & suite = $9;

				$$ = gen_function(variable_function, paramtable, variable_result, suite);
				update_pos($$, $1, $12);
			}
	
	_optional_name : YY_WORD
		|

    program : YY_PROGRAM _optional_name crlf suite YY_END YY_PROGRAM _optional_name crlf
			{
				ParseNode & suite = $4;
				$$ = gen_program_explicit(suite);
				update_pos($$, $1, $8);
			}
		| suite
			/* R1101 main-program is [ program-stmt ]
				[ specification-part ]
				[ execution-part ]
				[ internal-subprogram-part ]
				end-program-stmt */
			{
				ParseNode & suite = $1;
				$$ = gen_program(suite);
				update_pos($$, $1, $1);
			}


	wrapper :  function_decl
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				$$ = $1;
			}
		| program
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				$$ = $1;
			}	

	wrappers : wrapper
			{
				ParseNode newnode = ParseNode();
				newnode.addchild(new ParseNode($1)); // wrapper
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				$$ = newnode;
				update_pos($$, $1, $1);
			}
		| wrapper wrappers
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // wrapper
				newnode->addchild(new ParseNode($2)); // wrappers
				sprintf(codegen_buf, "%s\n%s", $1.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str());
				newnode = flattern_bin(newnode);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				$$ = *newnode;
				update_pos($$, $1, $2);
			}

	interface_decl : YY_INTERFACE _optional_name crlf wrappers crlf YY_END YY_INTERFACE _optional_name crlf
			{
				$$ = gen_interface($4);
				update_pos($$, $1, $9);
			}

	fortran_program : wrappers
			{
				gen_fortran_program($1);
			}
		|


%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), yylval);
}

void update_pos(YYSTYPE & current) {
	if (current.child.size() == 0) {
		/* do nothing */
		current.fs.parse_pos = 0;
		current.fs.parse_line = 0;
		current.fs.parse_len = 0;
		current.fs.line_pos = 0;
	}
	else if (current.child.size() == 1) {
		current.fs.parse_pos = current.child[0]->fs.parse_pos;
		current.fs.parse_line = current.child[0]->fs.parse_line;
		current.fs.parse_len = current.child[0]->fs.parse_len;
		current.fs.line_pos = current.child[0]->fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.child.size(); i++)
		{
			tot_len += current.child[i]->fs.parse_len;
		}
		current.fs.parse_pos = current.child[0]->fs.parse_pos;
		current.fs.parse_line = current.child[0]->fs.parse_line;
		current.fs.parse_len = tot_len;
		current.fs.line_pos = current.child[0]->fs.line_pos;
	}
}
void update_pos(YYSTYPE & current, YYSTYPE & start, YYSTYPE & end) {
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

int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
