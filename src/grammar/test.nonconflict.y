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

%token ADVCRLF CRLF EXP FUNCTIONBEGIN FUNCTIONEND

%left ADVCRLF
%left CRLF

%start program

%%

stmt : EXP
stmts : stmt CRLF stmts
	| stmt
function : FUNCTIONBEGIN stmts FUNCTIONEND
unit : function
	| stmts
program : unit
	| unit program

%%