#include "gen_config.h"

std::map<std::string, std::vector<keyword_param_info>> func_kwargs{
	{ "foropenfile",{ { "unit", "int", "" }, { "file", "string", "" }, { "access", "string", "" }, { "action", "string" , "" }, {"status", "string", "" }, { "iostat", "int", "" } } }
	,{ "forclosefile",{ { "unit", "int", "" }, { "status", "string", "" }, { "iostat", "int", "" } } }
	,{ "forread",{ { "unit", "int" , "" }, { "fmt", "string", "" }, { "iostat", "int", "" } } }

	,{ "forsum", { {"dim", "int", "" }, {"mask", "mask_wrapper<T>", "" } } }
	,{ "forproduct", { { "dim", "int", "" }, { "mask", "mask_wrapper<T>", "" } } }
	//,{ "forsize", { { "dim", "int", "" } } }
	//,{ "forlbound",{ { "dim", "int", "" } } }
	//,{ "forubound",{ { "dim", "int", "" } } }
};