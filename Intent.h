#pragma once

//namespace IntentMeta {
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

		New = -131,
		Delete = -132,
		Is = -135,
		Construct = -136,
		TypeDef = -137,
		Define = -138,
		Using = -139,
		Duplicate = -140,
		
		Stop = -150,//For Debug


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
		Function = -210, //TODO function声明 用于匿名函数等
		Extern = -211,
		Partial = -212,
		Final = -213,
		Readonly = -214,
		Region = -215,
		/*
		readonly is dynamic but can not change its value
		const is static
		readonly is not used,as it is replaced by final
		readonly是运行时动态分配的量,其值不可改变
		const是静态分配的量,其值不可改变
		readonly不再使用,因为被final代替
		*/
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

		// 标注变量类型(变量表)
		Void = -320,
		Obj = -321,
		Int = META_INTEGER,
		Char = -323,//type
		String = META_STRING,
		Double = META_FLOAT,
		Dynamic = -326,
		Bool = -327,
		Pointer = -328, // 声明指针类型
		Float = META_FLOAT,
		Long = -330,
		Complex = -331,
		Short = -332,

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

		//Flow-Control
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

		// system
		CRLF = -1000,
		InnerData = -1002,
		Label = -1003,//书签
		Sharp = -1004,//#号,表示预处理
		EndOfScan = -1005, //表示Scanning读取结束
		End = -1006,//程序结束
		not_a_token = -1007,
		Comments = -1008,// /*
		CommentsEnd = -1009,// */
		CommentLine = -1010,// //
		Include = -1011,

	};
//}


struct KeywordMeta {
	std::string what;
	int token;
	int yytoken;
};