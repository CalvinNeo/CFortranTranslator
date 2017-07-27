# todolist
## todolist(features)
- ~~lazygen~~
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
- ~~function forward declaration(if necessary)~~
- c-style array(partial)
- variable with type
- ~~enable crlf rule~~(may cause bugs)
- ~~mixed array_builder~~
- ~~more specific type(char, int, long long)~~
- derived type stmt(4.4.1)
- ~~comments~~
- ~~one-line if~~
- ~~error infomation include Intent name~~
- ~~allow named blocks~~
- ~~support function pointers, Parse `Interface` for function pointer~~
- ~~hidden do~~
- ~~more precise code/error location, start/end~~
- optimize ParseNode with rvalue
- ~support fortran77 standard~
- ~~farray~~
- ~~goto stmt~~
- ~~use fortran array [from, to] rather than [from, to)~~
- ~promote return type in formerge so it can accept 2 different type farray~
- ~~`fslice` return by reference~~
- C.13.2.1 Unconditional array computations and C.13.2.2 Conditional array computations
- underscore kind param, like `.93E7_QUAD` ref standard 4.3.1.2
- keyword conflict between fortran and c++, such as `class`, `struct`, `int`
- arithmatic if
- ~~labeled do,~~ if
- `exit`, `cycle` outer do-loop
- ~~detailed type attr(add `TokenMeta::Int64`, etc.), use `TokenMeta::Implicit_Decl`, clean `TokenMeta` enum~~
- unicode file
- underscore kind-param for all type literal(ref 4.3.2.1)
- ~~display comments~~
- support other C++ compilers
- free format continuation(ref 3.3.1.3)

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
- ~~`printf` array~~
- ~~fixed length character initialize with shorter characters~~
- ~~add arraybuilder rule to exp rules~~
- ~~use `make_str_list` function replace some ugly code~~
- ~~hidden do(io-implied-do, ac-implied-do, data-implied-do)~~
- ~~pointer problem, including `VariableDesc::slice`, deal with nullptr~~
- ~~`ParseNode` inteface change to reference, remove pointer in other structures~~
- ~~won't generate repeated definitions in implicit paramtable~~
    ```
    subroutine sub(A)
	    A = 2
    end subroutine
    ```
- ~~`temporary_variable` to `FunctionInfo` variable~~
- ~~`regen_if`, `regen_do`, `regen_suite`~~
- ~~delete all `gen_` functions except `gen_token` with multiple which accepts a list of `YYSTYPE`.~~ ~~`regen_paramtable`~~, ~~`regen_function_array`~~
- ~~log all arguments in paramtable to `get_context().variable`~~
- ~~use `is_exp` function instead of `NT_EXPRESSION` node~~. rename `NT_EXPRESSION` to `NT_ARITH_EXP`, which constructed only by arithmatic rules
- declare all implicit variables (ref demos/implicit variable.txt)
- ~~implicit variable in variable declaration like:~~
    ```
    integer a = c
    ```
- ~~solve `(i+1,i+2, i = 1, 2)` in IO function~~
- ~~tokenizer: real type(4.3.1.2) conflict with operators, refer demos/control/tokenizer.txt~~
- enum-reflect.h can not calculate value like `Void - 100`, refer `make_enum_table`'s TODO
- change `VariableInfo::vardef_node` from pointer to  `ParseNode`
- interface function's `local_name`,  ref `get_full_paramtable`

