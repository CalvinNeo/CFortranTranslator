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

void regen_simple_stmt(FunctionInfo * finfo, ARG_OUT stmt) {
	// exp and let_stmt
	if (stmt.child.size() > 0)
	{
		ParseNode & exp = stmt.get(0);
		regen_exp(finfo, exp);
	}
	else {
		// dummy
	}
}

vector<VariableInfo *> get_all_declared_by_log(FunctionInfo * finfo, ParseNode & suite) {
	vector<VariableInfo *> declared_variables_and_functions;
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> p) {
		declared_variables_and_functions.push_back(p.second);
	});
	return declared_variables_and_functions;
}

vector<ParseNode *> get_all_declared_by_node(FunctionInfo * finfo, ParseNode & suite) {
	/*
	* find out all var_def and interface-function nodes
	* NOT including implicit declared variables
	*/
	// vector<ParseNode *> dd = get_all_declared(get_context().current_module, finfo->local_name);
	vector<ParseNode *> declared_variables;
	for (int i = 0; i < (int)suite.child.size(); i++)
	{
		ParseNode & stmti = suite.get(i);
		if (stmti.fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINESET) {
			ParseNode & vardef_set = stmti;
			declared_variables.insert(declared_variables.end(), vardef_set.child.begin(), vardef_set.child.end());
		}
		else if (stmti.fs.CurrentTerm.token == TokenMeta::NT_INTERFACE && stmti.child.size() > 0) {
			// interface function
			ParseNode & wrappers = stmti.get(0);
			for (int i = 0; i < wrappers.child.size(); i++)
			{
				ParseNode & wrapper = wrappers.get(i);
				if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM) {
					fatal_error("no program in interface");
				}
				else if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
					// wrapper.child[1] is function name
					declared_variables.push_back(const_cast<ParseNode *>(&wrapper));
				}
			}
		}
	}
	return declared_variables;
}
vector<ParseNode *> get_all_commons(FunctionInfo * finfo, ParseNode & suite) {
	/*
	* find out all var_def and interface-function nodes
	* NOT including implicit declared variables
	*/
	// vector<ParseNode *> dd = get_all_declared(get_context().current_module, finfo->local_name);
	vector<ParseNode *> declared_commons;
	for (int i = 0; i < (int)suite.child.size(); i++)
	{
		ParseNode & stmti = suite.get(i);
		if (stmti.fs.CurrentTerm.token == TokenMeta::NT_COMMONBLOCK) {
			declared_commons.push_back(&stmti);
		}
	}
	return declared_commons;
}
void regen_suite(FunctionInfo * finfo, ARG_OUT oldsuite, bool is_partial) {
	/**** 
	 * this function regen code of `suite` node and 
	 * 1. remove all NT_DECLAREDVARIABLE in suite
	 * 2. regen_vardef 
	 ****/
	std::string newsuitestr;
	for (int i = 0; i < oldsuite.child.size(); i++)
	{
		ParseNode & stmt = oldsuite.get(i);
		/*** including:
		*	exp							NT_STATEMENT
		*	let_stmt					NT_STATEMENT
		*	control_stmt				NT_CONTROL_STMT
		*	format						NT_FORMAT
		*	var_def						NT_VARIABLEDEFINE
		*	comment						Comment
		*	common						NT_COMMONBLOCK
		*	dummy						NT_DUMMY
		*	interface(in suite rule)	NT_INTERFACE
		*	labelin suite rule)			Label
		*	input_stmt, output_stmt		NT_READ_STMT, NT_WRITE_STMT, NT_PRINT_STMT
		*	compound_stmt				NT_IF, ...
		***/
		// exp, leet_stmt, control_stmt
		if (stmt.fs.CurrentTerm.token == TokenMeta::NT_STATEMENT) {
			regen_simple_stmt(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_CONTROL_STMT) {
			if (stmt.child.size() > 0 && stmt.get(0).fs.CurrentTerm.token == TokenMeta::Return) {
				//sprintf(codegen_buf, "return %s;", finfo->funcdesc.declared_variables.back()->fs.CurrentTerm.what.c_str());
				newsuitestr += stmt.fs.CurrentTerm.what;
				newsuitestr += '\n';
			}
			else {
				newsuitestr += stmt.fs.CurrentTerm.what;
				newsuitestr += '\n';
			}
		}
		// format
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_FORMAT) {
		
		}
		// var_def
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINESET)
		{
			ParseNode & vardef_set = stmt;
			// examine all variable define stmt
			for (int j = 0; j < vardef_set.child.size(); j++)
			{
				ParseNode & vardef = vardef_set.get(j);
				ParseNode & type_nospec = vardef.get(0);
				ParseNode & vardescattr = vardef.get(1);
				ParseNode & entity_variable = vardef.get(2);
				std::string name = get_variable_name( entity_variable );
				if (get_function("", name) != nullptr) {
					// declared function
				}
				else {
					if (vardef.fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						// for every variable, generate independent definition
						VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
						bool belong_to_common_block = (vinfo != nullptr && vinfo->commonblock_name == "");
						if (belong_to_common_block)
						{
							vinfo->desc.merge(get_variabledesc_attr(vardescattr));
						}
						else {
							// `regen_vardef` will be called in the end
							vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
							vinfo->commonblock_index = 0; // set in regen_suite and gen_common
							vinfo->commonblock_name = ""; // set in regen_suite and gen_common
						}
						vinfo->desc = get_variabledesc_attr(vardescattr); // set in regen_vardef
						vinfo->implicit_defined = false; // set in regen_suite and regen_common
						vinfo->type = type_nospec; // set in regen_vardef
						vinfo->entity_variable = entity_variable; // set in regen_vardef
						vinfo->vardef = &vardef; // set in regen_vardef
					}
					else if (vardef.fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE) {
						// declared variable
					}
				}
			}
		}
		// comment
		else if (stmt.fs.CurrentTerm.token == TokenMeta::Comments) {
			
		}
		// common
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_COMMONBLOCK) {
			regen_common(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
		}
		// dummy
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {

		}
		// interface
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_INTERFACE) {
			ParseNode & wrappers = stmt.get(0);
			for (int i = 0; i < wrappers.child.size(); i++)
			{
				ParseNode & wrapper = wrappers.get(i);
				if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM) {
					fatal_error("illegal program struct in interface");
				}
				else if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
					// wrapper.child[1] is function name
					string name = wrapper.get(1).to_string();
					VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
					if (vinfo == nullptr)
					{
						ParseNode t = gen_type(Term{ TokenMeta::Function_Decl, "" });
						vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
						vinfo->commonblock_index = 0; // set in regen_suite and gen_common
						vinfo->commonblock_name = ""; // set in regen_suite and gen_common
						vinfo->desc = VariableDesc(); // set in regen_vardef
						vinfo->implicit_defined = false; // set in regen_suite and regen_common
						vinfo->type = t; // set in regen_vardef
						vinfo->entity_variable = gen_vardef_from_implicit(t, ""); // set in regen_vardef
						vinfo->vardef = &wrapper; // set in regen_vardef
					}
				}
			}
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::Label) {
			int j = i + 1;
			if (j < oldsuite.child.size())
			{
				ARG_IN next_stmt = oldsuite.get(j);
				if (next_stmt.fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{

				}
				else {
					sprintf(codegen_buf, "LABEL_%s:\n", stmt.to_string().c_str());
					newsuitestr += string(codegen_buf);
				}
			}
			
		}
		// input/output stmt
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_READ_STMT) {
			regen_read(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_WRITE_STMT) {
			regen_write(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_PRINT_STMT) {
			regen_print(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
		}
		// compound stmt
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_DO) {
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_IF) {
			regen_if(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_ELSEIF) {
			regen_elseif(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_DO) {
			regen_do(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_DORANGE) {
			regen_do_range(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_WHILE) {
			regen_do_while(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_SELECT) {
			regen_select(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
		else {
			// normal stmt
			print_error("Unknown Statement", stmt);
		}
	}
	// 这部分一定要放在commonblock检查之后
	// call `regen_` 
	if (!is_partial)
	{
		forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
			VariableInfo * vinfo = p.second;
			string local_name = vinfo->local_name;
			ParseNode & entity_variable = vinfo->entity_variable;
			VariableDesc & desc = vinfo->desc;
			ParseNode & local_type = vinfo->type;
			//ParseNode & vardef = vinfo->vardef; 不要使用这个局部变量因为vinfo->vardef是会变的（如果是nullptr会在regen_vardef中补上）
			if (p.second->declared)
			{
				fatal_error("Pre-declared variable");
			}
			else {
				if (p.second->commonblock_name != "") {
					// definition in common block
					desc.reference = true;
					regen_vardef(finfo, vinfo, local_type, desc, entity_variable);

					// set common
					auto common_info = get_context().commonblocks.find(vinfo->commonblock_name);
					if (common_info == get_context().commonblocks.end()) {
						fatal_error("can't find common");
					}
					else {
						common_info->second.variables[vinfo->commonblock_index].desc = desc;
						common_info->second.variables[vinfo->commonblock_index].type = local_type;
					}
				}
				else if (vinfo->vardef == nullptr) {
					// implicit definition
					regen_vardef(finfo, vinfo, local_type, desc, entity_variable);
				}
				else {
					// normal definition
					regen_vardef(finfo, vinfo, local_type, desc, entity_variable);
				}
			}
		});
	}

	// mark `VariableInfo::declared`
	std::vector<VariableInfo *> declared_variables = get_all_declared(finfo, oldsuite);
	std::vector<ParseNode *> declared_commons = get_all_commons(finfo, oldsuite);
	if (!is_partial)
	{
		finfo->funcdesc.declared_variables = declared_variables;
		finfo->funcdesc.declared_commons = declared_commons;
	}
	else {
		finfo->funcdesc.declared_variables.insert(finfo->funcdesc.declared_variables.end(), declared_variables.begin(), declared_variables.end());
		finfo->funcdesc.declared_commons.insert(finfo->funcdesc.declared_commons.end(), declared_commons.begin(), declared_commons.end());
	}

	// generate code
	if (!is_partial) {
		string variable_declarations;
		forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
			VariableInfo * vinfo = p.second;			
			string local_name = vinfo->local_name;
			ParseNode & entity_variable = vinfo->entity_variable;
			VariableDesc & desc = vinfo->desc;
			ParseNode & local_type = vinfo->type;
			if (p.second->declared)
			{
			}
			else {
				if (p.second->commonblock_name != "") {
					// definition in common block
					std::string common_varname = "_" + to_string(vinfo->commonblock_index + 1);
					sprintf(codegen_buf, "%s %s = %s.%s;\n", gen_qualified_typestr(local_type, desc).c_str()
						, local_name.c_str(), vinfo->commonblock_name.c_str(), common_varname.c_str());
				}
				else {
					// normal definition and implicit definition
					if (vinfo->type.fs.CurrentTerm.token == TokenMeta::Function_Decl)
					{

					}
					sprintf(codegen_buf, "%s;\n", vinfo->vardef->to_string().c_str());
				}
			}
			variable_declarations += string(codegen_buf);
		});
		newsuitestr = variable_declarations + newsuitestr;
	}
	oldsuite.fs.CurrentTerm.what = newsuitestr;
	//// CAN NOT call `clear_temporary_variables()` HERE
}