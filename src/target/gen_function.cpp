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

std::string gen_paramtable_str(FunctionInfo * finfo, const vector<string> & paramtable_info, bool with_name) {
	// generate C++ style parameter list for function def or decl
	string paramtblstr;
	vector<string>::const_iterator end_except_result = paramtable_info.end() - 1;
	paramtblstr = make_str_list(paramtable_info.begin(), end_except_result, [&](const string & param_name) -> std::string {
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, param_name);
		const ParseNode & type = vinfo->type;
		ParseNode * vardef_node = vinfo->vardef_node;
		if (vardef_node == nullptr) {
			fatal_error("Error when trying to find variable/function " + param_name);
		}
		/****************
		* IMPORTANT
		* it's wrong to use `get_variabledesc_attr(*vardef_node)`, it will fail when `dimension arr(10)`
		* because `vardef_node` is raw
		*****************/
		VariableDesc desc = vinfo->desc;
		std::string typestr = gen_qualified_typestr(type, desc, true);
		if (with_name)
		{
			// generate def
			sprintf(codegen_buf, "%s %s", typestr.c_str(), param_name.c_str());
		}
		else {
			// generate decl
			sprintf(codegen_buf, "%s", typestr.c_str());
		}
		return string(codegen_buf);
	});
	return paramtblstr;
}

