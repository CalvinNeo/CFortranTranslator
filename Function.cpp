#include "Function.h"
#include "tokenizer.h"
#include "parser.h"

std::map < std::string, funcptr_t > functions;

bool try_get_function(std::string module_name, std::string function_name) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool try_get_function(std::string module_name, std::string function_name, funcptr_t & fptr) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		fptr = &functions[fullname];
		return true;
	}
	else {
		return false;
	}
}

funcptr_t get_function(std::string module_name, std::string function_name) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		return functions[fullname];
	}
	else {
		throw 0;
	}
}

bool add_function(std::string module_name, std::string function_name, funcptr_t fptr) {
	std::string fullname = module_name + "::" + function_name;
	if (functions.find(fullname) != functions.end()) {
		return false;
	}
	else {
		functions[fullname] = fptr;
		return true;
	}
}