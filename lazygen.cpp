#include "parser.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>


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