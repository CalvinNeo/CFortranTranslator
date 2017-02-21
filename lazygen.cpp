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

#include "parser.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>

std::string lazy_gen(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	stack< pair< ParseNode *, int> > s;

	s.push(make_pair(ptree, 0));
	while (!s.empty())
	{
		p = s.top().first;
		int deep = s.top().second;
		s.pop();
		if (p->child.size() == 0) {
			// terminal
		}
		else {
			// non-terminal
			switch (p->fs.CurrentTerm.token)
			{
			case TokenMeta::NT_PARAMTABLE:
				break;
			case TokenMeta::NT_FORMATTER:
				break;
			case TokenMeta::NT_AUTOFORMATTER:
				break;
			case TokenMeta::NT_ARGTABLE:
				break;
			case TokenMeta::NT_FUNCTIONDECLARE:
				break;
			case TokenMeta::NT_VARIABLEDEFINE:
				break;
			case TokenMeta::NT_STATEMENT:
				break;
			case TokenMeta::NT_EXPRESSION:
				break;
			case TokenMeta::NT_IF:
				break;
			case TokenMeta::NT_ELSEIF:
				break;
			case TokenMeta::NT_DO:
				break;
			case TokenMeta::NT_VARIABLEINITIAL:
				break;
			case TokenMeta::NT_DECLAREDVARIABLE:
				break;
			case TokenMeta::NT_SUITE:
				break;
			case TokenMeta::NT_FUCNTIONARRAY:
				break;
			default:
				break;
			}
			update_pos(*p);
		}
	}
	return "";
}