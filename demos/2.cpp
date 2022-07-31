#include "../for90std/for90std.h"
#define USE_FORARRAY
namespace ma {
    int a;
    auto show_int = [](int n){
        forwrite(stdout, IOFormat{"n=%3d\n", 0}, n);
        return ;
    };

}