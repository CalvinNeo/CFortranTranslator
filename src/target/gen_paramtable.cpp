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
	/************************
	* this function promote a `word`(possibly variable name) to a new ParseNode of NT_KEYVALUE `(x, initial)`,
	*************************/
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLE_ENTITY, name }
		, gen_token(Term{ TokenMeta::UnknownVariant, name }) 
		, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, "" })
	);
	return newnode;
}

ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLE_ENTITY, variable.get_what() }, variable, initial);
	return newnode;
}

ParseNode promote_exp_to_keyvalue(const ParseNode & paramtable_elem) {
	/************************
	* this function promote a `exp` to a new ParseNode of NT_KEYVALUE `(x, initial)`,
	*************************/
	if (paramtable_elem.token_equals(TokenMeta::NT_KEYVALUE)) {
		// keyvalue pair
		return paramtable_elem;
	}
	else {
		return gen_keyvalue_from_exp(paramtable_elem, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, "" }));
	}
}

ParseNode gen_pure_paramtable(const ParseNode & paramtable_elem) {
	if (paramtable_elem.token_equals(TokenMeta::NT_DIMENSLICE)) {
		print_error("Can't generate paramtable from dimen_slice", paramtable_elem);
		return gen_reset(paramtable_elem, Term{ TokenMeta::NT_DIMENSLICE, "DIMENSLICE GENERATED IN REGEN_SUITE" });
	}
	else if(paramtable_elem.token_equals(TokenMeta::NT_ARGTABLE_PURE)) {
		print_error("Can't generate paramtable from pure argtable", paramtable_elem);
		// promote dimen_slice to parameter list
		return gen_reset(paramtable_elem, Term{ TokenMeta::NT_ARGTABLE_PURE, "ARGTABLE GENERATED IN REGEN_SUITE" });
	}
	else if(paramtable_elem.token_equals(TokenMeta::NT_KEYVALUE)){
		return gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, paramtable_elem.to_string() }, paramtable_elem);
	}
	else if (paramtable_elem.token_equals(TokenMeta::NT_PARAMTABLE_PURE)) {
		return paramtable_elem;
	}
	else {
		print_error("bad param table", paramtable_elem);
		return paramtable_elem;
	}
}


ParseNode gen_pure_paramtable(ParseNode & paramtable_elem, ParseNode & paramtable, bool left_recursion) {
	ParseNode newnode;
	bool to_param = is_paramtable(paramtable_elem) || is_paramtable(paramtable);
	bool all_param = is_paramtable(paramtable_elem) && is_paramtable(paramtable);
	bool to_dimen = is_dimenslice(paramtable_elem) || is_dimenslice(paramtable);
	bool all_dimen = is_dimenslice(paramtable_elem) && is_dimenslice(paramtable);
	bool to_arg = is_argtable(paramtable_elem) || is_argtable(paramtable);
	bool all_arg = is_argtable(paramtable_elem) && is_argtable(paramtable);

	if (all_param) {
		// all keyvalue pair
#ifdef USE_REUSE
		newnode = gen_flatten(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE_PURE, left_recursion);
		//newnode = gen_flatten_reused(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE_PURE, left_recursion);
#else
		newnode = gen_flatten(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE_PURE, left_recursion);
#endif
	}
	else if(to_param){
		// there is keyvalue pair
		ParseNode promoted_argtable = promote_argtable_to_paramtable(paramtable);
		newnode = gen_flatten(promote_exp_to_keyvalue(paramtable_elem), promoted_argtable, "%s, %s", TokenMeta::NT_PARAMTABLE_PURE, left_recursion);
	}
	else if (to_dimen) {
		print_error("Can't generate dimen_slice from paramtable");
		newnode = gen_token(Term{ TokenMeta::NT_DIMENSLICE, "" });
	}
	else if (all_arg) {
		// all argument_pure or variable
		print_error("Can't generate all arguments from paramtable");
		newnode = gen_flatten(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, left_recursion);
	}
	else {
		fatal_error("bad param table");
	}
	return newnode;
}

