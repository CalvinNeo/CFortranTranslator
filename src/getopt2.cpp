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

#include "getopt2.h"
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <cstring>

static int optind = 1; // from 0 to argc-1
char * optarg = nullptr;
static int opterr = 1;
static bool optinited = false;
static char optnames[128];
static std::queue<char> cached_ops;

void parse_arg(const char *optstring) {
	// do not use strchr
	char curname = 0;
	memset(optnames, -1, sizeof optnames);
	while (*optstring != '\0') {
		if (*optstring == ':') {
			if (*(optstring + 1) == ':') { // it will not overflow, because every legal string finish with '\0'
				optnames[curname] = optional_argument; // with optional argument
				optstring++;
			}
			else {
				optnames[curname] = required_argument; // with an argument
			}
		}
		else {
			curname = *optstring;
			optnames[curname] = no_argument; // with no arguments
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
		// finish processing
		return -1;
	}
	/**************
	* pay attention to
	* a.exe -negtive_arg -100 
	* this case won't cause error because when calling `_getopt_impl`, 
	* `optind` must point to a optioan rather than a argument
	* a.exe -1 2
	**************/
	std::function<bool(char * const)> test_option = [](char * const arg) {
		if (arg[0] != '-') {
			return false;
		}
		if (arg[1] == '-') {
			// --
			return true;
		}
		if (arg[1] < 128 && optnames[arg[1]] != -1)
		{
			return true;
		}
		else {
			return false;
		}
	};
	if (!cached_ops.empty()) {
		optname = cached_ops.front();
		cached_ops.pop();
		goto HANDLE_CACHED;
	}
	bool is_option_field = test_option(argv[optind]);
	if ((!is_option_field) || argv[optind][1] == '\0') {
		// begin with no dash or only a single dash
		// ERROR finish processing
		return -1;
	}
	if (is_option_field && argv[optind][1] == '-')
	{
		// long
		const option * longopptr = longopts;
		const char * long_optname = argv[optind];
		while (longopptr->name != nullptr)
		{
			// longopptr->name: argname
			// long_optname: --argname
			if (std::strcmp(longopptr->name, long_optname + 2) == 0)
			{
				break;
			}
			longopptr++;
		}
		++optind;
		if (longopptr->name == nullptr) {
			// if not defined
			// ERROR finish processing
			return '?';
		}
		else if (longopptr->flag == nullptr)
		{
			// use short name case
			optname = longopptr->name[0];
			goto HANDLE_CACHED;
		}
		else {
			// use long name case
			*(longopptr->flag) = longopptr->val;
			switch (longopptr->has_arg)
			{
			case required_argument:
				optarg = argv[optind++];
				break;
			case optional_argument:
				if (optind >= argc || argv[optind][0] != '-') {
					// no following arg
				}
				else {
					optarg = argv[optind++];
				}
				break;
			case no_argument:
			default:
				// do nothing
				break;
			}
			return 0;
		}
	}
	else {
		// short
		optname = argv[optind][1];
		// handle combined options, e.g.
		/**************
		* tar -xvf ...
		**************/
		if(is_option_field && argv[optind][2] != '\0') {
			int attached_option = 2;
			while (argv[optind][attached_option] != '\0') {
				// TODO sort all arguments
				char ao = argv[optind][attached_option];
				if (optnames[ao] == required_argument)
				{
					std::swap(ao, optname);
				}
				cached_ops.push(ao);
				attached_option++;
			}
		}
		++optind;
	HANDLE_CACHED:
		if (optnames[optname] == -1) {
			// if `optname` is not logged
			// ERROR finish processing
			return '?';
		}
		if (optnames[optname] == required_argument) {
			// with an argument
			if (optind >= argc) {
				// if args count is larger than optind_len, this is obvious error
				// ERROR finish processing
				return -1;
			}
			optarg = argv[optind++];
		}
		else if (optnames[optname] == optional_argument)
		{
			// with an optional argument
			if  (optind < argc && !test_option(argv[optind])) {
				optarg = argv[optind++];
			}
			else {
				// no following arg
				// TODO: consider `a.exe -arg1 -1 2`, where arg1 is an option which has optional argument, and -1 is a option with required argument(rather a argument)
				optarg = "?";
			}
		}
		return optname;
	}
}

int getopt(int argc, char *const argv[], const char *optstring) {
	return _getopt_impl(argc, argv, optstring, nullptr, nullptr);
}


int getopt_long(int argc, char *const argv[], const char * optString, const struct option * longopts, int * longindex) {
	return _getopt_impl(argc, argv, optString, longopts, longindex);
}