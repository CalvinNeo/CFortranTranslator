/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "for1array.h"
#include "farray.h"
#include <complex>

// If forced reversion occurs, FORTRAN 77 advances to the next record and rescans the format, starting with the right-most left parenthesis, including any repeat-count indicators. It then re-uses this part of the format. If there are no inner parenthesis in the FORMAT statement, then the entire format is reused.
// 若编辑符表中含有重复使用的编辑符组，如2(2X,F3)，则当所有编辑符用完之后，返回至最右边的左括号开始，如果没有左括号，则使用全部
//If format control encounters the rightmost parenthesis of a complete format specification and another effective
//input / output list item is not specified, format control terminates.However, if another effective input / output list
//item is specified, the file is positioned in a manner identical to the way it is positioned when a slash edit
//descriptor is processed(10.6.2).Format control then reverts to the beginning of the format item terminated by the
//last preceding right parenthesis.If there is no such preceding right parenthesis, format control reverts to the first
//left parenthesis of the format specification.If any reversion occurs, the reused portion of the format specification
//must contain at least one data edit descriptor.If format control reverts to a parenthesis that is preceded by a
//repeat specification, the repeat specification is reused.Reversion of format control, of itself, has no effect on the
//scale factor(10.6.5.1), the sign control edit descriptors(10.6.4), or the blank interpretation edit descriptors
//(10.6.6).

namespace for90std {
	template<typename T, typename F>
	struct IOLambda {
		IOLambda(int D, fsize_t * _lb, fsize_t * _to, F func ) : dim(D), f(func) {
			lb = new fsize_t[dim];
			sz = new fsize_t[dim];
			cur = new fsize_t[dim];
			std::copy_n(_lb, D, lb);
			for (int i = 0; i < dim; i++)
			{
				sz[i] = _to[i] - lb[i] + 1;
			}
			_map_impl_reset(cur, dim, cur_dim, lb, sz);
		}
		IOLambda(const IOLambda<T, F> & x) : f(x.f) {
			// TODO IOLambda is better passed by reference
			dim = x.dim;
			cur_dim = x.cur_dim;
			lb = new fsize_t[dim];
			sz = new fsize_t[dim];
			cur = new fsize_t[dim];
			std::copy_n(x.lb, dim, lb);
			std::copy_n(x.sz, dim, sz);
			std::copy_n(x.cur, dim, cur);
		}
		~IOLambda() {
			if (lb != nullptr)
			{
				delete[] lb;
				lb = nullptr;
			}
			if (sz != nullptr)
			{
				delete[] sz;
				sz = nullptr;
			}
			if (cur != nullptr)
			{
				delete[] cur;
				cur = nullptr;
			}
		}
		bool has_next() const {
			return _map_impl_has_next(cur, dim, lb, sz);
		}
		T get_next() const {
			T ans;
			auto newf = [&](fsize_t * _) {
				// move from expiring value to `ans`
				ans = std::move(f(_));
			};
			_map_impl_next(newf, cur, dim, cur_dim, lb, sz);
			return ans;
		}
		T & get_next() {
			T * ptr = nullptr;
			auto newf = [&](const fsize_t * _) {
				// f(_) must return left-value
				ptr = & f(_);
			};
			_map_impl_next(newf, cur, dim, cur_dim, lb, sz);
			return *ptr;
		}
		int dim;
		mutable int cur_dim;
		fsize_t * lb = nullptr, * sz = nullptr, *cur = nullptr;
		F f;
	};

	template <int D, typename F>
	auto make_iolambda(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func) {
		typedef typename function_traits<decltype(func)>::result_type T;
		return IOLambda<T, F>{D, (fsize_t *)_lb, (fsize_t *)_to, func};
	};
	template <typename T, int D, typename F>
	auto make_iolambda(fsize_t * _lb, fsize_t * _to, F func) {
		typedef typename function_traits<decltype(func)>::result_type T;
		return IOLambda<T, F>{D, _lb, _to, func};
	};

