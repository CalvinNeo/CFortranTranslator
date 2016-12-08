/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_FOR90_TAB_H_INCLUDED
# define YY_YY_FOR90_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _YY_VOID = 258,
     YY_REQ_MORE = 259,
     YY_CRLF = 260,
     _YY_OP = 261,
     YY_GT = 262,
     YY_GE = 263,
     YY_EQ = 264,
     YY_LE = 265,
     YY_LT = 266,
     YY_NEQ = 267,
     YY_NEQV = 268,
     YY_EQV = 269,
     YY_ANDAND = 270,
     YY_OROR = 271,
     YY_NOT = 272,
     YY_POWER = 273,
     YY_DOUBLECOLON = 274,
     YY_NEG = 275,
     YY_POS = 276,
     _YY_TYPE = 277,
     YY_INTEGER = 278,
     YY_FLOAT = 279,
     YY_WORD = 280,
     YY_OPERATOR = 281,
     YY_STRING = 282,
     YY_ILLEGAL = 283,
     YY_COMPLEX = 284,
     YY_TRUE = 285,
     YY_FALSE = 286,
     _YY_CONTROL = 287,
     YY_END = 288,
     YY_IF = 289,
     YY_THEN = 290,
     YY_ELSE = 291,
     YY_ELSEIF = 292,
     YY_ENDIF = 293,
     YY_DO = 294,
     YY_ENDDO = 295,
     YY_CONTINUE = 296,
     YY_BREAK = 297,
     YY_WHILE = 298,
     YY_ENDWHILE = 299,
     YY_WHERE = 300,
     YY_ENDWHERE = 301,
     YY_CASE = 302,
     YY_ENDCASE = 303,
     YY_SELECT = 304,
     YY_ENDSELECT = 305,
     YY_GOTO = 306,
     YY_DOWHILE = 307,
     YY_DEFAULT = 308,
     _YY_DELIM = 309,
     YY_PROGRAM = 310,
     YY_ENDPROGRAM = 311,
     YY_FUNCTION = 312,
     YY_ENDFUNCTION = 313,
     YY_RECURSIVE = 314,
     YY_RESULT = 315,
     YY_SUBROUTINE = 316,
     YY_ENDSUBROUTINE = 317,
     YY_MODULE = 318,
     YY_ENDMODULE = 319,
     YY_BLOCK = 320,
     YY_ENDBLOCK = 321,
     YY_INTERFACE = 322,
     YY_ENDINTERFACE = 323,
     _YY_DESCRIBER = 324,
     YY_IMPLICIT = 325,
     YY_NONE = 326,
     YY_USE = 327,
     YY_PARAMETER = 328,
     YY_FORMAT = 329,
     YY_ENTRY = 330,
     YY_DIMENSION = 331,
     YY_ARRAYINITIAL_START = 332,
     YY_ARRAYINITIAL_END = 333,
     YY_INTENT = 334,
     YY_IN = 335,
     YY_OUT = 336,
     YY_INOUT = 337,
     YY_OPTIONAL = 338,
     YY_LEN = 339,
     YY_KIND = 340,
     _YY_TYPEDEF = 341,
     YY_INTEGER_T = 342,
     YY_FLOAT_T = 343,
     YY_STRING_T = 344,
     YY_COMPLEX_T = 345,
     YY_BOOL_T = 346,
     YY_CHARACTER_T = 347,
     _YY_COMMAND = 348,
     YY_WRITE = 349,
     YY_READ = 350,
     YY_PRINT = 351,
     YY_CALL = 352
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_FOR90_TAB_H_INCLUDED  */
