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

ParseNode gen_type(ARG_IN type_nospec, ARG_IN _type_kind) {
	// attach _type_kind to type_nospec nonterminal
	ParseNode newnode = type_nospec;
	// now name translated in pre_map
	newnode.setattr(_type_kind.attr->clone());
	return newnode;
}

ParseNode gen_type(ARG_IN type_nospec) {
	// promote type_nospec to default type_spec nonterminal
	ParseNode newnode = type_nospec;
	// now name translated in pre_map
	newnode.setattr(new VariableDescAttr());
	return newnode;
}

ParseNode gen_type(Term typeterm) {
	ParseNode newnode = gen_token(typeterm);
	return gen_type(newnode);
}

ParseNode implicit_type_from_name(std::string name) {
	if (name.size() > 0 && name[0] <= 'n' && name[0] >= 'i')
	{
		return gen_type(Term{ TokenMeta::Int_Def, "int" });
	}
	else {
		return gen_type(Term{ TokenMeta::Float_Def, "double" });
	}
}

void promote_type(ParseNode & type_nospec, VariableDesc & vardesc) {
	// reset type according to kind
	/* merge type_spec and variable_desc attr */
	vardesc.merge(dynamic_cast<VariableDescAttr *>(type_nospec.attr)->desc);
	if (vardesc.kind.isdirty()) {
		if (type_nospec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
			if (vardesc.kind == 1) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int8_Def, "int8_t" };
			}
			else if (vardesc.kind == 2) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int16_Def, "int16_t" };
			}
			else if (vardesc.kind == 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int32_Def, "int32_t" };
			}
			else if (vardesc.kind == 8) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Int64_Def, "int64_t" };
			}
		}
		else if (type_nospec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
			if (vardesc.kind < 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Float_Def, "float" };
			}
			else if (vardesc.kind == 4) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::Double_Def, "double" };
			}
			else if (vardesc.kind == 8) {
				type_nospec.fs.CurrentTerm = Term{ TokenMeta::LongDouble_Def, "long double" };
			}
		}
	}
}

std::string gen_qualified_typestr(ARG_IN type_nospec, VariableDesc & vardesc) {
	ParseNode type_spec = type_nospec;
	promote_type(type_spec, vardesc); // reset type according to kind
	string var_pattern;
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
	}else {
		if (vardesc.reference) {
			if (vardesc.constant) {
				var_pattern = "const %s &";
			}
			else {
				var_pattern = "%s &";
			}
		}
		else {
			if (vardesc.constant) {
				var_pattern = "const %s";
			}
			else {
				var_pattern = "%s";
			}
		}
	}
	string name = type_spec.fs.CurrentTerm.what;
	if (vardesc.slice.is_initialized())
	{
		// if is array
		if (get_context().parse_config.usefarray) {
			sprintf(codegen_buf, "farray<%s>", name.c_str());
			name = string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "for1array<%s>", name.c_str());
			name = string(codegen_buf);
			for (int sliceid = vardesc.slice.value().child.size() - 2; sliceid >= 0; sliceid--)
			{
				sprintf(codegen_buf, "for1array<%s>", name.c_str());
				name = string(codegen_buf);
			}
		}
	}
	sprintf(codegen_buf, var_pattern.c_str(), name.c_str());
	return string(codegen_buf);
}

