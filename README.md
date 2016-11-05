# CFortranTranslator
A translator between C++ and Fortran90.

## Install
1. vs2015(Update 3) + win_flex(win_flex_bison 2.4.5, flex 2.5.37) + win_bison(win_flex_bison 2.4.5, bison 2.7), or any thing that works
2. boost(1.60)

## Debug
### Configurations
1. the **Debug** mode accept command line arguments `argv[]` which is set to default values in VS project configurations
2. the **Develop** mode invoke the function `void debug()` which is defined in [develop.cpp](/develop.cpp)
3. the **Release** is same as the **Debug** mode except for default values which is not set

## grammar restrictions and translate rules
refer to [/grammar/for90.y](/grammar/for90.y) for all accepted grammar
### unsupported keywords

1. no named blocks(supported soon)

### INTERFACE block
`INTERFACE` block will be skipped during parsing, so avoid:

1. rename kwyword parameter

### types
#### type mapping

|for90|c++|
|:-:|:-:|
|INTEGER(all length)|int|
|REAL(all length)|double|
|LOGICAL|bool|
|COMPLEX|struct for_complex|
|CHARACTER|std::string|
|array(1d)|for1array&lt;T&gt;|
|array(nd)|for1array&lt;forarray&lt; ...forarray&lt;T&gt;&gt;&gt;|
|array(alias)|forarray|
|array-cstyle|not implemented yet|

#### array
1. `DIMENSION(a:b)` -> `forarray<T>(a, b + 1)`
2. forarray default lower bound is **1**, which is different from cpp
3. fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn-first order**. for a 2d array, it means you a order of a(1)(1) -> a(2)(1) -> a(lb_1)(1) -> a(1)(2) . you can `#undef USE_FORARRAY` to use c-style array .for details refer to array_builder rule in [/grammar/for90.y](/grammar/for90.y)

### variables
1. all variables must be **explicitly** declared
2. since variable names in fortran is **case-insensitive**, all variables will be in lower case in generated cpp code

### functions and subroutines
1. remove all difinition of local variables which is also in parameter list
2. remove all interface
3. intent(out) variables will translate to `T & variable`

#### inherit function mapping
##### type cast
|for90|c++|
|:-:|:-:|
|INTEGER()|to_int|
|REAL()|to_double|
|LOGICAL()|to_bool|
|COMPLEX()|to_int|
|CHARACTER()|forcomplex(constructor)|

##### mathematical
|for90|c++|
|:-:|:-:|
|min|min_n|
|max|max_n|

##### file
|for90|c++|
|:-:|:-:|

##### array
|for90|c++|
|:-:|:-:|
|reshape|not implemented yet|
|spread|not implemented yet|
|transpose|not implemented yet|

### IO
|for90|c++|
|:-:|:-:|
|*|cin/cout|
|(*,*)|cin/cout|
|(*,formatter)|scanf/printf|
|(device_id,formatter)|not implemented yet|

## extend grammar
1. declare new %token in [/grammar/for90.y](/grammar/for90.y)
2. add pattern of this %token in [/grammar/for90.l](/grammar/for90.l)
3. add rules related to the %token in [/grammar/for90.y](/grammar/for90.y)
4. update bytecodes and grammar tokens in [/Intent.h](/Intent.h)
5. register keyword in [/tokenizer.cpp](/tokenizer.cpp)(if this token is keyword)
6. if this keyword takes more than 1 word and can cause reduction conflicts between itself and its prefix like `else if`, update forward1 in [/tokenizer.cpp](/tokenizer.cpp)
7. update translation rules in [/cgen.h](/cgen.h)

## code generate
when using immediate code generate(or using lazy gen), upper level non-terminal can channge generated codes by low level non-terminal, so `gen_` functions pass `ParseNode &` other than `const ParseNode &`:

1. function_decl change suite(function body)
2. all suite will be changed(`tabber` function)

## Parse Tree
all parse tree nodes are defined in [/Intent.h](/Intent.h) with an `NT_` prefix
### ParseNode
1. father: parent node
2. fs:
	* fs.CurrentTerm.what: direct-gen code
	* fs.CurrentTerm.token: refer [/Intent.h](/Intent.h)
3. attr
4. child

### Parse Tree Layers
- fortran_program -> wrappers
- wrappers -> wrapper +
- wrapper(not a node) -> function_decl || program
- NT_VARIABLEDEFINE -> (typeinfo, NT_DIMENSLICE || dummy, NT_PARAMTABLE )
- NT_PARAMTABLE -> NT_VARIABLEINITIAL || NT_DECLAREDVARIABLE
- NT_VARIABLEINITIAL/NT_DECLAREDVARIABLE -> (UnknownVariant, NT_EXPRESSION || NT_VARIABLEINITIALDUMMY)
- NT_ARGTABLE_DIMENSLICE -> NT_DIMENSLICE
- NT_DIMENSLICE -> NT_SLICE ; dimen_slice rule
- NT_ARGTABLE_PURE -> NT_EXPRESSION ; dimen_slice rule
- NT_SUITE -> NT_STATEMENT+
- NT_STATEMENT -> exp || var_def || compound_stmt || output_stmt || input_stmt || dummy_stmt || let_stmt || jump_stmt || interface_decl
- NT_ARRAYBUILDER -> (NT_ARRAYBUILDER_VALUE -> argtable || NT_ARRAYBUILDER_EXP || exp) +

### Attributes
`->` means `ParseAttr` attached to
- VariableDesc -> NT_DECLAREDVARIABLE

## todolist(features)
- lazygen(partial)
- ~~function-array reduction-reduction conflict~~
- ~~multi-dimension forarray~~
- ~~multi-dimension forarray array-builder~~
- for90std functions(partial)
- ~~io formatter~~
- optional parameters
- keyword parameter list
- ~~reference in parameter list~~
- ~~rewrite paramtable and var_def(simplify right-recursive rules, move dimension to dummy_variale_iden)~~
- ~~more elegant multi-word keyword handler(instead of defined in regular expression)~~
- replace interface with function forward declaration(if necessary)
- ~~if slice can be a scalar x and equal to (1: x + 1), there will be conflict in argtable~~
- c-style array(partial)
- variable with type
- ~~enable crlf rule~~(may cause bugs)
- mixed array_builder
- array functions(reshape, spread, transpose)
- ~~more specific type(char, int, long long)~~
- type stmt
- ~~comments~~
- file functions
- ~~one-line if~~
- ~~error infomation include Intent name~~
- allow named blocks
- support function pointers, Parse `Interface` for function pointer

## todolist(bugfix)
- more precise code location (update_pos parse_len)
- more specific type cast functions(char, int, long long)
- ~~read statement undefined device~~
- ~~minus 1 and negative 1 conflict(modify definition in .l)~~
- either an `interface` or **forward declaraion of return value** is need when calling functions in fortran, so must remove all `interface` and ~~forward declaraion of function return value~~ in generated code in order to avoid repeat definition.
- error message line info is always 0
- ~~handle error when can't find declaration of the variable listed in function paramtable~~
- handle with empty line