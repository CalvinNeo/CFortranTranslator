#pragma once
#include "for1array/for1array_def.h"
#include "for1array/for1array_forstyle.h"
#include "for1array/for1array_cstyle.h"

namespace for90std {
	//template<typename T>
	//for1array<T> for1array_init_hiddendo(int start, int end, std::function<T(int) > get_T) {
	//for1array<T> for1array_init_hiddendo(int start, int end, T (*get_T)(int) ) {
	template<typename T>
	auto _for1array_init_hiddendo(typename for1array<T>::size_type start, typename for1array<T>::size_type end, std::function<T(typename for1array<T>::size_type) > get_T)
	{
		std::vector<T> nvec;
		for (int i = start; i < end; i++) {
			nvec.push_back(get_T(i));
		}
		for1array<T> rt(nvec, start, end);
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
	//template <typename T>
	//fornarray<T, 2> operator fornarray<T, 2>(const fornarray<T, 1> & farr) {

	//}

//
//#define forarray for1array
//#define init_forarray for1array_init
//#define gen_forarray gen_for1array
}

