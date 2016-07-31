#pragma once
#include <string>
#include "intent.h"

typedef IntentMeta TokenMeta;
struct Term {
	//TokenMeta token;
	int token;
	std::string what;
};


#define USE_YACC

#ifdef USE_YACC
#else
//// flex part code
//// implement in for90.l
//int make_term_flex(const TokenMeta & token, const char * w);
#endif
struct FlexState {
	Term CurrentTerm;
	int parse_pos;
	int parse_line;
	int parse_len;
	int line_pos;
	bool isnull = false;
};
FlexState next_token(const std::string & in_str, int start = 0); 
FlexState iter_token(const std::string & in_str, int start);

// yacc part code
// implement in for90.y
#define YYSTYPE FlexState
int parse(std::string code);