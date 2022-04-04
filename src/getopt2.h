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

#pragma once


struct option {
	char * name;
	int has_arg;
	// flag == NULL: `getopt_long` returns val. val is usually a short option character
	// flag != NULL: Fill val to *flag, `getopt_long` returns 0
	int * flag;
	int val;
};

enum longarg_ops {
	no_argument = 0,
	required_argument = 1,
	optional_argument = 2
};

int getopt(int argc, char * const argv[], const char * optstring);
int getopt_long(int argc, char *const argv[], const char * optString, const struct option * longopts, int * longindex);
extern char * optarg;