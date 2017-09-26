#pragma once
#include "parser.h"
#include "Function.h"
#include "Variable.h"
#include <boost/optional/optional.hpp>

// �ڳ�ʼ��֮���Ƿ�ֵ�Ƿ��޸�
template<class T>
struct dirty {
	operator T() const {
		return value;
	}
	T & operator= (const T & newv) {
		// ��ֵ
		changed = true;
		value = newv;
		return value;
	}
	dirty(const T & newv) {
		// ��ʼ��
		changed = false;
		value = newv;
	}
	dirty(const dirty<T> & d) {
		// ���ƹ��캯��
		// ��ʼ��
		changed = false;
		changed = d.isdirty();
		value = d;
	}
	bool isdirty() const {
		return changed;
	}
	T get() {
		return value;
	}
	const T & const_get() const {
		return value;
	}
private:
	T value;
	bool changed = false;
};

// for90std.h��foroptional�ĸ���
// ����optionalparam<T>()��ʾ������
//template<typename T>
//using optionalparam = boost::optional<T>;


// Parseʱ���¼����
struct FunctionDesc {

};
struct VariableDesc {
	dirty<bool> reference = false;
	dirty<bool> constant = false;
	dirty<bool> optional = false;
	dirty<struct ParseNode *> slice = nullptr;
	dirty<int> kind = 0;
};

// �����ķ�
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
	Variable * variable;

	VariableAttr(ParseNode * parsenode, Variable * v) : ParseAttr(parsenode), variable(v) {}
	VariableAttr(const VariableAttr & va) {
		// do not call `clone()` else will cause stackoverflow
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
	void hack() {

	}
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

struct KwArgsAttr : public ParseAttr {
	std::map<std::string, std::string> key_value;

	KwArgsAttr(ParseNode * parsenode) : ParseAttr(parsenode) {}
	KwArgsAttr(const KwArgsAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		this->key_value = va.key_value;
	}
	ParseAttr * clone() { return new KwArgsAttr(*this); }

	void merge(const KwArgsAttr & x2) {

	}
};

struct FunctionAttr : public ParseAttr {
	std::vector<struct ParseNode *> param_definition;
	std::vector<std::tuple<std::string, ParseNode, struct ParseNode *>> param_name_typename;
	FunctionAttr(struct ParseNode * parsenode) : ParseAttr(parsenode) {}
	FunctionAttr(const FunctionAttr & va) {
		// do not call `clone()` else will cause stackoverflow
		this->param_definition = va.param_definition;
		this->param_name_typename = va.param_name_typename;
	}
	ParseAttr * clone() { return new FunctionAttr(*this); }

	void merge(const FunctionAttr & x2) {

	}
};
// struct ArrayAttr FormatterAttr
