#include "parser.h"
#include "tokenizer.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>

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