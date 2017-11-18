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
// this file functions as an api
#include "../parser/context.h"
#include "../parser/attribute.h"
#include "gen_config.h"
#include <boost/lexical_cast.hpp>

#define WHENDEBUG_OREMPTYSTR(STR) WHENDEBUG(STR, "")

inline TokenizerState gen_flex(const Term & term) {
	TokenizerState f;
	f.CurrentTerm = term;
	f.line_pos = f.parse_len = f.parse_line = f.parse_pos = 0;
	return f;
}

typedef std::vector<std::string> SliceIndexInfo;
//typedef std::vector<std::string> SliceSizeInfo;
typedef std::tuple<SliceIndexInfo, SliceIndexInfo> SliceBoundInfo;

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
std::string regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo, std::string alias_name = "", bool save_to_node = true);
void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node);
void regen_function_1(FunctionInfo * finfo, ParseNode & functiondecl_node);
void regen_function_2(FunctionInfo * finfo);
void regen_select(FunctionInfo * finfo, ParseNode & select_stmt);
void regen_if(FunctionInfo * finfo, ParseNode & if_stmt);
void regen_elseif(FunctionInfo * finfo, ParseNode & elseif_stmt);
void regen_do(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_do_range(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_do_while(FunctionInfo * finfo, ParseNode & do_stmt);
void regen_simple_stmt(FunctionInfo * finfo, ParseNode & stmt);
void regen_all_variables(FunctionInfo * finfo, ParseNode & oldsuite);
void regen_all_variables_decl_str(FunctionInfo * finfo, ParseNode & oldsuite);
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
void regen_type(ParseNode & type_nospec, FunctionInfo * finfo, VariableInfo * vinfo);
void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo);
void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo, std::function<void(ParseNode &)> regen_innermost_argtable);
void regen_hiddendo_exprex(FunctionInfo * finfo, ParseNode & hiddendo);
void regen_hiddendo_exprex(FunctionInfo * finfo, ParseNode & hiddendo, std::function<void(ParseNode &)> regen_innermost);



// var def
ParseNode gen_vardef(ARG_IN type_nospec, ARG_IN variable_desc, ARG_IN paramtable);
ParseNode gen_vardef_from_default(ARG_IN type, std::string name);
std::string gen_vardef_array_initial_str(FunctionInfo * finfo, VariableInfo * vinfo, const ParseNode & additional_desc);
std::string gen_vardef_scalar_initial_str(FunctionInfo * finfo, VariableInfo * vinfo);
std::string get_variable_name(ARG_IN entity_variable);
SliceBoundInfo get_lbound_size_from_slice(const ParseNode & slice);

// hidden do
#define get_all_declared get_all_declared_vinfo
std::vector<VariableInfo *> get_all_declared_vinfo(FunctionInfo * finfo, ARG_IN suite);
std::vector<ParseNode *> get_all_declared_nodes(FunctionInfo * finfo, ParseNode & suite);
ParseNode gen_hiddendo(ARG_IN argtable, ARG_IN index, ARG_IN from, ARG_IN to, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<ParseNode *> get_nested_hiddendo_layers(ParseNode & hiddendo);
std::vector<ParseNode *> get_parent_hiddendo_layers(ParseNode & hiddendo);
SliceBoundInfo get_lbound_size_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo, std::vector<ParseNode *> hiddendo_layer);
SliceBoundInfo get_lbound_ubound_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo, std::vector<ParseNode *> hiddendo_layer);

// slices and paramtables
ParseNode promote_exp_to_slice(ARG_IN exp);
ParseNode promote_argtable_to_dimenslice(ARG_IN argtable);
ParseNode gen_keyvalue_from_name(std::string name);
ParseNode gen_keyvalue_from_exp(ARG_IN variable, ARG_IN initial);
ParseNode promote_exp_to_keyvalue(ARG_IN paramtable_elem);
ParseNode promote_argtable_to_paramtable(ARG_IN paramtable);
ParseNode gen_pure_paramtable(ARG_IN paramtable_elem);
ParseNode gen_pure_paramtable(ARG_IN paramtable_elem, ARG_IN paramtable, bool left_recursion = false);
ParseNode gen_array_from_paramtable(ARG_IN argtable);
void foreach_paramtable(const ParseNode & pn, std::function<void(const ParseNode &)> f, bool recursion_direction_right);
void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional
	, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save, boost::optional<bool> allocatable, boost::optional<bool> target, boost::optional<bool> pointer);
VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node);
std::string gen_paramtable_str(FunctionInfo * finfo, const std::vector<std::string> & paramtable_info, bool with_name = true);


// type
ParseNode gen_implicit_type(FunctionInfo * finfo, std::string name);
ParseNode gen_type(ARG_IN type_nospec, ARG_IN _type_kind);
ParseNode gen_type(ARG_IN type_nospec);
ParseNode gen_type(Term typeterm);
std::string gen_qualified_typestr(const ParseNode & type_spec, VariableDesc & vardesc, bool in_paramtable);

// label
void log_format_index(std::string format_index, ARG_IN format);
ParseNode require_format_index(FunctionInfo * finfo, std::string format_index);

// copyrights
std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

// common
ParseNode gen_common_definition(std::string common_name);
ParseNode gen_common(ARG_IN commonname_node, ARG_IN paramtable);
VariableInfo * check_implicit_variable(FunctionInfo * finfo, const std::string & name);
ParseNode gen_comment(std::string comment, bool line_comment = true);
CommonBlockInfo * add_commonblock(std::string commonblock_name);
CommonBlockInfo * get_commonblock(std::string commonblock_name);

// function decl
ParseNode gen_function(ARG_IN variable_function, ARG_IN paramtable, ARG_IN variable_result, ARG_IN suite);
ParseNode gen_suite(ARG_IN item, ARG_IN list);
void get_full_paramtable(FunctionInfo * finfo);
std::string get_mapped_function_name(std::string origin_name);
std::string gen_function_signature(FunctionInfo * finfo, int style = 0);

// program 
void gen_fortran_program(ARG_IN wrappers);
void do_trans(const std::string & src);
