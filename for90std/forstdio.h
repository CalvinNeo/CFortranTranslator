#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include "for1array.h"

//#define eprintf(f, ...) fprintf(stdin, f, __VA_ARGS__)

namespace for90std {
	std::string _forwrite_noargs(FILE * f, std::string format);
	template <typename T, typename... Args>
	void forwrite(FILE * f, std::string format, T x, Args... args) {
		forwrite(f, _forwrite_noargs(format), forward<Args>(args)...);
	}
	template <typename T, typename... Args>
	void forwrite(std::string format, for1array<T> x, Args... args) {
		forwrite(f, _forwrite_noargs(format), forward<Args>(args)...);
	}
	void forprint();
	void forread();
}