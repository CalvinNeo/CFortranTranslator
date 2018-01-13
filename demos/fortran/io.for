subroutine T_io
11      FORMAT(/50X,2(2I3))
12      FORMAT('A'/2(2I3))
13      FORMAT(2F10.3,' ',2H(",I4,2H)")
14		FORMAT(5HCOLOR,' ',I1)
15      FORMAT(F10.3,'( 
			"',I1,2H)")
		print 11, 1, 2, 3, 4
		print 12, 1, 2, 3, 4
		print 13, 1.1, 2.2, 1, 2, 3, 4
		print 14, 1
		print 15, 1.1, 1
		character filename* 80
		READ (*,*) filename
		OPEN(1, FILE=filename)
		WRITE(1,*) (a, b, i=1,2)
		WRITE(2,*) ((a(i,j), j=1,i), i=1,10)
end subroutine