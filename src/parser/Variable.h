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
#include <boost/optional/optional.hpp>

#define _BOOST_VERSION_MAJOR_ (BOOST_VERSION / 100000)
#define _BOOST_VERSION_MINOR_ (BOOST_VERSION / 100 % 10000)

#if (_BOOST_VERSION_MAJOR_ < 1 && _BOOST_VERSION_MINOR_ <= 55) || defined(BOOST_NO_CXX11_REF_QUALIFIERS)
#define _value_or get_value_or
#else
#define _value_or value_or
#endif 


// checks whether value is modified after initialization
template<class T>
struct dirty {
	operator T() const {
		return value;
	}
	T & operator= (const T & newv) {
		changed = true;
		value = newv;
		return value;
	}
	dirty(const boost::none_t &) {
		changed = false;
	}
	dirty(const T & newv) {
		// constructor by T
		changed = false;
		value = newv;
	}
	dirty(const dirty<T> & d) {
		// copy constructor
		changed = false;
		changed = d.isdirty();
		value = d;
	}
	bool isdirty() const {
		return changed;
	}
	T & get() {
		return value;
	}
	const T & get() const {
		return value;
	}
	const T & const_get() const {
		return value;
	}
private:
	T value;
	bool changed = false;
};

struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> inout_reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	boost::optional<ParseNode> slice = boost::none;
	dirty<int> kind = 0;
	dirty<bool> save = false;
	dirty<bool> allocatable = false;
	dirty<bool> target = false;
	dirty<bool> pointer = false;
	void merge(const VariableDesc & x2) {
		if (!reference.isdirty() && x2.reference.isdirty()) {
			reference = x2.reference;
		}
		if (!inout_reference.isdirty() && x2.inout_reference.isdirty()) {
			inout_reference = x2.inout_reference;
		}
		if (!constant.isdirty() && x2.constant.isdirty()) {
			constant = x2.constant;
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
		, boost::optional<int> kind, boost::optional<bool> save, boost::optional<bool> allocatable, boost::optional<bool> target
		, boost::optional<bool> pointer, boost::optional<bool> inout_reference) {
		if (reference.is_initialized())
			this->reference = reference._value_or(this->reference);
		if (inout_reference.is_initialized())
			this->inout_reference = inout_reference._value_or(this->inout_reference);
		if (constant.is_initialized())
			this->constant = constant._value_or(this->constant);
		if (optional.is_initialized())
			this->optional = optional._value_or(this->optional);
		if (slice.is_initialized())
			this->slice = slice;
		if (kind.is_initialized())
			this->kind = kind._value_or(this->kind);
		if (save.is_initialized())
			this->save = save._value_or(this->save);
		if (allocatable.is_initialized())
			this->allocatable = allocatable._value_or(this->allocatable);
		if (target.is_initialized())
			this->target = target._value_or(this->target);
		if (pointer.is_initialized())
			this->pointer = pointer._value_or(this->pointer);
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
	*	this flag is intended to replace the `NT_DECLAREDVARIABLE` token.
	*	if `flag` is true, this variable is declared in parameter list,
	*	so don't need to generate repeated code in function body
	* ALSO REFER `NT_DECLAREDVARIABLE` in Function.h
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
		: local_name(""), vardef_node(nullptr), declared(false), generated(false), commonblock_name(""), commonblock_index(0), implicit_defined(true) {

	}

	~VariableInfo() {
		//delete vardef_node;
	}
};

struct CommonBlockInfo {
	std::string common_name;
	std::vector<VariableInfo *> variables;
	bool elsewhere_decl = false;
	CommonBlockInfo() {

	}
	CommonBlockInfo(std::string name) : common_name(name) {

	}
	CommonBlockInfo(std::string name, const std::vector<VariableInfo *> & vars) : common_name(name), variables(vars) {

	}
	~CommonBlockInfo() {
		// do not delete variables
		// they are observer pointers to get_context.variables
	}
};

VariableInfo * get_variable(std::string module_name, std::string function_name, std::string variable_name);
VariableInfo * add_variable(std::string module_name, std::string function_name, std::string variable_name, const VariableInfo & variable);
VariableInfo * redirect_variable(std::string module_name, std::string function_name, std::string variable_name, VariableInfo * dest_vinfo);
void delete_variable(std::string module_name, std::string function_name, std::string variable_name);
void forall_variable_in_function(std::string module_name, std::string function_name, std::function<void(std::pair<std::string, VariableInfo *>)> func);
void clear_variables();
