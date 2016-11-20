#include "gen_common.h"

ParseNode gen_keyvalue(const ParseNode & variable) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */

	sprintf(codegen_buf, "%s", variable.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(variable)); // type
	newnode.addchild(new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") }), &newnode, nullptr)); // void is dummy initial

	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return newnode;
}

ParseNode gen_keyvalue_from_exp(const ParseNode & variable, const ParseNode & initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */

	sprintf(codegen_buf, "%s", variable.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(variable)); // type
	newnode.addchild(new ParseNode(initial)); // void is dummy initial

	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return newnode;
}

ParseNode gen_keyvalue_from_arraybuilder(const ParseNode & variable, const ParseNode & initial) {
	/* paramtable is used in function decl */
	/* this paramtable has only one value */
	/* 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 */

	sprintf(codegen_buf, "%s.init(%s)", variable.fs.CurrentTerm.what.c_str(), initial.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(variable)); // type
	newnode.addchild(new ParseNode(initial)); // void is dummy initial

	// instead of return a NT_PARAMTABLE, now return NT_KEYVALUE node
	return newnode;
}

ParseNode gen_paramtable(ParseNode & paramtable_elem) {
	ParseNode newnode = ParseNode();
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE || paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		// promote dimen_slice to paramtable
		return gen_argtable(paramtable_elem);
	}
	else {
		newnode.addchild(new ParseNode(paramtable_elem)); // keyvalue
		sprintf(codegen_buf, "%s", paramtable_elem.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
		return newnode;
	}
}


ParseNode gen_paramtable(ParseNode & paramtable_elem, ParseNode & paramtable) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
	bool dimen1, dimen2, arg1, arg2;
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
		dimen1 = true;
	}
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		arg1 = true;
	}
	if (paramtable.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
		dimen2 = true;
	}
	if (paramtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		arg2 = true;
	}
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE) {
		// keyvalue pair 
		newnode = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE);
	}
	else if ((dimen1 || arg1)
		&& (dimen2 || arg2)) {
		// merge paramtable with keyvalue and paramtable with keyvalue
		newnode = ParseNode(gen_flex(Term{ (dimen1 || dimen2) ? TokenMeta::NT_DIMENSLICE : TokenMeta::NT_ARGTABLE_PURE, "" }), nullptr);
		for (int i = 0; i < paramtable_elem.child.size(); i++)
		{
			newnode.addchild(new ParseNode(*paramtable_elem.child[i]));
		}
		// assume paramtable is flatterned
		for (int i = 0; i < paramtable.child.size(); i++)
		{
			newnode.addchild(new ParseNode(*paramtable.child[i]));
		}
		sprintf(codegen_buf, "%s, %s", paramtable_elem.fs.CurrentTerm.what.c_str(), paramtable.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm.what = string(codegen_buf);
	}
	else {
		// merge dimen_slice(aka argtable) and paramtable with keyvalue
		// promote dimen_slice to paramtable
		for (int i = 0; i < paramtable_elem.child.size(); i++)
		{
			// promote exp to keyvalue
			// TODO
			// if slice raise Undefined Behavior
			newnode.addchild(new ParseNode(gen_promote_exp_to_keyvalue(*paramtable_elem.child[i])));
		}
		// assume paramtable is flatterned
		for (int i = 0; i < paramtable.child.size(); i++)
		{
			newnode.addchild(new ParseNode(*paramtable.child[i]));
		}
		sprintf(codegen_buf, "%s, %s", paramtable_elem.fs.CurrentTerm.what.c_str(), paramtable.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm.what = string(codegen_buf);
	}
	return newnode;
}

ParseNode gen_promote_exp_to_keyvalue(const ParseNode & paramtable_elem) {
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE) {
		// keyvalue pair
		return paramtable_elem;
	}
	else {
		return gen_keyvalue(paramtable_elem);
	}
}

ParseNode gen_promote_paramtable(const ParseNode paramtable) {
	const ParseNode * pn = &paramtable;
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
	do {
		// for all non-flatterned paramtable
		for (int i = 0; i < pn->child.size(); i++)
		{
			newnode.addchild(new ParseNode(gen_promote_exp_to_keyvalue(*pn->child[i])));
		}
		if (pn->child.size() >= 2)
		{
			/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
			pn = pn->child[1];
		}
	} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
	return newnode;
}