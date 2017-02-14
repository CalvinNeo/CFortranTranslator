#include "gen_common.h"

ParseNode gen_do(ParseNode & suite) {
	ParseNode newnode = ParseNode();
	suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
	sprintf(codegen_buf, "do{\n%s}", suite.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
	newnode.addchild(new ParseNode()); // do
	newnode.addchild(new ParseNode(suite)); // suite
	return newnode;
}

ParseNode gen_do_range(const ParseNode & loop_variable, const ParseNode & exp1, const ParseNode & exp2, const ParseNode & exp3, ParseNode & suite){
	ParseNode newnode = ParseNode();
	suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
	sprintf(codegen_buf, "for(%s = %s; %s <= %s; %s += %s){\n%s}", loop_variable.fs.CurrentTerm.what.c_str(), exp1.fs.CurrentTerm.what.c_str()
		, loop_variable.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str()
		, loop_variable.fs.CurrentTerm.what.c_str(), exp3.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

	newnode.addchild(new ParseNode()); // do
	newnode.addchild(new ParseNode(loop_variable)); // loop_variable name
	newnode.addchild(new ParseNode(exp1)); // begin
	newnode.addchild(new ParseNode(exp2)); // end
	newnode.addchild(new ParseNode(exp3)); // step
	newnode.addchild(new ParseNode(suite)); // suite
	return newnode;
}

ParseNode gen_do_while(const ParseNode & exp, ParseNode & suite) {
	ParseNode newnode = ParseNode();
	suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
	sprintf(codegen_buf, "while(%s){\n%s}", exp.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WHILE, string(codegen_buf) };
	newnode.addchild(new ParseNode()); // while
	newnode.addchild(new ParseNode(exp)); // exp
	newnode.addchild(new ParseNode(suite)); // suite
	return newnode;
}

std::vector<const ParseNode *> gen_nested_hiddendo_layers(const ParseNode & hiddendo) {
	std::vector<const ParseNode *> hiddendo_layer;
	const ParseNode * pn = &hiddendo;
	while (pn->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
		hiddendo_layer.push_back(pn);
		if (pn->child.size() > 0 && pn->child[0]->child.size() > 0) {
			pn = pn->child[0]/*NT_EXPRESSION*/->child[0]/*NT_HIDDENDO*/;
		}
		else {
			break;
		}
	}
	return hiddendo_layer;
}

std::string gen_nested_hiddendo(const std::vector<const ParseNode *> & hiddendo_layer) {
	vector<ParseNode *>::iterator x;
	string lb_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (x)->child[2]->fs.CurrentTerm.what; });
	string ub_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (x)->child[3]->fs.CurrentTerm.what; });
	string indexer_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return "fsize_t " + (x)->child[1]->fs.CurrentTerm.what; });
	sprintf(codegen_buf, "[](%s){return %s;}", indexer_str.c_str(), hiddendo_layer[hiddendo_layer.size() - 1]->child[0]->fs.CurrentTerm.what.c_str());
	string lambda = string(codegen_buf);
	string args;
	for (auto j = 0; j < hiddendo_layer.size(); j++)
	{
		if (j != 0) {
			args += ", ";
		}
		sprintf(codegen_buf, "current[%d]", (int)j);
		args += string(codegen_buf);
	}
	// map array to parameter
	//sprintf(codegen_buf, "[](const fsize_t(&current)[%d]){return %s(%s);}", (int)hiddendo_layer.size(), lambda.c_str(), args.c_str());
	sprintf(codegen_buf, "[](const fsize_t * current){return %s(%s);}", lambda.c_str(), args.c_str());
	return string(codegen_buf);
}

ParseNode gen_hiddendo(const ParseNode & _generate_stmt, TokenMeta_T return_token ) {
	/* give generate stmt */
	ParseNode newnode = ParseNode();
	ParseNode * exp = _generate_stmt.child[0];
	ParseNode * index = _generate_stmt.child[1];
	ParseNode * from = _generate_stmt.child[2];
	ParseNode * to = _generate_stmt.child[3];

	if (get_context().parse_config.usefarray)
	{
		std::vector<const ParseNode *> hiddendo_layer;
		const ParseNode * ab = &_generate_stmt;
		while (ab->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
			hiddendo_layer.push_back(ab);
			if (ab->child.size() > 0 && ab->child[0]->child.size() > 0) {
				ab = ab->child[0]/*NT_EXPRESSION*/->child[0]/*NT_HIDDENDO*/;
			}
			else {
				break;
			}
		}
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_HIDDENDO, gen_nested_hiddendo(hiddendo_layer) };
	}
	else {
		string rt = "";
		sprintf(codegen_buf, "[](int %s){return %s ;}", index->fs.CurrentTerm.what.c_str(), exp->fs.CurrentTerm.what.c_str());
		string str_lambda_body = string(codegen_buf);
		sprintf(codegen_buf, "f1a_init_hiddendo(%s, %s, %s)"
			, from->fs.CurrentTerm.what.c_str()/* exp_from */
			, to->fs.CurrentTerm.what.c_str()/* exp_to */
			, str_lambda_body.c_str());
		string str_init = string(codegen_buf);
		rt += str_init;
	}

	newnode.addchild(new ParseNode(*exp)); // 0 exp
	newnode.addchild(new ParseNode(*index)); // 1 index variable
	newnode.addchild(new ParseNode(*from)); // 2 exp_from
	newnode.addchild(new ParseNode(*to)); // 3 exp_to
	return newnode;
}
