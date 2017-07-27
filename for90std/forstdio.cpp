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

#include "forstdio.h"
#include "forfilesys.h"

namespace for90std{
	void forrewind(int unit, foroptional<int> iostat, foroptional<forlabel> err) {
		forrewind(get_file(unit), iostat, err);
	};
	void forbackspace(int unit, foroptional<int> iostat, foroptional<forlabel> err) {
		forbackspace(get_file(unit), iostat, err);
	};	
	void forrewind(FILE * f, foroptional<int> iostat, foroptional<forlabel> err) {
		std::rewind(f);
	};
	void forbackspace(FILE * f, foroptional<int> iostat, foroptional<forlabel> err) {
		while (std::fseek(f, -1L, SEEK_CUR) == 0) {
			char ch = std::fgetc(f);
			if (ch == '\n')
			{
				return;
			}
			else {
				std::fseek(f, -1L, SEEK_CUR);
			}
		}
	};
}