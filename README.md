# CFortranTranslator
A translator between C++ and Fortran90.

## Install
1. win_flex and win_bison
2. boost
3. vs2015

## grammar restrictions and translate rules
refer to for90.y for all accepted grammar
### unsupported keywords

1. NO `DO|IF|CASE|...` with a name after

### types
1. type mapping

|for90|c++|
|:-:|:-:|
|INTEGER(all kind)|int|
|REAL(all kind)|double|
|LOGICAL|bool|
|COMPLEX|struct for_complex|
|CHARACTER|std::string|
|array(1d)|for1array|
|array(nd)|fornarray|
|array|forarray|
|array-cstyle|not implemented|

### array
1. `DIMENSION(a:b)` -> `forarray<T>(a, b+1)`
2. forarray default lower bound is **1**, which is different from cpp

### variables
1. all variables must be **explicitly** declared
2. since variable names in fortran is case-insensitive, all variables will be in lower case in generated cpp code

### functions and subroutines
1. remove all difinition of local variables which is also in parameter list
2. remove all interface
3. intent(out) variables will translate to `T & variable`

#### inherit function mapping
|for90|c++|
|:-:|:-:|
|INTEGER()|to_int|
|REAL()|to_double|
|LOGICAL()|to_bool|
|COMPLEX()|to_int|
|CHARACTER()|forcomplex(constructor)|

### IO
|for90|c++|
|:-:|:-:|
|*,*|cout|
|*,formatter|printf|

## extend grammar
1. declare new %token in .y
2. add pattern of this %token in .l
3. add rules related to the %token in .y
4. update bytecodes and grammar tokens in Intent.h
5. register keyword in tokenizer.cpp(if this token is keyword)
**6**. if this keyword takes more than 1 word and can cause reduction conflicts between itself and its surfix like `else if`, update forward1 in tokenizer.cpp
7. update translation rules in cgen.h

## Parse Tree
all parse tree nodes are defined in Intents.h with an `NT_` surfix

## todolist
- lazygen(partial)
- ~~function-array reduction-reduction conflict~~
- multi-dimension forarray(partial)
- for90std functions(partial)
- ~~io formatter~~
- optional parameters
- keyword parameter list
- ~~reference in parameter list~~
- ~~rewrite paramtable and var_def(simplify right-recursive rules, move dimension to dummy_variale_iden)~~
- ~~more elegant multi-word keyword handler(instead of defined in regular expression)~~
- function forward declaration
