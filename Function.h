#pragma once
#include <string>
#include <vector>
#include <map>

struct FunctionInfo {
	std::vector<struct ParseNode *> param_definition;
};

typedef FunctionInfo * funcptr_t;

FunctionInfo * get_function(std::string module_name, std::string function_name);

bool add_function(std::string module_name, std::string function_name, const FunctionInfo & function);