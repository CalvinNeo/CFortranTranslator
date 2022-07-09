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
#line 403 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"

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
#define YYFINAL  173
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNRULES -- Number of states.  */
#define YYNSTATES  415

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     119,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   121,     2,     2,
     115,   116,   112,   110,   117,   111,     2,   113,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   114,
       2,   118,     2,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    20,    25,    30,    35,    40,    45,    47,    49,    51,
      53,    55,    57,    59,    63,    64,    68,    72,    74,    78,
      80,    82,    84,    86,    88,    91,    93,    95,    99,   105,
     107,   109,   113,   117,   119,   123,   125,   129,   133,   137,
     142,   147,   149,   152,   155,   157,   159,   163,   167,   171,
     175,   179,   183,   186,   189,   193,   197,   201,   205,   209,
     213,   216,   220,   224,   228,   232,   236,   238,   240,   242,
     246,   250,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   272,   274,   276,   277,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   306,   309,
     311,   314,   316,   320,   324,   327,   333,   336,   341,   343,
     347,   349,   353,   355,   359,   361,   365,   367,   369,   371,
     373,   375,   381,   384,   388,   392,   396,   398,   400,   402,
     404,   406,   408,   410,   415,   420,   424,   426,   430,   433,
     434,   438,   443,   447,   450,   452,   454,   457,   464,   466,
     470,   474,   478,   479,   481,   483,   485,   495,   499,   501,
     504,   505,   512,   523,   533,   546,   557,   571,   579,   588,
     590,   591,   598,   611,   626,   634,   644,   651,   658,   663,
     670,   672,   675,   680,   681,   683,   685,   687,   689,   691,
     702,   709,   711,   712,   714,   716,   719,   726,   728,   730,
     732,   734,   736,   738,   740,   744,   752
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     189,     0,    -1,     4,    -1,    -1,   126,    -1,   124,   126,
      -1,   114,    -1,     4,    -1,   125,    -1,    63,    -1,    -1,
      83,   115,    84,   116,    -1,    83,   115,    85,   116,    -1,
      83,   115,    86,   116,    -1,    80,   115,   167,   116,    -1,
      80,   115,   139,   116,    -1,    80,    -1,    87,    -1,    78,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,   117,
     128,   129,    -1,    -1,    89,   118,    22,    -1,    88,   118,
     139,    -1,    23,    -1,    22,    20,    22,    -1,    22,    -1,
      26,    -1,    29,    -1,    30,    -1,    28,    -1,     1,   119,
      -1,    24,    -1,   140,    -1,   139,   120,   139,    -1,   139,
     120,   139,   120,   139,    -1,   120,    -1,   112,    -1,   139,
     118,   139,    -1,   139,    21,   139,    -1,   139,    -1,   135,
     117,   139,    -1,   133,    -1,   136,   117,   133,    -1,   136,
     117,   139,    -1,   135,   117,   133,    -1,   132,   115,   167,
     116,    -1,   159,   115,   167,   116,    -1,   137,    -1,   104,
     137,    -1,   104,   132,    -1,   138,    -1,   170,    -1,   115,
     139,   116,    -1,   139,   110,   139,    -1,   139,   111,   139,
      -1,   139,   112,   139,    -1,   139,   113,   139,    -1,   139,
      16,   139,    -1,   111,   139,    -1,   110,   139,    -1,   139,
      10,   139,    -1,   139,    11,   139,    -1,   139,     7,   139,
      -1,   139,    12,   139,    -1,   139,    13,   139,    -1,   139,
      14,   139,    -1,    15,   139,    -1,   139,     5,   139,    -1,
     139,     6,   139,    -1,   139,     8,   139,    -1,   139,     9,
     139,    -1,   139,    25,   139,    -1,   168,    -1,   131,    -1,
     132,    -1,   132,   121,    24,    -1,   137,   121,    24,    -1,
     140,   121,    24,    -1,   139,    -1,   163,    -1,   144,    -1,
     143,    -1,   149,    -1,   148,    -1,   162,    -1,    31,    -1,
      32,    -1,   142,    -1,   151,    -1,    -1,   146,    -1,   147,
      -1,    42,    -1,   107,    -1,   145,    -1,   156,    -1,   157,
      -1,   158,    -1,   172,    -1,   175,    -1,   176,    -1,    45,
      -1,    44,    -1,    54,    22,    -1,   106,   131,    -1,   106,
      -1,   105,   131,    -1,   105,    -1,   139,    21,   139,    -1,
     139,   118,   139,    -1,    75,    76,    -1,    75,   159,   115,
     167,   116,    -1,    33,   141,    -1,   109,   115,   167,   116,
      -1,   150,    -1,   150,   126,   152,    -1,   141,    -1,   141,
     126,   152,    -1,   188,    -1,   188,   126,   152,    -1,   165,
      -1,   165,   126,   152,    -1,   112,    -1,    22,    -1,   112,
      -1,    22,    -1,    26,    -1,   115,   153,   117,   154,   116,
      -1,   154,   117,    -1,   101,   155,   167,    -1,   103,   155,
     167,    -1,   102,   155,   167,    -1,    94,    -1,    95,    -1,
     100,    -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,
      57,   115,    24,   116,    -1,   159,   115,   130,   116,    -1,
     159,   112,    22,    -1,   159,    -1,   113,    24,   113,    -1,
     113,   113,    -1,    -1,    73,   161,   167,    -1,   160,   129,
      17,   167,    -1,   160,   129,   167,    -1,   128,   167,    -1,
      58,    -1,    34,    -1,    34,    57,    -1,    57,    24,   124,
     152,   164,   183,    -1,   134,    -1,   166,   117,   134,    -1,
     166,   117,   139,    -1,   135,   117,   134,    -1,    -1,   166,
      -1,   135,    -1,   136,    -1,   115,   135,   117,   132,   118,
     139,   117,   139,   116,    -1,    81,   167,    82,    -1,   169,
      -1,    24,   120,    -1,    -1,   171,    35,   115,   139,   116,
     141,    -1,   171,    35,   115,   139,   116,    22,   117,    22,
     117,    22,    -1,   171,    35,   115,   139,   116,    36,   124,
     152,    39,    -1,   171,    35,   115,   139,   116,    36,   124,
     152,    37,   124,   152,    39,    -1,   171,    35,   115,   139,
     116,    36,   124,   152,   173,    39,    -1,   171,    35,   115,
     139,   116,    36,   124,   152,   173,    37,   124,   152,    39,
      -1,    38,   115,   139,   116,    36,   124,   152,    -1,    38,
     115,   139,   116,    36,   124,   152,   173,    -1,    22,    -1,
      -1,   171,    40,   124,   152,   123,    41,    -1,   171,    40,
     174,   132,   118,   139,   117,   139,   124,   152,   123,    41,
      -1,   171,    40,   174,   132,   118,   139,   117,   139,   117,
     139,   124,   152,   123,    41,    -1,   171,    55,   139,   124,
     152,   123,    41,    -1,   171,    52,    50,   115,   139,   116,
     124,   178,    53,    -1,    50,   115,   136,   116,   124,   152,
      -1,    50,   115,   135,   116,   124,   152,    -1,    50,    56,
     124,   152,    -1,    50,   115,    56,   116,   124,   152,    -1,
     177,    -1,   177,   178,    -1,    64,   115,   132,   116,    -1,
      -1,    61,    -1,    65,    -1,    62,    -1,    66,    -1,    34,
      -1,   127,   180,    24,   115,   167,   116,   179,   124,   152,
     181,    -1,   127,   180,    24,   124,   152,   181,    -1,    24,
      -1,    -1,    60,    -1,    34,    -1,    34,    59,    -1,    59,
     183,   124,   152,   184,   183,    -1,   185,    -1,   182,    -1,
     165,    -1,   141,    -1,   150,    -1,    34,    -1,   186,    -1,
     186,   124,   187,    -1,    71,   183,   124,   187,   123,    72,
     183,    -1,   187,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   155,   160,   166,   173,   180,   185,   191,
     197,   202,   210,   219,   227,   239,   253,   262,   270,   279,
     288,   297,   306,   316,   331,   344,   357,   373,   381,   390,
     397,   406,   412,   418,   428,   436,   444,   457,   467,   478,
     489,   502,   512,   538,   547,   565,   578,   600,   622,   646,
     657,   669,   674,   680,   700,   709,   716,   725,   735,   745,
     755,   765,   775,   784,   793,   803,   814,   824,   835,   845,
     855,   864,   874,   884,   893,   903,   923,   930,   950,   957,
     967,   976,   986,   998,  1004,  1010,  1016,  1021,  1028,  1034,
    1042,  1049,  1055,  1062,  1067,  1073,  1079,  1085,  1091,  1098,
    1103,  1108,  1114,  1119,  1124,  1130,  1136,  1142,  1150,  1157,
    1164,  1171,  1178,  1190,  1202,  1209,  1220,  1239,  1248,  1256,
    1270,  1277,  1290,  1298,  1310,  1318,  1330,  1340,  1347,  1356,
    1365,  1399,  1412,  1427,  1437,  1448,  1458,  1464,  1470,  1476,
    1482,  1488,  1494,  1500,  1519,  1526,  1532,  1538,  1544,  1552,
    1558,  1567,  1579,  1599,  1649,  1654,  1659,  1665,  1675,  1683,
    1691,  1700,  1710,  1717,  1722,  1727,  1733,  1751,  1761,  1769,
    1776,  1784,  1796,  1802,  1811,  1821,  1831,  1843,  1853,  1864,
    1870,  1875,  1883,  1907,  1919,  1929,  1940,  1951,  1962,  1970,
    1980,  1988,  1998,  2005,  2011,  2016,  2022,  2027,  2032,  2038,
    2053,  2066,  2072,  2077,  2082,  2087,  2093,  2101,  2106,  2111,
    2121,  2128,  2133,  2141,  2149,  2167,  2175
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
  "YY_POS", "YY_EXPONENT", "YY_PLET", "YY_INTEGER", "YY_FLOAT", "YY_WORD",
  "YY_OPERATOR", "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX", "YY_TRUE",
  "YY_FALSE", "YY_FORMAT_STMT", "YY_COMMENT", "YY_LABEL", "YY_END",
  "YY_IF", "YY_THEN", "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO",
  "YY_ENDDO", "YY_CONTINUE", "YY_BREAK", "YY_EXIT", "YY_CYCLE", "YY_WHILE",
  "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE",
  "YY_SELECT", "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT",
  "YY_TYPE", "YY_ENDTYPE", "YY_PROGRAM", "YY_ENDPROGRAM", "YY_FUNCTION",
  "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT", "YY_SUBROUTINE",
  "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE", "YY_BLOCK",
  "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE", "YY_COMMON", "YY_DATA",
  "YY_IMPLICIT", "YY_NONE", "YY_USE", "YY_PARAMETER", "YY_ENTRY",
  "YY_DIMENSION", "YY_ARRAYBUILDER_START", "YY_ARRAYBUILDER_END",
  "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN",
  "YY_KIND", "YY_SAVE", "YY_ALLOCATABLE", "YY_TARGET", "YY_POINTER",
  "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "YY_DOUBLE_T", "YY_WRITE", "YY_READ", "YY_PRINT",
  "YY_CALL", "YY_STOP", "YY_PAUSE", "YY_RETURN", "YY_CONFIG_IMPLICIT",
  "YY_ALLOCATE", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','",
  "'='", "'\\n'", "':'", "'%'", "$accept", "crlf_or_not",
  "at_least_one_end_line", "semicolon", "end_of_stmt",
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
      43,    45,    42,    47,    59,    40,    41,    44,    61,    10,
      58,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   122,   123,   123,   124,   124,   125,   126,   126,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   136,   136,   137,
     137,   138,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   140,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   142,   142,   142,   143,
     143,   143,   144,   144,   144,   145,   145,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   151,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   154,   154,
     154,   155,   155,   156,   157,   158,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   160,   161,   161,   161,
     162,   163,   163,   163,   164,   164,   164,   165,   166,   166,
     166,   166,   166,   167,   167,   167,   168,   169,   170,   171,
     171,   172,   172,   172,   172,   172,   172,   173,   173,   174,
     174,   175,   175,   175,   175,   176,   177,   177,   177,   177,
     178,   178,   179,   179,   180,   180,   181,   181,   181,   182,
     182,   183,   183,   184,   184,   184,   185,   186,   186,   186,
     186,   186,   186,   187,   187,   188,   189
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       0,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     5,     1,
       1,     3,     3,     1,     3,     1,     3,     3,     3,     4,
       4,     1,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     1,     3,     3,     2,     5,     2,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     5,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     1,     3,     2,     0,
       3,     4,     3,     2,     1,     1,     2,     6,     1,     3,
       3,     3,     0,     1,     1,     1,     9,     3,     1,     2,
       0,     6,    10,     9,    12,    10,    13,     7,     8,     1,
       0,     6,    12,    14,     7,     9,     6,     6,     4,     6,
       1,     2,     4,     0,     1,     1,     1,     1,     1,    10,
       6,     1,     0,     1,     1,     2,     6,     1,     1,     1,
       1,     1,     1,     1,     3,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    29,    27,    35,    30,    33,    31,    32,
      89,    90,     0,   212,    96,   106,   105,     0,     0,   202,
       9,   149,     0,    18,    16,     0,     0,    17,    19,    20,
      21,    22,   136,   137,   139,   140,   141,   142,   138,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,    77,    78,    51,    54,    82,    36,   210,    91,
      85,    84,    98,    94,    95,    87,    86,   211,    92,    99,
     100,   101,   146,    24,    88,    83,   209,    76,   168,    55,
       0,   102,   103,   104,   208,   207,   213,   216,     0,    34,
      35,     0,    70,     0,     0,   169,   116,   107,     0,     0,
     201,     0,     0,     0,   114,     0,     0,    40,    39,    45,
     158,   164,   165,    43,   163,     0,     0,   129,   130,   128,
       0,     0,     0,     0,     0,    53,    52,   110,   108,     0,
      63,    62,     0,    43,   194,   195,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,     0,     0,     7,     6,
       0,     8,     4,     1,     0,    28,     0,     0,     0,     0,
     148,   150,     0,    43,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,   127,   126,     0,   132,   133,
     135,   134,     0,     0,    56,     0,     0,    79,    80,    71,
      72,    66,    73,    74,    64,    65,    67,    68,    69,    61,
     112,    75,    57,    58,    59,    60,   113,    81,   145,     0,
       0,     0,     0,    24,     0,   152,     0,   179,     0,     0,
       0,     0,     5,   214,   202,   120,   118,     0,   124,   122,
     143,     0,   147,     0,    15,    14,    48,   161,    44,    46,
      47,    42,    41,    37,   159,   160,    11,    12,    13,     0,
     117,    78,    44,     0,     0,    49,     0,     0,   144,    50,
      23,   151,     0,     3,     0,     0,     0,     0,     0,     0,
       0,   155,   154,   202,     0,     0,   204,   203,   202,   115,
       0,     0,     0,     0,     0,    26,    25,     0,     2,     0,
       0,     0,     3,     0,   121,   119,   156,   157,   125,   123,
     205,   206,    38,   131,     0,   193,   198,   196,   197,   200,
      29,     0,   171,   181,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   202,   166,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,   191,
     185,   215,   192,   199,   172,     0,     0,     0,   175,     0,
       3,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,   188,     0,     0,     0,     0,   174,     0,     0,     3,
     182,     0,     0,    44,     0,     0,   176,     0,   189,   187,
     186,     0,   183,   177,   178
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   309,   170,   171,   172,    50,    51,   163,   231,    52,
      53,   109,   110,   111,   112,    54,    55,    56,    57,   245,
      59,    60,    61,    62,    63,    64,    65,    66,   246,    68,
     247,   197,   121,   122,    69,    70,    71,    93,    73,   103,
      74,    75,   293,   248,   114,   232,    77,    78,    79,    80,
      81,   364,   239,    82,    83,   354,   355,   340,   136,   329,
      84,   101,   298,    85,    86,    87,   249,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -234
