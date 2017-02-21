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
#include "IntentHelper.h"
#include <string>


#define TokenMeta IntentMeta
#define TokenMeta_T int
namespace IntentMeta {
	//enum class IntentMeta {
	enum IntentMeta {

		// Operator
		// in priority order
		Dereference = 260,
		Reference = 261,

		TypeCast = 262,

		PostInc = 240, //++ i
		PostDec = 241, //-- i
		Inc = 242,
		Dec = 243,

		Not = 230,
		Neg = 231,
		PreInc = 232, //i++
		PreDec = 233, //i--
		ShortWave = 234, //~

		Power = 200,

		Multiply = 190,
		MultiplyVirtual = 192,
		Divide = 191,
		Mod = 193,

		Add = 180,
		Minus = 181,
		MinusVirtual = 182,

		Shl = 170,
		Shr = 171,

		GT = 160,
		GE = 161,
		EQ = 162,
		LE = 163,
		LT = 164,
		NEQ = 165,
		Compare = 166,
		In = 167,
		EQV = 168,
		NEQV = 169,

		And = 150,
		AndVirtual = 151,

		Or = 140,

		AndAnd = 130,
		OrOr = 120,

		Let = 101,
		LetAdd = 102,
		LetMinus = 103,
		LetMultiply = 104,
		LetDivide = 105,
		LetShl = 106,
		LetShr = 107,
		LetAnd = 108,
		LetOr = 109,

		Nop = 0, //Parse时表示一个不合法的字符, 或者在VM中作为占位符

		// non/special priority operators
		LB = -1, //(
		RB = -2, //)
		SLB = -3, //[
		SRB = -4, //]
		Dot = -5, //.
		DoubleColon = -6, //::
		Comma = -7, //,
		Colon = -8, //:
		LBrace = -9, //{
		RBrace = -10, //}
		Semicolon = -11,//;

		// VM Commands and constants -100~-200

		Null = -101,
		True = -102,
		False = -103,

		OperatorCall = -110, //operator() 函数调用
		CallArgs = -111,
		HyperFuncCall = -112, //高阶函数f()()
		VacantArg = -113, //参数为空
		Lambda = -114,
		Operator = -115, //operator+-*.等, 占位符
		Return = -116,
		SetReturnValue = -117,

		PushPointer = -120,
		PushVar = -121,
		PushLiteralConst = -122, // 像LovalV加载常量
		PushExtern = -123, // 在闭包函数中 StaticBind 变量
		SystemFunction = -124, // 调用系统内置函数
		DynamicVariable = -125, //Heap中的指针
		UnknownVariant = -126, //尚未定位符号表的变量

		New = -131,
		Delete = -132,
		Is = -135,
		Construct = -136,
		TypeDef = -137,
		Define = -138,
		Using = -139,
		Duplicate = -140,
		
		Stop = -150, // For Debug
		Format = -151, // fortran77 format commandd

		// Describer
		Virtual = -201,
		Const = -202,
		Static = -203,
		Public = -204,
		Private = -205,
		Protected = -206,
		Friend = -207,
		Class = -208,
		NameSpace = -209,
		Extern = -211,
		Partial = -212,
		Final = -213,
		Readonly = -214,
		Region = -215,
		/* readonly is dynamic but can not change its value, it is not used, as it is replaced by final. const is static  */
		Enum = -216,
		Abstract = -217,

		//Build-in Type
		// META Type(for parse)
		META_WORD = -301,
		META_INTEGER = -302,
		META_STRING = -303,
		META_CHARACTER = -304,
		META_FLOAT = -305,
		META_OPERATOR = -306,
		META_ILLEGAL = -307,
		META_ANY = -308, // 尚未解析的Intent
		META_REQ_MORE = -309, // 词法分析器需要更多信息(Look Ahead)
		META_NONTERMINAL = -310, // 非终结符, 由NT_细化
		META_COMPLEX = -311,
		META_VOID = -312,

		// 标注变量类型(变量表)
		Void = META_VOID,
		Obj = -321,
		Int = META_INTEGER,
		Char = META_CHARACTER, 
		String = META_STRING,
		Double = META_FLOAT,
		Dynamic = -326,
		Bool = -327, // no use because Bool is true + false
		Pointer = -328, // 声明指针类型
		Float = META_FLOAT,
		Long = -330,
		Complex = -331,
		Short = -332,
		Function = -333, //TODO function声明 用于匿名函数等

