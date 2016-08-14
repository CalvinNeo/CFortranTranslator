#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include "tokenizer.h"
#include "Variable.h"

int parse(std::string code);

// 语义
struct ParseNode {
	struct ParseNode * father;
	
	std::vector<ParseNode *> child;
	FlexState fs; 
	/*
	对于终结符: cpp-stylish
	对于非终结符: 当前非终结符的语法子树的cpp code
	*/
	struct ParseAttr * attr;

	void addchild(ParseNode * ptrn, bool add_back = true);

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : father(nullptr), attr(nullptr) {}
	ParseNode(const FlexState & s, ParseNode * fa, ParseAttr * att = nullptr) : father(fa), attr(att), fs(s) {}
	virtual ~ParseNode();
};

// 属性文法
struct ParseAttr {
	ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(ParseNode * parsenode) : parsenode(parsenode) {}
	ParseAttr(const ParseAttr & pa) = default;
	virtual ParseAttr * clone() = 0;

	virtual void parse() = 0; // parse according to parsenode
};

struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	TypeAttr(const TypeAttr & ta) {
		clone();
	}
	ParseAttr * clone() { return new TypeAttr(*this); }

	void parse();
};
struct VariableAttr : public ParseAttr {
	Variable * variable;

	VariableAttr(ParseNode * parsenode, Variable * v) : ParseAttr(parsenode), variable(v){}
	VariableAttr(const VariableAttr & va) {
		clone();
	}
	ParseAttr * clone() { return new VariableAttr(*this); }

	void parse();
};
// struct ArrayAttr FormatterAttr

extern ParseNode program_tree;

void preorder(ParseNode * ptree);
/* generate codes instead of in .y files */
std::string lazy_gen(ParseNode * ptree);


// yacc part code
// implement in for90.y
typedef ParseNode yystype_t;
#define YYSTYPE ParseNode

/* update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) */
void update_pos(YYSTYPE &);