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
#include <iostream>
#include <functional>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <memory>
#include "../parser/tokenizer.h"
#include "../parser/parser.h"
#include "../parser/context.h"
#include "../target/gen_config.h"
#include "for90.tab.h"
#include <tuple>
/****************
*	this mean flex generated function is of name `pure_yylex`, not originally `yylex`
****************/

#define YY_DECL int pure_yylex(void)
	
static void update_flex(int len) {
	// do not update CurrentTerm
	bool newline = std::string(yytext) == "\n";
	if (newline) {
		get_tokenizer_state().parse_line++;
		get_tokenizer_state().parse_pos += len; get_tokenizer_state().line_pos = 0; get_tokenizer_state().parse_len = len;
	}
	else {
		get_tokenizer_state().parse_pos += len; get_tokenizer_state().line_pos += get_tokenizer_state().parse_len; get_tokenizer_state().parse_len = len;
	}
}
static void update_flex() {
	// do not update CurrentTerm
	update_flex((int)yyleng);
}
std::string CutString(std::string::iterator & b, std::string::iterator e, bool save, char jmp = ' ');

struct FlexCondition {
	std::string trigger;
	int condition;
	std::string code;
	FlexCondition(std::string trigger, int condition) {
		this->trigger = trigger;
		this->condition = condition;
		code = "";
	}
	virtual int do_scanner(const char * text) {
		return YY_IGNORE_THIS;
	};
};

struct FlexContext {
	std::vector<FlexCondition *> conditions;
	char * iter_buff = nullptr;
	YY_BUFFER_STATE yy_buffer = nullptr;
	bool abandon = false;
};

static FlexContext & get_flex_context() {
	static FlexContext fc;
	return fc;
}
static FlexCondition * get_current_scanner() {
	return get_flex_context().conditions.back();
}
static void reset_condition() {

}
static void enter_condition(FlexCondition * fsc) {
	get_flex_context().conditions.push_back(fsc);
	BEGIN(fsc->condition);
}
static int yield_condition(int yy_token, Term term) {
	update_yylval(term);
	return yy_token;
}
static void abort_condition() {
	delete get_flex_context().conditions.back();
	get_flex_context().conditions.pop_back();
	if (get_flex_context().conditions.empty())
	{
		BEGIN(0);
	}
	else {
		BEGIN(get_flex_context().conditions.back()->condition);
	}
}
static int quit_condition(int yy_token, Term term) {
	int p = yield_condition(yy_token, term);
	abort_condition();
	return p;
}

struct FlexExternalCondition : public FlexCondition {
	int left_brackets = 0;
	int len; // len != code.size(), because of special editing like H-editing
	int in_str = 0;
	int h_editing_count = 0;
	FlexExternalCondition(std::string trigger, int condition) : FlexCondition(trigger, condition) {
		left_brackets = 0;
		len = 0;
	}
	int do_scanner(const char * text) {
		// return true to return a YYTOK
		len++;
		if (this->trigger == "format")
		{
			if (text[0] == '(' && !in_str && !h_editing_count)
			{
				left_brackets++;
				code += text;
			}
			else if (text[0] == ')' && !in_str && !h_editing_count) {
				left_brackets--;
				code += text;
				if (left_brackets == 0)
				{
					std::string result = code; 
					update_flex((int)len);
					return quit_condition(YY_FORMAT_STMT, Term{ TokenMeta::NT_FORMAT, result });
				}
			}
			else if (tolower( text[0] ) == 'h' && !in_str) {
				// h-editing
				int num_s = code.size() - 1;
				while (num_s > 0 && !(code[num_s] >= '0' && code[num_s] <= '9')) {
					num_s--;
				}
				std::string h_editing_arg = code.substr(num_s);
				//code = code.substr(0, num_s ); // remove  `xH`
				h_editing_count = std::atoi(h_editing_arg.c_str());
				code += text;
			}
			else{
				if (!h_editing_count && (text[0] == '\"' || text[0] == '\''))
				{
					/****************
					*	e.g.
					*>	"aaa'bbb"
					*	aaa'bbb is in_str
					*>	'aaa"bbb'
					*	aaa"bbb is also in_str
					*================
					*	inside a pair of quotes(either " or '), the other pair of quotes do not function as string border
					****************/
					if (in_str == text[0])
					{

						in_str = 0;
					}
					else if(in_str == 0)
					{
						in_str = text[0];
					}
				}
				else if(text[0] == '\n')
				{
					get_tokenizer_state().parse_line++;
				}
				if (h_editing_count >0)
				{
					h_editing_count--;
				}
				code += text;
			}
		}
		else
		{
			code += text;
		}
		return YY_IGNORE_THIS;
	}
};

