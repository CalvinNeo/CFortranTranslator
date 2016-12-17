#pragma once
#include "for1array/for1array_def.h"
#include "for1array/for1array_forstyle.h"
#include "for1array/for1array_cstyle.h"

namespace for90std {
	//template<typename T>
	//for1array<T> init_for1array_hiddendo(int start, int end, std::function<T(int) > get_T) {
	//for1array<T> init_for1array_hiddendo(int start, int end, T (*get_T)(int) ) {
	template<typename T>
	auto _init_for1array_hiddendo(typename for1array<T>::size_type start, typename for1array<T>::size_type end, std::function<T(typename for1array<T>::size_type) > get_T)
	{
		std::vector<T> nvec;
		for (int i = start; i < end; i++) {
			nvec.push_back(get_T(i));
		}
		for1array<T> rt(nvec, start, end);
		return rt;
	}

	template <typename T>
	auto init_for1array_hiddendo(typename for1array<T>::size_type from, typename for1array<T>::size_type to, T lambda)
		-> for1array<typename function_traits<T>::result_type> {
		return _init_for1array_hiddendo<function_traits<decltype(lambda)>::result_type>(from, to, lambda);
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
	
	
	template<typename T, int D>
	fornarray<T, D> forreshape(const for1array<T> & farr, std::vector<int> shape) {

	}

//
//#define forarray for1array
//#define init_forarray init_for1array
//#define gen_forarray gen_for1array
}