static const yytype_int16 yypact[] =
{
    1272,   -92,  2521,    41,  -234,   -87,  -234,  -234,  -234,  -234,
    -234,  -234,  1048,  -234,  -234,  -234,  -234,    68,    -9,    39,
    -234,    -8,   471,  -234,    -7,   685,     3,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,    57,
      57,    57,   350,  2531,  2600,  -234,    37,  2521,  2521,  2521,
      24,   623,  -234,   -90,    60,  -234,  2690,    62,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,   -37,    12,  -234,  -234,  -234,  -234,  -234,  -234,
     122,  -234,  -234,  -234,  -234,  -234,    14,  -234,   158,  -234,
    -234,    91,   662,   106,   142,  -234,  -234,  -234,    14,   198,
    -234,    14,     4,   623,  -234,   108,   729,  -234,  -234,  -234,
    -234,   107,   110,  1383,   111,   143,    58,  -234,  -234,  -234,
     -18,   118,   623,   623,   623,   -90,    60,  -234,  -234,   729,
     188,   188,   123,  2753,  -234,  -234,   215,  -234,   729,   217,
     218,  2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,
    2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,   220,
     224,    15,   419,   522,   133,    10,   200,  2521,  -234,  -234,
    1160,  -234,  -234,  -234,   729,  -234,  1966,   136,  2078,   146,
    -234,  -234,   729,    43,   147,   835,   835,  2521,  2521,  2521,
    2521,  -234,   149,   151,   153,  -234,  -234,   154,  -234,  -234,
    -234,  -234,   156,  2521,  -234,     6,   159,  -234,  -234,   188,
     188,   347,   188,   188,   347,   248,   248,   662,   480,    51,
    1454,  1454,   124,   124,    51,    51,  1454,  -234,  -234,   152,
     163,   160,   161,    12,   623,  -234,  2521,  -234,  2302,   350,
     167,  2895,  -234,  -234,    39,    14,    14,     8,    14,    14,
    -234,    13,  -234,   168,  -234,  -234,  -234,  -234,  1383,  -234,
    1404,  1454,  1454,  1425,  -234,  2711,  -234,  -234,  -234,    36,
    -234,   -95,  1454,   729,  1742,  -234,  2521,   261,  -234,  -234,
    -234,  -234,  2782,   281,   -44,    60,  2521,  2302,    14,  1518,
    1518,   229,  -234,    39,  1518,  1518,   232,  -234,    39,  -234,
    2521,   172,  2521,   176,   183,  1454,  -234,   936,  -234,   252,
    2521,  2825,   281,  1630,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  1454,  -234,  1475,   233,  -234,  -234,  -234,  -234,
      16,    14,  -234,  -234,  2732,    14,   255,   281,  2521,   187,
      14,   282,  1854,  2521,    20,  -234,   231,  2846,   350,  1742,
     189,   171,  2669,   -35,   259,   258,    39,  -234,   -81,   183,
     283,    14,   197,  -234,    49,  2521,  2302,    14,   791,  -234,
    -234,  -234,  -234,  -234,  -234,  2414,  2521,    14,  -234,  2895,
     281,  2190,   199,    21,    29,  1404,   277,  2871,  2414,  2302,
     278,  -234,    14,    14,   835,    14,  -234,   288,   290,   281,
    -234,  2190,  2190,  1404,  2190,    14,  -234,   286,  -234,  -234,
    -234,  1854,  -234,   293,  -234
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -215,    38,  -234,    90,  -234,   170,   100,  -234,    55,
     -23,  -179,  -103,   -47,   -34,   -25,  -234,    44,  -234,     1,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,     5,  -234,
     132,  -234,    71,   179,  -234,  -234,  -234,     0,  -234,  -234,
    -234,  -234,  -234,     9,  -234,   -22,  -234,  -234,  -234,  -234,
    -234,   -76,  -234,  -234,  -234,  -234,   -13,  -234,  -234,   -16,
    -234,  -233,  -234,  -234,  -234,  -162,  -234,  -234
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -171
static const yytype_int16 yytable[] =
{
      72,    58,   132,   115,   195,    67,   256,   259,   243,    76,
     168,   288,    72,    96,   168,    98,     1,   126,   168,   125,
     138,   367,   105,   302,   168,   138,   139,    89,   179,   137,
       2,   139,   237,    95,   138,   372,    94,     3,     4,    90,
     139,     6,   291,     7,     8,     9,    92,   296,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   117,   151,
     317,    94,   118,   100,   187,   321,   292,   151,   153,   113,
     353,   138,    91,   297,   310,   160,   153,   139,   161,   117,
     368,   181,   257,   118,   184,   134,   377,   264,   378,   135,
      97,   130,   131,   133,   196,   113,    25,   336,   127,   128,
     199,   200,   201,   229,   230,   102,    99,   202,   106,    32,
      33,    34,    35,    36,    37,    38,   206,   180,   116,    42,
     169,   273,   346,   371,   169,    47,    48,   107,   169,   162,
      49,  -162,  -162,   341,   169,   108,   176,   393,   394,   178,
     151,   235,   192,   193,   194,   395,   186,   113,   119,   153,
     183,   337,   129,   154,   155,   156,   157,   164,   173,   254,
     253,   188,   165,   189,   175,   390,   113,   113,   113,   119,
      72,    58,   120,   113,   166,    67,    72,   167,    72,    76,
     271,   140,   113,   159,   407,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   238,   151,   113,    99,   113,   361,   362,
     363,   241,   281,   153,   285,   256,   284,   326,   113,   123,
     124,   174,   177,   182,   185,   191,   113,   186,   190,   258,
     260,   261,   262,   263,   265,   198,   156,   157,    72,   205,
     203,   207,   208,   274,   227,   327,   228,   272,   236,   328,
     240,   303,   250,   141,   142,   143,   144,   145,   146,   252,
     242,   149,   150,   255,   151,   266,   242,   267,   242,   268,
     276,   269,   270,   153,    72,   275,   278,   279,   113,   287,
     282,   277,   286,   306,   299,   308,   316,    72,   323,    72,
      72,   320,   325,   333,    72,    72,   345,   339,   154,   155,
     156,   157,   348,   356,   350,   374,   360,    72,   332,   353,
     251,   370,   376,    72,    58,   392,   396,   113,    67,   400,
     305,   383,    76,   285,   405,   358,   313,   412,   242,   406,
     311,   362,   233,   280,   384,   289,   290,   414,   294,   295,
     301,   369,    72,   373,   322,     0,   324,     0,     0,    72,
       0,     0,   141,   142,   334,   144,   145,     0,   154,   155,
     156,   157,     0,   151,   242,     0,    72,     0,     0,   342,
     283,     0,   153,   344,    90,    72,     0,   242,   349,     0,
       0,    72,   347,     0,     0,     0,     0,   352,    72,    72,
     366,     0,     0,     0,     0,     0,     0,     0,     0,   375,
       0,    72,    72,   242,    72,   381,   304,    91,     0,   379,
       0,    72,   385,     0,     0,   388,     0,   389,     0,   312,
     387,   314,   315,     0,     0,     0,   318,   319,     0,     0,
     401,   402,   242,   404,   242,     0,     0,     0,   403,   242,
       0,     0,     0,   411,    32,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,   242,   154,   155,   156,
     157,     0,     0,     0,     0,   242,     0,     0,     0,     0,
       0,   242,     0,     0,   351,     0,     0,     0,   242,   242,
       0,   359,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   242,   242,   149,   242,     0,   151,    23,   380,    24,
       0,   242,    26,     0,     0,   153,    27,   386,     0,    28,
      29,    30,    31,   391,     0,     0,     0,     0,     0,     0,
     398,   399,  -162,     1,     0,     0,  -162,     0,    91,     0,
       0,     0,     0,   408,   409,     0,   410,     2,     0,   234,
       0,     0,     0,   413,     3,     4,    90,   104,     6,     0,
       7,     8,     9,     0,     0,     0,  -162,     0,     0,  -162,
    -162,  -162,     0,  -162,     0,    32,    33,    34,    35,    36,
      37,    38,  -162,     0,     0,  -162,     0,     0,     0,    91,
    -162,     0,  -162,     0,  -162,     0,     0,     0,  -162,     0,
     154,   155,   156,   157,  -162,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,    35,
      36,    37,    38,  -162,     1,     0,    42,  -162,     0,     0,
       0,     0,    47,    48,   107,     0,  -162,    49,     2,  -162,
       0,     0,   108,     0,     0,     3,     4,    90,     0,     6,
       0,     7,     8,     9,     0,     0,     0,  -162,     0,     0,
    -162,  -162,  -162,     0,  -162,     0,     0,   141,   142,   143,
     144,   145,   146,  -162,     0,     0,  -162,     0,   151,     0,
      91,  -162,     0,  -162,     0,  -162,     1,   153,     0,  -162,
       0,     0,     0,     0,     0,  -162,     0,     0,     0,     0,
       2,     0,     0,     0,    25,     0,     0,     3,     4,    90,
       0,     6,     0,     7,     8,     9,     0,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,    42,     0,     0,
       1,     0,     0,    47,    48,   107,     0,  -162,    49,     0,
    -162,     0,    91,   108,     2,     0,     0,     0,     0,     0,
       0,     3,     4,    90,     0,     6,     0,     7,     8,     9,
       0,     0,     0,     0,     0,     0,    25,  -162,     0,     0,
       0,     0,   154,   155,   156,   157,     0,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    91,     0,     0,    42,
       0,     0,     1,     0,     0,    47,    48,   107,     0,     0,
      49,     0,  -162,     0,     0,   108,     2,     0,     0,     0,
      25,     0,     0,     3,     4,    90,     0,     6,     0,     7,
       8,     9,     0,    32,    33,    34,    35,    36,    37,    38,
       0,     0,     0,    42,     0,     0,     1,     0,     0,    47,
      48,   107,     0,     0,    49,  -162,  -162,   382,    91,   108,
       2,     0,     0,     0,     0,     0,     0,     3,     4,    90,
       0,     6,     0,     7,     8,     9,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    91,     0,     0,    42,     0,     0,     0,     0,
       0,    47,    48,   107,     0,     0,    49,     0,     0,     0,
       0,   108,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    34,    35,    36,    37,    38,   -93,     1,     0,    42,
     -93,     0,     0,     0,     0,    47,    48,   107,     0,     0,
      49,     2,     0,     0,     0,   108,     0,     0,   330,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
     -93,  -170,   331,   -93,   -93,   -93,  -170,   -93,    14,     0,
      15,    16,     0,     0,     0,     0,   -93,     0,  -170,   -93,
      17,  -170,     0,    91,   -93,     0,   -93,     0,   -93,     0,
       0,     0,   -93,     0,     0,     0,     0,     0,   -93,    21,
       0,    22,     0,     0,    23,     0,    24,    25,     0,    26,
       0,     0,     0,    27,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,   -93,     1,
     -93,    49,   -93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,     0,   -93,  -170,     0,   -93,   -93,   -93,  -170,   -93,
      14,     0,    15,    16,     0,     0,     0,     0,   -93,     0,
    -170,   -93,    17,  -170,     0,    91,   -93,     0,   -93,     0,
     -93,     0,     0,     0,   -93,     0,     0,     0,     0,     0,
     -93,    21,     0,    22,     0,     0,    23,     0,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
     -93,     1,   -93,    49,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,  -170,     0,     0,     0,     0,
    -170,     0,    14,     0,    15,    16,     0,     0,     0,     0,
       0,     0,  -170,     0,    17,  -170,     0,    18,     0,    19,
       0,   -10,     0,    20,     0,   -10,     0,     0,     0,     0,
       0,     0,   -93,    21,     0,    22,     0,     0,    23,     0,
      24,    25,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,   -93,     1,   169,    49,   -93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,    12,    13,  -170,     0,     0,
       0,     0,  -170,     0,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,  -170,     0,    17,  -170,     0,    18,
       0,    19,     0,   -10,     0,    20,     0,   -10,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    22,     0,     0,
      23,     0,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,     0,     0,   -93,    49,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
       0,     0,     0,     0,   187,     0,     0,     0,   153,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,   151,     0,   154,   155,   156,   157,     0,     0,     0,
     153,   188,     0,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,     0,     1,
       0,     0,   -93,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,   154,   155,   156,   157,     0,
       3,     4,     5,     0,     6,   300,     7,     8,     9,    10,
      11,    12,   -93,  -170,     0,   -93,   -93,   -93,  -170,   -93,
      14,     0,    15,    16,   154,   155,   156,   157,   -93,     0,
    -170,   -93,    17,  -170,     0,    18,   -93,     0,   -93,     0,
     -93,     0,     0,     0,   -93,   154,   155,   156,   157,   244,
       0,    21,   338,    22,     0,     0,    23,     0,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
       0,     1,   -93,    49,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,  -170,     0,     0,     0,     0,
    -170,     0,    14,     0,    15,    16,     0,     0,     0,     0,
       0,     0,  -170,     0,    17,  -170,     0,    18,     0,    19,
       0,   -10,     0,    20,     0,   -10,     0,     0,     0,     0,
       0,     0,   -93,    21,     0,    22,     0,     0,    23,     0,
      24,    25,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,     0,     1,   169,    49,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,    12,   -93,  -170,     0,     0,
       0,     0,  -170,     0,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,  -170,     0,    17,  -170,     0,    18,
       0,     0,     0,     0,   -93,     0,     0,     0,   -93,     0,
       0,     0,     0,   244,     0,    21,     0,    22,     0,     0,
      23,     0,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,     0,     1,   169,    49,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -170,
       0,   -93,   -93,   -93,  -170,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -170,     0,    17,  -170,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,    21,     0,    22,
       0,     0,    23,     0,    24,    25,     0,    26,     0,     0,
       0,    27,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,     0,     1,   169,    49,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
     -93,  -170,     0,     0,     0,     0,  -170,     0,    14,     0,
      15,    16,     0,     0,     0,     0,     0,     0,  -170,     0,
      17,  -170,     0,    18,   -93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,    21,
       0,    22,     0,     0,    23,     0,    24,    25,     0,    26,
       0,     0,     0,    27,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,     0,     1,
     169,    49,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,   -93,  -170,     0,     0,     0,     0,  -170,     0,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
    -170,     0,    17,  -170,     0,    18,     0,     0,   -93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,    21,     0,    22,     0,     0,    23,     0,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
       0,     1,   169,    49,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,     0,  -170,     0,     0,     0,     0,
    -170,     0,    14,     0,    15,    16,     0,     0,     0,     0,
     -93,     0,  -170,   -93,    17,  -170,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,     0,    21,     0,    22,     0,     0,    23,     0,
      24,    25,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,     0,     1,   169,    49,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,    12,     0,  -170,     0,     0,
       0,     0,  -170,   -93,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,  -170,     0,    17,  -170,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,    21,     0,    22,     0,     0,
      23,     0,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,     0,     1,   169,    49,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -170,
       0,     0,     0,   -93,  -170,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -170,     0,    17,  -170,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,    21,     0,    22,
       0,     0,    23,     0,    24,    25,     0,    26,     0,     0,
       0,    27,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     1,    46,    47,    48,     0,     0,   169,    49,
       0,  -111,     1,     0,     0,  -111,     2,     0,     0,     0,
       0,     0,     0,     3,     4,    90,     0,     6,     0,     7,
       8,     9,     0,     3,     4,     0,     0,     6,     0,     7,
       8,     9,     0,     0,     0,  -111,     0,     0,  -111,  -111,
    -111,     0,  -111,     0,     0,     0,     0,     0,    91,     0,
       0,  -111,     0,     0,  -111,     0,     0,     0,     0,  -111,
       0,  -111,     0,  -111,     0,     0,     0,  -111,     0,     0,
    -109,     1,    25,  -111,  -109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
      37,    38,     3,     4,     0,    42,     6,     0,     7,     8,
       9,    47,    48,     0,  -109,     0,    49,  -109,  -109,  -109,
       0,  -109,     0,     0,     0,  -111,     0,     0,     0,     0,
    -109,     0,     0,  -109,     0,     0,     0,     0,  -109,     0,
    -109,     0,  -109,     0,     0,     0,  -109,     0,     0,     0,
       0,     0,  -109,   168,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,   151,     0,     0,     0,
       0,   152,     0,     0,  -109,   153,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,   151,     0,     0,
       0,     0,   187,     0,     0,     0,   153,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   169,     0,     0,   365,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,   151,     0,
     154,   155,   156,   157,     0,     0,     0,   153,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   188,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,   151,   154,   155,   156,   157,     0,     0,     0,   343,
     153,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,   151,   154,   155,   156,   157,     0,     0,   204,
       0,   153,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,   151,     0,     0,
       0,     0,   154,   155,   156,   157,   153,     0,   307,   168,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,     0,
       0,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,   157,     0,     0,   397,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,   169
};

static const yytype_int16 yycheck[] =
{
       0,     0,    49,    25,    22,     0,   185,   186,   170,     0,
       4,   244,    12,    12,     4,    24,     1,    42,     4,    42,
     115,    56,    22,   118,     4,   115,   121,   119,    24,    51,
      15,   121,    22,   120,   115,   116,    20,    22,    23,    24,
     121,    26,    34,    28,    29,    30,     2,    34,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    22,    16,
     293,    20,    26,    24,    21,   298,    58,    16,    25,    25,
      50,   115,    57,    60,   118,   112,    25,   121,   115,    22,
     115,   103,   185,    26,   106,    61,    37,   190,    39,    65,
      22,    47,    48,    49,   112,    51,    81,   312,    43,    44,
     122,   123,   124,    88,    89,   113,   115,   129,   115,    94,
      95,    96,    97,    98,    99,   100,   138,   113,   115,   104,
     114,   115,   337,   356,   114,   110,   111,   112,   114,   117,
     115,   116,   117,   117,   114,   120,    98,   116,   117,   101,
      16,   163,    84,    85,    86,   116,   117,   103,   112,    25,
     106,   313,   115,   110,   111,   112,   113,    35,     0,   116,
     182,   118,    40,   120,    22,   380,   122,   123,   124,   112,
     170,   170,   115,   129,    52,   170,   176,    55,   178,   170,
     203,   121,   138,   121,   399,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   165,    16,   161,   115,   163,    37,    38,
      39,   167,   234,    25,   239,   394,   239,    34,   174,    40,
      41,   115,    24,   115,   117,    82,   182,   117,   117,   185,
     186,   187,   188,   189,   190,   117,   112,   113,   238,    24,
     117,    24,    24,   205,    24,    62,    22,   203,   115,    66,
      50,   273,   116,     5,     6,     7,     8,     9,    10,   113,
     170,    13,    14,   116,    16,   116,   176,   116,   178,   116,
     118,   117,   116,    25,   274,   116,   116,   116,   234,   241,
     236,   118,   115,    22,   116,     4,    57,   287,   116,   289,
     290,    59,   116,    41,   294,   295,    41,    64,   110,   111,
     112,   113,   115,    72,    22,    22,   117,   307,   307,    50,
     178,    53,   115,   313,   313,   116,    39,   273,   313,    41,
     276,   368,   313,   348,    36,   348,   288,    41,   238,    39,
     286,    38,   162,   233,   368,   245,   246,   413,   248,   249,
     269,   354,   342,   359,   300,    -1,   302,    -1,    -1,   349,
      -1,    -1,     5,     6,   310,     8,     9,    -1,   110,   111,
     112,   113,    -1,    16,   274,    -1,   366,    -1,    -1,   331,
     238,    -1,    25,   335,    24,   375,    -1,   287,   340,    -1,
      -1,   381,   338,    -1,    -1,    -1,    -1,   343,   388,   389,
     352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   361,
      -1,   401,   402,   313,   404,   367,   274,    57,    -1,   365,
      -1,   411,   368,    -1,    -1,   377,    -1,   379,    -1,   287,
     376,   289,   290,    -1,    -1,    -1,   294,   295,    -1,    -1,
     392,   393,   342,   395,   344,    -1,    -1,    -1,   394,   349,
      -1,    -1,    -1,   405,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,   366,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,    -1,   342,    -1,    -1,    -1,   388,   389,
      -1,   349,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,   401,   402,    13,   404,    -1,    16,    78,   366,    80,
      -1,   411,    83,    -1,    -1,    25,    87,   375,    -1,    90,
      91,    92,    93,   381,    -1,    -1,    -1,    -1,    -1,    -1,
     388,   389,     0,     1,    -1,    -1,     4,    -1,    57,    -1,
      -1,    -1,    -1,   401,   402,    -1,   404,    15,    -1,    17,
      -1,    -1,    -1,   411,    22,    23,    24,    76,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    -1,    41,    -1,    94,    95,    96,    97,    98,
      99,   100,    50,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    60,    -1,    62,    -1,    -1,    -1,    66,    -1,
     110,   111,   112,   113,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,     0,     1,    -1,   104,     4,    -1,    -1,
      -1,    -1,   110,   111,   112,    -1,   114,   115,    15,   117,
      -1,    -1,   120,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    39,    -1,    41,    -1,    -1,     5,     6,     7,
       8,     9,    10,    50,    -1,    -1,    53,    -1,    16,    -1,
      57,    58,    -1,    60,    -1,    62,     1,    25,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    81,    -1,    -1,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
       1,    -1,    -1,   110,   111,   112,    -1,   114,   115,    -1,
     117,    -1,    57,   120,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,    57,    -1,    -1,   104,
      -1,    -1,     1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,    -1,   117,    -1,    -1,   120,    15,    -1,    -1,    -1,
      81,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    30,    -1,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,   104,    -1,    -1,     1,    -1,    -1,   110,
     111,   112,    -1,    -1,   115,   116,   117,    56,    57,   120,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    57,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,    -1,    -1,   115,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,     0,     1,    -1,   104,
       4,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,    15,    -1,    -1,    -1,   120,    -1,    -1,    22,    23,
      24,    -1,    26,    -1,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    -1,    57,    58,    -1,    60,    -1,    62,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    75,    -1,    -1,    78,    -1,    80,    81,    -1,    83,
      -1,    -1,    -1,    87,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,   111,     0,     1,
     114,   115,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    -1,    28,    29,    30,    31,
      32,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    -1,    57,    58,    -1,    60,    -1,
      62,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    75,    -1,    -1,    78,    -1,    80,    81,
      -1,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,   111,
       0,     1,   114,   115,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    61,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    78,    -1,
      80,    81,    -1,    83,    -1,    -1,    -1,    87,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,   111,     0,     1,   114,   115,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    42,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,
      -1,    59,    -1,    61,    -1,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,
      78,    -1,    80,    81,    -1,    83,    -1,    -1,    -1,    87,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,   111,    -1,    -1,   114,   115,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      25,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,     1,
      -1,    -1,     4,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,   110,   111,   112,   113,    -1,
      22,    23,    24,    -1,    26,   120,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,   110,   111,   112,   113,    50,    -1,
      52,    53,    54,    55,    -1,    57,    58,    -1,    60,    -1,
      62,    -1,    -1,    -1,    66,   110,   111,   112,   113,    71,
      -1,    73,   117,    75,    -1,    -1,    78,    -1,    80,    81,
      -1,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,   111,
      -1,     1,   114,   115,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    61,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    78,    -1,
      80,    81,    -1,    83,    -1,    -1,    -1,    87,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,   111,    -1,     1,   114,   115,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    42,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    71,    -1,    73,    -1,    75,    -1,    -1,
      78,    -1,    80,    81,    -1,    83,    -1,    -1,    -1,    87,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,   111,    -1,     1,   114,   115,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,    -1,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,
      -1,    -1,    78,    -1,    80,    81,    -1,    83,    -1,    -1,
      -1,    87,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,   110,   111,    -1,     1,   114,   115,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    -1,    42,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,
      -1,    75,    -1,    -1,    78,    -1,    80,    81,    -1,    83,
      -1,    -1,    -1,    87,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,   111,    -1,     1,
     114,   115,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    -1,    78,    -1,    80,    81,
      -1,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,   111,
      -1,     1,   114,   115,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    73,    -1,    75,    -1,    -1,    78,    -1,
      80,    81,    -1,    83,    -1,    -1,    -1,    87,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,   111,    -1,     1,   114,   115,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    73,    -1,    75,    -1,    -1,
      78,    -1,    80,    81,    -1,    83,    -1,    -1,    -1,    87,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,   111,    -1,     1,   114,   115,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    39,    40,    -1,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,
      -1,    -1,    78,    -1,    80,    81,    -1,    83,    -1,    -1,
      -1,    87,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     1,   109,   110,   111,    -1,    -1,   114,   115,
      -1,     0,     1,    -1,    -1,     4,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    30,    -1,    22,    23,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    -1,    66,    -1,    -1,
       0,     1,    81,    72,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    22,    23,    -1,   104,    26,    -1,    28,    29,
      30,   110,   111,    -1,    34,    -1,   115,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    62,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,   114,    25,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   110,
     111,   112,   113,   114,    -1,    -1,   117,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    25,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,   110,   111,   112,   113,    -1,    -1,    -1,   117,
      25,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,   110,   111,   112,   113,    -1,    -1,   116,
      -1,    25,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,    25,    -1,   116,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    22,    23,    24,    26,    28,    29,    30,
      31,    32,    33,    34,    42,    44,    45,    54,    57,    59,
      63,    73,    75,    78,    80,    81,    83,    87,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   109,   110,   111,   115,
     127,   128,   131,   132,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   156,
     157,   158,   159,   160,   162,   163,   165,   168,   169,   170,
     171,   172,   175,   176,   182,   185,   186,   187,   189,   119,
      24,    57,   139,   159,    20,   120,   141,    22,    24,   115,
      24,   183,   113,   161,    76,   159,   115,   112,   120,   133,
     134,   135,   136,   139,   166,   167,   115,    22,    26,   112,
     115,   154,   155,   155,   155,   132,   137,   131,   131,   115,
     139,   139,   135,   139,    61,    65,   180,   167,   115,   121,
     121,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    16,    21,    25,   110,   111,   112,   113,   118,   121,
     112,   115,   117,   129,    35,    40,    52,    55,     4,   114,
     124,   125,   126,     0,   115,    22,   124,    24,   124,    24,
     113,   167,   115,   139,   167,   117,   117,    21,   118,   120,
     117,    82,    84,    85,    86,    22,   112,   153,   117,   167,
     167,   167,   167,   117,   116,    24,   167,    24,    24,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,    24,    22,    88,
      89,   130,   167,   128,    17,   167,   115,    22,   124,   174,
      50,   139,   126,   187,    71,   141,   150,   152,   165,   188,
     116,   152,   113,   167,   116,   116,   133,   134,   139,   133,
     139,   139,   139,   139,   134,   139,   116,   116,   116,   117,
     116,   132,   139,   115,   124,   116,   118,   118,   116,   116,
     129,   167,   139,   152,   132,   137,   115,   124,   183,   126,
     126,    34,    58,   164,   126,   126,    34,    60,   184,   116,
     120,   154,   118,   167,   152,   139,    22,   116,     4,   123,
     118,   139,   152,   124,   152,   152,    57,   183,   152,   152,
      59,   183,   139,   116,   139,   116,    34,    62,    66,   181,
      22,    36,   141,    41,   139,   116,   123,   187,   117,    64,
     179,   117,   124,   117,   124,    41,   123,   139,   115,   124,
      22,   152,   139,    50,   177,   178,    72,   116,   132,   152,
     117,    37,    38,    39,   173,   117,   124,    56,   115,   178,
      53,   183,   116,   181,    22,   124,   115,    37,    39,   139,
     152,   124,    56,   135,   136,   139,   152,   139,   124,   124,
     123,   152,   116,   116,   117,   116,    39,   116,   152,   152,
      41,   124,   124,   139,   124,    36,    39,   123,   152,   152,
     152,   124,    41,   152,   173
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
#line 358 "src/grammar/for90.y"
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
				// all arguments under `literal` rule is directly from tokenizer
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 28:
#line 382 "src/grammar/for90.y"
    {
				ARG_OUT base = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT expo = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float,  base.get_what() + "e" + expo.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 29:
#line 391 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.get_what() })); // int number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 30:
#line 398 "src/grammar/for90.y"
    {
				// replace `'` with `"`
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				std::string s = lit.get_what().substr(1, lit.get_what().size() - 2);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 31:
#line 407 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 32:
#line 413 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 33:
#line 419 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				string strcplx = lit.get_what();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 34:
#line 429 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				print_error("exp parse error");
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 35:
#line 437 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.get_what() });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 36:
#line 445 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 37:
#line 458 "src/grammar/for90.y"
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

  case 38:
#line 468 "src/grammar/for90.y"
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

  case 39:
#line 479 "src/grammar/for90.y"
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

  case 40:
#line 490 "src/grammar/for90.y"
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
#line 503 "src/grammar/for90.y"
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

  case 42:
#line 513 "src/grammar/for90.y"
    {
				// initial value is required in parse tree because it can be an non-terminal `exp` 
				// non-array initial values 
				// array_builder is exp 
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				std:string str = exp2.get_what();
				exp2.get_what()=std::string("&")+std::string("(")+exp2.get_what()+std::string(")");
				(yyval) = RETURN_NT(gen_keyvalue_from_exp(YY2ARG((yyvsp[(1) - (3)])), exp2));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));

				// initial value is required in parse tree because it can be an non-terminal `exp` 
				// non-array initial values 
				// array_builder is exp 
				//ARG_OUT variable = YY2ARG($1);
				//ARG_OUT exp2 = YY2ARG($3);
				//std:string str = exp2.get_what();
				//exp2.get_what()=std::string("&")+std::string("(")+exp2.get_what()+std::string(")");
				//sprintf(exp2.get_what(),"%s%s%s%s","&","(",str,")");
				printf("catchya");
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_VARIABLE_ENTITY, variable.get_what() }, variable, exp2));
				//update_pos(YY2ARG($$), YY2ARG($1), YY2ARG($3));
				//CLEAN_DELETE($1, $2, $3);
			;}
    break;

  case 43:
