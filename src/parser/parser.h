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
	T & get() {
		return value;
	}
	const T & get() const {
		return value;
	}
	const T & const_get() const {
		return value;
	}
private:
	T value;
	bool changed = false;
};



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
	void setattr(struct ParseAttr * pa);
	const std::string & to_string() const { return fs.CurrentTerm.what; }
	int length() const { return (int)child.size(); }
	TokenMeta_T & get_token() { return this->fs.CurrentTerm.token; }
	const TokenMeta_T & get_token() const { return this->fs.CurrentTerm.token; }
	std::string & get_what() { return this->fs.CurrentTerm.what; }
	const std::string & get_what() const { return this->fs.CurrentTerm.what; }
	std::vector<ParseNode *>::iterator begin() { return child.begin(); }
	std::vector<ParseNode *>::iterator end() { return child.end(); }
	std::vector<ParseNode *>::const_iterator begin() const { return child.begin(); }
	std::vector<ParseNode *>::const_iterator end() const  { return child.end(); }

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : attr(nullptr), father(nullptr) {};
	ParseNode(const FlexState & s, ParseNode * fa, struct ParseAttr * att = nullptr) : father(fa), attr(att), fs(s) {}
	~ParseNode();
};


int parse(std::string code);
void preorder(ParseNode * ptree);
FlexState & get_flex_state();
void print_error(const std::string & error_info, const ParseNode & node);
void print_error(const std::string & error_info);
void fatal_error(const std::string & error_info, const ParseNode & node);
void fatal_error(const std::string & error_info);

// yacc part code
// implement in for90.y
#define USE_TRIVIAL
#ifdef USE_TRIVIAL

#define YYSTYPE ParseNode*
#define RETURN_NT(X) new ParseNode(X)
inline ParseNode & YY2ARG(YYSTYPE X) {
	if (X == nullptr)
	{
		fatal_error("null ParseNode during parsing");
	}
	else {
		return *X;
	}
}
/***************
* this macro is error
// TODO why?
// #define (X == nullptr? ParseNode(): *X)
***************/
#define ARG_IN const ParseNode &
#define ARG_OUT ParseNode &
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE & x, Args&& ... args) {
	delete x;
	x = nullptr;
	CLEAN_RIGHT(std::forward<Args>(args)...);
}
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE & x) {
	delete x;
	x = nullptr;
}

#else

#define YYSTYPE ParseNode
#define RETURN_NT(X) X
#define YY2ARG(X) X
#define ARG_IN const ParseNode &
#define ARG_OUT ParseNode &
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE x, Args&& ... args) {
	// do nothing
}
template <typename ... Args>
void CLEAN_RIGHT(YYSTYPE x) {
	// do nothing
}
#endif

std::string tabber(const std::string &, bool tail_crlf = true); // add tab(`\t`) into the front of each line
ParseNode flattern_bin(ARG_IN pn, bool recursion_direction_right);// eliminate left/right recursion of an binary tree
void flattern_bin_inplace(ParseNode & pn, bool recursion_direction_right); // eliminate left/right recursion of an binary tree in place


/***************
* by testing 
* a 202kb code file will cause `sprintf` erase data elsewhere(when `MAX_CODE_LENGTH` is 32767)
* `MAX_CODE_LENGTH` should be enough
***************/
#define MAX_CODE_LENGTH 262143

struct ParseConfig {
	bool for90 = true;
	bool isdebug = false;
	bool hasfile = false;
	bool usefor = true;
	bool usefarray = true;
};


#ifdef _DEBUG
#define WHENDEBUG(THEN, ELSE) THEN
#else
#define WHENDEBUG(THEN, ELSE) ELSE
#endif // _DEBUG
