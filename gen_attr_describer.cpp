#include "gen_common.h"


void set_variabledesc_attr(ParseNode & vardescattr_node, boost::optional<bool> reference, boost::optional<bool> constant
	, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * x = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr);
	x->desc = VariableDesc(reference, constant, optional, slice, kind, save);
}

VariableDesc & get_variabledesc_attr(ParseNode & vardescattr_node) {
	if (vardescattr_node.attr == nullptr) {
		vardescattr_node.setattr(new VariableDescAttr());
	}
	VariableDescAttr * x = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr);
	return x->desc;
}

ParseNode gen_variabledesc_from_dimenslice(ParseNode & dimen_slice) {
	int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
	ParseNode dimen = ParseNode(dimen_slice);
	for (sliceid = 0; sliceid < dimen.child.size(); sliceid++)
	{
		if (dimen.get(sliceid).fs.CurrentTerm.token == TokenMeta::NT_SLICE) {

		}
		else {
			ParseNode tmp = promote_exp_to_slice(*dimen.child[sliceid]);
			delete dimen.child[sliceid];
			dimen.child[sliceid] = new ParseNode(tmp);
		}
		sprintf(codegen_buf, "(%s, %s)"
			/* from, to */
			, dimen.get(sliceid).get(0).fs.CurrentTerm.what.c_str()
			, dimen.get(sliceid).get(1).fs.CurrentTerm.what.c_str());
		dimen.get(sliceid).fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
	}
	return dimen;
}