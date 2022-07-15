/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     YY_IMPLICIT = 331,
     YY_NONE = 332,
     YY_USE = 333,
     YY_PARAMETER = 334,
     YY_ENTRY = 335,
     YY_DIMENSION = 336,
     YY_ARRAYBUILDER_START = 337,
     YY_ARRAYBUILDER_END = 338,
     YY_INTENT = 339,
     YY_IN = 340,
     YY_OUT = 341,
     YY_INOUT = 342,
     YY_OPTIONAL = 343,
     YY_LEN = 344,
     YY_KIND = 345,
     YY_SAVE = 346,
     YY_ALLOCATABLE = 347,
     YY_TARGET = 348,
     YY_POINTER = 349,
     YY_INTEGER_T = 350,
     YY_FLOAT_T = 351,
     YY_STRING_T = 352,
     YY_COMPLEX_T = 353,
     YY_BOOL_T = 354,
     YY_CHARACTER_T = 355,
     YY_DOUBLE_T = 356,
     YY_WRITE = 357,
     YY_READ = 358,
     YY_PRINT = 359,
     YY_CALL = 360,
     YY_STOP = 361,
     YY_PAUSE = 362,
     YY_RETURN = 363,
     YY_CONFIG_IMPLICIT = 364,
     YY_ALLOCATE = 365
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
#define YY_IMPLICIT 331
#define YY_NONE 332
#define YY_USE 333
#define YY_PARAMETER 334
#define YY_ENTRY 335
#define YY_DIMENSION 336
#define YY_ARRAYBUILDER_START 337
#define YY_ARRAYBUILDER_END 338
#define YY_INTENT 339
#define YY_IN 340
#define YY_OUT 341
#define YY_INOUT 342
#define YY_OPTIONAL 343
#define YY_LEN 344
#define YY_KIND 345
#define YY_SAVE 346
#define YY_ALLOCATABLE 347
#define YY_TARGET 348
#define YY_POINTER 349
#define YY_INTEGER_T 350
#define YY_FLOAT_T 351
#define YY_STRING_T 352
#define YY_COMPLEX_T 353
#define YY_BOOL_T 354
#define YY_CHARACTER_T 355
#define YY_DOUBLE_T 356
#define YY_WRITE 357
#define YY_READ 358
#define YY_PRINT 359
#define YY_CALL 360
#define YY_STOP 361
#define YY_PAUSE 362
#define YY_RETURN 363
#define YY_CONFIG_IMPLICIT 364
#define YY_ALLOCATE 365




/* Copy the first part of user declarations.  */
#line 20 "src/grammar/for90.y"

#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include <tuple>
#include <stdint.h>
#include "../parser/attribute.h"
#include "../parser/parser.h"
#include "../target/gen_common.h"
#include "../parser/Function.h"


void yyerror(const char* s); 

#ifdef USE_LEX
int pure_yylex(void);
void set_buff(const std::string & code);
void release_buff();
#else
#include "simple_lexer.h"
#endif

#define YYDEBUG 1
#define YYERROR_VERBOSE
#define YYINITDEPTH 2000

