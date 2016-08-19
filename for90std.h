#pragma once
#include <vector>
#include <cmath>

template<class T>
struct forarray {
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
		if (i - lb >= m_arr.size()) {
			m_arr.resize(i - lb);
			return m_arr[i - lb];
		}
		else {
			return m_arr[i - lb];
		}
	};

	template<class ... Args>
	void addrange(T x, Args ... args) {
		add(x);
		addrange(args);
	}
	void add(T x) {
		m_arr.push_back(x)
	}
	template<class ... Args>
	void init(T x, Args ... args) {
		m_arr.clear.clear();
		m_arr.push_back(x);
		init(args);
	}


	forarray(int l, int u) : lb(l), ub(u){

	};
protected:
	std::vector<T> m_arr;
	T * carr;
	int lb, ub;
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