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

void regen_do(FunctionInfo * finfo, ParseNode & do_stmt) {
	ParseNode & suite = do_stmt.get(0);
	regen_suite(finfo, suite, true);
	sprintf(codegen_buf, "do{\n%s}", tabber(suite.get_what()).c_str());
	do_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
}

void regen_do_range(FunctionInfo * finfo, ParseNode & do_stmt){
	ParseNode & loop_variable = do_stmt.get(0);
	ParseNode & exp1 = do_stmt.get(1);
	ParseNode & exp2 = do_stmt.get(2);
	ParseNode & exp3 = do_stmt.get(3);
	ParseNode & suite = do_stmt.get(4);
	regen_exp(finfo, exp1);
	regen_exp(finfo, exp2);
	regen_exp(finfo, exp3);
	regen_suite(finfo, suite, true);
	sprintf(codegen_buf, "for(%s = %s; %s <= %s; %s += %s){\n%s}"
		, loop_variable.get_what().c_str(), exp1.get_what().c_str()
		, loop_variable.get_what().c_str(), exp2.get_what().c_str()
		, loop_variable.get_what().c_str(), exp3.get_what().c_str(), tabber(suite.get_what()).c_str());
	do_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_DORANGE, string(codegen_buf) };
}

void regen_do_while(FunctionInfo * finfo, ParseNode & do_stmt) {
	ParseNode & exp = do_stmt.get(0);
	ParseNode & suite = do_stmt.get(1);
	regen_exp(finfo, exp);
	regen_suite(finfo, suite, true);
	sprintf(codegen_buf, "while(%s){\n%s}", exp.get_what().c_str(), tabber(suite.get_what()).c_str());
	do_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_WHILE, string(codegen_buf) };
}


std::vector<ParseNode *> get_nested_hiddendo_layers(ParseNode & hiddendo) {
	std::vector<ParseNode *> hiddendo_layer;
	ParseNode * pn = &hiddendo;
	while (pn->get_token() == TokenMeta::NT_HIDDENDO) {
		hiddendo_layer.push_back(pn);
		if (pn->length() > 0 
			&& pn->get(0).length() > 0 // NT_ARGTABLE_PURE
			&& pn->get(0).get(0).length() > 0 // NT_HIDDENDO
			) {
			pn = &pn->get(0).get(0);
		}
		else {
			break;
		}
	} 
	return hiddendo_layer;
}

SliceBoundInfo get_lbound_size_from_hiddendo(FunctionInfo * finfo, ParseNode & hiddendo) {
	vector<ParseNode *> hiddendo_layer = get_nested_hiddendo_layers(hiddendo);
	SliceBoundInfo lb_size = get_lbound_size_base(hiddendo_layer.begin(), hiddendo_layer.end()
		, [&](ParseNode * x) {
			regen_exp(finfo, x->get(2));
			return x->get(2).get_what();
	}
		, [&](ParseNode * x) {
			regen_exp(finfo, x->get(3));
			return x->get(3).get_what();
	});
	return lb_size;
}

