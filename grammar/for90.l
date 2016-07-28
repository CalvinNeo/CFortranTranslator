%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"

static FlexState flex_state;
%}
delim   [ \t]
ws      {delim}+
newline [\r\n]
%%
{newline} {flex_state.parse_line++; flex_state.parse_pos += yyleng; }
{ws} {/* no action and no return */flex_state.parse_pos += yyleng; }
[-+]?[0-9]+ {return make_term_flex(TokenMeta::Int, yytext); flex_state.parse_pos += yyleng; }
[-+]?[0-9\.]+([eE][0-9\.]+)? {return make_term_flex(TokenMeta::Double, yytext); flex_state.parse_pos += yyleng; }
[a-zA-Z_][a-zA-Z0-9]* {return make_term_flex(TokenMeta::Word, yytext); flex_state.parse_pos += yyleng; }
(".*"|'.*') {return make_term_flex(TokenMeta::Str, yytext); flex_state.parse_pos += yyleng;}
.true. {return make_term_flex(TokenMeta::True, yytext); flex_state.parse_pos += yyleng; }
.false. {return make_term_flex(TokenMeta::False, yytext); flex_state.parse_pos += yyleng; }
"(" {return make_term_flex(TokenMeta::LB, yytext); flex_state.parse_pos += yyleng; }
")" {return make_term_flex(TokenMeta::RB, yytext); flex_state.parse_pos += yyleng; }
"**" {return make_term_flex(TokenMeta::Power, yytext); flex_state.parse_pos += yyleng; }
"*" {return make_term_flex(TokenMeta::Multiply, yytext); flex_state.parse_pos += yyleng; }
"/" {return make_term_flex(TokenMeta::Divide, yytext); flex_state.parse_pos += yyleng; }
"+" {return make_term_flex(TokenMeta::Add, yytext); flex_state.parse_pos += yyleng; }
"-" {return make_term_flex(TokenMeta::Minus, yytext); flex_state.parse_pos += yyleng; }
(>|.gt.) {return make_term_flex(TokenMeta::GT, yytext); flex_state.parse_pos += yyleng;}
(>=|.ge.) {return make_term_flex(TokenMeta::GE, yytext); flex_state.parse_pos += yyleng; }
(<|.lt.) {return make_term_flex(TokenMeta::LT, yytext); flex_state.parse_pos += yyleng;}
(<=|.le.) {return make_term_flex(TokenMeta::LE, yytext); flex_state.parse_pos += yyleng;}
(==|.eq.) {return make_term_flex(TokenMeta::EQ, yytext); flex_state.parse_pos += yyleng; }
("/="|.ne.) {return make_term_flex(TokenMeta::NEQ, yytext); flex_state.parse_pos += yyleng;}
.and. {return make_term_flex(TokenMeta::AndAnd, yytext); flex_state.parse_pos += yyleng; }
.or. {return make_term_flex(TokenMeta::OrOr, yytext); flex_state.parse_pos += yyleng; }
.not. {return make_term_flex(TokenMeta::Not, yytext); flex_state.parse_pos += yyleng; }
.eqv. {return make_term_flex(TokenMeta::EQV, yytext); flex_state.parse_pos += yyleng; }
.neqv. {return make_term_flex(TokenMeta::NEQV, yytext); flex_state.parse_pos += yyleng; }
%%

//#undef YY_INPUT
//#define YY_INPUT(buf) (input_flex(buf))
//char * my_buf;
//void input_flex(char *buf)
//{
//	strcpy(buf, my_buf);
//} 
int yylex(void);
int yywrap() 
{ 
   return(1); 
}
int make_term_flex(const TokenMeta & token, const char * w) {
	flex_state.CurrentTerm = Term{ token, std::string(w) };
	return token;
}
FlexState next_token(std::string in_str, int start){
	using namespace std;
	int slen = in_str.size() - start;
	if (slen <= 0) {
		flex_state.parse_line = 0;
		flex_state.parse_pos = start;
		flex_state.parse_len = 0;
		flex_state.isnull = true;
		return flex_state;
	}
	flex_state.parse_line = 0;
	flex_state.parse_pos = start;
	flex_state.parse_len = 0;
	char * buff = (char *)malloc(slen + 2);
	// 要以两个'\0'结束
	memset(buff, 0, slen + 2);
	strcpy(buff, in_str.c_str() + start);
	YY_BUFFER_STATE buffer = yy_scan_buffer(buff, slen + 2);
    int token = yylex();
	if (token == 0) {
		flex_state.isnull = true;
	}
	else {
		flex_state.isnull = false;
	}
	flex_state.parse_len = yyleng;
    yy_delete_buffer(buffer);
	free(buff);
	return flex_state;
}

