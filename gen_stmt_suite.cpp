#include "gen_common.h"

ParseNode gen_stmt(const ParseNode & let) {
	sprintf(codegen_buf, "%s ;", let.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(let)); // let
	return newnode;
}