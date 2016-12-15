# CFortranTranslator
A translator from Fortran to C++

# Usage
## Install
My Configuration:

1. vs2015(Update 3) 
2. win_flex(win_flex_bison 2.4.5, flex 2.5.37)
3. win_bison(win_flex_bison 2.4.5, bison 2.7)
4. boost(1.60)

## fortran std
include [for90std/for90std.h](/for90std/for90std.h) to use c++ implementation of intrinsic fortran functions and language features
all slice in c++ is [from, to)

### inherit function mapping
#### type cast
|fortran|c++|
|:-:|:-:|
|INTEGER()|to_int|
|REAL()|to_double|
|LOGICAL()|to_bool|
|COMPLEX()|to_int|
|CHARACTER()|forcomplex(constructor)|

#### mathematical
|fortran|c++|
|:-:|:-:|
|min|min_n|
|max|max_n|

#### array
|fortran|c++|
|:-:|:-:|
|reshape|not implemented yet|
|spread|not implemented yet|
|transpose|not implemented yet|

### IO function mapping
#### device id mapping

|fortran|c++|
|:-:|:-:|
|*|get_file(-1)|
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
|*|cin/cout|
|(*,*)|cin/cout|
|(*,formatter)|scanf/printf|
|(device_id,formatter)|forread/forwrite|

## translation results and restrictions
refer to [/grammar/for90.y](/grammar/for90.y) for all accepted grammar
### unsupported keywords

1. now you can rename keyword parameter in `interface` block

### types
#### type mapping

|fortran|c++|
|:-:|:-:|
|INTEGER(all length)|int|
|REAL(all length)|double|
|LOGICAL|bool|
|COMPLEX|struct for_complex|
|CHARACTER|std::string|
|array(1d)|for1array&lt;T&gt;|
|array(nd)|for1array&lt;for1array&lt; ...for1array&lt;T&gt;&gt;&gt;|
|array(alias)|forarray|
|array-cstyle|not implemented yet|

#### array
1. `DIMENSION(a:b)` -> `forarray<T>(a, b + 1)` and forarray default lower bound is **1**
2. fortran use a 1d list to initialize a 2d(or higher) array, and store them in a **column-first order**. 
    - for a 2d array, it means you a order of `a(1)(1) -> a(2)(1) -> a(1)(2) -> a(1)(2)` . 
    - you can `#undef USE_FORARRAY` to use c-style array. 
    - for details refer to `array_builder` rule in [/grammar/for90.y](/grammar/for90.y)
3. `#define USE_FORARRAY` to use fortran style array, `#define USE_CARRAY` to use c style array
4. define a array
5. init a array
    - use `init_for1array(array, lower_bound, size, values)` to init array, in which
        1. `array` is reference of a defined array you want to init
        2. `lower_bound` is the lower bound of every dimension(from left to right) in this array
        3. `size` is the size of every dimension in this array
        4. `values` is `std::vector` of initialize list

6. hidden do will be translated to `init_for1array_hiddendo` in [/for90std/for1array.h](/for90std/for1array.h)
    - when use `hidden_do` to generate array, array's LBound and hidden_do index's initial value must agree

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

4. optional parameter: instead of c-style optional parameter, wrap optional parameters with `foroptional`, function `forpresent` functions as `present` function in fortran90
5. keyword/named parameter: c++ don't support keyword parameters, all keyword parameter will be reorganized in normal paramtable

# Develop

## Debug
### Configurations
1. the **Debug** mode accept command line arguments `argv[]` which is set to default values in VS project configurations
2. the **Develop** mode invoke the function `void debug()` which is defined in [develop.cpp](/develop.cpp)
3. the **Release** is same as the **Debug** mode except for default values which is not set

## extend grammar
1. declare new %token in [/grammar/for90.y](/grammar/for90.y)
2. add pattern of this %token in [/grammar/for90.l](/grammar/for90.l)
3. add rules related to the %token in [/grammar/for90.y](/grammar/for90.y)
4. update bytecodes and grammar tokens in [/Intent.h](/Intent.h)
5. update IntentName in [/IntentHelper.cpp](/IntentHelper.cpp)
6. register keyword in [/tokenizer.cpp](/tokenizer.cpp)(if this token is keyword)
7. if this keyword takes more than 1 word and can cause reduction conflicts between itself and its prefix like `else if`, update forward1 in [/tokenizer.cpp](/tokenizer.cpp)
8. update translation rules in [/gen_config.h.h](/gen_config.h.h)

## extend new intrinsic function
1. implement this function and included it in [for90std/for90std.h](/for90std/for90std.h)
	- if a parameter is **optional** in Fortran, wrap it with `foroptional`
2. log all parameters of this function in [/gen_config.cpp](/gen_config.cpp)

## c++ code generate
when using immediate code generate(or using lazy gen), upper level non-terminal can channge generated codes by low level non-terminal, so `gen_` functions pass `ParseNode &` other than `const ParseNode &`:

