#include "../for90std/for90std.h"
#define USE_FORARRAY
struct car
{
        double speed = 0.0;

};

struct carteam
{
        farray<car> * cars ;

};

int main()
{
        double cars = 0.0;
        farray<car> ccc {{1}, {3}};
        farray<carteam> var {{1}, {5}};
        var(INOUT(3)).cars =&(ccc);
        ccc(INOUT(1)).speed = 7.0;
        //forwritefree(stdout, (* (var(INOUT(3)).cars))(INOUT(1)).speed);
        forwritefree(stdout, var(INOUT(3)).(*cars)(INOUT(1)).speed);
        return 0;
}
