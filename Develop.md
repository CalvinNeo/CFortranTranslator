# Develop

## Debug
### Configurations
1. the **Debug** mode accept command line arguments `argv[]` which is set to default values in VS project configurations
2. the **Develop** mode invoke the function `void debug()` which is defined in [develop.cpp](/develop.cpp)
3. the **Release** is same as the **Debug** mode except for default values which is not set

## grammar
Currently, grammar are defined in [/src/grammar/for90.l](/src/grammar/for90.l) (and it will be replaced by a simpler non-flex-generated [/src/grammar/simple_lexer.cpp](/src/grammar/simple_lexer.cpp) ) and [/src/grammar/for90.y](/src/grammar/for90.y)

### tokenizer(by flex)
`#define USE_LEX` to enable
parser calls `int yylex(void)` to get one token at a time. 

### tokenizer(by simple_lexer)
`#undef USE_LEX` to enable
because can be continued in tokenizer's level, now a non-generated lexer simple_lexer substitute for flex tokenizer(for90.l).

### parser
1. `YY2ARG` get a `ParseNode &` from bison's arguments `$n`(namely `ParseNode *`)
2. `RETURN_NT` generates a bison's result `$$`(namely `ParseNode *`) from  `ParseNode`, `RETURN_NT` does opposite work of `YY2ARG`
3. `CLEAN_RIGHT` clear all bison's arguments

### extend grammar

1. declare new %token in [/src/grammar/for90.y](/src/grammar/for90.y)
2. add pattern of this %token in [/src/grammar/for90.l](/src/grammar/for90.l)
3. add rules related to the %token in [/src/grammar/for90.y](/src/grammar/for90.y)
4. update bytecodes and grammar tokens in [/src/parser/Intent.h](/src/parser/Intent.h)
5. register keyword in [/src/parser/tokenizer.cpp](/src/parser/tokenizer.cpp)(if this token is keyword)
6. if this keyword are made up of more than 1 word, reduction conflicts may be caused between the keyword and its prefix,
    - if rule's keyword are all charaters like `(/`, just add a regex to for90.l
    - if rule's keyword are all words like `else if`, update forward1 in [/src/parser/tokenizer.cpp](/src/parser/tokenizer.cpp)

        the first part don't need to be registered to keyword
7. update translation rules in [/src/target/gen_config.h](/src/target/gen_config.h.h)

### extend new intrinsic function

1. implement this function and included it in [for90std/for90std.h](/for90std/for90std.h)
	- if a parameter is **optional** in fortran, wrap it with `foroptional`, and log all parameters of this function in [/gen_config.cpp](/gen_config.cpp)
    - if the parameter is the **only** optional parameter, can omit `foroptional` wrapper
2. update `funcname_map` in [/src/target/gen_config.cpp](/src/target/gen_config.cpp) if necessary

## C++ target code
### lazy generate
when using immediate code generate(or using lazy gen), upper level non-terminal can channge generated codes by low level non-terminal, so `gen_` functions pass `ParseNode &` other than `const ParseNode &`:

1. all `regen_` function will change its input `ParseNode &`
2. all `gen_` function will not change its input `const ParseNode &`

due to fortran's implicit declaration, code above `stmt` level, including `function_decl`, `program` will be regenerated after the whole AST is builded by following steps:
1. `gen_fortran_program` handles `program`, `function_decl`
2. `regen_suite` handles `suite` rule
3. `regen_common` generates `common` statement code

### name mapping
many type names and function names are mapped, they are defined in in [/src/target/gen_config.h](/src/target/gen_config.h)
their replacement occur in following stages:

1. mappings defined in `pre_map` is replacement in tokenizing stage in [/src/grammar/for90.l](/src/grammar/for90.l)

2. function name mapping in `funcname_map` is replacement in parse stage in function `gen_function_array` [/src/target/gen_callable.cpp](/src/target/gen_callable.cpp)

### array

**though fortran-style array is different from c-style array, only need to consider relationship with flatterned 1d array**

1. for1array is a 1d dynamic array defined in [/for90std/for1array.h](/for90std/for1array.h), farray is a nd array defined in [/for90std/farray.h](/for90std/farray.h)
2. functions and arrays are generated in normal order in [/src/target/gen_callable.cpp](/src/target/gen_callable.cpp). 
3. array declaration is in [/src/target/gen_vardef.cpp](/src/target/gen_vardef.cpp)
4. overload `operator()` and  `operator[]` so `a(x, y, z)`(fortran-style) is same as `a(x)(y)(z)`(c-style) where x,y,z are `slice_info` or index
5. slice selections are handled in [/src/target/gen_callable.cpp](/src/target/gen_callable.cpp). 


### variable definition

#### 3-phase strategy
1. Step 1:
    1. when encounter a `UnknownVariant`(in `regen_exp`, when the AST is building):

        all variables, **once** reached by the parser and not registered to symbol table `gen_context().variables` yes, will be addded to symbol table, which includes: 

            1. add `VariableInfo` node 
            2. `.type` is deduced by its name in `gen_implicit_type`
            3. `.implicit_defined` = true
            4. `.vardef` is pointer(!= nullptr) to a `ParseNode` node. 
            5. `commonblock_name` = `""`, `commonblock_index` = `0`.
        VARIABLES ARE REGISTERED TO SYMBOL TABLE IN THIS CONDITION MOSTLY

        call `check_implicit_variable`, it will register this variable to `gen_context().variables`, if this variable is implicit defined, not declared as case 2.
    2. when encounter `NT_COMMONBLOCK`(occur in `regen_stmt`, after the AST is built):

        THIS IS AN EXPLICIT DEFINITION

        call `regen_common` to log `VariableInfo` to `gen_context().variables`, mark `commonblock_name` and `commonblock_index`
    3. when encounter `NT_VARIABLEDEFINESET` and `NT_VARIABLEDEFINE`(in `regen_stmt`, after the AST is built):

        THIS IS AN EXPLICIT DEFINITION

        these two nodes are generated in [/grammar/for90.y](/grammar/for90.y), generate `NT_VARIABLEDEFINESET` and `NT_VARIABLEDEFINE`
        register(add, only happen if the variable is never used, or **mainly modify/overwrite**) corresponding `VariableInfo` to symbol table.

