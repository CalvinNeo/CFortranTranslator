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

std::string gen_paramtable_str(FunctionInfo * finfo, const vector<string> & paramtable_info) {
	// generate C++ style parameter list
	string paramtblstr;
	paramtblstr = make_str_list(paramtable_info.begin(), paramtable_info.end() - 1/* exclude return value */, [&](const string & param_name) -> std::string {
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, param_name);
		const ParseNode & type = vinfo->type;
		ParseNode * vardef_node = vinfo->vardef_node;
		if (vardef_node == nullptr) {
			fatal_error("Error when trying to find variable/function " + param_name);
		}
		/****************
		* IMPORTANT
		* it's wrong to use `get_variabledesc_attr(*vardef_node)`, it will fail when `dimension arr(10)`
		*****************/
		VariableDesc desc = vinfo->desc;
		std::string typestr = gen_qualified_typestr(type, desc, true);
		sprintf(codegen_buf, "%s %s", typestr.c_str(), param_name.c_str());
		return string(codegen_buf);
	});
	return paramtblstr;
}

void get_full_paramtable(FunctionInfo * finfo) {
	const vector<VariableInfo *> & declared_variables = finfo->funcdesc.declared_variables;
	vector<string> & paramtable_info = finfo->funcdesc.paramtable_info;
	// find by finfo
	for (int i = 0; i < (int)paramtable_info.size(); i++) 
	{
		string param_name = paramtable_info[i];
		if (param_name == "")
		{
			/****************
			* refer `regen_function`
			* if param_name == "", this param is a return variable placeholder of subroutine,
			* so do not generate
			*****************/
			continue;
		}
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, param_name);

		if(vinfo != nullptr) // definition in suite
		{
			if (vinfo->type.get_token() == TokenMeta::Function) {
				// function declared in an interface block
				ParseNode * funcdef_node = vinfo->vardef_node;
				FunctionInfo * interface_finfo = add_function("@", "", FunctionInfo{});
				regen_function(interface_finfo, *funcdef_node); // regen interface function
				if (funcdef_node->attr != nullptr) {
					std::vector<std::string> & interface_paramtable_info = interface_finfo->funcdesc.paramtable_info;
					string interface_paramtable_str = gen_paramtable_str(interface_finfo, interface_paramtable_info);
					string interface_result_name = interface_paramtable_info.back();
					VariableInfo * interface_return_vinfo = get_variable(get_context().current_module, interface_finfo->local_name, interface_result_name);
					sprintf(codegen_buf, "std::function<%s(%s)>", interface_return_vinfo->type.get_what().c_str(), interface_paramtable_str.c_str());
					
					// set param_info for `regen_paramtable`
					vinfo->type = gen_type(Term{ TokenMeta::Function, string(codegen_buf) });

					if (i != paramtable_info.size() - 1) {
						// `delete` ParseNode except return value 
						vinfo->declared = true;
					}
				}
				else {
					print_error("Invalid interface: " + funcdef_node->get_what());
				}
			}else {
				ParseNode * vardef_node = vinfo->vardef_node;
				// variable
				ParseNode & entity_variable = vardef_node->get(2);
				ParseNode & initial = entity_variable.get(1);

				// set param_info for `regen_paramtable`
				if (i != paramtable_info.size() - 1) {
					// `delete` ParseNode except return value 
					vinfo->declared = true;
				}
			}
		}
		else {
			print_error("parameter is not defined: " + param_name);
		}
	}
	return;
}


ParseNode gen_function(ARG_IN variable_function, ARG_IN paramtable, ARG_IN variable_result, ARG_IN suite) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, ""});
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flatterned parameter list with all keyvalue elements
	newnode.addlist(ParseNode(), variable_function, kvparamtable, variable_result, suite);
	return newnode;
}

void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node) {
	/****************
	*	fortran90 does not declare type of arguments in function declaration statement
	*****************/
	ParseNode & variable_function = functiondecl_node.get(1);
	ParseNode & kvparamtable = functiondecl_node.get(2);
	ParseNode & result_variable = functiondecl_node.get(3);
	ParseNode & suite = functiondecl_node.get(4);
	ParseNode & oldsuite = suite;
	string result_name = result_variable.get_what();
	bool is_subroutine = result_name == "";
	
	/****************
	* compose parameter list
	*****************/
	std::vector<std::string> & paramtable_info = finfo->funcdesc.paramtable_info;
	for (auto iter = kvparamtable.begin(); iter < kvparamtable.end(); iter++)
	{
		/****************
		* `check_implicit_variable` is IMPORTANT here, 
		*	to prevent situation that
		*	a variable is only used in parameter list, 
		*	and not appear in function body(so it will not checked by `regen_exp`)
		*****************/
		check_implicit_variable(finfo, (*iter)->get_what());
		// refer to function suite and determine type of params
		paramtable_info.push_back((*iter)->get_what());
	}
	/****************
	* create a placeholder for return variable
	*================
	* `check_implicit_variable` is IMPORTANT here too
	* if result_variable is "", this function will have a local variable will have a varialbe whose name is "",
	*	then error will occurred, code like `double ;` will be generated
	*================
	* push result variable to the back of the paramtable_info stack
	* type of result variable is set by default `void`, 
	*	so if this subprogram is a subroutine with no result variable,
	*	it'll set by default `void`
	*****************/
	if (is_subroutine)
	{
	}
	else {
		check_implicit_variable(finfo, result_variable.get_what());
	}
	paramtable_info.push_back(result_variable.get_what()); 

	// regen_suite
	regen_suite(finfo, oldsuite);
	// make newnode
	string paramtblstr = gen_paramtable_str(finfo, paramtable_info);

	VariableInfo * result_vinfo = get_variable(get_context().current_module, finfo->local_name, result_name);
	std::string result_type_str;
	if (is_subroutine)
	{
		// subroutine
		result_type_str = "void";
	}else{
		result_type_str = gen_qualified_typestr( result_vinfo->type, result_vinfo->desc, false);
	}
	// generate function code 
	sprintf(codegen_buf, "%s %s(%s)\n{\n%s\treturn %s;\n}\n"
		, result_type_str.c_str() // return value type, "void" if subroutine
		, variable_function.to_string().c_str() // function name
		, paramtblstr.c_str() // parameter list
		, tabber(oldsuite.to_string()).c_str() // code
		, (is_subroutine ? "" : result_name.c_str()) // add return stmt if not function
	);
	functiondecl_node.get_what() = string(codegen_buf);

	// log function and set attr 
	functiondecl_node.setattr(new FunctionAttr(finfo));

	// cleaning
	return ;
}

FunctionInfo * check_implicit_function(FunctionInfo * finfo, const std::string & name) {
	/******************
	* call-stmt 
	* e.g.
	*	```
	*	call func
	*	```
	* `func` is not a variable, but a function
	* SHOULDN"T GENERATE VARDEF FOR `func`
	*******************/
	FunctionInfo * ineer_info = get_function(get_context().current_module, name);

	return ineer_info;
}