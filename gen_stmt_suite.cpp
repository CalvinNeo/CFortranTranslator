#include "gen_common.h"

ParseNode gen_stmt(const ParseNode & content) {
	sprintf(codegen_buf, "%s ;", content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); // let
	return newnode;
}

ParseNode gen_stmt(const ParseNode & content, const std::string & rules) {
	sprintf(codegen_buf, rules.c_str() , content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); // let
	return newnode;
}