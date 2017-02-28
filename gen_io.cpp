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

void regen_read(ParseNode & stmt) {
	const ParseNode & io_info = stmt.get(0);
	const ParseNode & argtable = stmt.get(1);
	string device = io_info.get(0).to_string();
	if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		if (device == "-1" || device == "") {
			//device = "5"; // stdin
			sprintf(codegen_buf, "forreadfree(stdin, %s);\n", argtable.fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forreadfree(get_file(%s), %s);\n", device.c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
	}
	else {
		string fmt;
		if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = get_context().labels[io_info.get(1).to_string()].to_string();
		}
		else {
			fmt = io_info.get(1).fs.CurrentTerm.what.substr(1, io_info.get(1).fs.CurrentTerm.what.size() - 1); // strip " 
		}
		if (device == "-1" || device == "") {
			//device = "5"; // stdin
			sprintf(codegen_buf, "forread(stdin, \"%s\", %s);\n", parse_ioformatter(fmt).c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forread(get_file(%s), \"%s\", %s);\n", device.c_str(), parse_ioformatter(fmt).c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_READ_STMT, string(codegen_buf) };
	return;
}


void regen_write(ParseNode & stmt) {
	// brace is forced
	const ParseNode & io_info = stmt.get(0);
	const ParseNode & argtable = stmt.get(1);
	string device = io_info.get(0).to_string();
	if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		if (device == "-1") {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwritefree(stdout, %s);\n", argtable.fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forwritefree(get_file(%s), %s);\n", device.c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
	}
	else {
		string fmt;
		if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = get_context().labels[io_info.get(1).to_string()].to_string();
		} else{
			fmt = io_info.get(1).fs.CurrentTerm.what.substr(1, io_info.get(1).fs.CurrentTerm.what.size() - 1); // strip " 
		}
		if (device == "-1") {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwrite(stdout, \"%s\", %s);\n", parse_ioformatter(fmt).c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forwrite(get_file(%s), \"%s\", %s);\n", device.c_str(), parse_ioformatter(fmt).c_str(), argtable.fs.CurrentTerm.what.c_str());
		}
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_WRITE_STMT, string(codegen_buf) };
	return;
}
void regen_print(ParseNode & stmt) {
	const ParseNode & io_info = stmt.get(0);
	const ParseNode & argtable = stmt.get(1);
	if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		sprintf(codegen_buf, "forprintfree(%s);\n", argtable.fs.CurrentTerm.what.c_str());
	}
	else {
		string fmt;
		if (io_info.get(1).fs.CurrentTerm.token == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = get_context().labels[io_info.get(1).to_string()].to_string();
		}
		else {
			fmt = io_info.get(1).fs.CurrentTerm.what.substr(1, io_info.get(1).fs.CurrentTerm.what.size() - 1); // strip " 
		}
		sprintf(codegen_buf, "forprint(\"%s\", %s);\n", parse_ioformatter(fmt).c_str(), argtable.fs.CurrentTerm.what.c_str());
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_PRINT_STMT, string(codegen_buf) };
	return;
}
ParseNode gen_format(const ParseNode & format) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
	newnode.addchild(gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.fs.CurrentTerm.what + "\"" }) );
	return newnode;
}

//10.1.1 FORMAT statement
//R1001 format - stmt is FORMAT format - specification
//R1002 format - specification is([format - item - list])
//Constraint: The format - stmt must be labeled.
//	Constraint : The comma used to separate format - items in a format - item - list may be omitted as follows :
//(1) Between a P edit descriptor and an immediately following F, E, EN, ES, D, or G edit descriptor
//(10.6.5)
//(2) Before a slash edit descriptor when the optional repeat specification is not present(10.6.2)
//(3) After a slash edit descriptor
//(4) Before or after a colon edit descriptor(10.6.3)
//Blank characters may precede the initial left parenthesis of the format specification.Additional blank characters
//may appear at any point within the format specification, with no effect on the interpretation of the format
//specification, except within a character string edit descriptor(10.7.1, 10.7.2).
//Examples of FORMAT statements are :
//5 FORMAT(1PE12.4, I10)
//9 FORMAT(I12, / , ’ Dates : ’, 2 (2I3, I5))

