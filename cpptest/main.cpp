#include "../for90std.h"

double ss(const double & r, const foroptional<double> & h)
{
	double ss_result;
	double temp_h;
	if ((forpresent(h))) {
		temp_h = h;
	}
	else {
		temp_h = 1.0;
	}
	ss_result = 3.1415926 * power(r, 2) * temp_h;
	return ss_result;
}
int main()
{
	printf(" %s%10.3f", "vol=", ss(2.5, 9));
	return 0;
}