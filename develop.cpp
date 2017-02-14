#include "develop.h"
#include <iostream>  
#include <sstream>  
#include "parser.h"
#include <stdio.h>
#include "codegen.h"
#include "for90std/for90std.h"
#include <numeric>

using namespace std;

char errlog[128];

void debug() {
	//istringstream istr;
	//istr.str("1 56.7 65.3 \n 321 555");
	//string x;
	//istr >> x;
	//cout << x << endl;
	//getline(istr, x);
	//cout << x << endl;
	//int LB = 4444;
	//cout << LB << endl;
	//cout << TokenMeta::LB << endl;

	// math
	get_context().global_code = "program 1 * -3 + +++++2 end program";
	get_context().global_code = "program 1 + (3 * (2.5 + 3.6)) end program";

	// if_stmt, logical eval
	get_context().global_code = "program if a .eqv. b then 2 else c end if end program";
	get_context().global_code = "program if a .eqv. b then 2 else if a >= b then b <= a end if end program";
	get_context().global_code = "program if (a .eqv. b) then 2 else if a >= b then b <= a else c end if end program";
	get_context().global_code = "program if 1 then if 2 then 3 end if end if end program";
	get_context().global_code = "program if 1 then if 11 then 22 else if 33 then 44 else 4 end if end if end program";
	get_context().global_code = "program if 1 then if 11 then 22 else if 33 then 44 end if else 4 end if end program";
	get_context().global_code = "program if 1 then if 11 then 22 else if 33 then 44 else 55 end if else if 3 then 4 else 5 end if end program";
	get_context().global_code = "program if a .eqv. b then if .not. a < b then a = b else b = .not. .true. end if else if a >= b then b <= a else c end if end program";
	get_context().global_code = "program 1.3 + 2 * 3 - .true. end program";

	// do_stmt
	get_context().global_code = "program do infi_loop() end do end program";
	get_context().global_code = "program do i = 1, 5 \n count_loop() end do end program";
	get_context().global_code = "program do i = 1, 5 \n if (a == 0) then cycle else exit end if end do end program";
	get_context().global_code = "program do while (i < 8) \n conditional_loop() end do end program";
	get_context().global_code = "program do i = 2, n-1 \n count_loop() end do end program";
	/* hidden do */
	get_context().global_code = "program \n ((abs(i + j), i = 1, 4), j = 5, 6) \n end program";

	// type
	get_context().global_code = "program real::a, b, c \n end program";
	get_context().global_code = "program recursive function main() result(C) \n complex::C = 1_2 \n end function end program";

	// var_decl
	get_context().global_code = "program integer::a = 1 + 2 * -3, b = 2, c = 3 \n  end program";
	get_context().global_code = "program integer::A, B \n  end program";
	get_context().global_code = "program integer::a = 1 + 2 \n logical::b = .false. \n a = 3 \n end program";
	get_context().global_code = "program integer,intent(out)::a = 1 + 2, b = 2, c = 3 \n  end program";
	get_context().global_code = "program integer(kind = 1)::int_char \n integer(kind = 4)::int_int \n integer(kind = 8)::int_longlong \n  end program";

	// io
	get_context().global_code = "program write *,* a, b \n  end program"; // syntax error, must wrapped with ()
	get_context().global_code = "program write (*,*) 'L=', L \n  end program";
	get_context().global_code = "program print '2(a,f)' \n  end program";
	get_context().global_code = "program write (*,\"1X,F10.3,F8.4\") x, y \n  end program";
	get_context().global_code = "program read *, x, y \n  end program";
	get_context().global_code = "program read (*,*) x, y \n  end program";
	get_context().global_code = "program read (*,\"F, F\") x, y \n  end program";

	// function
	get_context().global_code = " recursive function main(A,B) result(C) \n implicit none \n integer::a = 1 + 2, b = 2, c = 3 \n end function  ";
	get_context().global_code = " recursive function main(A,B) result(C) \n implicit none \n integer,intent(in)::a = 1 + 2, b \n integer,intent(out)::c = 3 \n end function  "; // pay attention  no def a, b and add return c
	get_context().global_code = "recursive function main(A,B) result(C) \n integer::a , b , c \n a = abs(c, abs(1 ,2)) \n end function";
	get_context().global_code = "recursive function main(A,B) result(C) \n integer::a , b , c \n a = empty() \n end function";
	get_context().global_code = "recursive function main(A,B) result(C) \n integer::a, b, c\n a = abs(ahhhhh(c)) \n end function"; /* '(' exp ')' 和 callable_head归约冲突 */ /* IMPORTANT */ // now ok
	get_context().global_code = "recursive function main(A,B) result(C) \n integer::a, b, c\n a = abs(real(c)) \n end function"; /* _type_kind 和 type cast function call 冲突 */ /* IMPORTANT */ // now ok
	/* 和以上对比，给出冲突的另一边 */
	get_context().global_code = "program \n integer(kind = 4)::a, b \n end program"; // now ok
	get_context().global_code = "program \n kwargs(1, b = 3, c = 3) \n end program";

	// array
	get_context().global_code = "program integer,intent(out),dimension(5:7)::A=(/1, 2/) \n  end program"; // intent
	
	get_context().global_code = "program integer,dimension(5:7)::A=(/1, 2/) \n  end program";
	get_context().global_code = "program integer,dimension(5:7, 6:8, 7:9)::A=(/1, 2, 3, 4, 5, 6/) \n  end program"; 
	get_context().global_code = "program integer,dimension(5:7, 6:8)::A \n A(1:2, :) \n  end program"; 

	get_context().global_code = "program integer,dimension(5:7)::A=(/ int(i) + 1, i=1,4/) \n  end program";
	get_context().global_code = "program integer,dimension(2, 3)::A=(/ (int(i) + 1, i=1,4) , j = 2, 3 /) \n  end program"; // not support

	get_context().global_code = "program integer,dimension(5:7)::A=(/ B(1:2:3) /) \n  end program";

	get_context().global_code = "program integer,dimension(5:7)::A=(/ a(1:2) , b(3:4) /) \n  end program";
	get_context().global_code = "program integer,dimension(5:7)::A=(/ a(1:2) , b(3:4) , (int(i) + 1, i=1,4) /) \n  end program"; // error
	get_context().global_code = "program print *, B(5), A(1)(2)(3) \n  end program";

	// select
	get_context().global_code = "program select case abs(i) \n case 1 \n a = 3 \n case 2 : 3 \n a = 4  end select end program";


	// paste here
	get_context().global_code = "program integer,intent(out),dimension(5:7)::A=(/1, 2/) \n  end program"; // intent

	get_context().global_code = "program \n kwargs(1, b = 3, c = 3) \n end program";
	get_context().global_code = "program integer, dimension(5:7)::A = (/ int(i) + 1, i = 1, 4 /) \n  end program";
	get_context().global_code = "program integer, dimension(5:7)::A = (/ int(i) + 1, i = 1, 4 /) \n  end program";
	get_context().global_code = "program integer, dimension(5:7, 6 : 8, 7 : 9)::A = (/ 11, 12, 13, 14, 15, 16 /) \n  end program";
	get_context().global_code = "program print *, B(5), A(1)(2)(3) \n  end program";


	//for1array< for1array< for1array<int>  > > b(1, 3);
	//b(1)(1)(1) = 1;
	//b(1)(2)(1) = 2;
	//cout << b(1)(1)(1) << endl;
	//f1a_init(b, {1, 1, 1}, {2, 2, 2}, {1, 2, 3, 4, 5, 6, 7, 8});
	//for (int i = 1; i <= 2; i++)
	//{
	//	for (int j = 1; j <= 2; j++)
	//	{
	//		cout << b(j)(i)(1) << endl;
	//	}
	//}
	//for (int i = 1; i <= 2; i++)
	//{
	//	for (int j = 1; j <= 2; j++)
	//	{
	//		cout << b(j)(i)(2) << endl;
	//	}
	//}
	//vector<fsize_t> size = f1a_getsize(b);
	// // forstyle should return 1, 2, 3, 4, 5, 6, 7, 8

	parse(get_context().global_code);
	while (fscanf(stderr, "%s", errlog) != EOF) {
		printf("%s\n", errlog);
		
	}
	preorder(&get_context().program_tree);
	//cout << endl << for2cpp(get_context().global_code) << endl;
}