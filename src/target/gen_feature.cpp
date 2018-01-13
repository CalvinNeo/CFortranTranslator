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
	return elem.token_equals(TokenMeta::NT_DIMENSLICE, TokenMeta::NT_SLICE) ;
}
bool is_argtable(const ParseNode & elem) {
	return elem.token_equals(TokenMeta::NT_ARGTABLE_PURE) ||
		(is_element(elem) || is_exp(elem) );
}
bool is_paramtable(const ParseNode & elem) {
	return elem.token_equals(TokenMeta::NT_PARAMTABLE_PURE, TokenMeta::NT_KEYVALUE);
}

bool is_function_array(const ParseNode & entity_variable) {
	const ParseNode & entity_variable_name = entity_variable.get(0);
	if (entity_variable_name.token_equals(TokenMeta::NT_FUCNTIONARRAY))
	{
		return true;
	}
	return false;
}

bool is_exp(const ParseNode & exp) {
	TokenMeta_T tok = exp.get_token();
	bool isexp;
	switch (tok)
	{
	case TokenMeta::NT_EXPRESSION:
	case TokenMeta::NT_ARRAYBUILDER_LIST:
	case TokenMeta::NT_FUCNTIONARRAY:
	case TokenMeta::NT_HIDDENDO:
		isexp = true;
	default:
		isexp = false;
	}
	return isexp;
}

bool is_element(const ParseNode & elem) {
	TokenMeta_T tok = elem.get_token();
	if (is_literal(elem)) return true;
	return elem.token_equals(TokenMeta::META_WORD, TokenMeta::Bool, TokenMeta::UnknownVariant);
}
bool is_literal(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (is_int(lit)) return true;
	if (is_str(lit)) return true;
	if (is_floating(lit)) return true;
	return lit.token_equals(TokenMeta::Bool, TokenMeta::Complex, TokenMeta::Function, TokenMeta::False, TokenMeta::True);
}

bool is_int(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	return lit.token_equals(TokenMeta::Int, TokenMeta::Char, TokenMeta::Int8, TokenMeta::Int16, TokenMeta::Int32, TokenMeta::Int64);
}

bool is_str(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (tok == TokenMeta::String) return true;
	return false;
}

bool is_floating(const ParseNode & lit) {
	return lit.token_equals(TokenMeta::Double, TokenMeta::LongDouble, TokenMeta::Float);
}


bool is_fortran_function(FunctionInfo * finfo, std::string name) {
	VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, name);
	if (vinfo == nullptr)
	{
		FunctionInfo * f = get_function(get_context().current_module, name);
		std::map<std::string, std::vector<KeywordParamInfo>>::iterator sysfunc = get_context().func_kwargs.find(get_mapped_function_name(name));
		if (f == nullptr && sysfunc == get_context().func_kwargs.end())
		{
			return false;
		}
		else {
			// registed function or sysfunc
			return true;
		}
	}
	else {
		if (vinfo->type.token_equals(TokenMeta::Function_Decl, TokenMeta::Function))
		{
			// interface
			return true;
		}
		else {
			return false;
		}
	}
}