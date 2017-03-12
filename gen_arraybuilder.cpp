/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"

ParseNode gen_array_from_hiddendo(ARG_IN hiddendo) {
	/* give hiddendo */
	// use gen_hiddendo
	return gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LAMBDA, hiddendo.to_string() }, hiddendo);
}


ParseNode gen_array_from_paramtable(ARG_IN argtable) {
	/* give initial value */
	/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
	ParseNode newnode = ParseNode();
	for (int i = 0; i < argtable.child.size(); i++)
	{
		if (argtable.get(i).fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION) {
			ARG_IN array_builder = argtable.get(i)/* NT_EXPRESSION */.get(0);
			if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
				// slice
				newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, array_builder);
			}
			else if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				// hidden_do, handled in gen_array_from_hiddendo
				newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LAMBDA, argtable.to_string() }, array_builder);
			}
			else {
				// just A(1)(2)(3) or A(1, 2, 3)
				newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, array_builder);
			}
		}
		else {
			// set in gen_vardef.cpp
			// use 1d list to initialize the array
			sprintf(codegen_buf, "{%s}", argtable.fs.CurrentTerm.what.c_str());
			goto CAN_ONLY_GEN_ONE;
		}
	}
	return newnode;
CAN_ONLY_GEN_ONE:
	newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, string(codegen_buf) }, argtable);
	return newnode;
}

void regen_arraybuilder(ARG_OUT arraybuilder) {
	// wrap arraybuilder.fs.CurrentTerm.what with make_farray function
	string arr_decl;
	ARG_IN compound_arraybuilder = arraybuilder; // NT_ARRAYBUILDER
	bool can_list_init = true;
	for (auto builderid = 0; builderid < compound_arraybuilder.child.size(); builderid++)
	{
		ARG_IN array_builder = compound_arraybuilder.get(builderid);
		if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LAMBDA) {
			can_list_init = false;
			break;
		}
		else if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LIST) {

		}
		else {

		}
	}
	int totalsize = 0;
	for (auto builderid = 0; builderid < compound_arraybuilder.child.size(); builderid++)
	{
		ARG_IN array_builder = compound_arraybuilder.get(builderid);
		if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LAMBDA /*hidden_do*/) {
			int from, to;
			sscanf(array_builder.get(0)/* NT_HIDDENDO */.get(2).fs.CurrentTerm.what.c_str(), "%d", &from );
			sscanf(array_builder.get(0)/* NT_HIDDENDO */.get(3).fs.CurrentTerm.what.c_str(), "%d", &to);
			totalsize +=  to - from + 1;
		}
		else {
			totalsize += (int)array_builder.get(0)/*NT_ARGTABLE_PURE or other paramtable nodes*/.child.size();
		}
	}
	if (can_list_init)
	{
		// can init array from initializer_list of initial value
		for (auto builderid = 0; builderid < compound_arraybuilder.child.size(); builderid++)
		{
			ARG_IN array_builder = compound_arraybuilder.get(builderid);
			// init from list
			sprintf(codegen_buf, "make_init_list(%s)", array_builder.fs.CurrentTerm.what.c_str());
			if (builderid > 0) {
				arr_decl += ", ";
			}
			arr_decl += codegen_buf;
		}
	}
	else {
		// must init array from another farray/for1array
		if (compound_arraybuilder.child.size() > 1) {
			arr_decl += "forconcat({";
		}
		for (auto builderid = 0; builderid < compound_arraybuilder.child.size(); builderid++)
		{
			ARG_IN array_builder = compound_arraybuilder.get(builderid);
			if (array_builder.get(0).fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				vector<const ParseNode *> hiddendo_layer = gen_nested_hiddendo_layers(array_builder.get(0));
				std::string vec_from = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (x)->get(2).fs.CurrentTerm.what; });
				std::string vec_to = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {
					int from, to;
					sscanf((x)->get(2).fs.CurrentTerm.what.c_str(), "%d", &from);
					sscanf((x)->get(3).fs.CurrentTerm.what.c_str(), "%d", &to);
					sprintf(codegen_buf, "%d", to - from + 1);
					return string(codegen_buf); 
				});
				// init from hidden do
				std::string stuff = gen_hiddendo_expr(array_builder.get(0));
				sprintf(codegen_buf, "make_init_list({%s}, {%s}, %s)", vec_from.c_str(), vec_to.c_str(), stuff.c_str());
			}
			else {
				sprintf(codegen_buf, "make_init_list(%s)", array_builder.fs.CurrentTerm.what.c_str());
			}
			if (builderid > 0) {
				arr_decl += ", ";
			}
			arr_decl += codegen_buf;
		}
		if (compound_arraybuilder.child.size() > 1) {
			arr_decl += " })";
		}
	}
	arraybuilder.fs.CurrentTerm.what = arr_decl;
	return;
}