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
		const bool is_view;
		typedef typename T * iterator;
		typedef typename const T * const_iterator;

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
		fsize_t flatsize() const {
			return fa_getflatsize(sz, sz + D);
		}
		const fsize_t * get_delta() const {
			return delta;
		}

		iterator begin() {
			return parr;
		}
		iterator end() {
			return parr + flatsize();
		}
		const_iterator cbegin() const {
			return parr;
		}
		const_iterator cend() const  {
			return parr + flatsize();
		}

		template<int X>
		auto & get(const size_type (& index)[X]) {
			auto it = begin();
			for (size_type i = 0; i < X; i++)
			{
				it += index[i] * delta[i];
			}
			return *it;
		}

		template<int X>
		auto const_get(const size_type(&index)[X]) {
			auto it = cbegin();
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


		operator farray<T, 1>() {
			// flattern all to vector
			farray<T, 1> r({ 1 }, { flatsize }, begin(), end());
			return r;
		}
		operator farray<T, 2>() {
			// promote vector to matrix
			farray<T, 2> r({ lb[0], 1 }, { sz[0], 1 }, begin(), end());
			return r;
		}

		void transpose() {
			std::reverse(lb, lb + D);
			std::reverse(sz, sz + D);
			std::reverse(begin(), end());
			fa_layer_delta(this->sz, this->sz + D, delta);
		}
		template <typename F>
		void map(F f) const {
			_map_impl<const farray<T, D>&, F>(*this, f, cbegin());
		}
		template <typename F>
		void map(F f) {
			_map_impl<farray<T, D>&, F>(*this, f, begin());
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
			std::transform(tp, tp + X, sz, [](typename slice_info<fsize_t> x) {
				return (x.to + 1 - x.fr) / x.step + ((x.to + 1 - x.fr) % x.step == 0 ? 0 : 1); 
			}); // size of each dimension(new array)
			fa_layer_delta(this->sz, this->sz + D, delta);
		}
		void reset_array(const size_type * lower_bound, const size_type * size) {
			std::copy_n(lower_bound, D, this->lb);
			std::copy_n(size, D, this->sz);
			fa_layer_delta(this->sz, this->sz + D, delta);
		}
		void clear() {
			delete[] parr;
			parr = nullptr;
		}
		void reset_value(fsize_t X, const T * values) {
			clear();
			parr = new T[flatsize()];
			std::copy_n(values, X, parr);
		}
		template <typename Iterator>
		void reset_value(Iterator b, Iterator e) {
			clear();
			parr = new T[flatsize()];
			std::copy_n(b, e - b, parr);
		}
		void reset_value(fsize_t X) {
			clear();
			parr = new T[flatsize()];
		}
		farray(const size_type * lower_bound, const size_type * size) : is_view(false)
		{
			reset_array(lower_bound, size);
		}
		farray(const T & scalar) : is_view(false) {
			// ISO/IEC 1539:1991 1.5.2
			// A scalar is conformable with any array
			// A rank-one array may be constructed from scalars and other arrays and may be reshaped into any allowable array shape
			std::fill_n(lb, D, 1);
			std::fill_n(sz, D, 1);
			reset_value(1, &scalar);
		}
		template <int X>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X]) : is_view(false)
		{
			reset_array(lower_bound, size);
			reset_value(X, values);
		}
		template <typename Iterator>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end) : is_view(false)
		{
			reset_array(lower_bound, size);
			reset_value(begin, end);
		}

		
		template <int X, typename F/*, typename = std::enable_if_t<std::is_callable<F, size_type>::value>*/>
		farray(const size_type(&from)[X], const size_type(&size)[X], F f) : is_view(false) {
			reset_array(from, size);
			// important: second argument is size, not to
			size_type totalsize = flatsize();
			reset_value(totalsize);
			map([&](T & item, const fsize_t(&cur)[D]) {
				item = f(cur); 
			});
		}
		farray() : is_view(false) {

		}
		farray(const farray<T, D> & m) : is_view(false) {
			reset_array(m.LBound(), m.size());
			reset_value(m.cbegin(), m.cend());
		}
		explicit farray(const farray<T, D> & m, bool view) : is_view(view) {

		}

		//std::shared_ptr<std::vector<T>> parr; // use shared can support inplace operation
		//std::vector<std::shared_ptr<T>> parr;
		T * parr = nullptr; // support inplace operation of each element
	protected:
		size_type lb[D], sz[D], delta[D];


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
	void _forslice_impl(const farray<T, D> & narr, int deep, const fsize_t * step_out, const fsize_t * delta_out, const fsize_t * delta_in
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
	auto forslice(const farray<T, D> & farr, const slice_info<typename farray<T, D>::size_type>(&tp)[X]) {
		// by fortran standard, slice must return by ref, now by val
		farray<T, D> narr(farr.LBound(), farr.size()); // if X < D, unspecified ranks of narr will remain the same as farr
		narr.reset_array(tp, true);

		fsize_t step_out[D];
		std::fill_n(step_out, D, 1); // if X < D, unspecified stride of narr will be 1
		std::transform(tp, tp + X, step_out, [](fsize_t> x) {return x.step; });

		fsize_t totalsize = narr.flatsize();
		narr.reset_value(totalsize);
		_forslice_impl<T, D, X>(narr, 0, step_out, narr.get_delta(), farr.get_delta(), narr.begin(), narr.end(), farr.cbegin(), farr.cend());

		return narr;
	}
	template <typename T, int D>
	farray<T, D - 1> forreorganize(const farray<T, D> & farr, int dim, fsize_t index) {
		// return a rank D - 1 sub array of farr
		farray<T, D - 1> narr;
		slice_info<fsize_t> sl[D];
		for (auto i = 0; i < D; i++)
		{
			sl[i] = slice_info<fsize_t>(); // select all elements
		}
		sl[dim] = slice_info<fsize_t>({ index, index }); // choose index in rank dim
		narr.reset_array(sl, false); // do not reset lower bound to 1

		fsize_t step_out[D];
		std::fill_n(step_out, D, 1); // 1

		fsize_t totalsize = narr.flatsize();
		narr.reset_value(totalsize);

		_forslice_impl<T, D, X>(narr, 0, step_out, narr.get_delta(), farr.get_delta(), narr.begin(), narr.end(), farr.cbegin(), farr.cend());
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
	auto formaxloc(const farray<T, D> & farr, foroptional<int> fordim, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		// return maxvalue of every subarray
		int dim = fordim - 1;

		for (auto i = farr.LBound(); i < farr.LBound() + farr.size(); i++)
		{
			farray<T, D - 1> sub_rank = forreorganize(farr, dim, i);
		}
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

