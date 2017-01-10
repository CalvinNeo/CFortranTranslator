program
	implicit none 
	integer::n,m
	read (*,*) n
	m = mod(n, 3)
	select case (m)
		case (0)
			write (*, '(1x,i6,2x,a)') n, 'can be divided exactly by 3'
		case default
			write (*, '(1x,i6,2x,a)') n, 'can not be divided exactly by 3'
	end select
end program