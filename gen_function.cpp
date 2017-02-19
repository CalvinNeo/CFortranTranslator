#include "gen_common.h"

std::string regen_paramtable(const vector<tuple<string, ParseNode, ParseNode *>> & paramtable_info) {
	/* generate new paramtable with type */
	string paramtblstr;
	for (int i = 0; i < paramtable_info.size() - 1 /* exclude return value */; i++)
	{
		if (i != 0)
			paramtblstr += ", ";
		ParseNode * vardef = get<2>(paramtable_info[i]);
		ParseNode * entity_variable = vardef->child[2];
		if (vardef == nullptr) {
			print_error("not find variable/function " + get<0>(paramtable_info[i]));
			continue;
		}
		
		if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE ||
			vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE)
		{
			VariableDesc desc = get_variabledesc_attr(*vardef);
			std::string typestr = gen_qualified_typestr(get<1>(paramtable_info[i]), desc);
			sprintf(codegen_buf, "%s %s", typestr.c_str(), get<0>(paramtable_info[i]).c_str());
			paramtblstr += string(codegen_buf);
		}
		else if (vardef->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
			paramtblstr += get<1>(paramtable_info[i]).fs.CurrentTerm.what;
			paramtblstr += " " + get<0>(paramtable_info[i]);
		}

	}
	return paramtblstr;
}

vector<ParseNode *> get_all_declared(ParseNode & suite) {
	/* find out all var_def and interface-function nodes */
	// NOTE in fortran variables in paramtable need to be declared in suite too
	vector<ParseNode *> declared_variables;
	for (int i = 0; i < (int)suite.child.size(); i++)
	{
		ParseNode * stmti = suite.child[i];
		if (stmti->child.size() == 1 && stmti->get(0).fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINESET) {
			ParseNode * vardef_set = stmti->child[0];
			for (int j = 0; (int)j < vardef_set->child.size(); j++)
			{
				declared_variables.push_back(vardef_set->child[j]);
			}
		}
		else if (stmti->fs.CurrentTerm.token == TokenMeta::NT_INTERFACE) {
			// interface function
			if (stmti->child.size() > 0) {
				ParseNode & wrappers = *stmti->child[0];
				for (int i = 0; i < wrappers.child.size(); i++)
				{
					const ParseNode & wrapper = *wrappers.child[i];
					if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_PROGRAM) {

					}
					else if (wrapper.fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
						// wrapper.child[1] is function name
						declared_variables.push_back(const_cast<ParseNode *>(&wrapper));
					}
				}
			}
		}
	}
	return declared_variables;
}

