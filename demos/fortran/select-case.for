subroutine T_select_case
	real::x, y
	read *, x
	select case (x >= 0)
		case (.true.)
			y = x + 5.0
		case (.false.)
			y = -x
	end select
	print *, x, y
end subroutine