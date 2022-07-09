#include "../for90std/for90std.h"
#define USE_FORARRAY
struct car
{
        double speed = 0.0;

};

struct way
{
        car * car;

};

int main()
{
        farray<car> a {{1}, {3}};
        farray<car> (* arr){};

        arr =&(a);
        a(INOUT(1)).speed = 5.0;
        (*arr)(INOUT(2)) = a(INOUT(1));

        printf("%f", (*arr)(INOUT(2)).speed);

        return 0;
}
