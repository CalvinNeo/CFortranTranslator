function sum_sum(n) result (isum_result)
	implicit none
	integer::n, isum_result, i
	isum_result = 0
	do i = 1, n
		isum_result = isum_result + 1
	end do
end function
subroutine test_sum
	implicit none
	integer::sum_sum, dummy ! sum_sum is a function, in c++ code its declaration will be removed from main function
	integer::s
	s = sum_sum(100)
	print *, s
end subroutine