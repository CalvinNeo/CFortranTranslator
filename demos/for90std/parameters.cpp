#include <gtest/gtest.h>
#include "for90std/for90std.h"
#include <tuple>
#include <fstream>
#include <string>
#include <iostream>
#include <streambuf>

#define TF "t.tmp"


int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    auto r = RUN_ALL_TESTS();
    return r;
}