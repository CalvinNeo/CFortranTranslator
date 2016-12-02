#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

template <class T>
struct foroptional
{
	operator T() const {
		return value;
	}

	T & operator= (const T & newv) {
		// 赋值运算符
		invalid = true;
		value = newv;
		return value;
	}
	foroptional(const T & newv) {
		// 给定值初始化，说明不是默认初始化
		invalid = true;
		value = newv;
	}
	foroptional(T & newv) {
		// 给定值初始化，说明不是默认初始化
		invalid = true;
		value = newv;
	}
	foroptional(const foroptional<T> & newv) {
		// 复制构造函数
		invalid = true;
		value = newv.const_get();
	}
	foroptional(foroptional<T> & newv) {
		// 复制构造函数
		invalid = true;
		value = newv.get();
	}
	foroptional() {
		// 默认初始化
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

template <class T>
bool forpresent(foroptional<T> x) {
	return x.inited();
}

template<typename T>
int to_int(T  x) {
	return (int)x;
}