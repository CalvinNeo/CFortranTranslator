#pragma once
#include <string>
#include <vector>
#include "tokenizer.h"

int parse(std::string code);

// ”Ô“Â
struct ParseNode {
	struct ParseNode * father;
	std::vector<ParseNode *> child;
	FlexState fs;

	ParseNode(const ParseNode &) = default;
	ParseNode() = default;
	~ParseNode();
};

extern ParseNode program_tree;
extern ParseNode * curnode;

void preoder(ParseNode * ptree);

// yacc part code
// implement in for90.y
typedef ParseNode  yystype_t;
#define YYSTYPE ParseNode