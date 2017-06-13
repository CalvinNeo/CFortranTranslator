//#include "../for90std/for90std.h"
//#define USE_FORARRAY
//
//int ff(fsize_t * cur) {
//	return 0;
//};
//int main()
//{
//	//int a = 0, b = 0, c = 0;
//	//test_pack_clvalue(a, b, c);
//	farray<int> aa = forconcat({ make_init_list({1,2,3}) });
//	forprintfree(aa);
//
//	forwrite(stdout, "%d%d%d", make_iolambda({ 1 }, { 2 }, [](fsize_t * current) {
//		return [](int i) {
//			return i + 1;
//		}(current[0]);
//	}));
//	system("pause");
//	return 0;
//}