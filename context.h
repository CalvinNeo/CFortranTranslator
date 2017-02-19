#pragma once
#include <map>
#include "parser.h"
#include "Variable.h"
#include "Function.h"


struct TranslateContext {
	std::map<std::string, CommonBlockInfo> commonblocks;
	std::map<std::string, ParseNode> labels;
	std::map < std::string, VariableInfo * > variables;
	std::map < std::string, VariableInfo * > temporary_variables;
	std::map < std::string, FunctionInfo * > functions;
	std::map<std::string, std::vector<KeywordParamInfo>> func_kwargs;
	ParseNode program_tree;
	std::string global_code;
	ParseConfig parse_config;
	bool inited;
};


TranslateContext & get_context();
void reset_parser();