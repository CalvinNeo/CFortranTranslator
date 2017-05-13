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
		, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, "" })
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
		newnode = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE);
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
		return gen_keyvalue_from_exp(paramtable_elem, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, "" }));
	}
}

ParseNode promote_argtable_to_paramtable(ARG_IN paramtable) {
	/************************
	*	this function map every element `x` in a argtable to a new ParseNode of NT_KEYVALUE `(x, initial)`, 
	*	and return a flat paramtable
	*************************/
	const ParseNode * pn = &paramtable;
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
	for (int i = 0; i < pn->length(); i++)
	{
		newnode.addchild(promote_exp_to_keyvalue(pn->get(i)));
	}
	return newnode;
}


ParseNode gen_argtable(ARG_IN argtable) {
	ParseNode newnode = argtable;
	newnode.get_token() = TokenMeta::NT_ARGTABLE_PURE;
	return newnode;
}


void regen_paramtable(FunctionInfo * finfo, ARG_OUT paramtable) {
	TokenMeta_T paramtable_type = TokenMeta::NT_ARGTABLE_PURE;
	for (int i = 0; i < paramtable.length(); i++)
	{
		const ParseNode & elem = paramtable.get(i);
		if (true)
		{

		}
	}
}


void foreach_paramtable(const ParseNode & pn, std::function<void(const ParseNode &)> f, bool recursion_direction_right) {
	const ParseNode * pp = &pn;
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
	do {
		int from, to;
		/************
		*	pn->length() == 0: empty paramtable
		*	pn->length() == 1: paramtable with a single element
		*	pn->length() == 2: probably non-flattern paramtable
		**************/
		bool possible_length = (pp->length() == 2);
		if (recursion_direction_right)
		{
			if (possible_length && pp->get(1).get_token() == TokenMeta::NT_PARAMTABLE_PURE)
			{
				from = 1;
			}
			else {
				from = 0;
			}
		}
		else {
			from = 0;
		}
		if (recursion_direction_right)
		{
			if (possible_length && pp->get(0).get_token() == TokenMeta::NT_PARAMTABLE_PURE)
			{
				to = pp->length() - 1;
			}
			else {
				to = pp->length();
			}
		}
		else {
			to = pp->length();
		}
		for (int i = from; i < to; i++)
		{
			f(*pp);
		}
		if (possible_length)
		{
			pp = (recursion_direction_right ? pp->child[1] : pp->child[0]);
		}
	} while (pp->get_token() == TokenMeta::NT_PARAMTABLE_PURE);
}