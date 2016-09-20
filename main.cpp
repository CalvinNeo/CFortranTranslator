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

using namespace std;

int main(int argc, char* argv[], char* env[])
{
	int opt; 
	while ((opt = getopt(argc, argv, "f:Fp")) != -1) {
		if (opt == 'f')
		{
			fstream f;
			f.open(optarg, ios::in);
			std::string code((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
			f.close();
		}
		else if (opt == 'F') {
			cout << optarg << endl;
		}
	}
	debug();
	system("pause");
	return 0;
}