		if (aa.and.		 ! comment can't be continued
     *bb) then
      cc
      endif
      
	dimension a(1)
	* , b(2) ! continuation
		  IF ((KNN(IE).EQ.M1.or.KNN(IE).EQ.M2.or.KNN(IE).EQ.M3).
	*  AND.KNN(JE).EQ.M4) THEN		! operator/float conflict(refer control/tokenizer.txt for more)
	do i = 1, 1
		if (a == 1) a(22) ;	if (a == 2) b(33)
	enddo
a = 10
end

SUBROUTINE MINTW(X,Y)  ! comments
	RETURN
END
! empty subprogram
	 SUBROUTINE MINTW2(M)
	 end SUBROUTINE