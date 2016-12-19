#include "gen_common.h"
#include <map>

std::map<std::string, ParseNode *> labels;

ParseNode gen_label(const ParseNode & tag) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_LABEL, "LABEL_" + tag.fs.CurrentTerm.what + ":\n" });
	return newnode;
}