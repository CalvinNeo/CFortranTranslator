common /cb/ a, b, c(10)
subroutine sub()
	common /cb/ x, y, z(10)
	integer::x
	common /cc/ nv
	dimension nv(100)
end subroutine
common /ca/ n
program
	common // block_a
	common /ca/ m
	common /cb/ a, b, c(10)
	common /cc/ nv
end program

!int & x = cb._1
!int & y = cd._2;
!farray<double> & z = cb._3