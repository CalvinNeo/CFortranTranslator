#pragma once
#include "parser.h"
#include <stack>
#include <map>
#include <string>

// const map has no operator[]
const std::map<std::string, std::string> typename_map{
	{"integer", "int"}
	, {"logical", "bool"}
	, {"character", "string"}
	, { "real", "double" }
	, { "complex", "forcomplex" }
};

/* NOTICE: `typename_map` has already do previous job for `funcname_map` */
const std::map<std::string, std::string> funcname_map{
	{ "min", "min_n" }
	, { "max", "max_n" }
	, {"int", "to_int"}
	, { "bool", "to_bool" }
	, { "string", "to_string" }
	, { "double", "to_double" }
	, { "forcomplex", "forcomplex" }
};

const std::string cpp_header = "#include\"for90std.h\"";

std::string for2cpp(std::string for_code); 

// utility
std::string parse_ioformatter(const std::string &);
