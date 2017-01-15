#include "gen_common.h"

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode  newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
	newnode.addchild(new ParseNode(lb)); // lower bound
	newnode.addchild(new ParseNode(ub)); // upper bound
	newnode.addchild(new ParseNode(step)); // step
	return newnode;
}

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode  newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
	newnode.addchild(new ParseNode(lb)); // lower bound
	newnode.addchild(new ParseNode(ub)); // upper bound
	return newnode;
}

ParseNode promote_exp_to_slice(const ParseNode & exp) {
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
	newnode.child.push_back(nullptr);
	newnode.child.push_back(new ParseNode(exp));
	ParseNode lb = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::NT_EXPRESSION, "1" })); // default lower bound is 1
	newnode.child[0] = new ParseNode(lb);
	return newnode;
}


// 下面多个的用gen_flattern

