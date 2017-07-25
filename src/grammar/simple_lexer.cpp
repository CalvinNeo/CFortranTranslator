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

#include <cstdio>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <memory>
#include "../target/gen_config.h"
#include "for90.tab.h"
#include "simple_lexer.h"


SimplerContext & get_simpler_context() {
	static SimplerContext sc{ "", 0 };
	return sc;
};

static bool is_name(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}
static bool is_int(char ch) {
	return ch >= '0' && ch <= '9';
}

static bool check_continuation(char & return_char) {
	return_char = 0;
	SimplerContext & sc = get_simpler_context();
	int & p = sc.pos;
	const std::string & s = sc.code;
	int new_line_p = p + 1;
	int continuation_symbol_p = -1;
	bool do_continuation = false;
	if (new_line_p + FORTRAN_CONTINUATION_SPACE < s.size())
	{
		// begin with 5 blanks(or numbers which are label, although useless)
		bool first_5 = std::accumulate(s.begin() + new_line_p, s.begin() + new_line_p + FORTRAN_CONTINUATION_SPACE, true, [](bool r, char y) {
			return r && (is_int(y) || y == ' ');
		});
		if (first_5)
		{
			continuation_symbol_p = new_line_p + FORTRAN_CONTINUATION_SPACE;
		}
	}
	if (continuation_symbol_p == -1 && new_line_p + 1 < s.size()) {
		// begin with 1 tab, this rule compromise to some wrong codes
		bool first_tab = s[new_line_p] == '\t';
		if (first_tab)
		{
			continuation_symbol_p = new_line_p + 1;
		}
	}
	if (continuation_symbol_p != -1)
	{
		do_continuation = continuation_symbol_p < s.size()
			&& s[continuation_symbol_p] != ' '
			&& s[continuation_symbol_p] != '\n'
			&& s[continuation_symbol_p] != '\t' // continuation mark can't be blank
			&& !is_name(s[continuation_symbol_p]); // continuation mark can't be alpha
		// if there's leading blanks
		if (do_continuation) {
			// `continuation_symbol_p` is a continuation mark
			p = continuation_symbol_p + 1;
			// skip leading blanks because of continuation
			return_char = s[p++];
		}
		else {
			return_char = s[p++];
		}
	}
	else {
		return_char = s[p++];
	}
	return do_continuation;
}
static char get_complete_char() {
	// TODO do not use save_pos, it will generate error parse_line
	SimplerContext & sc = get_simpler_context();
	int & p = sc.pos;
	const std::string & s = sc.code;
	int old_p = p;
	char return_char = 0;
	if (p >= s.size())
	{
		goto RETURN_CHAR;
	}

	if (s[p] == '\n')
	{
		// `new_line_p` is the first character of next line
		if (check_continuation(return_char)) {
		}
		get_tokenizer_state().parse_line++;
		//printf("-1---%d---%s---: %s\n", get_tokenizer_state().parse_line, sc.inStr? "T" : "F", s.substr(p, 40).c_str());
		sc.inStr = 0;
		sc.label_border = FORTRAN_CONTINUATION_SPACE + 1;
		sc.crlf_marker = true;
	}
	else if (!sc.in_format_stmt && !sc.inStr && ( (s[p] == '!') || (sc.crlf_marker && (s[p] == 'c' || s[p] == 'C')))) {
		std::string comment_str;
		while (p < s.size() && s[p] != '\n') {
			comment_str += s[p];
			p++;
		}
		// now s[p] == '\n'
		if (check_continuation(return_char)) {
		}
		get_tokenizer_state().parse_line++;
		//printf("-2---%d---%s---: %s\n", get_tokenizer_state().parse_line, sc.inStr ? "T" : "F", s.substr(p, 40).c_str());
		get_tokenizer_context().comments.push_back(comment_str);
		sc.inStr = 0;
		sc.label_border = FORTRAN_CONTINUATION_SPACE + 1;
		sc.crlf_marker = true;
	}
	else if (s[p] == ' ' || is_int(s[p]))
	{
		if (sc.label_border > 0)
		{
			// among the label region
			sc.label_border--;
		}
		return_char = s[p++];
		sc.crlf_marker = false;
	}
	else {
		// TODO must exclude format-stmt
		if (!sc.in_format_stmt)
		{
			if (s[p] == '\'' || s[p] == '\"')
			{
				if (sc.inStr && s[p] == sc.inStr)
				{
					sc.inStr = 0;
				}
				else if (!sc.inStr) {
					sc.inStr = s[p];
				}
			}
		}
		sc.label_border = 0;
		return_char = s[p++];
		sc.crlf_marker = false;
	}
RETURN_CHAR:
	return return_char;
}
static char pull_complete_char() {
	SimplerContext & sc = get_simpler_context(); 
	if (!sc.item_cache.empty())
	{
		for (int i = 0; i < sc.item_cache.size(); i++) {
			std::string & s = sc.item_cache[i];
			for (auto s_iter = s.rbegin(); s_iter < s.rend(); s_iter++)
			{
				sc.char_cache.push_back(*s_iter);
			}
		}
		sc.item_cache.clear();
	}
	if (!sc.char_cache.empty())
	{
		char ch = sc.char_cache.back();
		sc.char_cache.pop_back();
		return ch;
	}
	else {
		return get_complete_char();
	}
}
static void store_complete_char(char ch) {
	SimplerContext & sc = get_simpler_context();
	sc.char_cache.push_back(ch);
}

