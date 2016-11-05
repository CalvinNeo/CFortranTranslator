program
	implicit none
	integer,dimension(1:10)::a
	integer::i
	a(1) = 0; a(2) = 1;
	do i = 3, 10
		a(i) = a(i - 2) + a(i - 1)
	end do
	write (*, '1X, 5I8') a
end program