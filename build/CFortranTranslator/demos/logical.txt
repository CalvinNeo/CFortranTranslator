program
	implicit none
	logical::a, b, c, d
	read 'l5, l3', a, b
	c = .true.
	d = .false.
	print '(1x,2l3,2l2)', a, b, c, d
end program