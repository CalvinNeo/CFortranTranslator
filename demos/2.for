program main
 implicit none
 logical alive
          inquire(file="xx",exist=alive)
          if(.not.alive) then
            write(*,*) "no"
           endif
end program