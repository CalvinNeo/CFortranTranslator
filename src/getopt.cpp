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
#include <vector>
#include <queue>
#include <map>

static int optind = 1; // from 0 to argc-1
char * optarg = nullptr;
static int opterr = 1;
static bool optinited = false;
static char optnames[128];
static std::queue<char> cached_ops;

enum longarg_ops {
	no_argument = 0,
	required_argument = 1,
	optional_argument = 2
};

struct option {
	char *name;
	int has_arg;
	int *flag;
	int val;
};

void parse_arg(const char *optstring) {
	// do not use strchr
	char curname = 0;
	memset(optnames, 0, sizeof optnames);
	while (*optstring != '\0') {
		if (*optstring == ':') {
			if (*(optstring + 1) == ':') {
				optnames[curname] = 3; // with optional argument
			}
			else {
				optnames[curname] = 2; // with an argument
			}
		}
		else {
			curname = *optstring;
			optnames[curname] = 1; // with no arguments
		}
		optstring++;
	}
}

int _getopt_impl(int argc, char * const argv[], const char * optstring, const struct option * longopts, int * longindex) {
	// argv include both options and option arguments, argc = len(options) + len(option arguments)
	if (!optinited) {
		parse_arg(optstring);
		cached_ops = std::queue<char>();
		optinited = true;
	}
	char optname;
	optarg = nullptr;
	if (optind >= argc && cached_ops.empty()) {
		return -1;
	}
	bool option_rather_than_args = argv[optind][0] == '-';
	if (!cached_ops.empty()) {
		optname = cached_ops.front();
		cached_ops.pop();
		goto HANDLE_CACHED;
	}
	else if ((!option_rather_than_args) || argv[optind][1] == '\0') {
		// begin with no dash or only a single dash
		return -1;
	}
	if (option_rather_than_args && argv[optind][1] == '-')
	{
		// long
		return 0;
	}
	else {
		// short
		optname = argv[optind][1];
		if(option_rather_than_args && argv[optind][2] != '\0') {
			int jj = 2;
			while (argv[optind][jj] != '\0') {
				cached_ops.push(argv[optind][jj]);
				jj++;
			}
			++optind;
			return optname;
		}
		++optind;
	HANDLE_CACHED:
		if (optnames[optname] == 0) {
			// if `optname` is not logged
			return -1;
		}
		if (optnames[optname] == 2) {
			// with an argument
			if (optind >= argc) {
				// if args count is larger than optind_len, this is obvious error
				return -1;
			}
			optarg = argv[optind++];
		}
		else if (optnames[optname] == 3)
		{
			// with an optional argument
			if (optind >= argc || argv[optind][0] != '-') {
				// no following arg
			}
			else {
				optarg = argv[optind++];
			}
		}
		return optname;
	}
}

int getopt(int argc, char *const argv[], const char *optstring) {
	return _getopt_impl(argc, argv, optstring, nullptr, nullptr);
}


int getopt_long(int argc, char *const argv, const char * optString, const struct option * longopts, int * longindex) {
	return 0;
}