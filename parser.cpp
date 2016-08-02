#include "parser.h"
#include "tokenizer.h"
#include <stack>
#include <iostream>
#include <cstdio>

ParseNode::~ParseNode()
{
	for (int i = 0; i < child.size(); i++)
	{
		delete child[i];
	}
}

ParseNode program_tree;
ParseNode * curnode;

void preoder(ParseNode * ptree) {
	using namespace std;
	ParseNode * p = nullptr;
	stack<ParseNode *> s;
	s.push(ptree);
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		cout << p->fs.CurrentTerm.what << "	" << p->fs.CurrentTerm.token << endl;
		for (int i = p->child.size() - 1; i >= 0; i--)
		{
			s.push(p->child[i]);
		}
	}
}