#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <complex>

template <class T, class ... Args>
T min_n(T x, Args... args) {
	return min(x, args);
}
template <class T, class ... Args>
T min_n(T x, T y) {
	return min(x, y);
}
template <class T, class ... Args>
T max_n(T x, Args... args) {
	return max(x, args);
}
template <class T, class ... Args>
T max_n(T x, T y) {
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
long double power(T1 x, T2 y) {
	return powl(x, y);
}

#define mod modfl