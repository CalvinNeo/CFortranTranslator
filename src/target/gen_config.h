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
#include "../parser/context.h"
#include <stack>
#include <map>
#include <string>
#include <vector>

#define UBOUND_DELTA 1
#define UBOUND_DELTA_STR "1"

// const map has no operator[]
const std::map<std::string, std::string> pre_map{
	{ "integer", "int" }
	, { "logical", "bool" }
	, { "character", "string" }
	, { "real", "double" }
	, { "double", "double" }
	, { "doubleprecision", "double" }
	, { "complex", "forcomplex" }
	, { "cycle", "continue" }
	, { "exit", "break" }
	, { "null()", "null" }
};

// NOTICE: `pre_map` has already do previous job for `funcname_map`
const std::map<std::string, std::string> funcname_map{
	// math
	{ "min", "min_n" }
	, { "max", "max_n" }
	,{ "amin0", "min_n" }
	,{ "amin1", "min_n" }
	,{ "amax0", "max_n" }
	,{ "amax1", "max_n" }

	,{ "alog10", "log10" }
	,{ "alog", "log" }


	// cast
	, {"int", "to_int"}
	, { "bool", "to_bool" }
	, { "char", "to_string" }
	, { "float", "to_double" }
	, { "doubleprecision", "to_double" }
	, { "forcomplex", "to_forcomplex" }

	// array
	, { "reshape", "forreshape" }
	, { "sum", "forsum" }
	, { "product", "forproduct" }
	, { "size", "forsize" }
	, { "shape", "forshape" }
	, { "lbound", "forlbound" }
	, { "ubound", "forubound" }
	, { "maxloc", "formaxloc" }
	, { "minloc", "forminloc" }
	, { "maxval", "formaxval" }
	, { "minval", "forminval" }

	// file
	, { "open", "foropenfile" }
	, { "close", "forclosefile" }

	// io
	// read, write, print is specially handled in `gen_io.cpp`
	, { "rewind", "forrewind" }
	, { "backspace", "forbackspace" }


	// intrinsic
	, { "present", "forpresent" }
};

#define _WS(X) #X

const std::map<std::string, std::vector<KeywordParamInfo>> sysfunc_args = {
	{ "foropenfile", { { "unit", "int", "" }, { "iostat", "int", "" }, { "err", "forlabel", "" }, { "file", "string", "" }, { "status", "string", _WS("unkonwn") }
		, { "access", "string" , _WS("sequential") }, { "form", "string", "" }, { "recl", "int", "" }, { "blank", "string", "" }, { "position", "string", _WS("rewind") }
		, { "action", "string" , _WS("readwrite") }, { "delim", "string" , "" }, { "pad", "string" , "" } } }
	, { "forclosefile", { { "unit", "int", "" }, { "iostat", "int", "" }, { "err", "forlabel", "" } } }
	, { "forread", { { "unit", "int" , "" }, { "fmt", "string", "" }, { "iostat", "int", "" } } }
	, { "forwrite", { { "unit", "int" , "" }, { "fmt", "string", "" }, { "iostat", "int", "" } } }
	, { "forprint", { { "unit", "int" , "" }, { "fmt", "string", "" }, { "iostat", "int", "" } } }
	, { "forrewind", { { "unit", "int" , "" }, { "iostat", "int", "" }, { "err", "forlabel", "" } } }
	, { "forbackspace", { { "unit", "int" , "" }, { "iostat", "int", "" }, { "err", "forlabel", "" } } }

	,{ "forreshape",{ } }
	, { "forsum", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }
	, { "forproduct", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }
	, { "forsize", { { "dim", "int", "" } } }
	, { "forshape",{ } }
	, { "forlbound", { { "dim", "int", "" } } }
	, { "forubound", { { "dim", "int", "" } } }
	, { "formaxval", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }
	, { "forminval", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }
	, { "formaxloc", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }
	, { "forminloc", { { "dim", "int", "" }, { "mask", "mask_wrapper_t", "" } } }


	, { "abs", {  } }
	, { "acos", {  } }
	, { "asin", {} }
	, { "atan", {} }
	, { "cos", {} }
	, { "cosh", {} }
	, { "exp", {} }
	, { "log", {} }
	, { "log10", {} }
	, { "sin", {} }
	, { "sinh", {} }
	, { "sqrt", {} }
	, { "tan", {} }
	, { "tanh", {} }

	
	, { "min_n" ,{}}
	, { "max_n",{} }

	// cast
	, { "to_int",{} }
	, { "to_bool",{} }
	, { "to_string",{} }
	, { "to_double",{} }
	, { "to_forcomplex", {} }

};


const std::string cpp_header = "#include\"for90std.h\" \n";