// update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) 
void update_pos(ParseNode & current) {
	if (current.length() == 0) {
		// do nothing 
		current.fs.parse_pos = 0;
		current.fs.parse_line = 0;
		current.fs.parse_len = 0;
		current.fs.line_pos = 0;
	}
	else if (current.length() == 1) {
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = current.get(0).fs.parse_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.length(); i++)
		{
			tot_len += current.get(i).fs.parse_len;
		}
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = tot_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
}
void update_pos(ParseNode & current, const ParseNode & start, const ParseNode & end) {
	// if replace $$ with newnode then need to update_pos
	if (start.fs.parse_len == 0) {
		current.fs.parse_pos = end.fs.parse_pos;
		current.fs.parse_line = end.fs.parse_line;
		current.fs.parse_len = end.fs.parse_len;
		current.fs.line_pos = end.fs.line_pos;
	}
	else if (end.fs.parse_len == 0) {
		current.fs.parse_pos = start.fs.parse_pos;
		current.fs.parse_line = start.fs.parse_line;
		current.fs.parse_len = start.fs.parse_len;
		current.fs.line_pos = start.fs.line_pos;
	}
	else {
		current.fs.parse_pos = start.fs.parse_pos;
		current.fs.parse_line = start.fs.parse_line;
		current.fs.parse_len = end.fs.parse_len + end.fs.parse_pos - start.fs.parse_pos;
		current.fs.line_pos = start.fs.line_pos;
	}
}
using namespace std;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 405 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  177
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNRULES -- Number of states.  */
#define YYNSTATES  433

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     120,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   122,     2,     2,
     116,   117,   113,   111,   118,   112,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   121,   115,
       2,   119,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    20,    25,    30,    35,    40,    45,    47,    49,    51,
      53,    55,    57,    59,    63,    64,    68,    72,    74,    76,
      80,    82,    84,    86,    88,    90,    93,    95,    97,   101,
     107,   109,   111,   115,   121,   125,   127,   131,   133,   137,
     141,   145,   150,   155,   157,   160,   163,   165,   167,   171,
     175,   179,   183,   187,   191,   194,   197,   201,   205,   209,
     213,   217,   221,   224,   228,   232,   236,   240,   244,   246,
     248,   250,   252,   256,   260,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   282,   284,   286,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   316,   319,   321,   324,   326,   332,   336,   340,   346,
     349,   355,   358,   363,   365,   369,   371,   375,   377,   381,
     383,   387,   389,   391,   393,   395,   397,   403,   406,   410,
     414,   418,   420,   422,   424,   426,   428,   430,   432,   437,
     442,   446,   452,   454,   458,   461,   462,   466,   471,   475,
     478,   480,   482,   485,   492,   494,   498,   502,   506,   507,
     509,   511,   513,   523,   527,   529,   532,   533,   540,   551,
     561,   574,   585,   599,   607,   616,   618,   619,   626,   639,
     654,   662,   672,   679,   686,   691,   698,   700,   703,   708,
     709,   711,   713,   715,   717,   719,   730,   737,   739,   740,
     742,   744,   747,   754,   756,   758,   760,   762,   764,   766,
     768,   772,   780
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     190,     0,    -1,     4,    -1,    -1,   127,    -1,   125,   127,
      -1,   115,    -1,     4,    -1,   126,    -1,    64,    -1,    -1,
      84,   116,    85,   117,    -1,    84,   116,    86,   117,    -1,
      84,   116,    87,   117,    -1,    81,   116,   168,   117,    -1,
      81,   116,   140,   117,    -1,    81,    -1,    88,    -1,    79,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,   118,
     129,   130,    -1,    -1,    90,   119,    23,    -1,    89,   119,
     140,    -1,   140,    -1,    24,    -1,    23,    20,    23,    -1,
      23,    -1,    27,    -1,    30,    -1,    31,    -1,    29,    -1,
       1,   120,    -1,    25,    -1,   141,    -1,   140,   121,   140,
      -1,   140,   121,   140,   121,   140,    -1,   121,    -1,   113,
      -1,   140,   119,   140,    -1,   140,    21,    22,   116,   117,
      -1,   140,    21,   140,    -1,   140,    -1,   136,   118,   140,
      -1,   134,    -1,   137,   118,   134,    -1,   137,   118,   140,
      -1,   136,   118,   134,    -1,   133,   116,   168,   117,    -1,
     160,   116,   168,   117,    -1,   138,    -1,   105,   138,    -1,
     105,   133,    -1,   139,    -1,   171,    -1,   116,   140,   117,
      -1,   140,   111,   140,    -1,   140,   112,   140,    -1,   140,
     113,   140,    -1,   140,   114,   140,    -1,   140,    16,   140,
      -1,   112,   140,    -1,   111,   140,    -1,   140,    10,   140,
      -1,   140,    11,   140,    -1,   140,     7,   140,    -1,   140,
      12,   140,    -1,   140,    13,   140,    -1,   140,    14,   140,
      -1,    15,   140,    -1,   140,     5,   140,    -1,   140,     6,
     140,    -1,   140,     8,   140,    -1,   140,     9,   140,    -1,
     140,    26,   140,    -1,   169,    -1,   132,    -1,   133,    -1,
     141,    -1,   133,   122,    25,    -1,   138,   122,    25,    -1,
     141,   122,    25,    -1,   140,    -1,   164,    -1,   145,    -1,
     144,    -1,   150,    -1,   149,    -1,   163,    -1,    32,    -1,
      33,    -1,   143,    -1,   152,    -1,    -1,   147,    -1,   148,
      -1,    43,    -1,   108,    -1,   146,    -1,   157,    -1,   158,
      -1,   159,    -1,   173,    -1,   176,    -1,   177,    -1,    46,
      -1,    45,    -1,    55,    23,    -1,   107,   132,    -1,   107,
      -1,   106,   132,    -1,   106,    -1,   140,    21,    22,   116,
     117,    -1,   140,    21,   140,    -1,   140,   119,   140,    -1,
      75,   136,   114,   136,   114,    -1,    76,    77,    -1,    76,
     160,   116,   168,   117,    -1,    34,   142,    -1,   110,   116,
     168,   117,    -1,   151,    -1,   151,   127,   153,    -1,   142,
      -1,   142,   127,   153,    -1,   189,    -1,   189,   127,   153,
      -1,   166,    -1,   166,   127,   153,    -1,   113,    -1,    23,
      -1,   113,    -1,    23,    -1,    27,    -1,   116,   154,   118,
     155,   117,    -1,   155,   118,    -1,   102,   156,   168,    -1,
     104,   156,   168,    -1,   103,   156,   168,    -1,    95,    -1,
      96,    -1,   101,    -1,    97,    -1,    98,    -1,    99,    -1,
     100,    -1,    58,   116,    25,   117,    -1,   160,   116,   131,
     117,    -1,   160,   113,    23,    -1,   160,   113,   116,   113,
     117,    -1,   160,    -1,   114,    25,   114,    -1,   114,   114,
      -1,    -1,    74,   162,   168,    -1,   161,   130,    17,   168,
      -1,   161,   130,   168,    -1,   129,   168,    -1,    59,    -1,
      35,    -1,    35,    58,    -1,    58,    25,   125,   153,   165,
     184,    -1,   135,    -1,   167,   118,   135,    -1,   167,   118,
     140,    -1,   136,   118,   135,    -1,    -1,   167,    -1,   136,
      -1,   137,    -1,   116,   136,   118,   133,   119,   140,   118,
     140,   117,    -1,    82,   168,    83,    -1,   170,    -1,    25,
     121,    -1,    -1,   172,    36,   116,   140,   117,   142,    -1,
     172,    36,   116,   140,   117,    23,   118,    23,   118,    23,
      -1,   172,    36,   116,   140,   117,    37,   125,   153,    40,
      -1,   172,    36,   116,   140,   117,    37,   125,   153,    38,
     125,   153,    40,    -1,   172,    36,   116,   140,   117,    37,
     125,   153,   174,    40,    -1,   172,    36,   116,   140,   117,
      37,   125,   153,   174,    38,   125,   153,    40,    -1,    39,
     116,   140,   117,    37,   125,   153,    -1,    39,   116,   140,
     117,    37,   125,   153,   174,    -1,    23,    -1,    -1,   172,
      41,   125,   153,   124,    42,    -1,   172,    41,   175,   133,
     119,   140,   118,   140,   125,   153,   124,    42,    -1,   172,
      41,   175,   133,   119,   140,   118,   140,   118,   140,   125,
     153,   124,    42,    -1,   172,    56,   140,   125,   153,   124,
      42,    -1,   172,    53,    51,   116,   140,   117,   125,   179,
      54,    -1,    51,   116,   137,   117,   125,   153,    -1,    51,
     116,   136,   117,   125,   153,    -1,    51,    57,   125,   153,
      -1,    51,   116,    57,   117,   125,   153,    -1,   178,    -1,
     178,   179,    -1,    65,   116,   133,   117,    -1,    -1,    62,
      -1,    66,    -1,    63,    -1,    67,    -1,    35,    -1,   128,
     181,    25,   116,   168,   117,   180,   125,   153,   182,    -1,
     128,   181,    25,   125,   153,   182,    -1,    25,    -1,    -1,
      61,    -1,    35,    -1,    35,    60,    -1,    60,   184,   125,
     153,   185,   184,    -1,   186,    -1,   183,    -1,   166,    -1,
     142,    -1,   151,    -1,    35,    -1,   187,    -1,   187,   125,
     188,    -1,    72,   184,   125,   188,   124,    73,   184,    -1,
     188,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   155,   160,   166,   173,   180,   185,   191,
     197,   202,   210,   219,   227,   239,   253,   262,   270,   279,
     288,   297,   306,   316,   331,   344,   358,   373,   388,   396,
     405,   412,   421,   427,   433,   443,   451,   459,   473,   483,
     494,   505,   518,   530,   538,   548,   557,   575,   588,   610,
     632,   656,   667,   679,   684,   690,   710,   719,   726,   735,
     745,   755,   765,   775,   785,   794,   803,   813,   824,   834,
     845,   855,   865,   874,   884,   894,   903,   913,   933,   940,
     960,   965,   971,   981,   990,  1001,  1013,  1019,  1025,  1031,
    1036,  1043,  1049,  1057,  1064,  1070,  1077,  1082,  1088,  1094,
    1100,  1106,  1113,  1118,  1123,  1129,  1134,  1139,  1145,  1151,
    1157,  1165,  1172,  1179,  1186,  1193,  1205,  1217,  1228,  1266,
    1273,  1284,  1303,  1312,  1320,  1334,  1341,  1354,  1362,  1374,
    1382,  1394,  1404,  1411,  1420,  1429,  1463,  1476,  1491,  1501,
    1512,  1522,  1528,  1534,  1540,  1546,  1552,  1558,  1564,  1583,
    1590,  1596,  1602,  1608,  1614,  1622,  1628,  1637,  1649,  1669,
    1719,  1724,  1729,  1735,  1745,  1753,  1761,  1770,  1780,  1787,
    1792,  1797,  1803,  1821,  1831,  1839,  1846,  1854,  1866,  1872,
    1881,  1891,  1901,  1913,  1923,  1934,  1940,  1945,  1953,  1977,
    1989,  1999,  2010,  2021,  2032,  2040,  2050,  2058,  2068,  2075,
    2081,  2086,  2092,  2097,  2102,  2108,  2123,  2136,  2142,  2147,
    2152,  2157,  2163,  2171,  2176,  2181,  2191,  2198,  2203,  2211,
    2219,  2237,  2245
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "YY_IGNORE_THIS", "YY_CRLF", "YY_GT",
  "YY_GE", "YY_EQ", "YY_LE", "YY_LT", "YY_NEQ", "YY_NEQV", "YY_EQV",
  "YY_ANDAND", "YY_OROR", "YY_NOT", "YY_POWER", "YY_DOUBLECOLON", "YY_NEG",
  "YY_POS", "YY_EXPONENT", "YY_PLET", "YY_PNULL", "YY_INTEGER", "YY_FLOAT",
  "YY_WORD", "YY_OPERATOR", "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX",
  "YY_TRUE", "YY_FALSE", "YY_FORMAT_STMT", "YY_COMMENT", "YY_LABEL",
  "YY_END", "YY_IF", "YY_THEN", "YY_ELSE", "YY_ELSEIF", "YY_ENDIF",
  "YY_DO", "YY_ENDDO", "YY_CONTINUE", "YY_BREAK", "YY_EXIT", "YY_CYCLE",
  "YY_WHILE", "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE", "YY_CASE",
  "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE",
  "YY_DEFAULT", "YY_TYPE", "YY_ENDTYPE", "YY_PROGRAM", "YY_ENDPROGRAM",
  "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT",
  "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE",
  "YY_BLOCK", "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE",
  "YY_COMMON", "YY_DATA", "YY_IMPLICIT", "YY_NONE", "YY_USE",
  "YY_PARAMETER", "YY_ENTRY", "YY_DIMENSION", "YY_ARRAYBUILDER_START",
  "YY_ARRAYBUILDER_END", "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT",
  "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_SAVE", "YY_ALLOCATABLE",
  "YY_TARGET", "YY_POINTER", "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T",
  "YY_COMPLEX_T", "YY_BOOL_T", "YY_CHARACTER_T", "YY_DOUBLE_T", "YY_WRITE",
  "YY_READ", "YY_PRINT", "YY_CALL", "YY_STOP", "YY_PAUSE", "YY_RETURN",
  "YY_CONFIG_IMPLICIT", "YY_ALLOCATE", "'+'", "'-'", "'*'", "'/'", "';'",
  "'('", "')'", "','", "'='", "'\\n'", "':'", "'%'", "$accept",
  "crlf_or_not", "at_least_one_end_line", "semicolon", "end_of_stmt",
  "dummy_function_iden", "variable_desc_elem", "variable_desc",
  "type_selector", "literal", "variable", "slice", "keyvalue", "argtable",
  "dimen_slice", "function_array_body", "function_array", "exp",
  "inner_variable", "stmt", "control_stmt", "io_stmt", "compound_stmt",
  "jump_stmt", "pause_stmt", "stop_stmt", "let_stmt", "implicit_stmt",
  "labeled_stmts", "allocate_stmt", "suite", "_optional_device",
  "_optional_formatter", "io_info", "write", "print", "read", "type_name",
  "type_spec", "_blockname_or_none", "common_stmt", "var_def",
  "_optional_endtype", "type_decl", "pure_paramtable", "paramtable",
  "hidden_do", "array_builder_elem", "array_builder",
  "_optional_construct_name", "if_stmt", "elseif_stmt",
  "_optional_label_construct", "do_stmt", "select_stmt", "case_stmt_elem",
  "case_stmt", "_optional_result", "_optional_function",
  "_optional_endfunction", "function_decl", "_optional_name",
  "_optional_endprogram", "program", "wrapper", "wrappers",
  "interface_decl", "fortran_program", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,    43,    45,    42,    47,    59,    40,    41,    44,    61,
      10,    58,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   130,   130,   131,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   136,   136,   137,   137,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   143,   144,   144,   144,   145,   145,   145,   146,   146,
     146,   147,   147,   148,   148,   149,   149,   149,   149,   150,
     150,   151,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   156,   156,   157,   158,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   161,   162,   162,   162,   163,   164,   164,   164,
     165,   165,   165,   166,   167,   167,   167,   167,   167,   168,
     168,   168,   169,   170,   171,   172,   172,   173,   173,   173,
     173,   173,   173,   174,   174,   175,   175,   176,   176,   176,
     176,   177,   178,   178,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   182,   183,   183,   184,   184,   185,
     185,   185,   186,   187,   187,   187,   187,   187,   187,   188,
     188,   189,   190
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       0,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     3,     5,
       1,     1,     3,     5,     3,     1,     3,     1,     3,     3,
       3,     4,     4,     1,     2,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     1,     5,     3,     3,     5,     2,
       5,     2,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     5,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     5,     1,     3,     2,     0,     3,     4,     3,     2,
       1,     1,     2,     6,     1,     3,     3,     3,     0,     1,
       1,     1,     9,     3,     1,     2,     0,     6,    10,     9,
      12,    10,    13,     7,     8,     1,     0,     6,    12,    14,
       7,     9,     6,     6,     4,     6,     1,     2,     4,     0,
       1,     1,     1,     1,     1,    10,     6,     1,     0,     1,
       1,     2,     6,     1,     1,     1,     1,     1,     1,     1,
       3,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    30,    28,    36,    31,    34,    32,    33,
      92,    93,     0,   218,    99,   109,   108,     0,     0,   208,
       9,   155,     0,     0,    18,    16,     0,     0,    17,    19,
      20,    21,    22,   141,   142,   144,   145,   146,   147,   143,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,    79,    80,    53,    56,    85,    37,   216,
      94,    88,    87,   101,    97,    98,    90,    89,   217,    95,
     102,   103,   104,   152,    24,    91,    86,   215,    78,   174,
      57,     0,   105,   106,   107,   214,   213,   219,   222,     0,
      35,    36,     0,    72,     0,     0,   175,   121,   110,     0,
       0,   207,     0,     0,     0,     0,    45,   119,     0,     0,
      41,    40,    47,   164,   170,   171,    45,   169,     0,     0,
     134,   135,   133,     0,     0,     0,     0,     0,    55,    54,
      37,   113,   111,     0,    65,    64,     0,    45,   200,   201,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     7,     6,     0,     8,     4,     1,     0,    29,
       0,     0,     0,     0,   154,   156,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,   132,   131,     0,   137,   138,   140,   139,     0,     0,
      58,     0,     0,    82,    83,    73,    74,    68,    75,    76,
      66,    67,    69,    70,    71,    63,     0,   116,    77,    59,
      60,    61,    62,   117,    84,   150,     0,     0,     0,     0,
      27,     0,    24,     0,   158,     0,   185,     0,     0,     0,
       0,     5,   220,   208,   125,   123,     0,   129,   127,   148,
       0,   153,     0,    46,     0,    15,    14,    50,   167,    46,
      48,    49,     0,    44,    42,    38,   165,   166,    11,    12,
      13,     0,   122,    80,     0,     0,    51,     0,     0,     0,
       0,   149,    52,    23,   157,     0,     3,     0,     0,     0,
       0,     0,     0,     0,   161,   160,   208,     0,     0,   210,
     209,   208,   118,   120,     0,     0,     0,     0,     0,     0,
     115,   151,    26,    25,     0,     2,     0,     0,     0,     3,
       0,   126,   124,   162,   163,   130,   128,   211,   212,    43,
      39,   136,     0,   199,   204,   202,   203,   206,    30,     0,
     177,   187,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,   208,   172,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,   197,   191,   221,
     198,   205,   178,     0,     0,     0,   181,     0,     3,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,   180,     0,     0,     3,   188,     0,
       0,    46,     0,     0,   182,     0,   195,   193,   192,     0,
     189,   183,   184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   326,   174,   175,   176,    51,    52,   167,   239,    53,
      54,   112,   113,   114,   115,    55,    56,    57,    58,   254,
      60,    61,    62,    63,    64,    65,    66,    67,   255,    69,
     256,   203,   124,   125,    70,    71,    72,    94,    74,   104,
      75,    76,   306,   257,   117,   241,    78,    79,    80,    81,
      82,   382,   248,    83,    84,   372,   373,   358,   140,   347,
      85,   102,   311,    86,    87,    88,   258,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -280
