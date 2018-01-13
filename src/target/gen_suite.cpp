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

std::vector<ParseNode *> get_all_commons(FunctionInfo * finfo, ParseNode & suite) {
	/*****
	* find out all var_def and interface-function nodes
	* NOT including implicit declared variables
	*****/
	std::vector<ParseNode *> declared_commons;
	for (ParseNode * stmtptr : suite)
	{
		ParseNode & stmti = *stmtptr;
		if (stmti.token_equals(TokenMeta::NT_COMMONBLOCK)) {
			declared_commons.push_back(stmtptr);
		}
	}
	return declared_commons;
}

void regen_suite(FunctionInfo * finfo, ParseNode & oldsuite, bool is_partial) {
	/****
	* this function regen code of `suite` node and
	* 1. remove all NT_DECLAREDVARIABLE in suite
	* 2. regen_vardef
	****/
	std::string newsuitestr;

	// regen format
	if (oldsuite.token_equals(TokenMeta::NT_SUITE))
	{
		for (int i = 0; i < oldsuite.length(); i++)
		{
			ParseNode & stmt = oldsuite.get(i);
			if (stmt.token_equals(TokenMeta::Label)) {
				int j = i + 1;
				if (j < oldsuite.length())
				{
					// make sure j in within bound
					const ParseNode & next_stmt = oldsuite.get(j);
					if (next_stmt.token_equals(TokenMeta::NT_FORMAT))
					{
						/*****************
						* generate EMPTY code for format stmt
						* because format stmt will be parsed and substitute for all its occurrence
						* e.g.
						* ```
						* print 11, a
						* 11   format(1X, I)
						* ```
						*****************/
						sprintf(codegen_buf, "LABEL_%s_%s", finfo->local_name.c_str(), stmt.get_what().c_str());
						log_format_index(string(codegen_buf), next_stmt);
					}
					else {
					}
				}
			}
		}
	}

	// regen other stmt
	if (oldsuite.token_equals(TokenMeta::NT_SUITE))
	{
		for (int i = 0; i < oldsuite.length(); i++)
		{
			ParseNode & stmt = oldsuite.get(i);
			if (stmt.token_equals(TokenMeta::Label)) {
				int j = i + 1;
				if (j < oldsuite.length())
				{
					// make sure j in within bound
					const ParseNode & next_stmt = oldsuite.get(j);
					if (next_stmt.token_equals(TokenMeta::NT_FORMAT))
					{
						// handled in the prev loop
					}
					else {
						sprintf(codegen_buf, "LABEL_%s_%s:\n", finfo->local_name.c_str(), stmt.get_what().c_str());
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
		// sometimes `oldsuite` is exp, e.g. condition of `if` stmt
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

		regen_all_variables(finfo, oldsuite);
		//newsuitestr = regen_all_variables_decl_str(finfo, oldsuite) + newsuitestr;
	}
	// currently without all decls
	oldsuite.get_what() = newsuitestr;
}

void regen_all_variables(FunctionInfo * finfo, ParseNode & oldsuite) {
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
	bool all_generated = true;

	/**********************************
	* `regen_vardef` will set initial value to variables
	* variable A's initial value may depend on variable B
	* `all_generated` and `vinfo->generated` is used to make sure B is defined before A
	***********************************/
	do {
		all_generated = true;
		forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
			VariableInfo * vinfo = p.second;
			string local_name = vinfo->local_name;
			ParseNode & entity_variable = vinfo->entity_variable;
			VariableDesc & desc = vinfo->desc;
			ParseNode & local_type = vinfo->type;

			/**********************************
			* do not use the following reference
			//ParseNode & vardef_node = vinfo->vardef_node;
			* because vinfo->vardef_node is possibly reset by `regen_vardef`
			***********************************/
			if (p.second->declared)
			{
				fatal_error("Pre-declared variable encountered");
			}
			else {
				if (vinfo->generated)
				{

				}else{
					all_generated = false;
					if (p.second->commonblock_name != "") {
						// this variable is defined in common block

						// set common
						CommonBlockInfo * common_info = get_commonblock(vinfo->commonblock_name);
						if (common_info == nullptr)
						{
							common_info = add_commonblock(vinfo->commonblock_name);
						}
						// set CommonBLockInfo.variable
						VariableInfo * commonblock_vinfo = common_info->variables[vinfo->commonblock_index];
						// do not set `desc.reference = true;`, it is later set by `gen_qualified_typestr`
						if (!common_info->elsewhere_decl)
						{
							commonblock_vinfo->desc = desc;
							commonblock_vinfo->type = local_type;
							commonblock_vinfo->vardef_node = vinfo->vardef_node;
						}
						else {
							// this `vinfo` is actually overwrite by `commonblock_vinfo`
							// however, we don't do this here. we do this at the end, to cover all occurrence.
						}

						regen_vardef(finfo, vinfo);
					}
					else if (vinfo->vardef_node == nullptr) {
						// implicit definition
						sprintf(codegen_buf, "Variable %s has no vardef node", vinfo->local_name.c_str());
						fatal_error(string(codegen_buf));
					}
					else {
						// normal definition
						regen_vardef(finfo, vinfo);
					}
					vinfo->generated = true;
				}
			}
		});
	} while (!all_generated);

	/**********************************
	* if a variable is in the parameter list, 
	*	it should not have declaration in function body(which is different from fortran)	
	***********************************/
	get_full_paramtable(finfo);
	return ;
}

void regen_all_variables_decl_str(FunctionInfo * finfo, ParseNode & oldsuite) {
	/**********************************
	* this function join declarations of all variable declarations stmts together
	* IMPORTANT
	* in earlier versions, `regen_all_variables_decl_str` and `regen_all_variables` compose one bigger function `gen_joined_declarations`
	* and `regen_function` is not divided into two parts, as is mentionedd in `regen_function_2`
	***********************************/
	string variable_declarations;
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
		VariableInfo * vinfo = p.second;
		string local_name = vinfo->local_name;
		
		if (p.second->declared)
		{
			// this variable is in paramtable, do not need to generate declaration for it in function body
		}
		else {
			if (p.second->commonblock_name != "") {
				// this variable is defined in common block
				CommonBlockInfo * commonblock = get_commonblock(vinfo->commonblock_name);
				if (commonblock == nullptr)
				{
					commonblock = add_commonblock(vinfo->commonblock_name);
				}
				/**********************************
				* in earlier versions, using `vinfo->type` rather than `commonblock_vinfo->type`, this is wrong.
				* now using `commonblock_vinfo->type`, so all infomation about common block is gathered before this function is called
				***********************************/
				VariableInfo * commonblock_vinfo = commonblock->variables[vinfo->commonblock_index];
				ParseNode & type = commonblock_vinfo->type;
				VariableDesc & desc = commonblock_vinfo->desc;
				ParseNode & entity_variable = commonblock_vinfo->entity_variable;
				std::string common_varname = "_" + to_string(vinfo->commonblock_index + 1);
				if (commonblock_vinfo->desc.reference == true)
				{
					sprintf(codegen_buf, "%s %s = BLOCK_%s.%s;\n", gen_qualified_typestr(type, desc, false).c_str()
						, local_name.c_str(), vinfo->commonblock_name.c_str(), common_varname.c_str());
				}
				else {
					sprintf(codegen_buf, "%s & %s = BLOCK_%s.%s;\n", gen_qualified_typestr(type, desc, false).c_str()
						, local_name.c_str(), vinfo->commonblock_name.c_str(), common_varname.c_str());
				}
			}
			else {
				// normal definition and implicit definition
				ParseNode & local_type = vinfo->type;
				VariableDesc & desc = vinfo->desc;
				ParseNode & entity_variable = vinfo->entity_variable;
				if (local_type.token_equals(TokenMeta::Function))
				{
					// interface
					sprintf(codegen_buf, "");
				}
				else {
					sprintf(codegen_buf, "%s;\n", vinfo->vardef_node->to_string().c_str());
				}
			}
			variable_declarations += string(codegen_buf);
		}
	});
	oldsuite.get_what() = variable_declarations + oldsuite.get_what();
	return;
}

