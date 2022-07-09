/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YY_IGNORE_THIS = 258,
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
     YY_EXPONENT = 275,
     YY_PLET = 276,
     YY_INTEGER = 277,
     YY_FLOAT = 278,
     YY_WORD = 279,
     YY_OPERATOR = 280,
     YY_STRING = 281,
     YY_ILLEGAL = 282,
     YY_COMPLEX = 283,
     YY_TRUE = 284,
     YY_FALSE = 285,
     YY_FORMAT_STMT = 286,
     YY_COMMENT = 287,
     YY_LABEL = 288,
     YY_END = 289,
     YY_IF = 290,
     YY_THEN = 291,
     YY_ELSE = 292,
     YY_ELSEIF = 293,
     YY_ENDIF = 294,
     YY_DO = 295,
     YY_ENDDO = 296,
     YY_CONTINUE = 297,
     YY_BREAK = 298,
     YY_EXIT = 299,
     YY_CYCLE = 300,
     YY_WHILE = 301,
     YY_ENDWHILE = 302,
     YY_WHERE = 303,
     YY_ENDWHERE = 304,
     YY_CASE = 305,
     YY_ENDCASE = 306,
     YY_SELECT = 307,
     YY_ENDSELECT = 308,
     YY_GOTO = 309,
     YY_DOWHILE = 310,
     YY_DEFAULT = 311,
     YY_TYPE = 312,
     YY_ENDTYPE = 313,
     YY_PROGRAM = 314,
     YY_ENDPROGRAM = 315,
     YY_FUNCTION = 316,
     YY_ENDFUNCTION = 317,
     YY_RECURSIVE = 318,
     YY_RESULT = 319,
     YY_SUBROUTINE = 320,
     YY_ENDSUBROUTINE = 321,
     YY_MODULE = 322,
     YY_ENDMODULE = 323,
     YY_BLOCK = 324,
     YY_ENDBLOCK = 325,
     YY_INTERFACE = 326,
     YY_ENDINTERFACE = 327,
     YY_COMMON = 328,
     YY_DATA = 329,
     YY_IMPLICIT = 330,
     YY_NONE = 331,
     YY_USE = 332,
     YY_PARAMETER = 333,
     YY_ENTRY = 334,
     YY_DIMENSION = 335,
     YY_ARRAYBUILDER_START = 336,
     YY_ARRAYBUILDER_END = 337,
     YY_INTENT = 338,
     YY_IN = 339,
     YY_OUT = 340,
     YY_INOUT = 341,
     YY_OPTIONAL = 342,
     YY_LEN = 343,
     YY_KIND = 344,
     YY_SAVE = 345,
     YY_ALLOCATABLE = 346,
     YY_TARGET = 347,
     YY_POINTER = 348,
     YY_INTEGER_T = 349,
     YY_FLOAT_T = 350,
     YY_STRING_T = 351,
     YY_COMPLEX_T = 352,
     YY_BOOL_T = 353,
     YY_CHARACTER_T = 354,
     YY_DOUBLE_T = 355,
     YY_WRITE = 356,
     YY_READ = 357,
     YY_PRINT = 358,
     YY_CALL = 359,
     YY_STOP = 360,
     YY_PAUSE = 361,
     YY_RETURN = 362,
     YY_CONFIG_IMPLICIT = 363,
     YY_ALLOCATE = 364
   };
#endif
/* Tokens.  */
#define YY_IGNORE_THIS 258
#define YY_CRLF 259
#define YY_GT 260
#define YY_GE 261
#define YY_EQ 262
#define YY_LE 263
#define YY_LT 264
#define YY_NEQ 265
#define YY_NEQV 266
#define YY_EQV 267
#define YY_ANDAND 268
#define YY_OROR 269
#define YY_NOT 270
#define YY_POWER 271
#define YY_DOUBLECOLON 272
#define YY_NEG 273
#define YY_POS 274
#define YY_EXPONENT 275
#define YY_PLET 276
#define YY_INTEGER 277
#define YY_FLOAT 278
#define YY_WORD 279
#define YY_OPERATOR 280
#define YY_STRING 281
#define YY_ILLEGAL 282
#define YY_COMPLEX 283
#define YY_TRUE 284
#define YY_FALSE 285
#define YY_FORMAT_STMT 286
#define YY_COMMENT 287
#define YY_LABEL 288
#define YY_END 289
#define YY_IF 290
#define YY_THEN 291
#define YY_ELSE 292
#define YY_ELSEIF 293
#define YY_ENDIF 294
#define YY_DO 295
#define YY_ENDDO 296
#define YY_CONTINUE 297
#define YY_BREAK 298
#define YY_EXIT 299
#define YY_CYCLE 300
#define YY_WHILE 301
#define YY_ENDWHILE 302
#define YY_WHERE 303
#define YY_ENDWHERE 304
#define YY_CASE 305
#define YY_ENDCASE 306
#define YY_SELECT 307
#define YY_ENDSELECT 308
#define YY_GOTO 309
#define YY_DOWHILE 310
#define YY_DEFAULT 311
#define YY_TYPE 312
#define YY_ENDTYPE 313
#define YY_PROGRAM 314
#define YY_ENDPROGRAM 315
#define YY_FUNCTION 316
#define YY_ENDFUNCTION 317
#define YY_RECURSIVE 318
#define YY_RESULT 319
#define YY_SUBROUTINE 320
#define YY_ENDSUBROUTINE 321
#define YY_MODULE 322
#define YY_ENDMODULE 323
#define YY_BLOCK 324
#define YY_ENDBLOCK 325
#define YY_INTERFACE 326
#define YY_ENDINTERFACE 327
#define YY_COMMON 328
#define YY_DATA 329
#define YY_IMPLICIT 330
#define YY_NONE 331
#define YY_USE 332
#define YY_PARAMETER 333
#define YY_ENTRY 334
#define YY_DIMENSION 335
#define YY_ARRAYBUILDER_START 336
#define YY_ARRAYBUILDER_END 337
#define YY_INTENT 338
#define YY_IN 339
#define YY_OUT 340
#define YY_INOUT 341
#define YY_OPTIONAL 342
#define YY_LEN 343
#define YY_KIND 344
#define YY_SAVE 345
#define YY_ALLOCATABLE 346
#define YY_TARGET 347
#define YY_POINTER 348
#define YY_INTEGER_T 349
#define YY_FLOAT_T 350
#define YY_STRING_T 351
#define YY_COMPLEX_T 352
#define YY_BOOL_T 353
#define YY_CHARACTER_T 354
#define YY_DOUBLE_T 355
#define YY_WRITE 356
#define YY_READ 357
#define YY_PRINT 358
#define YY_CALL 359
#define YY_STOP 360
#define YY_PAUSE 361
#define YY_RETURN 362
#define YY_CONFIG_IMPLICIT 363
#define YY_ALLOCATE 364




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

