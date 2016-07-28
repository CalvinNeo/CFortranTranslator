#include <stdio.h>

%token BOOL, ELSE, IF, TRUE, WHILE, DO, FALSE, INT, VOID
%token LPAREN, RPAREN, LBRACK, RBRACK, LBRACE, RBRACE, SEMI, COMMA, PLUS, MINUS, TIMES
%token DIV, MOD, AND, OR, NOT, IS, ADDR, EQ, NE, LT, GT, LE, GE
%token NUM, ID, PUNCT, OP

int line = 1, numAttr;
char *strAttr;
%}

/* regular definitions */

delim   [ \t]
ws      {delim}+
letter  [A-Za-z]
digit   [0-9]
id      ({letter}|_)({letter}|{digit}|_)*
number  {digit}+

%%

{ws}        {/* no action and no return */}
[\n]        {line++;}
bool        {return(BOOL);}
else        {return(ELSE);}
if          {return(IF);}
true        {return(TRUE);}
while       {return(WHILE);}
do          {return(DO);}
false       {return(FALSE);}
int         {return(INT);}
void        {return(VOID);}

{id}        {return(ID);}  // error is on these two lines
{number}    {return(NUM);} //

"("         {yylval = LPAREN; return(PUNCT);}
")"         {yylval = RPAREN; return(PUNCT);}
"["         {yylval = LBRACK; return(PUNCT);}
"]"         {yylval = RBRACK; return(PUNCT);}
"{"         {yylval = LBRACE; return(PUNCT);}
"}"         {yylval = RBRACE; return(PUNCT);}
";"         {yylval = SEMI;   return(PUNCT);}
","         {yylval = COMMA;  return(PUNCT);}

"+"         {yylval = PLUS;   return(OP);}
"-"         {yylval = MINUS;  return(OP);}
"*"         {yylval = TIMES;  return(OP);}
"/"         {yylval = DIV;    return(OP);}
"%"         {yylval = MOD;    return(OP);}
"&"         {yylval = ADDR;   return(OP);}
"&&"        {yylval = AND;    return(OP);}
"||"        {yylval = OR;     return(OP);}
"!"         {yylval = NOT;    return(OP);}
"!="        {yylval = NE;     return(OP);}
"="         {yylval = IS;     return(OP);}
"=="        {yylval = EQ;     return(OP);}
"<"         {yylval = LT;     return(OP);}
"<="        {yylval = LE;     return(OP);}
">"         {yylval = GT;     return(OP);}
">="        {yylval = GE;     return(OP);}

%%