	template<typename ... Types>
	struct IOStuff {
		IOStuff() {

		}
		IOStuff(const std::tuple<Types...> & _tp) : tp(_tp) {

		}
		IOStuff(const IOStuff<Types...> & _m) {
			this->tp = _m.tp;
		}
		std::tuple<Types...> tp;
	};

	template<typename ... Types>
	IOStuff<Types...> make_iostuff(const std::tuple<Types...> & _tp) {
		return IOStuff<Types...>(_tp);
	}

	struct IOFormat {
		IOFormat(const char * ch) : reversion_start(0) {
			format = std::string(ch);
		}
		IOFormat(const std::string & s) : reversion_start(0) {
			format = s;
		}
		IOFormat(const char * ch, int rev_start) : reversion_start(rev_start) {
			format = std::string(ch);
		}
		IOFormat(const std::string & s, int rev_start) : reversion_start(rev_start) {
			format = s;
		}
		int reversion_start;
		std::string format;
	};


	inline std::string _forwrite_noargs(FILE * f, const std::string & format) {
		for (size_t i = 0; i < format.size(); i++)
		{
			switch (format[i])
			{
			case '\\':
				if (i + 1 < format.size()) {
					// escape character
					fprintf(f, format.substr(i, 2).c_str());
				}
				i++;
				break;
			case '%':
				return format.substr(i);
			default:
				fprintf(f, format.substr(i, 1).c_str());
				break;
			}
		}
		return format;
	}

