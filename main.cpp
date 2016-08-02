#include <iostream>  
#include <sstream>  
#include "parser.h"
#include <stdio.h>

using namespace std;

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

	//int i = 0;
	//string s = ",    \t\t ww075w ++ + +";
	//s = ", www ,www";
	//FlexState st;
	//while (!st.isnull) {
	//	st = next_token(s, i);
	//	if (!st.isnull) {
	//		cout << st.CurrentTerm.what << " ----- " << st.parse_len<< endl;
	//	}
	//	i = st.parse_pos;
	//}


	//string s = "+ +";
	//FlexState st = next_token(s);
	//cout << st.isnull << endl;
	//cout << st.CurrentTerm.what << endl;
	//cout << st.CurrentTerm.meta << endl;
	//cout << st.parse_pos << " " << st.parse_len << endl;

	//char chs[20];
	//memset(chs, 0, sizeof(chs));
	//strcpy(chs, s.c_str());
	//cout << s.size() << endl;
	//cout << strlen(chs) << endl;

	string s = "program if 1 then 2 else 2 end if end program";
	//s = "\"ab\\\"c\"";
	//string s = "(1.2)";

	parse(s);
	char errlog[128];
	while (fscanf(stderr, "%s", errlog) != EOF) {
		printf("%s\n", errlog);
	}
	preoder(&program_tree);
	system("pause");
	return 0;
}