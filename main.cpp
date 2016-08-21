#include <iostream>  
#include <sstream>  
#include "parser.h"
#include <stdio.h>
#include "cgen.h"

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
	//global_code = "\"ab\\\"c\"";
	//global_code = "program 1.3 + 2 * 3 - .true. end program";
	//global_code = "program 1.3 + 2 * 3 - .true. end program";
	global_code = "program integer::a \n if 1 then 2 else if 3 then 4 end if end program";
	global_code = "program integer::a = 1 + 2, b = 2, c = 3 \n  end program";
	global_code = "program write *,* a, b \n  end program";
	global_code = "program integer::A, B \n  end program";
	global_code = "program integer::a = 1 + 2 \n  end program";
	global_code = "program recursive function main(A,B) result(C) \n implicit none \n integer::a = 1 + 2, b = 2, c = 3 \n end function end program";
	global_code = "program recursive function main(A,B) result(C) \n a = abs(c) \n end function end program";
	/* '(' exp ')' ºÍ callable¹éÔ¼³åÍ» */
	global_code = "program recursive function main(A,B) result(C) \n a = abs(real(c)) \n end function end program";
	global_code = "program recursive function main() result(C) \n complex::C = 1_2 \n end function end program";
	global_code = "program integer,dimension(5:7)::A=(/1, 2/) \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/ int(i) + 1, i=1,4/) \n  end program";
	global_code = "program integer,dimension(5:7)::A=(/ B(1:2:3) /) \n  end program";

	//global_code = "program integer::a = 1 + 2 \n logical::b = .false. \n a = 3 \n end program";

	//global_code = "~~~~~";

	//next_token(global_code, 0);

	parse(global_code);
	while (fscanf(stderr, "%s", errlog) != EOF) {
		printf("%s\n", errlog);
	}
	preorder(&program_tree);
	//cout << endl << gen_code(&program_tree) << endl;
	system("pause");
	return 0;
}