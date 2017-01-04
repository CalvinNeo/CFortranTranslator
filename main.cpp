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
	std::string code;
	while ((opt = getopt(argc, argv, "df:Fp")) != -1) {
		if (opt == 'f')
		{
			parse_config.hasfile = true;
			fstream f;
			f.open(optarg, ios::in);
			code = std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
			f.close();
		}
		else if (opt == 'F') {
			// for90
			parse_config.for90 = true;
		}
		else if (opt == 'd') {
			// debug
			parse_config.isdebug = true;
		}
		else if (opt == 'C') {
			// usec
			parse_config.usefor = false;
		}
	}
	parse_config.usefarray = false;
	if (parse_config.isdebug) {
		debug();
	}
	else if(parse_config.hasfile){
		do_trans(code);
		cout << program_tree.fs.CurrentTerm.what << endl;
		//preorder(&program_tree);
	}
	else {

	}
	system("pause");
	return 0;
}