void get_full_paramtable(FunctionInfo * finfo) {
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
			if (vinfo->type.token_equals(TokenMeta::Function)) {
				// function declared in an interface block
				ParseNode * funcdef_node = vinfo->vardef_node;
				FunctionInfo * interface_finfo = add_function(get_context().current_module, finfo->local_name + "@" + vinfo->local_name, FunctionInfo{});
				interface_finfo->local_name = vinfo->local_name;
				regen_function(interface_finfo, *funcdef_node); // regen interface function
				if (funcdef_node->attr != nullptr) {
					vinfo->type = gen_type(Term{ TokenMeta::Function, gen_function_signature(interface_finfo, 1) });

					if (i + 1 != paramtable_info.size()) {
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
				if (i + 1 != paramtable_info.size()) {
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

void regen_function_1(FunctionInfo * finfo, ParseNode & functiondecl_node) {
	ParseNode & variable_function = functiondecl_node.get(1);
	assert(variable_function.get_what() == finfo->local_name);
	ParseNode & kvparamtable = functiondecl_node.get(2);
	ParseNode & result_variable = functiondecl_node.get(3);
	ParseNode & suite = functiondecl_node.get(4);

	finfo->result_name = result_variable.get_what();
	finfo->suite = &suite;
	finfo->node = &functiondecl_node;
	ParseNode & oldsuite = *finfo->suite;

	// log function and set attr 
	functiondecl_node.setattr(new FunctionAttr(finfo));

	/****************
	* compose parameter list
	*****************/
	std::vector<std::string> & paramtable_info = finfo->funcdesc.paramtable_info;
	regen_paramtable(finfo, kvparamtable);
	for (auto iter = kvparamtable.begin(); iter < kvparamtable.end(); iter++)
	{
		/****************
		* `check_implicit_variable` is IMPORTANT here,
		*	to prevent situation that
		*	a variable is only used in parameter list,
		*	and not appear in function body(so it will not checked by `regen_exp`)
		*****************/
		ParseNode * p = *iter;
		ParseNode & pn = *p;
		check_implicit_variable(finfo, pn.get_what());
		// refer to function suite and determine type of params
		paramtable_info.push_back(pn.get_what());
	}
	/****************
	* create a placeholder for return variable
	*================
	* `check_implicit_variable` is IMPORTANT here too
	* if result_variable is "", this function will have a local variable will have a varialbe whose name is "",
	* then error will occurred, code like `double ;` will be generated
	*================
	* push result variable to the back of the paramtable_info stack
	* type of result variable is set by default `void`,
	* so if this subprogram is a subroutine with no result variable,
	* it'll set by default `void`
	*****************/
	if (finfo->is_subroutine())
	{
	}
	else {
		check_implicit_variable(finfo, result_variable.get_what());
	}
	paramtable_info.push_back(result_variable.get_what());

	// regen_suite
	regen_suite(finfo, oldsuite);
}

void regen_function_2(FunctionInfo * finfo) {
	/****************
	* IMPORTANT
	* MUST split regen_function into two parts `regen_function_1` and `regen_function_2`
	* or some functions will have error definition about common block variables
	* e.g. should be `farray<int>` but actually `int`
	*================
	* REF `regen_all_variables_decl_str` for detailed reasons
	* `regen_all_variables_decl_str` MUST BE AFTER all common blocks in this program are handled.
	* because common definition can "rewrite" a variable's attribute, which is often inferred implicitly by their names
	*----------------
	* so in `gen_program`, the FIRST loop iterates over all functions and calls `regen_function_1` to each of them. 
	* after this procedure, all common blocks are found.
	* then `gen_common_definition` are called to each of the common blocks to regen common definition
	* finally, the SECOND loop iterates over all functions and calls `regen_function_2` to each of them. 
	* e.g.
	*****************/
	ParseNode & oldsuite = *finfo->suite;
	ParseNode & decl_node = *finfo->node;

	regen_all_variables_decl_str(finfo, oldsuite);

	// gen signature
	std::string signature = gen_function_signature(finfo);

	// generate function code 
	sprintf(codegen_buf, "%s\n{\n%s\treturn %s;\n}\n"
		, signature.c_str()
		, tabber(oldsuite.to_string()).c_str() // code
		, (finfo->is_subroutine() ? "" : finfo->result_name.c_str()) // add return stmt if not function
	);
	decl_node.get_what() = string(codegen_buf);
}

void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node) {
	/****************
	* fortran90 does not declare type of arguments in function declaration statement
	*****************/
	regen_function_1(finfo, functiondecl_node);
	regen_function_2(finfo);
	return;
}

std::string gen_function_signature(FunctionInfo * finfo, int style) {
	bool is_subroutine = finfo->result_name == "";
	std::string result_type_str;
	VariableInfo * result_vinfo = get_variable(get_context().current_module, finfo->local_name, finfo->result_name);
	if (is_subroutine)
	{
		// subroutine
		result_type_str = "void";
	}
	else {
		result_type_str = gen_qualified_typestr(result_vinfo->type, result_vinfo->desc, false);
	}
	if (style == 0)
	{
		// forward declaration
		std::string paramtblstr = gen_paramtable_str(finfo, finfo->funcdesc.paramtable_info, true);
		sprintf(codegen_buf, "%s %s(%s)"
			, result_type_str.c_str() // return value type, "void" if subroutine
			, finfo->local_name.c_str() // function name
			, paramtblstr.c_str() // parameter list
		);
	}
	else if (style == 1)
	{
		// std::function<> declaration
		std::string paramtblstr = gen_paramtable_str(finfo, finfo->funcdesc.paramtable_info, false);
		sprintf(codegen_buf, "std::function<%s(%s)>"
			, result_type_str.c_str() // return value type, "void" if subroutine
			, paramtblstr.c_str() // parameter list
		);
	} 
	return string(codegen_buf);
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

void regen_derived_type_1(TypeInfo* finfo, ParseNode& functiondecl_node) {
	ParseNode& variable_type = functiondecl_node.get(0);
	assert(variable_type.get_what() == finfo->local_name);
	//ParseNode& kvparamtable = functiondecl_node.get(1);
	ParseNode& suite = functiondecl_node.get(1);
	
	finfo->suite = &suite;
	finfo->node = &functiondecl_node;
	ParseNode& oldsuite = *finfo->suite;

	// log function and set attr 
	functiondecl_node.setattr(new FunctionAttr(finfo));

	/****************
	* compose parameter list
	*****************/
	//std::vector<std::string>& paramtable_info = finfo->funcdesc.paramtable_info;
	regen_paramtable(finfo, suite);
	//for (auto iter = kvparamtable.begin(); iter < kvparamtable.end(); iter++)
	//{
	//	/****************
	//	* `check_implicit_variable` is IMPORTANT here,
	//	*	to prevent situation that
	//	*	a variable is only used in parameter list,
	//	*	and not appear in function body(so it will not checked by `regen_exp`)
	//	*****************/
	//	ParseNode* p = *iter;
	//	ParseNode& pn = *p;
	//	check_implicit_variable(finfo, pn.get_what());
	//	// refer to function suite and determine type of params
	//	paramtable_info.push_back(pn.get_what());
	//}
	regen_suite(finfo, oldsuite);
}

void regen_derived_type_2(TypeInfo* tinfo) {
	ParseNode& oldsuite = *tinfo->suite;
	ParseNode& decl_node = *tinfo->node;
	
	regen_all_variables_decl_str(tinfo, oldsuite);

	// generate function code 
	sprintf(codegen_buf, "struct %s\n{\n%s};\n"
		, tinfo->local_name.c_str()
		, tabber(oldsuite.to_string()).c_str() // code
	);
	decl_node.get_what() = string(codegen_buf);
}
