#include "gen_common.h"

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" });
	newnode.addchild(lb); // lower bound
	newnode.addchild(ub); // upper bound
	newnode.addchild(step); // step
	return newnode;
}

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" });
	newnode.addchild(lb); // lower bound
	newnode.addchild(ub); // upper bound
	return newnode;
}

ParseNode promote_exp_to_slice(const ParseNode & exp) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" });
	newnode.addchild(gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::NT_EXPRESSION, "1" })));// default lower bound is 1
	newnode.addchild(exp);
	return newnode;
}

