#pragma once
#include "parser.h"
#include <stack>
#include <map>
#include <string>

// const map has no operator[]
const std::map<std::string, std::string> typename_map{
	{"integer", "int"}
	,{"logical", "bool"}
	,{"character", "string"}
	,{ "real", "double" }
};

/* NOTICE: `typename_map` has already do some job for `funcname_map` */
const std::map<std::string, std::string> funcname_map{
	{ "real", "int" }
};

const std::string cpp_header = "#include\"for90std.h\"";

std::string for2cpp(std::string for_code); 
