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
		const int dimension = D;
		typedef typename std::vector<T>::iterator iterator;
		typedef typename std::vector<T>::const_iterator const_iterator;
		typedef typename std::vector<T>::reverse_iterator reverse_iterator;
		typedef typename std::vector<T>::iterator const_reverse_iterator;

		size_type LBound(int dim) const {
			return lb[dim];
		};
		size_type UBound(int dim) const {
			return lb[dim] + sz[dim] - 1;
		};
		size_type size(int dim) const {
			return sz[dim];
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

		iterator begin() {
			return parr->begin();
		}
		iterator end() {
			return parr->end();
		}
		const_iterator cbegin() const {
			return parr->cbegin();
		}
		const_iterator cend() const  {
			return parr->cend();
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
			if (this == &x) return *this;
			parr.reset();
			reset_array(x.LBound(), x.size());
			reset_value(x.cbegin(), x.cend());
			return *this;
		}
		template <int I>
		struct Int2Type
		{
			enum { value = I };
		};
		typedef typename std::conditional<D == 1, std::true_type, std::false_type>::type is_vector_t;
		farray<T, D> & operator+=(const farray<T, D> & x) {
			return _pluseq_impl(x, is_vector_t());
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
		void reset_value(fsize_t X, const T * values) {
			std::vector<T> * nv = new std::vector<T>(X);
			std::copy_n(values, X, nv->begin());
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		template <typename Iterator>
		void reset_value(Iterator begin, Iterator end) {
			std::vector<T> * nv = new std::vector<T>(begin, end);
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		void reset_value(fsize_t X) {
			std::vector<T> * nv = new std::vector<T>(X);
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		farray(const T & scalar) {
			// ISO/IEC 1539:1991 1.5.2
			// A scalar is conformable with any array
			// A rank-one array may be constructed from scalars and other arrays and may be reshaped into any allowable array shape
			std::fill_n(lb, D, 1);
			std::fill_n(sz, D, 1);
			std::vector<T> * nv = new std::vector<T>{scalar};
			parr = std::shared_ptr<std::vector<T>>(nv);
		}
		template <int X>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X])
		{
			reset_array(lower_bound, size);
			reset_value(X, values);
		}
		template <typename Iterator>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end)
		{
			reset_array(lower_bound, size);
			reset_value(begin, end);
		}

		template <typename F>
		void map(F f) const {
			_map_impl<const farray<T, D>&, F>(*this, f, cbegin());
		}
		template <typename F>
		void map(F f) {
			_map_impl<farray<T, D>&, F>(*this, f, begin());
		}
		template <int X, typename F/*, typename = std::enable_if_t<std::is_callable<F, size_type>::value>*/>
		farray(const size_type(&from)[X], const size_type(&size)[X], F f) {
			reset_array(from, size);
			// important: second argument is size, not to
			size_type totalsize = flatsize();
			reset_value(totalsize);
			map([&](T & item, const fsize_t(&cur)[D]) {item = f(cur); });
		}
		farray() {

		}
		farray(const farray<T, D> & m) {
			reset_array(m.LBound(), m.size());
			reset_value(m.cbegin(), m.cend());
		}

		std::shared_ptr<std::vector<T>> parr; // use shared can support inplace operation

	protected:
		size_type lb[D], sz[D];


		farray<T, D> & _pluseq_impl(const farray<T, D> & x, std::true_type) {
			// D = 1: 1-dimension vector
		}
		farray<T, D> & _pluseq_impl(const farray<T, D> & x, std::false_type) {
			// D != 1: normal farray
		}		

		template <typename THIS, typename F, typename Iterator>
		static void _map_impl(THIS me, F f, Iterator iter) {
			size_type cur[D];
			std::copy_n(me.LBound(), D, cur);
#ifdef USE_FORARRAY
			int dim = 0; // current dimension
			while (true) {
				while (cur[dim] < me.LBound(dim) + me.size(dim)) {
					f(*iter, cur);
					iter++;
					cur[dim] ++;
				}
				while (cur[dim] + 1>= me.LBound(dim) + me.size(dim)) {
					// find innermost dimension which isn't to end
					dim++;
					if (dim == D) {
						break; // all finished
					}
				}
				if (dim < D) {
					cur[dim]++;
				}
				else {
					break; // all finished
				}
				std::copy_n(me.LBound(), dim, cur); // reset cur
				dim = 0;
			}
#endif
		}
	};
	template <typename T, int D, int X, typename _Iterator_In, typename _Iterator_Out>
	void _forslice_impl(const farray<T, D> & narr, int deep, const std::vector<typename farray<T, D>::size_type> step_out
		, const std::vector<typename farray<T, D>::size_type> & delta_out, const std::vector<typename farray<T, D>::size_type> & delta_in
		, _Iterator_Out bo, _Iterator_Out eo, _Iterator_In bi, _Iterator_In ei)
	{
		for (typename farray<T, D>::size_type i = narr.LBound(deep); i < narr.LBound(deep) + narr.size(deep); i+= step_out[deep])
		{
			if (deep == D - 1) {
				*bo = *bi;
			}
			else {
				_forslice_impl<T, D, X>(narr, deep + 1, step_out, delta_out, delta_in, bo, bo + delta_out[deep], bi, bi + delta_out[deep]);
			}
			if (i != narr.LBound(deep) + narr.size(deep) - 1) {
				bo += delta_out[deep];
				bi += delta_in[deep];
			}
		}
	};
	template <typename T, int D, int X>
	farray<T, D> forslice(const farray<T, D> & farr, const slice_info<typename farray<T, D>::size_type>(&tp)[X]) {
		// TODO by fortran standard, slice must return by ref, now by val
		farray<T, D> narr(farr.LBound(), farr.size()); 
		narr.reset_array(tp, true);

		std::vector<typename farray<T, D>::size_type> step_out(D, 1);
		std::transform(tp, tp + X, step_out.begin(), [](typename slice_info<typename farray<T, D>::size_type> x) {return x.step; });

		typename farray<T, D>::size_type totalsize = fa_getflatsize(narr.size(), narr.size() + D);
		std::vector<typename farray<T, D>::size_type> delta_out = fa_layer_delta(narr.size(), narr.size() + D);
		std::vector<typename farray<T, D>::size_type> delta_in = fa_layer_delta(farr.size(), farr.size() + D);
		narr.parr = std::shared_ptr<std::vector<T>>(new std::vector<T>(totalsize));
		_forslice_impl<T, D, X>(narr, 0, step_out, delta_out, delta_in, narr->begin(), narr->end(), farr->begin(), farr->end());

		return narr;
	}
	
	template <typename T, int D>
	auto fortranspose(const farray<T, D> & farr) {
		farray<T, D> narr(farr);
		narr.transpose();
		return narr;
	}
	
	template <typename T, int D>
	auto forlbound(const farray<T, D> & farr, int fordim = 1) {
		return farr.LBound(fordim - 1);
	}
	
	template <typename T, int D>
	auto forubound(const farray<T, D> & farr, int fordim = 1) {
		return farr.UBound(fordim - 1);
	}

	template <typename T, int D>
	farray<fsize_t, 1> forshape(const farray<T, D> & farr, int fordim = 1) {
		farray<fsize_t, 1> r = farray<fsize_t, 1>({ 1 }, { D }, farr.size(), farr.size() + D);
		return r;
	}

	template <typename T, int X, int D>
	auto forreshape(const T(&value)[X], const fsize_t(&shape)[D]){
		fsize_t lb[D];
		std::fill_n(lb, D, 1);
		farray<T, D> r = farray<T, D>(lb, shape, value , value + X);
		return r;
	}

	template <typename T, int D>
	auto forsize(const farray<T, D> & farr, int fordim = 1) {
		return farr.size(fordim - 1);
	}

	template <typename T, int D>
	void forvectorize(const farray<T, D> & farr, int dim ) {

	}

	template <typename T>
	using mask_wrapper = std::function<bool(T)>;

	template <typename T, int D>
	auto forsum(const farray<T, D> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		CHECK_AND_SET(fordim, 1)
		// do not need to CHECK_AND_SET mask because it's the last parameter
		return 0;
	}	
	
	template <typename T, int D>
	auto forproduct(const farray<T, D> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		CHECK_AND_SET(fordim, 1)
		return 0;
	}


	template <typename T, int D>
	auto forreorganize(const farray<T, D> & farr, int dim) {
		std::vector<fsize_t> delta = fa_layer_delta(farr.size(), farr.size() + farr.dimension);
		std::vector<T> new_vec(farr.flatsize());
		auto iter = farr.cbegin();
		for (fsize_t back = 0; back < delta[farr.dimension - 1] / delta[dim]; back++)
		{
			for (fsize_t dim_current = 0; dim_current < farr.size(dim); dim_current++)
			{
				// delta[0..(dim-1)]
				fsize_t dim_index = dim_current + farr.LBound(dim);
				if (dim > 0) {
					for (fsize_t front = 0; front < delta[dim - 1]; front++)
					{
						iter++;
					}
				}
				else {
					iter++;
				}
			}
		}
	}

	template <typename T, int D>
	auto formaxloc(const farray<T, D> & farr, foroptional<int> fordim, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		// return maxvalue of every subarray
		int dim = fordim - 1;
		std::vector<T> maxv(farr.size(dim));
		std::vector<bool> vis(farr.size(dim));
		std::vector<std::array<fsize_t, D - 1>> loc(farr.size(dim));

		farr.map([&](const T & item, const fsize_t(&cur)[D]) {
			size_t plain_index = cur[dim] - farr.LBound(dim);
			if (!vis[plain_index]  || maxv[plain_index] < item) {
				int k = 0;
				for (auto j = 0; j < D; j++)
				{
					if (j != dim)
					{
						loc[plain_index][k++] = cur[j];
					}
				}
				vis[plain_index] = true;
				maxv[plain_index] = item;
			}
		});
		return 0;
		//return farray<fsize_t, D - 1>({ 1 }, { farr.size(dim) }, loc, loc + D);
	}
	template <typename T, int D>
	auto formaxloc(const farray<T, D> & farr, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		T maxv = *farr.cbegin(); // set default to the first element
		fsize_t loc[D]; std::copy_n(farr.LBound(), D, loc);

		farr.map([&](const T & item, const fsize_t(&cur)[D]) {
			if (maxv < item) {
				std::copy_n(cur, D, loc);
				maxv = item;
			}
		});
		return farray<fsize_t, 1>({ 1 }, { D }, loc, loc + D);
	}
	
	template <typename T, int D>
	auto formaxval(const farray<T, D> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		// return maxvalue of every subarray
		CHECK_AND_SET(fordim, 1)
		return 0;
	}


	template <typename T1, typename T2, int D>
	auto formerge(const farray<T1, D> & tarr, const farray<T2, D> & farr, const farray<bool, D> & mask) {
		/***
			a = reshape((/ 1, 2, 3, 4, 5, 6 /), (/ 2, 3 /))
			a2 = reshape((/ 8, 9, 0, 1, 2, 3 /), (/ 2, 3 /))
			logi = reshape((/ .FALSE., .TRUE., .TRUE., .TRUE., .TRUE., .FALSE. /), (/ 2, 3 /))
			return  8 2 3 4 5 3
		***/
		typedef decltype(std::declval<T1>() + std::declval<T2>()) TR;
		farray<TR, D> narr(tarr);
		fsize_t fs = mask.flatsize();
		auto mask_iter = mask.cbegin();
		auto farr_iter = farr.cbegin();
		auto narr_iter = narr.begin();
		for (fsize_t i = 0; i < fs; i++, mask_iter++, farr_iter++, narr_iter++)
		{
			if (*mask_iter == false) {
				*narr_iter = *farr_iter;
			}
		}
		return narr;
	}
}

