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

ParseNode gen_slice(ARG_IN lb, ARG_IN ub, ARG_IN step) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" });
	newnode.addlist(lb, ub, step);
	return newnode;
}

ParseNode gen_slice(ARG_IN lb, ARG_IN ub) {
	/* arr[from : to] */
	/* target code of slice depend on context */
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" });
	newnode.addlist(lb, ub);
	return newnode;
}

ParseNode promote_exp_to_slice(ARG_IN exp) {
	ParseNode newnode = gen_slice(gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER, "1" })), exp);
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

