#pragma once

//namespace IntentMeta {
	//enum class IntentMeta {
	enum IntentMeta {
		// META Type
		META_WORD = -500,
		META_INTEGER = -501,
		META_STRING = -502,
		META_CHARACTER = -503,
		META_FLOAT = -504,
		META_OPERATOR = -505,
		META_ILLEGAL = -506,
		META_ANY = -510, // 尚未解析的Intent

		// Operator
		// in priority order
		Pointer = 160,
		Reference = 161,

		TypeCast = 162,

		PostInc = 140, //++ i
		PostDec = 141, //-- i
		Inc = 142,
		Dec = 143,

		Not = 130,
		Neg = 131,
		PreInc = 132, //i++
		PreDec = 133, //i--
		ShortWave = 134, //~

		Power = 100,

		Multiply = 90,
		MultiplyVirtual = 92,
		Divide = 91,
		Mod = 93,

		Add = 80,
		Minus = 81,
		MinusVirtual = 82,

		Shl = 70,
		Shr = 71,

		GT = 60,
		GE = 61,
		EQ = 62,
		LE = 63,
		LT = 64,
		NEQ = 65,
		Compare = 66,
		In = 67,
		EQV = 68,
		NEQV = 69,

		And = 50,
		AndVirtual = 51,

		Or = 40,

		AndAnd = 30,
		OrOr = 20,

		Let = 1,
		LetAdd = 2,
		LetMinus = 3,
		LetMultiply = 4,
		LetDivide = 5,
		LetShl = 6,
		LetShr = 7,
		LetAnd = 8,
		LetOr = 9,

		Nop = 0, //Parse时表示一个不合法的字符, 或者在VM中作为占位符

		LB = -1,//(
		RB = -2,//)
		SLB = -3,//[
		SRB = -4,//]
		Dot = -5,
		DoubleColon = -6,//::
		Comma = -7,//,
		Colon = -8,//:

		// VM Commands
		OperatorCall = -14, //operator() 函数调用
		CallArgs = -15,
		Duplicate = -16,
		HyperFuncCall = -17, //高阶函数f()()
		PushPointer = -18,
		PushVar = -19,
		PushLiteralConst = -20,
		SystemFunction = -21,
		DynamicVariable = -22,//Heap中的指针
		LBrace = -23, //{
		RBrace = -24, //}
		PushExtern = -25, //闭包 StaticBind
		VacantArg = -26, //参数为空
		Operator = -27,
		Lambda = -28,
		SetReturnValue = -29,
		Null = -30,
		True = -31,
		False = -32,
		New = -33,
		Delete = -34,
		Return = -35,
		Semicolon = -36,//;
		Include = -37,
		Comments = -38,// /*
		CommentsEnd = -39,// */
		CommentLine = -40,// //
		Is = -41,
		JumpNoJudge = -42,
		Construct = -43,
		TypeDef = -44,
		Define = -45,
		Using = -46,
		Region = -47,

		//Describer
		Virtual = -51,
		Const = -52,
		Static = -53,
		Public = -54,
		Private = -55,
		Protected = -56,
		Friend = -57,
		Class = -58,
		NameSpace = -59,
		Function = -60,
		Extern = -61,
		Partial = -62,
		Final = -63,
		Readonly = -64,
		/*
		readonly is dynamic but can not change its value
		const is static
		readonly is not used,as it is replaced by final
		readonly是运行时动态分配的量,其值不可改变
		const是静态分配的量,其值不可改变
		readonly不再使用,因为被final代替
		*/
		Enum = -65,
		Abstract = -66,

		//Build-in Type

		Void = -80,
		Obj = -81,
		Int = META_INTEGER,
		Char = -83,//type
		String = META_STRING,
		Double = META_FLOAT,
		Dynamic = -86,
		Bool = -87,
		PointerDef = -88, // 声明指针类型
		Float = -89,
		Long = -90,
		Complex = -91,

		//system
		CRLF = -93,
		Stop = -94,//For Debug
		InnerData = -95,
		Label = -96,//书签
		Sharp = -97,//#号,表示预处理
		EndOfScan = -98, //表示Scanning读取结束
		End = -99,//程序结束
		not_a_token = -100,


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
		Try = -251,
		Catch = -252,
		Finally = -253,
		Do = -254,
		Switch = -255,
		Case = -256,
		Default = -257,

	};
//}