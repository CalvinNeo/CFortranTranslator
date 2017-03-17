//#include "../for90std/for90std.h"
//#define USE_FORARRAY
//
//int main()
//{
//	farray<int > a{ { 1, 1 },{ 2, 3 },{ -14,3,0,-2,19,1 } };
//	forprintfree(formaxloc(a), "\n"); // 2 1 1
//	forprintfree(formaxloc(a, 1), "\n"); // 2 1 1
//	forprintfree(formaxloc(a, 2), "\n"); // 3 1
//	forprintfree(formaxval(a, 1), "\n"); // 3 0 19
//	forprintfree(formaxval(a, 1, a > 1), "\n"); // 3 -2147483647(-HUGE) 19
//	forprintfree(formaxval(a, 2), "\n"); // 19 3
//	forprintfree(formaxval(a), "\n"); // 19
//	forprintfree(a < 3);
//	forprintfree(a > 1);
//	forprintfree(a == 3);
//	forprintfree(a != 1);
//	forprintfree(a + 1);
//	forprintfree(a - 2);
//	forprintfree(a * 6);
//	forprintfree(a / 5);
//	forprintfree(!a);
//	forprintfree(!!a);
//
//	farray<int > b{ { 1, 1 },{ 2, 2 },{ 1,2,3,4 } };
//	forprintfree("--------------\n");
//	//forprintfree(forsum(b, 2));
//	//forprintfree(forproduct(b, 2));
//	//forprintfree(forall(b < 2));
//	forprintfree(forslice(b, { { }, { 1 } }));
//	forprintfree(forslice(b, { { }, { 2,2 } }));
//	forprintfree(forslice(b, { { 1,1 },{  } }));
//	forprintfree(forslice(b, { { 2 },{} }));
//	//forprintfree(forall(b < 3, 1));
//	//forprintfree(forproduct(b, 2));
//	system("pause");
//	return 0;
//}

#include "../for90std/for90std.h"
#define USE_FORARRAY
int sum(const int & x, const int & y)
{
	int sum_result;
	sum_result = x + y;
	return sum_result;
}

int minu(const int & x, const int & y)
{
	int minu_result;
	minu_result = x - y;
	return minu_result;
}

void proc(const int & a, const int & b, std::function<int(const int & x, const int & y)> fun)
{
	forprintfree(fun(a, b), "\n");
	return;
}

template <typename T, typename ... Args>
void test_pack_lvalue(T & x, Args ... args) {
	x = 1;
	test_pack(forward<Args>(args)...);
}
template <typename T, typename ... Args>
void test_pack_lvalue(T & x) {
	x = 1;
}
template <typename T, typename ... Args>
void test_pack_clvalue(const T & x, Args ... args) {

	test_pack_clvalue(forward<Args>(args)...);
}
template <typename T, typename ... Args>
void test_pack_clvalue(const T & x) {

}

int main()
{
	//int a = 0, b = 0, c = 0;
	//test_pack_clvalue(a, b, c);
	farray<int> aa = forconcat({ make_init_list({1,2,3}) });
	//int a;
	//int b;
	//forreadfree(get_file(-1), a, b);
	//proc(a, b, sum);
	//proc(a, b, minu);
	system("pause");
	return 0;
}