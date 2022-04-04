/*
*/

#include "Type.h"
#include "tokenizer.h"
#include "../parser/context.h"
#include <boost/algorithm/string/predicate.hpp>

TypeInfo * get_type(std::string module_name, std::string type_name) {

	std::string fullname = module_name + "::" + type_name;
	if (get_context().types.find(fullname) != get_context().types.end()) {
		return get_context().types[fullname];
	}
	else {
		return nullptr;
	}
}

TypeInfo * add_type(std::string module_name, std::string type_name, const TypeInfo & func) {
	TypeInfo * tinfo = new TypeInfo(func);

	std::string fullname = module_name + "::" + type_name;
	if (get_context().types.find(fullname) != get_context().types.end()) {
		fatal_error("type name conflict");
		return nullptr;
	}
	else {
		get_context().types[fullname] = tinfo;
	}
	tinfo->local_name = type_name;
	return tinfo;
}


void forall_type_in_module(std::string module_name, std::function<void(std::pair<std::string, TypeInfo *>)> func) {
	for(std::map <std::string, TypeInfo *>::value_type & pr : get_context().types)
	{
		if (boost::starts_with(pr.first, module_name + "::"))
		{
			func(pr);
		}
	}
}

void clear_types() {
	for(std::map <std::string, TypeInfo *>::value_type & pr : get_context().types)
	{
		delete pr.second;
	}
	get_context().types.clear();
}