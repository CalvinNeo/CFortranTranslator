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

#include "getopt.h"
#include <memory>

static int optind = 1;
char * optarg = nullptr;
static int opterr = 1;
static bool optinited = false;
static char optnames[128];

void parse_arg(const char *optstring) {
	// do not use strchr
	char curname = 0;
	memset(optnames, 0, sizeof optnames);
	while (*optstring != '\0') {
		if (*optstring == ':') {
			if (*(optstring + 1) == ':') {
				optnames[curname] = 3; // optional
			}
			else {
				optnames[curname] = 2; // an argument
			}
		}
		else {
			curname = *optstring;
			optnames[curname] = 1; // valid
		}
		optstring++;
	}
}

int getopt(int argc, char *const argv[], const char *optstring) {
	if (!optinited) {
		parse_arg(optstring);
		optinited = true;
	}
	optarg = nullptr;
	if (optind >= argc) {
		return -1;
	}
	else if (argv[optind][0] != '-' || argv[optind][1] == '\0') {
		// begin with no dash or dash alone
		return -1;
	}
	char optname = argv[optind][1];
	if (optnames[optname] == 0) {
		return -1;
		return '?';
	}
	if (optnames[optname] == 2) {
		// an argument
		if (++optind >= argc) {
			return -1;
		}
		optarg = argv[optind];
	}
	else {
		++optind;
	}
	return optname;
}