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
#line 1 "for90.y"

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
// static is necessary, or will cause lnk
static char codegen_buf[MAX_CODE_LENGTH];
using namespace std;

/* Line 371 of yacc.c  */
#line 95 "for90.tab.cpp"

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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 250 "for90.tab.cpp"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNRULES -- Number of states.  */
#define YYNSTATES  361

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      99,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,    97,    93,    91,    98,    92,     2,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   100,    95,
       2,    90,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    11,    16,    21,
      26,    31,    36,    38,    40,    44,    48,    51,    55,    56,
      58,    60,    62,    64,    66,    68,    71,    73,    75,    77,
      81,    87,    89,    91,    95,    97,   101,   106,   108,   111,
     113,   118,   122,   126,   130,   134,   138,   142,   145,   148,
     152,   156,   160,   164,   168,   172,   175,   179,   183,   187,
     191,   193,   195,   197,   199,   202,   204,   205,   208,   211,
     213,   215,   217,   219,   221,   223,   225,   228,   231,   234,
     237,   239,   241,   243,   246,   249,   253,   258,   262,   264,
     267,   269,   272,   273,   275,   276,   278,   280,   281,   283,
     285,   287,   289,   291,   297,   300,   304,   308,   312,   314,
     316,   318,   320,   322,   324,   329,   334,   339,   344,   349,
     354,   358,   360,   365,   367,   371,   375,   377,   379,   381,
     385,   386,   394,   398,   402,   406,   408,   409,   411,   415,
     418,   420,   428,   439,   448,   460,   465,   471,   478,   481,
     483,   489,   500,   513,   520,   523,   525,   535,   542,   544,
     547,   552,   553,   555,   557,   570,   572,   573,   582,   584,
     586,   588,   591,   601,   603
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     162,     0,    -1,     4,    -1,    95,    -1,    -1,    54,    -1,
      -1,    73,    96,    74,    97,    -1,    73,    96,    75,    97,
      -1,    73,    96,    76,    97,    -1,    70,    96,   111,    97,
      -1,    70,    96,   114,    97,    -1,    77,    -1,    67,    -1,
      79,    90,    20,    -1,    78,    90,   114,    -1,    98,   104,
      -1,    98,   104,   106,    -1,    -1,    21,    -1,    20,    -1,
      24,    -1,    27,    -1,    28,    -1,    26,    -1,     1,    99,
      -1,    22,    -1,   108,    -1,   134,    -1,   114,   100,   114,
      -1,   114,   100,   114,   100,   114,    -1,   100,    -1,   110,
      -1,   110,    98,   111,    -1,   114,    -1,   114,    98,   139,
      -1,   109,    96,   139,    97,    -1,   112,    -1,    89,   112,
      -1,   113,    -1,   114,    96,   114,    97,    -1,    96,   114,
      97,    -1,   114,    91,   114,    -1,   114,    92,   114,    -1,
     114,    93,   114,    -1,   114,    94,   114,    -1,   114,    16,
     114,    -1,    92,   114,    -1,    91,   114,    -1,   114,    10,
     114,    -1,   114,    11,   114,    -1,   114,     7,   114,    -1,
     114,    12,   114,    -1,   114,    13,   114,    -1,   114,    14,
     114,    -1,    15,   114,    -1,   114,     5,   114,    -1,   114,
       6,   114,    -1,   114,     8,   114,    -1,   114,     9,   114,
      -1,   141,    -1,   107,    -1,   109,    -1,   102,    -1,    95,
     102,    -1,    95,    -1,    -1,   114,   115,    -1,   136,   115,
      -1,   120,    -1,   118,    -1,   119,    -1,   123,    -1,   122,
      -1,   121,    -1,   161,    -1,   116,     4,    -1,   131,   115,
      -1,   132,   115,    -1,   133,   115,    -1,   146,    -1,   149,
      -1,   151,    -1,    37,   115,    -1,    38,   115,    -1,    47,
      20,   115,    -1,   114,    90,   114,   115,    -1,    64,    65,
     102,    -1,   117,    -1,   117,   124,    -1,   161,    -1,   161,
     124,    -1,    -1,    96,    -1,    -1,    97,    -1,    98,    -1,
      -1,    93,    -1,    20,    -1,    93,    -1,    20,    -1,    24,
      -1,    96,   128,    98,   129,    97,    -1,   129,   127,    -1,
      86,   130,   139,    -1,    88,   130,   139,    -1,    87,   130,
     139,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    80,    96,   105,    97,    -1,    81,
      96,   105,    97,    -1,    82,    96,   105,    97,    -1,    83,
      96,   105,    97,    -1,    84,    96,   105,    97,    -1,    85,
      96,   105,    97,    -1,    85,    93,    20,    -1,   134,    -1,
     135,   106,    17,   139,    -1,   108,    -1,   108,    90,   114,
      -1,   108,    90,   144,    -1,   137,    -1,   111,    -1,   138,
      -1,   138,    98,   139,    -1,    -1,   114,    98,   108,    90,
     114,    98,   114,    -1,    96,   140,    97,    -1,    71,   139,
      72,    -1,    71,   140,    72,    -1,    31,    -1,    -1,   142,
      -1,   142,    98,   144,    -1,    29,    30,    -1,    34,    -1,
      30,   114,    31,   102,   124,   145,   102,    -1,    30,   114,
      31,   102,   124,    32,   102,   124,   145,   102,    -1,    30,
     114,    31,   102,   124,   147,   145,   102,    -1,    30,   114,
      31,   102,   124,   147,    32,   102,   124,   145,   102,    -1,
      30,   114,   143,   117,    -1,    33,   114,    31,   102,   124,
      -1,    33,   114,    31,   102,   124,   147,    -1,    29,    35,
      -1,    36,    -1,    35,   102,   124,   148,   102,    -1,    35,
     108,    90,   114,    98,   114,   102,   124,   148,   102,    -1,
      35,   108,    90,   114,    98,   114,    98,   114,   102,   124,
     148,   102,    -1,    48,   114,   102,   124,   148,   102,    -1,
      29,    45,    -1,    46,    -1,    45,    43,   125,   114,   126,
     102,   153,   150,   102,    -1,    43,   125,   111,   126,   102,
     124,    -1,   152,    -1,   152,   153,    -1,    55,    96,   108,
      97,    -1,    -1,    52,    -1,    56,    -1,   103,   155,   108,
      96,   139,    97,   154,   102,   124,    29,   155,   102,    -1,
      22,    -1,    -1,    50,   157,   102,   124,    29,    50,   157,
     102,    -1,   156,    -1,   158,    -1,   159,    -1,   159,   160,
      -1,    62,   157,   102,   160,   102,    29,    62,   157,   102,
      -1,   160,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   117,   136,   143,   152,   163,   177,   182,   196,   205,
     210,   214,   219,   223,   227,   234,   237,   244,   250,   257,
     266,   276,   286,   296,   307,   314,   324,   334,   338,   343,
     350,   358,   366,   374,   382,   390,   398,   406,   413,   420,
     428,   436,   444,   452,   460,   468,   475,   483,   491,   499,
     507,   513,   517,   538,   539,   541,   546,   550,   561,   567,
     571,   575,   579,   583,   588,   593,   597,   604,   605,   607,
     609,   610,   611,   613,   614,   615,   621,   630,   637,   642,
     647,   652,   660,   661,   662,   663,   664,   665,   666,   670,
     674,   678,   682,   689,   700,   714,   722,   731,   739,   744,
     749,   754,   759,   764,   770,   777,   782,   787,   792,   797,
     806,   811,   814,   825,   833,   840,   849,   852,   856,   862,
     870,   877,   889,   897,   905,   915,   916,   918,   923,   930,
     931,   933,   942,   951,   960,   970,   977,   985,   994,   995,
     997,  1003,  1013,  1023,  1031,  1032,  1034,  1042,  1050,  1058,
    1069,  1075,  1081,  1082,  1084,  1097,  1098,  1100,  1111,  1116,
    1122,  1131,  1143,  1152,  1156
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "YY_REQ_MORE", "YY_CRLF", "YY_GT",
  "YY_GE", "YY_EQ", "YY_LE", "YY_LT", "YY_NEQ", "YY_NEQV", "YY_EQV",
  "YY_ANDAND", "YY_OROR", "YY_NOT", "YY_POWER", "YY_DOUBLECOLON", "YY_NEG",
  "YY_POS", "YY_INTEGER", "YY_FLOAT", "YY_WORD", "YY_OPERATOR",
  "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX", "YY_TRUE", "YY_FALSE", "YY_END",
  "YY_IF", "YY_THEN", "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO",
  "YY_ENDDO", "YY_CONTINUE", "YY_BREAK", "YY_WHILE", "YY_ENDWHILE",
  "YY_WHERE", "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE", "YY_SELECT",
  "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT", "YY_PROGRAM",
  "YY_ENDPROGRAM", "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE",
  "YY_RESULT", "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE",
  "YY_ENDMODULE", "YY_BLOCK", "YY_ENDBLOCK", "YY_INTERFACE",
  "YY_ENDINTERFACE", "YY_IMPLICIT", "YY_NONE", "YY_USE", "YY_PARAMETER",
  "YY_FORMAT", "YY_ENTRY", "YY_DIMENSION", "YY_ARRAYINITIAL_START",
  "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT",
  "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_INTEGER_T", "YY_FLOAT_T",
  "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T", "YY_CHARACTER_T", "YY_WRITE",
  "YY_READ", "YY_PRINT", "YY_CALL", "'='", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "','", "'\\n'", "':'", "$accept", "crlf",
  "dummy_function_iden", "variable_desc_elem", "typecast_spec",
  "variable_desc", "literal", "variable", "callable_head", "slice",
  "dimen_slice", "function_array_body", "function_array", "exp",
  "_crlf_semicolon", "semicolon", "stmt", "output_stmt", "input_stmt",
  "compound_stmt", "jump_stmt", "let_stmt", "dummy_stmt", "suite",
  "_optional_lbrace", "_optional_rbrace", "_optional_comma",
  "_optional_device", "_optional_formatter", "io_info", "write", "print",
  "read", "type_nospec", "type_spec", "var_def", "keyvalue",
  "paramtable_elem", "paramtable", "_generate_stmt", "hidden_do",
  "array_builder_elem", "_optional_then", "array_builder", "_yy_endif",
  "if_stmt", "elseif_stmt", "_yy_enddo", "do_stmt", "_yy_endselect",
  "select_stmt", "case_stmt_elem", "case_stmt", "_optional_result",
  "_optional_function", "function_decl", "_optional_name", "program",
  "wrapper", "wrappers", "interface_decl", "fortran_program", YY_NULL
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
      61,    43,    45,    42,    47,    59,    40,    41,    44,    10,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   102,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     110,   110,   111,   111,   111,   111,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     120,   120,   120,   121,   121,   121,   122,   123,   124,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   130,   130,   131,   132,   133,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   137,   137,   137,   138,   138,   139,   139,
     139,   140,   141,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   149,   150,   150,   151,   152,   153,   153,
     154,   154,   155,   155,   156,   157,   157,   158,   159,   159,
     160,   160,   161,   162,   162
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     0,     4,     4,     4,
       4,     4,     1,     1,     3,     3,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     3,
       5,     1,     1,     3,     1,     3,     4,     1,     2,     1,
       4,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     2,     2,     3,     4,     3,     1,     2,
       1,     2,     0,     1,     0,     1,     1,     0,     1,     1,
       1,     1,     1,     5,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       3,     1,     4,     1,     3,     3,     1,     1,     1,     3,
       0,     7,     3,     3,     3,     1,     0,     1,     3,     2,
       1,     7,    10,     8,    11,     4,     5,     6,     2,     1,
       5,    10,    12,     6,     2,     1,     9,     6,     1,     2,
       4,     0,     1,     1,    12,     1,     0,     8,     1,     1,
       1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,   166,     5,     0,   168,   169,   170,   173,     0,   165,
       4,   162,   163,     0,   171,     1,     2,     3,     0,    26,
       0,     0,     0,    20,    19,    21,    24,    22,    23,     0,
       4,     4,     4,     0,     0,     0,   166,     0,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
      65,     0,    61,    27,    62,    37,    39,     4,     0,     0,
      70,    71,    69,    74,    73,    72,     0,     4,     4,     4,
      28,    18,     4,    60,    80,    81,    82,     0,     0,    25,
     108,   109,   110,   111,   112,   113,    55,    28,   136,     0,
       0,     3,    63,    83,    84,    92,     4,     4,     4,     4,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   100,
       0,    97,     0,     0,     0,     0,    38,    48,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      76,    89,     0,    77,    78,    79,     0,     0,    68,    91,
      31,    27,    32,   127,    34,   126,   128,     0,     4,     0,
       0,     0,    64,    93,     0,    85,     0,     6,    87,     0,
       0,     0,     0,     0,     0,     0,   120,     0,    99,    98,
       0,    96,   104,   105,   107,   106,    41,     0,   132,     0,
      56,    57,    51,    58,    59,    49,    50,    52,    53,    54,
      46,     4,    42,    43,    44,    45,     0,   166,    13,     0,
       0,    12,    16,     0,     0,     0,     0,     0,     0,   161,
       0,   145,    75,     0,   149,     4,     0,    94,     0,     4,
       0,     0,   114,   115,   116,   117,   118,   119,     0,     0,
      36,    86,    40,     4,     0,     0,    17,   122,     0,   124,
     137,   125,    33,    35,    29,   129,     0,     4,     0,   148,
     150,     0,    95,     4,     4,     0,    15,    14,     0,     0,
     167,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     4,     0,   140,     4,     0,     4,
       0,   153,     0,   103,     0,    10,    11,     7,     8,     9,
       0,   133,   134,   138,    30,     0,     0,   139,     0,     0,
     141,     4,     4,     0,     0,    92,   158,     0,   166,     0,
      27,   160,     0,     0,     4,     0,   143,     4,     0,     0,
     159,     0,   155,     4,     4,   131,     0,     4,     4,     0,
       0,     0,     4,    94,   154,   156,   172,   124,   164,   142,
     146,     4,     0,   151,     4,   147,   144,     4,     0,   152,
     157
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,     3,   212,   171,   147,    52,    53,    54,   152,
     153,    55,    56,    57,    93,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   164,   263,   182,   180,   111,   112,
      67,    68,    69,    87,    71,    72,   155,   156,   253,   120,
      73,   250,   159,   251,   287,    74,   288,   225,    75,   333,
      76,   316,   317,   257,    13,     4,    10,     5,     6,     7,
      77,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -210
