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
7. if this keyword are made up of more than 1 word, reduction conflicts may be caused between the keyword and its prefix,
    - if rules keywords are all charaters like `(/`, just add a regex to for90.l
    - if rules keywords are all words like `else if`, update forward1 in [/tokenizer.cpp](/tokenizer.cpp)
8. update translation rules in [/gen_config.h.h](/gen_config.h.h)

## extend new intrinsic function
1. implement this function and included it in [for90std/for90std.h](/for90std/for90std.h)
	- if a parameter is **optional** in fortran, wrap it with `foroptional`, and log all parameters of this function in [/gen_config.cpp](/gen_config.cpp)
    - if the parameter is the **only** optional parameter, can omit `foroptional` wrapper
2. update `funcname_map` in [/gen_config.cpp](/gen_config.cpp) if necessary

## c++ code generate
when using immediate code generate(or using lazy gen), upper level non-terminal can channge generated codes by low level non-terminal, so `gen_` functions pass `ParseNode &` other than `const ParseNode &`:

1. `function_decl` change `suite`(function body)
2. all `suite` will be changed(`tabber` function)
3. ~~`dimen_slice` will append 1 child to the end of size == 1 slice~~
4. argtable will change `CurrentTerm.what` of `dimen_slice`
5. `gen_variabledesc_from_dimenslice` will promote `exp` to `slice`. because it is definitly an array other than a argtable now.

child ParseNode may also be referred when generating upper level ParseNode, so do not change child index of:

1. `NT_VARIABLEINITIAL`: referred in `function_decl`
2. `NT_FUNCTIONDECLARE`: can represent interface, referred in `paramtable` and `function_decl`

### name mapping
many type names and function names are mapped, they are defined in in [/gen_config.h](/gen_config.h)
their replacement occur in following stages:

1. mappings defined in `pre_map` is replacement in tokenizing stage in [/grammar/for90.l](/grammar/for90.l)

2. function name mapping in `funcname_map` is replacement in parse stage in function `gen_function_array` [/gen_callable.cpp](/gen_callable.cpp)

### array

**though fortran-style array is different from c-style array, only need to consider relationship with flatterned 1d array**

1. for1array is a 1d dynamic array defined in [/for90std/for1array.l](/for90std/for1array.h), farray is a nd array defined in [/for90std/farray.l](/for90std/farray.h)
2. functions and arrays are generated in normal order in [/gen_callable.cpp](/gen_callable.cpp). 
3. array declaration is in [/gen_vardef.cpp](/gen_vardef.cpp)
4. overload `operator()` and  `operator[]` so `a(x, y, z)`(fortran-style) is same as `a(x)(y)(z)`(c-style) where x,y,z are `slice_info` or index
5. slice selections are handled in [/gen_callable.cpp](/gen_callable.cpp). 


## Parse Tree
all parse tree nodes are defined in [/Intent.h](/Intent.h) with an `NT_` prefix
### struct ParseNode
1. fs:
	* fs.CurrentTerm.what: immediate-generated code, generated from child's `fs.CurrentTerm.what`, or from other infomations
	* fs.CurrentTerm.token: refer [/Intent.h](/Intent.h)
2. child
3. attr:
	attrs including
	* FunctionAttr
	* VariableDescAttr
4. father: parent node

### rules explanation
#### argtable, paramtable
- argtable is now alias of paramtable
- `callable_head` and `paramtable`(NT_ARGTABLE_PURE/NT_PARAMTABLE_DIMENSLICE) are two parts of a function call/array slice
- both type and function name are callable name, so both `type_nospec` and `variable` are `callable_head`
- `keyvalue` rules generates `NT_VARIABLEINITIAL` = `NT_KEYVALUE` node. `what` of this node is `name` not `name = value`, the later is regenerated in `gen_function_array` in [/gen_callable.cpp](/gen_callable.cpp)

#### dimen_slice, paramtable
- `dimen_slice` rule: 
    - `dimen_slice` rule can reduce to: `NT_DIMENSLICE`, `NT_ARGTABLE_PURE` node.
    - `dimen_slice` is needed in `paramtable`, `case_stmt_elem`, `variable_desc_elem`
    - `NT_ARGTABLE_PURE` + `NT_SLICE` -> `NT_DIMENSLICE`
    - `exp` + **`paramtable`** -> gen_paramtable() -> `NT_PARAMTABLE` / `NT_PARAMTABLE_DIMENSLICE` / `NT_ARGTABLE_PURE`
    - as a result, `dimen_slice` is a set of `slice`(`NT_DIMENSLICE`), or a set of both `exp` and `slice`(`NT_DIMENSLICE`), or a set of `exp`(`NT_ARGTABLE_PURE`) 

