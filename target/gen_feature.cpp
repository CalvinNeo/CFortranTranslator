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
	return elem.get_token() == TokenMeta::NT_DIMENSLICE || elem.get_token() == TokenMeta::NT_SLICE; 
}
bool is_argtable(const ParseNode & elem) {
	return elem.get_token() == TokenMeta::NT_ARGTABLE_PURE ||
		(is_element(elem) || is_exp(elem) );
}
bool is_paramtable(const ParseNode & elem) {
	return elem.get_token() == TokenMeta::NT_PARAMTABLE_PURE || elem.get_token() == TokenMeta::NT_KEYVALUE;
}

bool is_function_array(const ParseNode & entity_variable) {
	const ParseNode & entity_variable_name = entity_variable.get(0);
	if (entity_variable_name.get_token() == TokenMeta::NT_FUCNTIONARRAY)
	{
		return true;
	}
	return false;
}

bool is_exp(const ParseNode & exp) {
	TokenMeta_T tok = exp.get_token();
	bool res;
	switch (tok)
	{
	case TokenMeta::NT_EXPRESSION:
	case TokenMeta::NT_ARRAYBUILDER_LIST:
	case TokenMeta::NT_FUCNTIONARRAY:
	case TokenMeta::NT_HIDDENDO:
		res = true;
	default:
		res = false;
	}
	return res;
}

bool is_element(const ParseNode & elem) {
	TokenMeta_T tok = elem.get_token();
	if (is_literal(elem)) return true;
	if (tok == TokenMeta::META_WORD) return true;
	if (tok == TokenMeta::Bool) return true;
	if (tok == TokenMeta::UnknownVariant) return true;
	return false;
}
bool is_literal(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (is_int(lit)) return true;
	if (is_str(lit)) return true;
	if (is_floating(lit)) return true;
	if (tok == TokenMeta::Bool) return true;
	if (tok == TokenMeta::Complex) return true;
	if (tok == TokenMeta::Function) return true;
	if (tok == TokenMeta::False) return true;
	if (tok == TokenMeta::True) return true;
	return false;
}

bool is_int(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (tok == TokenMeta::Int) return true;
	if (tok == TokenMeta::Char) return true;
	if (tok == TokenMeta::Int8) return true;
	if (tok == TokenMeta::Int16) return true;
	if (tok == TokenMeta::Int32) return true;
	if (tok == TokenMeta::Int16) return true;
	if (tok == TokenMeta::Int64) return true;
	return false;
}

bool is_str(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (tok == TokenMeta::String) return true;
	return false;
}

bool is_floating(const ParseNode & lit) {
	TokenMeta_T tok = lit.get_token();
	if (tok == TokenMeta::Double) return true;
	if (tok == TokenMeta::LongDouble) return true;
	if (tok == TokenMeta::Float) return true;
	return false;
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
			// registed function
			return true;
		}
	}
	else {
		if (vinfo->type.get_token() == TokenMeta::Function_Decl || vinfo->type.get_token() == TokenMeta::Function)
		{
			// interface
			return true;
		}
		else {
			return false;
		}
	}
}