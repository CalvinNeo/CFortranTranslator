#pragma once
#include "parser.h"
#include <stack>
#include <map>
#include <string>
#include <vector>

// const map has no operator[]
const std::map<std::string, std::string> pre_map{
	{ "integer", "int" }
	,{ "logical", "bool" }
	,{ "character", "string" }
	,{ "real", "double" }
	,{ "complex", "forcomplex" }
	, { "cycle", "continue" }
	, { "exit", "break" }
};

/* NOTICE: `pre_map` has already do previous job for `funcname_map` */
const std::map<std::string, std::string> funcname_map{
	// math
	{ "min", "min_n" }
	, { "max", "max_n" }

	// type
	, {"int", "to_int"}
	, { "bool", "to_bool" }
	, { "string", "to_string" }
	, { "double", "to_double" }
	, { "forcomplex", "forcomplex" }

	// array

	// intrinsic
	,{ "present", "forpresent" }
};


// system left value
const std::vector<std::string> intrinsic_lvalue{
	"iostat"
};

// in gen_config.cpp
extern std::map<std::string, std::vector<std::pair<std::string, std::string>>> func_kwargs;

const std::string cpp_header = "#include\"for90std.h\" \n";



