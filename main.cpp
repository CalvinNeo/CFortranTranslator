/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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