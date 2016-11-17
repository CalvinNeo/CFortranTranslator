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

ParseNode gen_dimenslice_from_slice(ParseNode & slice) {
	/* 1d array */
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
	//if (slice.child.size() == 1) {
	//	// not a slice but a index
	//	slice.child.push_back(nullptr);
	//	slice.child[1] = slice.child[0];
	//	ParseNode lb = gen_exp(gen_token(Term{ TokenMeta::NT_EXPRESSION, "1" }));
	//	slice.child[0] = new ParseNode(lb);
	//}
	newnode.addchild(new ParseNode(slice)); // only 1 slice
	return newnode;
}

ParseNode gen_argtable_from_exp(ParseNode & exp) {
	/* argtable is used in function call */
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "%s", exp.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
	newnode.addchild(new ParseNode(exp)); // exp
	return newnode;
}

// 下面多个的用gen_flattern

//ParseNode gen_dimenslice(ParseNode & slice, const ParseNode & dimen_slice) {
//	/* arr[from : to] */
//	/* target code of slice depend on context */
//	ParseNode * nn = new ParseNode();
//	nn->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
//	//if (slice.child.size() == 1) {
//	//	// not a slice but a index
//	//	slice.child.push_back(nullptr);
//	//	slice.child[1] = slice.child[0];
//	//	ParseNode lb = gen_exp(gen_token(Term{ TokenMeta::NT_EXPRESSION, "1" }));
//	//	slice.child[0] = new ParseNode(lb);
//	//}
//	nn->addchild(new ParseNode(slice));
//	nn->addchild(new ParseNode(dimen_slice)); // dimen_slice
//	nn = flattern_bin(nn);
//	ParseNode newnode = ParseNode(*nn);
//	delete nn;
//	return newnode;
//}
//
//ParseNode gen_argtable(ParseNode & exp, const ParseNode & argtable) {
//	ParseNode * nn = new ParseNode();
//	sprintf(codegen_buf, "%s, %s", exp.fs.CurrentTerm.what.c_str(), argtable.fs.CurrentTerm.what.c_str());
//	nn->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
//	nn->addchild(new ParseNode(exp)); // exp
//	nn->addchild(new ParseNode(argtable)); // argtable
//	nn = flattern_bin(nn);
//	ParseNode newnode = ParseNode(*nn);
//	delete nn;
//	return newnode;
//}