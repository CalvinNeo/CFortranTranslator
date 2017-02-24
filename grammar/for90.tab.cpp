/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 20 "for90.y"

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include <tuple>
#include "../tokenizer.h"
#include "../attribute.h"
#include "../parser.h"
#include "../gen_config.h"
#include "../Function.h"
#include "../codegen.h"


// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
// static is necessary, or will cause lnk
static char codegen_buf[MAX_CODE_LENGTH];
using namespace std;

/* Line 371 of yacc.c  */
#line 96 "for90.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "for90.tab.h".  */
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
     YY_INTEGER = 275,
     YY_FLOAT = 276,
     YY_WORD = 277,
     YY_OPERATOR = 278,
     YY_STRING = 279,
     YY_ILLEGAL = 280,
     YY_COMPLEX = 281,
     YY_TRUE = 282,
     YY_FALSE = 283,
     YY_FORMAT_STMT = 284,
     YY_COMMENT = 285,
     YY_LABEL = 286,
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
     YY_EXIT = 297,
     YY_CYCLE = 298,
     YY_WHILE = 299,
     YY_ENDWHILE = 300,
     YY_WHERE = 301,
     YY_ENDWHERE = 302,
     YY_CASE = 303,
     YY_ENDCASE = 304,
     YY_SELECT = 305,
     YY_ENDSELECT = 306,
     YY_GOTO = 307,
     YY_DOWHILE = 308,
     YY_DEFAULT = 309,
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
     YY_COMMON = 324,
     YY_DATA = 325,
     YY_IMPLICIT = 326,
     YY_NONE = 327,
     YY_USE = 328,
     YY_PARAMETER = 329,
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
     YY_SAVE = 341,
     YY_INTEGER_T = 342,
     YY_FLOAT_T = 343,
     YY_STRING_T = 344,
     YY_COMPLEX_T = 345,
     YY_BOOL_T = 346,
     YY_CHARACTER_T = 347,
     YY_WRITE = 348,
     YY_READ = 349,
     YY_PRINT = 350,
     YY_CALL = 351,
     YY_STOP = 352,
     YY_PAUSE = 353
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 260 "for90.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  164
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  197
/* YYNRULES -- Number of states.  */
#define YYNSTATES  384

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   353

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     108,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     104,   105,   101,    99,   106,   100,     2,   102,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   109,   103,
       2,   107,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    16,    18,
      20,    22,    24,    25,    30,    35,    40,    45,    50,    52,
      54,    56,    59,    63,    64,    68,    72,    74,    76,    78,
      80,    82,    84,    87,    89,    93,    99,   101,   105,   107,
     111,   113,   117,   121,   125,   130,   135,   137,   140,   142,
     144,   149,   153,   157,   161,   165,   169,   173,   176,   179,
     183,   187,   191,   195,   199,   203,   206,   210,   214,   218,
     222,   224,   226,   228,   230,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   278,   281,
     283,   286,   288,   292,   295,   298,   303,   305,   309,   311,
     315,   316,   318,   319,   321,   323,   324,   326,   328,   330,
     332,   334,   340,   343,   347,   351,   355,   357,   359,   361,
     363,   365,   367,   372,   377,   382,   387,   392,   397,   401,
     403,   407,   410,   411,   415,   420,   424,   427,   429,   433,
     437,   441,   442,   444,   446,   448,   458,   462,   466,   468,
     471,   472,   475,   477,   484,   492,   503,   512,   524,   530,
     537,   540,   542,   549,   561,   575,   583,   586,   588,   598,
     605,   607,   610,   615,   616,   618,   620,   632,   634,   635,
     643,   650,   652,   654,   656,   658,   662,   671
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     176,     0,    -1,     4,    -1,    -1,     4,    -1,   112,     4,
      -1,   113,    -1,   112,   113,    -1,   103,    -1,     4,    -1,
     113,    -1,    59,    -1,    -1,    79,   104,    80,   105,    -1,
      79,   104,    81,   105,    -1,    79,   104,    82,   105,    -1,
      76,   104,   124,   105,    -1,    76,   104,   127,   105,    -1,
      83,    -1,    74,    -1,    86,    -1,   106,   116,    -1,   106,
     116,   117,    -1,    -1,    85,   107,    20,    -1,    84,   107,
     127,    -1,    21,    -1,    20,    -1,    24,    -1,    27,    -1,
      28,    -1,    26,    -1,     1,   108,    -1,    22,    -1,   127,
     109,   127,    -1,   127,   109,   127,   109,   127,    -1,   109,
      -1,   127,   107,   127,    -1,   127,    -1,   123,   106,   127,
      -1,   121,    -1,   124,   106,   121,    -1,   124,   106,   127,
      -1,   123,   106,   121,    -1,   120,   104,   154,   105,    -1,
     148,   104,   154,   105,    -1,   125,    -1,    96,   125,    -1,
     126,    -1,   157,    -1,   127,   104,   127,   105,    -1,   104,
     127,   105,    -1,   127,    99,   127,    -1,   127,   100,   127,
      -1,   127,   101,   127,    -1,   127,   102,   127,    -1,   127,
      16,   127,    -1,   100,   127,    -1,    99,   127,    -1,   127,
      10,   127,    -1,   127,    11,   127,    -1,   127,     7,   127,
      -1,   127,    12,   127,    -1,   127,    13,   127,    -1,   127,
      14,   127,    -1,    15,   127,    -1,   127,     5,   127,    -1,
     127,     6,   127,    -1,   127,     8,   127,    -1,   127,     9,
     127,    -1,   155,    -1,   119,    -1,   120,    -1,    31,    -1,
     127,    -1,   152,    -1,   132,    -1,   130,    -1,   131,    -1,
     137,    -1,   136,    -1,   133,    -1,   151,    -1,    29,    -1,
      30,    -1,   134,    -1,   135,    -1,    40,    -1,    -1,   145,
      -1,   146,    -1,   147,    -1,   160,    -1,   163,    -1,   165,
      -1,    43,    -1,    42,    -1,    52,    20,    -1,    98,   119,
      -1,    98,    -1,    97,   119,    -1,    97,    -1,   127,   107,
     127,    -1,    71,    72,    -1,   128,   129,    -1,   128,   129,
     114,   138,    -1,   129,    -1,   129,   114,   138,    -1,   175,
      -1,   175,   114,   138,    -1,    -1,   104,    -1,    -1,   105,
      -1,   106,    -1,    -1,   101,    -1,    20,    -1,   101,    -1,
      20,    -1,    24,    -1,   104,   142,   106,   143,   105,    -1,
     143,   141,    -1,    93,   144,   154,    -1,    95,   144,   154,
      -1,    94,   144,   154,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    87,   104,   118,
     105,    -1,    88,   104,   118,   105,    -1,    89,   104,   118,
     105,    -1,    90,   104,   118,   105,    -1,    91,   104,   118,
     105,    -1,    92,   104,   118,   105,    -1,   148,   101,    20,
      -1,   148,    -1,   102,   120,   102,    -1,   102,   102,    -1,
      -1,    69,   150,   154,    -1,   149,   117,    17,   154,    -1,
     149,   117,   154,    -1,    76,   154,    -1,   122,    -1,   153,
     106,   122,    -1,   153,   106,   127,    -1,   123,   106,   122,
      -1,    -1,   153,    -1,   123,    -1,   124,    -1,   104,   123,
     106,   120,   107,   127,   106,   127,   105,    -1,    77,   154,
      78,    -1,    77,   155,    78,    -1,   156,    -1,    22,   109,
      -1,    -1,    32,    33,    -1,    37,    -1,   158,    33,   104,
     127,   105,   129,    -1,   158,    33,   127,    34,   112,   138,
     159,    -1,   158,    33,   127,    34,   112,   138,    35,   112,
     138,   159,    -1,   158,    33,   127,    34,   112,   138,   161,
     159,    -1,   158,    33,   127,    34,   112,   138,   161,    35,
     112,   138,   159,    -1,    36,   127,    34,   112,   138,    -1,
      36,   127,    34,   112,   138,   161,    -1,    32,    38,    -1,
      39,    -1,   158,    38,   112,   138,   111,   162,    -1,   158,
      38,   120,   107,   127,   106,   127,   112,   138,   111,   162,
      -1,   158,    38,   120,   107,   127,   106,   127,   106,   127,
     112,   138,   111,   162,    -1,   158,    53,   127,   112,   138,
     111,   162,    -1,    32,    50,    -1,    51,    -1,   158,    50,
      48,   139,   127,   140,   112,   167,   164,    -1,    48,   139,
     124,   140,   112,   138,    -1,   166,    -1,   166,   167,    -1,
      60,   104,   120,   105,    -1,    -1,    57,    -1,    61,    -1,
     115,   169,   120,   104,   154,   105,   168,   112,   138,    32,
     169,    -1,    22,    -1,    -1,    55,   171,   112,   138,    32,
      55,   171,    -1,    55,   171,   112,    32,    55,   171,    -1,
     138,    -1,   170,    -1,   172,    -1,   173,    -1,   173,   112,
     174,    -1,    67,   171,   112,   174,   111,    32,    67,   171,
      -1,   174,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    79,    84,    89,    94,    99,   105,   110,
     111,   113,   114,   116,   123,   131,   138,   151,   169,   176,
     184,   193,   198,   212,   225,   236,   250,   255,   259,   265,
     269,   273,   280,   282,   296,   305,   315,   324,   334,   342,
     350,   360,   370,   380,   399,   409,   420,   424,   429,   436,
     444,   452,   460,   468,   476,   484,   492,   500,   507,   514,
     522,   531,   539,   548,   556,   564,   571,   579,   587,   595,
     603,   609,   614,   620,   626,   636,   642,   646,   650,   654,
     658,   663,   669,   674,   679,   684,   685,   686,   692,   698,
     699,   701,   703,   704,   705,   707,   712,   717,   723,   729,
     734,   740,   746,   755,   762,   780,   803,   809,   816,   821,
     827,   828,   829,   830,   831,   832,   833,   837,   841,   845,
     850,   857,   868,   882,   890,   899,   907,   912,   917,   922,
     927,   932,   938,   944,   949,   954,   959,   964,   972,   977,
     983,   988,   995,  1001,  1009,  1019,  1029,  1041,  1048,  1056,
    1064,  1073,  1080,  1081,  1082,  1084,  1100,  1107,  1115,  1130,
    1131,  1134,  1135,  1138,  1145,  1152,  1160,  1168,  1178,  1186,
    1195,  1196,  1198,  1204,  1214,  1224,  1232,  1233,  1235,  1243,
    1251,  1259,  1269,  1275,  1281,  1282,  1284,  1297,  1298,  1300,
    1306,  1312,  1325,  1326,  1328,  1337,  1349,  1355
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "YY_IGNORE_THIS", "YY_CRLF", "YY_GT",
  "YY_GE", "YY_EQ", "YY_LE", "YY_LT", "YY_NEQ", "YY_NEQV", "YY_EQV",
  "YY_ANDAND", "YY_OROR", "YY_NOT", "YY_POWER", "YY_DOUBLECOLON", "YY_NEG",
  "YY_POS", "YY_INTEGER", "YY_FLOAT", "YY_WORD", "YY_OPERATOR",
  "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX", "YY_TRUE", "YY_FALSE",
  "YY_FORMAT_STMT", "YY_COMMENT", "YY_LABEL", "YY_END", "YY_IF", "YY_THEN",
  "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO", "YY_ENDDO", "YY_CONTINUE",
  "YY_BREAK", "YY_EXIT", "YY_CYCLE", "YY_WHILE", "YY_ENDWHILE", "YY_WHERE",
  "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT",
  "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT", "YY_PROGRAM", "YY_ENDPROGRAM",
  "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT",
  "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE",
  "YY_BLOCK", "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE",
  "YY_COMMON", "YY_DATA", "YY_IMPLICIT", "YY_NONE", "YY_USE",
  "YY_PARAMETER", "YY_ENTRY", "YY_DIMENSION", "YY_ARRAYINITIAL_START",
  "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT",
  "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_SAVE", "YY_INTEGER_T",
  "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "YY_WRITE", "YY_READ", "YY_PRINT", "YY_CALL",
  "YY_STOP", "YY_PAUSE", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'",
  "','", "'='", "'\\n'", "':'", "$accept", "crlf_or_not",
  "at_least_one_end_line", "semicolon", "end_of_stmt",
  "dummy_function_iden", "variable_desc_elem", "variable_desc",
  "type_selector", "literal", "variable", "slice", "keyvalue", "argtable",
  "dimen_slice", "function_array_body", "function_array", "exp", "label",
  "stmt", "output_stmt", "input_stmt", "compound_stmt", "jump_stmt",
  "pause_stmt", "stop_stmt", "let_stmt", "dummy_stmt", "suite",
  "_optional_lbrace", "_optional_rbrace", "_optional_comma",
  "_optional_device", "_optional_formatter", "io_info", "write", "print",
  "read", "type_name", "type_spec", "_blockname_or_none", "common_stmt",
  "var_def", "pure_paramtable", "paramtable", "hidden_do",
  "array_builder_elem", "array_builder", "_optional_construct_name",
  "_yy_endif", "if_stmt", "elseif_stmt", "_yy_enddo", "do_stmt",
  "_yy_endselect", "select_stmt", "case_stmt_elem", "case_stmt",
  "_optional_result", "_optional_function", "function_decl",
  "_optional_name", "program", "wrapper", "wrappers", "interface_decl",
  "fortran_program", YY_NULL
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,    43,
      45,    42,    47,    59,    40,    41,    44,    61,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   112,   112,   112,   112,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   120,   121,   121,   121,   122,   123,   123,
     124,   124,   124,   124,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   131,   132,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   136,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   144,   144,   145,   146,   147,   148,   148,   148,   148,
     148,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   151,   152,   152,   152,   153,   153,   153,
     153,   153,   154,   154,   154,   155,   156,   156,   157,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     162,   162,   163,   163,   163,   163,   164,   164,   165,   166,
     167,   167,   168,   168,   169,   169,   170,   171,   171,   172,
     172,   172,   173,   173,   174,   174,   175,   176
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     2,     1,     1,
       1,     1,     0,     4,     4,     4,     4,     4,     1,     1,
       1,     2,     3,     0,     3,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     5,     1,     3,     1,     3,
       1,     3,     3,     3,     4,     4,     1,     2,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     1,     3,     2,     2,     4,     1,     3,     1,     3,
       0,     1,     0,     1,     1,     0,     1,     1,     1,     1,
       1,     5,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     3,     1,
       3,     2,     0,     3,     4,     3,     2,     1,     3,     3,
       3,     0,     1,     1,     1,     9,     3,     3,     1,     2,
       0,     2,     1,     6,     7,    10,     8,    11,     5,     6,
       2,     1,     6,    11,    13,     7,     2,     1,     9,     6,
       1,     2,     4,     0,     1,     1,    11,     1,     0,     7,
       6,     1,     1,     1,     1,     3,     8,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    27,    26,    33,    28,    31,    29,    30,
      83,    84,    73,    87,    96,    95,     0,   188,    11,   188,
     142,     0,     0,     0,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    46,    48,    74,     0,   106,    77,    78,    76,
      81,    85,    86,    80,    79,   191,    89,    90,    91,   139,
      23,    82,    75,    70,   158,    49,     0,    92,    93,    94,
     192,   193,   194,   197,   108,     0,    32,    33,   126,   127,
     128,   129,   130,   131,    65,     0,   159,    97,   187,     0,
       0,     0,     0,   103,    36,    40,   147,   153,   154,    38,
     152,   146,     0,    70,     0,     0,     0,     0,     0,     0,
     119,   120,   118,     0,   115,     0,     0,     0,     0,    47,
     100,    98,    58,    57,     0,    38,   184,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     9,     8,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     6,     0,     1,     0,     0,   141,     0,   143,
       0,     0,     0,     0,     0,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   116,     0,   114,   122,
     123,   125,   124,     0,    51,     0,     0,    66,    67,    61,
      68,    69,    59,    60,    62,    63,    64,    56,    52,    53,
      54,    55,     0,   102,     0,   107,   138,     0,    19,     0,
       0,    18,    20,    21,     0,   145,     0,     0,     0,     0,
     110,     0,     5,     7,   195,   109,     0,     0,     3,   140,
      43,   150,    39,    41,    42,    37,    34,   148,   149,     0,
       0,   132,   133,   134,   135,   136,   137,     0,    72,    39,
       0,    44,    50,   105,    45,     0,     0,    22,   144,    38,
       0,     3,     0,   111,     0,     0,   188,     0,     2,     0,
       0,    25,    24,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,   112,     3,   190,   188,
       0,    35,   121,     0,   183,     0,    16,    17,    13,    14,
      15,   163,     0,     0,   171,   172,     0,   113,     0,     0,
     189,   188,     0,     0,     0,    39,     0,     0,     0,   162,
     164,     0,   170,     0,     0,   175,   196,     0,     0,     0,
     161,     0,     0,     0,   166,     0,     0,   110,   180,     0,
     155,     0,     0,     0,     0,     0,     0,     3,     0,   181,
       0,   177,   178,   182,     0,   165,     0,     0,     0,     0,
     112,    38,   176,   186,   168,   167,     3,   173,     0,   169,
       0,     0,   174,   179
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   279,   161,   162,   151,    39,   223,   155,   179,    40,
      41,    95,    96,    97,    98,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   274,
     318,   189,   187,   114,   115,    56,    57,    58,    85,    60,
      92,    61,    62,   100,   101,    63,    64,    65,    66,   330,
      67,   331,   315,    68,   362,    69,   348,   349,   324,   128,
      70,    89,    71,    72,    73,    74,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -316
