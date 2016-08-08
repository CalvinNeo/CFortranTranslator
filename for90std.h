#pragma once
#include <vector>

template<T>
struct forarray {
	int lb, ub;

	forarray slice(int fr, int to, int step = 1);

	forarray(int l, int u) lb(l), ub(u){}
protected:
	std::vector<T> m_arr;
};