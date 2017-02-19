#pragma once
#include "parser.h"
#include "Function.h"
#include "Variable.h"


// ÊôÐÔÎÄ·¨
struct ParseAttr {
	ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(const ParseAttr & pa) = default; // do not call `clone()` in copy constructor else will cause stackoverflow
	virtual ParseAttr * clone() = 0; /* use clone because copy-constructor can not be virtual */
	virtual ~ParseAttr() = default;
	// virtual ParseAttr * merge() = 0;

};

struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr() : ParseAttr() {}
	TypeAttr(const TypeAttr & ta) {
		this->name = ta.name;
	}
	ParseAttr * clone() { return new TypeAttr(*this); }
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
};