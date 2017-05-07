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

ParseNode gen_keyvalue_from_name(std::string name) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */

	sprintf(codegen_buf, "%s", name.c_str());
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLE_ENTITY, string(codegen_buf) }
		, gen_token(Term{ TokenMeta::UnknownVariant, name }) 
		, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") })
	);
	return newnode;
}

ParseNode gen_keyvalue_from_exp(ARG_IN variable, ARG_IN initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */

	sprintf(codegen_buf, "%s", variable.to_string().c_str());
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLE_ENTITY, string(codegen_buf) }, variable, initial);
	return newnode;
}


ParseNode gen_paramtable(ARG_IN paramtable_elem) {
	if (paramtable_elem.get_token() == TokenMeta::NT_DIMENSLICE) {
		print_error("Can't generate paramtable from dimen_slice", paramtable_elem);
		return gen_dimenslice(paramtable_elem);
	}
	else if( paramtable_elem.get_token() == TokenMeta::NT_ARGTABLE_PURE) {
		print_error("Can't generate paramtable from pure argtable", paramtable_elem);
		// promote dimen_slice to paramtable
		return gen_argtable(paramtable_elem);
	}
	else if(paramtable_elem.get_token() == TokenMeta::NT_KEYVALUE){
		sprintf(codegen_buf, "%s", paramtable_elem.to_string().c_str());
		ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, string(codegen_buf) }, paramtable_elem);
		return newnode;
	}
	else if (paramtable_elem.get_token() == TokenMeta::NT_PARAMTABLE_PURE) {
		return paramtable_elem;
	}
	else {
		print_error("Illegal gen_paramtable arg", paramtable_elem);
		return paramtable_elem;
	}
}


ParseNode gen_paramtable(ARG_IN paramtable_elem, ARG_IN paramtable) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
	bool to_param = is_paramtable(paramtable_elem) || is_paramtable(paramtable);
	bool all_param = is_paramtable(paramtable_elem) && is_paramtable(paramtable);
	bool to_dimen = is_dimenslice(paramtable_elem) || is_dimenslice(paramtable);
	bool all_dimen = is_dimenslice(paramtable_elem) && is_dimenslice(paramtable);
	bool to_arg = is_argtable(paramtable_elem) || is_argtable(paramtable);
	bool all_arg = is_dimenslice(paramtable_elem) && is_dimenslice(paramtable);

	if (all_param) {
		// all keyvalue pair 
		newnode = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE_PURE);
	}
	else if(to_param){
		// there is keyvalue pair
		newnode = promote_argtable_to_paramtable(paramtable);
		newnode.addchild(promote_exp_to_keyvalue(paramtable_elem));
		sprintf(codegen_buf, "%s, %s", paramtable_elem.to_string().c_str(), paramtable.to_string().c_str());
		newnode.get_what() = string(codegen_buf);
	}
	else if (to_dimen) {
		print_error("invalid paramtable, dimension is not allowed");
		newnode = gen_token(Term{ TokenMeta::NT_DIMENSLICE, "" });
	}
	else if (all_arg) {
		// all dimen_slice or argument_pure or variable
		sprintf(codegen_buf, "%s, %s", paramtable_elem.to_string().c_str(), paramtable.to_string().c_str());
		newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) }, paramtable_elem);
	}
	else {
		print_error("bad param table");
	}
	return newnode;
}

ParseNode promote_exp_to_keyvalue(ARG_IN paramtable_elem) {
	if (paramtable_elem.get_token() == TokenMeta::NT_KEYVALUE) {
		// keyvalue pair
		return paramtable_elem;
	}
	else {
		return gen_keyvalue_from_exp(paramtable_elem, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") }));
	}
}

ParseNode promote_argtable_to_paramtable(ARG_IN paramtable) {
	const ParseNode * pn = &paramtable;
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
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
	} while (pn->length() == 2 && pn->get(1).get_token() == TokenMeta::NT_PARAMTABLE_PURE);
	return newnode;
}


ParseNode gen_argtable(ARG_IN argtable) {
	ParseNode newnode = argtable;
	newnode.get_token() = TokenMeta::NT_ARGTABLE_PURE;
	return newnode;
}