vector<tuple<string, ParseNode, ParseNode *>> get_full_paramtable(const ParseNode & paramtable, const ParseNode & variable_result, const vector<ParseNode *> & declared_variables, bool is_subroutine) {
	vector<tuple<string, ParseNode, ParseNode *>> paramtable_info; // (var_name, var_type, ParseNode*)
	const ParseNode * pn = &paramtable; 
	/* add the paramtable */
	do {
		for (int i = 0; i < pn->child.size(); i++)
		{
			paramtable_info.push_back(make_tuple(pn->get(i).fs.CurrentTerm.what
				, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr)); // refer to function suite and determine type of params
		}
		if (pn->child.size() >= 2)
		{
			pn = pn->child[1];
		}
	} while (pn->child.size() == 2 && pn->get(1).fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);


	/* result variable must be the last one */
	paramtable_info.push_back(make_tuple(variable_result.fs.CurrentTerm.what
		, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr));// if subroutine get tuple ("", "void")

	for (int i = 0; i < (int)paramtable_info.size(); i++) // definition in paramtable
	{
		string varname = get<0>(paramtable_info[i]);
		for (int j = 0; j < (int)declared_variables.size(); j++) // definition in suite
		{
			// variable
			ParseNode * vardef = declared_variables[j];
			ParseNode * entity_variable = vardef->child[2];
			ParseNode * initial = entity_variable->child[1];
			if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE || vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE){
				if (entity_variable->get(0).fs.CurrentTerm.what == varname) {
					get<1>(paramtable_info[i]) = *vardef->child[0]; // type_nospec
					get<2>(paramtable_info[i]) = vardef; // variable ParseNode
					if (i != paramtable_info.size() - 1) {
						/* `delete` ParseNode except return value */
						vardef->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
					}
				}
			}
			else if (vardef->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
				// interface function
				if (vardef->get(1).fs.CurrentTerm.what == varname) {
					string interface_paramtable_str = "";
					if (vardef->attr != nullptr) {
						// variables declared in the interface block
						FunctionAttr * interface_attr = dynamic_cast<FunctionAttr *>(vardef->attr);
						vector<tuple<string, ParseNode, ParseNode *>> interface_paramtable = interface_attr->finfoptr->funcdesc.paramtable_info;
						for (int k = 0; k < interface_paramtable.size() - 1; k++)
						{
							if (k != 0)
								interface_paramtable_str += ", ";
							ParseNode * param_node = get<2>(interface_paramtable[k]);
							VariableDesc desc = get_variabledesc_attr(*param_node);
							std::string typestr = gen_qualified_typestr(get<1>(interface_paramtable[k]), desc);
							sprintf(codegen_buf, "%s %s", typestr.c_str(), get<0>(interface_paramtable[k]).c_str());
							interface_paramtable_str += string(codegen_buf);
						}
					}
					get<1>(paramtable_info[i]) = gen_type(Term{TokenMeta::Function_Def, "std::function<"
						+ vardef->get(3)/*vardef return value*/.get(0).fs.CurrentTerm.what
						+ "(" + interface_paramtable_str + ")>" });
					get<2>(paramtable_info[i]) = vardef;
				}
			}
		}
	}
	return paramtable_info;
}

ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite) {
	/* fortran90 does not declare type of arguments in function declaration statement*/
	// paramtable is raw for90 paramtable and every variable in the table has no type infomation
	ParseNode newnode = ParseNode();
	
	ParseNode & oldsuite = suite;
	bool is_subroutine = variable_result.fs.CurrentTerm.what == "";

	// log function in function table

	// get all variables declared in this function
	vector<ParseNode *> declared_variables = get_all_declared(suite);
	// get all params in paramtable of function declare (var_name, var_type, ParseNode*)
	vector<tuple<string, ParseNode, ParseNode *>> paramtable_info = get_full_paramtable(paramtable, variable_result, declared_variables, is_subroutine);

	// log function and set attr 
	FunctionDesc funcdesc = FunctionDesc(declared_variables, paramtable_info);
	FunctionAttr functionattr = FunctionAttr(add_function("", variable_function.fs.CurrentTerm.what, FunctionInfo(funcdesc)));
	newnode.setattr(functionattr.clone());

	// make newnode
	string newsuitestr = regen_suite(oldsuite); 
	string paramtblstr = regen_paramtable(paramtable_info);
	/* generate function ParseTree */
	newnode.addchild(ParseNode()); // reserved functionhead 0
	newnode.addchild(variable_function); // function name 1
	newnode.addchild(paramtable); // paramtable 2
	if (get<2>(paramtable_info[paramtable_info.size() - 1]) == nullptr) {
		// void function
		ParseNode vardef = gen_vardef_simple(gen_type(Term{ TokenMeta::Void_Def, "void" }), "");
		newnode.addchild(vardef); // return_value 3
	}
	else {
		ParseNode vardef = gen_vardef_simple(get<1>(paramtable_info[paramtable_info.size() - 1]), ""); 
		newnode.addchild(vardef); // return_value 3
	}
	newnode.addchild(suite); // suite 4

	/* generate function code */
	sprintf(codegen_buf, "%s %s(%s)\n{\n%s\treturn %s;\n}\n"
		, get<1>(paramtable_info[paramtable_info.size() - 1]).fs.CurrentTerm.what.c_str() // return value type, "void" if subroutine
		, variable_function.fs.CurrentTerm.what.c_str() // function name
		, paramtblstr.c_str() // paramtable
		, oldsuite.fs.CurrentTerm.what.c_str() // code
		, (is_subroutine ? "" : variable_result/* variable_result is raw for90 return without type*/.fs.CurrentTerm.what.c_str()) // add return stmt if not function
	);
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
	// return
	insert_temporary_variables("@", variable_function.fs.CurrentTerm.what);
	return newnode;
}