struct FlexLabelEndCondition : public FlexCondition {
	bool end_label_hit = false;
	bool int_is_label = false;
	
	FlexLabelEndCondition(std::string trigger, int condition) : FlexCondition(trigger, condition){
		end_label_hit = false;
	}
};


int else_parse(const char * origin_yytext);
int comment_parse(const char * origin_yytext);
int label_parse(const char * origin_yytext);
int literal_parse(const char * origin_yytext, TokenMeta_T token, int yytoken);
int nop_parse();
int crlf_parse(const char * origin_yytext);
int operator_parse(const char * origin_yytext, TokenMeta_T token, int yytoken);
static int word_parse(const char * origin_yytext);

#define DORET(YYTOKEN) if(YYTOKEN == YY_IGNORE_THIS){/* do not return */}else{ return YYTOKEN; }

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
integral {digits}(_{kind_param})?
starter({letter}|_)
wordname {starter}({starter}|{digit})*
wordoperator \.{wordname}\.
word ({wordname}|{wordoperator})
string1 \"(\\.|[^"])*\"
string2 \'(\\.|[^'])*\'
string ({string1}|{string2})

%%

<external_scanner,jump_to_scanner>{newline} {
	// this rule is essential or `\n` will br left out intentionally
	int p = get_current_scanner()->do_scanner(yytext);
	DORET(p)
}
<external_scanner,jump_to_scanner>. { 
	int p = get_current_scanner()->do_scanner(yytext);
	DORET(p)
}

^[Cc]{delim}*[^\r\n]* {
	int p = comment_parse(yytext);
	update_flex();
	DORET(p);
}
![^\r\n]* {
	int p = comment_parse(yytext);
	update_flex();
	DORET(p);
}

