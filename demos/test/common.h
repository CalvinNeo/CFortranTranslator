#pragma once

#include <gtest/gtest.h>
#include "parser/tokenizer.h"
#include "grammar/simple_lexer.h"
#include "parser/attribute.h"
#include "grammar/for90.tab.h"
#include "parser/parser.h"
#include "target/gen_common.h"
#include "parser/Function.h"


void ResetToken(std::string code, bool is_new_line = true){
	get_tokenizer_state() = TokenizerState{};
	get_tokenizer_state().parse_line = 1;
	reset_tokenizer_context();

	get_simpler_context().code = code;
	get_simpler_context().newline_marker = is_new_line;
}

void ResetParser(std::string code){
	reset_parser();
	ResetToken(code, true);
	do_trans(code);
}