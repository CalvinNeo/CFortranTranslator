common /cb/ a, b, c(10)
subroutine T_commonblock2
	common /cb/ x, y, z(10) ! symbol in a common block can be changed
	integer::x
	common /cc/ nv
	dimension nv(100) ! if a variable in a common block is declared "normally" as an array, it's an array.
end subroutine
common /ca/ n
subroutine T_commonblock
	common // global_a
	common /ca/ m
	common /cb/ a, b, c(10)
	common /cc/ nv
end subroutine

!int & x = cb._1
!int & y = cd._2;
!farray<double> & z = cb._3