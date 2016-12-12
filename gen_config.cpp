#include "gen_config.h"

std::map<std::string, std::vector<std::pair<std::string, std::string>>> func_kwargs{
	{ "open",{ { "unit", "int" }, { "file", "string" }, { "access", "string" }, { "action", "string" }, {"status", "string"}, { "iostat", "int" } } }
	,{ "close",{ { "unit", "int" }, { "status", "string" }, { "iostat", "int" } } }
	,{ "read",{ { "unit", "int" }, { "fmt", "string" },{ "iostat", "int" } } }
};