﻿# CFortranTranslator

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

## translation results and restrictions
refer to [/grammar/for90.y](/grammar/for90.y) for all accepted grammar
### grammar

1. you can rename keyword parameter in `interface` block
2. you can use anonymous grammar structures
3. variable definitions and interfaces is not forced before any other statements
    1. you can initialize array immediately like `integer,dimension(3)::A = (/1, 2, 3/)`, in gfortran you must assign initial value after all variables/arrays are defined

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

|fortran|C++| |
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

|common statement|C++ code|
|:-:|:-:|:-:|
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
> 3.3.2 Fixed source form
In fixed source form, there are restrictions on where a statement may appear within a line. If a source line
contains only default kind characters, it must contain exactly 72 characters; otherwise, its maximum number of
characters is processor dependent.
Except in a character context, blanks are insignificant and may be used freely throughout the program.

> 3.3.2.1 Fixed form commentary
The character "!" initiates a comment except when it appears within a character context or in character position
6. The comment extends to the end of the line. If the first nonblank character on a line is an "!" in any character
position other than character position 6, the line is a comment line. Lines beginning with a "C" or "*" in
character position 1 and lines containing only blanks are also comments. Comments may appear anywhere within
a program unit and may precede the first statement of the program unit. Comments have no effect on the
interpretation of the program unit.

> 3.3.2.2 Fixed form statement separation
The character ";" separates statements, or partial statements, on a single source line except when it appears in a
character context or in a comment. If a ";" separator is followed by zero or more blanks and one or more ";"
separators, the sequence from the first ";" to the last, inclusive, is interpreted as a single ";" separator. A ";"
separator that is the last nonblank character on a line, or the last nonblank character ahead of commentary, is
ignored.

> 3.3.2.3 Fixed form statement continuation
Except within commentary, character position 6 is used to indicate continuation. If character position 6 contains
a blank or zero, this line is the initial line of a new statement which begins in character position 7. If character
position 6 contains any character other than blank or zero, character positions 7–72 of this line constitute a
continuation of the preceding noncomment line. Note that an "!" or ";" in character position 6 indicates a
continuation of the preceding noncomment line. Comment lines cannot be continued. Comment lines may occur
within a continued statement.

In order to support some old fortran codes, a tab `'\t'` at the beginning of one line is also treated as the 5 characters indent

### implicit 

> 5.3 IMPLICIT statement
> In a scoping unit, an IMPLICIT statement specifies a type, and possibly type parameters, for all implicitly
typed data entities whose names begin with one of the letters specified in the statement. Alternatively, it may
indicate that no implicit typing rules are to apply in a particular scoping unit.

> In each scoping unit, there is a mapping, which may be null, between each of the letters A, B, ..., Z and a type
(and type parameters). An IMPLICIT statement specifies the mapping for the letters in its letter-spec-list.
IMPLICIT NONE specifies the null mapping for all the letters. If a mapping is not specified for a letter, the
default for a program unit or an interface body is default integer if the letter is I, J, ..., or N and default real
otherwise, and the default for an internal or module procedure is the mapping in the host scoping unit.

> Any data entity that is not explicitly declared by a type declaration statement, is not an intrinsic function, and is
not made accessible by use association or host association is declared implicitly to be of the type (and type
parameters) mapped from the first letter of its name, provided the mapping is not null. Note that the mapping can
be to a derived type that is inaccessible in the local scope if the derived type is accessible to the host scope. The
data entity is treated as if it were declared in an explicit type declaration in the outermost scoping unit in which
it appears. An explicit type specification in a FUNCTION statement overrides an IMPLICIT statement for the
name of that function subprogram.

#### implicit common block

#### implicit parammeters table
Not all data entities need be declared explicitly in a paramtable

### subroutines and functions
#### parameters table

#### attribute specification statements
fortran77 programs do not specify intent:

|fortran|C++|
|:-:|:-:|
|literals(right value)|`T`|
|left value|`T &`|

# Develop
refer to [/Develop.md](/Develop.md)