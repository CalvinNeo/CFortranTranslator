subroutine T_fixed_format ! comments
character ch ! this is comment because of the beginning `c`
      character ch2 ! this is not comment, because `c` is not at the beginning of line
	do i=1,m
	do j=1,i
301	continue
!	endif ! 重要
c	endif ! 重要
	enddo
	enddo
	
	implicit double precision(z)
		if (aa.and.		 ! when doing continuation, comment should be removed
     *bb) then
      ! do nothing
      endif
      
	dimension arr1(10)
	* , arr2(10) ! continuation
		  IF ((arr1(1).EQ.M1.or.arr1(2).EQ.M2). ! the `.and.` token is continued between lines
	*  AND.arr1(3).EQ.M4) then		! operator/float conflict(ref tokenizer.txt for more)
	endif
	arr1(a) = 1; arr2(a) = 2! two stmts in one line seperated by `;`
a = 10 ! this free format stmt is allowed because this program accepts mixed codes
      goto 11
11    write(*, 12) a, b, c, arr(1), a, b, c, arr(2)
      read (3, 3) a, b, c
12    format(2(3I,F))
13    continue
3     format(3I)
      call T_fixed_format_empty1(1, 2)
      pause
      stop
end subroutine

! comments between subroutines 1
c comments between subroutines 2
C comments between subroutines 3
SUBROUTINE T_fixed_format_empty1(X,Y)  
	RETURN
ENDsubroutine
SUBROUTINE T_fixed_format_empty2() 

ENDsubroutine