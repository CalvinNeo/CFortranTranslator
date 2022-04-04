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

#include "Intent.h"

std::string get_intent_name(TokenMeta_T intent_id) {
	return TokenMeta::get_enum_table().from_value(intent_id);
}

void make_enum_table(std::map<std::string, TokenMeta_T> & m, std::string str) {
	size_t s = 0;
	std::string k, v;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			v = str.substr(s, i - s);
			// TODO: ERROR: it can not work for expressions
			int xv;	sscanf(v.c_str(), "%d", &xv);
			m[k] = xv;
			s = i + 1;
		}
		else if (str[i] == '=') {
			k = str.substr(s, i - s); 
			s = i + 1;
		}
		else if (str[i] == ' ') {
		}
		else {
		}
	}
}