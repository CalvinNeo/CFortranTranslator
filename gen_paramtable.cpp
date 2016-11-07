#include "gen_common.h"

ParseNode gen_keyvalue(const ParseNode & variable) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "%s", variable.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };

	sprintf(codegen_buf, "%s", variable.fs.CurrentTerm.what.c_str());
	ParseNode variablenode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), &newnode);
	variablenode.addchild(new ParseNode(variable)); // type
	variablenode.addchild(new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") }), &newnode, nullptr)); // void is dummy initial

	newnode.addchild(new ParseNode(variablenode));
	return newnode;
}

ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "%s = %s", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };

	sprintf(codegen_buf, "%s", variable.fs.CurrentTerm.what.c_str());
	ParseNode variablenode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), &newnode);
	variablenode.addchild(new ParseNode(variable)); // type
	variablenode.addchild(new ParseNode(initial)); // void is dummy initial

	newnode.addchild(new ParseNode(variablenode));
	return newnode;
}

ParseNode gen_keyvalue_from_arraybuilder(const ParseNode & variable, const ParseNode & initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */
	/* 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 */
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "%s.init(%s)", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };

	sprintf(codegen_buf, "%s.init(%s)", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	ParseNode variablenode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), &newnode);
	variablenode.addchild(new ParseNode(variable)); // type
	variablenode.addchild(new ParseNode(initial)); // void is dummy initial

	newnode.addchild(new ParseNode(variablenode));
	return newnode;
}

ParseNode gen_paramtable(const ParseNode & keyvalue, const ParseNode & paramtable) {
	ParseNode newnode = ParseNode();
	//newnode->addchild(keyvalue.child[0]); // keyvalue
	//sprintf(codegen_buf, "%s, %s", $1.fs.CurrentTerm.what.c_str(), $3.fs.CurrentTerm.what.c_str());
	//newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
	//ParseNode & pn = $3;
	//for (int i = 0; i < pn.child.size(); i++)
	//{
	//	newnode->addchild(new ParseNode(*pn.child[i])); // paramtable
	//}
	//$$ = *newnode;
	//update_pos($$);

	//ParseNode * nn = new ParseNode();
	//sprintf(codegen_buf, merge_rule.c_str(), item.fs.CurrentTerm.what.c_str(), list.fs.CurrentTerm.what.c_str());
	//if (merged_token_meta == -1) {
	//	merged_token_meta = list.fs.CurrentTerm.token;
	//}
	//nn->fs.CurrentTerm = Term{ merged_token_meta, string(codegen_buf) };
	//nn->addchild(new ParseNode(item)); // item
	//nn->addchild(new ParseNode(list)); // list
	//nn = flattern_bin(nn);
	//ParseNode newnode = ParseNode(*nn);
	//delete nn;
	return newnode;
}