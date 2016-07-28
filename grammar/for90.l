%{
#include <stdio.h>
#include "../tokenizer.h"
int parse_line = 1;
%}
delim   [ \t]
ws      {delim}+
%%
{ws} {/* no action and no return */}
[\n] {parse_line++;}
[-+]?[0-9]+ { make_term(TokenMeta::Int, yytext); }
[-+]?[0-9\.]+([eE][0-9\.]+)? { make_term(TokenMeta::Double, yytext); }
[a-zA-Z_][a-zA-Z0-9]* { make_term(TokenMeta::Word, yytext); }
(".*"|'.*') { make_term(TokenMeta::Str, yytext); }
.true. { make_term(TokenMeta::True, yytext); }
.false. { make_term(TokenMeta::False, yytext); }
"(" { make_term(TokenMeta::LB, yytext); }
")" { make_term(TokenMeta::RB, yytext); }
"**" { make_term(TokenMeta::Power, yytext); }
"*" { make_term(TokenMeta::Multiply, yytext); }
"/" { make_term(TokenMeta::Divide, yytext); }
"+" { make_term(TokenMeta::Add, yytext); }
"-" { make_term(TokenMeta::Minus, yytext); }
(>|.gt.) { make_term(TokenMeta::GT, yytext); }
(>=|.ge.) { make_term(TokenMeta::GE, yytext); }
(<|.lt.) { make_term(TokenMeta::LT, yytext); }
(<=|.le.) { make_term(TokenMeta::LE, yytext); }
(==|.eq.) { make_term(TokenMeta::EQ, yytext); }
("/="|.ne.) { make_term(TokenMeta::NEQ, yytext); }
.and. { make_term(TokenMeta::AndAnd, yytext); }
.or. { make_term(TokenMeta::OrOr, yytext); }
.not. { make_term(TokenMeta::Not, yytext); }
.eqv. { make_term(TokenMeta::EQV, yytext); }
.neqv. { make_term(TokenMeta::NEQV, yytext); }
%%
