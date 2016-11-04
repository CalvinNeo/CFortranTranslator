subroutine ss(r, h)
	implicit none
	real,intent(in)::r
	real,optional,intent(in)::h
end subroutine
program ss_optional
	implicit none
	ss(1, 2)
end program