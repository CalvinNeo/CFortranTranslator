/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"

ParseNode gen_do(const ParseNode & suite) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "do{\n%s}", tabber(suite.to_string()).c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
	newnode.addchild(ParseNode()); // do
	newnode.addchild(suite); // suite
	return newnode;
}

ParseNode gen_do_range(const ParseNode & loop_variable, const ParseNode & exp1, const ParseNode & exp2, const ParseNode & exp3, const ParseNode & suite){
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "for(%s = %s; %s <= %s; %s += %s){\n%s}", loop_variable.to_string().c_str(), exp1.to_string().c_str()
		, loop_variable.to_string().c_str(), exp2.to_string().c_str()
		, loop_variable.to_string().c_str(), exp3.to_string().c_str(), tabber(suite.to_string()).c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };

	newnode.addchild(ParseNode()); // do
	newnode.addchild(loop_variable); // loop_variable name
	newnode.addchild(exp1); // begin
	newnode.addchild(exp2); // end
	newnode.addchild(exp3); // step
	newnode.addchild(suite); // suite
	return newnode;
}

ParseNode gen_do_while(const ParseNode & exp, const ParseNode & suite) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "while(%s){\n%s}", exp.to_string().c_str(), tabber(suite.to_string()).c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WHILE, string(codegen_buf) };
	newnode.addchild(ParseNode()); // while
	newnode.addchild(exp); // exp
	newnode.addchild(suite); // suite
	return newnode;
}

std::vector<const ParseNode *> gen_nested_hiddendo_layers_from_exp(const ParseNode & hiddendo) {
	std::vector<const ParseNode *> hiddendo_layer;
	const ParseNode * pn = &hiddendo;
	while (pn->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
		hiddendo_layer.push_back(pn);
		if (pn->child.size() > 0 && pn->get(0).child.size() > 0) {
			pn = pn->child[0]/*NT_EXPRESSION*/->child[0]/*NT_HIDDENDO*/;
		}
		else {
			break;
		}
	}
	return hiddendo_layer;
}
std::vector<const ParseNode *> gen_nested_hiddendo_layers(const ParseNode & hiddendo) {
	std::vector<const ParseNode *> hiddendo_layer;
	const ParseNode * pn = &hiddendo;
	while (pn->fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO) {
		hiddendo_layer.push_back(pn);
		if (pn->child.size() > 0 && pn->get(0).child.size() > 0 && pn->get(0).get(0).child.size() > 0) {
			pn = &pn->get(0)/*NT_ARGTABLE_PURE*/.get(0)/*NT_EXPRESSION*/.get(0)/*NT_HIDDENDO*/;
		}
		else {
			break;
		}
	}
	return hiddendo_layer;
}

std::string gen_hiddendo_expr(const ParseNode & hiddendo) {
	if (get_context().parse_config.usefarray)
	{
		std::vector<const ParseNode *> hiddendo_layer = gen_nested_hiddendo_layers(hiddendo);
		string lb_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (x)->get(2).to_string(); });
		string ub_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return (x)->get(3).to_string(); });
		string indexer_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {return "fsize_t " + (x)->get(1).to_string(); });
		sprintf(codegen_buf, "[](%s){return %s;}", indexer_str.c_str(), hiddendo_layer[hiddendo_layer.size() - 1]->get(0).to_string().c_str());
		string lambda = string(codegen_buf);
		int j = 0;
		string args = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [&](auto x) {
			sprintf(codegen_buf, "current[%d]", j++);
			return string(codegen_buf);
		}, ", ");

		// map array to parameter
		sprintf(codegen_buf, "[](const fsize_t * current){return %s(%s);}", lambda.c_str(), args.c_str());
		return string(codegen_buf);
	}
	else {
		const ParseNode & exp = hiddendo.get(0);
		const ParseNode & index = hiddendo.get(1);
		const ParseNode & from = hiddendo.get(2);
		const ParseNode & to = hiddendo.get(3);
		sprintf(codegen_buf, "[](int %s){return %s ;}", index.to_string().c_str(), exp.to_string().c_str());
		string str_lambda_body = string(codegen_buf);
		sprintf(codegen_buf, "f1a_init_hiddendo(%s, %s, %s)", from.to_string().c_str(), to.to_string().c_str(), str_lambda_body.c_str());
		return string(codegen_buf);
	}
}

ParseNode gen_hiddendo(const ParseNode & argtable, const ParseNode & index, const ParseNode & from, const ParseNode & to, TokenMeta_T return_token) {
	/* give generate stmt */
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_HIDDENDO, "" });
	newnode.addchild(argtable); // 0 exp
	newnode.addchild(index); // 1 index variable
	newnode.addchild(from); // 2 exp_from
	newnode.addchild(to); // 3 exp_to
	std::string stuff;
	for (auto iter = argtable.child.begin(); iter < argtable.child.end(); iter++)
	{
		if ((*iter)->get(0).fs.CurrentTerm.token == TokenMeta::NT_HIDDENDO)
		{
			stuff += (*iter)->to_string();
		}
		else {
			stuff += (*iter)->to_string();
			stuff += ";";
		}
	}
	sprintf(codegen_buf, "for(int %s = %s; %s <= %s; %s++){\n%s}", index.to_string().c_str(), from.to_string().c_str(), index.to_string().c_str(), to.to_string().c_str(), index.to_string().c_str(), tabber(stuff).c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_HIDDENDO, string(codegen_buf) };
	return newnode;
}
