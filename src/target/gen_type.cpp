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

ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind) {
	// attach _type_kind to type_nospec nonterminal
	ParseNode newnode = type_nospec;
	// now base_typename translated in pre_map
	newnode.setattr(_type_kind.attr->clone());
	return newnode;
}

ParseNode gen_type(const ParseNode & type_nospec) {
	// promote type_nospec to default type_spec nonterminal
	ParseNode newnode = type_nospec;
	// now base_typename translated in pre_map
	newnode.setattr(new VariableDescAttr());
	return newnode;
}

ParseNode gen_type(Term typeterm) {
	return gen_type(gen_token(typeterm));
}

ParseNode gen_implicit_type(FunctionInfo * finfo, std::string name) {
	if (name.size() > 0)
	{	
		TokenMeta_T tok = finfo->implicit_type_config[name[0]];
		string tname;
		//std::cout << IntentMeta::get_enum_table().input_str << std::endl;
		if (tok == TokenMeta::Int_Decl) tname = "int";
		if (tok == TokenMeta::Char_Decl) tname = "char";
		if (tok == TokenMeta::Int8_Decl) tname = "int8_t";
		if (tok == TokenMeta::Int16_Decl) tname = "int16_t";
		if (tok == TokenMeta::Int32_Decl) tname = "int32_t";
		if (tok == TokenMeta::Int64_Decl) tname = "int64_t";
		if (tok == TokenMeta::Double_Decl) tname = "double";
		if (tok == TokenMeta::LongDouble_Decl) tname = "long double";
		if (tok == TokenMeta::Float_Decl) tname = "float";
		return gen_type(Term{ tok, tname });
	}
	else {
		return gen_type(Term{ TokenMeta::Float_Decl, "double" });
	}
}

void promote_type(ParseNode & type_nospec, VariableDesc & vardesc) {
	// reset type according to kind
	// merge type_spec and variable_desc attr
	vardesc.merge(dynamic_cast<VariableDescAttr *>(type_nospec.attr)->desc);
	if (vardesc.kind.isdirty()) {
		if (type_nospec.token_equals(TokenMeta::Int)) {
			if (vardesc.kind == 1) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int8, "int8_t" };
			}
			else if (vardesc.kind == 2) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int16, "int16_t" };
			}
			else if (vardesc.kind == 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int32, "int32_t" };
			}
			else if (vardesc.kind == 8) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int64, "int64_t" };
			}
		}
		else if (type_nospec.token_equals(TokenMeta::Float)) {
			if (vardesc.kind < 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Float, "float" };
			}
			else if (vardesc.kind == 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Double, "double" };
			}
			else if (vardesc.kind == 8) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::LongDouble, "long double" };
			}
		}
	}
}

std::string gen_qualified_typestr(const ParseNode & type_spec, VariableDesc & vardesc, bool in_paramtable) {
	string var_pattern;
	if (type_spec.token_equals(TokenMeta::Function))
	{
		var_pattern = "%s";
	}
	else
	{
		if (vardesc.optional)
		{
			var_pattern = "foroptional<%s>";
		}
		else if (vardesc.save) {
			if (vardesc.constant)
			{
				var_pattern = "static const %s";
			}
			else {
				var_pattern = "static %s";
			}
		}
		else {
			if(vardesc.inout_reference){
				var_pattern = "%s &&";
			}
			else if (vardesc.reference) {
				if (vardesc.constant) {
					var_pattern = "const %s &";
				}
				else {
					var_pattern = "%s &";
				}
			}
			else if (vardesc.pointer) {
				if (vardesc.constant) {
					var_pattern = "const %s *";
				}
				else {
					var_pattern = "%s *";
				}
			}
			else {
				if (vardesc.constant) {
					var_pattern = "const %s";
				}
				else {
					if (in_paramtable)
					{
						var_pattern = "%s &&";
					}
					else {
						var_pattern = "%s";
					}
				}
			}
		}
	}
	string base_typename = type_spec.get_what();
	if (vardesc.slice.is_initialized())
	{
		// if slice attr is presented, this variable is an array of type_spec 
		if (get_context().parse_config.usefarray) {
			sprintf(codegen_buf, "farray<%s>", base_typename.c_str());
			base_typename = string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "for1array<%s>", base_typename.c_str());
			base_typename = string(codegen_buf);
			for (int sliceid = vardesc.slice.get().length() - 2; sliceid >= 0; sliceid--)
			{
				sprintf(codegen_buf, "for1array<%s>", base_typename.c_str());
				base_typename = string(codegen_buf);
			}
		}
	}
	sprintf(codegen_buf, var_pattern.c_str(), base_typename.c_str());
	return string(codegen_buf);
}


void regen_type(ParseNode & type_decl, FunctionInfo * finfo, VariableInfo * vinfo) {
	/*****************
	* this function deduce type of a variable, by type decl, it will generate X_Decl -> X, where
	* type decl: X_Decl
	* type name: X
	*****************/
	if (type_decl.token_equals(TokenMeta::Implicit_Decl))
	{
		/*****************
		* type is implicit
		* if an variable is implicit defined, its type will be induced from its first letter
		* if an variable's type is deduced, it can be explicitly declared, e.g. `dimension a(10)`
		*=================
		* though `check_implicit_variable` will deduce all implicit variable's type and all Implicit_Decl type,
		*	it can't handle vardef nodes
		*****************/
		ParseNode deduced_type = gen_implicit_type(finfo, get_variable_name(vinfo->entity_variable));
		type_decl.fs.CurrentTerm = deduced_type.fs.CurrentTerm;
		type_decl.setattr(new VariableDescAttr());
	}
	else if (type_decl.token_equals(TokenMeta::Function_Decl))
	{
		// generate `std::function`
		type_decl.get_what() = gen_function_signature(finfo, 1);
		type_decl.get_token() = TokenMeta::Function;
	}
	else {
		// from type decl to type
		type_decl.get_token() = type_decl.get_token() + 100;
	}
	promote_type(type_decl, vinfo->desc);
}
