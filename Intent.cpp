#include "Intent.h"

namespace IntentMeta {
bool iselement(TokenMeta_T x) {
	if (x == IntentMeta::META_WORD) return true;
	if (x == IntentMeta::META_INTEGER) return true;
	if (x == IntentMeta::META_STRING) return true;
	if (x == IntentMeta::META_CHARACTER) return true;
	if (x == IntentMeta::META_FLOAT) return true;
	if (x == IntentMeta::META_COMPLEX) return true;
	if (x == IntentMeta::True) return true;
	if (x == IntentMeta::False) return true;
	if (x == IntentMeta::Bool) return true;
	if (x == IntentMeta::UnknownVariant) return true;
	return false;
}
}