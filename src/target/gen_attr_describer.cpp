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
	, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save
	, boost::optional<bool> allocatable, boost::optional<bool> target, boost::optional<bool> pointer, boost::optional<bool> inout_reference) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * desc_attr = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr); // explicit dynamic_cast is clearer than static_cast and vfunc, :D
	desc_attr->desc = VariableDesc(reference, constant, optional, slice, kind, save, allocatable, target, pointer, inout_reference);
}

VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * desc_attr = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr); // explicit dynamic_cast is clearer than static_cast and vfunc, :D
	return desc_attr->desc;
}
