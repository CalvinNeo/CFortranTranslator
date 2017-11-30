subroutine T_array_basic
	implicit none
	real, dimension(3) array_real ! decl an array
	REAL arr_initial(10) = (/1,2,3,4,5,6,7,8,9,0/) ! decl an array and set initial value
	REAL::arr_3d(10, 20, 30:40) ! decl a multi dimensional array
	integer,dimension(5:6, 6:7, 7:8)::arr_3d_initial=(/1, 2, 3, 4, 5, 6, 7, 8/)  ! decl and initialize a multi dimensional array
	integer,dimension(5:7)::arr_implied_do=(/ (int(i) + 1, i=5,7) /) ! decl an array by implied do
	arr_3d_initial = (/2, 3, 4, 5, 6, 7, 8, arr_initial(1) /) 	! assign value to an array by list
	integer,dimension(3)::C = A(:) ! assign value to 
	integer,dimension(5:7)::D = (/ a(5:7), b(5, 6, 7), ( int(i) + 1, i=5,7 ) /)
	integer,dimension(2, 2)::E = (/ ((i + j, j=1,2), i=1,2) /)
	
	! array io
	print *, A(6), B(5,6,7), C(1)
	read *, a(1)
	
	! allocatable
	ALLOCATABLE arr_alloc_a, arr_alloc_b
	ALLOCATE(arr_alloc_a(-2:2), arr_alloc_b(3,3,3))
end subroutine