static bool next_item(std::string & res) {
	/****************
	*	
	****************/
	char ch2;
	res = "";
	SimplerContext & sc = get_simpler_context();
	if (!sc.item_cache.empty())
	{
		res = sc.item_cache.back();
		sc.item_cache.pop_back();
		return true;
	}
	char ch = pull_complete_char();
	if (ch == 0)
	{
		return false;
	}
	if (is_int(ch)) {
		res += ch;
		if (sc.label_border > 0)
		{
			bool islabel = true;
			while (sc.label_border > 0)
			{
				ch = pull_complete_char();
				if (!is_int(ch) && ch != ' ' && ch != '\t')
				{
					islabel = false;
					store_complete_char(ch);
					break;
				}
				else if (ch == '\t')
				{
					// a tab means previous end of label region(according to somee non-standard codes)
					store_complete_char(ch);
					break;
				}
				else {
					res += ch;
				}
			}
			if (islabel)
			{
				// label
				int label_index = std::atoi(res.c_str()); // in order to strip space
				res = ":" + std::to_string(label_index);

			}
			else {
				// int

			}
		}
		else {
			// int
			while (true) {
				ch = pull_complete_char();
				if (is_int(ch))
				{
					res += ch;
				}
				else {
					store_complete_char(ch);
					break;
				}
			}
		}
	}
	else if (is_name(ch)) {
		res += ch;
		while (true) {
			ch = pull_complete_char();
			if (is_name(ch) || is_int(ch))
			{
				res += ch;
			}
			else {
				store_complete_char(ch);
				break;
			}
		}
	}
	else if (ch == '.')
	{
		/****************
		* maybe operator or floating's trailing dot
		* if handled in .y
		* refer rule exp : '.' operator '.'
		*       rule operator : '.' YY_WORD '.'
		*       rule literal : '.' YY_INTEGER
		*       rule literal : YY_INTEGER '.'
		* however it will cause shift-reduce conflict
		*================
		* now handled in `simpler_yylex`
		****************/
		res += ch;
	}
	else if (ch == '(') {
		res += ch;
		ch2 = pull_complete_char();
		// (/
		if (ch2 == '/')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == ':')
	{
		res += ch;
		ch2 = pull_complete_char();
		// ::
		if (ch2 == ':')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '*')
	{
		res += ch;
		ch2 = pull_complete_char();
		// "**"
		if (ch2 == '*')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '/')
	{
		res += ch;
		ch2 = pull_complete_char();
		// "/)", "//", "/="
		if (ch2 == ')' || ch2 == '/' || ch2 == '=')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '<')
	{
		res += ch;
		ch2 = pull_complete_char();
		// "<="
		if (ch2 == '=')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '>')
	{
		res += ch;
		ch2 = pull_complete_char();
		// ">="
		if (ch2 == '=')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '=')
	{
		res += ch;
		ch2 = pull_complete_char();
		// "=="
		if (ch2 == '=')
		{
			res += ch2;
		}
		else {
			store_complete_char(ch2);
		}
	}
	else if (ch == '\n')
	{
		// must check the next line
		res += ch;
	}
	else {
		res += ch;
	}
	return true;
}

