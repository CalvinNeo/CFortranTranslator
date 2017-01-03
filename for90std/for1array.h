#pragma once
#include "for1array/forarray_common.h"

namespace for90std {
	template<typename T>
	struct for1array {
		typedef T value_type;
		typedef f1a_size_t size_type; // for1array index can be negative
		typedef value_type * pointer;
		typedef value_type & reference;
		typedef const value_type * const_pointer;
		typedef const value_type & const_reference;
		typedef size_type difference_type;

		struct iterator {
			iterator() {}
			iterator(const iterator & m) : _pos(m._pos), _farr(m._farr) {}
			iterator(for1array<value_type> * forarray, size_type pos) : _pos(pos), _farr(forarray) {}

			reference operator*() const
			{	// return designated object
				return (*_farr)[_pos];
			}

			pointer operator->() const
			{	// return pointer to class object
				return &(*_farr)[_pos];
			}

			iterator& operator++()
			{	// preincrement
				++_pos;
				return (*this);
			}

			iterator operator++(int)
			{	// postincrement
				iterator tmp = *this;
				++_pos;
				return (tmp);
			}

			iterator& operator--()
			{	// predecrement
				--_pos;
				return (*this);
			}

			iterator operator--(int)
			{	// postdecrement
				iterator tmp = *this;
				--_pos;
				return (tmp);
			}

			bool operator==(const iterator& _right) const
			{	// test for iterator equality
				return _right._pos == _pos && _right._farr == _farr;
			}

			bool operator!=(const iterator& _right) const
			{	// test for iterator inequality
				return _right._pos != _pos || _right._farr != _farr;
			}

			bool operator<(const iterator& _right) const
			{	// test if this < _Right
				return _pos < _right._pos;
			}

			bool operator>(const iterator& _right) const
			{	// test if this > _Right
				return _pos > _right._pos;
			}

			bool operator<=(const iterator& _right) const
			{	// test if this <= _Right
				return _pos <= _right._pos;
			}

			bool operator>=(const iterator& _right) const
			{	// test if this >= _Right
				return _pos >= _right._pos;
			}
		protected:
			size_type _pos;
			for1array<value_type> * _farr;
		};

		typename for1array<T>::iterator begin() {
			return iterator(this, this->LBound());
		}

		typename for1array<T>::iterator end() {
			return iterator(this, this->UBound());
		}

