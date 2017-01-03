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
	typedef int f1a_size_t;

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
			else {
				fr = l[0]; step = l[2]; to = l[1];
			}
		}
		slice_info(const slice_info<T> & x) : fr(x.fr), to(x.to), step(x.step) {
		}
	};
#ifdef USE_FORARRAY
	template<typename Iterator>
	std::vector<f1a_size_t> f1a_layer_delta(Iterator begin, Iterator end) {
		std::vector<f1a_size_t> next_iter_delta(begin, end);
		f1a_size_t s = 1;
		std::transform(next_iter_delta.begin(), next_iter_delta.end(), next_iter_delta.begin()
			, [&s](f1a_size_t x) {f1a_size_t ans = s; s *= x; return ans; });
		return next_iter_delta;
	}
#else
#endif
}