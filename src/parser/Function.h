/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once
#include "parser.h"
#include "Variable.h"

struct FunctionDesc {	
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

	FunctionDesc() {
	}
};
struct FunctionInfo {
	std::string local_name; // name can only set by add_function
	std::string result_name;
	FunctionDesc funcdesc;
	ParseNode * suite;
	ParseNode * node;
	TokenMeta_T implicit_type_config[256];
	FunctionInfo() {
		std::fill_n(implicit_type_config, 256, TokenMeta::Double_Decl);
		for (char i = 'i'; i <= 'n'; i++)
		{
			implicit_type_config[i] = TokenMeta::Int_Decl;
		}
	}
	bool is_subroutine() const {
		return result_name == "";
	}
};
/******************
* KeywordParamInfo:
*	std::string name
*	std::string type
*	std::string default
*******************/
struct KeywordParamInfo : public std::tuple<std::string, std::string, std::string> {
public:
	KeywordParamInfo(const char * x, const char * y, const char * z) 
		: std::tuple<std::string, std::string, std::string>(std::string{x}, std::string{y}, std::string{z}) {

	}
};

FunctionInfo * get_function(std::string module_name, std::string function_name);
FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & func);
void forall_function_in_module(std::string module_name, std::function<void(std::pair<std::string, FunctionInfo *>)> func);
void clear_functions();