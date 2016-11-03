program
	implicit none
	! find numbers which equals to its digital sum
	integer::i, j, k, m, n
	do i = 1, 9
		do j = 0, 9
			do k = 0, 9
				m = i * 100 + j * 10 + k
				n = i ** 3 + j ** 3 + k ** 3
					if(m==n) print '(1x, i4)', m
			end do
		end do
	end do
end program