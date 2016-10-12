program
	implicit none
	real::i, r0, r1, r2, r12, r, u
	r0 = 100.0; r1 = 20.0; r2 = 50.0
	u = 200.0
	r12 = r1 * r2 / (r1 + r2)
	r = r0 + r12
	i = u / r
	write (*,*) 'R=', r
	write (*,*) "I=", i
end program