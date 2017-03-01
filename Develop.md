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
### lazy generate
when using immediate code generate(or using lazy gen), upper level non-terminal can channge generated codes by low level non-terminal, so `gen_` functions pass `ParseNode &` other than `const ParseNode &`:

1. all `regen_` function will change its input `ParseNode &`
2. all `gen_` function will not change its input `const ParseNode &`

due to fortran's implicit declaration, code above `stmt` level, including `function_decl`, `program` will be regenerated after the whole AST is builded by following steps:
1. `gen_fortran_program` handles `program`, `function_decl`
2. `regen_suite` handles `suite` rule
3. `regen_common` generates `common` statement code

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

### nodes

child ParseNode may also be referred when generating upper level ParseNode, so do not change child index of:

1. `NT_VARIABLEINITIAL`: referred in `function_decl`
2. `NT_FUNCTIONDECLARE`: can represent interface, referred in `paramtable` and `function_decl`

### rules explanation
#### argtable, dimen_slice, pure_paramtable
##### constitution
- `argtable` is a list of `exp`(`NT_EXPRESSION`)
- `dimen_slice` is a list of `slice`(`NT_SLICE`)
- `pure_paramtable` is a list of `keyvalue`(`NT_KEYVALUE`/`NT_VARIABLEINITIAL`)
    - `NT_KEYVALUE.fs.CurrentTerm.what` will be regenerated in `gen_function_array` in [/gen_callable.cpp](/gen_callable.cpp)
- `paramtable` is `argtable` or `dimen_slice` or `pure_paramtable`
##### promotion
- `argtable` + `slice` = `dimen_slice`, all elements in `argtable` will be promote to `slice`(with one child)
- `argtable` + `keyvalue` = `pure_paramtable`, all elements in `argtable` will be promote to `keyvalue`
	
#### type_spec, type_name, type_selector

>	(3) The suffix "- spec" is used consistently for specifiers, such as keyword actual arguments and
>		input / output statement specifiers.It also is used for type declaration attribute specifications(for
>			example, "array - spec" in R512), and in a few other cases.

>	(4) When reference is made to a type parameter, including the surrounding parentheses, the term
>		"selector" is used.See, for example, "length - selector"(R507) and "kind - selector"(R505).

you can use `REAL(x)` to get the float copy of x, however, you can also use `REAL(kind = 8)` to specify a floating number which is same to `long double` rather than `double`, so it may cause conflict. 
To specify, `type_name` is like `INTEGER` and a `type_spec` is like `INTEGER(kind = 4)`, `type_nospec` can be head of `callable`, `type_spec` is not.

#### array builder
- `hidden_do` wrapped by `(/ /)` is `NT_ARRAYBUILDER_LAMBDA`
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
| wrappers |  | wrapper + |
| wrapper | / | function_decl / program |
| function_decl | NT_FUNCTIONDECLARE |  |
| var_def | NT_VARIABLEDEFINE | typeinfo, NT_DIMENSLICE / dummy, NT_PARAMTABLE_PURE |
| paramtable_elem | / | dimen_slice / keyvalue / exp |
| paramtable | NT_PARAMTABLE_PURE | paramtable_elem + |
| | NT_DECLAREDVARIABLE | no rules, renamed from keyvalue |
| keyvalue | NT_VARIABLEINITIAL(namely NT_KEYVALUE) | variable, NT_EXPRESSION / NT_VARIABLEINITIALDUMMY |
| | NT_VARIABLEINITIAL | variable, exp |
| suite | NT_SUITE | NT_STATEMENT \* |
| stmt | NT_STATEMENT | exp / var_def / compound_stmt / output_stmt / input_stmt / dummy_stmt / let_stmt / jump_stmt / interface_decl |
| | NT_ARRAYBUILDER | (NT_ARRAYBUILDER_LAMBDA / NT_ARRAYBUILDER_LIST) + |
| | NT_ARRAYBUILDER_LAMBDA |  |
| | NT_ARRAYBUILDER_LIST |  |
| type_spec |  | type_name / (type_name, type_selector) |

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
| `VariableDescAttr` | NT_DECLAREDVARIABLE or NT_VARIABLEDEFINE or NT_VARIABLEINTIAL nodes of NT_VARIABLEDEFINE.NT_PARAMTABLE_PURE |
| `FunctionAttr` | NT_FUNCTIONDECLARE |
| `VarialbeAttr` | NT_FUNCTIONDECLARE |



