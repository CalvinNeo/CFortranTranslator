#include "gen_common.h"

ParseNode gen_array_generate_stmt(ParseNode & hiddendo) {
	/* give hiddendo */
	// use gen_hiddendo
	hiddendo.fs.CurrentTerm.token = TokenMeta::NT_ARRAYBUILDER_VALUE;
	return hiddendo;
}


ParseNode gen_array_from_paramtable(const ParseNode & argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */ParseNode newnode = ParseNode();
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
					std::vector<const ParseNode *> hiddendo_layer;
					ParseNode * ab = array_builder;
					while (ab->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
						hiddendo_layer.push_back(ab);
						if (ab->child.size() > 0 && ab->child[0]->child.size() > 0){
							ab = ab->child[0]/*NT_EXPRESSION*/->child[0]/*NT_HIDDENDO*/;
						}
						else {
							break;
						}
					}
					array_builder->fs.CurrentTerm.what = gen_nested_hiddendo(hiddendo_layer);
				}
			}
			else {
				// just A(1)(2)(3) or A(1, 2, 3)
			}
			array_builder_value = gen_promote(TokenMeta::NT_ARRAYBUILDER_VALUE, *array_builder);
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
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_LIST, string(codegen_buf) };
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}