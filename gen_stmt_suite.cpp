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
		if (stmt->child.size() > 0 && stmt->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINESET)
		{
			ParseNode * vardef_set = stmt->child[0];
			// examine all variable define stmt
			for (int j = 0; j < vardef_set->child.size(); j++)
			{
				ParseNode * vardef = vardef_set->child[j];
				ParseNode * typeinfo = vardef->child[0];
				ParseNode * vardescattr = vardef->child[1];
				ParseNode * entity_variable = vardef->child[2];
				std::string name = get_variable_name( entity_variable );
				if (get_function("", name) != nullptr) {
					// declared function
				}
				else {
					if (vardef->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						// for every variable, generate independent definition
						VariableInfo * vinfo = get_variable("@", "@", name);
						if (vinfo != nullptr)
						{
							// variable is defined by common block
							get_variabledesc_attr(vardescattr).merge(vinfo->desc);
							CommonBlockInfo commoninfo = get_context().commonblocks[vinfo->commonblock_name];
							std::string common_varname = "_" + to_string(vinfo->commonblock_index + 1);
							// common语句并不能给出 vinfo->type 的值
							vinfo->type = gen_qualified_typestr(typeinfo->fs.CurrentTerm.what, get_variabledesc_attr(vardescattr));
							regen_vardef(vinfo, *vardef, *typeinfo, *vardescattr, entity_variable);
							sprintf(codegen_buf, "%s = %s.%s", vardef->fs.CurrentTerm.what.c_str(), vinfo->commonblock_name.c_str(), common_varname.c_str());
							vinfo->implicit_defined = false; // `common` is explicit declaration
							newsuitestr += string(codegen_buf);
						}
						else {
							// variable haven't defined
							VariableInfo newinfo("", VariableDesc(), ParseNode());
							vinfo = add_variable("@", "@", name, newinfo);
							regen_vardef(vinfo, *vardef, *typeinfo, *vardescattr, entity_variable);
							newsuitestr += vardef->fs.CurrentTerm.what;
						}
						newsuitestr += ";\n";
					}
					else if (vardef->fs.CurrentTerm.token == TokenMeta::NT_DECLAREDVARIABLE) {
						// declared variable
					}
				}
			}
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
	// 这部分一定要放在commonblock检查之后
	forall_variable_in_function("@", "@", [&](const std::pair<std::string, VariableInfo *> & p) {
		if (p.second->implicit_defined)
		{
			string local_name = implicit_type_from_name(p.first).fs.CurrentTerm.what;
			if (p.second->commonblock_name == "") {
				sprintf(codegen_buf, "%s %s;\n", local_name.c_str(), p.first.c_str());
			}
			else {
				std::string common_varname = "_" + to_string(p.second->commonblock_index + 1);
				sprintf(codegen_buf, "%s & %s = %s.%s;\n", local_name.c_str()
					, p.first.c_str(), p.second->commonblock_name.c_str(), common_varname.c_str());
			}
			newsuitestr = string(codegen_buf) + newsuitestr;
		};
	});
	oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
	//// CAN NOT call `clear_temporary_variables();` HERE
	return newsuitestr;
}