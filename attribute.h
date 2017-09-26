#pragma once
#include "parser.h"

// �ڳ�ʼ��֮���Ƿ�ֵ�Ƿ��޸�
template<class T>
struct dirty{
	T & operator= (const T & newv) {
		// ��ֵ�Ǹ�ֵ
		changed = true;
		value = newv;
		return value;
	}
	operator T() const {
		return value;
	}
	dirty(const T & newv) {
		// ��ʼ���ǳ�ʼ��
		changed = false;
		value = newv;
	}
	dirty(const dirty & d) {
		// ���ƹ��캯��
		// ��ʼ���ǳ�ʼ��
		changed = false;
		changed = d.isdirty();
		value = d;
	}
	bool isdirty() const{
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
template <class T>
struct optionalparam
{
	operator T() const {
		return value;
	}

	T & operator= (const T & newv) {
		// ��ֵ�����
		invalid = true;
		value = newv;
		return value;
	}
	optionalparam(const T & newv) {
		// ����ֵ��ʼ����˵������Ĭ�ϳ�ʼ��
		invalid = true;
		value = newv;
	}
	optionalparam(T & newv) {
		// ����ֵ��ʼ����˵������Ĭ�ϳ�ʼ��
		invalid = true;
		value = newv;
	}
	optionalparam(const optionalparam<T> & newv) {
		// ���ƹ��캯��
		invalid = true;
		value = newv.const_get();
	}
	optionalparam(optionalparam<T> & newv) {
		// ���ƹ��캯��
		invalid = true;
		value = newv.get();
	}
	optionalparam() {
		// Ĭ�ϳ�ʼ��
		invalid = false;
	}
	bool inited() const {
		return invalid;
	}
	T get() {
		return value;
	}
	const T & const_get() const {
		return value;
	}
private:
	T value;
	bool invalid = false;
};

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