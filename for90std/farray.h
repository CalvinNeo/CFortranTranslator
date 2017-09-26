#pragma once
#include "forarray_common.h"
#include <memory>
#include <cmath>

namespace for90std {
	template <typename T, int D>
	struct farray {
		typedef T value_type;
		typedef fsize_t size_type; // fortran array index can be negative
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef const value_type * const_pointer;
		typedef const value_type & const_reference;
		typedef size_type difference_type;
		typedef slice_info<typename size_type> slice_type;
		const int DD = D;

		size_type LBound(int dimen) const {
			return lb[dimen];
		};
		size_type UBound(int dimen) const {
			return lb[dimen] + sz[dimen];
		};
		size_type size(int dimen) const {
			return sz[dimen];
		}
		const size_type * LBound() const {
			return lb;
		}
		const size_type * size() const {
			return sz;
		}
		const fsize_t flatsize() const {
			return fa_getflatsize(sz, sz + D);
		}

		template<int X>
		auto & get(const size_type (& index)[X]) {
			std::vector<T>::iterator it = parr->begin();
			std::vector<size_type> delta = fa_layer_delta(sz); // maybe constexpr later
			for (size_type i = 0; i < X; i++)
			{
				it += index[i] * delta[i];
			}
			return *it;
		}

		template<int X>
		auto const_get(const size_type(&index)[X]) {
			std::vector<T>::const_iterator it = parr->begin();
			for (size_type i = 0; i < X; i++)
			{
				it += index[i] * sz[i];
			}
			return *it;
		}
		template<typename... Args>
		auto & operator()(Args&&... args) {
			size_type index[sizeof...(args)] = { args... };
			return get(index);
		}

		template<int X>
		auto & operator[](const slice_type (&index)[X]) {
			return 0;
		}

		farray<T, D> & operator=(const farray<T, D> & x) {
			if (this == &rhs) return *this;

		}
		farray<T, D> & operator+=(const farray<T, D> & x) {

		}

		void clear() {
			parr.reset();
		}

		operator farray<T, 1>() {
			// flattern all to vector
			farray<T, 1> r({ 1 }, { flatsize }, parr->begin(), parr->end());
			return r;
		}
		operator farray<T, 2>() {
			// promote vector to matrix
			farray<T, 2> r({ lb[0], 1 }, { sz[0], 1 }, parr->begin(), parr->end());
			return r;
		}

		void transpose() {
			std::reverse(lb, lb + D);
			std::reverse(sz, sz + D);
			std::reverse(parr->begin(), parr->end());
		}
		
