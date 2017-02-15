#pragma once
#include "forarray_common.h"
#include <memory>
#include <cmath>
#include <cassert>
#include "forlang.h"

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
			//return fa_getflatsize(sz, sz + dimension);
			return this->delta[this->dimension - 1] * this->sz[this->dimension - 1];
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
			assert(X == dimension);
			auto it = begin();
			for (size_type i = 0; i < X; i++)
			{
				it += (index[i] - lb[i]) * delta[i];
			}
			return *it;
		}

		template<int X>
		const T & const_get(const size_type(&index)[X]) {
			assert(X == dimension);
			auto it = cbegin();
			for (size_type i = 0; i < X; i++)
			{
				it += (index[i] - lb[i]) * sz[i];
			}
			return *it;
		}

		template<typename Iterator>
		T & get(Iterator index_from, Iterator index_to) {
			assert(index_to - index_from == dimension);
			auto it = begin();
			size_t i = 0;
			for (Iterator iter = index_from; iter < index_to; iter++, i++)
			{
				it += (*iter - lb[i]) * delta[i];
			}
			return *it;
		}

		template<typename Iterator>
		const T & const_get(Iterator index_from, Iterator index_to) const {
			assert(index_to - index_from == dimension);
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
		farray<T> & operator=(farray<T> && x) {
			if (this == &x) return *this;
			this->parr = x.parr;
			x.parr = nullptr;
			return *this;
		}

		operator T() {
			// if this farray has only one element, it can be cast to a scalar
			assert(flatsize() == 1);
			return *cbegin();
		}
		//typedef typename std::conditional<D == 1, std::true_type, std::false_type>::type is_vector_t;

		// element-wise add operation
		// must make sure flatsize() is conformed
		template<typename U> friend farray<U> operator+(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<U> operator+(const U & x, const farray<U> & y);
		template<typename U> friend farray<U> operator+(const farray<U> & x, const U & y);
		template<typename U> friend farray<U> operator-(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<U> operator-(const U & x, const farray<U> & y);
		template<typename U> friend farray<U> operator-(const farray<U> & x, const U & y);
		template<typename U> friend farray<U> operator*(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<U> operator*(const U & x, const farray<U> & y);
		template<typename U> friend farray<U> operator*(const farray<U> & x, const U & y);
		template<typename U> friend farray<U> operator/(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<U> operator/(const U & x, const farray<U> & y);
		template<typename U> friend farray<U> operator/(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator<(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator<(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator<(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator<=(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator<=(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator<=(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator>(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator>(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator>(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator>=(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator>=(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator>=(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator==(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator==(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator==(const farray<U> & x, const U & y);
		template<typename U> friend farray<bool> operator!=(const farray<U> & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator!=(const U & x, const farray<U> & y);
		template<typename U> friend farray<bool> operator!=(const farray<U> & x, const U & y);

#define MAKE_ARITH_OPERATORS_UNARY(op, op2) farray<T> & operator##op(const farray<T> & x) { \
			std::transform(begin(), end(), x.cbegin(), begin(), [](auto x, auto y) {return x op2 y; }); \
			return *this; \
		} \
		farray<T> & operator##op(const T & x) { \
			map([&](T & item, const fsize_t * cur) {item op x;}); \
			return *this; \
		}

		MAKE_ARITH_OPERATORS_UNARY(+=, +);
		MAKE_ARITH_OPERATORS_UNARY(-=, -);
		MAKE_ARITH_OPERATORS_UNARY(*=, *);
		MAKE_ARITH_OPERATORS_UNARY(/=, / );

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
					sz[dim++] = (x.to + 1 - x.fr) / x.step + ((x.to + 1 - x.fr) % x.step == 0 ? 0 : 1);
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
		farray(int D, Iterator_FSize_T lower_bound, Iterator_FSize_T size) noexcept: is_view(false)
		{
			// on some occations, dimension is not given by sizeof(lower_bound) / sizeof(size)
			reset_array(D, lower_bound, size);
			reset_value();
		}
		template <int D>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D]) noexcept: is_view(false) {
			reset_array(D, lower_bound, size);
			reset_value();
		}
		template <int D, typename Iterator>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end, bool isview = false) noexcept : is_view(isview)
		{
			reset_array(D, lower_bound, size);
			reset_value(begin, end);
		}
		//template <int D>
		//farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T & scalar) noexcept : is_view(false) {
		//	reset_array(D, lower_bound, size);
		//	reset_value(scalar);
		//}

		// deprecated
		template <int D, int X>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X]) noexcept : is_view(false)
		{
			// X == 1 means explicitly use a scalar to initialize an array
			reset_array(D, lower_bound, size);
			reset_value(values, values + X);
		}
		template <int D>
		farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m, bool isview = false) noexcept : is_view(isview)
		{
			// used when construct from a farray<T>
			// copy and reshape from a farray
			reset_array(D, lower_bound, size);
			reset_value(m.cbegin(), m.cend());
		}
		farray(const T & scalar) noexcept : is_view(false) {
			/***
			ISO/IEC 1539:1991 1.5.2
			A scalar is conformable with any array
			A rank-one array may be constructed from scalars and other arrays and may be reshaped into any allowable array shape
			***/
			// implicitly use a scalr to initialize an array, so shape of array is undetermined
			reset_array({ 1 }, { 1 });
			narr.reset_value(scalar);
		}
		farray() noexcept: is_view(false) {

		}
		farray<T> & copy_from(const farray<T> & x) {
			if (this == &x) return *this;
			this->dimension = x.dimension;
			reset_array(this->dimension, x.LBound(), x.size());
			reset_value(x.cbegin(), x.cend());
			return *this;
		}
		farray(const farray<T> & m) noexcept: is_view(false){
			// copy constructor
			copy_from(m);
		}
		farray<T> & move_from(farray<T> && m) {
			if (this == &m) return *this;
			this->dimension = m.dimension;
			this->lb = m.lb;
			this->sz = m.sz;
			this->delta = m.delta;
			this->parr = m.parr;
			m.lb = nullptr;
			m.sz = nullptr;
			m.delta = nullptr;
			m.parr = nullptr;
			return *this;
		}
		farray(farray<T> && m) noexcept : is_view(false) {
			move_from(std::move(m));
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

template <typename T1, typename T2> 
auto power(const farray<T1> & x, const farray<T2> & y) { 
	assert(x.flatsize() == y.flatsize()); 
	decltype(std::declval<T1>() * std::declval<T2>()) narr(x);
	std::transform(narr.begin(), narr.end(), x.cbegin(), narr.begin(), [](auto m, auto n) {return power(m, n); });
	return narr; 
}
template <typename T1, typename T2>
auto power(const T1 & x, const farray<T2> & y) {
	decltype(std::declval<T1>() * std::declval<T2>()) narr(y);
	std::transform(narr.begin(), narr.end(), narr.begin(), [&](auto m) {return power(x, m); });
	return narr; 
}
template <typename T1, typename T2>
auto power(const farray<T1> & x, const T2 & y) {
	decltype(std::declval<T1>() * std::declval<T2>()) narr(x);
	std::transform(narr.begin(), narr.end(), narr.begin(), [&](auto m) {return power(m, y); });
	return narr; 
}

#define MAKE_ARITH_OPERATORS_BIN(op) template <typename T> \
	farray<T> operator##op(const farray<T> & x, const farray<T> & y) { \
		assert(x.flatsize() == y.flatsize()); \
		farray<T> narr(x); \
		narr op ## = y; \
		return narr; \
	} \
	template <typename T> \
	farray<T> operator##op(const T & x, const farray<T> & y) { \
		farray<T> narr(y); \
		narr op ## = x; \
		return narr; \
	} \
	template <typename T> \
	farray<T> operator##op(const farray<T> & x, const T & y) { \
		farray<T> narr(x); \
		narr op ## = y; \
		return narr; \
	}
	MAKE_ARITH_OPERATORS_BIN(+);
	MAKE_ARITH_OPERATORS_BIN(-);
	MAKE_ARITH_OPERATORS_BIN(*);
	MAKE_ARITH_OPERATORS_BIN(/ );

#define MAKE_CMP_OPERATORS(op) template <typename T> \
	farray<bool> operator##op(const farray<T> & x, const farray<T> & y) { \
		assert(x.flatsize() == y.flatsize()); \
		farray<bool> narr(x.dimension, x.LBound(), x.size()); \
		narr.map([&](bool & item, const fsize_t * cur) { \
			item = (x.const_get(cur, cur + x.dimension) op y.const_get(cur, cur + y.dimension)); \
		}); \
		return narr;  \
	} \
	template <typename T> \
	farray<bool> operator##op(const T & x, const farray<T> & y) { \
		farray<bool> narr(x.dimension, x.LBound(), x.size()); \
			narr.map([&](bool & item, const fsize_t * cur) { \
				item = (x op y.const_get(cur, cur + y.dimension)); \
		}); \
		return narr;  \
	} \
	template <typename T> \
	farray<bool> operator##op(const farray<T> & x, const T & y) { \
		farray<bool> narr(x.dimension, x.LBound(), x.size()); \
		narr.map([&](bool & item, const fsize_t * cur) { \
			item = (x.const_get(cur, cur + x.dimension) op y); \
		}); \
		return narr;  \
	}

	MAKE_CMP_OPERATORS(< );
	MAKE_CMP_OPERATORS(<= );
	MAKE_CMP_OPERATORS(> );
	MAKE_CMP_OPERATORS(>= );
	MAKE_CMP_OPERATORS(== );
	MAKE_CMP_OPERATORS(!= );
	MAKE_CMP_OPERATORS(&& );
	MAKE_CMP_OPERATORS(|| );
	MAKE_CMP_OPERATORS(^ );

	template <typename T>
	farray<bool> operator!(const farray<T> & x) {
		farray<bool> narr(x.dimension, x.LBound(), x.size());
		narr.map([&](bool & item, const fsize_t * cur) {
			item = (! x.const_get(cur, cur + x.dimension));
		});
		return narr; 
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
	auto make_init_list(const fsize_t(&from)[D], const fsize_t(&size)[D], F f) 
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
	farray<T> make_init_list(Iterator list_begin, Iterator list_end) {
		farray<T> narr({ 1 }, { list_end - list_begin });
		narr.reset_value(list_begin, list_end);
		return narr;
	}
	template <typename T, int X>
	farray<T> make_init_list(const T(&values)[X]){
		farray<T> narr({ 1 }, { X });
		narr.reset_value(values, values + X);
		return narr;
	}
	template <typename T>
	farray<T> make_init_list(const T & scalar)  {
		/***
		ISO/IEC 1539:1991 1.5.2
		A scalar is conformable with any array
		A rank-one array may be constructed from scalars and other arrays and may be reshaped into any allowable array shape
		***/
		// implicitly use a scalr to initialize an array, so shape of array is undetermined
		return farray<T>(scalar);
	}
	template <typename T>
	farray<T> make_init_list(int repeat, const T & scalar) {
		farray<T> narr({ 1 }, { repeat });
		narr.reset_value(scalar);
		return narr;
	}
	template <typename T>
	farray<T> make_init_list(const farray<T> & m) {
		return m;
	}

	template <typename T, int X, typename _Iterator_In, typename _Iterator_Out>
	void _forslice_impl(const slice_info<fsize_t>(&tp)[X], const farray<T> & farr, int deep, const fsize_t * delta_out, const fsize_t * delta_in
		, _Iterator_Out bo, _Iterator_Out eo, _Iterator_In bi, _Iterator_In ei)
	{
		int _X = X;
		for (fsize_t i = farr.LBound(deep); i < farr.LBound(deep) + farr.size(deep); i++)
		{
			bool hit = i >= tp[deep].fr && i <= tp[deep].to && ((i - tp[deep].fr) % tp[deep].step) == 0;
			if (hit) {
				if (deep + 1 == _X) { // if X not equal to narr.dimension, behaviour is not defined
					*bo = *bi;
				}
				else { 
					_forslice_impl<T, X>(tp, farr, deep + 1, delta_out, delta_in, bo, bo + delta_out[deep], bi, bi + delta_out[deep]);
				}
			}
			if (i != farr.LBound(deep) + farr.size(deep)) {
				if (hit) {
					bo += delta_out[deep];
				}
				bi += delta_in[deep];
			}
		}
	};
	template <typename T, int X>
	auto forslice(const farray<T> & farr, const slice_info<fsize_t>(&tp)[X]) {
		// by fortran standard, slice must return by ref
		farray<T> narr{}; // dimension will be reset later in reset_array
		slice_info<fsize_t> ntp[X];
		for (auto i = 0; i < X; i++)
		{
			if (tp[i].isall) {
				// [from, to]
				ntp[i] = slice_info<fsize_t>({ farr.LBound(i), farr.UBound(i) });
			}
			else {
				// just copy
				ntp[i] = slice_info<fsize_t>(tp[i]);
			}
		}
		narr.reset_array(ntp, true);
		narr.reset_value();
		// 因为narr的维数不一定等于farr的维数，所以不能直接用narr.get_delta()
		fsize_t ndelta[X];
		std::transform(ntp, ntp + X, ndelta, [](auto x) {return (x.to + 1 - x.fr) / x.step + ((x.to + 1 - x.fr) % x.step == 0 ? 0 : 1); }); // size
		fa_layer_delta(ndelta, ndelta + X, ndelta);
		_forslice_impl<T, X>(ntp, farr, 0, ndelta, farr.get_delta(), narr.begin(), narr.end(), farr.cbegin(), farr.cend());

		return narr;
	}
	template <typename T>
	farray<T> forreorganize(const farray<T> & farr, int dim, fsize_t index) {
		// return a rank D - 1 sub array of farr equals to farr(dim = index)
		farray<T> narr;
		slice_info<fsize_t> sl[farr.dimension];
		for (auto i = 0; i < farr.dimension; i++)
		{
			sl[i] = slice_info<fsize_t>(); // select all elements
		}
		sl[dim] = slice_info<fsize_t>({ {index} }); // choose index(isslice = false) in rank dim
		narr.reset_array(sl, false); // do not reset lower bound to 1
		narr.reset_value();

		_forslice_impl<T, X>(farr, 0, farr.get_delta(), narr.begin(), farr.cbegin(), farr.cend());
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
		farray<fsize_t> r = make_init_list(farr.size(), farr.size() + farr.dimension); 
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

	//template <typename T>
	//using mask_wrapper_t = std::function<bool(T)>;

	//template <typename T>
	//bool mask_wrapper_all(T x) {
	//	return true;
	//}
	using mask_wrapper_t = farray<bool>;

	template <typename T, typename F>
	farray<T> _forloc_impl(F predicate, const farray<T> & farr, int fordim, foroptional<mask_wrapper_t> mask = None ) {
		// if the array has zero size, or all of the elements of MASK are .FALSE., then the result is an array of zeroes. Similarly, if DIM is supplied and all of the elements of MASK along a given row are zero, the result value for that row is zero. 
		int dim = fordim - 1;
		std::vector<fsize_t> lb(farr.LBound(), farr.LBound() + farr.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(farr.size(), farr.size() + farr.dimension); sz.erase(sz.cbegin() + dim);		
		farray<fsize_t> loc(farr.dimension - 1, lb.cbegin(), sz.cbegin()); loc.reset_value(0); // only allocate
		farray<bool> inited(farr.dimension - 1, lb.cbegin(), sz.cbegin()); inited.reset_value(false); // set all elements to false
		T curv; 
		farr.map([&](const T & current_value, const fsize_t * cur) {
			std::vector<fsize_t> subcur = std::vector<fsize_t>(cur, cur + farr.dimension); subcur.erase(subcur.cbegin() + dim);
			if (inited.const_get(subcur.cbegin(), subcur.cend()) == false|| predicate(current_value, curv)) {
				loc.get(subcur.begin(), subcur.end()) = cur[dim];
				curv = current_value;
			}
			inited.get(subcur.begin(), subcur.end()) = true;
		});
		return loc;
	}
	template <typename T, typename F>
	farray<T> _forloc_impl(F predicate, const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		T curv;
		farray<fsize_t> loc({ 1 }, { farr.dimension }); loc.reset_value(0); // only allocate
		bool inited = false;
		farr.map([&](const T & current_value, const fsize_t * cur) {
			if (!inited || predicate(current_value, curv)) {
				std::copy_n(cur, farr.dimension, loc.begin());
				curv = current_value;
			}
			inited = true;
		});
		return loc;
	}
	template <typename T, typename F>
	farray<T> formap(F f, const farray<T> & farr) {
		farray<T> narr(farr);
		narr.map([&](T & current_value, const fsize_t * cur) {
			f(current_value);
		});
		return narr;
	}
	template <typename T, typename F>
	T formap(F f, T x) {
		return f(x);
	}

	template <typename R, typename T, typename F>
	R forreduce(F binop, R initial, const farray<T> & farr, foroptional<mask_wrapper_t> mask = None)
	{
		// TODO examine why this do not work
		//return std::accumulate(farr.cbegin(), farr.cend(), intial, [&](const R & op1, const T & op2) {
		//	return binop(op1, op2);
		//});
		if (mask.inited())
		{
			auto iter_bool = mask.const_get().cbegin();
			for (auto iter = farr.cbegin(); iter < farr.cend(); iter++, iter_bool++)
			{
				if (*iter_bool)
				{
					initial = binop(initial, *iter);
				}
			}
		}
		else {
			for (auto iter = farr.cbegin(); iter < farr.cend(); iter++)
			{
				initial = binop(initial, *iter);
			}
		}
		return initial;
	}
	template <typename R, typename T, typename F>
	farray<typename R> forreduce(F binop, farray<typename R> initial_set, const farray<T> & farr, int dim, foroptional<mask_wrapper_t> mask = None)
	{
		// previous_result_set is a farray 1 rank less than farr
		farr.map([&](const T & current_value, const fsize_t * cur) {
			std::vector<fsize_t> subcur = std::vector<fsize_t>(cur, cur + farr.dimension); subcur.erase(subcur.cbegin() + dim);
			if (mask.inited())
			{
				if (mask.const_get().const_get(cur, cur + farr.dimension) == false)
				{
					return;
				}
			}
			R & initial = initial_set.get(subcur.begin(), subcur.end());
			initial = binop(initial, current_value);
		});
		return initial_set;
	}

	template <typename T>
	auto forsum(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		int dim = fordim.value_or(1) - 1;
		// do not need to CHECK_AND_SET mask because it's the last parameter
		std::vector<fsize_t> lb(farr.LBound(), farr.LBound() + farr.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(farr.size(), farr.size() + farr.dimension); sz.erase(sz.cbegin() + dim);
		farray<T> ans(farr.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(0); // only allocate
		return forreduce([&](const T & op1, const T & op2) {
			return op1 + op2;
		}, ans, farr, dim, mask);
	}

	template <typename T>
	auto forsum(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return forreduce([&](const T & op1, const T & op2) -> T {
			return op1 + op2;
		}, 0, farr, mask);
	}

	template <typename T>
	auto forproduct(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		int dim = fordim.value_or(1) - 1;
		std::vector<fsize_t> lb(farr.LBound(), farr.LBound() + farr.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(farr.size(), farr.size() + farr.dimension); sz.erase(sz.cbegin() + dim);
		farray<T> ans(farr.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(1); // only allocate
		return forreduce([&](const T & op1, const T & op2) {
			return op1 * op2;
		}, ans, farr, dim, mask);
	}
	template <typename T>
	auto forproduct(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return forreduce([&](const T & op1, const T & op2) -> T {
			return op1 * op2;
		}, 1, farr, mask);
	}

	inline farray<bool> forall(mask_wrapper_t mask, int fordim) {
		int dim = fordim - 1;
		std::vector<fsize_t> lb(mask.LBound(), mask.LBound() + mask.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(mask.size(), mask.size() + mask.dimension); sz.erase(sz.cbegin() + dim);
		farray<bool> ans(mask.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(true); // only allocate
		return forreduce([&](const bool & op1, const bool & op2) -> bool {
			return op1 && op2;
		}, ans, mask, dim, None);
	}

	inline bool forall(mask_wrapper_t mask) {
		return forreduce([&](const bool & op1, const bool & op2) -> bool {
			return op1 && op2;
		}, true, mask, None);
	}
	
	inline farray<bool> forany(mask_wrapper_t mask, int fordim) {
		int dim = fordim - 1;
		std::vector<fsize_t> lb(mask.LBound(), mask.LBound() + mask.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(mask.size(), mask.size() + mask.dimension); sz.erase(sz.cbegin() + dim);
		farray<bool> ans(mask.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(false); // only allocate
		return forreduce([&](const bool & op1, const bool & op2) -> bool {
			return op1 || op2;
		}, ans, mask, dim, None);
	}

	inline bool forany(mask_wrapper_t mask) {
		return forreduce([&](const bool & op1, const bool & op2) -> bool {
			return op1 || op2;
		}, false, mask, None);
	}

	inline farray<fsize_t> forcount(mask_wrapper_t mask, int fordim) {
		int dim = fordim - 1;
		std::vector<fsize_t> lb(mask.LBound(), mask.LBound() + mask.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(mask.size(), mask.size() + mask.dimension); sz.erase(sz.cbegin() + dim);
		farray<fsize_t> ans(mask.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(0); // only allocate
		return forreduce([&](const fsize_t & op1, const bool & op2) -> fsize_t {
			if (op2) {
				return op1 + 1;
			}
			else {
				return op1;
			}
		}, ans, mask, dim, None);
	}

	inline fsize_t forcount(mask_wrapper_t mask) {
		return forreduce([&](const fsize_t & op1, const bool & op2) -> fsize_t {
			if (op2) {
				return op1 + 1;
			}
			else {
				return op1;
			}
		}, 0, mask, None);
	}

	template <typename T, typename F>
	T _forcmpval_impl(F predicate, const T & initial_value, const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return forreduce([&](const T & op1, const T & op2) -> T {
			if (predicate(op2, op1))
			{
				return op2;
			}
			else {
				return op1;
			}
		}, initial_value, farr, mask);
	}
	template <typename T, typename F>
	farray<T> _forcmpval_impl(F predicate, const T & initial_value, const farray<T> & farr, int fordim, foroptional<mask_wrapper_t> mask = None) {
		int dim = fordim - 1;
		std::vector<fsize_t> lb(farr.LBound(), farr.LBound() + farr.dimension); lb.erase(lb.cbegin() + dim); // remove dimension dim
		std::vector<fsize_t> sz(farr.size(), farr.size() + farr.dimension); sz.erase(sz.cbegin() + dim);
		farray<T> ans(farr.dimension - 1, lb.cbegin(), sz.cbegin()); ans.reset_value(initial_value); 
		return forreduce([&](const T & op1, const T & op2) {
			if (predicate(op2, op1))
			{
				return op2;
			}
			else {
				return op1;
			}
		}, ans, farr, dim, mask);
	}

	template <typename T>
	farray<T> formaxloc(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		/***
		ISO/IEC 1539:1991 1.5.2
		has not specify actions for this overload version
		conform to gfortran(fortran 95 standard)
		***/
		// 返回的是`[lb[dim], sz[dim]]`构成的`dim-1`维数组，令剩下来的维数取遍所有组合，对于每一种取组合，给出取得最大值时候对应原数组第dim维的下标
		return _forloc_impl(std::greater<T>(), farr, fordim, mask);
	}
	template <typename T>
	farray<T> forminloc(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		return _forloc_impl(std::less<T>(), farr, fordim, mask);
	}

	template <typename T>
	farray<T> formaxloc(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return _forloc_impl(std::greater<T>(), farr, mask);
	}
	template <typename T>
	farray<T> forminloc(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return _forloc_impl(std::less<T>(), farr, mask);
	}

	template <typename T>
	auto formaxval(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return _forcmpval_impl(std::greater<T>(), -forhuge<T>(),farr, mask);
	}
	template <typename T>
	auto formaxval(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		return _forcmpval_impl(std::greater<T>(), -forhuge<T>(), farr, fordim,  mask);
	}
	template <typename T>
	auto forminval(const farray<T> & farr, foroptional<mask_wrapper_t> mask = None) {
		return _forcmpval_impl(std::less<T>(), +forhuge<T>(), farr, mask);
	}
	template <typename T>
	auto forminval(const farray<T> & farr, foroptional<int> fordim, foroptional<mask_wrapper_t> mask = None) {
		return _forcmpval_impl(std::less<T>(), +forhuge<T>(), farr, fordim, mask);
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

