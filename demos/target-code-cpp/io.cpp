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
	
	forwrite(stdout, "%d", make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current) {
		return [&](fsize_t j) {
			return make_iostuff(make_tuple(j + 1, j + 2));
		}(current[0]);
	}));
}

void test_iolambda_ex(){
	farray<double> a{ { 1 },{ 2 } };
	farray<double> b{ { 1, 1 },{ 2, 2 } };

	a(1) = 1;
	a(2) = 2;
	b(1, 1) = 4; b(1, 2) = 5;
	b(2, 1) = 6; b(2, 2) = 7;
	// generated 1d write
	forwritefree(stdout, make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_i) {
		return [&](fsize_t i) {
			return make_iostuff(make_tuple(make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_j) {
				return [&](fsize_t j) {
					return b(FW(j), FW(j));
				}(current_j[0]);
			}), "\n"));
		}(current_i[0]);
	}));
	
	// generated 2d write
	forwritefree(stdout, make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_i) {
		return [&](fsize_t i) {
			return make_iostuff(make_tuple(a(FW(i)), make_iolambda({ i, 1 }, { i, 2 }, [&](const fsize_t * current_j) {
				return [&](fsize_t i, fsize_t j) {
					return b(FW(i), FW(j));
				}(current_j[0], current_j[1]);
			})));
		}(current_i[0]);
	}));

	// read 
	// parted
	auto xx = make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_j) {
		return [&](fsize_t j) {
			printf("=====b(%d,%d)\n", j, j);
			return &b(FW(j), FW(j));
		}(current_j[0]);
	});
	auto yy = make_iostuff(make_tuple(xx));
	auto zz = make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_i) {
		return [&](fsize_t i) {
			return yy;
		}(current_i[0]);
	});
	forreadfree(stdin, zz);

	// generated 2d read
	forreadfree(stdin, make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current_i) {
		return [&](fsize_t i) {
			return make_iostuff(make_tuple(&a(FW(i)), make_iolambda({ i, 1 }, { i, 2 }, [&](const fsize_t * current_j) {
				return [&](fsize_t i, fsize_t j) {
					return &b(FW(i), FW(j));
				}(current_j[0], current_j[1]);
			})));
		}(current_i[0]);
	}));
	
	// test _map_impl_next
	forwritefree(stdout, make_iolambda({ 1 }, { 10 }, [&](const fsize_t * current_i) {
		return [&](fsize_t i) {
			printf("---------%d \n", i);
			return 0;
		}(current_i[0]);
	}));
	forwritefree(stdout, make_iolambda({ 1, 1 }, { 1, 2 }, [&](const fsize_t * current_i) {
			return [&](fsize_t i, fsize_t j) {
				printf("---------%d %d\n", i, j);
				return 0;
			}(current_i[0], current_i[1]);
	}));
}

void test_ioformat(){
	int a , b, c;
	forreadfree(stdin, a, b, c);
	forread(stdin, IOFormat("%d"), a, b, c);
	a = 21; b = 22; c = 23;
	forprintfree(a, b, c);
}

void rewind_backspace(){
	/***************
	*  file content
	*===============
		1
		2
		3
	****************/
	foropenfile(1, None, None, SS("D:/11.txt"), SS("unkonwn"), SS("sequential"), None, None, None, SS("rewind"), SS("readwrite"), None, None);
	int x;
	forreadfree(get_file(1), x);
	forprintfree(x); // 1
	forreadfree(get_file(1), x);
	forprintfree(x); // 2 
	forrewind(get_file(1), None, None);
	forreadfree(get_file(1), x);
	forprintfree(x); // 1


	forbackspace(get_file(1), None, None);
	forreadfree(get_file(1), x);
	forprintfree(x);  // 1
	stop();
}

void test_read_string() {
	string rr = "";
	forread(get_file(5), IOFormat{ "%80s\n", 0 }, &rr);
	forprintfree(rr);
	stop();
}

void test_error(){
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
	
	//const IOStuff<int, int> * ptr = nullptr;
	//auto newf = [&](fsize_t * _) {
	//	const IOStuff<int, int> & ans = make_iostuff(make_tuple(1 + 1, 1 + 2));
		// WARNING: do not get pointer of expiring value
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
	
	//const auto stuff = make_iostuff(make_tuple(1, 2));
	//foreach_tuple(stuff.tp, [&](auto x) {
	//	cout << x + 1 << endl;;
	//});
	
		//int a = 1;
	//tuple<int&> tu = std::tie(a);
	//tuple<int&> tu2 = tu;
	//std::get<0>(tu2) = 22;
}