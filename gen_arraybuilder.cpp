#include "gen_common.h"

ParseNode gen_array_generate_stmt(const ParseNode & _generate_stmt) {
	/* give generate stmt */
	// use gen_hiddendo
	return gen_hiddendo(_generate_stmt, TokenMeta::NT_ARRAYBUILDER_VALUE);

}

ParseNode gen_array_generate_paramtable(const ParseNode & argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
	/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
	ParseNode newnode = ParseNode();
	for (int i = 0; i < argtable.child.size(); i++)
	{
		if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION) {
			ParseNode array_builder_value;
			if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
				// slice
			}
			else if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				// hidden_do
			}
			else {
				// just A(1)(2)(3) or A(1, 2, 3)
			}
			array_builder_value = gen_promote(TokenMeta::NT_ARRAYBUILDER_VALUE, *argtable.child[i]->child[0]);
			newnode.addchild(new ParseNode(array_builder_value));
		}
		else {
			// set in gen_vardef.cpp
			// use 1d list to initialize the array
			sprintf(codegen_buf, "{%s}", argtable.fs.CurrentTerm.what.c_str());
			goto CAN_ONLY_GEN_ONE;
		}
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, "" };
	return newnode;
CAN_ONLY_GEN_ONE:
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}