		farray(const size_type * lower_bound, const size_type * size)
		{
			reset_array(lower_bound, size);
		}
		template<int X>
		void reset_array(const slice_info<fsize_t>(&tp)[X], bool force_lower_bound = false) {
			// if X < D, use farr as default from dimension X + 1
			if (force_lower_bound) {
				// lower bound of each dimension(new array) should be forced to 1
				std::transform(tp, tp + X, lb, [](typename slice_info<fsize_t> x) {return 1; });
				if (X < D) {
					for (auto i = X; i < D; i++)
					{
						lb[i] = 1;
					}
				}
			}
			else {
				// lower bound of each dimension(new array)
				std::transform(tp, tp + X, lb, [](typename slice_info<fsize_t> x) {return x.fr; }); 
			}
			std::transform(tp, tp + X, sz.begin(), [](typename slice_info<fsize_t> x) {return (x.to - x.fr) / x.step + ((x.to - x.fr) % x.step == 0 ? 0 : 1); }); // size of each dimension(new array)
		}
		void reset_array(const size_type * lower_bound, const size_type * size) {
			std::copy_n(lower_bound, D, this->lb);
			std::copy_n(size, D, this->sz);
		}
		template <int X>
		farray(const size_type * lower_bound, const size_type * size, const T(&values)[X])
		{
			reset_array(lower_bound, size);
			std::vector<T> * nv = new std::vector<T>(X);
			std::copy_n(values, X, nv->begin());
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		template <typename Iterator>
		farray(const size_type * lower_bound, const size_type * size, Iterator begin, Iterator end)
		{
			reset_array(lower_bound, size);
			std::vector<T> * nv = new std::vector<T>(begin, end);
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		template <int X, typename F>
		farray(const size_type(&from)[X], const size_type(&size)[X], F f) {
			reset_array(from, size);
			// important: second argument is size, not to
			size_type to[X];
			size_type cur[X];
			size_type totalsize = flatsize();
			for (auto i = 0; i < X; i++)
			{
				to[i] = from[i] + size[i];
				cur[i] = from[i];
			}
			std::vector<T> * nv = new std::vector<T>(totalsize);
			parr = std::shared_ptr<std::vector<T>>(nv);
			std::vector<T>::iterator iter = nv->begin();
#ifdef USE_FORARRAY
			int cl = 0; // current layer
			while (true) {
				while (cur[cl] < to[cl]) {
					*iter = f(cur);
					iter++;
					cur[cl] ++;
				}
				while (cur[cl] >= to[cl]) {
					// find innermost layer which isn't to end
					cl++;
					if (cl == X) {
						break; // all finished
					}
				}
				cur[cl]++;
				if (cl >= X || (cl == X - 1 && cur[cl] >= to[cl])) {
					break; // all finished
				}
				std::copy_n(from, cl, cur);
				cl = 0;
			}
#endif
		}
		farray() {

		}
		farray(const farray<T, D> & m) {
			reset_array(m.LBound(), m.size());
			std::vector<T> * nv = new std::vector<T>(m.flatsize());
			std::copy_n(m.parr->begin(), m.flatsize(), nv->begin());
			parr = std::shared_ptr<std::vector<T>>(nv);
		}

		std::shared_ptr<std::vector<T>> parr; // use shared can support inplace operation
	protected:
		size_type lb[D], sz[D];
	};
	template <typename T, int D, int X, typename _Iterator_In, typename _Iterator_Out>
	void _forslice_impl(const farray<T, D> & narr, int deep, const std::vector<typename farray<T, D>::size_type> step_out
		, const std::vector<typename farray<T, D>::size_type> & delta_out, const std::vector<typename farray<T, D>::size_type> & delta_in
		, _Iterator_Out bo, _Iterator_Out eo, _Iterator_In bi, _Iterator_In ei)
	{
		for (typename farray<T, D>::size_type i = narr.LBound(deep); i < narr.UBound(deep); i+= step_out[deep])
		{
			if (deep == D - 1) {
				*bo = *bi;
			}
			else {
				_forslice_impl<T, D, X>(narr, deep + 1, step_out, delta_out, delta_in, bo, bo + delta_out[deep], bi, bi + delta_out[deep]);
			}
			if (i != narr.UBound(deep) - 1) {
				bo += delta_out[deep];
				bi += delta_in[deep];
			}
		}
	};
	template <typename T, int D, int X>
	farray<T, D> forslice(const farray<T, D> & farr, const slice_info<typename farray<T, D>::size_type>(&tp)[X]) {
		farray<T, D> narr(farr.LBound(), farr.size()); 
		narr.reset_array(tp, true);
		//std::vector<typename farray<T, D>::size_type> lbound_out(farr.LBound(), farr.LBound() + D);
		//std::transform(tp, tp + X, lbound_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return x.fr; }); // lower bound of each dimension(new array)
		//std::copy_n(lbound_out.begin(), D, narr.LBound());

		//std::vector<typename farray<T, D>::size_type> size_out(farr.size(), farr.size() + D);
		//std::transform(tp, tp + X, size_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return (x.to - x.fr) / x.step + ((x.to - x.fr) % x.step == 0 ? 0 : 1); }); // size of each dimension(new array)
		//std::copy_n(size_out.begin(), D, narr.size());

		std::vector<typename farray<T, D>::size_type> step_out(D, 1);
		std::transform(tp, tp + X, step_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return x.step; });

		typename farray<T, D>::size_type totalsize = fa_getflatsize(narr.size(), narr.size() + D);
		std::vector<typename farray<T, D>::size_type> delta_out = fa_layer_delta(narr.size(), narr.size() + D);
		std::vector<typename farray<T, D>::size_type> delta_in = fa_layer_delta(farr.size(), farr.size() + D);
		narr.parr = std::shared_ptr<std::vector<T>>(new std::vector<T>(totalsize));
		_forslice_impl<T, D, X>(narr, 0, step_out, delta_out, delta_in, narr.parr.get()->begin(), narr.parr.get()->end(), farr.parr.get()->begin(), farr.parr.get()->end());

		return narr;
	}

	template <typename T, int D_In, int D_Out>
	farray<T, D_Out> forreshape(const farray<T, D_In> & farr, const slice_info<fsize_t>(&newshape)[D_Out]) {
		farray<T, D_Out> narr;
		narr.reset_array(newshape);
		return narr;
	}

	template <typename T, int D>
	auto fortranspose(const farray<T, D> & farr) {
		farray<T, D> narr(farr);
		narr.transpose();
		return narr;
	}

	template <typename T>
	using farray_matcher = func_matcher<T, void, &(T::clear)>*;

	MAKE_TYPE_TEST(farray, farray_matcher)

}

