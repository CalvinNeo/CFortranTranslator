#pragma once
#include "for1array/for1array_def.h"

namespace for90std {
#ifdef USE_FORARRAY
	inline std::vector<for1array_size_t> for1array_layer_delta(const std::vector<for1array_size_t> & size) {
		std::vector<for1array_size_t> next_iter_delta(size);
		for1array_size_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin()
			, [&s](for1array_size_t x) {for1array_size_t ans = s; s *= x; return ans; });
		return next_iter_delta;
	}

	template<typename _DTYPE, typename _Container_value_type, typename _Iterator, typename = void>
	void _for1array_init_layer(
		for1array<_DTYPE> & farr, int deep
		, const std::vector<for1array_size_t> & lower_bound
		, const std::vector<for1array_size_t> & size
		, const std::vector<for1array_size_t> & next_iter_delta
		, _Iterator b, _Iterator e)
	{
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
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
		void _for1array_init_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<for1array_size_t> & lower_bound
			, const std::vector<for1array_size_t> & size
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e)
	{
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			_for1array_init_layer<_DTYPE, typename _Container_value_type::value_type, _Iterator>(farr(i), deep + 1, lower_bound, size
				, next_iter_delta, iter, iter + next_iter_delta[deep]);
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _DTYPE, typename _Container_value_type>
	void for1array_init(
		for1array<_Container_value_type> & farr
		, const std::vector<for1array_size_t> & lower_bound
		, const std::vector<for1array_size_t> & size
		, const std::initializer_list<_DTYPE> & values)
	{
		/* NOTE: assume the array is already allocated and no need to clear */
		std::vector<for1array_size_t> next_iter_delta = for1array_layer_delta(size);
		_for1array_init_layer<_DTYPE, _Container_value_type, std::initializer_list<_DTYPE>::const_iterator >(farr, 0, lower_bound, size
			, next_iter_delta, values.begin(), values.end());
	};

	template<typename _InnerT, int D>
	fornarray<_InnerT, D> for1array_gen(
		const std::vector<for1array_size_t> & lower_bound
		, const std::vector<for1array_size_t> & size
		, const std::initializer_list<_InnerT> & values)
	{
		fornarray<_InnerT, D> n;
		for1array_init(n, lower_bound, size, values);
		return n;
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return, typename = void>
	void _for1array_flatmapped_layer(
		for1array<_DTYPE> & farr, int deep
		, const std::vector<for1array_size_t> & next_iter_delta
		, _Iterator b, _Iterator e
		, std::function<_Return(typename _DTYPE *)> mapper)
	{
		auto iter = b;
		for (auto i = farr.LBound(); i < farr.UBound(); i++)
		{
			(*iter) = mapper(&(farr.get(i)));
			if (i != farr.UBound() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size())> >
		void _for1array_flatmapped_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, std::function<_Return(typename _DTYPE *)> mapper)
	{
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		for (auto i = farr.LBound(); i < farr.UBound(); i++)
		{
			/* NOTE: assume the array is already allocated and no need to clear */
			_for1array_flatmapped_layer<typename _Container_value_type::value_type, _DTYPE, _Iterator>(
				farr(i), deep + 1, next_iter_delta, iter, iter + next_iter_delta[deep], mapper);
			if (i != farr.UBound() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _Return>
	auto for1array_flatmapped(for1array<_Container_value_type> & farr, std::function<_Return(typename for1array_gettype<_Container_value_type>::type *)> mapper)
		-> std::vector< _Return >
	{
		typedef typename for1array_gettype<_Container_value_type>::type T; // inner most type
		std::vector<for1array_size_t> size = for1array_getsize(farr); // size of each dimension of array
		for1array_size_t sizeflat = accumulate(size.begin(), size.end(), 1, [](auto x, auto y) {return x * y; });
		std::vector< _Return > flat(sizeflat); // size of flatterned array
		std::vector<for1array_size_t> next_iter_delta = for1array_layer_delta(size);
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_for1array_flatmapped_layer<_New_value_type, T, std::vector<_Return>::iterator >(farr, 0, next_iter_delta, flat.begin(), flat.end(), mapper);
		return flat;
	};

	template<typename _Container_value_type, typename _Return>
	auto for1array_flatmapped_const(const for1array<_Container_value_type> & farr, std::function<_Return(typename const for1array_gettype<_Container_value_type>::type *)> mapper)
		->std::vector< _Return >
	{
		return for1array_flatmapped(const_cast<for1array<_Container_value_type> &>(farr), mapper);
	}

	// refer temp.log for full version
	template<typename _Container_value_type>
	auto for1array_flatterned(const for1array<_Container_value_type> & farr)
		//-> std::vector< typename for1array_gettype<_Container_value_type>::type > 
	{
		return for1array_flatmapped<_Container_value_type, typename for1array_gettype<_Container_value_type>::type>(
			const_cast<for1array<_Container_value_type> &>(farr), [](typename const for1array_gettype<_Container_value_type>::type * tx) {return *tx; });
	}
	template<typename _Container_value_type>
	auto for1array_flatternedptr(for1array<_Container_value_type> & farr)
		//-> std::vector< typename for1array_gettype<_Container_value_type>::type * > 
	{
		return for1array_flatmapped<_Container_value_type, typename for1array_gettype<_Container_value_type>::type *>(
			farr, [](typename for1array_gettype<_Container_value_type>::type * tx) {return tx; });
	}

	template<typename _Container_value_type>
	void for1array_mapdim(for1array<_Container_value_type> & farr, std::function<void(typename for1array_gettype<_Container_value_type>::type &)> mapper) {

	}
#else
	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<T> & farr, const std::vector<for1array_size_type_t> & lower_bound, int deep
			, const std::vector<for1array_size_type_t> & size
			, const std::vector<for1array_size_type_t> & next_iter_delta
			, _Iterator b, _Iterator e, .../* SFINAE */) {
		auto iter = b;
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			farr(i) = *iter;
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	}

	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(for1array<_Container_value_type> & farr, const std::vector<for1array_size_type_t> & lower_bound, int deep
			, const std::vector<for1array_size_type_t> & size
			, const std::vector<for1array_size_type_t> & next_iter_delta
			, _Iterator b, _Iterator e, for1array_matcher<_Container_value_type>/* SFINAE */) {
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			/* NOTE: assume the array is already allocated and no need to clear */
			_init_for1array_layer<T, typename _Container_value_type::value_type, _Iterator>(farr(i), lower_bound, deep + 1, size
				, next_iter_delta, iter, iter + next_iter_delta[deep], nullptr);
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	}

	template<typename T, typename _Container_value_type>
	void for1array_init(for1array<_Container_value_type> & farr, const std::vector<for1array_size_type_t> & lower_bound
		, const std::vector<for1array_size_type_t> & size, const std::vector<T> & values) {
		/* NOTE: assume the array is already allocated and no need to clear */
		std::vector<for1array_size_type_t> next_iter_delta(size);
		for1array_size_type_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin(), [&s](int x) {int ans = s; s *= x; return ans; });
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_init_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size
			, next_iter_delta, values.begin(), values.end(), nullptr);
	}
}
#endif
	template<typename T>
	auto _for1array_init_hiddendo(typename for1array<T>::size_type start, typename for1array<T>::size_type end, std::function<T(typename for1array<T>::size_type) > get_T)
	{
		for1array<T> rt;
		for (auto i = start; i < end; i++) {
			rt(i) = get_T(i);
		}
		return rt;
	}

	template <typename T>
	auto for1array_init_hiddendo(typename for1array<T>::size_type from, typename for1array<T>::size_type to, T lambda)
		-> for1array<typename function_traits<T>::result_type> {
		return _for1array_init_hiddendo<function_traits<decltype(lambda)>::result_type>(from, to, lambda);
	}

	template <typename T>
	for1array<T> slice(const for1array<T> & farr, typename foroptional<typename for1array<T>::size_type> fr, typename foroptional<typename for1array<T>::size_type> to, typename for1array<T>::size_type step = 1) {
		typename for1array<T>::size_type f, t;
		if (!fr.inited()) {
			f = farr.LBound();
		}
		else {
			f = fr.get();
		}
		if (!to.inited()) {
			t = farr.UBound() - 1;
		}
		else {
			t = to.get();
		}
		return farr.slice(f, t, step);
	}

	inline std::string slice(std::string str, std::string::size_type fr, std::string::size_type to, std::string::size_type step = 1) {
		if (to >= str.size()) {
			size_t appendlen = to - str.size() + 2;
			str += std::string(appendlen, ' ');
		}
		if (step == 1) {
			return str.substr(fr, to - fr);
		}
		else {
			std::string newstr;
			for (size_t i = fr; i < to; i+= step)
			{
				newstr += str[i];
			}
			return newstr;
		}
	}


	template<int D, typename T>
	auto forreshape(const std::initializer_list<T> & values, const for1array_size_t(&shape)[D])
	{
		std::vector<for1array_size_t> lbound = std::vector<for1array_size_t>(D, 1);
		std::vector<for1array_size_t> size = std::vector<for1array_size_t>(shape, shape + D);
		return for1array_gen<T, D>(lbound, size, values);
	}

	template <typename T>
	fornarray<T, 2> fortranspose(const for1array<T> & farr) {

	}

	// 1d vector -> 2d matrix
	template <typename T>
	fornarray<T, 2> for1array_promote(const fornarray<T, 1> & farr) {

	}


//
//#define forarray for1array
//#define init_forarray for1array_init
//#define gen_forarray gen_for1array
}

