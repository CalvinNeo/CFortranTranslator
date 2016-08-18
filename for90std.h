#pragma once
#include <vector>
#include <cmath>

template<class T>
struct forarray {
	int lb, ub;
	forarray slice(int fr, int to, int step = 1) {
		std::vector<T> nvec;
		if (step == 1) {
			nvec.insert(m_arr.begin() + fr - lb, m_arr.begin() + to - lb);
		}
		else {
			for (int i = fr; i <= to; i += step)
			{
				nvec.push_back(m_arr[i - lb]);
			}
		}
	};
	T * c_array() {

	};
	std::vector<T> c_vector() {
		return m_arr;
	}
	T & operator()(int i) {
		return m_arr[i - lb];
	};

	forarray(int l, int u) : lb(l), ub(u){
		m_arr.resize(u - l);
	};
protected:
	std::vector<T> m_arr;
	T * carr;
};

struct forcomplex {
	
	const forcomplex operator+(const forcomplex & rhs);

	forcomplex(double real, double imagine) : m_real(real), m_imagine(imagine) {}
	forcomplex(std::string);
protected:
	double m_real;
	double m_imagine;
};

template <class T, class ... Args>
T min_n(T x, Args... args) {
	return min(x, args);
}
template <class T, class ... Args>
T max_n(T x, Args... args) {
	return max(x, args);
}

int test() {
	return 0;
}