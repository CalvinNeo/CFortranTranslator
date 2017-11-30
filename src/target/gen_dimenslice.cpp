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
	// exp -> (UBOUND_DELTA_STR, exp)
	ParseNode lit = gen_token(Term{ TokenMeta::META_INTEGER, UBOUND_DELTA_STR });
	ParseNode exp0 = gen_token(Term{ TokenMeta::NT_EXPRESSION, UBOUND_DELTA_STR }, lit);
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp0, exp);
	return newnode;
}

ParseNode promote_argtable_to_dimenslice(ARG_IN argtable) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_DIMENSLICE, "" });
	for (int i = 0; i < argtable.length(); i++)
	{
		newnode.addchild(promote_exp_to_slice(argtable.get(i)));
	}
	return newnode;
}

void regen_slice(FunctionInfo * finfo, ParseNode & slice) {
	if (slice.get_token() == TokenMeta::NT_SLICE) {
		bool empty_slice = false;
		// use slice_info_arr to handle default situation
		string slice_info_arr[] = { UBOUND_DELTA_STR, UBOUND_DELTA_STR, UBOUND_DELTA_STR };
		for (int j = 0; j < slice.length(); j++)
		{
			if (slice.get(j).get_token() == TokenMeta::NT_VARIABLEINITIALDUMMY) {
				// a(:)
				empty_slice = true;
			}
			else {
				regen_exp(finfo, slice.get(j));
				slice_info_arr[j] = slice.get(j).to_string();
			}
		}
		if (empty_slice) {
			/***********
			* select the whole slice
			* e.g.
			*```
			* FROTRAN Code
			*	c = a(:)
			*	c = a(i, 1:j)
			* C++ Code:
			*	c = forslice(a, { {} });
			*	c = forslice(a, { {i}, {1, j} });
			*```
			***********/
		}
		else if (slice.length() == 0)
		{
			print_error("Slice can not be empty");
		}
		else if (slice.length() == 1) {
			// point to a single element, not mean size
			sprintf(codegen_buf, "%s", slice_info_arr[0].c_str());
		}
		else if (slice.length() == 2) {
			// forslice accepts lowerbound, size
			sprintf(codegen_buf, "%s, %s", slice_info_arr[0].c_str(), slice_info_arr[1].c_str());
		}
		else {
			sprintf(codegen_buf, "%s, %s, %s", slice_info_arr[0].c_str(), slice_info_arr[1].c_str(), slice_info_arr[2].c_str());
		}
		slice.get_what() = string(codegen_buf);
	}
	else {
		/***********
		* if dimen_slice has 3 components `a(1:2, 3, 4)`,
		*	`1:2` is NT_SLICE
		*	`3` and `4` is not NT_SLICE, they are literals
		* 
		* Whu don'r promote?
		* because in `a(1:2, 3, 4)` can be component of an array decl, where 3 and 4 can easyly be translated into {3, 3}, {4, 4}
		* but `a(1:2, 3, 4)` can also be index of an array, and it returns a scalar, 
		* if changed to ``a(1:2, 3:3, 4:4)`, it will return a array, as effect of array slicing
		***********/
		regen_exp(finfo, slice);
	}
}