1. `function_decl` change `suite`(function body)
2. all `suite` will be changed(`tabber` function)
3. ~~`dimen_slice` will append 1 child to the end of size == 1 slice~~
4. argtable will change `CurrentTerm.what` of `dimen_slice`
5. `gen_variabledesc_from_dimenslice` will promote `exp` to `slice`. because it is definitly an array other than a argtable now.

child ParseNode may also be referred when generating upper level ParseNode, so do not change child index of:

1. NT_VARIABLEINITIAL: referred by function_decl
2. NT_FUNCTIONDECLARE: referred by interface of paramtable

### name mapping
many type names and function names are mapped, they are defined in in [/gen_config.h](/gen_config.h)
their replacement occur in following stages:

1. mappings defined in `pre_map` is replacement in tokenizing stage in [/grammar/for90.l](/grammar/for90.l)

2. function name mapping in `funcname_map` is replacement in parse stage in function `gen_function_array` [/gen_callable.cpp](/gen_callable.cpp)

### fortran-style array
** though fortran-style array is different from c-style array, only need to consider relationship with flatterned 1d array **

1. for1array class defined in [/for90std/for1array.l](/for90std/for1array.h)
2. in [/gen_callable.cpp](/gen_callable.cpp), functions and arrays are generated in normal order
3. in [/gen_vardef.cpp](/gen_vardef.cpp)
4. overload for1array<T>::operator() so `a(1, 2, 3)` is same as `a(1)(2)(3)`

### c-style array

## Parse Tree
all parse tree nodes are defined in [/Intent.h](/Intent.h) with an `NT_` prefix
### struct ParseNode
1. father: parent node
2. fs:
	* fs.CurrentTerm.what: immediate-gen code
	* fs.CurrentTerm.token: refer [/Intent.h](/Intent.h)
3. attr:
	attrs including
	* FunctionAttr
	* VariableDescAttr

4. child

### rules explanation
#### callable_head, argtable, dimen_slice, paramtable, keyvalue
- argtable is now alias of paramtable
- `callable_head` and `argtable` are two parts of a function call
- both type and function name are callable name, so both `type_nospec` and `variable` are `callable_head`
- `keyvalue` rules generates `NT_VARIABLEINITIAL` = `NT_KEYVALUE` node. `what` of this node is `name` not `name = value`, the later is regenerated in `gen_function_array` in [/gen_callable.cpp](/gen_callable.cpp)

#### argtable, dimen_slice, paramtable
- `dimen_slice` rule: 
	`dimen_slice` rule can reduce to: `NT_DIMENSLICE`, `NT_ARGTABLE_PURE` node.
	`dimen_slice` is needed in `paramtable`, `case_stmt_elem`, `variable_desc_elem`
	- `NT_ARGTABLE_PURE` + `NT_SLICE` -> `NT_DIMENSLICE`
	- `exp` + **`paramtable`** -> gen_paramtable() -> `NT_PARAMTABLE` / `NT_PARAMTABLE_DIMENSLICE` / `NT_ARGTABLE_PURE`
	- as a result, `dimen_slice` is a set of `slice`(`NT_DIMENSLICE`), or a set of both `exp` and `slice`(`NT_DIMENSLICE`), or a set of `exp`(`NT_ARGTABLE_PURE`) 

- `paramtable` rule(refer [/gen_paramtable.cpp](/gen_paramtable.cpp)):
	`paramtable` rule can reduce to: `NT_PARAMTABLE`, `NT_ARGTABLE_PURE`, `NT_PARAMTABLE_DIMENSLICE` node.
	- `keyvalue` / `dimen_slice`(`NT_DIMENSLICE`/`NT_ARGTABLE_PURE`) -> `NT_PARAMTABLE`
	- when `keyvalue`: promote this to `paramtable`. 
	- when `NT_DIMENSLICE`: promote this to `NT_DIMENSLICE`. refer function `gen_argtable`
	- when `NT_ARGTABLE_PURE`: promote this to `NT_ARGTABLE_PURE`. refer function `gen_argtable`
	- `keyvalue` + `paramtable`
	- `NT_DIMENSLICE` + `paramtable`
	- `NT_ARGTABLE_PURE` + `paramtable`
	
#### type_spec, type_nospec
you can use `REAL(x)` to get the float copy of x, however, you can also use `REAL(kind = 8)` to specify a floating number which is same to `long double` rather than `double`, so it may cause conflict. so a `type_nospec` is like `INTEGER` and a `type_spec` is like `INTEGER(kind = 4)`, `type_nospec` is `callable_head`, `type_spec` is not.

#### hidden_do, _generate_stmt
- `_generate_stmt` is for `array_builder`, `hidden_do` is for `exp`
- `hidder_do` is wrapped by "( )", `_generate_stmt` is wrapped by "(/ /)"

#### stmt, suite
- `stmt` is statement end with ';' or '\n'
- `suite` is set of `stmt`


