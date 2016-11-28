#include "gen_common.h"

std::string regen_suite(ParseNode * oldsuite) {
	/* this function regen code of `suite` node without all repeated variable definition(NT_DECLAREDVARIABLE) in suite */
	/* NT_DECLAREDVARIABLE node will node be removed bacause they are marked already */
	std::string newsuitestr;
	for (int i = 0; i < oldsuite->child.size(); i++)
	{
		// oldsuite->child[i]: stmt/ interface_decl
		if (oldsuite->child[i]->child.size() > 0 && oldsuite->child[i]->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
		{
			// examine all variable define stmt
			// this code is similar to `find out all var_def nodes` code
			ParseNode * typeinfo = oldsuite->child[i]->child[0]->child[0];
			// oldsuite->child[i]->child[0]: NT_VARIABLEDEFINE
			// oldsuite->child[i]->child[0]->child[2]: NT_PARAMTABLE
			ParseNode * pn = oldsuite->child[i]->child[0]->child[2];
			do {
				// for all non-flatterned paramtable
				for (int j = 0; j < pn->child.size(); j++)
				{
					// for each variable in flatterned paramtable
					/* pn->child[i] is varname with initial value */
					/* pn->child[i]->child[0] is varname string */
					if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
						// for every variable, generate independent definition
						newsuitestr += typeinfo->fs.CurrentTerm.what; // type
						newsuitestr += " ";
						newsuitestr += pn->child[j]->child[0]->fs.CurrentTerm.what; // varname
						if (pn->child[j]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
							// default value
							newsuitestr += " = ";
							newsuitestr += pn->child[j]->child[1]->fs.CurrentTerm.what;
						}
						newsuitestr += " ;\n";
					}
					else if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE) {
						// do not generate declared string
					}
				}
				if (pn->child.size() >= 2)
				{
					/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
					/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
					pn = pn->child[1];
				}
			} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
		}
		else if (oldsuite->child[i]->fs.CurrentTerm.token == TokenMeta::NT_INTERFACE) {
			// do not generate declared string
		}
		else {
			// normal stmt
			newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
	}
	// update oldsuite->fs.CurrentTerm.what
	oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
	return newsuitestr;
}

std::string regen_paramtable(const vector<tuple<string, ParseNode, ParseNode *>> & param_name_typename) {
	/* generate new paramtable with type */
	string paramtblstr;
	for (int i = 0; i < param_name_typename.size() - 1 /* exclude return value */; i++)
	{
		if (i != 0)
			paramtblstr += ", ";
		if (get<2>(param_name_typename[i]) == nullptr) {
			print_error("not find variable/function " + get<0>(param_name_typename[i]));
			continue;
		}
	
		if (get<2>(param_name_typename[i])->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL || 
			get<2>(param_name_typename[i])->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE)
		{
			VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(get<2>(param_name_typename[i])->attr);
			if (vardescattr != nullptr)
			{
				if (vardescattr->desc.constant) {
					paramtblstr += "const ";
				}
				else {
				}
			}
			if (vardescattr != nullptr && vardescattr->desc.optional)
			{
				paramtblstr += "foroptional<";
				paramtblstr += get<1>(param_name_typename[i]).fs.CurrentTerm.what;
				paramtblstr += ">";
			}
			else {
				paramtblstr += get<1>(param_name_typename[i]).fs.CurrentTerm.what;
			}
			paramtblstr += " ";
			if (vardescattr != nullptr)
			{
				if (vardescattr->desc.reference) {
					paramtblstr += "& ";
				}
				else {
				}
			}
			paramtblstr += get<0>(param_name_typename[i]);
		}
		else if (get<2>(param_name_typename[i])->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
			paramtblstr += get<1>(param_name_typename[i]).fs.CurrentTerm.what;
			paramtblstr += " " + get<0>(param_name_typename[i]);
		}

	}

	return paramtblstr;
}

vector<ParseNode *> get_all_declared(ParseNode & suite) {
	/* find out all var_def and interface-function nodes */
	// NOTE in fortran variables in paramtable need to be declared in suite too
	vector<ParseNode *> param_definition;
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
					param_definition.push_back(pn->child[i]);
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
						param_definition.push_back(const_cast<ParseNode *>(&wrapper));
					}
				}
			}
		}
	}
	return param_definition;
}

std::string get_function_type(const ParseNode & func) {
	string rt = "";
	return rt;
}

