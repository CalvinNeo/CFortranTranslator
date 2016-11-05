#pragma once

#include "parser.h"

std::string for2cpp(std::string for_code);

std::string parse_ioformatter(const std::string &); 
ParseNode * gen_read(const ParseNode & io_info, const ParseNode & argtable);
ParseNode * gen_write(const ParseNode & io_info, const ParseNode & argtable);
ParseNode * gen_print(const ParseNode & io_info, const ParseNode & argtable);

ParseNode * gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule);
ParseNode * gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule);

ParseNode * gen_vardef(const ParseNode & type_spec, const ParseNode & dummy_variable_iden, const ParseNode & paramtable);

ParseNode * gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite);

ParseNode * gen_select(const ParseNode & exp, const ParseNode & case_stmt);