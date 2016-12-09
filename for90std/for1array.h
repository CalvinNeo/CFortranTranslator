#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

namespace for90std {
	template<typename T>
	struct for1array {
		typedef T value_type;
		typedef int size_type;
		typedef value_type *pointer;
		typedef value_type& reference;
		typedef const value_type *const_pointer;
		typedef const value_type& const_reference;
		for1array<T> slice(size_type fr, size_type to, int step = 1) {
			std::vector<T> nvec;
			for (int i = fr; i <= to; i += step)
			{
				nvec.push_back(m_arr[i - lb]);
			}
			return for1array<T>(nvec, fr, to);
		};
		size_type LBound() const {
			return lb;
		};
		size_type UBound() const {
			return ub;
		};
		size_type size() const {
			return m_arr.size();
		}
		int for1array_kind() {
			return 1;
		}
		T * c_array() {

		};
		std::vector<T> c_vector() const {
			return m_arr;
		}

		const T & const_get(size_type i) const {
			if (i - lb >= m_arr.size() || i - lb < 0) {
				throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & get(size_type i) {
			if (i - lb >= m_arr.size() || i - lb < 0) {
				m_arr.resize(i - lb + 1);
				ub = i + 1; // important
				return m_arr[i - lb];
				//throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & operator()(size_type i) {
			return get(i);
		};
		T & operator[](size_type i) {
			return get(i);
		}
		for1array<T> & operator=(const for1array<T> & x) {
			for (size_type i = 0; i < x.size(); i++)
			{
				m_arr = x.m_arr;
			}
			(this->lb) = x.LBound();
			(this->ub) = x.UBound();
			return *this;
		}
		for1array<T> & operator+=(const for1array<T> & x) {
			for (size_type i = x.LBound(); i < x.UBound(); i++)
			{
				m_arr.push_back(x.const_get(i));
			}
			this->ub += x.size();
			return *this;
		}

		template<class ... Args>
		void push_back_list(const T & x, Args ... args) {
			push_back(x);
			addrange(forward<Args>(args)...);
		}
		void push_back(const T & x) {
			m_arr.push_back(x);
		}

		template<class ... Args>
		void init(const T & x, Args ... args) {
			m_arr.clear();
			_init_by_value(x, forward<Args>(args)...);
		}
		template<class ... Args>
		void init() {
			m_arr.clear();
		}
		void clear() {
			m_arr.clear();
		}

		for1array(size_type l, size_type u) : lb(l), ub(u) {
			m_arr.resize(u - l);
		};
		for1array() : lb(0), ub(0) {

		};
		for1array(size_type l, size_type u, T x) : lb(l), ub(u) {
			m_arr.clear();
			for (int i = lb; i < ub; i++)
			{
				m_arr.push_back(x);
			}
		};
		for1array(const std::vector<T> & arr, size_type l, size_type u) : lb(l), ub(u) {
			m_arr = arr;
		};
		for1array(const for1array<T> & x) {
			m_arr.clear();
			(this->lb) = x.LBound();
			(this->ub) = x.UBound();
			for (size_type i = lb; i < ub; i++)
			{
				m_arr.push_back(x.const_get(i));
			}
		}
	protected:
		std::vector<T> m_arr;
		T * carr;
		size_type lb, ub;

		template<class ... Args>
		void _init_by_value(const T & x, Args ... args) {
			m_arr.push_back(x);
			_init_by_value(forward<Args>(args)...);
		}
		template<class ... Args>
		void _init_by_value(const T & x) {
			m_arr.push_back(x);
		}
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

	template<typename T>
	for1array<T> operator+(const for1array<T> & x, const for1array<T> & y) {
		for1array<T> n = for1array<T>(x);
		n += y;
		return n;
	}

#ifndef USE_FORARRAY
	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep
			, const std::vector<int> & size, const std::vector<int> & next_i_delta, const std::vector<int> & next_iter_delta
			, _Iterator b, _Iterator e, .../* SFINAE */) {
		auto iter = b;
		for (int times = 0; times < 1 /*always 1*/; times++) {
			for (int i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
			{
				farr(i) = *iter;
				if (i != lower_bound[deep] + size[deep] - 1) {
					iter += next_iter_delta[deep]/* always 1, always not 1 -- 2016-12-03 */;
				}
			}
		}
	}

	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, int deep
			, const std::vector<int> & size, const std::vector<int> & next_i_delta, const std::vector<int> & next_iter_delta
			, _Iterator b, _Iterator e, for1array_matcher<_Container_value_type>/* SFINAE */) {
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		for (int times = 0; times < 1; times++) {
			for (int i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
			{
				/* NOTE: assume the array is already allocated and no need to clear */
				_init_for1array_layer<T, typename _Container_value_type::value_type, _Iterator>(farr(i), lower_bound, deep + 1, size, next_i_delta
					, next_iter_delta, iter, iter + next_iter_delta[deep], nullptr);
				if (i != lower_bound[deep] + size[deep] - 1) {
					iter += next_iter_delta[deep];
				}
			}
		}
	}
#else
	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<T> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
		for (auto iter = b; iter != e; iter += accumulated[deep])
		{
			farr.add(*iter);
		}
	}
	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, int deep, const std::vector<int> & size, const std::vector<int> & accumulated, _Iterator b, _Iterator e) {
		/* deep can never be equal to size.size() - 1 */
		int i = lower_bound[deep];
		for (auto outer = b; outer != e; outer += accumulated[deep + 1])
		{
			for (auto iter = outer; iter != outer + accumulated[deep + 1]; iter += accumulated[deep])
			{
				/* NOTE: assume the array is already allocated and no need to clear */
				// farr.add(_Container_value_type());
				_init_for1array_layer<T, _Container_value_type, std::vector<T>::const_iterator >(farr(i), lower_bound, deep + 1, size, accumulated, b, e);
				i++;
			}
		}
	}
#endif // !USE_FORARRAY



	template<typename T, typename _Container_value_type>
	void init_for1array(for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, const std::vector<int> & size, const std::vector<T> & values) {
		/* NOTE: assume the array is already allocated and no need to clear */
		// f_arr.clear()
		std::vector<int> next_i_delta(size);
		std::vector<int> next_iter_delta(size);
		int s = 1;
#ifndef USE_FORARRAY
		std::transform(next_i_delta.rbegin(), next_i_delta.rend(), next_i_delta.rbegin(), [&s](int x) {int ans = s; s *= x; return ans; });
		s = 1; std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin(), [&s](int x) {int ans = s; s *= x; return ans; });
#else
		std::transform(next_i_delta.begin(), next_i_delta.end(), next_i_delta.begin(), [&s](int x) {int ans = s; s *= x; return ans; });
		next_iter_delta = next_i_delta;
#endif // !USE_FORARRAY
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_init_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size, next_i_delta
			, next_iter_delta, values.begin(), values.end(), nullptr);
	}
	template<typename T, typename _Container_value_type>
	for1array<_Container_value_type> gen_for1array(const for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound, const std::vector<int> & size, const std::vector<T> & values) {
		for1array<_Container_value_type> n;
		return init_for1array(n, lower_bound, size, values);
	}

