#include "gen_common.h"

ParseNode gen_case(const ParseNode & dimen_slice, ParseNode & suite) {
	// one case
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, "" }); // Yes, empty string
	suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
	newnode.addchild(ParseNode()); // case
	newnode.addchild(dimen_slice); // dimen_slice
	newnode.addchild(suite); // suite
	return newnode;
}

ParseNode gen_select(const ParseNode & exp, const ParseNode & case_stmt) {

	ParseNode newnode = ParseNode();
	string codegen = "";
	for (size_t i = 0; i < case_stmt.child.size(); i++)
	{
		ParseNode & case_stmt_elem = *case_stmt.child[i];
		ParseNode & dimen_slice = *case_stmt_elem.child[1];
		/*
		0 -- case
		1 -- dimen_slice
		2 -- stmt(case body)
		*/
		if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
			// NT_DIMENSLICE
			string dsstr;
			for (int sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
			{
				if (sliceid == 0) {
					sprintf(codegen_buf, "(%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(sliceid).get(0).fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(sliceid).get(1).fs.CurrentTerm.what.c_str());
				}
				else {
					sprintf(codegen_buf, " || (%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(sliceid).get(0).fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(sliceid).get(1).fs.CurrentTerm.what.c_str());
				}
				dsstr += string(codegen_buf);
			}
			if (i == 0) {
				sprintf(codegen_buf, "if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.get(2).fs.CurrentTerm.what.c_str());
			}
			else {
				sprintf(codegen_buf, "else if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.get(2).fs.CurrentTerm.what.c_str());
			}
		}
		else {
			// NT_ARGTABLE_PURE
			string choice = "";
			if (i == 0) {
				choice = "if(";
				sprintf(codegen_buf, "if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(0).fs.CurrentTerm.what.c_str(), case_stmt_elem.get(2).fs.CurrentTerm.what.c_str());
			}
			else {
				choice = "else if(";
				sprintf(codegen_buf, "else if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(0).fs.CurrentTerm.what.c_str(), case_stmt_elem.get(2).fs.CurrentTerm.what.c_str());
			}
			for (int j = 0; j < dimen_slice.child.size(); j++)
			{
				if (j == 0) {
					sprintf(codegen_buf, "%s == %s", exp.fs.CurrentTerm.what.c_str(), dimen_slice.get(j).fs.CurrentTerm.what.c_str());
				}
				else {
					sprintf(codegen_buf, "|| (%s == %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[j]->fs.CurrentTerm.what.c_str());
				}
				choice += codegen_buf;
			}
			sprintf(codegen_buf, "){\n%s}\n", case_stmt_elem.get(2).fs.CurrentTerm.what.c_str());
			choice += codegen_buf;
			sprintf(codegen_buf, "%s", choice.c_str());
		}
		codegen += codegen_buf;
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_SELECT, codegen };
	ParseNode select = ParseNode();
	newnode.addchild(select); // select
	newnode.addchild(exp); // exp
	newnode.addchild(case_stmt); // suite
	return newnode;
}