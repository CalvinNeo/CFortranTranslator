#include "gen_common.h"

// both function and array is callable

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable) {

	/* function call OR array index */
	/* NOTE that array index can be A(1:2, 3:4) */
	ParseNode newnode = ParseNode();
	string name;
	string args;
	if (funcname_map.find(callable_head.fs.CurrentTerm.what) != funcname_map.end()) {
		// some fortran intrinsic function NAME must be replaced with its c++ implementation function NAME in for90std.h
		name = funcname_map.at(callable_head.fs.CurrentTerm.what);
	}
	else {
		name = callable_head.fs.CurrentTerm.what;
	}
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_DIMENSLICE) {
		sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  string(codegen_buf) };
	}
	else /*if(argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE)*/{
		args += name;
		map<string, map<string, string>>::const_iterator map_func = func_kwargs.find(name);
		args += "(";
		bool kwargs = false;
		for (int i = 0; i < argtable.child.size(); i++)
		{
			if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE) {
				if (map_func == func_kwargs.end()) {
					print_error("invalid kwarg of " + name, argtable);
				}
				else {
					string argname = argtable.child[i]->child[0]->fs.CurrentTerm.what;
					string argvalue = argtable.child[i]->child[1]->fs.CurrentTerm.what;
					map<string, string>::const_iterator map_arg = map_func->second.find(argname);
					string argtype;
					if (map_arg == map_func->second.end()) {
						print_error("invalid kwarg of " + name, argtable);
					}
					else {
						args += /*map_arg->second + " " + */argname + " = " + argvalue;
					}
				}
			}
			else {
				if (kwargs) {
					print_error("keyword arguments must come after normal arguments", argtable);
				}
				else {
					args += argtable.child[i]->fs.CurrentTerm.what;
				}
			}
			if (i != argtable.child.size() - 1) {
				args += ", ";
			}
		}
		args += ")";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  args };
	}
	newnode.addchild(new ParseNode(callable_head)); // function/array name
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable, const ParseNode & paramtable) {
	// kwargs functrion
	/* function call OR array index */
	ParseNode newnode = ParseNode();
	string name, args;
	if (funcname_map.find(callable_head.fs.CurrentTerm.what) != funcname_map.end()) {
		// some fortran intrinsic function name must be replaced with its c++ implementation in for90std.h
		name = funcname_map.at(callable_head.fs.CurrentTerm.what);
	}
	else {
		name = callable_head.fs.CurrentTerm.what;
	}
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_DIMENSLICE) {
		// error
	}
	else {
		args += name;
		args += "(";
		args += argtable.fs.CurrentTerm.what;
		args += ",";
		args += paramtable.fs.CurrentTerm.what;
		args += ")";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  args };
	}
	return newnode;
}