ParseNode promote_argtable_to_paramtable(const ParseNode & paramtable) {
	/************************
	* this function map every element `x` in a argtable to a keyvalue by `promote_exp_to_keyvalue`, 
	* and return a flat parameter list
	*************************/
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
	for (int i = 0; i < paramtable.length(); i++)
	{
		newnode.addchild(promote_exp_to_keyvalue(paramtable.get(i)));
	}
	return newnode;
}

void regen_paramtable(FunctionInfo * finfo, ParseNode & paramtable) {
	TokenMeta_T paramtable_type = TokenMeta::NT_ARGTABLE_PURE;
	for (int i = 0; i < paramtable.length(); i++)
	{
		const ParseNode & elem = paramtable.get(i);
		if (elem.token_equals(TokenMeta::NT_SLICE))
		{
			if (paramtable_type == TokenMeta::NT_ARGTABLE_PURE)
			{
				paramtable_type = TokenMeta::NT_DIMENSLICE;
			}
			else if (paramtable_type == TokenMeta::NT_PARAMTABLE_PURE)
			{
				print_error("NT_DIMENSLICE and NT_PARAMTABLE_PURE", paramtable);
			}
			else if (paramtable_type == TokenMeta::NT_DIMENSLICE) {
				// don't need changing
			}
		}
		else if (elem.token_equals(TokenMeta::NT_KEYVALUE))
		{
			if (paramtable_type == TokenMeta::NT_ARGTABLE_PURE)
			{
				paramtable_type = TokenMeta::NT_PARAMTABLE_PURE;
			}
			else if (paramtable_type == TokenMeta::NT_PARAMTABLE_PURE)
			{
				// don't need changing
			}
			else if (paramtable_type == TokenMeta::NT_DIMENSLICE) {
				print_error("NT_KEYVALUE and NT_DIMENSLICE", paramtable);
			}
		}
		else {

		}
	}
	for (int i = 0; i < paramtable.length(); i++)
	{
		if (paramtable_type == TokenMeta::NT_PARAMTABLE_PURE) {
			ParseNode & item = paramtable.get(i);
			if (item.token_equals(TokenMeta::NT_KEYVALUE))
			{
				ParseNode & keyvalue = item;
				regen_exp(finfo, keyvalue.get(0));
				if (keyvalue.get(1).token_equals(TokenMeta::NT_VARIABLEINITIALDUMMY))
				{

				}
				else
				{
					regen_exp(finfo, keyvalue.get(1));
				}
			}
			else {
				ParseNode keyvalue = gen_promote("%s = %s", TokenMeta::NT_KEYVALUE, item, gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, "" }));
				regen_exp(finfo, keyvalue);
				paramtable.replace(i, keyvalue);
			}
		}
		else if (paramtable_type == TokenMeta::NT_DIMENSLICE) {
			ParseNode & slice = paramtable.get(i);
			regen_exp(finfo, slice);
		}
		else {
			ParseNode & item = paramtable.get(i);
			regen_exp(finfo, item);
		}
	}
	string paramtable_str = make_str_list(paramtable.begin(), paramtable.end(), [&](ParseNode * pn) {
		return pn->get_what();
	});
	paramtable.get_what() = paramtable_str;
}


void foreach_paramtable(const ParseNode & pn, std::function<void(const ParseNode &)> f, bool recursion_direction_right) {
	const ParseNode * pp = &pn;
	do {
		int from, to;
		/************
		* pn->length() == 0: empty parameter list
		* pn->length() == 1: parameter list with a single element
		* pn->length() == 2: probably non-flatten parameter list
		**************/
		bool possible_length = (pp->length() == 2);
		if (recursion_direction_right)
		{
			if (possible_length && pp->get(1).token_equals(TokenMeta::NT_PARAMTABLE_PURE))
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
			if (possible_length && pp->get(0).token_equals(TokenMeta::NT_PARAMTABLE_PURE))
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
			pp = (recursion_direction_right ? &pp->get(1) : &pp->get(0));
		}
	} while (pp->token_equals(TokenMeta::NT_PARAMTABLE_PURE));
}