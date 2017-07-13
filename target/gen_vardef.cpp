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

std::string gen_vardef_array_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const SliceBoundInfo & shape);
std::string gen_vardef_scalar_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str);

bool isnumber(std::string str) {
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
		return get_lbound_size_base(slice.begin(), slice.end()
			, [](const ParseNode * x) {
				return "1";
			}
			, [](const ParseNode * x) {
				return x->get_what();
		});
	}
	else {
		return get_lbound_size_base(slice.begin(), slice.end()
			, [](const ParseNode * x) {
			return x->get_what();
			}
			, [](const ParseNode * x) {
				if (isnumber(x->get(1).get_what()) && isnumber(x->get(0).get_what()))
				{
					int u; sscanf(x->get(1).get_what().c_str(), "%d", &u);
					int l; sscanf(x->get(0).get_what().c_str(), "%d", &l);
					return to_string(u - l + 1);
				}
				else {
					sprintf("%s - %s + 1", x->get(1).get_what().c_str(), x->get(0).get_what().c_str());
					return string(codegen_buf);
				}
		});
	}
}

std::string gen_vardef_array_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const SliceBoundInfo & shape) {
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLE_ENTITY(entity_variable) -> NT_FUCNTIONARRAY(entity_variable_name) -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLE_ENTITY
	// or NT_VARIABLE_ENTITY(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	string alias_name = get_variable_name(entity_variable);
	const std::vector<std::string> & lbound_vec = get<0>(shape);
	const std::vector<std::string> & size_vec = get<1>(shape);
	int dimension = (int)lbound_vec.size();
	// no desc if var_def is not in parameter list
	sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str()  /* array name */);
	arr_decl += string(codegen_buf);
	if (entity_variable.get(1).get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// default initialize
		if (get_context().parse_config.usefarray) {
			// farray
			sprintf(codegen_buf, "{%s}", gen_lbound_size_str(lbound_vec.begin(), lbound_vec.end(), size_vec.begin(), size_vec.end()).c_str()); // C++ reckon "T a();" as function decl, so use `{}` 
			arr_decl += string(codegen_buf);
		}
		else {
			// for1array
			sprintf(codegen_buf, "(%s, %s + %s + 1)", lbound_vec[0].c_str(), lbound_vec[0].c_str(), size_vec[0].c_str()); // slice from to
			arr_decl += string(codegen_buf);
		}
	}
	else {
		// init from array_builder
		sprintf(codegen_buf, "{%s};\n", gen_lbound_size_str(lbound_vec.begin(), lbound_vec.end(), size_vec.begin(), size_vec.end()).c_str());
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

std::string gen_vardef_scalar_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str) {
	ParseNode & entity_variable_name = entity_variable.get(0);
	ParseNode & entity_variable_initial = entity_variable.get(1);
	// from entity_variable
	if (entity_variable_initial.get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// if initial value is not dummy but `exp` 
		if (is_int(vinfo->type) ) {
			sprintf(codegen_buf, "%s %s = 0", type_str.c_str(), get_variable_name(entity_variable).c_str());
		}
		else if (is_floating(vinfo->type)) {
			sprintf(codegen_buf, "%s %s = 0.0", type_str.c_str(), get_variable_name(entity_variable).c_str());
		}
		else if (is_str(vinfo->type)) {
			sprintf(codegen_buf, "%s %s = \"\"", type_str.c_str(), get_variable_name(entity_variable).c_str());
		}
		else
		{
			sprintf(codegen_buf, "%s %s", type_str.c_str(), get_variable_name(entity_variable).c_str());
		}
	}
	else {
		regen_exp(finfo, entity_variable_initial);
		sprintf(codegen_buf, "%s %s = %s", type_str.c_str(), get_variable_name(entity_variable).c_str(), entity_variable_initial.get_what().c_str());
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
		newvardef.addlist(type_nospec, variable_desc, kvparamtable.get(i)/*variable_entity*/);
		newvardef.setattr(variable_desc.attr->clone()); 
		newnode.addchild(newvardef);
	}
	return newnode;
}

void regen_type(ParseNode & type_nospec, FunctionInfo * finfo, VariableInfo * vinfo) {
	if (type_nospec.get_token() == TokenMeta::Implicit_Decl)
	{
		/*****************
		* type is implicit
		* if an variable is implicit defined, its type will be induced from its first letter
		* if an variable's type is deduced, it can be explicitly declared, e.g. `dimension a(10)`
		*=================
		* though `check_implicit_variable` will deduce all implicit variable's type and all Implicit_Decl type,
		*	it can't handle vardef nodes
		*****************/
		type_nospec.get_what() = gen_implicit_type(finfo, get_variable_name(vinfo->entity_variable)).get_what();
		type_nospec.setattr(new VariableDescAttr());
	}
	else {
		// X_Decl -> X
		type_nospec.get_token() = type_nospec.get_token() + 100;
	}
	promote_type(type_nospec, vinfo->desc);
}

void regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo) {
	VariableDesc & desc = vinfo->desc;
	ParseNode & entity_variable = vinfo->entity_variable;
	ParseNode & type_nospec = vinfo->type;
	bool do_arr = desc.slice.is_initialized();
	string var_decl, type_str;
	regen_type(type_nospec, finfo, vinfo);
	// entity_variable is NT_VARIABLE_ENTITY
	if(do_arr){
		// ARRAY
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		var_decl = gen_vardef_array_str(finfo, vinfo, entity_variable, type_str, get_lbound_size_from_slice(desc.slice.value()));
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicit defined
			vinfo->vardef_node = new ParseNode(gen_vardef_from_default(vinfo->type, vinfo->local_name));
		}
		vinfo->vardef_node->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else if (is_function_array(entity_variable)) {
		// FOR70 ARRAY
		ParseNode & entity_variable_name = entity_variable.get(0);
		// add slice attribute to vardescattr.desc
		ParseNode & argtable = entity_variable_name.get(1);
		desc.slice = argtable;
		// get slice info
		SliceBoundInfo ls = get_lbound_size_from_slice(argtable);
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		var_decl = gen_vardef_array_str(finfo, vinfo, entity_variable, type_str, ls);
		vinfo->vardef_node->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else {
		// SCALAR
		type_str = gen_qualified_typestr(type_nospec, desc, false);
		var_decl = gen_vardef_scalar_str(finfo, vinfo, entity_variable, type_str);
		if (vinfo->vardef_node == nullptr)
		{
			// considered to be implicitly defined
			fatal_error("variable not defined: "+ vinfo->local_name);
		}
		vinfo->vardef_node->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} 
	vinfo->commonblock_index; // set in regen_suite and gen_common
	vinfo->commonblock_name; // set in regen_suite and gen_common
	vinfo->desc = desc; // set in regen_vardef
	vinfo->implicit_defined; // set in regen_suite
	vinfo->type = type_nospec; // set in regen_vardef
	vinfo->entity_variable = entity_variable; // set in regen_vardef
}
