/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
%{
#include <cstdio>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <boost/algorithm/string.hpp>
#include "../tokenizer.h"
#include "../parser.h"
#include "../context.h"
#include "../gen_config.h"
//#include "../format.h"


// 前置声明
#ifdef USE_YACC
#include "for90.tab.h"
#else

#endif
struct FlexContext{
	char * iter_buff = nullptr;
	YY_BUFFER_STATE yy_buffer = nullptr;
};
FlexContext & get_flex_context() {
	static FlexContext fc;
	return fc;
}
struct FlexExternalContext {
	std::string external_state;
	int left_brackets = 0;
	std::string code;
	void begin_external_scanner(std::string trigger);
	void end_external_scanner();
	bool do_external_scanner(const char * text);
	int YYTOK;
	int len;
};
FlexExternalContext & get_flex_external_context() {
	static FlexExternalContext fc;
	return fc;
}
static bool abandon = false;
#ifdef USE_YACC
// USE YACC
int word_parse();
void update_flex(int len, bool newline = false) {
	// do not update CurrentTerm
	if (newline) {
		get_flex_state().parse_line++; get_flex_state().line_pos = 0; get_flex_state().parse_pos += yyleng; get_flex_state().parse_len = 0;
	}
	else {
		get_flex_state().parse_pos += len; get_flex_state().line_pos += get_flex_state().parse_len; get_flex_state().parse_len = len;
	}
}

void update_yylval(Term & current_term, bool empty = false) {
	// YYRTWORD 不会调用该函数
	if (empty) {
		// 空格字符等
	}
	else {
		yylval.fs = FlexState(get_flex_state());
		yylval.fs.CurrentTerm = current_term;
	}
}

std::string parse_ioformatter(const std::string & src); // gen_io.cpp
#define YYRTN(TOK, YYTOK)  update_yylval(Term{TOK, std::string(yytext)});  update_flex((int)yyleng);  return YYTOK; 
#define YYRTCRLF()  update_yylval( Term{TokenMeta::CRLF, std::string(yytext)}); update_flex((int)yyleng, true); return YY_CRLF;
// 空格, 制表符等
#define YYRTNOP() update_yylval( Term{TokenMeta::Nop, std::string(yytext)},  true);  update_flex((int)yyleng); 
// include literal const such as pi, true, false, etc.
#define YYRTNCOMMENT() update_yylval( Term{TokenMeta::Nop, std::string(yytext)},  true);  update_flex((int)yyleng); return YY_NULL;
/*do not call update_yylval because some tokens need to be looked ahead, such as `else if` */
#define YYRTWORD() {  int p = word_parse(); \
	update_flex((int)yyleng); \
	if (p != YY_IGNORE_THIS) { \
		  return p;  \
	}\
}

// 对于非char运算符要预先解析
#define YYRTOP(TOK, YYTOK) YYRTN(TOK, YYTOK)
#define YYRTINT(TOK) YYRTN(TOK, YY_INTEGER) 
#define YYRTFLOAT(TOK) YYRTN(TOK, YY_FLOAT) 
#define YYRTSTRING(TOK) YYRTN(TOK, YY_STRING) 
#define YYRTCOMPLEX(TOK) YYRTN(TOK, YY_COMPLEX) 
// 规则中被定义的终结符, **包括ascii表内的单个字符**
#define YYRTILLEGAL(TOK) YYRTN(TOK, yytext[0])

#define RTN(TOK, YYTOK) YYRTN(TOK, YYTOK) 
#define RTOP(TOK, YYTOK) YYRTOP(TOK, YYTOK)
#define RTWORD() YYRTWORD()
#define RTINT(TOK) YYRTINT(TOK)
#define RTFLOAT(TOK) YYRTFLOAT(TOK)
#define RTSTRING(TOK) YYRTSTRING(TOK)
#define RTCOMPLEX(TOK) YYRTCOMPLEX(TOK)
#define RTILLEGAL(TOK) YYRTILLEGAL(TOK)
#define RTCRLF() YYRTCRLF()
#define RTNOP() YYRTNOP()
#define RTNCOMMENT() YYRTNCOMMENT()
#else
// more spectific
// DO **NOT** USE WHEN USE YACC EITHER
int make_term_flex(const TokenMeta_T & token, const char * w) {
	// same as gen_flex in codegen.h
	get_flex_state().CurrentTerm = Term{ token, std::string(w) };
	return token;
}
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

