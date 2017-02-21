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
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <limits>
#include <cassert>

namespace for90std {
	struct foroptional_dummy {};
	extern foroptional_dummy None;
	template <typename T>
	struct foroptional
	{
		operator T() const {
			assert(inited());
			return *value_ptr;
		}
		foroptional<T> & operator= (const T & newv) {
			delete value_ptr;
			value_ptr = new T(newv);
			return *this;
		}
		foroptional<T> & operator= (const foroptional<T> & newv) {
			invalid = (newv.inited());
			if (newv.inited())
			{
				delete value_ptr;
				value_ptr = new T(newv.const_get());
			}
			else {
				delete value_ptr;
				value_ptr = nullptr;
			}
			return *this;
		}
		foroptional<T> & operator= (const foroptional_dummy & dummy) {
			delete value_ptr;
			value_ptr = nullptr;
			return *this;
		}
		foroptional(const T & newv){
			// code here is not initialize but operator=
			delete value_ptr;
			value_ptr = new T(newv);
		}
		foroptional(const foroptional<T> & newv) {
			// copy constructor
			if (newv.inited())
			{
				// explicitly call copy constructor to avoid 
				delete value_ptr;
				value_ptr = new T(newv.const_get());
			}
			else {
				delete value_ptr;
				value_ptr = nullptr;
			}
		}
		foroptional(const foroptional_dummy & dummy) {
			delete value_ptr;
			value_ptr = nullptr;
		}
		foroptional() {
			delete value_ptr;
			value_ptr = nullptr;
		}
		bool inited() const {
			return value_ptr != nullptr;
		}
		T & get() {
			return *value_ptr;
		}
		const T & get() const {
			return *value_ptr;
		}
		const T & const_get() const {
			return *value_ptr;
		}

		const T & value_or(const T & def){
			if (inited())
			{
				return *value_ptr;
			}
			else {
				return def;
			}
		}
		template<typename F>
		const T & value_or_eval(F f) {
			if (inited())
			{
				return *value_ptr;
			}
			else {
				return f();
			}
		}

	protected:
		T * value_ptr = nullptr;
	};

	template <typename T>
	bool forpresent(const foroptional<T> & x) {
		return x.inited();
	}


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

	inline int8_t forhuge(int8_t x) {
		return INT8_MAX;
	}
	inline int16_t forhuge(int16_t x) {
		return INT16_MAX;
	}
	inline int32_t forhuge(int32_t x) {
		return INT32_MAX;
	}
	inline int64_t forhuge(int64_t x) {
		return INT64_MAX;
	}
	inline float forhuge(float x) {
		return FLT_MAX;
	}
	inline double forhuge(double x) {
		return DBL_MAX;
	}
	inline long double forhuge(long double x) {
		return LDBL_MAX;
	}

	inline float fortiny(float x) {
		return FLT_MIN;
	}
	inline double fortiny(double x) {
		return DBL_MIN;
	}
	inline long double fortiny(long double x) {
		return LDBL_MIN;
	}

	template<typename T>
	T forhuge() {
		return std::numeric_limits<T>::max();
	}
	template<typename T>
	T fortiny() {
		return std::numeric_limits<T>::max();
	}
}