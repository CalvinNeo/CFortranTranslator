#include "../for90std/for90std.h"
#define USE_FORARRAY


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