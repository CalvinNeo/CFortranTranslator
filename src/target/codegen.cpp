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

ParseNode gen_dummy() {
	return gen_token(Term{ TokenMeta::NT_DUMMY, "" });
}

TokenizerState gen_flex(Term term) {
	TokenizerState f;
	f.CurrentTerm = term;
	f.line_pos = f.parse_len = f.parse_line = f.parse_pos = 0;
	return f;
}

ParseNode flattern_bin(ARG_IN pn, bool recursion_direction_right) {
	// it cant work well because it create a whole new tree copy too much 
	// THIS ALGORITHM FLATTERNS A LEFT/RIGHT-RECURSIVE BINARY TREE
	if (pn.length() == 2) {
		ParseNode newp = ParseNode();
		// child[0] is the only data node
		if (recursion_direction_right)
		{
			// pn.child[1] is a **list** of ALREADY flatterned elements
			// child[0] is 1 
			// child[1] is [2, 3, 4, 5]
			newp.addchild(pn.get(0));
			for (int i = 0; i < pn.get(1).length(); i++)
			{
				newp.addchild(pn.get(1).get(i));
			}
		}
		else {
			// pn.child[0] is a **list** of ALREADY flatterned elements 
			// child[0] is [2, 3, 4, 5]
			// child[1] is 1 
			for (int i = 0; i < pn.get(0).length(); i++)
			{
				newp.addchild(pn.get(0).get(i));
			}
			newp.addchild(pn.get(1));
		}
		newp.fs = pn.fs;
		newp.father = pn.father;
		if (pn.attr != nullptr) {
			newp.setattr(pn.attr->clone());
		}
		return newp;
	}
	else {
		return pn;
	}
}

void flattern_bin_inplace(ParseNode & pn, bool recursion_direction_right) {
	if (pn.length() == 2) {
		ParseNode * list, *item;
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
			pn.child.push_back(item);
		}
		for (int i = 0; i < list->length(); i++)
		{
			pn.child.push_back(&list->get(i));
		}
		list->child.clear(); // must clear child vector or list will delete it's child recursively in its dtor
		delete list; // all list's child is now pn's child, so list is useless
		// don't delete item because it's add to pn directly
		if (!recursion_direction_right)
		{
			pn.child.push_back(item);
		}
		// pn.child[1] is a **list** of ALREADY flatterned elements
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
	}
	else {
		return;
	}
}


ParseNode gen_flattern(ARG_IN item, ARG_IN list, std::string merge_rule, TokenMeta_T merged_token_meta, bool left_recursion) {
	 ParseNode();
	if (left_recursion)
	{
		sprintf(codegen_buf, merge_rule.c_str(), list.to_string().c_str(), item.to_string().c_str());
	}
	else {
		sprintf(codegen_buf, merge_rule.c_str(), item.to_string().c_str(), list.to_string().c_str());
	}
	if (merged_token_meta == TokenMeta::USE_DEFAULT_VALUE) {
		merged_token_meta = list.get_token();
	}
	ParseNode nn = gen_token(Term{ merged_token_meta, string(codegen_buf) });
	if (left_recursion)
	{
		nn.addlist(list, item);
		flattern_bin_inplace(nn, false);
	}
	else {
		nn.addlist(item, list);
		flattern_bin_inplace(nn, true);
	}
	return nn;
}


ParseNode gen_merge(ARG_IN list1, ARG_IN list2, std::string merge_rule, TokenMeta_T merged_token_meta) {
	sprintf(codegen_buf, merge_rule.c_str(), list1.to_string().c_str(), list2.to_string().c_str());
	ParseNode nn = gen_token(Term{ merged_token_meta, string(codegen_buf) });
	for (int i = 0; i < list1.length(); i++)
	{
		nn.addchild(list1.get(i));
	}
	for (int i = 0; i < list2.length(); i++)
	{
		nn.addchild(list2.get(i));
	}
	return nn;
}

