#include "gen_common.h"

ParseNode gen_if(const ParseNode & exp, ParseNode & suite_true, const ParseNode & elseif, ParseNode & suite_else) {
	ParseNode newnode = ParseNode();


	if (suite_else.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
	}
	suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);

	if (elseif.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
		if (suite_else.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
			// neither elseif or suite_else
			sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());
		}
		else {
			// bare suite_else

			sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
		}
	}
	else {
		if (suite_else.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
			// bare elseif

			sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
		}
		else {
			// elseif + else
			sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
		}
	}


	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };

	newnode.addchild(new ParseNode()); // if
	newnode.addchild(new ParseNode(exp)); // exp
	newnode.addchild(new ParseNode(suite_true)); // suite
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(new ParseNode(elseif)); // recursive elseif-stmt
	}
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(new ParseNode(suite_else)); // else-stmt
	}
	return newnode;
}

ParseNode gen_if_oneline(const ParseNode & exp, const ParseNode & stmt_true) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "if (%s) %s", exp.fs.CurrentTerm.what.c_str(), stmt_true.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
	newnode.addchild(new ParseNode()); // if
	newnode.addchild(new ParseNode(exp)); // exp
	newnode.addchild(new ParseNode(stmt_true)); // stmt
	return newnode;
}

ParseNode gen_elseif(const ParseNode & exp, ParseNode & suite_true, const ParseNode & elseif) {
	ParseNode newnode = ParseNode();
	suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);

	if (elseif.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
		sprintf(codegen_buf, "else if(%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());}
	else {
		sprintf(codegen_buf, "else if{\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };

	newnode.addchild(new ParseNode()); // elseif
	newnode.addchild(new ParseNode(exp)); // exp
	newnode.addchild(new ParseNode(suite_true)); // suite
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(new ParseNode(elseif)); // another elseif-stmt
	}
	return newnode;
}