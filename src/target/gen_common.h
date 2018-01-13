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


// this file includes implemetations of common functions
// IMPORTANT: this file should be and only be included by every "gen_xxx.cpp" and ".y" files
#include "codegen.h"
#include <numeric>
#include <boost/lexical_cast.hpp>

using namespace std;

// use static instead of extern will make build fast
#ifdef _DEBUG
// static is necessary, or will cause lnk
static char codegen_buf[MAX_CODE_LENGTH]; 
#else
// defined in for90.y and codegen.cpp
extern char codegen_buf[MAX_CODE_LENGTH];
#endif

/****************
* `gen_token` generate token from several or none childs by given **Term**
* Usage:
* if the node generate a invariant string, use `gen_token`, otherwise, `gen_promote`
*****************/
inline ParseNode gen_token(const Term & term) {
	// four `_pos` is set by update_pos in for90.y
	return ParseNode{ gen_flex(term), nullptr };
}
template <typename ... Args>
ParseNode gen_token(const Term & term, Args&& ... args) {
	ParseNode newnode = gen_token(term);
	newnode.addlist(std::forward<Args>(args)...);
	return newnode;
}
inline void reuse_token(ParseNode & newnode, const Term & term) {
	newnode.fs.CurrentTerm = term;
}
template <typename ... Args>
void reuse_token(ParseNode & newnode, const Term & term, Args&& ... args) {
	newnode.fs.CurrentTerm = term;
	//ParseNode * nptr[] = { ([](ParseNode & nd) {return &nd; })(args)... };
	//for (size_t i = 0; i < sizeof...(args); i++) {
	//	newnode.addpointer(nptr[i]);
	//}
	int _[] = { (newnode.addpointer(([](ParseNode & nd) {return &nd; })(args)), 0)... };
}
/****************
* `gen_reset` copies given ParseNode, and reset it's term
* Usage:
*****************/
inline ParseNode gen_reset(const ParseNode & pn, const Term & newterm) {
	ParseNode newnode = pn;
	newnode.fs.CurrentTerm = newterm;
	return newnode;
}
inline ParseNode gen_dummy() {
	return gen_token(Term{ TokenMeta::NT_DUMMY, "" });
}
/****************
* `gen_flatten` append an item to a list
*****************/
ParseNode gen_flatten(const ParseNode & item, const ParseNode & list, std::string merge_rule, TokenMeta_T merged_token_meta = TokenMeta::USE_DEFAULT_VALUE, bool left_recursion = false);
void reuse_flatten(ParseNode & newnode, ParseNode & item, ParseNode & list, std::string merge_rule, TokenMeta_T merged_token_meta = TokenMeta::USE_DEFAULT_VALUE, bool left_recursion = false);
/****************
* `gen_merge` merge two lists
*****************/
ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, TokenMeta_T merged_token_meta); 
void reuse_merge(ParseNode & newnode, ParseNode & list1, ParseNode & list2, std::string merge_rule, TokenMeta_T merged_token_meta);

template <typename Iterator, typename F>
std::string make_str_list(Iterator begin, Iterator end, F handler, std::string delim = ", ") {
	std::string r;
	for (auto i = begin; i != end; i++)
	{
		if (i != begin) {
			r += delim;
		}
		r += handler(*i);
	}
	return r;
}


/****************
* `gen_promote` is improves `gen_token` function, so you can provide a format string of merge rule
* Usage:
* if the node generate a string depend on its child by given rule, use `gen_promote`, otherwise, `gen_token`
*****************/
template <typename ... Args>
void reuse_promote(ParseNode & newnode, std::string rule, TokenMeta_T merged_token_meta, Args&& ... items) {
	sprintf(codegen_buf, rule.c_str(), [&](const ParseNode & x) {return x.get_what().c_str(); }(items)...);
	newnode.fs = gen_flex(Term{ merged_token_meta, string(codegen_buf) });
	int _[] = { (newnode.addpointer(([](ParseNode & nd) {return &nd; })(items)), 0)... };
}
template <typename ... Args>
ParseNode gen_promote(std::string rule, TokenMeta_T merged_token_meta, Args&& ... items) {
	sprintf(codegen_buf, rule.c_str(), [&](const ParseNode & x) {return x.get_what().c_str(); }(items)...);
	ParseNode newnode = gen_token(Term{ merged_token_meta, string(codegen_buf) });
	newnode.addlist(std::forward<Args>(items)...);
	return newnode;
}
template <typename Iterator1, typename Iterator2>
std::string gen_sliceinfo_str(Iterator1 x_begin, Iterator1 x_end, Iterator2 y_begin, Iterator2 y_end) {
	std::string x_str, y_str;
	x_str = make_str_list(x_begin, x_end, [&](auto x) { return x; });
	y_str = make_str_list(y_begin, y_end, [&](auto x) { return x; });
	std::sprintf(codegen_buf, "{%s}, {%s}", x_str.c_str(), y_str.c_str());
	return std::string(codegen_buf);
}

template <typename Iterator, typename Func1, typename Func2>
SliceBoundInfo get_sliceinfo_base(Iterator begin, Iterator end, Func1 get_x, Func2 get_y) {
	SliceIndexInfo x(end - begin);
	SliceIndexInfo y(end - begin);
	std::transform(begin, end, x.begin(), get_x);
	std::transform(begin, end, y.begin(), get_y);
	return std::make_tuple(x, y);
}