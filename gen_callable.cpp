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

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable) {

	/* function call OR array index */
	/* NOTE that array index can be A(1:2, 3:4) */
	ParseNode newnode = ParseNode();
	string name;
	string func_header;
	newnode.addlist(callable_head, argtable);
	if (funcname_map.find(callable_head.fs.CurrentTerm.what) != funcname_map.end()) {
		// some fortran intrinsic function NAME must be replaced with its c++ implementation function NAME in for90std.h
		name = funcname_map.at(callable_head.fs.CurrentTerm.what);
	}
	else {
		name = callable_head.fs.CurrentTerm.what;
	}
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
		// array
		string arr;
		bool is_slice = false;
		for (auto i = 0; i < argtable.child.size(); i++)
		{
			if (argtable.get(i).fs.CurrentTerm.token == TokenMeta::NT_SLICE) {
				is_slice = true;
				break;
			}
		}
		if (is_slice) {
			string slice_info_str;
			for (auto i = 0; i < argtable.child.size(); i++)
			{
				if (i != 0) {
					slice_info_str += ",";
				}
				slice_info_str += "{";
				if (argtable.get(i).fs.CurrentTerm.token == TokenMeta::NT_SLICE) {
					ARG_IN slice = argtable.get(i);
					bool empty_slice = false;
					int slice_info_arr[] = {1, 1, 1};
					for (auto j = 0; j < slice.child.size(); j++)
					{
						if (slice.get(j).fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIALDUMMY) {
							// a(:)
							empty_slice = true;
							sprintf(codegen_buf, "");
						}
						else {
							sscanf(slice.get(j).fs.CurrentTerm.what.c_str(), "%d", slice_info_arr + j);
						}
					}
					if (empty_slice || slice.child.size() == 0) {

					}
					else if (slice.child.size() == 1) {
						// a single element, not size
						sprintf(codegen_buf, "%d", slice_info_arr[0]);
					}
					else if (slice.child.size() == 2) {
						// forslice accepts lowerbound, size
						sprintf(codegen_buf, "%d, %d", slice_info_arr[0], slice_info_arr[1]  ); 
					}
					else {
						sprintf(codegen_buf, "%d, %d, %d", slice_info_arr[0], slice_info_arr[1], slice_info_arr[2]);
					}

					slice_info_str += string(codegen_buf);
				}
				else {
					// slice like a(1:2, 3, 4)
					slice_info_str += argtable.get(i).fs.CurrentTerm.what;
				}
				slice_info_str += "}";
			}
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
	else if(argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE 
		|| argtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_PURE){
		// function call or function call with kwargs
		func_header += name;
		auto map_func = get_context().func_kwargs.find(name); // function_name -> args
		func_header += "(";
		bool kwargs = false;
		int normal_count = 0; // non kwarg count
		map<string, string> kws;
		for (int i = 0; i < argtable.child.size(); i++)
		{
			if (argtable.get(i).fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE) {
				// keyword/named argument
				//kwargs = true;
				if (map_func == get_context().func_kwargs.end()) {
					print_error("invalid kwarg of function " + name, argtable);
				}
				else {
					string argname = argtable.get(i).get(0).fs.CurrentTerm.what;
					string argvalue = argtable.get(i).get(1).fs.CurrentTerm.what;
					kws[argname] = argvalue;
				}
			}
			else {
				// normal argument
				vector<ParseNode *> args;
				if (argtable.get(i).fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER) {
					for (auto j = 0; j < argtable.get(i).child.size(); j++)
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
						if (args[j]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_LAMBDA) {
							func_header += "{" + args[j]->get(0).fs.CurrentTerm.what + "}";
						}
						else {
							func_header += args[j]->fs.CurrentTerm.what;
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
				string this_param_name = std::get<0> (params[i]);
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
	return newnode;
}

