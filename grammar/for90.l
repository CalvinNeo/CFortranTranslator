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
#ifdef USE_YACC
#include "for90.tab.h"
#else

#endif

void update_flex(int len, bool newline = false) {
	// do not update CurrentTerm
	if (newline) {
		get_flex_state().parse_line++;
		get_flex_state().parse_pos += len; get_flex_state().line_pos = 0; get_flex_state().parse_len = len;
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
struct FlexContext{
	char * iter_buff = nullptr;
	YY_BUFFER_STATE yy_buffer = nullptr;
};
FlexContext & get_flex_context() {
	static FlexContext fc;
	return fc;
}
struct FlexScannerContext {
	std::string trigger;
	int condition;
	virtual void begin_scanner(std::string trigger, int condition) {
		// 此时parse_pos已经扫过了trigger字符串
		this->trigger = trigger;
		this->condition = condition;
		code = "";
		BEGIN(condition);
	}
	virtual void end_scanner(int yy_token, Term term) {
		this->YYTOK = yy_token;
		update_yylval(term);
		BEGIN(0);
	}
	int YYTOK;
	std::string code;
};

std::string parse_ioformatter(const std::string & src); // gen_io.cpp
struct FlexExternalContext : public FlexScannerContext {
	int left_brackets = 0;
	int len;
	void begin_scanner(std::string trigger, int condition) {
		left_brackets = 0;
		len = 0;
		FlexScannerContext::begin_scanner(trigger, condition);
	}
	bool do_scanner(const char * text) {
		// return true to return a YYTOK
		len++;
		code += text;
		if (this->trigger == "format")
		{
			if (text[0] == '(')
			{
				left_brackets++;
			}
			else if (text[0] == ')') {
				left_brackets--;
				if (left_brackets == 0)
				{
					std::string result = parse_ioformatter(code); //
					update_flex((int)len);
					FlexScannerContext::end_scanner(YY_FORMAT_STMT, Term{ TokenMeta::NT_FORMAT, result });
					return true;
				}
			}
		}
		return false;
	}
};
FlexExternalContext & get_flex_external_context() {
	static FlexExternalContext fc;
	return fc;
}
struct FlexLabelEndContext : public FlexScannerContext {
	bool end_label_hit = false;
	bool quit;
	void begin_scanner(std::string trigger, int condition) {
		end_label_hit = false;
		FlexScannerContext::begin_scanner(trigger, condition);
	}
	void end_scanner(int yy_token, Term term) {
		this->YYTOK = yy_token;
		update_yylval(term);
		end_label_hit = false;
		if (quit)
		{
			BEGIN(0);
		}
		else {
			// keep in the label_end_scanner mode
		}
	}
};
FlexLabelEndContext & get_label_end_context() {
	static FlexLabelEndContext fc;
	return fc;
}
struct FlexJumpToContext : public FlexScannerContext {
	int index = 0;
	int goal;
	bool jumped_do_label;
	void begin_scanner(std::string trigger, int condition, int next_n) {
		index = 0;
		goal = next_n;
		jumped_do_label = false;
		FlexScannerContext::begin_scanner(trigger, condition);
	}
	bool do_scanner(const char * text) {
		// return true to return a YYTOK
		index++;
		if (index == goal)
		{
			FlexScannerContext::end_scanner(YY_NULL, Term{ TokenMeta::Nop, "" });
			return false; // 不返回
		}
		return false;
	}
};
FlexJumpToContext & get_jump_to_context() {
	static FlexJumpToContext fc;
	return fc;
}
static bool abandon = false;
#ifdef USE_YACC
// USE YACC
int word_parse();


#define YYRTN(TOK, YYTOK)  update_yylval(Term{TOK, std::string(yytext)});  update_flex((int)yyleng);  return YYTOK; 
#define YYRTCRLF()  update_yylval( Term{TokenMeta::CRLF, std::string(yytext)}); update_flex((int)yyleng, true); return YY_CRLF;
// 空格, 制表符等
#define YYRTNOP() /* do not update yylval */  update_flex((int)yyleng); /* do not return */
// include literal const such as pi, true, false, etc.
#define YYRTNCOMMENT() /* do not update yylval */  update_flex((int)yyleng, false/* not empty */);  /* do not return */

// 对于非char运算符要预先解析
#define YYRTCOMPLEX(TOK) YYRTN(TOK, YY_COMPLEX) 
// 规则中被定义的终结符, **包括ascii表内的单个字符**
#define YYRTILLEGAL(TOK) YYRTN(TOK, yytext[0])

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

#endif // USE_YACC

%}

%option yymore
%x external_scanner
%s label_end_scanner
%x jump_to_scanner

delim   [ \t]
ws      {delim}+
newline [\r\n]
/***
R412 signed - real - literal - constant is[sign] real - literal - constant
R413 real - literal - constant is significand[exponent - letter exponent][_ kind - param]
	or digit - string exponent - letter exponent[_ kind - param]
R414 significand is digit - string .[digit - string]
	or .digit - string
R415 exponent - letter is E
	or D
R416 exponent is signed - digit - string
Constraint : If both kind - param and exponent - letter are present, exponent - letter must be E.
	Constraint : The value of kind - param must specify an approximation method that exists on the processor.
	A real literal constant without a kind type parameter is a default real constant if it is without an exponent part or
	has exponent letter E, and is a double precision real constant if it has exponent letter D.A real literal constant
	written with a kind type parameter is a real constant with the specified kind type parameter.
**/
digit [0-9]
letter [a-zA-Z]
digits {digit}+
kind_param (digits|{letter}+)
exponent [eEdD][-+]?{digits}?\.{digits}
floating {digits}?\.{digits}{exponent}?
narrow_floating {digits}\.
integral {digits}(_{kind_param})?
starter ({letter}|_)
wordname {starter}({starter}|{digit})*
wordoperator \.{wordname}\.
word ({wordname}|{wordoperator})

%%

<external_scanner,jump_to_scanner>. { 
	if (get_flex_external_context().do_scanner(yytext)) { 
		return get_flex_external_context().YYTOK;  
	} else {
		/* DON'T return */
	} 
}


^[Cc]{delim}*[^\r\n]* {
	// std::cout << yytext << std::endl;
	YYRTNCOMMENT() 
}
![^\r\n]* {
	// std::cout << yytext << std::endl;
	YYRTNCOMMENT() 
}

{newline}{ws}\* {
	YYRTNOP() 
}
{newline} {YYRTCRLF() }
{ws} { YYRTNOP() }
<INITIAL>^{ws}[0-9]+ {
	YYRTN(TokenMeta::Label, YY_LABEL); 
}
<label_end_scanner>^{delim}*[0-9]+ {
	auto iter = get_context().end_labels.find(std::string(yytext));
	if (iter != get_context().end_labels.end()) {
		iter->second.pop_back();
		get_label_end_context().end_label_hit = true;
		if (iter->second.size() == 0)
		{
			get_label_end_context().quit = true;
		}
	}
	YYRTNOP()
}
<label_end_scanner>{integral} {
	if (!get_jump_to_context().jumped_do_label) {
		// std::cout << "---11 " << yytext << std::endl;
		get_jump_to_context().jumped_do_label = true;
		YYRTNOP()
	}
	else {
		// std::cout << "+++11 " << yytext << std::endl;
		YYRTN(TokenMeta::META_INTEGER, YY_INTEGER)
	}
}
<INITIAL>{integral} { YYRTN(TokenMeta::META_INTEGER, YY_INTEGER) }
{floating} {
	YYRTN(TokenMeta::META_FLOAT, YY_FLOAT)
}
{narrow_floating} {
	YYRTN(TokenMeta::META_FLOAT, YY_FLOAT)
}
{floating}_[-+]?{floating} { YYRTN(TokenMeta::META_COMPLEX, YY_COMPLEX) }
"(/" {YYRTN(TokenMeta::META_ANY, YY_ARRAYINITIAL_START) }
"/)" {YYRTN(TokenMeta::META_ANY, YY_ARRAYINITIAL_END) }
"::" { YYRTN(TokenMeta::DoubleColon, YY_DOUBLECOLON) }
"**" { YYRTN(TokenMeta::Power, YY_POWER) }
">" { YYRTN(TokenMeta::GT, YY_GT) }
">=" { YYRTN(TokenMeta::GE, YY_GE) }
"<" { YYRTN(TokenMeta::LT, YY_LT) }
"<=" { YYRTN(TokenMeta::LE, YY_LE) }
"==" { YYRTN(TokenMeta::EQ, YY_EQ) }
"/=" { YYRTN(TokenMeta::NEQ, YY_NEQ) }
"//" { YYRTN(TokenMeta::Add, '+') /* string concat */}

<INITIAL>{word} {
	// RTWORD() 
	/*do not call update_yylval in this macro because some tokens need to be looked ahead, such as `else if` */
	int p = word_parse();
	update_flex((int)yyleng); // IMPORTANT, yyleng NOT always equal to `lowercase_name.size()` because of `pre_map`
	// std::cout << "-----------" << yytext << std::endl;
	if (p != YY_IGNORE_THIS) {
		return p;  
	}
}

<label_end_scanner>{word} {
	int p = word_parse();
	update_flex((int)yyleng); // IMPORTANT, yyleng NOT always equal to `lowercase_name.size()` because of `pre_map`
	if (p == YY_CONTINUE && get_label_end_context().end_label_hit == true) {
		 std::cout << "---" << yytext << std::endl;
		// do not update_flex
		get_label_end_context().end_scanner(YY_ENDDO, Term{TokenMeta::RBrace, "enddo"});
		return YY_ENDDO;
	}
	if (p != YY_IGNORE_THIS) {
		return p;
	}
}

\"(\\.|[^"])*\" {
	YYRTN(TokenMeta::META_STRING, YY_STRING) /* The delimiting quotes are escaped because they are Flex meta-characters. */
}
\'(\\.|[^'])*\' {
	YYRTN(TokenMeta::META_STRING, YY_STRING)  /* string with `'` */
}
. {/* all other things, including some operators not listed */ YYRTILLEGAL(TokenMeta::META_ILLEGAL) }

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
		get_flex_external_context().begin_scanner("format", external_scanner);
		return YY_IGNORE_THIS;
	}
	else if (lowercase_name == "do") {
		std::string next = CutString(get_context().global_code.begin() + fs.parse_pos + yyleng
			/* yyleng != fs.parse_len because RTNWORD do not update_flex before */
			, get_context().global_code.end(), false);
		if (next[0] >= '0' && next[0] <= '9') {
			// label-do-stmt is [ do-construct-name : ] DO label [ loop-control ]
			get_context().end_labels[next].push_back("do");
			get_label_end_context().begin_scanner("do", label_end_scanner);
			return YY_DO;
		}
	}
NORMAL_CONDITION:
	int tok = TokenMeta::META_WORD;
	int yytok = YY_WORD;
	auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == lowercase_name; });
	if (keyword_iter != keywords.end()) {
		// if fortran keyword
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
		tok = keyword_iter->token;
		yytok = keyword_iter->yytoken;
	}
	if (pre_map.find(lowercase_name) != pre_map.end()) {
		// replace according to tokenizer.cpp
		lowercase_name = pre_map.at(lowercase_name);
	}
	update_yylval(Term{ tok, std::string(lowercase_name) });
	return yytok;
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