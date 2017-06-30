#include "../for90std/for90std.h"
#define USE_FORARRAY

void test_iostuff() {	
	IOStuff<double, string, int> tup(std::make_tuple(1.0, "xxxx", 2));
	forwritefree(stdout, tup);
	farray<int> arr({ 1 }, { 3 });
	arr = make_init_list({ 1,2,3 });
	forwritefree(stdout, arr);
	forreadfree(stdin, tup);
	forwritefree(stdout, tup);
}

void test_iolambda(){
	auto iol = make_iolambda({ 1, 1 }, { 3, 3 }, [](fsize_t * i) {
		return i[0] + i[1];
	});
	int x;
	while(iol.get_next(x)){
		cout << x << endl;
	}
	
	forwrite(stdout, "%d%d%d", make_iolambda({ 1 }, { 2 }, [](fsize_t * current) {
		return [](int i) {
			return i + 1;
		}(current[0]);
	}));
}

void test_combined(){
	//auto f = [&](const fsize_t * current) {
	//	const IOStuff<int, int> & iost = [&](fsize_t j) {
	//		return make_iostuff(make_tuple(j + 1, j + 2));
	//	}(current[0]);
	//	return iost;
	//};
	//const IOStuff<int, int> * ptr = nullptr;
	//auto newf = [&](fsize_t * _) {
	//	const IOStuff<int, int> & ans = f(_);
	//	ptr = &ans;
	//};
	//int index[] = { 0, 0 };
	//auto ans = f(index);
	//newf(index);
	//auto ans = *ptr; // error
	//const IOStuff<int, int> & ans = *ptr;
	//foreach_tuple(ans.tp, [&](auto x) {
	//	cout << x << endl;;
	//});
	const IOStuff<int, int> * ptr = nullptr;
	auto newf = [&](fsize_t * _) {
		const IOStuff<int, int> & ans = make_iostuff(make_tuple(1 + 1, 1 + 2));
		// WARNING: do not get pointer of expiring value
		ptr = &ans;
	};
	int index[] = { 0, 0 };
	//auto ans = f(index);
	newf(index);
	//auto ans = *ptr; // error
	const IOStuff<int, int> & ans = *ptr;
	foreach_tuple(ans.tp, [&](auto x) {
		cout << x << endl;;
	});
}