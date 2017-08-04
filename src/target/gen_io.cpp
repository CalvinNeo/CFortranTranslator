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
#include "../../for90std/for90std.h"

for90std::IOFormat parse_ioformatter(const std::string & src);

std::string gen_io_argtable_str(FunctionInfo * finfo, ParseNode & argtable, std::string iofunc, bool is_free_format) {
	regen_paramtable(finfo, argtable);
	string res = make_str_list(argtable.begin(), argtable.end(), [&](ParseNode * p) {
		ParseNode & pn = *p;
		if (pn.get_token() == TokenMeta::NT_HIDDENDO)
		{
			// wrap with IOLambda
			regen_hiddendo_expr(finfo, pn, [&](ParseNode & innermost_argtable) {
				string return_str;
				return_str = make_str_list(innermost_argtable.begin(), innermost_argtable.end(), [&](ParseNode * p2) {
					ParseNode & return_item = *p2;
					regen_exp(finfo, return_item);
					if (iofunc == "read")
					{
						// read use pointer
						return "&" + return_item.get_what();
					}
					else {
						return return_item.get_what();
					}
				}); 
				// #define MAKE_IOSTUFF(X) make_iostuff(make_tuple(X)) 
				sprintf(codegen_buf, "return MAKE_IOSTUFF(%s);", return_str.c_str());
				innermost_argtable.get_what() = string(codegen_buf);
				return;
			});

			vector<ParseNode *> hiddendo_layer = get_nested_hiddendo_layers(pn);
			SliceBoundInfo lb_ub = get_lbound_ubound_from_hiddendo(finfo, pn, hiddendo_layer);
			std::string lb_ub_str = gen_sliceinfo_str(get<0>(lb_ub).begin(), get<0>(lb_ub).end(), get<1>(lb_ub).begin(), get<1>(lb_ub).end());
			//auto make_iolambda(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func) {
			//auto make_iolambda(fsize_t * _lb, fsize_t * _to, F func) {
			sprintf(codegen_buf, "make_iolambda(%s, %s)", lb_ub_str.c_str(), pn.get_what().c_str());
			return string(codegen_buf);
		}
		else {
			return pn.get_what();
		}
	});
	return res;
}

std::string gen_io_argtable_strex(FunctionInfo * finfo, ParseNode & argtable, std::string iofunc, bool is_free_format) {
	string res = make_str_list(argtable.begin(), argtable.end(), [&](ParseNode * p) {
		ParseNode & pn = *p;
		std::string current_index = "";
		std::function<void(ParseNode &)> handler = [&](ParseNode & innermost) {
			if (innermost.get_token() == TokenMeta::NT_HIDDENDO)
			{
				// wrap with IOLambda
				regen_hiddendo_exprex(finfo, innermost, handler);
				//auto make_iolambda(const fsize_t(&_lb)[D], const fsize_t(&_to)[D], F func) {
				//auto make_iolambda(fsize_t * _lb, fsize_t * _to, F func) {

				vector<ParseNode *> hiddendo_layer = get_parent_hiddendo_layers(innermost);
				//SliceBoundInfo lb_ub = get_lbound_ubound_from_hiddendo(finfo, pn, hiddendo_layer);
				SliceBoundInfo lb_ub;
				for (int i = (int)hiddendo_layer.size() - 1; i >= 0 ; i--)
				{
					if (i == 0)
					{
						// innermost
						regen_exp(finfo, hiddendo_layer[i]->get(2));
						regen_exp(finfo, hiddendo_layer[i]->get(3));
						get<0>(lb_ub).push_back(hiddendo_layer[i]->get(2).get_what());
						get<1>(lb_ub).push_back(hiddendo_layer[i]->get(3).get_what());
					}
					else {
						get<0>(lb_ub).push_back(hiddendo_layer[i]->get(1).get_what());
						get<1>(lb_ub).push_back(hiddendo_layer[i]->get(1).get_what());
					}
				}
				std::string lb_ub_str = gen_sliceinfo_str(get<0>(lb_ub).begin(), get<0>(lb_ub).end(), get<1>(lb_ub).begin(), get<1>(lb_ub).end());
				sprintf(codegen_buf, "make_iolambda(%s, %s)", lb_ub_str.c_str(), innermost.get_what().c_str());

				innermost.get_what() = string(codegen_buf);
			}
			else {
				regen_exp(finfo, innermost);
				if (iofunc == "read")
				{
					// read use pointer
					innermost.get_what() = "&" + innermost.get_what();
				}
				else {
				}
			}
			return;
		};

		handler(pn);
		return pn.get_what();
	});
	return res;
}

