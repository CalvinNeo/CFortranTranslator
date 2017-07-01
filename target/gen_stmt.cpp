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

void regen_simple_stmt(FunctionInfo * finfo, ParseNode & stmt) {
	if (stmt.length() == 0)
	{
		// dummy
	}
	else {
		/************
		*	NT_EXPRESSION, NT_FUNCTIONARRAY, NT_HIDDENDO, etc
		*	are all types of exp. refer `is_exp`
		*************/
		ParseNode & exp = stmt.get(0);
		regen_exp(finfo, exp);
		stmt.get_what() = exp.get_what() + ";";
	}
}

vector<VariableInfo *> get_all_declared_vinfo(FunctionInfo * finfo, ARG_IN suite) {
	vector<VariableInfo *> declared_variables_and_functions;
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> p) {
		declared_variables_and_functions.push_back(p.second);
	});
	return declared_variables_and_functions;
}

vector<ParseNode *> get_all_declared_by_node(FunctionInfo * finfo, ParseNode & suite) {
	/***************
	* find out all explicit declarations of variables and interface in a function
	*	, by enumerating all nodes
	* NOT including implicit declared variables
	***************/
	vector<ParseNode *> declared_variables;
	for (int i = 0; i < suite.length(); i++)
	{
		ParseNode & stmti = suite.get(i);
		if (stmti.get_token() == TokenMeta::NT_VARIABLEDEFINESET) {
			ParseNode & vardef_set = stmti;
			declared_variables.insert(declared_variables.end(), vardef_set.begin(), vardef_set.end());
		}
		else if (stmti.get_token() == TokenMeta::NT_INTERFACE && stmti.length() > 0) {
			// interface function
			ParseNode & wrappers = stmti.get(0);
			for (int i = 0; i < wrappers.length(); i++)
			{
				ParseNode & wrapper = wrappers.get(i);
				if (wrapper.get_token() == TokenMeta::NT_PROGRAM) {
					fatal_error("no program in interface");
				}
				else if (wrapper.get_token() == TokenMeta::NT_FUNCTIONDECLARE) {
					// wrapper.child[1] is function name
					declared_variables.push_back(const_cast<ParseNode *>(&wrapper));
				}
			}
		}
	}
	return declared_variables;
}


