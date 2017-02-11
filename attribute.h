#pragma once
#include "parser.h"
#include "Function.h"
#include "Variable.h"


// 传入optionalparam<T>()表示不传参，原为for90std.h中foroptional的副本
//template<typename T>
//using optionalparam = boost::optional<T>;

// 属性文法
struct ParseAttr {
	ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(ParseNode * parsenode) : parsenode(parsenode) {}
	ParseAttr(const ParseAttr & pa) = default;
	virtual ParseAttr * clone() = 0; /* use clone because copy-constructor can not be virtual */
	virtual ~ParseAttr() = default;
	// virtual ParseAttr * merge() = 0;

};

struct TypeAttr : public ParseAttr {
	std::string name;

	TypeAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	TypeAttr(const TypeAttr & ta) {
		// do not call `clone()` else will cause stackoverflow
	}
	ParseAttr * clone() { return new TypeAttr(*this); }
	// void merge(const VariableDescAttr & pa) {  }
};

struct VariableAttr : public ParseAttr {
	VariableInfo * vinfoptr = nullptr;

	VariableAttr(ParseNode * parsenode, VariableInfo * vptr) : ParseAttr(parsenode), vinfoptr(vptr) {}
	VariableAttr(const VariableAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		this->vinfoptr = new VariableInfo(*va.vinfoptr);
	}
	ParseAttr * clone() { return new VariableAttr(*this); }

};

struct VariableDescAttr : public ParseAttr {
	//5.1.2 Attributes
	//	The additional attributes that may appear in the attribute specification of a type declaration statement further
	//	specify the nature of the entities being declared or specify restrictions on their use in the program.
	VariableDesc desc;

	VariableDescAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
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
	FunctionAttr(ParseNode * parsenode, FunctionInfo * fptr) : ParseAttr(parsenode), finfoptr(fptr) {}
	FunctionAttr(const FunctionAttr & fa) {
		// do not call `clone()` else will cause stackoverflow
		this->finfoptr = fa.finfoptr;
	}
	ParseAttr * clone() { return new FunctionAttr(*this); }

	void merge(const FunctionAttr & x2) {

	}
};