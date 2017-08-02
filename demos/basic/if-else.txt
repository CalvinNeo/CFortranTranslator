program
	implicit none
	real::x, y, z
	write (*,*) 'INPUT X'
	read (*,*) x
	if (x > 0) then
		y = sin(x)
		z = sqrt(x)
	else if(x == 0) then
		y = 0
		z = 0
	else
		y = tan(x)
		z = cos(x)
	end if
	write (*,*) 'X=', x, 'Y=', Y, 'Z=', z
end  program