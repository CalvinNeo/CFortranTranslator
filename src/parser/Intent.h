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
#include <string>
#include "enum_reflect.h"

namespace TokenMeta {

	//enum IntentMeta {
	//enum class IntentMeta_T : int {
	MAKE_ENUM(IntentMeta,  
		// Operator
		// in priority order
		//Dereference = 260,
		ADD_ENUM(Dereference, 260),
		ADD_ENUM(Reference, 261),

		ADD_ENUM(TypeCast, 262),

		ADD_ENUM(PostInc, 240), //++ i
		ADD_ENUM(PostDec, 241), //-- i
		ADD_ENUM(Inc, 242),
		ADD_ENUM(Dec, 243),

		ADD_ENUM(Not, 230),
		ADD_ENUM(Neg, 231),
		ADD_ENUM(PreInc, 232), //i++
		ADD_ENUM(PreDec, 233), //i--
		ADD_ENUM(Inv, 234), //~
		ADD_ENUM(Pos, 235),

		ADD_ENUM(Power, 200),

		ADD_ENUM(Multiply, 190),
		ADD_ENUM(MultiplyVirtual, 192),
		ADD_ENUM(Divide, 191),
		ADD_ENUM(Mod, 193),

		ADD_ENUM(Add, 180),
		ADD_ENUM(Minus, 181),
		ADD_ENUM(MinusVirtual, 182),

		ADD_ENUM(Shl, 170),
		ADD_ENUM(Shr, 171),

		ADD_ENUM(GT, 160),
		ADD_ENUM(GE, 161),
		ADD_ENUM(EQ, 162),
		ADD_ENUM(LE, 163),
		ADD_ENUM(LT, 164),
		ADD_ENUM(NEQ, 165),
		ADD_ENUM(Compare, 166),
		ADD_ENUM(In, 167),
		ADD_ENUM(EQV, 168),
		ADD_ENUM(NEQV, 169),

		ADD_ENUM(And, 150),
		ADD_ENUM(AndVirtual, 151),

		ADD_ENUM(Or, 140),

		ADD_ENUM(AndAnd, 130),
		ADD_ENUM(OrOr, 120),

		ADD_ENUM(Let, 101),
		ADD_ENUM(LetAdd, 102),
		ADD_ENUM(LetMinus, 103),
		ADD_ENUM(LetMultiply, 104),
		ADD_ENUM(LetDivide, 105),
		ADD_ENUM(LetShl, 106),
		ADD_ENUM(LetShr, 107),
		ADD_ENUM(LetAnd, 108),
		ADD_ENUM(LetOr, 109),

		ADD_ENUM(Nop, 0), 

		ADD_ENUM(LB, -1), //(
		ADD_ENUM(RB, -2), //)
		ADD_ENUM(SLB, -3), //[
		ADD_ENUM(SRB, -4), //]
		ADD_ENUM(Dot, -5), //.
		ADD_ENUM(DoubleColon, -6), //::
		ADD_ENUM(Comma, -7), //,
		ADD_ENUM(Colon, -8), //:
		ADD_ENUM(LBrace, -9), //{
		ADD_ENUM(RBrace, -10), //}
		ADD_ENUM(Semicolon, -11),//;

		// VM Commands and constants -100~-200

		ADD_ENUM(Null, -101),
		ADD_ENUM(True, -102),
		ADD_ENUM(False, -103),

		ADD_ENUM(OperatorCall, -110), 
		//ADD_ENUM(CallArgs, -111),
		//ADD_ENUM(HyperFuncCall, -112), 
		//ADD_ENUM(OptionalArg, -113), 
		//ADD_ENUM(Lambda, -114),
		ADD_ENUM(Operator, -115),
		ADD_ENUM(Return, -116),
		ADD_ENUM(SetReturnValue, -117),

		//ADD_ENUM(PushPointer, -120),
		//ADD_ENUM(PushVar, -121),
		//ADD_ENUM(PushLiteralConst, -122), 
		//ADD_ENUM(PushExtern, -123),
		//ADD_ENUM(SystemFunction, -124), 
		//ADD_ENUM(DynamicVariable, -125), 
		ADD_ENUM(UnknownVariant, -126), 

		//ADD_ENUM(New, -131),
		//ADD_ENUM(Delete, -132),
		//ADD_ENUM(Is, -135),
		//ADD_ENUM(Construct, -136),
		//ADD_ENUM(TypeDef, -137),
		//ADD_ENUM(Define, -138),
		//ADD_ENUM(Using, -139),
		//ADD_ENUM(Duplicate, -140),

		
		ADD_ENUM(Stop, -150), 
		ADD_ENUM(Format, -151), // fortran77 format commandd

		// Describer
		ADD_ENUM(Const, -202),
		ADD_ENUM(Static, -203),
		ADD_ENUM(Public, -204),
		ADD_ENUM(Private, -205),
		ADD_ENUM(Protected, -206),
		//ADD_ENUM(Friend, -207),
		//ADD_ENUM(Class, -208),
		//ADD_ENUM(NameSpace, -209),
		//ADD_ENUM(Extern, -211),
		//ADD_ENUM(Partial, -212),
		//ADD_ENUM(Final, -213),
		//ADD_ENUM(Enum, -216),
		//ADD_ENUM(Abstract, -217),

		//Build-in Type
		// META Type(for parse)
		ADD_ENUM(META_WORD, -301),
		ADD_ENUM(META_INTEGER, -302),
		ADD_ENUM(META_STRING, -303),
		ADD_ENUM(META_CHARACTER, -304),
		ADD_ENUM(META_REAL, -305),
		ADD_ENUM(META_OPERATOR, -306),
		ADD_ENUM(META_ILLEGAL, -307),
		/***************************************
		* META_ANY means this Intent has no token yet,
		*	it's often used for keyword like `where`, `program`, etc
		*	because they won't be used in AST, so there's no need to create a particular token for them,
		*	or they can be in AST, but we only use their literal meaning(but they are not sematiclly literals)
		****************************************/
		ADD_ENUM(META_ANY, -308), 
		/***************************************
		*	META_REQ_MORE ask the tokenizer to look ahead for one more token
		****************************************/
		ADD_ENUM(META_REQ_MORE, -309),
		/***************************************
		* META_NONTERMINAL is non-terminal version for `META_ANY`
		*	Intent with META_NONTERMINAL token can be in AST,
		* META_NONTERMINAL token means we only use their literal meaning of this token 
		****************************************/
		ADD_ENUM(META_NONTERMINAL, -310), 
		ADD_ENUM(META_COMPLEX, -311),
		ADD_ENUM(META_VOID, -312),

		// typename (-300~--399) and type decl(-400~-599)
		ADD_ENUM(Void, META_VOID), 	ADD_ENUM(Void_Decl, (Void - 100)),
		ADD_ENUM(Obj, -321), ADD_ENUM(Obj_Decl, Obj - 100),
		ADD_ENUM(Int, META_INTEGER), ADD_ENUM(Int_Decl, Int - 100),
		ADD_ENUM(Char, META_CHARACTER), ADD_ENUM(Char_Decl, Char - 100),
		ADD_ENUM(String, META_STRING), ADD_ENUM(String_Decl, String - 100),
		ADD_ENUM(Double, META_REAL), ADD_ENUM(Double_Decl, Double - 100),
		//ADD_ENUM(Dynamic, -326), ADD_ENUM(Dynamic_Decl, Dynamic - 100),
		ADD_ENUM(Bool, -327), ADD_ENUM(Bool_Decl, Bool - 100),
		//ADD_ENUM(Pointer, -328), ADD_ENUM(Pointer_Decl, Pointer - 100),
		ADD_ENUM(Float, -329), ADD_ENUM(Float_Decl, Float - 100),
		//ADD_ENUM(Long, -330), ADD_ENUM(Long_Decl, Long - 100),
		ADD_ENUM(Complex, -331), ADD_ENUM(Complex_Decl, Complex - 100),
		//ADD_ENUM(Short, -332), ADD_ENUM(Short_Decl, Short - 100),
		ADD_ENUM(Function, -333), ADD_ENUM(Function_Decl, Function - 100),
		ADD_ENUM(Int8, -334), ADD_ENUM(Int8_Decl, Int8 - 100),
		ADD_ENUM(Int16, -335), ADD_ENUM(Int16_Decl, Int16 - 100),
		ADD_ENUM(Int32, -336), ADD_ENUM(Int32_Decl, Int32 - 100),
		ADD_ENUM(Int64, -337), ADD_ENUM(Int64_Decl, Int64 - 100),
		ADD_ENUM(LongDouble, -338), ADD_ENUM(LongDouble_Decl, Int64 - 100),
		ADD_ENUM(Implicit_Decl, -599),

		// Flow-Control
		ADD_ENUM(If, -600),
		ADD_ENUM(Else, -601),
		ADD_ENUM(ElseIf, Else),
		ADD_ENUM(ElseLast, -602),
		ADD_ENUM(While, -603),
		ADD_ENUM(For, -604),
		ADD_ENUM(Goto, -605),
		ADD_ENUM(Continue, -606),
		ADD_ENUM(Break, -607),
		ADD_ENUM(JumpTrue, -608),
		ADD_ENUM(JumpFalse, -609),
		ADD_ENUM(JumpNoJudge, -610),
		ADD_ENUM(Try, -611),
		ADD_ENUM(Catch, -612),
		ADD_ENUM(Finally, -613),
		ADD_ENUM(Do, -614),
		ADD_ENUM(Switch, -615),
		ADD_ENUM(Case, -616),
		ADD_ENUM(Default, -617),

		// parsing tags
		ADD_ENUM(CRLF, -1000),
		ADD_ENUM(Label, -1003), //±êÇ©
		ADD_ENUM(Sharp, -1004),
		ADD_ENUM(EndOfScan, -1005),  // the end of the code
		ADD_ENUM(QuitProgram, -1006), // quit the program
		ADD_ENUM(Error, -1007),
		ADD_ENUM(Comments, -1008),
		ADD_ENUM(CommentsEnd, -1009),
		ADD_ENUM(CommentLine, -1010),
		ADD_ENUM(Include, -1011),
		ADD_ENUM(ConfigImplicit, -1012),

		/***************************************
		*	NT_PARAMTABLE is a deprecated
		*	currently, rule `paramtable` must be of the following TokenMeta:
		*	1) NT_ARGTABLE_PURE
		*	2) NT_DIMENSLICE
		*	3) NT_PARAMTABLE_PURE
		****************************************/
		ADD_ENUM(NT_PARAMTABLE, -2001),
		ADD_ENUM(NT_FORMATTER, -2002),
		/***************************************
		*	ref. 9.4.1.1 list-directed input/output statement
		****************************************/
		ADD_ENUM(NT_AUTOFORMATTER, -2003), /* the second `*` sign of write (*,*), xxx */
		/***************************************
		*	NT_ARGTABLE is a deprecated, ref NT_PARAMTABLE
		****************************************/
		ADD_ENUM(NT_ARGTABLE, -2004),
		ADD_ENUM(NT_FUNCTIONDECLARE, -2005),
		/***************************************
		* a statement that defines a list of variables , such as `int a = 2, b, c` ,
		*	will create 3 NT_VARIABLEDEFINE node , which are all sons to a NT_VARIABLEDEFINESET node
		****************************************/
		ADD_ENUM(NT_VARIABLEDEFINE, -2006), 
		ADD_ENUM(NT_STATEMENT, -2007),
		ADD_ENUM(NT_EXPRESSION, -2008),
		ADD_ENUM(NT_IF, -2009),
		ADD_ENUM(NT_ELSEIF, -2010),
		ADD_ENUM(NT_DO, -2011),
		/***************************************
		*	NT_VARIABLE_ENTITY is a pair (name, initial_value)
		*	, means the name of the variable and it's initial(default) value representively
		****************************************/
		ADD_ENUM(NT_VARIABLE_ENTITY, -2012),
		ADD_ENUM(NT_KEYVALUE, NT_VARIABLE_ENTITY),
		/***************************************
		*	in fortran, function's parameter list declarations don't include type of parameters
		*	, definition of parameters is placed in main body of function
		*	ParseNode token of variables in parameter list is NT_DECLAREDVARIABLE rather than NT_VARIABLE_ENTITY
		*	, because it's actual declaration is in the function's body
		* ALSO REFER `paramtable_info` in FUnction.h
		*========================================
		*	UPDATE:
		*	NT_DECLAREDVARIABLE is now DEPRECATED
		*	use `vinfo->declared = true` instead of `vardefnode->get_token() = NT_VARIABLE_ENTITY`
		****************************************/
		ADD_ENUM(NT_DECLAREDVARIABLE, -2013), 
		ADD_ENUM(NT_SUITE, -2014),
		ADD_ENUM(NT_FUCNTIONARRAY, -2015),
		/***************************************
		*	NT_ARRAYBUILDER_LAMBDA is a deprecated
		****************************************/
		ADD_ENUM(NT_ARRAYBUILDER_LAMBDA, -2016), 
		ADD_ENUM(NT_ARRAYBUILDER_LIST, -2017),
		/***************************************
		*	NT_DIMENSLICE is a section-subscript-list in fortran
		*	, which is a list of section-subscript concated by ','
		*=======================================
		*	EX:
		*	`1:2, 3:4`
		*	`1`
		*	`1, 2`
		****************************************/
		ADD_ENUM(NT_DIMENSLICE, -2018),
		/***************************************
		*	NT_PARAMTABLE_DIMENSLICE is a deprecated, ref NT_PARAMTABLE
		****************************************/
		ADD_ENUM(NT_PARAMTABLE_DIMENSLICE, -2019),
		/***************************************
		*	NT_SLICE is a section-subscript in fortran
		*	, which any of a subscript-triplet or a scalar-int-expr or a vector-subscript
		****************************************/
		ADD_ENUM(NT_SLICE, -2020),
		ADD_ENUM(NT_VARIABLEDESC, -2021),
		/***************************************
		*	NT_VARIABLEINITIALDUMMY is used when a NT_VARIABLE_ENTITY has no initial value
		****************************************/
		ADD_ENUM(NT_VARIABLEINITIALDUMMY, -2022),
		/***************************************
		*	this ParseNode do not exist but ParseNode * can not be nullptr so this is placeholder
		*========================================
		* UPDATE
		* use NT_DUMMY instead
		****************************************/
		ADD_ENUM(NT_VOID, -2023),
		/***************************************
		*	UPDATE:
		*	NT_ARRAYBUILDER is now DEPRECATED
		*	all array builder is NT_ARRAYBUILDER_LIST now
		****************************************/
		ADD_ENUM(NT_ARRAYBUILDER, -2024), 
		ADD_ENUM(NT_ARGTABLE_PURE, -2025),
		ADD_ENUM(NT_WRAPPER, -2026),
		ADD_ENUM(NT_SELECT, -2027),
		ADD_ENUM(NT_CASE, -2028),
		ADD_ENUM(NT_CASES, -2029),
		ADD_ENUM(NT_HIDDENDO, -2030),
		ADD_ENUM(NT_WHILE, -2031),
		ADD_ENUM(NT_OPEN, -2032),
		ADD_ENUM(NT_CLOSE, -2033),
		ADD_ENUM(NT_PROGRAM, -2034),
		ADD_ENUM(NT_INTERFACE, -2035),
		ADD_ENUM(NT_WRAPPERS, -2036),
		ADD_ENUM(NT_PARAMTABLE_PURE, -2037),
		ADD_ENUM(NT_FORMAT, -2038),
		ADD_ENUM(NT_LABEL_STMT, -2039),
		ADD_ENUM(NT_PROGRAM_EXPLICIT, -2040),
		ADD_ENUM(NT_COMMONBLOCK, -2041),
		ADD_ENUM(NT_COMMONBLOCKDEFINE, -2042),
		ADD_ENUM(NT_VARIABLEDEFINESET, -2043),
		ADD_ENUM(NT_FORMATTER_LOCATION, -2044),
		ADD_ENUM(NT_READ_STMT, -2045),
		ADD_ENUM(NT_WRITE_STMT, -2046),
		ADD_ENUM(NT_PRINT_STMT, -2047),
		ADD_ENUM(NT_DORANGE, -2048),
		ADD_ENUM(NT_CONTROL_STMT, -2049),
		ADD_ENUM(NT_ALLOCATE_STMT, -2050),

		ADD_ENUM(NT_DUMMY, -9999),
		/***************************************
		*	use given default value when passed as argument
		****************************************/
		ADD_ENUM(USE_DEFAULT_VALUE, -10000)
	)

}

std::string get_intent_name(TokenMeta_T intent_id);

struct KeywordMeta {
	std::string what;
	TokenMeta_T token;
	int yytoken;
};
