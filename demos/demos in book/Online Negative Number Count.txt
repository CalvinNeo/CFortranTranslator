program
	implicit none
	real::x, sum = 0.0
	integer::num = 0
	do
		read *, x
		if(x==0) exit
		if(x>0) cycle
		num = num + 1
		sum = sum + x
	end do
	print *, "NUMBER = ", num
	print *, "SUM = ", sum
end program