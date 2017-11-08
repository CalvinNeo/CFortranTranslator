# for1array
`for1array` is a 1-dimentional dynamic array, and now deprecated

1. initialize an array
    ways to initialize an for1array
    - with `f1a_init(array, lower_bound, size, values)` to init `array`, in which
        1. `array` is reference of a defined array you want to init
        2. `lower_bound` is the lower bound of every dimension(from left to right) in this array
        3. `size` is the size of every dimension in this array
        4. `values` is `std::vector` of initialize list
    - with `f1a_gen` and return a copy directly
    - with constructor `for1array(lower_bound, size, values)`
    - with `f1a_init_hiddendo` in [/for90std/for1array.h](/for90std/for1array.h) to init array by implied do-loop

2. array traits

|function|usage|
|:-:|:-:|
|`f1a_flattern(array)`|get flatterned size of an array|
|`f1a_gettype<T>::type`|get innermost type of an array|
|`f1a_flatmap(array, begin_iterator, end_iterator, lambda)`|return a vector of all elements mapped by function `lambda` in fortran/C++ order|