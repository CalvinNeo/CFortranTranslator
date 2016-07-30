%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
#include "for90.flex.h"
#ifdef USE_YACC
#include "for90.tab.h"
//#define YY_DECL extern "C" int yylex()
//#define YYSTYPE FlexState
#else
int make_term_flex(const TokenMeta & token, const char * w);
#endif
// more spectific
// DO **NOT** USE WHEN USE YACC EITHER
#define NYRTN(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TOK, yytext);  
#define NYRTOP(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TokenMeta::META_OPERATOR, yytext); 
// include literal const such as pi, true, false, etc.
#define NYRTWORD(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TokenMeta::META_WORD, yytext);  
#define NYRTINT(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TokenMeta::META_INTEGER, yytext); 
#define NYRTFLOAT(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TokenMeta::META_FLOAT, yytext); 
#define NYRTSTRING(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng; return make_term_flex(TokenMeta::META_STRING, yytext); 
#define NYRTILLEGAL(TOK) flex_state.parse_pos += 1; flex_state.line_pos += 1; return make_term_flex(TokenMeta::META_ILLEGAL, yytext); 
#define NYRTCRLF(TOK) flex_state.parse_line++; flex_state.line_pos = 0; flex_state.parse_pos = 0; 
#define NYRTNOP(TOK) flex_state.parse_pos += yyleng; flex_state.line_pos += yyleng;

// yacc
// USE WHTN USE YACC EITHER
#define YYRTN(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_ILLEGAL; 
#define YYRTOP(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_OPERATOR; 
// include literal const such as pi, true, false, etc.
#define YYRTWORD(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_WORD; 
#define YYRTINT(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_INTEGER; 
#define YYRTFLOAT(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_FLOAT; 
#define YYRTSTRING(TOK) yylval.parse_pos+=yyleng; yylval.line_pos+=yyleng; return YY_STRING; 
#define YYRTILLEGAL(TOK) yylval.parse_pos+=1; yylval.line_pos+=1; return yytext[0]; 
#define YYRTCRLF(TOK) yylval.parse_line++; yylval.parse_pos = 0; yylval.line_pos = 0;
#define YYRTNOP(TOK) yylval.parse_pos += yyleng; yylval.line_pos += yyleng;

#ifdef USE_YACC
#define RTN(TOK) YYRTN(TOK)
#define RTOP(TOK) YYRTOP(TOK)
#define RTWORD(TOK) YYRTWORD(TOK)
#define RTINT(TOK) YYRTINT(TOK)
#define RTFLOAT(TOK) YYRTFLOAT(TOK)
#define RTSTRING(TOK) YYRTSTRING(TOK)
#define RTILLEGAL(TOK) YYRTILLEGAL(TOK)
#define RTCRLF(TOK) YYRTCRLF(TOK)
#define RTNOP(TOK) YYRTNOP(TOK)
#else
#define RTN(TOK) NYRTN(TOK)
#define RTOP(TOK) NYRTOP(TOK)
#define RTWORD(TOK) NYRTWORD(TOK)
#define RTINT(TOK) NYRTINT(TOK)
#define RTFLOAT(TOK) NYRTFLOAT(TOK)
#define RTSTRING(TOK) NYRTSTRING(TOK)
#define RTILLEGAL(TOK) NYRTILLEGAL(TOK)
#define RTCRLF(TOK) NYRTCRLF(TOK)
#define RTNOP(TOK) NYRTNOP(TOK)
#endif // USE_YACC


FlexState flex_state;
#ifdef USE_YACC
int parse_pos;
int parse_line;
int parse_len;
int line_pos;
#else

#endif
%}
delim   [ \t]
ws      {delim}+
newline [\r\n]

