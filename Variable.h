#pragma once
#include "parser.h"

struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	boost::optional<ParseNode> slice = boost::none;
	dirty<int> kind = 0;
	dirty<bool> save = false;
	void merge(const VariableDesc & x2) {
		if (!constant.isdirty() && x2.constant.isdirty()) {
			constant = x2.constant;
		}
		if (!reference.isdirty() && x2.reference.isdirty()) {
			reference = x2.reference;
		}
		if (!optional.isdirty() && x2.optional.isdirty()) {
			optional = x2.optional;
		}
		if (!slice.is_initialized() && x2.slice.is_initialized()) {
			slice = x2.slice;
		}
		if (!kind.isdirty() && x2.kind.isdirty()) {
			kind = x2.kind;
		}
		if (!save.isdirty() && x2.save.isdirty()) {
			save = x2.save;
		}
	}

	VariableDesc() {

	}
	VariableDesc(boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<ParseNode> slice, boost::optional<int> kind, boost::optional<bool> save) {
		if (reference.is_initialized())
			this->reference = reference.value();
		if (constant.is_initialized())
			this->constant = constant.value();
		if (optional.is_initialized())
			this->optional = optional.value();
		if (slice.is_initialized())
			this->slice = slice.value();
		if (kind.is_initialized())
			this->kind = kind.value();
		if (save.is_initialized())
			this->save = save.value();
	}
};

struct VariableInfo
{
	bool is_array() {
		return desc.slice.is_initialized();
	}
	std::string type;
	VariableDesc desc;
	ParseNode entity_variable; // TokenMeta::NT_VARIABLEINITIALDUMMY if no initial
	std::string commonblock_name; 
	int commonblock_index = 0;
	bool implicit_defined = false; // no use
	VariableInfo(std::string typestr, const VariableDesc & vdesc, const ParseNode & variable_initial_node) 
		: type(typestr) , desc(vdesc), entity_variable(variable_initial_node), implicit_defined(false), commonblock_index(0){

	}
};

struct CommonBlockInfo {
	std::string common_name;
	std::vector<VariableInfo> variables;
};

VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name);
VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable);
void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(const std::pair<std::string, VariableInfo *> &)> func);
void clear_variables();
void insert_temporary_variables(std::string module_name, std::string function_name);
