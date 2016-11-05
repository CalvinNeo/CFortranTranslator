#include "gen_common.h"

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += program_tree.fs.CurrentTerm.what;
	return cpp_code;
}

ParseNode * gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule) {
	ParseNode * newnode = new ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
	newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode->addchild(new ParseNode(exp1)); // left operand exp
	newnode->addchild(new ParseNode(op)); // +
	newnode->addchild(new ParseNode(exp2)); // tight operand exp
	return newnode;
}

ParseNode * gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule) {
	ParseNode * newnode = new ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str());
	newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode->addchild(new ParseNode(op)); // (-)
	newnode->addchild(new ParseNode(exp1)); // only right operand exp
	return newnode;
}