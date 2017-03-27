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
#include "attribute.h"
#include "tokenizer.h"
#include "gen_config.h"
#include "codegen.h"
#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <boost/algorithm/string.hpp>
#include <cmath>

void reset_parser() {
	get_context().func_kwargs = func_kwargs_preset;
	get_context().labels.clear();
	clear_variables();
}

void ParseNode::setattr(ParseAttr * pa) {
	delete this->attr;
	this->attr = pa;
	pa->parsenode = this;
}
ParseNode & ParseNode::get(int child_index) {
	return *(this->child[child_index]);
}
const ParseNode & ParseNode::get(int child_index) const {
	return *(const_cast<const ParseNode *>(this)->child[child_index]);
}
const ParseNode & ParseNode::const_get(int child_index) const {
	return *(const_cast<const ParseNode *>(this)->child[child_index]);
}
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
			this->addchild(pn.get(i));
		}
		else {
			this->addchildptr(nullptr);
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
		this->child.clear();

		this->fs = pn.fs;
		this->father = pn.father;
		this->attr = (pn.attr == nullptr ? nullptr : pn.attr->clone());
		for (int i = 0; i < pn.child.size(); i++)
		{
			this->addchild(pn.get(i));
		}

		return *this;
	}
}

void ParseNode::addchildptr(ParseNode * ptrn, bool add_back) {
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
	this->addchildptr(new ParseNode(n), add_back);
}

void ParseNode::replace(int childid, const ParseNode & pn) {
	delete this->child[childid];
	this->child[childid] = new ParseNode(pn);
}

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
	for (std::string::size_type pos = 0; pos != -1; pos += new_value.length())
		if ((pos = str.find(old_value, pos)) != -1)
			str.replace(pos, old_value.length(), new_value);
		else break;
		return str;
}

std::string compose_marker(std::string cont, int place, int end) {
	// used to mark error token
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
	const int extend_length = 20; // print `length * 2 + len(parse_len)` context characters if possible
	int error_start = get_flex_state().parse_pos - get_flex_state().parse_len;
	int error_end = get_flex_state().parse_pos;
	int error_len = get_flex_state().parse_len;
	int left = max(0, error_start - extend_length); // left-most character index
	int left_length = error_start - left; 
	int right = min((int)get_context().global_code.size(), error_end + extend_length); // right-most character index
	int right_length = right - error_end; 
	/********************************************************
	*...................XXXXXXXXXXXXXXXXXX....................
	*|l|				|err|
	*|e|				|or |
	*|f|				|sta|
	*|t|				|rt |
	*---------------------------------------------------------
	*     left length  |   error length   |   right length   |
	*********************************************************/
	sprintf(buf, "%s", get_context().global_code.substr(left, left_length + error_len + right_length).c_str());
	string cont = string(buf);
	string marker = compose_marker(cont, left_length, left_length + error_len);
	replace_all_distinct(cont, "\n", "\\n");
	cont += marker;
	printf("%s", cont.c_str());
}

void print_error(const std::string & error_info) {
	using namespace std;
	printf("\nError : %s\n", error_info.c_str());
}
void fatal_error(const std::string & error_info) {
	using namespace std;
}

