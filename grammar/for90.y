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
#include "../cgen.h"

// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE
#define MAX_CODE_LENGTH 65535
char codegen_buf[MAX_CODE_LENGTH];
using namespace std;
%}

%debug

%token _YY_VOID YY_REQ_MORE YY_CRLF
%token _YY_OP YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token _YY_TYPE YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token _YY_CONTROL YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE YY_SELECT YY_ENDSELECT YY_GOTO YY_DOWHILE YY_DEFAULT
%token _YY_DELIM YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK
%token _YY_DESCRIBER YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY YY_DIMENSION YY_ARRAYINITIAL_START YY_ARRAYINITIAL_END YY_INTENT YY_IN YY_OUT YY_INOUT YY_OPTIONAL YY_LEN YY_KIND
%token _YY_TYPEDEF YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T YY_CHARACTER_T
%token _YY_COMMAND YY_WRITE YY_READ YY_PRINT YY_OPEN YY_CLOSE YY_CALL


%left '='
%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%left '+' '-' 
%left '*' '/' 
%left YY_POWER
%right YY_NEG YY_NOT

%start program

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
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
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

	callable : variable | type_spec
			{
				/* array index and function name and type cast */
				string x = $1.fs.CurrentTerm.what;
				$$ = $1;
			}
	
	slice : exp ':' exp
			{
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				ParseNode & lb = $1;
				ParseNode & ub = $3;
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode(lb)); // lower bound
				newnode->addchild(new ParseNode(ub)); // upper bound
				$$ = *newnode;
				update_pos($$);
				/*
				*/			
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to : step] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode($1)); // lower bound
				newnode->addchild(new ParseNode($3)); // upper bound
				newnode->addchild(new ParseNode($5)); // step
				$$ = *newnode;
				update_pos($$);
			}
		| ':'
			{
				/* arr[from : to : step] */
				ParseNode * newnode = new ParseNode();
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "-1" };
					ParseNode * ub = new ParseNode();
					ub->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "-1" };
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode(*lb)); // lower bound
				newnode->addchild(new ParseNode(*ub)); // upper bound
				$$ = *newnode;
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

	function_array : callable '(' argtable ')' 
			{
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode * newnode = new ParseNode();
				ParseNode & callable = $1;
				ParseNode & argtable = $3;
#ifndef LAZY_GEN
				string name;
				string x;
				if (funcname_map.find(callable.fs.CurrentTerm.what) != funcname_map.end()) {
					name = funcname_map.at(callable.fs.CurrentTerm.what);
				}
				else {
					name = callable.fs.CurrentTerm.what;
				}
				if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_DIMENSLICE) {
					sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  string(codegen_buf) };
				}
				else {
					x += name;
					x += "(";
					x += argtable.fs.CurrentTerm.what;
					x += ")";
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  x };
				}
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(callable)); // function/array name
				newnode->addchild(new ParseNode(argtable)); // argtable
				$$ = *newnode;
				update_pos($$);
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
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
#ifndef LAZY_GEN
				sprintf(codegen_buf, "( %s )", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(exp));
				$$ = *newnode;
				update_pos($$);
			}
		| exp '+' exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s + %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // +
				newnode->addchild(new ParseNode(exp2)); // tight operand exp
				$$ = *newnode;
			}
		| exp '-' exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s - %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // -
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp '*' exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s * %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // *
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp '/' exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s / %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // /
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_POWER exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "power(%s, %s)", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // **
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
        | '-' %prec YY_NEG exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				sprintf(codegen_buf, "(-%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // (-)
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				$$ = *newnode;
				update_pos($$);
			}
		| exp YY_NEQ exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_NEQV exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_EQ exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_EQV exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_ANDAND exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s && %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // &&
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_OROR exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s || %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ||
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| YY_NOT exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $2;
				ParseNode & op = $1;
				sprintf(codegen_buf, "!(%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // !
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				$$ = *newnode;
				update_pos($$);
			}
		| exp YY_GT exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s > %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_GE exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s >= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_LE exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s <= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_LT exp 
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s < %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
			}
		| literal 
            { 
				// 
				$$ = $1;
			}
		| callable 
			{
				// may cause reduction-reduction conflict when use `variable` instead of `callable`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
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

	stmt : exp crlf
			{
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $1;
				//(crlf.fs.CurrentTerm.token == TokenMeta::CRLF ? ";" : "")
				sprintf(codegen_buf, "%s ;\n", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp)); // exp
				$$ = *newnode;
				update_pos($$);
			}
		| var_def crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & var_def = $1;
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s \n", var_def.fs.CurrentTerm.what.c_str());
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
				sprintf(codegen_buf, "%s ;\n", let.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(let)); // let
				$$ = *newnode;
				update_pos($$);
			}
		| jump_stmt
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & jmp = $1;
				sprintf(codegen_buf, "%s ;\n", jmp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(jmp)); // jmp
				$$ = *newnode;
				update_pos($$);
			}

    output_stmt : write
	input_stmt : read

	compound_stmt : if_stmt 
		| do_stmt 
		| select_stmt

	jump_stmt : YY_CONTINUE
		| YY_BREAK
		| YY_GOTO

	let_stmt : exp '=' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = $1;
				ParseNode & op = $2;
				ParseNode & exp2 = $3;
				sprintf(codegen_buf, "%s = %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::Let, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // =
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				$$ = *newnode;
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
				sprintf(codegen_buf, "%s \n", stmt.fs.CurrentTerm.what.c_str());
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
				sprintf(codegen_buf, "%s \n %s \n", stmt.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
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

	io_info : _optional_device ',' _optional_formatter
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & _optional_device = $1;
				ParseNode & _optional_formatter = $3;
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode(_optional_device)); // _optional_device
				newnode->addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				$$ = *newnode;
				update_pos($$);
			}

    write : YY_WRITE _optional_lbrace io_info _optional_rbrace argtable crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = $3;
				ParseNode & argtable = $5;
				ParseNode * argtbl = &argtable;
				ParseNode * formatter = io_info.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				}
				else {
					/* NT_AUTOFORMATTER */
					string coutcode = "cout";
					/* enumerate argtable */
					// TODO the while loop is wrong, there is need for while loop. ref: var_def code
					//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
						// for all non-flatterned argtable
						for (int i = 0; i < argtbl->child.size(); i++)
						{
							// for each variable in flatterned argtable
							coutcode += "<<";
							coutcode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					coutcode += ";";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode(argtable)); // argtable
				$$ = *newnode;
				update_pos($$);
			}

	read: YY_READ _optional_lbrace io_info _optional_rbrace argtable crlf
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = $3;
				ParseNode & argtable = $5;
				ParseNode * argtbl = &argtable;
				ParseNode * formatter = $3.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					string pointer_to;
					for (int i = 0; i < argtbl->child.size(); i++)
					{
						if (i > 0) {
							pointer_to += ",";
						}
						pointer_to += "&";
						pointer_to += argtbl->child[i]->fs.CurrentTerm.what;
					}
					argtbl = argtbl->child[1];
					sprintf(codegen_buf, "scanf(\"%s\", %s) ;\n", parse_ioformatter(fmt).c_str(), pointer_to.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				}
				else {
					/* NT_AUTOFORMATTER */
					string cincode = "cin";
					/* enumerate argtable */
					// TODO the while loop is wrong, there is need for while loop. ref: var_def code
					//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
						// for all non-flatterned argtable
						for (int i = 0; i < argtbl->child.size(); i++)
						{
							// for each variable in flatterned argtable
							cincode += ">>";
							cincode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					cincode += ";";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, cincode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode(argtable)); // argtable
				$$ = *newnode;
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
				string arr_decl = ""; string var_decl = ""; bool do_arr = false;
				ParseNode * newnode = new ParseNode();
				ParseNode & type_spec = $1;
				ParseNode & dummy_variable_iden = $2;
				ParseNode * ty = new ParseNode(type_spec); // type
				VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(dummy_variable_iden.attr);
				ParseNode * slice = vardescattr->desc.slice;
				newnode->addchild(ty); // type
				// specify type
				/* merge type_spec and dummy_variable_iden attr */
				VariableDescAttr * ty_a = dynamic_cast<VariableDescAttr *>(type_spec.attr);
				vardescattr->merge(*ty_a);
				if (vardescattr->desc.kind != 0) {
					if (type_spec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
						if (vardescattr->desc.kind == 1) {
							ty->fs.CurrentTerm.what = "char";
						}
						else if (vardescattr->desc.kind == 2) {
							ty->fs.CurrentTerm.what = "int";
						}
						else if (vardescattr->desc.kind == 4) {
							ty->fs.CurrentTerm.what = "int";
						}
						else if (vardescattr->desc.kind == 8) {
							ty->fs.CurrentTerm.what = "long long";
						}
					}
					else if (type_spec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
						if (vardescattr->desc.kind == 1) {
							ty->fs.CurrentTerm.what = "float";
						}
						else if (vardescattr->desc.kind == 2) {
							ty->fs.CurrentTerm.what = "double";
						}
						else if (vardescattr->desc.kind == 4) {
							ty->fs.CurrentTerm.what = "double";
						}
						else if (vardescattr->desc.kind == 8) {
							ty->fs.CurrentTerm.what = "long double";
						}
					}
				}
				if (slice == nullptr) {
					// slice == nullptr if this is not array
					/* must assure no ParseNode * is nullptr */
					slice = new ParseNode();
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VOID, "" };
				}
				else {
					do_arr = true;
				}
				newnode->addchild(slice); 
				ParseNode * pn = new ParseNode($4); // paramtable
				newnode->addchild(pn); // paramtable
				if (do_arr)
				{
					/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
					/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
#define USE_LOOP
						for (int i = 0; i < pn->child.size(); i++)
						{
							// for each variable in flatterned paramtable
							int sliceid = 0;
							sprintf(codegen_buf, "forarray<%s>", ty->fs.CurrentTerm.what.c_str());
							string type_str(codegen_buf);
							// init high dimension array
							/* though using for-loop to init a high-dimension array is verbose comparing to using constructors, i use this form because it is more clear and it can remind users of the cost of using a high dimension array */
							vector<string> this_major; /* if you want to set value of a(i0)(i1)(i2) then this major is a(i0)(i1) */
							this_major.push_back(pn->child[i]->child[0]->fs.CurrentTerm.what /* array name */);
							for (int i = 1; i < slice->child.size(); i++)
							{
								sprintf(codegen_buf, "%s(i%d)", this_major.back().c_str(), i - 1);
								this_major.push_back(string(codegen_buf));
							}
							for (sliceid = slice->child.size() - 2; sliceid >= 0 ; sliceid--)
							{
								string prev_type_str = type_str;
								sprintf(codegen_buf, "forarray< %s >", type_str.c_str());
								type_str = string(codegen_buf);
								sprintf(codegen_buf, "for(int i%d = %s; i%d < %s; i%d++){\n\t%s(i%d) = %s(%s, %s + 1);\n%s\n}\n" /* NOTE fortran is [lower_bound, upper_bound] cpp is [lower_bound, upper_bound) */
									, sliceid, slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), sliceid, slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), sliceid
									, this_major[sliceid].c_str(), sliceid, prev_type_str.c_str(), slice->child[sliceid + 1]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[sliceid + 1]->child[1]->fs.CurrentTerm.what.c_str()
									, sliceid + 1 == slice->child.size() - 1 ? "" : tabber(slice->child[sliceid + 1]->fs.CurrentTerm.what).c_str());
								prev_type_str = type_str;
								slice->child[sliceid]->fs.CurrentTerm.what = string(codegen_buf);
							}
							// use it in fucntion_decl
							string var_pattern;
							if (vardescattr->desc.reference) {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s & %s";
								}
								else {
									var_pattern = "%s & %s";
								}
							}
							else {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s %s";
								}
								else {
									var_pattern = "%s %s";
								}
							}
							// no desc if var_def is not in paramtable
							sprintf(codegen_buf, "%s %s(%s, %s + 1);\n" , type_str.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* array name */
								, slice->child[0]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[0]->child[1]->fs.CurrentTerm.what.c_str() /* slice from to */);
							arr_decl += codegen_buf;
							/* set initial value */
							if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
							{
								for (int abid = 0; abid < pn->child[i]->child[1]->child.size(); abid++)
								{
									ParseNode * ab = pn->child[i]->child[1]->child[abid];
									if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
										std::string vec_size = "std::vector<int>{", vec_lb = "std::vector<int>{";
										for (int sliceid = 0; sliceid < slice->child.size(); sliceid++)
										{
											if (sliceid != 0) {
												vec_lb += ",";
												vec_size += ",";
											}
											vec_lb += slice->child[sliceid]->child[0]->fs.CurrentTerm.what;
											int lb, ub;
											sscanf(slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), "%d", &lb);
											sscanf(slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), "%d", &ub);
											sprintf(codegen_buf, "%d", ub - lb + 1);
											vec_size += codegen_buf;
										}
										vec_size += "}", vec_lb += "}";
										sprintf(codegen_buf, ab->fs.CurrentTerm.what.c_str() /* sth like "init_for1array(%%s, %%s, %%s, %s)\n" */
											, pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* variable name */
											, vec_lb.c_str()
											, vec_size.c_str());
									}
									else if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_EXP) {
										string formatter = (ab->fs.CurrentTerm.what + ";\n");
										sprintf(codegen_buf, formatter.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
									}
									else {
										sprintf(codegen_buf, "");
									}
								}
							}
							else {
								sprintf(codegen_buf, "");
							}
							arr_decl += codegen_buf;
						}
						if (pn->child.size() >= 2)
						{
							/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
							/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
							pn = pn->child[1];
						}
					} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
				}
				else {
					sprintf(codegen_buf, "%s ", ty->fs.CurrentTerm.what.c_str());
					var_decl += string(codegen_buf);
					/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
						for (int i = 0; i < pn->child.size(); i++)
						{
							if (i > 0) {
								var_decl += ", ";
							}
							ParseNode * this_variable = pn->child[i];
							// use it in fucntion_decl
							string var_pattern;
							if (vardescattr->desc.reference) {
								if (vardescattr->desc.constant) {
									var_pattern = "const & %s";
								}
								else {
									var_pattern = "& %s";
								}
							}
							else {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s";
								}
								else {
									var_pattern = "%s";
								}
							}
							// no desc if var_def is not in paramtable
							sprintf(codegen_buf, "%s" , this_variable->child[0]->fs.CurrentTerm.what.c_str());

							var_decl += codegen_buf;
							/* initial value */
							if (this_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
								/* if initial value is not dummy but `exp` */
								var_decl += " = ";
								var_decl += this_variable->child[1]->fs.CurrentTerm.what;
							}
							/* desc */
							this_variable->attr = vardescattr->clone();
						}
						if (pn->child.size() >= 2)
						{
							/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
							/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
							pn = pn->child[1];
						}
					} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					var_decl += ";";