%%
{newline} {RTCRLF(void) }
{ws} {RTNOP(void) }
[-+]?[0-9]+ {RTINT(TokenMeta::Int) }
[-+]?[0-9\.]+([eE][0-9\.]+)? {RTFLOAT(TokenMeta::META_FLOAT) }
[a-zA-Z_][a-zA-Z0-9]* { RTWORD(TokenMeta::META_WORD) }
.true. {RTN(TokenMeta::True) }
.false. {RTN(TokenMeta::False) }
"**" {RTOP(TokenMeta::Power) }
"*" {RTOP(TokenMeta::Multiply) }
"/" {RTOP(TokenMeta::Divide) }
"+" {RTOP(TokenMeta::Add) }
"-" {RTOP(TokenMeta::Minus) }
(>|.gt.) {RTOP(TokenMeta::GT)}
(>=|.ge.) {RTOP(TokenMeta::GE) }
(<|.lt.) {RTOP(TokenMeta::LT)}
(<=|.le.) {RTOP(TokenMeta::LE)}
(==|.eq.) {RTOP(TokenMeta::EQ) }
("/="|.ne.) {RTOP(TokenMeta::NEQ)}
.and. {RTOP(TokenMeta::AndAnd) }
.or. {RTOP(TokenMeta::OrOr) }
.not. {RTOP(TokenMeta::Not) }
.eqv. {RTOP(TokenMeta::EQV) }
.neqv. {RTOP(TokenMeta::NEQV) }
:: {RTOP(TokenMeta::DoubleColon)}
\"(\\.|[^"])*\" {RTSTRING(TokenMeta::META_STRING) 
/* The delimiting quotes are escaped because they are Flex meta-characters. */}
. {/* can be parsed, including some operators not listed */ RTILLEGAL(TokenMeta::META_ILLEGAL) }
%%

int yywrap() 
{ 
   return(1); 
}
#ifdef USE_YACC
char * iter_buff = nullptr;
YY_BUFFER_STATE yy_buffer = nullptr;
void set_buff(const std::string & code) {
	using namespace std;
	int slen = code.size();
	flex_state.parse_line = 0;
	flex_state.parse_pos = 0;
	flex_state.parse_len = 0;
	flex_state.line_pos = 0;
	if (iter_buff != 0) {
		free(iter_buff); iter_buff = nullptr;
	}
	iter_buff = (char *)malloc(slen + 2);
	// 要以两个'\0'结束
	memset(iter_buff, 0, slen + 2);
	strcpy(iter_buff, code.c_str());
	yy_buffer = yy_scan_buffer(iter_buff, slen + 2);
	//int token = yyparse();
	//if (token == 0) {
	//	flex_state.isnull = true;
	//}
	//else {
	//	flex_state.isnull = false;
	//}
	//flex_state.parse_len = yyleng;
}
void release_buff() {
	yy_delete_buffer(yy_buffer);
	free(iter_buff);iter_buff = nullptr;
}
#else
int make_term_flex(const TokenMeta & token, const char * w) {
	flex_state.CurrentTerm = Term{ token, std::string(w) };
	return token;
}
FlexState next_token(const std::string & in_str, int start){
	using namespace std;
	int slen = in_str.size() - start;
	flex_state.parse_line = 0;
	flex_state.parse_pos = start;
	flex_state.parse_len = 0;
	flex_state.line_pos = start;
	if (slen <= 0) {
		flex_state.isnull = true;
		return flex_state;
	}
	char * buff = (char *)malloc(slen + 2);
	// 要以两个'\0'结束
	memset(buff, 0, slen + 2);
	strcpy(buff, in_str.c_str() + start);
	// or you can use
	/*
	FILE *newstdin = fmemopen (args, strlen (args), "r");
	FILE *oldstdin = fdup(stdin);
	stdin = newstdin;
	*/
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

char * iter_buff = nullptr;
FlexState iter_token(const std::string & in_str, int start) {
	using namespace std;
	int slen = in_str.size();
	flex_state.parse_line = 0;
	flex_state.parse_pos = start;
	flex_state.parse_len = 0;
	flex_state.line_pos = start;
	if (start >= slen) {
		flex_state.isnull = true;
		return flex_state;
	}
	if (iter_buff == 0) {
		iter_buff = (char *)malloc(slen + 2);
		// 要以两个'\0'结束
		memset(iter_buff, 0, slen + 2);
		strcpy(iter_buff, in_str.c_str());
	}
	YY_BUFFER_STATE buffer = yy_scan_buffer(iter_buff + start, slen + 2 - start);
	int token = yylex();
	if (token == 0) {
		flex_state.isnull = true;
		yy_delete_buffer(buffer);
		free(iter_buff);
		iter_buff = nullptr;
	}
	else {
		flex_state.isnull = false;
	}
	flex_state.parse_len = yyleng;
	return flex_state;
}
#endif