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

#include "Intent.h"

namespace IntentMeta {
bool iselement(TokenMeta_T x) {
	if (x == IntentMeta::META_WORD) return true;
	if (isliteral(x)) return true;
	if (x == IntentMeta::Bool) return true;
	if (x == IntentMeta::UnknownVariant) return true;
	return false;
}
bool isliteral(TokenMeta_T x) {
	if (x == IntentMeta::META_INTEGER) return true;
	if (x == IntentMeta::META_STRING) return true;
	if (x == IntentMeta::META_CHARACTER) return true;
	if (x == IntentMeta::META_REAL) return true;
	if (x == IntentMeta::META_COMPLEX) return true;
	if (x == IntentMeta::True) return true;
	if (x == IntentMeta::False) return true;
	return false;
}
}