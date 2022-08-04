    module ma
    use bee
    implicit none
    interface show
      subroutine fun
      end subroutine
    end interface
    contains
    function fff
    use ccc
    end function

    end module