//10.1.2 Character format specification
//A character expression used as a format specifier in a formatted input / output statement must evaluate to a
//character string whose leading part is a valid format specification.Note that the format specification begins with
//a left parenthesis and ends with a right parenthesis.
std::string parse_ioformatter(const std::string & src) {

	std::string rt = "";
	std::string descriptor;
	std::string prec;
	char buf[256];
	char ch;
	int stat = 0; /* stat == 0 repeat */
	std::vector<int> repeat;
	std::vector<int> repeat_from;
	repeat.push_back(1);
	bool add_crlf_at_end = true;
	for (int i = 0; i < src.size(); i++)
	{
		ch = tolower(src[i]);
		switch (ch)
		{
		case 'l':
			// bool
			descriptor = "%%c";
			stat = 1;
			break;
		case 'i':
			/* integer */
			descriptor = "%%%sd";
			stat = 1;
			break;
		case 'f':
			descriptor = "%%%sf";
			stat = 1;
			break;
		case 'e':
			descriptor = "%%%sf";
			stat = 1;
			break;
		case 'a':
			/* char */
			descriptor = "%%%ss";
			stat = 1;
			break;
		case 'x':
			/* space */
			descriptor += " ";
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
				// precision
				// have previous i, e, f, a, x, is component of std::string prec
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				prec = src.substr(i, j - i).c_str();
				i = j - 1;
			}
			else {
				// repeat 
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				// IMPORTANT in level repeat.size() - 1 BEFORE push_back, or will cause `rt += buf;` failure
				sscanf(src.substr(i, j - i).c_str(), "%d", &repeat[repeat.size() - 1]);
				i = j - 1;
			}
			break;
		case '.':
			if (stat == 1)
			{
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				prec += src.substr(i, j - i);
				i = j - 1;
			}
			else {

			}
			break;
		case ',':
			memset(buf, 0, sizeof(buf));
			sprintf(buf, descriptor.c_str(), prec.c_str()); // set precision(prec) specifier to descriptor
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			descriptor = "";
			stat = 0;
			break;
		case '(':
			// 此层的重复次数默认是1
			repeat.push_back(1);
			// 重复从'('的下一个字符开始
			repeat_from.push_back((int)rt.size());
			break;
		case ')':
			memset(buf, 0, sizeof(buf));
			sprintf(buf, descriptor.c_str(), prec.c_str()); // set precision(prec) specifier to descriptor
			// 重复最后一个字符
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			// pop stack repeat before repeat braced
			repeat.pop_back();
			{

				// 重复括号内部的项
				string braced = rt.substr(repeat_from.back(), i - repeat_from.back() + 1);
				for (int j = 1; j < repeat[repeat.size() - 1]; j++)
				{
					rt += braced;
				}
				braced = "";
			}

			repeat_from.pop_back();
			stat = 0;
			break;
		case '%':
			rt += "%%";
		case '/':
			rt += "\n";
		case '\\':
			add_crlf_at_end = false;
		case '\"':
			for (i++; i < src.size() && src[i] != '\"'; i++)
			{
				rt += src[i];
			}
		case '\'':
			for (i++; i < src.size() && src[i] != '\''; i++)
			{
				rt += src[i];
			}
			break;
		case '\n':
		{
			int start = i;
			for (i++; i < src.size() && src[i] != '*'; i++)
			{
				rt += src[i];
			}
			int leading_space = i - start - 1;
			rt += '\n';
			rt += string(leading_space, ' ');
			break;
		}
		default:
			break;
		}
	}
	memset(buf, 0, sizeof(buf));
	sprintf(buf, descriptor.c_str(), prec.c_str());
	for (int j = 0; j < repeat[repeat.size() - 1]; j++)
	{
		rt += buf;
	}
	if (add_crlf_at_end)
	{
		rt += "\\n";
	}
	return rt;
}
