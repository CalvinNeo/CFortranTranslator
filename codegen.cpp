#include "gen_common.h"

//char codegen_buf[MAX_CODE_LENGTH];

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += program_tree.fs.CurrentTerm.what;
	return cpp_code;
}


ParseNode gen_token(Term term) {
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	return newnode;
}

FlexState gen_flex(Term term) {
	FlexState f;
	f.CurrentTerm = term;
	f.line_pos = f.parse_len = f.parse_line = f.parse_pos = 0;
	return f;
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