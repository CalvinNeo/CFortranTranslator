#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

template<typename T>
struct for1array {
	typedef T value_type;
	typedef int size_type;
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
	int for1array_kind(){
		return 1;
	}
	T * c_array() {

	};
	std::vector<T> c_vector() const {
		return m_arr;
	}

	const T & get_const(int i) const {
		if (i - lb >= m_arr.size() || i - lb < 0) {
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

/* SFINAE */
template<typename T, int (T::*)()>
struct func_matcher;

template <typename T>
using for1array_matcher = func_matcher<T, &T::for1array_kind>*;

struct is_for1array
{
	template<typename T>
	static bool test(for1array_matcher<T>)
	{
		return true;
	}

	template<typename T>
	static bool test(...)
	{
		return false;
	}
};

#ifndef USE_FORARRAY
template<typename T
	, typename _Container_value_type
	, typename _Iterator>
	void init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep
		, const std::vector<int> & size, const std::vector<int> & accumulated
		, _Iterator b, _Iterator e, const std::vector<T> & values, .../* SFINAE */) {
	for (auto iter = b; iter != e; iter += accumulated[deep] /* always 1 */)
	{
		farr.add(*iter);
	}
}

template<typename T
	, typename _Container_value_type
	, typename _Iterator>
	void init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, int deep
		, const std::vector<int> & size, const std::vector<int> & accumulated
		, _Iterator b, _Iterator e, const std::vector<T> & values, for1array_matcher<_Container_value_type>/* SFINAE */) {
	/* deep can never be equal to size.size() - 1 */
	int i = lower_bound[deep]; 
	for (auto iter = b; iter != e; iter += accumulated[deep])
	{
		/* NOTE: assume the array is already allocated and no need to clear */
		// farr.add(_Container_value_type());
		init_for1array_layer<T, typename _Container_value_type::value_type, _Iterator>(farr(i), lower_bound, deep + 1, size, accumulated
			, iter, iter + accumulated[deep], values, nullptr);
		i++;
	}
}
#else
template<typename T
	, typename _Container_value_type
	, typename _Iterator>
	void init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
	for (auto iter = b; iter != e; iter += accumulated[deep])
	{
		farr.add(*iter);
	}
}
template<typename T
	, typename _Container_value_type
	, typename _Iterator>
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



template<typename T, typename _Container_value_type>
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
	init_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size, accumulated
		, values.begin(), values.end(),  values, nullptr);
}

template<typename T>
for1array<T> init_for1array_hiddendo(int start, int end, std::function<T (int)> get_T) {
	std::vector<T> nvec;
	for (int i = start; i < end; i++) {
		nvec.push_back(get_T(i));
	}
	return for1array<T>(nvec, start, end);
}



#define forarray for1array
#define init_forarray init_for1array