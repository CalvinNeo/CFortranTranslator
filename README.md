# CFortranTranslator

A translator from Fortran90/Fortran77(ISO/IEC 1539:1991) to C++

Fortran is an efficient tool in scientific calculation. However sometimes translating old fortran codes to C++ will enable more programming abstraction, better GUI framework support, higher performance IDE and easier interaction.

This translator is not intended to improve existing codes, but to make convenience for those who need features of C++ and remain fortran traits as much as possible.

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

# Usage
## Install
### Build Translator
My Configuration:

- translator
    1. vs2015(Update 3) 
    2. win\_flex(win\_flex\_bison 2.4.5, flex 2.5.37)
    3. win\_bison(win\_flex\_bison 2.4.5, bison 2.7)
    4. boost(1.60)

- build boost
```
bjam --toolset=msvc-14.0 address-model=64
```

- configure boost
    1. add **boost\_dir** directory to additional include library
    2. add **boost\_dir/libs** and **boost\_dir/stage/lib** to additional library directory

- configure win\_flex and win\_bison
    1. On the Project menu, choose Project Dependencies.
    2. Select Custom Build Tools
    3. Add [/build/custom_build_rules/win_flex_bison_custom_build.props](/build/custom_build_rules/win_flex_bison_custom_build.props)

### Use fortran standard library
fortran standard library requires compiler support at least C++14 standard

### start

    -f file_name : translate file_name into C++
    -d : use debug mode
    -C : use c-style array

## Debug
Only fatal errors hinderring parsing will be reported by translator. 

Debug origin fortran code or generated C++ code is recommended.

## Demo
demos provided in [demos](/demos)

## fortran standard library
include [for90std/for90std.h](/for90std/for90std.h) to use C++ implementation of intrinsic fortran functions and language features

### inherit function mapping
#### type and type cast function
|fortran|C++|
|:-:|:-:|
|`INTEGER()`|`to_int`|
|`REAL()`|`to_double`|
|`LOGICAL()`|`to_bool`|
|`COMPLEX()`|`to_forcomplex`|
|`CHARACTER()`|`to_string`|

#### mathematical
|fortran|C++|
|:-:|:-:|
|`min`|`min_n`|
|`max`|`max_n`|

#### array
refer types:array

### IO function mapping
#### unit id mapping

|fortran|C++|
|:-:|:-:|
|*|`stdin`/`stdout`|
|5|`stdin`|
|6|`stdout`|
|id|`get_file(id)`|

#### file function mapping

|fortran|C++|
|:-:|:-:|
|open|foropenfile|
|close|forclosefile|

#### IO formatter mapping

|fortran|C++|
|:-:|:-:|
|`*` and `(*,*)`|forscanfree/forprintfree|
|`(*,formatter)`|forscan/forprint|
|`(device_id,*)`|forreadfree/forwritefree|
|`(device_id,formatter)`|forread/forwrite|

#### io-implied-do

> R916 io-implied-do is ( io-implied-do-object-list , io-implied-do-control )

> R917 io-implied-do-object is input-item or output-item

> R918 io-implied-do-control is do-variable = scalar-numeric-expr , scalar-numeric-expr [ , scalar-numeric-expr ]

io-implied-do will be translated into a `IOLambda`, refer [/target/gen_io.cpp](/target/gen_io.cpp)
```
auto make_iolambda(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func);
auto make_iolambda(fsize_t * _lb, fsize_t * _to, F func);
```
For input function like `forreadfree` and `forread`, the `io-implied-do-object-list` must be a *variable*(R914), so `F f` must return left-value.
For output function like `forwritefree` and `forwrite`, the `io-implied-do-object-list` must be a *expr*(R915), so `F f` can return anything.

#### IOStuff
`IOStuff` wraps a list of `input-item-list` or `output-item-list` inside an io-implied-do.  

## translation results and restrictions
refer to [/grammar/for90.y](/grammar/for90.y) for all accepted grammar
### grammar

1. you can rename keyword parameter in `interface` block
2. you can use anonymous grammar structures
3. declaration/specification is not forced before any other statements
    by fortran standard, declaration/specification(sudh as variable declarations and interfaces) statements must before all executable constructs(2.3.1)
    however, there's no such restriction in this translator 

