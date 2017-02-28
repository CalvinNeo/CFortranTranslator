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

#include "gen_common.h"
#include <map>

//3.2.5 Statement labels
//A statement label provides a means of referring to an individual statement.
//R313 label is digit[digit[digit[digit[digit]]]]
//Constraint: At least one digit in a label must be nonzero.
//	If a statement is labeled, the statement must contain a nonblank character.The same statement label must not be
//	given to more than one statement in a scoping unit.Leading zeros are not significant in distinguishing between
//	statement labels.For example :
//99999
//10
//010
//are all statement labels.The last two are equivalent

void log_format_index(std::string format_index, const ParseNode & format) {
	get_context().labels[format_index] = format;
}

ParseNode require_format_index(std::string format_index) {
	// read/write 语句可以直接使用format语句的行号作为参数
	return get_context().labels[format_index];
}