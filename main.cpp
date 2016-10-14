#include <iostream>  
#include <sstream>
#include <fstream>
#include "parser.h"
#include <stdio.h>
#include "cgen.h"
#include "for90std.h"
#include <numeric>
#include "develop.h"
#include "getopt.h"
#include "IntentHelper.h"

using namespace std;

void do_trans(const std::string & src) {
	global_code = src;
	parse(global_code);
}

int main(int argc, char* argv[], char* env[])
{
	int opt;
	bool for90 = true;
	bool isdebug = false; 
	std::string code;
	while ((opt = getopt(argc, argv, "df:Fp")) != -1) {
		if (opt == 'f')
		{
			fstream f;
			f.open(optarg, ios::in);
			code = std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
			f.close();
		}
		else if (opt == 'F') {
			// for90
			for90 = true;
		}
		else if (opt == 'd') {
			// debug
			isdebug = true;
		}
	}
	if (isdebug) {
		debug();
	}
	else {
		do_trans(code);
		cout << program_tree.fs.CurrentTerm.what << endl;
		//preorder(&program_tree);
	}
	system("pause");
	return 0;
}