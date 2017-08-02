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

static bool isnumber(std::string str) {
	return std::accumulate(str.begin(), str.end(), true, [](bool x, char y) {
		return x && y >= '0' && y <= '9';
	});
}

SliceBoundInfo get_lbound_size_from_slice(const ParseNode & slice) {

	/*****************
	* because the usage of `boost::optional<ParseNode> desc.slice`
	* below if-stmt is useless
	* ================
	//if (slice == nullptr) {
	//	return make_tuple(std::vector<int>(), std::vector<int>());
	//}
	*****************/

	std::vector<std::string> lb(slice.length()), sz(slice.length());
	if (slice.get_token() == TokenMeta::NT_ARGTABLE_PURE)
	{
		return get_sliceinfo_base(slice.begin(), slice.end()
			, [](const ParseNode * x) {
				return "1";
			}
			, [](const ParseNode * x) {
				return x->get_what();
		});
	}
	else {
		return get_sliceinfo_base(slice.begin(), slice.end()
			, [](const ParseNode * x) {
				if (isnumber(x->get(0).get_what()))
				{
					int l = std::atoi(x->get(0).get_what().c_str());
					return to_string(l);
				}
				else {
					return x->get(0).get_what();
				}
			}
			, [](const ParseNode * x) {
				if (isnumber(x->get(1).get_what()) && isnumber(x->get(0).get_what()))
				{
					int u = std::atoi(x->get(1).get_what().c_str()); 
					int l = std::atoi(x->get(0).get_what().c_str()); 
					return to_string(u - l + 1);
				}
				else {
					sprintf(codegen_buf, "%s - %s + 1", x->get(1).get_what().c_str(), x->get(0).get_what().c_str());
					return string(codegen_buf);
				}
		});
	}
}


std::string gen_vardef_array_initial_str(FunctionInfo * finfo, VariableInfo * vinfo, const ParseNode & additional_desc) {
	ParseNode & entity_variable = vinfo->entity_variable;
	string alias_name = get_variable_name(entity_variable);
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLE_ENTITY(entity_variable) -> NT_FUCNTIONARRAY(entity_variable_name) -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLE_ENTITY
	// or NT_VARIABLE_ENTITY(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	bool dynamic_array = false;
	for (int i = 0; i < additional_desc.length(); i++)
	{
		const ParseNode & slice = additional_desc.get(i);
		if (slice.get_token() == TokenMeta::NT_SLICE && slice.get(0).get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY)
		{
			dynamic_array = true;
		}
	}

	SliceBoundInfo & shape = get_lbound_size_from_slice(additional_desc);
	const std::vector<std::string> & lbound_vec = get<0>(shape);
	const std::vector<std::string> & size_vec = get<1>(shape);
	int dimension = (int)lbound_vec.size();
	if (entity_variable.get(1).get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// default initialize
		if (get_context().parse_config.usefarray) {
			// farray
			if (dynamic_array)
			{
				sprintf(codegen_buf, "{}");
				arr_decl += string(codegen_buf);
			}
			else {
				std::string lb_sz_str = gen_sliceinfo_str(lbound_vec.begin(), lbound_vec.end(), size_vec.begin(), size_vec.end());
				sprintf(codegen_buf, "{%s}", lb_sz_str.c_str()); // C++ reckon "T a();" as function decl, so use `{}` 
				arr_decl += string(codegen_buf);
			}
		}
		else {
			// for1array
			sprintf(codegen_buf, "(%s, %s + %s + 1)", lbound_vec[0].c_str(), lbound_vec[0].c_str(), size_vec[0].c_str()); // slice from to
			arr_decl += string(codegen_buf);
		}
	}
	else {
		// init from array_builder
		sprintf(codegen_buf, "{%s};\n", gen_sliceinfo_str(lbound_vec.begin(), lbound_vec.end(), size_vec.begin(), size_vec.end()).c_str());
		arr_decl += string(codegen_buf);
		ParseNode & arraybuilder = entity_variable.get(1); // initial value is array_builder rule
		regen_arraybuilder(finfo, arraybuilder);
		sprintf(codegen_buf, "%s = %s", alias_name.c_str(), arraybuilder.get_what().c_str());
		arr_decl += string(codegen_buf);
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return arr_decl;
}


std::string get_variable_name(const ParseNode & entity_variable) {
	if (entity_variable.get_token() == TokenMeta::NT_VARIABLE_ENTITY)
	{
		const ParseNode & entity_variable_name = entity_variable.get(0);
		if (is_function_array(entity_variable))
		{
			// entity_variable_name.get(0) has subobject designator like `A(0,1,2)`
			// NT_VARIABLE_ENTITY(entity_variable) -> NT_FUCNTIONARRAY(entity_variable_name) -> (UnknownVariant, NT_ARGTABLE_PURE)
			return entity_variable_name.get(0).get_what();
		}
		else if (entity_variable_name.length() == 3 && entity_variable_name.get(2).get_token() == TokenMeta::Multiply) {
			// character a*1
			return entity_variable_name.get(0).get_what();
		}
		else {
			// variable with initial value
			return entity_variable_name.get_what();
		}
	}
	else {
		return entity_variable.get_what();
	}
}

std::string gen_vardef_scalar_initial_str(FunctionInfo * finfo, VariableInfo * vinfo) {
	ParseNode & entity_variable = vinfo->entity_variable;
	ParseNode & entity_variable_name = entity_variable.get(0);
	ParseNode & entity_variable_initial = entity_variable.get(1);
	// from entity_variable
	if (entity_variable_initial.get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// if initial value is not dummy but `exp` 
		if (is_int(vinfo->type) ) {
			sprintf(codegen_buf, " = 0");
		}
		else if (is_floating(vinfo->type)) {
			sprintf(codegen_buf, " = 0.0");
		}
		else if (is_str(vinfo->type)) {
			sprintf(codegen_buf, " = \"\"");
		}
		else
		{
			sprintf(codegen_buf, "");
		}
	}
	else {
		regen_exp(finfo, entity_variable_initial);
		sprintf(codegen_buf, " = %s", entity_variable_initial.get_what().c_str());
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return string(codegen_buf);
}

ParseNode gen_vardef_from_default(ARG_IN type, std::string name) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINE, name });
	newnode.addlist(type // type
		, gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }) // variable_desc with default desc
		, gen_keyvalue_from_name(name) // variable_entity
	);
	return newnode;
}

