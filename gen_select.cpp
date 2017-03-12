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

void regen_select(FunctionInfo * finfo, ARG_OUT select_stmt) {
	ParseNode & exp = select_stmt.get(0);
	ParseNode & case_stmt = select_stmt.get(1); 
	select_stmt.fs.CurrentTerm = Term{ TokenMeta::NT_SELECT, "" };
	for (size_t i = 0; i < case_stmt.child.size(); i++)
	{
		ParseNode & case_stmt_elem = case_stmt.get(i);
		ParseNode & dimen_slice = case_stmt_elem.get(0);
		ParseNode & body = case_stmt_elem.get(1);
		regen_suite(finfo, body, true);
		if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
			// NT_DIMENSLICE
			string selector;
			for (int sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
			{
				ParseNode & from = dimen_slice.get(sliceid).get(0);
				ParseNode & to = dimen_slice.get(sliceid).get(1);
				if (sliceid == 0) {
					sprintf(codegen_buf, "(%s >= %s && %s < %s)", exp.to_string().c_str(), from.to_string().c_str(), exp.to_string().c_str(), to.to_string().c_str());
				}
				else {
					sprintf(codegen_buf, " || (%s >= %s && %s < %s)", exp.to_string().c_str(), from.to_string().c_str(), exp.to_string().c_str(), to.to_string().c_str());
				}
				selector += string(codegen_buf);
			}
			if (i == 0) {
				sprintf(codegen_buf, "if(%s){\n%s}\n", selector.c_str(), tabber(body.to_string()).c_str());
			}
			else {
				sprintf(codegen_buf, "else if(%s){\n%s}\n", selector.c_str(), tabber(body.to_string()).c_str());
			}
		}
		else {
			// NT_ARGTABLE_PURE
			string selector = "";
			if (i == 0) {
				selector = "if(";
				sprintf(codegen_buf, "if(%s == %s){\n%s}\n", exp.to_string().c_str(), dimen_slice.get(0).to_string().c_str(), tabber(body.to_string()).c_str());
			}
			else {
				selector = "else if(";
				sprintf(codegen_buf, "else if(%s == %s){\n%s}\n", exp.to_string().c_str(), dimen_slice.get(0).to_string().c_str(), tabber(body.to_string()).c_str());
			}
			for (int j = 0; j < dimen_slice.child.size(); j++)
			{
				if (j == 0) {
					sprintf(codegen_buf, "%s == %s", exp.to_string().c_str(), dimen_slice.get(j).to_string().c_str());
				}
				else {
					sprintf(codegen_buf, "|| (%s == %s)", exp.to_string().c_str(), dimen_slice.child[j]->to_string().c_str());
				}
				selector += codegen_buf;
			}
			sprintf(codegen_buf, "){\n%s}\n", tabber(case_stmt_elem.get(1).to_string()).c_str());
			selector += codegen_buf;
			sprintf(codegen_buf, "%s", selector.c_str());
		}
		select_stmt.fs.CurrentTerm.what += codegen_buf;
	}
}