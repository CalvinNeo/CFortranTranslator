%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
// 前置声明, 不然编译不过
void yyerror(char* s); 
extern int yylex();
extern int yyparse();
#define YYSTYPE Term
%}

%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL

%left '+' '-'
%%
number : YY_FLOAT
	| YY_INTEGER

	exp : exp '+' exp
	| number

%%
//extern "C" int yylex();
void yyerror(char* s)
{
	fprintf(stderr, "%s", s);
}
int parse(std::string code) {
	return 0;
}