#ifndef LAZY_GEN
					// sprintf(codegen_buf, "%s %s;", $1.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
#endif // !LAZY_GEN
				}

				$$ = *newnode;
				update_pos($$);
			}

    kwargtable : variable
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
				/* 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 */
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
	paramtable : kwargtable
			{
				$$ = $1;
				update_pos($$);
			}
		| kwargtable ',' paramtable
			{
				ParseNode * newnode = new ParseNode(); 
				newnode->addchild($1.child[0]); // kwargtable
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
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite YY_END YY_IF
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
				ParseNode * newnode = new ParseNode();
				ParseNode & suite = $3; suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "do{\n%s}", suite.fs.CurrentTerm.what.c_str());
#endif // !LAZY_GEN

				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode(suite)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & variable = $2;
				ParseNode & exp_from = $4;
				ParseNode & exp_to = $6;
				ParseNode & suite = $8; suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s++){\n%s}", variable.fs.CurrentTerm.what.c_str(), exp_from.fs.CurrentTerm.what.c_str(), variable.fs.CurrentTerm.what.c_str(), exp_to.fs.CurrentTerm.what.c_str(), variable.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode(variable)); // varname
				newnode->addchild(new ParseNode(exp_from)); // begin
				newnode->addchild(new ParseNode(exp_to)); // end
				newnode->addchild(new ParseNode(suite)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				$9.fs.CurrentTerm.what = tabber($9.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s+=%s){\n%s}", $2.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $8.fs.CurrentTerm.what.c_str(), $9.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($2)); // varname
				newnode->addchild(new ParseNode($4)); // begin
				newnode->addchild(new ParseNode($6)); // end
				newnode->addchild(new ParseNode($8)); // step
				newnode->addchild(new ParseNode($9)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DOWHILE exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $2;
				ParseNode & suite = $4; suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "while(%s){\n%s}", exp.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::While, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode($1)); // while
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite)); // suite
				$$ = *newnode;
				update_pos($$);
			}

	select_stmt : YY_SELECT YY_CASE _optional_lbrace exp _optional_rbrace crlf case_stmt YY_END YY_SELECT
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = $4;
				ParseNode & case_stmt = $7;
				string codegen = "";
				for (int i = 0; i < case_stmt.child.size(); i++)
				{
					ParseNode & case_stmt_elem = *case_stmt.child[i];
					ParseNode & dimen_slice = *case_stmt_elem.child[1];
					if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
						// NT_DIMENSLICE
						string dsstr;
						for (int sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
						{
							if (sliceid == 0) {
								sprintf(codegen_buf, "(%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
							}
							else {
								sprintf(codegen_buf, " || (%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
							}
							dsstr += string(codegen_buf);
						}
						if (i == 0) {
							sprintf(codegen_buf, "if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
						else {
							sprintf(codegen_buf, "else if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
					}
					else {
						// NT_ARGTABLE_PURE
						if (i == 0) {
							sprintf(codegen_buf, "if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[0]->fs.CurrentTerm.what.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
						else {
							sprintf(codegen_buf, "else if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[0]->fs.CurrentTerm.what.c_str(),  case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
					}
					codegen += codegen_buf;
				}
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SELECT, codegen };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode($1)); // select
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(case_stmt)); // suite
				$$ = *newnode;
				update_pos($$);
			}
	case_stmt_elem : YY_CASE _optional_lbrace dimen_slice _optional_rbrace crlf suite
			{
				ParseNode * newnode = new ParseNode();
				ParseNode & dimen_slice = $3;
				ParseNode & suite = $6; suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASE, "" };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode($1)); // case
				newnode->addchild(new ParseNode(dimen_slice)); // dimen_slice
				newnode->addchild(new ParseNode(suite)); // suite
				$$ = *newnode;
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
				newnode->addchild(new ParseNode(case_stmt_elem), false); // case_stmt_elem
				$$ = *newnode;
				update_pos($$);
			}


	function_decl : dummy_function_iden YY_FUNCTION variable '(' paramtable ')' YY_RESULT '(' variable ')' crlf suite YY_END YY_FUNCTION
			{
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode * newnode = new ParseNode();
				vector<tuple<string, string, ParseNode *>> param_name_typename; // all params in paramtable of function declare (var_name, var_type)
				ParseNode & variable_function = $3;
				/* enumerate paramtable */
				ParseNode & paramtable = $5;
				ParseNode * prmtbl = &paramtable;
				vector<ParseNode *> param_definition;
				ParseNode & variable_result = $9;
				ParseNode & suite = $12;
				do {
					// for all non-flatterned paramtable
					for (int i = 0; i < prmtbl->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						param_name_typename.push_back(make_tuple(prmtbl->child[i]->fs.CurrentTerm.what, "void", nullptr)); // refer to function suite and determine type of params
					}
					if (prmtbl->child.size() >= 2)
					{
						/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
						/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
						prmtbl = prmtbl->child[1];
					}
				} while (prmtbl->child.size() == 2 && prmtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
				/* result variable */
				param_name_typename.push_back(make_tuple(variable_result.fs.CurrentTerm.what, "void", nullptr));
				/* find out all var_def nodes */
				for (int i = 0; i < suite.child.size(); i++)
				{
					ParseNode * stmti = suite.child[i];
					/* suite.child[i] => stmt */ 
					/*  REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
					if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						/* stmti->child[0] => var_def */
						/* from pn=stmti->child[0].child[0] is typename */
						/* from pn=stmti->child[0].child[1] is dimen_slice */
						/* from pn=stmti->child[0].child[2] is all variables of this type */
						ParseNode * pn = stmti->child[0]->child[2];
						do {
							// for all non-flatterned paramtable
							for (int i = 0; i < pn->child.size(); i++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname_i with initial value */
								/* pn->child[i]->child[0] is varname string */
								param_definition.push_back(pn->child[i]->child[0]);
							}
							if (pn->child.size() >= 2)
							{
								/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
								/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
								pn = pn->child[1];
							}
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
				}

				/* set type to all param_name_typename */
				for (int i = 0; i < param_name_typename.size(); i++)
				{
					string varname = get<0>(param_name_typename[i]);
					for (int j = 0; j < param_definition.size(); j++)
					{
						ParseNode * varname_node = param_definition[j];
						if (varname_node->fs.CurrentTerm.what == varname) {
							//	father		NT_VARIABLEINITIAL (variable_name, variable_initial_value)
							//	father * 2	NT_PARAMTABLE
							//	father * 3	NT_VARIABLEDEFINE var_def
							//  param_name_typename[i] = tuple<name, type, ParseNode *>
							get<1>(param_name_typename[i]) = varname_node->father->father->father->child[0]->fs.CurrentTerm.what;
							get<2>(param_name_typename[i]) = varname_node->father;
							/* `delete` ParseNode except return value */
							if (i != param_name_typename.size() - 1) {
								varname_node->father->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
							}
						}
					}
				}

				/* generate new paramtable with type */
				string argtblstr;
				for (int i = 0; i < param_name_typename.size() - 1 /* exclude YY_RESULT(return value) */; i++)
				{
					if(i != 0)
						argtblstr += ", ";
					VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>( get<2>(param_name_typename[i])->attr );
					if (vardescattr != nullptr)
					{
						if (vardescattr->desc.constant) {
							argtblstr += "const ";
						}
						else {
						}
					}
					argtblstr += get<1>(param_name_typename[i]);
					argtblstr += " ";
					if (vardescattr != nullptr)
					{
						if (vardescattr->desc.reference) {
							argtblstr += "& ";
						}
						else {
						}
					}
					argtblstr += get<0>(param_name_typename[i]);
				}

				/* add type infomation to paramtable ParseNodes  */
				ParseNode * newpt; // paramtable is raw for90 paramtable without type
				// TODO This is optional so i decide not to implement currently
				/* generate new return with type */
				ParseNode * newrt; // variable_result is raw for90 return without type
				// TODO This is optional so i decide not to implement currently
				
				/* re-generated codes of suite */
				string newsuitestr; // suite is raw for90 suite without type
				ParseNode * oldsuite = &suite;
				for (int i = 0; i < oldsuite->child.size(); i++)
				{
					if (oldsuite->child[i]->child.size() > 0 && oldsuite->child[i]->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
					{
						// this code is similar to `find out all var_def nodes` code
						//ParseNode * pn = oldsuite->child[0]->child[1];
						ParseNode * typeinfo = oldsuite->child[i]->child[0]->child[0];
						ParseNode * pn = oldsuite->child[i]->child[0]->child[2];
						do {
							// for all non-flatterned paramtable
							for (int j = 0; j < pn->child.size(); j++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname with initial value */
								/* pn->child[i]->child[0] is varname string */
								if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
									//newsuitestr += oldsuite->child[i]->child[0]->fs.CurrentTerm.what; // deprecated THIS IS NT_VARIABLEDEFINE, but different variables can be different
									newsuitestr += typeinfo->fs.CurrentTerm.what;
									newsuitestr += " ";
									newsuitestr += pn->child[j]->child[0]->fs.CurrentTerm.what;
									if (pn->child[j]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
										newsuitestr += " = ";
										newsuitestr += pn->child[j]->child[1]->fs.CurrentTerm.what;
									}
									newsuitestr += " ;\n";
								}
							}
							if (pn->child.size() >= 2)
							{
								/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
								/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
								pn = pn->child[1];
							}
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
					else {
						newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
					}
				}
				// update oldsuite->fs.CurrentTerm.what
				oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
				/* generate function ParseTree */
				newnode->addchild(new ParseNode($2)); // function
				newnode->addchild(new ParseNode(variable_function)); // function name
				// argtable
				// TODO 
				// return value
				newnode->addchild(new ParseNode(suite)); // trimed suite

				sprintf(codegen_buf, "%s %s(%s){\n%s\n}"
					, get<1>(param_name_typename[param_name_typename.size()-1]).c_str() // return value type
					, variable_function.fs.CurrentTerm.what.c_str() // function name
					, argtblstr.c_str() // argtable
					, oldsuite->fs.CurrentTerm.what.c_str() // code
				);
				/* generate function code */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
				$$ = *newnode;
				update_pos($$);
			}
	
	wrapper : suite
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				//$$.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPER, string(codegen_buf) };
				$$ = $1;
				update_pos($$);
			}
		| function_decl
			{
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				//$$.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPER, string(codegen_buf) };
				$$ = $1;
				update_pos($$);
			}

    program : YY_PROGRAM YY_WORD crlf wrapper YY_END YY_PROGRAM YY_WORD crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($4)); //wrapper
				sprintf(codegen_buf, "%s", $4.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				program_tree = *newnode;
			}
        | YY_PROGRAM crlf wrapper YY_END YY_PROGRAM crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($3)); //wrapper
				sprintf(codegen_buf, "%s", $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				program_tree = *newnode;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
	printf("line %d from %d len %d, current token %d : %s \n", get_flex_state().parse_line, get_flex_state().parse_pos, get_flex_state().parse_len, yylval.fs.CurrentTerm.token, yylval.fs.CurrentTerm.what.c_str());
	printf("context : %s\n", global_code.substr(get_flex_state().parse_pos - 5, 10).c_str());
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
