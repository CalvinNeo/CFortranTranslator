#include "../for90std/for90std.h"
#define USE_FORARRAY

void test_open() {
	foropenfile(1, None, None, SS("D:/test.txt"), None, None, None, None, None, None, None, None, None);
	int a = 22222;
	forreadfree(get_file(1), &a);
	forprintfree(a);
}

void test_repeated_open(){
	foropenfile(1, None, None, SS("test.dat"), None, None, None, None, None, None, None, None, None);
	int a = 22222;
	forreadfree(get_file(1), &a);
	forprintfree(a); // 1

	foropenfile(1, None, None, SS("test.dat"), None, None, None, None, None, None, None, None, None);
	forreadfree(get_file(1), &a);
	forprintfree(a); // should be 2

	stop();
}