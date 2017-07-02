#include "../for90std/for90std.h"
#define USE_FORARRAY


void tets_open(){
	foropenfile(1, None, None, "test.txt", None, None, None, None, None, None, None, None, None);
	int a = 22222;
	forreadfree(get_file(1), a);
	forprintfree(a);
}