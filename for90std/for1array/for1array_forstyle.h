#pragma once

#include "for1array_def.h"

#ifdef USE_FORARRAY
namespace for90std {

	template<typename T
		, typename _Container_value_type
		, typename _Iterator
		, typename = void
	>
		void _for1array_init_layer(
			for1array<T> & farr, int deep
			, const std::vector<for1array_size_t> & lower_bound
			, const std::vector<for1array_size_t> & size
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
		)
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

	template<typename T
		, typename _Container_value_type
		, typename _Iterator
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size()) >
	>
		void _for1array_init_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<for1array_size_t> & lower_bound
			, const std::vector<for1array_size_t> & size
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
		)
	{
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			_for1array_init_layer<T, typename _Container_value_type::value_type, _Iterator>(farr(i), deep + 1, lower_bound, size
				, next_iter_delta, iter, iter + next_iter_delta[deep]);
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename T, typename _Container_value_type>
	void for1array_init(
		for1array<_Container_value_type> & farr
		, const std::vector<for1array_size_t> & lower_bound
		, const std::vector<for1array_size_t> & size
		, const std::initializer_list<T> & values)
	{
		/* NOTE: assume the array is already allocated and no need to clear */
		std::vector<for1array_size_t> next_iter_delta(size);
		for1array_size_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin(), [&s](for1array_size_t x) {for1array_size_t ans = s; s *= x; return ans; });
		//typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_for1array_init_layer<T, _Container_value_type, std::initializer_list<T>::const_iterator >(farr, 0, lower_bound, size
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

	template<typename _Container_value_type
		, typename T
		, typename _Iterator
		, typename _Return>
		void _for1array_flatmapped_layer(
			for1array<T> & farr, int deep
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, std::function<_Return(typename T *)> mapper
			, .../* SFINAE */) 
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

	template<typename _Container_value_type
		, typename T
		, typename _Iterator
		, typename _Return >
		void _for1array_flatmapped_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<for1array_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, std::function<_Return(typename T *)> mapper
			, for1array_matcher<_Container_value_type>/* SFINAE */) 
	{
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		for (auto i = farr.LBound(); i < farr.UBound(); i++)
		{
			/* NOTE: assume the array is already allocated and no need to clear */
			_for1array_flatmapped_layer<typename _Container_value_type::value_type, T, _Iterator>(
				farr(i), deep + 1, next_iter_delta, iter, iter + next_iter_delta[deep], mapper, nullptr);
			if (i != farr.UBound() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type
		, typename _Return>
	auto for1array_flatmapped(for1array<_Container_value_type> & farr, std::function<_Return(typename for1array_gettype<_Container_value_type>::type *)> mapper)
		-> std::vector< _Return >
	{
		typedef typename for1array_gettype<_Container_value_type>::type T; // inner most type
		std::vector<for1array_size_t> size = for1array_getsize(farr); // size of each dimension of array
		for1array_size_t sizeflat = accumulate(size.begin(), size.end(), 1, [](auto x, auto y) {return x * y; });
		std::vector< _Return > flat(sizeflat); // size of flatterned array
		std::vector<for1array_size_t> next_iter_delta(size); // copy from size to compute		
		for1array_size_t s = 1; std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin(), [&s](for1array_size_t x) {for1array_size_t ans = s; s *= x; return ans; });
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_for1array_flatmapped_layer<_New_value_type, T, std::vector<_Return>::iterator >(farr, 0, next_iter_delta, flat.begin(), flat.end(), mapper, nullptr);
		return flat;
	};

	// refer temp.log for full version
	template<typename _Container_value_type>
	auto for1array_flatterned(const for1array<_Container_value_type> & farr)
		//-> std::vector< typename for1array_gettype<_Container_value_type>::type > 
	{
		return for1array_flatmapped<_Container_value_type, typename for1array_gettype<_Container_value_type>::type>(
			const_cast<for1array<_Container_value_type> &>(farr), [](typename for1array_gettype<_Container_value_type>::type * tx) {return *tx; });
	}
	template<typename _Container_value_type>
	auto for1array_flatternedptr(for1array<_Container_value_type> & farr)
		//-> std::vector< typename for1array_gettype<_Container_value_type>::type * > 
	{
		return for1array_flatmapped<_Container_value_type, typename for1array_gettype<_Container_value_type>::type *>(
			farr, [](typename for1array_gettype<_Container_value_type>::type * tx) {return tx; });
	}

}
#endif