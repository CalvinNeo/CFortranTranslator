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
#line 409 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"

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
#define YYFINAL  184
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  243
/* YYNRULES -- Number of states.  */
#define YYNSTATES  473

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   367

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     122,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   124,     2,     2,
     118,   119,   115,   113,   120,   114,     2,   116,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   123,   117,
       2,   121,     2,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    20,    25,    30,    35,    40,    45,    47,    49,    51,
      53,    55,    57,    59,    63,    64,    66,    70,    74,    78,
      80,    82,    86,    88,    90,    92,    94,    96,    99,   101,
     103,   107,   113,   115,   117,   121,   127,   131,   133,   137,
     141,   145,   150,   155,   157,   160,   163,   165,   167,   171,
     175,   179,   183,   187,   191,   194,   197,   201,   205,   209,
     213,   217,   221,   224,   228,   232,   236,   240,   244,   246,
     248,   250,   254,   258,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   282,   284,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     314,   317,   319,   322,   324,   330,   334,   338,   344,   346,
     348,   350,   352,   356,   358,   360,   362,   364,   366,   370,
     374,   380,   383,   389,   395,   398,   403,   405,   409,   411,
     415,   417,   421,   423,   427,   432,   434,   438,   440,   442,
     444,   446,   448,   454,   457,   461,   465,   469,   471,   473,
     475,   477,   479,   481,   483,   488,   493,   497,   503,   505,
     509,   512,   513,   517,   522,   526,   529,   531,   533,   536,
     543,   545,   549,   553,   557,   558,   560,   562,   564,   574,
     578,   580,   583,   584,   591,   602,   612,   625,   636,   650,
     658,   667,   669,   670,   677,   690,   705,   713,   723,   730,
     737,   742,   749,   751,   754,   759,   760,   762,   764,   766,
     768,   770,   782,   790,   792,   793,   795,   797,   800,   802,
     804,   807,   814,   821,   823,   825,   827,   829,   831,   833,
     835,   837,   841,   849
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     201,     0,    -1,     4,    -1,    -1,   129,    -1,   127,   129,
      -1,   117,    -1,     4,    -1,   128,    -1,    64,    -1,    -1,
      86,   118,    87,   119,    -1,    86,   118,    88,   119,    -1,
      86,   118,    89,   119,    -1,    83,   118,   177,   119,    -1,
      83,   118,   142,   119,    -1,    83,    -1,    90,    -1,    81,
      -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,   120,
     131,   132,    -1,    -1,   142,    -1,   133,   120,   142,    -1,
      92,   121,    23,    -1,    91,   121,   142,    -1,   142,    -1,
      24,    -1,    23,    20,    23,    -1,    23,    -1,    27,    -1,
      30,    -1,    31,    -1,    29,    -1,     1,   122,    -1,    25,
      -1,   143,    -1,   142,   123,   142,    -1,   142,   123,   142,
     123,   142,    -1,   123,    -1,   115,    -1,   142,   121,   142,
      -1,   142,    21,    22,   118,   119,    -1,   142,    21,   142,
      -1,   137,    -1,   139,   120,   137,    -1,   139,   120,   142,
      -1,   133,   120,   137,    -1,   136,   118,   177,   119,    -1,
     169,   118,   177,   119,    -1,   140,    -1,   107,   140,    -1,
     107,   136,    -1,   141,    -1,   180,    -1,   118,   142,   119,
      -1,   142,   113,   142,    -1,   142,   114,   142,    -1,   142,
     115,   142,    -1,   142,   116,   142,    -1,   142,    16,   142,
      -1,   114,   142,    -1,   113,   142,    -1,   142,    10,   142,
      -1,   142,    11,   142,    -1,   142,     7,   142,    -1,   142,
      12,   142,    -1,   142,    13,   142,    -1,   142,    14,   142,
      -1,    15,   142,    -1,   142,     5,   142,    -1,   142,     6,
     142,    -1,   142,     8,   142,    -1,   142,     9,   142,    -1,
     142,    26,   142,    -1,   178,    -1,   135,    -1,   136,    -1,
     136,   124,    25,    -1,   140,   124,    25,    -1,   143,   124,
      25,    -1,   142,    -1,   173,    -1,   147,    -1,   146,    -1,
     158,    -1,   151,    -1,   172,    -1,    32,    -1,    33,    -1,
     145,    -1,   160,    -1,    -1,   149,    -1,   150,    -1,    43,
      -1,   110,    -1,   148,    -1,   166,    -1,   167,    -1,   168,
      -1,   182,    -1,   185,    -1,   186,    -1,    46,    -1,    45,
      -1,    55,    23,    -1,   109,   135,    -1,   109,    -1,   108,
     135,    -1,   108,    -1,   142,    21,    22,   118,   119,    -1,
     142,    21,   142,    -1,   142,   121,   142,    -1,    75,   153,
     116,   157,   116,    -1,   136,    -1,   140,    -1,   178,    -1,
     152,    -1,   153,   120,   152,    -1,   135,    -1,    25,    -1,
      23,    -1,   154,    -1,   156,    -1,   157,   120,   156,    -1,
     155,   115,   154,    -1,   157,   120,   155,   115,   154,    -1,
      78,    79,    -1,    78,   169,   118,   177,   119,    -1,    78,
     170,   118,   177,   119,    -1,    34,   144,    -1,   112,   118,
     177,   119,    -1,   159,    -1,   159,   129,   161,    -1,   144,
      -1,   144,   129,   161,    -1,   200,    -1,   200,   129,   161,
      -1,   175,    -1,   175,   129,   161,    -1,    77,   127,   162,
     127,    -1,   192,    -1,   162,   127,   192,    -1,   115,    -1,
      23,    -1,   115,    -1,    23,    -1,    27,    -1,   118,   163,
     120,   164,   119,    -1,   164,   120,    -1,   104,   165,   177,
      -1,   106,   165,   177,    -1,   105,   165,   177,    -1,    97,
      -1,    98,    -1,   103,    -1,    99,    -1,   100,    -1,   101,
      -1,   102,    -1,    58,   118,    25,   119,    -1,   169,   118,
     134,   119,    -1,   169,   115,    23,    -1,   169,   115,   118,
     115,   119,    -1,   169,    -1,   116,    25,   116,    -1,   116,
     116,    -1,    -1,    74,   171,   177,    -1,   170,   132,    17,
     177,    -1,   170,   132,   177,    -1,   131,   177,    -1,    59,
      -1,    35,    -1,    35,    58,    -1,    58,    25,   127,   161,
     174,   193,    -1,   138,    -1,   176,   120,   138,    -1,   176,
     120,   142,    -1,   133,   120,   138,    -1,    -1,   176,    -1,
     133,    -1,   139,    -1,   118,   133,   120,   136,   121,   142,
     120,   142,   119,    -1,    84,   177,    85,    -1,   179,    -1,
      25,   123,    -1,    -1,   181,    36,   118,   142,   119,   144,
      -1,   181,    36,   118,   142,   119,    23,   120,    23,   120,
      23,    -1,   181,    36,   118,   142,   119,    37,   127,   161,
      40,    -1,   181,    36,   118,   142,   119,    37,   127,   161,
      38,   127,   161,    40,    -1,   181,    36,   118,   142,   119,
      37,   127,   161,   183,    40,    -1,   181,    36,   118,   142,
     119,    37,   127,   161,   183,    38,   127,   161,    40,    -1,
      39,   118,   142,   119,    37,   127,   161,    -1,    39,   118,
     142,   119,    37,   127,   161,   183,    -1,    23,    -1,    -1,
     181,    41,   127,   161,   126,    42,    -1,   181,    41,   184,
     136,   121,   142,   120,   142,   127,   161,   126,    42,    -1,
     181,    41,   184,   136,   121,   142,   120,   142,   120,   142,
     127,   161,   126,    42,    -1,   181,    56,   142,   127,   161,
     126,    42,    -1,   181,    53,    51,   118,   142,   119,   127,
     188,    54,    -1,    51,   118,   139,   119,   127,   161,    -1,
      51,   118,   133,   119,   127,   161,    -1,    51,    57,   127,
     161,    -1,    51,   118,    57,   119,   127,   161,    -1,   187,
      -1,   187,   188,    -1,    65,   118,   136,   119,    -1,    -1,
      62,    -1,    66,    -1,    63,    -1,    67,    -1,    35,    -1,
     130,   190,    25,   118,   177,   119,   189,   127,   161,   191,
     193,    -1,   130,   190,    25,   127,   161,   191,   193,    -1,
      25,    -1,    -1,    69,    -1,    35,    -1,    35,    68,    -1,
      61,    -1,    35,    -1,    35,    60,    -1,    68,   193,   127,
     161,   194,   193,    -1,    60,   193,   127,   161,   195,   193,
      -1,   197,    -1,   196,    -1,   192,    -1,   175,    -1,   144,
      -1,   159,    -1,    35,    -1,   198,    -1,   198,   127,   199,
      -1,    72,   193,   127,   199,   126,    73,   193,    -1,   199,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   155,   160,   166,   173,   180,   185,   191,
     197,   202,   210,   219,   227,   239,   253,   262,   270,   279,
     288,   297,   306,   316,   331,   337,   346,   370,   384,   399,
     414,   422,   431,   438,   447,   453,   459,   469,   477,   485,
     499,   509,   520,   531,   544,   556,   564,   575,   588,   610,
     632,   656,   667,   679,   684,   690,   710,   719,   726,   735,
     745,   755,   765,   775,   785,   794,   803,   813,   824,   834,
     845,   855,   865,   874,   884,   894,   903,   913,   933,   940,
     960,   972,   982,   991,  1002,  1014,  1020,  1026,  1032,  1037,
    1044,  1050,  1058,  1065,  1071,  1078,  1083,  1089,  1095,  1101,
    1107,  1114,  1119,  1124,  1130,  1135,  1140,  1146,  1152,  1158,
    1166,  1173,  1180,  1187,  1194,  1206,  1218,  1229,  1264,  1270,
    1276,  1284,  1293,  1312,  1318,  1324,  1332,  1340,  1349,  1367,
    1400,  1434,  1441,  1451,  1462,  1481,  1490,  1498,  1512,  1519,
    1532,  1540,  1552,  1560,  1571,  1583,  1594,  1606,  1616,  1623,
    1632,  1641,  1675,  1688,  1703,  1713,  1724,  1734,  1740,  1746,
    1752,  1758,  1764,  1770,  1776,  1795,  1802,  1808,  1814,  1820,
    1826,  1834,  1840,  1849,  1861,  1881,  1931,  1936,  1941,  1947,
    1957,  1965,  1973,  1982,  1992,  1999,  2004,  2009,  2015,  2033,
    2043,  2051,  2058,  2066,  2078,  2084,  2093,  2103,  2113,  2125,
    2135,  2146,  2152,  2157,  2165,  2189,  2201,  2211,  2222,  2233,
    2244,  2252,  2262,  2270,  2280,  2287,  2293,  2298,  2304,  2309,
    2314,  2320,  2335,  2348,  2354,  2359,  2364,  2369,  2375,  2380,
    2385,  2391,  2398,  2406,  2411,  2416,  2421,  2431,  2438,  2443,
    2451,  2459,  2477,  2485
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
  "YY_COMMON", "YY_DATA", "YY_PROCEDURE", "YY_CONTAINS", "YY_IMPLICIT",
  "YY_NONE", "YY_USE", "YY_PARAMETER", "YY_ENTRY", "YY_DIMENSION",
  "YY_ARRAYBUILDER_START", "YY_ARRAYBUILDER_END", "YY_INTENT", "YY_IN",
  "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_SAVE",
  "YY_ALLOCATABLE", "YY_TARGET", "YY_POINTER", "YY_INTEGER_T",
  "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "YY_DOUBLE_T", "YY_WRITE", "YY_READ", "YY_PRINT",
  "YY_CALL", "YY_STOP", "YY_PAUSE", "YY_RETURN", "YY_CONFIG_IMPLICIT",
  "YY_ALLOCATE", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','",
  "'='", "'\\n'", "':'", "'%'", "$accept", "crlf_or_not",
  "at_least_one_end_line", "semicolon", "end_of_stmt",
  "dummy_function_iden", "variable_desc_elem", "variable_desc", "argtable",
  "type_selector", "literal", "variable", "slice", "keyvalue",
  "dimen_slice", "function_array_body", "function_array", "exp",
  "inner_variable", "stmt", "control_stmt", "io_stmt", "compound_stmt",
  "jump_stmt", "pause_stmt", "stop_stmt", "let_stmt", "nlists_elem",
  "nlists", "c_in_clist", "r_in_clist", "clists_elem", "clists",
  "implicit_stmt", "labeled_stmts", "allocate_stmt", "suite",
  "function_decls", "_optional_device", "_optional_formatter", "io_info",
  "write", "print", "read", "type_name", "type_spec", "_blockname_or_none",
  "common_stmt", "var_def", "_optional_endtype", "type_decl",
  "pure_paramtable", "paramtable", "hidden_do", "array_builder_elem",
  "array_builder", "_optional_construct_name", "if_stmt", "elseif_stmt",
  "_optional_label_construct", "do_stmt", "select_stmt", "case_stmt_elem",
  "case_stmt", "_optional_result", "_optional_function",
  "_optional_endfunction", "function_decl", "_optional_name",
  "_optional_endmodule", "_optional_endprogram", "module", "program",
  "wrapper", "wrappers", "interface_decl", "fortran_program", 0
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
     365,   366,   367,    43,    45,    42,    47,    59,    40,    41,
      44,    61,    10,    58,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   125,   126,   126,   127,   127,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     137,   137,   137,   137,   138,   138,   138,   139,   139,   139,
     139,   140,   140,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   145,   145,   145,   145,
     145,   146,   146,   146,   147,   147,   147,   148,   148,   148,
     149,   149,   150,   150,   151,   151,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   155,   156,   157,   157,   157,
     157,   158,   158,   158,   159,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   164,   165,   165,   166,   167,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   170,   171,
     171,   171,   172,   173,   173,   173,   174,   174,   174,   175,
     176,   176,   176,   176,   176,   177,   177,   177,   178,   179,
     180,   181,   181,   182,   182,   182,   182,   182,   182,   183,
     183,   184,   184,   185,   185,   185,   185,   186,   187,   187,
     187,   187,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   192,   192,   193,   193,   194,   194,   194,   195,   195,
     195,   196,   197,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   201
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       0,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     3,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     5,     1,     1,     3,     5,     3,     1,     3,     3,
       3,     4,     4,     1,     2,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     1,     5,     3,     3,     5,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     3,
       5,     2,     5,     5,     2,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     5,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     3,     5,     1,     3,
       2,     0,     3,     4,     3,     2,     1,     1,     2,     6,
       1,     3,     3,     3,     0,     1,     1,     1,     9,     3,
       1,     2,     0,     6,    10,     9,    12,    10,    13,     7,
       8,     1,     0,     6,    12,    14,     7,     9,     6,     6,
       4,     6,     1,     2,     4,     0,     1,     1,     1,     1,
       1,    11,     7,     1,     0,     1,     1,     2,     1,     1,
       2,     6,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    32,    30,    38,    33,    36,    34,    35,
      91,    92,     0,   239,    98,   108,   107,     0,     0,   224,
       9,   224,   171,     0,     0,    18,    16,     0,     0,    17,
      19,    20,    21,    22,   157,   158,   160,   161,   162,   163,
     159,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,    79,    80,    53,    56,    84,    39,
     237,    93,    87,    86,   100,    96,    97,    89,    88,   238,
      94,   101,   102,   103,   168,    24,    90,    85,   236,    78,
     190,    57,     0,   104,   105,   106,   235,   234,   233,   240,
     243,     0,    37,    38,     0,    72,     0,     0,   191,   134,
     109,     0,     0,   223,     0,     0,     0,     0,     0,   118,
     119,   121,     0,   120,   131,     0,     0,     0,    43,    42,
     186,    47,   180,   187,    25,   185,     0,     0,   150,   151,
     149,     0,     0,     0,     0,     0,    55,    54,   112,   110,
       0,    65,    64,     0,    25,   216,   217,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,     7,
       6,     0,     8,     4,     1,     0,    31,     0,     0,     0,
       0,     0,   170,   172,    25,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   148,   147,     0,   153,   154,   156,   155,     0,     0,
      58,     0,     0,    81,    82,    73,    74,    68,    75,    76,
      66,    67,    69,    70,    71,    63,     0,   115,    77,    59,
      60,    61,    62,   116,    83,   166,     0,     0,     0,     0,
      25,     0,    24,     0,   174,     0,   201,     0,     0,     0,
       0,     5,   241,   224,     0,   138,   136,     0,   142,   140,
     164,     0,     0,   169,    32,   124,   123,   126,     0,   127,
       0,   122,     0,     0,    15,    14,    50,   183,    26,    48,
      49,     0,    46,    44,    40,   181,   182,    11,    12,    13,
       0,   135,    80,    26,     0,     0,    51,     0,     0,     0,
       0,   165,    52,    23,   173,     0,     3,     0,     0,     0,
       0,     0,    10,     0,     0,   177,   176,   224,     0,     0,
     229,   228,   224,   226,   225,   224,     0,   117,     0,   132,
     133,     0,     0,     0,     0,     0,     0,   114,   167,    28,
      27,     0,     2,     0,     0,     0,     3,     0,     0,   145,
     139,   137,   178,   179,   143,   141,   230,   232,   227,   231,
     129,     0,   128,    45,    41,   152,     0,   215,   220,   218,
     219,   224,    32,     0,   193,   203,     0,     0,     0,     3,
     144,     0,     0,     0,     0,   222,     0,     0,     0,     0,
     206,     0,   146,   130,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   224,   188,     0,     0,     0,     0,     0,
     195,     0,     0,     0,     0,     0,   213,   207,   242,   214,
     224,   194,     0,     0,     0,   197,     0,     3,     0,     0,
       0,     0,    25,   221,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,   196,     0,     0,     3,   204,     0,
       0,    26,     0,     0,   198,     0,   211,   209,   208,     0,
     205,   199,   200
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   353,   181,   182,   183,    52,    53,   174,   120,   249,
      54,    55,   121,   122,   123,    56,    57,    58,    59,   265,
      61,    62,    63,    64,    65,    66,    67,   111,   112,   277,
     278,   279,   280,    68,   266,    70,   267,   358,   213,   132,
     133,    71,    72,    73,    96,    75,   107,    76,    77,   327,
     268,   125,   251,    79,    80,    81,    82,    83,   421,   258,
      84,    85,   411,   412,   394,   147,   381,    86,   104,   335,
     332,    87,    88,    89,    90,   269,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -337
