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

ParseNode gen_array_from_paramtable(ARG_IN argtable) {
	/*****************
	* give initial value
	* `B(1:2:3)` can be either a single-element argtable or a exp, depending on what `B` is
	* in light of this, reduction conflicts can be raised, 
	* promote argtable/dimen_slice to paramtable, in order to defer anaslysis
	*****************/
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARRAYBUILDER_LIST, argtable.to_string() }, argtable);
	return newnode;
}

bool maybe_return_array(FunctionInfo * finfo, const ParseNode & elem) {
	/*****************
	*	return true: have a possiblity to return array section
	*	return false: won't return array section
	*=================
	* IMPORTANT:
	* a function is not an array section, 
	*	BUT it maybe return array section
	* if you want to distinguish between function and array semanticly,
	*	use `is_fortran_function`
	*****************/
	if (elem.get_token() == TokenMeta::NT_HIDDENDO) {
		return true;
	}
	else if (elem.get_token() == TokenMeta::UnknownVariant) {
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, elem.to_string());
		if (vinfo != nullptr)
		{
			if (vinfo->is_array()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			fatal_error("Variable not defined");
			return true;
		}
	}
	else if (elem.get_token() == TokenMeta::NT_FUCNTIONARRAY){
		// 1. function may return either array or non-array
		// 2. a NT_FUCNTIONARRAY can be either a array slice(which returns either an array or a scalar) or a function
		// hard to determine, though it's possible to do that, however, this project is not a compiler
		// so return true
		string varname = elem.get(0).get_what();
		VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, varname);
		FunctionInfo * f = get_function(get_context().current_module, varname);
		// TODO search function context
		if (f != nullptr)
		{
			// function
			std::string & result_name = f->funcdesc.paramtable_info.back();
			VariableInfo * result_vinfo = get_variable(get_context().current_module, finfo->local_name, result_name);
			ParseNode & result_type = result_vinfo->type;
			if (result_type.token_equals(TokenMeta::Void_Decl, TokenMeta::Void))
			{
				// subroutine
				return false;
			}
			else {
				if (result_vinfo->is_array())
				{
					return true;
				}
				else {
					return false;
				}
			}
		}
		else if (vinfo == nullptr)
		{
			// implicit
			return true;
		}
		else {
			return true;
		}
	}
	else if (elem.get_token() == TokenMeta::NT_ARGTABLE_PURE){
		// hard to determine, so return true
		return true;
	}
	else if (is_literal(elem))
	{
		// including literals
		return false;
	} 
	else{
		print_error("Strange element", elem);
		return true;
	}
}

void regen_arraybuilder(FunctionInfo * finfo, ParseNode & array_builder) {
	// wrap arraybuilder.fs.CurrentTerm.what with make_farray function
	string arr_decl;
	if (array_builder.get_token() == TokenMeta::NT_ARRAYBUILDER_LIST)
	{
		// if array is assigned by an `(/` `/)` constructor
		bool concat_array = false;
		ParseNode & argtable = array_builder.get(0);
		// if any of NT_ARRAYBUILDER_LIST's child is an array, then concat_array = true
		concat_array = std::accumulate(argtable.begin(), argtable.end(), false, [&](bool x, ParseNode * p) {
			return x || maybe_return_array(finfo, *p);
		});
		if (!concat_array)
		{
			// all elements in the array builder is scalar
			// can init array from initializer_list of initial value
			sprintf(codegen_buf, "make_init_list(%s)", argtable.get_what().c_str());
			arr_decl = string(codegen_buf);
		}
		else {
			// must init array from another farray/for1array
			string subarrays = make_str_list(argtable.begin(), argtable.end(), [&](ParseNode * p) {
				ParseNode & elem = *p;
				if (elem.get_token() == TokenMeta::NT_HIDDENDO) {

					vector<ParseNode *> hiddendo_layer = get_nested_hiddendo_layers(elem);
					SliceBoundInfo lb_size = get_lbound_size_from_hiddendo(finfo, elem, hiddendo_layer);
					std::string lb_size_str = gen_sliceinfo_str(get<0>(lb_size).begin(), get<0>(lb_size).end(), get<1>(lb_size).begin(), get<1>(lb_size).end());
					regen_exp(finfo, elem);
					std::string lambda = elem.get_what();
					sprintf(codegen_buf, "make_init_list(%s, %s)", lb_size_str.c_str(), lambda.c_str());
				}
				else if (elem.token_equals(TokenMeta::UnknownVariant, TokenMeta::NT_FUCNTIONARRAY)) {
					regen_exp(finfo, elem);
					VariableInfo * vinfo = get_variable(get_context().current_module, finfo->local_name, elem.get_what());
					if (maybe_return_array(finfo, elem))
					{
						sprintf(codegen_buf, "make_init_list(%s)", elem.get_what().c_str());
					}
					else {
						// because forconcat only concat between arrays, so use `make_init_list` to promote a scalar to array
						// IMPORTANT, TODO an specification `farray<T> make_init_list(const farray<T> & narr)` make sure no action should be performed to an array
						sprintf(codegen_buf, "make_init_list(%s)", elem.get_what().c_str());
					}
				}
				else if (elem.get_token() == TokenMeta::NT_ARGTABLE_PURE)
				{
					// a list of elements
					regen_paramtable(finfo, elem);
					sprintf(codegen_buf, "make_init_list(%s)", elem.get_what().c_str());
				}
				else {
					// literal
					sprintf(codegen_buf, "make_init_list(%s)", elem.get_what().c_str());
				}
				return string(codegen_buf);
			});
			arr_decl = "forconcat({" + subarrays + "})";
		}
	}
	else
	{
		// if array is assigned by a scalar
		// e.g. A = B(:)
		regen_exp(finfo, array_builder);
		arr_decl = array_builder.get_what();
	}

	array_builder.get_what() = arr_decl;
	return;
}