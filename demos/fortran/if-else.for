subroutine T_if_else
	implicit none
	real::x, y, z
	write (*,*) 'INPUT X'
	read (*,*) x
	if (x > 0) then
		y = sin(x)
		z = sqrt(x)
	else if(x == 0) then
		if (y .eq. 1) then
			y = 0
		else if(y .eq. 2) then
			z = 0
		end if
	else
		y = tan(x)
		z = cos(x)
	end if
	if(x == 1) if(y == 2) write(*,*) 'x == 1 and y == 2'
	write (*,*) 'X=', x, 'Y=', Y, 'Z=', z
end subroutine