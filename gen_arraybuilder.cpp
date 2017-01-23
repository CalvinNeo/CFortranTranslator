#include "gen_common.h"

ParseNode gen_array_from_hiddendo(ParseNode & hiddendo) {
	/* give hiddendo */
	// use gen_hiddendo
	return gen_promote(TokenMeta::NT_ARRAYBUILDER_VALUE, hiddendo);
}


ParseNode gen_array_from_paramtable(const ParseNode & argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
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
				// hidden_do, handled in gen_array_from_hiddendo
				//if (parse_config.usefarray)
				//{
				//	std::vector<const ParseNode *> hiddendo_layer = gen_nested_hiddendo_layers(*array_builder);
				//	array_builder->fs.CurrentTerm.what = gen_nested_hiddendo(hiddendo_layer);
				//}
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

ParseNode & gen_arraybuilder_str(ParseNode & arraybuilder) {
	// wrap arraybuilder.fs.CurrentTerm.what with make_farray function
	string arr_decl;
	ParseNode * compound_arraybuilder = &arraybuilder; // NT_ARRAYBUILDER
	bool can_list_init = true;
	for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
	{
		ParseNode * array_builder = compound_arraybuilder->child[builderid];
		if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
			can_list_init = false;
			break;
		}
		else if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LIST) {

		}
		else {

		}
	}
	int totalsize = 0;
	for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
	{
		ParseNode * array_builder = compound_arraybuilder->child[builderid];
		if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE /*hidden_do*/) {
			totalsize += array_builder->child[3] - array_builder->child[2] + 1;
		}
		else {
			totalsize += array_builder->child[0]/*NT_ARGTABLE_PURE or other paramtable nodes*/->child.size();
		}
	}
	if (can_list_init)
	{
		// can init array from initializer_list of initial value
		for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
		{
			ParseNode * array_builder = compound_arraybuilder->child[builderid];
			sprintf(codegen_buf, "make_farray(%s)", array_builder->fs.CurrentTerm.what.c_str());
			if (builderid > 0) {
				arr_decl += ", ";
			}
			arr_decl += codegen_buf;
		}
	}
	else {
		// must init array from another farray/for1array
		if (compound_arraybuilder->child.size() > 1) {
			arr_decl += "forconcat({";
		}
		for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
		{
			ParseNode * array_builder = compound_arraybuilder->child[builderid];
			if (array_builder->child[0]->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				vector<const ParseNode *> hiddendo_layer = gen_nested_hiddendo_layers(*array_builder->child[0]);
				std::string vec_from = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (*x)->child[2]->fs.CurrentTerm.what; });
				std::string vec_to = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (*x)->child[3]->fs.CurrentTerm.what + " - " + (*x)->child[2]->fs.CurrentTerm.what; });
				sprintf(codegen_buf, "make_farray({%s}, {%s}, %s)", vec_from.c_str(), vec_to.c_str(), array_builder->fs.CurrentTerm.what.c_str());
			}
			else {
				sprintf(codegen_buf, "make_farray(%s)", array_builder->fs.CurrentTerm.what.c_str());
			}
			if (builderid > 0) {
				arr_decl += " , ";
			}
			arr_decl += codegen_buf;
		}
		if (compound_arraybuilder->child.size() > 1) {
			arr_decl += " })";
		}
	}
	arraybuilder.fs.CurrentTerm.what = arr_decl;
	return arraybuilder;
}