- `paramtable` rule(refer [/gen_paramtable.cpp](/gen_paramtable.cpp)):
	`paramtable` rule can reduce to: `NT_PARAMTABLE`, `NT_ARGTABLE_PURE`, `NT_PARAMTABLE_DIMENSLICE` node.
	- `keyvalue` / `dimen_slice`(`NT_DIMENSLICE`/`NT_ARGTABLE_PURE`) -> `NT_PARAMTABLE`
	- when `keyvalue`: promote this to `paramtable`. 
	- when `NT_DIMENSLICE`: promote this to `NT_PARAMTABLE_DIMENSLICE`(do not keep `NT_DIMENSLICE`). refer function `gen_argtable`
	- when `NT_ARGTABLE_PURE`: promote this to `NT_ARGTABLE_PURE`. refer function `gen_argtable`
	- `keyvalue` + `paramtable`
	- `NT_DIMENSLICE` + `paramtable`
	- `NT_ARGTABLE_PURE` + `paramtable`

	
#### type_spec, type_nospec
you can use `REAL(x)` to get the float copy of x, however, you can also use `REAL(kind = 8)` to specify a floating number which is same to `long double` rather than `double`, so it may cause conflict. To specify, `type_nospec` is like `INTEGER` and a `type_spec` is like `INTEGER(kind = 4)`, `type_nospec` is `callable_head`, `type_spec` is not.

#### array builder
- `_generate_stmt` wrapped by `"( )"` is `hidder_do`
- `hidden_do` wrapped by `"(/ /)"` is `NT_ARRAYBUILDER_LAMBDA`
- `array_builder` can be composed of several kind of `array_builder_elem`:
    - `NT_ARRAYBUILDER_LAMBDA`
    - `NT_ARRAYBUILDER_LIST`

    a `array_builder` will be translated into a array object in c++ code
- `NT_FUCNTIONARRAY` and `NT_HIDDENDO` will all be promote to `NT_EXPRESSION`
- `NT_HIDDENDO` has 4 child elements: lambda, indexer, from, to. refer `gen_hiddendo` in [/gen_do.cpp](/gen_do.cpp)

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
| paramtable_elem | / | dimen_slice / keyvalue / exp |
| paramtable | NT_PARAMTABLE | paramtable_elem + |
| | NT_DECLAREDVARIABLE | no rules, renamed from keyvalue |
| keyvalue | NT_VARIABLEINITIAL(namely NT_KEYVALUE) | variable, NT_EXPRESSION / NT_VARIABLEINITIALDUMMY |
| | NT_VARIABLEINITIAL | variable, exp / array_builder |
| function_array_body | NT_FUCNTIONARRAY | NT_PARAMTABLE_DIMENSLICE / NT_PARAMTABLE |
| dimen_slice | NT_DIMENSLICE | NT_SLICE |
| dimen_slice | NT_ARGTABLE_PURE | NT_EXPRESSION |
| variable_desc_elem | NT_VARIABLEDESC | dimen_slice |
| suite | NT_SUITE | NT_STATEMENT \* |
| stmt | NT_STATEMENT | exp / var_def / compound_stmt / output_stmt / input_stmt / dummy_stmt / let_stmt / jump_stmt / interface_decl |
| | NT_ARRAYBUILDER | (NT_ARRAYBUILDER_LAMBDA / NT_ARRAYBUILDER_LIST) + |
| | NT_ARRAYBUILDER_LAMBDA |  |
| | NT_ARRAYBUILDER_LIST |  |
| type_spec |  | type_nospec / (type_nospec, typecast_spec) |

### Symbols
all variables(including `commom` block) and functions is now logged in [/Variable.h](/Variable.h) and [/Function.h](/Function.h) by
`VariableInfo` and `FunctionInfo`

#### VariableDesc
| item | rule |
|:-:|:-:|
| kind | typecast_spec |
| len | typecast_spec |
| dimension | variable_desc_elem |
| intent | variable_desc_elem |
| optional | variable_desc_elem |
| parameter | variable_desc_elem |

### Attributes
`->` means a `ParseNode` has this `ParseAttr`

| ParseAttr | Usage |
|:-:|:-:|
| `VariableDescAttr` | NT_DECLAREDVARIABLE or NT_VARIABLEDEFINE or NT_VARIABLEINTIAL nodes of NT_VARIABLEDEFINE.NT_PARAMTABLE |
| `FunctionAttr` | NT_FUNCTIONDECLARE |
| `VarialbeAttr` | NT_FUNCTIONDECLARE |