static const yytype_int16 yypact[] =
{
    1470,   -73,  2903,    53,  -337,   -11,  -337,  -337,  -337,  -337,
    -337,  -337,  1240,  -337,  -337,  -337,  -337,    80,    -7,    82,
    -337,    82,    -1,   196,   858,  -337,    59,   865,    64,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,   174,   174,   174,   477,    37,   499,  -337,    87,  2903,
    2903,  2903,   -30,   737,  -337,   -40,    76,  -337,  3040,    91,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,   -21,    93,  -337,  -337,  -337,  -337,
    -337,  -337,   195,  -337,  -337,  -337,  -337,  -337,  -337,    17,
    -337,   218,  -337,  -337,   112,   595,   125,   214,  -337,  -337,
    -337,    17,   222,  -337,    17,    17,    70,   737,  2903,   -40,
      76,  -337,   -69,  -337,  -337,    99,   134,   911,  -337,  -337,
     133,  -337,  -337,   135,  1584,   138,   175,   139,  -337,  -337,
    -337,    42,   142,   737,   737,   737,   -40,    76,  -337,  -337,
     911,   230,   230,   159,  3110,  -337,  -337,   256,  -337,   911,
     257,   258,  2903,  2903,  2903,  2903,  2903,  2903,  2903,  2903,
    2903,  2903,  2903,  2853,  2903,  2903,  2903,  2903,  2903,  2903,
     259,    25,   784,   584,   633,   170,     3,   240,  2903,  -337,
    -337,  1355,  -337,  -337,  -337,   911,  -337,  2168,   181,  2283,
    2398,   185,  -337,  -337,  1642,   793,   196,   784,   911,   264,
     183,  1021,  1021,  2878,  2903,  2903,  2903,  -337,   187,   190,
     193,  -337,  -337,   184,  -337,  -337,  -337,  -337,   198,  2903,
    -337,     1,   199,  -337,  -337,   230,   230,  1367,   230,   230,
    1367,  3249,  3249,   595,   479,    36,   201,  1642,  1642,    83,
      83,    36,    36,  1642,  -337,  -337,   206,   205,   209,   203,
    1584,   208,    93,   737,  -337,  2903,  -337,  2628,   477,   215,
    3226,  -337,  -337,    82,    17,    17,    17,    -5,    17,    17,
    -337,    10,    -6,  -337,    22,  -337,  -337,  -337,   217,  -337,
     -46,  -337,   216,   219,  -337,  -337,  -337,  -337,  1584,  -337,
     119,   223,  1642,  1642,  1606,  -337,  3062,  -337,  -337,  -337,
      23,  -337,   -16,  1642,   911,  1938,  -337,   233,   234,  2903,
     288,  -337,  -337,  -337,  -337,  3134,   343,    32,    76,  2903,
    2628,    17,     5,  1708,  1708,   291,  -337,    82,  1708,  1708,
     294,  -337,    82,   290,  -337,    82,   840,  -337,   793,  -337,
    -337,   237,  2903,   244,  2903,   246,   153,  -337,  -337,  1642,
    -337,  1125,  -337,   317,  2903,  3158,   343,  1823,    17,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,   251,  -337,  -337,  1642,  -337,   713,   302,  -337,  -337,
    -337,    82,    -3,    17,  -337,  -337,  3084,    17,   327,   343,
      19,   840,  2903,   253,    17,  -337,   349,  2053,  2903,    35,
    -337,   300,  -337,  -337,  3180,   477,  1938,   254,   228,  3018,
     -29,   325,   330,    82,  -337,   -84,   153,   363,    17,   272,
    -337,   111,  2903,  2628,    17,   975,  -337,  -337,  -337,  -337,
      82,  -337,  2743,  2903,    17,  -337,  3226,   343,  2513,   276,
     -27,   120,   119,  -337,   351,  3202,  2743,  2628,   354,  -337,
      17,    17,  1021,    17,  -337,   362,   360,   343,  -337,  2513,
    2513,   119,  2513,    17,  -337,   361,  -337,  -337,  -337,  2053,
    -337,   366,  -337
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -337,  -336,    43,  -337,   150,  -337,   229,   156,   -50,  -337,
      -2,   -17,  -187,  -119,   -15,   -13,  -337,     6,  -337,     4,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,   213,  -337,  -311,
      74,    75,  -337,  -337,    11,  -337,   192,  -337,  -337,   114,
     207,  -337,  -337,  -337,     0,   393,  -337,  -337,  -337,  -337,
      13,  -337,    89,   -20,  -337,  -337,  -337,  -337,   -51,  -337,
    -337,  -337,  -337,    14,  -337,  -337,     8,  -300,   -19,  -337,
    -337,  -337,  -337,  -337,  -162,  -337,  -337
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -193
static const yytype_int16 yytable[] =
{
      74,   143,   105,   113,    60,   179,   109,   179,    95,   179,
     110,    69,    74,    78,   286,   289,    99,    97,   101,   262,
     388,   179,   359,   179,   115,   370,   256,   136,   424,   333,
     325,   137,   145,   124,   149,   429,   146,  -113,     1,   179,
     150,  -113,    97,   138,   139,   330,   128,   195,   245,    92,
     129,   196,   162,   401,   326,   141,   142,   144,   143,   124,
       3,     4,   164,   334,     6,   211,     7,     8,     9,    20,
     337,   331,  -113,    97,   338,  -113,  -113,  -113,   149,  -113,
     403,   -10,   287,    20,   150,   -10,   410,   295,  -113,   425,
     402,  -113,   451,   452,   171,   191,  -113,   172,  -113,   162,
    -113,   448,   149,   100,  -113,   344,  -113,   103,   150,   164,
    -113,   102,    98,   124,   194,   106,   126,   396,   180,   304,
     180,   465,   180,   199,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   180,   162,   180,  -125,   130,   124,
     124,   124,   148,   246,   187,   164,   124,   189,   190,   434,
     149,   435,   180,   354,  -113,   124,   150,   212,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   237,
     238,   239,   240,   241,   242,   243,   113,   117,   250,   109,
     124,    74,   127,   110,   260,    60,   192,    74,   378,    74,
      74,   124,    69,   276,    78,   389,   193,   128,   167,   168,
     151,   129,   302,   250,   124,   140,   200,   288,   290,   292,
     293,   294,   296,   173,   171,   170,   379,   197,   184,   257,
     380,    93,   215,   216,   217,   303,   208,   209,   210,   218,
     102,   175,   165,   166,   167,   168,   176,   186,   222,   453,
     202,   317,   205,   185,   321,   318,   162,   188,   177,   134,
     135,   178,   198,   201,    94,   202,   164,    74,   206,   124,
     207,   315,   214,   254,   305,   286,   418,   419,   420,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   219,
     162,   221,   223,   224,   244,   203,   282,   283,   255,   130,
     164,   259,   131,    34,    35,    36,    37,    38,    39,    40,
     270,   273,   285,   320,   300,    74,   297,   322,   363,   298,
     124,   350,   299,   367,   108,   349,   369,   301,   306,   307,
      74,   308,   311,    74,    74,   355,   309,   312,    74,    74,
     310,   261,   336,   319,   276,   339,   276,   261,   340,   261,
     261,   341,   314,   165,   166,   167,   168,   352,   374,   362,
     376,    74,   347,   348,   366,   384,   373,    74,   368,   385,
     386,    60,   395,   375,   357,   377,   391,   393,    69,   400,
      78,   405,   407,   413,   417,   440,   410,   165,   166,   167,
     168,   271,   272,   284,   427,   204,   431,   205,   415,   276,
     433,   454,   318,   345,   428,   450,   458,    74,   404,   463,
     464,   390,   252,   470,   409,   419,    74,   261,   313,   281,
     441,   443,   371,   372,   343,   323,   324,   116,   328,   329,
     472,     0,     0,    74,   430,   426,   397,     0,   436,     0,
     399,   442,    74,     0,     0,     0,     0,   406,    74,   445,
       0,     0,     0,     0,     0,     0,    74,    74,     0,   316,
       0,     0,   423,     0,     0,   261,     0,     0,   461,    74,
      74,   432,    74,     0,     0,     0,     0,   438,     0,    74,
     261,     0,   261,     0,     0,     0,     0,   446,     0,   447,
       0,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,     0,   160,   459,   460,   162,   462,   346,     0,  -111,
       1,     0,    93,  -111,     0,   164,   469,   261,     0,     0,
       0,     0,   356,     0,     0,   360,   361,     0,     0,     0,
     364,   365,     3,     4,     0,     0,     6,     0,     7,     8,
       9,     0,     0,     0,  -111,    94,     0,  -111,  -111,  -111,
     261,  -111,     0,     0,     0,     0,     0,   261,     0,   261,
    -111,     0,     0,  -111,     0,     0,   261,     0,  -111,     0,
    -111,     0,  -111,     0,     0,     0,  -111,     0,  -111,     0,
       0,     0,  -111,   261,    34,    35,    36,    37,    38,    39,
      40,     0,   261,     0,     0,     0,     0,     0,   261,   408,
       0,     0,   165,   166,   167,   168,   261,   261,   416,     0,
     152,   153,   154,   155,   156,   157,     0,     0,     0,   261,
     261,   162,   261,     0,     0,   437,  -111,     0,     0,   261,
       0,   164,     0,     0,   444,     0,     0,     0,     0,     0,
     449,     0,     0,  -184,     1,     0,     0,  -184,   456,   457,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
     253,   466,   467,     0,   468,     0,     3,     4,    93,     0,
       6,   471,     7,     8,     9,    25,     0,    26,  -184,     0,
      28,  -184,  -184,  -184,    29,  -184,     0,    30,    31,    32,
      33,     0,     0,     0,  -184,     0,     0,  -184,     0,     0,
       0,    94,  -184,     0,  -184,     0,  -184,     0,     0,     0,
    -184,     0,  -184,     0,     0,     0,  -184,     0,   165,   166,
     167,   168,     0,     0,     0,     0,     0,    27,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,   162,
      34,    35,    36,    37,    38,    39,    40,  -184,     1,   164,
      44,  -184,     0,     0,     0,     0,    49,    50,   118,     0,
    -184,    51,     2,  -184,     0,     0,   119,     0,     0,     0,
       3,     4,    93,     0,     6,     0,     7,     8,     9,     0,
       0,     0,  -184,     0,     0,  -184,  -184,  -184,     0,  -184,
       0,     0,     0,     0,     0,     1,     0,     0,  -184,     0,
       0,  -184,     0,     0,     1,    94,  -184,     0,  -184,     2,
    -184,     0,     0,     0,  -184,     0,  -184,     3,     4,    93,
    -184,     6,     0,     7,     8,     9,   274,     4,   275,     0,
       6,    27,     7,     8,     9,     0,   165,   166,   167,   168,
       0,     0,     0,   392,    34,    35,    36,    37,    38,    39,
      40,     1,    94,     0,    44,     0,     0,     0,     0,     0,
      49,    50,   118,     0,  -184,    51,     0,  -184,     0,     0,
     119,     0,     0,     3,     4,   275,     1,     6,    27,     7,
       8,     9,     0,     0,     0,   247,   248,     0,     0,     0,
       2,    34,    35,    36,    37,    38,    39,    40,     3,     4,
      93,    44,     6,     0,     7,     8,     9,    49,    50,   118,
       0,     0,    51,  -184,  -184,     0,     0,   119,     0,     0,
       0,     0,     1,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,    93,   114,     6,     0,
       7,     8,     9,     0,     0,     0,     0,     0,     0,    27,
    -184,     0,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,    34,    35,    36,    37,    38,    39,    40,    94,
       0,     0,    44,     0,     0,     0,     1,     0,    49,    50,
     118,     0,     0,    51,     0,  -184,     0,     0,   119,     0,
       2,     0,     0,     0,     0,    27,     0,     0,     3,     4,
      93,     0,     6,     0,     7,     8,     9,     0,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,    44,     0,
       0,     0,     1,     0,    49,    50,   118,     0,     0,    51,
    -184,  -184,   439,    94,   119,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,    93,     0,     6,     0,
       7,     8,     9,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,    94,
       0,     0,    44,     0,     0,     0,     0,     0,    49,    50,
     118,     0,     0,    51,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
      36,    37,    38,    39,    40,   -95,     1,     0,    44,   -95,
       0,     0,     0,     0,    49,    50,   118,     0,     0,    51,
       2,     0,     0,     0,   119,     0,     0,     0,   382,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
     -95,  -192,   383,   -95,   -95,   -95,  -192,   -95,    14,     0,
      15,    16,     0,     0,     0,     0,   -95,     0,  -192,   -95,
      17,  -192,     0,    94,   -95,     0,   -95,     0,   -95,     0,
       0,     0,   -95,     0,   -95,     0,     0,     0,   -95,    22,
      23,     0,     0,    24,     0,     0,    25,     0,    26,    27,
       0,    28,     0,     0,     0,    29,     0,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     -95,     1,   -95,    51,   -95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,     0,   -95,  -192,     0,   -95,   -95,
     -95,  -192,   -95,    14,     0,    15,    16,     0,     0,     0,
       0,   -95,     0,  -192,   -95,    17,  -192,     0,    94,   -95,
       0,   -95,     0,   -95,     0,     0,     0,   -95,     0,   -95,
       0,     0,     0,   -95,    22,    23,     0,     0,    24,     0,
       0,    25,     0,    26,    27,     0,    28,     0,     0,     0,
      29,     0,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   -95,     1,   -95,    51,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,   152,   153,     0,   155,   156,     0,     3,     4,
       5,     0,     6,   162,     7,     8,     9,    10,    11,    12,
      13,  -192,     0,   164,     0,     0,  -192,     0,    14,     0,
      15,    16,     0,     0,     0,     0,     0,     0,  -192,     0,
      17,  -192,     0,    18,     0,    19,     0,   -10,     0,    20,
       0,   -10,     0,    21,     0,     0,     0,     0,   -95,    22,
      23,     0,     0,    24,     0,     0,    25,     0,    26,    27,
       0,    28,     0,     0,     0,    29,     0,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     -95,     1,   180,    51,   -95,     0,     0,     0,     0,     0,
     165,   166,   167,   168,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,  -192,     0,     0,     0,
       0,  -192,     0,    14,     0,    15,    16,     0,     0,     0,
       0,     0,     0,  -192,     0,    17,  -192,     0,    18,     0,
      19,     0,   -10,     0,    20,     0,   -10,     0,    21,     0,
       0,     0,     0,     0,    22,    23,     0,     0,    24,     0,
       0,    25,     0,    26,    27,     0,    28,     0,     0,     0,
      29,     0,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,     0,     0,   -95,    51,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     162,     0,     0,     0,     0,   203,     0,     0,     0,     0,
     164,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,     0,     0,     0,     0,   204,     0,   205,     0,     1,
       0,     0,   -95,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,     2,     0,     0,     0,     0,     0,   342,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -95,  -192,     0,   -95,   -95,   -95,  -192,
     -95,    14,     0,    15,    16,   165,   166,   167,   168,   -95,
       0,  -192,   -95,    17,  -192,     0,    18,   -95,     0,   -95,
       0,   -95,     0,     0,     0,   -95,     0,   -95,     0,     0,
     263,     0,    22,    23,     0,   264,    24,     0,     0,    25,
       0,    26,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     1,   -95,    51,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,  -192,
       0,     0,     0,     0,  -192,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -192,     0,    17,  -192,
       0,    18,     0,    19,     0,   -10,     0,    20,     0,   -10,
       0,    21,     0,     0,     0,     0,   -95,    22,    23,     0,
       0,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,     0,     1,
     180,    51,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -95,  -192,     0,     0,     0,     0,  -192,
       0,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -192,     0,    17,  -192,     0,    18,     0,     0,     0,
       0,   -95,     0,     0,     0,   -95,     0,     0,     0,     0,
     263,     0,    22,    23,     0,   264,    24,     0,     0,    25,
       0,    26,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     1,   180,    51,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -192,
       0,   -95,   -95,   -95,  -192,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -192,     0,    17,  -192,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,    22,    23,     0,
     264,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,     0,     1,
     180,    51,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -95,  -192,     0,     0,     0,     0,  -192,
       0,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -192,     0,    17,  -192,     0,    18,   -95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,    22,    23,     0,   264,    24,     0,     0,    25,
       0,    26,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     1,   180,    51,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,   -95,  -192,
       0,     0,     0,     0,  -192,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -192,     0,    17,  -192,
       0,    18,     0,     0,   -95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,    22,    23,     0,
     264,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,     0,     1,
     180,    51,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -95,  -192,     0,     0,     0,     0,  -192,
       0,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -192,     0,    17,  -192,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -95,     0,     0,
     263,     0,    22,    23,     0,   264,    24,     0,     0,    25,
       0,    26,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     1,   180,    51,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -192,
       0,     0,     0,     0,  -192,     0,    14,     0,    15,    16,
       0,     0,     0,     0,   -95,     0,  -192,   -95,    17,  -192,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,    22,    23,     0,
     264,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,     0,     1,
     180,    51,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,     0,  -192,     0,     0,     0,     0,  -192,
     -95,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -192,     0,    17,  -192,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,    22,    23,     0,   264,    24,     0,     0,    25,
       0,    26,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     1,   180,    51,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -192,
       0,     0,     0,   -95,  -192,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,  -192,     0,    17,  -192,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,    22,    23,     0,
     264,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     1,    48,    49,    50,     0,     0,
     180,    51,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,   236,     3,     4,    93,     1,
       6,     0,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
     291,     3,     4,    93,     1,     6,     0,     7,     8,     9,
       0,    94,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,    93,     0,
       6,     0,     7,     8,     9,     0,    94,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
      44,    94,    27,     0,     0,     0,    49,    50,     0,     0,
       0,    51,     0,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    44,     0,    27,     0,     0,
       0,    49,    50,     0,     0,     0,    51,     0,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    49,    50,     0,     0,
       0,    51,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,   162,     0,     0,     0,
       0,   163,     0,     0,     0,     0,   164,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   162,     0,
       0,     0,     0,   203,     0,     0,     0,     0,   164,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,   162,     0,     0,     0,
       0,   165,   166,   167,   168,   180,   164,     0,   422,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     162,     0,     0,   165,   166,   167,   168,     0,     0,     0,
     164,   169,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,   162,   165,   166,   167,   168,     0,
       0,     0,     0,   204,   164,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,   162,   165,   166,   167,
     168,     0,     0,     0,   398,     0,   164,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   162,     0,
       0,     0,     0,   165,   166,   167,   168,     0,   164,   220,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,   162,     0,     0,     0,     0,   165,   166,   167,
     168,     0,   164,   351,   152,   153,   154,   155,   156,   157,
       0,     0,   160,   161,     0,   162,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   164,     0,   387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,     0,     0,   414,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,     0,
       0,   455,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
       0,    51,    21,    23,     0,     4,    23,     4,     2,     4,
      23,     0,    12,     0,   201,   202,    12,    20,    25,   181,
     356,     4,   322,     4,    24,   336,    23,    44,    57,    35,
      35,    44,    62,    27,   118,   119,    66,     0,     1,     4,
     124,     4,    20,    45,    46,    35,    23,   116,    23,   122,
      27,   120,    16,   389,    59,    49,    50,    51,   108,    53,
      23,    24,    26,    69,    27,    23,    29,    30,    31,    64,
     116,    61,    35,    20,   120,    38,    39,    40,   118,    42,
     391,    62,   201,    64,   124,    66,    51,   206,    51,   118,
     390,    54,   119,   120,   115,    25,    59,   118,    61,    16,
      63,   437,   118,    23,    67,   121,    69,    25,   124,    26,
      73,   118,   123,   107,   108,   116,    27,   120,   117,   118,
     117,   457,   117,   117,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   117,    16,   117,   115,   115,   133,
     134,   135,    53,   118,   101,    26,   140,   104,   105,    38,
     118,    40,   117,   121,   117,   149,   124,   115,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   196,   118,   172,   196,
     174,   181,   118,   196,   178,   181,   116,   187,    35,   189,
     190,   185,   181,   195,   181,   357,   107,    23,   115,   116,
     124,    27,   219,   197,   198,   118,   117,   201,   202,   203,
     204,   205,   206,   120,   115,   124,    63,   118,     0,   176,
      67,    25,   133,   134,   135,   219,    87,    88,    89,   140,
     118,    36,   113,   114,   115,   116,    41,    23,   149,   119,
     120,   258,   123,   118,   263,   258,    16,    25,    53,    42,
      43,    56,   118,   120,    58,   120,    26,   257,   120,   253,
      85,   255,   120,   174,   221,   452,    38,    39,    40,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   120,
      16,    25,    25,    25,    25,    21,   197,   198,   118,   115,
      26,    51,   118,    97,    98,    99,   100,   101,   102,   103,
     119,   116,   119,   260,   120,   305,   119,   264,   327,   119,
     304,    23,   119,   332,   118,   309,   335,   119,   119,   118,
     320,   115,   119,   323,   324,   319,   121,   119,   328,   329,
     121,   181,   115,   118,   336,   119,   338,   187,   119,   189,
     190,   118,   253,   113,   114,   115,   116,     4,   342,    58,
     344,   351,   119,   119,    60,   351,   119,   357,    68,    42,
     354,   357,   381,   119,   321,   119,   115,    65,   357,    42,
     357,   118,    23,    73,   120,   425,    51,   113,   114,   115,
     116,   189,   190,   119,    54,   121,    23,   123,   405,   391,
     118,    40,   405,   304,   413,   119,    42,   397,   392,    37,
      40,   358,   173,    42,   398,    39,   406,   257,   252,   196,
     425,   430,   338,   338,   300,   265,   266,    24,   268,   269,
     471,    -1,    -1,   423,   416,   411,   383,    -1,   422,    -1,
     387,   425,   432,    -1,    -1,    -1,    -1,   394,   438,   433,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,    -1,   257,
      -1,    -1,   409,    -1,    -1,   305,    -1,    -1,   452,   459,
     460,   418,   462,    -1,    -1,    -1,    -1,   424,    -1,   469,
     320,    -1,   322,    -1,    -1,    -1,    -1,   434,    -1,   436,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,   450,   451,    16,   453,   305,    -1,     0,
       1,    -1,    25,     4,    -1,    26,   463,   357,    -1,    -1,
      -1,    -1,   320,    -1,    -1,   323,   324,    -1,    -1,    -1,
     328,   329,    23,    24,    -1,    -1,    27,    -1,    29,    30,
      31,    -1,    -1,    -1,    35,    58,    -1,    38,    39,    40,
     390,    42,    -1,    -1,    -1,    -1,    -1,   397,    -1,   399,
      51,    -1,    -1,    54,    -1,    -1,   406,    -1,    59,    -1,
      61,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    -1,    73,   423,    97,    98,    99,   100,   101,   102,
     103,    -1,   432,    -1,    -1,    -1,    -1,    -1,   438,   397,
      -1,    -1,   113,   114,   115,   116,   446,   447,   406,    -1,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,   459,
     460,    16,   462,    -1,    -1,   423,   117,    -1,    -1,   469,
      -1,    26,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
     438,    -1,    -1,     0,     1,    -1,    -1,     4,   446,   447,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,   459,   460,    -1,   462,    -1,    23,    24,    25,    -1,
      27,   469,    29,    30,    31,    81,    -1,    83,    35,    -1,
      86,    38,    39,    40,    90,    42,    -1,    93,    94,    95,
      96,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    -1,    61,    -1,    63,    -1,    -1,    -1,
      67,    -1,    69,    -1,    -1,    -1,    73,    -1,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    84,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      97,    98,    99,   100,   101,   102,   103,     0,     1,    26,
     107,     4,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
     117,   118,    15,   120,    -1,    -1,   123,    -1,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    35,    -1,    -1,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    51,    -1,
      -1,    54,    -1,    -1,     1,    58,    59,    -1,    61,    15,
      63,    -1,    -1,    -1,    67,    -1,    69,    23,    24,    25,
      73,    27,    -1,    29,    30,    31,    23,    24,    25,    -1,
      27,    84,    29,    30,    31,    -1,   113,   114,   115,   116,
      -1,    -1,    -1,   120,    97,    98,    99,   100,   101,   102,
     103,     1,    58,    -1,   107,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,   117,   118,    -1,   120,    -1,    -1,
     123,    -1,    -1,    23,    24,    25,     1,    27,    84,    29,
      30,    31,    -1,    -1,    -1,    91,    92,    -1,    -1,    -1,
      15,    97,    98,    99,   100,   101,   102,   103,    23,    24,
      25,   107,    27,    -1,    29,    30,    31,   113,   114,   115,
      -1,    -1,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    79,    27,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    97,    98,    99,   100,   101,   102,   103,    58,
      -1,    -1,   107,    -1,    -1,    -1,     1,    -1,   113,   114,
     115,    -1,    -1,   118,    -1,   120,    -1,    -1,   123,    -1,
      15,    -1,    -1,    -1,    -1,    84,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    -1,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,    -1,
      -1,    -1,     1,    -1,   113,   114,   115,    -1,    -1,   118,
     119,   120,    57,    58,   123,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,    58,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,   118,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,     0,     1,    -1,   107,     4,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,   118,
      15,    -1,    -1,    -1,   123,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    -1,    63,    -1,
      -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    73,    74,
      75,    -1,    -1,    78,    -1,    -1,    81,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,   113,   114,
       0,     1,   117,   118,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,
      -1,    -1,    -1,    73,    74,    75,    -1,    -1,    78,    -1,
      -1,    81,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,   112,   113,   114,     0,     1,   117,   118,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,     5,     6,    -1,     8,     9,    -1,    23,    24,
      25,    -1,    27,    16,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    26,    -1,    -1,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,
      75,    -1,    -1,    78,    -1,    -1,    81,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,   113,   114,
       0,     1,   117,   118,     4,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    -1,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,
      -1,    81,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,   112,   113,   114,    -1,    -1,   117,   118,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,   121,    -1,   123,    -1,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,    15,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,   113,   114,   115,   116,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,     1,   117,   118,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    60,    -1,    62,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    74,    75,    -1,
      -1,    78,    -1,    -1,    81,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,    -1,     1,
     117,   118,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,     1,   117,   118,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    81,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,    -1,     1,
     117,   118,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,     1,   117,   118,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    81,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,    -1,     1,
     117,   118,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,     1,   117,   118,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    51,    -1,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    81,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,   114,    -1,     1,
     117,   118,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    81,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,     1,   117,   118,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    -1,    40,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    81,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     1,   112,   113,   114,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,     1,
      27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,     1,    27,    -1,    29,    30,    31,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    -1,    58,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,    58,    84,    -1,    -1,    -1,   113,   114,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,    -1,    84,    -1,    -1,
      -1,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
      -1,   118,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,    26,    -1,   120,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,   113,   114,   115,   116,    -1,    -1,    -1,
      26,   121,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,   121,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,   113,   114,   115,
     116,    -1,    -1,    -1,   120,    -1,    26,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,    -1,    26,   119,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    26,   119,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,    26,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    23,    24,    25,    27,    29,    30,    31,
      32,    33,    34,    35,    43,    45,    46,    55,    58,    60,
      64,    68,    74,    75,    78,    81,    83,    84,    86,    90,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   112,   113,
     114,   118,   130,   131,   135,   136,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   158,   159,
     160,   166,   167,   168,   169,   170,   172,   173,   175,   178,
     179,   180,   181,   182,   185,   186,   192,   196,   197,   198,
     199,   201,   122,    25,    58,   142,   169,    20,   123,   144,
      23,    25,   118,    25,   193,   193,   116,   171,   118,   136,
     140,   152,   153,   178,    79,   169,   170,   118,   115,   123,
     133,   137,   138,   139,   142,   176,   177,   118,    23,    27,
     115,   118,   164,   165,   165,   165,   136,   140,   135,   135,
     118,   142,   142,   133,   142,    62,    66,   190,   177,   118,
     124,   124,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    16,    21,    26,   113,   114,   115,   116,   121,
     124,   115,   118,   120,   132,    36,    41,    53,    56,     4,
     117,   127,   128,   129,     0,   118,    23,   127,    25,   127,
     127,    25,   116,   177,   142,   116,   120,   118,   118,   142,
     177,   120,   120,    21,   121,   123,   120,    85,    87,    88,
      89,    23,   115,   163,   120,   177,   177,   177,   177,   120,
     119,    25,   177,    25,    25,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,    22,   142,   142,   142,
     142,   142,   142,   142,    25,    23,   118,    91,    92,   134,
     142,   177,   131,    17,   177,   118,    23,   127,   184,    51,
     142,   129,   199,    72,    77,   144,   159,   161,   175,   200,
     119,   161,   161,   116,    23,    25,   135,   154,   155,   156,
     157,   152,   177,   177,   119,   119,   137,   138,   142,   137,
     142,    22,   142,   142,   142,   138,   142,   119,   119,   119,
     120,   119,   136,   142,   118,   127,   119,   118,   115,   121,
     121,   119,   119,   132,   177,   142,   161,   136,   140,   118,
     127,   193,   127,   129,   129,    35,    59,   174,   129,   129,
      35,    61,   195,    35,    69,   194,   115,   116,   120,   119,
     119,   118,   123,   164,   121,   177,   161,   119,   119,   142,
      23,   119,     4,   126,   121,   142,   161,   127,   162,   192,
     161,   161,    58,   193,   161,   161,    60,   193,    68,   193,
     154,   155,   156,   119,   142,   119,   142,   119,    35,    63,
      67,   191,    23,    37,   144,    42,   142,   119,   126,   199,
     127,   115,   120,    65,   189,   193,   120,   127,   120,   127,
      42,   126,   192,   154,   142,   118,   127,    23,   161,   142,
      51,   187,   188,    73,   119,   136,   161,   120,    38,    39,
      40,   183,   120,   127,    57,   118,   188,    54,   193,   119,
     191,    23,   127,   118,    38,    40,   142,   161,   127,    57,
     133,   139,   142,   193,   161,   142,   127,   127,   126,   161,
     119,   119,   120,   119,    40,   119,   161,   161,    42,   127,
     127,   142,   127,    37,    40,   126,   161,   161,   161,   127,
      42,   161,   183
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
#line 338 "src/grammar/for90.y"
    {
				// argtable is used in function call
				ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 26:
#line 347 "src/grammar/for90.y"
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

  case 27:
#line 371 "src/grammar/for90.y"
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

  case 28:
#line 385 "src/grammar/for90.y"
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

  case 29:
#line 400 "src/grammar/for90.y"
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

  case 30:
#line 415 "src/grammar/for90.y"
    {
				// all arguments under `literal` rule is directly from tokenizer
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 31:
#line 423 "src/grammar/for90.y"
    {
				ARG_OUT base = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT expo = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float,  base.get_what() + "e" + expo.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 32:
#line 432 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.get_what() })); // int number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 33:
#line 439 "src/grammar/for90.y"
    {
				// replace `'` with `"`
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				std::string s = lit.get_what().substr(1, lit.get_what().size() - 2);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 34:
#line 448 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 35:
#line 454 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 36:
#line 460 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				string strcplx = lit.get_what();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 37:
#line 470 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				print_error("exp parse error");
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 38:
#line 478 "src/grammar/for90.y"
    {
                ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
                ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.get_what() });
                (yyval) = RETURN_NT(newnode);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
                CLEAN_DELETE((yyvsp[(1) - (1)]));
            ;}
    break;

  case 39:
#line 486 "src/grammar/for90.y"
    {
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 40:
#line 500 "src/grammar/for90.y"
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

  case 41:
#line 510 "src/grammar/for90.y"
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

  case 42:
#line 521 "src/grammar/for90.y"
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

  case 43:
#line 532 "src/grammar/for90.y"
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

  case 44:
#line 545 "src/grammar/for90.y"
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

  case 45:
#line 557 "src/grammar/for90.y"
    {
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (5)]));
				(yyval) = RETURN_NT(gen_keyvalue_from_exp(YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]));
			;}
    break;

  case 46:
#line 565 "src/grammar/for90.y"
    {
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				std:string str = exp2.get_what();
				exp2.get_what()=std::string("&")+std::string("(")+exp2.get_what()+std::string(")");
				(yyval) = RETURN_NT(gen_keyvalue_from_exp( YY2ARG((yyvsp[(1) - (3)])),exp2));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
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
#line 973 "src/grammar/for90.y"
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
#line 983 "src/grammar/for90.y"
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
#line 992 "src/grammar/for90.y"
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
#line 1003 "src/grammar/for90.y"
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

  case 85:
#line 1015 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 86:
#line 1021 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 87:
#line 1027 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 88:
#line 1033 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 89:
#line 1038 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 90:
#line 1045 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 91:
#line 1051 "src/grammar/for90.y"
    {
				ARG_OUT format = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.to_string() + "\"" }, format);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 92:
#line 1059 "src/grammar/for90.y"
    { 
				ARG_OUT comment = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_comment(comment.get_what()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 93:
#line 1066 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 94:
#line 1072 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 95:
#line 1078 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 96:
#line 1084 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 97:
#line 1090 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 98:
#line 1096 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 99:
#line 1102 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 100:
#line 1108 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 101:
#line 1115 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 102:
#line 1120 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 103:
#line 1125 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 104:
#line 1131 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 105:
#line 1136 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 106:
#line 1141 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 107:
#line 1147 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Continue, "continue;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 108:
#line 1153 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 109:
#line 1159 "src/grammar/for90.y"
    {
				ARG_OUT line = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Goto, line.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 110:
#line 1167 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.get_what() + ");stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 111:
#line 1174 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 112:
#line 1181 "src/grammar/for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop(" + lit.get_what() + ");" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 113:
#line 1188 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop();" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 114:
#line 1195 "src/grammar/for90.y"
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

  case 115:
#line 1207 "src/grammar/for90.y"
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

  case 116:
#line 1219 "src/grammar/for90.y"
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

  case 117:
#line 1230 "src/grammar/for90.y"
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
				        lelem = exp1.get(0);
				        lelem.get_what().append("(").append("INOUT("+std::to_string(i+1)+")").append(")");
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

  case 118:
#line 1265 "src/grammar/for90.y"
    {
                //printf("in nlists_elem:variable\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 119:
#line 1271 "src/grammar/for90.y"
    {
                //printf("in nlists_elem:function_array_body\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 120:
#line 1277 "src/grammar/for90.y"
    {
                //printf("in nlists_elem:hidden_do\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 121:
#line 1285 "src/grammar/for90.y"
    {
                //printf("in nlists:nlists_elem\n");
            	ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
            	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
            	(yyval) = RETURN_NT(newnode);
            	update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            	CLEAN_DELETE((yyvsp[(1) - (1)]));
            ;}
    break;

  case 122:
#line 1294 "src/grammar/for90.y"
    {
                //printf("in nlists:nlists, nlists_elem\n");
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

  case 123:
#line 1313 "src/grammar/for90.y"
    {
                //printf("in c_in_clist:literal\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 124:
#line 1319 "src/grammar/for90.y"
    {
                //printf("in c_in_clist:YY_WORD\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 125:
#line 1325 "src/grammar/for90.y"
    {
                //printf("in r_in_clist:YY_INTEGER\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 126:
#line 1333 "src/grammar/for90.y"
    {
                //printf("in clists_elem:c_in_clist\n");
                (yyval) = (yyvsp[(1) - (1)]);
                update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            ;}
    break;

  case 127:
#line 1341 "src/grammar/for90.y"
    {
                //printf("in clists:clists_elem\n");
            	ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
            	ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
            	(yyval) = RETURN_NT(newnode);
            	update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
            	CLEAN_DELETE((yyvsp[(1) - (1)]));
            ;}
    break;

  case 128:
#line 1350 "src/grammar/for90.y"
    {
                //printf("in clists:clists, clists_elem\n");
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

  case 129:
#line 1368 "src/grammar/for90.y"
    {
                //printf("in clists:r_in_clist * c_in_clist\n");
				ARG_OUT r = YY2ARG((yyvsp[(1) - (3)]));
				int times = std::stoi(r.get_what());
				ARG_OUT c = YY2ARG((yyvsp[(3) - (3)]));

				ParseNode * newnode = new ParseNode();
            	*newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , c.get_what()}, c);

#ifdef USE_REUSE
                for(int i = 1; i < times; i++)
                {
                  ParseNode * container = new ParseNode();
                  ParseNode *exp = new ParseNode(c);
				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				  newnode = container;
                }
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
                for(int i = 1; i < times; i++)
                {
                  ParseNode *exp = new ParseNode(c);
				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                }
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
            ;}
    break;

  case 130:
#line 1401 "src/grammar/for90.y"
    {
                //printf("in clists:clists ',' r_in_clist '*' c_in_clist\n");
				ARG_OUT argtable = YY2ARG((yyvsp[(1) - (5)]));
				ARG_OUT r = YY2ARG((yyvsp[(3) - (5)]));
				int times = std::stoi(r.get_what());
				ARG_OUT c = YY2ARG((yyvsp[(5) - (5)]));

				ParseNode * newnode = new ParseNode();
				*newnode = argtable;
#ifdef USE_REUSE
                for(int i = 0; i < times; i++)
                {
                  ParseNode * container = new ParseNode();
                  ParseNode *exp = new ParseNode(c);
				  reuse_flatten(*container, *exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				  newnode = container;
                }
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
				CLEAN_REUSE((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
#else
                for(int i = 0; i < times; i++)
                {
                  ParseNode *exp = new ParseNode(c);
				  *newnode = gen_flatten(*exp, *newnode, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
                }
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
#endif
            ;}
    break;

  case 131:
#line 1435 "src/grammar/for90.y"
    {
				// dummy stmt
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 132:
#line 1442 "src/grammar/for90.y"
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

  case 133:
#line 1452 "src/grammar/for90.y"
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

  case 134:
#line 1463 "src/grammar/for90.y"
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

  case 135:
#line 1482 "src/grammar/for90.y"
    {
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ALLOCATE_STMT, "" }, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 136:
#line 1491 "src/grammar/for90.y"
    {
				// NT_FORMAT or other stmt node
				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 137:
#line 1499 "src/grammar/for90.y"
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

  case 138:
#line 1513 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 139:
#line 1520 "src/grammar/for90.y"
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

  case 140:
#line 1533 "src/grammar/for90.y"
    {
				// NT_INTERFACE
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(interf, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 141:
#line 1541 "src/grammar/for90.y"
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

  case 142:
#line 1553 "src/grammar/for90.y"
    {
				// NT_DERIVED_TYPE
				ARG_OUT type_decl = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(type_decl, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 143:
#line 1561 "src/grammar/for90.y"
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

  case 144:
#line 1572 "src/grammar/for90.y"
    {
				ARG_OUT func_decls = YY2ARG((yyvsp[(3) - (4)]));
				(yyval) = RETURN_NT(gen_suite(func_decls, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(3) - (4)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
#endif
			;}
    break;

  case 145:
#line 1584 "src/grammar/for90.y"
    {
				ARG_OUT func_decl = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(func_decl, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (1)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (1)]));
#endif
			;}
    break;

  case 146:
#line 1595 "src/grammar/for90.y"
    {
				ARG_OUT func_decl = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(1) - (3)]));
				(yyval) = RETURN_NT(gen_suite(func_decl, suite));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			;}
    break;

  case 147:
#line 1607 "src/grammar/for90.y"
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

  case 148:
#line 1617 "src/grammar/for90.y"
    {
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, integer.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 149:
#line 1624 "src/grammar/for90.y"
    {
				/******************
				* an asterisk (*) which indicates list-directed formatting (10.8).
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 150:
#line 1633 "src/grammar/for90.y"
    {
				// use format stmt at line YY2ARG($1) to format
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				std::string location_label = integer.get_what();
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 151:
#line 1642 "src/grammar/for90.y"
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

  case 152:
#line 1676 "src/grammar/for90.y"
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

  case 153:
#line 1689 "src/grammar/for90.y"
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

  case 154:
#line 1704 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, WHEN_DEBUG_OR_EMPTY("WRITE GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 155:
#line 1714 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, WHEN_DEBUG_OR_EMPTY("PRINT GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 156:
#line 1725 "src/grammar/for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, WHEN_DEBUG_OR_EMPTY("READ GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 157:
#line 1735 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 158:
#line 1741 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 159:
#line 1747 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 160:
#line 1753 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 161:
#line 1759 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 162:
#line 1765 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 163:
#line 1771 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 164:
#line 1777 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 165:
#line 1796 "src/grammar/for90.y"
    {
				// now translated in pre_map
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 166:
#line 1803 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 167:
#line 1809 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (5)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(3) - (5)])));
				CLEAN_DELETE((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]));
			;}
    break;

  case 168:
#line 1815 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 169:
#line 1821 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 170:
#line 1827 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 171:
#line 1834 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 172:
#line 1841 "src/grammar/for90.y"
    {
				ARG_OUT blockname = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_common(blockname, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 173:
#line 1850 "src/grammar/for90.y"
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

  case 174:
#line 1862 "src/grammar/for90.y"
    {
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));

				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 175:
#line 1882 "src/grammar/for90.y"
    {
				ARG_OUT variable_desc_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc_elem, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 176:
#line 1932 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 177:
#line 1937 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 178:
#line 1942 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 179:
#line 1948 "src/grammar/for90.y"
    {
				ARG_OUT variable_type = YY2ARG((yyvsp[(2) - (6)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				//$$ = RETURN_NT(gen_suite(suite, gen_dummy()));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_DERIVED_TYPE, "" }, variable_type, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 180:
#line 1958 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 181:
#line 1966 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 182:
#line 1974 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 183:
#line 1983 "src/grammar/for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 184:
#line 1992 "src/grammar/for90.y"
    {
				// empty list
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 185:
#line 2000 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 186:
#line 2005 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 187:
#line 2010 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 188:
#line 2016 "src/grammar/for90.y"
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

  case 189:
#line 2034 "src/grammar/for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = RETURN_NT(gen_arraybuilder_from_paramtable(YY2ARG((yyvsp[(2) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			;}
    break;

  case 190:
#line 2044 "src/grammar/for90.y"
    {
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 191:
#line 2052 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			;}
    break;

  case 192:
#line 2058 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 193:
#line 2067 "src/grammar/for90.y"
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

  case 194:
#line 2079 "src/grammar/for90.y"
    {
				// Arithmetic if
				// `IF (e) s1, s2, s3`, where
				// s1, s2, s3 are labels
			;}
    break;

  case 195:
#line 2085 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			;}
    break;

  case 196:
#line 2094 "src/grammar/for90.y"
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

  case 197:
#line 2104 "src/grammar/for90.y"
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

  case 198:
#line 2114 "src/grammar/for90.y"
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

  case 199:
#line 2126 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 200:
#line 2136 "src/grammar/for90.y"
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

  case 201:
#line 2147 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 202:
#line 2152 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 203:
#line 2158 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, WHEN_DEBUG_OR_EMPTY("DO-BARE GENERATED IN REGEN_SUITE") }, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(5) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
			;}
    break;

  case 204:
#line 2166 "src/grammar/for90.y"
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

  case 205:
#line 2190 "src/grammar/for90.y"
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

  case 206:
#line 2202 "src/grammar/for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, WHEN_DEBUG_OR_EMPTY("DO-WHILE GENERATED IN REGEN_SUITE") }, exp, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(6) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]));
			;}
    break;

  case 207:
#line 2212 "src/grammar/for90.y"
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

  case 208:
#line 2223 "src/grammar/for90.y"
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

  case 209:
#line 2234 "src/grammar/for90.y"
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

  case 210:
#line 2245 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 211:
#line 2253 "src/grammar/for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 212:
#line 2263 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, case_stmt_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 213:
#line 2271 "src/grammar/for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_flatten(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			;}
    break;

  case 214:
#line 2281 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			;}
    break;

  case 215:
#line 2287 "src/grammar/for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 216:
#line 2294 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 217:
#line 2299 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 218:
#line 2305 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 219:
#line 2310 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 220:
#line 2315 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 221:
#line 2321 "src/grammar/for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (11)])); // function name
				// enumerate parameter list 
				ARG_OUT paramtable = YY2ARG((yyvsp[(5) - (11)]));
				ARG_OUT variable_result = YY2ARG((yyvsp[(7) - (11)])); // result variable
				ARG_OUT suite = YY2ARG((yyvsp[(9) - (11)]));

				ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flattened parameter list with all keyvalue elements
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (11)])), YY2ARG((yyvsp[(11) - (11)])));
				CLEAN_DELETE((yyvsp[(1) - (11)]), (yyvsp[(2) - (11)]), (yyvsp[(3) - (11)]), (yyvsp[(4) - (11)]), (yyvsp[(5) - (11)]), (yyvsp[(6) - (11)]), (yyvsp[(7) - (11)]), (yyvsp[(8) - (11)]), (yyvsp[(9) - (11)]), (yyvsp[(10) - (11)]), (yyvsp[(11) - (11)]));
			;}
    break;

  case 222:
#line 2336 "src/grammar/for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (7)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (7)]));

				ParseNode kvparamtable = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				ParseNode void_return = gen_token(Term{ TokenMeta::UnknownVariant, "" });
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 223:
#line 2349 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 224:
#line 2354 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			;}
    break;

  case 225:
#line 2360 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 226:
#line 2365 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 227:
#line 2370 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 228:
#line 2376 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 229:
#line 2381 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 230:
#line 2386 "src/grammar/for90.y"
    {
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
			;}
    break;

  case 231:
#line 2392 "src/grammar/for90.y"
    {
				ParseNode & suite = YY2ARG((yyvsp[(4) - (6)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_MODULE, (yyvsp[(2) - (6)])->get_what() }, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 232:
#line 2399 "src/grammar/for90.y"
    {
				ParseNode & suite = YY2ARG((yyvsp[(4) - (6)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.get_what() }, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			;}
    break;

  case 233:
#line 2407 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 234:
#line 2412 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
		    ;}
    break;

  case 235:
#line 2417 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 236:
#line 2422 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 237:
#line 2432 "src/grammar/for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 238:
#line 2439 "src/grammar/for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;

  case 239:
#line 2444 "src/grammar/for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 240:
#line 2452 "src/grammar/for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_promote("%s", TokenMeta::NT_WRAPPERS, wrapper);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			;}
    break;

  case 241:
#line 2460 "src/grammar/for90.y"
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

  case 242:
#line 2478 "src/grammar/for90.y"
    {
				ARG_OUT wrappers = YY2ARG((yyvsp[(4) - (7)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			;}
    break;

  case 243:
#line 2486 "src/grammar/for90.y"
    {
				gen_fortran_program(YY2ARG((yyvsp[(1) - (1)])));
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 5515 "/Users/xiehaoning/Library/Mobile Documents/3L68KQB4HG~com~readdle~CommonDocuments/Documents/FDU/2021 秋-2022 春夏/春/腾飞科创/CFortranTranslator/cmake-build-debug/for90.cpp"
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


#line 2491 "src/grammar/for90.y"

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

