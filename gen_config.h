#pragma once
#include "parser.h"
#include <stack>
#include <map>
#include <string>
#include <vector>
#include "context.h"

#define UBOUND_DELTA "1"

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
	,{ "reshape", "forreshape" }
	,{ "sum", "forsum" }
	,{ "product", "forproduct" }
	,{ "size", "forsize" }
	,{ "shape", "forshape" }
	,{ "lbound", "forlbound" }
	,{ "ubound", "forubound" }
	,{ "maxloc", "formaxloc" }
	,{ "minloc", "forminloc" }
	,{ "maxval", "formaxval" }
	,{ "minval", "forminval" }

	// file
	,{ "open", "foropenfile" }
	,{ "close", "forclosefile" }
	// io
	,{ "read", "forread" }
	,{ "print", "forprint" }
	,{ "write", "forwrite" }

	// intrinsic
	,{ "present", "forpresent" }
};

const std::map<std::string, std::vector<keyword_param_info>> func_kwargs_preset{
	{ "foropenfile",{ { "unit", "int", "" },{ "file", "string", "" },{ "access", "string", "" },{ "action", "string" , "" },{ "status", "string", "" },{ "iostat", "int", "" }, {"form", "string", ""} } }
	,{ "forclosefile",{ { "unit", "int", "" },{ "status", "string", "" },{ "iostat", "int", "" } } }
	,{ "forread",{ { "unit", "int" , "" },{ "fmt", "string", "" },{ "iostat", "int", "" } } }

	,{ "forsum",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	,{ "forproduct",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	,{ "formaxval",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	,{ "forminval",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	,{ "formaxloc",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	,{ "forminloc",{ { "dim", "int", "" },{ "mask", "mask_wrapper_t", "" } } }
	//,{ "forsize", { { "dim", "int", "" } } }
	//,{ "forlbound",{ { "dim", "int", "" } } }
	//,{ "forubound",{ { "dim", "int", "" } } }
};


const std::string cpp_header = "#include\"for90std.h\" \n";



