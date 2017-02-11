#include "Variable.h"
#include "tokenizer.h"
#include <boost/algorithm/string/predicate.hpp>

std::map < std::string, VariableInfo* > variables;
std::map < std::string, VariableInfo* > temporary_variables;


VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name) {
	if (module_name == "@" && function_name == "@") {
		if (temporary_variables.find(function_name) != temporary_variables.end()) {
			return temporary_variables[function_name];
		}
		else {
			return nullptr;
		}
	}
	else {
		std::string fullname = module_name + "::" + function_name + "::" + variable_name;
		if (variables.find(fullname) != variables.end()) {
			return variables[fullname];
		}
		else {
			return nullptr;
		}
	}
}

VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable) {
	if (module_name == "@" && function_name == "@") {
		temporary_variables[variable_name] = new VariableInfo(variable);
		return temporary_variables[variable_name];
	}
	else {
		std::string fullname = module_name + "::" + function_name + "::" + variable_name;
		if (variables.find(fullname) != variables.end()) {
			return nullptr;
		}
		else {
			variables[fullname] = new VariableInfo(variable);
			return variables[fullname];
		}
	}
}

void clear_temporary_variables() {
	for (std::map < std::string, VariableInfo* >::iterator iter = temporary_variables.begin(); iter != temporary_variables.end(); iter++) {
		delete iter->second;
	}
	temporary_variables.clear();
}
void clear_variables() {

}

void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(const std::pair<std::string, VariableInfo *> &)> func) {
	for (std::map < std::string, VariableInfo* >::iterator iter = variables.begin(); iter != variables.end(); iter++)
	{
		if (boost::starts_with(iter->first, module_name + "::" + function_name))
		{
			func(*iter);
		}
	}
}