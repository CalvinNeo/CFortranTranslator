#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <string>
#include <random>
#include "../forlang.h"

#define USE_FORARRAY

namespace for90std {
	typedef int for1array_size_t;
	template<typename T>
	struct for1array {
		typedef T value_type;
		typedef for1array_size_t size_type; // for1array index can be negative
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef const value_type * const_pointer;
		typedef const value_type & const_reference;
		typedef size_type difference_type;

		struct iterator {
			iterator() {}
			iterator(const iterator & m) : _pos(m._pos), _farr(m._farr) {}
			iterator(for1array<value_type> * forarray, size_type pos) : _pos(pos), _farr(forarray) {}

			reference operator*() const
			{	// return designated object
				return (*_farr)[_pos];
			}

			pointer operator->() const
			{	// return pointer to class object
				return &(*_farr)[_pos];
			}

			iterator& operator++()
			{	// preincrement
				++_pos;
				return (*this);
			}

			iterator operator++(int)
			{	// postincrement
				iterator tmp = *this;
				++_pos;
				return (tmp);
			}

			iterator& operator--()
			{	// predecrement
				--_pos;
				return (*this);
			}

			iterator operator--(int)
			{	// postdecrement
				iterator tmp = *this;
				--_pos;
				return (tmp);
			}

			bool operator==(const iterator& _right) const
			{	// test for iterator equality
				return _right._pos == _pos && _right._farr == _farr;
			}

			bool operator!=(const iterator& _right) const
			{	// test for iterator inequality
				return _right._pos != _pos || _right._farr != _farr;
			}

			bool operator<(const iterator& _right) const
			{	// test if this < _Right
				return _pos < _right._pos;
			}

			bool operator>(const iterator& _right) const
			{	// test if this > _Right
				return _pos > _right._pos;
			}

			bool operator<=(const iterator& _right) const
			{	// test if this <= _Right
				return _pos <= _right._pos;
			}

			bool operator>=(const iterator& _right) const
			{	// test if this >= _Right
				return _pos >= _right._pos;
			}
		protected:
			size_type _pos;
			for1array<value_type> * _farr;
		};

		typename for1array<T>::iterator begin() {
			return iterator(this, this->LBound());
		}

		typename for1array<T>::iterator end() {
			return iterator(this, this->UBound());
		}

		for1array<T> slice(size_type fr, size_type to, size_type step = 1) const {
			std::vector<T> nvec;
			for (int i = fr; i < to; i += step)
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
			return ub - lb;
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
			if (i - lb >= (int)m_arr.size() || i - lb < 0) {
				throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & get(size_type i) {
			if (i - lb >= (int)m_arr.size() || i < lb) {
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
			return this->get(i);
		}
		template<typename... Args>
		auto & operator()(size_type i, Args... args){
			value_type & x = this->get(i);
			auto & y = x.operator()(std::forward<Args>(args)...);
			return y;
		}

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
		void resize(int l, int u) {
			this->lb = l;
			this->ub = u;
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
		constexpr static bool test(for1array_matcher<T>)
		{
			return true;
		}

		template<typename T>
		constexpr static bool test(...)
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

	template<typename T, int D = 0>
	using fornarray = for1array<T>;
	template<typename T, int D>
	using fornarray = fornarray<T, D - 1>;


	//template <typename T>
	//struct for1array_gettype {
	//	typedef std::conditional<is_for1array::test<T>(nullptr), typename for1array_gettype<typename T::value_type>::type, T> type;
	//};

	// get inner most type of nested for1array
	template <typename T>
	struct for1array_gettype {
		using type = T;
	};
	template<typename T>
	struct for1array_gettype<for1array<T>> {
		using type = typename for1array_gettype<T>::type;
	};

	template <typename T>
	struct function_traits
		: public function_traits<decltype(&T::operator())>
	{};
	// For generic types, directly use the result of the signature of its 'operator()'

	template <typename ClassType, typename ReturnType, typename... Args>
	struct function_traits<ReturnType(ClassType::*)(Args...) const>
	{
		// we specialize for pointers to member function
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

	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_getsize_layer(
		for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & size
		, .../* SFINAE */) {
		size.push_back(farr.size());
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_getsize_layer(
		for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & size
		, for1array_matcher<_Container_value_type>/* SFINAE */) {
		size.push_back(farr.size());
		_for1array_getsize_layer<typename _Container_value_type::value_type>(farr(farr.LBound()), size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> for1array_getsize(for1array<_Container_value_type> & farr) {
		std::vector<for1array_size_t> size;
		_for1array_getsize_layer<_Container_value_type>(farr, size, nullptr);
		return size;
	}

}