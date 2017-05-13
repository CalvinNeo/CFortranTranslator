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

vector<ParseNode *> get_all_commons(FunctionInfo * finfo, ParseNode & suite) {
	/*****
	* find out all var_def and interface-function nodes
	* NOT including implicit declared variables
	*****/
	vector<ParseNode *> declared_commons;
	for (int i = 0; i < suite.length(); i++)
	{
		ParseNode & stmti = suite.get(i);
		if (stmti.get_token() == TokenMeta::NT_COMMONBLOCK) {
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
	if (oldsuite.get_token() == TokenMeta::NT_SUITE)
	{
		for (int i = 0; i < oldsuite.length(); i++)
		{
			ParseNode & stmt = oldsuite.get(i);
			if (stmt.get_token() == TokenMeta::Label) {
				int j = i + 1;
				if (j < oldsuite.length())
				{
					// make sure j in within bound
					ARG_IN next_stmt = oldsuite.get(j);
					if (next_stmt.get_token() == TokenMeta::NT_FORMAT)
					{
						// do not generate code for format stmt
					}
					else {
						sprintf(codegen_buf, "LABEL_%s:\n", stmt.get_what().c_str());
						newsuitestr += string(codegen_buf);
					}
				}
			}
			else {
				newsuitestr += regen_stmt(finfo, stmt);
			}
		}
	}
	else
	{
		// 有些时候是exp，例如if里面的条件语句
		newsuitestr += regen_stmt(finfo, oldsuite);
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
	if (!is_partial)
	{
		newsuitestr = gen_joined_declarations(finfo, oldsuite) + newsuitestr;
	}
	oldsuite.get_what() = newsuitestr;
}

std::string gen_joined_declarations(FunctionInfo * finfo, ARG_OUT oldsuite) {
	/**********************************
	*	for all variables used in the subprogram, cal regen_vardef to generate their code
	*	there're 2 cases:
	*	1) this variable is declared by a explicit statement
	*	2) this variable is used implicitly
	because the rule can be override by case 1(5.1.1), so it must be until all variables are "regen"ed,
	when we join declarations of all variables together
	considering `COMMON` block, muse consider the following 2 cases:
	*	3) this variable is used implicitly, and is in a declared common block
	*	4) this variable is declared by a explicit statement, and is in a declared common block
	***********************************/
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
		VariableInfo * vinfo = p.second;
		string local_name = vinfo->local_name;
		ParseNode & entity_variable = vinfo->entity_variable;
		VariableDesc & desc = vinfo->desc;
		ParseNode & local_type = vinfo->type;
		//ParseNode & vardef_node = vinfo->vardef_node; 不要使用这个局部变量因为vinfo->vardef_node是会变的（如果是nullptr会在regen_vardef中补上）
		if (p.second->declared)
		{
			fatal_error("Pre-declared variable encountered");
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
			else if (vinfo->vardef_node == nullptr) {
				// implicit definition
				fatal_error("vinfo->vardef_node is nullptr");
				regen_vardef(finfo, vinfo, local_type, desc, entity_variable);
			}
			else {
				// normal definition
				regen_vardef(finfo, vinfo, local_type, desc, entity_variable);
			}
		}
	});

	/**********************************
	*	join declarations of all variables together
	***********************************/
	string variable_declarations;
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
		VariableInfo * vinfo = p.second;
		string local_name = vinfo->local_name;
		ParseNode & entity_variable = vinfo->entity_variable;
		VariableDesc & desc = vinfo->desc;
		ParseNode & local_type = vinfo->type;
		if (p.second->declared)
		{
			fatal_error("Pre-declared variable encountered");
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
				if (vinfo->type.get_token() == TokenMeta::Function_Decl)
				{
					// interface
					sprintf(codegen_buf, "");
				}
				else {
					sprintf(codegen_buf, "%s;\n", vinfo->vardef_node->to_string().c_str());
				}
			}
		}
		variable_declarations += string(codegen_buf);
	});
	return variable_declarations;
}