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
	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return variablenode;
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
	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return variablenode;
}

ParseNode gen_keyvalue_from_arraybuilder(const ParseNode & variable, const ParseNode & initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */
	/* ��Ϊʹ��forarray��Ϊ����, ����Ҫ֪��������Ϣ, ���ڴ˴���ֵ, ���ϲ��var_def����ֵ */
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "%s.init(%s)", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };

	sprintf(codegen_buf, "%s.init(%s)", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	ParseNode variablenode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), &newnode);
	variablenode.addchild(new ParseNode(variable)); // type
	variablenode.addchild(new ParseNode(initial)); // void is dummy initial

	newnode.addchild(new ParseNode(variablenode));
	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return variablenode;
}

ParseNode gen_paramtable(const ParseNode & keyvalue) {
	ParseNode newnode = ParseNode();
	newnode.addchild(new ParseNode(keyvalue)); // keyvalue
	sprintf(codegen_buf, "%s", keyvalue.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
	return newnode;
}