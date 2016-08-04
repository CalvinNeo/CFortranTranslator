#include "parser.h"
#include "tokenizer.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>

ParseNode::~ParseNode()
{
	//delete attr;
	for (int i = 0; i < child.size(); i++)
	{
		delete child[i];
	}
}
ParseNode::ParseNode(const ParseNode & pn)
{
	this->fs = pn.fs;
	this->father = pn.father;
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
		//delete attr;
		for (int i = 0; i < child.size(); i++)
		{
			delete child[i];
		}
		child.clear();

		this->fs = pn.fs;
		this->father = pn.father;
		for (int i = 0; i < pn.child.size(); i++)
		{
			this->addchild(new ParseNode(*pn.child[i]));
		}

		return *this;
	}
}

void ParseNode::addchild(ParseNode * ptrn) {
	this->child.push_back(ptrn);
	ptrn -> father = this;
}

ParseNode program_tree;
ParseNode * curnode;

void preoder(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	stack< pair< ParseNode * , int> > s;

	s.push(make_pair(ptree, 0));
	while (!s.empty())
	{
		p = s.top().first;
		int deep = s.top().second;
		s.pop();
		cout << string(deep * 2, ' ') << p->fs.CurrentTerm.token << "," << p->fs.CurrentTerm.what << endl;
		for (int i = p->child.size() - 1; i >= 0; i--)
		{
			s.push(make_pair(p->child[i], deep + 1));
		}
	}
}

void VariableAttr::parse() {

}
void TypeAttr::parse() {

}