		for1array<T> slice(size_type fr, size_type to, size_type step = 1) const {
			std::vector<T> nvec;
			for (int i = fr; i < to; i += step)
			{
				nvec.push_back(m_arr[i - lb]);
			}
			return for1array<T>(nvec, fr, to);
		};
		size_type LBound() const {
			return lb;
		};
		size_type UBound() const {
			return ub;
		};
		size_type size() const {
			return ub - lb;
		}
		int f1a_kind() const {
			return 1;
		}
		const T & const_get(size_type i) const {
			if (i - lb >= (size_type)m_arr.size() || i - lb < 0) {
				throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & get(size_type i) {
			if (i - lb >= (size_type)m_arr.size() || i < lb) {
				m_arr.resize(i - lb + 1);
				ub = i + 1; // important
				return m_arr[i - lb];
				//throw 0;
			}
			else {
				return m_arr[i - lb];
			}
		}
		T & operator()(size_type i) {
			return this->get(i);
		}
		template<typename... Args>
		auto & operator()(size_type i, Args&&... args) {
			value_type & x = this->get(i);
			auto & y = x.operator()(std::forward<Args>(args)...);
			return y;
		}

		T & operator[](size_type i) {
			return get(i);
		}

		template<typename _Inner>
		for1array<T> & operator=(const std::vector<_Inner> & x) {
			f1a_init(*this, f1a_lbound(*this), f1a_getsize(*this), x);
			return *this;
		}
		for1array<T> & operator+=(const for1array<T> & x) {
			for (size_type i = x.LBound(); i < x.UBound(); i++)
			{
				m_arr.push_back(x.const_get(i));
			}
			this->ub += x.size();
			return *this;
}

		// deprecated
		template<class ... Args>
		void push_back(const T & x, Args&& ... args) {
			push_back(x);
			push_back(forward<Args>(args)...);
		}
		void push_back(const T & x) {
			m_arr.push_back(x);
		}

		void clear() {
			m_arr.clear();
		}
		void resize(size_type l, size_type u) {
			this->lb = l;
			this->ub = u;
		}
		template<typename _InnerT>
		for1array(const std::vector<size_type> & lower_bound, const std::vector<size_type> & size, const std::initializer_list<_InnerT> & values)
		{
			f1a_init(*this, lower_bound, size, values);
		}
		for1array(size_type l, size_type u) : lb(l), ub(u) {
			m_arr.resize(u - l);
		};
		for1array() : lb(0), ub(0) {

		};
		for1array(const for1array<T> & x) {
			m_arr.clear();
			(this->lb) = x.LBound();
			(this->ub) = x.UBound();
			for (size_type i = lb; i < ub; i++)
			{
				m_arr.push_back(x.const_get(i));
			}
		}

	protected:
		std::vector<T> m_arr;
		size_type lb, ub;
	};


	template <typename T>
	using f1a_matcher = const_func_matcher<T, f1a_size_t, &(T::size)>*;

	struct is_for1array
	{
		template<typename T>
		constexpr static bool test(f1a_matcher<T>)
		{
			return true;
		}

		template<typename T>
		constexpr static bool test(...)
		{
			return false;
		}
	};

	template<typename T>
	for1array<T> operator+(const for1array<T> & x, const for1array<T> & y) {
		for1array<T> n = for1array<T>(x);
		n += y;
		return n;
	}

	// base template must before inherited
	template<typename _DTYPE, int D>
	struct fornarray_impl {
		typedef typename for1array<typename fornarray_impl<_DTYPE, D - 1>::type> type;
	};
	template<typename _DTYPE>
	struct fornarray_impl<_DTYPE, 1> {
		typedef typename for1array<_DTYPE> type;
	};
	template<typename _DTYPE>
	struct fornarray_impl<_DTYPE, 0> {
		typedef typename _DTYPE type;
	};
	template<typename _DTYPE, int D>
	using fornarray = typename fornarray_impl<_DTYPE, D>::type;



	// get inner most type of nested for1array
	template <typename T>
	struct f1a_gettype {
		using type = T;
	};
	template<typename _Container_value_type>
	struct f1a_gettype<for1array<_Container_value_type>> {
		using type = typename f1a_gettype<_Container_value_type>::type;
	};


	template<typename _Container_value_type>
	std::vector<f1a_size_t> _f1a_getsize_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<f1a_size_t> & size
		, .../* SFINAE */) {
		size.push_back(farr.size());
		return size;
	}

	template<typename _Container_value_type>
	std::vector<f1a_size_t> _f1a_getsize_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<f1a_size_t> & size
		, f1a_matcher<_Container_value_type>/* SFINAE */) {
		size.push_back(farr.size());
		_f1a_getsize_layer<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<f1a_size_t> f1a_getsize(const for1array<_Container_value_type> & farr) {
		std::vector<f1a_size_t> size;
		_f1a_getsize_layer<_Container_value_type>(farr, size, nullptr);
		return size;
	}

	template<typename _Container_value_type>
	std::vector<f1a_size_t> _f1a_lbound_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<f1a_size_t> & lbound
		, .../* SFINAE */) {
		lbound.push_back(farr.LBound());
		return lbound;
	}

	template<typename _Container_value_type>
	std::vector<f1a_size_t> _f1a_lbound_layer(
		const for1array<_Container_value_type> & farr
		, std::vector<f1a_size_t> & lbound
		, f1a_matcher<_Container_value_type>/* SFINAE */) {
		lbound.push_back(farr.LBound());
		_f1a_lbound_layer<typename _Container_value_type::value_type>(farr.const_get(farr.LBound()), lbound, nullptr);
		return lbound;
	}

