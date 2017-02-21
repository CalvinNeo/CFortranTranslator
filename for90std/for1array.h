/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once
#include "forarray_common.h"

namespace for90std {
	template<typename T>
	struct for1array {
		typedef T value_type;
		typedef fsize_t size_type; // for1array index can be negative
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef const value_type * const_pointer;
		typedef const value_type & const_reference;
		typedef size_type difference_type;

		for1array<T> slice(size_type fr, size_type to, size_type step = 1) const {
			// [from, to]
			for1array<T> nfor1(1, to + 1 - fr);
			size_type j = 1;
			for (size_type i = fr; i <= to; i += step, j++)
			{
				nfor1(j) = const_get(i);
			}
			return nfor1;
		};
		size_type LBound() const {
			return lb;
		};
		size_type UBound() const {
			return lb + sz - 1;
		};
		size_type size() const {
			return sz;
		}
		int f1a_kind() const {
			return 1;
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
				sz = i - lb + 1; // important
				return m_arr[i - lb];
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & operator()(size_type i) {
			return this->get(i);
		}
		template<typename... Args>
		auto & operator()(size_type i, Args&&... args) {
			value_type & x = this->get(i);
			auto & y = x.operator()(std::forward<Args>(args)...);
			return y;
		}

		T & operator[](size_type i) {
			return get(i);
		}

		template<typename _Inner>
		for1array<T> & operator=(const std::vector<_Inner> & x) {
			if (this == &x) return *this;
			f1a_init(*this, f1a_lbound(*this), f1a_getsize(*this), x);
			return *this;
		}
		for1array<T> & operator+=(const for1array<T> & x) {
			for (size_type i = x.LBound(); i < x.LBound() + x.size(); i++)
			{
				m_arr.push_back(x.const_get(i));
			}
			this->sz += x.size();
			return *this;
		}

		template<class ... Args>
		void push_back(const T & x, Args&& ... args) {
			push_back(x);
			push_back(forward<Args>(args)...);
		}
		void push_back(const T & x) {
			m_arr.push_back(x);
		}

		void clear() {
			m_arr.clear();
		}
		void resize(size_type l, size_type s) {
			this->lb = l;
			this->sz = s;
			m_arr.resize(this->sz); // if removed, f1a_resize will boom
		}
		template<typename _InnerT>
		for1array(const std::vector<size_type> & lower_bound, const std::vector<size_type> & size, const std::initializer_list<_InnerT> & values)
		{
			f1a_init(*this, lower_bound, size, values);
		}
		for1array(const std::vector<size_type> & lower_bound, const std::vector<size_type> & size, const for1array<T> & x)
		{
			m_arr.clear();
			m_arr = x.m_arr;
			f1a_resize<typename f1a_gettype<T>::type, T>(*this, lower_bound, size);
		}
		for1array() : lb(0), sz(0) {

		};
		for1array(const for1array<T> & x) {
			m_arr.clear();
			(this->lb) = x.LBound();
			(this->sz) = x.size();
			for (size_type i = lb; i < lb + sz; i++)
			{
				m_arr.push_back(x.const_get(i));
			}
		}

		std::vector<T> m_arr;
	protected:
		size_type lb;
		size_type sz;
	};


	template <typename T>
	using for1array_matcher = const_func_matcher<T, fsize_t, &(T::size)>*;

	MAKE_FUNC_TEST(for1array, for1array_matcher)

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



	// get inner most type of nested for1array
	template <typename T>
	struct f1a_gettype {
		using type = T;
	};
	template<typename _Container_value_type>
	struct f1a_gettype<for1array<_Container_value_type>> {
		using type = typename f1a_gettype<_Container_value_type>::type;
	};


	template<typename _Container_value_type>
	std::vector<fsize_t> _f1a_getsize_impl(
		const for1array<_Container_value_type> & farr
		, std::vector<fsize_t> & size
		, .../* SFINAE */) {
		size.push_back(farr.size());
		return size;
	}

