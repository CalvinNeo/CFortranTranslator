# Target code
See [/src/grammar/for90.y](/src/grammar/for90.y) for all accepted grammar

## Fortran's special grammar

1. You can rename keyword parameter in `interface` block
2. You can use anonymous grammar structures
3. Declaration/specification is not forced before any other statements
    According to Fortran standard, declaration/specification(sudh as variable declarations and interfaces) statements must before all executable constructs(2.3.1)
    However, there's no such restriction in this translator 

### implied-do
All implied-do will be translated in to struct `ImpliedDo`:
`ImpliedDo(int D, fsize_t * fr, fsize_t * to, F func )`

- This implied-do loop has `D` layers, the outmost layer is layer 0, the innermost layer is layer (D - 1)
- Layer `i` loops in range `[fr[i], to[i]]`
- `F func` should have signature like `[&](fsize_t * current){return X}`, where `current` points to a size `D` array giving current index of each loop layer

### io-implied-do

See [/src/target/gen_io.cpp](/src/target/gen_io.cpp)

> R916 io-implied-do is ( io-implied-do-object-list , io-implied-do-control )
> R917 io-implied-do-object is input-item or output-item
> R918 io-implied-do-control is do-variable = scalar-numeric-expr , scalar-numeric-expr [ , scalar-numeric-expr ]

io-implied-do will also be translated into a `ImpliedDo`, for details of this struct ref implied-do
```
auto make_implieddo(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func);
auto make_implieddo(fsize_t * _lb, fsize_t * _to, F func);
```
For input function like `forreadfree` and `forread`, the `io-implied-do-object-list` must be a *variable*(R914), so `F f` must return left-value.

For output function like `forwritefree` and `forwrite`, the `io-implied-do-object-list` must be a *expr*(R915), so `F f` can return anything.

Here is a simple Fortran's io-implied-do demo
```
WRITE(2,*) ((A(I,J),B(I),J=1,i),I=2,10)
```
And this will be transformed into
```
forwritefree(get_file(2), make_implieddo({2}, {10}, [&](const fsize_t * current_i){
		return [&](fsize_t i){
				return make_implieddo({i, 1}, {i, i}, [&](const fsize_t * current_j){
						return [&](fsize_t i, fsize_t j){
								return make_iostuff(make_tuple(a(INOUT(i), INOUT(j)), b(INOUT(i))));
						}(current_j[0], current_j[1]);
				});
		}(current_i[0]);
}));
```

To understand this code, several stuffs are worth learning:

#### IOStuff
`IOStuff` wraps a list of `input-item-list` or `output-item-list` inside an io-implied-do. 

`IOStuff` can be built from a `std::tuple`, with `make_iostuff`
```
template<typename ... Types>
IOStuff<Types...> make_iostuff(const std::tuple<Types...> & _tp) {
	return IOStuff<Types...>(_tp);
}
```

Read/write a `IOStuff` is to read/write every element of `IOStuff` in order

#### IOFormat
IOFormat has basic form, `IOFormat(const std::string & s, int rev_start, int rev_end)`, in which `rev_start` and `rev_end` is optional.

- `formatter` is generated from Fortran's format

- `reversion_start` is a value computed by compiler, it shows index of beginning of the repeat string (ref. 10.3), while `reversion_end` shows this end of repeat string
```
WRITE(2,"(I)\n") 1,2,3,4,5
```
Will be translated into
```
forwrite(get_file(2), IOFormat{"%d", 0, 2}, 1, 2, 3, 4, 5);
```

## Array
See [brief/array.md](brief/array.md)

## Types
### Type mapping

|Fortran|C++|
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

### Type casting

|Fortran|C++|
|:-:|:-:|
|`INTEGER()`|`to_int`|
|`REAL()`|`to_double`|
|`FLOAT()`|`to_double`|
|`LOGICAL()`|`to_bool`|
|`COMPLEX()`|`to_forcomplex`|
|`CHAR()`|`to_string`|


## Variables
1. Variable names in Fortran are **case-insensitive**, and their names will be translated into lower case.
2. Variable names that conflicts with C++ keywords and standard library functions will be renamed with a `R_` surfix

### Common block

Common blocks, can be accessed by any of the scoping units in an executable program

| Common statement | C++ |
|:-:|:-:|
|`INTEGER::A; COMMON A`| `int & a = G.a` |
|`INTEGER::B; COMMON /COMMON_NAME/ B`| `int & b = COMMON_NAME.b` |
|`COMMON C`| `T & c = G.c` |
|`COMMON /COMMON_NAME/ D`| `T & c = COMMON_NAME.c` |

Where T conform to Fortran's implicit type deduction(refer Fortran 77 standard support for detail)
Each commom block will be create a singleton struct
```
struct{
    T1 _1;
    T2 _2;
    /* common variables */
}COMMON_NAME;
```
If this common block is an unamed block, `COMMON_NAME` is by default `G`


