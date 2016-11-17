#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <complex>

//#define USE_FORARRAY

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
	typedef T value_type;
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
		return for1array<T>(nvec, fr, to);
	};
	int LBound() const {
		return lb; 
	};
	int UBound() const { 
		return ub; 
	};
	T * c_array() {

	};
	std::vector<T> c_vector() const {
		return m_arr;
	}

	const T & get_const(int i) const {
		if (i - lb >= m_arr.size() || i - lb < 0 ) {
			throw 0;
		}
		else {
			return m_arr[i - lb];
		}
	}
	T & get(int i) {
		if (i - lb >= m_arr.size() || i - lb < 0) {
			m_arr.resize(i - lb + 1);
			return m_arr[i - lb];
			//throw 0;
		}
		else {
			return m_arr[i - lb];
		}
	}
	T & operator()(int i) {
		return get(i);
	};
	T & operator[](int i) {
		return get(i);
	}

	template<class ... Args>
	void add_list(const T & x, Args ... args) {
		add(x);
		addrange(forward<Args>(args)...);
	}
	void add(const T & x) {
		m_arr.push_back(x);
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
		init_value(forward<Args>(args)...);
	}
	template<class ... Args>
	void init_value(const T & x) {
		m_arr.push_back(x);
	}
	void clear() {
		m_arr.clear();
	}

	for1array(int l, int u) : lb(l), ub(u) {
		m_arr.resize(u - l);
	};
	for1array() : lb(0), ub(0) {

	};
	for1array(int l, int u, T x) : lb(l), ub(u) {
		m_arr.clear();
		for (int i = lb; i < ub; i++)
		{
			m_arr.push_back(x);
		}
	};
	for1array(const std::vector<T> & arr, int l, int u) : lb(l), ub(u) {
		m_arr = arr;
	};
	for1array(const for1array<T> & x) {
		m_arr.clear();
		(this->lb) = x.LBound();
		(this->ub) = x.UBound();
		for (int i = lb; i < ub; i++)
		{
			m_arr.push_back(x.get_const(i));
		}
	}
protected:
	std::vector<T> m_arr;
	T * carr;
	int lb, ub;
};

#ifndef USE_FORARRAY
template<typename T
	, class _Container_value_type
	, class _Iterator>
	void init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
	for (auto iter = b; iter != e; iter += accumulated[deep] /* always 1 */)
	{
		farr.add(*iter);
	}
}
template<typename T
	, class _Container_value_type
	, class _Iterator>
	void init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
	/* deep can never be equal to size.size() - 1 */
	int i = lower_bound[deep];
	for (auto iter = b; iter != e; iter += accumulated[deep])
	{
		/* NOTE: assume the array is already allocated and no need to clear */
		// farr.add(_Container_value_type());
		init_for1array_layer<T, _Container_value_type, std::vector<T>::const_iterator >(farr(i), lower_bound, deep + 1, size, accumulated, iter, iter + accumulated[deep]);
		i++;
	}
}
#else
template<typename T
	, class _Container_value_type
	, class _Iterator>
	void init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
	for (auto iter = b; iter != e; iter += accumulated[deep])
	{
		farr.add(*iter);
	}
}
template<typename T
	, class _Container_value_type
	, class _Iterator>
	void init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
	/* deep can never be equal to size.size() - 1 */
	int i = lower_bound[deep];
	for (auto outer = b; outer != e; outer += accumulated[deep + 1])
	{
		for (auto iter = outer; iter != outer + accumulated[deep + 1]; iter += accumulated[deep])
		{
			/* NOTE: assume the array is already allocated and no need to clear */
			// farr.add(_Container_value_type());
			init_for1array_layer<T, _Container_value_type, std::vector<T>::const_iterator >(farr(i), lower_bound, deep + 1, size, accumulated, b, e);
			i++;
		}
	}
}
#endif // !USE_FORARRAY


template<typename T, class _Container_value_type>
void init_for1array(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, const std::vector<int> & size, const std::vector<T> & values) {
	/* NOTE: assume the array is already allocated and no need to clear */
	// f_arr.clear()
	std::vector<int> accumulated(size);
	int s = 1;
#ifndef USE_FORARRAY
	std::transform(accumulated.rbegin(), accumulated.rend(), accumulated.rbegin(), [&s](int x) {int ans = s; s *= x; return ans; });
#else
	std::transform(accumulated.begin(), accumulated.end(), accumulated.begin(), [&s](int x) {int ans = s; s *= x; return ans; });
#endif // !USE_FORARRAY
	typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
	init_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size, accumulated, values.begin(), values.end());
}

template<typename T>
for1array<T> init_for1array_hiddendo(int start, int end, std::function<const T &(int)> get_T) {
	std::vector<T> nvec;
	for (int i = start; i < end; i++) {
		nvec.push_back(get_T(i));
	}
	return for1array<T>(nvec, start, end);
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

template<class T1, class T2>
long double power(T1 x, T2 y) {
	return powl(x, y);
}

#define mod modfl

#define forarray for1array
#define init_forarray init_for1array

using namespace std;