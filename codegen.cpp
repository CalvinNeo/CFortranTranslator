#include "gen_common.h"
#include <iostream>
#include <sstream>
#include <array>
#ifndef _DEBUG
char codegen_buf[MAX_CODE_LENGTH];
#endif

void do_trans(const std::string & src) {
	global_code = src;
	parse(global_code);
	program_tree.addchild(new ParseNode(gen_header()), false);
	string x;
	for (int i = 0; i < program_tree.child.size(); i++)
	{
		x += program_tree.child[i]->fs.CurrentTerm.what;
		x += "\n";
	}
	program_tree.fs.CurrentTerm.what = x;
}

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += program_tree.fs.CurrentTerm.what;
	return cpp_code;
}

ParseNode gen_token(Term term) {
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = term;
	return newnode;
}

ParseNode gen_dummy() {
	return ParseNode(gen_flex(Term{ TokenMeta::NT_DUMMY, "" }), nullptr);
}

ParseNode gen_promote(std::string rule, int merged_token_meta, const ParseNode & lower) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, rule.c_str(), lower.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	newnode.addchild(new ParseNode(lower)); 
	return newnode;
}

ParseNode gen_promote(int merged_token_meta, const ParseNode & lower) {
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ merged_token_meta, lower.fs.CurrentTerm.what };
	newnode.addchild(new ParseNode(lower));
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

ParseNode * flattern_bin(ParseNode * pn) {
	/* it cant work well because it create a whole noew tree copy too much */
	/* THIS ALGORITHM FLATTERNS A RIGHT-RECURSIVE BINARY TREE */
	if (pn->child.size() == 2) {
		ParseNode * newp = new ParseNode();
		/* child[0] is the only data node */
		newp->addchild(new ParseNode(*pn->child[0]));

		/* pn->child[1] is a **list** of ALREADY flatterned elements */
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
		for (int i = 0; i < pn->child[1]->child.size(); i++)
		{
			newp->addchild(new ParseNode(*pn->child[1]->child[i]));
		}
		newp->fs = pn->fs;
		newp->father = pn->father;
		if (pn->attr != nullptr) {
			newp->attr = pn->attr->clone();
		}
		delete pn;
		return newp;
	}
	else {
		return pn;
	}
}

ParseNode gen_flattern(const ParseNode & item, const ParseNode & list, std::string merge_rule, int merged_token_meta) {
	ParseNode * nn = new ParseNode();
	sprintf(codegen_buf, merge_rule.c_str(), item.fs.CurrentTerm.what.c_str(), list.fs.CurrentTerm.what.c_str());
	if (merged_token_meta == -1) {
		merged_token_meta = list.fs.CurrentTerm.token;
	}
	nn->fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	nn->addchild(new ParseNode(item)); // item
	nn->addchild(new ParseNode(list)); // list
	nn = flattern_bin(nn);
	ParseNode newnode = ParseNode(*nn);
	delete nn;
	return newnode;
}


ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, int merged_token_meta) {
	ParseNode nn = ParseNode();
	sprintf(codegen_buf, merge_rule.c_str(), list1.fs.CurrentTerm.what.c_str(), list2.fs.CurrentTerm.what.c_str());
	nn.fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	for (auto i = 0; i < list1.child.size(); i++)
	{
		nn.addchild(new ParseNode(*list1.child[i]));
	}
	for (auto i = 0; i < list2.child.size(); i++)
	{
		nn.addchild(new ParseNode(*list2.child[i]));
	}
	return nn;
}