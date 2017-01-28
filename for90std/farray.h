#pragma once
#include "forarray_common.h"
#include <memory>
#include <cmath>

namespace for90std {
	template <typename T>
	struct farray {
		typedef T value_type;
		typedef fsize_t size_type; // fortran array index can be negative
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef const value_type * const_pointer;
		typedef const value_type & const_reference;
		typedef size_type difference_type;
		typedef slice_info<typename size_type> slice_type;
		int dimension;
		const bool is_view;
		typedef typename T * iterator;
		typedef typename const T * const_iterator;
		typedef typename std::reverse_iterator<iterator> reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

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
			return fa_getflatsize(sz, sz + dimension);
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
		T & get(const size_type (& index)[X]) {
			auto it = begin();
			for (size_type i = 0; i < X; i++)
			{
				it += (index[i] - lb[i]) * delta[i];
			}
			return *it;
		}

		template<int X>
		const T & const_get(const size_type(&index)[X]) {
			auto it = cbegin();
			for (size_type i = 0; i < X; i++)
			{
				it += (index[i] - lb[i]) * sz[i];
			}
			return *it;
		}

		template<typename Iterator>
		T & get(Iterator index_from, Iterator index_to) {
			auto it = begin();
			size_t i = 0;
			for (Iterator iter = index_from; iter < index_to; iter++, i++)
			{
				it += (*iter - lb[i]) * delta[i];
			}
			return *it;
		}

		template<typename Iterator>
		const T & const_get(Iterator index_from, Iterator index_to) {
			auto it = cbegin();
			size_t i = 0;
			for (Iterator iter = index_from; iter < index_to; iter++, i++)
			{
				it += (*iter - lb[i]) * delta[i];
			}
			return *it;
		}
		template<typename... Args>
		T & operator()(Args&&... args) {
			size_type index[sizeof...(args)] = { args... };
			return get(index);
		}

		template<int X>
		T & operator[](const slice_type (&index)[X]) {
			return get(index);
		}

		farray<T> & operator=(const farray<T> & x) {
			if (this == &x) return *this;
			reset_value(x.cbegin(), x.cend());
			return *this;
		}
		farray<T> & copy_from(const farray<T> & x) {
			if (this == &x) return *this;
			this->dimension = x.dimension;
			reset_array(this->dimension, x.LBound(), x.size());
			reset_value(x.cbegin(), x.cend());
			return *this;
		}

		//typedef typename std::conditional<D == 1, std::true_type, std::false_type>::type is_vector_t;
		friend farray<T> & operator+(const farray<T> & x, const farray<T> & y);
		friend farray<T> & operator+(const T & x, const farray<T> & y);
		farray<T> & operator+=(const farray<T> & x) {
			// element-wise add operation
			auto tb = begin(); 
			auto xb = x.cbegin();
			while (tb < end()) {
				*tb = *xb;
				tb++; xb++;
			}
			return *this;
		}

		void transpose() {
			T * na = new T[flatsize()];
			map([&](T & item, const fsize_t * cur) {
				fsize_t oldindex = 0;
				fsize_t newindex = 0;
				for (int i = 0; i < dimension; i++)
				{
					fsize_t oldt = 1;
					oldt = delta[j];
					//for (int j = 0; j <= i - 1; j++)
					//{
					//	oldt *= sz[j];
					//}
					oldindex += (cur[i] - lb[i]) * oldt;

					fsize_t newt = 1;
					for (int j = 0; j <= i - 1; j++)
					{
						newt *= sz[dimension - 1 - j];
					}
					newindex += (cur[dimension - 1 - i] - lb[dimension - 1 - i]) * newt;
				}
				na[newindex] = parr[oldindex];
			});
			std::swap(na, parr);
			delete[] na;
			//std::reverse(begin(), end());
			std::reverse(lb, lb + dimension);
			std::reverse(sz, sz + dimension);
			fa_layer_delta(this->sz, this->sz + dimension, delta);
		}

		template <typename F>
		void map(F f) const {
			_map_impl<const farray<T>&, F>(*this, f, cbegin());
		}
		template <typename F>
		void map(F f) {
			_map_impl<farray<T>&, F>(*this, f, begin());
		}

