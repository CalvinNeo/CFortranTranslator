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

void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant
	, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * x = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr);
	x->desc = VariableDesc(reference, constant, optional, slice, kind, save);
}

VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * x = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr);
	return x->desc;
}

ParseNode gen_variabledesc_from_dimenslice(const ParseNode & dimen_slice) {
	ParseNode dimen = dimen_slice;
	for (int sliceid = 0; sliceid < dimen.child.size(); sliceid++)
	{
		if (dimen.get(sliceid).fs.CurrentTerm.token == TokenMeta::NT_SLICE) {

		}
		else {
			ParseNode tmp = promote_exp_to_slice(dimen.get(sliceid));
			delete dimen.child[sliceid];
			dimen.child[sliceid] = new ParseNode(tmp);
		}
		sprintf(codegen_buf, "(%s, %s)"
			/* from, to */
			, dimen.get(sliceid).get(0).to_string().c_str()
			, dimen.get(sliceid).get(1).to_string().c_str());
		dimen.get(sliceid).fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
	}
	return dimen;
}