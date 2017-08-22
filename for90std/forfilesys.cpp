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

#include "forfilesys.h"
#include <map>

namespace for90std {
	static std::map<int, FILE *> filenos;
	static bool forfilesys_inited = false;
	FILE * get_file(int unit) {
		if (!forfilesys_inited) flush_fileno();
		auto iter = filenos.find(unit);
		assert(iter != filenos.end());
		return iter->second;
	}
	void flush_fileno() {
		filenos.clear();
		filenos[5] = stdin;
		filenos[6] = stdout;
		forfilesys_inited = true;
	}
	void foropenfile(int unit, foroptional<int> iostat, foroptional<forlabel> err, foroptional<const char *> file, foroptional<std::string> status, foroptional<std::string> access
		, foroptional<std::string> form, foroptional<int> recl, foroptional<std::string> blank, foroptional<std::string> position, foroptional<std::string> action
		, foroptional<std::string> delim, foroptional<std::string> pad) {
		foropenfile(unit, iostat, err, std::string(file.get()), status, access, form, recl, blank, position, action, delim, pad);
	}
	void foropenfile(int unit, foroptional<int> iostat, foroptional<forlabel> err, foroptional<std::string> file, foroptional<std::string> status, foroptional<std::string> access
		, foroptional<std::string> form, foroptional<int> recl, foroptional<std::string> blank, foroptional<std::string> position, foroptional<std::string> action
		, foroptional<std::string> delim, foroptional<std::string> pad) {

		/***************
		*	UNIT = 
		*	IOSTAT = 
		*	FILE = 
		*	STATUS = OLD, NEW, SCRATCH, REPLACE, UNKNOWN
		*	ACCESS = SEQUENTIAL, DIRECT
		*	FORM = FORMATTED, UNFORMATTED
		*	RECL =
		*	BLANK = NULL or ZERO
		*	POSITION =
		*	ACTION= = READ, WRITE, READWRITE
		*	DELIM = APOSTROPHE, QUOTE, NONE
		*	PAD =
		****************/
		if (!forfilesys_inited) flush_fileno();
		using namespace std;
		bool docreate = true;
		bool doread = true;
		bool dowrite = true;
		bool doappend = true;
		bool doreplace = false;
		string s;

		// method opertion(file attribute)
		// r read(r)
		// w write create/replace(w)
		// r+ read write(rw)
		// w+ read write create/replace(rw)
		// a append create(w)
		// a+ append create(rw)

		// 9.3.4.7
		s = position.value_or("asis");
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "rewind") {
			// REWIND positions an existing file at its initial point.
			doappend = false;
		}
		else if (s == "append") {
			// APPEND positions the file at its terminal point
			doappend = true;
		}
		else {
			// asis
			// ASIS leaves the position unchanged if the file
			// exists and already is connected.ASIS leaves the position unspecified if the file exists but is not connected.If this
			//	specifier is omitted, the default value is ASIS.
			doappend = false;
		}

		s = access.value_or("sequential");
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "sequential") {

		}
		else if (s == "direct") {

		}
		else {
			// not inited or else value
		}

		s = status.value_or("unknown");
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "new") {
			docreate = true;
			doreplace = false;
		}else if(s == "replace"){
			docreate = true;
			doreplace = true;
		}
		else if (s == "old") {
			docreate = false;
			doreplace = false;
		}
		else if (s == "scratch") {
			docreate = true;
			doreplace = false;
		}
		else {
			// unknown
			docreate = true;
			doreplace = false;
		}

		s = action.value_or("readwrite");
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "read") {
			doread = true;
			dowrite = false;
		}
		else if (s == "write") {
			dowrite = false;
			dowrite = true;
		}
		else {
			// s == "readwrite"
			doread = true;
			dowrite = true;
		}
		string mode;
		if (doappend) {
			mode = "a";
		}
		else {
			std::string flag_rw = (dowrite ? "+" : "");
			std::string flag_replace = (doreplace ? "w" : "r");
			mode = flag_replace + flag_rw;
		}
		filenos[unit] = fopen(file.get().c_str(), mode.c_str());
		if (filenos[unit] == 0)
		{
			// if not exist then create
			filenos[unit] = fopen(file.get().c_str(), "w+");
		}
		if (position.value_or("rewind") == "")
		{
			fseek(filenos[unit], 0, SEEK_SET);
		}
		else if (position.value_or("append") == "")
		{
			fseek(filenos[unit], 0, SEEK_END);
		}
		nop();
	}
	void forclosefile(foroptional<int> unit, foroptional<int> iostat, foroptional<forlabel> err, foroptional<std::string> status) {
		if (!forfilesys_inited) flush_fileno();
		auto iter = filenos.find(unit.get());
		if (iter != filenos.end()) {
			fclose(iter->second);
		}
	}
}