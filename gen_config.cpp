#include "gen_config.h"

std::map<std::string, std::map<std::string, std::string>> func_kwargs{
	{ "open",{ { "file", "string" }, {"unit", "int"}, {"status", "string"}, {"action", "string"}, { "iostat", "int" } } }
	,{ "close",{ { "unit", "int" },{ "status", "string" }, { "iostat", "int" } } }
	,{ "read",{ { "unit", "int" },{ "fmt", "string" },{ "iostat", "int" } } }
};