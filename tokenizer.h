#pragma once
#include <string>

enum TokenMeta {
//Operators or idents with priorities
	TypeCast = 162,

	PostInc = 140,//++ i
	PostDec = 141,//-- i
	Inc = 142,
	Dec = 143,

	Not = 130,
	Neg = 131, // -
	ShortWave = 134, //~

	Power = 100,

	Multiply = 90,
	MultiplyVirtual = 92,
	Divide = 91,
	Mod = 93,

	Add = 80,
	Minus = 81,
	MinusVirtual = 82,

	GT = 60,
	GE = 61,
	EQ = 62,
	LE = 63,
	LT = 64,
	NEQ = 65,
	EQV = 66,
	NEQV = 67,

	AndAnd = 30,
	OrOr = 20,

	Nop = 0,

	LB = -1,//(
	RB = -2,//)
	SLB = -3,//[
	SRB = -4,//]
	Dot = -5, // .
	DoubleColon = -6,//::
	Comma = -7,//,
	Colon = -8,//:

	//Generic
	META_WORD = -10,
	META_INTEGER = -11,
	META_STRING = -12,
	META_CHARACTER = -13,
	META_FLOAT = -14,
	META_OPERATOR = -15,
	META_ILLEGAL = -16,


	LBrace = -23,//{
	RBrace = -24,//}
	VacantArg = -26,//参数为空

	Null = -30,
	True = -31,
	False = -32,
	Return = -35,
	Semicolon = -36,//,
	Include = -37,
	Comments = -38,// /*
	CommentsEnd = -39,// */
	CommentLine = -40,// //

//Describer

	Const = -52,
	Static = -53,
	Function = -60,
	Extern = -61,

//Build-in Type decl

	Int = META_INTEGER,
	Char = -83,//type
	String = META_STRING,
	Double = META_FLOAT,
	Bool = -87,
	Complex = -88,

//system
	CRLF = -93,
	Stop = -94,//For Debug
	Label = -96,//书签
	EndOfScan = -98, //表示Scanning读取结束
	End = -99,//程序结束

//Flow-Control
	If = -241,
	Else = -242,
	While = -243,
	For = -244,
	Goto = -245,
	Continue = -246,
	Break = -247,
	ElseLast = -248,
	JumpTrue = -249,
	JumpFalse = -250,
	Do = -254,
	Switch = -255,
	Case = -256,
	Default = -257,
	JumpNoJudge = -300,

};

struct Term {
	TokenMeta token;
	std::string what;
};


#define USE_YACC

Term make_term(const TokenMeta & token, std::string w);
Term make_term(const TokenMeta & token, const char * w);

#ifdef USE_YACC
#else
//// flex part code
//// implement in for90.l
//int make_term_flex(const TokenMeta & token, const char * w);
#endif
struct FlexState {
	Term CurrentTerm;
	int parse_pos;
	int parse_line;
	int parse_len;
	int line_pos;
	bool isnull = false;
};
FlexState next_token(const std::string & in_str, int start = 0); 
FlexState iter_token(const std::string & in_str, int start);

// yacc part code
// implement in for90.y
#define YYSTYPE FlexState
int parse(std::string code);