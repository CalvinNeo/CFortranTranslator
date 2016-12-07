#include "forlang.h"

/* general type cast */
template<typename T>
int to_int(T x) {
	return (int)x;
}
template<typename T>
long long to_longlong(T x) {
	return (long long)x;
}
template<typename T>
long double to_longdouble(T x) {
	return (long double)x;
}
template<typename T>
double to_double(T x) {
	return (double)x;
}
/* string type cast */
template<>
int to_int(std::string x) {
	int a;
	sscanf(x.c_str(), "%d", &a);
	return a;
}
template<>
long long to_longlong(std::string x) {
	long long a;
	sscanf(x.c_str(), "%lld", &a);
	return a;
}
template<>
double to_double(std::string x) {
	double a;
	sscanf(x.c_str(), "%f", &a);
	return a;
}
template<>
long double to_longdouble(std::string x) {
	long double a;
	sscanf(x.c_str(), "%LF", &a);
	return a;
}
