#include "gen_common.h"


std::string gen_paramtable_variable_str(VariableDesc vardesc, const tuple<string, ParseNode, ParseNode *> & param_info) {
	string paramtblstr;
	string type_nospec;
	if (vardesc.optional)
	{
		type_nospec += "foroptional<";
		type_nospec += get<1>(param_info).fs.CurrentTerm.what;
		type_nospec += ">";
	}
	else {
		type_nospec += get<1>(param_info).fs.CurrentTerm.what;
	}	
	paramtblstr += gen_qualified_typestr(type_nospec, vardesc); // type
	paramtblstr += get<0>(param_info); // variable name
	return paramtblstr;
}

std::string regen_paramtable(const vector<tuple<string, ParseNode, ParseNode *>> & paramtable_info) {
	/* generate new paramtable with type */
	string paramtblstr;
	for (int i = 0; i < paramtable_info.size() - 1 /* exclude return value */; i++)
	{
		if (i != 0)
			paramtblstr += ", ";
		ParseNode * vp = get<2>(paramtable_info[i]);
		if (vp == nullptr) {
			print_error("not find variable/function " + get<0>(paramtable_info[i]));
			continue;
		}
		
		if (vp->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL ||
			vp->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE)
		{
			paramtblstr += gen_paramtable_variable_str(
				(vp->attr == nullptr || dynamic_cast<VariableAttr *>(vp->attr)->vinfoptr == nullptr)
				? VariableDesc() : dynamic_cast<VariableAttr *>(vp->attr)->vinfoptr->desc, paramtable_info[i]);
		}
		else if (vp->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
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
	for (int i = 0; i < suite.child.size(); i++)
	{
		ParseNode * stmti = suite.child[i];
		if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
			// var_def 
			/* suite.child[i] => stmt */
			/* REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
			/* stmti->child[0] => var_def */
			/* from pn=stmti->child[0].child[0] is typename */
			/* from pn=stmti->child[0].child[1] is dimen_slice */
			/* from pn=stmti->child[0].child[2] is all variables of this type */
			ParseNode * pn = stmti->child[0]->child[2];
			do {
				// for all non-flatterned paramtable
				for (int i = 0; i < pn->child.size(); i++)
				{
					// for each variable in flatterned paramtable
					/* pn->child[i] is varname_i with initial value */
					/* pn->child[i]->child[0] is varname string */
					//param_definition.push_back(pn->child[i]->child[0]);
					declared_variables.push_back(pn->child[i]);
				}
				if (pn->child.size() >= 2)
				{
					/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
					/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
					pn = pn->child[1];
				}
			} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
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
		// for all non-flatterned paramtable
		for (int i = 0; i < pn->child.size(); i++)
		{
			// for each variable in flatterned paramtable
			paramtable_info.push_back(make_tuple(pn->child[i]->fs.CurrentTerm.what, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr)); // refer to function suite and determine type of params
		}
		if (pn->child.size() >= 2)
		{
			/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
			pn = pn->child[1];
		}
	} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);


	/* result variable must be the last one */
	paramtable_info.push_back(make_tuple(variable_result.fs.CurrentTerm.what, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr));// if subroutine get tuple ("", "void")

	/* set type to all paramtable_info */
	for (int i = 0; i < paramtable_info.size(); i++) // varname in paramtable
	{
		string varname = get<0>(paramtable_info[i]);
		for (int j = 0; j < declared_variables.size(); j++) // definition in suite
		{
			ParseNode * declared_variable_node = declared_variables[j];
			// variable
			if (declared_variable_node->fs.CurrentTerm.token ==  TokenMeta::NT_VARIABLEINITIAL
				|| declared_variable_node->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE){
				if (declared_variable_node->child[0]->fs.CurrentTerm.what == varname) {
					//					NT_VARIABLEINITIAL/NT_KEYVALUE (variable_name, variable_initial_value)
					//	father 			NT_PARAMTABLE
					//	father.father	NT_VARIABLEDEFINE var_def = (type_nospec, vardescattr, paramtable)
					//  paramtable_info[i] = tuple<name, type, ParseNode *>
					get<1>(paramtable_info[i]) = *declared_variable_node->father->father->child[0]; // type
					get<2>(paramtable_info[i]) = declared_variable_node; // variable ParseNode
					/* `delete` ParseNode except return value */
					if (i != paramtable_info.size() - 1) {
						declared_variable_node->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
					}
				}
			}
			else if (declared_variable_node->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
				// interface function
				if (declared_variable_node->child[1]->fs.CurrentTerm.what == varname) {
					string interface_paramtable_str = "";
					if (declared_variable_node->attr != nullptr) {
						// variables declared in the interface block
						FunctionAttr * interface_attr = dynamic_cast<FunctionAttr *>(declared_variable_node->attr);
						vector<tuple<string, ParseNode, ParseNode *>> interface_paramtable = interface_attr->finfoptr->funcdesc.paramtable_info;
						for (int k = 0; k < interface_paramtable.size() - 1; k++)
						{
							if (k != 0)
								interface_paramtable_str += ", ";
							ParseNode * param_node = get<2>(interface_paramtable[k]);
							interface_paramtable_str += gen_paramtable_variable_str(
								(param_node->attr == nullptr || dynamic_cast<VariableAttr *>(param_node->attr)->vinfoptr == nullptr)
								? VariableDesc() : dynamic_cast<VariableAttr *>(param_node->attr)->vinfoptr->desc
								, interface_paramtable[k]);
						}
					}
					get<1>(paramtable_info[i]) = gen_type(Term{TokenMeta::Function_Def, "std::function<"
						+ declared_variable_node->child[3]/*vardef return value*/->child[0]->fs.CurrentTerm.what
						+ "(" + interface_paramtable_str + ")>" });
					get<2>(paramtable_info[i]) = declared_variable_node;
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
	
	ParseNode * oldsuite = &suite;
	bool is_subroutine = variable_result.fs.CurrentTerm.what == "";

	// log function in function table

	// get all variables declared in this function
	vector<ParseNode *> declared_variables = get_all_declared(suite);
	// get all params in paramtable of function declare (var_name, var_type, ParseNode*)
	vector<tuple<string, ParseNode, ParseNode *>> paramtable_info = get_full_paramtable(paramtable, variable_result, declared_variables, is_subroutine);

	// log function and set attr 
	FunctionDesc funcdesc = FunctionDesc(declared_variables, paramtable_info);
	FunctionAttr functionattr = FunctionAttr(&newnode, add_function("", variable_function.fs.CurrentTerm.what, FunctionInfo(funcdesc)));
	newnode.attr = functionattr.clone();

	// make newnode
	string newsuitestr = regen_suite(oldsuite); 
	string paramtblstr = regen_paramtable(paramtable_info);
	/* generate function ParseTree */
	newnode.addchild(new ParseNode()); // reserved functionhead 0
	newnode.addchild(new ParseNode(variable_function)); // function name 1
	newnode.addchild(new ParseNode(paramtable)); // paramtable 2
	if (get<2>(paramtable_info[paramtable_info.size() - 1]) == nullptr) {
		// void function
		ParseNode vardef = gen_vardef_simple(gen_type(Term{ TokenMeta::Void_Def, "void" }), "");
		newnode.addchild(new ParseNode(vardef)); // return_value 3
	}
	else {
		ParseNode vardef = gen_vardef_simple(get<1>(paramtable_info[paramtable_info.size() - 1]), ""); 
		newnode.addchild(new ParseNode(vardef)); // return_value 3
	}
	newnode.addchild(new ParseNode(suite)); // suite 4

	/* generate function code */
	sprintf(codegen_buf, "%s %s(%s)\n{\n%s\treturn %s;\n}\n"
		, get<1>(paramtable_info[paramtable_info.size() - 1]).fs.CurrentTerm.what.c_str() // return value type, "void" if subroutine
		, variable_function.fs.CurrentTerm.what.c_str() // function name
		, paramtblstr.c_str() // paramtable
		, oldsuite->fs.CurrentTerm.what.c_str() // code
		, (is_subroutine ? "" : variable_result/* variable_result is raw for90 return without type*/.fs.CurrentTerm.what.c_str()) // add return stmt if not function
	);
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
	// return
	return newnode;
}
