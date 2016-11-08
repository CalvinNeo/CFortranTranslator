#include "gen_common.h"

/* rules */
/* handle both NT_ARGTABLE_DIMENSLICE and NT_ARGTABLE_PURE */
/*
argtable : dimen_slice
	|
*/

ParseNode gen_argtable(ParseNode & dimen_slice) {
	ParseNode newnode = ParseNode();
	bool isdimen = false;
	int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
	dimen_slice.fs.CurrentTerm.what = "";
	for (sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
	{
		if (sliceid != 0) {
			dimen_slice.fs.CurrentTerm.what += ", ";
		}
		if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
			// dimen_slice
			isdimen = true;
			newnode.addchild(new ParseNode(*dimen_slice.child[sliceid]));
			sprintf(codegen_buf, "%s, %s"
				/* from, to */
				, dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
				, dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
		}
		else {
			// exp
			isdimen = false;
			newnode.addchild(new ParseNode(*dimen_slice.child[sliceid]));
			sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->fs.CurrentTerm.what.c_str());
		}
		dimen_slice.fs.CurrentTerm.what += codegen_buf;
	}
	if (isdimen) {
		//sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
		sprintf(codegen_buf, "%%s.slice(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_DIMENSLICE, string(codegen_buf) };
	}
	else {
		//sprintf(codegen_buf, "%%s(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
		sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
	}
	return newnode;
}