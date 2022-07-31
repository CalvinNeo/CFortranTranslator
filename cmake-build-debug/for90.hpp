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
     YY_PNULL = 277,
     YY_INTEGER = 278,
     YY_FLOAT = 279,
     YY_WORD = 280,
     YY_OPERATOR = 281,
     YY_STRING = 282,
     YY_ILLEGAL = 283,
     YY_COMPLEX = 284,
     YY_TRUE = 285,
     YY_FALSE = 286,
     YY_FORMAT_STMT = 287,
     YY_COMMENT = 288,
     YY_LABEL = 289,
     YY_END = 290,
     YY_IF = 291,
     YY_THEN = 292,
     YY_ELSE = 293,
     YY_ELSEIF = 294,
     YY_ENDIF = 295,
     YY_DO = 296,
     YY_ENDDO = 297,
     YY_CONTINUE = 298,
     YY_BREAK = 299,
     YY_EXIT = 300,
     YY_CYCLE = 301,
     YY_WHILE = 302,
     YY_ENDWHILE = 303,
     YY_WHERE = 304,
     YY_ENDWHERE = 305,
     YY_CASE = 306,
     YY_ENDCASE = 307,
     YY_SELECT = 308,
     YY_ENDSELECT = 309,
     YY_GOTO = 310,
     YY_DOWHILE = 311,
     YY_DEFAULT = 312,
     YY_TYPE = 313,
     YY_ENDTYPE = 314,
     YY_PROGRAM = 315,
     YY_ENDPROGRAM = 316,
     YY_FUNCTION = 317,
     YY_ENDFUNCTION = 318,
     YY_RECURSIVE = 319,
     YY_RESULT = 320,
     YY_SUBROUTINE = 321,
     YY_ENDSUBROUTINE = 322,
     YY_MODULE = 323,
     YY_ENDMODULE = 324,
     YY_BLOCK = 325,
     YY_ENDBLOCK = 326,
     YY_INTERFACE = 327,
     YY_ENDINTERFACE = 328,
     YY_COMMON = 329,
     YY_DATA = 330,
     YY_PROCEDURE = 331,
     YY_CONTAINS = 332,
     YY_IMPLICIT = 333,
     YY_NONE = 334,
     YY_USE = 335,
     YY_PARAMETER = 336,
     YY_ENTRY = 337,
     YY_DIMENSION = 338,
     YY_ARRAYBUILDER_START = 339,
     YY_ARRAYBUILDER_END = 340,
     YY_INTENT = 341,
     YY_IN = 342,
     YY_OUT = 343,
     YY_INOUT = 344,
     YY_OPTIONAL = 345,
     YY_LEN = 346,
     YY_KIND = 347,
     YY_SAVE = 348,
     YY_ALLOCATABLE = 349,
     YY_TARGET = 350,
     YY_POINTER = 351,
     YY_INTEGER_T = 352,
     YY_FLOAT_T = 353,
     YY_STRING_T = 354,
     YY_COMPLEX_T = 355,
     YY_BOOL_T = 356,
     YY_CHARACTER_T = 357,
     YY_DOUBLE_T = 358,
     YY_WRITE = 359,
     YY_READ = 360,
     YY_PRINT = 361,
     YY_CALL = 362,
     YY_STOP = 363,
     YY_PAUSE = 364,
     YY_RETURN = 365,
     YY_CONFIG_IMPLICIT = 366,
     YY_ALLOCATE = 367
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
#define YY_PNULL 277
#define YY_INTEGER 278
#define YY_FLOAT 279
#define YY_WORD 280
#define YY_OPERATOR 281
#define YY_STRING 282
#define YY_ILLEGAL 283
#define YY_COMPLEX 284
#define YY_TRUE 285
#define YY_FALSE 286
#define YY_FORMAT_STMT 287
#define YY_COMMENT 288
#define YY_LABEL 289
#define YY_END 290
#define YY_IF 291
#define YY_THEN 292
#define YY_ELSE 293
#define YY_ELSEIF 294
#define YY_ENDIF 295
#define YY_DO 296
#define YY_ENDDO 297
#define YY_CONTINUE 298
#define YY_BREAK 299
#define YY_EXIT 300
#define YY_CYCLE 301
#define YY_WHILE 302
#define YY_ENDWHILE 303
#define YY_WHERE 304
#define YY_ENDWHERE 305
#define YY_CASE 306
#define YY_ENDCASE 307
#define YY_SELECT 308
#define YY_ENDSELECT 309
#define YY_GOTO 310
#define YY_DOWHILE 311
#define YY_DEFAULT 312
#define YY_TYPE 313
#define YY_ENDTYPE 314
#define YY_PROGRAM 315
#define YY_ENDPROGRAM 316
#define YY_FUNCTION 317
#define YY_ENDFUNCTION 318
#define YY_RECURSIVE 319
#define YY_RESULT 320
#define YY_SUBROUTINE 321
#define YY_ENDSUBROUTINE 322
#define YY_MODULE 323
#define YY_ENDMODULE 324
#define YY_BLOCK 325
#define YY_ENDBLOCK 326
#define YY_INTERFACE 327
#define YY_ENDINTERFACE 328
#define YY_COMMON 329
#define YY_DATA 330
#define YY_PROCEDURE 331
#define YY_CONTAINS 332
#define YY_IMPLICIT 333
#define YY_NONE 334
#define YY_USE 335
#define YY_PARAMETER 336
#define YY_ENTRY 337
#define YY_DIMENSION 338
#define YY_ARRAYBUILDER_START 339
#define YY_ARRAYBUILDER_END 340
#define YY_INTENT 341
#define YY_IN 342
#define YY_OUT 343
#define YY_INOUT 344
#define YY_OPTIONAL 345
#define YY_LEN 346
#define YY_KIND 347
#define YY_SAVE 348
#define YY_ALLOCATABLE 349
#define YY_TARGET 350
#define YY_POINTER 351
#define YY_INTEGER_T 352
#define YY_FLOAT_T 353
#define YY_STRING_T 354
#define YY_COMPLEX_T 355
#define YY_BOOL_T 356
#define YY_CHARACTER_T 357
#define YY_DOUBLE_T 358
#define YY_WRITE 359
#define YY_READ 360
#define YY_PRINT 361
#define YY_CALL 362
#define YY_STOP 363
#define YY_PAUSE 364
#define YY_RETURN 365
#define YY_CONFIG_IMPLICIT 366
#define YY_ALLOCATE 367




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

