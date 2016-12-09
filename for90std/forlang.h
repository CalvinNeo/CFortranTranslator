#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

namespace for90std {
	struct foroptional_dummy {};
	#define _D foroptional_dummy()

	template <typename T>
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
		foroptional(const foroptional<T> & newv) {
			// 复制构造函数
			invalid = true;
			value = newv.const_get();
		}
		foroptional(const foroptional_dummy & newv) {
			// 语法糖
			invalid = false;
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
	protected:
		T value;
		bool invalid = false;
	};

	template <typename T>
	bool forpresent(const foroptional<T> & x) {
		return x.inited();
	}

	template<typename T>
	struct forargs {

	};

	/* general type cast */
	template<typename T>
	int to_int(T x, foroptional<int> kind = foroptional<int>()) {
		return (int)x;
	}
	template<typename T>
	long long to_longlong(T x, foroptional<int> kind = foroptional<int>()) {
		return (long long)x;
	}
	template<typename T>
	long double to_longdouble(T x, foroptional<int> kind = foroptional<int>()) {
		return (long double)x;
	}
	template<typename T>
	double to_double(T x, foroptional<int> kind = foroptional<int>()) {
		return (double)x;
	}
	/* string type cast */
	extern /* using static/inline/extern to avoid repeated definition */ int to_int(std::string x, foroptional<int> kind);
	extern long long to_longlong(std::string x, foroptional<int> kind);
	extern double to_double(std::string x, foroptional<int> kind);
	extern long double to_longdouble(std::string x, foroptional<int> kind);

}