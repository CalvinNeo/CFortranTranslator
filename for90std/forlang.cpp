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

#include "forlang.h"

namespace for90std {
	/* string type cast */
	/* using static/inline/extern to avoid repeated definition */ 
	foroptional_dummy None;
	int to_int(std::string x, foroptional<int> kind = None) {
		int a;
		sscanf(x.c_str(), "%d", &a);
		return a;
	}
	long long to_longlong(std::string x, foroptional<int> kind = None) {
		long long a;
		sscanf(x.c_str(), "%lld", &a);
		return a;
	}
	double to_double(std::string x, foroptional<int> kind = None) {
		double a;
		sscanf(x.c_str(), "%lf", &a);
		return a;
	}
	long double to_longdouble(std::string x, foroptional<int> kind = None) {
		long double a;
		sscanf(x.c_str(), "%LF", &a);
		return a;
	}
}
