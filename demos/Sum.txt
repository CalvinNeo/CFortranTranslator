function isum(n) result (isum_result)
	implicit none
	integer::n, isum_result, i
	isum_result = 0
	do i = 1, n
		isum_result = isum_result + 1
	end do
end function
program
	implicit none
	integer::isum, dummy ! isum is a function, in c++ code its declaration will be removed from main function
	integer::s
	s = isum(100)
	print *, s
end program