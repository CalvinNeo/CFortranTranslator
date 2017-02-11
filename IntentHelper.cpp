#include "IntentHelper.h"
#include "Intent.h"
#include "tokenizer.h"
/*
([\w-]+) *= *([+-\d]+),
, {$2, "$1"}
*/

std::map<int, std::string> IntentName = {
	{ 260, "Dereference" }
	,{ 261, "Reference" }

	,{ 262, "TypeCast" }

	,{ 240, "PostInc" }
	,{ 241, "PostDec" }
	,{ 242, "Inc" }
	,{ 243, "Dec" }

	,{ 230, "Not" }
	,{ 231, "Neg" }
	,{ 232, "PreInc" }
	,{ 233, "PreDec" }
	,{ 234, "ShortWave" }

	,{ 200, "Power" }

	,{ 190, "Multiply" }
	,{ 192, "MultiplyVirtual" }
	,{ 191, "Divide" }
	,{ 193, "Mod" }

	,{ 180, "Add" }
	,{ 181, "Minus" }
	,{ 182, "MinusVirtual" }

	,{ 170, "Shl" }
	,{ 171, "Shr" }

	,{ 160, "GT" }
	,{ 161, "GE" }
	,{ 162, "EQ" }
	,{ 163, "LE" }
	,{ 164, "LT" }
	,{ 165, "NEQ" }
	,{ 166, "Compare" }
	,{ 167, "In" }
	,{ 168, "EQV" }
	,{ 169, "NEQV" }

	,{ 150, "And" }
	,{ 151, "AndVirtual" }

	,{ 140, "Or" }

	,{ 130, "AndAnd" }
	,{ 120, "OrOr" }

	,{ 101, "Let" }
	,{ 102, "LetAdd" }
	,{ 103, "LetMinus" }
	,{ 104, "LetMultiply" }
	,{ 105, "LetDivide" }
	,{ 106, "LetShl" }
	,{ 107, "LetShr" }
	,{ 108, "LetAnd" }
	,{ 109, "LetOr" }

	,{ 0, "Nop" }

	,{ -1, "LB" }
	,{ -2, "RB" }
	,{ -3, "SLB" }
	,{ -4, "SRB" }
	,{ -5, "Dot" }
	,{ -6, "DoubleColon" }
	,{ -7, "Comma" }
	,{ -8, "Colon" }
	,{ -9, "LBrace" }
	,{ -10, "RBrace" }
	,{ -11, "Semicolon" }

	,{ -101, "Null" }
	,{ -102, "True" }
	,{ -103, "False" }

	,{ -110, "OperatorCall" }
	,{ -111, "CallArgs" }
	,{ -112, "HyperFuncCall" }
	,{ -113, "VacantArg" }
	,{ -114, "Lambda" }
	,{ -115, "Operator" }
	,{ -116, "Return" }
	,{ -117, "SetReturnValue" }

	,{ -120, "PushPointer" }
	,{ -121, "PushVar" }
	,{ -122, "PushLiteralConst" }
	,{ -123, "PushExtern" }
	,{ -124, "SystemFunction" }
	,{ -125, "DynamicVariable" }
	,{ -126, "UnknownVariant" }

	,{ -131, "New" }
	,{ -132, "Delete" }
	,{ -135, "Is" }
	,{ -136, "Construct" }
	,{ -137, "TypeDef" }
	,{ -138, "Define" }
	,{ -139, "Using" }
	,{ -140, "Duplicate" }

	,{ -150, "Stop" }
	, {-151, "Format"}

	,{ -201, "Virtual" }
	,{ -202, "Const" }
	,{ -203, "Static" }
	,{ -204, "Public" }
	,{ -205, "Private" }
	,{ -206, "Protected" }
	,{ -207, "Friend" }
	,{ -208, "Class" }
	,{ -209, "NameSpace" }
	,{ -211, "Extern" }
	,{ -212, "Partial" }
	,{ -213, "Final" }
	,{ -214, "Readonly" }
	,{ -215, "Region" }

	,{ -216, "Enum" }
	,{ -217, "Abstract" }

	,{ -301, "META_WORD" }
	,{ -302, "META_INTEGER or Int" }
	,{ -303, "META_STRING or String" }
	,{ -304, "META_CHARACTER or Char" }
	,{ -305, "META_FLOAT or Double" }
	,{ -306, "META_OPERATOR" }
	,{ -307, "META_ILLEGAL" }
	,{ -308, "META_ANY" }
	,{ -309, "META_REQ_MORE" }
	,{ -310, "META_NONTERMINAL" }
	,{ -311, "META_COMPLEX" }
	,{ -312, "Void or META_VOID" }

	,{ -321, "Obj" }
	,{ -326, "Dynamic" }
	,{ -327, "Bool" }
	,{ -328, "Pointer" }
	,{ -330, "Long" }
	,{ -331, "Complex" }
	,{ -332, "Short" }
	, { -333, "Function" }

	,{ TokenMeta::Void - 100, "Void_Def" }
	,{ TokenMeta::Obj - 100, "Obj_Def" }
	,{ TokenMeta::Int - 100, "Int_Def" }
	,{ TokenMeta::Char - 100, "Char_Def" }
	,{ TokenMeta::String - 100, "String_Def" }
	,{ TokenMeta::Double - 100, "Double_Def" }
	,{ TokenMeta::Dynamic - 100, "Dynamic_Def" }
	,{ TokenMeta::Bool - 100, "Bool_Def" }
	,{ TokenMeta::Pointer - 100, "Pointer_Def" }
	,{ TokenMeta::Float - 100, "Float_Def" }
	,{ TokenMeta::Long - 100, "Long_Def" }
	,{ TokenMeta::Complex - 100, "Complex_Def" }
	,{ TokenMeta::Short - 100, "Short_Def" }
	, { TokenMeta::Function - 100, "Function_Def" }

	,{ -600, "If" }
	,{ -601, "Else or ElseIf" }
	,{ -202, "ElseLast" }
	,{ -603, "While" }
	,{ -604, "For" }
	,{ -605, "Goto" }
	,{ -606, "Continue" }
	,{ -607, "Break" }
	,{ -608, "JumpTrue" }
	,{ -609, "JumpFalse" }
	,{ -610, "JumpNoJudge" }
	,{ -611, "Try" }
	,{ -612, "Catch" }
	,{ -613, "Finally" }
	,{ -614, "Do" }
	,{ -615, "Switch" }
	,{ -616, "Case" }
	,{ -617, "Default" }

	,{ -1000, "CRLF" }
	,{ -1003, "Label" }
	,{ -1004, "Sharp" }
	,{ -1005, "EndOfScan" }
	,{ -1006, "End" }
	,{ -1007, "Error" }
	,{ -1008, "Comments" }
	,{ -1009, "CommentsEnd" }
	,{ -1010, "CommentLine" }
	,{ -1011, "Include" }

	,{ -2001, "NT_PARAMTABLE" }
	,{ -2002, "NT_FORMATTER" }
	,{ -2003, "NT_AUTOFORMATTER" }
	,{ -2004, "NT_ARGTABLE" }
	,{ -2005, "NT_FUNCTIONDECLARE" }
	,{ -2006, "NT_VARIABLEDEFINE" }
	,{ -2007, "NT_STATEMENT" }
	,{ -2008, "NT_EXPRESSION" }
	,{ -2009, "NT_IF" }
	,{ -2010, "NT_ELSEIF" }
	,{ -2011, "NT_DO" }
	,{ -2012, "NT_VARIABLEINITIAL or NT_KEYVALUE" }
	,{ -2013, "NT_DECLAREDVARIABLE" }

	,{ -2014, "NT_SUITE" }
	,{ -2015, "NT_FUCNTIONARRAY" }
	,{ -2016, "NT_ARRAYBUILDER_LAMBDA" }
	,{ -2017, "NT_ARRAYBUILDER_LIST" }
	,{ -2018, "NT_DIMENSLICE" }
	,{ -2019, "NT_PARAMTABLE_DIMENSLICE" }
	,{ -2020, "NT_SLICE" }
	,{ -2021, "NT_VARIABLEDESC" }
	,{ -2022, "NT_VARIABLEINITIALDUMMY" }

	,{ -2023, "NT_VOID" }
	,{ -2024, "NT_ARRAYBUILDER" }
	,{ -2025, "NT_ARGTABLE_PURE" }
	,{ -2026, "NT_WRAPPER" }
	,{ -2027, "NT_SELECT" }
	,{ -2028, "NT_CASE" }
	,{ -2029, "NT_CASES" }
	,{ -2030, "NT_HIDDENDO" }
	,{ -2031, "NT_WHILE"}
	,{ -2032, "NT_OPEN" }
	,{ -2033, "NT_CLOSE" }
	, {-2034, "NT_PROGRAM"}
	, {-2035, "NT_INTERFACE"}
	, {-2036, "NT_WRAPPERS"}
	, {-2037, "NT_PARAMTABLE_PURE"}
	, {-2038, "NT_FORMAT"}
	, {-2039, "NT_LABEL"}
	, {-2040, "NT_PROGRAM_EXPLICIT"}
	, {-2041, "NT_COMMONBLOCK"}
	,{ -9999, "NT_DUMMY"}
};


std::string get_intent_name(int intent_id) {
	if (IntentName.find(intent_id) != IntentName.end()) {
		return IntentName[intent_id];
	}
	else {
		return "!undefined!";
	}
}