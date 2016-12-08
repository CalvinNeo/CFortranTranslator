#include "tokenizer.h"
#include "attribute.h"
#include "parser.h"
#include "gen_config.h"
#include "Function.h"
#include "codegen.h"
#include <vector>
#include <string>

using namespace std;

// use static instead of extern will make build fast
#ifdef _DEBUG
static char codegen_buf[MAX_CODE_LENGTH]; 
#else
extern char codegen_buf[MAX_CODE_LENGTH];
#endif
