#include "Function.h"
#include "tokenizer.h"
#include "codegen.h"
#include <boost/algorithm/string/predicate.hpp>

//std::map < std::string, FunctionInfo* > functions;


FunctionInfo * get_function(std::string module_name, std::string function_name) {
	if (module_name == "@" ) {
		if (get_context().temporary_functions.find(function_name) != get_context().temporary_functions.end()) {
			return get_context().temporary_functions[function_name];
		}
		else {
			return nullptr;
		}
	}
	else {
		std::string fullname = module_name + "::" + function_name;
		if (get_context().functions.find(fullname) != get_context().functions.end()) {
			return get_context().functions[fullname];
		}
		else {
			return nullptr;
		}
	}
}

FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & func) {
	if (module_name == "@") {
		get_context().temporary_functions[function_name] = new FunctionInfo(func);
		return get_context().temporary_functions[function_name];
	}
	else {
		std::string fullname = module_name + "::" + function_name;
		if (get_context().functions.find(fullname) != get_context().functions.end()) {
			return nullptr;
		}
		else {
			get_context().functions[fullname] = new FunctionInfo(func);
			return get_context().functions[fullname];
		}
	}
}

void insert_temporary_functions(std::string module_name) {
	for (std::map < std::string, FunctionInfo * >::iterator iter = get_context().temporary_functions.begin(); iter != get_context().temporary_functions.end(); iter++) {
		std::string fullname = module_name + "::" + iter->first;
		get_context().functions[fullname] = iter->second; // do not copy
	}
	get_context().temporary_functions.clear();
}

void forall_function_in_module(std::string module_name, std::function<void(const std::pair<std::string, FunctionInfo *> &)> func) {

	if (module_name == "@") {
		for (std::map < std::string, FunctionInfo* >::iterator iter = get_context().temporary_functions.begin(); iter != get_context().temporary_functions.end(); iter++)
		{
			func(*iter);
		}
	}
	else {
		for (std::map < std::string, FunctionInfo* >::iterator iter = get_context().functions.begin(); iter != get_context().functions.end(); iter++)
		{
			if (boost::starts_with(iter->first, module_name))
			{
				func(*iter);
			}
		}
	}
}

void clear_functions() {

}