	template<typename _Container_value_type>
	std::vector<f1a_size_t> f1a_lbound(const for1array<_Container_value_type> & farr) {
		std::vector<f1a_size_t> lbound;
		_f1a_lbound_layer<_Container_value_type>(farr, lbound, nullptr);
		return lbound;
	}
#ifdef USE_FORARRAY
	template<typename _DTYPE, typename _Container_value_type, typename _Iterator, typename = void>
	void _f1a_init_layer(
		for1array<_DTYPE> & farr, int deep
		, const std::vector<f1a_size_t> & lower_bound
		, const std::vector<f1a_size_t> & size
		, const std::vector<f1a_size_t> & next_iter_delta
		, _Iterator b, _Iterator e)
	{
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			farr(i) = *iter;
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _DTYPE, typename _Container_value_type, typename _Iterator
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size()) >>
		void _f1a_init_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<f1a_size_t> & lower_bound
			, const std::vector<f1a_size_t> & size
			, const std::vector<f1a_size_t> & next_iter_delta
			, _Iterator b, _Iterator e)
	{
		auto iter = b;
		farr.resize(lower_bound[deep], lower_bound[deep] + size[deep]);
		for (auto i = lower_bound[deep]; i < lower_bound[deep] + size[deep]; i++)
		{
			_f1a_init_layer<_DTYPE, typename _Container_value_type::value_type, _Iterator>(farr(i), deep + 1, lower_bound, size
				, next_iter_delta, iter, iter + next_iter_delta[deep]);
			if (i != lower_bound[deep] + size[deep] - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _DTYPE, typename _Container_value_type>
	void f1a_init(
		for1array<_Container_value_type> & farr
		, const std::vector<f1a_size_t> & lower_bound
		, const std::vector<f1a_size_t> & size
		, const std::initializer_list<_DTYPE> & values)
	{
		/* NOTE: assume the array is already allocated and no need to clear */
		std::vector<f1a_size_t> next_iter_delta = f1a_layer_delta(size.begin(), size.end());
		_f1a_init_layer<_DTYPE, _Container_value_type, std::initializer_list<_DTYPE>::const_iterator >(farr, 0, lower_bound, size
			, next_iter_delta, values.begin(), values.end());
	};

	template<typename _InnerT, int D>
	fornarray<_InnerT, D> f1a_gen(
		const std::vector<f1a_size_t> & lower_bound
		, const std::vector<f1a_size_t> & size
		, const std::initializer_list<_InnerT> & values)
	{
		fornarray<_InnerT, D> n;
		f1a_init(n, lower_bound, size, values);
		return n;
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return, typename = void>
	void _f1a_flatmapped_layer(
		for1array<_DTYPE> & farr, int deep
		, const std::vector<f1a_size_t> & next_iter_delta
		, _Iterator b, _Iterator e
		, std::function<_Return(typename _DTYPE *)> mapper)
	{
		auto iter = b;
		for (auto i = farr.LBound(); i < farr.UBound(); i++)
		{
			(*iter) = mapper(&(farr.get(i)));
			if (i != farr.UBound() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _DTYPE, typename _Iterator, typename _Return
		, typename = std::void_t< decltype(std::declval<_Container_value_type>().size())> >
		void _f1a_flatmapped_layer(
			for1array<_Container_value_type> & farr, int deep
			, const std::vector<f1a_size_t> & next_iter_delta
			, _Iterator b, _Iterator e
			, std::function<_Return(typename _DTYPE *)> mapper)
	{
		/* deep can never be equal to size.size() - 1 */
		auto iter = b;
		for (auto i = farr.LBound(); i < farr.UBound(); i++)
		{
			/* NOTE: assume the array is already allocated and no need to clear */
			_f1a_flatmapped_layer<typename _Container_value_type::value_type, _DTYPE, _Iterator>(
				farr(i), deep + 1, next_iter_delta, iter, iter + next_iter_delta[deep], mapper);
			if (i != farr.UBound() - 1) {
				iter += next_iter_delta[deep];
			}
		}
	};

	template<typename _Container_value_type, typename _Return>
	auto f1a_flatmapped(for1array<_Container_value_type> & farr, std::function<_Return(typename f1a_gettype<_Container_value_type>::type *)> mapper)
		-> std::vector< _Return >
	{
		typedef typename f1a_gettype<_Container_value_type>::type T; // inner most type
		std::vector<f1a_size_t> size = f1a_getsize(farr); // size of each dimension of array
		f1a_size_t sizeflat = accumulate(size.begin(), size.end(), 1, [](auto x, auto y) {return x * y; });
		std::vector< _Return > flat(sizeflat); // size of flatterned array
		std::vector<f1a_size_t> next_iter_delta = f1a_layer_delta(size.begin(), size.end());
		typedef std::conditional<std::is_same<_Container_value_type, T>::value, T, _Container_value_type >::type _New_value_type;
		_f1a_flatmapped_layer<_New_value_type, T, std::vector<_Return>::iterator >(farr, 0, next_iter_delta, flat.begin(), flat.end(), mapper);
		return flat;
	};

	template<typename _Container_value_type, typename _Return>
	auto f1a_flatmapped_const(const for1array<_Container_value_type> & farr, std::function<_Return(typename const f1a_gettype<_Container_value_type>::type *)> mapper)
		->std::vector< _Return >
	{
		return f1a_flatmapped(const_cast<for1array<_Container_value_type> &>(farr), mapper);
	}

	// refer temp.log for full version
	template<typename _Container_value_type>
	auto f1a_flatterned(const for1array<_Container_value_type> & farr)
		//-> std::vector< typename f1a_gettype<_Container_value_type>::type > 
	{
		return f1a_flatmapped<_Container_value_type, typename f1a_gettype<_Container_value_type>::type>(
			const_cast<for1array<_Container_value_type> &>(farr), [](typename const f1a_gettype<_Container_value_type>::type * tx) {return *tx; });
	}
	template<typename _Container_value_type>
	auto f1a_flatternedptr(for1array<_Container_value_type> & farr)
		//-> std::vector< typename f1a_gettype<_Container_value_type>::type * > 
	{
		return f1a_flatmapped<_Container_value_type, typename f1a_gettype<_Container_value_type>::type *>(
			farr, [](typename f1a_gettype<_Container_value_type>::type * tx) {return tx; });
	}

	template<typename _Container_value_type>
	void f1a_mapdim(for1array<_Container_value_type> & farr, std::function<void(typename f1a_gettype<_Container_value_type>::type &)> mapper) {

	}
#else

#endif

	template<typename T>
	auto _f1a_init_hiddendo(typename for1array<T>::size_type start, typename for1array<T>::size_type end, std::function<T(typename for1array<T>::size_type) > get_T)
	{
		for1array<T> rt;
		for (auto i = start; i < end; i++) {
			rt(i) = get_T(i);
		}
		return rt;
	}

	template <typename T>
	auto f1a_init_hiddendo(typename for1array<T>::size_type from, typename for1array<T>::size_type to, T lambda)
		-> for1array<typename function_traits<T>::result_type> {
		return _f1a_init_hiddendo<function_traits<decltype(lambda)>::result_type>(from, to, lambda);
	}
	template<typename T, typename... Args>
	auto slice(const for1array<T> & farr, const slice_info<typename for1array<T>::size_type> & tp, Args... args) {
		return slice(farr.slice(tp.fr, tp.to, tp.step), std::forward<Args>(args)...);
	}

	template <typename T>
	auto slice(const for1array<T> & farr, const slice_info<typename for1array<T>::size_type> & tp) {
		return farr.slice(tp.fr, tp.to, tp.step);
	}

	inline std::string slice(std::string str, const slice_info<std::string::size_type> & tp) {
		if (tp.to >= str.size()) {
			size_t appendlen = tp.to - str.size() + 2;
			str += std::string(appendlen, ' ');
		}
		if (tp.step == 1) {
			return str.substr(tp.fr, tp.to - tp.fr);
		}
		else {
			std::string newstr;
			for (size_t i = tp.fr; i < tp.to; i+= tp.step)
			{
				newstr += str[i];
			}
			return newstr;
		}
	}

	//template<int D, typename T>
	//auto forreshape(const std::initializer_list<T> & values, const f1a_size_t(&shape)[D])
	//{
	//	std::vector<f1a_size_t> lbound = std::vector<f1a_size_t>(D, 1);
	//	std::vector<f1a_size_t> size = std::vector<f1a_size_t>(shape, shape + D);
	//	return f1a_gen<T, D>(lbound, size, values);
	//}

	//template <typename T>
	//fornarray<T, 2> fortranspose(const for1array<T> & farr) {

	//}

	//// 1d vector -> 2d matrix
	//template <typename T>
	//fornarray<T, 2> f1a_promote(const fornarray<T, 1> & farr) {

	//}
	

}

