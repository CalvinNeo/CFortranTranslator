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

#pragma once

#include "parser.h"
#include "attribute.h"
#include "gen_config.h"
#include "context.h"
#include <boost/lexical_cast.hpp>

std::string for2cpp(std::string for_code);

ParseNode gen_token(Term term);
ParseNode gen_dummy();
ParseNode gen_promote(std::string rule, int merged_token_meta, const ParseNode & lower);
ParseNode gen_promote(int merged_token_meta, const ParseNode & lower);
template <typename Iterator, typename F>
std::string make_str_list(Iterator begin, Iterator end, F handler, std::string delim = ", ") {
	std::string r;
	for (auto i = begin; i != end; i++)
	{
		if (i != begin) {
			r += delim;
		}
		r += handler(*i);
	}
	return r;
}

FlexState gen_flex(Term term);
ParseNode gen_flattern(const ParseNode & item, const ParseNode & list, std::string merge_rule, int merged_token_meta = -1, bool left_recursion = false);
ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, int merged_token_meta = -1);

std::string parse_ioformatter(const std::string &); 
void regen_read(ParseNode & stmt);
void regen_write(ParseNode & stmt);
void regen_print(ParseNode & stmt);
ParseNode gen_format(const ParseNode & format);

ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule);
ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule);

std::string get_variable_name(ParseNode & entity_variable);
ParseNode gen_vardef(const ParseNode & type_nospec, const ParseNode & variable_desc, const ParseNode & paramtable);
void regen_vardef(VariableInfo * vinfo, ParseNode & vardef_node, ParseNode & type_nospec, VariableDesc & desc, ParseNode & entity_variable);
std::string gen_vardef_array_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str, const std::tuple<std::vector<int>, std::vector<int>> & shape);
std::string gen_vardef_scalar_str(VariableInfo * vinfo, ParseNode & entity_variable, std::string type_str);
std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape);
std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice);
ParseNode gen_vardef_from_implicit(const ParseNode & type, std::string name);

std::vector<ParseNode *> get_all_explicit_declared(ParseNode & suite);
ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, const ParseNode & suite); // function define
void regen_function(ParseNode & functiondecl_node); // function define

ParseNode gen_select(const ParseNode & exp, const ParseNode & case_stmt);
ParseNode gen_case(const ParseNode & dimen_slice, const ParseNode & suite);

ParseNode gen_if(const ParseNode & exp, const ParseNode & suite_true, const ParseNode & elseif, const ParseNode & suite_else);
ParseNode gen_if_oneline(const ParseNode & exp, const ParseNode & stmt_true);
ParseNode gen_elseif(const ParseNode & exp, const ParseNode & suite_true, const ParseNode & elseif);

ParseNode gen_do(const ParseNode & suite);
ParseNode gen_do_range(const ParseNode & loop_variable, const ParseNode & exp1, const ParseNode & exp2, const ParseNode & exp3, const ParseNode & suite);
ParseNode gen_do_while(const ParseNode & exp, const ParseNode & suite);
ParseNode gen_hiddendo(const ParseNode & argtable, const ParseNode & index, const ParseNode & from, const ParseNode & to, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<const ParseNode *> gen_nested_hiddendo_layers(const ParseNode & hiddendo);
std::string gen_hiddendo_expr(const ParseNode & hiddendo);

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable); // callable, function call or array
ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable, const ParseNode & paramtable); // kwargs(not used)

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step);
ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub); 
ParseNode promote_exp_to_slice(const ParseNode & exp);
ParseNode promote_argtable_to_dimenslice(const ParseNode & argtable);

ParseNode gen_keyvalue_from_name(std::string name);
ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial);
ParseNode gen_paramtable(const ParseNode & paramtable_elem);
ParseNode gen_paramtable(const ParseNode & paramtable_elem, const ParseNode & paramtable);
ParseNode promote_exp_to_keyvalue(const ParseNode & paramtable_elem);
ParseNode promote_argtable_to_paramtable(const ParseNode & paramtable);

ParseNode implicit_type_from_name(std::string name);
ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind);
ParseNode gen_type(const ParseNode & type_nospec);
ParseNode gen_type(Term typeterm);
ParseNode promote_type(const ParseNode & type_spec, VariableDesc & vardesc);
std::string gen_qualified_typestr(const ParseNode & type_name, VariableDesc & vardesc);

ParseNode gen_dimenslice(const ParseNode & dimen_slice);
ParseNode gen_argtable(const ParseNode & argtable);

ParseNode gen_stmt(const ParseNode & content);
ParseNode gen_stmt(const ParseNode & content, const std::string & rules); 
std::string regen_suite(ParseNode & oldsuite, bool is_partial = false);

ParseNode gen_array_from_hiddendo(const ParseNode & hiddendo);
ParseNode gen_array_from_paramtable(const ParseNode & argtable);
void regen_arraybuilder_str(ParseNode & arraybuilder);

void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save);
VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node);
ParseNode gen_variabledesc_from_dimenslice(const ParseNode & dimen_slice);

ParseNode gen_interface(const ParseNode & wrappers);

void add_function_forward(const ParseNode & function_decl);

void log_format_index(std::string format_index, const ParseNode & format);
ParseNode require_format_index(std::string format_index);

std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

ParseNode gen_common_definition(std::string common_name);
ParseNode gen_common(const ParseNode & commonname_node, const ParseNode & paramtable);
void regen_common(ParseNode & common_block);
void check_implicit_variable(const ParseNode &);

ParseNode gen_program_explicit(ParseNode & suite);
ParseNode gen_program(ParseNode & suite);

void gen_fortran_program(const ParseNode & wrappers);

void do_trans(const std::string & src);