%}

%option yymore
%x external_scanner

delim   [ \t]
ws      {delim}+
newline [\r\n]
floating [0-9\.]+([eE][0-9\.]+)?
integral [0-9]+
wordname [a-zA-Z_][a-zA-Z0-9_]*
wordoperator \.[a-zA-Z_][a-zA-Z0-9]*\.

%%

<external_scanner>. { if (get_flex_external_context().do_external_scanner(yytext)) { return get_flex_external_context().YYTOK;  } else { } }
^[Cc]{ws}+.*{newline}$ {	RTCRLF() /*注释*/}
!.*{newline}$ { RTCRLF() /*注释*/}
^[Cc]{ws}+.*$ {	RTNCOMMENT() /*注释*/}
!.*$ { RTNCOMMENT() /*注释*/}

^{newline}$ { /* 空行 */ }
{newline} {RTCRLF() }
{ws} { RTNOP() }
^[0-9]+ {RTN(TokenMeta::Label, YY_LABEL); }
{integral} { RTINT(TokenMeta::META_INTEGER) }
{floating} { RTFLOAT(TokenMeta::META_FLOAT) }
{floating}_[-+]?{floating} { RTCOMPLEX(TokenMeta::META_COMPLEX) }
"(/" {RTOP(TokenMeta::META_ANY, YY_ARRAYINITIAL_START) }
"/)" {RTOP(TokenMeta::META_ANY, YY_ARRAYINITIAL_END) }
"::" { RTOP(TokenMeta::DoubleColon, YY_DOUBLECOLON) }
"**" { RTOP(TokenMeta::Power, YY_POWER) }
">" { RTOP(TokenMeta::GT, YY_GT) }
">=" { RTOP(TokenMeta::GE, YY_GE) }
"<" { RTOP(TokenMeta::LT, YY_LT) }
"<=" { RTOP(TokenMeta::LE, YY_LE) }
"==" { RTOP(TokenMeta::EQ, YY_EQ) }
"/=" { RTOP(TokenMeta::NEQ, YY_NEQ) }
"//" { RTOP(TokenMeta::Add, '+') /* string concat */}

{wordname} { 
	RTWORD() 
}
{wordoperator} { RTWORD() }
\"(\\.|[^"])*\" {RTSTRING(TokenMeta::META_STRING) 
/* The delimiting quotes are escaped because they are Flex meta-characters. */}
\'(\\.|[^'])*\' {RTSTRING(TokenMeta::META_STRING) 
/* string with `'` */}
. {/* all other things, including some operators not listed */ RTILLEGAL(TokenMeta::META_ILLEGAL) }

%%

int yywrap() 
{ 
   return(1); 
}

#ifdef USE_YACC

int word_parse() {
	using namespace std;
	const FlexState & fs = get_flex_state();
	if (abandon) {
		// 跳过这个字符
		abandon = false;
		return YY_IGNORE_THIS;
	}
	string lowercase_name = string(yytext);
	transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), tolower); 
