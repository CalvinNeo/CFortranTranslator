#pragma once
#include <string>
#include <map>
#include <vector>
#include "Intent.h"


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
	// ´Ê·¨·ÖÎö
	Term CurrentTerm;
	int parse_pos = 0;
	int parse_line = 0;
	int parse_len = 0;
	int line_pos = 0;
	bool isnull = false;
};

FlexState & get_flex_state();
extern const std::vector<KeywordMeta> keywords;
extern const std::map<std::string, std::vector<std::string> > forward1;

// flex part code
FlexState next_token(const std::string & in_str, int start = 0); 
FlexState iter_token(const std::string & in_str, int start);
std::string CutString(std::string::iterator & b, std::string::iterator e, bool save, char jmp = ' ');


// for90.l
//void update_yylval(Term & current_term, bool empty);

