#include "gen_common.h"

ParseNode gen_type(const ParseNode & type_nospec, const ParseNode & _type_kind) {
	// attach _type_kind to type_nospec to get type_spec
	ParseNode newnode = ParseNode(type_nospec);
	// now name translated in pre_map
	newnode.attr = _type_kind.attr->clone();
	return newnode;
}

ParseNode gen_type(const ParseNode & type_nospec) {
	// promote type_nospec to default type_spec
	ParseNode newnode = ParseNode(type_nospec);
	// now name translated in pre_map
	ParseNode _type_kind = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
	_type_kind.attr = new VariableDescAttr(&_type_kind);

	newnode.attr = _type_kind.attr->clone();
	return newnode;
}

ParseNode gen_type(Term typeterm) {
	ParseNode newnode = ParseNode(gen_flex(typeterm), nullptr);
	return gen_type(newnode);
}

ParseNode promote_type(const ParseNode & type_spec, VariableDesc & vardesc) {
	// reset type according to kind
	ParseNode promoted_type = ParseNode(type_spec); // type
	/* merge type_spec and variable_desc attr */
	vardesc.merge(dynamic_cast<VariableDescAttr *>(type_spec.attr)->desc);
	if (vardesc.kind.isdirty()) {
		if (type_spec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
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
		else if (type_spec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
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

std::string gen_qualified_typestr(std::string type_name, const VariableDesc & vardesc) {
	string var_pattern;
	if (vardesc.reference) {
		if (vardesc.constant) {
			var_pattern = "const %s & ";
		}
		else {
			var_pattern = "%s & ";
		}
	}
	else {
		if (vardesc.constant) {
			var_pattern = "const %s ";
		}
		else {
			var_pattern = "%s ";
		}
	}
	sprintf(codegen_buf, var_pattern.c_str(), type_name.c_str());
	return string(codegen_buf);
}