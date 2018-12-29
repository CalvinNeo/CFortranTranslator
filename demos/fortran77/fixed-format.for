subroutine T_fixed_format ! comments
character ch ! This is comment because of the beginning `c`
      character ch2 ! This is not comment, because `c` is not at the beginning of line
!   endif ! 中文注释 This is comment
c   endif ! 中文注释 This is also comment

	do i=1,m
	do j=1,i
301	continue
	enddo
	enddo
	
		if (cond_a.and.		 ! When doing continuation, comment should be removed
     *cond_b) then ! `*` is a continuation
      ! do nothing
      endif
      
	dimension arr1(10)
	* , arr2(10) ! `*` is a continuation
		  if ((arr1(1).eq.m1.or.arr1(2).eq.m2). ! The `.and.` token is continued between lines
	*  and.arr1(3).eq.m3) then ! operator/float conflict(ref tokenizer.txt for more)
	endif
	arr1(a) = 1; arr2(a) = 2 ! two stmts in one line seperated by `;`
a = 10 ! Free format and fixed format can co-exist
      goto 11
      ! `write` can use format defined later at label `12`.
11    write(*, 12) a, b, c, arr(1), a, b, c, arr(2)
      read (3, 3) a, b, c
12    format(2(3I,F))
13    continue
3     format(3I)
      call T_fixed_format_empty1(1, 2)
      pause
      stop
end subroutine

! Comments between subroutines 1
c Comments between subroutines 2
C Comments between subroutines 3
SUBROUTINE T_fixed_format_empty1(X, Y)  
	RETURN
ENDsubroutine
SUBROUTINE T_fixed_format_empty2() 

ENDsubroutine