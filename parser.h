#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "tokenizer.h"
#include <boost/optional/optional.hpp>

// 在初始化之后是否值是否被修改
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
	dirty(const boost::none_t &) {
		changed = false;
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



// 分析树
struct ParseNode {
	FlexState fs;
	std::vector<ParseNode *> child;
	struct ParseNode * father;
	struct ParseAttr * attr = nullptr;

	void addchildptr(ParseNode * ptrn, bool add_back = true);
	void addchild(const ParseNode & n, bool add_back = true);

	template <typename ... Args>
	void addlist(const ParseNode & x, Args&& ... args) {
		addchild(x);
		addlist(std::forward<Args>(args)...);
	}
	template <typename ... Args>
	void addlist(const ParseNode & x) {
		addchild(x);
	}
	void replace(int childid, const ParseNode & pn);
	ParseNode & get(int child_index);
	const ParseNode & get(int child_index) const;
	const ParseNode & const_get(int child_index) const;
	void setattr(ParseAttr * pa);
	std::string to_string() const { return fs.CurrentTerm.what; }

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : attr(nullptr), father(nullptr) {};
	ParseNode(const FlexState & s, ParseNode * fa, ParseAttr * att = nullptr) : father(fa), attr(att), fs(s) {}
	~ParseNode();
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
#define YYSTYPE ParseNode*
#define RETURN_NT(X) new ParseNode(X)
#define YY2ARG(X) (X == nullptr? ParseNode(): *X)
#define ARG_IN const ParseNode &
#define ARG_OUT ParseNode &
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE x, Args&& ... args) {
	delete x;
	//x = nullptr;
	CLEAN_RIGHT(std::forward<Args>(args)...);
}
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE x) {
	delete x;
	//x = nullptr;
}
//#define RETURN_NT(X) X
//#define YY2ARG(X) X

std::string tabber(const std::string &); // add tab(`\t`) into the front of each line
ParseNode flattern_bin(ARG_IN pn, bool recursion_direction_right);// eliminate left/right recursion of an binary tree
void flattern_bin_inplace(ParseNode & pn, bool recursion_direction_right); // eliminate left/right recursion of an binary tree in place

/* lazygen */

#define MAX_CODE_LENGTH 32767

struct ParseConfig {
	bool for90 = true;
	bool isdebug = false;
	bool hasfile = false;
	bool usefor = true;
	bool usefarray = true;
};