static bool next_nonblank_item(std::string & res) {
	std::string cur;
	while (next_item(cur)) {
		if (cur == " " || cur == "\t")
		{
			continue;
		}
		else {
			break;
		}
	}
	res = cur;
	if (cur == "")
	{
		return false;
	}
	else {
		return true;
	}
}

template<typename T, typename R>
static bool is_within(const T & x, const typename std::vector<R> & vec) {
	return std::accumulate(vec.begin(), vec.end(), false, [&](bool b, const R & y ) {
		return b || (x == y);
	});
}

static void update_flex(const std::string & cur) {
	// do not update CurrentTerm
	SimplerContext & sc = get_simpler_context();
	bool newline = cur == "\n";
	int cur_len = (int)cur.size();
	if (newline) {
		get_tokenizer_state().parse_pos = sc.pos - cur_len;
		get_tokenizer_state().line_pos = 0; 
		get_tokenizer_state().parse_len = cur_len;
	}
	else {
		// when encountering continuation, parse_pos may not be accurate
		get_tokenizer_state().parse_pos = sc.pos - cur_len;
		// must update line_pos before parse_len
		get_tokenizer_state().line_pos += get_tokenizer_state().parse_len; // cumulative
		get_tokenizer_state().parse_len = cur_len;
	}
}

static bool check_frac(const std::string & cur, std::string & res) {
	/****************
	*	if floating: return true
	*	if int or else: return false
	****************/
	std::string cur2;
	if (cur == ".")
	{
		// starting with `.`
		// floating with only frac part
		next_nonblank_item(cur2);
		bool all_digit = std::accumulate(cur2.begin(), cur2.end(), true, [](bool b, char x) {
			return b && (is_int(x));
		});
		if (all_digit)
		{
			// float
			res = "0." + cur2;
			return true;
		}
		else {
			// not float, maybe operator or error
			res = ".";
			get_simpler_context().item_cache.push_back(cur2);
			return false;
		}
	}
	else {
		// floating with integral part
		next_nonblank_item(cur2);
		if (cur2 == ".")
		{
			next_nonblank_item(cur2);
			bool all_digit = std::accumulate(cur2.begin(), cur2.end(), true, [](bool b, char x) {
				return b && (is_int(x));
			});
			bool all_alpha = std::accumulate(cur2.begin(), cur2.end(), true, [](bool b, char x) {
				return b && (is_name(x));
			});
			// if all digit
			if (all_digit) {
				// float, definitely
				res = cur + "." + cur2;
				return true;
			}
			else if (cur2 == ".")
			{
				// if two continuous `.`, the later `.` must belong to a operator
				// e.g. `2..gt.3`
				res = cur + ".0" ;
				get_simpler_context().item_cache.push_back(cur2);
				return true;
			}
			else if (all_alpha)
			{
				// operator
				// ref.R311, operator name should have no digits
				// e.g. `2.e2.0` is float, not a operator `e2` with two operands `2` and `0`
				res = cur;
				get_simpler_context().item_cache.push_back(cur2);
				get_simpler_context().item_cache.push_back(".");
				return false;
			}
			else {
				// float without frac part
				// e.g. `2.`, `1.`, polish it to `2.0`, `1.0`
				res = cur + ".0";
				get_simpler_context().item_cache.push_back(cur2);
				return true;
			}
		}
		else {
			res = cur;
			get_simpler_context().item_cache.push_back(cur2);
			return false;
		}
	}
}


static bool check_expo(const std::string & pre, std::string & res) {
	SimplerContext & sc = get_simpler_context();
	std::string cur, cur2;
	bool flag;
	//R416 exponent is signed - digit - string
	//A real literal constant without a kind type parameter is a default real constant if it is without an exponent part or
	//	has exponent letter E, and is a double precision real constant if it has exponent letter D.
	res = pre;
	char exp_mark = pull_complete_char();
	if (is_within(exp_mark, std::vector<char>{ 'E', 'e', 'D', 'd'}))
	{
		next_nonblank_item(cur);
		if (is_int(cur[0]))
		{
			bool is_fl = check_frac(cur, cur2);
			res += "e";
			res += cur2;
			flag = true;
		}
		else if (cur[0] == '.')
		{
			bool is_fl = check_frac(".", cur2);
			res += "e";
			res += cur2;
			flag = true;
		}
		else {
			fatal_error("Tokenizer error: incompelete exponent");
			flag = false;
		}
	}
	else {
		// this can cause error, must push to the front of queue, not back
		store_complete_char(exp_mark);
		flag = false;
	}
	return flag;
}

