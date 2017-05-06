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

std::string regen_paramtable(const vector<tuple<string, ParseNode, ParseNode *>> & paramtable_info) {
	/* generate new paramtable with type */
	string paramtblstr;
	paramtblstr = make_str_list(paramtable_info.begin(), paramtable_info.end() - 1/* exclude return value */, [&](const tuple<string, ParseNode, ParseNode *> & param) -> std::string {
		string name = get<0>(param);
		const ParseNode & type = get<1>(param);
		ParseNode * vardef = get<2>(param);
		if (vardef == nullptr) {
			print_error("Error when trying to find variable/function " + name);
			return string("ERROR");
		}
		std::string typestr;
		if (type.fs.CurrentTerm.token == TokenMeta::Function_Decl) {
			typestr = type.to_string();
		}
		else {
			VariableDesc desc = get_variabledesc_attr(*vardef);
			typestr = gen_qualified_typestr(type, desc);
		}
		sprintf(codegen_buf, "%s %s", typestr.c_str(), name.c_str());
		return string(codegen_buf);
	});
	return paramtblstr;
}

void get_full_paramtable(FunctionInfo * finfo, bool is_subroutine) {
	// (var_name, var_type, ParseNode*)
	const vector<VariableInfo *> & declared_variables = finfo->funcdesc.declared_variables;
	vector<tuple<string, ParseNode, ParseNode *>> & paramtable_info = finfo->funcdesc.paramtable_info;
	// find by finfo
	for (int i = 0; i < (int)paramtable_info.size(); i++) // definition in paramtable
	{
		tuple<string, ParseNode, ParseNode *> & param = paramtable_info[i];
		string param_name = get<0>(param);
		ParseNode & param_type = get<1>(param);
		ParseNode *& param_vardef = get<2>(param);
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, param_name);

		if(vinfo != nullptr) // definition in suite
		{
			ParseNode * vardef = vinfo->vardef;
			if (vinfo->type.fs.CurrentTerm.token == TokenMeta::Function_Decl) {
				// function declared in an interface block
				FunctionInfo * interface_finfo = add_function("@", "", FunctionInfo{});
				regen_function(interface_finfo, *vardef); // regen interface function
				if (vardef->attr != nullptr) {
					FunctionAttr * interface_attr = dynamic_cast<FunctionAttr *>(vardef->attr);
					vector<tuple<string, ParseNode, ParseNode *>> & interface_paramtable_info = interface_attr->finfoptr->funcdesc.paramtable_info;
					string interface_paramtable_str = regen_paramtable(interface_paramtable_info);
					sprintf(codegen_buf, "std::function<%s(%s)>", get<1>(interface_paramtable_info.back()).to_string().c_str(), interface_paramtable_str.c_str());
					
					// set param_info for regen_paramtable
					vinfo->type = gen_type(Term{ TokenMeta::Function_Decl, string(codegen_buf) });
					param_type = vinfo->type;
					param_vardef = vardef;
					if (i != paramtable_info.size() - 1) {
						/* `delete` ParseNode except return value */
						vardef->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
						vinfo->declared = true;
					}
				}
				else {
					print_error("Invalid interface: " + vardef->fs.CurrentTerm.what);
				}
			}else {
				// variable
				ParseNode & entity_variable = vardef->get(2);
				ParseNode & initial = entity_variable.get(1);

				// set param_info for regen_paramtable
				param_type = vardef->get(0); // type_nospec
				param_vardef = vardef; // variable ParseNode
				if (i != paramtable_info.size() - 1) {
					/* `delete` ParseNode except return value */
					vardef->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
					vinfo->declared = true;
				}
			}
		}
		else {
			print_error("Implicit parameter: " + param_name);
		}
	}
	return;
}


ParseNode gen_function(ARG_IN variable_function, ARG_IN paramtable, ARG_IN variable_result, ARG_IN suite) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, ""});
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flatterned paramtable with all keyvalue elements
	newnode.addlist(ParseNode(), variable_function, kvparamtable, variable_result, suite);
	return newnode;
}

void regen_function(FunctionInfo * finfo, ARG_OUT functiondecl_node) {
	/* fortran90 does not declare type of arguments in function declaration statement*/
	// paramtable is raw for90 paramtable and every variable in the table has no type infomation
	ParseNode & variable_function = functiondecl_node.get(1);
	ParseNode & kvparamtable = functiondecl_node.get(2);
	ParseNode & variable_result = functiondecl_node.get(3);
	ParseNode & suite = functiondecl_node.get(4);
	ParseNode & oldsuite = suite;
	bool is_subroutine = variable_result.fs.CurrentTerm.what == "";
	
	// regen_suite
	regen_suite(finfo, oldsuite); 	
	// init paramtable
	std::vector<std::tuple<std::string, ParseNode, struct ParseNode *>> & paramtable_info = finfo->funcdesc.paramtable_info;
	/* add the paramtable */
	for (auto iter = kvparamtable.child.begin(); iter < kvparamtable.child.end(); iter++)
	{
		// 这里也需要check，以防参数表中参数在函数体中没有被使用
		check_implicit_variable(finfo, (*iter)->to_string());
		// refer to function suite and determine type of params
		paramtable_info.push_back(make_tuple((*iter)->to_string()
			, gen_type(Term{ TokenMeta::Void_Decl, "void" }), nullptr));
	}
	/* result variable must be the last one */
	check_implicit_variable(finfo, variable_result.to_string());
	paramtable_info.push_back(make_tuple(variable_result.to_string()
		, gen_type(Term{ TokenMeta::Void_Decl, "void" }), nullptr));// if subroutine get tuple ("", "void")

	get_full_paramtable(finfo, is_subroutine);
	// make newnode
	string newsuitestr = oldsuite.to_string();
	string paramtblstr = regen_paramtable(paramtable_info);

	std::string return_type_str = get<1>(paramtable_info.back()).to_string();
	/* generate function code */
	sprintf(codegen_buf, "%s %s(%s)\n{\n%s\treturn %s;\n}\n"
		, return_type_str.c_str() // return value type, "void" if subroutine
		, variable_function.to_string().c_str() // function name
		, paramtblstr.c_str() // paramtable
		, tabber(oldsuite.to_string()).c_str() // code
		, (is_subroutine ? "" : variable_result.to_string().c_str()) // add return stmt if not function
	);
	functiondecl_node.fs.CurrentTerm.what = string(codegen_buf);

	// log function and set attr 
	functiondecl_node.setattr(new FunctionAttr(finfo));

	// cleaning
	insert_temporary_variables("@", variable_function.fs.CurrentTerm.what);
	return ;
}
