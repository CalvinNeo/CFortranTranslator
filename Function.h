#pragma once
#include <string>
#include <vector>
#include <map>

typedef void * funcptr_t;

bool try_get_function(std::string module_name, std::string function_name, funcptr_t & fptr );
bool try_get_function(std::string module_name, std::string function_name);

funcptr_t get_function(std::string module_name, std::string function_name);

bool add_function(std::string module_name, std::string function_name, funcptr_t fptr);