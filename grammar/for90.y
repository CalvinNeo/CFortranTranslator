%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE
%}

%debug

%token YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token YY_IF YY_THEN YY_ELSE YY_END YY_DO YY_CONTINUE YY_WHILE YY_WHERE YY_CASE
%token YY_PROGRAM YY_FUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_MODULE YY_BLOCK
%token YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY
%token YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T

%type <fs> YY_INTEGER
%type <fs> YY_FLOAT
%type <fs> YY_WORD
%type <fs> YY_OPERATOR
%type <fs> YY_STRING
%type <fs> YY_ILLEGAL
%type <fs> YY_COMPLEX


%left '='
%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%left '+' '-' 
%left '*' '/' 
%left YY_POWER
%right YY_NEG YY_NOT

%start stmt

%%	
	literal : YY_FLOAT
			{printf("float "); }
		| YY_INTEGER
			{printf("int "); }
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

	stmt : exp
        | compound_stmt

    type_spec : YY_INTEGER_T
        | YY_FLOAT_T
        | YY_STRING_T 
        | YY_COMPLEX_T
        | YY_BOOL_T

    var_def : type_spec YY_DOUBLECOLON argtable

    argtable : YY_WORD
        | YY_WORD '=' exp
        | YY_WORD ',' argtable        
        | YY_WORD '=' exp
        | YY_WORD '=' exp ',' argtable

    compound_stmt : if_stmt

	if_stmt : YY_IF exp YY_THEN stmt YY_END YY_IF
			{printf("if .. end if"); }
		| YY_IF exp YY_THEN stmt YY_ELSE stmt YY_END YY_IF
			{printf("if .. else .. end if"); }
		| YY_IF exp YY_THEN stmt elseif_stmt YY_END YY_IF
			{printf("if .. else if ... end if "); }
		| YY_IF exp YY_THEN stmt elseif_stmt YY_ELSE stmt YY_END YY_IF
			{printf("if .. else if .. else end if"); }
	elseif_stmt : YY_ELSE YY_IF exp YY_THEN stmt
		| YY_ELSE YY_IF exp YY_THEN stmt elseif_stmt

    stmts : stmt
        | stmt stmts

    program : YY_PROGRAM YY_WORD stmts YY_END YY_PROGRAM YY_WORD

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
