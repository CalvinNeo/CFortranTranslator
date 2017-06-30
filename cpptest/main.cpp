#include "../for90std/for90std.h"
#define USE_FORARRAY

int main() {
	forwritefree(stdout, make_iolambda({ 1 }, { 2 }, [&](const fsize_t * current) {
		return [&](fsize_t j) {
			return make_iostuff(make_tuple(j + 1, j + 2));
		}(current[0]);
	}));


	//const auto stuff = make_iostuff(make_tuple(1, 2));
	//foreach_tuple(stuff.tp, [&](auto x) {
	//	cout << x + 1 << endl;;
	//});

	system("pause");
	return 0;
}