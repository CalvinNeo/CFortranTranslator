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

vector<VariableInfo *> get_all_declared_vinfo(FunctionInfo * finfo, const ParseNode & suite) {
	vector<VariableInfo *> declared_variables_and_functions;
	forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> p) {
		declared_variables_and_functions.push_back(p.second);
	});
	return declared_variables_and_functions;
}

vector<ParseNode *> get_all_declared_nodes(FunctionInfo * finfo, ParseNode & suite) {
	/***************
	* find out all explicit declarations of variables and interface in a function
	*	, by enumerating all nodes
	* NOT including implicit declared variables
	***************/
	vector<ParseNode *> declared_variables;
	for (ParseNode * stmtptr : suite)
	{
		ParseNode & stmti = *stmtptr;
		if (stmti.token_equals(TokenMeta::NT_VARIABLEDEFINESET)) {
			ParseNode & vardef_set = stmti;
			declared_variables.insert(declared_variables.end(), vardef_set.begin(), vardef_set.end());
		}
		else if (stmti.token_equals(TokenMeta::NT_INTERFACE) && stmti.length() > 0) {
			// interface function
			ParseNode & wrappers = stmti.get(0);
			for (ParseNode *  wrapperptr : wrappers)
			{
				ParseNode & wrapper = *wrapperptr;
				if (wrapper.token_equals(TokenMeta::NT_PROGRAM)) {
					fatal_error("no program in interface");
				}
				else if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE)) {
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
	*	implicit_stmt				ConfigImplicit
	*	allocate_stmt				NT_ALLOCATE_STMT
	*===============
	* control_stmt include:
	*	pause_stmt, stop_stmt, YY_CONTINUE, YY_RETURN, jump_stmt(YY_CYCLE, YY_EXIT, YY_GOTO)
	***************/
	std::string newsuitestr;
	int comment_start = -1;
	// exp, leet_stmt, control_stmt
	if (stmt.token_equals(TokenMeta::NT_STATEMENT)) {
		regen_simple_stmt(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
		comment_start = 1;
	}
	else if (stmt.token_equals(TokenMeta::NT_CONTROL_STMT)) {
		if (stmt.length() > 0 && stmt.get(0).token_equals(TokenMeta::Return)) {
			newsuitestr += stmt.get_what();
			newsuitestr += '\n';
		}
		else if (stmt.get(0).token_equals(TokenMeta::Goto))
		{
			sprintf(codegen_buf, "goto LABEL_%s_%s;", finfo->local_name.c_str(), stmt.get_what().c_str());
			newsuitestr += string(codegen_buf);
			newsuitestr += '\n';
		}
		else {
			newsuitestr += stmt.get_what();
			newsuitestr += '\n';
		}
	}
	// format
	else if (stmt.token_equals(TokenMeta::NT_FORMAT)) {

	}
	// var_def
	else if (stmt.token_equals(TokenMeta::NT_VARIABLEDEFINESET))
	{
		ParseNode & vardef_set = stmt;
		// examine all variable define stmt
		for (int j = 0; j < vardef_set.length(); j++)
		{
			ParseNode & vardef_node = vardef_set.get(j);
			if (vardef_node.token_equals(TokenMeta::Comments))
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
				if (vardef_node.token_equals(TokenMeta::NT_VARIABLEDEFINE)) {
					// for every variable, generate independent definition
					VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
					bool new_variable = (vinfo == nullptr);
					if (!new_variable && vinfo->commonblock_name != "")
					{
						// if this variable is already defined in a common block statement
						// NT_VARIABLEDEFINE have priority over common block
						CommonBlockInfo * commonblock_info = get_commonblock(vinfo->commonblock_name);
						if (commonblock_info == nullptr)
						{
							sprintf(codegen_buf, "variable %s require common block %s which is not exist", vinfo->local_name.c_str(), vinfo->commonblock_name.c_str());
							fatal_error(string(codegen_buf), vardef_node);
						}
						VariableInfo * commonblock_vinfo = commonblock_info->variables[vinfo->commonblock_index];
						//if (!vinfo->implicit_defined)
						//{
							commonblock_vinfo->type = type_nospec;
							commonblock_vinfo->desc.merge(get_variabledesc_attr(vardescattr));
							commonblock_vinfo->entity_variable = entity_variable;
							commonblock_info->elsewhere_decl = true;
						//}
					}
					else if (!new_variable)
					{
						// actually use interface decl
					}
					else if(vinfo == nullptr){
						// `regen_vardef` will be called in `regen_all_variables`
						vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
						vinfo->commonblock_index = 0; 
						vinfo->commonblock_name = ""; 
					}

					/*****************
					* IMPORTANT
					* must take care of duplicate decl
					* in case of
					*	```
					*	real a(:)
					*	allocatable a
					*	intent(in) a
					*	```
					* it will overwrite previous decls
					*****************/
					vinfo->desc.merge(get_variabledesc_attr(vardescattr));
					vinfo->implicit_defined = false; 
					vinfo->type = type_nospec;
					if (!new_variable && is_function_array(vinfo->entity_variable) && !is_function_array(entity_variable))
					{
						/*****************
						* IMPORTANT
						* if this variable is declared as an fortran 77 style array by one decl stmt
						* the array feature will never be "erased" by another decl
						* e.g.
						*	```
						*	REAL A(:)
						*	ALLOCATABLE A
						*	```
						* a is still array
						*****************/
						
						// do nothing
					}
					else {
						vinfo->entity_variable = entity_variable;
					}
					if (vinfo->vardef_node != nullptr)
					{
						delete vinfo->vardef_node;
					}
					vinfo->vardef_node = new ParseNode(vardef_node); 
				}
				else if (vardef_node.token_equals(TokenMeta::NT_DECLAREDVARIABLE)) {
					// declared variable
					fatal_error("NT_DECLAREDVARIABLE is removed");
				}
			}
		}
	}
	// comment
	else if (stmt.token_equals(TokenMeta::Comments)) {
		newsuitestr += stmt.get_what();
		newsuitestr += "\n";
	}
	// common
	else if (stmt.token_equals(TokenMeta::NT_COMMONBLOCK)) {
		regen_common(finfo, stmt);
		newsuitestr += stmt.get_what();
	}
	// dummy
	else if (stmt.token_equals(TokenMeta::NT_DUMMY)) {

	}
	// interface
	else if (stmt.token_equals(TokenMeta::NT_INTERFACE)) {
		ParseNode & wrappers = stmt.get(0);
		for (int i = 0; i < wrappers.length(); i++)
		{
			ParseNode & wrapper = wrappers.get(i);
			// wrapper is `NT_FUNCTION_DECLARE`
			if (wrapper.token_equals(TokenMeta::NT_PROGRAM)) {
				fatal_error("illegal program struct in interface");
			}
			else if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE)) {
				// wrapper.child[1] is function name
				string name = wrapper.get(1).get_what();
				VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
				if (vinfo == nullptr)
				{
					// normal case
				}
				else {
					// this interface Function_Decl variable is declared by `check_implicit_variable`
					// overwrite previous node
					delete_variable(get_context().current_module, finfo->local_name, name);
				}
				vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
				vinfo->commonblock_index = 0;
				vinfo->commonblock_name = "";
				vinfo->desc = VariableDesc();
				vinfo->implicit_defined = false;
				vinfo->type = gen_type(Term{ TokenMeta::Function_Decl, "" });
				vinfo->entity_variable = gen_vardef_from_default(vinfo->type, "");
				vinfo->vardef_node = &wrapper;
			}
            else if(wrapper.token_equals(TokenMeta::META_WORD))
            {
                FunctionInfo *target_finfo =  get_function(get_context().current_module, wrapper.get_what());
                if(target_finfo!= nullptr)
                {
                    target_finfo->func_alias.push_back(stmt.get_what());
                }
            }
		}
	}
	else if (stmt.token_equals(TokenMeta::NT_DERIVED_TYPE)) {
		ParseNode& wrapper = stmt;
		ParseNode& variable_type = wrapper.get(0);
		get_context().current_module = "";
		TypeInfo* tinfo = add_type(get_context().current_module, variable_type.get_what(), TypeInfo{});
		regen_derived_type_1(tinfo, wrapper);
	}
	// input/output stmt
	else if (stmt.token_equals(TokenMeta::NT_READ_STMT)) {
		regen_read(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	else if (stmt.token_equals(TokenMeta::NT_WRITE_STMT)) {
		regen_write(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	else if (stmt.token_equals(TokenMeta::NT_PRINT_STMT)) {
		regen_print(finfo, stmt);
		newsuitestr += stmt.get_what();
		comment_start = 2;
	}
	else if (stmt.token_equals(TokenMeta::NT_IF)) {
		regen_if(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.token_equals(TokenMeta::NT_ELSEIF)) {
		regen_elseif(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.token_equals(TokenMeta::NT_DO)) {
		regen_do(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.token_equals(TokenMeta::NT_DORANGE)) {
		regen_do_range(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.token_equals(TokenMeta::NT_WHILE)) {
		regen_do_while(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
	else if (stmt.token_equals(TokenMeta::NT_SELECT)) {
		regen_select(finfo, stmt);
		newsuitestr += stmt.get_what();
		newsuitestr += '\n';
	}
    else if (stmt.token_equals(TokenMeta::NT_USE)) {
        if(std::find(finfo->use_stmts.begin(), finfo->use_stmts.end(),&stmt)==finfo->use_stmts.end())
            finfo->use_stmts.push_back(&stmt);
    }
	else if (stmt.token_equals(TokenMeta::ConfigImplicit))
	{
		ParseNode & type_decl = stmt.get(0);
        type_decl.get_token() += 100; /* from type decl to type */
        promote_type(type_decl,get_variabledesc_attr(type_decl));
        type_decl.get_token() -= 100; /* from type to type decl */


		ParseNode & paramtable = stmt.get(1);
		for (ParseNode * rangeptr : paramtable)
		{
			ParseNode & range = *rangeptr;
			if (range.length() == 3 && range.get(2).token_equals(TokenMeta::Minus))
			{
				// 'A' - 'Z' generates a range
				char start = range.get(0).get_what()[0];
				char end = range.get(1).get_what()[0];
				if (start > end)
				{
					std::swap(start, end);
				}
				for (char ch = start; ch <= end; ch++)
				{
					finfo->implicit_type_config[ch] = type_decl.get_token();
				}
			}
			else {
				char start = range.get_what()[0];
				finfo->implicit_type_config[start] = type_decl.get_token();
			}
		}
	}
	else if (stmt.token_equals(TokenMeta::NT_ALLOCATE_STMT))
	{
		ParseNode & paramtable = stmt.get(0);
		for (ParseNode * arrptr : paramtable)
		{
			ParseNode & arr = *arrptr; // NT_FUNCTIONARRAY
			ParseNode & arr_name = arr.get(0);
			ParseNode & dimen_slice = arr.get(1);
			if (dimen_slice.token_equals(TokenMeta::NT_DIMENSLICE))
			{
			}
			else if (dimen_slice.token_equals(TokenMeta::NT_ARGTABLE_PURE))
			{

			}
			string slice_info_str = make_str_list(dimen_slice.begin(), dimen_slice.end(), [&](ParseNode * pslice) {
				ParseNode & slice = *pslice;
				regen_slice(finfo, slice);
				string res = "{" + slice.get_what() + "}";
				return res;
			});
			sprintf(codegen_buf, "%s.reset_array({%s})", arr_name.get_what().c_str(), slice_info_str.c_str());
			stmt.get_what() = string(codegen_buf);
			newsuitestr += stmt.get_what();
			newsuitestr += ";\n";
		}
	}
	else {
		// normal stmt
		print_error("Unknown Statement", stmt);
	}
	for (ParseNode * item : stmt)
	{
		if (item->token_equals(TokenMeta::Comments))
		{
			newsuitestr += item->get_what();
			newsuitestr += "\n";
		}
	}
	return newsuitestr;
}
