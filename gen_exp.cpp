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

void regen_exp(FunctionInfo * finfo, ARG_OUT exp) {
	if (exp.get_token() == TokenMeta::NT_EXPRESSION)
	{
		if (exp.length() == 2)
		{
			// unary op
			regen_exp(finfo, exp.get(0));
		}
		else if (exp.length() == 3) {
			// binary op
			regen_exp(finfo, exp.get(0));
			regen_exp(finfo, exp.get(1));
		}
		else if (exp.length() == 1) {
			// function_array, array_builder, hidden_do
			ParseNode & elem = exp.get(0);
			switch (elem.get_token())
			{
			case TokenMeta::NT_HIDDENDO:
				break;
			case TokenMeta::NT_ARRAYBUILDER:
				break;
			default:
				print_error("error exp: ", exp);
				break;
			}
		}
		else if (exp.length() == 0) {
			print_error("error empty exp: ", exp);
		}
		else {
			print_error("error exp: ", exp);
		}
	}
	else if(is_literal(exp))
	{

	}
	else if (exp.get_token() == TokenMeta::UnknownVariant)
	{
		check_implicit_variable(finfo, exp.to_string());
	}
	else if (exp.get_token() == TokenMeta::NT_FUCNTIONARRAY)
	{
		
	}
	else {
		print_error("error exp: ", exp);
	}
}