static void check_keyword(const std::string name, std::function<void(const KeywordMeta &, const std::string &)> keyword_handler
	, std::function<void(const std::string &)> non_keyword_handler) {
	SimplerContext & sc = get_simpler_context();
	std::string lowercase_name = name;
	std::transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), tolower);
	CHECK_CONCATED_WORD:
	auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const KeywordMeta & x) {return x.what == lowercase_name; });
	auto forward1_iter = find_if(forward1.begin(), forward1.end(), [&](const auto & x) {return x.first == lowercase_name; });
	if (forward1_iter != forward1.end()) {
		// if this token can be concated
		std::string next_token;
		next_nonblank_item(next_token);
		std::transform(next_token.begin(), next_token.end(), next_token.begin(), tolower);
		auto next_iter = find_if(forward1_iter->second.begin(), forward1_iter->second.end(), [&](const std::string & x) {return x == next_token; });
		if (next_iter != forward1_iter->second.end()) {
			// if this token can be concated exactly with `next`
			lowercase_name += next_token;
			goto CHECK_CONCATED_WORD;
		}
		else {
			sc.item_cache.push_back(next_token);
		}
	}
	if (pre_map.find(lowercase_name) != pre_map.end()) {
		// replace according to tokenizer.cpp
		lowercase_name = pre_map.at(lowercase_name);
	}
	if (keyword_iter != keywords.end())
	{
		// this is a keyword
		keyword_handler(*keyword_iter, lowercase_name);
	}
	else {
		// this is not a keyword
		non_keyword_handler(lowercase_name);
	}
}

