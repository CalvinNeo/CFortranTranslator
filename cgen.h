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