subroutine T_variable_decl()
	implicit integer(a-c) ! a is INTEGER by implicit(originally, a is REAL)
	a = 1; c = 3
	dimension arr(10), j	
	character s1*3
	character*3 s2
	integer int2 = int1 + 1
	integer(kind=2)::int1 = int(int2)
	integer, parameter, save::int3 = 10
	
	integer, intent(in)::a2 = c_implicit
	integer, intent(out)::a3 = c_implicit_arr(3)
	read *, a1, a(1)
	fun(b + 3)
	arr2(1) = arr1(1)
	if (arr3(i,j).le.arr2(i)) then
		a = a .neqv. c
		a = a .eqv. c
		a = a .ne. c
	end if
end subroutine