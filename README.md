# CFortranTranslator

A translator from Fortran90/Fortran77(ISO/IEC 1539:1991) to C++

Fortran is an efficient tool in scientific calculation. However sometimes translating old fortran codes to C++ will enable more programming abstraction, better GUI framework support, higher performance IDE and easier interaction.

This translator is not intended to improve existing codes, but to make convenience for those who need features of C++ and remain fortran traits and performance as much as possible.

[![Build Status](https://travis-ci.org/CalvinNeo/CFortranTranslator.svg?branch=master)](https://travis-ci.org/CalvinNeo/CFortranTranslator)  [![Coverage Status](https://coveralls.io/repos/github/CalvinNeo/CFortranTranslator/badge.svg?branch=master)](https://coveralls.io/github/CalvinNeo/CFortranTranslator?branch=master)

## Features

1. Convert Fortran90/Fortran77 code to C++14
2. Parse codes mixed with fixed form and free form automaticlly
3. C++ implemetation of some Fortran's type and functions
4. Generated C++ code remains abstract level of the origin code

    e.g. implied-do will not expand to a for-loop directly, but to a `ImpliedDo` struct


## License
The whole project, including both the translator itself and fortran standrad library implementation is distributed under GNU GENERAL PUBLIC LICENSE Version 2

                        GNU GENERAL PUBLIC LICENSE
                           Version 2, June 1991

    Calvin Neo
    Copyright (C) 2016  Calvin Neo

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# Install
## Build project in Windows
### Dependencies
1. MSVC(e.g. Visual Studio 2015)
2. win\_flex(win\_flex\_bison 2.4.5, flex 2.5.37)
3. win\_bison(win\_flex\_bison 2.4.5, bison 2.7)
4. boost(1.60)

### Configure boost
- build boost
```
bjam --toolset=msvc-14.0 address-model=64
```

- configure boost
    1. Add **boost\_dir** directory to additional include library
    2. Add **boost\_dir/libs** and **boost\_dir/stage/lib** to additional library directory

### Configure winflex and winbison
1. On the Project menu, choose Project Dependencies.
2. Select Custom Build Tools
3. Add [/src/grammar/custom\_build\_rules/win\_flex\_bison\_custom\_build.props](/src/grammar/custom\_build\_rules/win\_flex\_bison\_custom\_build.props)

### Build by MSBuild
Run [/build/vcbuild.cmd](/build/vcbuild.cmd)

You can get Visual C++ Build Tools [here(Not available now)](http://landinghub.visualstudio.com/visual-cpp-build-tools) or [here](https://visualstudio.microsoft.com/zh-hans/downloads/)

All built production will be in [/bin](/bin)

### Build by NMake
Run [/build/winmake.cmd](/build/winmake.cmd) to get a x64 Release binary

### Build By Visual Studio
Open [/vsbuild/CFortranTranslator.sln](/vsbuild/CFortranTranslator.sln)

## Build project in Ubuntu
### Dependencies
1. g++(e.g. g++ 5.4.0)
2. bison
3. boost

### Configure boost
Install boost by

	sudo apt-get install libboost-all-dev
### Configure bison
Install bison by

	sudo apt-get install bison
### Make

	cd build && make
	make install

## Fortran standard library(for90std)
**for90std** is a simple implementation of fortran's library and is yet to be done

for90std requires compiler support at least C++14 standard(with several C++17 std functions)

With the following statement to include for90std module

    #include "for90std/for90std.h"

### cpptest
[cpptest](/cpptest) is a C++ project template for you to test for90std.

## Run CFortranTranslator with arguments

    -f file_name : translate file_name into C++
        **Currently, Unicode encoding is not supported**
    -d : use debug mode
    -C : use c-style array
    -F 90/77 : specify Fortran standard, by default the translator accept a mixed Fortran77/90 codes

# Demo
## The "hello world" demo
1. Use the following command to generate target C++ code
    ```
    CFortranTranslator.exe -Ff demos/helloworld.f90 > target.cpp
    ```
2. Build *target.cpp*, modify `#include "../for90std/for90std.h"` to ensure you include the right path of for90std library.
	You can either use [/cpptest/winmake.cmd](/cpptest/winmake.cmd) to build your code, or build them in cpptest project.

## More demos
### Translator Demos
Several demos are provided in [/demos](/demos).
Run [/demos/merge_test.py](/demos/merge_test.py) to generate a `*.form.test` file by merging codes from all `.for`/`.f90` files in a certain folder. Then you can convert the merged Fortran code into C++.

### for90std Demos
Several demos are provided in [/demos/for90std](/demos/for90std).
Make sure you have google-test library before test.

# Debug
Only fatal errors hindering parsing will be reported by translator. 

Debuging origin fortran code or generated C++ code is recommended.

# Docs
see [/docs/brief.md](/docs/brief.md)

## Develop details guide
see [/docs/Develop.md](/docs/Develop.md) to have an general understanding of implementation of this project.