{newline}([ ][ ][ ][ ][ ])({digit}|[*#&]) {
	// continuation line
	// {newline}{ws}\*
	int p = nop_parse();
	update_flex();
	get_tokenizer_state().parse_line++;
	DORET(p);
}
{newline}\t({digit}|[*#&]) {
	// continuation line
	// THIS IS A COMPROMISE TO SOME WRONG CODE IN FORTRAN POWERED STATION
	int p = nop_parse();
	update_flex();
	get_tokenizer_state().parse_line++;
	DORET(p);
}
{newline} {
	int p = crlf_parse(yytext);
	update_flex();
	DORET(p);
}
{ws} {
	int p = nop_parse();
	update_flex();
	DORET(p);
}
<INITIAL>^{delim}*[0-9]+ {
	int p = label_parse(yytext);
	update_flex();
	DORET(p);
}
<label_end_scanner>^{delim}*[0-9]+ {
	int label_index = std::atoi(yytext);
	auto end_label_iter = get_context().end_labels.find(std::to_string(label_index));
	if (end_label_iter != get_context().end_labels.end()) {
		FlexLabelEndCondition * fec;
		bool first = true;
		while (!end_label_iter->second.empty()) {
			fec = dynamic_cast<FlexLabelEndCondition*> (get_current_scanner());
			end_label_iter->second.pop_back();
			quit_condition(YY_IGNORE_THIS, Term{ TokenMeta::Nop, "" });
			get_tokenizer_context().terminal_cache_line.push_back(std::make_tuple(YY_ENDDO, Term{ TokenMeta::RBrace, std::string("enddo") }));
		}
		update_flex();
		DORET(YY_IGNORE_THIS);
	}
	else {
		int p = label_parse(yytext);
		update_flex();
		DORET(p);
	}
}

{integral} { 
	int p = literal_parse(yytext, TokenMeta::META_INTEGER, YY_INTEGER);
	update_flex();
	DORET(p)
}
{floating} {
	/****************
	*	narrow_floating is of rule
	*	```
	*	narrow_floating{ digits }\.
	*	```
	* It will conflict with keywords begins with dot"." such as `.and.`
	****************/

	/****************
	{narrow_floating} {

	int p = literal_parse(yytext, TokenMeta::META_REAL, YY_FLOAT);
	update_flex();
	DORET(p)
	}
	****************/
	int p = literal_parse(yytext, TokenMeta::META_REAL, YY_FLOAT);
	update_flex();
	DORET(p)
}
{floating}_[-+]?{floating} {
	int p = literal_parse(yytext, TokenMeta::META_COMPLEX, YY_COMPLEX);
	update_flex();
	DORET(p)
}
{string} {
	/* The delimiting quotes are escaped because they are Flex meta-characters. */
	int p = literal_parse(yytext, TokenMeta::META_STRING, YY_STRING);
	update_flex();
	DORET(p)
}

"(/" { int p = operator_parse(yytext, TokenMeta::META_ANY, YY_ARRAYBUILDER_START);  update_flex(); DORET(p) }
"/)" { int p = operator_parse(yytext, TokenMeta::META_ANY, YY_ARRAYBUILDER_END); update_flex(); DORET(p)  }
"::" { int p = operator_parse(yytext, TokenMeta::DoubleColon, YY_DOUBLECOLON); update_flex(); DORET(p) }
"**" { int p = operator_parse(yytext, TokenMeta::Power, YY_POWER);  update_flex(); DORET(p) }
">" { int p = operator_parse(yytext, TokenMeta::GT, YY_GT);  update_flex(); DORET(p)  }
">=" { int p = operator_parse(yytext, TokenMeta::GE, YY_GE);  update_flex(); DORET(p)  }
"<" { int p = operator_parse(yytext, TokenMeta::LT, YY_LT);  update_flex(); DORET(p)  }
"<=" { int p = operator_parse(yytext, TokenMeta::LE, YY_LE);  update_flex(); DORET(p) }
"==" { int p = operator_parse(yytext, TokenMeta::EQ, YY_EQ);  update_flex(); DORET(p) }
"/=" { int p = operator_parse(yytext, TokenMeta::NEQ, YY_NEQ);  update_flex(); DORET(p)  }
"//" { int p = operator_parse(yytext, TokenMeta::Add, '+');  update_flex(); DORET(p) /* string concat */}

{word} {
	/*do not call update_yylval in this macro because some tokens need to be looked ahead, such as `else if` */
	int p = word_parse(yytext);
	// std::cout << "-----------" << yytext << std::endl;
	update_flex(); // IMPORTANT, yyleng NOT always equal to `lowercase_name.size()` because of `pre_map`
	DORET(p)
}

. {
	/* all other things, including some operators not listed */
	int p = else_parse(yytext);
	update_flex();
	DORET(p)
}

%%

int else_parse(const char * origin_yytext) {
	update_yylval(Term{ TokenMeta::META_ILLEGAL, std::string(origin_yytext) });
	return origin_yytext[0];
}
int comment_parse(const char * origin_yytext) {
	/* do not update yylval */
	get_tokenizer_context().comments.push_back(std::string(origin_yytext));
	return YY_IGNORE_THIS; /* do not return */
}
int label_parse(const char * origin_yytext) {
	// remove leading spaces
	int label_index;
	sscanf(origin_yytext, "%d", &label_index);
	update_yylval(Term{ TokenMeta::Label, std::to_string(label_index) });
	return YY_LABEL;
}
int literal_parse(const char * origin_yytext, TokenMeta_T token, int yytoken) {
	update_yylval(Term{ token, std::string(origin_yytext) });
	return yytoken;
}
int nop_parse() {
	/* do not update yylval */
	return YY_IGNORE_THIS; /* do not return */
}

int crlf_parse(const char * origin_yytext) {
	update_yylval(Term{ TokenMeta::CRLF, std::string(origin_yytext) });
	return YY_CRLF;
}

int operator_parse(const char * origin_yytext, TokenMeta_T token, int yytoken) {
	update_yylval(Term{ token, std::string(origin_yytext) });
	return yytoken;
}

static int word_parse(const char * origin_yytext) {
	using namespace std;
	/* MUST NOT call update_flex at beginning because CutString */
	const TokenizerState & fs = get_tokenizer_state();
	if (get_flex_context().abandon) {
		// Ìø¹ýÕâ¸ö×Ö·û
		get_flex_context().abandon = false;
		return YY_IGNORE_THIS;
	}
	string lowercase_name = string(origin_yytext);
	int len = (int)lowercase_name.size();
	//assert(yyleng == len);
	transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), tolower); 
FIND_CONCAT:
	if (lowercase_name == "format")
	{
		enter_condition(new FlexExternalCondition("format", external_scanner));		
		return YY_IGNORE_THIS;
	}
	else if (lowercase_name == "do") {
		std::string next = CutString(get_context().global_code.begin() + fs.parse_pos + len, get_context().global_code.end(), false);
		if (next[0] >= '0' && next[0] <= '9') {
			// label-do-stmt is [ do-construct-name : ] DO label [ loop-control ]
			get_context().end_labels[next].push_back("do");
			enter_condition(new FlexLabelEndCondition("do", label_end_scanner));
			update_yylval(Term{ TokenMeta::Do, "do" });
			return YY_DO;
		}
	}
NORMAL_CONDITION:
	TokenMeta_T tok = TokenMeta::META_WORD;
	int yytok = YY_WORD;
	auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == lowercase_name; });
	auto forward1_iter = find_if(forward1.begin(), forward1.end(), [&](const auto & x) {return x.first == lowercase_name; });
	if (keyword_iter != keywords.end() || forward1_iter != forward1.end()) {
		// if fortran keyword
		if (forward1_iter != forward1.end()) {
			// not a valid yylval
			std::string next = CutString(get_context().global_code.begin() + fs.parse_pos + len, get_context().global_code.end(), false);
			transform(next.begin(), next.end(), next.begin(), tolower);
			auto next_iter = find_if(forward1_iter->second.begin(), forward1_iter->second.end(), [&](const auto & x) {return x == next; });
			if (next_iter != forward1_iter->second.end()) {
				// concat two string
				lowercase_name += next;
				get_flex_context().abandon = true; // ignore next
				goto FIND_CONCAT;
			}
		}
		if (keyword_iter != keywords.end())
		{
			// this is another keyword
			tok = keyword_iter->token;
			yytok = keyword_iter->yytoken;
		}
		else {
			// this is just a name
			
		}
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
	int slen = (int)code.size();
	get_tokenizer_state().parse_line = 0;
	get_tokenizer_state().parse_pos = 0;
	get_tokenizer_state().parse_len = 0;
	get_tokenizer_state().line_pos = 0; 
	if (get_flex_context().iter_buff != nullptr) {
		free(get_flex_context().iter_buff); 
		get_flex_context().iter_buff = nullptr;
	}
	get_flex_context().iter_buff = (char *)malloc(slen + 2);
	// must have 2 '\0's at the end of the string
	memset(get_flex_context().iter_buff, 0, slen + 2);
	strcpy(get_flex_context().iter_buff, code.c_str());
	get_flex_context().yy_buffer = yy_scan_buffer(get_flex_context().iter_buff, slen + 2);
}
void release_buff() {
	yy_delete_buffer(get_flex_context().yy_buffer);
	free(get_flex_context().iter_buff);
	get_flex_context().iter_buff = nullptr;
}

int yywrap()
{
	return(1);
}
