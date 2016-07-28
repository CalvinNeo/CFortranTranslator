#include "tokenizer.h"
#include <string>

using namespace std;
Term make_term(const TokenMeta & token, string w) {
	return Term{ token, w };
}
Term make_term(const TokenMeta & token, const char * w) {
	return Term{ token, string(w) };
}