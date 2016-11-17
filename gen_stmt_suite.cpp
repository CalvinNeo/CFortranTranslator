#include "gen_common.h"

ParseNode gen_stmt(const ParseNode & content) {
	sprintf(codegen_buf, "%s ;", content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); 
	return newnode;
}

ParseNode gen_stmt(const ParseNode & content, const std::string & rules) {
	sprintf(codegen_buf, rules.c_str() , content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); 
	return newnode;
}

ParseNode gen_empty_suite() {
	
	ParseNode * newnode = new ParseNode();
	ParseNode & stmt = ParseNode(gen_flex(Term{ TokenMeta::NT_SUITE, "\n" }), newnode);
	newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
	newnode->addchild(new ParseNode(stmt)); // stmt
	newnode = flattern_bin(newnode);
	return *newnode;
}