#include "Variable.h"
#include "tokenizer.h"
#include "codegen.h"
#include <boost/algorithm/string/predicate.hpp>

//std::map < std::string, VariableInfo* > variables;
//std::map < std::string, VariableInfo* > temporary_variables;


VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name) {
	if (module_name == "@" && function_name == "@") {
		if (get_context().temporary_variables.find(variable_name) != get_context().temporary_variables.end()) {
			return get_context().temporary_variables[variable_name];
		}
		else {
			return nullptr;
		}
	}
	else {
		std::string fullname = module_name + "::" + function_name + "::" + variable_name;
		if (get_context().variables.find(fullname) != get_context().variables.end()) {
			return get_context().variables[fullname];
		}
		else {
			return nullptr;
		}
	}
}

VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable) {
	if (module_name == "@" && function_name == "@") {
		get_context().temporary_variables[variable_name] = new VariableInfo(variable);
		return get_context().temporary_variables[variable_name];
	}
	else {
		std::string fullname = module_name + "::" + function_name + "::" + variable_name;
		if (get_context().variables.find(fullname) != get_context().variables.end()) {
			return nullptr;
		}
		else {
			get_context().variables[fullname] = new VariableInfo(variable);
			return get_context().variables[fullname];
		}
	}
}

void insert_temporary_variables(std::string module_name, std::string function_name) {

	for (std::map < std::string, VariableInfo* >::iterator iter = get_context().temporary_variables.begin(); iter != get_context().temporary_variables.end(); iter++) {
		std::string fullname = module_name + "::" + function_name + "::" + iter->first;
		get_context().variables[fullname] = iter->second; // do not copy
	}
	get_context().temporary_variables.clear();
}
void clear_variables() {

}

void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(const std::pair<std::string, VariableInfo *> &)> func) {

	if (module_name == "@" && function_name == "@") {
		for (std::map < std::string, VariableInfo* >::iterator iter = get_context().temporary_variables.begin(); iter != get_context().temporary_variables.end(); iter++)
		{
			func(*iter);
		}
	}
	else {
		for (std::map < std::string, VariableInfo* >::iterator iter = get_context().variables.begin(); iter != get_context().variables.end(); iter++)
		{
			if (boost::starts_with(iter->first, module_name + "::" + function_name))
			{
				func(*iter);
			}
		}
	}
}