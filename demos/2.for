    module ma
    implicit none
    interface show
    module procedure  show_int
    module procedure  show_character
    end interface

    contains
    subroutine show_int(n)
    implicit none
    integer,intent(in)::n
    write(*,"('n=',i3)")n
    end subroutine show_int

    subroutine show_character(str)
    implicit none
    character(len=4),intent(in)::str
    write(*,"('str=',A)")str
    end subroutine show_character

    end module
