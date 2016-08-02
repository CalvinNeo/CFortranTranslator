%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
#include "../parser.h"
// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE

#define ADDNODE(ND) curnode->child.push_back(new ParseNode(ND))
%}

%debug

%token YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token YY_IF YY_THEN YY_ELSE YY_END YY_DO YY_CONTINUE YY_WHILE YY_WHERE YY_CASE
%token YY_PROGRAM YY_FUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_MODULE YY_BLOCK
%token YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY
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
    dummy_function : YY_RECURSIVE
	
	literal : YY_FLOAT
			{printf("float "); }
		| YY_INTEGER
			{  }
		| YY_STRING
			{printf("string "); }
		| YY_WORD
			{printf("word "); }
        | YY_COMPLEX
            {printf("complex " );}

	exp : '(' exp ')'
			{ printf("bracket "); }
		| exp '+' exp
			{ printf("+ "); }
		| exp '-' exp
			{ printf("- "); }
		| exp '*' exp
			{ printf("* "); }
		| exp '/' exp
			{ printf("/ "); }
		| exp YY_POWER exp
			{ printf("** "); }
        | '-' exp %prec YY_NEG
            { printf("neg "); }
		| literal
            { printf("literal ");}
        | YY_WORD
            { printf("word ");}

	stmt : exp
        | compound_stmt
        | output_stmt

    output_stmt : write

    write : '(' YY_INTEGER ',' YY_STRING ')' argtable
        | '(' '*' ',' YY_STRING ')' argtable
        | '(' '*' ',' '*' ')' argtable
        | '*' ',' argtable

    type_spec : YY_INTEGER_T
        | YY_FLOAT_T
        | YY_STRING_T 
        | YY_COMPLEX_T
        | YY_BOOL_T

    var_def : type_spec YY_DOUBLECOLON paramtable

    paramtable : YY_WORD
        | YY_WORD '=' exp
        | YY_WORD ',' argtable        
        | YY_WORD '=' exp
        | YY_WORD '=' exp ',' argtable

    argtable : exp
        | exp , argtable

    compound_stmt : if_stmt

	if_stmt : YY_IF exp YY_THEN stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt YY_ELSE stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($6)); // else-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt elseif_stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($5)); // elseif-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt elseif_stmt YY_ELSE stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($5)); // elseif-stmt
				newnode->child.push_back(new ParseNode($7)); // else-stmt
				$$ = *newnode;
			}
	elseif_stmt : YY_ELSE YY_IF exp YY_THEN stmt
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::ElseIf, "" };
				newnode->child.push_back(new ParseNode($3)); // exp
				newnode->child.push_back(new ParseNode($5)); // stmt
				$$ = *newnode;
			}

		| YY_ELSE YY_IF exp YY_THEN stmt elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::ElseIf, "" };
				newnode->child.push_back(new ParseNode($3)); // exp
				newnode->child.push_back(new ParseNode($5)); // stmt
				newnode->child.push_back(new ParseNode($6)); // another elseif-stmt
				$$ = *newnode;
			}

    stmts : stmt
        | stmt stmts

    program : YY_PROGRAM YY_WORD stmts YY_END YY_PROGRAM YY_WORD
			{ 
				ParseNode * newnode = new ParseNode();
				newnode->child.push_back(new ParseNode($3));
				program_tree = *newnode;
			}
        | YY_PROGRAM stmts YY_END YY_PROGRAM 
			{
				ParseNode * newnode = new ParseNode();
				newnode->child.push_back(new ParseNode($2));
				program_tree = *newnode;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
}
int parse(std::string code) {
	//YYSTYPE aa;
	//aa.isnull = true;
	set_buff(code);
	yyparse();
	release_buff();
	return 0;
}
