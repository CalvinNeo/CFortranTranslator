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
        farray<car> * arr {};
        farray<int> array {{1}, {3}};
        way ca;
        farray<way> var {};
        ca.car->speed;
        arr =&(a);
        arr(INOUT(2)) = ca.car;
        farray<int> a{{1},{3}}
        a

        return 0;
}