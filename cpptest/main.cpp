#include "../for90std/for90std.h"
#define USE_FORARRAY

struct Cls {
	~Cls() {
		puts("end");
	}
};

void sub(int && c) {

}


int main() {

	farray<double> ds{ { 1 },{ 8 } };
	double a = 0.0;
	printf("%8.1f", 0.0000 / a);
	system("pause");
	return 0;
}