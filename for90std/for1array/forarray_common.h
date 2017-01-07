#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <string>
#include <array>
#include <random>
#include <tuple>
#include "../forlang.h"
#include "../forutils.h"

#define USE_FORARRAY

namespace for90std {
	typedef int fsize_t;

	template<typename T>
	struct slice_info {
		T fr, to, step;
		slice_info(T i) {
			fr = i; to = i; step = 1;
		}
		slice_info(std::initializer_list<T> il) {
			std::vector<T> l(il);
			if (l.size() == 1)
			{
				fr = l[0]; step = 1; to = l[0];
			}
			else if (l.size() == 2) {
				fr = l[0]; step = 1; to = l[1];
			}
			else if (l.size() == 0) {

			}
			else {
				fr = l[0]; step = l[2]; to = l[1];
			}
		}
		slice_info(const slice_info<T> & x) : fr(x.fr), to(x.to), step(x.step) {
		}
	};
	inline std::string fslice(std::string str, const slice_info<std::string::size_type> & tp) {
		if (tp.to >= str.size()) {
			size_t appendlen = tp.to - str.size() + 2;
			str += std::string(appendlen, ' ');
		}
		if (tp.step == 1) {
			return str.substr(tp.fr, tp.to - tp.fr);
		}
		else {
			std::string newstr;
			for (size_t i = tp.fr; i < tp.to; i += tp.step)
			{
				newstr += str[i];
			}
			return newstr;
		}
	}
#ifdef USE_FORARRAY
	template<typename Iterator>
	std::vector<fsize_t> fa_layer_delta(Iterator begin, Iterator end) {
		std::vector<fsize_t> next_iter_delta(begin, end);
		fsize_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin()
			, [&s](fsize_t x) {fsize_t ans = s; s *= x; return ans; });
		return next_iter_delta;
	}
#else
#endif
	template<typename _Iterator>
	fsize_t fa_getflatsize(_Iterator begin, _Iterator end) {
		fsize_t sizeflat = accumulate(begin, end, 1, [](auto x, auto y) {return x * y; });
		return sizeflat;
	}
}