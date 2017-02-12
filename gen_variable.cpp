#include "gen_common.h"
#include <map>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>

// refer Variable.h
std::map<std::string, CommonBlockInfo> commonblocks;
//5.5.2 COMMON statement
//The COMMON statement specifies blocks of physical storage, called common blocks, that may be accessed by
//any of the scoping units in an executable program.Thus, the COMMON statement provides a global data facility
//based on storage association(14.6.3).The common blocks specified by the COMMON statement may be named
//and are called named common blocks, or may be unnamed and are called blank common.
void add_common(std::string common_name, const ParseNode & paramtable) {

}

void add_common_component() {

}

ParseNode gen_common(const ParseNode & common_block, const ParseNode & paramtable) {
	// the unique blank COMMON block must be declared in the main program.
	string common_name = common_block.fs.CurrentTerm.what;
	auto common_info = commonblocks.find(common_name);
	if (common_info == commonblocks.end()) {
		commonblocks[common_name] = CommonBlockInfo{ common_name, std::vector<VariableInfo>() };
		common_info = commonblocks.find(common_name);
	}
	auto range = boost::irange(0, (int)paramtable.child.size());
	std::string decl = make_str_list(range.begin(), range.end(), [&](auto x) {
		size_t i = (size_t)x;
		std::string local_varname = get_variable_name(paramtable.child[i]/* NT_EXPRESSION */->child[0]/* NT_VARIABLEINITIAL */);
		VariableInfo * local_vinfo = get_variable("@", "@", local_varname);
		if (local_vinfo == nullptr)
		{
			// if this common variable has no prev explicit declaration
			VariableDesc desc; 
			local_vinfo = add_variable("@", "@", local_varname
				, VariableInfo(implicit_type_from_name(local_varname).fs.CurrentTerm.what, desc
					, gen_token(Term{TokenMeta::NT_VARIABLEINITIALDUMMY, ""})));
		}
		VariableInfo global_vinfo(*local_vinfo);
		common_info->second.variables.push_back(global_vinfo);
		local_vinfo->desc.constant = false;
		local_vinfo->desc.reference = true;
		std::string common_varname = "_" + to_string(i + 1);
		sprintf(codegen_buf, "%s = %s.%s;", local_varname.c_str(), common_name.c_str(), common_varname.c_str());
		return string(codegen_buf);
	}, "\n");
	return gen_token(Term{ TokenMeta::NT_COMMONBLOCK, decl });
}

ParseNode gen_common_definition(std::string common_name) {
	auto common_info = commonblocks.find(common_name);
	if (common_info == commonblocks.end()) {
		print_error("Common block without definition");
	}
	int i = 0;
	string struct_str = make_str_list(common_info->second.variables.begin(), common_info->second.variables.end(), [&](const VariableInfo & x) {
		std::string common_varname = "_" + to_string(++i);
		sprintf(codegen_buf, "%s %s;", x.type.c_str(), common_varname.c_str());
		return string(codegen_buf);
	}, "\n");
	if (common_name == "")
	{
		sprintf(codegen_buf, "typedef struct{\n%s\n}G;\n", tabber(struct_str).c_str());
	}
	else {
		sprintf(codegen_buf, "typedef struct{\n%s\n}%s;\n", tabber(struct_str).c_str(), common_name.c_str());
	}
	return gen_token(Term{ TokenMeta::NT_COMMONBLOCKDEFINE, string(codegen_buf) });
}