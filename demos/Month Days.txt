program
	select case (month)
		case (2)
			days = 28
		case (4, 6, 9, 11)
			days = 30
		case (1,3,5,7,8,10,12)
			days = 31
	end select
end program