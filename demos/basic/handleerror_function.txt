subroutine ss(r, h)
	implicit none
	! missing stuffs beneath will cause error
	! need to be handled elegantly
	! real,intent(in)::r
	! real,optional,intent(in)::h
end subroutine
program ss_optional
	implicit none
	ss(1, 2)
end program