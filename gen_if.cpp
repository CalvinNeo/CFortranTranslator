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

ParseNode gen_if(const ParseNode & exp, const ParseNode & suite_true, const ParseNode & elseif, const ParseNode & suite_else) {
	ParseNode newnode = ParseNode();

	string true_str, else_str;
	if (suite_else.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		else_str = tabber(suite_else.fs.CurrentTerm.what);
	}
	true_str = tabber(suite_true.fs.CurrentTerm.what);

	if (elseif.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
		if (suite_else.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
			// neither elseif or suite_else
			sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str());
		}
		else {
			// bare suite_else

			sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), else_str.c_str());
		}
	}
	else {
		if (suite_else.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
			// bare elseif

			sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str());
		}
		else {
			// elseif + else
			sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str(), else_str.c_str());
		}
	}


	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };


	newnode.addlist(ParseNode(), exp, suite_true);
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(elseif); // recursive elseif-stmt
	}
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(suite_else); // else-stmt
	}
	return newnode;
}

ParseNode gen_if_oneline(const ParseNode & exp, const ParseNode & stmt_true) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, "if (%s) %s", exp.fs.CurrentTerm.what.c_str(), stmt_true.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };

	newnode.addlist(ParseNode(), exp, stmt_true);
	return newnode;
}

ParseNode gen_elseif(const ParseNode & exp, const ParseNode & suite_true, const ParseNode & elseif) {
	ParseNode newnode = ParseNode();
	string true_str = tabber(suite_true.fs.CurrentTerm.what);

	if (elseif.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
		sprintf(codegen_buf, "else if(%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str());}
	else {
		sprintf(codegen_buf, "else if(%s){\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str());
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };


	newnode.addlist(ParseNode(), exp, suite_true);
	if (elseif.fs.CurrentTerm.token != TokenMeta::NT_DUMMY) {
		newnode.addchild(elseif); // another elseif-stmt
	}
	return newnode;
}