std::string regen_stmt(FunctionInfo * finfo, ParseNode & stmt) {
	/***************
	*	including:
	*	exp							NT_STATEMENT
	*	let_stmt					NT_STATEMENT
	*	control_stmt				NT_CONTROL_STMT
	*	format						NT_FORMAT
	*	var_def						NT_VARIABLEDEFINE
	*	comment						Comment
	*	common						NT_COMMONBLOCK
	*	dummy						NT_DUMMY
	*	interface(in suite rule)	NT_INTERFACE
	*	label(in suite rule)		Label
	*	io_stmt						NT_READ_STMT, NT_WRITE_STMT, NT_PRINT_STMT
	*	compound_stmt				NT_IF, ...
	***************/
	std::string newsuitestr;
	int comment_start = -1;
	// exp, leet_stmt, control_stmt
	if (stmt.get_token() == TokenMeta::NT_STATEMENT) {
		regen_simple_stmt(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
		comment_start = 1;
	}
	else if (stmt.get_token() == TokenMeta::NT_CONTROL_STMT) {
		if (stmt.length() > 0 && stmt.get(0).get_token() == TokenMeta::Return) {
			//sprintf(codegen_buf, "return %s;", finfo->funcdesc.declared_variables.back()->get_what().c_str());
			newsuitestr += stmt.get_what();
			newsuitestr += '\n';
		}
		else {
			newsuitestr += stmt.get_what();
			newsuitestr += '\n';
		}
	}
	// format
	else if (stmt.get_token() == TokenMeta::NT_FORMAT) {

	}
	// var_def
	else if (stmt.get_token() == TokenMeta::NT_VARIABLEDEFINESET)
	{
		ParseNode & vardef_set = stmt;
		// examine all variable define stmt
		for (int j = 0; j < vardef_set.length(); j++)
		{
			ParseNode & vardef_node = vardef_set.get(j);
			if (vardef_node.get_token() == TokenMeta::Comments)
			{
				comment_start = j;
				break;
			}
			ParseNode & type_nospec = vardef_node.get(0);
			ParseNode & vardescattr = vardef_node.get(1);
			ParseNode & entity_variable = vardef_node.get(2);
			std::string name = get_variable_name(entity_variable);
			if (get_function("", name) != nullptr) {
				// declared function
			}
			else {
				if (vardef_node.get_token() == TokenMeta::NT_VARIABLEDEFINE) {
					// for every variable, generate independent definition
					VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
					bool belong_to_common_block = (vinfo != nullptr && vinfo->commonblock_name == "");
					if (belong_to_common_block)
					{
						vinfo->desc.merge(get_variabledesc_attr(vardescattr));
					}
					else if(vinfo == nullptr){
						// `regen_vardef` will be called in `gen_joined_declarations`
						vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
						vinfo->commonblock_index = 0; // set in regen_suite and gen_common
						vinfo->commonblock_name = ""; // set in regen_suite and gen_common
					}
					if (is_function_array(entity_variable))
					{
						
					}
					else if (entity_variable.get_token() == TokenMeta::NT_EXPRESSION)
					{

					}
					vinfo->desc = get_variabledesc_attr(vardescattr); // set in regen_vardef
					vinfo->implicit_defined = false; // set in regen_suite and regen_common
					vinfo->type = type_nospec; // set in regen_vardef
					vinfo->entity_variable = entity_variable; // set in regen_vardef
					vinfo->vardef_node = &vardef_node; // set in regen_vardef
				}
				else if (vardef_node.get_token() == TokenMeta::NT_DECLAREDVARIABLE) {
					// declared variable
					fatal_error("NT_DECLAREDVARIABLE is removed");
				}
			}
		}
	}
	// comment
	else if (stmt.get_token() == TokenMeta::Comments) {
		newsuitestr += stmt.get_what();
		newsuitestr += "\n";
	}
	// common
	else if (stmt.get_token() == TokenMeta::NT_COMMONBLOCK) {
		regen_common(finfo, stmt);
		newsuitestr += stmt.get_what();
	}
	// dummy
	else if (stmt.get_token() == TokenMeta::NT_DUMMY) {

	}
	// interface
	else if (stmt.get_token() == TokenMeta::NT_INTERFACE) {
		ParseNode & wrappers = stmt.get(0);
		for (int i = 0; i < wrappers.length(); i++)
		{
			ParseNode & wrapper = wrappers.get(i);
			if (wrapper.get_token() == TokenMeta::NT_PROGRAM) {
				fatal_error("illegal program struct in interface");
			}
			else if (wrapper.get_token() == TokenMeta::NT_FUNCTIONDECLARE) {
				// wrapper.child[1] is function name
				string name = wrapper.get(1).get_what();
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
					vinfo->entity_variable = gen_vardef_from_default(t, ""); // set in regen_vardef
					vinfo->vardef_node = &wrapper; // set in regen_vardef
				}
				else {
					print_error("repeated declaration of interface");
				}
			}
		}
	}
	// input/output stmt
	else if (stmt.get_token() == TokenMeta::NT_READ_STMT) {
		regen_read(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	else if (stmt.get_token() == TokenMeta::NT_WRITE_STMT) {
		regen_write(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	else if (stmt.get_token() == TokenMeta::NT_PRINT_STMT) {
		regen_print(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	// compound stmt
	else if (stmt.get_token() == TokenMeta::NT_DO) {
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_IF) {
		regen_if(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_ELSEIF) {
		regen_elseif(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_DO) {
		regen_do(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_DORANGE) {
		regen_do_range(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_WHILE) {
		regen_do_while(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.get_token() == TokenMeta::NT_SELECT) {
		regen_select(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else {
		// normal stmt
		print_error("Unknown Statement", stmt);
	}
	for (int i = 0; i < stmt.length(); i++)
	{
		if (stmt.get(i).get_token() == TokenMeta::Comments)
		{
			newsuitestr += stmt.get(i).get_what();
			newsuitestr += "\n";
		}
	}
	return newsuitestr;
}
