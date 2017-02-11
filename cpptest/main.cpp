#include "../for90std/for90std.h"
#define USE_FORARRAY

int main()
{
	farray<int > a{ { 1, 1 },{ 2, 3 },{ -14,3,0,-2,19,1 } };
	forprintfree(formaxloc(a), "\n"); // 2 1 1
	forprintfree(formaxloc(a, 1), "\n"); // 2 1 1
	forprintfree(formaxloc(a, 2), "\n"); // 3 1
	forprintfree(formaxval(a, 1), "\n"); // 3 0 19
	forprintfree(formaxval(a, 1, a > 1), "\n"); // 3 -2147483647(-HUGE) 19
	forprintfree(formaxval(a, 2), "\n"); // 19 3
	forprintfree(formaxval(a), "\n"); // 19
	forprintfree(a < 3);
	forprintfree(a > 1);
	forprintfree(a == 3);
	forprintfree(a != 1);
	forprintfree(a + 1);
	forprintfree(a - 2);
	forprintfree(a * 6);
	forprintfree(a / 5);
	forprintfree(!a);
	forprintfree(!!a);

	farray<int > b{ { 1, 1 },{ 2, 2 },{ 1,2,3,4 } };
	forprintfree("--------------\n");
	//forprintfree(forsum(b, 2));
	//forprintfree(forproduct(b, 2));
	//forprintfree(forall(b < 2));
	forprintfree(forslice(b, { { }, { 1 } }));
	forprintfree(forslice(b, { { }, { 2,2 } }));
	forprintfree(forslice(b, { { 1,1 },{  } }));
	forprintfree(forslice(b, { { 2 },{} }));
	//forprintfree(forall(b < 3, 1));
	//forprintfree(forproduct(b, 2));
	system("pause");
	return 0;
}