		template <typename F>
		void forall(F f) {
			map([&](T & item, const fsize_t * cur) {
				f(item);
			});
		}

		template<int X>
		void reset_array(const slice_info<fsize_t>(&tp)[X], bool force_lower_bound = false) {
			// this overload do not provide dimension parameter, because dimension is dependant on `tp`
			delete[] lb; delete[] sz; delete[] delta;
			// modify dimension because not all element of tp is slice, probably index instead
			dimension = 0;
			int dim;
			for (auto i = 0; i < X; i++)
			{
				if ((tp[i]).isslice)
				{
					dimension++;
				}
			}
			lb = new fsize_t[dimension]; sz = new fsize_t[dimension]; delta = new fsize_t[dimension];
			// if X < dimension, use farr as default from dimension X + 1
			if (force_lower_bound) {
				// lower bound of each dimension(new array) should be forced to 1
				std::fill_n(lb, dimension, 1);
			}
			else {
				// lower bound of each dimension(new array)
				dim = 0;
				for (auto i = 0; i < X; i++)
				{
					if ((tp[i]).isslice)
					{
						lb[dim++] = tp[i].fr;
					}
				}
			}
			// size of each dimension(new array)
			dim = 0;
			for (auto i = 0; i < X; i++)
			{
				if ((tp[i]).isslice)
				{
					const slice_info<fsize_t> & x = tp[i];
					sz[dim++] = (x.to + 1 - x.fr) / x.step + ((x.to + 1 - x.fr) % x.step == 0 ? 0 : 1);;
				}
			}
			fa_layer_delta(this->sz, this->sz + dimension, delta);
		}

		template <typename Iterator_FSize_T>
		void reset_array(int dim, Iterator_FSize_T l, Iterator_FSize_T s) {
			this->dimension = dim;
			delete[] lb; delete[] sz; delete[] delta;
			lb = new fsize_t[dim]; sz = new fsize_t[dim]; delta = new fsize_t[dim];
			for (fsize_t i = 0; i < dim; i++)
			{
				*(this->lb + i) = *(l + i);
				*(this->sz + i) = *(s + i);
			}
			fa_layer_delta(this->sz, this->sz + dim, delta);
		}

		void clear() {
			delete[] parr;
			parr = nullptr;
		}
		void reset_value(const T & value) {
			clear();
			parr = new T[flatsize()];
			std::fill_n(parr, flatsize(), value);
		}
		void reset_value(int X, const farray<T> * farrs) {
			// reset value from several arrays
			clear();
			fsize_t flatsize = 0;
			for (int i = 0; i < X; i++)
			{
				flatsize += (farrs + i)->flatsize();
			}
			parr = new T[flatsize];
			auto parr1 = parr;
			for (int i = 0; i < X; i++)
			{
				std::copy_n((farrs + i)->cbegin(), X, parr1);
				parr1 += (farrs + i)->flatsize();
			}
		}
		template <typename Iterator>
		void reset_value(Iterator b, Iterator e) {
			clear();
			parr = new T[flatsize()];
			std::copy_n(b, e - b, parr);
		}
		void reset_value() {
			// allocate only according to sz
			clear();
			fsize_t totalsize = flatsize();
			parr = new T[totalsize];
		}
		template <typename Iterator_FSize_T>
		farray(int D, Iterator_FSize_T lower_bound, Iterator_FSize_T size,  bool isview = false) : is_view(isview)
		{
			// on some occations, dimension is not given by sizeof(lower_bound) / sizeof(size)
			reset_array(D, lower_bound, size);
			reset_value();
		}
		template <int D>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D]): is_view(false) {
			reset_array(D, lower_bound, size);
			reset_value();
		}
		template <int D, typename Iterator>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end) : is_view(false)
		{
			reset_array(D, lower_bound, size);
			reset_value(begin, end);
		}
		//template <int D>
		//farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T & scalar) : is_view(false) {
		//	reset_array(D, lower_bound, size);
		//	reset_value(scalar);
		//}

		// deprecated
		template <int D, int X>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X]) : is_view(false)
		{
			// X == 1 means explicitly use a scalar to initialize an array
			reset_array(D, lower_bound, size);
			reset_value(values, values + X);
		}
		template <int D>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m) : is_view(false)
		{
			// used when construct from a farray<T>
			// copy and reshape from a farray
			reset_array(D, lower_bound, size);
			reset_value(m.cbegin(), m.cend());
		}

		farray() : is_view(false) {
			reset_array(1);
		}
		farray(const farray<T> & m) : is_view(false){
			// copy constructor
			copy_from(m);
		}

		~farray() {
			if (!is_view) {
				delete[] parr;
			}
			delete[] lb; delete[] sz; delete[] delta;
		}
		T * parr = nullptr; // support inplace operation of each element
	protected:
		size_type * lb = nullptr, * sz = nullptr, * delta = nullptr;

		template <typename THIS, typename F, typename Iterator>
		static void _map_impl(THIS me, F f, Iterator iter) {
			size_type * cur = new size_type[me.dimension];
			std::copy_n(me.LBound(), me.dimension, cur);
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
					if (dim == me.dimension) {
						break; // all finished
					}
				}
				if (dim < me.dimension) {
					cur[dim]++;
				}
				else {
					break; // all finished
				}
				std::copy_n(me.LBound(), dim, cur); // reset cur
				dim = 0;
			}