2. Step 2:

    the first loop of `gen_joined_declarations`

    enumerate all `VariableInfo` of this suite several times UNTIL ALL VARIABLES ARE GENERATED(`.generate` = true), call `regen_vardef`

3. Step 3:

    the second loop of `gen_joined_declarations`

    join generated codes of Step 2, depending whether this variable is common block

#### interface
1. all items in interface are firstly variables, so it will be
    1. registered by `add_variable` under `finfo->local_name`
    2. its `local_name` will be exactly the item's name

2. all items in interface can also considered to be function(with no function body), so it will be
    1. registered by `add_function` under `get_context().current_module`
    2. its `local_name` will be `finfo->local_name + "@" + the item's name`

### function declaration


## Parse Tree(AST)
all parse tree nodes are defined in [/src/Intent.h](/src/Intent.h) with an `NT_` prefix
### struct ParseNode
1. fs:
	* fs.CurrentTerm.what: immediate-generated code, generated from child's `fs.CurrentTerm.what`, or from other infomations
	* fs.CurrentTerm.token: refer [/src/Intent.h](/src/Intent.h)
2. child
3. attr:
	attrs including
	* FunctionAttr
	* VariableDescAttr
4. father: pointer to parent node

### nodes

child ParseNode may also be referred when generating upper level ParseNode, so do not change child index of:

1. `NT_VARIABLE_ENTITY`: referred in `function_decl`
2. `NT_FUNCTIONDECLARE`: can represent interface, referred in `paramtable` and `function_decl`

### rules explanation
#### argtable, dimen_slice, pure_paramtable
`argtable`, `dimen_slice`, `pure_paramtable` are a list of different items seprated by `,`
##### constitution
- `argtable` is a list of `exp`(ref `is_exp()`)
- `dimen_slice` is a list of `slice`(`NT_SLICE`) or `exp`
- `pure_paramtable` is a list of `keyvalue`(`NT_KEYVALUE`/`NT_VARIABLE_ENTITY`) or `slice` or `exp`
    - `NT_KEYVALUE.get_what()` will be regenerated in `gen_function_array` in [/src/target/gen_callable.cpp](/src/target/gen_callable.cpp)
- `paramtable` is `argtable` or `dimen_slice` or `pure_paramtable`
##### promotion
- `argtable` + `slice` = `dimen_slice`, all elements in `argtable` will be promote to `slice`(with one child)
- `argtable` + `keyvalue` = `pure_paramtable`, all elements in `argtable` will be promote to `keyvalue`
- `dimen_slice` + `keyvalue` or `pure_paramtable` + `slice` is illegal
	
#### type_spec, type_name, type_selector

>	(3) The suffix "- spec" is used consistently for specifiers, such as keyword actual arguments and
>		input / output statement specifiers.It also is used for type declaration attribute specifications(for
>			example, "array - spec" in R512), and in a few other cases.

>	(4) When reference is made to a type parameter, including the surrounding parentheses, the term
>		"selector" is used.See, for example, "length - selector"(R507) and "kind - selector"(R505).

you can use `REAL(x)` to get the float copy of x, however, you can also use `REAL(kind = 8)` to specify a floating number which is same to `long double` rather than `double`, so it may cause conflict. 
To specify, `type_name` is like `INTEGER` and a `type_spec` is like `INTEGER(kind = 4)`, `type_nospec` can be head of `callable`, `type_spec` is not.

#### array builder
- `NT_FUCNTIONARRAY` and `NT_HIDDENDO` will **NOT** be promote to `NT_EXPRESSION`
- `NT_HIDDENDO` has 4 child elements: lambda, indexer, from, to. refer `gen_hiddendo` in [/src/target/gen_do.cpp](/src/target/gen_do.cpp)

#### stmt, suite
- `stmt` is statement end with ';' or '\n'
- `suite` is set of `stmt`


### production rules illustration

|rules|left NT|right(included)|
|:-:|:-:|:-:|
| fortran_program | root | wrappers |
| wrappers |  | wrapper + |
| wrapper | / | function_decl / program |
| function_decl | NT_FUNCTIONDECLARE |  |
| var_def | NT_VARIABLEDEFINE/NT_DECLAREDVARIABLE |   |
| keyvalue | NT_VARIABLE_ENTITY(namely NT_KEYVALUE) | variable, NT_EXPRESSION / NT_VARIABLEINITIALDUMMY |
| | NT_VARIABLE_ENTITY | variable, exp |
| suite | NT_SUITE | stmt |
| stmt |  | exp / var_def / compound_stmt / output_stmt / input_stmt / dummy_stmt / let_stmt / jump_stmt / interface_decl |
| | NT_ARRAYBUILDER_LIST | (NT_HIDDENDO / NT_FUNCTIONARRAY / exp)  |
| type_spec |  | type_name / (type_name, type_selector) |

### Symbols
all variables(including `commom` block) and functions is now logged in [/src/Variable.h](/src/Variable.h) and [/src/Function.h](/src/Function.h) by
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

