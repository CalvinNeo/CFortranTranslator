#include "Variable.h"
#include "tokenizer.h"


std::map < std::string, Variable > variables;


Variable * get_variable(std::string module_name, std::string function_name, std::string variable_name ) {
	std::string fullname = module_name + "::" + function_name + "::" + variable_name;
	if (variables.find(fullname) != variables.end()) {
		return &variables[fullname];
	}
	else {
		return nullptr;
	}
}

bool add_variable(std::string module_name, std::string function_name, std::string variable_name, const Variable & variable) {
	std::string fullname = module_name + "::" + function_name + "::" + variable.name;
	if (variables.find(fullname) != variables.end()) {
		return false;
	}
	else {
		variables[fullname] = variable;
		return true;
	}
}