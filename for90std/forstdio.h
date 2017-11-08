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
	struct ImpliedDo {
		ImpliedDo(int D, fsize_t * fr, fsize_t * to, F func) : dim(D), f(func) {
			lb = new fsize_t[dim];
			sz = new fsize_t[dim];
			cur = new fsize_t[dim];
			std::copy_n(fr, D, lb);
			for (int i = 0; i < dim; i++)
			{
				sz[i] = to[i] - lb[i] + 1;
			}
			_map_impl_reset(cur, dim, cur_dim, lb, sz);
		}
		ImpliedDo(const ImpliedDo<T, F> & x) : f(x.f) {
			// TODO ImpliedDo is better passed by reference
			dim = x.dim;
			cur_dim = x.cur_dim;
			lb = new fsize_t[dim];
			sz = new fsize_t[dim];
			cur = new fsize_t[dim];
			std::copy_n(x.lb, dim, lb);
			std::copy_n(x.sz, dim, sz);
			std::copy_n(x.cur, dim, cur);
		}
		//ImpliedDo() {

		//}
		//ImpliedDo & operator=(const ImpliedDo & x) {
		//	if (this == &x) return *this;
		//	dim = x.dim;
		//	cur_dim = x.cur_dim;
		//	lb = new fsize_t[dim];
		//	sz = new fsize_t[dim];
		//	cur = new fsize_t[dim];
		//	std::copy_n(x.lb, dim, lb);
		//	std::copy_n(x.sz, dim, sz);
		//	std::copy_n(x.cur, dim, cur);
		//	return *this;
		//}
		~ImpliedDo() {
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
			std::function<T(void)> cps_retrieve;
			auto newf = [&](fsize_t * _) {
				// move from expiring value to `ans`
				//ans = std::move(f(_));
				T ans = f(_);
				cps_retrieve = [=]() -> T {
					return ans;
				};
			};
			_map_impl_next(newf, cur, dim, cur_dim, lb, sz);
			return cps_retrieve();
		}

		int dim;
		mutable int cur_dim;
		fsize_t * lb = nullptr, *sz = nullptr, *cur = nullptr;
		F f;
	};

	template <int D, typename F>
	auto make_implieddo(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func) {
		typedef typename function_traits<decltype(func)>::result_type T;
		return ImpliedDo<T, F>{D, (fsize_t *)_lb, (fsize_t *)_to, func};
	};
	template <int D, typename F>
	auto make_implieddo(fsize_t * _lb, fsize_t * _to, F func) {
		typedef typename function_traits<decltype(func)>::result_type T;
		return ImpliedDo<T, F>{D, _lb, _to, func};
	};

	template<typename ... Types>
	struct IOStuff {
		IOStuff() {

		}
		IOStuff(const std::tuple<Types...> & _tp) : tp(_tp) {

		}
		IOStuff(const IOStuff<Types...> & _m) : tp(_m.tp) {

		}

		std::tuple<Types...> tp;
	};

	template<typename ... Types>
	IOStuff<Types...> make_iostuff(const std::tuple<Types...> & _tp) {
		return IOStuff<Types...>(_tp);
	}

	struct IOFormat {
		IOFormat(const char * ch) : reversion_start(0), p(0) {
			fmt = std::string(ch);
			reversion_end = (int)fmt.size();
		}
		IOFormat(const std::string & s) : reversion_start(0), p(0) {
			fmt = s;
			reversion_end = (int)fmt.size();
		}
		IOFormat(const char * ch, int rev_start) : reversion_start(rev_start), p(0) {
			fmt = std::string(ch);
			reversion_end = (int)fmt.size();
		}
		IOFormat(const std::string & s, int rev_start) : reversion_start(rev_start), p(0) {
			fmt = s;
			reversion_end = (int)fmt.size();
		}
		IOFormat(const char * ch, int rev_start, int rev_end) : reversion_start(rev_start), reversion_end(rev_end), p(0) {
			fmt = std::string(ch);
		}
		IOFormat(const std::string & s, int rev_start, int rev_end) : reversion_start(rev_start), reversion_end(rev_end), p(0) {
			fmt = s;
		}

		IOFormat & operator=(const IOFormat & x) {
			if (this == &x) return *this;
			fmt = x.fmt;
			reversion_start = x.reversion_start;
			p = 0;
			return *this;
		}

		const char & operator[](size_t off) const {
			return fmt[off];
		}
		char & operator[](size_t off) {
			return fmt[off];
		}
		size_t size() const {
			return fmt.size();
		}
		std::string substr(size_t offset = 0, size_t count = std::string::npos) const {
			return fmt.substr(offset, count);
		}
		const char * c_str() const {
			return fmt.c_str();
		}
		size_t & index() const {
			if ((int)p >= reversion_end)
			{
				p = reversion_start;
			}
			return p;
		}
		
		std::string strip_front() const {
			size_t st = index();
			size_t i = st;
			for (; i < size(); i++)
			{
				switch (fmt[i])
				{
				case '\\':
					if (i + 1 < size()) {
						// escape character
					}
					i++;
					break;
				case '%':
					// start of placeholder
					goto RETURN_FRONT;
				default:
					break;
				}
			}
		RETURN_FRONT:
			std::string sub = fmt.substr(st, i - st);
			index() = i;
			return sub;
		}

		std::string next_editing() const {
			std::string editing;
			size_t st = index();
			assert(st >= size() || fmt[st] == '%'); // start with an editing
			size_t e = fmt.find_first_of('%', st + 1); // find next editing
			if (e == std::string::npos) {
				// the last editing
				if (reversion_end == (int)fmt.size())
				{
					editing = fmt.substr(st, e - st);
					index() = e;
				}
				else {
					editing = fmt.substr(st, reversion_end - st);
					index() = reversion_end;
				}
			}
			else {
				editing = fmt.substr(st, e - st);
				index() = e;
			}
			return editing;
		}

		void end_this_line() const {
			size_t st = index();
			while (st < fmt.size() && fmt[st] != '\n') {
				index() = index() + 1;
			}
		}

		std::string end_format() const {
			// IIF after all inputs are swallowed, print the rest of the format string
			size_t st = reversion_end;
			std::string s;
			for (; st < fmt.size(); st++)
			{
				if (fmt[st] == '%') {
					st++;
					continue;
				}
				else {
					s += fmt[st];
				}
			}
			return s;
		}

		int reversion_start, reversion_end;
		mutable size_t p;
		std::string fmt;
	};


	inline void _forwrite_noargs(FILE * f, IOFormat & format) {
		fprintf(f, format.strip_front().c_str());
		return;
	}

	template <typename T>
	void _str_fprintf(FILE * f, const std::string & _format, const T & x) {
		fprintf(f, _format.c_str(), x);
	}
	inline void _str_fprintf(FILE * f, const std::string & _format, const std::string & x) {
		fprintf(f, _format.c_str(), x.c_str());
	}


	// format
	// write formatted step 2
	template <typename T>
	void _forwrite_one(FILE * f, IOFormat & format, const T & x) {
		// strip front
		_forwrite_noargs(f, format);
		std::string ed = format.next_editing();
		fprintf(f, ed.c_str(), x);
	};
	inline void _forwrite_one(FILE * f, IOFormat & format, const std::string & x) {
		// strip front
		_forwrite_noargs(f, format);
		std::string ed = format.next_editing();
		fprintf(f, ed.c_str(), x.c_str());
	};
	//template <typename T>
	//void _forwrite_one_arr1(FILE * f, IOFormat & format, const T & x) {
	//	// clear front
	//	_forwrite_noargs(f, format);
	//	typedef typename f1a_gettype<T>::type _InnerT;
	//	std::vector<_InnerT> vec = f1a_flatterned(x);
	//	for (size_t i = 0; i < vec.size(); i++)
	//	{
	//		_forwrite_dispatch(f, format, vec[i]);
	//	}
	//	return;
	//};
	template <typename T>
	void _forwrite_one_arrf(FILE * f, IOFormat & format, const farray<T> & x) {
		// clear front
		_forwrite_noargs(f, format);
		auto iter = x.cbegin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			_forwrite_dispatch(f, format, *(iter + i));
		}
		return;
	};
	// write formatted step 1
	//template <typename T>
	//void _forwrite_dispatch(FILE * f, IOFormat & format, const for1array<T> & x) {
	//	_forwrite_one_arr1(f, format, x);
	//};
	template <typename T>
	void _forwrite_dispatch(FILE * f, IOFormat & format, const farray<T> & x) {
		_forwrite_one_arrf(f, format, x);
	};
	template <typename T>
	void _forwrite_dispatch(FILE * f, IOFormat & format, const T & x) {
		_forwrite_one(f, format, x);
	};
	template <typename ... Types>
	void _forwrite_dispatch(FILE * f, IOFormat & format, const IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto x) {
			_forwrite_dispatch(f, format, x);
		});
	};
	template <typename T, typename F>
	void _forwrite_dispatch(FILE * f, IOFormat & format, const ImpliedDo<T, F> & l) {
		format.strip_front();
		while (l.has_next())
		{
			_forwrite_dispatch(f, format, l.get_next());
		}
		return;
	};

	// write formatted step 0
	template <typename T, typename... Args>
	void forwrite(FILE * f, IOFormat & format, const T & x, Args&&... args) {
		_forwrite_dispatch(f, format, x);
		forwrite(f, format, std::forward<Args>(args)...);
	};
	template <typename T, typename... Args>
	void forwrite(FILE * f, const std::string & format, const T & x, Args&&... args) {
		IOFormat _format(format);
		_forwrite_dispatch(f, _format, x);
		forwrite(f, _format, std::forward<Args>(args)...);
	};
	inline void forwrite(FILE * f, IOFormat & format) {
		// clear end
		//_forwrite_noargs(f, format);
		std::string ss = format.end_format();
		fprintf(f, ss.c_str());

	};
	inline void forwrite(FILE * f, const std::string & format) {
		// clear end
		IOFormat _format(format);
		//_forwrite_noargs(f, _format);
		std::string ss = _format.end_format();
		fprintf(f, ss.c_str());
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

	//template <typename T>
	//void _forwritefree_one_arr1(FILE * f, const for1array<T> &  x) {
	//	typedef typename f1a_gettype<T>::type _InnerT;
	//	std::vector<_InnerT> vec = f1a_flatterned(x);
	//	for (size_t i = 0; i < vec.size(); i++)
	//	{
	//		_forwritefree_one(f, vec[i]);
	//		fprintf(f, "\t");
	//	}
	//};
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
	//template <typename T>
	//void _forwritefree_dispatch(FILE * f, const for1array<T> & x) {
	//	_forwritefree_one_arr1(f, x);
	//};
	template <typename T>
	void _forwritefree_dispatch(FILE * f, const farray<T> & x) {
		_forwritefree_one_arrf(f, x);
	};
	template <typename T>
	void _forwritefree_dispatch(FILE * f, const T & x) {
		_forwritefree_one(f, x);
	};
	template <typename ... Types>
	void _forwritefree_dispatch(FILE * f, const IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto x) {
			_forwritefree_dispatch(f, x);
		});
	};
	template <typename T, typename F>
	void _forwritefree_dispatch(FILE * f, const ImpliedDo<T, F> & l) {
		while (l.has_next())
		{
			const T & x = l.get_next();
			_forwritefree_dispatch(f, x);
		}
	};

	// write free step 0
	template <typename T, typename... Args>
	void forwritefree(FILE * f, const T & x, Args&&... args) {
		_forwritefree_dispatch(f, x);
		fprintf(f, "\t");
		forwritefree(f, std::forward<Args>(args)...);
	};
	template <typename T>
	void forwritefree(FILE * f, const T & x) {
		_forwritefree_dispatch(f, x);
		fprintf(f, "\n");
	};
	inline void forwritefree(FILE * f) {
		fprintf(f, "\n");
	};


	template <typename T, typename... Args>
	void forprintfree(const T & x, Args&&... args) {
		// no format
		forwritefree(stdout, x, std::forward<Args>(args)...);
	};
	inline void forprintfree() {
		forwritefree(stdout, "\n");
	};

	template <typename T, typename... Args>
	void forprint(IOFormat && format, const T & x, Args&&... args) {
		// format
		forwrite(stdout, format, x, std::forward<Args>(args)...);
	};
	template <typename T, typename... Args>
	void forprint(const std::string & format, const T & x, Args&&... args) {
		// format
		forwrite(stdout, format, x, std::forward<Args>(args)...);
	};
	inline void forprint(IOFormat & format) {
		forwrite(stdout, format);
	};
	inline void forprint(const std::string & format) {
		forwrite(stdout, format);
	};


	// read
	inline void _forread_noargs(FILE * f, IOFormat & format) {
		format.strip_front();
	}

	template <typename T>
	void _str_fscanf(FILE * f, const std::string & _format, T & x) {
		fscanf(f, _format.c_str(), &x);
	}
	inline void _str_fscanf(FILE * f, const std::string & _format, std::string & x) {
		//		std::ifstream ifs(f);
		//		ifs >> x;
		const unsigned N = 1024;
		while (true) {
			std::vector<char> buf(N);
			size_t read = fread((void *)&buf[0], 1, N, f);
			if (read) {
				x.append(buf.begin(), buf.end());
			}
			if (read < N) {
				break;
			}
		}
	}

	// read formatted step 2
	template <typename T>
	void _forread_one(FILE * f, IOFormat & format, T & x) {
		// strip front
		_forread_noargs(f, format);
		fscanf(f, format.next_editing().c_str(), &x);
	};
	inline void _forread_one(FILE * f, IOFormat & format, std::string & x) {
		// strip front
		_forread_noargs(f, format);
		std::string fmt = format.next_editing();
		_str_fscanf(f, fmt, x);
	};
	//template <typename T>
	//void _forread_one_arr1(FILE * f, IOFormat & format, for1array<T> & x) {

	//};
	template <typename T>
	void _forread_one_arrf(FILE * f, IOFormat & format, farray<T> & x) {
		// clear front
		_forread_noargs(f, format);
		auto iter = x.cbegin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			_forread_dispatch(f, format, *(iter + i));
		}
	};
	// read formatted step 1
	//template <typename T>
	//void _forread_dispatch(FILE * f, IOFormat & format, for1array<T> * x) {
	//	_forread_one_arr1(f, format, *x);
	//};
	template <typename T>
	void _forread_dispatch(FILE * f, IOFormat & format, farray<T> * x) {
		_forread_one_arrf(f, format, *x);
	};
	template <typename T>
	void _forread_dispatch(FILE * f, IOFormat & format, T * x) {
		_forread_one(f, format, *x);
	};
	template <typename ... Types>
	void _forread_dispatch(FILE * f, IOFormat & format, IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto & x) {
			_forread_dispatch(f, x);
		});
	};
	template <typename T, typename F>
	void _forread_dispatch(FILE * f, IOFormat & format, ImpliedDo<T, F> & l) {
		format.strip_front();
		while (l.has_next())
		{
			_forread_dispatch(f, format, l.get_next());
		}
	};

	// read formatted step 0
	template <typename T, typename... Args>
	void forread(FILE * f, IOFormat & format, T&& x, Args&&... args) {
		_forread_dispatch(f, format, x);
		forread(f, format, std::forward<Args>(args)...);
	};

	inline void forread(FILE * f, IOFormat & format) {
		// iteration terminal
	};

	template <typename T, typename... Args>
	void forread(FILE * f, const std::string & format, T && x, Args&&... args) {
		IOFormat _format(format);
		_forread_dispatch(f, _format, x);
		forread(f, _format, std::forward<Args>(args)...);
	};

	// free format
	// read free step 2

	inline void _forreadfree_one(FILE * f, int & x) {
		int res = fscanf(f, "%d", &x);

	};
	inline void _forreadfree_one(FILE * f, long long & x) {
		fscanf(f, "%lld", &x);
	};
	inline void _forreadfree_one(FILE * f, double & x) {
		fscanf(f, "%lf", &x);
	};
	inline void _forreadfree_one(FILE * f, long double & x) {
		fscanf(f, "%Lf", &x);
	};
	inline void _forreadfree_one(FILE * f, std::string & x) {
		_str_fscanf(f, "", x);
	};
	inline void _forreadfree_one(FILE * f, bool & x) {
		char bool_str[10];
		fscanf(f, "%s", bool_str);
		if (bool_str[0] == 'T' || bool_str[0] == 't')
		{
			x = true;
		}
		else {
			x = false;
		}
	};
	inline void _forreadfree_one(FILE * f, char * x) {
		fscanf(f, "%s", x);
	};
	//template <typename T>
	//void _forreadfree_one(FILE * f, T & x) {
	//	std::ifstream ifs(f);
	//	ifs >> x;
	//};

	//template <typename T>
	//void _forreadfree_one_arr1(FILE * f, for1array<T> & x) {

	//};
	template <typename T>
	void _forreadfree_one_arrf(FILE * f, farray<T> & x) {
		auto iter = x.begin();
		for (fsize_t i = 0; i < x.flatsize(); i++)
		{
			_forreadfree_one(f, *(iter + i));
		}
	};
	// read free step 1
	//template <typename T>
	//void _forreadfree_dispatch(FILE * f, for1array<T> * x) {
	//	_forreadfree_one_arr1(f, *x);
	//};
	template <typename T>
	void _forreadfree_dispatch(FILE * f, farray<T> * x) {
		_forreadfree_one_arrf(f, *x);
	};
	template <typename T>
	void _forreadfree_dispatch(FILE * f, T * x) {
		_forreadfree_one(f, *x);
	};
	template <typename ... Types>
	void _forreadfree_dispatch(FILE * f, IOStuff<Types...> & iostuff) {
		foreach_tuple(iostuff.tp, [&](auto & x) {
			_forreadfree_dispatch(f, x);
		});
	};
	template <typename T, typename F>
	void _forreadfree_dispatch(FILE * f, ImpliedDo<T, F> & l) {
		while (l.has_next())
		{
			_forreadfree_dispatch(f, l.get_next());
		}
	};
	// read free step 0
	template <typename T, typename... Args>
	void forreadfree(FILE * f, T&& x, Args &&... args) {
		_forreadfree_dispatch(f, x);
		forreadfree(f, std::forward<Args>(args)...);
	};
	template <typename T>
	void forreadfree(FILE * f, T&& x) {
		_forreadfree_dispatch(f, x);
	};

	void forrewind(int unit, foroptional<int> iostat, foroptional<forlabel> err);
	void forbackspace(int unit, foroptional<int> iostat, foroptional<forlabel> err);
	void forrewind(FILE * f, foroptional<int> iostat, foroptional<forlabel> err);
	void forbackspace(FILE * f, foroptional<int> iostat, foroptional<forlabel> err);
}
