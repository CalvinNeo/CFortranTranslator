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

VariableInfo* get_vinfo(FunctionInfo* finfo, ParseNode& exp);
void parse_inner_variable(FunctionInfo* finfo, ParseNode& exp);
void add_star(ParseNode& exp);
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
		if (get_vinfo(finfo,exp)->desc.pointer.isdirty()) {
			add_star(exp);
		}
	}
	else if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY))
	{
		if (exp.get(0).token_equals(TokenMeta::NT_DERIVED_TYPE)|| exp.get(0).token_equals(TokenMeta::UnknownVariant)) {
			regen_exp(finfo, exp.get(0));
		}
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
		
		parse_inner_variable(finfo, exp);
		//regen_derived_type_1(finfo, exp);

		//ParseNode& var = exp.get(0);
		//std::string var_name = get_variable_name(var);
		//VariableInfo* local_vinfo = get_variable(get_context().current_module, finfo->local_name, var_name);
		//if (local_vinfo->desc.pointer.isdirty()) {
		//	std::string str = exp.get_what().replace(var.fs.parse_len, 1, "->");
		//}

		//std::map < std::string, VariableInfo* > variables = get_context().variables;
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

VariableInfo* get_vinfo(FunctionInfo* finfo, ParseNode& exp) {
	if (exp.token_equals(TokenMeta::NT_FUCNTIONARRAY)) {
		return get_vinfo(finfo, exp.get(0));
	}

	if (exp.token_equals(TokenMeta::NT_DERIVED_TYPE)) {
		VariableInfo* parent_vinfo = get_vinfo(finfo, exp.get(0));
		std::string member = exp.get_what().substr(exp.get_what().rfind(".") + 1);
		return get_variable(get_context().current_module, parent_vinfo->type.get_what(), member);
	}

	return get_variable(get_context().current_module, finfo->local_name, get_variable_name(exp));
}

void parse_inner_variable(FunctionInfo* finfo, ParseNode& exp) {
	VariableInfo* overall_vinfo = get_vinfo(finfo, exp);
	for (ParseNode * var : exp.child)
	{
		bool is_array = (*var).token_equals(TokenMeta::NT_FUCNTIONARRAY);
		if (var->token_equals(TokenMeta::NT_FUCNTIONARRAY)||var->token_equals(TokenMeta::UnknownVariant)) {
			std::string toReplace = var->get_what();
			regen_exp(finfo, (*var));
			exp.get_what().replace(exp.get_what().find(toReplace), toReplace.length(), var->get_what());
			/*exp.father->get_what().replace(exp.father->get_what().find(toReplace), toReplace.length(), var->get_what());*/
		}
	}

	//VariableInfo* overall_vinfo = get_vinfo(finfo, exp);
	//std::map < std::string, VariableInfo* > variables = get_context().variables;
	if (overall_vinfo->desc.pointer.isdirty()) {
		add_star(exp);
	}
}

void add_star(ParseNode & exp) {
	if (exp.father->token_equals(TokenMeta::NT_EXPRESSION) && exp.father->get(2).get_what() == "%s =&(%s)") {
		/*do not add '*' */
	}
	else {
		std::string toReplace = exp.get_what();
		exp.get_what() = "(*(" + exp.get_what() + "))";
		//exp.father->get_what().replace(exp.father->get_what().find(toReplace), toReplace.length(), "(*" + toReplace + ")");
	}
}