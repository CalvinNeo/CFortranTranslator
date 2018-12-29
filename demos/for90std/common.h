#pragma once
#include <gtest/gtest.h>
#include "for90std/for90std.h"
#include <tuple>
#include <fstream>
#include <string>
#include <iostream>
#include <streambuf>

#define TF "t.tmp"

std::string & replace_all(std::string & s, const std::string & old_value, const std::string & new_value)
{
    while (true)
    {
        size_t pos = 0;
        if ((pos = s.find(old_value, 0)) != std::string::npos)
            s.replace(pos, old_value.length(), new_value);
        else break;
    }
    return s;
}

std::string RF(){
    std::ifstream t(TF);
    std::string s((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    replace_all(s, "\t", " ");
    replace_all(s, "\n\n", "\n");
    return s;
}
