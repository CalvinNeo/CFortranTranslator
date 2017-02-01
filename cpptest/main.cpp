#include "../for90std/for90std.h"
#define USE_FORARRAY

int main()
{
	farray<int > a{ { 1, 1 },{ 2, 3 },{ -14,3,0,-2,19,1 } };
	forprintfree(formaxloc(a, 1), "\n"); // 2 1 1
	forprintfree(formaxloc(a, 2), "\n"); // 3 1
	forprintfree(formaxval(a, 1), "\n"); // 3 0 19
	forprintfree(formaxval(a, 2), "\n"); // 19 3
	forprintfree(formaxval(a), "\n"); // 19
	system("pause");
	return 0;
}