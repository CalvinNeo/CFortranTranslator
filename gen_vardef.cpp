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

std::string gen_vardef_array_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const std::tuple<std::vector<int>, std::vector<int>> & shape);
std::string gen_vardef_scalar_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str);
std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	std::string size_str = "{", lbound_str = "{";
	lbound_str += make_str_list(get<0>(shape).begin(), get<0>(shape).end(), [&](auto x) { return to_string(x); });
	size_str += make_str_list(get<1>(shape).begin(), get<1>(shape).end(), [&](auto x) { return to_string(x); });
	size_str += "}"; lbound_str += "}";
	return lbound_str + ", " + size_str;
}

std::tuple<std::vector<int>, std::vector<int>> get_lbound_size(const ParseNode * slice) {
	if (slice == nullptr) {
		return make_tuple(std::vector<int>(), std::vector<int>());
	}
	std::vector<int> lb(slice->length()), sz(slice->length());
	if (slice->get_token() == TokenMeta::NT_ARGTABLE_PURE)
	{
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			return 1;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int l; sscanf(x->get_what().c_str(), "%d", &l);
			return l;
		});
	}
	else {
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			int l; sscanf(x->get(0).get_what().c_str(), "%d", &l);
			return l;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int u; sscanf(x->get(1).get_what().c_str(), "%d", &u);
			int l; sscanf(x->get(0).get_what().c_str(), "%d", &l);
			return u - l + 1;
		});
	}
	return make_tuple(lb, sz);
}

std::string gen_vardef_array_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLE_ENTITY(entity_variable) -> NT_FUCNTIONARRAY(entity_variable_name) -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLE_ENTITY
	// or NT_VARIABLE_ENTITY(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	int dimension = (int)get<0>(shape).size();
	string alias_name = get_variable_name(entity_variable);

	// no desc if var_def is not in paramtable
	sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str()  /* array name */);
	arr_decl += string(codegen_buf);
	if (entity_variable.get(1).get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
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
		ParseNode & arraybuilder = entity_variable.get(1); // NT_ARRAYBUILDER
		regen_arraybuilder(finfo, arraybuilder);
		sprintf(codegen_buf, "%s = %s", alias_name.c_str(), arraybuilder.get_what().c_str());
		arr_decl += string(codegen_buf);
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return arr_decl;
}


std::string get_variable_name(const ParseNode & entity_variable) {
	const ParseNode & entity_variable_name = entity_variable;
	if (is_function_array(entity_variable))
	{
		// entity_variable_name->child[0] has subobject designator like `A(0,1,2)`
		return entity_variable_name.get(0).get(0).get_what();
	}
	else if (entity_variable_name.length() == 3 && entity_variable_name.get(1).get_what() == "*") {
		// character a*1
		return entity_variable_name.get(0).get_what();
	}
	else {
		// variable with initial value
		return entity_variable_name.get_what();
	}
}

std::string gen_vardef_scalar_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str) {
	string var_decl; 
	ParseNode & entity_variable_name = entity_variable.get(0);
	// from entity_variable
	// NT_VARIABLE_ENTITY(entity_variable) -> NT_FUCNTIONARRAY(entity_variable_name) -> (UnknownVariant, NT_ARGTABLE_PURE)
	sprintf(codegen_buf, "%s %s", type_str.c_str(), get_variable_name(entity_variable).c_str());
	var_decl = string(codegen_buf);
	if (entity_variable.get(1).get_token() != TokenMeta::NT_VARIABLEINITIALDUMMY) {
		/* if initial value is not dummy but `exp` */
		var_decl += " = ";
		var_decl += entity_variable.get(1).get_what(); // initial value
	}
	entity_variable.setattr(new VariableAttr(vinfo));
	return var_decl;
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
		newvardef.addlist(type_nospec, variable_desc, kvparamtable.get(i)/*variable_entity*/);
		newvardef.setattr(variable_desc.attr->clone()); 
		newnode.addchild(newvardef);
	}
	return newnode;
}

void regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo, ARG_OUT type_nospec, VariableDesc & desc, ARG_OUT entity_variable) {
	string var_decl = ""; 
	bool do_arr = desc.slice.is_initialized();
	string type_str;
	// entity_variable is NT_VARIABLE_ENTITY
	if (type_nospec.get_what() == "")
	{
		// if type is implicit
		// 注意隐式类型和隐式声明含义不一样，隐式类型则类型从变量名推导，隐式声明则与`implicit none`相对应
		type_nospec.get_what() = gen_implicit_type(get_variable_name(entity_variable)).get_what();
		type_nospec.setattr(new VariableDescAttr());
	}
	if(do_arr){
		// ARRAY
		type_str = gen_qualified_typestr(type_nospec, desc);
		var_decl += gen_vardef_array_str(finfo, vinfo, entity_variable, type_str, get_lbound_size(desc.slice.get_ptr()));
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicit defined
			vinfo->vardef_node = new ParseNode(gen_vardef_from_default(vinfo->type, vinfo->local_name));
		}
		vinfo->vardef_node->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else {
		// SCALAR
		if (is_function_array(entity_variable))
		{
			ParseNode & entity_variable_name = entity_variable.get(0);
			// add slice attribute to vardescattr.desc
			ParseNode & argtable = entity_variable_name.get(1);
			desc.slice = argtable;
			// get slice info
			std::tuple<std::vector<int>, std::vector<int>> ls = get_lbound_size(&argtable);
			type_str = gen_qualified_typestr(type_nospec, desc);
			var_decl = gen_vardef_array_str(finfo, vinfo, entity_variable, type_str, ls);
		}
		else {
			type_str = gen_qualified_typestr(type_nospec, desc);
			var_decl = gen_vardef_scalar_str(finfo, vinfo, entity_variable, type_str);
		}
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicit defined
			print_error("variable not defined: "+ vinfo->local_name );
		}
		vinfo->vardef_node->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} // end if
	vinfo->commonblock_index; // set in regen_suite and gen_common
	vinfo->commonblock_name; // set in regen_suite and gen_common
	vinfo->desc = desc; // set in regen_vardef
	vinfo->implicit_defined; // set in regen_suite
	vinfo->type = type_nospec; // set in regen_vardef
	vinfo->entity_variable = entity_variable; // set in regen_vardef
}
