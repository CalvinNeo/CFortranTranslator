#include "gen_common.h"

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step) {
	/* arr[from : to] */
	ParseNode  newnode = ParseNode();
	/* target code of slice depend on context */
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
	newnode.addchild(new ParseNode(lb)); // lower bound
	newnode.addchild(new ParseNode(ub)); // upper bound
	newnode.addchild(new ParseNode(step)); // step
	return newnode;
}
ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub) {
	/* arr[from : to] */
	ParseNode  newnode = ParseNode();
	/* target code of slice depend on context */
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
	newnode.addchild(new ParseNode(lb)); // lower bound
	newnode.addchild(new ParseNode(ub)); // upper bound
	return newnode;
}