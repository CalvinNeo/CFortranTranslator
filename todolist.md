# todolist
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
- goto stmt

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
- global attr and node attr
- dimen_slice ',' paramtable rule use gen_paramtable directly
- add arraybuilder rule to exp rules