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

#include "Function.h"
#include "tokenizer.h"
#include "codegen.h"
#include <boost/algorithm/string/predicate.hpp>

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
	FunctionInfo * finfo = new FunctionInfo(func);
	if (module_name == "@") {
		get_context().temporary_functions[function_name] = finfo;
	}
	else {
		std::string fullname = module_name + "::" + function_name;
		if (get_context().functions.find(fullname) != get_context().functions.end()) {
			fatal_error("function name conflict");
			return nullptr;
		}
		else {
			get_context().functions[fullname] = finfo;
		}
	}
	finfo->local_name = function_name;
	return finfo;
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