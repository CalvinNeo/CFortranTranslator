#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "for1array.h"
#include "farray.h"
#include <complex>

//#define eprintf(f, ...) fprintf(stdin, f, __VA_ARGS__)

namespace for90std {
	inline std::string _forwrite_noargs(FILE * f, const std::string & format) {
		for (size_t i = 0; i < format.size(); i++)
		{
			switch (format[i])
			{
			case '\\':
				if (i + 1 < format.size()) {
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
	void _do_fprintf(FILE * f, std::string _format, const T & x) {
		fprintf(f, _format.c_str(), x);
	}
	inline void _do_fprintf(FILE * f, std::string _format, const std::string & x) {
		fprintf(f, _format.c_str(), x.c_str());
	}

	
	// format
	template <typename T>
	std::string _forwrite_one(FILE * f, std::string format, const T & x) {
		// clear front
		std::string _format = _forwrite_noargs(f, format);
		if (_format != "") {
			// now start from '%' or _format is empty string
			size_t e = _format.find_first_of('%', 1);
			if (e == std::string::npos) {
				// the last formatter
				_do_fprintf(f, _format, x);
				return "";
			}
			else {
				_do_fprintf(f, _format.substr(0, e), x);
				return _format.substr(e);
			}
		}
		else {
			_do_fprintf(f, _format, x);
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
		for (auto i = 0; i < x.flatsize(); i++)
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
	template <typename T>
	std::string _forwrite(FILE * f, std::string format, const for1array<T> & x) {
		return _forwrite_one_arr1(f, format, x);
	};
	template <typename T>
	std::string _forwrite(FILE * f, std::string format, const farray<T> & x) {
		return _forwrite_one_arrf(f, format, x);
	};
	template <typename T>
	std::string _forwrite(FILE * f, std::string format, const T & x) {
		return _forwrite_one(f, format, x);
	};
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, const T & x, Args... args) {
		format = _forwrite(f, format, x);
		forwrite(f, format, forward<Args>(args)...);
	};
	inline void forwrite(FILE * f, std::string format) {
		// clear end
		_forwrite_noargs(f, format);
	};

	// free format
	
	inline void _forwritefree_one(FILE * f, int x) {
		fprintf(f, "%d ", x);
	};
	inline void _forwritefree_one(FILE * f, long long x) {
		fprintf(f, "%lld ", x);
	};
	inline void _forwritefree_one(FILE * f, double x) {
		fprintf(f, "%lf ", x);
	};
	inline void _forwritefree_one(FILE * f, long double x) {
		fprintf(f, "%Lf ", x);
	};
	inline void _forwritefree_one(FILE * f, std::string x) {
		fprintf(f, "%s ", x.c_str());
	};
	inline void _forwritefree_one(FILE * f, bool x) {
		fprintf(f, "%s ", x ? "true" : "false");
	};
	inline void _forwritefree_one(FILE * f, const char * x) {
		fprintf(f, "%s ", x);
	};
	template <typename T>
	void _forwritefree_one(FILE * f, T x) {
		fprintf(f, "[object %s] %p ", typeid(T).name(), &x);
	};
	template <typename T>
	void _forwritefree_one_arr1(FILE * f, const for1array<T> &  x) {
		typedef typename f1a_gettype<T>::type _InnerT;
		std::vector<_InnerT> vec = f1a_flatterned(x);
		for (auto i = 0; i < vec.size(); i++)
		{
			_forwritefree_one(f, vec[i]);
		}
	};
	template <typename T>
	void _forwritefree_one_arrf(FILE * f, const farray<T> & x) {
		auto iter = x.cbegin();
		for (auto i = 0; i < x.flatsize(); i++)
		{
			_forwritefree_one(f, *(iter + i));
		}
		fprintf(f, "\n");
	};
	template <typename T>
	void _forwritefree(FILE * f, const for1array<T> & x) {
		_forwritefree_one_arr1(f, x);
	};
	template <typename T>
	void _forwritefree(FILE * f, const farray<T> & x) {
		_forwritefree_one_arrf(f, x);
	};
	template <typename T>
	void _forwritefree(FILE * f, const T & x) {
		_forwritefree_one(f, x);
	};

	template <typename T, typename... Args>
	void forwritefree(FILE * f, const T & x, Args... args) {
		_forwritefree(f, x);
		forwritefree(f, forward<Args>(args)...);
	};
	template <typename T>
	void forwritefree(FILE * f, const T & x) {
		_forwritefree(f, x);
	};

	template <typename T, typename... Args>
	void forprintfree(const T & x, Args... args) {
		// no format
		forwritefree(stdout, x, forward<Args>(args)...);
	};
	template <typename T>
	void forprintfree(const T & x) {
		forwritefree(stdout, x);
	};
	template <typename T, typename... Args>
	void forprint(std::string format, const T & x, Args... args) {
		// format
		forwrite(stdout, format, x, forward<Args>(args)...);
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
	void _do_fscanf(FILE * f, std::string _format, T & x) {
		fscanf(f, _format.c_str(), &x);
	}
	inline void _do_fscanf(FILE * f, std::string _format, std::string & x) {
		std::cin >> x;
	}
	// format
	template <typename T>
	void _forread_one(FILE * f, std::string format, T & x) {
		// clear front
		std::string _format = _forread_noargs(f, format);
		if (_format != "") {
			// now start from '%' or _format is empty string
			size_t e = _format.find_first_of('%', 1);
			if (e == std::string::npos) {
				// the last formatter
				_do_fscanf(f, _format, x);
				return "";
			}
			else {
				_do_fscanf(f, _format.substr(0, e), x);
				return _format.substr(e);
			}
		}
		else {
			_do_fscanf(f, _format, x);
			return "";
		}
	};
	template <typename T>
	void _forread_one_arr1(FILE * f, std::string format, for1array<T> & x) {

	};
	template <typename T>
	void _forread_one_arrf(FILE * f, std::string format, farray<T> & x) {

	};
	template <typename T>
	std::string _forread(FILE * f, std::string format, for1array<T> & x) {
		return _forread_one_arr1(f, format, x);
	};
	template <typename T>
	std::string _forread(FILE * f, std::string format, farray<T> & x) {
		return _forread_one_arrf(f, format, x);
	};
	template <typename T>
	std::string _forread(FILE * f, std::string format, T & x) {
		return _forread_one(f, format, x);
	};
	template <typename T, typename... Args>
	void forread(FILE * f, std::string format, T & x, Args... args) {
		format = _forread(f, format, x);
		forread(f, format, forward<Args>(args)...);
	};
	template <typename T>
	void forread(FILE * f, std::string format, T & x) {
		format = _forread(f, format, x);
	};

	// free format
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
		for (auto i = 0; i < x.flatsize(); i++)
		{
			_forreadfree_one(f, *(iter + i));
		}
	};
	template <typename T>
	void _forreadfree(FILE * f, for1array<T> & x) {
		_forreadfree_one_arr1(f, x);
	};
	template <typename T>
	void _forreadfree(FILE * f, farray<T> & x) {
		_forreadfree_one_arrf(f, x);
	};
	template <typename T>
	void _forreadfree(FILE * f, T & x) {
		_forreadfree_one(f, x);
	};
	template <typename T, typename... Args>
	void forreadfree(FILE * f, T & x, Args... args) {
		_forreadfree(f, x);
		forreadfree(f, forward<Args>(args)...);
	};
	template <typename T>
	void forreadfree(FILE * f, T & x) {
		_forreadfree(f, x);
	};
}