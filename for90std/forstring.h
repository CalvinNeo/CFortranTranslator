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
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <locale>

namespace for90std {
	// specialization `forslice` of std::string
	inline std::string forslice(std::string str, const slice_info<int> & tp) {
		// use `slice_info<int>` to avoid narrow casting
		if (tp.to >= str.size()) {
			size_t appendlen = tp.to + 1 - str.size() + 1;
			str += std::string(appendlen, ' ');
		}
		if (tp.step == 1) {
			return str.substr(tp.fr, tp.to - tp.fr + 1);
		}
		else {
			std::string newstr;
			for (size_t i = tp.fr; (int)i <= tp.to; i += tp.step)
			{
				newstr += str[i];
			}
			return newstr;
		}
	}

	inline std::string foradjustl(std::string s) {
		// ltrim
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch);
		}));
		return s;
	}

	inline std::string foradjustr(std::string s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), s.end());
		return s;
	}

}
