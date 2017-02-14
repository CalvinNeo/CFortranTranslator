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
     YY_LABEL = 284,
     YY_END = 285,
     YY_IF = 286,
     YY_THEN = 287,
     YY_ELSE = 288,
     YY_ELSEIF = 289,
     YY_ENDIF = 290,
     YY_DO = 291,
     YY_ENDDO = 292,
     YY_CONTINUE = 293,
     YY_BREAK = 294,
     YY_WHILE = 295,
     YY_ENDWHILE = 296,
     YY_WHERE = 297,
     YY_ENDWHERE = 298,
     YY_CASE = 299,
     YY_ENDCASE = 300,
     YY_SELECT = 301,
     YY_ENDSELECT = 302,
     YY_GOTO = 303,
     YY_DOWHILE = 304,
     YY_DEFAULT = 305,
     YY_PROGRAM = 306,
     YY_ENDPROGRAM = 307,
     YY_FUNCTION = 308,
     YY_ENDFUNCTION = 309,
     YY_RECURSIVE = 310,
     YY_RESULT = 311,
     YY_SUBROUTINE = 312,
     YY_ENDSUBROUTINE = 313,
     YY_MODULE = 314,
     YY_ENDMODULE = 315,
     YY_BLOCK = 316,
     YY_ENDBLOCK = 317,
     YY_INTERFACE = 318,
     YY_ENDINTERFACE = 319,
     YY_COMMON = 320,
     YY_DATA = 321,
     YY_IMPLICIT = 322,
     YY_NONE = 323,
     YY_USE = 324,
     YY_PARAMETER = 325,
     YY_ENTRY = 326,
     YY_DIMENSION = 327,
     YY_ARRAYINITIAL_START = 328,
     YY_ARRAYINITIAL_END = 329,
     YY_INTENT = 330,
     YY_IN = 331,
     YY_OUT = 332,
     YY_INOUT = 333,
     YY_OPTIONAL = 334,
     YY_LEN = 335,
     YY_KIND = 336,
     YY_INTEGER_T = 337,
     YY_FLOAT_T = 338,
     YY_STRING_T = 339,
     YY_COMPLEX_T = 340,
     YY_BOOL_T = 341,
     YY_CHARACTER_T = 342,
     YY_WRITE = 343,
     YY_READ = 344,
     YY_PRINT = 345,
     YY_CALL = 346,
     YY_FORMAT = 347
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
#line 253 "for90.tab.cpp"

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
#define YYFINAL  163
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNRULES -- Number of states.  */
#define YYNSTATES  377

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     102,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      99,   100,    96,    94,   101,    95,     2,    97,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,    98,
       2,    93,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    11,    16,    21,
      26,    31,    36,    38,    40,    43,    47,    48,    52,    56,
      58,    60,    62,    64,    66,    68,    71,    73,    77,    83,
      85,    87,    91,    93,    97,   102,   107,   109,   112,   114,
     116,   121,   125,   129,   133,   137,   141,   145,   148,   151,
     155,   159,   163,   167,   171,   175,   178,   182,   186,   190,
     194,   196,   198,   200,   202,   205,   207,   208,   210,   213,
     216,   218,   220,   222,   224,   226,   228,   231,   233,   235,
     238,   241,   244,   246,   248,   250,   253,   256,   260,   265,
     269,   271,   274,   276,   279,   280,   282,   283,   285,   287,
     288,   290,   292,   294,   296,   298,   304,   307,   311,   315,
     319,   321,   323,   325,   327,   329,   331,   336,   341,   346,
     351,   356,   361,   365,   367,   371,   374,   375,   379,   384,
     388,   390,   394,   398,   400,   402,   404,   408,   409,   417,
     421,   425,   429,   431,   434,   436,   444,   455,   464,   476,
     481,   485,   491,   498,   501,   503,   509,   520,   533,   540,
     543,   545,   555,   562,   564,   567,   572,   573,   575,   577,
     590,   592,   593,   602,   604,   606,   608,   610,   613,   623,
     625
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,     4,    -1,    98,    -1,    -1,    55,    -1,
      -1,    75,    99,    76,   100,    -1,    75,    99,    77,   100,
      -1,    75,    99,    78,   100,    -1,    72,    99,   113,   100,
      -1,    72,    99,   116,   100,    -1,    79,    -1,    70,    -1,
     101,   107,    -1,   101,   107,   108,    -1,    -1,    81,    93,
      20,    -1,    80,    93,   116,    -1,    21,    -1,    20,    -1,
      24,    -1,    27,    -1,    28,    -1,    26,    -1,     1,   102,
      -1,    22,    -1,   116,   103,   116,    -1,   116,   103,   116,
     103,   116,    -1,   103,    -1,   112,    -1,   112,   101,   113,
      -1,   116,    -1,   116,   101,   144,    -1,   111,    99,   144,
     100,    -1,   137,    99,   144,   100,    -1,   114,    -1,    91,
     114,    -1,   115,    -1,   148,    -1,   116,    99,   116,   100,
      -1,    99,   116,   100,    -1,   116,    94,   116,    -1,   116,
      95,   116,    -1,   116,    96,   116,    -1,   116,    97,   116,
      -1,   116,    16,   116,    -1,    95,   116,    -1,    94,   116,
      -1,   116,    10,   116,    -1,   116,    11,   116,    -1,   116,
       7,   116,    -1,   116,    12,   116,    -1,   116,    13,   116,
      -1,   116,    14,   116,    -1,    15,   116,    -1,   116,     5,
     116,    -1,   116,     6,   116,    -1,   116,     8,   116,    -1,
     116,     9,   116,    -1,   146,    -1,   110,    -1,   111,    -1,
     105,    -1,    98,   105,    -1,    98,    -1,    -1,    29,    -1,
     116,   117,    -1,   141,   117,    -1,   123,    -1,   121,    -1,
     122,    -1,   126,    -1,   125,    -1,   124,    -1,   118,     4,
      -1,   119,    -1,   140,    -1,   134,   117,    -1,   135,   117,
      -1,   136,   117,    -1,   150,    -1,   153,    -1,   155,    -1,
      38,   117,    -1,    39,   117,    -1,    48,    20,   117,    -1,
     116,    93,   116,   117,    -1,    67,    68,   105,    -1,   120,
      -1,   120,   127,    -1,   165,    -1,   165,   127,    -1,    -1,
      99,    -1,    -1,   100,    -1,   101,    -1,    -1,    96,    -1,
      20,    -1,    96,    -1,    20,    -1,    24,    -1,    99,   131,
     101,   132,   100,    -1,   132,   130,    -1,    88,   133,   144,
      -1,    90,   133,   144,    -1,    89,   133,   144,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    82,    99,   109,   100,    -1,    83,    99,   109,   100,
      -1,    84,    99,   109,   100,    -1,    85,    99,   109,   100,
      -1,    86,    99,   109,   100,    -1,    87,    99,   109,   100,
      -1,   137,    96,    20,    -1,   137,    -1,    97,   111,    97,
      -1,    97,    97,    -1,    -1,    65,   139,   144,    -1,   138,
     108,    17,   144,    -1,   138,   108,   144,    -1,   111,    -1,
     116,    93,   116,    -1,   116,    93,   148,    -1,   113,    -1,
     142,    -1,   143,    -1,   143,   101,   144,    -1,    -1,   116,
     101,   111,    93,   116,   101,   116,    -1,    99,   145,   100,
      -1,    73,   144,    74,    -1,    73,   146,    74,    -1,   147,
      -1,    30,    31,    -1,    35,    -1,    31,   116,    32,   105,
     127,   149,   105,    -1,    31,   116,    32,   105,   127,    33,
     105,   127,   149,   105,    -1,    31,   116,    32,   105,   127,
     151,   149,   105,    -1,    31,   116,    32,   105,   127,   151,
      33,   105,   127,   149,   105,    -1,    31,   116,    32,   120,
      -1,    31,   116,   120,    -1,    34,   116,    32,   105,   127,
      -1,    34,   116,    32,   105,   127,   151,    -1,    30,    36,
      -1,    37,    -1,    36,   105,   127,   152,   105,    -1,    36,
     111,    93,   116,   101,   116,   105,   127,   152,   105,    -1,
      36,   111,    93,   116,   101,   116,   101,   116,   105,   127,
     152,   105,    -1,    49,   116,   105,   127,   152,   105,    -1,
      30,    46,    -1,    47,    -1,    46,    44,   128,   116,   129,
     105,   157,   154,   105,    -1,    44,   128,   113,   129,   105,
     127,    -1,   156,    -1,   156,   157,    -1,    56,    99,   111,
     100,    -1,    -1,    53,    -1,    57,    -1,   106,   159,   111,
      99,   144,   100,   158,   105,   127,    30,   159,   105,    -1,
      22,    -1,    -1,    51,   161,   105,   127,    30,    51,   161,
     105,    -1,   127,    -1,   160,    -1,   162,    -1,   163,    -1,
     163,   164,    -1,    63,   161,   105,   164,   105,    30,    63,
     161,   105,    -1,   164,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   117,   135,   142,   151,   156,   171,   179,   190,   204,
     209,   213,   218,   222,   226,   233,   235,   242,   251,   261,
     270,   280,   290,   297,   317,   327,   338,   342,   347,   355,
     363,   371,   379,   387,   395,   403,   411,   419,   426,   433,
     441,   450,   458,   467,   475,   483,   490,   498,   506,   514,
     522,   528,   533,   540,   541,   543,   548,   552,   558,   568,
     574,   578,   582,   586,   590,   595,   600,   605,   609,   615,
     616,   618,   620,   621,   622,   624,   625,   626,   632,   641,
     648,   653,   658,   663,   670,   671,   672,   673,   674,   675,
     676,   680,   684,   688,   693,   700,   711,   725,   733,   742,
     750,   755,   760,   765,   770,   775,   781,   787,   792,   797,
     802,   807,   815,   820,   822,   827,   834,   839,   847,   857,
     868,   873,   882,   891,   895,   899,   906,   915,   922,   934,
     942,   949,   960,   992,   993,  1000,  1007,  1015,  1023,  1032,
    1039,  1047,  1055,  1064,  1065,  1067,  1073,  1083,  1093,  1101,
    1102,  1104,  1112,  1120,  1128,  1139,  1145,  1151,  1152,  1154,
    1167,  1168,  1170,  1176,  1189,  1194,  1200,  1209,  1221,  1227,
    1231
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
  "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX", "YY_TRUE", "YY_FALSE",
  "YY_LABEL", "YY_END", "YY_IF", "YY_THEN", "YY_ELSE", "YY_ELSEIF",
  "YY_ENDIF", "YY_DO", "YY_ENDDO", "YY_CONTINUE", "YY_BREAK", "YY_WHILE",
  "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE",
  "YY_SELECT", "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT",
  "YY_PROGRAM", "YY_ENDPROGRAM", "YY_FUNCTION", "YY_ENDFUNCTION",
  "YY_RECURSIVE", "YY_RESULT", "YY_SUBROUTINE", "YY_ENDSUBROUTINE",
  "YY_MODULE", "YY_ENDMODULE", "YY_BLOCK", "YY_ENDBLOCK", "YY_INTERFACE",
  "YY_ENDINTERFACE", "YY_COMMON", "YY_DATA", "YY_IMPLICIT", "YY_NONE",
  "YY_USE", "YY_PARAMETER", "YY_ENTRY", "YY_DIMENSION",
  "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN",
  "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_INTEGER_T",
  "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "YY_WRITE", "YY_READ", "YY_PRINT", "YY_CALL",
  "YY_FORMAT", "'='", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'",
  "','", "'\\n'", "':'", "$accept", "crlf", "dummy_function_iden",
  "variable_desc_elem", "variable_desc", "typecast_spec", "literal",
  "variable", "slice", "dimen_slice", "function_array_body",
  "function_array", "exp", "_crlf_semicolon", "semicolon", "label", "stmt",
  "output_stmt", "input_stmt", "compound_stmt", "jump_stmt", "let_stmt",
  "dummy_stmt", "suite", "_optional_lbrace", "_optional_rbrace",
  "_optional_comma", "_optional_device", "_optional_formatter", "io_info",
  "write", "print", "read", "type_nospec", "type_spec",
  "_blockname_or_none", "common_stmt", "var_def", "keyvalue",
  "paramtable_elem", "paramtable", "_generate_stmt", "hidden_do",
  "array_builder_elem", "array_builder", "_yy_endif", "if_stmt",
  "elseif_stmt", "_yy_enddo", "do_stmt", "_yy_endselect", "select_stmt",
  "case_stmt_elem", "case_stmt", "_optional_result", "_optional_function",
  "function_decl", "_optional_name", "program", "wrapper", "wrappers",
  "interface_decl", "fortran_program", YY_NULL
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
     345,   346,   347,    61,    43,    45,    42,    47,    59,    40,
      41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   112,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   123,   123,   123,   124,   124,   124,   125,   126,
     127,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   132,   133,   133,   134,   135,   136,
     137,   137,   137,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   139,   139,   140,   141,   141,
     142,   142,   142,   143,   143,   144,   144,   144,   145,   146,
     147,   147,   148,   149,   149,   150,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   153,   153,   153,   153,   154,
     154,   155,   156,   157,   157,   158,   158,   159,   159,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   165,   166,
     166
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     0,     4,     4,     4,
       4,     4,     1,     1,     2,     3,     0,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     5,     1,
       1,     3,     1,     3,     4,     4,     1,     2,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     3,     4,     3,
       1,     2,     1,     2,     0,     1,     0,     1,     1,     0,
       1,     1,     1,     1,     1,     5,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     3,     1,     3,     2,     0,     3,     4,     3,
       1,     3,     3,     1,     1,     1,     3,     0,     7,     3,
       3,     3,     1,     2,     1,     7,    10,     8,    11,     4,
       3,     5,     6,     2,     1,     5,    10,    12,     6,     2,
       1,     9,     6,     1,     2,     4,     0,     1,     1,    12,
       1,     0,     8,     1,     1,     1,     1,     2,     9,     1,
       0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    20,    19,    26,    21,    24,    22,    23,
      67,     0,     4,     4,     4,     0,     0,     0,   171,     5,
     171,   126,     0,     0,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,    65,     0,     0,    61,
      62,    36,    38,     4,     0,    77,     0,    71,    72,    70,
      75,    74,    73,   173,     4,     4,     4,   123,    16,    78,
       4,    60,   142,    39,    82,    83,    84,   174,   175,     0,
     179,     0,     0,    25,   110,   111,   112,   113,   114,   115,
      55,     0,     0,     2,     3,     0,     0,     3,    63,    85,
      86,    94,     4,     4,   170,     4,     4,     0,     0,     4,
      29,    62,    30,   133,    32,   134,   135,     0,    60,     0,
       0,     0,     0,     0,     0,   103,   104,   102,     0,    99,
       0,     0,     0,     0,    37,    48,    47,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    76,    91,    79,    80,    81,     0,     0,     0,     0,
      69,   177,    93,     1,     0,     0,     0,     0,   150,     0,
       0,    64,    95,     0,    87,     0,     0,     0,   125,     0,
     127,    89,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   100,     0,
      98,   106,   107,   109,   108,    41,     0,   139,     0,     0,
      56,    57,    51,    58,    59,    49,    50,    52,    53,    54,
      46,     4,    42,    43,    44,    45,     0,   122,     0,    13,
       0,     0,    12,    14,     0,   129,     3,     0,   149,    42,
      43,     0,     0,   154,     4,     0,    96,     0,     0,     4,
     124,    31,    32,   131,    39,    33,    27,   136,     0,     0,
     116,   117,   118,   119,   120,   121,     0,     0,     0,    34,
      88,    40,    35,     0,     0,    15,   128,     0,    40,   153,
     155,     0,    97,     4,     4,     0,     0,     0,    18,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,   144,     4,     0,     4,     0,   158,   171,     0,    28,
     105,     0,   166,    10,    11,     7,     8,     9,   143,     0,
       0,   145,     4,     4,     0,     0,    94,   163,     0,     4,
     171,     0,     0,     4,     0,     4,     0,   147,     4,     0,
       0,   164,     0,   160,     4,   172,     4,   138,     0,     0,
       4,     0,     0,     0,     4,    96,   159,   161,   178,     0,
       0,   146,   151,     4,     0,   156,     4,   165,     0,   152,
     148,     4,     0,     4,   157,   162,   169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    38,   233,   159,   191,    39,    40,   102,   103,
      41,    42,    43,    89,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   173,   283,   201,   199,   119,   120,
      54,    55,    56,    81,    58,    98,    59,    60,   105,   106,
     107,   128,    61,    62,    63,   302,    64,   303,   244,    65,
     344,    66,   327,   328,   333,   131,    67,    95,    68,    69,
      70,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -242
