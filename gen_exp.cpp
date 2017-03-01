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

ParseNode  gen_exp(const ParseNode & exp1, const ParseNode & op, const ParseNode & exp2, std::string trans_rule) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode.addlist(exp1, op, exp2);
	return newnode;
}

ParseNode gen_exp(const ParseNode & exp1, const ParseNode & op, std::string trans_rule) {
	ParseNode newnode = ParseNode();
	sprintf(codegen_buf, trans_rule.c_str(), exp1.fs.CurrentTerm.what.c_str());
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
	newnode.addlist(op, exp1);
	return newnode;
}

