%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>
#include "../tokenizer.h"
#include "for90.flex.h"

	// 前置声明
#ifdef USE_YACC
#include "for90.tab.h"
//#define YY_DECL extern "C" int yylex()
//#define YYSTYPE FlexState
int word_parse(YYSTYPE & fs);
#else

#endif
void update_flex(int len, bool newline = false);
int make_term_flex(const TokenMeta & token, const char * w);

#ifdef USE_YACC
// yacc
// USE WHTN USE YACC EITHER
#define YYRTN(TOK, YYTOK) update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)}; return YYTOK; 
// 对于非char运算符要预先解析
#define YYRTOP(TOK, YYTOK) update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)}; return YYTOK; 
// include literal const such as pi, true, false, etc.
#define YYRTWORD() update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TokenMeta::META_ANY, std::string(yytext)}; return word_parse(yylval); 
#define YYRTINT(TOK) update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)};  return YY_INTEGER;
#define YYRTFLOAT(TOK) update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)}; return YY_FLOAT; 
#define YYRTSTRING(TOK) update_flex(yyleng); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)}; return YY_STRING; 
// 规则中被定义的终结符, **包括ascii表内的单个字符**
#define YYRTILLEGAL(TOK) update_flex(1); yylval = flex_state; yylval.CurrentTerm = Term{TOK, std::string(yytext)}; return yytext[0]; 
#define YYRTCRLF(TOK) update_flex(yyleng, true);
#define YYRTNOP(TOK) update_flex(yyleng);

#define RTN(TOK, YYTOK) YYRTN(TOK, YYTOK) 
#define RTOP(TOK, YYTOK) YYRTOP(TOK, YYTOK)
#define RTWORD(TOK) YYRTWORD(TOK)
#define RTINT(TOK) YYRTINT(TOK)
#define RTFLOAT(TOK) YYRTFLOAT(TOK)
#define RTSTRING(TOK) YYRTSTRING(TOK)
#define RTILLEGAL(TOK) YYRTILLEGAL(TOK)
// 换行
#define RTCRLF(TOK) YYRTCRLF(TOK)
// 空格, 制表符等
#define RTNOP(TOK) YYRTNOP(TOK)
#else
// more spectific
// DO **NOT** USE WHEN USE YACC EITHER
#define NYRTN(TOK) update_flex(yyleng); return make_term_flex(TOK, yytext);  
#define NYRTOP(TOK) update_flex(yyleng); return make_term_flex(TokenMeta::META_OPERATOR, yytext); 
#define NYRTWORD(TOK) update_flex(yyleng); return make_term_flex(TokenMeta::META_WORD, yytext);  
#define NYRTINT(TOK) update_flex(yyleng); return make_term_flex(TokenMeta::META_INTEGER, yytext); 
#define NYRTFLOAT(TOK) update_flex(yyleng); return make_term_flex(TokenMeta::META_FLOAT, yytext); 
#define NYRTSTRING(TOK) update_flex(yyleng); return make_term_flex(TokenMeta::META_STRING, yytext); 
#define NYRTILLEGAL(TOK) update_flex(1); return make_term_flex(TokenMeta::META_ILLEGAL, yytext); 
#define NYRTCRLF(TOK) update_flex(yyleng, true);  /*DO NOT RETURN, CONTINUE yylex*/
#define NYRTNOP(TOK) update_flex(yyleng); /*DO NOT RETURN*/

#define RTN(TOK, YYTOK) NYRTN(TOK)
#define RTOP(TOK, YYTOK) NYRTOP(TOK)
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
[-+]?[0-9]+ {RTINT(TokenMeta::META_INTEGER) }
[-+]?[0-9\.]+([eE][0-9\.]+)? {RTFLOAT(TokenMeta::META_FLOAT) }
[a-zA-Z_][a-zA-Z0-9]* { RTWORD() }
"**" {RTOP(TokenMeta::Power, YY_POWER) }
">" {RTOP(TokenMeta::GT, YY_GT) }
">=" {RTOP(TokenMeta::GE, YY_GE )}
"<" {RTOP(TokenMeta::LT, YY_LT)}
"<=" {RTOP(TokenMeta::LE, YY_LE)}
"==" {RTOP(TokenMeta::EQ, YY_EQ) }
"/=" {RTOP(TokenMeta::NEQ, YY_NEQ)}
\.[a-zA-Z_][a-zA-Z0-9]*\. { RTWORD() }
:: {RTOP(TokenMeta::DoubleColon, YY_DOUBLECOLON)}
\"(\\.|[^"])*\" {RTSTRING(TokenMeta::META_STRING) 
/* The delimiting quotes are escaped because they are Flex meta-characters. */}
. {/* can be parsed, including some operators not listed */ RTILLEGAL(TokenMeta::META_ILLEGAL) }