	template <typename T>
	void _str_fprintf(FILE * f, std::string _format, const T & x) {
		fprintf(f, _format.c_str(), x);
	}
	inline void _str_fprintf(FILE * f, std::string _format, const std::string & x) {
		fprintf(f, _format.c_str(), x.c_str());
	}

	
	// format
	// write formatted step 2
	template <typename T>
	std::string _forwrite_one(FILE * f, std::string format, const T & x) {
		// clear front
		std::string _format = _forwrite_noargs(f, format);
		if (_format != "") {
			// now start from '%' or _format is empty string
			size_t e = _format.find_first_of('%', 1);
			if (e == std::string::npos) {
				// the last formatter
				_str_fprintf(f, _format, x);
				return "";
			}
			else {
				_str_fprintf(f, _format.substr(0, e), x);
				return _format.substr(e);
			}
		}
		else {
			_str_fprintf(f, _format, x);
			return "";
		}
	};
	template <typename T>
	std::string _forwrite_one_arr1(FILE * f, std::string format, const T & x) {
		// clear front
		std::string _format = _forwrite_noargs(f, format);
		typedef typename f1a_gettype<T>::type _InnerT;
		std::vector<_InnerT> vec = f1a_flatterned(x);
		for (auto i = 0; i < vec.size(); i++)
		{
			if (_format == "") {
				_format = format;
			}
			_format = _forwrite_one(f, _format, vec[i]);
		}
		if (_format.find_first_of("%") != std::string::npos) {
			fprintf(f, "\n");
		}
		return _format;
	};
	template <typename T>
	std::string _forwrite_one_arrf(FILE * f, std::string format, const farray<T> & x) {
		// clear front
		std::string _format = _forwrite_noargs(f, format);
		auto iter = x.cbegin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			if (_format == "") {
				_format = format;
			}
			_format = _forwrite_one(f, _format, *(iter + i));
		}
		if (_format.find_first_of("%") != std::string::npos) {
			fprintf(f, "\n");
		}
		return _format;
	};
	// write formatted step 1
	template <typename T>
	std::string _forwrite_dispatch(FILE * f, std::string format, const for1array<T> & x) {
		return _forwrite_one_arr1(f, format, x);
	};
	template <typename T>
	std::string _forwrite_dispatch(FILE * f, std::string format, const farray<T> & x) {
		return _forwrite_one_arrf(f, format, x);
	};
	template <typename T>
	std::string _forwrite_dispatch(FILE * f, std::string format, const T & x) {
		return _forwrite_one(f, format, x);
	};
	template <typename T, typename F>
	std::string _forwrite_dispatch(FILE * f, std::string format, IOLambda<T, F> & l) {
		string _format = format;
		while (l.has_next())
		{
			_format = _forwrite_dispatch(f, _format, l.get_next());
		}
		return  _format;
	};

	// write formatted step 0
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, T x, Args... args) {
		format = _forwrite_dispatch(f, format, x);
		forwrite(f, format, std::forward<Args>(args)...);
	};
	inline void forwrite(FILE * f, std::string format) {
		// clear end
		_forwrite_noargs(f, format);
	};

	// free format
	// write free step 2
	inline void _forwritefree_one(FILE * f, int x) {
		fprintf(f, "%d", x);
	};
	inline void _forwritefree_one(FILE * f, long long x) {
		fprintf(f, "%lld", x);
	};
	inline void _forwritefree_one(FILE * f, double x) {
		fprintf(f, "%lf", x);
	};
	inline void _forwritefree_one(FILE * f, long double x) {
		fprintf(f, "%Lf", x);
	};
	inline void _forwritefree_one(FILE * f, std::string x) {
		fprintf(f, "%s", x.c_str());
	};
	inline void _forwritefree_one(FILE * f, bool x) {
		fprintf(f, "%s", x ? "T" : "F");
	};
	inline void _forwritefree_one(FILE * f, const char * x) {
		fprintf(f, "%s", x);
	};
	template <typename T>
	void _forwritefree_one(FILE * f, T x) {
		fprintf(f, "[object %s] %p", typeid(T).name(), &x);
	};
	template <typename T>
	void _forwritefree_one_arr1(FILE * f, const for1array<T> &  x) {
		typedef typename f1a_gettype<T>::type _InnerT;
		std::vector<_InnerT> vec = f1a_flatterned(x);
		for (auto i = 0; i < vec.size(); i++)
		{
			_forwritefree_one(f, vec[i]);
			fprintf(f, "\t");
		}
	};
	template <typename T>
	void _forwritefree_one_arrf(FILE * f, const farray<T> & x) {
		auto iter = x.cbegin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			_forwritefree_one(f, *(iter + i));
			fprintf(f, "\t");
		}
		fprintf(f, "\n");
	};
	// write free step 1
	template <typename T>
	void _forwritefree_dispatch(FILE * f, const for1array<T> & x) {
		_forwritefree_one_arr1(f, x);
	};
	template <typename T>
	void _forwritefree_dispatch(FILE * f, const farray<T> & x) {
		_forwritefree_one_arrf(f, x);
	};
	template <typename T>
	void _forwritefree_dispatch(FILE * f, const T & x) {
		_forwritefree_one(f, x);
	};
	template <typename ... Types>
	void _forwritefree_dispatch(FILE * f, const typename IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto x) {
			_forwritefree_dispatch(f, x);
		});
	};
	template <typename T, typename F>
	void _forwritefree_dispatch(FILE * f, const IOLambda<T, F> & l) {
		while (l.has_next())
		{
			const T & x = l.get_next();
			_forwritefree_dispatch(f, x);
		}
	};

	// write free step 0
	template <typename T, typename... Args>
	void forwritefree(FILE * f, const T & x, Args... args) {
		_forwritefree_dispatch(f, x);
		forwritefree(f, std::forward<Args>(args)...);
	};
	template <typename T>
	void forwritefree(FILE * f, const T & x) {
		_forwritefree_dispatch(f, x);
	};


	template <typename T, typename... Args>
	void forprintfree(const T & x, Args... args) {
		// no format
		forwritefree(stdout, x, std::forward<Args>(args)...);
	};
	template <typename T>
	void forprintfree(const T & x) {
		forwritefree(stdout, x);
	};
	template <typename T, typename... Args>
	void forprint(std::string format, const T & x, Args... args) {
		// format
		forwrite(stdout, format, x, std::forward<Args>(args)...);
	};
	inline void forprint(std::string format) {
		forwrite(stdout, format);
	};
	

	// read
	inline std::string _forread_noargs(FILE * f, std::string format) {
		char x;
		std::string::iterator it = format.begin();
		while (fscanf(f, "%c", &x) != EOF)
		{
			if (x == *it) {
				it++;
			}
			else if (x == '%') {
				break;
			}
			else {
				// error
				throw 0;
			}
		}
		return std::string(it, format.end());
	}


	template <typename T>
	void _str_fscanf(FILE * f, std::string _format, T & x) {
		fscanf(f, _format.c_str(), &x);
	}
	inline void _str_fscanf(FILE * f, std::string _format, std::string & x) {
		std::cin >> x;
	}
	// read formatted step 2
	template <typename T>
	void _forread_one(FILE * f, std::string format, T & x) {
		// clear front
		std::string _format = _forread_noargs(f, format);
		if (_format != "") {
			// now start from '%' or _format is empty string
			size_t e = _format.find_first_of('%', 1);
			if (e == std::string::npos) {
				// the last formatter
				_str_fscanf(f, _format, x);
				return "";
			}
			else {
				_str_fscanf(f, _format.substr(0, e), x);
				return _format.substr(e);
			}
		}
		else {
			_str_fscanf(f, _format, x);
			return "";
		}
	};
	template <typename T>
	void _forread_one_arr1(FILE * f, std::string format, for1array<T> & x) {

	};
	template <typename T>
	void _forread_one_arrf(FILE * f, std::string format, farray<T> & x) {

	};
	// read formatted step 1
	template <typename T>
	std::string _forread_dispatch(FILE * f, std::string format, for1array<T> & x) {
		return _forread_one_arr1(f, format, x);
	};
	template <typename T>
	std::string _forread_dispatch(FILE * f, std::string format, farray<T> & x) {
		return _forread_one_arrf(f, format, x);
	};
	template <typename T>
	std::string _forread_dispatch(FILE * f, std::string format, T & x) {
		return _forread_one(f, format, x);
	};
	template <typename T, typename F>
	std::string _forread_dispatch(FILE * f, std::string format, IOLambda<T, F> & l) {
		string _format = format;
		while (l.has_next())
		{
			_format = _forread_dispatch(f, _format, l.get_next());
		}
		return _format;
	};
	// read formatted step 0
	template <typename T, typename... Args>
	void forread(FILE * f, std::string format, T & x, Args... args) {
		format = _forread_dispatch(f, format, x);
		forread(f, format, std::forward<Args>(args)...);
	};
	template <typename T>
	void forread(FILE * f, std::string format, T & x) {
		format = _forread_dispatch(f, format, x);
	};

	// free format
	// read free step 2
	template <typename T>
	void _forreadfree_one(FILE * f, T & x) {
		std::cin >> x;
	};
	template <typename T>
	void _forreadfree_one_arr1(FILE * f, for1array<T> & x) {

	};
	template <typename T>
	void _forreadfree_one_arrf(FILE * f, farray<T> & x) {
		auto iter = x.begin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			_forreadfree_one(f, *(iter + i));
		}
	};
	// read free step 1
	template <typename T>
	void _forreadfree_dispatch(FILE * f, for1array<T> & x) {
		_forreadfree_one_arr1(f, x);
	};
	template <typename T>
	void _forreadfree_dispatch(FILE * f, farray<T> & x) {
		_forreadfree_one_arrf(f, x);
	};
	template <typename T>
	void _forreadfree_dispatch(FILE * f, T & x) {
		_forreadfree_one(f, x);
	};
	template <typename ... Types>
	void _forreadfree_dispatch(FILE * f, IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto & x) {
			 _forreadfree_dispatch(f, x);
		});
	};
	template <typename T, typename F>
	void _forreadfree_dispatch(FILE * f, IOLambda<T, F> & l) {
		while (l.has_next())
		{
			_forreadfree_dispatch(f, l.get_next());
		}
	};
	// read free step 0
	template <typename T, typename... Args>
	void forreadfree(FILE * f, T & x, Args &&... args) {
		_forreadfree_dispatch(f, x);
		forreadfree(f, std::forward<Args>(args)...);
	};
	template <typename T>
	void forreadfree(FILE * f, T & x) {
		_forreadfree_dispatch(f, x);
	};
}