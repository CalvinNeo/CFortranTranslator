#pragma once
#include <vector>
#include <cmath>

template<class T>
struct fornarray {
	template<class ... Args>
	fornarray slice(int l, int r, Args ... args) {
		
		init_value(std::forward<Args>(args)...);
	}
	template<class ... Args>
	fornarray slice(int l, int r) {

	}

	int lower_bound(int dimen) { return lb[dimen]; };
	int upper_bound(int dimen) { return ub[dimen]; };

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
	void addrange(const T & x, Args ... args) {
		add(x);
		addrange(forward<Args>(args)...);
	}
	void add(const T & x) {
		m_arr.push_back(x)
	}
	template<class ... Args>
	void init(const T & x, Args ... args) {
		m_arr.clear();
		init_value(x, forward<Args>(args)...);
	}
	template<class ... Args>
	void init() {
		m_arr.clear();
	}
	template<class ... Args>
	void init_value(const T & x, Args ... args) {
		m_arr.push_back(x);
		init_value(std::forward<Args>(args)...);
	}
	template<class ... Args>
	void init_value() {
		m_arr.push_back(x);
	}

	fornarray(const std::vector<int> & l, const std::vector<int> & u) : lb(l), ub(u) {

	};
protected:
	std::vector<T> m_arr;
	std::vector<int> lb, ub;
};

template<class T>
struct for1array {
	for1array slice(int fr, int to, int step = 1) {
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
	int lower_bound() { return lb; };
	int upper_bound() { return ub; };
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
	void addrange(const T & x, Args ... args) {
		add(x);
		addrange(forward<Args>(args)...);
	}
	void add(const T & x) {
		m_arr.push_back(x)
	}
	template<class ... Args>
	void init(const T & x, Args ... args) {
		m_arr.clear();
		init_value(x, forward<Args>(args)...);
	}
	void init() {
		m_arr.clear();
	}
	template<class ... Args>
	void init_value(const T & x, Args ... args) {
		m_arr.push_back(x);
		init_value(forward<Args>(args)...);
	}
	template<class ... Args>
	void init_value(const T & x) {
		m_arr.push_back(x);
	}
	void init(const for1array<T> & x) {
		m_arr.clear();
		this.lb = x.lower_bound();
		this.ub = x.upper_bound();
		for (int i = lb; i < ub; i++)
		{
			m_arr.push_back(x(i));
		}
	}

	for1array(int l, int u) : lb(l), ub(u) {

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

#define forarray for1array