int simpler_yylex(void) {
	/****************
	*	bison calls this function directly
	*	pure_yylex is flex's generated function, by `#define YY_DECL int pure_yylex(void)`
	****************/
	SimplerContext & sc = get_simpler_context();
	std::string cur;
	int return_token; 
	Term return_term;
NOP_REPEAT:
	if (next_item(cur))
	{
		if(is_int(cur[0])) {
			// int or float
			std::string cur2, res;
			check_frac(cur, cur2);
			res += cur2;
			bool is_fl = check_expo(res, cur2);
			if (is_fl)
			{
				return_term = Term{ TokenMeta::Float, cur2 };
				return_token = YY_FLOAT;
			}
			else {
				return_term = Term{ TokenMeta::Int, res };
				return_token = YY_INTEGER;
			}
		}
		else if (is_name(cur[0]) || (cur.size() > 1 && cur[0] == '.' && is_name(cur[1]))) {
			std::string lowercase_name = cur;
			transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), tolower);
		FIND_CONCAT:
			if (lowercase_name == "format")
			{
				int left_brackets = 0;
				int len = 0; // len != code.size(), because of special editing like H-editing
				int in_str = 0;
				int h_editing_count = 0;
				char ch;
				sc.in_format_stmt = true;
				cur = ""; // clear `cur` which is now "format"
				while (ch = pull_complete_char()) {
					if (ch == 0)
					{
						break;
					}
					else if (ch == '(' && !in_str && !h_editing_count)
					{
						left_brackets++;
						cur += ch;
					}
					else if (ch == ')' && !in_str && !h_editing_count) {
						left_brackets--;
						cur += ch;
						if (left_brackets == 0)
						{
							return_term = Term{ TokenMeta::NT_FORMAT, cur };
							return_token = YY_FORMAT_STMT;
							sc.in_format_stmt = false;
							break;
						}
					}
					else if (tolower(ch) == 'h' && !in_str && !h_editing_count) {
						// h-editing
						int num_s = (int)cur.size() - 1;
						while (num_s > 0 && !(cur[num_s] >= '0' && cur[num_s] <= '9')) {
							num_s--;
						}
						std::string h_editing_arg = cur.substr(num_s);
						h_editing_count = std::atoi(h_editing_arg.c_str());
						cur += ch;
					}
					else {
						if (!h_editing_count && (ch == '\"' || ch == '\''))
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
							if (in_str == ch)
							{

								in_str = 0;
							}
							else if (in_str == 0)
							{
								in_str = ch;
							}
						}
						else if (ch == '\n')
						{
							// get_tokenizer_state().parse_line++;
						}
						if (h_editing_count >0)
						{
							h_editing_count--;
						}
						cur += ch;
					}
				}

			}
			else if (lowercase_name == "do") {
				// label-do-stmt is [ do-construct-name : ] DO label [ loop-control ]
				std::string cur2;
				next_nonblank_item(cur2);
				if (is_int(cur2[0])) {
					get_context().end_labels[cur2].push_back("do");
				}
				else {
					sc.item_cache.push_back(cur2);
				}
				return_term = Term{ TokenMeta::Do, "do" };
				return_token = YY_DO;
			}
			else {
				// YY_WORD
				check_keyword(cur, [&](const KeywordMeta & kinfo, const std::string & actual_name) {
					// this is a keyword
					return_term = Term{ kinfo.token, actual_name };
					return_token = kinfo.yytoken;
				}, [&](const std::string & actual_name) {
					// this is just a name
					return_term = Term{ TokenMeta::META_WORD, actual_name };
					return_token = YY_WORD;
				});
			}
		}
		else if (cur == ".") {
			std::string res;
			bool is_fl = check_frac(".", res);
			if (is_fl)
			{
				check_expo(res, res);
				return_term = Term{ TokenMeta::Float, res };
				return_token = YY_FLOAT;
			} 
			else {
				res = cur; // res = `.`
				next_nonblank_item(cur);
				if (is_name(cur[0])) {
					// operator
					res += cur;
					next_nonblank_item(cur);
					assert(cur == ".");
					res += cur;
					check_keyword(res, [&](const KeywordMeta & kinfo, const std::string & actual_name) {
						// this is a keyword
						return_term = Term{ kinfo.token, actual_name };
						return_token = kinfo.yytoken;
					}, [&](const std::string & actual_name) {
						return_term = Term{ TokenMeta::NT_DEFINED_OPERATOR, actual_name };
						return_token = YY_OPERATOR;
					});
				}
				else {
					// just dot `.`
					sc.item_cache.push_back(cur);
					return_term = Term{ TokenMeta::Dot, "." };
					return_token = '.';
				}
			} 
		}
		else if (cur == "\n") {
			return_term = Term{ TokenMeta::CRLF, "\n" };
			return_token = YY_CRLF;
		}
		else if (cur == "\"" || cur == "\'")
		{
			char ch;
			while (ch = pull_complete_char())
			{
				cur += ch;
				if (ch == cur[0])
				{
					break;
				}
			}
			return_term = Term{ TokenMeta::String, "\"" + cur.substr(1, cur.size()  - 2)+ "\"" };
			return_token = YY_STRING;
		}
		else if (cur == "!") {
			// this will not happen, because comments are handled in `get_complete_char`
			return_term = Term{ TokenMeta::CRLF, "\n" };
			return_token = YY_CRLF;
		}
		else if (cur == " " || cur == "\t")
		{
			// continuation is handled in get_complete_char
			goto NOP_REPEAT;
		}
		else if (cur.size() > 1 && cur[0] == ':' && cur[1] != ':') {
			// label
			std::string label_name = cur.substr(1, cur.size() - 1);
			auto end_label_iter = get_context().end_labels.find(label_name);
			if (end_label_iter != get_context().end_labels.end()) {
				bool first = true;
				while (!end_label_iter->second.empty()) {
					end_label_iter->second.pop_back();
					get_tokenizer_context().terminal_cache_line.push_back(std::make_tuple(YY_ENDDO, Term{ TokenMeta::RBrace, std::string("enddo") }));
				}
			}
			// remove the leading `:`
			return_term = Term{ TokenMeta::Label, cur.substr(1, cur.size() - 1) };
			return_token = YY_LABEL;
		}
		else {
			// if may be non-word keywords
			auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == cur; });
			if (keyword_iter != keywords.end())
			{
				// this is a keyword
				return_term = Term{ keyword_iter->token, cur };
				return_token = keyword_iter->yytoken;
			}
			else {
				return_term = Term{ TokenMeta::META_ANY, cur };
				return_token = cur[0];
			}
		}
		update_flex(return_term.what);
		update_yylval(return_term);
		return return_token;
	}
	else {
		// refer yywrap
		return 0;
	}
}