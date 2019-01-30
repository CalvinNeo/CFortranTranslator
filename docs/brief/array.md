# Array
## Fortran-style array and c-style array

1. Fortran array is in **column-first order**
    - for a 2d array, it means when initializing a 1d array by sequence, it follows the order of `a(1)(1) -> a(2)(1) -> a(1)(2) -> a(1)(2)` 
    - similarly, for a nd array, index increase from the left-most to the right-most
    - for details refer to `array_builder` rule in [/src/grammar/for90.y](/src/grammar/for90.y)
2. Fortran array is **1**-indexed array, and it can be negative; each dimension of C++ style array is **0**-indexed array
3. Fortran array **rank**(also called dim in Fortran standard, but called fordim in order to distinguish with C++'s dimension) start from 1, C++ array **dimension** start from 0
	- parameter for most `for-` functions use **rank** other than dimension, in order to be compactable with Fortran source codes.
4. `#define USE_FORARRAY` to use Fortran style array, `#define USE_CARRAY` to use c style array
5. `farray` set no limit to rank, in Fortran90, the maximun rank is 7

## Slice
`struct slice_info<T>` implement for a slice in Fortran

1. `slice_info<T>{T x}`: stands for the scalar `x`, `x` is an index not a range
2. `slice_info<T>{T x, T y}`: `x`, `y` stands for a range of **[x, y]** of default step 1
3. `slice_info<T>{T x, T y, T z}`: `x`, `y`, `z` stands for a range of **[x, y]** step `z`

`template <typename T, int X> auto forslice(const farray<T> & farr, const slice_info<fsize_t>(&tp)[X])` returns an array section by `tp`, an array of `slice_info<fsize_t>`
`tp` has length `X`, represents `slice_info<fsize_t>` data of the first `X` dimension, `X` is not always equal to `farr.dimension`

## farray
`farray` is a multi-dimentional array defined in [/for90std/farray.h](/for90std/farray.h). 
**DON'T** call member function of `farray` directly

1. Construct an array
    - Construct an array by given lower bound and size of each dimension

        ```
        farray<T>(int dimension, Iterator lower_bound, Iterator size)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D])
        ```
    - Construct an array by given lower bound and size of each dimension, and assign an 1d list to the array

        ```
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X])
        ```
    - Implicitly construct an 1d array from a scalar

        ```
        farray<T>(const T & scalar)
        ```
    - Construct an array by given lower bound and size of each dimension, and assign another array's value(**NOT** including shape) to the array

        ```
        farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m)
        ```
    - Construct an array by given lower bound and size of each dimension, and assign another array's value(**AND** shape) to the array

        ```
        farray(const farray<T> & m) // copy constructor
        ```

2. Assign value to an array without chaning shape

    ALL these functions do **NOT** change the shape of `farr` itself. They all call `operator=` by implemetation.
    - Assign from a list: 

        ```
        farr = make_init_list(Iterator list_begin, Iterator list_end)
        farr = make_init_list(const T(&values)[X])
        ```
    - Assign from implied `do`-loop
        Important: `from` and `to` arguments do **NOT** indicate the shape of farr. they indicate the implied `do`-loop will loop from `from[dimension]` to `to[dimension]` in each dimension
        
        ```
        farr = make_init_list(const fsize_t(&from)[D], const fsize_t(&size)[D], F f)
        ```
    - Assign from a scalar

        ```
        farr = make_init_list(const T & scalar)
        ```
    - Assign from a list of a scalar repeated by `repeat` times

        ```
        farr = make_init_list(int repeat, const T & scalar)
        ```
    - Assign from a `farray`
        This function will return exactly a copy of m

        ```
        farr = make_init_list(const farray<T> & m)
        ```
    - Assign from a list of `farray`s
        All `farrs` must be of the same type `farray<T>`

        ```
        forconcat(const farray<T>(&farrs)[X])
        ```
        
3. Assign value to an array and change its shape

    Set `farr` 's shape and value equal to given argument `x`

    ```
    farr.copy_from(const farray<T> & x)
    ```
4. Create a view from an array
    A view `varr` of array `farr` is another `farray<T>`, it shares physical storage with original `farr`. if `farr` is destructed, accessing data of `varr` us undefined behaviour

    The only way to create a view is by several constructor, and pass optional argument `isview = true`

    ```
	farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m, bool isview = false)
    ```

5. Array traits

|Function|Usage|
|:-:|:-:|
|`.flatsize()`|Get total number of elements in the array|
|`forconcat(x, y)`|Concat array x and y|

## Intrinsic array functions

|Fortran|C++| Explanation |
|:-:|:-:|:-:|
|get|`a(1, 2, 3, 4)` or `a({1, 2, 3, 4})` or `a[{1, 2, 3, 4}]` or `a(1)(2)(3)(4)`| |
|forslice|`a[{{1, 3, 1}, {1, 4}, {5}, {}}]` or `forslice(a, {{1, 3, 1}, {1, 4}, {5}}, {})`| |
|reshape|forreshape| |
|spread|not implemented yet| |
|transpose|fortranspose| Fortran standard only defined rank 2 situation, for this implementation, the result will be a array with reversed rank |
|maxloc, minloc, maxval, minval|formaxloc, forminloc, formaxval, formaxloc| |
|sum, product|forsum, forproduct| call `operator+` and `operator*` |
|any, all, count|forany, forall, forcount| `forall` is **NOT** Fortran95's `forall`, which is renamed to `forforall` |
|pack, unpack|not implemented yet| |
|merge|formerge| |
|size, lbound, ubound|forsize, forlbound, forubound| |
|matmul, dot_product|not implemented yet| |
|eoshift, cshift|not implemented yet| |

### Inside farray
Though Fortran-style array is different from c-style array, only need to consider relationship with flattened 1d array
1. Handle a named array: [/src/target/gen_vardef.cpp](/src/target/gen_vardef.cpp)
2. Define a array variable: [/src/target/gen_vardef.cpp](/src/target/gen_vardef.cpp)
3. Handle array slice: [/src/target/gen_callable.cpp](/src/target/gen_callable.cpp)