static const yytype_int16 yypact[] =
{
    1105,   -86,  1613,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  1613,     3,     5,     5,   -11,    22,  1613,    31,  -242,
      31,   -23,     9,   117,    -6,    11,    16,    18,    28,    30,
      71,    71,    71,   140,  1613,  1613,  -242,  1613,   -38,  -242,
      36,  -242,  -242,  1879,    95,  -242,   829,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,     5,     5,     5,   -29,    39,  -242,
       5,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  1013,
    -242,   921,   104,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
      23,    43,  1298,  -242,  -242,  1489,    64,    26,  -242,  -242,
    -242,    83,     5,  1892,  -242,    26,    26,   -14,   737,    26,
    -242,    36,    88,  -242,  1261,  -242,    91,   119,   120,   106,
     106,   106,   106,   106,   106,  -242,  -242,  -242,    -7,    96,
     737,   737,   737,    36,  -242,   149,   149,    52,    98,  -242,
    -242,   174,   425,  1613,  1613,  1613,  1613,  1613,  1613,  1613,
    1613,  1613,  1613,  1613,  1613,  1613,  1613,  1613,  1613,  1613,
    -242,  -242,  -242,  -242,  -242,  -242,   186,   425,    99,   645,
    -242,  -242,  -242,  -242,  1581,  1613,  1613,  1613,  -242,    17,
    1613,  -242,  -242,  1613,  -242,  1489,  1489,  1397,  -242,   110,
    -242,  -242,   456,  1613,   553,  1613,   553,  -242,  -242,   116,
     121,   113,   115,   134,   136,   138,   139,  -242,  -242,   109,
    -242,  -242,  -242,  -242,  -242,  -242,   174,  -242,   122,   142,
     149,   149,    12,   149,   149,    12,  2042,  2042,  2066,  2054,
      15,  1905,    29,    29,    15,    15,  1917,  -242,   150,  -242,
     152,   153,  -242,    39,   737,  -242,  -242,  1489,  -242,  1186,
    1201,  1757,   182,  -242,    26,  1769,  1929,    17,   189,    26,
    -242,  -242,  1720,  2042,  -242,  -242,  1732,  -242,  1613,   221,
    -242,  -242,  -242,  -242,  -242,  -242,    92,   156,   425,  -242,
    -242,  -242,  -242,   456,   103,  -242,  -242,    46,  1506,  -242,
    -242,  1613,  -242,    26,    26,   202,   224,  1613,  2042,  -242,
     155,  1613,   157,   158,  1708,   159,   160,   161,   232,    26,
    1613,  -242,    26,   133,  1745,   220,  -242,    31,   203,  2042,
    -242,  1781,   209,  -242,  -242,  -242,  -242,  -242,  -242,  1489,
    1947,  -242,    26,    26,  1613,  1489,    83,   220,    25,    26,
      31,  1613,   170,    26,    14,    26,  1489,  -242,  1892,    17,
     456,  -242,   225,  -242,    26,  -242,    26,  2042,   174,  1489,
      26,  1489,    14,  1489,    26,   172,  -242,  -242,  -242,   173,
     240,  -242,   242,    26,    17,  -242,    26,  -242,   -38,  -242,
    -242,    26,  1489,    26,  -242,  -242,  -242
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,    -9,  -242,  -242,    45,   118,  -242,    -1,  -242,  -181,
     248,  -242,   245,    -4,  -242,  -242,   -70,  -242,  -242,  -242,
    -242,  -242,  -242,   -42,   -41,   -71,  -242,  -242,    20,   141,
    -242,  -242,  -242,     0,  -242,  -242,  -242,  -242,  -242,  -242,
     -84,  -242,   264,  -242,   105,  -198,  -242,   -66,  -241,  -242,
    -242,  -242,  -242,   -36,  -242,   -76,  -242,   -18,  -242,  -242,
     -64,  -242,  -242
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
      57,   251,    96,    85,   152,   161,   284,    83,     5,    83,
      90,    86,   168,   197,   180,   129,    73,   133,   134,   130,
     136,   137,   101,   139,   140,     5,   139,   140,   143,   162,
      83,   143,   123,    91,   139,   140,   202,   203,   204,   150,
     139,   140,    92,   169,   298,   143,    57,   242,   209,   301,
     153,   154,   155,    94,   243,   342,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   156,   143,    57,
     157,    57,   343,   228,    97,   235,   298,    99,   171,   299,
     300,   301,    57,   178,   175,    57,   176,   177,   174,   198,
     181,   115,   293,   109,   238,   116,   179,   101,   354,   151,
     255,    84,   257,    87,   163,   323,   145,   146,   147,   148,
     110,   149,   115,   249,   149,   111,   116,   112,     1,   101,
     101,   101,   149,   371,    84,   147,   148,   113,   149,   114,
     208,   101,     2,   247,   248,   132,   350,     3,     4,     5,
     158,     6,   157,     7,     8,     9,   145,   146,   147,   148,
     276,   149,   205,   206,   363,   237,   101,   170,   101,   355,
     139,   140,     5,   298,    57,   143,   322,   117,   301,   229,
     118,   230,   121,   122,   231,    57,    57,    57,   232,   295,
     296,   297,   172,   101,   292,   101,   189,   190,   117,   182,
      23,  -137,   186,   187,   188,   277,     5,   200,   207,    74,
      75,    76,    77,    78,    79,   267,   227,   250,    33,   258,
     266,    34,    35,   260,   259,   261,    37,   270,   279,   285,
     100,   268,    74,    75,    76,    77,    78,    79,   192,   193,
     194,   195,   196,   101,   262,   280,   263,    57,   264,   265,
     286,   289,   269,   145,   146,   147,   148,    80,   149,   291,
     272,   273,   274,   307,   308,   310,    82,   312,   313,   315,
     316,   317,    93,   318,   326,   332,   330,   101,   104,   348,
     368,   356,   282,   367,   305,   306,   300,   334,   275,   125,
     126,   124,   127,   339,   366,   340,   290,   108,   254,   329,
     319,   341,   373,   321,   352,   325,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,     0,   362,
       0,   364,   346,   336,   337,     0,     0,     0,     0,    57,
     345,     0,     0,     0,   349,    57,   351,     0,     0,   353,
     375,     0,     0,     0,     0,   357,    57,   358,     0,     0,
       0,   361,     0,   104,     0,   365,     0,   359,     0,    57,
       0,    57,     0,    57,   370,     0,     0,   372,     0,     0,
       0,     0,   374,     0,   376,   104,   104,   104,     0,     0,
       0,     0,    57,     0,     0,     0,     0,   104,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
       0,     0,   104,     0,   104,     0,     0,     0,     0,     0,
     239,   240,   241,     0,     0,   245,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     1,   252,   253,   104,
     256,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,   104,
       6,     0,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,   288,     0,     0,     0,    74,    75,    76,
      77,    78,    79,   104,     0,     0,    33,     0,   294,    34,
      35,     0,     0,     0,    37,  -137,   304,     0,   100,    23,
       0,     0,   309,     0,     0,     0,   311,     0,    74,    75,
      76,    77,    78,    79,     0,   320,     0,    33,     0,     0,
      34,    35,     0,  -137,     1,    37,     0,  -137,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     2,   338,
       0,     0,     0,     3,     4,     5,   347,     6,     0,     7,
       8,     9,  -137,  -137,  -137,   252,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,     0,     0,     0,     0,  -137,     0,  -137,
    -137,  -137,  -137,     0,  -137,     0,  -137,     0,  -137,     0,
    -137,     0,     0,     0,     0,     0,  -137,     0,  -137,     0,
    -137,     0,     0,     0,     0,     0,    23,  -137,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,  -137,  -137,  -137,    33,  -137,     1,    34,    35,  -137,
       0,  -137,    37,  -137,  -137,     0,   100,     0,     0,     0,
       2,     0,   234,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,  -137,  -137,  -137,     0,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,  -137,
       0,  -137,  -137,  -137,  -137,     0,  -137,     0,  -137,     0,
    -137,     0,  -137,     0,     0,     0,     0,     0,  -137,     0,
    -137,     0,  -137,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,  -137,  -137,  -137,    33,  -137,     1,    34,
      35,  -137,     0,  -137,    37,     0,     0,     0,   100,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,  -137,  -137,  -137,     0,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,
       0,  -137,     0,  -137,  -137,  -137,  -137,     0,  -137,     0,
    -137,     0,  -137,     0,  -137,     0,     0,     0,     0,     0,
    -137,     0,  -137,     0,  -137,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,  -137,  -137,  -137,    33,   -90,
       1,    34,    35,   -66,     0,  -137,    37,     0,     0,     0,
     100,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,   -90,
      11,     0,   -90,   -90,   -90,    12,   -90,    13,    14,     0,
       0,     0,     0,   -90,     0,    15,   -90,    16,    17,     0,
     -90,     0,   -90,     0,   -90,     0,   -90,     0,     0,     0,
       0,     0,    20,     0,    21,     0,    22,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   -92,     1,    34,    35,   -66,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,   -92,    11,     0,   -92,   -92,   -92,    12,   -92,    13,
      14,     0,     0,     0,     0,   -92,     0,    15,   -92,    16,
      17,     0,   -92,     0,   -92,     0,   -92,     0,   -92,     0,
       0,     0,     0,     0,    20,     0,    21,     0,    22,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,  -176,     1,    34,    35,   -66,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,  -176,    11,     0,     0,     0,     0,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,    15,
       0,    16,    17,     0,    18,     0,    -6,     0,    19,     0,
      -6,     0,     0,     0,     0,     0,    20,     0,    21,     0,
      22,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,  -180,     1,    34,    35,   -66,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,    10,     0,    11,     0,     0,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,     0,
       0,    15,     0,    16,    17,     0,    18,     0,    -6,     0,
      19,     0,    -6,     0,     0,     0,     0,     0,    20,     0,
      21,     0,    22,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,   -48,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   139,   140,    34,
      35,   -47,   143,    36,    37,     0,     0,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   -48,   143,     0,   -48,
     -48,   -48,     0,   -48,     0,     0,     0,     0,     0,     0,
     -48,   -47,     0,   -48,   -47,   -47,   -47,   -48,   -47,   -48,
       0,   -48,     0,   -48,     0,   -47,     0,     0,   -47,   -48,
       0,     0,   -47,     0,   -47,     0,   -47,     0,   -47,     0,
       0,     0,     0,     0,   -47,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,     0,   -48,
       0,     0,   147,   148,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,   -47,     0,     0,   147,   148,     1,
     149,     0,   -66,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     2,   143,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,     0,    11,
     164,     0,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,   183,   145,   146,   147,   148,     0,
     149,     0,   184,    21,   185,    22,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,   165,   166,   147,   148,    36,   167,     1,     0,
       0,   -66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,     0,    11,     0,
       0,     0,     0,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    15,     0,    16,    17,     0,    18,     0,
      -6,     0,    19,     0,    -6,     0,     0,     0,     0,     0,
      20,     0,    21,     0,    22,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       1,    34,    35,   -66,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     2,     0,   -41,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,     0,
      11,     0,     0,     0,     0,    12,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,   -41,    16,    17,   -41,
     -41,   -41,     0,   -41,     0,     0,     0,     0,     0,     0,
     -41,     0,    20,   -41,    21,     0,    22,   -41,     0,   -41,
       0,   -41,    23,   -41,     0,     0,     0,     0,     0,   -41,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     1,    34,    35,    83,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,   -41,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,     0,    11,     0,     1,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,    15,     2,    16,
      17,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,     0,     0,    -4,     0,    21,     0,    22,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,     0,    34,    35,     0,     0,   236,
      37,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    33,     0,     0,    34,    35,     0,
       0,     0,    37,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,   143,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,   143,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,    83,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,     0,     0,
       0,     0,   145,   146,   147,   148,     0,   149,   314,   184,
       0,   185,     0,     0,   145,   146,   147,   148,     0,   149,
       0,   184,     0,   185,     0,     0,   145,   146,   147,   148,
       0,   149,     0,     0,     0,   287,     0,     0,     0,   145,
     146,   147,   148,    84,   149,     0,   324,     0,     0,     0,
       0,   145,   146,   147,   148,     0,   149,   278,   206,     0,
       0,     0,     0,   145,   146,   147,   148,     0,   149,     0,
     281,     0,     0,     0,     0,   145,   146,   147,   148,     0,
     149,     0,   331,    83,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,    83,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,    83,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,   148,    87,   149,   335,
       0,     0,     0,     0,     0,     0,   145,   146,   147,   148,
      84,   149,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,   148,    87,   149,     0,     0,     0,     0,     0,
       0,   145,   146,   147,   148,     0,   149,   271,     0,     0,
       0,     0,     0,   145,   146,   147,   148,     0,   149,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,   148,     0,   149,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     143,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,   148,
       0,   149,     0,     0,     0,     0,     0,     0,   145,   146,
     147,   148,     0,   149,     0,     0,     0,     0,     0,     0,
     145,   146,   147,   148,     0,   149
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-242)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   182,    20,    12,    46,    69,   247,     4,    22,     4,
      14,    12,    82,    20,    98,    53,   102,     5,     6,    57,
       8,     9,    23,    11,    12,    22,    11,    12,    16,    71,
       4,    16,    33,    44,    11,    12,   120,   121,   122,    43,
      11,    12,    20,    85,    30,    16,    46,    30,   132,    35,
      54,    55,    56,    22,    37,    30,    60,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    96,    16,    69,
      99,    71,    47,   157,    97,   159,    30,    68,    87,    33,
      34,    35,    82,    97,    93,    85,    95,    96,    92,    96,
      99,    20,   273,    99,   164,    24,    97,    98,   339,     4,
     184,    98,   186,    98,     0,   303,    94,    95,    96,    97,
      99,    99,    20,   177,    99,    99,    24,    99,     1,   120,
     121,   122,    99,   364,    98,    96,    97,    99,    99,    99,
     131,   132,    15,   175,   176,    99,   334,    20,    21,    22,
     101,    24,    99,    26,    27,    28,    94,    95,    96,    97,
     234,    99,   100,   101,   352,   164,   157,    93,   159,   340,
      11,    12,    22,    30,   164,    16,    33,    96,    35,    70,
      99,    72,    31,    32,    75,   175,   176,   177,    79,    76,
      77,    78,    99,   184,   268,   186,    80,    81,    96,   101,
      73,    74,   101,    74,    74,   237,    22,   101,   100,    82,
      83,    84,    85,    86,    87,   206,    20,    97,    91,    93,
     101,    94,    95,   100,    93,   100,    99,   221,    36,    30,
     103,    99,    82,    83,    84,    85,    86,    87,   110,   111,
     112,   113,   114,   234,   100,   244,   100,   237,   100,   100,
     249,    20,   100,    94,    95,    96,    97,     2,    99,    93,
     100,    99,    99,    51,    30,   100,    11,   100,   100,   100,
     100,   100,    17,    31,    44,    56,    63,   268,    23,    99,
      30,    46,   100,   100,   283,   284,    34,   319,   233,    34,
      35,    33,    37,   325,   355,   326,   266,    23,   183,   307,
     299,   327,   368,   302,   336,   304,   362,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,   351,
      -1,   353,   330,   322,   323,    -1,    -1,    -1,    -1,   319,
     329,    -1,    -1,    -1,   333,   325,   335,    -1,    -1,   338,
     372,    -1,    -1,    -1,    -1,   344,   336,   346,    -1,    -1,
      -1,   350,    -1,    98,    -1,   354,    -1,   348,    -1,   349,
      -1,   351,    -1,   353,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,   371,    -1,   373,   120,   121,   122,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,   234,
      24,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,   268,    -1,    -1,    91,    -1,   273,    94,
      95,    -1,    -1,    -1,    99,   100,   281,    -1,   103,    73,
      -1,    -1,   287,    -1,    -1,    -1,   291,    -1,    82,    83,
      84,    85,    86,    87,    -1,   300,    -1,    91,    -1,    -1,
      94,    95,    -1,     0,     1,    99,    -1,     4,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,   324,
      -1,    -1,    -1,    20,    21,    22,   331,    24,    -1,    26,
      27,    28,    29,    30,    31,   340,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    46,
      47,    48,    49,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     1,    94,    95,     4,
      -1,    98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,    49,    -1,    51,    -1,    53,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     1,    94,
      95,     4,    -1,    98,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    46,    47,    48,    49,    -1,    51,    -1,
      53,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       1,    94,    95,     4,    -1,    98,    99,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    48,    49,    -1,
      51,    -1,    53,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     1,    94,    95,     4,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,
      49,    -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     1,    94,    95,     4,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    49,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     1,    94,    95,     4,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    49,    -1,    51,    -1,    53,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    11,    12,    94,
      95,     0,    16,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    30,    16,    -1,    33,
      34,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    30,    -1,    47,    33,    34,    35,    51,    37,    53,
      -1,    55,    -1,    57,    -1,    44,    -1,    -1,    47,    63,
      -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    63,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    93,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    97,     1,
      99,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,
      99,    -1,   101,    65,   103,    67,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    94,    95,    96,    97,    98,    99,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    48,    49,    -1,    51,    -1,
      53,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
       1,    94,    95,     4,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,     0,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    30,    48,    49,    33,
      34,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    63,    47,    65,    -1,    67,    51,    -1,    53,
      -1,    55,    73,    57,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,     1,    94,    95,     4,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    93,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    -1,     1,    -1,    -1,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    15,    48,
      49,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,
      -1,    -1,    99,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,   103,    -1,    -1,    94,    95,    96,    97,    -1,    99,
      -1,   101,    -1,   103,    -1,    -1,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,
     101,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,
      99,    -1,   101,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    -1,    99,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    31,    36,    38,    39,    46,    48,    49,    51,    55,
      63,    65,    67,    73,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    94,    95,    98,    99,   106,   110,
     111,   114,   115,   116,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   134,   135,   136,   137,   138,   140,
     141,   146,   147,   148,   150,   153,   155,   160,   162,   163,
     164,   165,   166,   102,    82,    83,    84,    85,    86,    87,
     116,   137,   116,     4,    98,   105,   111,    98,   105,   117,
     117,    44,    20,   116,    22,   161,   161,    97,   139,    68,
     103,   111,   112,   113,   116,   142,   143,   144,   146,    99,
      99,    99,    99,    99,    99,    20,    24,    96,    99,   132,
     133,   133,   133,   111,   114,   116,   116,   116,   145,    53,
      57,   159,    99,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    93,    94,    95,    96,    97,    99,
     117,     4,   127,   117,   117,   117,    96,    99,   101,   108,
     117,   164,   127,     0,    32,    94,    95,    99,   120,   127,
      93,   105,    99,   128,   117,   105,   105,   105,    97,   111,
     144,   105,   101,    93,   101,   103,   101,    74,    74,    80,
      81,   109,   109,   109,   109,   109,   109,    20,    96,   131,
     101,   130,   144,   144,   144,   100,   101,   100,   111,   144,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,    20,   144,    70,
      72,    75,    79,   107,    17,   144,    98,   105,   120,   116,
     116,   116,    30,    37,   152,   116,   116,   127,   127,   164,
      97,   113,   116,   116,   148,   144,   116,   144,    93,    93,
     100,   100,   100,   100,   100,   100,   101,   111,    99,   100,
     117,   100,   100,    99,    99,   108,   144,   127,   100,    36,
     105,   101,   100,   129,   152,    30,   105,   103,   116,    20,
     132,    93,   144,   113,   116,    76,    77,    78,    30,    33,
      34,    35,   149,   151,   116,   105,   105,    51,    30,   116,
     100,   116,   100,   100,   100,   100,   100,   100,    31,   105,
     116,   105,    33,   149,   101,   105,    44,   156,   157,   161,
      63,   101,    56,   158,   127,    32,   105,   105,   116,   127,
     128,   157,    30,    47,   154,   105,   161,   116,    99,   105,
     149,   105,   127,   105,   152,   113,    46,   105,   105,   111,
     127,   105,   127,   149,   127,   105,   129,   100,    30,   151,
     105,   152,   105,   159,   105,   127,   105
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
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 91 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 99 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none);
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
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen, boost::none);
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
				ParseNode & exp_from = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER, "1" }));

				slice.addchild(new ParseNode(exp_from)); // slice from 1
				slice.addchild(new ParseNode(exp_to)); // slice to

				ParseNode * dimen = new ParseNode(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				newnode->addchild(dimen); // def slice

				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen, boost::none);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 136 "for90.y"
    {
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 143 "for90.y"
    {
				/* const value */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 152 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 157 "for90.y"
    {
				ParseNode & variable_elem = (yyvsp[(2) - (3)]);
				ParseNode * variable_desc = & (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr);
				/* merge attrs */
				newnode.attr = variable_elem.attr->clone();
				//dynamic_cast<VariableDescAttr *>(newnode.attr)->merge(*dynamic_cast<VariableDescAttr *>(variable_desc->attr));
				get_variabledesc_attr(&newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 171 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 180 "for90.y"
    {
				int kind;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &kind);

				/* type size */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // kind
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, kind);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 191 "for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &len);

				/* string length */
				ParseNode * newnode = new ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }), nullptr); // len
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len);
				(yyval) = *newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 205 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 210 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 214 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 219 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 223 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 227 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 236 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 243 "for90.y"
    {
				/* arr[from : to] */
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				(yyval) = gen_slice(exp1, exp2);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 252 "for90.y"
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

  case 29:
/* Line 1792 of yacc.c  */
#line 262 "for90.y"
    {
				ParseNode & lb = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				ParseNode & ub = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				/* target code of slice depend on context */
				(yyval) = gen_slice(lb, ub);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 271 "for90.y"
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

  case 31:
/* Line 1792 of yacc.c  */
#line 281 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				/* target code of slice depend on context */
				ParseNode & slice = (yyvsp[(1) - (3)]);
				ParseNode & dimen_slice = (yyvsp[(3) - (3)]);
				(yyval) = gen_flattern(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 291 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 298 "for90.y"
    {
				/* IMPORTANT: not `exp ',' dimen_slice` but `exp ',' paramtable`, or will cause confliction */
				ParseNode & exp = (yyvsp[(1) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				ParseNode newnode = ParseNode();
				switch (argtable.fs.CurrentTerm.token) {
					case TokenMeta::NT_ARGTABLE_PURE:
					case TokenMeta::NT_DIMENSLICE:
					case TokenMeta::NT_PARAMTABLE:
					case TokenMeta::NT_PARAMTABLE_DIMENSLICE:
						newnode = gen_paramtable(exp, argtable);
						break;
					default:
						print_error("Illegal dimen_slice", argtable);
				}
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 318 "for90.y"
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

  case 35:
/* Line 1792 of yacc.c  */
#line 328 "for90.y"
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

  case 36:
/* Line 1792 of yacc.c  */
#line 339 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 343 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 348 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 356 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 364 "for90.y"
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
#line 372 "for90.y"
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
#line 380 "for90.y"
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
#line 388 "for90.y"
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
#line 396 "for90.y"
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
#line 404 "for90.y"
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
#line 412 "for90.y"
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
#line 420 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 427 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 434 "for90.y"
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
#line 442 "for90.y"
    {
				// xor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 451 "for90.y"
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
#line 459 "for90.y"
    {
				// nor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "!(%s == %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 468 "for90.y"
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
#line 476 "for90.y"
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
#line 484 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 491 "for90.y"
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
#line 499 "for90.y"
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
#line 507 "for90.y"
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
#line 515 "for90.y"
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
#line 523 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 529 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 534 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 544 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 548 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 553 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 559 "for90.y"
    {
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s;");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 569 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 575 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 579 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 583 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 587 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 591 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 596 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 601 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 606 "for90.y"
    {
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 610 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 627 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 633 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 642 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 649 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 654 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s\n%s", TokenMeta::NT_SUITE);;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 659 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 664 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 677 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 681 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 685 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 689 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 694 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 701 "for90.y"
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

  case 106:
/* Line 1792 of yacc.c  */
#line 712 "for90.y"
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

  case 107:
/* Line 1792 of yacc.c  */
#line 726 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 734 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 743 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 751 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 756 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 761 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 766 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 776 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 782 "for90.y"
    {
				// now translated in pre_map
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
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 803 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 808 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str(), "%d", &len);
				set_variabledesc_attr(&newnode, boost::none, boost::none, boost::none, boost::none, len);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 816 "for90.y"
    {
				// $$ = gen_type($1, $3);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 823 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 828 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 834 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 840 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 848 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 858 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (3)]);
				ParseNode & variable_desc = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 869 "for90.y"
    { 
				// useless reduction
				/* paramtable is used in function decl */
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 874 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 883 "for90.y"
    {
				// array initial values 
				// 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 892 "for90.y"
    {
				// from rule ` dimen_slice : exp ',' paramtable `
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 896 "for90.y"
    {
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 900 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 907 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 915 "for90.y"
    {
				/* no params */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 923 "for90.y"
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

  case 139:
/* Line 1792 of yacc.c  */
#line 935 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode & _generate_stmt = (yyvsp[(2) - (3)]);
				(yyval) = gen_hiddendo(_generate_stmt);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 943 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 950 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				// rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule because \
				// these two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict 
				// so either that `variable '(' dimen_slice ')'` is an `exp`
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 961 "for90.y"
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

  case 145:
/* Line 1792 of yacc.c  */
#line 1001 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite_true = (yyvsp[(5) - (7)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1008 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (10)]);
				ParseNode & suite_true = (yyvsp[(5) - (10)]); 
				ParseNode & suite_else = (yyvsp[(8) - (10)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1016 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (8)]);
				ParseNode & suite_true = (yyvsp[(5) - (8)]);
				ParseNode & elseif = (yyvsp[(6) - (8)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1024 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]);
				ParseNode & elseif = (yyvsp[(6) - (11)]);
				ParseNode & suite_else = (yyvsp[(9) - (11)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1033 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1040 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode & stmt_true = (yyvsp[(3) - (3)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1048 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1056 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1068 "for90.y"
    {
				ParseNode & suite = (yyvsp[(3) - (5)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1074 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(2) - (10)]);
				ParseNode & exp_from = (yyvsp[(4) - (10)]);
				ParseNode & exp_to = (yyvsp[(6) - (10)]);
				ParseNode & step = gen_promote(TokenMeta::NT_EXPRESSION, gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = (yyvsp[(8) - (10)]); 
				(yyval) = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1084 "for90.y"
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

  case 158:
/* Line 1792 of yacc.c  */
#line 1094 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1105 "for90.y"
    {
				ParseNode & select = (yyvsp[(1) - (9)]);
				ParseNode & exp = (yyvsp[(4) - (9)]);
				ParseNode & case_stmt = (yyvsp[(7) - (9)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1113 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1121 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_CASES, "" }), nullptr);
				newnode.addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1129 "for90.y"
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

  case 165:
/* Line 1792 of yacc.c  */
#line 1140 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1145 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1155 "for90.y"
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

  case 172:
/* Line 1792 of yacc.c  */
#line 1171 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1182 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1190 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1195 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1201 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild(new ParseNode((yyvsp[(1) - (1)]))); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1210 "for90.y"
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

  case 178:
/* Line 1792 of yacc.c  */
#line 1222 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1228 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 3797 "for90.tab.cpp"
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
#line 1234 "for90.y"

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
