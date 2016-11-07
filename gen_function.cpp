#include "gen_common.h"

ParseNode gen_function(const ParseNode & variable_function, const ParseNode & paramtable, const ParseNode & variable_result, ParseNode & suite) {
	/* fortran90 does not declare type of arguments in function declaration statement*/
	ParseNode newnode = ParseNode();
	// all params in paramtable of function declare (var_name, var_type, ParseNode*)
	vector<tuple<string, string, ParseNode *>> param_name_typename;
	vector<ParseNode *> param_definition; // all variables declared in this function
	const ParseNode * prmtbl = (&paramtable); // iterate the paramtable
	ParseNode * oldsuite = const_cast<ParseNode *>(&suite);
	bool is_subroutine = variable_result.fs.CurrentTerm.what == "";

	// log function in function table
	add_function("", variable_function.fs.CurrentTerm.what, nullptr);

	do {
		// for all non-flatterned paramtable
		for (int i = 0; i < prmtbl->child.size(); i++)
		{
			// for each variable in flatterned paramtable
			param_name_typename.push_back(make_tuple(prmtbl->child[i]->fs.CurrentTerm.what, "void", nullptr)); // refer to function suite and determine type of params
		}
		if (prmtbl->child.size() >= 2)
		{
			/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
			/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
			prmtbl = prmtbl->child[1];
		}
	} while (prmtbl->child.size() == 2 && prmtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
	/* result variable */
	// if subroutine get tuple ("", "void")
	param_name_typename.push_back(make_tuple(variable_result.fs.CurrentTerm.what, "void", nullptr));
	/* find out all var_def nodes */
	for (int i = 0; i < suite.child.size(); i++)
	{
		ParseNode * stmti = suite.child[i];
		/* suite.child[i] => stmt */
		/*  REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
		if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
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
					param_definition.push_back(pn->child[i]->child[0]);
				}
				if (pn->child.size() >= 2)
				{
					/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
					/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
					pn = pn->child[1];
				}
			} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
		}
	}

	/* set type to all param_name_typename */
	for (int i = 0; i < param_name_typename.size(); i++)
	{
		string varname = get<0>(param_name_typename[i]);
		for (int j = 0; j < param_definition.size(); j++)
		{
			ParseNode * varname_node = param_definition[j];
			if (varname_node->fs.CurrentTerm.what == varname) {
				//	father		NT_VARIABLEINITIAL (variable_name, variable_initial_value)
				//	father * 2	NT_PARAMTABLE
				//	father * 3	NT_VARIABLEDEFINE var_def
				//  param_name_typename[i] = tuple<name, type, ParseNode *>
				get<1>(param_name_typename[i]) = varname_node->father->father->father->child[0]->fs.CurrentTerm.what;
				get<2>(param_name_typename[i]) = varname_node->father;
				/* `delete` ParseNode except return value */
				if (i != param_name_typename.size() - 1) {
					varname_node->father->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
				}
			}
		}
	}

	/* generate new paramtable with type */
	string argtblstr;
	for (int i = 0; i < param_name_typename.size() - 1 /* exclude YY_RESULT(return value) */; i++)
	{
		if (i != 0)
			argtblstr += ", ";
		if (get<2>(param_name_typename[i]) == nullptr) {
			print_error( "not find variable/function " + get<0>(param_name_typename[i]));
			continue;
		}
		VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(get<2>(param_name_typename[i])->attr);
		if (vardescattr != nullptr)
		{
			if (vardescattr->desc.constant) {
				argtblstr += "const ";
			}
			else {
			}
		}
		if (vardescattr->desc.optional)
		{
			argtblstr += "foroptional<";
			argtblstr += get<1>(param_name_typename[i]);
			argtblstr += ">";
		}
		else {
			argtblstr += get<1>(param_name_typename[i]);
		}
		argtblstr += " ";
		if (vardescattr != nullptr)
		{
			if (vardescattr->desc.reference) {
				argtblstr += "& ";
			}
			else {
			}
		}
		argtblstr += get<0>(param_name_typename[i]);
	}

	/* add type infomation to paramtable ParseNodes  */
	ParseNode * newpt; // paramtable is raw for90 paramtable without type
					   // TODO This is optional so i decide not to implement currently
					   /* generate new return with type */
	ParseNode * newrt; // variable_result is raw for90 return without type
					   // TODO This is optional so i decide not to implement currently

					   /* re-generated codes of suite */
	string newsuitestr; // suite is raw for90 suite without type
	for (int i = 0; i < oldsuite->child.size(); i++)
	{
		if (oldsuite->child[i]->child.size() > 0 && oldsuite->child[i]->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
		{
			// this code is similar to `find out all var_def nodes` code
			//ParseNode * pn = oldsuite->child[0]->child[1];
			ParseNode * typeinfo = oldsuite->child[i]->child[0]->child[0];
			ParseNode * pn = oldsuite->child[i]->child[0]->child[2];
			do {
				// for all non-flatterned paramtable
				for (int j = 0; j < pn->child.size(); j++)
				{
					// for each variable in flatterned paramtable
					/* pn->child[i] is varname with initial value */
					/* pn->child[i]->child[0] is varname string */
					if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
						//newsuitestr += oldsuite->child[i]->child[0]->fs.CurrentTerm.what; // deprecated THIS IS NT_VARIABLEDEFINE, but different variables can be different
						newsuitestr += typeinfo->fs.CurrentTerm.what;
						newsuitestr += " ";
						newsuitestr += pn->child[j]->child[0]->fs.CurrentTerm.what;
						if (pn->child[j]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
							newsuitestr += " = ";
							newsuitestr += pn->child[j]->child[1]->fs.CurrentTerm.what;
						}
						newsuitestr += " ;\n";
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
		else {
			newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
	}
	// update oldsuite->fs.CurrentTerm.what
	oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
	/* generate function ParseTree */
	ParseNode function_head;
	newnode.addchild(new ParseNode(function_head)); // function
	newnode.addchild(new ParseNode(variable_function)); // function name
														 // argtable
														 // TODO add nodes
														 // return value
	newnode.addchild(new ParseNode(suite)); // trimed suite

	sprintf(codegen_buf, "%s %s(%s)\n{%s\treturn %s;\n}"
		, get<1>(param_name_typename[param_name_typename.size() - 1]).c_str() // return value type, "void" if subroutine
		, variable_function.fs.CurrentTerm.what.c_str() // function name
		, argtblstr.c_str() // argtable
		, oldsuite->fs.CurrentTerm.what.c_str() // code
		, (is_subroutine ? "" : variable_result.fs.CurrentTerm.what.c_str()) // add return stmt if not function
	);
	/* generate function code */
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
	return newnode;
}