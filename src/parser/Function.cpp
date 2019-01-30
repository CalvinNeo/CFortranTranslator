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
#include "../parser/context.h"
#include <boost/algorithm/string/predicate.hpp>

FunctionInfo * get_function(std::string module_name, std::string function_name) {

	std::string fullname = module_name + "::" + function_name;
	if (get_context().functions.find(fullname) != get_context().functions.end()) {
		return get_context().functions[fullname];
	}
	else {
		return nullptr;
	}
}

FunctionInfo * add_function(std::string module_name, std::string function_name, const FunctionInfo & func) {
	FunctionInfo * finfo = new FunctionInfo(func);

	std::string fullname = module_name + "::" + function_name;
	if (get_context().functions.find(fullname) != get_context().functions.end()) {
		fatal_error("function name conflict");
		return nullptr;
	}
	else {
		get_context().functions[fullname] = finfo;
	}
	finfo->local_name = function_name;
	return finfo;
}


void forall_function_in_module(std::string module_name, std::function<void(std::pair<std::string, FunctionInfo *>)> func) {
	for(std::map <std::string, FunctionInfo *>::value_type & pr : get_context().functions)
	{
		if (boost::starts_with(pr.first, module_name + "::"))
		{
			func(pr);
		}
	}
}

void clear_functions() {
	for(std::map <std::string, FunctionInfo *>::value_type & pr : get_context().functions)
	{
		delete pr.second;
	}
	get_context().functions.clear();
}