	template <typename T>
	struct function_traits
		: public function_traits<decltype(&T::operator())>
	{};
	// For generic types, directly use the result of the signature of its 'operator()'

	template <typename ClassType, typename ReturnType, typename... Args>
	struct function_traits<ReturnType(ClassType::*)(Args...) const>
		// we specialize for pointers to member function
	{
		enum { arity = sizeof...(Args) };
		// arity is the number of arguments.

		typedef ReturnType result_type;

		template <size_t i>
		struct arg
		{
			typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
			// the i-th argument is equivalent to the i-th tuple element of a tuple
			// composed of those arguments.
		};
	};

	//template<typename T>
	//for1array<T> init_for1array_hiddendo(int start, int end, std::function<T(int) > get_T) {
	//for1array<T> init_for1array_hiddendo(int start, int end, T (*get_T)(int) ) {
	template<typename T>
	auto _init_for1array_hiddendo(int start, int end, std::function<T(int) > get_T)
	{
		std::vector<T> nvec;
		for (int i = start; i < end; i++) {
			nvec.push_back(get_T(i));
		}
		for1array<T> rt(nvec, start, end);
		return rt;
	}

	template <typename T>
	auto init_for1array_hiddendo(int from, int to, T lambda)
		-> for1array<typename function_traits<T>::result_type> {
		auto _Gen_stmt = lambda;
		return _init_for1array_hiddendo<function_traits<decltype(_Gen_stmt)>::result_type>(from, to, _Gen_stmt);
	}

#define forarray for1array
#define init_forarray init_for1array
#define gen_forarray gen_for1array
}
