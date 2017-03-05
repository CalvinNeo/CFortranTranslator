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

ParseNode gen_stmt(const ParseNode & content) {
	sprintf(codegen_buf, "%s;", content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) });
	newnode.addchild(content); 
	return newnode;
}

ParseNode gen_stmt(const ParseNode & content, const std::string & rules) {
	sprintf(codegen_buf, rules.c_str() , content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) });
	newnode.addchild(content); 
	return newnode;
}

vector<ParseNode *> get_all_declared(std::string module_name, std::string function_name) {
	vector<ParseNode *> declared_variables_and_functions;
	forall_variable_in_function(module_name, function_name, [&](const std::pair<std::string, VariableInfo *> p) {
		declared_variables_and_functions.push_back(&(p.second->entity_variable));
	});
	forall_function_in_module(module_name, [&](const std::pair<std::string, FunctionInfo *> p) {
	});
	return declared_variables_and_functions;
}

vector<ParseNode *> get_all_explicit_declared(FunctionInfo * finfo, ParseNode & suite) {
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
					assert("no program in interface");
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
void regen_suite(FunctionInfo * finfo, ParseNode & oldsuite, bool is_partial) {
	// regen suite(especially variable declaration)
	/* this function regen code of `suite` node and 
	 * 1. remove all NT_DECLAREDVARIABLE in suite
	 * 2. regen_vardef 
	 */
	std::string newsuitestr;
	vector<ParseNode *> declared_variables = get_all_explicit_declared(finfo, oldsuite);
	vector<ParseNode *> declared_commons = get_all_commons(finfo, oldsuite);
	for (int i = 0; i < oldsuite.child.size(); i++)
	{
		// oldsuite.child[i]: stmt/ interface_decl
		ParseNode & stmt = oldsuite.get(i);
		if (stmt.fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINESET)
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
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_COMMONBLOCK) {
			regen_common(finfo, stmt);
			newsuitestr += stmt.fs.CurrentTerm.what;
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::NT_INTERFACE) {
			// do not generate declared string
		}
		else if (stmt.fs.CurrentTerm.token == TokenMeta::Label) {
			int j = i + 1;
			if (j < oldsuite.child.size())
			{
				const ParseNode & next_stmt = oldsuite.get(j);
				if (next_stmt.child.size() > 0 && next_stmt.get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{

				}
				else {
					sprintf(codegen_buf, "LABEL_%s:\n", stmt.to_string().c_str());
					newsuitestr += string(codegen_buf);
				}
			}
			
		}
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
			newsuitestr += stmt.fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
	}
	// 这部分一定要放在commonblock检查之后
	if (!is_partial)
	{
		string variable_declarations;
		forall_variable_in_function(get_context().current_module, finfo->local_name, [&](const std::pair<std::string, VariableInfo *> & p) {
			VariableInfo * vinfo = p.second;
			string local_name = vinfo->local_name;
			ParseNode & entity_variable = vinfo->entity_variable;
			VariableDesc & desc = vinfo->desc;
			ParseNode * vardef = vinfo->vardef;
			ParseNode & local_type = vinfo->type;
			if (p.second->commonblock_name == "") {
				regen_vardef(vinfo, *vardef, local_type, desc, entity_variable);
				sprintf(codegen_buf, "%s;\n", vardef->to_string().c_str());
			}
			else {
				desc.reference = true;
				regen_vardef(vinfo, gen_vardef_from_implicit(local_type, local_name), local_type, desc, entity_variable);
				std::string common_varname = "_" + to_string(vinfo->commonblock_index + 1);
				sprintf(codegen_buf, "%s %s = %s.%s;\n", gen_qualified_typestr(local_type, desc).c_str()
					, local_name.c_str(), vinfo->commonblock_name.c_str(), common_varname.c_str());

				auto common_info = get_context().commonblocks.find(vinfo->commonblock_name);
				if (common_info == get_context().commonblocks.end()) {
					assert("can't find common");
				}
				else {
					common_info->second.variables[vinfo->commonblock_index].desc = desc;
					common_info->second.variables[vinfo->commonblock_index].type = local_type;
				}
			}
			variable_declarations += string(codegen_buf);
		});
		newsuitestr = variable_declarations + newsuitestr;
		finfo->funcdesc.declared_variables = declared_variables;
		finfo->funcdesc.declared_commons = declared_commons;
	}
	else {
		finfo->funcdesc.declared_variables.insert(finfo->funcdesc.declared_variables.end(), declared_variables.begin(), declared_variables.end());
		finfo->funcdesc.declared_commons.insert(finfo->funcdesc.declared_commons.end(), declared_commons.begin(), declared_commons.end());
	}
	oldsuite.fs.CurrentTerm.what = newsuitestr;
	//// CAN NOT call `clear_temporary_variables();` HERE
}