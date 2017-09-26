program
	implicit none
	integer::n, i
	read *, n
	do i = 2, n-1
		if(mod(n, i) == 0) exit
	end do
	if(i>=n) then
		print 'Y'
	else
		print 'N'
	end if
end program