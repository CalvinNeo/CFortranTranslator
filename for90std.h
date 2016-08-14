#pragma once
#include <vector>

template<T>
struct forarray {
	int lb, ub;
	forarray slice(int fr, int to, int step = 1);
	char * c_array();
	std::vector<T> c_vector();
	T & operator(int i);

	forarray(int l, int u) lb(l), ub(u){}
protected:
	std::vector<T> m_arr;
	char * carr;
};

struct forcomplex {
	
	const forcomplex operator+(const forcomplex & rhs);

	forcomplex(double real, double imagine) : m_real(real), m_imagine(imagine) {}
protected:
	double m_real;
	double m_imagine;
};