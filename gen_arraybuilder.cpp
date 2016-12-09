#include "gen_common.h"

ParseNode gen_array_generate_stmt(const ParseNode & _generate_stmt) {
	/* give generate stmt */
	ParseNode newnode = ParseNode();
	ParseNode * exp = _generate_stmt.child[0];
	ParseNode * index = _generate_stmt.child[1];
	ParseNode * from = _generate_stmt.child[2];
	ParseNode * to = _generate_stmt.child[3];
	//print_error("LBound don't agree", _generate_stmt);
	sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s;\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
		, index->fs.CurrentTerm.what.c_str(), to->fs.CurrentTerm.what.c_str() /* exp_to */, index->fs.CurrentTerm.what.c_str() /* index variable inc */
		, "\t%s" /* array variable name */, index->fs.CurrentTerm.what.c_str() /* index variable */, exp->fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
	newnode.addchild(new ParseNode(*exp)); // exp
	newnode.addchild(new ParseNode(*index)); // index variable
	newnode.addchild(new ParseNode(*from)); // exp_from
	newnode.addchild(new ParseNode(*to)); // exp_to
	return newnode;

}

ParseNode gen_array_generate_paramtable(const ParseNode & argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
	/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
	ParseNode newnode = ParseNode();
	vector<ParseNode *> slices;
	vector<ParseNode *> hiddens;
	std::vector<std::string> ans;
	string fi;
	for (int i = 0; i < argtable.child.size() + 1; i++)
	{
		int stat = 0;
		if (i == argtable.child.size()) {
			stat = 0;
		}else
		{
			if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION) {
				if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
					// slice
					stat = 1;
					slices.push_back(argtable.child[i]->child[0]);
				}
				else if (argtable.child[i]/* NT_EXPRESSION */->child[0]->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
					// hidden_do
					stat = 2;
					hiddens.push_back(argtable.child[i]->child[0]);
				}
			}
			else {
				/* for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound
				, const std::vector<int> & size, const std::vector<T> & values */
				// set in gen_vardef.cpp
				sprintf(codegen_buf, "init_for1array(%%s, %%s, %%s, std::vector<%%s>{%s});\n", /* value */ argtable.fs.CurrentTerm.what.c_str());
				goto CAN_ONLY_GEN_ONE;
			}
		}
		if (stat != 1 && !slices.empty()) {
			for (int i = 0; i < slices.size(); i++)
			{
				ans.push_back(slices[i]->fs.CurrentTerm.what);
			}
			slices.clear();
		}
		if (stat != 2 && !hiddens.empty()) {
			for (int i = 0; i < hiddens.size(); i++)
			{
				ans.push_back(hiddens[i]->fs.CurrentTerm.what);
			}
			hiddens.clear();
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			fi += " + ";
		fi += ans[i];
	}
	sprintf(codegen_buf, "%%s = %s;\n", /* value */ fi.c_str());
CAN_ONLY_GEN_ONE:
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE, string(codegen_buf) };
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}