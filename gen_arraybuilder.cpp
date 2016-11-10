#include "gen_common.h"

ParseNode gen_array_generate_stmt(const ParseNode & _generate_stmt) {
	/* give generate stmt */
	ParseNode newnode = ParseNode();
	ParseNode * exp = _generate_stmt.child[0];
	ParseNode * index = _generate_stmt.child[1];
	ParseNode * from = _generate_stmt.child[2];
	ParseNode * to = _generate_stmt.child[3];
	sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s;\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
		, index->fs.CurrentTerm.what.c_str(), to->fs.CurrentTerm.what.c_str() /* exp_to */, index->fs.CurrentTerm.what.c_str() /* index variable inc */
		, "\t%s" /* array variable name */, index->fs.CurrentTerm.what.c_str() /* index variable */, exp->fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
	newnode.addchild(new ParseNode(*exp)); // exp
	newnode.addchild(new ParseNode(*index)); // index variable
	newnode.addchild(new ParseNode(*from)); // exp_from
	newnode.addchild(new ParseNode(*to)); // exp_to
	return newnode;

}
