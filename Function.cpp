#include "Function.h"
#include "tokenizer.h"
#include "codegen.h"
#include "parser.h"

//std::map < std::string, FunctionInfo* > functions;


FunctionInfo * get_function(std::string module_name, std::string function_name) {
	std::string fullname = module_name + "::" + function_name;
	if (get_context().functions.find(fullname) != get_context().functions.end()) {
		return get_context().functions[fullname];
	}
	else {
		return nullptr;
	}
}

FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & finfo) {
	std::string fullname = module_name + "::" + function_name;
	if (get_context().functions.find(fullname) != get_context().functions.end()) {
		return nullptr;
	}
	else {
		get_context().functions[fullname] = new FunctionInfo(finfo);
		return get_context().functions[fullname];
	}
}

void clear_functions() {

}