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
	program_tree = wrappers;
	for (size_t i = 0; i < wrappers.child.size(); i++)
	{
		ParseNode & wrapper = *wrappers.child[i];
		if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM_EXPLICIT)
		{
			main_code = wrapper.fs.CurrentTerm.what;
		}
		else if(wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM){
			main_code += wrapper.fs.CurrentTerm.what;
		}
		else if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
			codes += wrapper.fs.CurrentTerm.what;
			codes += "\n";
		}
	}
	sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
	codes += string(codegen_buf);
	program_tree.fs.CurrentTerm.what = codes;
}