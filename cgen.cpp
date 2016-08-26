#include "cgen.h"

std::string for2cpp(std::string for_code) {
	using namespace std;
	string cpp_code = cpp_header;
	parse(for_code);
	cpp_code += program_tree.fs.CurrentTerm.what;
	return "";
}


std::string parse_ioformatter(const std::string & src) {
	std::string rt = "";
	std::string s;
	std::string mid; 
	char buf[256];
	char ch;
	int stat = 0; /* stat == 0 repeat */
	std::vector<int> repeat;
	std::vector<int> repeat_from;
	repeat.push_back(1);
	for (int i = 0; i < src.size(); i++)
	{
		ch = tolower(src[i]);
		switch (ch)
		{
		case 'i':
			s = "%%%sd";
			stat = 1;
			break;
		case 'f':
			s = "%%%sf";
			stat = 1;
			break;
		case 'e':
			s = "%%%sf";
			stat = 1;
			break;
		case 'a':
			/* char */
			s = "%%%ss";
			stat = 1;
			break;
		case 'x':
			/* space */
			s += " ";
			stat = 1;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (stat == 1)
			{
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				mid = src.substr(i, j - i).c_str();
				i = j - 1;
			}
			else {
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				sscanf(src.substr(i, j - i).c_str(), "%d", &repeat[repeat.size() - 1]);
			}
			break;
		case '.':
			if (stat == 1)
			{
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				mid += src.substr(i, j - i);
				i = j - 1;
			}
			else {

			}
			break;
		case ',':
			memset(buf, 0, sizeof(buf));
			sprintf(buf, s.c_str(), mid.c_str());
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			s = "";
			stat = 0;
			break;
		case '(':
			repeat.push_back(1);
			repeat_from.push_back(rt.size());
			break;
		case ')':
			memset(buf, 0, sizeof(buf));
			sprintf(buf, s.c_str(), mid.c_str());
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			s = rt.substr(repeat_from.back(), i - repeat_from.back());
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += s;
			}
			s = "";
			/* because s is empty so no need to jump ',' */
			//for (; i < s.size() && s[i] != ','; i++);
			//i--;
			repeat.pop_back();
			repeat_from.pop_back();
			stat = 0;
			break;
		case '%':
			rt += "%%";
		case '/':
			rt += "\n";
		case '\"':
			for (i++; i < src.size() && src[i] != '\"'; i++)
			{
				rt += src[i];
			}
		default:
			break;
		}
	}
	memset(buf, 0, sizeof(buf));
	sprintf(buf, s.c_str(), mid.c_str());
	for (int j = 0; j < repeat[repeat.size() - 1]; j++)
	{
		rt += buf;
	}
	return rt;
}