#pragma once

namespace for90std {
	template<typename T, typename Return, Return(T::*)()>
	struct func_matcher;

	template<typename T, typename Return, Return(T::*)()const>
	struct const_func_matcher;


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
}