### Parse Tree Layers

|rules|left NT|right(included)|
|:-:|:-:|:-:|
| fortran_program | root | wrappers |
| wrappers | NT_WRAPPERS | wrapper + |
| wrapper | / | function_decl / program |
| function_decl | NT_FUNCTIONDECLARE |  |
| var_def | NT_VARIABLEDEFINE | typeinfo, NT_DIMENSLICE / dummy, NT_PARAMTABLE |
| paramtable_elem | / | dimen_slice / keyvalue / NT_DECLAREDVARIABLE |
| paramtable | NT_PARAMTABLE | paramtable_elem + |
| | NT_DECLAREDVARIABLE | no rules, renamed from keyvalue |
| keyvalue | NT_VARIABLEINITIAL(namely NT_KEYVALUE) | variable, NT_EXPRESSION / NT_VARIABLEINITIALDUMMY |
| | NT_VARIABLEINITIAL | variable, exp / array_builder |
| function_array_body | NT_FUCNTIONARRAY | NT_PARAMTABLE_DIMENSLICE / NT_PARAMTABLE |
| dimen_slice | NT_DIMENSLICE | NT_SLICE |
| dimen_slice | NT_ARGTABLE_PURE | NT_EXPRESSION |
| variable_desc_elem | NT_VARIABLEDESC | dimen_slice |
| ~~argtable~~ | NT_PARAMTABLE_DIMENSLICE / NT_ARGTABLE_PURE | dimen_slice |
| suite | NT_SUITE | NT_STATEMENT \* |
| stmt | NT_STATEMENT | exp / var_def / compound_stmt / output_stmt / input_stmt / dummy_stmt / let_stmt / jump_stmt / interface_decl |
| | NT_ARRAYBUILDER | NT_ARRAYBUILDER_VALUE + |
| | NT_ARRAYBUILDER_VALUE | argtable / NT_ARRAYBUILDER_EXP / exp |
| callable_head |  | variable / type_nospec |
| type_spec |  | type_nospec / (type_nospec, typecast_spec) |

### Attributes
`->` means `ParseAttr` attached to:
- VariableDesc -> NT_DECLAREDVARIABLE
- VariableDesc -> NT_VARIABLEINTIAL nodes of NT_PARAMTABLE(only son of NT_VARIABLEDEFINE node)
- VariableDesc -> NT_VARIABLEDEFINE

#### VariableDesc
| item | rule |
|:-:|:-:|
| kind | typecast_spec |
| len | typecast_spec |
| dimension | variable_desc_elem |
| intent | variable_desc_elem |
| optional | variable_desc_elem |
| parameter | variable_desc_elem |

## todolist(features)
- lazygen(partial)
- ~~function-array reduction-reduction conflict~~
- ~~multi-dimension forarray~~
- ~~multi-dimension forarray array-builder~~
- for90std functions
	- file
	- array(reshape, spread, transpose)
- ~~io formatter~~
- ~~optional parameters~~
- ~~keyword parameter list~~
- ~~reference in parameter list~~
- ~~rewrite paramtable and var_def(simplify right-recursive rules, move dimension to dummy_variale_iden)~~
- ~~more elegant multi-word keyword handler(instead of defined in regular expression)~~
- replace interface with function forward declaration(if necessary)
- c-style array(partial)
- variable with type
- ~~enable crlf rule~~(may cause bugs)
- ~~mixed array_builder~~
- ~~more specific type(char, int, long long)~~
- type stmt
- ~~comments~~
- ~~one-line if~~
- ~~error infomation include Intent name~~
- ~~allow named blocks~~
- ~~support function pointers, Parse `Interface` for function pointer~~
- ~~hidden do~~
- ~~more precise code/error location, start/end~~
- optimize ParseNode with rvalue
- support fortran77 standard
- rewrite for1array functions using constexpr

## todolist(bugfix)
- ~~if slice can be a scalar x and equal to (1: x + 1), there will be conflict in argtable~~
- more specific type cast functions(char, int, long long)
- ~~read statement undefined device~~
- ~~minus 1 and negative 1 conflict(modify definition in .l)~~
- either an `interface` or **forward declaraion of return value** is need when calling functions in fortran, so must remove all `interface` and ~~forward declaraion of function return value~~ in generated code in order to avoid repeat definition.
- ~~error message line info is always 0~~
- ~~handle error when can't find declaration of the variable listed in function paramtable~~
- ~~handle with empty line~~
- ~~split keyvalue rules from paramtable rules, may cause bugs~~
- ~~_type_kind rules and type cast function call conflict~~
- ~~solve `paramtable : exp`, `argtable : exp` conflict by merging argtable to paramtable~~
	~~1. merge `argtable` and `dimen_slice` to paramtable~~
	~~2. only change reduce rules~~
- `printf` array
- fixed length character initialize with shorter characters
- dimen_slice ',' paramtable rule use gen_paramtable directly
