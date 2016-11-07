#pragma once

#include "parser.h"

std::string for2cpp(std::string for_code);
ParseNode * flattern_bin(ParseNode * pn);

ParseNode gen_token(Term term);

std::string parse_ioformatter(const std::string &); 
ParseNode gen_read(const ParseNode & io_info, const ParseNode & argtable);
ParseNode gen_write(const ParseNode & io_info, const ParseNode & argtable);
ParseNode gen_print(const ParseNode & io_info, const ParseNode & argtable);

ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule);
ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule);
ParseNode gen_exp(const ParseNode & variable);

ParseNode gen_vardef(const ParseNode & type_spec, const ParseNode & dummy_variable_iden, const ParseNode & paramtable);

ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite); // function define

ParseNode gen_select(const ParseNode & exp, const ParseNode & case_stmt);
ParseNode gen_case(const ParseNode & dimen_slice, ParseNode & suite);


ParseNode gen_do(ParseNode & suite);
ParseNode gen_do_range(const ParseNode & loop_variable, const ParseNode & exp1, const ParseNode & exp2, const ParseNode & exp3, ParseNode & suite);
ParseNode gen_do_while(const ParseNode & exp, ParseNode & suite);

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable); // callable, function call or array

ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub, const ParseNode & step);
ParseNode gen_slice(const ParseNode & lb, const ParseNode & ub); 
ParseNode gen_dimenslice_from_slice(ParseNode & slice);
ParseNode gen_argtable_from_exp(ParseNode & exp);
ParseNode gen_dimenslice(ParseNode & slice, const ParseNode & dimen_slice);
ParseNode gen_argtable(ParseNode & exp, const ParseNode & argtable);