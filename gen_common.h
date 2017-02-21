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
#include "attribute.h"
#include "parser.h"
#include "gen_config.h"
#include "Function.h"
#include "codegen.h"
#include <vector>
#include <string>

using namespace std;

// use static instead of extern will make build fast
#ifdef _DEBUG
static char codegen_buf[MAX_CODE_LENGTH]; 
#else
extern char codegen_buf[MAX_CODE_LENGTH];
#endif