void regen_read(FunctionInfo * finfo, ParseNode & stmt) {
	const ParseNode & io_info = stmt.get(0);
	ParseNode & argtable = stmt.get(1);
	string device = io_info.get(0).to_string();
	bool is_stdio = (device == "-1" || device == "" || device == "0");
	std::string argtable_str = gen_io_argtable_strex(finfo, argtable, "read", io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER);

	if (argtable.length() == 0)
	{
		// a read-stmt without args are intented to pause
		// e.g. `read(*,*)`
		sprintf(codegen_buf, "stop();\n");
	}
	else if (io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER) {
		if (is_stdio) {
			// device = "5"; // stdin
			sprintf(codegen_buf, "forreadfree(stdin%s %s);\n", (argtable_str==""?"":","), argtable_str.c_str());
		}
		else {
			sprintf(codegen_buf, "forreadfree(get_file(%s)%s %s);\n", device.c_str(), (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
	}
	else {
		string fmt;
		string label_name = io_info.get(1).to_string();
		if (io_info.get(1).get_token() == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = require_format_index(finfo, label_name).to_string();
		}
		else {
		}
		fmt = fmt.substr(1, fmt.size() - 1); // strip " 
		for90std::IOFormat ioformat = parse_ioformatter(fmt);
		if (is_stdio) {
			// device = "5"; // stdin
			sprintf(codegen_buf, "forread(stdin, IOFormat{\"%s\", %d}%s %s);\n", ioformat.fmt.c_str()
				, ioformat.reversion_start, (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
		else {
			sprintf(codegen_buf, "forread(get_file(%s), IOFormat{\"%s\", %d}%s %s);\n", device.c_str()
				, ioformat.fmt.c_str(), ioformat.reversion_start, (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_READ_STMT, string(codegen_buf) };
	return;
}


void regen_write(FunctionInfo * finfo, ParseNode & stmt) {
	// brace is forced
	const ParseNode & io_info = stmt.get(0);
	ParseNode & argtable = stmt.get(1);
	string device = io_info.get(0).to_string();
	bool is_stdio = (device == "-1" || device == "" || device == "0");
	std::string argtable_str = gen_io_argtable_strex(finfo, argtable, "write", io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER);
	if (io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER) {
		if (is_stdio) {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwritefree(stdout%s %s);\n", (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
		else {
			sprintf(codegen_buf, "forwritefree(get_file(%s)%s %s);\n", device.c_str(), (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
	}
	else {
		string fmt;
		if (io_info.get(1).get_token() == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = require_format_index(finfo, io_info.get(1).to_string()).to_string();
		} else{
		}
		fmt = fmt.substr(1, fmt.size() - 1); // strip " 
		for90std::IOFormat ioformat = parse_ioformatter(fmt);
		if (is_stdio) {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwrite(stdout, IOFormat{\"%s\", %d}%s %s);\n", ioformat.fmt.c_str()
				, ioformat.reversion_start, (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
		else {
			sprintf(codegen_buf, "forwrite(get_file(%s), IOFormat{\"%s\", %d}%s %s);\n", device.c_str()
				, ioformat.fmt.c_str(), ioformat.reversion_start, (argtable_str == "" ? "" : ","), argtable_str.c_str());
		}
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_WRITE_STMT, string(codegen_buf) };
	return;
}

void regen_print(FunctionInfo * finfo, ParseNode & stmt) {
	const ParseNode & io_info = stmt.get(0);
	ParseNode & argtable = stmt.get(1);
	std::string argtable_str = gen_io_argtable_strex(finfo, argtable, "print", io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER);
	if (io_info.get(1).get_token() == TokenMeta::NT_AUTOFORMATTER) {
		sprintf(codegen_buf, "forprintfree(%s);\n", argtable_str.c_str());
	}
	else {
		string fmt;
		if (io_info.get(1).get_token() == TokenMeta::NT_FORMATTER_LOCATION)
		{
			fmt = require_format_index(finfo, io_info.get(1).to_string()).to_string();
		}
		else {
		}
		fmt = fmt.substr(1, fmt.size() - 1); // strip " 
		sprintf(codegen_buf, "forprint(\"%s\"%s %s);\n", parse_ioformatter(fmt).c_str(), (argtable_str == "" ? "" : ","), argtable_str.c_str());
	}
	stmt.fs.CurrentTerm = Term{ TokenMeta::NT_PRINT_STMT, string(codegen_buf) };
	return;
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

std::string add_escape_char(std::string s) {
	string r;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '\\':
		case '\'':
		case '\"':
			r += '\\';
			/* NO `break;` */
		default:
			r += s[i];
			break;
		}
	}
	return r;
}

//10.1.2 Character format specification
//A character expression used as a format specifier in a formatted input / output statement must evaluate to a
//character string whose leading part is a valid format specification.Note that the format specification begins with
//a left parenthesis and ends with a right parenthesis.
for90std::IOFormat parse_ioformatter(const std::string & src) {

	std::string rt = "";
	std::string descriptor;
	std::string prec;
	char buf[256];
	char ch;
	/********************
	*	stat == 0: this integer is repeat specification
	*	stat == 1: this integer is edit descriptor(w, m, d, e)
	********************/
	int stat = 0; 
	std::vector<int> repeat;
	std::vector<int> repeat_from;
	/********************
	*	`instant_defined = true` means this repeat counter is attached to a edit descriptor, e.g. `2I`,
	*	not a parenthesis, e.g. `2(I, F)`
	********************/
	bool instant_defined = false;
	bool add_crlf_at_end = true;
	int reversion_start = 0;
	for (int i = 0; i < src.size(); i++)
	{
		ch = tolower(src[i]);
		switch (ch)
		{
		case 'l':
			// bool
			descriptor = "%%c";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'i':
			/* integer */
			descriptor = "%%%sd";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'f':
			descriptor = "%%%sf";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'e':
			descriptor = "%%%sf";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'a':
			/* char */
			descriptor = "%%%ss";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'x':
			/* space */
			descriptor += " ";
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case 'h':
		{
			/*
			*	H-editing
			* nH means put next n characters after H into output
			*/
			int length = repeat.back(); 
			repeat.pop_back();
			repeat.push_back(1); // the H editing can't only be repeated
			string raw = src.substr(i + 1, length);
			rt += add_escape_char(raw);
			i = i + 1 + length;
			break;
		}
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
				instant_defined = true;
				int t = std::atoi(src.substr(i, j - i).c_str());
				repeat.push_back(t);
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
			for (int j = 0; j < repeat.back(); j++)
			{
				rt += buf;
			}
			descriptor = "";
			prec = "";
			repeat.pop_back();
			stat = 0;
			break;
		case '(':
			// every `( format-item-list )` repeat 1 time by default
			repeat.push_back(1);
			// 重复从'('的下一个字符开始
			repeat_from.push_back((int)rt.size());
			reversion_start = i;
			break;
		case ')':
			memset(buf, 0, sizeof(buf));
			sprintf(buf, descriptor.c_str(), prec.c_str()); // set precision(prec) specifier to descriptor
			// 重复最后一个字符
			if (descriptor != "")
			{
				for (int j = 0; j < repeat.back(); j++)
				{
					rt += buf;
				}
				descriptor = "";
				prec = "";
				repeat.pop_back();
			}
			{
				// 重复括号内部的项
				string braced = rt.substr(repeat_from.back(), i - repeat_from.back() + 1);
				for (int j = 1; j < repeat.back(); j++)
				{
					rt += braced;
				}
				braced = "";
				repeat.pop_back();
				repeat_from.pop_back();
			}

			stat = 0;
			break;
		case '%':
			rt += "%%";
			break;
		case '/':
			rt += "\\n";
			break;
		case '\\':
			add_crlf_at_end = false;
			break;
		case '\"':
			descriptor = "";
			for (i++; i < src.size() && src[i] != '\"'; i++)
			{
				if (src[i] != '\'') {
					descriptor += src[i];
				}
			}
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case '\'':
			descriptor = "";
			for (i++; i < src.size() && src[i] != '\''; i++)
			{
				if (src[i] != '\"') {
					descriptor += src[i];
				}
			}
			if (!instant_defined)
			{
				repeat.push_back(1);
			}
			stat = 1;
			instant_defined = false;
			break;
		case '\n':
		{
			int start = i;
			// line continuation
			for (i++; i < src.size() && src[i] == ' '; i++)
			{
				rt += src[i];
			}
			int leading_space = i - start - 1;
			//rt += '\\n';
			rt += string(leading_space, ' ');
			i++; // jump line continuation symbol
			break;
		}
		case ' ':
			//Blank characters may precede the initial left parenthesis of the format specification.Additional blank characters
			//	may appear at any point within the format specification, with no effect on the interpretation of the format
			//	specification, except within a character string edit descriptor(10.7.1, 10.7.2).
			break;
		default:
			break;
		}
	}
	memset(buf, 0, sizeof(buf));
	sprintf(buf, descriptor.c_str(), prec.c_str());
	rt += string(buf);
	if (add_crlf_at_end)
	{
		rt += "\\n";
	}
	return for90std::IOFormat(rt, reversion_start);
}
