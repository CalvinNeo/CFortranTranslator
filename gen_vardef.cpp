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

std::string gen_vardef_array_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const std::tuple<std::vector<int>, std::vector<int>> & shape);
std::string gen_vardef_scalar_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str);
std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	std::string size_str = "{", lbound_str = "{";
	lbound_str += make_str_list(get<0>(shape).begin(), get<0>(shape).end(), [&](auto x) { return to_string(x); });
	size_str += make_str_list(get<1>(shape).begin(), get<1>(shape).end(), [&](auto x) { return to_string(x); });
	size_str += "}"; lbound_str += "}";
	return lbound_str + ", " + size_str;
}

std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice) {
	if (slice == nullptr) {
		return make_tuple(std::vector<int>(), std::vector<int>());
	}
	std::vector<int> lb(slice->child.size()), sz(slice->child.size());
	if (slice->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE)
	{
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			return 1;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int l; sscanf(x->fs.CurrentTerm.what.c_str(), "%d", &l);
			return l;
		});
	}
	else {
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			int l; sscanf(x->get(0).fs.CurrentTerm.what.c_str(), "%d", &l);
			return l;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int u; sscanf(x->get(1).fs.CurrentTerm.what.c_str(), "%d", &u);
			int l; sscanf(x->get(0).fs.CurrentTerm.what.c_str(), "%d", &l);
			return u - l + 1;
		});
	}
	return make_tuple(lb, sz);
}

std::string gen_vardef_array_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLEINITIAL
	// or NT_VARIABLEINITIAL(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	int dimension = (int)get<0>(shape).size();
	string alias_name = get_variable_name(entity_variable);

	// no desc if var_def is not in paramtable
	sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str()  /* array name */);
	arr_decl += string(codegen_buf);
	if (entity_variable.get(1).fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// default initialize
		if (get_context().parse_config.usefarray) {
			sprintf(codegen_buf, "{%s}", gen_lbound_size_str(shape).c_str()); // compile reckon "T a();" as function decl, so use `{}` 
			arr_decl += string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "(%d, %d)", get<0>(shape)[0], get<0>(shape)[0] + get<1>(shape)[0] + 1 /* slice from to */);
			arr_decl += string(codegen_buf);
		}
	}
	else {
		// init from array_builder
		sprintf(codegen_buf, "{%s};\n", gen_lbound_size_str(shape).c_str());
		arr_decl += string(codegen_buf);
		ParseNode & compound_arraybuilder = entity_variable.get(1); // NT_ARRAYBUILDER
		regen_arraybuilder(compound_arraybuilder);
		sprintf(codegen_buf, "%s = %s", alias_name.c_str(), compound_arraybuilder.fs.CurrentTerm.what.c_str());
		arr_decl += string(codegen_buf);
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return arr_decl;
}

bool is_array_variable_node(ParseNode & entity_variable) {
	ParseNode & entity_variable_name = entity_variable.get(0);
	if (entity_variable_name.fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name.get(0).fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		return true;
	}
	return false;
}

std::string get_variable_name(ParseNode & entity_variable) {
	ParseNode & entity_variable_name = entity_variable.get(0);
	if (is_array_variable_node(entity_variable))
	{
		// entity_variable_name->child[0] has subobject designator like `A(0,1,2)`
		return entity_variable_name.get(0).get(0).fs.CurrentTerm.what;
	}
	else if (entity_variable_name.child.size() == 3 && entity_variable_name.get(1).to_string() == "*") {
		// character a*1
		return entity_variable_name.get(0).fs.CurrentTerm.what;
	}
	else {
		// entity_variable_name->child[0] is like `A`
		return entity_variable_name.fs.CurrentTerm.what;
	}
}

std::string gen_vardef_scalar_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str) {
	string var_decl; 
	ParseNode & entity_variable_name = entity_variable.get(0);
	// from entity_variable
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)
	sprintf(codegen_buf, "%s %s", type_str.c_str(), get_variable_name(entity_variable).c_str());
	var_decl = string(codegen_buf);
	if (entity_variable.get(1).fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
		/* if initial value is not dummy but `exp` */
		var_decl += " = ";
		var_decl += entity_variable.get(1).fs.CurrentTerm.what; // initial value
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return var_decl;
}

ParseNode gen_vardef_from_implicit(ARG_IN type, std::string name) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINE, name });
	newnode.addlist(type, gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" })// variable_desc
		, gen_keyvalue_from_name(name) // variable_entity
	);
	return newnode;
}

ParseNode gen_vardef(ARG_IN type_nospec, ARG_IN variable_desc, ARG_IN paramtable) {
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flatterned paramtable with all keyvalue elements
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINESET, "VARDEFSET GENERATED IN REGEN_SUITE" });
	for (int i = 0; i < (int)kvparamtable.child.size(); i++)
	{
		ParseNode newvardef = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINE, "VARDEF GENERATED IN REGEN_SUITE" });
		newvardef.addlist(type_nospec, variable_desc, kvparamtable.get(i)/*variable_entity*/);
		newvardef.setattr(variable_desc.attr->clone()); 
		newnode.addchild(newvardef);
	}
	return newnode;
}

void regen_vardef(VariableInfo * vinfo, ARG_OUT vardef_node, ARG_OUT type_nospec, VariableDesc & desc, ARG_OUT entity_variable) {
	string var_decl = ""; 
	bool do_arr = desc.slice.is_initialized();
	string type_str;
	if (type_nospec.fs.CurrentTerm.what == "")
	{
		type_nospec.fs.CurrentTerm.what = implicit_type_from_name(get_variable_name(entity_variable)).fs.CurrentTerm.what;
		type_nospec.setattr(new VariableDescAttr());
	}
	if(do_arr){
		// ARRAY
		type_str = gen_qualified_typestr(type_nospec, desc);
		var_decl += gen_vardef_array_str(vinfo, entity_variable, type_str, gen_lbound_size(desc.slice.get_ptr()));
		vardef_node.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else {
		// SCALAR
		if (is_array_variable_node(entity_variable))
		{
			ParseNode & entity_variable_name = entity_variable.get(0);
			ParseNode & argtable = entity_variable_name.get(0).get(1);
			std::tuple<std::vector<int>, std::vector<int>> ls = gen_lbound_size(&argtable);
			desc.slice = argtable; // add slice attribute to vardescattr.desc
			type_str = gen_qualified_typestr(type_nospec, desc);
			var_decl = gen_vardef_array_str(vinfo, entity_variable, type_str, ls);
		}
		else {
			type_str = gen_qualified_typestr(type_nospec, desc);
			var_decl = gen_vardef_scalar_str(vinfo, entity_variable, type_str);
		}
		vardef_node.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} // end if
	vinfo->commonblock_index; // set in regen_suite and gen_common
	vinfo->commonblock_name; // set in regen_suite and gen_common
	vinfo->desc = desc; // set in regen_vardef
	vinfo->implicit_defined; // set in regen_suite
	vinfo->type = type_nospec; // set in regen_vardef
	vinfo->entity_variable = entity_variable; // set in regen_vardef
}
