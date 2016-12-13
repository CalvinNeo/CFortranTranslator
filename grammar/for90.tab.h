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
     YY_REQ_MORE = 258,
     YY_CRLF = 259,
     YY_GT = 260,
     YY_GE = 261,
     YY_EQ = 262,
     YY_LE = 263,
     YY_LT = 264,
     YY_NEQ = 265,
     YY_NEQV = 266,
     YY_EQV = 267,
     YY_ANDAND = 268,
     YY_OROR = 269,
     YY_NOT = 270,
     YY_POWER = 271,
     YY_DOUBLECOLON = 272,
     YY_NEG = 273,
     YY_POS = 274,
     YY_INTEGER = 275,
     YY_FLOAT = 276,
     YY_WORD = 277,
     YY_OPERATOR = 278,
     YY_STRING = 279,
     YY_ILLEGAL = 280,
     YY_COMPLEX = 281,
     YY_TRUE = 282,
     YY_FALSE = 283,
     YY_END = 284,
     YY_IF = 285,
     YY_THEN = 286,
     YY_ELSE = 287,
     YY_ELSEIF = 288,
     YY_ENDIF = 289,
     YY_DO = 290,
     YY_ENDDO = 291,
     YY_CONTINUE = 292,
     YY_BREAK = 293,
     YY_WHILE = 294,
     YY_ENDWHILE = 295,
     YY_WHERE = 296,
     YY_ENDWHERE = 297,
     YY_CASE = 298,
     YY_ENDCASE = 299,
     YY_SELECT = 300,
     YY_ENDSELECT = 301,
     YY_GOTO = 302,
     YY_DOWHILE = 303,
     YY_DEFAULT = 304,
     YY_PROGRAM = 305,
     YY_ENDPROGRAM = 306,
     YY_FUNCTION = 307,
     YY_ENDFUNCTION = 308,
     YY_RECURSIVE = 309,
     YY_RESULT = 310,
     YY_SUBROUTINE = 311,
     YY_ENDSUBROUTINE = 312,
     YY_MODULE = 313,
     YY_ENDMODULE = 314,
     YY_BLOCK = 315,
     YY_ENDBLOCK = 316,
     YY_INTERFACE = 317,
     YY_ENDINTERFACE = 318,
     YY_IMPLICIT = 319,
     YY_NONE = 320,
     YY_USE = 321,
     YY_PARAMETER = 322,
     YY_FORMAT = 323,
     YY_ENTRY = 324,
     YY_DIMENSION = 325,
     YY_ARRAYINITIAL_START = 326,
     YY_ARRAYINITIAL_END = 327,
     YY_INTENT = 328,
     YY_IN = 329,
     YY_OUT = 330,
     YY_INOUT = 331,
     YY_OPTIONAL = 332,
     YY_LEN = 333,
     YY_KIND = 334,
     YY_INTEGER_T = 335,
     YY_FLOAT_T = 336,
     YY_STRING_T = 337,
     YY_COMPLEX_T = 338,
     YY_BOOL_T = 339,
     YY_CHARACTER_T = 340,
     YY_WRITE = 341,
     YY_READ = 342,
     YY_PRINT = 343,
     YY_CALL = 344
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
