#pragma once

#include "for1array_def.h"

#ifdef USE_FORARRAY
namespace for90std {

	template<typename T
		, typename _Container_value_type
		, typename _Iterator>
		void _init_for1array_layer(
			for1array<T> & farr
			, const std::vector<for1array_size_type_t> & lower_bound
			, int deep
			, const std::vector<for1array_size_type_t> & size
			, const std::vector<for1array_size_type_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, .../* SFINAE */) {
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
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
		void _init_for1array_layer(
			for1array<_Container_value_type> & farr
			, const std::vector<for1array_size_type_t> & lower_bound
			, int deep
			, const std::vector<for1array_size_type_t> & size
			, const std::vector<for1array_size_type_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, for1array_matcher<_Container_value_type>/* SFINAE */) {
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
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
	void init_for1array(
		for1array<_Container_value_type> & farr
		, const std::vector<for1array_size_type_t> & lower_bound
		, const std::vector<for1array_size_type_t> & size
		, const std::vector<T> & values) {
		/* NOTE: assume the array is already allocated and no need to clear */
		std::vector<for1array_size_type_t> next_iter_delta(size);
		for1array_size_type_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin()
			, [&s](for1array_size_type_t x) {for1array_size_type_t ans = s; s *= x; return ans; });
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_init_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size
			, next_iter_delta, values.begin(), values.end(), nullptr);
	}

	template<typename T, typename _Container_value_type>
	for1array<_Container_value_type> gen_for1array(
		const for1array<_Container_value_type> & farr
		, const std::vector<for1array_size_type_t> & lower_bound
		, const std::vector<for1array_size_type_t> & size
		, const std::vector<T> & values) {
		for1array<_Container_value_type> n;
		return init_for1array(n, lower_bound, size, values);
	}

	//template<typename _Container_value_type
	//	, typename T>
	//	void _flattern_for1array_layer(
	//		for1array<T> & farr
	//		, int deep
	//		, const std::vector<int> & next_iter_delta
	//		, .../* SFINAE */) {
	//	auto iter = b;
	//	for (auto i = farr.LBound(); i < farr.UBound(); i++)
	//	{
	//		farr(i) = *iter;
	//		if (i != farr.UBound() - 1) {
	//			iter += next_iter_delta[deep]
	//		}
	//	}
	//}

	//template<typename _Container_value_type
	//	, typename T>
	//	void _flattern_for1array_layer(
	//		for1array<_Container_value_type> & farr
	//		, int deep
	//		, const std::vector<int> & next_iter_delta
	//		, for1array_matcher<_Container_value_type>/* SFINAE */) {
	//	/* deep can never be equal to size.size() - 1 */
	//	auto iter = b;
	//	for (auto i = farr.LBound(); i < farr.UBound(); i++)
	//	{
	//		/* NOTE: assume the array is already allocated and no need to clear */
	//		_flattern_for1array_layer<typename _Container_value_type::value_type, T>(farr(i), deep + 1,
	//			, next_iter_delta, iter, iter + next_iter_delta[deep], nullptr);
	//		if (i != farr.UBound() - 1) {
	//			iter += next_iter_delta[deep];
	//		}
	//	}
	//}

	//template<typename _Container_value_type
	//	, typename T>
	//	void flattern_for1array(
	//		for1array<_Container_value_type> & farr
	//		, std::vector<T> values) {
	//		/* NOTE: assume the array is already allocated and no need to clear */
	//	std::vector<for1array_size_type_t> size = for1array_getsize(farr);
	//	typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
	//	_flattern_for1array_layer<T, _New_value_type, std::vector<T>::const_iterator >(farr, lower_bound, 0, size,
	//		, next_iter_delta, values.begin(), values.end(), nullptr);
	//}

	template<typename _Container_value_type>
		std::vector<for1array_size_type_t> _for1array_getsize_layer(for1array<_Container_value_type> & farr
			, std::vector<for1array_size_type_t> & size , .../* SFINAE */) {
		size.push_back(farr.size());
		return size;
	}

	template<typename _Container_value_type>
		std::vector<for1array_size_type_t> _for1array_getsize_layer(for1array<_Container_value_type> & farr
			, std::vector<for1array_size_type_t> & size, for1array_matcher<_Container_value_type>/* SFINAE */) {
		size.push_back(farr.size());
		_for1array_getsize_layer<typename _Container_value_type::value_type>(farr(farr.LBound()), size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<for1array_size_type_t> for1array_getsize(for1array<_Container_value_type> & farr) {
		std::vector<for1array_size_type_t> size;
		_for1array_getsize_layer<_Container_value_type>(farr, size, nullptr);
		return size;
	}
}
#endif