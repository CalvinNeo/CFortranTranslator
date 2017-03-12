/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"


ParseNode promote_exp_to_slice(ARG_IN exp) {
	ParseNode lit = gen_token(Term{ TokenMeta::META_INTEGER, "1" });
	ParseNode exp0 = gen_token(Term{ TokenMeta::NT_EXPRESSION , lit.to_string() }, lit);
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp0, exp);
	return newnode;
}

ParseNode promote_argtable_to_dimenslice(ARG_IN argtable) {
	const ParseNode * pn = &argtable;
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_DIMENSLICE, "" });
	do {
		// for all non-flatterned paramtable
		for (int i = 0; i < pn->child.size(); i++)
		{
			newnode.addchild(promote_exp_to_keyvalue(*pn->child[i]));
		}
		if (pn->child.size() >= 2)
		{
			/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
			pn = pn->child[1];
		}
	} while (pn->child.size() == 2 && pn->get(1).fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE);
	return newnode;
}


ParseNode gen_dimenslice(ARG_IN dimen_slice) {
	// all promoted to dimen_slice
	ParseNode newnode = dimen_slice;
	int sliceid = 0;
	for (sliceid = 0; sliceid < newnode.child.size(); sliceid++)
	{
		if (sliceid != 0) {
			newnode.fs.CurrentTerm.what += ", ";
		}
		if (newnode.get(sliceid).fs.CurrentTerm.token == TokenMeta::NT_SLICE) {
			// slice
			if (newnode.get(sliceid).child.size() == 2) {
				/* from, to */
				sprintf(codegen_buf, "%s, %s", newnode.get(sliceid).get(0).fs.CurrentTerm.what.c_str()
					, newnode.get(sliceid).get(1).fs.CurrentTerm.what.c_str());
			}
			else {
				// size
				sprintf(codegen_buf, "%s", newnode.get(sliceid).get(0).fs.CurrentTerm.what.c_str());
			}
		}
		else {
			// exp
			sprintf(codegen_buf, "%s", newnode.get(sliceid).fs.CurrentTerm.what.c_str());
		}
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "LAZY GEN DIMENSLICE" };
	return newnode;
}