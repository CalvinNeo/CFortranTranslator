#pragma once

#include "parser.h"
#include "attribute.h"

std::string for2cpp(std::string for_code);
ParseNode * flattern_bin(ParseNode * pn);
std::string tabber(std::string & src);

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
		r += handler(i);
	}
	return r;
}

FlexState gen_flex(Term term);
ParseNode gen_flattern(const ParseNode & item, const ParseNode & list, std::string merge_rule, int merged_token_meta = -1);
ParseNode gen_merge(const ParseNode & list1, const ParseNode & list2, std::string merge_rule, int merged_token_meta = -1);

std::string parse_ioformatter(const std::string &); 
ParseNode gen_read(const ParseNode & io_info, const ParseNode & argtable);
ParseNode gen_write(const ParseNode & io_info, const ParseNode & argtable);
ParseNode gen_print(const ParseNode & io_info, const ParseNode & argtable);

ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule);
ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule);

ParseNode gen_vardef(const ParseNode & type_spec, const ParseNode & variable_desc, const ParseNode & paramtable);
std::string gen_vardef_array(std::string alias_name, ParseNode * entity_variable, ParseNode * spec_typename, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr);
std::string gen_vardef_array(ParseNode * entity_variable, ParseNode * spec_typename, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr);
std::string gen_qualified_typestr(std::string type_name, VariableDescAttr * vardescattr);
std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape);
std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice);
ParseNode gen_vardef_simple(const ParseNode & type, std::string name);

ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite); // function define

ParseNode gen_select(const ParseNode & exp, const ParseNode & case_stmt);
ParseNode gen_case(const ParseNode & dimen_slice, ParseNode & suite);

ParseNode gen_if(const ParseNode & exp, ParseNode & suite_true, const ParseNode & elseif, ParseNode & suite_else);
ParseNode gen_if_oneline(const ParseNode & exp, const ParseNode & stmt_true);

ParseNode gen_elseif(const ParseNode & exp, ParseNode & suite_true, const ParseNode & elseif);

ParseNode gen_do(ParseNode & suite);
ParseNode gen_do_range(const ParseNode & loop_variable, const ParseNode & exp1, const ParseNode & exp2, const ParseNode & exp3, ParseNode & suite);
ParseNode gen_do_while(const ParseNode & exp, ParseNode & suite);
ParseNode gen_hiddendo(const ParseNode & _generate_stmt, TokenMeta_T return_token = TokenMeta::NT_HIDDENDO);
std::vector<const ParseNode *> gen_nested_hiddendo_layers(const ParseNode & hiddendo);
std::string gen_nested_hiddendo(const std::vector<const ParseNode *> & hiddendo_layer);

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable); // callable, function call or array
ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable, const ParseNode & paramtable); // kwargs(not used)

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step);
ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub); 
ParseNode promote_exp_to_slice(const ParseNode & exp);

ParseNode gen_keyvalue(const ParseNode & variable);
ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial);
ParseNode gen_keyvalue_from_arraybuilder(const ParseNode & variable, const ParseNode & initial);
ParseNode gen_paramtable(ParseNode & paramtable_elem);
ParseNode gen_paramtable(ParseNode & paramtable_elem, ParseNode & paramtable);
ParseNode gen_promote_exp_to_keyvalue(const ParseNode & paramtable_elem);
ParseNode gen_promote_paramtable(const ParseNode paramtable); 

ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind);
ParseNode gen_type(const ParseNode & type_nospec);
ParseNode gen_type(Term typeterm);

ParseNode gen_argtable(ParseNode & dimen_slice);

ParseNode gen_stmt(const ParseNode & content);
ParseNode gen_stmt(const ParseNode & content, const std::string & rules);

ParseNode gen_array_from_hiddendo(ParseNode & hiddendo);
ParseNode gen_array_from_paramtable(const ParseNode & argtable);
ParseNode & gen_arraybuilder_str(ParseNode & arraybuilder);

void set_variabledesc_attr(ParseNode * newnode, boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<struct ParseNode *> slice, boost::optional<int> kind);
ParseNode gen_variabledesc_from_dimenslice(ParseNode & dimen_slice);

ParseNode gen_interface(const ParseNode & wrappers);

void add_function_forward(const ParseNode & function_decl);

ParseNode gen_label(const ParseNode & tag); 
void log_format_index(std::string format_index);
void require_format_index(std::string format_index);

std::string gen_rights(std::string filename, std::string author);
ParseNode gen_header();

ParseNode gen_program(ParseNode & suite);

void do_trans(const std::string & src);