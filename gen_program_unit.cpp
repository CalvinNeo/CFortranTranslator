#include "gen_common.h"

/*
R202 program-unit is main-program
	or external-subprogram
	or module
	or block-data
*/
// external-subprogram is in gen_function

ParseNode gen_program_explicit(ParseNode & suite) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, tabber(suite.fs.CurrentTerm.what) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
	return newnode;
}

ParseNode gen_program(ParseNode & suite) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM, tabber(suite.fs.CurrentTerm.what) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
	return newnode;
}

ParseNode gen_program_end(ParseNode & suite) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM, tabber(suite.fs.CurrentTerm.what) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
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
		ParseNode & wrapper = *wrappers.child[i];
		if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM_EXPLICIT)
		{
			string newsuitestr = regen_suite(wrapper.child[0]);
			main_code = tabber(newsuitestr);
		}
		else if(wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM){
			string newsuitestr = regen_suite(wrapper.child[0]);
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