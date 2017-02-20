#include "gen_common.h"

ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind) {
	// attach _type_kind to type_nospec nonterminal
	ParseNode newnode = type_nospec;
	// now name translated in pre_map
	newnode.setattr(_type_kind.attr->clone());
	return newnode;
}

ParseNode gen_type(const ParseNode & type_nospec) {
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

ParseNode promote_type(const ParseNode & type_nospec, VariableDesc & vardesc) {
	// reset type according to kind
	ParseNode promoted_type = ParseNode(type_nospec); // type
	/* merge type_spec and variable_desc attr */
	vardesc.merge(dynamic_cast<VariableDescAttr *>(type_nospec.attr)->desc);
	if (vardesc.kind.isdirty()) {
		if (type_nospec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
			if (vardesc.kind == 1) {
				promoted_type.fs.CurrentTerm.what = "int8_t";
			}
			else if (vardesc.kind == 2) {
				promoted_type.fs.CurrentTerm.what = "int16_t";
			}
			else if (vardesc.kind == 4) {
				promoted_type.fs.CurrentTerm.what = "int32_t";
			}
			else if (vardesc.kind == 8) {
				promoted_type.fs.CurrentTerm.what = "int64_t";
			}
		}
		else if (type_nospec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
			if (vardesc.kind < 4) {
				promoted_type.fs.CurrentTerm.what = "float";
			}
			else if (vardesc.kind == 4) {
				promoted_type.fs.CurrentTerm.what = "double";
			}
			else if (vardesc.kind == 8) {
				promoted_type.fs.CurrentTerm.what = "long double";
			}
		}
	}
	return promoted_type;
}

std::string gen_qualified_typestr(const ParseNode & type_nospec, VariableDesc & vardesc) {
	ParseNode type_spec = promote_type(type_nospec, vardesc); // reset type according to kind
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