#endif
			delete[] cur;
		}
	};

	template <typename T>
	farray<T> operator+(const farray<T> & x, const farray<T> & y) {
		// element-wise add operation
		// must make sure flatsize() is conformed
		farray<T> narr(x);
		x += y;
	}
	template <typename T>
	farray<T> operator+(const T & x, const farray<T> & y) {
		farray<T> narr(y);
		narr.map([&](T & item, const fsize_t * cur) {
			item += x;
		});
	}
	template <typename T>
	farray<T> operator+(const farray<T> & x, const T & y) {
		return y + x;
	}

	template <typename T, int X>
	farray<T> forconcat(const farray<T>(&farrs)[X])
	{
		fsize_t flatsize = 0;
		for (int i = 0; i < X; i++)
		{
			flatsize += (farrs + i)->flatsize();
		}
		farray<T> narr({ 1 }, { flatsize });
		// concat several farrays
		narr.reset_value(X, farrs);
		return narr;
	}


	template <int D, typename F/*, typename = std::enable_if_t<std::is_callable<F, size_type>::value>*/>
	auto make_farray(const fsize_t(&from)[D], const fsize_t(&size)[D], F f) 
	-> typename farray<typename function_traits<decltype(f)>::result_type> {
		typedef typename function_traits<decltype(f)>::result_type T;
		farray<T> narr(D, from, size);
		// important: second argument is size, not to
		fsize_t totalsize = narr.flatsize();
		narr.reset_value(totalsize);
		narr.map([&](T & item, const fsize_t *cur) {
			item = f(cur);
		});
		return narr;
	}
	template <typename T, int D, typename Iterator>
	farray<T> make_farray(Iterator b, Iterator e) {
		farray<T> narr({ 1 }, { e - b });
		narr.reset_value(b, e);
		return narr;
	}
	template <typename T, int X>
	farray<T> make_farray(const T(&values)[X]){
		farray<T> narr({ 1 }, { X });
		narr.reset_value(values, values + X);
		return narr;
	}
	template <typename T>
	farray<T> make_farray(const T & scalar)  {
		/***
		ISO/IEC 1539:1991 1.5.2
		A scalar is conformable with any array
		A rank-one array may be constructed from scalars and other arrays and may be reshaped into any allowable array shape
		***/
		// implicitly use a scalr to initialize an array, so shape of array is undetermined
		farray<T> narr({ 1 }, { 1 });
		narr.reset_value(scalar);
		return narr;
	}
	template <typename T>
	farray<T> make_farray(int repeat, const T & scalar) {
		farray<T> narr({ 1 }, { repeat });
		narr.reset_value(scalar);
		return narr;
	}
	template <typename T>
	farray<T> make_farray(const farray<T> & m) {
		return m;
	}

	template <typename T, int X, typename _Iterator_In, typename _Iterator_Out>
	void _forslice_impl(const slice_info<fsize_t>(&tp)[X], const farray<T> & narr, int deep, const fsize_t * delta_out, const fsize_t * delta_in
		, _Iterator_Out bo, _Iterator_Out eo, _Iterator_In bi, _Iterator_In ei)
	{
		for (fsize_t i = tp[deep].fr; i <= tp[deep].to; i+= tp[deep].step)
		{
			if (deep == X) { // if X not equal to narr.dimension, behaviour is not defined
				*bo = *bi;
			}
			else {
				_forslice_impl<T, X>(tp, narr, deep + 1, delta_out, delta_in, bo, bo + delta_out[deep], bi, bi + delta_out[deep]);
			}
			if (i != tp[deep].to) {
				bo += delta_out[deep];
				bi += delta_in[deep];
			}
		}
	};
	template <typename T, int X>
	auto forslice(const farray<T> & farr, const slice_info<fsize_t>(&tp)[X]) {
		// by fortran standard, slice must return by ref
		farray<T> narr(farr.dimension, farr.LBound(), farr.size()); // dimension will be modified in reset_array
		slice_info<fsize_t> ntp[X];
		for (auto i = 0; i < X; i++)
		{
			if (ntp[i].isall) {
				ntp[i] = slice_info<fsize_t>({ farr.LBound(i), farr.LBound(i) + farr.size(i) });
			}
			else {
				ntp[i] = slice_info<fsize_t>(tp[i]);
			}
		}
		narr.reset_array(ntp, true);

		fsize_t totalsize = narr.flatsize();
		narr.reset_value(totalsize);
		_forslice_impl<T, X>(ntp, narr, 0, narr.get_delta(), farr.get_delta(), narr.begin(), narr.end(), farr.cbegin(), farr.cend());

		return narr;
	}
	template <typename T>
	farray<T> forreorganize(const farray<T> & farr, int dim, fsize_t index) {
		// return a rank D - 1 sub array of farr
		farray<T> narr;
		slice_info<fsize_t> sl[farr.dimension];
		for (auto i = 0; i < farr.dimension; i++)
		{
			sl[i] = slice_info<fsize_t>(); // select all elements
		}
		sl[dim] = slice_info<fsize_t>({ {index} }); // choose index(isslice = false) in rank dim
		narr.reset_array(sl, false); // do not reset lower bound to 1

		fsize_t totalsize = narr.flatsize();
		narr.reset_value(totalsize);

		_forslice_impl<T, X>(narr, 0, narr.get_delta(), farr.get_delta(), narr.begin(), narr.end(), farr.cbegin(), farr.cend());
		return narr;
	}

	template <typename T>
	auto fortranspose(const farray<T> & farr) {
		farray<T> narr(farr);
		narr.transpose();
		return narr;
	}
	
	template <typename T>
	auto forlbound(const farray<T> & farr, int fordim = 1) {
		return farr.LBound(fordim - 1);
	}
	
	template <typename T>
	auto forubound(const farray<T> & farr, int fordim = 1) {
		return farr.UBound(fordim - 1);
	}

	template <typename T>
	farray<fsize_t> forshape(const farray<T> & farr, int fordim = 1) {
		farray<fsize_t> r = make_farray(farr.size(), farr.size() + farr.dimension); 
		return r;
	}

	template <typename T, int X, int D>
	auto forreshape(const T(&value)[X], const fsize_t(&shape)[D]){
		fsize_t lb[D];
		std::fill_n(lb, D, 1);
		farray<T> r = farray<T>(lb, shape, value, value + X);
		return r;
	}

	template <typename T>
	auto forsize(const farray<T> & farr, int fordim = 1) {
		return farr.size(fordim - 1);
	}

	template <typename T>
	using mask_wrapper = std::function<bool(T)>;

	template <typename T>
	auto forsum(const farray<T> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		CHECK_AND_SET(fordim, 1)
		// do not need to CHECK_AND_SET mask because it's the last parameter
		return 0;
	}	
	
	template <typename T>
	auto forproduct(const farray<T> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		CHECK_AND_SET(fordim, 1)
		return 0;
	}

	template <typename T, typename F>
	farray<T> _forloc_impl(F predicate, const farray<T> & farr, int fordim, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		/***
		ISO/IEC 1539:1991 1.5.2
		has not specify actions for this overload version
		conform to gfortran(fortran 95 standard)
		***/
		// 返回的是`[lb[dim], sz[dim]]`构成的`dim-1`维数组，令剩下来的维数取遍所有组合，对于每一种取组合，给出取得最大值时候对应原数组第dim维的下标
		int dim = fordim - 1;
		std::vector<fsize_t> lb(farr.LBound(), farr.LBound() + farr.dimension);
		std::vector<fsize_t> sz(farr.size(), farr.size() + farr.dimension);
		lb.erase(lb.cbegin() + dim);
		sz.erase(sz.cbegin() + dim);
		farray<fsize_t> narr(farr.dimension - 1, lb.cbegin(), sz.cbegin());
		narr.reset_value();
		farray<bool> barr(farr.dimension - 1, lb.cbegin(), sz.cbegin());
		barr.reset_value(false);
		//barr.forall([](bool & x) {x = false; });
		T curv; 
		farr.map([&](const T & item, const fsize_t * cur) {
			std::vector<fsize_t> subcur = std::vector<fsize_t>(cur, cur + farr.dimension);
			subcur.erase(subcur.cbegin() + dim);
			if (barr.const_get(subcur.cbegin(), subcur.cend()) == false|| predicate(item, curv)) {
				narr.get(subcur.begin(), subcur.end()) = cur[dim];
				curv = item;
			}
			barr.get(subcur.begin(), subcur.end()) = true;
		});
		return narr;
	}
	template <typename T>
	farray<T> formaxloc(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		return _forloc_impl([](T x, T y) {return x > y; }, farr, fordim, mask);
	}
	template <typename T>
	farray<T> forminloc(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		return _forloc_impl([](T x, T y) {return x < y; }, farr, fordim, mask);
	}
	template <typename T, typename F>
	farray<T> _forloc_impl(F predicate, const farray<T> & farr, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		T curv = *farr.cbegin(); // set default to the first element
		std::vector<fsize_t> loc = std::vector<fsize_t>(farr.dimension);
		std::copy_n(farr.LBound(), farr.dimension, loc.begin()); // set initial value for loc
		farr.map([&](const T & item, const fsize_t * cur) {
			if (predicate(item, curv)) {
				std::copy_n(cur, farr.dimension, loc.begin());
				curv = item;
			}
		});
		return make_farray(loc.begin(), loc.end()); 
	}
	template <typename T>
	farray<T> formaxloc(const farray<T> & farr, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		return _forloc_impl(std::greater<T>(), farr, mask);
	}
	template <typename T>
	farray<T> forminloc(const farray<T> & farr, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		return _forloc_impl(std::less<T>(), farr, mask);
	}

	template <typename T>
	auto formaxval(const farray<T> & farr, foroptional<int> fordim = 1, foroptional<mask_wrapper<T>> mask = foroptional<mask_wrapper<T>>([](T x) {return true; })) {
		// return maxvalue of every subarray
		int dim = fordim.value_or(1) - 1;
		return 0;
	}


	template <typename T1, typename T2>
	auto formerge(const farray<T1> & tarr, const farray<T2> & farr, const farray<bool> & mask) {
		/***
			a = reshape((/ 1, 2, 3, 4, 5, 6 /), (/ 2, 3 /))
			a2 = reshape((/ 8, 9, 0, 1, 2, 3 /), (/ 2, 3 /))
			logi = reshape((/ .FALSE., .TRUE., .TRUE., .TRUE., .TRUE., .FALSE. /), (/ 2, 3 /))
			return  8 2 3 4 5 3
		***/
		typedef decltype(std::declval<T1>() + std::declval<T2>()) TR;
		farray<TR> narr(tarr);
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

