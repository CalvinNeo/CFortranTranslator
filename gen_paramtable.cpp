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
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE 
		|| paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		// promote dimen_slice to paramtable
		return gen_argtable(paramtable_elem);
	}
	else if(paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE){
		newnode.addchild(new ParseNode(paramtable_elem)); // keyvalue
		sprintf(codegen_buf, "%s", paramtable_elem.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
		return newnode;
	}
	else if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE
		|| paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_DIMENSLICE) {
		// get a paramtable from dimen_slice
		newnode = paramtable_elem;
		return newnode;
	}
	else {
		newnode = paramtable_elem;
		print_error("Illegal gen_paramtable arg", newnode);
		return newnode;
	}
}


ParseNode gen_paramtable(ParseNode & paramtable_elem, ParseNode & paramtable) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
	bool dimen1 = false, dimen2 = false, arg1 = false, arg2 = false, va1 = false, va2 = false;;
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
		dimen1 = true;
	}
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		arg1 = true;
	}
	if (TokenMeta::iselement(paramtable_elem.fs.CurrentTerm.token)) {
		va1 = true;
	}
	if (paramtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_DIMENSLICE) {
		dimen2 = true;
	}
	if (paramtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
		arg2 = true;
	}
	if (TokenMeta::iselement(paramtable.fs.CurrentTerm.token)) {
		va2 = true;
	}
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE && paramtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE) {
		// all keyvalue pair 
		newnode = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE);
	}
	else if(paramtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE){
		// there is keyvalue pair
		// this is possible because of rule `dimen_slice : exp ',' paramtable `
		// there is keyvalue
		if (dimen1) {
			// promote dimen_slice to paramtable
			for (int i = 0; i < paramtable_elem.child.size(); i++)
			{
				newnode.addchild(new ParseNode(*paramtable_elem.child[i]));
			}
		}
		else {
			// do not promote exp to keyvalue
			// TODO
			newnode.addchild(new ParseNode(paramtable_elem));
		}
		// assume paramtable is flatterned
		for (int i = 0; i < paramtable.child.size(); i++)
		{
			newnode.addchild(new ParseNode(*paramtable.child[i]));
		}
		sprintf(codegen_buf, "%s, %s", paramtable_elem.fs.CurrentTerm.what.c_str(), paramtable.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm.what = string(codegen_buf);
	}
	else if ((dimen1 || arg1 || va1) && (dimen2 || arg2 || va2)) {
		// all dimen_slice or argument_pure or variable
		newnode = ParseNode(gen_flex(Term{ (dimen1 || dimen2) ? TokenMeta::NT_PARAMTABLE_DIMENSLICE : TokenMeta::NT_ARGTABLE_PURE, "" }), nullptr);
		if (dimen1 || arg1) {
			for (int i = 0; i < paramtable_elem.child.size(); i++)
			{
				newnode.addchild(new ParseNode(*paramtable_elem.child[i]));
			}
		}
		else {
			newnode.addchild(new ParseNode(paramtable_elem));
		}
		// assume paramtable is flatterned
		if (dimen2 || arg2) {
			for (int i = 0; i < paramtable.child.size(); i++)
			{
				newnode.addchild(new ParseNode(*paramtable.child[i]));
			}
		}
		else {
			newnode.addchild(new ParseNode(paramtable));
		}
		sprintf(codegen_buf, "%s, %s", paramtable_elem.fs.CurrentTerm.what.c_str(), paramtable.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm.what = string(codegen_buf);
	}
	else {
		print_error("bad param table");
	}
	return newnode;
}

ParseNode gen_promote_exp_to_keyvalue(const ParseNode & paramtable_elem) {
	if (paramtable_elem.fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE) {
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


ParseNode gen_argtable(ParseNode & dimen_slice) {
	ParseNode newnode = ParseNode();
	bool isdimen = false;
	int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
	dimen_slice.fs.CurrentTerm.what = "";
	for (sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
	{
		if (sliceid != 0) {
			dimen_slice.fs.CurrentTerm.what += ", ";
		}
		if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
			// dimen_slice
			// slice or slice/exp
			isdimen = true;
			newnode.addchild(new ParseNode(*dimen_slice.child[sliceid]));
			if (dimen_slice.child[sliceid]->fs.CurrentTerm.token == TokenMeta::NT_SLICE) {
				// slice
				if (dimen_slice.child[sliceid]->child.size() == 2) {
					/* from, to */
					sprintf(codegen_buf, "%s, %s", dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
						, dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
				}
				else {
					// size
					sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str());
				}
			}
			else {
				// exp
				sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->fs.CurrentTerm.what.c_str());
			}
		}
		else if(dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE){
			// NT_ARGTABLE_PURE
			// exp
			isdimen = false;
			newnode.addchild(new ParseNode(*dimen_slice.child[sliceid]));
			sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->fs.CurrentTerm.what.c_str());
		}
		else {
			print_error("Illegal argtable", dimen_slice);
		}
		dimen_slice.fs.CurrentTerm.what += codegen_buf;
	}
	if (isdimen) {
		// %%s.slice(%s)
		// should not set codegen_buf here
		sprintf(codegen_buf, "/* deprecated */ slice(%%s, %s)", dimen_slice.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE_DIMENSLICE, string(codegen_buf) };
	}
	else {
		sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
	}
	return newnode;
}