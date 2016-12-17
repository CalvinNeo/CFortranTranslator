#pragma once
#include <string>
#include <vector>

struct Variable
{
	std::string name;
	bool is_array;
};

typedef void * variableptr_t;


variableptr_t get_variable(std::string module_name, std::string function_name);

bool add_variable(std::string module_name, std::string function_name, std::string variable_name, const variableptr_t & fptr);