vector<tuple<string, ParseNode, ParseNode *>> get_full_paramtable(const ParseNode & paramtable, const ParseNode & variable_result, const vector<ParseNode *> & param_definition, bool is_subroutine) {
	vector<tuple<string, ParseNode, ParseNode *>> param_name_typename; // (var_name, var_type, ParseNode*)
	const ParseNode * pn = &paramtable; 
	/* add the paramtable */
	do {
		// for all non-flatterned paramtable
		for (int i = 0; i < pn->child.size(); i++)
		{
			// for each variable in flatterned paramtable
			param_name_typename.push_back(make_tuple(pn->child[i]->fs.CurrentTerm.what, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr)); // refer to function suite and determine type of params
		}
		if (pn->child.size() >= 2)
		{
			/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
			pn = pn->child[1];
		}
	} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);

	//param_name_typename.push_back(make_tuple(param_definition[j]->fs.CurrentTerm.what
	//	, get_function_type(*param_definition[j]), param_definition[j])); // refer to function suite and determine type of params

	/* add result variable */
	// must be the last one of param_name_typename
	param_name_typename.push_back(make_tuple(variable_result.fs.CurrentTerm.what, gen_type(Term{ TokenMeta::Void_Def, "void" }), nullptr));// if subroutine get tuple ("", "void")

	/* set type to all param_name_typename */
	for (int i = 0; i < param_name_typename.size(); i++)
	{
		string varname = get<0>(param_name_typename[i]);
		for (int j = 0; j < param_definition.size(); j++)
		{
			ParseNode * varname_node = param_definition[j];
			// variable
			if (varname_node->fs.CurrentTerm.token ==  TokenMeta::NT_VARIABLEINITIAL 
				|| varname_node->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE){
				if (varname_node->child[0]->fs.CurrentTerm.what == varname) {
					//				NT_VARIABLEINITIAL/NT_KEYVALUE (variable_name, variable_initial_value)
					//	father 		NT_PARAMTABLE
					//	father * 2	NT_VARIABLEDEFINE var_def = (type_spec, slice, paramtable)
					//  param_name_typename[i] = tuple<name, type, ParseNode *>
					get<1>(param_name_typename[i]) = *varname_node->father->father->child[0]; // type
					get<2>(param_name_typename[i]) = varname_node; // variable ParseNode
					/* `delete` ParseNode except return value */
					if (i != param_name_typename.size() - 1) {
						varname_node->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
					}
				}
			}
			// interface function
			else if (varname_node->fs.CurrentTerm.token == TokenMeta::NT_FUNCTIONDECLARE) {
				if (varname_node->child[1]->fs.CurrentTerm.what == varname) {
					string paramtable_types = "";
					if (varname_node->attr != nullptr) {
						FunctionAttr * fa = dynamic_cast<FunctionAttr *>(varname_node->attr);
						for (int k = 0; k < fa->param_name_typename.size() - 1; k++)
						{
							if (k != 0)
								paramtable_types += ", ";
							paramtable_types += get<1>(fa->param_name_typename[k]).fs.CurrentTerm.what;
						}
					}
					get<1>(param_name_typename[i]) = gen_type(Term{TokenMeta::Function_Def, "std::function<"
						+ varname_node->child[3]/*vardef return value*/->child[0]->fs.CurrentTerm.what
						+ "(" + paramtable_types + ")"
						+ ">" });
					get<2>(param_name_typename[i]) = varname_node;
				}
			}
		}
	}
	return param_name_typename;
}

ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite) {
	/* fortran90 does not declare type of arguments in function declaration statement*/
	ParseNode newnode = ParseNode();
	
	ParseNode * oldsuite = const_cast<ParseNode *>(&suite);
	bool is_subroutine = variable_result.fs.CurrentTerm.what == "";

	// log function in function table
	add_function("", variable_function.fs.CurrentTerm.what, nullptr);

	// get all variables declared in this function
	vector<ParseNode *> param_definition = get_all_declared(suite);
	// get all params in paramtable of function declare (var_name, var_type, ParseNode*)
	vector<tuple<string, ParseNode, ParseNode *>> param_name_typename = get_full_paramtable(paramtable, variable_result, param_definition, is_subroutine);

	
	/* add type infomation to paramtable ParseNodes  */
	ParseNode newpt; // paramtable is raw for90 paramtable without type /* generate new return with type */
	
					   
	ParseNode newrt; // variable_result is raw for90 return without type
					   // NOW WRAP TO GET var_def

					   /* re-generated codes of suite */
	string newsuitestr = regen_suite(oldsuite); // suite is raw for90 suite without type
	string paramtblstr = regen_paramtable(param_name_typename);
	/* generate function ParseTree */
	newnode.addchild(new ParseNode()); // functionhead 0
	newnode.addchild(new ParseNode(variable_function)); // function name 1
	newnode.addchild(new ParseNode(paramtable)); // paramtable 2
	if (get<2>(param_name_typename[param_name_typename.size() - 1]) == nullptr) {
		// void function
		ParseNode vardef = gen_vardef_simple(gen_type(Term{ TokenMeta::Void_Def, "void" })
			, "");
		newnode.addchild(new ParseNode(vardef)); // return value 3
	}
	else {
		ParseNode vardef = gen_vardef_simple(get<1>(param_name_typename[param_name_typename.size() - 1])
			, "");  // *get<2>(param_name_typename[param_name_typename.size() - 1]);
		newnode.addchild(new ParseNode(vardef)); // return value 3
	}
	newnode.addchild(new ParseNode(suite)); // suite 4

	sprintf(codegen_buf, "%s %s(%s)\n{\n%s\treturn %s;\n}\n"
		, get<1>(param_name_typename[param_name_typename.size() - 1]).fs.CurrentTerm.what.c_str() // return value type, "void" if subroutine
		, variable_function.fs.CurrentTerm.what.c_str() // function name
		, paramtblstr.c_str() // paramtable
		, oldsuite->fs.CurrentTerm.what.c_str() // code
		, (is_subroutine ? "" : variable_result.fs.CurrentTerm.what.c_str()) // add return stmt if not function
	);
	/* generate function code */
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
	// set attr
	FunctionAttr functionattr = FunctionAttr(&newnode);
	functionattr.param_definition = param_definition;
	functionattr.param_name_typename = param_name_typename;
	newnode.attr = functionattr.clone();
	// return
	return newnode;
}