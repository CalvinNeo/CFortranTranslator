program
	implicit none
	real::a, b, c, d, e, big, small
	read (*,*) a, b, c, d, e
	big = max(abs(a), abs(b), abs(c), abs(d), abs(e))
	small = min(abs(a), abs(b), abs(c), abs(d), abs(e))
	write (*, "(1x,2(a,f8.2))") 'MAX=', big, ' MIN=', small
end program