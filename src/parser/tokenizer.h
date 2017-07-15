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
#pragma once
#include <string>
#include <map>
#include <vector>
#include "Intent.h"


struct Term {
	TokenMeta_T token;
	std::string what;
};


#define USE_YACC

struct FlexState {
	// ´Ê·¨·ÖÎö
	Term CurrentTerm;
	int parse_pos = 0;
	int parse_line = 0;
	int parse_len = 0;
	int line_pos = 0;
	bool isnull = false;
};
FlexState & get_flex_state();

struct FlexContext {
	// return immediately
	std::vector<std::tuple<int, Term>> terminal_cache;
	// return after the whole line ends
	std::vector<std::tuple<int, Term>> terminal_cache_line;
	std::vector<std::string> comments;
};
FlexContext & get_flex_context();

extern const std::vector<KeywordMeta> keywords;
extern const std::map<std::string, std::vector<std::string> > forward1;

// because we use yacc, so this is not necessary
//FlexState next_token(const std::string & in_str, int start = 0); 
//FlexState iter_token(const std::string & in_str, int start);
std::string CutString(std::string::iterator & b, std::string::iterator e, bool save, char jmp = ' ');

int pure_yylex(void);
int yylex(void);

// for90.l
#include <stdint.h>

