#include <iostream>  
#include <sstream>
#include <fstream>
#include "parser.h"
#include <stdio.h>
#include "gen_config.h"
#include "for90std/for90std.h"
#include <numeric>
#include "develop.h"
#include "getopt.h"
#include "IntentHelper.h"
#include "codegen.h"

using namespace std;


int main(int argc, char* argv[], char* env[])
{
	int opt;
	bool for90 = true;
	bool isdebug = false;
	bool hasfile = false;
	std::string code;
	while ((opt = getopt(argc, argv, "df:Fp")) != -1) {
		if (opt == 'f')
		{
			hasfile = true;
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
	else if(hasfile){
		do_trans(code);
		cout << program_tree.fs.CurrentTerm.what << endl;
		//preorder(&program_tree);
	}
	else {

	}
	system("pause");
	return 0;
}