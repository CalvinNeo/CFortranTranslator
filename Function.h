#pragma once
#include <string>
#include <vector>
#include <map>


struct FunctionDesc {
	// all variables passed as paramtable(must also be declared in function) and declared in the function
	std::vector<struct ParseNode *> declared_variables;
	// tuple (name, type node, variable_initial node) of all parameters
	std::vector<std::tuple<std::string, ParseNode, struct ParseNode *>> paramtable_info;
	FunctionDesc(const std::vector<struct ParseNode *> &declared_variables
		, const std::vector<std::tuple<std::string, ParseNode, struct ParseNode *>> & paramtable_info)
	: paramtable_info(paramtable_info), declared_variables(declared_variables){

	}
};
struct FunctionInfo {
	FunctionDesc funcdesc;
	FunctionInfo(const FunctionDesc & desc) : funcdesc(desc) {

	}
};

FunctionInfo * get_function(std::string module_name, std::string function_name);
FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & function);
void clear_functions();