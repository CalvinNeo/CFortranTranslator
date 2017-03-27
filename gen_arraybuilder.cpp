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
		ARG_IN array_builder = argtable.get(i);
		if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
			// slice
			newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, array_builder);
		}
		else if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
			// hidden_do, handled in gen_array_from_hiddendo
			// 现在统一把NT_ARRAYBUILDER_LAMBDA放到NT_ARRAYBUILDER_LIST的list里面了
			newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, array_builder);
			//newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LAMBDA, argtable.to_string() }, array_builder);
		}
		else if (array_builder.fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION) {
			// just A(1)(2)(3) or A(1, 2, 3)
			newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, array_builder);
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

bool element_maybe_array(FunctionInfo * finfo, const ParseNode & elem) {
	/**
	 *  return true: have a possiblity to be array
	 *	return false: not array
	**/
	if (elem.fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
		return true;
	}
	else if (elem.fs.CurrentTerm.token == TokenMeta::UnknownVariant) {
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, get_variable_name(elem));
		if (vinfo != nullptr)
		{
			if (vinfo->is_array()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			print_error("Variable not defined", elem);
			fatal_error("Variable not defined");
			return true;
		}
	}
	else if (elem.fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY){
		// hard to determine, so return true
		return true;
	}
	else {
		// including literals
		return false;
	}
}

void regen_arraybuilder(FunctionInfo * finfo, ARG_OUT array_builder) {
	// wrap arraybuilder.fs.CurrentTerm.what with make_farray function
	string arr_decl;
	bool concat_array = false;
	// if any of NT_ARRAYBUILDER_LIST's child is an array, then concat_array = true
	ParseNode & arguments = array_builder.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LAMBDA ? array_builder : array_builder.get(0);
	for (int i = 0; i < arguments.child.size(); i++)
	{
		ParseNode & elem = arguments.get(i);
		if (element_maybe_array(finfo, elem)) {
			concat_array = true;
		}
	}

	if (!concat_array)
	{
		// can init array from initializer_list of initial value
		sprintf(codegen_buf, "make_init_list(%s)", array_builder.fs.CurrentTerm.what.c_str());
		arr_decl += string(codegen_buf);
	}
	else {
		// must init array from another farray/for1array
		arr_decl += "forconcat({";
		for (auto i = 0; i < arguments.child.size(); i++)
		{
			ARG_IN elem = arguments.get(i);
			if (elem.fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
				vector<const ParseNode *> hiddendo_layer = gen_nested_hiddendo_layers(elem);
				std::string vec_from = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {
					return x->get(2).fs.CurrentTerm.what; 
				});
				std::string vec_to = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {
					int from, to;
					sscanf(x->get(2).fs.CurrentTerm.what.c_str(), "%d", &from);
					sscanf(x->get(3).fs.CurrentTerm.what.c_str(), "%d", &to);
					sprintf(codegen_buf, "%d", to - from + 1);
					return string(codegen_buf); 
				});
				// init from hidden do
				std::string stuff = gen_hiddendo_expr(arguments.get(0));
				sprintf(codegen_buf, "make_init_list({%s}, {%s}, %s)", vec_from.c_str(), vec_to.c_str(), stuff.c_str());
			}
			else if (arguments.get(i).fs.CurrentTerm.token == TokenMeta::UnknownVariant 
				|| arguments.get(i).fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
				VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, elem.fs.CurrentTerm.what);
				if (element_maybe_array(finfo, elem))
				{
					sprintf(codegen_buf, "make_init_list(%s)", elem.fs.CurrentTerm.what.c_str());
				}
				else {
					sprintf(codegen_buf, "make_init_list(%s)", elem.fs.CurrentTerm.what.c_str());
				}
			}
			else {
				// literal
				sprintf(codegen_buf, "make_init_list(%s)", elem.fs.CurrentTerm.what.c_str());
			}
			if (i > 0) {
				arr_decl += ", ";
			}
			arr_decl += string(codegen_buf);
		}
		arr_decl += "})";
	}
	array_builder.fs.CurrentTerm.what = arr_decl;
	return;
}