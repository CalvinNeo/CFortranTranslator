#pragma once
#include "for1array/forarray_common.h"
#include <memory>
#include <valarray>
#include <cmath>

namespace for90std {
	template <typename T, int D>
	struct farray {
		typedef T value_type;
		typedef fa_size_t size_type; // for1array index can be negative
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
		size_type * LBound() {
			return lb;
		}
		size_type * size() {
			return sz;
		}
		const size_type * cLBound() const {
			return lb;
		}
		const size_type * csize() const {
			return sz;
		}

		template<int X>
		auto & get(const size_type (& index)[X]) {
			std::vector<T>::iterator it = parr->begin();
			std::vector<size_type> delta = f1a_layer_delta(sz); // maybe constexpr later
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

		}
		farray<T, D> & operator+=(const farray<T, D> & x) {

		}

		void clear() {
			parr.reset();
		}

		farray(const size_type * lower_bound, const size_type * size)
		{
			std::copy_n(lower_bound, D, this->lb);
			std::copy_n(size, D, this->sz);
		}
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D])
		{
			std::copy_n(lower_bound, D, this->lb);
			std::copy_n(size, D, this->sz);
		}
		template <int X>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X])
		{
			std::copy_n(lower_bound, D, this->lb);
			std::copy_n(size, D, this->sz);
			std::vector<T> * nv = new std::vector<T>(X);
			std::copy_n(values, X, nv->begin());
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		farray() {

		}
		farray(const farray<T, D> & m) {
			std::copy_n(m.cLBound(), D, this->lb);
			std::copy_n(m.csize(), D, this->sz);
			std::vector<T> * nv = new std::vector<T>(*m.parr.get());
			std::copy_n(m.parr.get()->begin(), m.parr.get()->size(), nv->begin());
			parr = std::shared_ptr<std::vector<T>>(nv);
		}

		std::shared_ptr<std::vector<T>> parr; // use shared can support inplace operation
	protected:
		size_type lb[D], sz[D];
	};
	template <typename T, int D, int X, typename _Iterator_In, typename _Iterator_Out>
	void _fslice_impl(const farray<T, D> & narr, int deep, const std::vector<typename farray<T, D>::size_type> step_out
		, const std::vector<typename farray<T, D>::size_type> & delta_out, const std::vector<typename farray<T, D>::size_type> & delta_in
		, _Iterator_Out bo, _Iterator_Out eo, _Iterator_In bi, _Iterator_In ei)
	{
		for (typename farray<T, D>::size_type i = narr.LBound(deep); i < narr.UBound(deep); i+= step_out[deep])
		{
			if (deep == D - 1) {
				*bo = *bi;
			}
			else {
				_fslice_impl<T, D, X>(narr, deep + 1, step_out, delta_out, delta_in, bo, bo + delta_out[deep], bi, bi + delta_out[deep]);
			}
			if (i != narr.UBound(deep) - 1) {
				bo += delta_out[deep];
				bi += delta_in[deep];
			}
		}
	};
	template <typename T, int D, int X>
	farray<T, D> fslice(const farray<T, D> & farr, const slice_info<typename farray<T, D>::size_type>(&tp)[X]) {
		farray<T, D> narr(farr.cLBound(), farr.csize());
		std::vector<typename farray<T, D>::size_type> lbound_out(farr.cLBound(), farr.cLBound() + D);
		std::transform(tp, tp + X, lbound_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return x.fr; }); // lower bound of each dimension(new array)
		std::copy_n(lbound_out.begin(), D, narr.LBound());

		std::vector<typename farray<T, D>::size_type> size_out(farr.csize(), farr.csize() + D);
		std::transform(tp, tp + X, size_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return (x.to - x.fr) / x.step + ((x.to - x.fr) % x.step == 0 ? 0 : 1); }); // size of each dimension(new array)
		std::copy_n(size_out.begin(), D, narr.size());
		typename farray<T, D>::size_type totalsize = std::accumulate(size_out.begin(), size_out.end(), 1, [](auto x, auto y) {return x * y; });

		std::vector<typename farray<T, D>::size_type> step_out(D, 1);
		std::transform(tp, tp + X, step_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return x.step; });

		std::vector<typename farray<T, D>::size_type> delta_out = f1a_layer_delta(narr.csize(), narr.csize() + D);
		std::vector<typename farray<T, D>::size_type> delta_in = f1a_layer_delta(farr.csize(), farr.csize() + D);
		narr.parr = std::shared_ptr<std::vector<T>>(new std::vector<T>(totalsize));
		_fslice_impl<T, D, X>(narr, 0, step_out, delta_out, delta_in, narr.parr.get()->begin(), narr.parr.get()->end(), farr.parr.get()->begin(), farr.parr.get()->end());

		return narr;
	}
}

