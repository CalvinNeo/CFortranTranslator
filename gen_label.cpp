#include "gen_common.h"
#include <map>

std::map<std::string, ParseNode *> labels;

//3.2.5 Statement labels
//A statement label provides a means of referring to an individual statement.
//R313 label is digit[digit[digit[digit[digit]]]]
//Constraint: At least one digit in a label must be nonzero.
//	If a statement is labeled, the statement must contain a nonblank character.The same statement label must not be
//	given to more than one statement in a scoping unit.Leading zeros are not significant in distinguishing between
//	statement labels.For example :
//99999
//10
//010
//are all statement labels.The last two are equivalent

ParseNode gen_label(const ParseNode & tag) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_LABEL, "LABEL_" + tag.fs.CurrentTerm.what + ":\n" });
	return newnode;
}

void log_format_index(std::string format_index) {

}

void require_format_index(std::string format_index) {

}