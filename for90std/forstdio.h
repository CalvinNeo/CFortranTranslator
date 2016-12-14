#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "for1array.h"

//#define eprintf(f, ...) fprintf(stdin, f, __VA_ARGS__)

namespace for90std {
	std::string _forwrite_noargs(FILE * f, std::string format);
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, T x, Args... args) {
		std::string _format = _forwrite_noargs(format);
		size_t e = _format.find_first_of('%', 1);
		fprintf(f, _format.substr(0, e - 1).c_str(), x);
		forwrite(f, _format, forward<Args>(args)...);
	}
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, for1array<T> x, Args... args) {
		std::string _format = _forwrite_noargs(format);
		forwrite(f, _format, forward<Args>(args)...);
	}
	void forprint();
	void forread();
}