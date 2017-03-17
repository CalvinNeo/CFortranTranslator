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
	for (int i = 0; i < paramtable_info.size() - 1 /* exclude return value */; i++)
	{
		if (i != 0)
			paramtblstr += ", ";
		ParseNode * vardef = get<2>(paramtable_info[i]);
		if (vardef == nullptr) {
			print_error("not find variable/function " + get<0>(paramtable_info[i]));
			continue;
		}
		
		if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE ||
			vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE)
		{
			VariableDesc desc = get_variabledesc_attr(*vardef);
			std::string typestr = gen_qualified_typestr(get<1>(paramtable_info[i]), desc);
			sprintf(codegen_buf, "%s %s", typestr.c_str(), get<0>(paramtable_info[i]).c_str());
			paramtblstr += string(codegen_buf);
		}
		else if (vardef->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
			paramtblstr += get<1>(paramtable_info[i]).fs.CurrentTerm.what;
			paramtblstr += " " + get<0>(paramtable_info[i]);
		}

	}
	return paramtblstr;
}

vector<tuple<string, ParseNode, ParseNode *>> get_full_paramtable(ARG_IN paramtable, ARG_IN variable_result, const vector<ParseNode *> & declared_variables, bool is_subroutine) {
	vector<tuple<string, ParseNode, ParseNode *>> paramtable_info; // (var_name, var_type, ParseNode*)
	/* add the paramtable */
	for (auto iter = paramtable.child.begin(); iter < paramtable.child.end(); iter++)
	{
		// refer to function suite and determine type of params
		paramtable_info.push_back(make_tuple((*iter)->fs.CurrentTerm.what
			, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr));
	}
	/* result variable must be the last one */
	paramtable_info.push_back(make_tuple(variable_result.fs.CurrentTerm.what
		, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr));// if subroutine get tuple ("", "void")

	for (int i = 0; i < (int)paramtable_info.size(); i++) // definition in paramtable
	{
		string varname = get<0>(paramtable_info[i]);
		auto declared_variables_iter = find_if(declared_variables.begin(), declared_variables.end(), [&](ParseNode * vardef) {
			if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE || vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE)
			{
				ParseNode & entity_variable = vardef->get(2);
				if (entity_variable.get(0).fs.CurrentTerm.what == varname) {
					return true;
				}
			}
			if (vardef->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE)
			{
				if (vardef->get(1).fs.CurrentTerm.what == varname) {
					return true;
				}
			}
			return false;
		});

		if(declared_variables_iter != declared_variables.end()) // definition in suite
		{
			// variable
			ParseNode * vardef = *declared_variables_iter;
			if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE || vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE){
				ParseNode & entity_variable = vardef->get(2);
				ParseNode & initial = entity_variable.get(1);
				get<1>(paramtable_info[i]) = vardef->get(0); // type_nospec
				get<2>(paramtable_info[i]) = vardef; // variable ParseNode
				if (i != paramtable_info.size() - 1) {
					/* `delete` ParseNode except return value */
					vardef->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
				}
			}
			else if (vardef->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
				// interface function
				string interface_paramtable_str = "";
				FunctionInfo * interface_finfo = add_function("@", "", FunctionInfo{});
				regen_function(interface_finfo, *vardef); // regen interface function
				if (vardef->attr != nullptr) {
					// variables declared in the interface block
					FunctionAttr * interface_attr = dynamic_cast<FunctionAttr *>(vardef->attr);
					vector<tuple<string, ParseNode, ParseNode *>> interface_paramtable = interface_attr->finfoptr->funcdesc.paramtable_info;
					for (int k = 0; k < interface_paramtable.size() - 1; k++)
					{
						if (k != 0)
							interface_paramtable_str += ", ";
						ParseNode * param_node = get<2>(interface_paramtable[k]);
						VariableDesc param_desc = get_variabledesc_attr(*param_node);
						std::string param_typestr = gen_qualified_typestr(get<1>(interface_paramtable[k]), param_desc);
						std::string param_name = get<0>(interface_paramtable[k]);
						sprintf(codegen_buf, "%s %s", param_typestr.c_str(), param_name.c_str());
						interface_paramtable_str += string(codegen_buf);
					}
					sprintf(codegen_buf, "std::function<%s(%s)>", get<1>(paramtable_info.back()).to_string().c_str(),interface_paramtable_str.c_str());
					get<1>(paramtable_info[i]) = gen_type(Term{ TokenMeta::Function_Def, string(codegen_buf) });
					get<2>(paramtable_info[i]) = vardef;
				}
				else {
					print_error("Invalid interface: " + vardef->fs.CurrentTerm.what);
				}
			}
		}
	}
	return paramtable_info;
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

	//// get all variables declared in this function
	//// 必须在regen_suite前面调用，这不是重复调用，目的是为了去掉DECARED_VARIABLE
	//vector<ParseNode *> declared_variables = get_all_declared(finfo, suite);
	//// get all params in paramtable of function declare (var_name, var_type, ParseNode*)
	//vector<tuple<string, ParseNode, ParseNode *>> paramtable_info = get_full_paramtable(kvparamtable, variable_result, declared_variables, is_subroutine);
	// regen_suite
	regen_suite(finfo, oldsuite); 
	vector<tuple<string, ParseNode, ParseNode *>> paramtable_info = get_full_paramtable(kvparamtable, variable_result, finfo->funcdesc.declared_variables, is_subroutine);
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
		, (is_subroutine ? "" : variable_result/* variable_result is raw for90 return without type*/.fs.CurrentTerm.what.c_str()) // add return stmt if not function
	);
	functiondecl_node.fs.CurrentTerm.what = string(codegen_buf);

	// log function and set attr 
	finfo->funcdesc.paramtable_info = paramtable_info;
	functiondecl_node.setattr(new FunctionAttr(finfo));

	// cleaning
	insert_temporary_variables("@", variable_function.fs.CurrentTerm.what);
	return ;
}
