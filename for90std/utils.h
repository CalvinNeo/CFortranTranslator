/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#pragma once
#include <tuple>
#include <functional>

// WARNING: DEPRECATED
#if (defined(_MSC_VER) && _MSC_VER <= 1900)
namespace std {
	template<class F, class...Args>
	struct is_callable
	{
		template<class U> static auto test(U* p) -> decltype((*p)(std::declval<Args>()...), void(), std::true_type());
		template<class U> static auto test(...) -> decltype(std::false_type());

		static constexpr bool value = decltype(test<F>(0))::value;
	};
}
#endif

_NAMESPACE_FORTRAN_BEGIN

_NAMESPACE_HIDDEN_BEGIN

#define CHECK_AND_SET(A, INITIAL) if (!A.inited()) { \
		A = INITIAL; \
	}

template<typename T, typename Return, Return(T::*)()>
struct func_matcher;

template<typename T, typename Return, Return(T::*)()const>
struct const_func_matcher;
	
/*****************
*	create a struct `is_typename` 
*	struct `is_typename` test whether type of a variable matchs signature given by `MATCHERNAME`
* e.g.
* ```
*	template <typename T>
*	using for1array_matcher = const_func_matcher<T, fsize_t, &(T::size)>*;
*
*	MAKE_FUNC_TEST(for1array, for1array_matcher)
* ```
*****************/
#define MAKE_FUNC_TEST(TYPENAME, MATCHERNAME) struct is_##TYPENAME { \
	template<typename T> \
	constexpr static bool test(MATCHERNAME<T>) {\
		return true; \
	} \
	template<typename T> \
	constexpr static bool test(...){ \
		return false; \
	} \
};

template <typename T>
struct function_traits
	: public function_traits<decltype(&T::operator())>
{};
// For generic types, directly use the result of the signature of its 'operator()'

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
{
	// we specialize for pointers to member function
	enum { arity = sizeof...(Args) };
	// arity is the number of arguments.
	typedef ReturnType result_type;
	template <size_t i>
	struct arg
	{
		typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
		// the i-th argument is equivalent to the i-th tuple element of a tuple
		// composed of those arguments.
	};
};

#if (defined(__GNUC__) && __GNUC__ <= 5)
#define __MA_STR(x) __MA_STR1(x)
#define __MA_STR1(x) #x
#define invoke __invoke
#endif

template <typename T>
class for_reference_wrapper {
public:
	// types
	typedef T type;

	// construct/copy/destroy
	for_reference_wrapper(T& ref) noexcept : _ptr(std::addressof(ref)) {}
	for_reference_wrapper(T&&) = delete;
	for_reference_wrapper(const for_reference_wrapper&) noexcept = default;
	for_reference_wrapper() {}

	// assignment
	for_reference_wrapper& operator=(const for_reference_wrapper& x) noexcept = default;

	// access
	operator T& () const noexcept { return *_ptr; }
	T& get() const noexcept { return *_ptr; }

	void change(T& ref) noexcept {
		_ptr = std::addressof(ref);
	}

	template< class... ArgTypes >
	typename std::result_of<T&(ArgTypes&&...)>::type
		operator() (ArgTypes&&... args) const {
		return std::invoke(get(), std::forward<ArgTypes>(args)...);
	}

private:
	T* _ptr;
};


template <int I>
struct Int2Type
{
	enum { value = I };
};

template <typename F>
struct _foreach_tuple_runnable
{
	F func;
	_foreach_tuple_runnable(F f) : func(f){
		
	}
	template<typename T>
	void operator()(T & t) const
	{
		func(t);
	}
	template<typename T>
	void operator()(const T & t) const
	{
		func(t);
	}
};

template<typename F, typename _Tuple, std::size_t ... Is >
size_t _foreach_tuple_impl(F f, const _Tuple & tup, std::index_sequence<Is...>)
{
	int dummy[] = { (f(std::get<Is>(tup)), 0)... };
	return sizeof(dummy);
}

template<typename F, typename _Tuple, std::size_t ... Is >
size_t _foreach_tuple_impl(F f, _Tuple & tup, std::index_sequence<Is...>)
{
	int dummy[] = { (f(std::get<Is>(tup)), 0)... };
	return sizeof(dummy);
}

_NAMESPACE_HIDDEN_END

template <typename F, typename ... Args>
void foreach_tuple(const std::tuple<Args...> & tup, F f) {
	_foreach_tuple_impl(for90std::_foreach_tuple_runnable<F>(f), tup, std::index_sequence_for<Args...>{});
}

template <typename F, typename ... Args>
void foreach_tuple(std::tuple<Args...> & tup, F f) {
	_foreach_tuple_impl(for90std::_foreach_tuple_runnable<F>(f), tup, std::index_sequence_for<Args...>{});
}

inline char to_lower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
	{
		return (char)(ch - 'A' + 'a');
	}
	return ch;
};

#define FW(X) std::move(X)
#define INOUT(X) std::move(X)
#define IN(X) X
#define OUT(X) X
#define SS(X) std::string(X)
_NAMESPACE_FORTRAN_END