ParseNode gen_suite(const ParseNode & item, const ParseNode & list) {
	/*******************
	* item can be of the following 3 cases:
	* 1) labeled_stmts
	*	including NT_SUITE node
	* 2) stmt
	*	including normal stmt node
	* 3) interface_decl
	*	including NT_INTERFACE node
	********************/
	ParseNode newnode;
	if (list.token_equals(TokenMeta::NT_DUMMY))
	{
		if (item.token_equals(TokenMeta::NT_INTERFACE))
		{
			// case 3, interface_decl
			newnode = gen_promote("", TokenMeta::NT_SUITE, item);
		}
		else if (item.token_equals(TokenMeta::NT_SUITE)){
			// case 1, labeled_stmts
			newnode = item;
		}
		else {
			// case 2, stmt
			newnode = gen_promote("%s\n", TokenMeta::NT_SUITE, item);
		}
	}
	else
	{
		if (item.token_equals(TokenMeta::NT_INTERFACE))
		{
			// case 3, interface_decl
			newnode = gen_flatten(item, list, "%s%s", TokenMeta::NT_SUITE);
		}
		else if (item.token_equals(TokenMeta::NT_SUITE)) {
			// case 1, labeled_stmts
			newnode = gen_merge(item, list, "%s\n%s", TokenMeta::NT_SUITE);
		}
		else {
			// case 2, stmt
			newnode = gen_flatten(item, list, "%s\n%s", TokenMeta::NT_SUITE);
		}
	}
	return newnode;
}