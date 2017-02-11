# CFortranTranslator
A translator from Fortran90/Fortran77(ISO/IEC 1539:1991) to C++

Fortran is an efficient tool in scientific calculation. However sometimes translating old fortran codes to c++ will enable more programming abstraction, better GUI framework support, higher performance IDE and easier interaction.

This translator is not intended to improve existing codes, but to make convenience for those who need features of c++ and remain fortran traits as much as possible.

## License
Boththe translator itself and fortran standrad library implementation is distributed under GNU GENERAL PUBLIC LICENSE Version 2

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

# Usage
## Install
My Configuration:

- translator
    1. vs2015(Update 3) 
    2. win_flex(win_flex_bison 2.4.5, flex 2.5.37)
    3. win_bison(win_flex_bison 2.4.5, bison 2.7)
    4. boost(1.60)

- fortran standard library
    1. C++14 standard

## Debug
Only fatal errors hinderring parsing will be reported by translator. 

Debug origin fortran code or generated c++ code is recommended.

## Demo
demos provided in [demos](/demos)

## fortran standard library
include [for90std/for90std.h](/for90std/for90std.h) to use c++ implementation of intrinsic fortran functions and language features

### inherit function mapping
#### type and type cast function
|fortran|c++|
|:-:|:-:|
|INTEGER()|to_int|
|REAL()|to_double|
|LOGICAL()|to_bool|
|COMPLEX()|to_forcomplex|
|CHARACTER()|to_string|

#### mathematical
|fortran|c++|
|:-:|:-:|
|min|min_n|
|max|max_n|

#### array
refer types:array

### IO function mapping
#### device id mapping

|fortran|c++|
|:-:|:-:|
|*|stdin/stdout|
|5|stdin|
|6|stdout|
|id|get_file(id)|

#### file function mapping

|fortran|c++|
|:-:|:-:|
|open|foropenfile|
|close|forclosefile|

#### print formatter mapping

|fortran|c++|
|:-:|:-:|
|`*` and `(*,*)`|forscanfree/forprintfree|
|`(*,formatter)`|forscan/forprint|
|`(device_id,*)`|forreadfree/forwritefree|
|`(device_id,formatter)`|forread/forwrite|

## translation results and restrictions
refer to [/grammar/for90.y](/grammar/for90.y) for all accepted grammar
### grammar

1. you can rename keyword parameter in `interface` block
2. you can use anonymous grammar structures
3. variable definitions and interfaces is not forced before any other statements
    1. you can initialize array immediately like `integer,dimension(3)::A = (/1, 2, 3/)`, in gfortran you must assign initial value after all variables/arrays are defined

### types
#### type mapping

|fortran|c++|
|:-:|:-:|
|INTEGER(all length)|`int`|
|REAL(all length)|`double`|
|LOGICAL|`bool`|
|COMPLEX|`struct forcomplex`|
|CHARACTER|`std::string`|
|array|`farray<T>`|

### array
#### fortran-style array and c-style array

1. fortran store array in a **column-first order**
    - for a 2d array, it means when initializing a 1d array by sequence, it follows the order of `a(1)(1) -> a(2)(1) -> a(1)(2) -> a(1)(2)` 
    - similarly, for a nd array, rank 1 increase by 1 first, when rank 1 equals to upper bound it wrap back and rank 2 increase by 1..., rank n increase the last.
    - for details refer to `array_builder` rule in [/grammar/for90.y](/grammar/for90.y)
2. fortran array default lower bound for each rank is **1**, and it can be negative; each dimension of c++ style array has constant lower bound 0
3. fortran array **rank** start from 1, c++ array **dimension** start from 0, parameter for most `for-` functions are index of rank, though they are called "dim" in standard, they are called `fordim` in this implementation
4. `#define USE_FORARRAY` to use fortran style array, `#define USE_CARRAY` to use c style array
5. `farray` set no limit to rank, in fortran90, the maximun rank is 7

#### slice
`struct slice_info<T>` implement for a slice in fortran

1. `slice_info<T>{T x}`: stands for the scalar `x`, `x` is an index not a range
2. `slice_info<T>{T x, T y}`: `x`, `y` stands for a range of **[x, y]** of default step 1
3. `slice_info<T>{T x, T y, T z}`: `x`, `y`, `z` stands for a range of **[x, y]** step `z`

#### farray
`farray` is a multi-dimentional valarray

**DON'T** call member function of `farray` directly

1. define an array
2. init a array
    - from fortran list-initialization: `farray<T>(lower_bound, size, values)`
    - from hidden `do`-loop: `farray<T>(lower_bound, size, hidden_do_func)`
3. array traits

|function|usage|
|:-:|:-:|
|`.flatsize()`|get flatterned size|
|`forconcat(x, y)`|concat array x and y|

4. fortran intrinsic functions

|fortran|c++| |
|:-:|:-:|:-:|
|get|`a(1, 2, 3, 4)` or `a({1, 2, 3, 4})` or `a[{1, 2, 3, 4}]` or `forslice(a, {1, 2, 3, 4})`| |
|forslice|`a[{{1, 3, 1}, {1, 4}, {5}, {}}]` or `forslice(a, {{1, 3, 1}, {1, 4}, {5}}, {})`| |
|reshape|forreshape| |
|spread|not implemented yet| |
|transpose|fortranspose| fortran standard only defined rank 2 situation, for this implementation, the result will be a array with reversed rank |
|maxloc, minloc, maxval, minval|formaxloc, forminloc, formaxval, formaxloc| |
|sum, product|forsum, forproduct| call `operator+` and `operator*` |
|any, all, count|forany, forall, forcount| `forall` is **NOT** fortran95's `forall` |
|pack, unpack|not implemented yet| |
|merge|formerge| |
|size, lbound, ubound|forsize, forlbound, forubound| |
|matmul, dot_product|not implemented yet| |
|eoshift, cshift|not implemented yet| |

#### for1array
`for1array` is a 1-dimentional dynamic array

1. initialize an array
    ways to initialize an for1array
    - with `f1a_init(array, lower_bound, size, values)` to init `array`, in which
        1. `array` is reference of a defined array you want to init
        2. `lower_bound` is the lower bound of every dimension(from left to right) in this array
        3. `size` is the size of every dimension in this array
        4. `values` is `std::vector` of initialize list
    - with `f1a_gen` and return a copy directly
    - with constructor `for1array(lower_bound, size, values)`
    - with `f1a_init_hiddendo` in [/for90std/for1array.h](/for90std/for1array.h) to init array by hidden do

2. array traits

|function|usage|
|:-:|:-:|
|`f1a_flattern(array)`|get flatterned size of an array|
|`f1a_gettype<T>::type`|get innermost type of an array|
|`f1a_flatmap(array, begin_iterator, end_iterator, lambda)`|return a vector of all elements mapped by function `lambda` in fortran/c order|

### variables
1. all variables must be **explicitly** declared
2. since variable names in fortran is **case-insensitive**, all variables will be in lower case in generated cpp code

### functions and subroutines
1. remove all definition of local variables which is also in parameter list
2. replace all interface with forward declaration when necessary
3. value pass strategy:

|intent|parameter|result|
|:-:|:-:|:-:|
|/|/|T|
|/|parameter|const T|
|in|ignore|const T &|
|out|ignore|T &|
|inout|ignore|T &|

4. optional parameter: instead of c-style optional parameter, wrap optional parameters with `foroptional<T>`, function `forpresent` functions as `present` function in fortran90
5. keyword/named parameter: c++ don't support keyword parameters, all keyword parameter will be reorganized in normal paramtable

# Develop
refer to [/Develop.md](/Develop.md)