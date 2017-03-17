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


bool is_dimenslice(const ParseNode & elem) {
	return elem.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE || elem.fs.CurrentTerm.token == TokenMeta::NT_SLICE;
}
bool is_argtable(const ParseNode & elem) {
	return elem.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE ||
		(TokenMeta::iselement(elem.fs.CurrentTerm.token)
			|| elem.fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION
			|| elem.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER
			|| elem.fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY
			|| elem.fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO);
}
bool is_paramtable(const ParseNode & elem) {
	return elem.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_PURE || elem.fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE;
}

bool is_function_array(const ParseNode & entity_variable) {
	const ParseNode & entity_variable_name = entity_variable.get(0);
	if (entity_variable_name.fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		return true;
	}
	return false;
}