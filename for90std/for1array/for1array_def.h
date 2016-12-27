#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <string>
#include <array>
#include <random>
#include "../forlang.h"
#include "../forutils.h"

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
		int for1array_kind() const{
			return 1;
		}
		T * c_array() {

		};
		std::vector<T> c_vector() const {
			return m_arr;
		}

		const T & const_get(size_type i) const {
			if (i - lb >= (size_type)m_arr.size() || i - lb < 0) {
				throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & get(size_type i) {
			if (i - lb >= (size_type)m_arr.size() || i < lb) {
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
		template<typename _Inner>
		for1array<T> & operator=(const std::vector<_Inner> & x) {
			for1array_init(*this, for1array_lbound(*this), for1array_getsize(*this), x);
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

		// deprecated
		template<class ... Args>
		void push_back(const T & x, Args ... args) {
			push_back(x);
			push_back(forward<Args>(args)...);
		}
		template<class ... Args>
		void push_back(const T & x) {
			m_arr.push_back(x);
		}

		void clear() {
			m_arr.clear();
		}
		void resize(size_type l, size_type u) {
			this->lb = l;
			this->ub = u;
		}
		template<typename _InnerT>
		for1array(const std::vector<size_type> & lower_bound, const std::vector<size_type> & size, const std::initializer_list<_InnerT> & values)
		{
			for1array_init(*this, lower_bound, size, values);
		}
		for1array(const std::vector<T> & arr, size_type l, size_type u) : lb(l), ub(u) {
			m_arr = arr;
		};
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
	};
	

	template <typename T>
	using for1array_matcher = const_func_matcher<T, &(T::for1array_kind)>*;

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

	// base template must before inherited
	template<typename _DTYPE, int D>
	struct fornarray_impl {
		typedef typename for1array<typename fornarray_impl<_DTYPE, D - 1>::type> type;
	};
	template<typename _DTYPE>
	struct fornarray_impl<_DTYPE, 1> {
		typedef typename for1array<_DTYPE> type;
	};
	template<typename _DTYPE>
	struct fornarray_impl<_DTYPE, 0> {
		typedef typename _DTYPE type;
	};
	template<typename _DTYPE, int D>
	using fornarray = typename fornarray_impl<_DTYPE, D>::type;


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


	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_getsize_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & size
		, .../* SFINAE */) {
		size.push_back(farr.size());
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_getsize_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & size
		, for1array_matcher<_Container_value_type>/* SFINAE */) {
		size.push_back(farr.size());
		_for1array_getsize_layer<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> for1array_getsize(const for1array<_Container_value_type> & farr) {
		std::vector<for1array_size_t> size;
		_for1array_getsize_layer<_Container_value_type>(farr, size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_lbound_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & lbound
		, .../* SFINAE */) {
		lbound.push_back(farr.LBound());
		return lbound;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> _for1array_lbound_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<for1array_size_t> & lbound
		, for1array_matcher<_Container_value_type>/* SFINAE */) {
		lbound.push_back(farr.LBound());
		_for1array_lbound_layer<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), lbound, nullptr);
		return lbound;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_t> for1array_lbound(const for1array<_Container_value_type> & farr) {
		std::vector<for1array_size_t> lbound;
		_for1array_lbound_layer<_Container_value_type>(farr, lbound, nullptr);
		return lbound;
	}

}