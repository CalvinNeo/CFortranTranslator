#include "gen_common.h"

ParseNode gen_stmt(const ParseNode & content) {
	sprintf(codegen_buf, "%s ;", content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); 
	return newnode;
}

ParseNode gen_stmt(const ParseNode & content, const std::string & rules) {
	sprintf(codegen_buf, rules.c_str() , content.fs.CurrentTerm.what.c_str());
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) }), nullptr);
	newnode.addchild(new ParseNode(content)); 
	return newnode;
}

ParseNode gen_empty_suite() {
	
	ParseNode * newnode = new ParseNode();
	ParseNode & stmt = ParseNode(gen_flex(Term{ TokenMeta::NT_SUITE, "\n" }), newnode);
	newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
	newnode->addchild(new ParseNode(stmt)); // stmt
	newnode = flattern_bin(newnode);
	return *newnode;
}

std::string regen_suite(ParseNode * oldsuite) {
	// regen suite(especially variable declaration)
	/* this function regen code of `suite` node and 
	 * 1. remove all NT_DECLAREDVARIABLE in suite
	 * 2. regen_vardef */
	std::string newsuitestr;
	for (int i = 0; i < oldsuite->child.size(); i++)
	{
		// oldsuite->child[i]: stmt/ interface_decl
		ParseNode * stmt = oldsuite->child[i];
		if (stmt->child.size() > 0 && stmt->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
		{
			// examine all variable define stmt
			ParseNode * vardef = stmt->child[0];
			ParseNode * typeinfo = stmt->child[0]->child[0];
			ParseNode * vardescattr = vardef->child[1];
			ParseNode * pn = vardef->child[2];
			do {
				// for all non-flatterned paramtable
				for (int j = 0; j < pn->child.size(); j++)
				{
					// for each variable
					/* pn->child[i] is varname with initial value */
					/* pn->child[i]->child[0] is varname string */
					if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
						// for every variable, generate independent definition
						//newsuitestr += typeinfo->fs.CurrentTerm.what; // type
						//newsuitestr += " ";
						//newsuitestr += pn->child[j]->child[0]->fs.CurrentTerm.what; // varname
						//if (pn->child[j]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
						//	//default value
						//	newsuitestr += " = ";
						//	newsuitestr += pn->child[j]->child[1]->fs.CurrentTerm.what;
						//}
						//newsuitestr += ";\n";
						ParseNode newdefinenode;
						regen_vardef(newdefinenode, *typeinfo, *vardescattr, pn->child[j]);
						newsuitestr += newdefinenode.fs.CurrentTerm.what;
						newsuitestr += "\n";
					}
					else if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE) {
						// declared variable
					}
					else if (get_function("", pn->child[i]->child[0]->fs.CurrentTerm.what) != nullptr){
						// declared function
					}
				}
				if (pn->child.size() >= 2)
				{
					pn = pn->child[1];
				}
			} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
		}
		else if (stmt->fs.CurrentTerm.token == TokenMeta::NT_INTERFACE) {
			// do not generate declared string
		}
		else {
			// normal stmt
			newsuitestr += stmt->fs.CurrentTerm.what;
			newsuitestr += '\n';
		}
	}
	// update oldsuite->fs.CurrentTerm.what
	oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
	return newsuitestr;
}