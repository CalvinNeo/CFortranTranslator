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
     _YY_TYPE = 276,
     YY_INTEGER = 277,
     YY_FLOAT = 278,
     YY_WORD = 279,
     YY_OPERATOR = 280,
     YY_STRING = 281,
     YY_ILLEGAL = 282,
     YY_COMPLEX = 283,
     YY_TRUE = 284,
     YY_FALSE = 285,
     _YY_CONTROL = 286,
     YY_END = 287,
     YY_IF = 288,
     YY_THEN = 289,
     YY_ELSE = 290,
     YY_ELSEIF = 291,
     YY_ENDIF = 292,
     YY_DO = 293,
     YY_ENDDO = 294,
     YY_CONTINUE = 295,
     YY_BREAK = 296,
     YY_WHILE = 297,
     YY_ENDWHILE = 298,
     YY_WHERE = 299,
     YY_ENDWHERE = 300,
     YY_CASE = 301,
     YY_ENDCASE = 302,
     _YY_DESCRIBER = 303,
     YY_PROGRAM = 304,
     YY_ENDPROGRAM = 305,
     YY_FUNCTION = 306,
     YY_ENDFUNCTION = 307,
     YY_RECURSIVE = 308,
     YY_RESULT = 309,
     YY_SUBROUTINE = 310,
     YY_ENDSUBROUTINE = 311,
     YY_MODULE = 312,
     YY_ENDMODULE = 313,
     YY_BLOCK = 314,
     YY_ENDBLOCK = 315,
     YY_IMPLICIT = 316,
     YY_NONE = 317,
     YY_USE = 318,
     YY_PARAMETER = 319,
     YY_FORMAT = 320,
     YY_ENTRY = 321,
     YY_DIMENSION = 322,
     YY_ARRAYINITIAL_START = 323,
     YY_ARRAYINITIAL_END = 324,
     _YY_TYPEDEF = 325,
     YY_INTEGER_T = 326,
     YY_FLOAT_T = 327,
     YY_STRING_T = 328,
     YY_COMPLEX_T = 329,
     YY_BOOL_T = 330,
     _YY_COMMAND = 331,
     YY_WRITE = 332,
     YY_READ = 333,
     YY_PRINT = 334,
     YY_OPEN = 335,
     YY_CLOSE = 336,
     YY_CALL = 337
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
