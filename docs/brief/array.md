# array
## fortran-style array and c-style array

1. fortran store array in a **column-first order**
    - for a 2d array, it means when initializing a 1d array by sequence, it follows the order of `a(1)(1) -> a(2)(1) -> a(1)(2) -> a(1)(2)` 
    - similarly, for a nd array, rank 1 increase by 1 first, when rank 1 equals to upper bound it wrap back and rank 2 increase by 1..., rank n increase the last.
    - for details refer to `array_builder` rule in [/src/grammar/for90.y](/src/grammar/for90.y)
2. fortran array is **1**-indexed array, and it can be negative; each dimension of C++ style array is **0**-indexed array
3. fortran array **rank** start from 1, C++ array **dimension** start from 0, parameter for most `for-` functions are index of rank, though they are called "dim" in standard, they are called `fordim` in this implementation
4. `#define USE_FORARRAY` to use fortran style array, `#define USE_CARRAY` to use c style array
5. `farray` set no limit to rank, in fortran90, the maximun rank is 7

## slice
`struct slice_info<T>` implement for a slice in fortran

1. `slice_info<T>{T x}`: stands for the scalar `x`, `x` is an index not a range
2. `slice_info<T>{T x, T y}`: `x`, `y` stands for a range of **[x, y]** of default step 1
3. `slice_info<T>{T x, T y, T z}`: `x`, `y`, `z` stands for a range of **[x, y]** step `z`

`template <typename T, int X> auto forslice(const farray<T> & farr, const slice_info<fsize_t>(&tp)[X])` returns an array section by `tp`, an array of `slice_info<fsize_t>`
`tp` has length `X`, represents `slice_info<fsize_t>` data of the first `X` dimension, `X` is not always equal to `farr.dimension`

## farray
`farray` is a multi-dimentional valarray

**DON'T** call member function of `farray` directly

1. construct an array
    - construct an array by given lower bound and size of each dimension

        ```
        farray<T>(int dimension, Iterator lower_bound, Iterator size)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D])
        ```
    - construct an array by given lower bound and size of each dimension, and assign an 1d list to the array

        ```
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], Iterator begin, Iterator end)
        farray<T>(const size_type(&lower_bound)[D], const size_type(&size)[D], const T(&values)[X])
        ```
    - implicitly construct an 1d array from a scalar

        ```
        farray<T>(const T & scalar)
        ```
    - construct an array by given lower bound and size of each dimension, and assign another array's value(**NOT** including shape) to the array

        ```
        farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m)
        ```
    - construct an array by given lower bound and size of each dimension, and assign another array's value(**AND** shape) to the array

        ```
        farray(const farray<T> & m) // copy constructor
        ```

2. assign value to an array

    ALL these functions do **NOT** change the shape of `farr` itself. They practically called `operator=`
    - assign from a list: 

        ```
        farr = make_init_list(Iterator list_begin, Iterator list_end)
        farr = make_init_list(const T(&values)[X])
        ```
    - assign from implied `do`-loop
        important: `from` and `to` arguments do **NOT** indicate the shape of farr. they indicate the implied `do`-loop will loop from `from[dimension]` to `to[dimension]` in each dimension
        
        ```
        farr = make_init_list(const fsize_t(&from)[D], const fsize_t(&size)[D], F f)
        ```
    - assign from a scalar

        ```
        farr = make_init_list(const T & scalar)
        ```
    - assign from a list of a scalar repeated by `repeat` times

        ```
        farr = make_init_list(int repeat, const T & scalar)
        ```
    - assign from a `farray`
         this function will return exactly a copy of m

         ```
        farr = make_init_list(const farray<T> & m)
        ```
    - assign from a list of `farray`s
        all `farrs` must be of the same type `farray<T>`

        ```
        forconcat(const farray<T>(&farrs)[X])
        ```
        
3. assign value to an array and change its shape

    set `farr` 's shape and value equal to given argument `x`

    ```
    farr.copy_from(const farray<T> & x)
    ```
4. create a view from an array
    a view `varr` of array `farr` is another `farray<T>`, it shares physical storage with original `farr`. if `farr` is destructed, accessing data of `varr` us undefined behaviour

    the only way to create a view is by several constructor, and pass optional argument `isview = true`

    ```
	farray(const size_type(&lower_bound)[D], const size_type(&size)[D], const farray<T> & m, bool isview = false)
    ```

5. array traits

|function|usage|
|:-:|:-:|
|`.flatsize()`|get total number of elements in the array|
|`forconcat(x, y)`|concat array x and y|

## intrinsic array functions

|fortran|C++| explanation |
|:-:|:-:|:-:|
|get|`a(1, 2, 3, 4)` or `a({1, 2, 3, 4})` or `a[{1, 2, 3, 4}]` or `forslice(a, {1, 2, 3, 4})`| |
|forslice|`a[{{1, 3, 1}, {1, 4}, {5}, {}}]` or `forslice(a, {{1, 3, 1}, {1, 4}, {5}}, {})`| |
|reshape|forreshape| |
|spread|not implemented yet| |
|transpose|fortranspose| fortran standard only defined rank 2 situation, for this implementation, the result will be a array with reversed rank |
|maxloc, minloc, maxval, minval|formaxloc, forminloc, formaxval, formaxloc| |
|sum, product|forsum, forproduct| call `operator+` and `operator*` |
|any, all, count|forany, forall, forcount| `forall` is **NOT** fortran95's `forall`, which is renamed to `forforall` |
|pack, unpack|not implemented yet| |
|merge|formerge| |
|size, lbound, ubound|forsize, forlbound, forubound| |
|matmul, dot_product|not implemented yet| |
|eoshift, cshift|not implemented yet| |
