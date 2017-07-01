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


#include "../parser/context.h"
#include "../parser/attribute.h"
#include "gen_config.h"
#include <boost/lexical_cast.hpp>

#define WHENDEBUG_OREMPTYSTR(STR) WHENDEBUG(STR, "")

FlexState gen_flex(Term term);
/****************
* `gen_token` generate token from several or none childs by given **Term**
* Usage:
* if the node generate a invariant string, use `gen_token`, otherwise, `gen_promote`
*****************/
inline ParseNode gen_token(Term term) {
	// four `_pos` is set by update_pos in for90.y
	return ParseNode(gen_flex(term), nullptr);
}
template <typename ... Args>
ParseNode gen_token(Term term, Args&& ... args) {
	ParseNode newnode = gen_token(term);
	newnode.addlist(std::forward<Args>(args)...);
	return newnode;
}
ParseNode gen_dummy();

/****************
* `gen_promote` generate token from several or none childs by given **pattern**
* Usage:
* if the node generate a string depend on its child by given rule, use `gen_promote`, otherwise, `gen_token`
*****************/
template<typename ... Args>
void sprintf_wrapper(std::string format, Args&& ... args) {
	sprintf(codegen_buf, format.c_str(), [&](const ParseNode & x) {return x.get_what().c_str(); }(args)...);
}
template <typename ... Args>
ParseNode gen_promote(std::string rule, TokenMeta_T merged_token_meta, Args&& ... items) {
	sprintf_wrapper(rule, std::forward<Args>(items)...);
	ParseNode newnode = gen_token(Term{ merged_token_meta, string(codegen_buf) });
	newnode.addlist(std::forward<Args>(items)...);
	return newnode;
}
/****************
* `gen_flattern` append an item to a list
*****************/
ParseNode gen_flattern(ARG_IN item, ARG_IN list, std::string merge_rule, TokenMeta_T merged_token_meta = TokenMeta::USE_DEFAULT_VALUE, bool left_recursion = false);
/****************
* `gen_merge` merge two lists
*****************/
ParseNode gen_merge(ARG_IN list1, ARG_IN list2, std::string merge_rule, TokenMeta_T merged_token_meta);

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


typedef std::vector<std::string> SliceLBoundInfo;
typedef std::vector<std::string> SliceSizeInfo;
typedef std::tuple<SliceLBoundInfo, SliceSizeInfo> SliceBoundInfo;

bool is_dimenslice(const ParseNode & elem);
bool is_argtable(const ParseNode & elem);
bool is_paramtable(const ParseNode & elem);
bool is_function_array(const ParseNode & entity_variable);
bool is_exp(const ParseNode & exp); 
bool is_element(const ParseNode & x);
bool is_literal(const ParseNode & x);
bool is_str(const ParseNode & x);
bool is_int(const ParseNode & x);
bool is_floating(const ParseNode & x);
bool is_fortran_function(FunctionInfo * finfo, std::string name);

