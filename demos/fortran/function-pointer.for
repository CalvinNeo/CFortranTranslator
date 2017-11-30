function T_function_pointer_sum(x,y) result (sum_result)
	integer,intent(in)::x, y
	integer::sum_result
	sum_result = x + y
end function
function T_function_pointer_minu(x,y) result(minu_result)
	integer,intent(in)::x, y
	integer::minu_result
	minu_result = x - y
end function
subroutine T_function_pointer_proc(a, b, fun)
	interface
		function fun(x,y) result (fun_result)
			integer,intent(in)::x, y
			integer::fun_result
		end function
	end interface
	integer,intent(in)::a, b
	print *, fun(a, b) 
end subroutine
subroutine T_function_pointer
	implicit none
	interface
		function T_function_pointer_sum(x,y) result (sum_result)
			integer,intent(in)::x, y
			integer::sum_result
		end function
		function T_function_pointer_minu(x,y) result(minu_result)
			integer,intent(in)::x, y
			integer::minu_result
		end function
	end interface
	!integer, parameter::const_int
	integer::a, b
	read *, a, b
	call T_function_pointer_proc(a, b, T_function_pointer_sum)
	call T_function_pointer_proc(a, b, T_function_pointer_minu)
end subroutine
