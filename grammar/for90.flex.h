#pragma once

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