FIND_CONCAT:
	if (lowercase_name == "format")
	{
		get_flex_external_context().begin_external_scanner("format");
		return YY_IGNORE_THIS;
	}
	else {
		auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == lowercase_name; });
		if (keyword_iter != keywords.end()) {
			auto forward1_iter = find_if(forward1.begin(), forward1.end(), [&](const auto & x) {return x.first == lowercase_name; });
			if (forward1_iter != forward1.end()) {
				// not a valid yylval
				std::string next = CutString(get_context().global_code.begin() + fs.parse_pos + yyleng
					/* yyleng != fs.parse_len because RTNWORD do not update_flex before */
					, get_context().global_code.end(), false);
				auto next_iter = find_if(forward1_iter->second.begin(), forward1_iter->second.end(), [&](const auto & x) {return x == next; });
				if (next_iter != forward1_iter->second.end()) {
					// concat two string
					lowercase_name += next;
					abandon = true; // ignore next
					goto FIND_CONCAT;
				}
			}
			/* this is a keyword with specialized yytoken */
			if (pre_map.find(lowercase_name) != pre_map.end()) {
				lowercase_name = pre_map.at(lowercase_name);
			}
			update_yylval(Term{ keyword_iter->token , std::string(lowercase_name) });
			return keyword_iter->yytoken;
		}
		if (pre_map.find(lowercase_name) != pre_map.end()) {
			// replace according to tokenizer.cpp
			lowercase_name = pre_map.at(lowercase_name);
		}
		update_yylval(Term{ TokenMeta::META_WORD , std::string(lowercase_name) });
		return YY_WORD;
	}
}

void set_buff(const std::string & code) {
	using namespace std;
	int slen = code.size();
	get_flex_state().parse_line = 0;
	get_flex_state().parse_pos = 0;
	get_flex_state().parse_len = 0;
	get_flex_state().line_pos = 0; 
	if (get_flex_context().iter_buff != nullptr) {
		free(get_flex_context().iter_buff); get_flex_context().iter_buff = nullptr;
	}
	get_flex_context().iter_buff = (char *)malloc(slen + 2);
	// 要以两个'\0'结束
	memset(get_flex_context().iter_buff, 0, slen + 2);
	strcpy(get_flex_context().iter_buff, code.c_str());
	get_flex_context().yy_buffer = yy_scan_buffer(get_flex_context().iter_buff, slen + 2);
}
void release_buff() {
	yy_delete_buffer(get_flex_context().yy_buffer);
	free(get_flex_context().iter_buff); get_flex_context().iter_buff = nullptr;
}
void FlexExternalContext::begin_external_scanner(std::string trigger) {
	external_state = trigger;
	left_brackets = 0;
	code = "";
	// 此时parse_pos已经扫过了trigger字符串
	len = 0;
	BEGIN(external_scanner);
}
void FlexExternalContext::end_external_scanner() {
	BEGIN(0);
}
bool FlexExternalContext::do_external_scanner(const char * text) {
	len++;
	if (external_state == "format")
	{
		if (text[0] == '(')
		{
			left_brackets++;
		}
		else if (text[0] == ')') {
			left_brackets--;
			if (left_brackets == 0)
			{
				end_external_scanner();
				YYTOK = YY_FORMAT_STMT;
				std::string result = parse_ioformatter(code);
				update_yylval(Term{ TokenMeta::NT_FORMAT, result });
				update_flex((int)len);
				return true;
			}
		}
		else {
			code += text;
		}
	}
	return false;
}
#else
FlexState next_token(const std::string & in_str, int start){
	using namespace std;
	int slen = in_str.size() - start;
	get_flex_state().parse_line = 0;
	get_flex_state().parse_pos = start;
	get_flex_state().parse_len = 0;
	get_flex_state().line_pos = start;
	if (slen <= 0) {
		get_flex_state().isnull = true;
		return get_flex_state();
	}
	char * buff = (char *)malloc(slen + 2);
	// end with two '\0'
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
		get_flex_state().isnull = true;
	}
	else {
		get_flex_state().isnull = false;
	}
	get_flex_state().parse_len = yyleng;
    yy_delete_buffer(buffer);
	free(buff);
	return get_flex_state();
}

char * iter_buff = nullptr;
FlexState iter_token(const std::string & in_str, int start) {
	using namespace std;
	int slen = in_str.size();
	get_flex_state().parse_line = 0;
	get_flex_state().parse_pos = start;
	get_flex_state().parse_len = 0;
	get_flex_state().line_pos = start;
	if (start >= slen) {
		get_flex_state().isnull = true;
		return get_flex_state();
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
		get_flex_state().isnull = true;
		yy_delete_buffer(buffer);
		free(iter_buff);
		iter_buff = nullptr;
	}
	else {
		get_flex_state().isnull = false;
	}
	get_flex_state().parse_len = yyleng;
	return get_flex_state();
}
#endif