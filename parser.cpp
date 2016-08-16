#include "parser.h"
#include "tokenizer.h"
#include "cgen.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>

ParseNode::~ParseNode()
{
	delete attr;
	for (int i = 0; i < child.size(); i++)
	{
		delete child[i];
	}
}
ParseNode::ParseNode(const ParseNode & pn)
{
	this->fs = pn.fs;
	this->father = pn.father;
	this->attr = pn.attr == nullptr? nullptr: pn.attr->clone();
	for (int i = 0; i < pn.child.size(); i++)
	{
		this->addchild( new ParseNode(*pn.child[i]) );
	}
}

ParseNode & ParseNode::operator= (const ParseNode & pn) {
	if (this == &pn) {
		return *this;
	}
	else {
		delete attr;
		for (int i = 0; i < child.size(); i++)
		{
			delete child[i];
		}
		child.clear();

		this->fs = pn.fs;
		this->father = pn.father;
		for (int i = 0; i < pn.child.size(); i++)
		{
			this->addchild( new ParseNode(*pn.child[i]) );
		}

		return *this;
	}
}

void ParseNode::addchild(ParseNode * ptrn, bool add_back) {
	if (ptrn != nullptr) {
		ptrn->father = this;
	}
	if (add_back) {
		this->child.push_back(ptrn);
	}
	else {
		this->child.insert(this->child.begin(), ptrn);
	}
}

ParseNode program_tree;
ParseNode * curnode;

void preorder(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	stack< pair< ParseNode * , int> > s;

	s.push(make_pair(ptree, 0));
	while (!s.empty())
	{
		p = s.top().first;
		int deep = s.top().second;
		s.pop();
		if (p->child.size()==0) {
			cout << string(deep * 2, ' ') << p->fs.CurrentTerm.token << ", " << "TERMINAL " << p->fs.CurrentTerm.what << endl;
		}
		else {
			cout << string(deep * 2, ' ') << p->fs.CurrentTerm.token << ", " << p->fs.CurrentTerm.what << endl;
			for (int i = p->child.size() - 1; i >= 0; i--)
			{
				s.push(make_pair(p->child[i], deep + 1));
			}
		}
	}
}

void VariableAttr::parse() {

}
void TypeAttr::parse() {

}


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