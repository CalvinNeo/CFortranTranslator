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
	//int a = 1;
	//reference_wrapper<int> w = make_reference_wrapper(a);
	//w.get() = 2;
	//reference_wrapper<int> w2 = std::reference_wrapper<int>(a);
	//w2.get() = 3;

	int a = 0;
	forreadfree(stdin, make_iolambda({ 1 }, { 1 }, [&](const fsize_t * current) {
		return [&](fsize_t i) {
			std::tuple<int*> tt = make_tuple(&a);
			return IOStuff<int*>(tt);
		}(current[0]);
	}));

	//int a = 1;
	//tuple<int&> tu = std::tie(a);
	//tuple<int&> tu2 = tu;
	//std::get<0>(tu2) = 22;
	forprintfree(a);


	system("pause");
	return 0;
}