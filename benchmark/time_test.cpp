#include "../for90std/for90std.h"
#include <ctime>

#define USE_FORARRAY
int main()
{
	farray<int> m{ { 1, 1 },{ 5, 5 } };

	time_t pretime;
	pretime = time(NULL);
	for (int i = 0; i < 1000; i++) {
		m.reset_array({ { 1, 5 }, { 1, 5 } });
		m(2, 4) = i;
	}
	printf("elased: %lld\n", time(NULL) - pretime);
	stop();
	return 0;
}