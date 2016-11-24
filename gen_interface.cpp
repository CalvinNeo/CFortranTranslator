#include "gen_common.h"

ParseNode gen_interface(const ParseNode & wrappers) {
	ParseNode newnode = ParseNode(gen_flex(Term{TokenMeta::NT_INTERFACE, wrappers.fs.CurrentTerm.what}), nullptr);

	newnode.addchild(new ParseNode(wrappers));
	return newnode;
}