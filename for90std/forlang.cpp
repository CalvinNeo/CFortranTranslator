#include "forlang.h"

namespace for90std {
	/* string type cast */
	/* using static/inline/extern to avoid repeated definition */ 
	int to_int(std::string x, foroptional<int> kind = foroptional<int>()) {
		int a;
		sscanf(x.c_str(), "%d", &a);
		return a;
	}
	long long to_longlong(std::string x, foroptional<int> kind = foroptional<int>()) {
		long long a;
		sscanf(x.c_str(), "%lld", &a);
		return a;
	}
	double to_double(std::string x, foroptional<int> kind = foroptional<int>()) {
		double a;
		sscanf(x.c_str(), "%lf", &a);
		return a;
	}
	long double to_longdouble(std::string x, foroptional<int> kind = foroptional<int>()) {
		long double a;
		sscanf(x.c_str(), "%LF", &a);
		return a;
	}
}
