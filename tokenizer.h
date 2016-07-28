#pragma once
#include <string>

enum TokenMeta {
	TypeCast = 162,

	PostInc = 140,//++ i
	PostDec = 141,//-- i
	Inc = 142,
	Dec = 143,

	Not = 130,
	Neg = 131,
	ShortWave = 134,//~

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
	Dot = -5,
	DoubleColon = -6,//::
	Comma = -7,//,
	Colon = -8,//:

							//Generic
	Word = -10,
	Numeric = -11,
	Str = -12,
	Character = -13,


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

	Int = -82,
	Char = -83,//type
	String = -84,
	Double = -85,
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
	TokenMeta meta;
	std::string what;
};


Term make_term(const TokenMeta & token, std::string w);
Term make_term(const TokenMeta & token, const char * w);