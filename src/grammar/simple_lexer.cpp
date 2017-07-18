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
#include <queue>
#include "../parser/tokenizer.h"
#include "../parser/parser.h"
#include "../parser/context.h"
#include "../target/gen_config.h"
#include "../grammar/for90.tab.h"

struct SimplerContext {
	std::string code;
	int pos;
	std::queue < std::string > cache;
	SimplerContext(const std::string & _code, int p) : code(_code), pos(p) {

	}
};

SimplerContext & get_simpler_context() {
	static SimplerContext sc{"", 0};
	return sc;
}

static bool next_match(const std::string s, const std::string & pat, int & p, bool save_pos = true) {
	if (p + pat.size() <= s.size() && s.substr(p, pat.size()) == pat)
	{
		if (save_pos)
		{
			p += pat.size();
		}
		return true;
	}
	else {
		return false;
	}
}
static bool next_match(const std::string s, const std::vector<std::string> & pats, int & p, bool save_pos = true) {
	/****************
	*	math the LONGGEST pattern string in `pats`
	*   TODO: this code CAN be optimized, because pats.size() is usually small, so we just use the UN-OPTIMIZED code
	****************/
	int matched_index = -1;
	for (int i = 0; i < pats.size(); i++)
	{
		const std::string & pat = pats[i];
		if (p + pat.size() <= s.size() && s.substr(p, pat.size()) == pat)
		{
			if (matched_index != -1 && pats[matched_index].size() < pat.size())
			{
				matched_index = i;
			}
		}
	}
	if (matched_index == -1)
	{
		return false;
	}
	else {
		if (save_pos)
		{
			p += pats[matched_index].size();
		}
		return true;
	}
}

static bool next_match(const std::string & s, std::function<bool(char)> f, int & p, bool save_pos = true) {
	int pp = p;
	bool flag = false;
	while (pp < s.size() && f(s[pp])) {
		pp++;
		flag = true;
	}
	if (save_pos)
	{
		p = pp;
	}
	return flag;
}
static bool is_name(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}
static bool is_int(char ch) {
	return ch >= '0' && ch <= '9';
}
#define FORTRAN_CONTINUATION_SPACE 5
static char get_complete_char(const std::string & s, int & p) {
	if (p < s.size())
	{
		if (s[p] == '\n')
		{
			int new_line_p = p + 1;
			int continuation_symbol_p = -1;
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
			else if (new_line_p < s.size()) {
				// begin with 1 tab, this rule compromise to some wrong codes
				bool first_tab = s[new_line_p] == '\t';
				if (first_tab)
				{
					continuation_symbol_p = new_line_p + 1;
				}
			}
			if (continuation_symbol_p != -1)
			{
				// if there's leading blanks
				if (continuation_symbol_p < s.size()
					&& s[continuation_symbol_p] != ' ' // continuation mark can't be blank
					&& !is_name(s[continuation_symbol_p]) // continuation mark can't be alpha
				) {
					// if there's continuation mark
					get_flex_state().parse_line++;
					p = continuation_symbol_p + 1;
					return s[continuation_symbol_p];
				}
				else {
					p++;
					return s[p];
				}
			}
			else {
				p++;
				return s[p];
			}
		}
		return s[p];
	}
	else {
		return 0;
	}
}
static bool next_item(const std::string & s, int & p, std::string & res) {
	/****************
	*	
	****************/
	int st = p;
	if (p >= s.size())
	{
		res = "";
		return false;
	}
	else {
		if (is_int(s[p])) {
			next_match(s, is_int, p);
			res = s.substr(st, p - st);
			return true;
		}
		else if (is_name(s[p])) {
			next_match(s, is_name, p);
			res = s.substr(st, p - st);
			return true;
		}
		else if (s[p] == '.')
		{
			// maybe operator or floating's trailing dot
			int kind = 0;
			if (p + 1 < s.size()) {
				if (is_int(s[p + 1]))
				{
					// floating
					p++;
					next_match(s, is_int, p);
				}
				else if (is_name(s[p + 1]))
				{
					// operator
					p++;
					next_match(s, is_name, p);
					if (s[p] != '.')
					{
						print_error("Tokenizer error: incompelete operator");
					}
				}
			}
			res = s.substr(st, p - st);
			return true;
		}
		else if (next_match(s, { "(/", "/)", "::", "**", ">", ">=", "<", "<=", "==", "/=", "//" }, p))
		{
			res = s.substr(st, p - st);
			return true;
		}
		else if (next_match(s, "\n", p))
		{
			// must check the next line
			res = s[p];
			p++;
			return true;
		}
		else {
			res = s[p];
			p++;
			return true;
		}
	}
	res = "";
	return false;
}

template<typename T, typename R>
bool is_within(const T & x, const std::vector<R> & vec) {
	std::accumulate(vec.begin(), vec.end(), false, [&](bool b, const R & y ) {
		return b || (x == y);
	});
}

int simpler_yylex(void) {
	/****************
	*	bison calls this function directly
	*	pure_yylex is flex's generated function, by `#define YY_DECL int pure_yylex(void)`
	****************/
	SimplerContext & sc = get_simpler_context();
	int p = sc.pos;
	std::string cur;
	std::queue < std::string > & cache = sc.cache;
	std::vector < std::string > parse_statck;
	while (next_item(sc.code, p, cur))
	{
		if(is_int(cur[0]) || (cur.size() > 1 && cur[0] == '.' && is_int(cur[1]))) {
			//R416 exponent is signed - digit - string
			//A real literal constant without a kind type parameter is a default real constant if it is without an exponent part or
			//	has exponent letter E, and is a double precision real constant if it has exponent letter D.
			parse_statck.push_back(cur);
			if (next_item(sc.code, p, cur))
			{
				if (is_within(cur, std::vector<std::string>{ "D" , "d", "E", "e"})) {
					// floating
					std::string floating_str = parse_statck.back() + "e" + cur;
				}
				else {
					// else
					cache.push(cur);
					//update_yylval();
					//update_flex();
					return YY_INTEGER;
				}
			}
		}
		else if (is_name(cur[0])) {

		}
		else if (cur == ".") {

		}
		else if (cur == "\n") {

		}
		else if (cur == "\"")
		{

		}
		else if (cur == "\'")
		{

		}
	}
	return 0;
}