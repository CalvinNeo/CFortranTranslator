#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <string>
#include <array>
#include <random>
#include <tuple>
#include "forlang.h"
#include "forutils.h"

#define USE_FORARRAY

namespace for90std {
	typedef int fsize_t;

	template<typename T>
	struct slice_info {
		T fr, to, step;
		bool isslice;
		bool isall;
		// [from, to]
		slice_info() {
			// select all
			isslice = true;
			isall = true;
		}
		slice_info(T i) {
			// a single element, not slice
			fr = i; to = i; step = 1;
			isslice = false;
		}
		slice_info(std::initializer_list<T> il) {
			std::vector<T> l(il);
			if (l.size() == 1)
			{
				// a single element, not slice
				fr = l[0]; step = 1; to = l[0];
				isslice = false;
			}
			else if (l.size() == 2) {
				fr = l[0]; step = 1; to = l[1];
				isslice = true;
			}
			else if (l.size() == 0) {
				// select all
				isslice = true;
				isall = true;
			}
			else {
				fr = l[0]; step = l[2]; to = l[1];
				isslice = true;
			}
		}
		slice_info(const slice_info<T> & x) : fr(x.fr), to(x.to), step(x.step) {
		}
	};
	inline std::string forslice(std::string str, const slice_info<std::string::size_type> & tp) {
		if (tp.to >= str.size()) {
			size_t appendlen = tp.to + 1- str.size() + 1;
			str += std::string(appendlen, ' ');
		}
		if (tp.step == 1) {
			return str.substr(tp.fr, tp.to - tp.fr + 1);
		}
		else {
			std::string newstr;
			for (size_t i = tp.fr; i <= tp.to; i += tp.step)
			{
				newstr += str[i];
			}
			return newstr;
		}
	}
#ifdef USE_FORARRAY
	template<typename Iterator>
	std::vector<fsize_t> fa_layer_delta(Iterator size_begin, Iterator size_end) {
		std::vector<fsize_t> next_iter_delta(size_begin, size_end);
		fsize_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin()
			, [&s](fsize_t x) {fsize_t ans = s; s *= x; return ans; });
		return next_iter_delta;
	}	
	template<typename In_Iter, typename Out_Iter>
	void fa_layer_delta(In_Iter size_begin, In_Iter size_end, Out_Iter out_begin) {
		fsize_t s = 1;
		std::transform(size_begin, size_end, out_begin, [&s](fsize_t x) {fsize_t ans = s; s *= x; return ans; });
	}
#else
#endif
	template<typename _Iterator>
	fsize_t fa_getflatsize(_Iterator b, _Iterator e) {
		fsize_t sizeflat = accumulate(b, e, 1, [](auto x, auto y) {return x * y; });
		return sizeflat;
	}
}