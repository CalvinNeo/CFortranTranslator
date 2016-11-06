#include "gen_common.h"

//char codegen_buf[MAX_CODE_LENGTH];

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += program_tree.fs.CurrentTerm.what;
	return cpp_code;
}


ParseNode gen_token(Term term) {
	ParseNode newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	return newnode;
}