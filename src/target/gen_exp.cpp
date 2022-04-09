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

void regen_exp(FunctionInfo * finfo, ParseNode & exp) {
	if (exp.token_equals(TokenMeta::NT_EXPRESSION))
	{
		if (exp.length() == 2)
		{
			// unary op
			regen_exp(finfo, exp.get(0));
			ParseNode & op = exp.get(1);
			sprintf(codegen_buf, op.get_what().c_str(), exp.get(0).get_what().c_str());
			exp.get_what() = string(codegen_buf);
		}
		else if (exp.length() == 3) {
			// binary op
			regen_exp(finfo, exp.get(0));
			regen_exp(finfo, exp.get(1));
			ParseNode & op = exp.get(2);
			sprintf(codegen_buf, op.get_what().c_str(), exp.get(0).get_what().c_str(), exp.get(1).get_what().c_str());
			exp.get_what() = string(codegen_buf);
		}
		else if (exp.length() == 1) {
			// function_array, array_builder, hidden_do
			ParseNode & elem = exp.get(0);
		}
		else if (exp.length() == 0) {
			print_error("error empty expression: ", exp);
		}
		else {
			print_error("error expression: ", exp);
		}
	}
	else if (exp.token_equals(TokenMeta::NT_DERIVED_TYPE)) {
		std::string what = exp.get_what();
		std::string local_name = finfo->local_name;
		int pos = 0;
		for each (ParseNode *var in exp.child)
		{
			std::string var_name = get_variable_name(*var);
			VariableInfo* local_vinfo = get_variable(get_context().current_module, local_name, var_name);
			if (local_vinfo->desc.pointer.isdirty()) {
				int target_pos = pos + var->fs.parse_len;
				std::string str = exp.get_what().replace(target_pos, 1, "->");
				pos = target_pos + 2;
			}
			else {
				pos+= var->fs.parse_len+1;
			}
			local_name = local_vinfo->type.get_what();
		}

		//ParseNode& var = exp.get(0);
		//std::string var_name = get_variable_name(var);
		//VariableInfo* local_vinfo = get_variable(get_context().current_module, finfo->local_name, var_name);
		//if (local_vinfo->desc.pointer.isdirty()) {
		//	std::string str = exp.get_what().replace(var.fs.parse_len, 1, "->");
		//}

		//std::map < std::string, VariableInfo* > variables = get_context().variables;

	}
	else if(is_literal(exp))
	{
		if (exp.token_equals(TokenMeta::String))
		{
			sprintf(codegen_buf, "SS(%s)", exp.get_what().c_str());
			exp.get_what() = string(codegen_buf);
		}
	}
	else if (exp.token_equals(TokenMeta::UnknownVariant))
	{
		check_implicit_variable(finfo, exp.to_string());
	}
	else if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY))
	{
		regen_function_array(finfo, exp);
	}
	else if (exp.token_equals(TokenMeta::NT_HIDDENDO))
	{
		regen_hiddendo_exprex(finfo, exp);
	}
	else if (exp.token_equals(TokenMeta::Comments))
	{
		
	}
	else if (exp.token_equals(TokenMeta::NT_ARRAYBUILDER_LIST))
	{
		regen_arraybuilder(finfo, exp);
	}
	else if (exp.token_equals(TokenMeta::NT_DERIVED_TYPE))
	{
		//regen_derived_type_1(finfo, exp);
	}
	else if (exp.token_equals(TokenMeta::NT_VARIABLEDEFINESET))
	{
	}
	else if (exp.token_equals(TokenMeta::NT_STATEMENT))
	{
	}
	else {
		print_error("error exp: ", exp);
	}
}