#### implied-do


### types
#### type mapping

|fortran|C++|
|:-:|:-:|
|INTEGER(unspecified kind)|`int`|
|INTEGER(kind = 1)|`int8_t`|
|INTEGER(kind = 2)|`int16_t`|
|INTEGER(kind = 8)|`int32_t`|
|INTEGER(kind = 1)|`int64_t`|
|REAL(unspecified kind)|`double`|
|REAL(kind <= 4)|`float`|
|REAL(kind = 4)|`double`|
|REAL(kind = 8)|`long double`|
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
2. fortran array default lower bound for each rank is **1**, and it can be negative; each dimension of C++ style array has constant lower bound 0
3. fortran array **rank** start from 1, C++ array **dimension** start from 0, parameter for most `for-` functions are index of rank, though they are called "dim" in standard, they are called `fordim` in this implementation
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

1. construct an array
    - construct an array by given lower bound and size of each dimension

        ```
        farray<T>(int dimension, Iterator lower_bound, Iterator size)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D])
        ```
    - construct an array by given lower bound and size of each dimension, and assign an 1d list to the array

        ```
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X])
        ```
    - implicitly construct an 1d array from a scalar

        ```
        farray<T>(const T & scalar)
        ```
    - construct an array by given lower bound and size of each dimension, and assign another array's value(**NOT** including shape) to the array

        ```
        farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m)
        ```
    - construct an array by given lower bound and size of each dimension, and assign another array's value(**AND** shape) to the array

        ```
        farray(const farray<T> & m) // copy constructor
        ```

2. assign value to an array

    ALL these functions do **NOT** change the shape of `farr` itself. They practically called `operator=`
    - assign from a list: 

        ```
        farr = make_init_list(Iterator list_begin, Iterator list_end)
        farr = make_init_list(const T(&values)[X])
        ```
    - assign from implied `do`-loop
        important: `from` and `to` arguments do **NOT** indicate the shape of farr. they indicate the implied `do`-loop will loop from `from[dimension]` to `to[dimension]` in each dimension
        
        ```
        farr = make_init_list(const fsize_t(&from)[D], const fsize_t(&size)[D], F f)
        ```
    - assign from a scalar

        ```
        farr = make_init_list(const T & scalar)
        ```
    - assign from a list of a scalar repeated by `repeat` times

        ```
        farr = make_init_list(int repeat, const T & scalar)
        ```
    - assign from a `farray`
         this function will return exactly a copy of m

         ```
        farr = make_init_list(const farray<T> & m)
        ```
    - assign from a list of `farray`s
        all `farrs` must be of the same type `farray<T>`

        ```
        forconcat(const farray<T>(&farrs)[X])
        ```
        
3. assign value to an array and change its shape

    set `farr` 's shape and value equal to given argument `x`

    ```
    farr.copy_from(const farray<T> & x)
    ```
4. create a view from an array
    a view `varr` of array `farr` is another `farray<T>`, it shares physical storage with original `farr`. if `farr` is destructed, accessing data of `varr` us undefined behaviour

    the only way to create a view is by several constructor, and pass optional argument `isview = true`

    ```
	farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m, bool isview = false)
    ```

5. array traits

|function|usage|
|:-:|:-:|
|`.flatsize()`|get total number of elements in the array|
|`forconcat(x, y)`|concat array x and y|

##### fortran intrinsic functions

|fortran|C++| explaination |
|:-:|:-:|:-:|
|get|`a(1, 2, 3, 4)` or `a({1, 2, 3, 4})` or `a[{1, 2, 3, 4}]` or `forslice(a, {1, 2, 3, 4})`| |
|forslice|`a[{{1, 3, 1}, {1, 4}, {5}, {}}]` or `forslice(a, {{1, 3, 1}, {1, 4}, {5}}, {})`| |
|reshape|forreshape| |
|spread|not implemented yet| |
|transpose|fortranspose| fortran standard only defined rank 2 situation, for this implementation, the result will be a array with reversed rank |
|maxloc, minloc, maxval, minval|formaxloc, forminloc, formaxval, formaxloc| |
|sum, product|forsum, forproduct| call `operator+` and `operator*` |
|any, all, count|forany, forall, forcount| `forall` is **NOT** fortran95's `forall`, which is renamed to `forforall` |
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
    - with `f1a_init_hiddendo` in [/for90std/for1array.h](/for90std/for1array.h) to init array by implied do-loop

