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
			get_context().parse_config.hasfile = true;
			fstream f;
			f.open(optarg, ios::in);
			code = std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
			f.close();
		}
		else if (opt == 'F') {
			// for90
			get_context().parse_config.for90 = true;
		}
		else if (opt == 'd') {
			// debug
			get_context().parse_config.isdebug = true;
		}
		else if (opt == 'C') {
			// usec
			get_context().parse_config.usefor = false;
		}
	}
	get_context().parse_config.usefarray = true;
	if (get_context().parse_config.isdebug) {
		debug();
	}
	else if(get_context().parse_config.hasfile){
		do_trans(code);
		cout << get_context().program_tree.fs.CurrentTerm.what << endl;
		// preorder(&program_tree);
	}
	else {

	}
	system("pause");
	return 0;
}