%{
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include "../tokenizer.h"
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

%token YY_REQ_MORE YY_CRLF
%token YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token YY_END YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_ENDDO YY_CONTINUE YY_BREAK YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE
%token YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK
%token YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY YY_DIMENSION
%token YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T
%token YY_WRITE YY_READ YY_PRINT YY_OPEN YY_CLOSE


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
		| 

	dummy_function_iden : YY_RECURSIVE
			{
				
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
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, $1.fs.CurrentTerm.what }; // string
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
	
	function_array : callable '(' argtable ')' crlf
			{
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
			sprintf(codegen_buf, "%s(%s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
			newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode($1)); // function/array name
				newnode->addchild(new ParseNode($3)); // argtable
				$$ = *newnode;
				update_pos($$);
			}

	exp : function_array
			{
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
			newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, $1.fs.CurrentTerm.what };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($1)); // function_array
				$$ = *newnode;
				update_pos($$);
			}
		| '(' exp ')' crlf
			{
				/* `callable '(' argtable ')'` rule has priority over this rule  */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
			sprintf(codegen_buf, "( %s )", $2.fs.CurrentTerm.what.c_str());
			newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode($2)); 
				$$ = *newnode;
				update_pos($$);
			}
		| exp '+' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s + %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // +
				newnode->addchild(new ParseNode($3)); // tight operand exp
				$$ = *newnode;
			}
		| exp '-' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s - %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // -
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '*' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s * %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // *
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '/' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s / %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // /
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_POWER exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "power(%s, %s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // **
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
        | '-' exp %prec YY_NEG crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "(-%s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // (-)
				newnode->addchild(new ParseNode($2)); // only right operand exp
				$$ = *newnode;
				update_pos($$);
			}
		| literal crlf
            { 
				// 
				$$ = $1;
			}
		| callable crlf
			{
				// may cause reduction-reduction conflict when use `variable` instead of `callable`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				string x = $1.fs.CurrentTerm.what;
				$$ = $1;
			}

    argtable : exp
			{
				/* argtable is used in function call */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // exp
				$$ = *newnode;
				update_pos($$);
			}
        | exp ',' argtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // exp
				newnode->addchild(new ParseNode($3)); // argtable
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				// TODO : argtable can also be empty
			}
	stmt : exp
			{
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ;\n", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // exp
				$$ = *newnode;
				update_pos($$);
			}
		| var_def
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ;\n", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // var_def
				$$ = *newnode;
				update_pos($$);
			}
        | compound_stmt
        | output_stmt
		| dummy_stmt
		| let_stmt

    output_stmt : write

	compound_stmt : if_stmt | do_stmt

	let_stmt : exp '=' exp
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // =
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
				update_pos($$);
			}

	dummy_stmt : YY_IMPLICIT YY_NONE
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
				sprintf(codegen_buf, "%s \n", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // stmt
				$$ = *newnode;
				update_pos($$);
			}
		| stmt suite
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s \n %s \n", $1.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // stmt
				newnode->addchild(new ParseNode($2)); // suite
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
		|
			{
				/* suite can be empty but stmt can not */
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
				$$.fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, $1.fs.CurrentTerm.what };
				update_pos($$);
			}

	io_info : _optional_device ',' _optional_formatter
			{
				ParseNode * newnode = new ParseNode();
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode($1)); // formatter
				newnode->addchild(new ParseNode($3)); // argtable
				$$ = *newnode;
				update_pos($$);
			}

    write : YY_WRITE _optional_lbrace io_info _optional_rbrace argtable
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($3)); // ioinfo
				newnode->addchild(new ParseNode($5)); // argtable
				ParseNode * argtbl = &$5;
				ParseNode * formatter = $3.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", $3.child[1]->fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str());
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
				$$ = *newnode;
				update_pos($$);
			}

	read: YY_READ _optional_lbrace io_info _optional_rbrace argtable
			{
			}

    type_spec : YY_INTEGER_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				update_pos($$);
			}
        | YY_FLOAT_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				update_pos($$);
			}
        | YY_STRING_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				update_pos($$);
			}
        | YY_COMPLEX_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				update_pos($$);
			}
        | YY_BOOL_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
				update_pos($$);
			}

	slice : exp ':' exp
			{
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode($1)); // lower bound
				newnode->addchild(new ParseNode($3)); // upper bound
				$$ = *newnode;
				update_pos($$);
			}
		| exp ':' exp ':' exp
			{
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode($1)); // lower bound
				newnode->addchild(new ParseNode($3)); // upper bound
				newnode->addchild(new ParseNode($5)); // step
				$$ = *newnode;
				update_pos($$);
			}
	def_slice : '(' exp ',' exp ')'
			{
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode($2)); // lower bound
				newnode->addchild(new ParseNode($4)); // upper bound
				$$ = *newnode;
				update_pos($$);
			}

    var_def : type_spec YY_DOUBLECOLON paramtable
			{
				/*  */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // type
				newnode->addchild(new ParseNode($3)); // paramtable
				$$ = *newnode;
				update_pos($$);
			}
		| type_spec ',' YY_DIMENSION  def_slice  YY_DOUBLECOLON paramtable
			{
				/* array decl */
				ParseNode * newnode = new ParseNode();
				string arr_decl = "";
				newnode->addchild(new ParseNode($1)); // type
				newnode->addchild(new ParseNode($4)); // slice
				ParseNode * pn = new ParseNode($6); //paramtable
				newnode->addchild(pn); // paramtable

				/* in cpp code, definition of an array is inherit attribute grammar */
				/* enumerate paramtable */
				do {
					// for all non-flatterned paramtable
					for (int i = 0; i < pn->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						sprintf(codegen_buf, "forarr<%s> %s(%s, %s);", $1.fs.CurrentTerm.what.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str(), $4.child[0]->fs.CurrentTerm.what.c_str(), $4.child[1]->fs.CurrentTerm.what.c_str());
						arr_decl += codegen_buf;
						arr_decl += '\n';
					}
					pn = pn->child[1];
				} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
				$$ = *newnode;
				update_pos($$);
			}

    paramtable : variable
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
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string("void") };
					variablenode->addchild( new ParseNode(fs, newnode) ); // void is dummy initial
					newnode->addchild(variablenode);
				$$ = *newnode;
				update_pos($$);
			}
        | variable '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					variablenode->addchild(new ParseNode($3)); // initial
					newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
        | variable ',' paramtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string("void") };
					variablenode->addchild(new ParseNode(fs, newnode)); // void is dummy initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode($3)); // paramtable
				newnode = flattern_bin(newnode);
				$$ = *newnode;
				update_pos($$);
			}
        | variable '=' exp ',' paramtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					variablenode->addchild(new ParseNode($3)); // initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode($5)); // paramtable
				newnode = flattern_bin(newnode);
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
	array_builder : '(' '/' argtable '/' ')'
			{
			}
		| '(' '/' '(' exp ')' ',' variable '=' exp ',' exp '/' ')'
			{
			}
		| '(' '/' variable '(' slice ')' '/' ')'

	if_stmt : YY_IF exp YY_THEN crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				$5.fs.CurrentTerm.what = tabber($5.fs.CurrentTerm.what);
				sprintf(codegen_buf, "if (%s) {\n%s}", $2.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite YY_ELSE crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				$5.fs.CurrentTerm.what = tabber($5.fs.CurrentTerm.what); $8.fs.CurrentTerm.what = tabber($8.fs.CurrentTerm.what);
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", $2.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str(), $8.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // else
				newnode->addchild(new ParseNode($8)); // else-stmt
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				$5.fs.CurrentTerm.what = tabber($5.fs.CurrentTerm.what); $6.fs.CurrentTerm.what = tabber($6.fs.CurrentTerm.what);
				sprintf(codegen_buf, "if (%s) {\n%s}\n%s", $2.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				$$ = *newnode;
				update_pos($$);
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				$3.fs.CurrentTerm.what = tabber($3.fs.CurrentTerm.what); $6.fs.CurrentTerm.what = tabber($6.fs.CurrentTerm.what);
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n%s}%s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $9.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				newnode->addchild(new ParseNode($9)); // else-stmt
				$$ = *newnode;
				update_pos($$);
			}
	elseif_stmt : YY_ELSEIF exp YY_THEN crlf suite
			{
				ParseNode * newnode = new ParseNode();
				$5.fs.CurrentTerm.what = tabber($5.fs.CurrentTerm.what);
				sprintf(codegen_buf, "else if(%s) {\n%s}", $2.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
				update_pos($$);
			}

		| YY_ELSEIF exp YY_THEN crlf suite elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				$5.fs.CurrentTerm.what = tabber($5.fs.CurrentTerm.what);
				sprintf(codegen_buf, "else if{\n%s}\n%s", $2.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // another elseif-stmt
				$$ = *newnode;
				update_pos($$);
			}
	do_stmt : YY_DO crlf suite YY_END YY_DO crlf
			{
				ParseNode * newnode = new ParseNode(); 
				$3.fs.CurrentTerm.what = tabber($3.fs.CurrentTerm.what);
				sprintf(codegen_buf, "do{\n%s}", $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($3)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				$8.fs.CurrentTerm.what = tabber($8.fs.CurrentTerm.what); 
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s++){\n%s}", $2.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $8.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($2)); // varname
				newnode->addchild(new ParseNode($4)); // begin
				newnode->addchild(new ParseNode($6)); // end
				newnode->addchild(new ParseNode($8)); // suite
				$$ = *newnode;
				update_pos($$);
			}
		| YY_DO variable '=' exp ',' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				$9.fs.CurrentTerm.what = tabber($9.fs.CurrentTerm.what);
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s+=%s){\n%s}", $2.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $8.fs.CurrentTerm.what.c_str(), $9.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($2)); // varname
				newnode->addchild(new ParseNode($4)); // begin
				newnode->addchild(new ParseNode($6)); // end
				newnode->addchild(new ParseNode($8)); // step
				newnode->addchild(new ParseNode($9)); // suite
				$$ = *newnode;
				update_pos($$);
			}

	function_decl : dummy_function_iden YY_FUNCTION variable '(' paramtable ')' YY_RESULT '(' variable ')' crlf suite YY_END YY_FUNCTION
			{
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode * newnode = new ParseNode();
				vector<pair<string, string>> param_name_typename; // all params in paramtable of function declare
				vector<ParseNode *> param_definition;
				/* enumerate paramtable */
				ParseNode * prmtbl = &$5;
				do {
					// for all non-flatterned paramtable
					for (int i = 0; i < prmtbl->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						param_name_typename.push_back(make_pair(prmtbl->child[i]->fs.CurrentTerm.what, "void")); // refer to function suite and determine type of params
					}
					if (prmtbl->child.size() >= 2)
					{
						/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
						/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
						prmtbl = prmtbl->child[1];
					}
				} while (prmtbl->child.size() == 2 && prmtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
				/* result variable */
				param_name_typename.push_back(make_pair($9.fs.CurrentTerm.what, "void"));
				/* find out all var_def nodes */
				for (int i = 0; i < $12.child.size(); i++)
				{
					ParseNode * stmti = $12.child[i];
					/* $12 => suite */
					/* $12.child[i] => stmt */ /*  REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
					if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						/* stmti->child[0] => var_def */
						/* from pn=stmti->child[0].child[0] is typename */
						/* from pn=stmti->child[0].child[1] is all variables of this type */
						ParseNode * pn = stmti->child[0]->child[1];
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
					string varname = param_name_typename[i].first;
					for (int j = 0; j < param_definition.size(); j++)
					{
						ParseNode * varname_node = param_definition[j];
						if (varname_node->fs.CurrentTerm.what == varname) {
							//	father		NT_VARIABLEINITIAL (variable_name, variable_initial_value)
							//	father * 2	NT_PARAMTABLE
							//	father * 3	NT_VARIABLEDEFINE
							param_name_typename[i].second = varname_node->father->father->father->child[0]->fs.CurrentTerm.what;
							/* `delete` ParseNode except return value */
							if (i != param_name_typename.size() - 1) {
								varname_node->father->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
							}
						}
					}
				}

				string argtblstr;
				for (int i = 0; i < param_name_typename.size() - 1 /* exclude YY_RESULT(return value) */; i++)
				{
					if(i != 0)
						argtblstr += ", ";
					argtblstr += param_name_typename[i].second;
					argtblstr += " ";
					argtblstr += param_name_typename[i].first;
				}

				/* generate new paramtable with type */
				ParseNode * newpt; // $5 is raw for90 paramtable without type
				// TODO This is optional so i decide not to implement currently
				/* generate new return with type */
				ParseNode * newrt; // $9 is raw for90 return without type
				// TODO This is optional so i decide not to implement currently
				
				/* re-generated codes of suite */
				string newsuitestr; // $12 is raw for90 suite without type
				ParseNode * oldsuite = & $12;
				for (int i = 0; i < oldsuite->child.size(); i++)
				{
					if (oldsuite->child[i]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
					{
						// this code is similar to `find out all var_def nodes` code
						ParseNode * pn = $12.child[0]->child[1];
						do {
							// for all non-flatterned paramtable
							for (int j = 0; j < pn->child.size(); j++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname with initial value */
								/* pn->child[i]->child[0] is varname string */
								if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
									newsuitestr += oldsuite->child[i]->child[0]->fs.CurrentTerm.what;
									newsuitestr += " ";
									newsuitestr += pn->child[j]->fs.CurrentTerm.what;
									newsuitestr += " ;\n";
								}
							}
							pn = pn->child[1];
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
					else {
						newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
					}
				}
				oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
				/* generate function ParseTree */
				newnode->addchild(new ParseNode($2)); // function
				newnode->addchild(new ParseNode($3)); // function name
				// argtable
				// return value
				newnode->addchild(new ParseNode($12)); // trimed suite

				sprintf(codegen_buf, "%s %s(%s){\n%s\n}"
					, param_name_typename[param_name_typename.size()-1].second.c_str() // return value type
					, $3.fs.CurrentTerm.what.c_str() // function name
					, argtblstr.c_str()
					, $12.fs.CurrentTerm.what.c_str()
				);
				/* generate function code */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
				$$ = *newnode;
				update_pos($$);
			}
	
	wrapper : suite
			{
				$$ = $1;
				update_pos($$);
			}
		| function_decl
			{
				$$ = $1;
				update_pos($$);
			}

    program : YY_PROGRAM YY_WORD crlf wrapper YY_END YY_PROGRAM YY_WORD crlf
			{ 
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($4)); //wrapper
				program_tree = *newnode;
			}
        | YY_PROGRAM crlf wrapper YY_END YY_PROGRAM crlf
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($3)); //wrapper
				program_tree = *newnode;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
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
		/* pn->child[1] is a list of ALREADY flatterned elements */
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
		current_node.fs.parse_len = current_node.child[0]->fs.line_pos;
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
