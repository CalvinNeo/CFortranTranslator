#pragma once
#include "IntentHelper.h"
#include <string>

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

		Nop = 0, //Parseʱ��ʾһ�����Ϸ����ַ�, ������VM����Ϊռλ��

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

		OperatorCall = -110, //operator() ��������
		CallArgs = -111,
		HyperFuncCall = -112, //�߽׺���f()()
		VacantArg = -113, //����Ϊ��
		Lambda = -114,
		Operator = -115, //operator+-*.��, ռλ��
		Return = -116,
		SetReturnValue = -117,

		PushPointer = -120,
		PushVar = -121,
		PushLiteralConst = -122, // ��LovalV���س���
		PushExtern = -123, // �ڱհ������� StaticBind ����
		SystemFunction = -124, // ����ϵͳ���ú���
		DynamicVariable = -125, //Heap�е�ָ��
		UnknownVariant = -126, //��δ��λ���ű�ı���

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
		META_ANY = -308, // ��δ������Intent
		META_REQ_MORE = -309, // �ʷ���������Ҫ������Ϣ(Look Ahead)
		META_NONTERMINAL = -310, // ���ս��, ��NT_ϸ��
		META_COMPLEX = -311,
		META_VOID = -312,

		// ��ע��������(������)
		Void = META_VOID,
		Obj = -321,
		Int = META_INTEGER,
		Char = -323,//type
		String = META_STRING,
		Double = META_FLOAT,
		Dynamic = -326,
		Bool = -327,
		Pointer = -328, // ����ָ������
		Float = META_FLOAT,
		Long = -330,
		Complex = -331,
		Short = -332,
		Function = -333, //TODO function���� ��������������

		// �������� -400~-500
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

		// system
		CRLF = -1000,
		Label = -1003,//��ǩ
		Sharp = -1004,//#��,��ʾԤ����
		EndOfScan = -1005, //��ʾScanning��ȡ����
		End = -1006,//�������
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
		/* ��fortran��������, �����Ĳ�������������������, ������ʵ�ʶ����ں�������, ���Է����Cʱ, ��Ҫ���ⲿ�ֶ������ᵽ��������, ��ʱ��Դ���ĺ������岻��NT_VARIABLEINITIAL����NT_DECLAREDVARIABLE */	
		NT_SUITE = -2014,
		NT_FUCNTIONARRAY = -2015,
		NT_ARRAYBUILDER_VALUE = -2016, /* ʹ�ó�ʼ���б��ʼ������ */
		NT_ARRAYBUILDER_EXP = -2017, /* ʹ�ò���ʽ��ʼ������ */
		NT_DIMENSLICE = -2018, /* 1:2, 3:4 */
		NT_ARGTABLE_DIMENSLICE = -2019, /* 1:2, 3:4 */
		NT_SLICE = -2020,
		NT_VARIABLEDESC = -2021,
		NT_VARIABLEINITIALDUMMY = -2022, /* dummy initial_value of (varname, initial_value) ref NT_VARIABLEINITIAL */
		/* NT_ARGTABLE �� NT_ARGTABLE_DIMENSLICE ��Ӧ�����������Ĳ����� */
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

		NT_DUMMY = -9999,
};
}


struct KeywordMeta {
	std::string what;
	int token;
	int yytoken;
};
