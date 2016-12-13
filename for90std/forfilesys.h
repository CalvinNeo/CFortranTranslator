#pragma once
#include <string>
#include "forlang.h"

namespace for90std {
	void foropenfile(int unit, std::string file, foroptional<std::string> access, foroptional<std::string> action, foroptional<std::string> status, foroptional<int> iostat);
	void forclosefile(foroptional<int> unit, foroptional<std::string> status, foroptional<int> iostat);
	FILE * get_file(int unit);
	void flush_fileno();
}