static const yytype_int16 yypact[] =
{
    1071,   -67,  1925,  -316,  -316,   -25,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,    45,    51,  -316,    51,
      24,    18,   419,   465,    49,    56,    58,    76,    78,    85,
      19,    19,    19,   153,  1216,  2030,  1925,  1925,  1925,   -17,
    -316,    89,  -316,  -316,  2090,   869,     5,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,   -47,
      43,  -316,  -316,  -316,  -316,  -316,     9,  -316,  -316,  -316,
    -316,  -316,     6,  -316,     5,   200,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,    21,    97,  -316,  -316,  -316,     6,
       6,    -7,   419,  -316,  -316,  -316,  -316,    96,   103,   619,
     104,  -316,   133,   134,   -56,   -56,   -56,   -56,   -56,   -56,
    -316,  -316,  -316,    -3,   107,   419,   419,   419,    89,  -316,
    -316,  -316,   187,   187,   109,  2154,  -316,  -316,   194,   511,
    1925,  1925,  1925,  1925,  1925,  1925,  1925,  1925,  1925,  1925,
    1925,  1925,  1925,  1925,  1925,  1925,  1925,     5,  -316,  -316,
    -316,   768,   197,   511,   111,   373,  1949,     2,   170,  1925,
    -316,   970,  -316,   768,  -316,  1790,  1285,  -316,   118,  -316,
     557,   557,  1925,  1925,  1925,  -316,  -316,   114,   115,   119,
     121,   122,   124,   127,   128,  -316,  -316,   129,  -316,  -316,
    -316,  -316,  -316,  1925,  -316,   130,   131,   187,   187,    77,
     187,   187,    77,  2334,  2334,  2434,  2415,    15,    55,    55,
      15,    15,  2255,  2334,   768,  -316,  -316,   141,  -316,   135,
     143,  -316,  -316,    43,   419,  -316,  1925,  2303,  1588,   146,
     150,  2142,  -316,  -316,  -316,  -316,   195,   224,   253,  -316,
    -316,  -316,   619,  -316,  1183,  2334,  1195,  -316,  2102,  1925,
     238,  -316,  -316,  -316,  -316,  -316,  -316,    26,   -43,  2334,
     511,  -316,  -316,  -316,  -316,   557,    -2,  -316,  -316,  2267,
       6,   253,  1925,  -316,  1925,  1588,    51,   205,  -316,   230,
    1925,  2334,  -316,   158,  1925,   160,   161,   -36,  1171,   163,
     165,   167,   663,  1386,    16,  2114,  2279,   253,  -316,    51,
     199,  2334,  -316,  2129,   209,   557,  -316,  -316,  -316,  -316,
    -316,  -316,    40,   236,  -316,  -316,  1925,  -316,     6,    16,
    -316,    51,  1925,   172,     6,  1183,   245,     6,  1925,  -316,
    -316,    67,  -316,  2078,     3,  -316,  -316,  2291,   194,  1891,
    -316,  1689,  2315,     6,  -316,  1925,  1588,   150,   232,    17,
    -316,   176,   250,   -12,     6,  1689,  2142,   253,   557,  -316,
     235,  -316,  -316,  -316,   -17,  -316,  1386,   -12,  1588,    16,
      62,  1183,  -316,  -316,   258,  -316,   253,  -316,     6,  -316,
      16,  1487,  -316,  -316
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -316,  -263,     7,   -44,   -55,  -316,  -316,    73,    99,    66,
     -10,  -159,  -114,   -35,  -251,   266,  -316,    -1,  -316,   -40,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,    23,   -46,
     -70,  -316,  -316,    46,   164,  -316,  -316,  -316,     0,  -316,
    -316,  -316,  -316,  -316,    -5,   282,  -316,  -316,  -316,  -315,
    -316,   -66,  -306,  -316,  -316,  -316,  -316,   -41,  -316,   -54,
    -316,   -15,  -316,  -316,  -108,  -316,  -316
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -161
static const yytype_int16 yytable[] =
{
      59,    84,   150,   124,    90,   147,   160,   232,   294,   148,
     160,   240,   243,   335,   287,    77,   344,   185,   102,   163,
     326,    99,    99,   118,    77,   329,   136,   137,   177,   178,
     150,   140,   136,   137,   319,   122,   123,   125,   365,   110,
     126,    76,   156,   111,   127,    59,   110,   157,   313,   360,
     111,   347,   375,   234,   152,   314,   241,   153,   238,   158,
     247,   129,   159,   377,   284,    87,   136,   137,   361,   306,
     171,   140,   326,    88,   382,   327,   328,   329,   289,   290,
     291,   168,   130,   131,    86,   133,   134,   169,   136,   137,
      93,    99,   214,   140,   369,   167,   165,   166,   186,   326,
     120,   121,   343,   150,   329,   149,   149,   370,   149,   149,
     190,   191,   192,   380,    99,    99,    99,   233,   195,   145,
     112,   233,   233,   113,   196,   145,    91,   112,    99,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   240,   229,   217,   154,
     225,    59,    99,   104,    99,   227,   143,   144,   231,   145,
     105,    59,   106,    59,   228,    59,    59,   317,   171,   242,
     244,   245,   246,   248,   215,    77,   141,   142,   143,   144,
     107,   145,   108,   258,   233,   218,   235,   219,   237,   109,
     220,   124,   259,   129,   221,   116,   117,   222,   136,   137,
     164,   153,   170,   140,   180,   181,   182,   183,   184,   171,
     174,   175,   176,   188,    59,   193,    77,   216,   230,   268,
     239,   249,   250,    99,   251,   269,   252,   253,    59,   254,
     286,   233,   255,   256,   260,   257,   261,   263,   275,   265,
      78,    79,    80,    81,    82,    83,   264,   266,   281,   233,
     276,   271,   311,   272,   273,   285,   277,   278,   282,    99,
     299,   298,   300,   302,   288,   304,   321,   305,   308,   323,
     309,   295,   310,   296,   332,    59,   338,   293,   340,   301,
     347,   363,   364,   303,   320,   372,   141,   142,   143,   144,
     233,   145,    59,    59,   328,   233,   267,   233,   297,   119,
     378,   358,   233,   283,   325,   103,   336,   359,   379,     0,
     373,   233,     0,     0,     0,   333,   312,     0,     0,     0,
       0,   337,   233,   286,   233,   334,     0,   342,   351,     0,
       0,   339,     0,     0,   341,     0,     0,   233,     0,    59,
     346,    59,     0,     0,   356,     0,    59,     0,     0,     0,
     355,     0,     0,     0,     0,    59,     0,   371,     0,     0,
       0,   366,   352,   368,   353,     0,    59,     0,    59,   357,
       0,     0,     0,  -151,     1,     0,     0,  -151,   367,     0,
       0,    59,     0,     0,     0,   381,     0,     0,     2,   374,
     224,   376,     0,     3,     4,    77,     0,     6,     0,     7,
       8,     9,     0,     0,   383,  -151,     0,     0,  -151,  -151,
    -151,     0,  -151,     0,     0,     0,     0,     0,     0,  -151,
       1,  -151,     0,  -151,  -151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,    77,     0,     6,     0,     7,     8,     9,     0,     0,
      23,  -151,     0,     0,  -151,  -151,  -151,     0,  -151,     0,
      78,    79,    80,    81,    82,    83,     1,  -151,     0,    33,
    -151,     0,    36,    37,     0,     0,  -151,    38,     0,  -151,
       2,     0,    94,     0,     0,     3,     4,    77,     0,     6,
       0,     7,     8,     9,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,     1,     0,     0,    33,     0,     0,    36,    37,
       0,     0,  -151,    38,     0,  -151,     2,     0,    94,     0,
       0,     3,     4,    77,     0,     6,     0,     7,     8,     9,
       0,     0,    23,  -151,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,     1,     0,
       0,    33,     0,     0,    36,    37,     0,     0,     0,    38,
       0,  -151,     2,     0,    94,     0,     0,     3,     4,    77,
       0,     6,     0,     7,     8,     9,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,     0,     0,     0,    33,     0,     0,
      36,    37,     0,     0,     0,    38,  -151,  -151,     0,     0,
      94,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    23,   140,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
       0,     0,     0,    33,     0,     0,    36,    37,     0,     0,
       0,    38,     0,   -88,     1,     0,    94,   -88,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,     2,   -51,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,     0,   -88,  -160,   -51,   -88,   -88,
     -88,  -160,   -88,    13,     0,    14,    15,     0,     0,     0,
       0,   -88,     0,  -160,   -88,    16,  -160,     0,   141,   142,
     143,   144,     0,   145,     0,     0,   172,     0,   173,     0,
       0,     0,    20,     0,    21,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   -51,   -51,   -88,    38,   -88,     1,
       0,     0,   -88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
     -88,  -160,     0,   -88,   -88,   -88,  -160,   -88,    13,     0,
      14,    15,     0,     0,     0,     0,   -88,     0,  -160,   -88,
      16,  -160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   -88,
       1,   -88,    38,   -88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
       0,   -88,  -160,     0,   -88,   -88,   -88,  -160,   -88,    13,
       0,    14,    15,     0,     0,     0,     0,   -88,     0,  -160,
     -88,    16,  -160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      21,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     -88,     1,   -88,    38,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,   -88,  -160,     0,     0,     0,     0,  -160,     0,
      13,     0,    14,    15,     0,     0,     0,     0,     0,     0,
    -160,     0,    16,  -160,     0,    17,     0,   -12,     0,    18,
       0,   -12,     0,     0,     0,     0,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   -88,     1,   149,    38,   -88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,     0,  -160,     0,     0,     0,     0,  -160,
       0,    13,     0,    14,    15,     0,     0,     0,     0,     0,
       0,  -160,     0,    16,  -160,     0,    17,     0,   -12,     0,
      18,     0,   -12,     0,     0,     0,     0,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,   -88,    38,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   140,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,   140,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,     0,     0,     0,     0,  -101,     1,     0,     0,
    -101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     0,
       6,     0,     7,     8,     9,     0,     0,     0,  -101,     0,
       0,  -101,  -101,  -101,     0,  -101,     0,     0,     0,     0,
       0,     0,     0,     0,  -101,     0,     0,  -101,     0,     0,
     141,   142,   143,   144,     0,   145,   307,     0,     0,     0,
     173,     0,   141,   142,   143,   144,     1,   145,     0,   232,
       0,     0,   173,     0,   141,   142,   143,   144,     0,   145,
       2,     0,     0,     0,   280,     3,     4,     5,     0,     6,
       0,     7,     8,     9,    10,    11,    12,   -88,  -160,  -101,
       0,     0,     0,  -160,     0,    13,     0,    14,    15,     0,
       0,     0,     0,     0,     0,  -160,     0,    16,  -160,     0,
      17,     0,   -12,     0,    18,     0,   -12,     0,     0,     0,
       0,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     1,   149,    38,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,   -88,  -160,
       0,   -88,   -88,   -88,  -160,     0,    13,     0,    14,    15,
       0,     0,     0,     0,     0,     0,  -160,     0,    16,  -160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    20,     0,    21,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     1,   149,
      38,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,    12,   -88,
    -160,     0,     0,     0,     0,  -160,     0,    13,     0,    14,
      15,     0,     0,     0,     0,   -88,     0,  -160,   -88,    16,
    -160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    20,     0,    21,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,     1,
     149,    38,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
     -88,  -160,     0,     0,     0,     0,  -160,   -88,    13,     0,
      14,    15,     0,     0,     0,     0,     0,     0,  -160,     0,
      16,  -160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     0,
       1,   149,    38,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
      12,   -88,  -160,     0,     0,     0,   -88,  -160,     0,    13,
       0,    14,    15,     0,     0,     0,     0,     0,     0,  -160,
       0,    16,  -160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     1,   149,    38,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,   236,  -160,     0,     0,     0,     0,  -160,     0,
      13,     0,    14,    15,     0,     0,     0,     0,     0,     0,
    -160,     0,    16,  -160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,     1,   149,    38,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -88,  -160,     0,     1,     0,     0,  -160,
       0,    13,     0,    14,    15,     0,     0,     0,     0,     0,
       2,  -160,     0,    16,  -160,     3,     4,    77,     0,     6,
       1,     7,     8,     9,     0,     0,     0,     0,    19,     0,
      20,     0,    21,     0,     2,     0,     0,    22,    23,     3,
       4,    77,     0,     6,     0,     7,     8,     9,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,   149,    38,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,     0,     0,
       0,    33,     0,     0,    36,    37,    23,     0,     0,    38,
     -99,     1,     0,     0,   -99,     0,    78,    79,    80,    81,
      82,    83,     0,     0,     0,    33,     0,     0,    36,    37,
       3,     4,     0,   226,     6,     0,     7,     8,     9,     0,
       0,     0,   -99,     0,     0,   -99,   -99,   -99,     0,   -99,
       0,     0,     0,     0,     0,     0,     0,     0,   -99,     0,
       0,   -99,   160,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,   140,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,   140,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,     0,     0,   -99,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   140,   160,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,   140,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,   149,   145,     0,   345,     0,     0,     0,     0,   141,
     142,   143,   144,     0,   145,     0,     0,   146,     0,     0,
       0,   141,   142,   143,   144,     0,   145,     0,     0,   172,
       0,     0,     0,   141,   142,   143,   144,     0,   145,     0,
     316,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,     0,   145,     0,   322,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   149,   145,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   145,   194,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   140,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   140,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,   140,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,     0,     0,     0,     0,     0,   270,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   354,
     140,     0,     0,     0,   141,   142,   143,   144,     0,   145,
     262,     0,     0,     0,     0,     0,   141,   142,   143,   144,
       0,   145,   292,     0,     0,     0,     0,     0,   141,   142,
     143,   144,     0,   145,   317,     0,     0,     0,     0,     0,
     141,   142,   143,   144,     0,   145,   350,     0,     0,     0,
       0,     0,   141,   142,   143,   144,     0,   145,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,     0,   145,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,   140,     0,   141,   142,   143,   144,     0,   145,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   145
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-316)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     2,    46,    38,    19,    45,     4,     4,   271,     4,
       4,   170,   171,   319,   265,    22,   331,    20,    23,    74,
      32,    22,    23,    33,    22,    37,    11,    12,    84,    85,
      74,    16,    11,    12,   297,    36,    37,    38,   353,    20,
      57,   108,    33,    24,    61,    45,    20,    38,    32,    32,
      24,    48,   367,   161,   101,    39,   170,   104,   166,    50,
     174,   104,    53,   369,   107,    20,    11,    12,    51,   105,
     106,    16,    32,    22,   380,    35,    36,    37,    80,    81,
      82,    91,     5,     6,   109,     8,     9,    92,    11,    12,
      72,    92,   147,    16,   357,   102,    89,    90,   101,    32,
      34,    35,    35,   147,    37,   103,   103,   358,   103,   103,
     115,   116,   117,   376,   115,   116,   117,   161,   128,   104,
     101,   165,   166,   104,   129,   104,   102,   101,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   305,   157,   153,   106,
     155,   151,   153,   104,   155,   156,   101,   102,   159,   104,
     104,   161,   104,   163,   157,   165,   166,   105,   106,   170,
     171,   172,   173,   174,   151,    22,    99,   100,   101,   102,
     104,   104,   104,   193,   228,    74,   163,    76,   165,   104,
      79,   226,   193,   104,    83,    31,    32,    86,    11,    12,
       0,   104,   106,    16,   105,   106,   107,   108,   109,   106,
     106,    78,    78,   106,   214,   106,    22,    20,    48,   224,
     102,   107,   107,   224,   105,   226,   105,   105,   228,   105,
     265,   275,   105,   105,   104,   106,   105,   214,   231,   104,
      87,    88,    89,    90,    91,    92,   105,   104,   249,   293,
      55,   228,   292,   107,   104,   260,    32,     4,    20,   260,
      55,   276,    32,   105,   265,   105,    67,   106,   105,    60,
     105,   272,   105,   274,    38,   275,   104,   270,    33,   280,
      48,   105,    32,   284,   299,    50,    99,   100,   101,   102,
     334,   104,   292,   293,    36,   339,   223,   341,   275,    33,
     370,   347,   346,   257,   305,    23,   321,   348,   374,    -1,
     364,   355,    -1,    -1,    -1,   316,   293,    -1,    -1,    -1,
      -1,   322,   366,   358,   368,   318,    -1,   328,   338,    -1,
      -1,   324,    -1,    -1,   327,    -1,    -1,   381,    -1,   339,
     333,   341,    -1,    -1,   345,    -1,   346,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,   355,    -1,   358,    -1,    -1,
      -1,   354,   339,   356,   341,    -1,   366,    -1,   368,   346,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,   355,    -1,
      -1,   381,    -1,    -1,    -1,   378,    -1,    -1,    15,   366,
      17,   368,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    -1,    -1,   381,    32,    -1,    -1,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    48,    -1,     4,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    -1,    -1,
      77,    32,    -1,    -1,    35,    36,    37,    -1,    39,    -1,
      87,    88,    89,    90,    91,    92,     1,    48,    -1,    96,
      51,    -1,    99,   100,    -1,    -1,   103,   104,    -1,   106,
      15,    -1,   109,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,     1,    -1,    -1,    96,    -1,    -1,    99,   100,
      -1,    -1,   103,   104,    -1,   106,    15,    -1,   109,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,     1,    -1,
      -1,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,
      -1,   106,    15,    -1,   109,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,   100,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    77,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,   100,    -1,    -1,
      -1,   104,    -1,     0,     1,    -1,   109,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    -1,    99,   100,
     101,   102,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       1,   103,   104,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     1,   103,   104,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    -1,    55,    -1,    57,    -1,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     1,   103,   104,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    -1,    55,    -1,    57,    -1,
      59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      24,    -1,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      99,   100,   101,   102,    -1,   104,   105,    -1,    -1,    -1,
     109,    -1,    99,   100,   101,   102,     1,   104,    -1,     4,
      -1,    -1,   109,    -1,    99,   100,   101,   102,    -1,   104,
      15,    -1,    -1,    -1,   109,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,   103,
      -1,    -1,    -1,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,    -1,    57,    -1,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,     1,   103,   104,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,     1,   103,
     104,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,     1,
     103,   104,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
       1,   103,   104,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,     1,   103,   104,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,     1,   103,   104,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,     1,    -1,    -1,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      15,    50,    -1,    52,    53,    20,    21,    22,    -1,    24,
       1,    26,    27,    28,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    15,    -1,    -1,    76,    77,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    96,    -1,    -1,    99,   100,    77,    -1,    -1,   104,
       0,     1,    -1,    -1,     4,    -1,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,   100,
      20,    21,    -1,   104,    24,    -1,    26,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,   103,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,   104,    -1,    -1,   107,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,   104,    -1,    -1,   107,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,   105,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    34,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    34,
      16,    -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,
     105,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,   105,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    99,   100,   101,   102,    -1,   104,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    30,    31,    40,    42,    43,    52,    55,    59,    67,
      69,    71,    76,    77,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   104,   115,
     119,   120,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   145,   146,   147,   148,
     149,   151,   152,   155,   156,   157,   158,   160,   163,   165,
     170,   172,   173,   174,   175,   176,   108,    22,    87,    88,
      89,    90,    91,    92,   127,   148,   109,    20,    22,   171,
     171,   102,   150,    72,   109,   121,   122,   123,   124,   127,
     153,   154,   154,   155,   104,   104,   104,   104,   104,   104,
      20,    24,   101,   104,   143,   144,   144,   144,   120,   125,
     119,   119,   127,   127,   123,   127,    57,    61,   169,   104,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    99,   100,   101,   102,   104,   107,   129,     4,   103,
     113,   114,   101,   104,   106,   117,    33,    38,    50,    53,
       4,   112,   113,   114,     0,   112,   112,   102,   120,   154,
     106,   106,   107,   109,   106,    78,    78,    84,    85,   118,
     118,   118,   118,   118,   118,    20,   101,   142,   106,   141,
     154,   154,   154,   106,   105,   120,   154,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   114,   138,    20,   154,    74,    76,
      79,    83,    86,   116,    17,   154,   104,   127,   112,   120,
      48,   127,     4,   113,   174,   138,    32,   138,   174,   102,
     121,   122,   127,   121,   127,   127,   127,   122,   127,   107,
     107,   105,   105,   105,   105,   105,   105,   106,   120,   127,
     104,   105,   105,   138,   105,   104,   104,   117,   154,   127,
      34,   138,   107,   104,   139,   112,    55,    32,     4,   111,
     109,   127,    20,   143,   107,   154,   123,   124,   127,    80,
      81,    82,   105,   112,   111,   127,   127,   138,   171,    55,
      32,   127,   105,   127,   105,   106,   105,   105,   105,   105,
     105,   129,   138,    32,    39,   162,   106,   105,   140,   111,
     171,    67,   106,    60,   168,   127,    32,    35,    36,    37,
     159,   161,    38,   127,   112,   162,   171,   127,   104,   112,
      33,   112,   127,    35,   159,   106,   112,    48,   166,   167,
     105,   120,   138,   138,    34,   112,   127,   138,   139,   167,
      32,    51,   164,   105,    32,   159,   112,   138,   112,   111,
     124,   127,    50,   169,   138,   159,   138,   162,   140,   161,
     111,   112,   162,   138
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 74 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 79 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
				update_pos((yyval));
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 85 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 90 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 95 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 100 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 106 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 117 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 124 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 132 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 139 "for90.y"
    {
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				ParseNode & dimen_slice = (yyvsp[(3) - (4)]);
				ParseNode attr = gen_variabledesc_from_dimenslice(dimen_slice);
				newnode.addchild(attr); // def slice
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 152 "for90.y"
    {
				/* define array like a(1) */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				ParseNode slice = ParseNode();
				ParseNode & exp_to = (yyvsp[(3) - (4)]);
				ParseNode & exp_from = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER, "1" }));

				slice.addchild(exp_from); // slice from 1
				slice.addchild(exp_to); // slice to

				ParseNode attr = gen_variabledesc_from_dimenslice(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				newnode.addchild(attr); // def slice

				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 170 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 177 "for90.y"
    {
				/* const value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 185 "for90.y"
    {
				/* static value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 194 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 199 "for90.y"
    {
				ParseNode & variable_elem = (yyvsp[(2) - (3)]);
				ParseNode & variable_desc = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				/* merge attrs */
				newnode.setattr(variable_elem.attr->clone());
				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 212 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 226 "for90.y"
    {
				int kind;
				sscanf((yyvsp[(3) - (3)]).to_string().c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 237 "for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf((yyvsp[(3) - (3)]).to_string().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 251 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).to_string() });// float number
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 256 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).to_string() });// int number
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 260 "for90.y"
    {
				// replace `'` with `"`
				std::string s = (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2);
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + s + "\"" }); // string
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 266 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 270 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 274 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).to_string();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 283 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).to_string() });// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 297 "for90.y"
    {
				/* arr[from : to] */
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				(yyval) = gen_slice(exp1, exp2);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 306 "for90.y"
    {
				/* arr[from : to : step] */
				ParseNode & exp1 = (yyvsp[(1) - (5)]);
				ParseNode & exp2 = (yyvsp[(3) - (5)]);
				ParseNode & exp3 = (yyvsp[(5) - (5)]);
				/* target code of slice depend on context */
				(yyval) = gen_slice(exp1, exp2, exp3);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 316 "for90.y"
    {
				ParseNode & lb = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				ParseNode & ub = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				/* target code of slice depend on context */
				(yyval) = gen_slice(lb, ub);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 325 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				/* array_builder is exp */
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 335 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				ParseNode newnode = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 343 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (3)]);
				ParseNode & argtable = (yyvsp[(1) - (3)]);
				(yyval) = gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 351 "for90.y"
    {
				/* 1d array */
				/* arr[from : to] */
				/* target code of slice depend on context */
				ParseNode & slice = (yyvsp[(1) - (1)]);
				// only 1 slice
				(yyval) = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 361 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ParseNode & slice = (yyvsp[(3) - (3)]);
				ParseNode & dimen_slice = (yyvsp[(1) - (3)]);
				(yyval) = gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 371 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ParseNode & exp = (yyvsp[(3) - (3)]);
				ParseNode & dimen_slice = (yyvsp[(1) - (3)]);
				(yyval) = gen_flattern(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 381 "for90.y"
    {
				ParseNode & slice = (yyvsp[(3) - (3)]);
				ParseNode & argtable = (yyvsp[(1) - (3)]);
				ParseNode newnode = ParseNode();
				switch (argtable.fs.CurrentTerm.token) {
					case TokenMeta::NT_ARGTABLE_PURE:
					//case TokenMeta::NT_DIMENSLICE:
					//case TokenMeta::NT_PARAMTABLE_PURE:
					//case TokenMeta::NT_PARAMTABLE_DIMENSLICE:
						newnode = gen_flattern(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
						break;
					default:
						print_error("Illegal dimen_slice", argtable);
				}
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 400 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode & callable_head = (yyvsp[(1) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				ParseNode newnode = gen_function_array(callable_head, argtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 410 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode & callable_head = (yyvsp[(1) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				ParseNode newnode = gen_function_array(callable_head, argtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 421 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 425 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 430 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 437 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 445 "for90.y"
    {
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s(%s)");
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 453 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				(yyval) = gen_exp(exp, op, "( %s )");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 461 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 469 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 477 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 485 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 493 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 501 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 508 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 515 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 523 "for90.y"
    {
				// xor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 532 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 540 "for90.y"
    {
				// nor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "!(%s ^ %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 549 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 557 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 565 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 572 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 580 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 588 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 596 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 604 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 610 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 615 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 621 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 627 "for90.y"
    {
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				(yyval) = gen_stmt((yyvsp[(1) - (1)]), "%s;");
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 637 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (1)]), "%s");
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 643 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 647 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 651 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 655 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 659 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 664 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 670 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 675 "for90.y"
    {
				(yyval) = gen_format((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 680 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Comments, "/*" + (yyvsp[(1) - (1)]).to_string() + "*/"});
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 687 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Comments, "nop();"});
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 692 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 708 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::META_ANY, "continue;"});
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 713 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::META_ANY, "break;"});
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 718 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(2) - (2)]).to_string() + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 724 "for90.y"
    {
				ParseNode & lit = (yyvsp[(2) - (2)]);
				(yyval) = gen_token(Term{ TokenMeta::META_ANY, "printf(" + lit.to_string() + ");\nsystem(\"pause\");\n" });
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 730 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::META_ANY, "system(\"pause\");\n" });
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 735 "for90.y"
    {
			ParseNode & lit = (yyvsp[(2) - (2)]);
			(yyval) = gen_token(Term{ TokenMeta::META_ANY, "printf(" + lit.to_string() + ");\nsystem(\"pause\");\n" });
			update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 741 "for90.y"
    {
			(yyval) = gen_token(Term{ TokenMeta::META_ANY, "system(\"pause\");\n" });
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 747 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 756 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 763 "for90.y"
    {
				ParseNode & label = (yyvsp[(1) - (2)]); // TokenMeta::Label
				ParseNode & stmt = (yyvsp[(2) - (2)]);
				if (stmt.child.size() > 0 && stmt.get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{
					log_format_index(label.to_string(), stmt);
					(yyval) = gen_token(Term{TokenMeta::Nop, ""}); // do not print format stmt
				}
				else {
					sprintf(codegen_buf, "%s\n%s", label.to_string().c_str(), stmt.to_string().c_str());
					ParseNode & newnode = gen_token(Term{ TokenMeta::NT_SUITE , string(codegen_buf) });
					newnode.addchild(label);
					newnode.addchild(stmt);
					(yyval) = newnode;
				}
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 781 "for90.y"
    {
				ParseNode & label = (yyvsp[(1) - (4)]); 
				ParseNode & stmt = (yyvsp[(2) - (4)]);
				ParseNode & suite = (yyvsp[(4) - (4)]);				
				if (stmt.child.size() > 0 && stmt.get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
				{
					log_format_index(label.to_string(), stmt);
					(yyval) = suite; // do not print format stmt
				}
				else {
					sprintf(codegen_buf, "%s\n%s\n%s", label.to_string().c_str(), stmt.to_string().c_str(), suite.to_string().c_str());
					ParseNode & newnode = gen_token(Term{ TokenMeta::NT_SUITE , string(codegen_buf) });
					newnode.addchild(label);
					newnode.addchild(stmt);
					for (int i = 0; i < suite.child.size(); i++)
					{
						newnode.addchild(suite.get(i));
					}
					(yyval) = newnode;
				}
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 804 "for90.y"
    {
				ParseNode & stmt = (yyvsp[(1) - (1)]); // TokenMeta::NT_LABEL
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, stmt);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 810 "for90.y"
    {
				ParseNode & stmt = (yyvsp[(1) - (3)]); 
				ParseNode & suite = (yyvsp[(3) - (3)]);
				(yyval) = gen_flattern(stmt, suite, "%s\n%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 817 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 822 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 834 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 838 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).to_string() };
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 842 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 846 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).to_string());
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 851 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 858 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" });
				ParseNode & _optional_device = (yyvsp[(2) - (5)]);
				ParseNode & _optional_formatter = (yyvsp[(4) - (5)]);
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode.addchild(_optional_device); // _optional_device
				newnode.addchild(_optional_formatter); // _optional_formatter
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 869 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" });
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				ParseNode & _optional_formatter = (yyvsp[(1) - (2)]);
				/* target code of io_info depend on context */
				newnode.addchild(_optional_device); // _optional_device
				newnode.addchild(_optional_formatter); // _optional_formatter
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 883 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 891 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 900 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 908 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 913 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 918 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 923 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 928 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 933 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 939 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 945 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 950 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 955 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 960 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 965 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).to_string().c_str(), "%d", &len);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 973 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 978 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 984 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 989 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 995 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1002 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1010 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1020 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (3)]);
				ParseNode & variable_desc = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1030 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = gen_token(Term {TokenMeta::Implicit_Def, ""});
				ParseNode variable_desc = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(variable_desc, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				ParseNode & paramtable = (yyvsp[(2) - (2)]);
				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1042 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1049 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1057 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(promote_exp_to_keyvalue(paramtable_elem), paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1065 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1073 "for90.y"
    {
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1085 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				/*
				R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
				R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
				■ scalar - int - expr[, scalar - int - expr]
				*/
				const ParseNode & exp = (yyvsp[(2) - (9)]);
				const ParseNode & index = (yyvsp[(4) - (9)]);
				const ParseNode & from = (yyvsp[(6) - (9)]);
				const ParseNode & to = (yyvsp[(8) - (9)]);
				(yyval) = gen_hiddendo(exp, index, from, to);
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1101 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1108 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1116 "for90.y"
    {
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				if (array_builder_elem.fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
				{
					(yyval) = array_builder_elem;
				}
				else {
					(yyval) = gen_promote("%s", TokenMeta::NT_ARRAYBUILDER, array_builder_elem); // array_builder_elem
				}
				gen_arraybuilder_str((yyval));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1139 "for90.y"
    {
				ParseNode & exp = (yyvsp[(4) - (6)]);
				ParseNode & stmt_true = (yyvsp[(6) - (6)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1146 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (7)]);
				ParseNode & suite_true = (yyvsp[(6) - (7)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1153 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (10)]);
				ParseNode & suite_true = (yyvsp[(6) - (10)]); 
				ParseNode & suite_else = (yyvsp[(9) - (10)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1161 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (8)]);
				ParseNode & suite_true = (yyvsp[(6) - (8)]);
				ParseNode & elseif = (yyvsp[(7) - (8)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1169 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (11)]);
				ParseNode & suite_true = (yyvsp[(6) - (11)]);
				ParseNode & elseif = (yyvsp[(7) - (11)]);
				ParseNode & suite_else = (yyvsp[(10) - (11)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1179 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1187 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1199 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(5) - (6)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1205 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(3) - (11)]);
				ParseNode & exp_from = (yyvsp[(5) - (11)]);
				ParseNode & exp_to = (yyvsp[(7) - (11)]);
				ParseNode & step = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = (yyvsp[(9) - (11)]); 
				(yyval) = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1215 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(3) - (13)]);
				ParseNode & exp1 = (yyvsp[(5) - (13)]);
				ParseNode & exp2 = (yyvsp[(7) - (13)]);
				ParseNode & exp3 = (yyvsp[(9) - (13)]);
				ParseNode & suite = (yyvsp[(11) - (13)]);
				(yyval) = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos((yyval), (yyvsp[(1) - (13)]), (yyvsp[(11) - (13)]));
			}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1225 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (7)]);
				ParseNode & suite = (yyvsp[(5) - (7)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(6) - (7)]));
			}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1236 "for90.y"
    {
				ParseNode & select = (yyvsp[(2) - (9)]);
				ParseNode & exp = (yyvsp[(5) - (9)]);
				ParseNode & case_stmt = (yyvsp[(8) - (9)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1244 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1252 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1260 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem, false /* add to the front of the vector */); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1270 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1275 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1285 "for90.y"
    {
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode & variable_function = (yyvsp[(3) - (11)]); // function name
				/* enumerate paramtable */
				ParseNode & paramtable = (yyvsp[(5) - (11)]);
				ParseNode & variable_result = (yyvsp[(7) - (11)]); // result variable
				ParseNode & suite = (yyvsp[(9) - (11)]);

				(yyval) = gen_function(variable_function, paramtable, variable_result, suite);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1301 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (7)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1307 "for90.y"
    {
				(yyval) = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1318 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1329 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (1)])); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).to_string().c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1338 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (3)])); // wrapper
				newnode.addchild((yyvsp[(3) - (3)])); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (3)]).to_string().c_str(), (yyvsp[(3) - (3)]).to_string().c_str());
				newnode = flattern_bin_right(newnode);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1350 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (8)]));
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1356 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 4064 "for90.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 1361 "for90.y"

//extern "C" int yylex();

void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), yylval);
}

void update_pos(YYSTYPE & current) {
	if (current.child.size() == 0) {
		/* do nothing */
		current.fs.parse_pos = 0;
		current.fs.parse_line = 0;
		current.fs.parse_len = 0;
		current.fs.line_pos = 0;
	}
	else if (current.child.size() == 1) {
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = current.get(0).fs.parse_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.child.size(); i++)
		{
			tot_len += current.get(i).fs.parse_len;
		}
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = tot_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
}
void update_pos(YYSTYPE & current, YYSTYPE & start, YYSTYPE & end) {
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

int parse(std::string code) {
#ifdef USE_YACC
	set_buff(code);
	yyparse();
	release_buff();
#endif
	return 0;
}