ParseNode gen_vardef(ARG_IN type_nospec, ARG_IN variable_desc, ARG_IN paramtable) {
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flatterned paramtable with all keyvalue elements
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINESET, "VARDEFSET GENERATED IN REGEN_SUITE" });
	for (int i = 0; i < kvparamtable.length(); i++)
	{
		ParseNode newvardef = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINE, "VARDEF GENERATED IN REGEN_SUITE" });
		ParseNode & variable_entity = kvparamtable.get(i);
		newvardef.addlist(type_nospec, variable_desc, variable_entity);

		/*****************
		* IMPORTANT
		* must take care of duplicate decl
		* in case of
		*	```
		*	real a(:)
		*	allocatable a
		*	intent(in) a
		*	```
		* it will overwrite previous decls
		*****************/
		newvardef.setattr(variable_desc.attr->clone());
		newnode.addchild(newvardef);
	}
	return newnode;
}

std::string regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo, std::string alias_name, bool save_to_node) {
	VariableDesc & desc = vinfo->desc;
	ParseNode & entity_variable = vinfo->entity_variable;
	ParseNode & type_nospec = vinfo->type;
	/*****************
	* IMPORTANT
	* ref `vinfo->is_array()`
	*=================
	* is array when 
	*	desc.slice.is_initialized() == true or,
	*	desc.allocatable == true
	*****************/
	bool do_arr = vinfo->is_array();
	string var_decl, type_str;
	/*****************
	* IMPORTANT
	* this function should handle `Function_Decl`(function variables which are often declared by `interface`)
	*****************/
	regen_type(type_nospec, finfo, vinfo);
	if (alias_name == "")
	{
		alias_name = get_variable_name(entity_variable);
	}
	// entity_variable is NT_VARIABLE_ENTITY
	if(desc.slice.is_initialized()){
		// ARRAY with slice info
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str());
		var_decl = string(codegen_buf);
		var_decl += gen_vardef_array_initial_str(finfo, vinfo, desc.slice.value());
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicit defined
			vinfo->vardef_node = new ParseNode(gen_vardef_from_default(vinfo->type, vinfo->local_name));
		}
		if (save_to_node)
		{
			vinfo->vardef_node->get_what() = var_decl;
		}
	}
	else if (is_function_array(entity_variable)) {
		// ARRAY declared by `DIMENSION a(10)`
		// OVERRIDE original dimension attr
		ParseNode & entity_variable_name = entity_variable.get(0);
		// add slice attribute to vardescattr.desc
		ParseNode & argtable = entity_variable_name.get(1);
		desc.slice = argtable;
		// get slice info
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str());
		var_decl = string(codegen_buf);
		var_decl += gen_vardef_array_initial_str(finfo, vinfo, desc.slice.value());
		if (save_to_node)
		{
			vinfo->vardef_node->get_what() = var_decl;
		}
	}
	else if (type_nospec.get_token() == TokenMeta::Function)
	{
		// Function
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		var_decl = type_str + " " + vinfo->local_name;
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicitly defined
			fatal_error("variable not defined: " + vinfo->local_name);
		}
		if (save_to_node)
		{
			vinfo->vardef_node->get_what() = var_decl;
		}
	}
	else {
		// SCALAR
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str());
		var_decl = string(codegen_buf);
		var_decl += gen_vardef_scalar_initial_str(finfo, vinfo);
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicitly defined
			fatal_error("variable not defined: "+ vinfo->local_name);
		}
		if (save_to_node)
		{
			vinfo->vardef_node->get_what() = var_decl;
		}
	} 
	vinfo->commonblock_index;
	vinfo->commonblock_name;
	vinfo->desc = desc; 
	vinfo->implicit_defined;
	vinfo->type = type_nospec;
	vinfo->entity_variable = entity_variable; 
	return var_decl;
}
