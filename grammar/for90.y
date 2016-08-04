%{
#include <stdio.h>
#include <string>
#include <iostream>
#include "../tokenizer.h"
#include "../parser.h"
// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE

%}

%debug

%token YY_REQ_MORE
%token YY_GT YY_GE YY_EQ YY_LE YY_LT YY_NEQ YY_NEQV YY_EQV YY_ANDAND YY_OROR YY_NOT YY_POWER YY_DOUBLECOLON YY_NEG
%token YY_INTEGER YY_FLOAT YY_WORD YY_OPERATOR YY_STRING YY_ILLEGAL YY_COMPLEX YY_TRUE YY_FALSE
%token YY_IF YY_THEN YY_ELSE YY_ELSEIF YY_ENDIF YY_DO YY_CONTINUE YY_WHILE YY_ENDWHILE YY_WHERE YY_ENDWHERE YY_CASE YY_ENDCASE
%token YY_PROGRAM YY_ENDPROGRAM YY_FUNCTION YY_ENDFUNCTION YY_RECURSIVE YY_RESULT YY_SUBROUTINE YY_ENDSUBROUTINE YY_MODULE YY_ENDMODULE YY_BLOCK YY_ENDBLOCK
%token YY_IMPLICIT YY_NONE YY_USE YY_PARAMETER YY_FORMAT YY_ENTRY
%token YY_INTEGER_T YY_FLOAT_T YY_STRING_T YY_COMPLEX_T YY_BOOL_T
%token YY_WRITE YY_READ YY_PRINT YY_OPEN YY_CLOSE


%left '='
%left YY_OROR
%left YY_ANDAND
%left YY_EQ YY_NEQ
%left YY_GT YY_GE YY_LE YY_LT
%left '+' '-' 
%left '*' '/' 
%left YY_POWER
%right YY_NEG YY_NOT

%start program

%%
    dummy_function : YY_RECURSIVE
	
	literal : YY_FLOAT
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, "float: " + $1.fs.CurrentTerm.what }; // float number
				$$ = *newnode;
			}
		| YY_INTEGER
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, "int: " + $1.fs.CurrentTerm.what }; // int number
				$$ = *newnode;
			}
		| YY_STRING
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, "string: " + $1.fs.CurrentTerm.what }; // string
				$$ = *newnode;
			}
		| YY_TRUE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "bool: " + $1.fs.CurrentTerm.what }; // bool true
				$$ = *newnode;
			}
		| YY_FALSE
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "bool: " + $1.fs.CurrentTerm.what };
				$$ = *newnode;
			}
        | YY_COMPLEX
            {printf("complex " );}

	exp : '(' exp ')'
			{ printf("bracket "); }
		| exp '+' exp
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Add, "+" };
				newnode->child.push_back(new ParseNode($1)); // left operand exp
				newnode->child.push_back(new ParseNode($3)); // tight operand exp
				$$ = *newnode;
			}
		| exp '-' exp
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Minus, "-" };
				newnode->child.push_back(new ParseNode($1)); // left operand exp
				newnode->child.push_back(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '*' exp
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Multiply, "*" };
				newnode->child.push_back(new ParseNode($1)); // left operand exp
				newnode->child.push_back(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp '/' exp
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Divide, "/" };
				newnode->child.push_back(new ParseNode($1)); // left operand exp
				newnode->child.push_back(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
		| exp YY_POWER exp
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Power, "**" };
				newnode->child.push_back(new ParseNode($1)); // left operand exp
				newnode->child.push_back(new ParseNode($3)); // right operand exp
				$$ = *newnode;
			}
        | '-' exp %prec YY_NEG
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Neg, "-" };
				newnode->child.push_back(new ParseNode($2)); // only right operand exp
				$$ = *newnode;
			}
		| literal
            { 
				// 
				$$ = $1;
			}
        | YY_WORD
            { printf("word ");}

	stmt : exp
        | compound_stmt
        | output_stmt

    output_stmt : write

    write : '(' YY_INTEGER ',' YY_STRING ')' argtable
        | '(' '*' ',' YY_STRING ')' argtable
        | '(' '*' ',' '*' ')' argtable
        | '*' ',' argtable

    type_spec : YY_INTEGER_T
        | YY_FLOAT_T
        | YY_STRING_T 
        | YY_COMPLEX_T
        | YY_BOOL_T

    var_def : type_spec YY_DOUBLECOLON paramtable

    paramtable : YY_WORD
        | YY_WORD '=' exp
        | YY_WORD ',' argtable        
        | YY_WORD '=' exp
        | YY_WORD '=' exp ',' argtable

    argtable : exp
        | exp , argtable

    compound_stmt : if_stmt

	if_stmt : YY_IF exp YY_THEN stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "if" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt YY_ELSE stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "if-else" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($6)); // else-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt elseif_stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "if-elseif" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($5)); // recursive elseif-stmt
				$$ = *newnode;
			}
		| YY_IF exp YY_THEN stmt elseif_stmt YY_ELSE stmt YY_END YY_IF
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::If, "if-elseif-else" };
				newnode->child.push_back(new ParseNode($2)); // exp
				newnode->child.push_back(new ParseNode($4)); // stmt
				newnode->child.push_back(new ParseNode($5)); // recursive elseif-stmt
				newnode->child.push_back(new ParseNode($7)); // else-stmt
				$$ = *newnode;
			}
	elseif_stmt : YY_ELSE YY_IF exp YY_THEN stmt
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::ElseIf, "elseif" };
				newnode->child.push_back(new ParseNode($3)); // exp
				newnode->child.push_back(new ParseNode($5)); // stmt
				$$ = *newnode;
			}

		| YY_ELSE YY_IF exp YY_THEN stmt elseif_stmt
			{
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::ElseIf, "elseif-else-if" };
				newnode->child.push_back(new ParseNode($3)); // exp
				newnode->child.push_back(new ParseNode($5)); // stmt
				newnode->child.push_back(new ParseNode($6)); // another elseif-stmt
				$$ = *newnode;
			}

    stmts : stmt
        | stmt stmts

    program : YY_PROGRAM YY_WORD stmts YY_END YY_PROGRAM YY_WORD
			{ 
				ParseNode * newnode = new ParseNode();
				newnode->child.push_back(new ParseNode($3));
				program_tree = *newnode;
			}
        | YY_PROGRAM stmts YY_END YY_PROGRAM 
			{
				ParseNode * newnode = new ParseNode();
				newnode->child.push_back(new ParseNode($2));
				program_tree = *newnode;
			}

%%
//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
}
int parse(std::string code) {
	//YYSTYPE aa;
	//aa.isnull = true;
	set_buff(code);
	yyparse();
	release_buff();
	return 0;
}
