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
	ParseNode exp0 = gen_token(Term{ TokenMeta::NT_EXPRESSION , lit.get_what() }, lit);
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp0, exp);
	return newnode;
}

ParseNode promote_argtable_to_dimenslice(ARG_IN argtable) {
	const ParseNode * pn = &argtable;
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_DIMENSLICE, "" });
	do {
		// for all non-flatterned paramtable
		for (int i = 0; i < pn->length(); i++)
		{
			newnode.addchild(promote_exp_to_keyvalue(*pn->child[i]));
		}
		if (pn->length() >= 2)
		{
			/* if pn->length() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
			pn = pn->child[1];
		}
	} while (pn->length() == 2 && pn->get(1).get_token() == TokenMeta::NT_ARGTABLE_PURE);
	return newnode;
}


ParseNode gen_dimenslice(ARG_IN dimen_slice) {
	// all promoted to dimen_slice
	ParseNode newnode = dimen_slice;
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "LAZY GEN DIMENSLICE" };
	return newnode;
}