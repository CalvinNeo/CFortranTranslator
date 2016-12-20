#include "gen_common.h"

// both function and array is callable

ParseNode gen_function_array(const ParseNode & callable_head, const ParseNode & argtable) {

	/* function call OR array index */
	/* NOTE that array index can be A(1:2, 3:4) */
	ParseNode newnode = ParseNode();
	string name;
	string func_header;
	newnode.addchild(new ParseNode(callable_head)); // function/array name
	newnode.addchild(new ParseNode(argtable)); // argtable
	if (funcname_map.find(callable_head.fs.CurrentTerm.what) != funcname_map.end()) {
		// some fortran intrinsic function NAME must be replaced with its c++ implementation function NAME in for90std.h
		name = funcname_map.at(callable_head.fs.CurrentTerm.what);
	}
	else {
		name = callable_head.fs.CurrentTerm.what;
	}
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_DIMENSLICE) {
		// array
		//sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
		string arr = name;
		for (int i = 0; i < argtable.child.size(); i++)
		{
			if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_SLICE) {
				sprintf(codegen_buf, "slice(%s, %s, %s + 1)", arr.c_str()
					, argtable.child[i]->child[0]->fs.CurrentTerm.what.c_str()
					, argtable.child[i]->child[1]->fs.CurrentTerm.what.c_str());
				arr = string(codegen_buf);
			}
			else {
				sprintf(codegen_buf, "(%s)", argtable.child[i]->fs.CurrentTerm.what.c_str());
				arr += string(codegen_buf);
			}
		}
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  arr };
	}
	else if(argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE){
		// function call
		func_header += name;
		auto map_func = func_kwargs.find(name); // function_name -> args
		func_header += "(";
		bool kwargs = false;
		int normal_count = 0;
		map<string, string> kws;
		for (int i = 0; i < argtable.child.size(); i++)
		{
			if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_KEYVALUE) {
				// keyword/named argument
				//kwargs = true;
				if (map_func == func_kwargs.end()) {
					print_error("invalid kwarg of function " + name, argtable);
				}
				else {
					string argname = argtable.child[i]->child[0]->fs.CurrentTerm.what;
					string argvalue = argtable.child[i]->child[1]->fs.CurrentTerm.what;
					kws[argname] = argvalue;
				}
			}
			else {
				// normal argument
				vector<ParseNode *> args;
				if (argtable.child[i]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER) {
					for (auto j = 0; j < argtable.child[i]->child.size(); j++)
					{
						args.push_back(argtable.child[i]->child[j]);
					}
				}
				else {
					args.push_back(argtable.child[i]);
				}

				if (kwargs) {
					print_error("keyword arguments must come after normal arguments", argtable);
				}
				else {
					for (auto j = 0; j < args.size(); j++)
					{
						if (i != 0 || j != 0) {
							func_header += " ,";
						}
						func_header += args[j]->fs.CurrentTerm.what;
						normal_count++;
					}
				}
			}
		}
		if (map_func != func_kwargs.end()) {
			for (int i = normal_count; i < map_func->second.size(); i++)
			{
				string this_param_name = map_func->second[i].first;
				auto this_arg = kws.find(this_param_name);
				if (normal_count != 0) {
					func_header += ", ";
				}
				if (this_arg == kws.end()) {
					func_header += "_D";
				}
				else {
					func_header += this_arg->second;
				}
				normal_count++;
			}
		}
		func_header += ")";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  func_header };
	}
	else {
		print_error("callable generate fail", newnode);
	}
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
	if (argtable.fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE_DIMENSLICE) {
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