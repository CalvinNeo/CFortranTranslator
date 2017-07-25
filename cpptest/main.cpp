#include "../for90std/for90std.h"
#include "windows.h"
#define USE_FORARRAY

struct Cls {
	~Cls() {
		puts("end");
	}
};

void sub(int && c) {

}


int main() {
	return 0;
}