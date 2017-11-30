subroutine T_io

11       FORMAT(/50X,6(3I3))

12       FORMAT('FIXED NODEL PLONT'/6(3I3))
13     FORMAT('PS ',2F10.3,' 0.06 0.0 ',2H(",I4,2H)")

14		FORMAT(5HCOLOR,' ',I1)
15     FORMAT('PS ',2F10.3,' 0.06 0.0  "(',I1,2H)")

	character  filename* 80
        READ (*,*) FILENAME
        OPEN(1,FILE=FILENAME)
READ(1,*) (I + 1,I=1,M)
WRITE(1,*) (a,b,J=1,2)

WRITE(2,*) ((IFD(I,J),J=1,i),I=2,10)

end subroutine