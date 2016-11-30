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