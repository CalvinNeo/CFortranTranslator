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

#include "gen_common.h"

// both function and array is callable

void regen_function_array(FunctionInfo * finfo, ARG_OUT newnode) {

	/* function call OR array index */
	/* NOTE that array index can be A(1:2, 3:4) */
	ParseNode & callable_head = newnode.get(0);
	ParseNode & argtable = newnode.get(1);
	string name;
	string func_header;
	if (funcname_map.find(callable_head.to_string()) != funcname_map.end()) {
		/***********
		* some fortran intrinsic function NAME is different from
		*	its C++ implementation function NAME in for90std.h, 
		*	in order to avoid possible name conflicts
		***********/
		name = funcname_map.at(callable_head.to_string());
	}
	else {
		name = callable_head.to_string();
	}
	if (argtable.get_token() == TokenMeta::NT_DIMENSLICE) {
		// array
		string arr;
		bool is_slice = false;
		for (auto i = 0; i < argtable.length(); i++)
		{
			if (argtable.get(i).get_token() == TokenMeta::NT_SLICE) {
				is_slice = true;
				break;
			}
		}
		if (is_slice) {
			string slice_info_str;
			slice_info_str = make_str_list(argtable.begin(), argtable.end(), [&](ParseNode * pslice) {
				ParseNode & slice = *pslice;
				string res = "{";
				regen_slice(finfo, slice);
				res += slice.get_what();
				res += "}";
				return res;
			});
			sprintf(codegen_buf, "forslice(%s, {%s})", name.c_str(), slice_info_str.c_str());
			arr = string(codegen_buf);
		}
		else {
			// dead code
			// a dimen_slice with no slice, now all promote to slice
			print_error("bad slice", argtable);
		}
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  arr };
	}
	else if(argtable.get_token() == TokenMeta::NT_ARGTABLE_PURE 
		|| argtable.get_token() == TokenMeta::NT_PARAMTABLE_PURE){
		// function call or function call with kwargs
		func_header += name;
		auto map_func = get_context().func_kwargs.find(name); // function_name -> args
		func_header += "(";
		bool kwargs = false;
		int normal_count = 0; // non kwarg count
		map<string, string> kws;
		for (int i = 0; i < argtable.length(); i++)
		{
			if (argtable.get(i).get_token() == TokenMeta::NT_KEYVALUE) {
				// keyword/named argument
				//kwargs = true;
				if (map_func == get_context().func_kwargs.end()) {
					print_error("invalid kwarg of function " + name, argtable);
				}
				else {
					string argname = argtable.get(i).get(0).to_string();
					string argvalue = argtable.get(i).get(1).to_string();
					kws[argname] = argvalue;
				}
			}
			else {
				// normal argument
				vector<ParseNode *> args;
				if (argtable.get(i).get_token() == TokenMeta::NT_ARRAYBUILDER) {
					for (auto j = 0; j < argtable.get(i).length(); j++)
					{
						args.push_back(argtable.get(i).child[j]);
					}
				}
				else {
					args.push_back(argtable.child[i]);
				}

				// generated code from vector<ParseNode *> args
				if (kwargs) {
					print_error("keyword arguments must come after normal arguments", argtable);
				}
				else {
					for (auto j = 0; j < args.size(); j++)
					{
						if (i != 0 || j != 0) {
							func_header += ", ";
						}
						if (args[j]->get_token() == TokenMeta::NT_ARRAYBUILDER_LAMBDA) {
							func_header += "{" + args[j]->get(0).get_what() + "}";
						}
						else {
							func_header += args[j]->get_what();
						}
						normal_count++;
					}
				}
			}
		}
		// generated code of kwargs
		if (map_func != get_context().func_kwargs.end()) {
			std::vector<KeywordParamInfo> & params = map_func->second;
			for (int i = normal_count; i < params.size(); i++)
			{
				string this_param_name = std::get<0>(params[i]);
				string this_param_type = std::get<1>(params[i]);
				string this_param_intial_default = std::get<2>(params[i]);
				auto this_arg = kws.find(this_param_name);
				if (normal_count != 0) {
					func_header += ", ";
				}
				if (this_arg == kws.end()) {
					// if this argument is not given
					if (this_param_intial_default == "") {
						func_header += "None";
					}
					else {
						// use initial defined in gen_config.h
						func_header += this_param_intial_default;
					}
				}
				else {
					// if this argument is given
					if (this_param_type == "mask_wrapper_t") {
						func_header += this_arg->second;
					}
					else {
						func_header += this_arg->second;
					}
				}
				normal_count++;
			}
		}
		func_header += ")";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY, func_header };
	}
	else {
		print_error("callable generate fail", newnode);
	}
	return;
}

