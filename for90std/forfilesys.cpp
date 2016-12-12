#include "forfilesys.h"
#include <map>

namespace for90std {
	static std::map<int, FILE *> filenos;
	FILE * get_file(int unit) {
		auto iter = filenos.find(unit);
		if (iter != filenos.end()) {
			return iter->second;
		}
		return stdin;
		return stdout;
	}
	void flush_fileno() {
		filenos.clear();
		filenos[5] = stdin;
		filenos[6] = stdout;
	}
	void foropenfile(int unit, std::string file, foroptional<std::string> access, foroptional<std::string> action, foroptional<std::string> status, foroptional<int> iostat) {
		using namespace std;
		bool docreate;
		bool doread;
		bool dowrite;
		bool doappend;
		string s;

		// method opertion(file attribute)
		// r read(r)
		// w write create/replace(w)
		// r+ read write(rw)
		// w+ read write create/replace(rw)
		// a append create(w)
		// a+ append create(rw)

		s = access.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "append") {
			doappend = true;
		}
		else if (s == "sequential") {

		}
		else if (s == "direct") {

		}
		else {
			// not inited or else value
		}

		s = status.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "new") {
			docreate = true;
		}else if(s == "replace"){
			docreate = true;
		}
		else if (s == "old") {
			docreate = false;
		}
		else if (s == "scratch") {
		}
		else {
			// not inited or else value
		}

		s = action.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "read") {
			doread = true;
		}
		else if (s == "write") {
			dowrite = true;
		}
		else {
			doread = true;
			dowrite = true;
		}
		string mode;
		if (doappend) {
			mode = "a";
		}
		else {
			if (doread) {
				if (dowrite) {
					if (docreate) {
						mode = "w+";
					}
					else {
						mode = "r+";
					}
				}
				else {
					mode = "r";
				}
			}
			else {
				mode = "w";
			}
		}
		filenos[unit] = fopen(file.c_str(), mode.c_str());
	}
	void forclosefile(foroptional<int> unit, foroptional<std::string> status, foroptional<int> iostat) {
		auto iter = filenos.find(unit.get());
		if (iter != filenos.end()) {
			fclose(iter->second);
		}
	}
}