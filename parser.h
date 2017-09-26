#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "tokenizer.h"
#include <boost/optional/optional.hpp>

// �ڳ�ʼ��֮���Ƿ�ֵ�Ƿ��޸�
template<class T>
struct dirty {
	operator T() const {
		return value;
	}
	T & operator= (const T & newv) {
		changed = true;
		value = newv;
		return value;
	}
	dirty(const T & newv) {
		// constructor by T
		changed = false;
		value = newv;
	}
	dirty(const dirty<T> & d) {
		// copy constructor
		changed = false;
		changed = d.isdirty();
		value = d;
	}
	bool isdirty() const {
		return changed;
	}
	T get() {
		return value;
	}
	const T & const_get() const {
		return value;
	}
private:
	T value;
	bool changed = false;
};

// ������
struct ParseNode {
	FlexState fs;
	std::vector<ParseNode *> child;
	struct ParseNode * father;
	/*
	�����ս��: cpp-stylish
	���ڷ��ս��: ��ǰ���ս�����﷨������cpp code
	*/
	struct ParseAttr * attr = nullptr;

	void addchild(ParseNode * ptrn, bool add_back = true);
	void addchild(const ParseNode & n, bool add_back = true);
	template <typename ... Args>
	void addlist(const ParseNode & x, Args ... args) {
		addchild(new ParseNode(x));
		addlist(std::forward<Args...>(args...));
	}
	template <typename ... Args>
	void addlist(const ParseNode & x) {
		addchild(new ParseNode(x));
	}
	void replace(int childid, const ParseNode & pn);

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : father(nullptr), attr(nullptr) {}
	ParseNode(const FlexState & s, ParseNode * fa, ParseAttr * att = nullptr) : father(fa), attr(att), fs(s) {}
	virtual ~ParseNode();
};



int parse(std::string code);
void preorder(ParseNode * ptree);
/* generate codes instead of in .y files */
std::string lazy_gen(ParseNode * ptree);
FlexState & get_flex_state();
void print_error(const std::string & error_info, const ParseNode & pn);
void print_error(const std::string & error_info);

// yacc part code
// implement in for90.y
typedef ParseNode yystype_t;
#define YYSTYPE ParseNode

/* update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) */
void update_pos(YYSTYPE & current);
void update_pos(YYSTYPE & current, YYSTYPE & start, YYSTYPE & end);
std::string tabber(std::string &); // add tab(`\t`) into the front of each line
ParseNode * flattern_bin(ParseNode *); // eliminate right recursion of an binary tree

/* lazygen */

#define MAX_CODE_LENGTH 32767

struct ParseConfig {
	bool for90 = true;
	bool isdebug = false;
	bool hasfile = false;
	bool usefor = true;
	bool usefarray = true;
};
