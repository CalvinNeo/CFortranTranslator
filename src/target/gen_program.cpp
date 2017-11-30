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

/*
R202 program-unit is main-program
	or external-subprogram (in gen_function.cpp)
	or module (not supported)
	or block-data
*/

void gen_fortran_program(ARG_IN wrappers) {
	std::string codes;
	std::string main_code;
	get_context().program_tree = wrappers;

	FunctionInfo * program_info = add_function("", "program", FunctionInfo());
	ParseNode script_program = gen_token(Term{ TokenMeta::NT_SUITE , "" });
		
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.get_token() == TokenMeta::NT_SUITE)
		{
			for (int j = 0; j < wrapper.length(); j++)
			{
				script_program.addchild(wrapper.get(j));
			}
		}
		else if (wrapper.get_token() == TokenMeta::NT_PROGRAM_EXPLICIT)
		{
			for (int j = 0; j < wrapper.get(0).length(); j++)
			{
				script_program.addchild(wrapper.get(0).get(j));
			}
		}
		else if (wrapper.get_token() == TokenMeta::NT_FUNCTIONDECLARE)
		{
			get_context().current_module = "";
			ParseNode & variable_function = wrapper.get(1);
			/************
			* IMPORTANT
			* MUST call `add_function` to all functions
			*	, before actually call `regen_function` or `regen_vardef` to any of the functions
			*************/
			FunctionInfo * finfo = add_function(get_context().current_module, variable_function.get_what(), FunctionInfo{});
		}
		else if (wrapper.get_token() == TokenMeta::NT_DUMMY)
		{
			// YY_END
		}
		else {
			print_error("Unexpected wrappers");
		}
	}

	// regen all subprogram's step 1: generate subprogram's code
	// create function, generate function body
	get_context().current_module = "";
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if(wrapper.get_token() == TokenMeta::NT_FUNCTIONDECLARE)
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_1(finfo, wrapper);
		}
	}
	// main program code
	regen_suite(program_info, script_program);

	// regen common definition 
	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
	// if you move this code block under the "regen all subprogram's step 2" block, errors will occur when processing file *For3d14.for*
	std::string common_decls;
	for (std::map<std::string, CommonBlockInfo *>::value_type & pr : get_context().commonblocks)
	{
		string s = gen_common_definition(pr.first).get_what();
		common_decls += s;
	}

	// regen all subprogram's step 2: generate subprogram's code
	// generate function signature
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.get_token() == TokenMeta::NT_FUNCTIONDECLARE)
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_2(finfo);
			codes += finfo->node->get_what();
			codes += "\n";
		}
	}

	// main program code
	regen_all_variables_decl_str(program_info, script_program);
	main_code = tabber(script_program.get_what());
	sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
	codes += string(codegen_buf);

	// forward declarations
	std::string forward_decls;
	forall_function_in_module("", [&](std::pair<std::string , FunctionInfo * > pr) {
		FunctionInfo * finfo;
		std::tie(std::ignore, finfo) = pr;
		std::string name = finfo->local_name;
		if (name != "program" && name != "")
		{
			forward_decls += gen_function_signature(finfo);
			forward_decls += ";\n";
		}
	});


	/************
	* PROGRAM STRUCTURE
	* 
	* common blocks
	* forward function decls
	* function definitions
	* the `main` program
	*************/
	codes = forward_decls + codes;
	codes = common_decls + codes;

	get_context().program_tree.get_what() = codes;
}