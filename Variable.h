#pragma once
#include <string>
#include <vector>
#include "parser.h"

struct VariableInfo
{
	std::string name;
	bool is_array;
	std::string typestr;
	struct ParseNode * pn;
};

typedef VariableInfo * variableptr_t;

variableptr_t get_variable(std::string module_name, std::string function_name, std::string variable_name);

bool add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable);
