program main
  use m
  implicit none

  write(*,*)one
  car1%speed=2.0
  write(*,*) car1%speed
  call xx(car1%speed)
end program
