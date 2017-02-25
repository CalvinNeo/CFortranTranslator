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
#include "Function.h"
#include "Variable.h"

// ÊôÐÔÎÄ·¨
struct ParseAttr {
	struct ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(const ParseAttr & pa) = default; // do not call `clone()` in copy constructor else will cause stackoverflow
	virtual ParseAttr * clone() = 0; /* use clone because copy-constructor can not be virtual */
	virtual ~ParseAttr() {};
	// virtual ParseAttr * merge() = 0;
};

struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr() : ParseAttr() {}
	TypeAttr(const TypeAttr & ta) {
		this->name = ta.name;
	}
	ParseAttr * clone() { return new TypeAttr(*this); }
	~TypeAttr() {
	}
	// void merge(const VariableDescAttr & pa) {  }
};

struct VariableAttr : public ParseAttr {
	VariableInfo * vinfoptr = nullptr;

	VariableAttr(VariableInfo * vptr) : ParseAttr(), vinfoptr(vptr) {}
	VariableAttr(const VariableAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		// do NOT copy vinfoptr because vinfoptr pointer to VariableInfo in get_context()
		this->vinfoptr = va.vinfoptr;
	}
	ParseAttr * clone() { return new VariableAttr(*this); }
	~VariableAttr() {
	}
};

struct VariableDescAttr : public ParseAttr {
	//5.1.2 Attributes
	//	The additional attributes that may appear in the attribute specification of a type declaration statement further
	//	specify the nature of the entities being declared or specify restrictions on their use in the program.
	VariableDesc desc;

	VariableDescAttr() : ParseAttr() {}
	VariableDescAttr(const VariableDescAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		this->desc = va.desc;
	}
	ParseAttr * clone() { return new VariableDescAttr(*this); }

	void merge(const VariableDescAttr & x2) {
		desc.merge(x2.desc);
	}
	~VariableDescAttr() {
	}
};

struct FunctionAttr : public ParseAttr {
	FunctionInfo * finfoptr;
	FunctionAttr(FunctionInfo * fptr) : ParseAttr(), finfoptr(fptr) {}
	FunctionAttr(const FunctionAttr & fa) {
		// do not call `clone()` else will cause stackoverflow
		this->finfoptr = fa.finfoptr;
	}
	ParseAttr * clone() { return new FunctionAttr(*this); }

	void merge(const FunctionAttr & x2) {

	}
	~FunctionAttr() {
	}
};