static const yytype_int16 yypact[] =
{
    1346,   -60,  2679,    51,  -280,   -41,  -280,  -280,  -280,  -280,
    -280,  -280,  1120,  -280,  -280,  -280,  -280,    64,    -6,    65,
    -280,   -17,  2679,   218,  -280,    -8,   738,    -5,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
      45,    45,    45,   159,  2781,  2826,  -280,    19,  2679,  2679,
    2679,    11,   614,  -280,   -68,    -2,  -280,  2895,    24,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   -34,    33,  -280,  -280,  -280,  -280,  -280,
    -280,    22,  -280,  -280,  -280,  -280,  -280,     6,  -280,   132,
    -280,  -280,    67,  1245,    69,   136,  -280,  -280,  -280,     6,
     137,  -280,     6,     3,   614,    16,  3100,  -280,    71,   782,
    -280,  -280,  -280,  -280,    57,    70,  1480,    90,   127,   157,
    -280,  -280,  -280,    10,    94,   614,   614,   614,   -68,    -2,
      24,  -280,  -280,   782,    43,    43,    96,  2961,  -280,  -280,
     191,  -280,   782,   194,   200,  2679,  2679,  2679,  2679,  2679,
    2679,  2679,  2679,  2679,  2679,  2679,  2629,  2679,  2679,  2679,
    2679,  2679,  2679,   201,   -14,   659,     7,   512,   112,    26,
     178,  2679,  -280,  -280,  1233,  -280,  -280,  -280,   782,  -280,
    2069,   116,  2182,   120,  -280,  -280,  2679,  2679,   782,  1458,
     128,   905,   905,  2654,  2679,  2679,  2679,  -280,   129,   144,
     145,  -280,  -280,   130,  -280,  -280,  -280,  -280,   146,  2679,
    -280,    12,   148,  -280,  -280,    43,    43,   265,    43,    43,
     265,   477,   477,  1245,  3125,    48,   150,  3100,  3100,     1,
       1,    48,    48,  3100,  -280,  -280,   154,   149,   153,   161,
      31,   162,    33,   614,  -280,  2679,  -280,  2408,   159,   164,
    3078,  -280,  -280,    65,     6,     6,    -4,     6,     6,  -280,
     -10,  -280,    46,  3100,   165,  -280,  -280,  -280,  -280,  1480,
    -280,  1502,   167,  3100,  3100,  1524,  -280,  2917,  -280,  -280,
    -280,    -1,  -280,    17,   782,  1843,  -280,   169,   173,  2679,
     261,  -280,  -280,  -280,  -280,  2984,   288,   105,    -2,  2679,
    2408,     6,  1617,  1617,   235,  -280,    65,  1617,  1617,   234,
    -280,    65,  -280,  -280,   179,  2679,   180,  2679,   181,    18,
    -280,  -280,  3100,  -280,  1007,  -280,   257,  2679,  3011,   288,
    1730,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    3100,  -280,   590,   236,  -280,  -280,  -280,  -280,    -9,     6,
    -280,  -280,  2939,     6,   262,   288,  2679,   189,     6,   283,
    1956,  2679,    14,  -280,   237,  3033,   159,  1843,   193,   212,
    2578,   -33,   258,   266,    65,  -280,     9,    18,   289,     6,
     206,  -280,    78,  2679,  2408,     6,   861,  -280,  -280,  -280,
    -280,  -280,  -280,  2521,  2679,     6,  -280,  3078,   288,  2295,
     208,   -83,    49,  1502,   287,  3055,  2521,  2408,   281,  -280,
       6,     6,   905,     6,  -280,   292,   297,   288,  -280,  2295,
    2295,  1502,  2295,     6,  -280,   298,  -280,  -280,  -280,  1956,
    -280,   302,  -280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -279,    38,  -280,    95,  -280,   182,   102,  -280,    59,
     -28,  -171,  -129,   -21,   -40,   -35,  -280,    44,   -30,     2,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,     4,  -280,
     139,  -280,    66,   131,  -280,  -280,  -280,     0,  -280,  -280,
    -280,  -280,  -280,     5,  -280,   -20,  -280,  -280,  -280,  -280,
    -280,   -86,  -280,  -280,  -280,  -280,   -18,  -280,  -280,   -26,
    -280,  -250,  -280,  -280,  -280,  -167,  -280,  -280
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -177
static const yytype_int16 yytable[] =
{
      73,   105,    59,   301,    68,    77,   118,   252,   129,   235,
     172,    95,    73,   130,    97,   128,   172,   155,   172,    99,
     267,   270,   120,   108,   385,   309,   121,   157,   183,   136,
     172,   304,   141,   201,   411,   412,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    93,   155,   142,   246,
     354,   310,   193,   344,   143,   305,   334,   157,   168,   155,
      90,   338,   268,   169,   155,   371,   106,   276,   120,   157,
     116,    95,   121,   138,   157,   170,   364,   139,   171,   164,
      96,   345,   165,   386,   185,   346,    24,    98,    25,   190,
     101,    27,   134,   135,   137,    28,   116,   103,    29,    30,
      31,    32,   236,   131,   132,   205,   206,   207,   109,   359,
     100,   119,   122,   208,   160,   161,   395,   184,   396,   408,
     144,   173,   212,   202,   389,   142,   390,   173,   284,   173,
     186,   143,   177,   142,   187,   133,   317,   180,   425,   143,
     182,   173,   158,   159,   160,   161,   163,   244,   116,   -45,
     194,   166,   195,   189,   158,   159,   160,   161,   122,   179,
     312,   123,   181,   355,   187,   262,   413,   192,   264,   116,
     116,   116,   126,   127,    73,   191,    59,   116,    68,    77,
      73,   283,    73,   100,    91,   178,   116,   188,   192,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     227,   228,   229,   230,   231,   232,   233,   247,   196,   240,
     197,   116,   204,   298,   209,   250,   211,    92,   130,   213,
     297,   142,   116,   294,   327,   214,   234,   143,   245,   249,
     106,   263,   116,   259,   261,   269,   271,   273,   274,   275,
     277,   267,   198,   199,   200,   266,   278,    73,   281,   285,
     379,   380,   381,   263,    33,    34,    35,    36,    37,    38,
      39,   279,   280,   282,   318,   286,   287,   288,   289,   251,
     145,   146,   290,   148,   149,   251,    92,   251,   291,   292,
     299,   155,   313,   314,   323,    73,   320,   116,   300,   295,
     321,   157,   325,   333,   337,   107,   339,   341,   343,   351,
      73,   357,    73,    73,   363,   366,   368,    73,    73,   371,
     374,   378,   392,    33,    34,    35,    36,    37,    38,    39,
     388,   260,   394,   418,    73,   410,   350,   414,   116,   423,
      73,   298,    59,   322,    68,    77,   130,   424,   376,   330,
     430,   380,   251,   328,   293,   432,   402,   316,   242,   302,
     303,   391,   307,   308,   387,     0,     0,     0,     0,   340,
      73,   342,     0,     0,     0,   401,     0,    73,     0,     0,
       0,   352,     0,     0,     0,     0,   158,   159,   160,   161,
     251,     0,     0,     0,    73,     0,   296,   360,     0,     0,
       0,   362,     0,    73,     0,   251,   367,     0,     0,    73,
     365,     0,     0,     0,     0,   370,    73,    73,   384,     0,
       0,     0,     0,     0,     0,     0,     0,   393,     0,    73,
      73,     0,    73,   399,   319,   251,     0,   397,     0,    73,
     403,     0,     0,   406,     0,   407,     0,     0,   405,   329,
       0,   331,   332,     0,     0,     0,   335,   336,   419,   420,
       0,   422,     0,     0,     0,   251,   421,   251,     0,     0,
       0,   429,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,     0,   145,   146,   147,   148,   149,   150,   251,     0,
     153,   154,     0,   155,   251,     0,     0,     0,     0,   369,
       0,   251,   251,   157,     0,     0,   377,     0,     0,     0,
       0,     0,  -168,     1,   251,   251,  -168,   251,     0,     0,
       0,     0,     0,   398,   251,     0,     0,     2,     0,   243,
       0,     0,   404,     0,     0,     3,     4,    91,   409,     6,
       0,     7,     8,     9,     0,   416,   417,  -168,     0,     0,
    -168,  -168,  -168,     0,  -168,     0,     0,     0,   426,   427,
       0,   428,     0,  -168,     0,     0,  -168,     0,   431,     0,
      92,  -168,     0,  -168,     0,  -168,     0,     0,     0,  -168,
       0,     0,     0,     0,     0,  -168,     0,     0,   158,   159,
     160,   161,     0,     0,    26,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,    33,    34,    35,
      36,    37,    38,    39,  -168,     1,   157,    43,  -168,     0,
       0,     0,     0,    48,    49,   110,     0,  -168,    50,     2,
    -168,     0,     0,   111,     0,     0,     0,     3,     4,    91,
       0,     6,     0,     7,     8,     9,     0,     0,     0,  -168,
       0,     0,  -168,  -168,  -168,     0,  -168,     0,     0,     0,
       1,     0,     0,     0,     0,  -168,     0,     0,  -168,     0,
       0,     0,    92,  -168,     2,  -168,     0,  -168,     0,     0,
       0,  -168,     3,     4,    91,     0,     6,  -168,     7,     8,
       9,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,   158,   159,   160,   161,     0,     0,     0,   356,    33,
      34,    35,    36,    37,    38,    39,     0,    92,     0,    43,
       0,     0,     0,     0,     0,    48,    49,   110,     0,  -168,
      50,     0,  -168,     0,     0,   111,     0,     0,     0,     1,
       0,    26,     0,     0,     0,     0,     0,     0,   237,   238,
       0,     0,     0,     2,    33,    34,    35,    36,    37,    38,
      39,     3,     4,    91,    43,     6,     0,     7,     8,     9,
      48,    49,   110,     0,     0,    50,  -168,  -168,     0,     0,
     111,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,    91,     0,     6,
       0,     7,     8,     9,     0,     0,     0,     0,     0,     0,
      26,  -168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    38,    39,
      92,     0,     0,    43,     0,     0,     0,     0,     0,    48,
      49,   110,     0,     0,    50,     0,  -168,     0,     0,   111,
       0,     0,     1,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,    33,    34,    35,
      36,    37,    38,    39,     3,     4,    91,    43,     6,     0,
       7,     8,     9,    48,    49,   110,     0,     0,    50,  -168,
    -168,     0,     0,   111,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,    92,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
      91,     0,     6,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    92,     0,     0,    43,     0,     0,     0,
       0,     0,    48,    49,   110,     0,     0,    50,     0,     0,
       0,     0,   111,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,    39,   -96,     1,     0,
      43,   -96,     0,     0,     0,     0,    48,    49,   110,     0,
       0,    50,     2,     0,     0,     0,   111,     0,     0,     0,
     348,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,     0,   -96,  -176,   349,   -96,   -96,   -96,  -176,   -96,
      14,     0,    15,    16,     0,     0,     0,     0,   -96,     0,
    -176,   -96,    17,  -176,     0,    92,   -96,     0,   -96,     0,
     -96,     0,     0,     0,   -96,     0,     0,     0,     0,     0,
     -96,    21,    22,    23,     0,     0,    24,     0,    25,    26,
       0,    27,     0,     0,     0,    28,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    47,    48,    49,
     -96,     1,   -96,    50,   -96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,     0,   -96,  -176,     0,   -96,   -96,
     -96,  -176,   -96,    14,     0,    15,    16,     0,     0,     0,
       0,   -96,     0,  -176,   -96,    17,  -176,     0,    92,   -96,
       0,   -96,     0,   -96,     0,     0,     0,   -96,     0,     0,
       0,     0,     0,   -96,    21,    22,    23,     0,     0,    24,
       0,    25,    26,     0,    27,     0,     0,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,   -96,     1,   -96,    50,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
     145,   146,   147,   148,   149,   150,     3,     4,     5,     0,
       6,   155,     7,     8,     9,    10,    11,    12,    13,  -176,
       0,   157,     0,     0,  -176,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -176,     0,    17,  -176,
       0,    18,     0,    19,     0,   -10,     0,    20,     0,   -10,
       0,     0,     0,     0,     0,     0,   -96,    21,    22,    23,
       0,     0,    24,     0,    25,    26,     0,    27,     0,     0,
       0,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    47,    48,    49,   -96,     1,   173,    50,
     -96,     0,     0,     0,     0,     0,   158,   159,   160,   161,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
      12,    13,  -176,     0,     0,     0,     0,  -176,     0,    14,
       0,    15,    16,     0,     0,     0,     0,     0,     0,  -176,
       0,    17,  -176,     0,    18,     0,    19,     0,   -10,     0,
      20,     0,   -10,     0,     0,     0,     0,     0,     0,     0,
      21,    22,    23,     0,     0,    24,     0,    25,    26,     0,
      27,     0,     0,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,     0,
       0,   -96,    50,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,     0,     0,     0,     0,   193,
       0,     0,     0,     0,   157,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,     0,     0,     0,
       0,   193,     0,     0,     0,     0,   157,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,   160,   161,     0,     0,   265,     0,   194,     0,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,   160,   161,     0,     0,     0,     0,   194,
       0,   195,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,   160,   161,     0,     1,     0,
       0,   -96,     0,   195,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,   158,   159,   160,   161,     0,
       3,     4,     5,     0,     6,   315,     7,     8,     9,    10,
      11,    12,   -96,  -176,     0,   -96,   -96,   -96,  -176,   -96,
      14,     0,    15,    16,     0,     0,     0,     0,   -96,     0,
    -176,   -96,    17,  -176,     0,    18,   -96,     0,   -96,     0,
     -96,     0,     0,     0,   -96,     0,     0,     0,     0,   253,
       0,    21,    22,    23,     0,     0,    24,     0,    25,    26,
       0,    27,     0,     0,     0,    28,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    47,    48,    49,
       0,     1,   -96,    50,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,  -176,     0,     0,     0,
       0,  -176,     0,    14,     0,    15,    16,     0,     0,     0,
       0,     0,     0,  -176,     0,    17,  -176,     0,    18,     0,
      19,     0,   -10,     0,    20,     0,   -10,     0,     0,     0,
       0,     0,     0,   -96,    21,    22,    23,     0,     0,    24,
       0,    25,    26,     0,    27,     0,     0,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,     0,     1,   173,    50,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,   -96,  -176,
       0,     0,     0,     0,  -176,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -176,     0,    17,  -176,
       0,    18,     0,     0,     0,     0,   -96,     0,     0,     0,
     -96,     0,     0,     0,     0,   253,     0,    21,    22,    23,
       0,     0,    24,     0,    25,    26,     0,    27,     0,     0,
       0,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    47,    48,    49,     0,     1,   173,    50,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
      12,     0,  -176,     0,   -96,   -96,   -96,  -176,     0,    14,
       0,    15,    16,     0,     0,     0,     0,     0,     0,  -176,
       0,    17,  -176,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
      21,    22,    23,     0,     0,    24,     0,    25,    26,     0,
      27,     0,     0,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,     0,
       1,   173,    50,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,   -96,  -176,     0,     0,     0,     0,
    -176,     0,    14,     0,    15,    16,     0,     0,     0,     0,
       0,     0,  -176,     0,    17,  -176,     0,    18,   -96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,     0,    21,    22,    23,     0,     0,    24,     0,
      25,    26,     0,    27,     0,     0,     0,    28,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    47,
      48,    49,     0,     1,   173,    50,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,    10,    11,    12,   -96,  -176,     0,
       0,     0,     0,  -176,     0,    14,     0,    15,    16,     0,
       0,     0,     0,     0,     0,  -176,     0,    17,  -176,     0,
      18,     0,     0,   -96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,    21,    22,    23,     0,
       0,    24,     0,    25,    26,     0,    27,     0,     0,     0,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,     0,     1,   173,    50,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
       0,  -176,     0,     0,     0,     0,  -176,     0,    14,     0,
      15,    16,     0,     0,     0,     0,   -96,     0,  -176,   -96,
      17,  -176,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,    21,
      22,    23,     0,     0,    24,     0,    25,    26,     0,    27,
       0,     0,     0,    28,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,     0,     1,
     173,    50,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,     0,  -176,     0,     0,     0,     0,  -176,
     -96,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -176,     0,    17,  -176,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,    21,    22,    23,     0,     0,    24,     0,    25,
      26,     0,    27,     0,     0,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,     0,     1,   173,    50,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,    12,     0,  -176,     0,     0,
       0,   -96,  -176,     0,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,  -176,     0,    17,  -176,     0,    18,
       0,     0,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   253,   155,    21,    22,    23,     0,     0,
      24,     0,    25,    26,   157,    27,     0,     0,     0,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       1,    47,    48,    49,     0,     0,   173,    50,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,   226,     3,     4,    91,     1,     6,     0,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,   272,     3,     4,    91,
       1,     6,     0,     7,     8,     9,     0,    92,     0,   158,
     159,   160,   161,   173,     2,     0,   383,     0,     0,     0,
       0,     0,     3,     4,    91,     0,     6,     0,     7,     8,
       9,    26,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,    43,     0,    26,    92,     0,     0,
      48,    49,     0,     0,     0,    50,     0,     0,     0,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,    43,
       0,    26,     0,     0,     0,    48,    49,     0,     0,     0,
      50,     0,     0,     0,    33,    34,    35,    36,    37,    38,
      39,  -114,     1,     0,    43,  -114,     0,     0,     0,     0,
      48,    49,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     0,     6,     0,
       7,     8,     9,     0,     0,     0,  -114,     0,     0,  -114,
    -114,  -114,     0,  -114,     0,     0,  -112,     1,     0,     0,
    -112,     0,  -114,     0,     0,  -114,     0,     0,     0,     0,
    -114,     0,  -114,     0,  -114,     0,     0,     0,  -114,     3,
       4,     0,     0,     6,  -114,     7,     8,     9,     0,     0,
       0,  -112,     0,     0,  -112,  -112,  -112,     0,  -112,     0,
       0,     0,     0,     0,     0,     0,     0,  -112,     0,     0,
    -112,     0,     0,     0,     0,  -112,     0,  -112,     0,  -112,
       0,     0,     0,  -112,     0,     0,  -114,     0,     0,  -112,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,     0,     0,     0,     0,   156,     0,     0,     0,
       0,   157,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,     0,     0,     0,     0,   193,     0,
       0,  -112,     0,   157,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,     0,     0,     0,     0,     0,   158,   159,   160,   161,
     157,     0,     0,     0,   162,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   158,   159,
     160,   161,     0,     0,     0,     0,   194,   157,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     158,   159,   160,   161,     0,     0,     0,   361,     0,   157,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   158,   159,   160,   161,     0,     0,   210,     0,
       0,   157,   172,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   158,   159,   160,   161,     0,
       0,   324,     0,     0,   157,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   157,     0,   353,     0,
     145,   146,   147,   148,   149,   150,     0,     0,   153,     0,
       0,   155,     0,     0,   158,   159,   160,   161,     0,     0,
     375,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,   160,   161,
       0,     0,   415,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,   160,   161,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,   160,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,   160,   161
};

static const yytype_int16 yycheck[] =
{
       0,    22,     0,   253,     0,     0,    26,   174,    43,    23,
       4,    20,    12,    43,    12,    43,     4,    16,     4,    25,
     191,   192,    23,    23,    57,    35,    27,    26,    25,    50,
       4,    35,    52,    23,   117,   118,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     2,    16,   116,    23,
     329,    61,    21,    35,   122,    59,   306,    26,    36,    16,
     120,   311,   191,    41,    16,    51,    22,   196,    23,    26,
      26,    20,    27,    62,    26,    53,   355,    66,    56,   113,
     121,    63,   116,   116,   104,    67,    79,    23,    81,   109,
      25,    84,    48,    49,    50,    88,    52,   114,    91,    92,
      93,    94,   116,    44,    45,   125,   126,   127,   116,   118,
     116,   116,   113,   133,   113,   114,    38,   114,    40,   398,
     122,   115,   142,   113,   374,   116,   117,   115,   116,   115,
     114,   122,     0,   116,   118,   116,   119,    99,   417,   122,
     102,   115,   111,   112,   113,   114,   122,   167,   104,   118,
     119,   118,   121,   109,   111,   112,   113,   114,   113,    23,
     114,   116,    25,   330,   118,   186,   117,   118,   188,   125,
     126,   127,    41,    42,   174,   118,   174,   133,   174,   174,
     180,   209,   182,   116,    25,   116,   142,   116,   118,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   169,   118,   165,
      83,   167,   118,   248,   118,   171,    25,    58,   248,    25,
     248,   116,   178,   243,   119,    25,    25,   122,   116,    51,
     186,   187,   188,   117,   114,   191,   192,   193,   194,   195,
     196,   412,    85,    86,    87,   117,   117,   247,   118,   211,
      38,    39,    40,   209,    95,    96,    97,    98,    99,   100,
     101,   117,   117,   117,   284,   117,   116,   113,   119,   174,
       5,     6,   119,     8,     9,   180,    58,   182,   117,   117,
     116,    16,   117,   116,    23,   285,   117,   243,   250,   245,
     117,    26,     4,    58,    60,    77,   117,   117,   117,    42,
     300,    65,   302,   303,    42,   116,    23,   307,   308,    51,
      73,   118,    23,    95,    96,    97,    98,    99,   100,   101,
      54,   182,   116,    42,   324,   117,   324,    40,   284,    37,
     330,   366,   330,   289,   330,   330,   366,    40,   366,   301,
      42,    39,   247,   299,   242,   431,   386,   281,   166,   254,
     255,   377,   257,   258,   372,    -1,    -1,    -1,    -1,   315,
     360,   317,    -1,    -1,    -1,   386,    -1,   367,    -1,    -1,
      -1,   327,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     285,    -1,    -1,    -1,   384,    -1,   247,   349,    -1,    -1,
      -1,   353,    -1,   393,    -1,   300,   358,    -1,    -1,   399,
     356,    -1,    -1,    -1,    -1,   361,   406,   407,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   379,    -1,   419,
     420,    -1,   422,   385,   285,   330,    -1,   383,    -1,   429,
     386,    -1,    -1,   395,    -1,   397,    -1,    -1,   394,   300,
      -1,   302,   303,    -1,    -1,    -1,   307,   308,   410,   411,
      -1,   413,    -1,    -1,    -1,   360,   412,   362,    -1,    -1,
      -1,   423,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,     5,     6,     7,     8,     9,    10,   393,    -1,
      13,    14,    -1,    16,   399,    -1,    -1,    -1,    -1,   360,
      -1,   406,   407,    26,    -1,    -1,   367,    -1,    -1,    -1,
      -1,    -1,     0,     1,   419,   420,     4,   422,    -1,    -1,
      -1,    -1,    -1,   384,   429,    -1,    -1,    15,    -1,    17,
      -1,    -1,   393,    -1,    -1,    23,    24,    25,   399,    27,
      -1,    29,    30,    31,    -1,   406,   407,    35,    -1,    -1,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,   419,   420,
      -1,   422,    -1,    51,    -1,    -1,    54,    -1,   429,    -1,
      58,    59,    -1,    61,    -1,    63,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    82,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    95,    96,    97,
      98,    99,   100,   101,     0,     1,    26,   105,     4,    -1,
      -1,    -1,    -1,   111,   112,   113,    -1,   115,   116,    15,
     118,    -1,    -1,   121,    -1,    -1,    -1,    23,    24,    25,
      -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    15,    61,    -1,    63,    -1,    -1,
      -1,    67,    23,    24,    25,    -1,    27,    73,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,   118,    95,
      96,    97,    98,    99,   100,   101,    -1,    58,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,   115,
     116,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,     1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    15,    95,    96,    97,    98,    99,   100,
     101,    23,    24,    25,   105,    27,    -1,    29,    30,    31,
     111,   112,   113,    -1,    -1,   116,   117,   118,    -1,    -1,
     121,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      58,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,    -1,     1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    95,    96,    97,
      98,    99,   100,   101,    23,    24,    25,   105,    27,    -1,
      29,    30,    31,   111,   112,   113,    -1,    -1,   116,   117,
     118,    -1,    -1,   121,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,    58,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,     0,     1,    -1,
     105,     4,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,   116,    15,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    -1,    58,    59,    -1,    61,    -1,
      63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      -1,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
       0,     1,   115,   116,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    -1,    63,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    82,    -1,    84,    -1,    -1,    -1,    88,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,     0,     1,   115,   116,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
       5,     6,     7,     8,     9,    10,    23,    24,    25,    -1,
      27,    16,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    26,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    60,    -1,    62,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    82,    -1,    84,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,     0,     1,   115,   116,
       4,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    82,    -1,
      84,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,    -1,   117,    -1,   119,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,     1,    -1,
      -1,     4,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,   111,   112,   113,   114,    -1,
      23,    24,    25,    -1,    27,   121,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    -1,    58,    59,    -1,    61,    -1,
      63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    82,
      -1,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,     1,   115,   116,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    -1,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    82,    -1,    84,    -1,    -1,    -1,    88,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,    -1,     1,   115,   116,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    82,    -1,    84,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,     1,   115,   116,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    82,    -1,
      84,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
       1,   115,   116,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,     1,   115,   116,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,    -1,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    82,    -1,    84,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,     1,   115,   116,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,   111,   112,    -1,     1,
     115,   116,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      82,    -1,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,     1,   115,   116,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      -1,    40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    56,    -1,    58,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    72,    16,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    82,    26,    84,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       1,   110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,     1,    27,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
       1,    27,    -1,    29,    30,    31,    -1,    58,    -1,   111,
     112,   113,   114,   115,    15,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,    30,
      31,    82,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,   105,    -1,    82,    58,    -1,    -1,
     111,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,   105,
      -1,    82,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,     0,     1,    -1,   105,     4,    -1,    -1,    -1,    -1,
     111,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      29,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    -1,    42,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    51,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    -1,    61,    -1,    63,    -1,    -1,    -1,    67,    23,
      24,    -1,    -1,    27,    73,    29,    30,    31,    -1,    -1,
      -1,    35,    -1,    -1,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    63,
      -1,    -1,    -1,    67,    -1,    -1,   115,    -1,    -1,    73,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,
      -1,   115,    -1,    26,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      26,    -1,    -1,    -1,   119,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,    26,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
     111,   112,   113,   114,    -1,    -1,    -1,   118,    -1,    26,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,   111,   112,   113,   114,    -1,    -1,   117,    -1,
      -1,    26,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,   111,   112,   113,   114,    -1,
      -1,   117,    -1,    -1,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    26,    -1,   117,    -1,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      -1,    16,    -1,    -1,   111,   112,   113,   114,    -1,    -1,
     117,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    23,    24,    25,    27,    29,    30,    31,
      32,    33,    34,    35,    43,    45,    46,    55,    58,    60,
      64,    74,    75,    76,    79,    81,    82,    84,    88,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   110,   111,   112,
     116,   128,   129,   132,   133,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     157,   158,   159,   160,   161,   163,   164,   166,   169,   170,
     171,   172,   173,   176,   177,   183,   186,   187,   188,   190,
     120,    25,    58,   140,   160,    20,   121,   142,    23,    25,
     116,    25,   184,   114,   162,   136,   140,    77,   160,   116,
     113,   121,   134,   135,   136,   137,   140,   167,   168,   116,
      23,    27,   113,   116,   155,   156,   156,   156,   133,   138,
     141,   132,   132,   116,   140,   140,   136,   140,    62,    66,
     181,   168,   116,   122,   122,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    16,    21,    26,   111,   112,
     113,   114,   119,   122,   113,   116,   118,   130,    36,    41,
      53,    56,     4,   115,   125,   126,   127,     0,   116,    23,
     125,    25,   125,    25,   114,   168,   114,   118,   116,   140,
     168,   118,   118,    21,   119,   121,   118,    83,    85,    86,
      87,    23,   113,   154,   118,   168,   168,   168,   168,   118,
     117,    25,   168,    25,    25,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,    22,   140,   140,   140,
     140,   140,   140,   140,    25,    23,   116,    89,    90,   131,
     140,   168,   129,    17,   168,   116,    23,   125,   175,    51,
     140,   127,   188,    72,   142,   151,   153,   166,   189,   117,
     153,   114,   136,   140,   168,   117,   117,   134,   135,   140,
     134,   140,    22,   140,   140,   140,   135,   140,   117,   117,
     117,   118,   117,   133,   116,   125,   117,   116,   113,   119,
     119,   117,   117,   130,   168,   140,   153,   133,   138,   116,
     125,   184,   127,   127,    35,    59,   165,   127,   127,    35,
      61,   185,   114,   117,   116,   121,   155,   119,   168,   153,
     117,   117,   140,    23,   117,     4,   124,   119,   140,   153,
     125,   153,   153,    58,   184,   153,   153,    60,   184,   117,
     140,   117,   140,   117,    35,    63,    67,   182,    23,    37,
     142,    42,   140,   117,   124,   188,   118,    65,   180,   118,
     125,   118,   125,    42,   124,   140,   116,   125,    23,   153,
     140,    51,   178,   179,    73,   117,   133,   153,   118,    38,
      39,    40,   174,   118,   125,    57,   116,   179,    54,   184,
     117,   182,    23,   125,   116,    38,    40,   140,   153,   125,
      57,   136,   137,   140,   153,   140,   125,   125,   124,   153,
     117,   117,   118,   117,    40,   117,   153,   153,    42,   125,
     125,   140,   125,    37,    40,   124,   153,   153,   153,   125,
      42,   153,   174
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 149 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)]))); 
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 3:
#line 155 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Nop, "" }));
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 4:
#line 161 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 5:
#line 167 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 6:
#line 174 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Semicolon, ";" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 7:
#line 181 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 8:
#line 186 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 9:
#line 192 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 10:
#line 197 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 11:
#line 203 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 12:
#line 211 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 13:
#line 220 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 14:
#line 228 "src/grammar/for90.y"
    {
				// if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' 
				// if is array reduce immediately and goto `var_def` 
				// do not parse array slices here because this is difficult 
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 15:
#line 240 "src/grammar/for90.y"
    {
				// define array like a(1)
				ARG_OUT exp_to = YY2ARG((yyvsp[(3) - (4)]));

				ParseNode slice = promote_exp_to_slice(exp_to);
				ParseNode dimen_slice = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 16:
#line 254 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 17:
#line 263 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 18:
#line 271 "src/grammar/for90.y"
    {
				// const value
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 19:
#line 280 "src/grammar/for90.y"
    {
				// static value 
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // static
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 20:
#line 289 "src/grammar/for90.y"
    {
				/* allocatable value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // allocatable
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 21:
#line 298 "src/grammar/for90.y"
    {
				// target value
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // target
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 22:
#line 307 "src/grammar/for90.y"
    {
				// target value
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // pointer
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 23:
#line 317 "src/grammar/for90.y"
    {
				ParseNode variable_elem = YY2ARG((yyvsp[(2) - (3)]));
				ParseNode variable_desc = YY2ARG((yyvsp[(3) - (3)]));
				// target code of slice depend on context
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				// merge attrs 
				newnode.setattr(variable_elem.attr->clone());
				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 24:
#line 331 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				newnode.setattr(new VariableDescAttr());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 25:
#line 345 "src/grammar/for90.y"
    {
				int kind;
				ARG_OUT integer = YY2ARG((yyvsp[(3) - (3)]));
				sscanf(integer.get_what().c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 26:
#line 359 "src/grammar/for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				ARG_OUT integer = YY2ARG((yyvsp[(3) - (3)]));
				sscanf(integer.get_what().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 27:
#line 374 "src/grammar/for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				sscanf(integer.get_what().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 28:
#line 389 "src/grammar/for90.y"
    {
				// all arguments under `literal` rule is directly from tokenizer
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 29:
#line 397 "src/grammar/for90.y"
    {
				ARG_OUT base = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT expo = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float,  base.get_what() + "e" + expo.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 30:
#line 406 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.get_what() })); // int number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 31:
#line 413 "src/grammar/for90.y"
    {
				// replace `'` with `"`
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				std::string s = lit.get_what().substr(1, lit.get_what().size() - 2);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 32:
#line 422 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 33:
#line 428 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 34:
#line 434 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				string strcplx = lit.get_what();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 35:
#line 444 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				print_error("exp parse error");
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 36:
#line 452 "src/grammar/for90.y"
    {
                ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
                ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.get_what() });
                (yyval) = RETURN_NT(newnode);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
                CLEAN_DELETE((yyvsp[(1) - (1)]));
            ;}
    break;

  case 37:
#line 460 "src/grammar/for90.y"
    {
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 38:
#line 474 "src/grammar/for90.y"
    {
				// arr[from : to]
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 39:
#line 484 "src/grammar/for90.y"
    {
				// arr[from : to : step]
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (5)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (5)]));
				ARG_OUT exp3 = YY2ARG((yyvsp[(5) - (5)]));
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2, exp3));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			;}
    break;

  case 40:
#line 495 "src/grammar/for90.y"
    {
				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.get_what() }, from);
				ParseNode ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.get_what() }, to);
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 41:
#line 506 "src/grammar/for90.y"
    {
				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.get_what() }, from);
				ParseNode ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.get_what() }, to);
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 42:
#line 519 "src/grammar/for90.y"
    {
				// initial value is required in parse tree because it can be an non-terminal `exp` 
				// non-array initial values 
				// array_builder is exp 
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_keyvalue_from_exp(YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 43:
#line 531 "src/grammar/for90.y"
    {
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (5)]));
				(yyval) = RETURN_NT(gen_keyvalue_from_exp(YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]));
			;}
    break;

  case 44:
#line 539 "src/grammar/for90.y"
    {
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				std:string str = exp2.get_what();
				exp2.get_what()=std::string("&")+std::string("(")+exp2.get_what()+std::string(")");
				(yyval) = RETURN_NT(gen_keyvalue_from_exp( YY2ARG((yyvsp[(1) - (3)])),exp2));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 45:
#line 549 "src/grammar/for90.y"
    {
				// argtable is used in function call 
				ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 46:
#line 558 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(1) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 47:
#line 576 "src/grammar/for90.y"
    {
				/******************
				* 1d array
				* arr[from : to]
				* target code of slice depend on context
				******************/ 
				ARG_OUT slice = YY2ARG((yyvsp[(1) - (1)]));
				// only 1 slice
				(yyval) = RETURN_NT(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 48:
#line 589 "src/grammar/for90.y"
    {
				/******************
				* multi dimension array
				* arr[from:to, from:to, ...]
				* target code of slice depend on context
				******************/
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT slice = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 49:
#line 611 "src/grammar/for90.y"
    {
				/******************
				* multi dimension array
				* arr[from:to, index, ...]
				* target code of slice depend on context
				******************/
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 50:
#line 633 "src/grammar/for90.y"
    {
				ARG_OUT argtable = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT slice = YY2ARG((yyvsp[(3) - (3)]));
				if (!argtable.token_equals(TokenMeta::NT_ARGTABLE_PURE))
				{
					print_error("Illegal dimen_slice", argtable);
				}
				// IMPORTANT: can't promote here, or `s(i, 1:j)` cause error, ref `regen_slice`
				//newnode = gen_flatten(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 51:
#line 657 "src/grammar/for90.y"
    {
				// function call OR array index 
				// NOTE that array index can be A(1:2, 3:4)
				ARG_OUT callable_head = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 52:
#line 668 "src/grammar/for90.y"
    {
				// function call OR array index 
				// NOTE that array index can be A(1:2, 3:4) 
				ARG_OUT callable_head = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 53:
#line 680 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 54:
#line 685 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]));
			;}
    break;

  case 55:
#line 691 "src/grammar/for90.y"
    {
				/******************
				* call-stmt
				* function call can omit trailing `()` if there's no arguments
				* e.g.
				*	```
				*	call func
				*	```
				* `func` is not a variable, but a function
				* SHOULDN"T GENERATE VARDEF FOR `func`
				*******************/
				ARG_OUT callable_head = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }
					, callable_head, gen_token(Term{TokenMeta::NT_ARGTABLE_PURE, ""}) );
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 56:
#line 711 "src/grammar/for90.y"
    {
				/******************
				* this is sth callable, maybe array section(NT_DIMENSLICE) or function
				******************/
				ARG_OUT function_array = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 57:
#line 720 "src/grammar/for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 58:
#line 727 "src/grammar/for90.y"
    {
				// `function_array` rule MUST have priority over this rule 
				ARG_OUT exp = YY2ARG((yyvsp[(2) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LB, "( %s )" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 59:
#line 736 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Add, "%s + %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 60:
#line 746 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Minus, "%s - %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 61:
#line 756 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Multiply, "%s * %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 62:
#line 766 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Divide, "%s / %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 63:
#line 776 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Power, "power(%s, %s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 64:
#line 786 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Neg, "(-%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 65:
#line 795 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Pos, "%s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 66:
#line 804 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::NEQ, "%s != %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 67:
#line 814 "src/grammar/for90.y"
    {
				// xor
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::NEQV, "%s ^ %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 68:
#line 825 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::EQ, "%s == %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 69:
#line 835 "src/grammar/for90.y"
    {
				// nor
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::EQV, "!(%s ^ %s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 70:
#line 846 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::AndAnd, "%s && %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 71:
#line 856 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "%s || %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 72:
#line 866 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "!(%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 73:
#line 875 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::GT, "%s > %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 74:
#line 885 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::GE, "%s >= %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 75:
#line 895 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LE, "%s <= %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
			;}
    break;

  case 76:
#line 904 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LT, "%s < %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 77:
#line 914 "src/grammar/for90.y"
    {
				// TODO may have error priority 
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				const string & op_name = op.get_what();
				auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == op_name; });
				if (keyword_iter != keywords.end())
				{
					// this is a keyword
				}
				else {
					fatal_error("self-defined operator is not supported", op);
				}
				ParseNode opnew = gen_token(Term{ keyword_iter->token, "%s " + op_name + " %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 78:
#line 934 "src/grammar/for90.y"
    {
				ARG_OUT hidden_do = YY2ARG((yyvsp[(1) - (1)]));
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, hidden_do.get_what() }, hidden_do));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 79:
#line 941 "src/grammar/for90.y"
    {
				/******************
				* shouldn't promote literals to NT_EXPRESSION, 
				*	because it can bring trouble to hardcoded dealt values
				* e.g.
				* when generating NT_SLICE, we can set a default lower bound UBOUND_DELTA_STR = `1`, 
				*	and we hard code the UBOUND_DELTA_STR
				*	if we promote  literals to NT_EXPRESSION, we should write
				*	`gen_token(Term{TokenMeta::NT_EXPRESSION, UBOUND_DELTA_STR}, gen_token(Term{TokenMeta::Int, UBOUND_DELTA_STR}))`
				*	it's not elegant
				******************/
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 80:
#line 961 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 81:
#line 966 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 82:
#line 972 "src/grammar/for90.y"
    {
            
                ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
                ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
                ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                (yyval) = RETURN_NT(newnode);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
                CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
            ;}
    break;

  case 83:
#line 982 "src/grammar/for90.y"
    {
                ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
                ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
                ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                (yyval) = RETURN_NT(newnode);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
                CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
            ;}
    break;

  case 84:
#line 991 "src/grammar/for90.y"
    {
                ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
                ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
                ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
                (yyval) = RETURN_NT(newnode);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
                CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
            ;}
    break;

  case 85:
#line 1002 "src/grammar/for90.y"
    {
				/******************
				* formerly, considering `stmt` are completed by `\n` or certain mark like `end do(enddo)`
				* so `stmt` is used to have a list of children
				* however, now,
				******************/
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 86:
#line 1014 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 87:
#line 1020 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 88:
#line 1026 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 89:
#line 1032 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 90:
#line 1037 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 91:
#line 1044 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 92:
#line 1050 "src/grammar/for90.y"
    {
				ARG_OUT format = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.to_string() + "\"" }, format);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 93:
#line 1058 "src/grammar/for90.y"
    { 
				ARG_OUT comment = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_comment(comment.get_what()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 94:
#line 1065 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 95:
#line 1071 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 96:
#line 1077 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 97:
#line 1083 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 98:
#line 1089 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 99:
#line 1095 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 100:
#line 1101 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 101:
#line 1107 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 102:
#line 1114 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 103:
#line 1119 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 104:
#line 1124 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 105:
#line 1130 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 106:
#line 1135 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 107:
#line 1140 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 108:
#line 1146 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Continue, "continue;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 109:
#line 1152 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 110:
#line 1158 "src/grammar/for90.y"
    {
				ARG_OUT line = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Goto, line.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 111:
#line 1166 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.get_what() + ");stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 112:
#line 1173 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 113:
#line 1180 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop(" + lit.get_what() + ");" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 114:
#line 1187 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop();" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 115:
#line 1194 "src/grammar/for90.y"
    {
			    //printf("in rule =>");
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (5)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (5)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (5)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			;}
    break;

  case 116:
#line 1206 "src/grammar/for90.y"
    {
			    //printf("in rule =>");
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s =&(%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 117:
#line 1218 "src/grammar/for90.y"
    {
			    //printf("in rule =");
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 118:
#line 1229 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (5)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(4) - (5)]));
				bool initialized = false;
				ParseNode newGroup;
				for(int i = 0; i < exp2.length(); i++)
				{
				    ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
				    ParseNode lelem;
				    if(exp1.length() == exp2.length())
				    {
				        lelem = exp1.get(i);
				    }
				    else
				    {
				        lelem = exp1;
				        lelem.get_what().append("[").append(std::to_string(i)).append("]");
				    }

				    ParseNode newToken = gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, lelem, exp2.get(i), opnew);
				    if(initialized)
				    {
				        ParseNode link = gen_token(Term{ TokenMeta::Let, "%s;%s" });
				        newGroup = gen_promote(link.get_what(), TokenMeta::NT_EXPRESSION, newGroup, newToken, link);
				    }else
				    {
				        newGroup = newToken;
				        initialized = true;
				    }
				}
				(yyval) = RETURN_NT(newGroup);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
		    ;}
    break;

  case 119:
#line 1267 "src/grammar/for90.y"
    {
				// dummy stmt
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 120:
#line 1274 "src/grammar/for90.y"
    {
				// dummy stmt
				ParseNode & type_name = YY2ARG((yyvsp[(2) - (5)]));
				ParseNode & paramtable = YY2ARG((yyvsp[(4) - (5)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::ConfigImplicit, "" }, type_name, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			;}
    break;

  case 121:
#line 1285 "src/grammar/for90.y"
    {
				ARG_OUT label = YY2ARG((yyvsp[(1) - (2)])); // TokenMeta::Label
				ARG_OUT stmt = YY2ARG((yyvsp[(2) - (2)]));
				if (stmt.token_equals(TokenMeta::NT_FORMAT))
				{
					//log_format_index(label.get_what(), stmt.get(0)); 
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL FORMAT GENERATED IN REGEN_SUITE") }, label, stmt);
					// do not generate target code of format stmt
					(yyval) = RETURN_NT(newnode);
				}
				else {
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL GENERATED IN REGEN_SUITE") }, label, stmt);
					(yyval) = RETURN_NT(newnode);
				}
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 122:
#line 1304 "src/grammar/for90.y"
    {
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ALLOCATE_STMT, "" }, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 123:
#line 1313 "src/grammar/for90.y"
    {
				// NT_FORMAT or other stmt node
				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 124:
#line 1321 "src/grammar/for90.y"
    {

				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 125:
#line 1335 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 126:
#line 1342 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(stmt, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 127:
#line 1355 "src/grammar/for90.y"
    {
				// NT_INTERFACE
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(interf, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 128:
#line 1363 "src/grammar/for90.y"
    {
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(interf, suite));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 129:
#line 1375 "src/grammar/for90.y"
    {
				// NT_DERIVED_TYPE
				ARG_OUT type_decl = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(type_decl, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 130:
#line 1383 "src/grammar/for90.y"
    {
				ARG_OUT type_decl = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(type_decl, suite));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 131:
#line 1395 "src/grammar/for90.y"
    {	/******************
				* An asterisk identifies particular processor-dependent external units that are preconnected for formatted sequential access (9.4.4.2).
				*==================
				* -1 stands for stdin/stdout, depending it's in whether a read or a write stmt, ref gen_io.cpp
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, "-1" })); // 
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 132:
#line 1405 "src/grammar/for90.y"
    {
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, integer.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 133:
#line 1412 "src/grammar/for90.y"
    {
				/******************
				* an asterisk (*) which indicates list-directed formatting (10.8).
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 134:
#line 1421 "src/grammar/for90.y"
    {
				// use format stmt at line YY2ARG($1) to format
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				std::string location_label = integer.get_what();
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 135:
#line 1430 "src/grammar/for90.y"
    {
				/******************
				* C++ only allows strings wrapped by `"`,
				*	replace `'` string with `"`
				******************/
				ARG_OUT s = YY2ARG((yyvsp[(1) - (1)]));
				string modified = "\"" + s.get_what().substr(1, s.get_what().size() - 2) + "\"";
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER, modified }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 136:
#line 1464 "src/grammar/for90.y"
    {
				/******************
				* target code of io_info depend on context
				*	can be either iostream/cstdio
				******************/
				ARG_OUT _optional_device = YY2ARG((yyvsp[(2) - (5)]));
				ARG_OUT _optional_formatter = YY2ARG((yyvsp[(4) - (5)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			;}
    break;

  case 137:
#line 1477 "src/grammar/for90.y"
    {				
				/******************
				* target code of io_info depend on context
				*	can be either iostream/cstdio
				******************/
				ParseNode _optional_device = gen_token(Term{TokenMeta::META_INTEGER, "-1"});
				ARG_OUT _optional_formatter = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 138:
#line 1492 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, WHEN_DEBUG_OR_EMPTY("WRITE GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 139:
#line 1502 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, WHEN_DEBUG_OR_EMPTY("PRINT GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 140:
#line 1513 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, WHEN_DEBUG_OR_EMPTY("READ GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 141:
#line 1523 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 142:
#line 1529 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 143:
#line 1535 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 144:
#line 1541 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 145:
#line 1547 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 146:
#line 1553 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 147:
#line 1559 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 148:
#line 1565 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 149:
#line 1584 "src/grammar/for90.y"
    {
				// now translated in pre_map
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 150:
#line 1591 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 151:
#line 1597 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (5)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)])));
				CLEAN_DELETE((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]));
			;}
    break;

  case 152:
#line 1603 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 153:
#line 1609 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 154:
#line 1615 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 155:
#line 1622 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 156:
#line 1629 "src/grammar/for90.y"
    {
				ARG_OUT blockname = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_common(blockname, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 157:
#line 1638 "src/grammar/for90.y"
    {
				// TODO: Here may be a shift-reduce confliction, because `variable_desc` can be empty,
				// when confronting ',', both reducing to variable_desc or shifting may make sense.
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (4)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(4) - (4)]));
				// get_variabledesc_attr(const_cast<ParseNode &>(variable_desc)).slice.value()
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 158:
#line 1650 "src/grammar/for90.y"
    {
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));

				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 159:
#line 1670 "src/grammar/for90.y"
    {
				ARG_OUT variable_desc_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc_elem, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 160:
#line 1720 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 161:
#line 1725 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 162:
#line 1730 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 163:
#line 1736 "src/grammar/for90.y"
    {
				ARG_OUT variable_type = YY2ARG((yyvsp[(2) - (6)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				//$$ = RETURN_NT(gen_suite(suite, gen_dummy()));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_DERIVED_TYPE, "" }, variable_type, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 164:
#line 1746 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 165:
#line 1754 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 166:
#line 1762 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 167:
#line 1771 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 168:
#line 1780 "src/grammar/for90.y"
    {
				// empty list
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 169:
#line 1788 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 170:
#line 1793 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 171:
#line 1798 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 172:
#line 1804 "src/grammar/for90.y"
    {
				/******************
				* implied do is something like `(abs(i), i=1,4)`
				*==================
				* Standard
					R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
					R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
					■ scalar - int - expr[, scalar - int - expr]
				******************/
				ARG_OUT argtable = YY2ARG((yyvsp[(2) - (9)]));
				ARG_OUT index = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT from = YY2ARG((yyvsp[(6) - (9)]));
				ARG_OUT to = YY2ARG((yyvsp[(8) - (9)]));
				(yyval) = RETURN_NT(gen_hiddendo(argtable, index, from, to));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
			;}
    break;

  case 173:
#line 1822 "src/grammar/for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = RETURN_NT(gen_arraybuilder_from_paramtable(YY2ARG((yyvsp[(2) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 174:
#line 1832 "src/grammar/for90.y"
    {
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 175:
#line 1840 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 176:
#line 1846 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 177:
#line 1855 "src/grammar/for90.y"
    {
				// one line if
				// `IF (e) st` where
				// st can be any executable statement, except a DO block, IF, ELSE IF, ELSE, END IF, END, or another logical IF statement.
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (6)]));
				ARG_OUT stmt_true = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "" }, exp, stmt_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 178:
#line 1867 "src/grammar/for90.y"
    {
				// Arithmetic if
				// `IF (e) s1, s2, s3`, where
				// s1, s2, s3 are labels
			;}
    break;

  case 179:
#line 1873 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			;}
    break;

  case 180:
#line 1882 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (12)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (12)]));
				ARG_OUT suite_else = YY2ARG((yyvsp[(11) - (12)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), suite_else);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (12)])), YY2ARG((yyvsp[(12) - (12)])));
				CLEAN_DELETE((yyvsp[(1) - (12)]), (yyvsp[(2) - (12)]), (yyvsp[(3) - (12)]), (yyvsp[(4) - (12)]), (yyvsp[(5) - (12)]), (yyvsp[(6) - (12)]), (yyvsp[(7) - (12)]), (yyvsp[(8) - (12)]), (yyvsp[(9) - (12)]), (yyvsp[(10) - (12)]), (yyvsp[(11) - (12)]), (yyvsp[(12) - (12)]));
			;}
    break;

  case 181:
#line 1892 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (10)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (10)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(9) - (10)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (10)])), YY2ARG((yyvsp[(10) - (10)])));
				CLEAN_DELETE((yyvsp[(1) - (10)]), (yyvsp[(2) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(9) - (10)]), (yyvsp[(10) - (10)]));
			;}
    break;

  case 182:
#line 1902 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (13)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (13)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(9) - (13)]));
				ARG_OUT suite_else = YY2ARG((yyvsp[(12) - (13)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, suite_else);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (13)])), YY2ARG((yyvsp[(13) - (13)])));
				CLEAN_DELETE((yyvsp[(1) - (13)]), (yyvsp[(2) - (13)]), (yyvsp[(3) - (13)]), (yyvsp[(4) - (13)]), (yyvsp[(5) - (13)]), (yyvsp[(6) - (13)]), (yyvsp[(7) - (13)]), (yyvsp[(8) - (13)]), (yyvsp[(9) - (13)]), (yyvsp[(10) - (13)]), (yyvsp[(11) - (13)]), (yyvsp[(12) - (13)]), (yyvsp[(13) - (13)]));
			;}
    break;

  case 183:
#line 1914 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 184:
#line 1924 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (8)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (8)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(8) - (8)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (8)])), YY2ARG((yyvsp[(8) - (8)])));
				CLEAN_DELETE((yyvsp[(1) - (8)]), (yyvsp[(2) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]), (yyvsp[(8) - (8)]));
			;}
    break;

  case 185:
#line 1935 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 186:
#line 1940 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 187:
#line 1946 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, WHEN_DEBUG_OR_EMPTY("DO-BARE GENERATED IN REGEN_SUITE") }, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(5) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
			;}
    break;

  case 188:
#line 1954 "src/grammar/for90.y"
    {
				YYSTYPE X1 = (yyvsp[(1) - (12)]);
				YYSTYPE X2 = (yyvsp[(2) - (12)]);
				YYSTYPE X3 = (yyvsp[(3) - (12)]);
				YYSTYPE X4 = (yyvsp[(4) - (12)]);
				YYSTYPE X5 = (yyvsp[(5) - (12)]);
				YYSTYPE X6 = (yyvsp[(6) - (12)]);
				YYSTYPE X7 = (yyvsp[(7) - (12)]);
				YYSTYPE X8 = (yyvsp[(8) - (12)]);
				YYSTYPE X9 = (yyvsp[(9) - (12)]);
				YYSTYPE X10 = (yyvsp[(10) - (12)]);
				YYSTYPE X11 = (yyvsp[(11) - (12)]);
				YYSTYPE X12 = (yyvsp[(12) - (12)]);
				ARG_OUT loop_variable = YY2ARG((yyvsp[(4) - (12)]));
				ARG_OUT exp_from = YY2ARG((yyvsp[(6) - (12)]));
				ARG_OUT exp_to = YY2ARG((yyvsp[(8) - (12)]));
				ParseNode step = gen_token(Term{ TokenMeta::META_INTEGER , UBOUND_DELTA_STR });
				ARG_OUT suite = YY2ARG((yyvsp[(10) - (12)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (12)])), YY2ARG((yyvsp[(12) - (12)])));
				CLEAN_DELETE((yyvsp[(1) - (12)]), (yyvsp[(2) - (12)]), (yyvsp[(3) - (12)]), (yyvsp[(4) - (12)]), (yyvsp[(5) - (12)]), (yyvsp[(6) - (12)]), (yyvsp[(7) - (12)]), (yyvsp[(8) - (12)]), (yyvsp[(9) - (12)]), (yyvsp[(10) - (12)]), (yyvsp[(11) - (12)]), (yyvsp[(12) - (12)]));
			;}
    break;

  case 189:
#line 1978 "src/grammar/for90.y"
    {
				ARG_OUT loop_variable = YY2ARG((yyvsp[(4) - (14)]));
				ARG_OUT exp_from = YY2ARG((yyvsp[(6) - (14)]));
				ARG_OUT exp_to = YY2ARG((yyvsp[(8) - (14)]));
				ARG_OUT step = YY2ARG((yyvsp[(10) - (14)]));
				ARG_OUT suite = YY2ARG((yyvsp[(12) - (14)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE-STEP GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (14)])), YY2ARG((yyvsp[(14) - (14)])));
				CLEAN_DELETE((yyvsp[(1) - (14)]), (yyvsp[(2) - (14)]), (yyvsp[(3) - (14)]), (yyvsp[(4) - (14)]), (yyvsp[(5) - (14)]), (yyvsp[(6) - (14)]), (yyvsp[(7) - (14)]), (yyvsp[(8) - (14)]), (yyvsp[(9) - (14)]), (yyvsp[(10) - (14)]), (yyvsp[(11) - (14)]), (yyvsp[(12) - (14)]), (yyvsp[(13) - (14)]), (yyvsp[(14) - (14)]));
			;}
    break;

  case 190:
#line 1990 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, WHEN_DEBUG_OR_EMPTY("DO-WHILE GENERATED IN REGEN_SUITE") }, exp, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(6) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]));
			;}
    break;

  case 191:
#line 2000 "src/grammar/for90.y"
    {
				ARG_OUT select = YY2ARG((yyvsp[(2) - (9)]));
				ARG_OUT exp = YY2ARG((yyvsp[(5) - (9)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_SELECT, WHEN_DEBUG_OR_EMPTY("SELECT GENERATED IN REGEN_SUITE") }, exp, case_stmt);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			;}
    break;

  case 192:
#line 2011 "src/grammar/for90.y"
    {
				// one case
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (6)]));
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)])); 

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 193:
#line 2022 "src/grammar/for90.y"
    {
				// one case
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (6)]));
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 194:
#line 2033 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 195:
#line 2041 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 196:
#line 2051 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, case_stmt_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 197:
#line 2059 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_flatten(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 198:
#line 2069 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 199:
#line 2075 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 200:
#line 2082 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 201:
#line 2087 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 202:
#line 2093 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 203:
#line 2098 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 204:
#line 2103 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 205:
#line 2109 "src/grammar/for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (10)])); // function name
				// enumerate parameter list 
				ARG_OUT paramtable = YY2ARG((yyvsp[(5) - (10)]));
				ARG_OUT variable_result = YY2ARG((yyvsp[(7) - (10)])); // result variable
				ARG_OUT suite = YY2ARG((yyvsp[(9) - (10)]));

				ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flattened parameter list with all keyvalue elements
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (10)])), YY2ARG((yyvsp[(10) - (10)])));
				CLEAN_DELETE((yyvsp[(1) - (10)]), (yyvsp[(2) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(9) - (10)]), (yyvsp[(10) - (10)]));
			;}
    break;

  case 206:
#line 2124 "src/grammar/for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (6)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (6)]));

				ParseNode kvparamtable = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				ParseNode void_return = gen_token(Term{ TokenMeta::UnknownVariant, "" });
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(1) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 207:
#line 2137 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 208:
#line 2142 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 209:
#line 2148 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 210:
#line 2153 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 211:
#line 2158 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 212:
#line 2164 "src/grammar/for90.y"
    {
				ParseNode & suite = YY2ARG((yyvsp[(4) - (6)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.get_what() }, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 213:
#line 2172 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 214:
#line 2177 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 215:
#line 2182 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 216:
#line 2192 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 217:
#line 2199 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 218:
#line 2204 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 219:
#line 2212 "src/grammar/for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_promote("%s", TokenMeta::NT_WRAPPERS, wrapper);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 220:
#line 2220 "src/grammar/for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT wrappers = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 221:
#line 2238 "src/grammar/for90.y"
    {
				ARG_OUT wrappers = YY2ARG((yyvsp[(4) - (7)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 222:
#line 2246 "src/grammar/for90.y"
    {
				gen_fortran_program(YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 5164 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2251 "src/grammar/for90.y"

void update_yylval(Term & current_term) {
	get_tokenizer_state().CurrentTerm = current_term;
	ParseNode newnode{ TokenizerState(get_tokenizer_state()) , nullptr, nullptr };
	yylval = RETURN_NT(newnode);
}
void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), YY2ARG(yylval));
}
int parse(std::string code) {
#ifdef USE_YACC
#ifdef USE_LEX
	get_tokenizer_context().load_code = set_buff;
	get_tokenizer_context().unload_code = release_buff;
#else
	get_tokenizer_context().load_code = [&](const std::string & _code) {
		get_simpler_context().reset();
		get_simpler_context().code = _code;
		get_tokenizer_state().parse_line = 1;
	};
	get_tokenizer_context().unload_code = []() {
	
	};
#endif
	get_tokenizer_context().load_code(code);
	yyparse();
	get_tokenizer_context().unload_code();
#endif
	return 0;
}

