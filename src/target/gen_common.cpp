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
#include "gen_common.h"
#include <iostream>
#include <sstream>
#include <array>

#ifndef _DEBUG
char codegen_buf[MAX_CODE_LENGTH];
#endif

TranslateContext & get_context() {
	static TranslateContext tc;
	if (tc.inited == false)
	{
		tc.func_kwargs = sysfunc_args;
		tc.inited = true;
	}
	return tc;
}

void do_trans(const std::string & src) {
	get_context().global_code = src;
	reset_parser();
	parse(get_context().global_code);
	get_context().program_tree.get_what() = gen_header().to_string() + get_context().program_tree.to_string();
}

ParseNode flatten_bin(const ParseNode & pn, bool recursion_direction_right) {
	// it's DEPRECATED because it create a whole new tree
	// THIS ALGORITHM FLATTERNS A LEFT/RIGHT-RECURSIVE BINARY TREE
	ParseNode newp = ParseNode{pn};
	flatten_bin_inplace(newp, recursion_direction_right);
	return newp;
}

void flatten_bin_inplace(ParseNode & pn, bool recursion_direction_right) {
	if (pn.length() == 2) {
		ParseNode * list, * item;
		if (recursion_direction_right)
		{
			list = &pn.get(1);
			item = &pn.get(0);
		}
		else {
			list = &pn.get(0);
			item = &pn.get(1);
		}
		pn.child.clear();
		if (recursion_direction_right)
		{
			// pn.child[1] is a **list** of ALREADY flattened elements
			// child[0] is 1 
			// child[1] is [2, 3, 4, 5]
			pn.child.push_back(item);
		}
		for (int i = 0; i < list->length(); i++)
		{
			// pn.child[0] is a **list** of ALREADY flattened elements 
			// child[0] is [2, 3, 4, 5]
			// child[1] is 1 
			pn.child.push_back(&list->get(i));
		}
		list->child.clear(); // must clear child vector or list will delete it's child recursively in its dtor
		delete list; // all list's child is now pn's child, so list is useless
		// don't delete item because it's add to pn directly
		if (!recursion_direction_right)
		{
			pn.child.push_back(item);
		}
		// pn.child[1] is a **list** of ALREADY flattened elements
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
	}
	else {
		return;
	}
}


ParseNode gen_flatten(const ParseNode & item, const ParseNode & list, std::string merge_rule, TokenMeta_T merged_token_meta, bool left_recursion) {
	ParseNode newnode{};
	reuse_flatten(newnode, *new ParseNode(item), *new ParseNode(list), merge_rule, merged_token_meta, left_recursion);
	return newnode;
}

void reuse_flatten(ParseNode & newnode, ParseNode & item, ParseNode & list, std::string merge_rule, TokenMeta_T merged_token_meta, bool left_recursion) {
	// make fs
	if (left_recursion)
	{
		sprintf(codegen_buf, merge_rule.c_str(), list.to_string().c_str(), item.to_string().c_str());
		newnode.fs.line_pos = list.fs.line_pos;
		newnode.fs.parse_pos = list.fs.parse_pos;
	}
	else {
		sprintf(codegen_buf, merge_rule.c_str(), item.to_string().c_str(), list.to_string().c_str());
		newnode.fs.line_pos = item.fs.line_pos;
		newnode.fs.parse_pos = item.fs.parse_pos;
	}
	if (merged_token_meta == TokenMeta::USE_DEFAULT_VALUE) {
		merged_token_meta = list.get_token();
	}
	newnode.fs = gen_flex(Term{ merged_token_meta, string(codegen_buf) });
	newnode.fs.parse_line = item.fs.parse_line;
	newnode.fs.parse_len = item.fs.parse_len + list.fs.parse_len;
	if (left_recursion)
	{
		newnode.addpointer(&list);
		newnode.addpointer(&item);
	}
	else {
		newnode.addpointer(&item);
		newnode.addpointer(&list);
	}
	// do inplace flatten on new node
	if (left_recursion)
	{
		flatten_bin_inplace(newnode, false);
	}
	else {
		flatten_bin_inplace(newnode, true);
	}
}

ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, TokenMeta_T merged_token_meta) {
	ParseNode newnode{};
	reuse_merge(newnode, *new ParseNode(list1), *new ParseNode(list2), merge_rule, merged_token_meta);
	return newnode;
}

void reuse_merge(ParseNode & newnode, ParseNode & list1, ParseNode & list2, std::string merge_rule, TokenMeta_T merged_token_meta) {
	sprintf(codegen_buf, merge_rule.c_str(), list1.to_string().c_str(), list2.to_string().c_str());
	newnode.fs = gen_flex(Term{ merged_token_meta, string(codegen_buf) });
	for (int i = 0; i < list1.length(); i++)
	{
		newnode.addpointer(&list1.get(i));
	}	
	for (int i = 0; i < list2.length(); i++)
	{
		newnode.addpointer(&list2.get(i));
	}
}