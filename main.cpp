#include <iostream>  
#include <sstream>  
#include "parser.h"
#include <stdio.h>
#include "cgen.h"
#include "for90std.h"
#include <numeric>

using namespace std;

string global_code;
char errlog[128];

int main()
{
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

	global_code = "program if 1 then 2 else if 3 then 4 end if end program";
	//global_code = "program 1.3 + 2 * 3 - .true. end program";
	global_code = "program integer::a \n if 1 then 2 else if 3 then 4 end if end program";
	global_code = "program integer::a = 1 + 2, b = 2, c = 3 \n  end program";
	global_code = "program write *,* a, b \n  end program";
	global_code = "program integer::A, B \n  end program"; 
	global_code = "program integer::a = 1 + 2 \n logical::b = .false. \n a = 3 \n end program";
	global_code = "program integer::a = 1 + 2 \n  end program";
	global_code = "program recursive function main(A,B) result(C) \n implicit none \n integer::a = 1 + 2, b = 2, c = 3 \n end function end program";
	global_code = "program recursive function main(A,B) result(C) \n a = abs(c, abs(1 ,2)) \n end function end program";
	/* '(' exp ')' �� callable��Լ��ͻ */
	global_code = "program recursive function main(A,B) result(C) \n integer::a, b, c\n a = abs(real(c)) \n end function end program";
	global_code = "program recursive function main() result(C) \n complex::C = 1_2 \n end function end program";
	global_code = "program integer,dimension(5:7)::A=(/1, 2/) \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/ int(i) + 1, i=1,4/) \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/ B(1:2:3) /) \n  end program";
	global_code = "program integer,intent(out)::a = 1 + 2, b = 2, c = 3 \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/1, 2/) \n  end program"; 
	global_code = "program integer,intent(out),dimension(5:7)::A=(/1, 2/) \n  end program";
	global_code = "program integer,dimension(5:7, 6:8, 7:9)::A=(/1, 2, 3, 4, 5, 6/) \n  end program";
	global_code = "program integer,dimension(2, 3)::A=(/ (int(i) + 1, i=1,4) , j = 2, 3 /) \n  end program";
	global_code = "program integer,dimension(5 : 7, 6 : 8)::A \n A(1:2, :) \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/ a(1:2) , b(3:4)/) \n  end program";


	std::vector<int> accumulated{2, 2, 2};
	int s = 1;
	std::transform(accumulated.rbegin() , accumulated.rend(), accumulated.rbegin() , [&s](int x) {int ans = s; s *= x; return ans; });


	cout << max_n(1, 2) << endl;
	cout << parse_ioformatter("\"aaa\"2(f, 2i)") << endl;

	forarray<forarray<int>> a(1, 3);
	for (int i = 1; i < 3; i++)
	{
		a(i) = forarray<int>(1, 3);
	}
	init_forarray(a, vector<int>{1, 1}, vector<int>{2, 2}, std::vector<int>{1, 2, 3, 4});
	cout << a(1)(1) << " " << a(1)(2) << endl;

	parse(global_code);
	while (fscanf(stderr, "%s", errlog) != EOF) {
		printf("%s\n", errlog);
	}
	preorder(&program_tree);
	//cout << endl << for2cpp(global_code) << endl;
	system("pause");
	return 0;
}