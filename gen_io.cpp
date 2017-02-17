#include "gen_common.h"

ParseNode gen_read(const ParseNode & io_info, const ParseNode & argtable) {
	ParseNode newnode = ParseNode();
	const ParseNode * pn = &argtable;
	ParseNode * formatter = io_info.child[1];
	string device = io_info.child[0]->fs.CurrentTerm.what;
	if (io_info.child[1]->fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		if (device == "-1" || device == "") {
			//device = "5"; // stdin
			sprintf(codegen_buf, "forreadfree(stdin, %s) ;", pn->fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forreadfree(get_file(%s), %s) ;", device.c_str(), pn->fs.CurrentTerm.what.c_str());
		}
	}
	else {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		if (device == "-1" || device == "") {
			//device = "5"; // stdin
			sprintf(codegen_buf, "forread(stdin, \"%s\", %s) ;", parse_ioformatter(fmt).c_str(), pn->fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forread(get_file(%s), \"%s\", %s) ;", device.c_str(), parse_ioformatter(fmt).c_str(), pn->fs.CurrentTerm.what.c_str());
		}
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}


ParseNode gen_write(const ParseNode & io_info, const ParseNode & argtable) {
	// brace is forced
	ParseNode newnode = ParseNode();
	const ParseNode * pn = &argtable;
	ParseNode * formatter = io_info.child[1];
	string device = io_info.child[0]->fs.CurrentTerm.what;
	if (io_info.child[1]->fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		if (device == "-1") {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwritefree(stdout, %s) ;", pn->fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forwritefree(get_file(%s), %s) ;", device.c_str(), pn->fs.CurrentTerm.what.c_str());
		}
	}
	else {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		if (device == "-1") {
			// device = "6"; // stdout
			sprintf(codegen_buf, "forwritefree(stdout, \"%s\\n\", %s) ;", parse_ioformatter(fmt).c_str(), pn->fs.CurrentTerm.what.c_str());
		}
		else {
			sprintf(codegen_buf, "forwrite(get_file(%s), \"%s\\n\", %s) ;", device.c_str(), parse_ioformatter(fmt).c_str(), pn->fs.CurrentTerm.what.c_str());
		}
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}
ParseNode gen_print(const ParseNode & io_info, const ParseNode & argtable) {

	ParseNode newnode = ParseNode();
	const ParseNode * pn = &argtable;
	if (io_info.child[1]->fs.CurrentTerm.token == TokenMeta::NT_AUTOFORMATTER) {
		sprintf(codegen_buf, "forprintfree(%s, \"\\n\") ;", pn->fs.CurrentTerm.what.c_str());
	}
	else {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		sprintf(codegen_buf, "forprint(\"%s\\n\", %s) ;", parse_ioformatter(fmt).c_str(), pn->fs.CurrentTerm.what.c_str());
	}
	newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}
ParseNode gen_format(const ParseNode & format) {
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.fs.CurrentTerm.what + "\"" });
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
	std::string s;
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
			s = "%%c";
			stat = 1;
			break;
		case 'i':
			/* integer */
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
			sprintf(buf, s.c_str(), prec.c_str());
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			s = "";
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
			sprintf(buf, s.c_str(), prec.c_str()); // prec is precision specifier
			// 重复最后一个字符
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			// pop stack repeat before repeat s
			repeat.pop_back();
			// 重复括号内部的项
			s = rt.substr(repeat_from.back(), i - repeat_from.back() + 1);
			for (int j = 1; j < repeat[repeat.size() - 1]; j++)
			{
				rt += s;
			}
			s = "";

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
	sprintf(buf, s.c_str(), prec.c_str());
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
