! Here we create a Common Block cb with 3 fields.
common /cb/ a, b, c(10)
subroutine T_commonblock2
    ! We create alias for fields in cb.
	common /cb/ alias_a, alias_b, alias_c(10) 
	integer::x
	! We IMPLICITLY create a Common Block cc with one field.
	common /cc/ d
	! Fields declaration of Common Block has lower priority.
	dimension d(100) 
end subroutine
common /ca/ n
subroutine T_commonblock
    ! We create a Common Block which name is empty.
	common // global_a
	common /ca/ m
	common /cb/ a, b, c(10)
	common /cc/ nv
end subroutine

! Common Block will generate following codes.
! int & x = cb._1
! int & y = cd._2;
! farray<double> & z = cb._3