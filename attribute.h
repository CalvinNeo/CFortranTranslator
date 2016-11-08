#pragma once
#include "parser.h"

//
template<class T>
struct dirty{
	T & operator= (const T & newv) {
		changed = true;
		value = newv;
		return value;
	}
	operator T() {
		return value;
	}
	dirty(const T & newv) {
		changed = false;
		value = newv;
	}
	dirty(const dirty & d) {
		changed = d->isdirty();
		value = d->value;
	}
	bool isdirty() const{
		return changed;
	}
private:
	T value;
	bool changed = false;
};

// Parse时候记录性质
struct FunctionDesc {

};
struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	dirty<struct ParseNode *> slice = nullptr;
	dirty<int> kind = 0;
};

// 属性文法
struct ParseAttr {
	ParseNode * parsenode; // observer ptr

	ParseAttr() = default;
	ParseAttr(ParseNode * parsenode) : parsenode(parsenode) {}
	ParseAttr(const ParseAttr & pa) = default;
	virtual ParseAttr * clone() = 0; /* use clone because copy-constructor can not be virtual */
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
	Variable * variable;

	VariableAttr(ParseNode * parsenode, Variable * v) : ParseAttr(parsenode), variable(v) {}
	VariableAttr(const VariableAttr & va) {
		// do not call `clone()` else will cause stackoverflow
	}
	ParseAttr * clone() { return new VariableAttr(*this); }

};

struct VariableDescAttr : public ParseAttr {
	VariableDesc desc;

	VariableDescAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	VariableDescAttr(const VariableDescAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		this->desc = va.desc;
	}
	ParseAttr * clone() { return new VariableDescAttr(*this); }

	void merge(const VariableDescAttr & x2) {
		if (!desc.constant.isdirty() && x2.desc.constant.isdirty()) {
			desc.constant = x2.desc.constant;
		}
		if (!desc.reference.isdirty() && x2.desc.reference.isdirty()) {
			desc.reference = x2.desc.reference;
		}
		if (!desc.optional.isdirty() && x2.desc.optional.isdirty()) {
			desc.optional = x2.desc.optional;
		}
		if (!desc.slice.isdirty() && x2.desc.slice.isdirty()) {
			desc.slice = x2.desc.slice;
		}
		if (!desc.kind.isdirty() && x2.desc.kind.isdirty()) {
			desc.kind = x2.desc.kind;
		}
	}
};

// struct ArrayAttr FormatterAttr