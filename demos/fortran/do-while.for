subroutine T_do_while
	implicit none
	integer::x, n, i = 0, m = 0
	real::aver, sum = 0
	read *, n
	do while(i < n)
		read *, x
		if(mod(x,4) == 0 .or. mod(x,4) == 3) then
			sum = sum + x
			m = m + 1
		else if(mod(x,4) == 1) then
			print *, "ignore and continue"
			cycle
		else if(mod(x,4) == 2) then
			print *, "exit from the loop"
			exit
		end if
		i = i + 1
	end do
	aver = sum / m
	print *, aver
end subroutine

subroutine T_do
	implicit none
	integer::r
	r = ((abs(i + j), i = 1, 4), j = 5, 6)
	!((a(i, j), j = 1, 10),i = 1, 5)
	 !(a(i),(b(i,j),j=1,m),i=1,n)
end subroutine