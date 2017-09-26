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


// ǰ������, ��Ȼ���벻��
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

%token _YY_VOID YY_REQ_MORE YY_CRLF
%token _YY_OP YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG YY_POS
%token _YY_TYPE YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token _YY_CONTROL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT
%token _YY_DELIM YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK YY_INTERFACE YY_ENDINTERFACE
%token _YY_DESCRIBER YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY YY_DIMENSION YY_ARRAYINITIAL_START YY_ARRAYINITIAL_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND
%token _YY_TYPEDEF YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T
%token _YY_COMMAND YY_WRITE YY_READ YY_PRINT YY_OPEN YY_CLOSE YY_CALL


%left '='
%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%right YY_NEG YY_POS
%left '+' '-' 
%left '*' '/' 
%left YY_POWER
%right YY_NOT

%start fortran_program

%%
	crlf : YY_CRLF
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos($$);
			}
		| ';'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
				update_pos($$);
			}
		|
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
				update_pos($$);
			}

	dummy_function_iden : YY_RECURSIVE
		| dummy_function_iden
		|

	dummy_variable_iden_1 : YY_INTENT '(' YY_IN ')'
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(in)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = true;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_INTENT '(' YY_OUT ')'
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(out)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = false;
				$$ = *newnode;
				update_pos($$);
			}

		| YY_INTENT '(' YY_INOUT ')'
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = false;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DIMENSION '(' dimen_slice ')'
			{
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode * newnode = new ParseNode();
				ParseNode * dimen = new ParseNode($3);
				newnode->addchild(dimen); // def slice
				int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
				for (sliceid = 0; sliceid < dimen->child.size(); sliceid++)
				{
					sprintf(codegen_buf, "(%s, %s)"
						/* from, to */
						, dimen->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
						, dimen->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
					dimen->child[sliceid]->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
				}
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = dimen;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DIMENSION '(' exp ')'
			{
				/* define array like a(1) */
				ParseNode * newnode = new ParseNode();
				ParseNode * dimen = new ParseNode();
				ParseNode * slice = new ParseNode();
				ParseNode * exp = new ParseNode();
				exp->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "1" };
				slice->addchild(exp); // slice from 1
				sprintf(codegen_buf, "%s", /* from 1, to */$3.fs.CurrentTerm.what.c_str());
				slice->addchild(new ParseNode($3)); // slice to
				dimen->addchild(slice);
				newnode->addchild(dimen); // def slice

				int sliceid = 0; /* only 1 dimension */
				sprintf(codegen_buf, "(%s, %s)"
					/* from 1, to */
					, dimen->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
					, dimen->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
				dimen->child[sliceid]->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };

				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = dimen;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_OPTIONAL
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.optional = true;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_PARAMETER
			{
				/* const value */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // const
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = true;
				$$ = *newnode;
				update_pos($$);
			}
		| YY_LEN '=' exp
			{
				// do nothing because we use std::string
			}
		| YY_KIND '=' YY_INTEGER
			{
				int kind;
				sscanf($3.fs.CurrentTerm.what.c_str(), "%d", &kind);
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // kind
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.kind = kind;
				$$ = *newnode;
				update_pos($$);
			}
				
	dummy_variable_iden : ',' dummy_variable_iden_1
			{
				ParseNode * newnode = new ParseNode($1);
				$$ = $2;
				update_pos($$);
			}
		| ',' dummy_variable_iden_1 dummy_variable_iden
			{				
				ParseNode * newnode = new ParseNode();
				ParseNode * variable_iden = & $3;
				ParseNode & variable_iden_1 = $2;
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				newnode->attr = variable_iden_1.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(variable_iden->attr);
				new_a->merge(*var_a);
				// TODO do not add child
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	dummy_variable_spec : dummy_variable_iden_1
			{
				ParseNode * newnode = new ParseNode($1);
				$$ = $1;
				update_pos($$);
			}
		| dummy_variable_iden_1 dummy_variable_spec
			{				
				ParseNode * newnode = new ParseNode();
				ParseNode * variable_iden = & $2;
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				newnode->attr = $1.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(variable_iden->attr);
				new_a->merge(*var_a);
				// TODO do not add child
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	literal : YY_FLOAT
			{
				/* ����Ŀ�µ��Ҳ�ȫ��Ϊ�����ս����(�﷨����Ҷ�ӽڵ�), ���$1ȫ������lex���� */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, $1.fs.CurrentTerm.what }; // float number
				$$ = *newnode;
			}
		| YY_INTEGER
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, $1.fs.CurrentTerm.what }; // int number
				$$ = *newnode;
			}
		| YY_STRING
			{
				ParseNode * newnode = new ParseNode();
				// replace `'` with `"`
				string modified = "\"" + $1.fs.CurrentTerm.what.substr(1, $1.fs.CurrentTerm.what.size() - 2) + "\"";
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, modified }; // string
				$$ = *newnode;
			}
		| YY_TRUE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "true" }; // bool true
				$$ = *newnode;
			}
		| YY_FALSE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "false" }; // bool false
				$$ = *newnode;
			}
        | YY_COMPLEX
            {
				ParseNode * newnode = new ParseNode();
				string strcplx = $1.fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				newnode->fs.CurrentTerm = Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") "}; // complex
				$$ = *newnode;
			}

		| error '\n'


	variable : YY_WORD
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, $1.fs.CurrentTerm.what }; // variant
				$$ = *newnode;
			}

	callable_head : variable | type_spec
			{
				/* array index and function name and type cast */
				string x = $1.fs.CurrentTerm.what;
				$$ = $1;
			}
	
	slice : exp ':' exp
			{
				/* arr[from : to] */
				ParseNode & exp1 = $1;
				ParseNode & exp2 = $3;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2);
				update_pos($$);
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to : step] */
				ParseNode & exp1 = $1;
				ParseNode & exp2 = $3;
				ParseNode & exp3 = $5;
				/* target code of slice depend on context */
				$$ = gen_slice(exp1, exp2, exp3);
				update_pos($$);
			}
		| ':'
			{
				/* arr[from : to : step] */
				ParseNode & lb = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER, "-1" }));
				ParseNode & ub = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER, "-1" }));
				/* target code of slice depend on context */
				$$ = gen_slice(lb, ub);
				update_pos($$);
			}

	dimen_slice : slice 
			{
				/* 1d array */
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				ParseNode & slice = $1;
				if (slice.child.size() == 1) {
					// not a slice but a index
					slice.child.push_back(nullptr);
					slice.child[1] = slice.child[0];
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "1" };
					slice.child[0] = lb;
				}
				newnode->addchild(new ParseNode(slice)); // only 1 slice
				$$ = *newnode;
				update_pos($$);
			}
		| slice ',' dimen_slice
			{
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				ParseNode & slice = $1;
				if (slice.child.size() == 1) {
					slice.child.push_back(nullptr);
					slice.child[1] = slice.child[0];
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "1" };
					slice.child[0] = lb;
				}
				newnode->addchild(new ParseNode(slice)); // slice
				newnode->addchild(new ParseNode($3)); // dimen_slice
				// attention flattern_bin
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
		| exp
			{
				/* argtable is used in function call */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode($1)); // exp
				$$ = *newnode;
				update_pos($$);
			}
        | exp ',' argtable
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $1;
				ParseNode & argtable = $3;
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(argtable)); // argtable
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
				
	function_array_body : callable_head '(' argtable ')'
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode & callable_head = $1;
				ParseNode & argtable = $3;
				$$ = gen_function_array(callable_head, argtable);
				update_pos($$);
			}

	function_array : function_array_body
			{
				$$ = $1
			}
		| YY_CALL function_array_body
			{
				$$ = $2
			}

	exp : function_array 
			{
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
				ParseNode & function_array = $1;
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION,  function_array.fs.CurrentTerm.what };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(function_array)); // function_array
				$$ = *newnode;
				update_pos($$);
			}

		| '(' exp ')' 
			{
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = $2;
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				$$ = gen_exp(exp, op, "( %s )");
				update_pos($$);
			}
		| exp '+' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos($$);
			}
		| exp '-' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos($$);
			}
		| exp '*' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos($$);
			}
		| exp '/' exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos($$);
			}
		| exp YY_POWER exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos($$);
			}
        | '-' %prec YY_NEG exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "(-%s)");
				update_pos($$);
			}
        | '+' %prec YY_NEG exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op,  "%s");
				update_pos($$);
			}
		| exp YY_NEQ exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos($$);
			}
		| exp YY_NEQV exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos($$);
			}
		| exp YY_EQ exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos($$);
			}
		| exp YY_EQV exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos($$);
			}
		| exp YY_ANDAND exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos($$);
			}
		| exp YY_OROR exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos($$);
			}
		| YY_NOT exp 
			{
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				$$ = gen_exp(exp1, op, "!(%s)");
				update_pos($$);
			}
		| exp YY_GT exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos($$);
			}
		| exp YY_GE exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos($$);
			}
		| exp YY_LE exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos($$);
			}
		| exp YY_LT exp 
			{
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				$$ = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos($$);
			}
		| literal 
            { 
				// 
				ParseNode & exp = $1;
				$$ = $1;
			}
		| callable_head
			{
				// may cause reduction-reduction conflict when use `variable` instead of `callable_head`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable_head will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				ParseNode & exp = $1;
				$$ = $1;
			}

    argtable : dimen_slice
			{
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				ParseNode & dimen_slice = $1;
				bool isdimen = false;
				int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
				dimen_slice.fs.CurrentTerm.what = "";
				for (sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
				{
					if (sliceid != 0) {
						dimen_slice.fs.CurrentTerm.what += ", ";
					}
					if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
						// dimen_slice
						isdimen = true;
						newnode->addchild(new ParseNode(*dimen_slice.child[sliceid]));
						sprintf(codegen_buf, "%s, %s"
							/* from, to */
							, dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
							, dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
					}
					else {
						// exp
						isdimen = false;
						newnode->addchild(new ParseNode(*dimen_slice.child[sliceid]));
						sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->fs.CurrentTerm.what.c_str());
					}
					dimen_slice.fs.CurrentTerm.what += codegen_buf;
				}
				if (isdimen) {
					//sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
					sprintf(codegen_buf, "%%s.slice(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_DIMENSLICE, string(codegen_buf) };
				}
				else {
					//sprintf(codegen_buf, "%%s(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
					sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
				}
#endif // !LAZY_GEN
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				// TODO : argtable can also be empty
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, "" };
#endif // !LAZY_GEN
				$$ = *newnode;
				update_pos($$);
			}

	_crlf_semicolon : crlf
		| ';' crlf

	stmt : exp _crlf_semicolon
			{
				// TODO IMPORTANT
				/*
					һ����˵, ���Բ���������stmt��ParseNode, �����Ψһ��child(exp, var_def, compound_stmt��).
					���ǿ��ǵ���cpp�������п��ܳ���ʹ��,�ָ�����������(��������������õ�, �������������԰����Լ���˳����ֵ)
					���Ե�������stmt�ڵ�����$1λstmt�ڵ��Ψһ�Ķ���
				*/
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $1;
				//(crlf.fs.CurrentTerm.token == TokenMeta::CRLF ? ";" : "")
				sprintf(codegen_buf, "%s ;", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp)); // exp
				$$ = *newnode;
				update_pos($$);
			}
		| var_def _crlf_semicolon
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & var_def = $1;
				/* ��Ϊvar_def����������ɶ��д���, ��˴˴����ɴ��벻Ӧ�����ֺ�`;` */
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s ", var_def.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(var_def)); // var_def
				$$ = *newnode;
				update_pos($$);
			}
        | compound_stmt
        | output_stmt 
		| input_stmt 
		| dummy_stmt
		| let_stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & let = $1;
				sprintf(codegen_buf, "%s ;", let.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(let)); // let
				$$ = *newnode;
				update_pos($$);
			}
		| jump_stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & jmp = $1;
				sprintf(codegen_buf, "%s ;", jmp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(jmp)); // jmp
				$$ = *newnode;
				update_pos($$);
			}
		| interface_decl


    output_stmt : write _crlf_semicolon
		| print _crlf_semicolon

	input_stmt : read _crlf_semicolon

	compound_stmt : if_stmt 
		| do_stmt 
		| select_stmt

	jump_stmt : YY_CONTINUE _crlf_semicolon
		| YY_BREAK crlf
		| YY_GOTO crlf

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
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, "" };
				// dummy stmt
				$$ = *newnode;
				update_pos($$);
			}

	suite : stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = $1;
				sprintf(codegen_buf, "%s\n", stmt.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				$$ = *newnode;
				update_pos($$);
			}
		| stmt suite
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = $1;
				ParseNode & suite = $2;
				sprintf(codegen_buf, "%s\n%s", stmt.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				newnode->addchild(new ParseNode(suite)); // suite
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				/* suite can be empty but stmt can not */
				ParseNode * newnode = new ParseNode();
				FlexState fs; fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
				ParseNode & stmt = ParseNode(fs, newnode, nullptr);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
				newnode->addchild(new ParseNode(stmt)); // stmt
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	_optional_lbrace : 
		| '('
	_optional_rbrace : 
		| ')'
	_optional_comma : ','
		|
	_optional_device : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				update_pos($$);
			}
		| YY_INTEGER
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, $1.fs.CurrentTerm.what };
				update_pos($$);
			}
	_optional_formatter : '*'
			{
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
				update_pos($$);
			}
		| YY_STRING
			{
				// replace `'` with `"`
				string modified = "\"" + $1.fs.CurrentTerm.what.substr(1, $1.fs.CurrentTerm.what.size() - 2) + "\"";
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
				update_pos($$);
			}

	io_info : '(' _optional_device ',' _optional_formatter ')'
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & _optional_device = $2;
				ParseNode & _optional_formatter = $4;
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode(_optional_device)); // _optional_device
				newnode->addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				$$ = *newnode;
				update_pos($$);
			}
		| _optional_formatter _optional_comma
			{
				ParseNode * newnode = new ParseNode();
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				ParseNode _optional_formatter = $1;
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode(_optional_device)); // _optional_device
				newnode->addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				$$ = *newnode;
				update_pos($$);
			}


    write : YY_WRITE io_info argtable 
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_write(io_info, argtable);
				update_pos($$);
			}

	print : YY_PRINT io_info argtable 
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_print(io_info, argtable);
				update_pos($$);
			}


	read: YY_READ io_info argtable 
			{
				ParseNode & io_info = $2;
				ParseNode & argtable = $3;
				$$ = gen_read(io_info, argtable);
				update_pos($$);
			}
				
	_type_kind : '(' dummy_variable_spec ')'
			{
				$$ = $2;
				update_pos($$);
			}
		| 
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				newnode->attr = new VariableDescAttr(newnode);
				$$ = *newnode;
				update_pos($$);
			}

    type_spec : YY_INTEGER_T _type_kind
			{
				// now translated in pre_map
				//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}
        | YY_FLOAT_T _type_kind
			{
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}
        | YY_STRING_T _type_kind
			{
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}
        | YY_COMPLEX_T _type_kind
			{
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}
        | YY_BOOL_T _type_kind
			{
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}
        | YY_CHARACTER_T _type_kind
			{
				$$ = $1;
				ParseNode * newnode = &$$;
				newnode->attr = $2.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>($2.attr);
				new_a->merge(*var_a);
				update_pos($$);
			}


    var_def : type_spec dummy_variable_iden YY_DOUBLECOLON paramtable 
			{
				/* array decl */
				ParseNode & type_spec = $1;
				ParseNode & dummy_variable_iden = $2;
				ParseNode & paramtable = $4;

				$$ = gen_vardef(type_spec, dummy_variable_iden, paramtable);
				update_pos($$);
			}

    keyvalue : variable
			{
				/* paramtable is used in function decl */
				/* this paramtable has only one value */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild( new ParseNode($1) ); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") };
					variablenode->addchild( new ParseNode(fs, newnode) ); // void is dummy initial
					newnode->addchild(variablenode);
				$$ = *newnode;
				update_pos($$);
			}
        | variable '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s" , $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // variable
					variablenode->addchild(new ParseNode($3)); // initial
					newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
		| variable '=' array_builder
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* array initial values */
				ParseNode * newnode = new ParseNode();
				/* ��Ϊʹ��forarray��Ϊ����, ����Ҫ֪��������Ϣ, ���ڴ˴���ֵ, ���ϲ��var_def����ֵ */
				sprintf(codegen_buf, "%s.init(%s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s.init(%s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // variable
					variablenode->addchild(new ParseNode($3)); // initial(array_builder)
				newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	paramtable : keyvalue
			{
				$$ = $1;
				update_pos($$);
			}
		| keyvalue ',' paramtable
			{
				ParseNode * newnode = new ParseNode(); 
				newnode->addchild($1.child[0]); // keyvalue
				sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
				ParseNode & pn = $3;
				for (int i = 0; i < pn.child.size(); i++)
				{
					newnode->addchild(new ParseNode(*pn.child[i])); // paramtable
				}
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				/* no params */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, "" };
				$$ = *newnode;
				update_pos($$);
			}

	_generate_stmt : exp ',' variable '=' exp ',' exp
			{
				/* something like `abs(i), i=1,4` */
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // exp
				newnode->addchild(new ParseNode($3)); // index variable
				newnode->addchild(new ParseNode($5)); // exp_from
				newnode->addchild(new ParseNode($7)); // exp_to
				$$ = *newnode;
				update_pos($$);
			}

	array_builder_elem : YY_ARRAYINITIAL_START argtable YY_ARRAYINITIAL_END
			{
				/* give initial value */
				/* NOTE that `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, NOW we merge rules */
				/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
				ParseNode * newnode = new ParseNode();
				ParseNode & argtable = $2; 
				/* for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound
				, const std::vector<int> & size, const std::vector<T> & values */
				sprintf(codegen_buf, "init_for1array(%%s, %%s, %%s, %s);\n", /* value */ argtable.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE, string(codegen_buf) };
				newnode->addchild(new ParseNode(argtable)); // argtable
				$$ = *newnode;
				update_pos($$);
			}
		| YY_ARRAYINITIAL_START _generate_stmt YY_ARRAYINITIAL_END
			{
				/* give generate stmt */
				ParseNode * newnode = new ParseNode();
				ParseNode * exp = $2.child[0];
				ParseNode * index = $2.child[1];
				ParseNode * from = $2.child[2];
				ParseNode * to = $2.child[3];
				sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s;\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
					, index->fs.CurrentTerm.what.c_str(), to->fs.CurrentTerm.what.c_str() /* exp_to */, index->fs.CurrentTerm.what.c_str() /* index variable inc */
					, "\t%s" /* array variable name */, index->fs.CurrentTerm.what.c_str() /* index variable */, exp->fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
				newnode->addchild(new ParseNode(*exp)); // exp
				newnode->addchild(new ParseNode(*index)); // index variable
				newnode->addchild(new ParseNode(*from)); // exp_from
				newnode->addchild(new ParseNode(*to)); // exp_to
				$$ = *newnode;
				update_pos($$);
				// TODO 
				/* rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule*/
				/* note that this two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict */
				/* note either that `variable '(' dimen_slice ')'` is an `exp` */
			}
	_optional_then : YY_THEN
		|
	array_builder : array_builder_elem
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // array_builder_elem
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, string(codegen_buf) };
				$$ = *newnode;
				update_pos($$);
			}
		| array_builder_elem ',' array_builder
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // array_builder_elem
				newnode->addchild(new ParseNode($3)); // array_builder
				sprintf(codegen_buf, "%s\n%s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, string(codegen_buf) };
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}

	if_stmt : YY_IF exp YY_THEN crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite YY_ELSE crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & suite_else = $8; suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode($6)); // else
				newnode->addchild(new ParseNode(suite_else)); // else-stmt
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = $6;
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // recursive elseif-stmt
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = $6;
				ParseNode & suite_else = $9; suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
				
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // recursive elseif-stmt
				newnode->addchild(new ParseNode(suite_else)); // else-stmt
				$$ = *newnode;
				update_pos($$);
			}
		|  YY_IF exp _optional_then stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & stmt_true = $4; 
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) %s", exp.fs.CurrentTerm.what.c_str(), stmt_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(stmt_true)); // stmt
				$$ = *newnode;
				update_pos($$);
			}
	elseif_stmt : YY_ELSEIF exp YY_THEN crlf suite
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if(%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				$$ = *newnode;
				update_pos($$);
			}

		| YY_ELSEIF exp YY_THEN crlf suite elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite_true = $5; suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = $6;
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if{\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // another elseif-stmt
				$$ = *newnode;
				update_pos($$);
			}

	do_stmt : YY_DO crlf suite YY_END YY_DO crlf
			{
				ParseNode & suite = $3; 
				$$ = gen_do(suite);
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp crlf suite YY_END YY_DO crlf
			{
				ParseNode & loop_variable = $2;
				ParseNode & exp_from = $4;
				ParseNode & exp_to = $6;
				ParseNode & step = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = $8; 
				$$ = gen_do_range(exp_from, exp_from, exp_to, step, suite);
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp ',' exp crlf suite YY_END YY_DO crlf
			{
				ParseNode & loop_variable = $2;
				ParseNode & exp1 = $4;
				ParseNode & exp2 = $6;
				ParseNode & exp3 = $8;
				ParseNode & suite = $10;
				$$ = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos($$);
			}
		| YY_DOWHILE exp crlf suite YY_END YY_DO crlf
			{
				ParseNode & exp = $2;
				ParseNode & suite = $4; 
				$$ = gen_do_while(exp, suite);
				update_pos($$);
			}

	select_stmt : YY_SELECT YY_CASE _optional_lbrace exp _optional_rbrace crlf case_stmt YY_END YY_SELECT crlf
			{
				ParseNode & select = $1;
				ParseNode & exp = $4;
				ParseNode & case_stmt = $7;
				$$ = gen_select(exp, case_stmt);
				update_pos($$);
			}
	case_stmt_elem : YY_CASE _optional_lbrace dimen_slice _optional_rbrace crlf suite
			{
				// one case
				ParseNode & dimen_slice = $3;
				ParseNode & suite = $6; 
				$$ = gen_case(dimen_slice, suite);
				update_pos($$);
			}
	case_stmt : case_stmt_elem
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & case_stmt_elem = $1;
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode->addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				$$ = *newnode;
				update_pos($$);
			}
	case_stmt : case_stmt_elem case_stmt
			{
				ParseNode & case_stmt_elem = $1;
				ParseNode & case_stmt = $2;
				ParseNode * newnode = new ParseNode(case_stmt);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode->addchild(new ParseNode(case_stmt_elem), false /* add to the front of the vector */); // case_stmt_elem
				$$ = *newnode;
				update_pos($$);
			}
	
	_optional_result : YY_RESULT '(' variable ')'
			{
				$$ = $3;
			}
		|
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, "" }; // return nothing
				$$ = *newnode;
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
				update_pos($$);
			}
	
	_optional_name : YY_WORD
		|

    program : YY_PROGRAM _optional_name crlf suite YY_END YY_PROGRAM _optional_name crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($4)); //suite
				sprintf(codegen_buf, "int main()\n{%s\treturn 0;\n}", tabber($4.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				$$ = *newnode;
			}


	wrapper :  function_decl
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				$$ = $1;
				update_pos($$);
			}
		| program
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				$$ = $1;
				update_pos($$);
			}	

	wrappers : wrapper
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // wrapper
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				$$ = *newnode;
			}
		| wrapper wrappers
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($1)); // wrapper
				newnode->addchild(new ParseNode($2)); // wrappers
				sprintf(codegen_buf, "%s\n%s", $1.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str());
				newnode = flattern_bin(newnode);
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				$$ = *newnode;
			}

	interface_decl : YY_INTERFACE crlf wrappers crlf YY_END YY_INTERFACE crlf
			{
				// drop interface directly
				ParseNode * newnode = new ParseNode();
				// no child
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				$$ = *newnode;
			}

	fortran_program : wrappers
			{
				program_tree = $1;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), yylval);
}

