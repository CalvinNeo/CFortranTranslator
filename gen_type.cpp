#include "gen_common.h"

ParseNode gen_type(const ParseNode & type, const ParseNode & _type_kind) {
	// now name translated in pre_map
	//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
	ParseNode newnode = ParseNode(type);
	newnode.attr = _type_kind.attr->clone();
	VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode.attr);
	VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(_type_kind.attr);
	new_a->merge(*var_a);
	return newnode;
}

ParseNode gen_type(const ParseNode & type) {
	// now name translated in pre_map
	//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
	ParseNode newnode = ParseNode(type);

	ParseNode _type_kind = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
	_type_kind.attr = new VariableDescAttr(&_type_kind);

	newnode.attr = _type_kind.attr->clone();
	VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode.attr);
	VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(_type_kind.attr);
	new_a->merge(*var_a);
	return newnode;
}