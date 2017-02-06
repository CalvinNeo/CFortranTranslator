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
	this->attr = (pn.attr == nullptr ? nullptr: pn.attr->clone());
	for (int i = 0; i < pn.child.size(); i++)
	{
		if (pn.child[i] != nullptr) {
			this->addchild(new ParseNode(*pn.child[i]));
		}
		else {
			this->addchild(nullptr);
		}
	}
}

ParseNode & ParseNode::operator= (const ParseNode & pn) {
	if (this == &pn) {
		return *this;
	}
	else {
		delete this->attr;
		for (int i = 0; i < child.size(); i++)
		{
			delete child[i];
		}
		child.clear();

		this->fs = pn.fs;
		this->father = pn.father;
		this->attr = (pn.attr == nullptr ? nullptr : pn.attr->clone());
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

void ParseNode::addchild(const ParseNode & n, bool add_back ) {
	this->addchild(new ParseNode(n), add_back);
}

void ParseNode::replace(int childid, const ParseNode & pn) {
	delete this->child[childid];
	this->child[childid] = new ParseNode(pn);
}

ParseNode program_tree;
ParseNode * curnode;
ParseConfig parse_config;

void preorder(ParseNode * ptree) {
	using namespace std;
	ParseNode * p;
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
			for (int/*must be int, not size_t*/ i = p->child.size() - 1; i >= 0; i--)
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
		size_t pos = 0;
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

std::string compose_marker(std::string cont, int place, int end) {
	using namespace std;
	string ret = "\n";
	auto len = cont.size();
	int i;
	for (i = 0; i < len; i++)
	{
		if (i >= place - 1) {
			break;
		}
		if (cont[i] == '\t') {
			ret += "\t";
		}
		else if (cont[i] == '\n') {
			ret += "  ";
		}
		else {
			ret += " ";
		}
	}
	ret += "^";
	if (place < end) {
		for (i = place; i < len; i++) {
			if (i >= end - 1) {
				break;
			}
			if (cont[i] == '\t') {
				ret += "\t";
			}
			else if (cont[i] == '\n') {
				ret += "  ";
			}
			else {
				ret += " ";
			}
		}
	}
	ret += "$";
	ret += "\n";
	return ret;
}

void print_error(const std::string & error_info, const ParseNode & yylval) {
	using namespace std;
	printf("\nError : %s\n", error_info.c_str());
	printf("(line %d:%d, index = %d, len = %d), current token is %s(id = %d) : \"%s\" \n"
		, get_flex_state().parse_line + 1, get_flex_state().line_pos, get_flex_state().parse_pos, get_flex_state().parse_len
		, get_intent_name(yylval.fs.CurrentTerm.token).c_str(), yylval.fs.CurrentTerm.token, yylval.fs.CurrentTerm.what.c_str());
	char buf[255];
	const int length = 20; // print `length * 2 + len(parse_len)` context characters if possible
	int left = max(0, get_flex_state().parse_pos - get_flex_state().parse_len - length); // left-most character index
	int left_indent = get_flex_state().parse_pos - get_flex_state().parse_len - left; // error start position
	int right = min((int)global_code.size(), get_flex_state().parse_pos + length); // right-most character index
	int right_length = right - get_flex_state().parse_pos;
	sprintf(buf, "%s", global_code.substr(left, left_indent + get_flex_state().parse_len + right_length).c_str());
	string cont = string(buf);
	string marker = compose_marker(cont, left_indent, left_indent + get_flex_state().parse_len);
	replace_all_distinct(cont, "\n", "\\n");
	cont += marker;
	printf("%s", cont.c_str());
}

void print_error(const std::string & error_info) {
	using namespace std;
	printf("\nError : %s\n", error_info.c_str());
}

