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
	or external-subprogram
	or module
	or block-data
*/
// external-subprogram is in gen_function

ParseNode gen_program_explicit(ParseNode & suite) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, tabber(suite.fs.CurrentTerm.what) });
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_explicit_declared(suite);
	newnode.addchild(suite); //suite
	return newnode;
}

ParseNode gen_program(ParseNode & suite) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PROGRAM, tabber(suite.fs.CurrentTerm.what) });
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_explicit_declared(suite);
	newnode.addchild(suite); //suite
	return newnode;
}

ParseNode gen_program_end(ParseNode & suite) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PROGRAM, tabber(suite.fs.CurrentTerm.what) });
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_explicit_declared(suite);
	newnode.addchild(suite); //suite
	return newnode;
}

void gen_fortran_program(const ParseNode & wrappers) {
	std::string codes;
	std::string main_code;
	get_context().program_tree = wrappers;
	for (std::map<std::string, CommonBlockInfo>::iterator iter = get_context().commonblocks.begin(); iter != get_context().commonblocks.end(); iter++)
	{
		string xx = gen_common_definition(iter->first).fs.CurrentTerm.what;
		codes += xx;
	}
	for (size_t i = 0; i < wrappers.child.size(); i++)
	{
		const ParseNode & wrapper = wrappers.get(i);
		if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM_EXPLICIT)
		{
			string newsuitestr = regen_suite(*wrapper.child[0]);
			main_code = tabber(newsuitestr);
		}
		else if(wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM){
			string newsuitestr = regen_suite(*wrapper.child[0]);
			main_code += tabber(newsuitestr);
		}
		else if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
			codes += wrapper.fs.CurrentTerm.what;
			codes += "\n";
		}
		else {
			print_error("Unexpected wrappers");
		}
	}
	sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
	codes += string(codegen_buf);
	get_context().program_tree.fs.CurrentTerm.what = codes;
}