void regen_read(FunctionInfo * finfo, ParseNode & stmt);
void regen_write(FunctionInfo * finfo, ParseNode & stmt);
void regen_print(FunctionInfo * finfo, ParseNode & stmt);
void regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo, VariableDesc & desc);
void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node);
void regen_select(FunctionInfo * finfo, ParseNode & select_stmt);
void regen_if(FunctionInfo * finfo, ParseNode & if_stmt);
void regen_elseif(FunctionInfo * finfo, ParseNode & elseif_stmt);
void regen_do(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_do_range(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_do_while(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_simple_stmt(FunctionInfo * finfo, ParseNode & stmt);
std::string gen_joined_declarations(FunctionInfo * finfo, ParseNode & oldsuite);
void regen_suite(FunctionInfo * finfo, ParseNode & oldsuite, bool is_partial = false);
std::string regen_stmt(FunctionInfo * finfo, ParseNode & stmt);
void regen_arraybuilder(FunctionInfo * finfo, ParseNode & arraybuilder);
void regen_common(FunctionInfo * finfo, ParseNode & common_block);
void promote_type(ParseNode & type_nospec, VariableDesc & vardesc);
void regen_exp(FunctionInfo * finfo, ParseNode & exp);
void regen_paramtable(FunctionInfo * finfo, ParseNode & paramtable);
void regen_function_array(FunctionInfo * finfo, ParseNode & callable);
void regen_slice(FunctionInfo * finfo, ParseNode & slice);
void insert_comments(ParseNode & newnode);

ParseNode gen_format(ARG_IN format);

ParseNode gen_vardef(ARG_IN type_nospec, ARG_IN variable_desc, ARG_IN paramtable);

std::string get_variable_name(const ParseNode & entity_variable);
SliceBoundInfo get_lbound_size_from_slice(const ParseNode & slice);
ParseNode gen_vardef_from_default(ARG_IN type, std::string name);

#define get_all_declared get_all_declared_vinfo

std::vector<VariableInfo *> get_all_declared_vinfo(FunctionInfo * finfo, ARG_IN suite);
std::vector<ParseNode *> get_all_declared_by_node(FunctionInfo * finfo, ParseNode & suite);
ParseNode gen_function(ARG_IN variable_function, ARG_IN paramtable, ARG_IN variable_result, ARG_IN suite); 
ParseNode gen_hiddendo(ARG_IN argtable, ARG_IN index, ARG_IN from, ARG_IN to, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<ParseNode *> get_nested_hiddendo_layers(ParseNode & hiddendo);
SliceBoundInfo get_lbound_size_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo);
void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo);
void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo, std::function<void(ParseNode &)> regen_innermost);

ParseNode gen_function_array(ARG_IN callable_head, ARG_IN argtable); 


ParseNode promote_exp_to_slice(ARG_IN exp);
ParseNode promote_argtable_to_dimenslice(ARG_IN argtable);

ParseNode gen_keyvalue_from_name(std::string name);
ParseNode gen_keyvalue_from_exp(ARG_IN variable, ARG_IN initial);
ParseNode promote_exp_to_keyvalue(ARG_IN paramtable_elem);
ParseNode promote_argtable_to_paramtable(ARG_IN paramtable);
ParseNode gen_pure_paramtable(ARG_IN paramtable_elem);
ParseNode gen_pure_paramtable(ARG_IN paramtable_elem, ARG_IN paramtable, bool left_recursion = false);
ParseNode gen_dimenslice(ARG_IN dimen_slice);
ParseNode gen_argtable(ARG_IN argtable);
void foreach_paramtable(const ParseNode & pn, std::function<void(const ParseNode &)> f, bool recursion_direction_right);

ParseNode gen_implicit_type(std::string name);
ParseNode gen_type(ARG_IN type_nospec, ARG_IN _type_kind);
ParseNode gen_type(ARG_IN type_nospec);
ParseNode gen_type(Term typeterm);
std::string gen_qualified_typestr(const ParseNode & type_spec, VariableDesc & vardesc);

ParseNode gen_array_from_paramtable(ARG_IN argtable);

void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save);
VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node);
ParseNode gen_variabledesc_from_dimenslice(ARG_IN dimen_slice);

void add_function_forward(ARG_IN function_decl);

void log_format_index(std::string format_index, ARG_IN format);
ParseNode require_format_index(std::string format_index);

std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

ParseNode gen_common_definition(std::string common_name);
ParseNode gen_common(ARG_IN commonname_node, ARG_IN paramtable);
VariableInfo * check_implicit_variable(FunctionInfo * finfo, const std::string & name);
ParseNode gen_comment(std::string comment, bool line_comment = true);

ParseNode gen_suite(ARG_IN item, ARG_IN list);
void get_full_paramtable(FunctionInfo * finfo);

std::string get_mapped_function_name(std::string origin_name);

void gen_fortran_program(ARG_IN wrappers);

void do_trans(const std::string & src);


template <typename Iterator>
std::string gen_lbound_size_str(Iterator lb_begin, Iterator lb_end, Iterator sz_begin, Iterator sz_end) {
	std::string size_str, lbound_str;
	lbound_str = make_str_list(lb_begin, lb_end, [&](auto x) { return x; });
	size_str = make_str_list(sz_begin, sz_end, [&](auto x) { return x; });
	sprintf(codegen_buf, "{%s}, {%s}", lbound_str.c_str(), size_str.c_str());
	return string(codegen_buf);
}

template <typename Iterator, typename Func1, typename Func2>
SliceBoundInfo get_lbound_size_base(Iterator begin, Iterator end, Func1 get_lb, Func2 get_sz) {
	SliceLBoundInfo lb(end - begin);
	SliceSizeInfo sz(end - begin);
	transform(begin, end, lb.begin(), get_lb);
	transform(begin, end, sz.begin(), get_sz);
	return make_tuple(lb, sz);
}