void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo, std::function<void(ParseNode &)> regen_innermost) {
	/**************************************
	* this function flattern a n-layer nested hidden do into an lambda function,
	*	this function use a 1-dimension size-n array of `fsize_t`,
	*	which stands for index of every n-dimensions.
	* this function is used to deal with io-implied-do, ac-implied-do, data-implied-do.
	* Usage:
	* 1) io-implied-do
	* 2) ac-implied-do
	*	passed to `make_init_list` its 3rd argument
	*======================================
	*	A a0; B b0; C c0;
	*	auto result = [](const fsize_t * current) {
	*		return [](A a, B b, C c){ 
	*			// actual ac/data/io-implied-do-control codes
	*		}(current[0], current[1], ...);
	*	}
	*	({a0, b0, c0}) // call with args
	***************************************/
	if (get_context().parse_config.usefarray)
	{
		std::vector<ParseNode *> hiddendo_layer = get_nested_hiddendo_layers(hiddendo);

		/**************************************
		* generate indexer for each dimension(nested implied-do layers)
		*======================================
		*	e.g.
		*	```
		*	((F(I,J),J=1,2),I=3,4)
		*	```
		*	the indexer is
		*	`fsize_t i, fsize_t j`
		***************************************/
		string indexer_str = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [](auto x)->string {
			return "fsize_t " + (x)->get(1).get_what();
		});

		/**************************************
		* IMPORTANT
		*	refer rule `hidden_do` and found NT_HIDDENDO have EXACTLY **4** children
		*	the first child is argtable(because a hidden_do can contain several exps)
		* can't handle following code
		*======================================
		*	WRITE(2,*) (A(I),(B(I,J),J=1,i),I=2,10)
		***************************************/
		ParseNode & innermost_argtable = hiddendo_layer.back()->get(0);
		regen_innermost(innermost_argtable);
		string innermost_code = innermost_argtable.get_what();
		/**************************************
		* generate the following lambda
		*======================================
		*		return [](fsize_t a, fsize_t b, fsize_t c){
		*			// actual codes
		*		}(current[0], current[1], ...);
		*======================================
		*	`current` is a `fsize_t *` array.
		*	length of `current` = dimension
		*	count of parameter of this lambda = dimension
		*======================================
		*	usage of this lambda is to
		*	feed current to each parameters:
		*	current[0] -> a
		*	current[1] -> b
		*	current[2] -> c
		*	so actual codes can directly use names, not a `fsize_t *` array
		*======================================
		*	WHY NEED THIS WORKAROUND?
		*	because we need a iterative function, not a deep for-loop
		***************************************/
		sprintf(codegen_buf, "[&](%s){\n%s}", indexer_str.c_str(), tabber(innermost_code).c_str());
		string lambda_def = string(codegen_buf);
		int j = 0;
		string lambda_args = make_str_list(hiddendo_layer.begin(), hiddendo_layer.end(), [&](auto x) {
			sprintf(codegen_buf, "current[%d]", j++);
			return string(codegen_buf);
		}, ", ");

		// map array to parameter
		sprintf(codegen_buf, "return %s(%s);", lambda_def.c_str(), lambda_args.c_str());
		string lambda_call = string(codegen_buf);
		sprintf(codegen_buf, "[&](const fsize_t * current){\n%s\n}", tabber(lambda_call, false).c_str());
	}
	else {
		const ParseNode & exp = hiddendo.get(0);
		const ParseNode & index = hiddendo.get(1);
		const ParseNode & from = hiddendo.get(2);
		const ParseNode & to = hiddendo.get(3);
		sprintf(codegen_buf, "[&](int %s){return %s ;}", index.get_what().c_str(), exp.get_what().c_str());
		string str_lambda_body = string(codegen_buf);
		sprintf(codegen_buf, "f1a_init_hiddendo(%s, %s, %s)", from.get_what().c_str(), to.get_what().c_str(), str_lambda_body.c_str());
	}
	hiddendo.get_what() = string(codegen_buf);
}

void regen_hiddendo_expr(FunctionInfo * finfo, ParseNode & hiddendo) {
	regen_hiddendo_expr(finfo, hiddendo, [&](ParseNode & innermost_argtable) {
		regen_paramtable(finfo, innermost_argtable);
		sprintf(codegen_buf, "return %s;", innermost_argtable.get_what().c_str());
		innermost_argtable.get_what() = string(codegen_buf);
	});
}


ParseNode gen_hiddendo(ARG_IN argtable, ARG_IN index, ARG_IN from, ARG_IN to, TokenMeta_T return_token) {
	/**************************************
	* this function handles 1 layer at 1 time,
	*	it simply expands the hidden do into a `for` statement
	* though this function generates simpler code,
	*	it can not deal with io-implied-do, ac-implied-do, data-implied-do
	****************************************/
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_HIDDENDO, "" });
	newnode.addlist(argtable, index, from, to);
	std::string stuff = make_str_list(argtable.begin(), argtable.end(), [&](ParseNode * iter) {
		if (iter->length() > 0 && (iter)->get(0).get_token() == TokenMeta::NT_HIDDENDO)
		{
			return (iter)->get_what();
		}
		else {
			return (iter)->get_what() + ";";
		}
	}, "");
	sprintf(codegen_buf, "for(int %s = %s; %s <= %s; %s++){\n%s}", index.get_what().c_str(), from.get_what().c_str()
		, index.get_what().c_str(), to.get_what().c_str(), index.get_what().c_str(), tabber(stuff).c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_HIDDENDO, string(codegen_buf) };
	return newnode;
}