		// 变量声明 -400~-500
		Void_Def = Void - 100,
		Obj_Def = Obj - 100,
		Int_Def =  Int - 100,
		Char_Def = Char - 100,
		String_Def = String - 100,
		Double_Def = Double - 100,
		Dynamic_Def = Dynamic - 100,
		Bool_Def = Bool - 100,
		Pointer_Def = Pointer - 100,
		Float_Def = Float - 100,
		Long_Def = Long - 100,
		Complex_Def = Complex - 100,
		Short_Def = Short - 100,
		Function_Def = Function - 100,
		Implicit_Def = -599,

		// Flow-Control
		If = -600,
		Else = -601,
		ElseIf = Else,
		ElseLast = -202,
		While = -603,
		For = -604,
		Goto = -605,
		Continue = -606,
		Break = -607,
		JumpTrue = -608,
		JumpFalse = -609,
		JumpNoJudge = -610,
		Try = -611,
		Catch = -612,
		Finally = -613,
		Do = -614,
		Switch = -615,
		Case = -616,
		Default = -617,

		// parsing tags
		CRLF = -1000,
		Label = -1003,//标签
		Sharp = -1004,//#号,表示预处理
		EndOfScan = -1005, //表示Scanning读取结束
		End = -1006,//程序结束
		Error = -1007,
		Comments = -1008,// /*
		CommentsEnd = -1009,// */
		CommentLine = -1010,// //
		Include = -1011,


		NT_PARAMTABLE = -2001,
		NT_FORMATTER = -2002,
		NT_AUTOFORMATTER = -2003, /* the second `*` sign of write (*,*), xxx */
		NT_ARGTABLE = -2004,
		NT_FUNCTIONDECLARE = -2005,
		NT_VARIABLEDEFINE = -2006,  /* is a statement that can define a list of variables , such as int a = 2, b, c */
		NT_STATEMENT = -2007,
		NT_EXPRESSION = -2008,
		NT_IF = -2009,
		NT_ELSEIF = -2010,
		NT_DO = -2011,
		NT_VARIABLEINITIAL = -2012, /* is a variable define info, such as (varname, initial_value), or namely KEYVALUE */
		NT_DECLAREDVARIABLE = -2013, /* in programming languages such as fortran, function's paramtable declares the name but the type of parameters, the definition of parameters is placed in main structure of function */
		/* 在fortran类语言中, 函数的参数表不包含变量的类型, 参数的实际定义在函数体内, 所以翻译成C时, 需要将这部分定义外提到参数表中, 此时置源语句的函数定义不是NT_VARIABLEINITIAL而是NT_DECLAREDVARIABLE */	
		NT_SUITE = -2014,
		NT_FUCNTIONARRAY = -2015,
		NT_ARRAYBUILDER_LAMBDA = -2016, /*  */
		NT_ARRAYBUILDER_LIST = -2017, /*  */
		NT_DIMENSLICE = -2018, /* 1:2, 3:4 in `dimen_slice` level */
		NT_PARAMTABLE_DIMENSLICE = -2019, /* 1:2, 3:4 in `paramtable` level*/
		NT_SLICE = -2020,
		NT_VARIABLEDESC = -2021,
		NT_VARIABLEINITIALDUMMY = -2022, /* dummy initial_value of (varname, initial_value) ref NT_VARIABLEINITIAL */
		NT_VOID = -2023, /* this ParseNode do not exist but ParseNode * can not be nullptr so this is placeholder */
		NT_ARRAYBUILDER = -2024, /* mixed array builder */
		NT_ARGTABLE_PURE = -2025,
		NT_WRAPPER = -2026,
		NT_SELECT = -2027,
		NT_CASE = -2028,
		NT_CASES = -2029,
		NT_KEYVALUE = NT_VARIABLEINITIAL,
		NT_HIDDENDO = -2030,
		NT_WHILE = -2031,
		NT_OPEN = -2032,
		NT_CLOSE = -2033,
		NT_PROGRAM = -2034,
		NT_INTERFACE = -2035,
		NT_WRAPPERS = -2036,
		NT_PARAMTABLE_PURE = -2037,
		NT_FORMAT = -2038,
		NT_LABEL = -2039,
		NT_PROGRAM_EXPLICIT = -2040,
		NT_COMMONBLOCK = -2041,
		NT_COMMONBLOCKDEFINE = -2042,
		NT_VARIABLEDEFINESET = -2043,

		NT_DUMMY = -9999,
};

bool iselement(TokenMeta_T x);

}


struct KeywordMeta {
	std::string what;
	int token;
	int yytoken;
};
