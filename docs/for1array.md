# For1array
`for1array` is a 1-dimentional dynamic array, and now deprecated. Do NOT use it.

1. Initialize an array
    Ways to initialize an for1array
    - With `f1a_init(array, lower_bound, size, values)` to init `array`, in which
        1. `array` is reference of a defined array you want to init
        2. `lower_bound` is the lower bound of every dimension(from left to right) in this array
        3. `size` is the size of every dimension in this array
        4. `values` is `std::vector` of initialize list
    - With `f1a_gen` and return a copy directly
    - With constructor `for1array(lower_bound, size, values)`
    - With `f1a_init_hiddendo` in [/for90std/for1array.h](/for90std/for1array.h) to init array by implied do-loop

2. Array traits

|Function|Usage|
|:-:|:-:|
|`f1a_flattern(array)`|Get flatterned size of an array|
|`f1a_gettype<T>::type`|Get innermost type of an array|
|`f1a_flatmap(array, begin_iterator, end_iterator, lambda)`|Return a vector of all elements mapped by function `lambda` in fortran/C++ order|