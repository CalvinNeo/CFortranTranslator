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
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <complex>
#include "farray.h"

namespace for90std {

	template <class T, class ... Args>
	auto min_n(T x, Args... args) {
		return min(x, args);
	}
	template <class T1, class T2>
	decltype(std::declval<T1>() + std::declval<T2>()) min_n(T1 x, T2 y) {
		return min(x, y);
	}
	template <class T, class ... Args>
	auto max_n(T x, Args... args) {
		return max(x, args);
	}
	template <class T1, class T2>
	decltype(std::declval<T1>() + std::declval<T2>()) max_n(T1 x, T2 y) {
		return max(x, y);
	}
	
	typedef std::complex<double> forcomplex;
	//struct forcomplex {
	//	
	//	const forcomplex operator+(const forcomplex & rhs);
	//
	//	forcomplex(double real, double imagine);
	//	forcomplex(std::string);
	//protected:
	//	double m_real;
	//	double m_imagine;
	//};

	template<class T1, class T2>
	auto power(T1 x, T2 y) {
		return powl(x, y);
	}

	template<typename T1, typename T2>
	inline auto mod(T1 x, T2 y) {
		return modfl(x, y);
	}
	inline long long mod(long long x, long long y) {
		return x % y;
	}
}