static const yytype_int16 yypact[] =
{
     167,    -1,  -210,    44,  -210,  -210,     7,  -210,    12,  -210,
       2,  -210,  -210,     1,  -210,  -210,  -210,  -210,   866,  -210,
     -64,   -55,   914,  -210,  -210,  -210,  -210,  -210,  -210,   914,
       0,     4,     4,    19,    55,   914,    -1,    25,   -32,    28,
      37,    41,    53,    46,    36,    36,    36,   154,   914,   914,
    -210,   914,  -210,  -210,    70,  -210,  -210,  1056,   153,   688,
    -210,  -210,  -210,  -210,  -210,  -210,    69,     4,     4,     4,
      32,    73,     4,  -210,  -210,  -210,  -210,   777,   558,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,    40,  -210,  1198,   866,
      87,     2,  -210,  -210,  -210,    96,     4,  1069,     2,     2,
     -25,   -25,   -25,   -25,   -25,   179,   -25,  -210,  -210,  -210,
      -9,   113,   433,   433,   433,    70,  -210,    67,    67,  1019,
     116,   558,   914,   914,   914,   914,   914,   914,   914,   914,
     914,   914,   914,   914,   914,   914,   914,   914,   914,  -210,
    -210,  -210,   164,  -210,  -210,  -210,   -43,   201,  -210,  -210,
    -210,   130,   124,  -210,   496,  -210,   125,   133,     2,   866,
     -11,   914,  -210,  -210,   914,  -210,   866,    81,  -210,   150,
     169,   135,   160,   165,   166,   173,  -210,   185,  -210,  -210,
     178,  -210,  -210,  -210,  -210,  -210,  -210,     1,  -210,   187,
      67,    67,  1318,    67,    67,  1318,  1226,  1226,    60,   196,
      40,  1162,   162,   162,    26,    26,  1174,    -1,  -210,   168,
     189,  -210,    73,   433,   897,   602,   344,   914,   344,   231,
     866,  -210,  -210,   256,  -210,     2,  1031,  1186,   -11,     2,
     914,   275,  -210,  -210,  -210,  -210,  -210,  -210,    -7,   206,
    -210,  -210,  -210,     2,   602,   176,  -210,  -210,   580,  1226,
     199,  -210,  -210,  -210,   751,  -210,   202,     2,   136,  -210,
    -210,   914,  -210,     2,     2,   271,  1226,  -210,   208,   914,
    -210,   209,   175,   210,   211,   214,   735,   240,   243,   232,
     914,     1,   866,   288,     2,   914,  -210,     2,    48,  1007,
     276,  -210,   258,  -210,  1043,  -210,  -210,  -210,  -210,  -210,
     472,  -210,  -210,  -210,  1226,   225,   296,  -210,   866,  1210,
    -210,     2,     2,   914,   866,    96,   276,   -13,    -1,   914,
     236,  -210,    44,    94,     2,   866,  -210,  1069,   -11,   602,
    -210,   284,  -210,     2,     2,  1226,   897,     2,     2,   866,
      94,   866,     2,   233,  -210,  -210,  -210,  1043,  -210,  -210,
     298,     2,   -11,  -210,     2,  -210,  -210,     2,   866,  -210,
    -210
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,   -10,  -210,  -210,   142,   121,  -210,    13,   287,  -210,
    -208,   289,  -210,   -20,   -22,  -210,   180,  -210,  -210,  -210,
    -210,  -210,  -210,    61,    23,     3,  -210,  -210,   102,   101,
    -210,  -210,  -210,    -4,  -210,  -210,  -210,  -210,   -73,   103,
    -210,  -210,  -210,    63,   -98,  -210,     5,  -209,  -210,  -210,
    -210,  -210,    33,  -210,    30,  -210,   -35,  -210,  -210,    -3,
     191,  -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -175
static const yytype_int16 yytable[] =
{
      18,    98,    86,    14,    16,   157,    16,   252,    16,    88,
      94,   178,    15,   107,    70,    97,   331,   108,   223,   264,
      89,     9,    19,    19,   208,   224,    20,   209,   117,   118,
     210,   119,    78,   332,   211,   139,   271,   128,   129,   183,
     184,   185,   132,    90,    79,   143,   144,   145,   189,  -121,
     148,   128,   129,   169,   170,    70,   107,     1,   154,    -6,
     108,     2,    95,    -6,   100,   122,   123,   124,   125,   126,
     127,   128,   129,    70,   165,    96,   132,   283,   128,   129,
     311,   162,   286,   132,   179,    70,   109,   166,   167,   168,
      99,   151,   154,   154,   154,    17,    11,    17,   142,    91,
      12,   154,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   342,
     141,   343,   138,   283,   101,   151,   151,   151,   286,   109,
    -121,     1,   110,   102,   151,     2,   138,   103,   149,   105,
     247,   226,   106,   357,   227,   255,   113,   114,   220,   104,
     160,   134,   135,   136,   137,    70,   138,   140,   134,   135,
     136,   137,    70,   138,   229,   283,   121,  -174,   284,   285,
     286,   146,   243,   128,   129,   277,    19,   161,   132,   241,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     312,   132,   163,   154,   249,   154,   154,   254,   154,   176,
     239,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     266,   181,   132,   188,   207,   260,    70,     1,   213,   265,
     214,     2,   215,   218,   272,   338,   151,   228,   276,   151,
     219,   151,   232,   270,    80,    81,    82,    83,    84,    85,
     230,   289,   351,   172,   173,   174,   175,   282,   177,   294,
     273,   274,   275,   290,   291,   136,   137,   233,   138,   231,
     304,   151,   234,   235,   244,   309,   134,   135,   136,   137,
     236,   138,   296,   216,   308,   217,   238,   310,    70,   314,
     154,   258,   237,   334,   240,   245,   256,   134,   135,   136,
     137,   259,   138,   327,   305,   267,   269,   279,   281,   335,
     292,   325,   326,   248,    70,   293,   295,   297,   298,   154,
      70,   299,   301,   320,   339,   302,   347,   341,   307,   315,
     318,    70,   321,   345,   346,   322,   336,   348,   349,   344,
     262,   285,   353,   246,   115,    70,   116,    70,   329,   221,
     268,   356,   303,   306,   358,    21,   354,   359,  -130,   330,
     222,   278,   337,     0,    70,   355,     0,     0,     0,    22,
       0,     0,     0,     0,    23,    24,    19,     0,    25,   323,
      26,    27,    28,  -130,  -130,   328,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,     0,     0,   340,  -130,     0,  -130,
    -130,  -130,  -130,     0,     0,     0,     0,     0,     0,     0,
     350,     0,   352,     0,     0,     0,  -130,     0,  -130,     0,
       0,     0,     0,     0,     0,     0,  -130,     0,     0,   360,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
    -130,  -130,  -130,    47,    21,    48,    49,  -130,     0,  -130,
      51,  -130,  -130,     0,   150,     0,     0,     0,    22,     0,
       0,     0,     0,    23,    24,    19,     0,    25,     0,    26,
      27,    28,  -130,  -130,     0,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,     0,    21,     0,     0,  -130,     0,  -130,  -130,
    -130,  -130,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,    23,    24,    19,  -130,    25,  -130,    26,    27,
      28,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,    80,    81,    82,    83,    84,    85,  -130,
    -130,  -130,    47,     0,    48,    49,     0,     0,  -130,    51,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -130,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,     0,    21,
       0,    47,     0,    48,    49,     0,     0,     0,    51,     0,
    -130,     0,   150,    22,     0,     0,     0,     0,    23,    24,
      19,    21,    25,     0,    26,    27,    28,   134,   135,   136,
     137,     0,   138,     0,   216,    22,   217,     0,     0,     0,
      23,    24,    19,    21,    25,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,    23,    24,    19,     0,    25,     0,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    47,     0,    48,
      49,     0,  -130,     0,    51,  -130,     0,     0,   150,     0,
      80,    81,    82,    83,    84,    85,     0,     0,     0,    47,
       0,    48,    49,     0,     0,     0,    51,     0,     0,     0,
     150,     0,    80,    81,    82,    83,    84,    85,     0,    21,
       0,    47,   -66,    48,    49,     0,     0,     0,    51,     0,
       0,     0,   150,    22,     0,     0,     0,     0,    23,    24,
      19,     0,    25,     0,    26,    27,    28,   -88,    29,     0,
     -88,   -88,   -88,    30,   -88,    31,    32,     0,     0,     0,
       0,   -88,     0,    33,   -88,    34,    35,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      36,   132,    37,     0,     0,     0,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   132,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    21,    48,
      49,   -66,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,    23,    24,    19,
       0,    25,     0,    26,    27,    28,   -75,    29,     0,   -75,
     -75,   -75,    30,   -75,    31,    32,     0,     0,     0,     0,
     -75,     0,    33,   -75,    34,    35,   134,   135,   136,   137,
       0,   138,     0,   300,     0,   217,     0,     0,     0,    36,
       0,    37,   134,   135,   136,   137,     0,   138,     0,     0,
       0,   280,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    21,    48,    49,
     -66,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,    23,    24,    19,     0,
      25,     0,    26,    27,    28,     0,    29,     0,    21,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,    33,    22,    34,    35,    21,     0,    23,    24,    19,
       0,    25,     0,    26,    27,    28,     0,     0,    36,    22,
      37,     0,     0,     0,    23,    24,    19,     0,    25,     0,
      26,    27,    28,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,     0,
       0,    50,    51,     0,     0,     0,     0,     0,   248,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,     0,     0,     0,    47,     0,    48,    49,
       0,     0,     0,    51,    80,    81,    82,    83,    84,    85,
       0,     0,     0,    47,     0,    48,    49,     0,     0,     0,
      51,    16,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,   132,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   132,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   132,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
      16,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,    16,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,    17,   138,     0,   313,     0,     0,     0,     0,
     134,   135,   136,   137,     0,   138,   186,   187,     0,     0,
       0,     0,   134,   135,   136,   137,     0,   138,     0,   261,
       0,     0,     0,     0,   134,   135,   136,   137,     0,   138,
       0,   319,     0,     0,     0,     0,   133,   134,   135,   136,
     137,    91,   138,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,    17,   138,    16,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,   132,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
     132,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,   132,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,   132,     0,     0,   158,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   324,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,    91,   138,     0,
       0,     0,     0,     0,     0,   134,   135,   136,   137,     0,
     138,   242,     0,     0,     0,     0,     0,   134,   135,   136,
     137,     0,   138,   262,     0,     0,     0,     0,     0,   134,
     135,   136,   137,     0,   138,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,     0,   138,   122,   123,     0,   125,   126,     0,   128,
     129,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   136,   137,     0,   138
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-210)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,    36,    22,     6,     4,    78,     4,   215,     4,    29,
      32,    20,     0,    20,    18,    35,    29,    24,    29,   228,
      30,    22,    22,    22,    67,    36,    13,    70,    48,    49,
      73,    51,    96,    46,    77,    57,   244,    11,    12,   112,
     113,   114,    16,    30,    99,    67,    68,    69,   121,    17,
      72,    11,    12,    78,    79,    59,    20,    50,    78,    52,
      24,    54,    43,    56,    96,     5,     6,     7,     8,     9,
      10,    11,    12,    77,    96,    20,    16,    29,    11,    12,
      32,    91,    34,    16,    93,    89,    93,    97,    98,    99,
      65,    78,   112,   113,   114,    95,    52,    95,    29,    95,
      56,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   328,
      59,   329,    96,    29,    96,   112,   113,   114,    34,    93,
      98,    50,    96,    96,   121,    54,    96,    96,    77,    93,
     213,   161,    96,   352,   164,   218,    45,    46,   158,    96,
      89,    91,    92,    93,    94,   159,    96,     4,    91,    92,
      93,    94,   166,    96,   167,    29,    96,     0,    32,    33,
      34,    98,   207,    11,    12,   248,    22,    90,    16,   201,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     288,    16,    96,   213,   214,   215,   216,   217,   218,    20,
     187,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     230,    98,    16,    97,    50,   225,   220,    50,    17,   229,
      90,    54,    98,    98,   244,   323,   213,   166,   248,   216,
      97,   218,    97,   243,    80,    81,    82,    83,    84,    85,
      90,   261,   340,   101,   102,   103,   104,   257,   106,   269,
      74,    75,    76,   263,   264,    93,    94,    97,    96,    90,
     280,   248,    97,    97,    96,   285,    91,    92,    93,    94,
      97,    96,    97,    98,   284,   100,    98,   287,   282,   289,
     300,   220,    97,   318,    97,    96,    55,    91,    92,    93,
      94,    35,    96,   313,   281,    20,    90,    98,    96,   319,
      29,   311,   312,    71,   308,    97,    97,    97,    97,   329,
     314,    97,    72,   300,   324,    72,   336,   327,    30,    43,
      62,   325,    97,   333,   334,    29,    90,   337,   338,    45,
      97,    33,   342,   212,    47,   339,    47,   341,   315,   159,
     238,   351,   279,   282,   354,     1,   343,   357,     4,   316,
     159,   248,   322,    -1,   358,   350,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,   308,
      26,    27,    28,    29,    30,   314,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,   325,    43,    -1,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,    62,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,   358,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     1,    91,    92,     4,    -1,    95,
      96,    97,    98,    -1,   100,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    -1,     1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    62,    24,    64,    26,    27,
      28,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    92,    -1,    -1,    95,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    -1,     1,
      -1,    89,    -1,    91,    92,    -1,    -1,    -1,    96,    -1,
      98,    -1,   100,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,     1,    24,    -1,    26,    27,    28,    91,    92,    93,
      94,    -1,    96,    -1,    98,    15,   100,    -1,    -1,    -1,
      20,    21,    22,     1,    24,    -1,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    89,    -1,    91,
      92,    -1,    72,    -1,    96,    97,    -1,    -1,   100,    -1,
      80,    81,    82,    83,    84,    85,    -1,    -1,    -1,    89,
      -1,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    80,    81,    82,    83,    84,    85,    -1,     1,
      -1,    89,     4,    91,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      62,    16,    64,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     1,    91,
      92,     4,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    91,    92,    93,    94,
      -1,    96,    -1,    98,    -1,   100,    -1,    -1,    -1,    62,
      -1,    64,    91,    92,    93,    94,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     1,    91,    92,
       4,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    -1,    30,    -1,     1,    -1,
      -1,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    15,    47,    48,     1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    -1,    -1,    62,    15,
      64,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    -1,    -1,    -1,    89,    -1,    91,    92,
      -1,    -1,    -1,    96,    80,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    89,    -1,    91,    92,    -1,    -1,    -1,
      96,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    96,    97,    98,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    31,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    31,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      96,    97,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    96,     5,     6,    -1,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    54,   103,   156,   158,   159,   160,   162,    22,
     157,    52,    56,   155,   160,     0,     4,    95,   102,    22,
     108,     1,    15,    20,    21,    24,    26,    27,    28,    30,
      35,    37,    38,    45,    47,    48,    62,    64,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    91,    92,
      95,    96,   107,   108,   109,   112,   113,   114,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   131,   132,   133,
     134,   135,   136,   141,   146,   149,   151,   161,    96,    99,
      80,    81,    82,    83,    84,    85,   114,   134,   114,   102,
     108,    95,   102,   115,   115,    43,    20,   114,   157,    65,
      96,    96,    96,    96,    96,    93,    96,    20,    24,    93,
      96,   129,   130,   130,   130,   109,   112,   114,   114,   114,
     140,    96,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    16,    90,    91,    92,    93,    94,    96,   115,
       4,   124,    29,   115,   115,   115,    98,   106,   115,   124,
     100,   108,   110,   111,   114,   137,   138,   139,    31,   143,
     124,    90,   102,    96,   125,   115,   102,   102,   102,    78,
      79,   105,   105,   105,   105,   105,    20,   105,    20,    93,
     128,    98,   127,   139,   139,   139,    97,    98,    97,   139,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,    50,    67,    70,
      73,    77,   104,    17,    90,    98,    98,   100,    98,    97,
     102,   117,   161,    29,    36,   148,   114,   114,   124,   160,
      90,    90,    97,    97,    97,    97,    97,    97,    98,   108,
      97,   115,    97,   157,    96,    96,   106,   139,    71,   114,
     142,   144,   111,   139,   114,   139,    55,   154,   124,    35,
     102,    98,    97,   126,   148,   102,   114,    20,   129,    90,
     102,   111,   114,    74,    75,    76,   114,   139,   140,    98,
     100,    96,   102,    29,    32,    33,    34,   145,   147,   114,
     102,   102,    29,    97,   114,    97,    97,    97,    97,    97,
      98,    72,    72,   144,   114,   108,   124,    30,   102,   114,
     102,    32,   145,    98,   102,    43,   152,   153,    62,    98,
     108,    97,    29,   124,    31,   102,   102,   114,   124,   125,
     153,    29,    46,   150,   157,   114,    90,   155,   145,   102,
     124,   102,   148,   111,    45,   102,   102,   114,   102,   102,
     124,   145,   124,   102,   126,   147,   102,   148,   102,   102,
     124
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
#line 55 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 59 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 63 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 84 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(in)
				set_variabledesc_attr(newnode, true, true, optionalparam<bool>(), optionalparam<ParseNode *>(), optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 91 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(out)
				set_variabledesc_attr(newnode, true, false, optionalparam<bool>(), optionalparam<ParseNode *>(), optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 99 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(inout)
				set_variabledesc_attr(newnode, true, false, optionalparam<bool>(), optionalparam<ParseNode *>(), optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 106 "for90.y"
    {
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
				ParseNode * dimen = new ParseNode(gen_variabledesc_from_dimenslice((yyvsp[(3) - (4)])));
				newnode->addchild(dimen); // def slice
				set_variabledesc_attr(newnode, optionalparam<bool>(), optionalparam<bool>(), optionalparam<bool>(), dimen, optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 118 "for90.y"
    {
				/* define array like a(1) */
				ParseNode * newnode = new ParseNode();
				ParseNode slice = ParseNode();
				ParseNode & exp_to = (yyvsp[(3) - (4)]);
				ParseNode & exp_from = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER, "1" }));

				slice.addchild(new ParseNode(exp_from)); // slice from 1
				slice.addchild(new ParseNode(exp_to)); // slice to
				// sprintf(codegen_buf, "%s", /* from 1, to */exp_to.fs.CurrentTerm.what.c_str());				

				ParseNode * dimen = new ParseNode(gen_dimenslice_from_slice(slice));
				newnode->addchild(dimen); // def slice

				set_variabledesc_attr(newnode, optionalparam<bool>(), optionalparam<bool>(), optionalparam<bool>(), dimen, optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 137 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // optional
				set_variabledesc_attr(newnode, optionalparam<bool>(), optionalparam<bool>(), true, optionalparam<ParseNode *>(), optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 144 "for90.y"
    {
				/* const value */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // const
				set_variabledesc_attr(newnode, optionalparam<bool>(), true, optionalparam<bool>(), optionalparam<ParseNode *>(), optionalparam<int>());
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 153 "for90.y"
    {
				int kind;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &kind);

				/* type size */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // kind
				set_variabledesc_attr(newnode, optionalparam<bool>(), true, optionalparam<bool>(), optionalparam<ParseNode *>(), kind);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 164 "for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &len);

				/* string length */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // len
				set_variabledesc_attr(newnode, optionalparam<bool>(), optionalparam<bool>(), optionalparam<bool>(), optionalparam<ParseNode *>(), len);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 178 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 183 "for90.y"
    {
				ParseNode * variable_iden = & (yyvsp[(3) - (3)]);
				ParseNode & variable_iden_1 = (yyvsp[(2) - (3)]);
				/* target code of slice depend on context */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
				/* merge attrs */
				newnode.attr = variable_iden_1.attr->clone();
				(dynamic_cast<VariableDescAttr *>(newnode.attr))->merge(*dynamic_cast<VariableDescAttr *>(variable_iden->attr));
				// TODO do not add child
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 196 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 206 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 211 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 215 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 220 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 224 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 228 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 238 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 245 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 251 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 258 "for90.y"
    {
				/* arr[from : to] */
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				(yyval) = gen_slice(exp1, exp2);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 267 "for90.y"
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

  case 31:
/* Line 1792 of yacc.c  */
#line 277 "for90.y"
    {
				/* arr[from : to : step] */
				ParseNode & lb = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER, "-1" }));
				ParseNode & ub = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER, "-1" }));
				/* target code of slice depend on context */
				(yyval) = gen_slice(lb, ub);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 287 "for90.y"
    {
				/* 1d array */
				/* arr[from : to] */
				/* target code of slice depend on context */
				ParseNode & slice = (yyvsp[(1) - (1)]);
				// only 1 slice
				(yyval) = gen_dimenslice_from_slice(slice);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 297 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ParseNode & slice = (yyvsp[(1) - (3)]);
				ParseNode & dimen_slice = (yyvsp[(3) - (3)]);
				// gen_dimenslice(slice, dimen_slice);
				(yyval) = gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 308 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_argtable_from_exp(exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 315 "for90.y"
    {
				ParseNode & exp = (yyvsp[(1) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				// gen_argtable(exp, argtable);
				(yyval) = gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 325 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode & callable_head = (yyvsp[(1) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				(yyval) = gen_function_array(callable_head, argtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 335 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)])
			;}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 339 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)])
			;}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 344 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_exp(function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 351 "for90.y"
    {
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s(%s)");
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 359 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				(yyval) = gen_exp(exp, op, "( %s )");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 367 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 375 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 383 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 391 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 399 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 407 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 414 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 421 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 429 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 437 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 445 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 453 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 461 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 469 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 476 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 484 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 492 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 500 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 508 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_exp(hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 514 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 518 "for90.y"
    {
				// may cause reduction-reduction conflict when use `variable` instead of `callable_head`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable_head will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 542 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 546 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 551 "for90.y"
    {
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ;");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 562 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 568 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 572 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 576 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 580 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 584 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 589 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 594 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 598 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 616 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 622 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 631 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 638 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 643 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s\n%s", TokenMeta::NT_SUITE);;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 648 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 653 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				//$$.fs.CurrentTerm.what = $2.fs.CurrentTerm.what;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 667 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 671 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 675 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 679 "for90.y"
    {
					
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 683 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 690 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				ParseNode & _optional_device = (yyvsp[(2) - (5)]);
				ParseNode & _optional_formatter = (yyvsp[(4) - (5)]);
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode.addchild(new ParseNode(_optional_device)); // _optional_device
				newnode.addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 701 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				ParseNode & _optional_formatter = (yyvsp[(1) - (2)]);
				/* target code of io_info depend on context */
				newnode.addchild(new ParseNode(_optional_device)); // _optional_device
				newnode.addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 715 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 723 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 732 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 740 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 745 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 750 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 755 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 760 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 765 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				// now translated in pre_map
				//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 778 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 783 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 788 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 793 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 798 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str(), "%d", &len);
				set_variabledesc_attr(&newnode, optionalparam<bool>(), optionalparam<bool>(), optionalparam<bool>()
					, optionalparam<ParseNode *>(), len);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 807 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 815 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 826 "for90.y"
    {	
				/* paramtable is used in function decl */
				/* this paramtable has only one value */
				ParseNode & variable = (yyvsp[(1) - (1)]);
				(yyval) = gen_keyvalue(variable);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 834 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 841 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* array initial values */;
				/* 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 */
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 850 "for90.y"
    {
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 853 "for90.y"
    {
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 857 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				(yyval) = gen_paramtable(paramtable_elem);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 863 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 870 "for90.y"
    {
				/* no params */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 878 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_HIDDENDO, "" }), nullptr);
				newnode.addchild(new ParseNode((yyvsp[(1) - (7)]))); // exp
				newnode.addchild(new ParseNode((yyvsp[(3) - (7)]))); // index variable
				newnode.addchild(new ParseNode((yyvsp[(5) - (7)]))); // exp_from
				newnode.addchild(new ParseNode((yyvsp[(7) - (7)]))); // exp_to
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 890 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode & _generate_stmt = (yyvsp[(2) - (3)]);
				(yyval) = gen_hiddendo(_generate_stmt);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 898 "for90.y"
    {
				/* give initial value */
				/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
				/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
				(yyval) = gen_array_generate_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 906 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_generate_stmt((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				/* rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule*/
				/* note that this two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict */
				/* note either that `variable '(' dimen_slice ')'` is an `exp` */
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 919 "for90.y"
    {
				(yyval) = gen_promote("%s", TokenMeta::NT_ARRAYBUILDER, (yyvsp[(1) - (1)])); // array_builder_elem
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 924 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "%s\n%s", TokenMeta::NT_ARRAYBUILDER);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));

			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 934 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite_true = (yyvsp[(5) - (7)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());

				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 943 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (10)]);
				ParseNode & suite_true = (yyvsp[(5) - (10)]); 
				ParseNode & suite_else = (yyvsp[(8) - (10)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 952 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (8)]);
				ParseNode & suite_true = (yyvsp[(5) - (8)]);
				ParseNode & elseif = (yyvsp[(6) - (8)]);
				//sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 961 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]);
				ParseNode & elseif = (yyvsp[(6) - (11)]);
				ParseNode & suite_else = (yyvsp[(9) - (11)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 971 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 978 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 986 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 998 "for90.y"
    {
				ParseNode & suite = (yyvsp[(3) - (5)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1004 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(2) - (10)]);
				ParseNode & exp_from = (yyvsp[(4) - (10)]);
				ParseNode & exp_to = (yyvsp[(6) - (10)]);
				ParseNode & step = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = (yyvsp[(8) - (10)]); 
				(yyval) = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1014 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(2) - (12)]);
				ParseNode & exp1 = (yyvsp[(4) - (12)]);
				ParseNode & exp2 = (yyvsp[(6) - (12)]);
				ParseNode & exp3 = (yyvsp[(8) - (12)]);
				ParseNode & suite = (yyvsp[(10) - (12)]);
				(yyval) = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1024 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1035 "for90.y"
    {
				ParseNode & select = (yyvsp[(1) - (9)]);
				ParseNode & exp = (yyvsp[(4) - (9)]);
				ParseNode & case_stmt = (yyvsp[(7) - (9)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1043 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1051 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_CASES, "" }), nullptr);
				newnode.addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1059 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode newnode = ParseNode(case_stmt);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode.addchild(new ParseNode(case_stmt_elem), false /* add to the front of the vector */); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1070 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1075 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1085 "for90.y"
    {
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode & variable_function = (yyvsp[(3) - (12)]); // function name
				/* enumerate paramtable */
				ParseNode & paramtable = (yyvsp[(5) - (12)]);
				ParseNode & variable_result = (yyvsp[(7) - (12)]); // result variable
				ParseNode & suite = (yyvsp[(9) - (12)]);

				(yyval) = gen_function(variable_function, paramtable, variable_result, suite);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1101 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", tabber(suite.fs.CurrentTerm.what).c_str());
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM, string(codegen_buf) }), nullptr);
				newnode.addchild(new ParseNode(suite)); //suite
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1112 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1117 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1123 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild(new ParseNode((yyvsp[(1) - (1)]))); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1132 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (2)]))); // wrapper
				newnode->addchild(new ParseNode((yyvsp[(2) - (2)]))); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (2)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (2)]).fs.CurrentTerm.what.c_str());
				newnode = flattern_bin(newnode);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1144 "for90.y"
    {
				// drop interface directly
				//ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				// no child
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1153 "for90.y"
    {
				program_tree = (yyvsp[(1) - (1)]);
			}
    break;


/* Line 1792 of yacc.c  */
#line 3543 "for90.tab.cpp"
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
#line 1159 "for90.y"

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
		current.fs.parse_pos = current.child[0]->fs.parse_pos;
		current.fs.parse_line = current.child[0]->fs.parse_line;
		current.fs.parse_len = current.child[0]->fs.parse_len;
		current.fs.line_pos = current.child[0]->fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.child.size(); i++)
		{
			tot_len += current.child[i]->fs.parse_len;
		}
		current.fs.parse_pos = current.child[0]->fs.parse_pos;
		current.fs.parse_line = current.child[0]->fs.parse_line;
		current.fs.parse_len = tot_len;
		current.fs.line_pos = current.child[0]->fs.line_pos;
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
