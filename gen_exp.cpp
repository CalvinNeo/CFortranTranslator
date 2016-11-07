#include "gen_common.h"


ParseNode  gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule) {
	ParseNode  newnode = ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode.addchild(new ParseNode(exp1)); // left operand exp
	newnode.addchild(new ParseNode(op)); // op
	newnode.addchild(new ParseNode(exp2)); // tight operand exp
	return newnode;
}

ParseNode  gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule) {
	ParseNode  newnode = ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode.addchild(new ParseNode(op)); // op
	newnode.addchild(new ParseNode(exp1)); // only right operand exp
	return newnode;
}

ParseNode  gen_exp(const ParseNode & variable) {
	ParseNode  newnode = ParseNode();
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, variable.fs.CurrentTerm.what };
	newnode.addchild(new ParseNode(variable)); 
	return newnode;
}
