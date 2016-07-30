%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
// 前置声明, 不然编译不过
void yyerror(char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
%}

%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL
%type <fs> YY_INTEGER
%type <fs> YY_FLOAT
%type <fs> YY_WORD
%type <fs> YY_OPERATOR
%type <fs> YY_STRING
%type <fs> YY_ILLEGAL
%left '+' '-'
%%
	exp : '(' exp ')'
			{ printf("bracket"); }
		| exp '+' exp
			{ printf("+"); }
		| exp '-' exp
			{ printf("-"); }
		| exp '*' exp
			{ printf("*"); }
		| exp '/' exp
			{ printf("/"); }
		| exp '**' exp
			{ printf("**"); }
		| YY_FLOAT
			{printf("float"); }
		| YY_INTEGER
			{printf("int"); }
		| YY_STRING
			{printf("string"); }
		| YY_WORD
			{printf("word"); }

	stmt : exp

	logical_stmt : exp

	if_stmt : "if" logical_stmt 'then' stmt "end" "if" 
			{printf("if .. end if"); }
		| "if" logical_stmt "then" stmt "else" stmt "end" "if" 
			{printf("if .. else .. end if"); }
		| "if" logical_stmt "then" stmt elseif_stmt "end" "if" 
			{printf("if .. else if ... end if"); }
		| "if" logical_stmt "then" stmt elseif_stmt "else" stmt "end" "if" 
			{printf("if .. else if .. else end if"); }
	elseif_stmt : "else" "if" logical_stmt "then" stmt
		| "else" "if" logical_stmt "then" stmt elseif_stmt
%%
//extern "C" int yylex();

void yyerror(char* s)
{
	fprintf(stderr, "%s", s);
}
int parse(std::string code) {
	//YYSTYPE aa;
	//aa.isnull = true;
	set_buff(code);
	yyparse();
	release_buff();
	return 0;
}
