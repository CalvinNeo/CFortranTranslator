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

#include "Variable.h"
#include "tokenizer.h"
#include "../parser/context.h"
#include <boost/algorithm/string/predicate.hpp>

VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name) {
	std::string fullname = module_name + "::" + function_name + "::" + variable_name;
	if (get_context().variables.find(fullname) != get_context().variables.end()) {
		return get_context().variables[fullname];
	}
	else {
		return nullptr;
	}
}

VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable) {
	std::string fullname = module_name + "::" + function_name + "::" + variable_name;
	if (get_context().variables.find(fullname) != get_context().variables.end()) {
		fatal_error("Variable " + fullname + " already exists");
		return nullptr;
	}
	else {
		VariableInfo * ninfo = new VariableInfo(variable);
		ninfo->local_name = variable_name;
		get_context().variables[fullname] = ninfo;
		return get_context().variables[fullname];
	}
}


void delete_variable(std::string module_name, std::string function_name, std::string variable_name) {
	VariableInfo * vinfo = get_variable(module_name, function_name, variable_name);
	delete vinfo;
	std::string fullname = module_name + "::" + function_name + "::" + variable_name;
	get_context().variables.erase(fullname);
}

void clear_variables() {

}

void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(std::pair<std::string, VariableInfo *> )> func) {
	if (function_name == "@") {
		fatal_error("@ function name is removed: " + function_name);
	}
	else {
		for (std::map < std::string, VariableInfo* >::iterator iter = get_context().variables.begin(); iter != get_context().variables.end(); iter++)
		{
			// the last `::` is ery important
			// consider
			// variable in the same function `suf` and `suffix`
			if (boost::starts_with(iter->first, module_name + "::" + function_name + "::"))
			{
				func(*iter);
			}
		}
	}
}