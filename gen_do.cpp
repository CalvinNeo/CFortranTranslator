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

ParseNode gen_hiddendo(const ParseNode & _generate_stmt, TokenMeta_T return_token ) {
	/* give generate stmt */
	ParseNode newnode = ParseNode();
	ParseNode * exp = _generate_stmt.child[0];
	ParseNode * index = _generate_stmt.child[1];
	ParseNode * from = _generate_stmt.child[2];
	ParseNode * to = _generate_stmt.child[3];
	string rt = "";
	sprintf(codegen_buf, "[](int %s){return %s ;}", index->fs.CurrentTerm.what.c_str(), exp->fs.CurrentTerm.what.c_str());
	string str_lambda_body = string(codegen_buf);
	sprintf(codegen_buf, "f1a_init_hiddendo(%s, %s, %s)"
		, from->fs.CurrentTerm.what.c_str()/* exp_from */
		, to->fs.CurrentTerm.what.c_str()/* exp_to */
		, str_lambda_body.c_str());
	string str_init = string(codegen_buf);
	rt += str_init;
	newnode.fs.CurrentTerm = Term{ return_token, rt };
	newnode.addchild(new ParseNode(*exp)); // exp
	newnode.addchild(new ParseNode(*index)); // index variable
	newnode.addchild(new ParseNode(*from)); // exp_from
	newnode.addchild(new ParseNode(*to)); // exp_to
	return newnode;
}
