%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>
#include <map>
#include "../tokenizer.h"
#include "../parser.h"

	// 前置声明
#ifdef USE_YACC
#include "for90.tab.h"
int word_parse();
#else

#endif
void update_yylval(int len, Term & current_term, bool newline = false, bool empty = false);
int make_term_flex(const TokenMeta & token, const char * w);

int code_pos = 0;

#ifdef USE_YACC
// yacc
// USE WHTN USE YACC EITHER
#define YYRTN(TOK, YYTOK) code_pos += yyleng; update_yylval(yyleng, Term{TOK, std::string(yytext)});	 return YYTOK; 
// 对于非char运算符要预先解析
#define YYRTOP(TOK, YYTOK) code_pos += yyleng; update_yylval(yyleng, Term{TOK, std::string(yytext)});    return YYTOK; 
// include literal const such as pi, true, false, etc.
#define YYRTWORD() { code_pos += yyleng; /*do not update yylval because some tokens need to be looked ahead, such as `else if` */ int p = word_parse(); if (p != YY_REQ_MORE) { return p; } }

#define YYRTINT(TOK) code_pos += yyleng; update_yylval(yyleng, Term{TOK, std::string(yytext)});   	return YY_INTEGER;
#define YYRTFLOAT(TOK) code_pos += yyleng; update_yylval(yyleng, Term{TOK, std::string(yytext)});   	return YY_FLOAT; 
#define YYRTSTRING(TOK) code_pos += yyleng; update_yylval(yyleng, Term{TOK, std::string(yytext)});  	return YY_STRING; 
// 规则中被定义的终结符, **包括ascii表内的单个字符**
#define YYRTILLEGAL(TOK) code_pos += 1; update_yylval(1, Term{TOK, std::string(yytext)});  	return yytext[0]; 
#define YYRTCRLF() code_pos += yyleng; update_yylval(yyleng, Term{TokenMeta::CRLF, std::string(yytext)}, true);
#define YYRTNOP() code_pos += yyleng; update_yylval(yyleng, Term{TokenMeta::Nop, std::string(yytext)}, false, true);

#define RTN(TOK, YYTOK) YYRTN(TOK, YYTOK) 
#define RTOP(TOK, YYTOK) YYRTOP(TOK, YYTOK)
#define RTWORD() YYRTWORD();
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

void update_yylval(int len, Term & current_term, bool newline, bool empty){
	// YYRTWORD 不会调用该函数
	if(newline){
		flex_state.parse_line++; flex_state.line_pos = 0; flex_state.parse_pos = 0; flex_state.parse_len = 0;
	}
	else if (empty) {
		// 空格字符等
	}
	else {
		//flex_state.parse_pos += flex_state.parse_len; flex_state.line_pos += flex_state.parse_len; flex_state.parse_len = yyleng;
		flex_state.parse_pos += code_pos; flex_state.line_pos += flex_state.parse_len; flex_state.parse_len = yyleng;
		flex_state.CurrentTerm = current_term;
		yylval.fs = flex_state;
	}
}
int make_term_flex(const TokenMeta & token, const char * w) {
	flex_state.CurrentTerm = Term{ token, std::string(w) };
	return token;
}
#ifdef USE_YACC
int word_parse() {
	using namespace std;
	FlexState & fs = yylval.fs;
	string yytextstr = string(yytext);
	transform(yytextstr.begin(), yytextstr.end(), yytextstr.begin(), tolower);
	for (int i = 0; i < keywords.size(); i++)
	{
		if (keywords[i].what == yytextstr) {
		//	// 
		//	map<string, vector<string>>::iterator mapf = forward1.find(flex_state.CurrentTerm.what);
		//	map<string, vector<string>>::iterator mapself = forward1.find(yytextstr);
		//	if (mapf != forward1.end()) {
		//		// 如果yytextstr前面是forward1里面的key, 例如if, 此时flex_state(等于else) 比 fs(等于if) 要提前一个token
		//		if (find(mapf->second.begin(), mapf->second.end(), yytextstr) != mapf->second.end()) {
		//			// 构成归约
		//		}
		//		else {
		//			// 不构成归约
		//		}
		//	}
		//	else if (mapself != forward1.end()) {
		//		// do not update yylval because need to look ahead
		//		// e.g else | if
		//		update_yylval(yyleng, Term{ keywords[i].token , std::string(yytextstr) });
		//		return YY_REQ_MORE;
		//	}
		//	else {
				update_yylval(yyleng, Term{ keywords[i].token , std::string(yytextstr) });
				return keywords[i].yytoken;
			//}
		}
	}
	return YY_WORD;
}
char * iter_buff = nullptr;
/*
	遇到空格或者回车等无效字符时, code_pos会自增, 但是flex_state不会改变
*/
YY_BUFFER_STATE yy_buffer = nullptr;
void set_buff(const std::string & code) {
	using namespace std;
	int slen = code.size();
	flex_state.parse_line = 0;
	flex_state.parse_pos = 0;
	flex_state.parse_len = 0;
	flex_state.line_pos = 0; 
	code_pos = 0;
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