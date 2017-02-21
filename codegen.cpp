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
		tc.func_kwargs = func_kwargs_preset;
		tc.inited = true;
	}
	return tc;
}

void do_trans(const std::string & src) {
	get_context().global_code = src;
	parse(get_context().global_code);
	//program_tree.addchild(gen_header(), false);
	get_context().program_tree.fs.CurrentTerm.what = gen_header().fs.CurrentTerm.what + get_context().program_tree.fs.CurrentTerm.what;
}

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += get_context().program_tree.fs.CurrentTerm.what;
	return cpp_code;
}

ParseNode gen_token(Term term) {
	// four `_pos` is set by update_pos in for90.y
	return ParseNode(gen_flex(term), nullptr);
}

ParseNode gen_dummy() {
	return ParseNode(gen_flex(Term{ TokenMeta::NT_DUMMY, "" }), nullptr);
}

ParseNode gen_promote(std::string rule, int merged_token_meta, const ParseNode & lower) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, rule.c_str(), lower.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	newnode.addchild(lower); 
	return newnode;
}

ParseNode gen_promote(int merged_token_meta, const ParseNode & lower) {
	ParseNode newnode = gen_token(Term{ merged_token_meta, lower.fs.CurrentTerm.what });
	newnode.addchild(lower);
	return newnode;
}

FlexState gen_flex(Term term) {
	FlexState f;
	f.CurrentTerm = term;
	f.line_pos = f.parse_len = f.parse_line = f.parse_pos = 0;
	return f;
}

std::string tabber(std::string & src) {
	std::string newline;
	string ans = "";
	std::istringstream f(src);
	while (::getline(f, newline)) {
		ans += '\t';
		ans += newline;
		ans += '\n';
	}
	return ans;
}

ParseNode flattern_bin(const ParseNode & pn) {
	/* it cant work well because it create a whole new tree copy too much */
	/* THIS ALGORITHM FLATTERNS A RIGHT-RECURSIVE BINARY TREE */
	if (pn.child.size() == 2) {
		ParseNode newp = ParseNode();
		/* child[0] is the only data node */
		newp.addchild(pn.get(0));

		/* pn.child[1] is a **list** of ALREADY flatterned elements */
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
		for (int i = 0; i < pn.get(1).child.size(); i++)
		{
			newp.addchild(pn.get(1).get(i));
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

ParseNode flattern_bin_left(const ParseNode & pn) {
	/* it cant work well because it create a whole new tree copy too much */
	/* THIS ALGORITHM FLATTERNS A RIGHT-RECURSIVE BINARY TREE */
	if (pn.child.size() == 2) {
		ParseNode newp = ParseNode();
		/* child[0] is the only data node */

		/* pn.child[1] is a **list** of ALREADY flatterned elements */
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
		for (int i = 0; i < pn.get(0).child.size(); i++)
		{
			newp.addchild(pn.get(0).get(i));
		}

		newp.addchild(pn.get(1));
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

ParseNode gen_flattern(const ParseNode & item, const ParseNode & list, std::string merge_rule, int merged_token_meta, bool left_recursion) {
	ParseNode nn = ParseNode();
	if (left_recursion)
	{
		sprintf(codegen_buf, merge_rule.c_str(), list.fs.CurrentTerm.what.c_str(), item.fs.CurrentTerm.what.c_str());
	}
	else {
		sprintf(codegen_buf, merge_rule.c_str(), item.fs.CurrentTerm.what.c_str(), list.fs.CurrentTerm.what.c_str());
	}
	if (merged_token_meta == -1) {
		merged_token_meta = list.fs.CurrentTerm.token;
	}
	nn.fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	if (left_recursion)
	{
		nn.addchild(list); // list
		nn.addchild(item); // item
		nn = flattern_bin_left(nn);
	}
	else {
		nn.addchild(item); // item
		nn.addchild(list); // list
		nn = flattern_bin(nn);
	}
	return nn;
}


ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, int merged_token_meta) {
	ParseNode nn = ParseNode();
	sprintf(codegen_buf, merge_rule.c_str(), list1.fs.CurrentTerm.what.c_str(), list2.fs.CurrentTerm.what.c_str());
	nn.fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	for (auto i = 0; i < list1.child.size(); i++)
	{
		nn.addchild(list1.get(i));
	}
	for (auto i = 0; i < list2.child.size(); i++)
	{
		nn.addchild(list2.get(i));
	}
	return nn;
}

