#include "parser.h"
#include "attribute.h"
#include "tokenizer.h"
#include "gen_config.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>
#include <cmath>

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
		this->attr = pn.attr == nullptr ? nullptr : pn.attr->clone();
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

std::string & replace_all(std::string & str, const std::string & old_value, const std::string & new_value)
{
	while (true)
	{
		int pos = 0;
		if ((pos = str.find(old_value, 0)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else break;
	}
	return str;
}
std::string & replace_all_distinct(std::string & str, const std::string & old_value, const std::string & new_value)
{
	for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else break;
	}
	return str;
}
std::string & repalce_all_my(std::string & str, const std::string & old_value, const std::string & new_value)
{
	for (int pos = 0; pos != -1; pos += new_value.length())
		if ((pos = str.find(old_value, pos)) != -1)
			str.replace(pos, old_value.length(), new_value);
		else break;
		return str;
}

void print_error(const std::string & error_info, const ParseNode & yylval) {
	using namespace std;
	printf("\nError : %s\n", error_info.c_str());
	printf("line %d from %d len %d, current token is %s(id = %d) : %s \n"
		, get_flex_state().parse_line, get_flex_state().parse_pos, get_flex_state().parse_len, get_intent_name(yylval.fs.CurrentTerm.token).c_str(), yylval.fs.CurrentTerm.token, yylval.fs.CurrentTerm.what.c_str());
	char buf[255];
	sprintf(buf, "context : %s ^ %s"
		, global_code.substr(max(0, get_flex_state().parse_pos - 10), 10).c_str()
		, global_code.substr(get_flex_state().parse_pos, 10).c_str());
	string cont = string(buf);
	replace_all_distinct(cont, "\n", "\\n");
	printf("%s\n", cont.c_str());
}

void print_error(const std::string & error_info) {
	using namespace std;
	printf("\nError : %s\n", error_info.c_str());
}