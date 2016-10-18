program
	implicit none
	integer::x, n, i = 0, m = 0
	real::aver, sum = 0
	read *, n
	do while(i < n)
		read *, x
		if(mod(x,2) /= 0) then
			sum = sum + x
			m = m + 1
		end if
		i = i + 1
	end do
	aver = sum / m
	print *, aver
end program