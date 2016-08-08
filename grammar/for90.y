%{
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
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
char codegen_buf[65535];
using namespace std;
string tabber(string &);
ParseNode * flattern(ParseNode *); // eliminate right recursion
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
            {printf("complex " );}

		| error '\n'

	variable : YY_WORD
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, $1.fs.CurrentTerm.what }; // variant
				$$ = *newnode;
			}

	exp : '(' exp ')' crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "( %s )", $2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($2)); 
				$$ = *newnode;
			}
		| exp '+' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s + %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // +
				newnode->addchild(new ParseNode($3)); // tight operand exp
				$$ = *newnode;
			}
		| exp '-' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s - %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // -
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '*' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s * %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // *
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '/' exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s / %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // /
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_POWER exp crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ** %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // **
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
        | '-' exp %prec YY_NEG crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "(-%s)", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // (-)
				newnode->addchild(new ParseNode($2)); // only right operand exp
				$$ = *newnode;
			}
		| exp '=' exp
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // left operand exp
				newnode->addchild(new ParseNode($2)); // =
				newnode->addchild(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| literal crlf
            { 
				// 
				$$ = $1;
			}
		| variable crlf
			{
				// 
				$$ = $1;
			}

	stmt : exp
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ;\n", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // exp
				$$ = *newnode;
			}
		| var_def
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ;\n", $1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // var_def
				$$ = *newnode;
			}
        | compound_stmt
        | output_stmt

    output_stmt : write

	_optional_lbrace : 
		| '('
			{
				printf("abc\n");
			}
	_optional_rbrace : 
		| ')'

    write : YY_WRITE _optional_lbrace YY_INTEGER ',' YY_STRING _optional_rbrace argtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", $4.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($3)); // device id
				newnode->addchild(new ParseNode($5)); // formatter
				newnode->addchild(new ParseNode($7)); // paramtable
				$$ = *newnode;
			}
		| YY_WRITE _optional_lbrace '*' ',' '*' _optional_rbrace argtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "printf(\"%%g\", %s) ;\n", $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				ParseNode * deviceidnode = new ParseNode();
				deviceidnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(deviceidnode); // device id
				ParseNode * formatternode = new ParseNode();
				formatternode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "%g" };
				newnode->addchild(formatternode); // formatter

				newnode->addchild(new ParseNode($7)); // paramtable
				$$ = *newnode;
			}
        | YY_WRITE _optional_lbrace '*' ',' YY_STRING _optional_rbrace argtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					ParseNode * deviceidnode = new ParseNode();
					deviceidnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
					newnode->addchild(deviceidnode); // device id
				newnode->addchild(new ParseNode($5)); // formatter
				newnode->addchild(new ParseNode($7)); // paramtable
				$$ = *newnode;
			}
			
        | YY_WRITE '*' ',' argtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "printf(\"%g\", %s) ;\n", $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					ParseNode * deviceidnode = new ParseNode();
					deviceidnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
					newnode->addchild(deviceidnode); // device id
					ParseNode * formatternode = new ParseNode();
					formatternode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "%g" };
					newnode->addchild(formatternode); // formatter

				newnode->addchild(new ParseNode($4)); // paramtable
				$$ = *newnode;
			}
    type_spec : YY_INTEGER_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
			}
        | YY_FLOAT_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
			}
        | YY_STRING_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
			}
        | YY_COMPLEX_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
			}
        | YY_BOOL_T
			{
				$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				$$ = $1;
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
			}

    var_def : type_spec YY_DOUBLECOLON paramtable
			{
				/*  */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // type
				newnode->addchild(new ParseNode($3)); // paramtable
				$$ = *newnode;
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

				while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE) {
					// for all non-flatterned paramtable
					for (int i = 0; i < pn->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						sprintf(codegen_buf, "forarr<%s> %s(%s, %s);", $1.fs.CurrentTerm.what.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str(), $4.child[0]->fs.CurrentTerm.what.c_str(), $4.child[1]->fs.CurrentTerm.what.c_str());
						arr_decl += codegen_buf;
						arr_decl += '\n';
					}
					pn = pn->child[1];
				}
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, arr_decl };
				$$ = *newnode;
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
					variablenode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					variablenode->addchild( new ParseNode($1) ); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string("void") };
					variablenode->addchild( new ParseNode(fs, newnode) ); // dummy initial
					newnode->addchild(variablenode);
				$$ = *newnode;
			}
        | variable '=' exp
			{
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s = %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					variablenode->addchild(new ParseNode($3)); // initial
					newnode->addchild(variablenode);
				newnode = flattern(newnode);
				$$ = *newnode;
			}
        | variable ',' paramtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string("void") };
					variablenode->addchild(new ParseNode(fs, newnode)); // dummy initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode($3)); // paramtable
				newnode = flattern(newnode);
				$$ = *newnode;
			}
        | variable '=' exp ',' paramtable
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str(), $5.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", $1.fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode($1)); // type
					variablenode->addchild(new ParseNode($3)); // initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode($5)); // paramtable
				newnode = flattern(newnode);
				$$ = *newnode;
			}

    argtable : exp
			{
				/* argtable is used in function call */
			}
        | exp ',' argtable

    compound_stmt : if_stmt | do_stmt

	if_stmt : YY_IF exp YY_THEN crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "if (%s) {\n%s}", $2.fs.CurrentTerm.what.c_str(), tabber($5.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite YY_ELSE crlf suite YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", $2.fs.CurrentTerm.what.c_str(), tabber($5.fs.CurrentTerm.what).c_str(), tabber($8.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // else
				newnode->addchild(new ParseNode($8)); // else-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_END YY_IF crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "if (%s) {\n%s}\n%s", $2.fs.CurrentTerm.what.c_str(), tabber($5.fs.CurrentTerm.what).c_str(), $6.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN crlf suite elseif_stmt YY_ELSE crlf suite YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n%s}%s", $1.fs.CurrentTerm.what.c_str(), tabber($3.fs.CurrentTerm.what).c_str(), tabber($6.fs.CurrentTerm.what).c_str(), $9.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // if
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // recursive elseif-stmt
				newnode->addchild(new ParseNode($9)); // else-stmt
				$$ = *newnode;
			}
	elseif_stmt : YY_ELSEIF exp YY_THEN crlf suite
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "else if(%s) {\n%s}", $2.fs.CurrentTerm.what.c_str(), tabber($5.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				$$ = *newnode;
			}

		| YY_ELSEIF exp YY_THEN crlf suite elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "else if{\n%s}\n%s", $2.fs.CurrentTerm.what.c_str(), tabber($5.fs.CurrentTerm.what).c_str(), $6.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // elseif
				newnode->addchild(new ParseNode($2)); // exp
				newnode->addchild(new ParseNode($5)); // suite
				newnode->addchild(new ParseNode($6)); // another elseif-stmt
				$$ = *newnode;
			}
	do_stmt : YY_DO crlf suite YY_END YY_DO crlf
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "do{\n%s}", tabber($3.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($3)); // suite
				$$ = *newnode;
			}
		| YY_DO variable '=' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s++){\n%s}", $2.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), tabber($8.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($2)); // varname
				newnode->addchild(new ParseNode($4)); // begin
				newnode->addchild(new ParseNode($6)); // end
				newnode->addchild(new ParseNode($8)); // suite
				$$ = *newnode;
			}
		| YY_DO variable '=' exp ',' exp ',' exp crlf suite YY_END YY_DO
			{
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s+=%s){\n%s}", $2.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $6.fs.CurrentTerm.what.c_str(), $2.fs.CurrentTerm.what.c_str(), $8.fs.CurrentTerm.what.c_str(), tabber($9.fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode($1)); // do
				newnode->addchild(new ParseNode($2)); // varname
				newnode->addchild(new ParseNode($4)); // begin
				newnode->addchild(new ParseNode($6)); // end
				newnode->addchild(new ParseNode($8)); // step
				newnode->addchild(new ParseNode($9)); // suite
				$$ = *newnode;
			}

    suite : stmt
        | stmt suite

	function_decl : dummy_function_iden YY_FUNCTION YY_WORD '(' paramtable ')' YY_RESULT '(' YY_WORD '(' crlf suite YY_END YY_FUNCTION
			{
				
			}

    program : YY_PROGRAM YY_WORD suite YY_END YY_PROGRAM YY_WORD
			{ 
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($3));
				program_tree = *newnode;
			}
        | YY_PROGRAM suite YY_END YY_PROGRAM
			{
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode($2));
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
ParseNode * flattern(ParseNode * pn) {
	/* it cant work well because it create a whole noew tree copy too much */
	if (pn->child.size() == 2) {
		ParseNode * newp = new ParseNode();
		newp->addchild(new ParseNode(*pn->child[0]));
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
int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
