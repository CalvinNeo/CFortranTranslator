#include "tokenizer.h"
#include "grammar\for90.tab.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

const vector<KeywordMeta> keywords = {
	// .what keyword
	// .token keyword as intent
	// .yytoken yacc terminal

	KeywordMeta{"if"
		, TokenMeta::If
		, YY_IF
	}
	, KeywordMeta{"then"
		, TokenMeta::META_ANY
		, YY_THEN
	}
	, KeywordMeta{"else"
		, TokenMeta::ElseLast
		, YY_ELSE
	}
	, KeywordMeta{"elseif"
		, TokenMeta::ElseIf
		, YY_ELSEIF
	}
	, KeywordMeta{"end"
		, TokenMeta::RBrace
		, YY_END
	}
	, KeywordMeta{"endif"
		, TokenMeta::RBrace
		, YY_ENDIF
	}
	, KeywordMeta{"endprogram"
		, TokenMeta::RBrace
		, YY_ENDPROGRAM
	}
	, KeywordMeta{"enddo"
		, TokenMeta::RBrace
		, YY_ENDDO
	}
	, KeywordMeta{"endwhere"
		, TokenMeta::RBrace
		, YY_ENDWHERE
	}
	, KeywordMeta{"endwhile"
		, TokenMeta::RBrace
		, YY_ENDWHILE
	}
	, KeywordMeta{"endfunction"
		, TokenMeta::RBrace
		, YY_ENDFUNCTION
	}
	, KeywordMeta{"endblock"
		, TokenMeta::RBrace
		, YY_ENDBLOCK
	}
	, KeywordMeta{"endcase"
		, TokenMeta::RBrace
		, YY_ENDCASE
	}
	, KeywordMeta{"endsubroutine"
		, TokenMeta::RBrace
		, YY_ENDSUBROUTINE
	}
	, KeywordMeta{"endmodule"
		, TokenMeta::RBrace
		, YY_ENDMODULE
	}
	, KeywordMeta{"do"
		, TokenMeta::Do
		, YY_DO
	}
	, KeywordMeta{"dowhile"
		, TokenMeta::While
		, YY_DOWHILE
	}
	, KeywordMeta{"exit"
		, TokenMeta::Break
		, YY_BREAK
	}
	, KeywordMeta{"cycle"
		, TokenMeta::Continue
		, YY_CONTINUE
	}
	, KeywordMeta{"while"
		, TokenMeta::While
		, YY_WHILE
	}
	, KeywordMeta{"where"
		, TokenMeta::META_ANY
		, YY_WHERE
	}
	, KeywordMeta{"case"
		, TokenMeta::Case
		, YY_CASE
	}
	, KeywordMeta{"program"
		, TokenMeta::META_ANY
		, YY_PROGRAM
	}
	, KeywordMeta{"function"
		, TokenMeta::META_ANY
		, YY_FUNCTION
	}
	, KeywordMeta{"recursive"
		, TokenMeta::META_ANY
		, YY_RECURSIVE
	}
	, KeywordMeta{"result"
		, TokenMeta::META_ANY
		, YY_RESULT
	}
	, KeywordMeta{"subroutine"
		, TokenMeta::META_ANY
		, YY_SUBROUTINE
	}
	, KeywordMeta{"module"
		, TokenMeta::META_ANY
		, YY_MODULE
	}
	, KeywordMeta{"block"
		, TokenMeta::META_ANY
		, YY_BLOCK
	}
	, KeywordMeta{"implicit"
		, TokenMeta::META_ANY
		, YY_IMPLICIT
	}
	, KeywordMeta{"none"
		, TokenMeta::META_ANY
		, YY_NONE
	}
	, KeywordMeta{"use"
		, TokenMeta::META_ANY
		, YY_USE
	}
	, KeywordMeta{"parameter"
		, TokenMeta::META_ANY
		, YY_PARAMETER
	}
	, KeywordMeta{"format"
		, TokenMeta::META_ANY
		, YY_FORMAT
	}
	, KeywordMeta{"and" 
		, TokenMeta::AndAnd
		, YY_ANDAND
	}
	, KeywordMeta{".or."
		, TokenMeta::OrOr
		, YY_OROR
	}
	, KeywordMeta{".not."
		, TokenMeta::Not
		, YY_NOT
	}
	, KeywordMeta{".eqv."
		, TokenMeta::META_ANY
		, YY_EQV
	}
	, KeywordMeta{".neqv"
		, TokenMeta::META_ANY
		, YY_NEQV
	}
	, KeywordMeta{".true."
		, TokenMeta::True
		, YY_TRUE
	}
	, KeywordMeta{".false."
		, TokenMeta::False
		, YY_FALSE
	}
	, KeywordMeta{".gt."
		, TokenMeta::GT
		, YY_GT
	}
	, KeywordMeta{".ge."
		, TokenMeta::GE
		, YY_GE
	}
	, KeywordMeta{".lt."
		, TokenMeta::LT
		, YY_LT
	}
	, KeywordMeta{".le."
		, TokenMeta::LE
		, YY_LE
	}
	, KeywordMeta{".eq."
		, TokenMeta::EQ
		, YY_EQ
	}
	, KeywordMeta{".neq."
		, TokenMeta::NEQ
		, YY_NEQ
	}
	, KeywordMeta{ "real"
		, TokenMeta::Float_Def
		// YY_FLOAT 指的是一个float类型的常量
		// YY_FLOAT_T 是float类型声明符
		, YY_FLOAT_T
	}
	, KeywordMeta{ "integer"
		, TokenMeta::Int_Def
		, YY_INTEGER_T
	}
	, KeywordMeta{ "logical"
		, TokenMeta::Bool_Def
		, YY_BOOL_T
	}
	, KeywordMeta{ "complex"
		, TokenMeta::Complex_Def
		, YY_COMPLEX_T
	}
	, KeywordMeta{ "character"
		, TokenMeta::String_Def
		, YY_STRING_T
	}
	, KeywordMeta{ "print"
		, TokenMeta::META_ANY
		, YY_PRINT
	}
	, KeywordMeta{ "write"
		, TokenMeta::META_ANY
		, YY_WRITE
	}
	, KeywordMeta{ "read"
		, TokenMeta::META_ANY
		, YY_READ
	}
	, KeywordMeta{ "open"
		, TokenMeta::META_ANY
		, YY_OPEN
	}
	, KeywordMeta{ "close"
		, TokenMeta::META_ANY
		, YY_CLOSE
	}
	, KeywordMeta{ "dimension"
		, TokenMeta::META_ANY
		, YY_DIMENSION
	}
	, KeywordMeta{ "intent"
		, TokenMeta::META_ANY
		, YY_INTENT
	}
	, KeywordMeta{ "in"
		, TokenMeta::META_ANY
		, YY_IN
	}
	, KeywordMeta{ "out"
		, TokenMeta::META_ANY
		, YY_OUT
	}
	, KeywordMeta{ "inout"
		, TokenMeta::META_ANY
		, YY_INOUT
	}
	, KeywordMeta{ "optional"
		, TokenMeta::META_ANY
		, YY_OPTIONAL
	}
	, KeywordMeta{ "select"
		, TokenMeta::Switch
		, YY_SELECT
	}
	, KeywordMeta{ "default"
		, TokenMeta::Default
		, YY_DEFAULT
	}
	, KeywordMeta{ "len"
		, TokenMeta::META_ANY
		, YY_LEN
	}
	, KeywordMeta{ "kind"
		, TokenMeta::META_ANY
		, YY_KIND
	}
};


const std::map<std::string, std::vector<std::string> > forward1 = {
	{"else", {"if"}}
	, {"do",{ "while" }}
};