%%

int yywrap() 
{ 
   return(1); 
}
void update_flex(int len, bool newline){
	if(newline){
		flex_state.parse_line++; flex_state.line_pos = 0; flex_state.parse_pos = 0;
	}else{
		flex_state.parse_pos += len; flex_state.line_pos += len;
	}
}
int make_term_flex(const TokenMeta & token, const char * w) {
	flex_state.CurrentTerm = Term{ token, std::string(w) };
	return token;
}
#ifdef USE_YACC
int word_parse(YYSTYPE & fs) {
	using namespace std;
	transform(fs.CurrentTerm.what.begin(), fs.CurrentTerm.what.end(), fs.CurrentTerm.what.begin(), tolower);
	const string & s = fs.CurrentTerm.what;
	if (s == "if") {
		yylval.CurrentTerm = Term{ TokenMeta::If, std::string(yytext) };
		return YY_IF;
	}
	else if (s == "then") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_THEN;
	}
	else if (s == "else") {
		yylval.CurrentTerm = Term{ TokenMeta::Else, std::string(yytext) };
		return YY_ELSE;
	}
	else if (s == "end") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_END;
	}
	else if (s == "do") {
		yylval.CurrentTerm = Term{ TokenMeta::Do, std::string(yytext) };
		return YY_DO;
	}
	else if (s == "continue") {
		yylval.CurrentTerm = Term{ TokenMeta::Continue, std::string(yytext) };
		return YY_CONTINUE;
	}
	else if (s == "while") {
		yylval.CurrentTerm = Term{ TokenMeta::While, std::string(yytext) };
		return YY_WHILE;
	}
	else if (s == "where") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_WHERE;
	}
	else if (s == "case") {
		yylval.CurrentTerm = Term{ TokenMeta::Case, std::string(yytext) };
		return YY_CASE;
	}
	else if (s == "program") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_PROGRAM;
	}
	else if (s == "function") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_FUNCTION;
	}
	else if (s == "recursive") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_RECURSIVE;
	}
	else if (s == "result") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_RESULT;
	}
	else if (s == "subroutine") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_SUBROUTINE;
	}
	else if (s == "module") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_MODULE;
	}
	else if (s == "block") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_BLOCK;
	}
	else if (s == "implicit") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_IMPLICIT;
	}
	else if (s == "none") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_NONE;
	}
	else if (s == "use") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_USE;
	}
	else if (s == "parameter") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_PARAMETER;
	}
	else if (s == "format") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_FORMAT;
	}
	else if (s == ".and.") {
		yylval.CurrentTerm = Term{ TokenMeta::AndAnd, std::string(yytext) };
		return YY_ANDAND;
	}
	else if (s == ".or.") {
		yylval.CurrentTerm = Term{ TokenMeta::OrOr, std::string(yytext) };
		return YY_OROR;
	}
	else if (s == ".not.") {
		yylval.CurrentTerm = Term{ TokenMeta::Not, std::string(yytext) };
		return YY_NOT;
	}
	else if (s == ".eqv.") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_EQV;
	}
	else if (s == ".neqv") {
		yylval.CurrentTerm = Term{ TokenMeta::META_ANY, std::string(yytext) };
		return YY_NEQV;
	}
	else if (s == ".true.") {
		yylval.CurrentTerm = Term{ TokenMeta::True, std::string(yytext) };
		return YY_TRUE;
	}
	else if (s == ".false.") {
		yylval.CurrentTerm = Term{ TokenMeta::False, std::string(yytext) };
		return YY_FALSE;
	}
	else if (s == ".gt.") {
		yylval.CurrentTerm = Term{ TokenMeta::GT, std::string(yytext) };
		return YY_GT;
	}
	else if (s == ".ge.") {
		yylval.CurrentTerm = Term{ TokenMeta::GE, std::string(yytext) };
		return YY_GE;
	}
	else if (s == ".lt.") {
		yylval.CurrentTerm = Term{ TokenMeta::LT, std::string(yytext) };
		return YY_LT;
	}
	else if (s == ".le.") {
		yylval.CurrentTerm = Term{ TokenMeta::LE, std::string(yytext) };
		return YY_LE;
	}
	else if (s == ".eq.") {
		yylval.CurrentTerm = Term{ TokenMeta::EQ, std::string(yytext) };
		return YY_EQ;
	}
	else if (s == ".neq.") {
		yylval.CurrentTerm = Term{ TokenMeta::NEQ, std::string(yytext) };
		return YY_NEQ;
	}
	else {
		return YY_WORD;
	}
}
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
}
void release_buff() {
	yy_delete_buffer(yy_buffer);
	free(iter_buff);iter_buff = nullptr;
}
#else
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