string tabber(string & src) {
	string newline;
	string ans = "";
	std::istringstream f(src);
	while (getline(f, newline) ) {
		ans += '\t';
		ans += newline;
		ans += '\n';
	}
	return ans;
}
ParseNode * flattern_bin(ParseNode * pn) {
	/* it cant work well because it create a whole noew tree copy too much */
	/* THIS ALGORITHM FLATTERNS A RIGHT-RECURSIVE BINARY TREE */
	if (pn->child.size() == 2) {
		ParseNode * newp = new ParseNode();
		/* child[0] is the only data node */
		newp->addchild(new ParseNode(*pn->child[0]));

		/* pn->child[1] is a **list** of ALREADY flatterned elements */
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
		for (int i = 0; i < pn->child[1]->child.size(); i++)
		{
			newp->addchild(new ParseNode(*pn->child[1]->child[i]));
		}
		newp->fs = pn->fs;
		newp->father = pn->father;
		delete pn;
		return newp;
	}
	else {
		return pn;
	}
}
void update_pos(YYSTYPE & current_node) {
	if (current_node.child.size() == 0) {
		/* do nothing */
	}
	else if (current_node.child.size() == 1) {
		current_node.fs.parse_pos = current_node.child[0]->fs.parse_pos;
		current_node.fs.parse_line = current_node.child[0]->fs.parse_line;
		current_node.fs.parse_len = current_node.child[0]->fs.parse_len;
		current_node.fs.line_pos = current_node.child[0]->fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current_node.child.size(); i++)
		{
			tot_len += current_node.child[i]->fs.parse_len;
		}
		current_node.fs.parse_pos = current_node.child[0]->fs.parse_pos;
		current_node.fs.parse_line = current_node.child[0]->fs.parse_line;
		current_node.fs.parse_len = tot_len;
		current_node.fs.line_pos = current_node.child[0]->fs.line_pos;
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
