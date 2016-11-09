#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tokenizer.h"
#include "Variable.h"

// 分析树
struct ParseNode {
	struct ParseNode * father;
	
	std::vector<ParseNode *> child;
	FlexState fs; 
	/*
	对于终结符: cpp-stylish
	对于非终结符: 当前非终结符的语法子树的cpp code
	*/
	struct ParseAttr * attr = nullptr;

	void addchild(ParseNode * ptrn, bool add_back = true);

	ParseNode(const ParseNode &);
	ParseNode & operator= (const ParseNode &) ;
	ParseNode() : father(nullptr), attr(nullptr) {}
	ParseNode(const FlexState & s, ParseNode * fa, ParseAttr * att = nullptr) : father(fa), attr(att), fs(s) {}
	virtual ~ParseNode();
};


int parse(std::string code);
extern ParseNode program_tree;
extern std::string global_code;
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

#define MAX_CODE_LENGTH 65535