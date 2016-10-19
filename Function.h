#pragma once
#include <string>
#include <vector>
#include <map>

typedef void * funcprt_t;

funcprt_t get_function(std::string module_name, std::string function_name);

bool add_function(std::string module_name, std::string function_name, funcprt_t fptr);