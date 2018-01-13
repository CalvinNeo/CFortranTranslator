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
#include <map>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

//5.5.2 COMMON statement
//The COMMON statement specifies blocks of physical storage, called common blocks, that may be accessed by
//any of the scoping units in an executable program.Thus, the COMMON statement provides a global data facility
//based on storage association(14.6.3).The common blocks specified by the COMMON statement may be named
//and are called named common blocks, or may be unnamed and are called blank common.

CommonBlockInfo * get_commonblock(std::string commonblock_name) {
	if (get_context().commonblocks.find(commonblock_name) != get_context().commonblocks.end()) {
		// already exists
		return get_context().commonblocks[commonblock_name];
	}
	else {
		return nullptr;
	}
}
CommonBlockInfo * add_commonblock(std::string commonblock_name) {
	if (get_context().commonblocks.find(commonblock_name) != get_context().commonblocks.end()) {
		// already exists
	}
	else {
		//if (get_function("", "BLOCK_" + commonblock_name) == nullptr)
		//{
		//	add_function("", "BLOCK_" + commonblock_name, FunctionInfo{});
		//}
		get_context().commonblocks[commonblock_name] = new CommonBlockInfo{ commonblock_name };
	}
	return get_context().commonblocks[commonblock_name];
}

ParseNode gen_common(const ParseNode & commonname_node, const ParseNode & paramtable) {
	// the unique blank COMMON block must be declared in the main program.
	ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable);
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_COMMONBLOCK, "" }, commonname_node, kvparamtable);
	return newnode;
}

void regen_common(FunctionInfo * finfo, ParseNode & common_block) {
	/******************
	*	this function is called for every occurrence of this commonblock(usually 1 time in one subprogram)
	******************/
	ParseNode & commonname_node = common_block.get(0);
	ParseNode & kvparamtable = common_block.get(1);
	string commonblock_name = commonname_node.get_what();
	if (commonblock_name == "")
	{
		commonblock_name = "G";
	}
	CommonBlockInfo * common_info = get_commonblock(commonblock_name);
	bool new_common = (common_info == nullptr);
	if (new_common)
	{
		common_info = add_commonblock(commonblock_name);
	}
	std::vector<VariableInfo *> & common_variables = common_info->variables;
	for (int i = 0; i < kvparamtable.length(); i++)
	{
		//  for every variable in common block node
		ParseNode & entity_variable = kvparamtable.get(i);
		std::string local_varname = get_variable_name(entity_variable);
		// this is VariableInfo in local
		VariableInfo * local_vinfo = get_variable(get_context().current_module, finfo->local_name, local_varname);

		if (local_vinfo == nullptr)
		{
			// if local_vinfo is null, use common decl as default
			// vardef stmt may or may not appear in the following stmts
			local_vinfo = check_implicit_variable(finfo, local_varname);
			local_vinfo->entity_variable = kvparamtable.get(i);
			local_vinfo->commonblock_index = i;
			local_vinfo->commonblock_name = commonblock_name;
			local_vinfo->implicit_defined = true;
		}
		else {
			// if this block is defined in a vardef stmt
			// USE DEFINITION OF VARDEF
			local_vinfo->commonblock_index = i;
			local_vinfo->commonblock_name = commonblock_name;
		}
		if (new_common)
		{
			// this is VariableInfo in commonblock
			common_variables.push_back(add_variable("", "BLOCK_" + commonblock_name, local_varname, *local_vinfo));
		}
		local_vinfo->desc.constant = false;
		/******************
		* do not set
		* `local_vinfo->desc.reference = true`
		* because common block's definition(which is a struct) should not contain `T &`
		* ```
		* int b = 1;
		* struct CB{
		*     int & a = b; // this is wrong
		* };
		* ```
		******************/
	}
	// codes are actually generated in gen_suite
}

ParseNode gen_common_definition(std::string commonblock_name) {
	CommonBlockInfo * common_info = get_commonblock(commonblock_name);
	std::vector<VariableInfo *> & common_variables = common_info->variables;
	int i = 0;
	string struct_str = make_str_list(common_variables.begin(), common_variables.end(), [&](VariableInfo * vinfo) {
		std::string common_varname = "_" + to_string(++i);
		std::string var_decl = regen_vardef(get_function("", ""), vinfo, common_varname, false) + ";";
		return var_decl;
	}, "\n");
	if (commonblock_name == "")
	{
		sprintf(codegen_buf, "struct{\n%s\n}BLOCK_G;\n", tabber(struct_str).c_str());
	}
	else {
		sprintf(codegen_buf, "struct{\n%s\n}BLOCK_%s;\n", tabber(struct_str).c_str(), commonblock_name.c_str());
	}
	return gen_token(Term{ TokenMeta::NT_COMMONBLOCKDEFINE, string(codegen_buf) });
}


VariableInfo * check_implicit_variable(FunctionInfo * finfo, const std::string & name) {
	/******************
	* this function must be called AFTER the AST is finished construct, by `regen_exp` function
	* for all variables in function body that not appear in `finfo->desc->declared_variables`, 
	* mark them as implicit variables and generate its definition
	* NOTICE:
	* this function only works on `exp` nodes, not including variable declaration(`vardef` nodes), etc.
	*******************/
	VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
	if (vinfo == nullptr)
	{
		vinfo = add_variable(get_context().current_module, finfo->local_name, name, VariableInfo{});
		ParseNode implicit_type = gen_implicit_type(finfo, name);
		vinfo->commonblock_index = 0; 
		vinfo->commonblock_name = ""; 
		vinfo->desc = VariableDesc{};
		vinfo->implicit_defined = true; 
		vinfo->type = implicit_type; 
		vinfo->entity_variable = gen_keyvalue_from_name(name); 
		// vardef_node's value is finally determined by `regen_vardef` in `regen_all_variables`
		ParseNode vardef_node = gen_vardef_from_default(implicit_type, name);
		vinfo->vardef_node = new ParseNode(vardef_node); 
	}
	else if (vinfo->type.token_equals(TokenMeta::Implicit_Decl))
	{
		vinfo->type = gen_implicit_type(finfo, name); 
	}
	return vinfo;
}

