
subroutine test_online_negative_number_count
	implicit none
	real::x, sum = 0.0
	integer::num = 0
	do
		read *, x
		if(x==0) then exit
		if(x>0) then cycle
		num = num + 1
		sum = sum + x
	end do
	print *, "NUMBER = ", num
	print *, "SUM = ", sum
end subroutine