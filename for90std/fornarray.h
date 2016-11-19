#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <complex>

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
