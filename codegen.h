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

// generate token from several or none childs by given Term
ParseNode gen_token(Term term);
template <typename ... Args>
ParseNode gen_token(Term term, Args&& ... args) {
	ParseNode newnode = gen_token(term);
	newnode.addlist(std::forward<Args>(args)...);
	return newnode;
}
ParseNode gen_dummy();
// generate token from several or none childs by given pattern

template<typename ... Args>
void sprintf_wrapper(std::string format, Args&& ... args) {
	sprintf(codegen_buf, format.c_str(), [&](const ParseNode & x) {return x.fs.CurrentTerm.what.c_str(); }(args)...);
}
template <typename ... Args>
ParseNode gen_promote(std::string rule, int merged_token_meta, Args&& ... items) {
	sprintf_wrapper(rule, std::forward<Args>(items)...);
	ParseNode newnode = gen_token(Term{ merged_token_meta, string(codegen_buf) });
	newnode.addlist(std::forward<Args>(items)...);
	return newnode;
}
FlexState gen_flex(Term term);
ParseNode gen_flattern(ARG_IN item, ARG_IN list, std::string merge_rule, int merged_token_meta = -1, bool left_recursion = false);
ParseNode gen_merge(ARG_IN list1, ARG_IN list2, std::string merge_rule, int merged_token_meta = -1);

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


void regen_read(FunctionInfo * finfo, ARG_OUT stmt);
void regen_write(FunctionInfo * finfo, ARG_OUT stmt);
void regen_print(FunctionInfo * finfo, ARG_OUT stmt);
void regen_vardef(VariableInfo * vinfo, ARG_OUT vardef_node, ARG_OUT type_nospec, VariableDesc & desc, ARG_OUT entity_variable); 
void regen_function(FunctionInfo * finfo, ARG_OUT functiondecl_node); // function define
void regen_select(FunctionInfo * finfo, ARG_OUT select_stmt);
void regen_if(FunctionInfo * finfo, ARG_OUT if_stmt);
void regen_elseif(FunctionInfo * finfo, ARG_OUT elseif_stmt);
void regen_do(FunctionInfo * finfo, ARG_OUT do_stmt);
void regen_do_range(FunctionInfo * finfo, ARG_OUT do_stmt);
void regen_do_while(FunctionInfo * finfo, ARG_OUT do_stmt);
void regen_simple_stmt(FunctionInfo * finfo, ARG_OUT stmt);
void regen_suite(FunctionInfo * finfo, ARG_OUT oldsuite, bool is_partial = false);
void regen_arraybuilder(ARG_OUT arraybuilder);
void regen_common(FunctionInfo * finfo, ARG_OUT common_block);
void promote_type(ARG_OUT type_nospec, VariableDesc & vardesc);

std::string parse_ioformatter(const std::string &); 
ParseNode gen_format(ARG_IN format);

ParseNode gen_vardef(ARG_IN type_nospec, ARG_IN variable_desc, ARG_IN paramtable);

std::string get_variable_name(ParseNode & entity_variable);
std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice);
ParseNode gen_vardef_from_implicit(ARG_IN type, std::string name);

std::vector<ParseNode *> get_all_explicit_declared(FunctionInfo * finfo, ParseNode & suite);
ParseNode gen_function(ARG_IN variable_function, ARG_IN paramtable, ARG_IN variable_result, ARG_IN suite); // function define

ParseNode gen_hiddendo(ARG_IN argtable, ARG_IN index, ARG_IN from, ARG_IN to, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<const ParseNode *> gen_nested_hiddendo_layers(ARG_IN hiddendo);
std::string gen_hiddendo_expr(ARG_IN hiddendo);

ParseNode gen_function_array(ARG_IN callable_head, ARG_IN argtable); // callable, function call or array


ParseNode promote_exp_to_slice(ARG_IN exp);
ParseNode promote_argtable_to_dimenslice(ARG_IN argtable);

ParseNode gen_keyvalue_from_name(std::string name);
ParseNode gen_keyvalue_from_exp(ARG_IN variable, ARG_IN initial);
ParseNode promote_exp_to_keyvalue(ARG_IN paramtable_elem);
ParseNode promote_argtable_to_paramtable(ARG_IN paramtable);
ParseNode gen_paramtable(ARG_IN paramtable_elem);
ParseNode gen_paramtable(ARG_IN paramtable_elem, ARG_IN paramtable);
ParseNode gen_dimenslice(ARG_IN dimen_slice);
ParseNode gen_argtable(ARG_IN argtable);

ParseNode implicit_type_from_name(std::string name);
ParseNode gen_type(ARG_IN type_nospec, ARG_IN _type_kind);
ParseNode gen_type(ARG_IN type_nospec);
ParseNode gen_type(Term typeterm);
std::string gen_qualified_typestr(ARG_IN type_name, VariableDesc & vardesc);


ParseNode gen_array_from_hiddendo(ARG_IN hiddendo);
ParseNode gen_array_from_paramtable(ARG_IN argtable);

void set_variabledesc_attr(ARG_OUT vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save);
VariableDesc & get_variabledesc_attr(ARG_OUT vardescattr_node);
ParseNode gen_variabledesc_from_dimenslice(ARG_IN dimen_slice);

void add_function_forward(ARG_IN function_decl);

void log_format_index(std::string format_index, ARG_IN format);
ParseNode require_format_index(std::string format_index);

std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

ParseNode gen_common_definition(std::string common_name);
ParseNode gen_common(ARG_IN commonname_node, ARG_IN paramtable);
void check_implicit_variable(ARG_IN);


void gen_fortran_program(ARG_IN wrappers);

void do_trans(const std::string & src);
