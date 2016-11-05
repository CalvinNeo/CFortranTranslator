#include "tokenizer.h"
#include "attribute.h"
#include "parser.h"
#include "gen_config.h"
#include "Function.h"
#include "codegen.h"
#include <vector>
#include <string>

using namespace std;

// static is necessary, or will cause
static char codegen_buf[MAX_CODE_LENGTH]; 
