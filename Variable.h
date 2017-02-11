#pragma once
#include <string>
#include <vector>
#include "parser.h"

struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	dirty<struct ParseNode *> slice = nullptr;
	dirty<int> kind = 0;
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
		if (!slice.isdirty() && x2.slice.isdirty()) {
			slice = x2.slice;
		}
		if (!kind.isdirty() && x2.kind.isdirty()) {
			kind = x2.kind;
		}
	}

	VariableDesc() {

	}
	VariableDesc(boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<struct ParseNode *> slice, boost::optional<int> kind) {
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
	}
};

struct VariableInfo
{
	bool is_array() {
		return desc.slice != nullptr;
	}
	std::string type;
	VariableDesc desc;
	VariableInfo(std::string typestr, const VariableDesc vdesc) : type(typestr) , desc(vdesc){

	}
};

VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name);
VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable);
void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(const std::pair<std::string, VariableInfo *> &)> func);
void clear_variables();
