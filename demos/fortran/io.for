	character  filename* 80
        READ (*,*) FILENAME
        OPEN(1,FILE=FILENAME)
READ(1,*) (I + 1,I=1,M)
WRITE(1,*) (a,b,J=1,2)

WRITE(2,*) ((IFD(I,J),J=1,i),I=2,10)