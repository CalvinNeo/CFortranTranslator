%{
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include <tuple>

using namespace std;
%}

%debug

%token CRLF EXP FUNCTIONBEGIN FUNCTIONEND

%start program

%%

stmt : EXP
	|
stmts : stmt CRLF stmts
	| stmt
function : FUNCTIONBEGIN CRLF stmts CRLF FUNCTIONEND
unit : function
	| stmts
program : unit
	| unit CRLF program

%%