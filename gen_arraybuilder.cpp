#include "gen_common.h"

ParseNode gen_array_generate_stmt(const ParseNode & _generate_stmt) {
	/* give generate stmt */
	//print_error("LBound don't agree", _generate_stmt);
	//sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s;\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
	//	, index->fs.CurrentTerm.what.c_str(), to->fs.CurrentTerm.what.c_str() /* exp_to */, index->fs.CurrentTerm.what.c_str() /* index variable inc */
	//	, "\t%s" /* array variable name */, index->fs.CurrentTerm.what.c_str() /* index variable */, exp->fs.CurrentTerm.what.c_str());
	
	// use gen_hiddendo
	return gen_hiddendo(_generate_stmt, TokenMeta::NT_ARRAYBUILDER_EXP);

}

ParseNode gen_array_generate_paramtable(const ParseNode & argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
	/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
	ParseNode newnode = ParseNode();
	for (int i = 0; i < argtable.child.size(); i++)
	{
		if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION) {
			if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
				// slice
			}
			else if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				// hidden_do
			}
			else {
				// just A(1)(2)(3)
			}
			ParseNode array_builder_value = gen_promote(TokenMeta::NT_ARRAYBUILDER_VALUE, *argtable.child[i]->child[0]);
			newnode.addchild(new ParseNode(array_builder_value));
		}
		else {
			// set in gen_vardef.cpp
			//sprintf(codegen_buf, "init_for1array(%%s, %%s, %%s, std::vector<%%s>{%s});\n", /* value */ argtable.fs.CurrentTerm.what.c_str());
			// use 1d list to initialize the array
			sprintf(codegen_buf, "gen_for1array<%%s, %%d>(%%s, %%s, std::vector<%%s>{%s})", argtable.fs.CurrentTerm.what.c_str());
			goto CAN_ONLY_GEN_ONE;
		}
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, "" };
	return newnode;
CAN_ONLY_GEN_ONE:
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE, string(codegen_buf) };
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}