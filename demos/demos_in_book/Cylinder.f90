function cylinder_ss(r, h) result(ss_result)
	implicit none
	real,intent(in)::r
	real,optional,intent(in)::h
	real::ss_result
	real::temp_h
	if(present(h)) then
		temp_h = h
	else
		temp_h = 1.0
	end if
	ss_result = 3.1415926*r**2*temp_h
end function
subroutine test_cylinder
	implicit none
	interface
		function cylinder_ss(r,h) result (ss_result)
			real,intent(in)::r
			real,optional,intent(in)::h
			real::ss_result
		end function
	end interface
	print '(1x,a,f10.3)' ,'area=', cylinder_ss(2.5)
	print '(1x,a,f10.3)' ,'vol=', cylinder_ss(2.5,9.6)
end subroutine