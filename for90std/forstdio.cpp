#include "forstdio.h"

namespace for90std{
std::string _forwrite_noargs(FILE * f, std::string format) {
	for (size_t i = 0; i < format.size(); i++)
	{
		switch (format[i])
		{
		case '\\':
			if (i + 1 < format.size()) {
				fprintf(f, format.substr(i, 2).c_str());
			}
			i++;
			break;
		case '%':
			return format.substr(i);
		default:
			fprintf(f, format.substr(i, 1).c_str());
			break;
		}
	}
	return format;
}
}