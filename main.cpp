#include <iostream>  
#include <sstream>  
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
	while (opt = getopt(argc, argv, "f:F:p") != -1) {

	}
	debug();
	system("pause");
	return 0;
}