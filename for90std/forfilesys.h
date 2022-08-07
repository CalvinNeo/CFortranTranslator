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
#include <string>
#include "fordefs.h"
#include "forlang.h"
#include <unistd.h>

_NAMESPACE_FORTRAN_BEGIN
void foropenfile(int unit, foroptional<int> iostat, foroptional<forlabel> err, foroptional<std::string> file, foroptional<std::string> status = None, foroptional<std::string> access = None
	, foroptional<std::string> form = None, foroptional<int> recl = None, foroptional<std::string> blank = None, foroptional<std::string> position = None, foroptional<std::string> action = None
	, foroptional<std::string> delim = None, foroptional<std::string> pad = None);
void forclosefile(foroptional<int> unit, foroptional<int> iostat, foroptional<forlabel> err = None, foroptional<std::string> status = None);
FILE * get_file(int unit);
void flush_fileno();
void forinquire(foroptional<int> unit, foroptional<std::string> file, foroptional<int> iostat, foroptional<forlabel> err, bool &exist);
_NAMESPACE_FORTRAN_END