## Subroutines and functions
### Parameter list
1. Remove all definition of local variables which is also in parameter list
2. Optional parameter: instead of c-style optional parameter, wrap optional parameters with `foroptional<T>`, function `forpresent` functions as `present` function in Fortran90
3. Keyword/named parameter: C++ don't support keyword parameters, all keyword parameter will be reorganized in normal paramtable

### Interface
"functions" delcared in interface will be generated as a `std::function<...>` clause

For example
```
subroutine proc(a, b, fun)
	interface
		function fun(x,y) result (fun_result)
			integer,intent(in)::x, y
			integer::fun_result
		end function
	end interface
	integer,intent(in)::a, b
	print *, fun(a, b) 
end subroutine
```
Will be translated into

```
void proc(const int & a, const int & b, std::function<int(const int &, const int &)> fun)
{
	forprintfree(fun(INOUT(a), INOUT(b)));
	return ;
}

```

### Attribute specification statements

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

The `intent`, `parameter`, `save` specification generate codes following rules:

|Intent|Parameter|Save|C++|Argument passing pattern|
|:-:|:-:|:-:|:-:|:-:|
|/|/|/|`T &&`| `INOUT(v)` |
|any|/|save|`static`| `INOUT(v)` |
|any|parameter|save|`static const`| `INOUT(v)` |
|any|parameter|/|`const T`| `INOUT(v)` |
|in|any|/|`const T &`| `INOUT(v)` |
|out|any|/|`T &`| `INOUT(v)` |
|inout|any|/|`T &&`| `INOUT(v)` |

By implementation, `INOUT(v)` is simply `std::move(v)`, it just convert a `T &` to `T &&`, so it can be accepted by a `T &&` function. You must make sure `v` will not be destructed before you no long need it and `v` is an left value before you use `&(INOUT(v))`.

Currently, all arguments are passed by pattern `INOUT`

## Iperators
1. According to R311, defined operators should have NO digits in their names

    This rule is necessary, considering `2.e2.0` is float, not a operator `e2` with two operands `2` and `0`

### Intrinsic operators

| Fortran intrinsic operators | C++ |
|:-:|:-:|
| `.and.` | `&&` |
| `.or.` | `||` |
| `.eqv.` | `!(A^B)` |
| `.neqv.` | `^` |
| `.eq.` | `==` |
| `.neq.` | `!=` |
| `.gt.` | `>` |
| `.ge.` | `>=` |
| `.lt.` | `<` |
| `.le.` | `<=` |

# Fortran 77 standard support
## Fixed form
CFortranTranslator can accept both fixed form and free form code.

CFortranTranslator **WON'T** handle fixed/free part of the code respectively

1. Comments(ref 3.3.2.1 Fixed form commentary)

    Under any condition lines begin with `C` or `c` are comments

2. Continuation(ref 3.3.2.3 Fixed form statement continuation)

    THIS DO NOT CONFORM TO FORTRAN90 STANDARD

    Under any condition lines is continuation when
    1. Begin with **5** **BLANKS**(not in standard) and position 6 is not blank, **or**,
    2. (Not in standard)Begin with **1** **TAB**(in this case 1 TAB can consider to be equal to 5 blanks) and the next character is not blank or TAB

## Implicit variables
All implicit variables will have their definitions generated in target code.
Because of the [3-phase strategy](/docs/Develop.md)

### Implicit variables in parameters list
Not all parameters in a `paramtable` need to be declared explicitly in the function body, if the parameter
1. Used in both `paramtable` and the function body

    Fortran 90 standard
2. Used only in `paramtable`

    Implicit definition conforming to Fortran77 standard

## Subprogram
### Attribute specification statements
Fortran77 does not specify intent, target code will follow the strategy:

|Fortran|C++|
|:-:|:-:|
|literals(right value)|`T &&`|
|left value|`T &`|

# Implementation of Fortran's inherent function
## Math

|Fortran|C++|
|:-:|:-:|
|`min`|`min_n`|
|`max`|`max_n`|

## IO
### Unit id mapping

|Fortran|C++|
|:-:|:-:|
|*|`stdin`/`stdout`|
|5|`stdin`|
|6|`stdout`|
|id|`get_file(id)`|
|string|` `|

### File function

|Fortran|C++|
|:-:|:-:|
|`open`|`foropenfile`|
|`close`|`forclosefile`|
|`rewind`|`forrewind`|
|`backspace`|`forbackspace`|

### IO format

|Fortran|C++|
|:-:|:-:|
|`*` and `(*,*)`|`forscanfree`/`forprintfree`|
|`(*,formatter)`|`forscan`/`forprint`|
|`(device_id,*)`|`forreadfree`/`forwritefree`|
|`(device_id,formatter)`|`forread`/`forwrite`|

