#include "gen_common.h"

/*
R202 program-unit is main-program
	or external-subprogram
	or module
	or block-data
*/
// external-subprogram is in gen_function

ParseNode gen_program_explicit(ParseNode & suite) {
	sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", tabber(suite.fs.CurrentTerm.what).c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM, string(codegen_buf) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
	return newnode;
}

ParseNode gen_program(ParseNode & suite) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM,  tabber(suite.fs.CurrentTerm.what) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
	return newnode;
}

ParseNode gen_program_end(ParseNode & suite) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM,  tabber(suite.fs.CurrentTerm.what) }), nullptr);
	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	newnode.addchild(new ParseNode(suite)); //suite
	return newnode;
}