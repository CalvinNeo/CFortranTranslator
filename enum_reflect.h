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

#pragma once

#include <cassert>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

#define ADD_ENUM(NAME, VALUE) NAME = VALUE
#define __MAKE_ENUM_DECL(T, ...) enum T {__VA_ARGS__}
#define __MAKE_ENUM_HELPER(STR) struct EnumTableHelper { 																\
		int EnumTableHelper::from_name(std::string name) { 																\
			std::map<std::string, int>::const_iterator iter = m.find(name); 											\
			assert(iter != m.end()); 																					\
			return iter->second; 																						\
		} 																												\
		std::string EnumTableHelper::from_value(int value) { 															\
			std::map<std::string, int>::const_iterator iter = 															\
				std::find_if(m.begin(), m.end() 																		\
					, [&](const std::pair<std::string, int> & p) {return p.second == value;  }); 						\
			assert(iter != m.end()); 																					\
			return iter->first; 																						\
		} 																												\
/*		void EnumTableHelper::make_enum_table(std::string str) { 														\
			size_t s = 0; 																								\
			std::string k, v; 																							\
			for (size_t i = 0; i < str.length(); i++) { 																\
				if (str[i] == ',')	{ 																					\
					v = str.substr(s, i - s); 																			\
					int xv;	sscanf(v.c_str(), "%d", &xv); 																\
					m[k] = xv;	s = i + 1; 																				\
				}else if (str[i] == '='){ 																				\
					k = str.substr(s, i - s); s = i + 1; 																\
				} 																										\
				else if (str[i] = ' ') {  } 																			\
				else {	} 																								\
			} 																											\
		} 		*/																										\
		EnumTableHelper() {																								\
			make_enum_table(m, input_str);																				\
		} 																												\
	protected:																											\
		std::map<std::string, int> m; 																					\
		const std::string input_str = #STR;																				\
	}; 																													\
	inline EnumTableHelper & get_enum_table() { 																		\
		static EnumTableHelper table; 																					\
		return table;																									\
	}
#define MAKE_ENUM(T, ...) __MAKE_ENUM_DECL(T, __VA_ARGS__); \
	__MAKE_ENUM_HELPER(__VA_ARGS__) 
// 注意不能在这里给__VA_ARGS__加上#，否则ADD_ENUM不能被展开


/*******************
*	name scope of tokens
*******************/
#define TokenMeta IntentMeta
//#define TokenMeta IntentMeta::IntentMeta_T
/*******************
*	type of tokens
*******************/
#define TokenMeta_T int
//#define TokenMeta_T IntentMeta::IntentMeta_T

namespace IntentMeta {
	inline void make_enum_table(std::map<std::string, int> & m, std::string str) {
		size_t s = 0;
		std::string k, v;
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == ',') {
				v = str.substr(s, i - s);
				int xv;	sscanf(v.c_str(), "%d", &xv);
				m[k] = xv;
				s = i + 1;
			}
			else if (str[i] == '=') {
				k = str.substr(s, i - s); s = i + 1;
			}
			else if (str[i] == ' ') {}
			else {}
		}
	}
}

