#include "forstdio.h"

std::string _forwrite_noargs(FILE * f, std::string format) {
	for (size_t i = 0; i < format.size(); i++)
	{
		switch (format[i])
		{
		case '\\':
			if (i + 1 < format.size()) {
				printf(format.substr(i, 2).c_str());
			}
			i++;
			break;
		case '%':
			return format.substr(i);
		default:
			printf(format.substr(i, 1).c_str());
			break;
		}
	}
}