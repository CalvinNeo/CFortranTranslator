/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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

const std::map<std::string, std::vector<KeywordParamInfo>> func_kwargs_preset{
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