2. array traits

|function|usage|
|:-:|:-:|
|`f1a_flattern(array)`|get flatterned size of an array|
|`f1a_gettype<T>::type`|get innermost type of an array|
|`f1a_flatmap(array, begin_iterator, end_iterator, lambda)`|return a vector of all elements mapped by function `lambda` in fortran/c order|

### variables
1. variable names in fortran is **case-insensitive**, and their names will be translated into lower case.
2. variable names that conflicts with C++ keywords and std functions will be renamed with a `R_` surffix

#### common block

common blocks, can be accessed by any of the scoping units in an executable program

| common statement | CPP code |
|:-:|:-:|
|`INTEGER::A; COMMON A`| `int & a = G.a` |
|`INTEGER::B; COMMON /COMMON_NAME/ B`| `int & b = COMMON_NAME.b` |
|`COMMON C`| `T & c = G.c` |
|`COMMON /COMMON_NAME/ D`| `T & c = COMMON_NAME.c` |

where T conform to fortran's implicit type deduction(refer fortran 77 standard support for detail)
each commom block will be create a singleton struct
```
struct{
    T1 _1;
    T2 _2;
    /* common variables */
}COMMON_NAME;
```
if this common block is an unamed block, `COMMON_NAME` is by default `G`


### subroutines and functions
#### parameter tables
1. remove all definition of local variables which is also in parameter list
2. optional parameter: instead of c-style optional parameter, wrap optional parameters with `foroptional<T>`, function `forpresent` functions as `present` function in fortran90
3. keyword/named parameter: C++ don't support keyword parameters, all keyword parameter will be reorganized in normal paramtable

#### interface
1. replace all interface with forward declaration when necessary

#### attribute specification statements

> The INTENT (IN) attribute specifies that the dummy argument must not be redefined or become undefined
during the execution of the procedure.

> The INTENT (OUT) attribute specifies that the dummy argument must be defined before a reference to the
dummy argument is made within the procedure and any actual argument that becomes associated with such a
dummy argument must be definable. On invocation of the procedure, such a dummy argument becomes
undefined.

> The INTENT (INOUT) attribute specifies that the dummy argument is intended for use both to receive data from
and to return data to the invoking scoping unit. Any actual argument that becomes associated with such a dummy
argument must be definable.

> If no INTENT attribute is specified for a dummy argument, its use is subject to the limitations of the associated
actual argument (12.5.2.1, 12.5.2.2, 12.5.2.3).


|intent|parameter|save|result|
|:-:|:-:|:-:|:-:|
|/|/|/|refer fortran 77 standard support|
|ignore|/|save|`static`|
|ignore|parameter|save|`static const`|
|ignore|parameter|/|`const T`|
|in|ignore|/|`const T &`|
|out|ignore|/|`T &`|
|inout|ignore|/|`T &`|


### operators
1. defined operators is not supported

#### intrinsic operators

| fortran intrinsic operators | C++ |
|:-:|:-:|
| `.and.` | `&&` |
| `.or.` | `&&` |
| `.eqv.` | `!(A^B)` |
| `.neqv.` | `^` |
| `.eq.` | `==` |
| `.neq.` | `!=` |
| `.gt.` | `>` |
| `.ge.` | `>=` |
| `.lt.` | `<` |
| `.le.` | `<=` |

## fortran 77 standard support
### fixed form

### implicit 


#### implicit parameters table
Not all parameters in a `paramtable` need to be declared explicitly in the function body, if the parameter
1. used in both `paramtable` and the function body
    fortran 90 standard
2. used only in `paramtable`
    implicit definition conforming to fortran 77 standard

### subroutines and functions
#### attribute specification statements
fortran77 programs do not specify intent:

|fortran|C++|
|:-:|:-:|
|literals(right value)|`T`|
|left value|`T &`|

# Develop
refer to [/Develop.md](/Develop.md)