#pragma once

// export functions and types

//struct yy_buffer_state
//{
//	FILE *yy_input_file;
//	char *yy_ch_buf;
//	char *yy_buf_pos;
//	size_t yy_buf_size;
//	size_t yy_n_chars;
//	int yy_is_our_buffer;
//	int yy_is_interactive;
//	int yy_at_bol;
//	int yy_bs_lineno;
//	int yy_bs_column;
//	int yy_fill_buffer;
//	int yy_buffer_status;
//};
//typedef size_t yy_size_t;
//typedef yy_buffer_state *YY_BUFFER_STATE;
//void yy_delete_buffer(YY_BUFFER_STATE b);
//YY_BUFFER_STATE yy_scan_buffer(char *base, yy_size_t size);
//extern FlexState flex_state;

//enum TokenMeta {
//	xxxW1 = 1,
//	xxxW2 = 2
//};
//struct Term {
//	TokenMeta token;
//	std::string what;
//};
//struct FlexState {
//	Term CurrentTerm;
//	int parse_pos;
//	int parse_line;
//	int parse_len;
//	int line_pos;
//	bool isnull = false;
//};
//union XXSTR {
//	std::string x;
//	XXSTR() = default;
//	~XXSTR() = default;
//};
//union YYSTR {
//	int a;
//}
//
//YYSTR testunion() {
//	return YYSTR();
//}

//for (int i = 0; i < keywords.size(); i++)
//{
//	if (keywords[i].what == yytextstr) {
//		//	// 
//		//	map<string, vector<string>>::iterator mapf = forward1.find(flex_state.CurrentTerm.what);
//		//	map<string, vector<string>>::iterator mapself = forward1.find(yytextstr);
//		//	if (mapf != forward1.end()) {
//		//		// 如果yytextstr前面是forward1里面的key, 例如if, 此时flex_state(等于else) 比 fs(等于if) 要提前一个token
//		//		if (find(mapf->second.begin(), mapf->second.end(), yytextstr) != mapf->second.end()) {
//		//			// 构成归约
//		//		}
//		//		else {
//		//			// 不构成归约
//		//		}
//		//	}
//		//	else if (mapself != forward1.end()) {
//		//		// do not update yylval because need to look ahead
//		//		// e.g else | if
//		//		update_yylval(yyleng, Term{ keywords[i].token , std::string(yytextstr) });
//		//		return YY_REQ_MORE;
//		//	}
//		//	else {
//		update_yylval(Term{ keywords[i].token , std::string(yytextstr) });
//		return keywords[i].yytoken;
//		//}
//	}
//}