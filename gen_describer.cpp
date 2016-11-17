#include "gen_common.h"

void set_variabledesc_attr(ParseNode * newnode, optionalparam<bool> reference, optionalparam<bool> constant, optionalparam<bool> optional, optionalparam<struct ParseNode *> slice, optionalparam<int> kind ) {
	if (newnode->attr == nullptr) {
		newnode->attr = new VariableDescAttr(newnode);
	}
	if(reference.inited())
		dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = reference;
	if (constant.inited())
		dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = constant;
	if (optional.inited())
		dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.optional = optional;
	if (slice.inited())
		dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = slice;
	if (kind.inited())
		dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.kind = kind;
}

ParseNode gen_variabledesc_from_dimenslice(const ParseNode & dimen_slice) {
	int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
	ParseNode dimen = ParseNode(dimen_slice);
	for (sliceid = 0; sliceid < dimen.child.size(); sliceid++)
	{
		sprintf(codegen_buf, "(%s, %s)"
			/* from, to */
			, dimen.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
			, dimen.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
		dimen.child[sliceid]->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
	}
	return dimen;
}