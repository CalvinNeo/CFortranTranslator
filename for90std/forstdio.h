#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "for1array.h"
#include <complex>

//#define eprintf(f, ...) fprintf(stdin, f, __VA_ARGS__)

namespace for90std {
	inline std::string _forwrite_noargs(FILE * f, std::string format) {
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
	void _do_fprintf(FILE * f, std::string _format, T x) {
		fprintf(f, _format.c_str(), x);
	}
	inline void _do_fprintf(FILE * f, std::string _format, std::string x) {
		fprintf(f, _format.c_str(), x.c_str());
	}

	template <typename T>
	std::string _forwrite_one(FILE * f, std::string format, T x) {
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
	std::string _forwrite_one_arr(FILE * f, std::string format, T x) {
		// clear front
		std::string _format = _forwrite_noargs(f, format);
		typedef typename for1array_gettype<T>::type _InnerT;
		std::vector<_InnerT> vec = for1array_flattern(x);
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
	void _forwrite_one_arr_noform(FILE * f, T x) {
		typedef typename for1array_gettype<T>::type _InnerT;
		std::vector<_InnerT> vec = for1array_flattern(x);
		for (auto i = 0; i < vec.size(); i++)
		{
			_forwrite_one_noform(f, vec[i]);
		}
	};

	inline void _forwrite_one_noform(FILE * f, int x) {
		fprintf(f, "%d ", x);
	};
	inline void _forwrite_one_noform(FILE * f, long long x) {
		fprintf(f, "%lld ", x);
	};
	inline void _forwrite_one_noform(FILE * f, double x) {
		fprintf(f, "%lf ", x);
	};
	inline void _forwrite_one_noform(FILE * f, long double x) {
		fprintf(f, "%Lf ", x);
	};
	inline void _forwrite_one_noform(FILE * f, std::string x) {
		fprintf(f, "%s ", x.c_str());
	};
	inline void _forwrite_one_noform(FILE * f, bool x) {
		fprintf(f, "%s ", x ? "true" : "false");
	};
	template <typename T>
	void _forwrite_one_noform(FILE * f, T x) {
		// fprintf(f, "%g ", x);
	};
	
	// format
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, T x, Args... args) {
		format = _forwrite_one(f, format, x);
		forwrite(f, format, forward<Args>(args)...);
	};
	template <typename T>
	void forwrite(FILE * f, std::string format, T x) {
		if (is_for1array::test<T>(nullptr)) {
			format = _forwrite_one_arr(f, format, x);
		}
		else {
			format = _forwrite_one(f, format, x);
		}
		// clear end
		_forwrite_noargs(f, format);
	};
	// no format
	template <typename T, typename... Args>
	void forwrite_noform(FILE * f, T x, Args... args) {
		_forwrite_one_noform(f, x);
		forwrite_noform(f, forward<Args>(args)...);
	};
	template <typename T>
	void forwrite_noform(FILE * f, T x) {
		if (is_for1array::test<T>(nullptr)) {
			_forwrite_one_arr_noform(f, x);
		}
		else {
			_forwrite_one_noform(f, x);
		}
	};

	template <typename T, typename... Args>
	void forprint_noform(T x, Args... args) {
		// no format
		forwrite_noform(stdout, x, forward<Args>(args)...);
	};
	template <typename T>
	void forprint_noform(T x) {
		forwrite_noform(stdout, x);
	};
	template <typename T, typename... Args>
	void forprint(std::string format, T x, Args... args) {
		// format
		forwrite(stdout, format, x, forward<Args>(args)...);
	};
	template <typename T>
	void forprint(std::string format, T x) {
		forwrite(stdout, format, x);
	};




	void forread();
}