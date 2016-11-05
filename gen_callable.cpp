#include "gen_common.h"

// both function and array is callable

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable) {

	/* function call OR array index */
	/* NOTE that array index can be A(1:2, 3:4) */
	ParseNode newnode = ParseNode();
	string name;
	string x;
	if (funcname_map.find(callable_head.fs.CurrentTerm.what) != funcname_map.end()) {
		// some fortran intrinsic function name must be replaced with its c++ implementation in for90std.h
		name = funcname_map.at(callable_head.fs.CurrentTerm.what);
	}
	else {
		name = callable_head.fs.CurrentTerm.what;
	}
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_DIMENSLICE) {
		sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  string(codegen_buf) };
	}
	else {
		x += name;
		x += "(";
		x += argtable.fs.CurrentTerm.what;
		x += ")";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  x };
	}
	newnode.addchild(new ParseNode(callable_head)); // function/array name
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}