/*
*/

#pragma once
#include "parser.h"
#include "Variable.h"
#include "Function.h"

struct TypeDesc {
	/******************
	* record all variables declared in the function
	* because variables passed in parameter list are also declared in function body, so they are included in `declared_variables`
	*******************/
	std::vector<struct VariableInfo *> declared_variables;
	/******************
	* fortran's parameter list provides every parameter(called dummy arguments)'s name without their type
	*	which are given in the function body as a normal variable decl statement
	* `paramtable_info` log all names which appear in the parameter list
	* you can `get_variable` to query every parameter's infomation
	* ALSO REFER `NT_DECLAREDVARIABLE` in FUnction.h and `VariableInfo::declared` in Variable.h
	*******************/
	std::vector<std::string> paramtable_info;
	std::vector<struct ParseNode *> declared_commons;

	TypeDesc() {
	}
};
struct TypeInfo : FunctionInfo {
};

TypeInfo* get_type(std::string module_name, std::string type_name);
TypeInfo* add_type(std::string module_name, std::string type_name, const TypeInfo & func);
void forall_type_in_module(std::string module_name, std::function<void(std::pair<std::string, TypeInfo *>)> func);
void clear_types();