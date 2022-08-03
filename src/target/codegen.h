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

#define WHEN_DEBUG_OR_EMPTY(STR) WHENDEBUG(STR, "")

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

// Regen functions
void regen_read(FunctionInfo * finfo, ParseNode & stmt);
void regen_write(FunctionInfo * finfo, ParseNode & stmt);
void regen_print(FunctionInfo * finfo, ParseNode & stmt);
std::string regen_vardef(FunctionInfo * finfo, VariableInfo * vinfo, std::string alias_name = "", bool save_to_node = true);
std::string regen_vardef_array_initial_str(FunctionInfo * finfo, VariableInfo * vinfo, ParseNode & slice_node); // only called by regen_vardef
std::string regen_vardef_scalar_initial_str(FunctionInfo * finfo, VariableInfo * vinfo); // only called by regen_vardef
void regen_function(FunctionInfo * finfo, ParseNode & functiondecl_node);
void regen_function_1(FunctionInfo * finfo, ParseNode & functiondecl_node);
void regen_function_2(FunctionInfo * finfo);
void regen_derived_type_1(TypeInfo* finfo, ParseNode& functiondecl_node);
void regen_derived_type_2(TypeInfo* tinfo);
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

// In-context functions
SliceBoundInfo get_lbound_size_from_slice(FunctionInfo * finfo, ParseNode & dimen_slice);
SliceBoundInfo get_lbound_size_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo, std::vector<ParseNode *> hiddendo_layer);
SliceBoundInfo get_lbound_ubound_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo, std::vector<ParseNode *> hiddendo_layer);
std::vector<VariableInfo *> get_all_declared_vinfo(FunctionInfo * finfo, const ParseNode & suite);
std::vector<ParseNode *> get_all_declared_nodes(FunctionInfo * finfo, ParseNode & suite);
VariableInfo * check_implicit_variable(FunctionInfo * finfo, const std::string & name);
ParseNode gen_implicit_type(FunctionInfo * finfo, std::string name);
ParseNode require_format_index(FunctionInfo * finfo, std::string format_index);
void get_full_paramtable(FunctionInfo * finfo);
std::string gen_function_signature(FunctionInfo * finfo, int style = 0);
std::vector<std::string> gen_func_alias_signature(FunctionInfo * finfo);
std::string gen_paramtable_str(FunctionInfo * finfo, const std::vector<std::string> & paramtable_info, bool with_name = true);

// var def
ParseNode gen_vardef(const ParseNode & type_nospec, const ParseNode & variable_desc, const ParseNode & paramtable);
ParseNode gen_vardef_from_default(const ParseNode & type, std::string name);
std::string get_variable_name(const ParseNode & entity_variable);

// hidden do
#define get_all_declared get_all_declared_vinfo
ParseNode gen_hiddendo(const ParseNode & argtable, const ParseNode & index, const ParseNode & from, const ParseNode & to, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<ParseNode *> get_nested_hiddendo_layers(ParseNode & hiddendo);
std::vector<ParseNode *> get_parent_hiddendo_layers(ParseNode & hiddendo);

// slices and paramtables
ParseNode promote_exp_to_slice(const ParseNode & exp);
ParseNode promote_argtable_to_dimenslice(const ParseNode & argtable);
ParseNode gen_keyvalue_from_name(std::string name);
ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial);
ParseNode promote_exp_to_keyvalue(const ParseNode & paramtable_elem);
ParseNode promote_argtable_to_paramtable(const ParseNode & paramtable);
ParseNode gen_pure_paramtable(const ParseNode & paramtable_elem);
ParseNode gen_pure_paramtable(ParseNode & paramtable_elem, ParseNode & paramtable, bool left_recursion = false);
ParseNode gen_arraybuilder_from_paramtable(const ParseNode & argtable);
void foreach_paramtable(const ParseNode & pn, std::function<void(const ParseNode &)> f, bool recursion_direction_right);
void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional
	, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save, boost::optional<bool> allocatable, boost::optional<bool> target
	, boost::optional<bool> pointer, boost::optional<bool> inout_reference);
VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node);

// type
ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind);
ParseNode gen_type(const ParseNode & type_nospec);
ParseNode gen_type(Term typeterm);
std::string gen_qualified_typestr(const ParseNode & type_spec, VariableDesc & vardesc, bool in_paramtable);

// label
void log_format_index(std::string format_index, const ParseNode & format);

// copyrights
std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

// common
ParseNode gen_common_definition(std::string common_name);
ParseNode gen_common(const ParseNode & commonname_node, const ParseNode & paramtable);
ParseNode gen_comment(std::string comment, bool line_comment = true);
CommonBlockInfo * add_commonblock(std::string commonblock_name);
CommonBlockInfo * get_commonblock(std::string commonblock_name);

// function decl
ParseNode gen_suite(const ParseNode & item, const ParseNode & list);
std::string get_mapped_function_name(std::string origin_name);

// program 
void gen_fortran_program(const ParseNode & wrappers);
void do_trans(const std::string & src);
