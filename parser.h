#pragma once
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "tokenizer.h"

int parse(std::string code);

// 语义
struct ParseNode {
	struct ParseNode * father;
	
	std::vector<ParseNode *> child;
	FlexState fs;
	struct ParseAttr * attr;

	void addchild(ParseNode * ptrn);

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() = default;
	~ParseNode();
};

// 属性文法
struct ParseAttr {
	ParseNode * parsenode; // observer ptr
	virtual void parse() = 0; // parse according to parsenode

	ParseAttr() = default;
	ParseAttr(ParseNode * parsenode) : parsenode(parsenode) {}
	ParseAttr(const ParseAttr & pa) = default;
};
struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	TypeAttr(const TypeAttr & ta) = default;

	void parse();
};
struct VariableAttr : public ParseAttr {
	std::string name;
	std::string initial; // 初值仍是string
	struct TypeAttr * typeattr; // observer ptr

	VariableAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	VariableAttr(const VariableAttr & va) = default;

	void parse();
};
// struct ArrayAttr FormatterAttr

extern ParseNode program_tree;
extern ParseNode * curnode;

void preoder(ParseNode * ptree);

// yacc part code
// implement in for90.y
typedef ParseNode yystype_t;
#define YYSTYPE ParseNode