	template<typename _Container_value_type>
	std::vector<fsize_t> _f1a_getsize_impl(
		const for1array<_Container_value_type> & farr
		, std::vector<fsize_t> & size
		, for1array_matcher<_Container_value_type>/* SFINAE */) {
		size.push_back(farr.size());
		_f1a_getsize_impl<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<fsize_t> f1a_getsize(const for1array<_Container_value_type> & farr) {
		std::vector<fsize_t> size;
		_f1a_getsize_impl<_Container_value_type>(farr, size, nullptr);
		return size;
	}


	//template<typename _Container_value_type>
	//std::vector<fsize_t> _f1a_lbound_impl(
	//	const for1array<_Container_value_type> & farr
	//	, std::vector<fsize_t> & lbound
	//	, .../* SFINAE */) {
	//	lbound.push_back(farr.LBound());
	//	return lbound;
	//}

	//template<typename _Container_value_type>
	//std::vector<fsize_t> _f1a_lbound_impl(
	//	const for1array<_Container_value_type> & farr
	//	, std::vector<fsize_t> & lbound
	//	, for1array_matcher<_Container_value_type>/* SFINAE */) {
	//	lbound.push_back(farr.LBound());
	//	_f1a_lbound_impl<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), lbound, nullptr);
	//	return lbound;
	//}

	template<typename _Container_value_type>
	void _f1a_lbound_impl(_Container_value_type & farr, std::vector<fsize_t> & lbound) {
	}

	template<typename _Container_value_type>
	void _f1a_lbound_impl(const for1array<_Container_value_type> & farr, std::vector<fsize_t> & lbound) {
		lbound.push_back(farr.LBound());
		_f1a_lbound_impl(farr.const_get(farr.LBound()), lbound); // can not specify
	}

	template<typename _Container_value_type>
	std::vector<fsize_t> f1a_lbound(const for1array<_Container_value_type> & farr) {
		std::vector<fsize_t> lbound;
		_f1a_lbound_impl(farr, lbound);
		return lbound;
	}
#ifdef USE_FORARRAY
	template<typename _DTYPE, typename _Container_value_type, typename = void>
	void _f1a_resize_impl(for1array<_DTYPE> & farr, int deep
		, const std::vector<fsize_t> & lower_bound, const std::vector<fsize_t> & size)
	{
		farr.resize(lower_bound[deep], size[deep]);
	}

	template<typename _DTYPE, typename _Container_value_type
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size()) >>
		void _f1a_resize_impl(for1array<_Container_value_type> & farr, int deep
			, const std::vector<fsize_t> & lower_bound
			, const std::vector<fsize_t> & size)
	{
		farr.resize(lower_bound[deep], size[deep]);
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			_f1a_resize_impl<_DTYPE, typename _Container_value_type::value_type>(farr(i), deep + 1, lower_bound, size);
		}
	}

	template<typename _DTYPE, typename _Container_value_type>
	void f1a_resize(for1array<_Container_value_type> & farr
		, const std::vector<fsize_t> & lower_bound
		, const std::vector<fsize_t> & size)
	{
		_f1a_resize_impl<_DTYPE, _Container_value_type >(farr, 0, lower_bound, size);
	}

