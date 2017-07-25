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

struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	boost::optional<ParseNode> slice = boost::none;
	dirty<int> kind = 0;
	dirty<bool> save = false;
	dirty<bool> allocatable = false;
	dirty<bool> target = false;
	dirty<bool> pointer = false;
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
		if (!allocatable.isdirty() && x2.allocatable.isdirty()) {
			allocatable = x2.allocatable;
		}
		if (!target.isdirty() && x2.target.isdirty()) {
			target = x2.target;
		}
		if (!pointer.isdirty() && x2.pointer.isdirty()) {
			pointer = x2.pointer;
		}
	}

	VariableDesc() {

	}
	VariableDesc(boost::optional<bool> reference, boost::optional<bool> constant, boost::optional<bool> optional, boost::optional<ParseNode> slice
		, boost::optional<int> kind, boost::optional<bool> save, boost::optional<bool> allocatable, boost::optional<bool> target, boost::optional<bool> pointer) {
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
		if (allocatable.is_initialized())
			this->allocatable = allocatable.value();
		if (target.is_initialized())
			this->target = target.value();
		if (pointer.is_initialized())
			this->pointer = pointer.value();
	}
};

struct VariableInfo
{
	bool is_array() {
		// only array has slice info, or is allocatable
		return desc.slice.is_initialized() || desc.allocatable.get();
	}
	/******************
	*	name of this variable
	*******************/
	std::string local_name;
	/******************
	*	type of this variable
	*******************/
	ParseNode type;
	/******************
	*	VariableDesc
	*	describer, ref definition of VariableDesc
	*******************/
	VariableDesc desc;
	/******************
	*	a ParseNode of NT_VARIABLE_ENTITY
	*	restore initial value of this variable, NT_VARIABLEINITIALDUMMY if the variable has default initial value
	*******************/
	ParseNode entity_variable; 
	/******************
	*	pointer to a ParseNode of NT_VARIABLEDEFINE 
	*	vardef_node is nullptr iif this is neither examined as implicit variable by calling `check_implicit_variable`,
	*		nor declared explicitly by any statement. An Error May Occurrd under this circumstance
	*	WARNING:
	*	DO NOT USE `vardef_node == nullptr` to check if this variable is implicit or not, use `implicit_defined` instead
	*******************/
	ParseNode * vardef_node;
	/******************
	*	this flag is intended to replace the `NT_DECLAREDVARIABLE` token
	*	if `flag` is true, this variable is declared in parameter list
	*	so don't need to generate repeated code in function body
	* ALSO REFER `NT_DECLAREDVARIABLE` in FUnction.h
	*******************/
	bool declared;
	/******************
	*	true if `regen_vardef` is called towards this variable
	*******************/
	bool generated;

	/******************
	*	commonblock_name == "" if this variable is not in any `COMMON` block
	*******************/
	std::string commonblock_name; 
	int commonblock_index = 0;

	/******************
	*	this variable has no explicit declaration
	*******************/
	bool implicit_defined = true; 

	VariableInfo()
		: local_name(""), implicit_defined(true), commonblock_index(0), commonblock_name(""), vardef_node(nullptr), declared(false), generated(false) {

	}
};

struct CommonBlockInfo {
	std::string common_name;
	std::vector<VariableInfo> variables;
};

VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name);
VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable);
void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(std::pair<std::string, VariableInfo *>)> func);
void clear_variables();