#line 539 "src/grammar/for90.y"
    {
				// argtable is used in function call 
				ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 44:
#line 548 "src/grammar/for90.y"
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

  case 45:
#line 566 "src/grammar/for90.y"
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

  case 46:
#line 579 "src/grammar/for90.y"
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

  case 47:
#line 601 "src/grammar/for90.y"
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

  case 48:
#line 623 "src/grammar/for90.y"
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

  case 49:
#line 647 "src/grammar/for90.y"
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

  case 50:
#line 658 "src/grammar/for90.y"
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

  case 51:
#line 670 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 52:
#line 675 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]));
			;}
    break;

  case 53:
#line 681 "src/grammar/for90.y"
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

  case 54:
#line 701 "src/grammar/for90.y"
    {
				/******************
				* this is sth callable, maybe array section(NT_DIMENSLICE) or function
				******************/
				ARG_OUT function_array = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 55:
#line 710 "src/grammar/for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 56:
#line 717 "src/grammar/for90.y"
    {
				// `function_array` rule MUST have priority over this rule 
				ARG_OUT exp = YY2ARG((yyvsp[(2) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LB, "( %s )" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 57:
#line 726 "src/grammar/for90.y"
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

  case 58:
#line 736 "src/grammar/for90.y"
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

  case 59:
#line 746 "src/grammar/for90.y"
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

  case 60:
#line 756 "src/grammar/for90.y"
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

  case 61:
#line 766 "src/grammar/for90.y"
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

  case 62:
#line 776 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Neg, "(-%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 63:
#line 785 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Pos, "%s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 64:
#line 794 "src/grammar/for90.y"
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

  case 65:
#line 804 "src/grammar/for90.y"
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

  case 66:
#line 815 "src/grammar/for90.y"
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

  case 67:
#line 825 "src/grammar/for90.y"
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

  case 68:
#line 836 "src/grammar/for90.y"
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

  case 69:
#line 846 "src/grammar/for90.y"
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

  case 70:
#line 856 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "!(%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 71:
#line 865 "src/grammar/for90.y"
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

  case 72:
#line 875 "src/grammar/for90.y"
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

  case 73:
#line 885 "src/grammar/for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LE, "%s <= %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
			;}
    break;

  case 74:
#line 894 "src/grammar/for90.y"
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

  case 75:
#line 904 "src/grammar/for90.y"
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

  case 76:
#line 924 "src/grammar/for90.y"
    {
				ARG_OUT hidden_do = YY2ARG((yyvsp[(1) - (1)]));
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, hidden_do.get_what() }, hidden_do));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 77:
#line 931 "src/grammar/for90.y"
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

  case 78:
#line 951 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 79:
#line 958 "src/grammar/for90.y"
    {
			
				ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 80:
#line 968 "src/grammar/for90.y"
    {
				ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 81:
#line 977 "src/grammar/for90.y"
    {
				ARG_OUT t = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT v = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_flatten(t, v, "%s.%s", TokenMeta::NT_DERIVED_TYPE);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 82:
#line 987 "src/grammar/for90.y"
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

  case 83:
#line 999 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 84:
#line 1005 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 85:
#line 1011 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 86:
#line 1017 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 87:
#line 1022 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 88:
#line 1029 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 89:
#line 1035 "src/grammar/for90.y"
    {
				ARG_OUT format = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.to_string() + "\"" }, format);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 90:
#line 1043 "src/grammar/for90.y"
    { 
				ARG_OUT comment = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_comment(comment.get_what()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 91:
#line 1050 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 92:
#line 1056 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 93:
#line 1062 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 94:
#line 1068 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 95:
#line 1074 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 96:
#line 1080 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 97:
#line 1086 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 98:
#line 1092 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 99:
#line 1099 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 100:
#line 1104 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 101:
#line 1109 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 102:
#line 1115 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 103:
#line 1120 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 104:
#line 1125 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 105:
#line 1131 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Continue, "continue;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 106:
#line 1137 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 107:
#line 1143 "src/grammar/for90.y"
    {
				ARG_OUT line = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Goto, line.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 108:
#line 1151 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.get_what() + ");stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 109:
#line 1158 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 110:
#line 1165 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop(" + lit.get_what() + ");" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 111:
#line 1172 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop();" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 112:
#line 1179 "src/grammar/for90.y"
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

  case 113:
#line 1191 "src/grammar/for90.y"
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

  case 114:
#line 1203 "src/grammar/for90.y"
    {
				// dummy stmt
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 115:
#line 1210 "src/grammar/for90.y"
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

  case 116:
#line 1221 "src/grammar/for90.y"
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

  case 117:
#line 1240 "src/grammar/for90.y"
    {
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ALLOCATE_STMT, "" }, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 118:
#line 1249 "src/grammar/for90.y"
    {
				// NT_FORMAT or other stmt node
				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 119:
#line 1257 "src/grammar/for90.y"
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

  case 120:
#line 1271 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 121:
#line 1278 "src/grammar/for90.y"
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

  case 122:
#line 1291 "src/grammar/for90.y"
    {
				// NT_INTERFACE
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(interf, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 123:
#line 1299 "src/grammar/for90.y"
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

  case 124:
#line 1311 "src/grammar/for90.y"
    {
				// NT_DERIVED_TYPE
				ARG_OUT type_decl = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(type_decl, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 125:
#line 1319 "src/grammar/for90.y"
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

  case 126:
#line 1331 "src/grammar/for90.y"
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

  case 127:
#line 1341 "src/grammar/for90.y"
    {
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, integer.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 128:
#line 1348 "src/grammar/for90.y"
    {
				/******************
				* an asterisk (*) which indicates list-directed formatting (10.8).
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 129:
#line 1357 "src/grammar/for90.y"
    {
				// use format stmt at line YY2ARG($1) to format
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				std::string location_label = integer.get_what();
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 130:
#line 1366 "src/grammar/for90.y"
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

  case 131:
#line 1400 "src/grammar/for90.y"
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

  case 132:
#line 1413 "src/grammar/for90.y"
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

  case 133:
#line 1428 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, WHEN_DEBUG_OR_EMPTY("WRITE GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 134:
#line 1438 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, WHEN_DEBUG_OR_EMPTY("PRINT GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 135:
#line 1449 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, WHEN_DEBUG_OR_EMPTY("READ GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 136:
#line 1459 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 137:
#line 1465 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 138:
#line 1471 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 139:
#line 1477 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 140:
#line 1483 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 141:
#line 1489 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 142:
#line 1495 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 143:
#line 1501 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 144:
#line 1520 "src/grammar/for90.y"
    {
				// now translated in pre_map
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 145:
#line 1527 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 146:
#line 1533 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 147:
#line 1539 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 148:
#line 1545 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 149:
#line 1552 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 150:
#line 1559 "src/grammar/for90.y"
    {
				ARG_OUT blockname = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_common(blockname, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 151:
#line 1568 "src/grammar/for90.y"
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

  case 152:
#line 1580 "src/grammar/for90.y"
    {
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));

				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 153:
#line 1600 "src/grammar/for90.y"
    {
				ARG_OUT variable_desc_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc_elem, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 154:
#line 1650 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 155:
#line 1655 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 156:
#line 1660 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 157:
#line 1666 "src/grammar/for90.y"
    {
				ARG_OUT variable_type = YY2ARG((yyvsp[(2) - (6)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				//$$ = RETURN_NT(gen_suite(suite, gen_dummy()));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_DERIVED_TYPE, "" }, variable_type, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 158:
#line 1676 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 159:
#line 1684 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 160:
#line 1692 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 161:
#line 1701 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 162:
#line 1710 "src/grammar/for90.y"
    {
				// empty list
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 163:
#line 1718 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 164:
#line 1723 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 165:
#line 1728 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 166:
#line 1734 "src/grammar/for90.y"
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

  case 167:
#line 1752 "src/grammar/for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = RETURN_NT(gen_arraybuilder_from_paramtable(YY2ARG((yyvsp[(2) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 168:
#line 1762 "src/grammar/for90.y"
    {
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 169:
#line 1770 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 170:
#line 1776 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 171:
#line 1785 "src/grammar/for90.y"
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

  case 172:
#line 1797 "src/grammar/for90.y"
    {
				// Arithmetic if
				// `IF (e) s1, s2, s3`, where
				// s1, s2, s3 are labels
			;}
    break;

  case 173:
#line 1803 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			;}
    break;

  case 174:
#line 1812 "src/grammar/for90.y"
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

  case 175:
#line 1822 "src/grammar/for90.y"
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

  case 176:
#line 1832 "src/grammar/for90.y"
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

  case 177:
#line 1844 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 178:
#line 1854 "src/grammar/for90.y"
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

  case 179:
#line 1865 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 180:
#line 1870 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 181:
#line 1876 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, WHEN_DEBUG_OR_EMPTY("DO-BARE GENERATED IN REGEN_SUITE") }, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(5) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
			;}
    break;

  case 182:
#line 1884 "src/grammar/for90.y"
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

  case 183:
#line 1908 "src/grammar/for90.y"
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

  case 184:
#line 1920 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, WHEN_DEBUG_OR_EMPTY("DO-WHILE GENERATED IN REGEN_SUITE") }, exp, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(6) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]));
			;}
    break;

  case 185:
#line 1930 "src/grammar/for90.y"
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

  case 186:
#line 1941 "src/grammar/for90.y"
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

  case 187:
#line 1952 "src/grammar/for90.y"
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

  case 188:
#line 1963 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 189:
#line 1971 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 190:
#line 1981 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, case_stmt_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 191:
#line 1989 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_flatten(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 192:
#line 1999 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 193:
#line 2005 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 194:
#line 2012 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 195:
#line 2017 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 196:
#line 2023 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 197:
#line 2028 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 198:
#line 2033 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 199:
#line 2039 "src/grammar/for90.y"
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

  case 200:
#line 2054 "src/grammar/for90.y"
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

  case 201:
#line 2067 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 202:
#line 2072 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 203:
#line 2078 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 204:
#line 2083 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 205:
#line 2088 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 206:
#line 2094 "src/grammar/for90.y"
    {
				ParseNode & suite = YY2ARG((yyvsp[(4) - (6)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.get_what() }, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 207:
#line 2102 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 208:
#line 2107 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 209:
#line 2112 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 210:
#line 2122 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 211:
#line 2129 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 212:
#line 2134 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 213:
#line 2142 "src/grammar/for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_promote("%s", TokenMeta::NT_WRAPPERS, wrapper);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 214:
#line 2150 "src/grammar/for90.y"
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

  case 215:
#line 2168 "src/grammar/for90.y"
    {
				ARG_OUT wrappers = YY2ARG((yyvsp[(4) - (7)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 216:
#line 2176 "src/grammar/for90.y"
    {
				gen_fortran_program(YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 5023 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"
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


#line 2181 "src/grammar/for90.y"

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

