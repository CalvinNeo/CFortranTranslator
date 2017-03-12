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

void regen_if(FunctionInfo * finfo, ARG_OUT if_stmt) {
	ParseNode & exp = if_stmt.get(0);
	ParseNode & suite_true = if_stmt.get(1);
	ParseNode & elseif = if_stmt.get(2);
	ParseNode & suite_else = if_stmt.get(3);
	regen_suite(finfo, suite_true, true);
	regen_suite(finfo, suite_else, true);

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
		regen_elseif(finfo, elseif);
		if (suite_else.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
			// bare elseif

			sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str());
		}
		else {
			// elseif + else
			sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str(), else_str.c_str());
		}
	}
	if_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
}

void regen_elseif(FunctionInfo * finfo, ARG_OUT elseif_stmt) {
	ParseNode & exp = elseif_stmt.get(0);
	ParseNode & suite_true = elseif_stmt.get(1);
	ParseNode & elseif = elseif_stmt.get(2);

	regen_suite(finfo, suite_true, true);

	string true_str = tabber(suite_true.fs.CurrentTerm.what);

	if (elseif.fs.CurrentTerm.token == TokenMeta::NT_DUMMY) {
		sprintf(codegen_buf, "else if(%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), true_str.c_str());
	}
	else {
		regen_elseif(finfo, elseif);
		sprintf(codegen_buf, "else if(%s){\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), true_str.c_str(), elseif.fs.CurrentTerm.what.c_str());
	}
	elseif_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
}
