#include "Function.h"
#include "tokenizer.h"
#include "parser.h"

std::map < std::string, funcprt_t > functions;

funcprt_t get_function(std::string module_name, std::string function_name) {
	
}

bool add_function(std::string module_name, std::string function_name, funcprt_t fptr) {
	if (functions.find(module_name + "::" + function_name) != functions.end()) {
		return false;
	}
	else {

	}
}