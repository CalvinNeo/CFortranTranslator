# CFortranTranslator
A translator between C++ and Fortran90.

## Install
1. win_flex and win_bison
2. boost
3. vs2015

## fortran grammar restrictions and translate rules
refer to for90.y for all accepted grammar
### dumb keywords

1. NO named `DO|IF|CASE|...` term

### types
1. type mapping

|for90|c++|
|:-:|:-:|
|INTEGER(all kind)|int|
|REAL(all kind)|double|
|LOGICAL|bool|
|COMPLEX|struct for_complex|
|CHARACTER|std::string|
|array(1d)|forarray|

### variables
1. all variables must be **explicitly** declared

### functions and subroutines
1. 

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
6. update translation rules in cgen.h

## todolist
- lazygen(partial complete)
- function-array reduction-reduction conflict
- multi-dimension forarray
- for90std functions(partial complete)
