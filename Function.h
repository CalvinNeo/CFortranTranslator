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
	std::map < std::string, FunctionInfo * > function_variables;
	FunctionInfo(const FunctionDesc & desc) : funcdesc(desc){

	}
};
typedef std::tuple<std::string, std::string, std::string> KeywordParamInfo;

FunctionInfo * get_function(std::string module_name, std::string function_name);
FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & func);
void forall_function_in_module(std::string module_name, std::function<void(const std::pair<std::string, FunctionInfo *> &)> func);
void insert_temporary_functions(std::string module_name);
void clear_functions();