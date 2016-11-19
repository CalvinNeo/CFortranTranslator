#include "gen_common.h"

ParseNode gen_read(const ParseNode & io_info, const ParseNode & argtable) {
	ParseNode newnode = ParseNode();
	const ParseNode * argtbl = &argtable;
	ParseNode * formatter = io_info.child[1];
	if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		string pointer_to;
		for (int i = 0; i < argtbl->child.size(); i++)
		{
			if (i > 0) {
				pointer_to += ",";
			}
			pointer_to += "&";
			pointer_to += argtbl->child[i]->fs.CurrentTerm.what;
		}
		argtbl = argtbl->child[1];
		sprintf(codegen_buf, "scanf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), pointer_to.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	}
	else {
		/* NT_AUTOFORMATTER */
		string cincode = "cin";
		/* enumerate argtable */
		// TODO the while loop is wrong, there is need for while loop. ref: var_def code
		//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
		// for all non-flatterned argtable
		for (int i = 0; i < argtbl->child.size(); i++)
		{
			// for each variable in flatterned argtable
			cincode += " >> ";
			cincode += argtbl->child[i]->fs.CurrentTerm.what;
		}
		// argtbl = argtbl->child[1];
		//}
		cincode += ";";
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, cincode };
	}
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}


ParseNode gen_write(const ParseNode & io_info, const ParseNode & argtable) {
	// brace is forced
	ParseNode newnode = ParseNode();
	const ParseNode * argtbl = &argtable;
	ParseNode * formatter = io_info.child[1];
	if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		sprintf(codegen_buf, "printf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	}
	else {
		/* NT_AUTOFORMATTER */
		string coutcode = "cout";
		/* enumerate argtable */
		// TODO the while loop is wrong, there is need for while loop. ref: var_def code
		//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
		// for all non-flatterned argtable
		for (int i = 0; i < argtbl->child.size(); i++)
		{
			// for each variable in flatterned argtable
			coutcode += " << ";
			coutcode += argtbl->child[i]->fs.CurrentTerm.what;
		}
		// argtbl = argtbl->child[1];
		//}
		coutcode += " << endl;";
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
	}
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
}
ParseNode gen_print(const ParseNode & io_info, const ParseNode & argtable) {

	ParseNode newnode = ParseNode();
	const ParseNode * argtbl = &argtable;
	ParseNode * formatter = io_info.child[1];
	if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
		string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
		sprintf(codegen_buf, "printf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
	}
	else {
		/* NT_AUTOFORMATTER */
		string coutcode = "cout";
		/* enumerate argtable */
		// TODO the while loop is wrong, there is need for while loop. ref: var_def code
		//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
		// for all non-flatterned argtable
		for (int i = 0; i < argtbl->child.size(); i++)
		{
			// for each variable in flatterned argtable
			coutcode += " << ";
			coutcode += argtbl->child[i]->fs.CurrentTerm.what;
		}
		// argtbl = argtbl->child[1];
		//}
		coutcode += " << endl;";
		newnode.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
	}
	newnode.addchild(new ParseNode(io_info)); // ioinfo
	newnode.addchild(new ParseNode(argtable)); // argtable
	return newnode;
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
		case 'l':
			// bool
			s = "%%c";
			stat = 1;
			break;
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
				// have previous i, e, f, a, x, is component of std::string mid
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				mid = src.substr(i, j - i).c_str();
				i = j - 1;
			}
			else {
				int j = i + 1;
				for (; j < src.size() && src[j] >= '0' && src[j] <= '9'; j++);
				// IMPORTANT in level repeat.size() - 1 BEFORE push_back, or will cause `rt += buf;` failure
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
			sprintf(buf, s.c_str(), mid.c_str()); // mis is precision specifier
												  // handle`1` of `1X`
			for (int j = 0; j < repeat[repeat.size() - 1]; j++)
			{
				rt += buf;
			}
			// pop stack repeat before repeat s
			repeat.pop_back();
			s = rt.substr(repeat_from.back(), i - repeat_from.back() + 1);
			for (int j = 1; j < repeat[repeat.size() - 1]; j++)
			{
				rt += s;
			}
			s = "";
			/* because s is empty so no need to jump ',' */
			//for (; i < s.size() && s[i] != ','; i++);
			//i--;
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
