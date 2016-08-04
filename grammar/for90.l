%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>
#include <map>
#include <boost/algorithm/string.hpp>
#include "../tokenizer.h"
#include "../parser.h"

	// 前置声明
#ifdef USE_YACC
#include "for90.tab.h"
int word_parse();
#else

#endif
void update_flex(int len, bool newline = false); // do not update CurrentTerm
void update_yylval(Term & current_term, bool empty = false);
extern std::string global_code;
int make_term_flex(const TokenMeta & token, const char * w);

#ifdef USE_YACC
// yacc
// USE WHTN USE YACC EITHER
#define YYRTN(TOK, YYTOK)  update_yylval(Term{TOK, std::string(yytext)});	update_flex(yyleng);  return YYTOK; 
// 对于非char运算符要预先解析
#define YYRTOP(TOK, YYTOK) update_yylval(Term{TOK, std::string(yytext)});  update_flex(yyleng);  return YYTOK; 
// include literal const such as pi, true, false, etc.
#define YYRTWORD() {  /*do not update yylval because some tokens need to be looked ahead, such as `else if` */ int p = word_parse(); if (p != YY_REQ_MORE) \
	{ update_flex(yyleng);  return p;  } else{  /* ?? */ update_flex(yyleng); } }

#define YYRTINT(TOK) YYRTN(TOK, YY_INTEGER) 
#define YYRTFLOAT(TOK) YYRTN(TOK, YY_FLOAT) 
#define YYRTSTRING(TOK) YYRTN(TOK, YY_STRING) 
// 规则中被定义的终结符, **包括ascii表内的单个字符**
#define YYRTILLEGAL(TOK) update_yylval( Term{TOK, std::string(yytext)});  	 update_flex(1);	return yytext[0]; 
#define YYRTCRLF()  update_yylval( Term{TokenMeta::CRLF, std::string(yytext)}); update_flex(yyleng);
#define YYRTNOP() update_yylval( Term{TokenMeta::Nop, std::string(yytext)},  true);  update_flex(yyleng);

#define RTN(TOK, YYTOK) YYRTN(TOK, YYTOK) 
#define RTOP(TOK, YYTOK) YYRTOP(TOK, YYTOK)
#define RTWORD() YYRTWORD()
#define RTINT(TOK) YYRTINT(TOK)
#define RTFLOAT(TOK) YYRTFLOAT(TOK)
#define RTSTRING(TOK) YYRTSTRING(TOK)
#define RTILLEGAL(TOK) YYRTILLEGAL(TOK)
// 换行
#define RTCRLF() YYRTCRLF()
// 空格, 制表符等
#define RTNOP() YYRTNOP()
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
#define NYRTCRLF() update_flex(yyleng, true);  /*DO NOT RETURN, CONTINUE yylex*/
#define NYRTNOP() update_flex(yyleng); /*DO NOT RETURN*/

#define RTN(TOK, YYTOK) NYRTN(TOK)
#define RTOP(TOK, YYTOK) NYRTOP(TOK)
#define RTWORD(TOK) NYRTWORD(TOK)
#define RTINT(TOK) NYRTINT(TOK)
#define RTFLOAT(TOK) NYRTFLOAT(TOK)
#define RTSTRING(TOK) NYRTSTRING(TOK)
#define RTILLEGAL(TOK) NYRTILLEGAL(TOK)
#define RTCRLF() NYRTCRLF()
#define RTNOP() NYRTNOP()
#endif // USE_YACC


FlexState flex_state;
#ifdef USE_YACC

#else

#endif
%}

%option yymore

delim   [ \t]
ws      {delim}+
newline [\r\n]

%%

{newline} {RTCRLF() }
{ws} {RTNOP() }
[-+]?[0-9]+ {RTINT(TokenMeta::META_INTEGER) }
[-+]?[0-9\.]+([eE][0-9\.]+)? {RTFLOAT(TokenMeta::META_FLOAT) }
:: {RTOP(TokenMeta::DoubleColon, YY_DOUBLECOLON)}
"**" {RTOP(TokenMeta::Power, YY_POWER) }
">" {RTOP(TokenMeta::GT, YY_GT) }
">=" {RTOP(TokenMeta::GE, YY_GE)}
"<" {RTOP(TokenMeta::LT, YY_LT)}
"<=" {RTOP(TokenMeta::LE, YY_LE)}
"==" {RTOP(TokenMeta::EQ, YY_EQ) }
"/=" {RTOP(TokenMeta::NEQ, YY_NEQ)}
"~" {yymore(); ECHO; putchar('\n'); }
[Ee][Ll][Ss][Ee]{ws}[Ii][Ff] {RTWORD()}
[a-zA-Z_][a-zA-Z0-9]* { RTWORD() }
\.[a-zA-Z_][a-zA-Z0-9]*\. { RTWORD() }
\"(\\.|[^"])*\" {RTSTRING(TokenMeta::META_STRING) 
/* The delimiting quotes are escaped because they are Flex meta-characters. */}
. {/* can be parsed, including some operators not listed */ RTILLEGAL(TokenMeta::META_ILLEGAL) }

%%

int yywrap() 
{ 
   return(1); 
}

int make_term_flex(const TokenMeta & token, const char * w) {
	flex_state.CurrentTerm = Term{ token, std::string(w) };
	return token;
}
void update_flex(int len, bool newline) {
	if (newline) {
		flex_state.parse_line++; flex_state.line_pos = 0; flex_state.parse_pos += yyleng; flex_state.parse_len = 0;
	}
	else {
		flex_state.parse_pos += len; flex_state.line_pos += flex_state.parse_len; flex_state.parse_len = len;
	}
}
#ifdef USE_YACC

void update_yylval(Term & current_term, bool empty) {
	// YYRTWORD 不会调用该函数
	if (empty) {
		// 空格字符等
	}
	else {
		yylval.fs = FlexState(flex_state);
		yylval.fs.CurrentTerm = current_term;
		//yylval.fs.CurrentTerm = Term{current_term.token, global_code.substr(flex_state.parse_pos, yyleng) };
		//std::cout << global_code.substr(flex_state.parse_pos, yyleng) << std::endl;
	}
}
int word_parse() {
	using namespace std;
	FlexState & fs = flex_state;
	string yytextstr = string(yytext);
	transform(yytextstr.begin(), yytextstr.end(), yytextstr.begin(), tolower);
	yytextstr.erase(remove_if(yytextstr.begin(), yytextstr.end(), isspace), yytextstr.end());
	//yymore();
	//cout << "yytext : " << yytext << endl;
	for (int i = 0; i < keywords.size(); i++)
	{
		if (keywords[i].what == yytextstr) {
				update_yylval( Term{ keywords[i].token , std::string(yytextstr) });
				return keywords[i].yytoken;
		}
	}
	update_yylval(Term{ TokenMeta::META_WORD , std::string(yytextstr) });
	return YY_WORD;
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