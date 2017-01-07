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
			ParseNode * array_builder = argtable.child[i]/* NT_EXPRESSION */->child[0];
			if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
				// slice
			}
			else if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				// hidden_do
				if (parse_config.usefarray)
				{
					std::vector<ParseNode *> init_layer;
					ParseNode * ab = array_builder;
					while (ab->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
						init_layer.push_back(ab);
						if (ab->child.size() > 0 && ab->child[0]->child.size() > 0){
							ab = ab->child[0]/*NT_EXPRESSION*/->child[0]/*NT_HIDDENDO*/;
						}
						else {
							break;
						}
					}
					vector<ParseNode *>::iterator x;
					// refer `gen_hiddendo`
					string lb_str = make_str_list(init_layer.begin(), init_layer.end(), [](auto x)->string {return (*x)->child[2]->fs.CurrentTerm.what; });
					string ub_str = make_str_list(init_layer.begin(), init_layer.end(), [](auto x)->string {return (*x)->child[3]->fs.CurrentTerm.what + "+1"; });
					string indexer_str = make_str_list(init_layer.begin(), init_layer.end(), [](auto x)->string {return "fsize_t " + (*x)->child[1]->fs.CurrentTerm.what; });
					sprintf(codegen_buf, "[](%s){return %s;}", indexer_str.c_str(), init_layer[init_layer.size() - 1]->child[0]->fs.CurrentTerm.what.c_str());
					string lambda = string(codegen_buf);
					string args;
					for (auto j = 0; j < init_layer.size(); j++)
					{
						if (j != 0) {
							args += ", ";
						}
						sprintf(codegen_buf, "current[%d]", (int)j);
						args += string(codegen_buf);
					}
					sprintf(codegen_buf, "[](const fsize_t(&current)[%d]){return %s(%s);}"
						, (int)init_layer.size(), lambda.c_str(), args.c_str());
					array_builder->fs.CurrentTerm.what = string(codegen_buf);
				}
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