	template<typename _DTYPE, typename _Container_value_type, typename _Iterator, typename = void>
	void _f1a_init_impl(for1array<_DTYPE> & farr, int deep
		, const std::vector<fsize_t> & lower_bound
		, const std::vector<fsize_t> & size
		, const std::vector<fsize_t> & next_iter_delta
		, _Iterator b, _Iterator e)
	{
		auto iter = b;
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			farr(i) = *iter;
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _DTYPE, typename _Container_value_type, typename _Iterator
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size()) >>
		void _f1a_init_impl(for1array<_Container_value_type> & farr, int deep
			, const std::vector<fsize_t> & lower_bound
			, const std::vector<fsize_t> & size
			, const std::vector<fsize_t> & next_iter_delta
			, _Iterator b, _Iterator e)
	{
		auto iter = b;
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			_f1a_init_impl<_DTYPE, typename _Container_value_type::value_type, _Iterator>(farr(i), deep + 1, lower_bound, size
				, next_iter_delta, iter, iter + next_iter_delta[deep]);
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _DTYPE, typename _Container_value_type>
	void f1a_init(for1array<_Container_value_type> & farr
		, const std::vector<fsize_t> & lower_bound
		, const std::vector<fsize_t> & size
		, const std::initializer_list<_DTYPE> & values)
	{
		f1a_resize<_DTYPE, _Container_value_type>(farr, lower_bound, size);
		std::vector<fsize_t> next_iter_delta = fa_layer_delta(size.begin(), size.end());
		//_f1a_init_impl<_DTYPE, _Container_value_type, std::initializer_list<_DTYPE>::const_iterator >(farr, 0, lower_bound, size
		//	, next_iter_delta, values.begin(), values.end());
		auto vec_ptr = f1a_flatternedptr(farr);
		auto iter = values.begin();
		for (auto i = 0; i < vec_ptr.size(); i++, iter++)
		{
			*(vec_ptr[i]) = *iter;
		}
	};

	template<typename _InnerT, int D>
	fornarray<_InnerT, D> f1a_gen(const std::vector<fsize_t> & lower_bound
		, const std::vector<fsize_t> & size
		, const std::initializer_list<_InnerT> & values)
	{
		fornarray<_InnerT, D> n;
		f1a_init(n, lower_bound, size, values);
		return n;
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return, typename = void>
	void _f1a_flatmapped_impl(for1array<_DTYPE> & farr, int deep
		, const std::vector<fsize_t> & next_iter_delta
		, _Iterator b, _Iterator e
		, std::function<_Return(typename _DTYPE *)> mapper)
	{
		auto iter = b;
		for (auto i = farr.LBound(); i < x.LBound() + x.size(); i++)
		{
			(*iter) = mapper(&(farr.get(i)));
			if (i != x.LBound() + x.size() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size())> >
		void _f1a_flatmapped_impl(for1array<_Container_value_type> & farr, int deep
			, const std::vector<fsize_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, std::function<_Return(typename _DTYPE *)> mapper)
	{
		auto iter = b;
		for (auto i = farr.LBound(); i < x.LBound() + x.size(); i++)
		{
			_f1a_flatmapped_impl<typename _Container_value_type::value_type, _DTYPE, _Iterator>(
				farr(i), deep + 1, next_iter_delta, iter, iter + next_iter_delta[deep], mapper);
			if (i != x.LBound() + x.size() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _Return, typename _Iterator>
	void f1a_flatmapped(for1array<_Container_value_type> & farr, _Iterator begin, _Iterator end, std::function<_Return(typename f1a_gettype<_Container_value_type>::type *)> mapper)
	{
		typedef typename f1a_gettype<_Container_value_type>::type T; // inner most type
		std::vector<fsize_t> size = f1a_getsize(farr); // size of each dimension of array
		std::vector<fsize_t> next_iter_delta = fa_layer_delta(size.begin(), size.end());
		_f1a_flatmapped_impl<_Container_value_type, T, _Iterator, _Return >(farr, 0, next_iter_delta, begin, end, mapper);
	};

	template<typename _Container_value_type, typename _Return, typename _Iterator>
	void f1a_flatmapped_const(const for1array<_Container_value_type> & farr, _Iterator begin, _Iterator end, std::function<_Return(typename const f1a_gettype<_Container_value_type>::type *)> mapper)
	{
		f1a_flatmapped(const_cast<for1array<_Container_value_type> &>(farr), begin, end, mapper);
	}

	// refer temp.log for full version
	template<typename _Container_value_type>
	auto f1a_flatterned(const for1array<_Container_value_type> & farr)
	{
		std::vector<fsize_t> size = f1a_getsize(farr); // size of each dimension of array
		fsize_t sizeflat = fa_getflatsize(size.begin(), size.end());
		std::vector< typename f1a_gettype<_Container_value_type>::type >  ans(sizeflat);

		f1a_flatmapped<_Container_value_type, typename f1a_gettype<_Container_value_type>::type>(
			const_cast<for1array<_Container_value_type> &>(farr), ans.begin(), ans.end()
			, [](typename const f1a_gettype<_Container_value_type>::type * tx) {return *tx; });
		return ans;
	}
	template<typename _Container_value_type>
	auto f1a_flatternedptr(for1array<_Container_value_type> & farr)
		//-> std::vector< typename f1a_gettype<_Container_value_type>::type * > 
	{
		std::vector<fsize_t> size = f1a_getsize(farr); // size of each dimension of array
		fsize_t sizeflat = fa_getflatsize(size.begin(), size.end());
		std::vector< typename f1a_gettype<_Container_value_type>::type *>  ans(sizeflat);
		f1a_flatmapped<_Container_value_type, typename f1a_gettype<_Container_value_type>::type *>(
			farr, ans.begin(), ans.end(), [](typename f1a_gettype<_Container_value_type>::type * tx) {return tx; });
		return ans;
	}
#else

#endif

	template<typename T>
	auto _f1a_init_hiddendo(typename for1array<T>::size_type start, typename for1array<T>::size_type end, std::function<T(typename for1array<T>::size_type) > get_T)
	{
		for1array<T> rt;
		for1array<T>::size_type j = rt.LBound();
		for (auto i = start; i < end; i++, j++) {
			rt(j) = get_T(i);
		}
		return rt;
	}
	template <typename T>
	auto f1a_init_hiddendo(typename for1array<T>::size_type from, typename for1array<T>::size_type to, T lambda)
		-> for1array<typename function_traits<T>::result_type> {
		return _f1a_init_hiddendo<typename function_traits<decltype(lambda)>::result_type>(from, to, lambda);
	}

	template <typename T, int X, int D>
	struct _f1aslice_impl {
		static auto get(const for1array<T> & farr, const slice_info<fsize_t>(&tp)[X]) {
			return _f1aslice_impl<T, X, D - 1>::get(farr.slice(tp[X - D].fr, tp[X - D].to, tp[X - D].step), tp);
		}
	};
	template <typename T, int X>
	struct _f1aslice_impl<T, X, 0> {
		static auto get(const for1array<T> & farr, const slice_info<fsize_t>(&tp)[X]) {
			return farr.slice(tp[X - 1].fr, tp[X - 1].to, tp[X - 1].step);
		}
	};
	
	template <typename T, int DUMMY = 0, int X>
	for1array<T> forslice(const for1array<T> & farr, const slice_info<fsize_t>(&tp)[X]) {
		return _f1aslice_impl<T, X, X - 1>::get(farr, tp);
	}

	//template<int D, typename T>
	//auto forreshape(const std::initializer_list<T> & values, const fsize_t(&shape)[D])
	//{
	//	std::vector<fsize_t> lbound = std::vector<fsize_t>(D, 1);
	//	std::vector<fsize_t> size = std::vector<fsize_t>(shape, shape + D);
	//	return f1a_gen<T, D>(lbound, size, values);
	//}


}

