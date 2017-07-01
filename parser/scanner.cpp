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

#include "tokenizer.h"
#include <iostream>
using namespace std;

bool isNumeric(char asc)
{
	return ((asc >= '0' && asc <= '9') || asc == '.');
}
string::iterator Jump(string & src, string::iterator c, int flag, char lb, char rb)
{
	int k = 0;
	bool inStr = false;
	for (; c != src.end(); c++) {
		if (*c == lb && !inStr) {
			k++;
		}
		else if (*c == rb && !inStr) {
			if (--k == flag) {
				return c;
			}
		}
		else if (*c == '\"')
		{
			inStr = !inStr;
		}
	}return c;
}

string CutString(string::iterator & b, string::iterator e, bool save, char jmp)
{
	if (b == e)
	{
		return "";
	}
	string rt;
	string::iterator pre = b;

	if (*b == jmp)
	{
		for (++b; b != e; b++)
		{
			if (*b != jmp)
			{
				break;
			}
		}
	}

	string::iterator lb = b;
	bool flag = false;

LABEL_BEGIN:
	if (*b == '\"')
	{
		rt = "\"";
		for (++b; b != e; b++)
		{
			if (*b == '\"')
			{
				b++;
				rt += '\"';
				break;
			}
			else if (*b == '\\')
			{
				switch (*(++b))
				{
				case '\"':
					rt += '\"';
					break;
				case '\n':
					rt += '\n';
					break;
				case '\r':
					rt += '\r';
					break;
				default:
					rt += *b;
					break;
				}
			}
			else
			{
				rt += *b;
			}
		}
		END_STR:
			   __nop();
	}
	else if (*b == '&')
	{
		if (*(b + 1) == '&')
		{
			rt = "&&";
			b += 2;
		}
		else
		{
			rt = "&";
			b++;
		}
	}
	else if (*b == '|')
	{
		if (*(b + 1) == '|')
		{
			rt = "||";
			b += 2;
		}
		else
		{
			rt = "|";
			b++;
		}
	}
	else if (*b == '<')
	{
		switch (*(b + 1))
		{
		case '>':
			//<>
			rt = string(b, b + 2);
			b += 2;
			break;
		case '=':
			//<=
			if (*(b + 2) == '>')
			{
				rt = string(b, b + 3);
				b += 3;
			}
			else
			{
				rt = string(b, b + 2);
				b += 2;
			}
			break;
		case '<':
			//<<
			if (*(b + 2) == '=')
			{
				rt = string(b, b + 3);
				b += 3;
				break;
			}
			else
			{
				rt = string(b, b + 2);
				b += 2;
				break;
			}
		default:
			rt =  string(b, b + 1);
			b++;
			break;
		}
	}
	else if (*b == '=')
	{
		switch (*(b + 1))
		{
		case '>':
			//=>
			rt =  string(b, b + 2);
			b += 2;
			break;
		case '=':
			//==
			rt =  string(b, b + 2);
			b += 2;
			break;
		case '<':
			//=<
			rt =  string(b, b + 2);
			b += 2;
			break;
		default:
			rt =  string(b, b + 1);
			b++;
			break;
		}
	}
	else if (*b == '>')
	{
		switch (*(b + 1))
		{
		case '>':
			//>>
			if (*(b + 2) == '=')
			{
				rt =  string(b, b + 3);
				b += 3;
				break;
			}
			else
			{
				rt =  string(b, b + 2);
				b += 2;
				break;
			}
		case '=':
			//>=
			rt =  string(b, b + 2);
			b += 2;
			break;
		case '<':
			//><
			rt =  string(b, b + 2);
			b += 2;
			break;
		default:
			rt =  string(b, b + 1);
			b++;
			break;
		}
	}
	else if (*b == '+' || *b == '-')
	{
		rt =  string(b, b + 1);
		for (b++; b != e; b++)
		{
			switch (*b)
			{
			case '+':
				continue;
			case '-':
				rt = (rt == "+") ? "-" : "+";
				continue;
			default:
				break;
			}
		}
	}
	else if (*b == '*' || *b == '/')
	{
		if (*(b + 1) == '=')
		{
			// not equal in fortran
			rt = string(b, b + 2);
			b += 2;
		}
		else {
			rt = string(b, b + 1);
			b++;
		}
	}
	else if (*b == '!')
	{
		rt =  string(b, b + 1);
		b++;
	}
	else if (*b == ':')
	{
		if (*(b + 1) == ':')
		{
			rt = "::";
			b += 2;
		}
		else
		{
			rt = ":";
			b++;
		}
	}
	else if (isNumeric(*b))
	{
		for (++b; b != e; b++)
		{
			if (!isNumeric(*b) && *b != '_')
			{
				break;
			}
		}
		//Exponent
		if (b != e && (*b == 'E' || *b == 'e'))
		{
			b++;
			if (*b == '+' || *b == '-')
			{
				b++;
			}
			for (b++; b != e; b++)
			{
				if (!isNumeric(*b) && *b != '_')
				{
					break;
				}
			}
		}

		rt =  string(lb, b);
	}
	else if ((*b >= 'A' && *b <= 'Z') || (*b >= 'a' && *b <= 'z'))
	{
		for (b++; b != e; b++)
		{
			char c = *b;
			if (!((*b >= 'A' && *b <= 'Z')
				|| (*b >= 'a' && *b <= 'z')
				|| (*b >= '0' && *b <= '9'))){
				rt =  string(lb, b);
				break;
			}
		}
	}
	else if (*b == '\n' || *b == '\r' || *b == '\t')
	{
		rt =  string(b, b + 1);
		b++;
	}
	else
	{
		rt =  string(b, b + 1);
		b++;
	}
	if (rt == "" && b == e)
	{
		rt =  string(lb, e);
	}
Ret:
	if (!save)
	{
		b = pre;
	}
	return rt;
};
