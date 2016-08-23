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
#include "../tokenizer.h"
#include "../attribute.h"
#include "../parser.h"
#include "../cgen.h"

// 前置声明, 不然编译不过
void yyerror(const char* s); 
extern int yylex();
extern void set_buff(const std::string & code);
extern void release_buff();
#define YYDEBUG 1
#define YYERROR_VERBOSE
#define MAX_CODE_LENGTH 65535
char codegen_buf[MAX_CODE_LENGTH];
using namespace std;

/* Line 371 of yacc.c  */
#line 91 "for90.tab.cpp"

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
     _YY_DELIM = 303,
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
     _YY_DESCRIBER = 316,
     YY_IMPLICIT = 317,
     YY_NONE = 318,
     YY_USE = 319,
     YY_PARAMETER = 320,
     YY_FORMAT = 321,
     YY_ENTRY = 322,
     YY_DIMENSION = 323,
     YY_ARRAYINITIAL_START = 324,
     YY_ARRAYINITIAL_END = 325,
     YY_INTENT = 326,
     YY_IN = 327,
     YY_OUT = 328,
     YY_INOUT = 329,
     _YY_TYPEDEF = 330,
     YY_INTEGER_T = 331,
     YY_FLOAT_T = 332,
     YY_STRING_T = 333,
     YY_COMPLEX_T = 334,
     YY_BOOL_T = 335,
     _YY_COMMAND = 336,
     YY_WRITE = 337,
     YY_READ = 338,
     YY_PRINT = 339,
     YY_OPEN = 340,
     YY_CLOSE = 341,
     YY_CALL = 342
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
#line 244 "for90.tab.cpp"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   626

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  212

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      93,    94,    91,    89,    95,    90,     2,    92,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    97,     2,
       2,    88,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    11,    16,    21,
      26,    31,    34,    38,    39,    41,    43,    45,    47,    49,
      51,    54,    56,    58,    60,    64,    70,    72,    76,    82,
      84,    89,    94,    99,   104,   109,   114,   118,   121,   124,
     126,   130,   132,   133,   135,   137,   139,   141,   143,   145,
     147,   149,   151,   155,   158,   160,   163,   164,   165,   167,
     168,   170,   172,   174,   176,   178,   182,   188,   190,   192,
     194,   196,   198,   203,   205,   209,   213,   217,   223,   224,
     232,   236,   240,   244,   253,   265,   275,   287,   293,   300,
     307,   318,   331,   346,   348,   350,   359
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     133,     0,    -1,     5,    -1,    -1,    53,    -1,   100,    -1,
      -1,    71,    93,    72,    94,    -1,    71,    93,    73,    94,
      -1,    71,    93,    74,    94,    -1,    68,    93,   107,    94,
      -1,    95,   101,    -1,    95,   101,   102,    -1,    -1,    23,
      -1,    22,    -1,    26,    -1,    29,    -1,    30,    -1,    28,
      -1,     1,    96,    -1,    24,    -1,   104,    -1,   123,    -1,
     109,    97,   109,    -1,   109,    97,   109,    97,   109,    -1,
     106,    -1,   106,    95,   106,    -1,   105,    93,   110,    94,
      99,    -1,   108,    -1,    93,   109,    94,    99,    -1,   109,
      89,   109,    99,    -1,   109,    90,   109,    99,    -1,   109,
      91,   109,    99,    -1,   109,    92,   109,    99,    -1,   109,
      18,   109,    99,    -1,    90,   109,    99,    -1,   103,    99,
      -1,   105,    99,    -1,   109,    -1,   109,    95,   110,    -1,
     107,    -1,    -1,   109,    -1,   124,    -1,   113,    -1,   112,
      -1,   115,    -1,   114,    -1,   122,    -1,   128,    -1,   130,
      -1,   109,    88,   109,    -1,    62,    63,    -1,   111,    -1,
     111,   116,    -1,    -1,    -1,    93,    -1,    -1,    94,    -1,
      91,    -1,    22,    -1,    91,    -1,    26,    -1,   119,    95,
     120,    -1,    82,   117,   121,   118,   110,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,   123,   102,
      19,   125,    -1,   104,    -1,   104,    88,   109,    -1,   104,
      88,   127,    -1,   104,    95,   125,    -1,   104,    88,   109,
      95,   125,    -1,    -1,   109,    95,   104,    88,   109,    95,
     109,    -1,    69,   110,    70,    -1,    69,   126,    70,    -1,
      69,   109,    70,    -1,    33,   109,    34,    99,   116,    32,
      33,    99,    -1,    33,   109,    34,    99,   116,    35,    99,
     116,    32,    33,    99,    -1,    33,   109,    34,    99,   116,
     129,    32,    33,    99,    -1,    33,   109,    34,    99,   116,
     129,    35,    99,   116,    32,    33,    -1,    36,   109,    34,
      99,   116,    -1,    36,   109,    34,    99,   116,   129,    -1,
      38,    99,   116,    32,    38,    99,    -1,    38,   104,    88,
     109,    95,   109,    99,   116,    32,    38,    -1,    38,   104,
      88,   109,    95,   109,    95,   109,    99,   116,    32,    38,
      -1,   100,    51,   104,    93,   125,    94,    54,    93,   104,
      94,    99,   116,    32,    51,    -1,   116,    -1,   131,    -1,
      49,    24,    99,   132,    32,    49,    24,    99,    -1,    49,
      99,   132,    32,    49,    99,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    50,    52,    53,    54,    56,    65,    75,
      84,   104,   110,   121,   129,   136,   142,   148,   154,   160,
     169,   171,   178,   178,   185,   196,   208,   219,   233,   248,
     261,   274,   284,   294,   304,   314,   324,   334,   339,   347,
     359,   372,   384,   388,   403,   415,   416,   417,   418,   420,
     422,   422,   424,   436,   445,   454,   466,   470,   471,   472,
     473,   474,   479,   484,   489,   495,   506,   543,   549,   555,
     561,   567,   575,   664,   681,   698,   716,   733,   750,   758,
     769,   780,   802,   838,   853,   870,   886,   903,   919,   935,
     949,   966,   985,  1127,  1132,  1138,  1144
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_YY_VOID", "YY_REQ_MORE", "YY_CRLF",
  "_YY_OP", "YY_GT", "YY_GE", "YY_EQ", "YY_LE", "YY_LT", "YY_NEQ",
  "YY_NEQV", "YY_EQV", "YY_ANDAND", "YY_OROR", "YY_NOT", "YY_POWER",
  "YY_DOUBLECOLON", "YY_NEG", "_YY_TYPE", "YY_INTEGER", "YY_FLOAT",
  "YY_WORD", "YY_OPERATOR", "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX",
  "YY_TRUE", "YY_FALSE", "_YY_CONTROL", "YY_END", "YY_IF", "YY_THEN",
  "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO", "YY_ENDDO", "YY_CONTINUE",
  "YY_BREAK", "YY_WHILE", "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE",
  "YY_CASE", "YY_ENDCASE", "_YY_DELIM", "YY_PROGRAM", "YY_ENDPROGRAM",
  "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT",
  "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE",
  "YY_BLOCK", "YY_ENDBLOCK", "_YY_DESCRIBER", "YY_IMPLICIT", "YY_NONE",
  "YY_USE", "YY_PARAMETER", "YY_FORMAT", "YY_ENTRY", "YY_DIMENSION",
  "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN",
  "YY_OUT", "YY_INOUT", "_YY_TYPEDEF", "YY_INTEGER_T", "YY_FLOAT_T",
  "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T", "_YY_COMMAND", "YY_WRITE",
  "YY_READ", "YY_PRINT", "YY_OPEN", "YY_CLOSE", "YY_CALL", "'='", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "','", "'\\n'", "':'", "$accept",
  "crlf", "dummy_function_iden", "dummy_variable_iden_1",
  "dummy_variable_iden", "literal", "variable", "callable", "slice",
  "dimen_slice", "function_array", "exp", "argtable", "stmt",
  "output_stmt", "compound_stmt", "let_stmt", "dummy_stmt", "suite",
  "_optional_lbrace", "_optional_rbrace", "_optional_device",
  "_optional_formatter", "io_info", "write", "type_spec", "var_def",
  "paramtable", "_generate_stmt", "array_builder", "if_stmt",
  "elseif_stmt", "do_stmt", "function_decl", "wrapper", "program", YY_NULL
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
     335,   336,   337,   338,   339,   340,   341,   342,    61,    43,
      45,    42,    47,    40,    41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   105,   105,   106,   106,   107,   107,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   112,
     113,   113,   114,   115,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   122,   123,   123,   123,
     123,   123,   124,   125,   125,   125,   125,   125,   125,   126,
     127,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   131,   132,   132,   133,   133
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     0,     4,     4,     4,
       4,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     5,     1,     3,     5,     1,
       4,     4,     4,     4,     4,     4,     3,     2,     2,     1,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     0,     0,     1,     0,
       1,     1,     1,     1,     1,     3,     5,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     5,     0,     7,
       3,     3,     3,     8,    11,     9,    11,     5,     6,     6,
      10,    12,    14,     1,     1,     8,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     2,     3,     0,     1,     0,     0,    15,
      14,    21,    16,    19,    17,    18,     0,     3,     4,     0,
      67,    68,    69,    70,    71,    57,     0,     0,     0,     3,
      22,     3,    29,    43,     0,    46,    45,    48,    47,    93,
      49,    23,    44,    50,    51,    94,     0,     0,    20,     0,
      23,     0,     0,    53,    58,     0,     3,     0,     0,    37,
       0,    38,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     3,     0,     0,    62,    61,     0,    59,
      36,     3,     0,    26,    41,    39,     0,     3,    52,     3,
       3,     3,     3,     0,     0,    11,    78,     3,     0,     0,
       0,     0,     0,    60,     0,    30,    78,     0,     0,     0,
       3,    35,    31,    32,    33,    34,     0,     0,    12,    73,
      72,    96,     3,     0,     3,     0,    64,    63,    65,    66,
       0,    27,     0,    40,    24,    28,     0,     0,     0,     0,
       0,    78,    95,     0,     3,     0,     0,    89,     3,     0,
       0,    10,     7,     8,     9,     0,    74,    75,    76,     3,
       0,     0,     0,     3,     0,     0,     0,    25,     0,     0,
       0,    78,    83,     0,     3,     3,     0,     3,     0,     0,
      82,     0,    80,    81,    77,     0,     0,    85,     0,     0,
       0,     0,    22,     3,    87,     0,     0,    90,     3,     0,
      84,    88,    86,     0,     0,     0,    91,     0,     0,     0,
      79,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    28,    95,    70,    29,    30,    31,    83,    84,
      32,    33,   133,    34,    35,    36,    37,    38,    39,    55,
     104,    78,   128,    79,    40,    50,    42,   120,   170,   157,
      43,   146,    44,    45,    46,     2
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
     -40,     7,    22,   -99,    18,   317,   -99,   317,   -62,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   533,     8,   -99,   -28,
     -99,   -99,   -99,   -99,   -99,   -55,   533,   533,   -15,    18,
     -99,     0,   -99,   246,   352,   -99,   -99,   -99,   -99,   -99,
     -99,   -12,   -99,   -99,   -99,   -99,     5,    10,   -99,   406,
     -99,   515,   -49,   -99,   -99,   -21,    61,   393,    20,   -99,
     237,   -99,   533,   533,   533,   533,   533,   533,   -99,   -57,
      28,    -4,     1,    18,    17,   533,   -99,   -99,   -44,   -42,
     -99,    18,   -39,   -38,   -99,   231,   -41,    61,   399,    61,
      61,    61,    61,   -37,   -35,   -36,    20,    18,    40,   424,
      36,    77,   -20,   -99,   443,   -99,    20,   533,   218,   533,
      18,   -99,   -99,   -99,   -99,   -99,   533,   -47,   -99,   -78,
     -99,   -99,    18,   -17,    18,   533,   -99,   -99,   -99,   -99,
     -19,   -99,   213,   -99,   267,   -99,   -18,   -16,   -13,   -10,
      39,    20,   -99,    52,    18,   533,   -11,   -99,    15,    38,
     533,   -99,   -99,   -99,   -99,   343,   182,   -99,   -99,    18,
     515,   421,    67,    18,   533,   515,     9,   399,   192,    31,
      33,    20,   -99,    79,    18,    18,   515,    61,    80,    20,
     -99,   343,   -99,   -99,   -99,    81,   424,   -99,    90,   515,
      75,    30,    51,    18,    91,    93,    96,   -99,    18,   533,
     -99,   -99,   -99,   102,   515,   311,   -99,   109,   533,    94,
     399,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,    -1,   -99,   -99,    47,   -99,    24,   -99,    37,    32,
     -99,    71,   -56,   -99,   -99,   -99,   -99,   -99,    26,   -99,
     -99,   -99,   -99,   -99,   -99,    -5,   -99,   -98,   -99,   -99,
     -99,   -45,   -99,   -99,   147,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
      41,    76,    41,     7,    86,     3,   126,   -13,   130,     1,
     140,    93,     3,     3,    94,   143,    51,   141,   144,   145,
       3,   162,     6,     3,   163,   137,   138,   139,    59,    41,
      61,     4,    11,    62,    48,    53,    58,    71,    54,    75,
       8,    52,    72,   158,    11,    97,    41,    96,   129,   100,
      98,   102,   103,   110,   106,    80,   116,   107,   117,    69,
      68,     9,    10,    11,   122,    12,     3,    13,    14,    15,
      77,   127,    99,   184,   124,   149,   151,    74,   152,    62,
     105,   153,    82,    69,   154,   159,   111,    49,   112,   113,
     114,   115,   166,    60,    41,    62,   121,    56,    57,   169,
     175,   182,   179,   183,    64,    65,    66,    67,   155,   135,
     164,   185,   190,   197,   193,    20,    21,    22,    23,    24,
     119,   142,   195,   147,   198,   123,   202,   145,   203,    26,
     119,    85,    27,    87,    88,    89,    90,    91,    92,   199,
     206,   209,   118,   160,   131,   211,   101,   165,   136,   201,
      64,    65,    66,    67,    47,    41,     0,     0,   172,     0,
      41,     0,   176,     0,     0,   119,    64,    65,    66,    67,
       0,    41,   125,   186,   187,    85,   189,     0,   132,    85,
     134,    41,     0,     0,    41,     0,   173,   132,     0,     0,
       0,   178,   200,     0,     0,   119,   148,   204,     0,    41,
      62,     0,   188,   191,     0,   192,     0,     0,     0,     0,
      62,   156,   194,     0,     0,   196,   161,     0,     0,     8,
       0,   167,     0,     0,     0,     0,   168,     0,     0,     0,
     207,    62,     0,     0,     0,   177,     0,     0,     8,     0,
       9,    10,    11,     0,    12,     0,    13,    14,    15,    62,
     -42,   -42,    85,   -42,   -42,     0,   -42,     0,     0,     9,
      10,    11,   180,    12,    62,    13,    14,    15,     0,     0,
     205,    64,    65,    66,    67,     0,     0,   171,     0,   210,
     -42,    64,    65,    66,    67,    62,     0,   181,   -42,   109,
       0,     0,     0,     0,    20,    21,    22,    23,    24,     0,
     -42,     0,    64,    65,    66,    67,     0,     0,    26,     0,
     109,    27,   -42,    20,    21,    22,    23,    24,     8,     0,
      64,    65,    66,    67,     0,     0,   108,    26,   109,    62,
      27,   -42,     0,     0,    63,    64,    65,    66,    67,     9,
      10,    11,     0,    12,     8,    13,    14,    15,     0,   -56,
      16,     0,     0,     8,     0,    17,    64,    65,    66,    67,
       0,     0,     0,     0,   150,     9,    10,    11,    -6,    12,
      18,    13,    14,    15,     9,    10,    11,     0,    12,    19,
      13,    14,    15,     0,   -54,    16,     0,   -54,   -54,     0,
      17,     0,     0,    20,    21,    22,    23,    24,     0,    25,
      64,    65,    66,    67,     0,     0,   208,    26,     0,     0,
      27,    62,     0,   -42,    19,     0,     0,    62,     0,    20,
      21,    22,    23,    24,    62,     8,     0,     0,    20,    21,
      22,    23,    24,    26,    25,     0,    27,     0,     0,    62,
      73,     0,    26,     0,     8,    27,     9,    10,    11,     0,
      12,     0,    13,    14,    15,   174,   -56,    16,     0,   -56,
     -56,     0,    17,     0,     0,     9,    10,    11,     0,    12,
       0,    13,    14,    15,     0,   -42,   -42,     0,   -42,   -42,
       0,   -42,    64,    65,    66,    67,    19,    81,    64,    65,
      66,    67,     0,     0,     0,    64,    65,    66,    67,     0,
      20,    21,    22,    23,    24,   -42,    25,     0,     0,     0,
      64,    65,    66,    67,    26,     0,     8,    27,     0,    20,
      21,    22,    23,    24,     0,   -42,     0,     0,     0,     0,
       0,     0,     0,    26,     8,     0,    27,     9,    10,    11,
       0,    12,     0,    13,    14,    15,     0,   -56,    16,     0,
       0,     0,     0,    17,     0,     9,    10,    11,     0,    12,
       0,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    27,    20,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,    27
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       5,    22,     7,     4,    60,     5,    26,    19,   106,    49,
      88,    68,     5,     5,    71,    32,    17,    95,    35,    36,
       5,    32,     0,     5,    35,    72,    73,    74,    29,    34,
      31,    24,    24,    18,    96,    63,    51,    32,    93,    88,
       1,    17,    32,   141,    24,    49,    51,    19,   104,    32,
      49,    95,    94,    94,    93,    56,    93,    95,    93,    95,
      34,    22,    23,    24,    24,    26,     5,    28,    29,    30,
      91,    91,    73,   171,    38,    94,    94,    51,    94,    18,
      81,    94,    58,    95,    94,    33,    87,    16,    89,    90,
      91,    92,    54,    93,    99,    18,    97,    26,    27,   155,
      33,    70,    93,    70,    89,    90,    91,    92,    69,   110,
      95,    32,    32,    38,    33,    76,    77,    78,    79,    80,
      96,   122,    32,   124,    94,    99,    33,    36,    32,    90,
     106,    60,    93,    62,    63,    64,    65,    66,    67,    88,
      38,    32,    95,   144,   107,    51,    75,   148,   116,   194,
      89,    90,    91,    92,     7,   160,    -1,    -1,   159,    -1,
     165,    -1,   163,    -1,    -1,   141,    89,    90,    91,    92,
      -1,   176,    95,   174,   175,   104,   177,    -1,   107,   108,
     109,   186,    -1,    -1,   189,    -1,   160,   116,    -1,    -1,
      -1,   165,   193,    -1,    -1,   171,   125,   198,    -1,   204,
      18,    -1,   176,   179,    -1,   181,    -1,    -1,    -1,    -1,
      18,   140,   186,    -1,    -1,   189,   145,    -1,    -1,     1,
      -1,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
     204,    18,    -1,    -1,    -1,   164,    -1,    -1,     1,    -1,
      22,    23,    24,    -1,    26,    -1,    28,    29,    30,    18,
      32,    33,   181,    35,    36,    -1,    38,    -1,    -1,    22,
      23,    24,    70,    26,    18,    28,    29,    30,    -1,    -1,
     199,    89,    90,    91,    92,    -1,    -1,    95,    -1,   208,
      62,    89,    90,    91,    92,    18,    -1,    95,    70,    97,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,
      82,    -1,    89,    90,    91,    92,    -1,    -1,    90,    -1,
      97,    93,    94,    76,    77,    78,    79,    80,     1,    -1,
      89,    90,    91,    92,    -1,    -1,    95,    90,    97,    18,
      93,    94,    -1,    -1,    88,    89,    90,    91,    92,    22,
      23,    24,    -1,    26,     1,    28,    29,    30,    -1,    32,
      33,    -1,    -1,     1,    -1,    38,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,    97,    22,    23,    24,    51,    26,
      53,    28,    29,    30,    22,    23,    24,    -1,    26,    62,
      28,    29,    30,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    -1,    -1,    76,    77,    78,    79,    80,    -1,    82,
      89,    90,    91,    92,    -1,    -1,    95,    90,    -1,    -1,
      93,    18,    -1,    70,    62,    -1,    -1,    18,    -1,    76,
      77,    78,    79,    80,    18,     1,    -1,    -1,    76,    77,
      78,    79,    80,    90,    82,    -1,    93,    -1,    -1,    18,
      34,    -1,    90,    -1,     1,    93,    22,    23,    24,    -1,
      26,    -1,    28,    29,    30,    34,    32,    33,    -1,    35,
      36,    -1,    38,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    89,    90,    91,    92,    62,    94,    89,    90,
      91,    92,    -1,    -1,    -1,    89,    90,    91,    92,    -1,
      76,    77,    78,    79,    80,    62,    82,    -1,    -1,    -1,
      89,    90,    91,    92,    90,    -1,     1,    93,    -1,    76,
      77,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,     1,    -1,    93,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,    -1,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,   133,     5,    24,    99,     0,    99,     1,    22,
      23,    24,    26,    28,    29,    30,    33,    38,    53,    62,
      76,    77,    78,    79,    80,    82,    90,    93,   100,   103,
     104,   105,   108,   109,   111,   112,   113,   114,   115,   116,
     122,   123,   124,   128,   130,   131,   132,   132,    96,   109,
     123,    99,   104,    63,    93,   117,   109,   109,    51,    99,
      93,    99,    18,    88,    89,    90,    91,    92,   116,    95,
     102,    32,    32,    34,   116,    88,    22,    91,   119,   121,
      99,    94,   104,   106,   107,   109,   110,   109,   109,   109,
     109,   109,   109,    68,    71,   101,    19,    49,    49,    99,
      32,   109,    95,    94,   118,    99,    93,    95,    95,    97,
      94,    99,    99,    99,    99,    99,    93,    93,   102,   104,
     125,    99,    24,   116,    38,    95,    26,    91,   120,   110,
     125,   106,   109,   110,   109,    99,   107,    72,    73,    74,
      88,    95,    99,    32,    35,    36,   129,    99,   109,    94,
      97,    94,    94,    94,    94,    69,   109,   127,   125,    33,
      99,   109,    32,    35,    95,    99,    54,   109,   109,   110,
     126,    95,    99,   116,    34,    33,    99,   109,   116,    93,
      70,    95,    70,    70,   125,    32,    99,    99,   116,    99,
      32,   104,   104,    33,   116,    32,   116,    38,    94,    88,
      99,   129,    33,    32,    99,   109,    38,   116,    95,    32,
     109,    51
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
        case 7:
/* Line 1792 of yacc.c  */
#line 57 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(in)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = false;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 66 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(out)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 76 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 85 "for90.y"
    {
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode * newnode = new ParseNode();
				ParseNode * slice = new ParseNode((yyvsp[(3) - (4)]));
				newnode->addchild(slice); // def slice
				int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
				sprintf(codegen_buf, "(%s, %s)"
					/* from, to */
					, slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
					, slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = slice;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 105 "for90.y"
    {
				ParseNode * newnode = new ParseNode((yyvsp[(1) - (2)]));
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 111 "for90.y"
    {				
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				// TODO do not add child
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 121 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 130 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // float number
				(yyval) = *newnode;
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 137 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // int number
				(yyval) = *newnode;
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 143 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // string
				(yyval) = *newnode;
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 149 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "true" }; // bool true
				(yyval) = *newnode;
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 155 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "false" }; // bool false
				(yyval) = *newnode;
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 161 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				newnode->fs.CurrentTerm = Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") "}; // complex
				(yyval) = *newnode;
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 172 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // variant
				(yyval) = *newnode;
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 179 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 186 "for90.y"
    {
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // lower bound
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // upper bound
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 197 "for90.y"
    {
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (5)]))); // lower bound
				newnode->addchild(new ParseNode((yyvsp[(3) - (5)]))); // upper bound
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // step
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 209 "for90.y"
    {
				/* 1d array */
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // only 1 slice
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 220 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // 
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)])));
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 234 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s(%s)", (yyvsp[(1) - (5)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (5)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (5)]))); // function/array name
				newnode->addchild(new ParseNode((yyvsp[(3) - (5)]))); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 249 "for90.y"
    {
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // function_array
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 262 "for90.y"
    {
				/* `callable '(' argtable ')'` rule has priority over this rule  */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "( %s )", (yyvsp[(2) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); 
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 275 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s + %s", (yyvsp[(1) - (4)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); // +
				newnode->addchild(new ParseNode((yyvsp[(3) - (4)]))); // tight operand exp
				(yyval) = *newnode;
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 285 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s - %s", (yyvsp[(1) - (4)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); // -
				newnode->addchild(new ParseNode((yyvsp[(3) - (4)]))); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 295 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s * %s", (yyvsp[(1) - (4)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); // *
				newnode->addchild(new ParseNode((yyvsp[(3) - (4)]))); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 305 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s / %s", (yyvsp[(1) - (4)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); // /
				newnode->addchild(new ParseNode((yyvsp[(3) - (4)]))); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 315 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "power(%s, %s)", (yyvsp[(1) - (4)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (4)]))); // **
				newnode->addchild(new ParseNode((yyvsp[(3) - (4)]))); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 325 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "(-%s)", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // (-)
				newnode->addchild(new ParseNode((yyvsp[(2) - (3)]))); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 335 "for90.y"
    { 
				// 
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 340 "for90.y"
    {
				// may cause reduction-reduction conflict when use `variable` instead of `callable`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				string x = (yyvsp[(1) - (2)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 348 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 360 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s, %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // argtable
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 373 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_DIMENSLICE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // dimen_slice
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 384 "for90.y"
    {
				// TODO : argtable can also be empty
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 389 "for90.y"
    {
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s ;\n", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 404 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s \n", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // var_def
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 425 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // left operand exp
				newnode->addchild(new ParseNode((yyvsp[(2) - (3)]))); // =
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 437 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, "" };
				// dummy stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 446 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s \n", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 455 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s \n %s \n", (yyvsp[(1) - (2)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (2)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (2)]))); // stmt
				newnode->addchild(new ParseNode((yyvsp[(2) - (2)]))); // suite
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 466 "for90.y"
    {
				/* suite can be empty but stmt can not */
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 475 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				update_pos((yyval));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 480 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
				update_pos((yyval));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 485 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
				update_pos((yyval));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 490 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
				update_pos((yyval));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 496 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // formatter
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 507 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(3) - (5)]))); // ioinfo
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // argtable
				ParseNode * argtbl = &(yyvsp[(5) - (5)]);
				ParseNode * formatter = (yyvsp[(3) - (5)]).child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", (yyvsp[(3) - (5)]).child[1]->fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (5)]).fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				}
				else {
					/* NT_AUTOFORMATTER */
					string coutcode = "cout";
					/* enumerate argtable */
					// TODO the while loop is wrong, there is need for while loop. ref: var_def code
					//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
						// for all non-flatterned argtable
						for (int i = 0; i < argtbl->child.size(); i++)
						{
							// for each variable in flatterned argtable
							coutcode += "<<";
							coutcode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					coutcode += ";";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
				}
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 544 "for90.y"
    {
				(yyvsp[(1) - (1)]).fs.CurrentTerm.what = typename_map.at((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 550 "for90.y"
    {
				(yyvsp[(1) - (1)]).fs.CurrentTerm.what = typename_map.at((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 556 "for90.y"
    {
				(yyvsp[(1) - (1)]).fs.CurrentTerm.what = typename_map.at((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 562 "for90.y"
    {
				(yyvsp[(1) - (1)]).fs.CurrentTerm.what = typename_map.at((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 568 "for90.y"
    {
				(yyvsp[(1) - (1)]).fs.CurrentTerm.what = typename_map.at((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 576 "for90.y"
    {
				/* array decl */
				ParseNode * newnode = new ParseNode();
				ParseNode * ty = new ParseNode((yyvsp[(1) - (4)]));
				newnode->addchild(ty); // type
				ParseNode * iden = &(yyvsp[(2) - (4)]); // dummy_variable_iden
				VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(iden->attr);
				ParseNode * slice = vardescattr->desc.slice;
				newnode->addchild(slice); // slice == nullptr if this is not array
				ParseNode * pn = new ParseNode((yyvsp[(4) - (4)])); // paramtable
				newnode->addchild(pn); // paramtable
				string arr_decl = ""; string var_decl = "";

				if (slice != nullptr)
				{
					/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
			/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
						for (int i = 0; i < pn->child.size(); i++)
						{
							// for each variable in flatterned paramtable
							int sliceid = 0;
							sprintf(codegen_buf, "forarr<%s> %s%s;\n", ty->fs.CurrentTerm.what.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str()
								/* slice from to */, slice->fs.CurrentTerm.what.c_str());
							arr_decl += codegen_buf;
							/* set initial value */
							if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
								sprintf(codegen_buf, "%s.init%s;\n", pn->child[i]->child[0]->fs.CurrentTerm.what.c_str(), pn->child[i]->child[1]->fs.CurrentTerm.what.c_str());
							}
							else if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_EXP) {
								string formatter = (pn->child[i]->child[1]->fs.CurrentTerm.what + ";\n");
								sprintf(codegen_buf, formatter.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
							}
							arr_decl += codegen_buf;
						}
						if (pn->child.size() >= 2)
						{
							/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
							/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
							pn = pn->child[1];
						}
					} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
				}
				else {
					sprintf(codegen_buf, "%s ", ty->fs.CurrentTerm.what.c_str());
					var_decl += string(codegen_buf);
					/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
						for (int i = 0; i < pn->child.size(); i++)
						{
							if (i > 0) {
								var_decl += ", ";
							}
							if (vardescattr->desc.reference) {
								sprintf(codegen_buf, " & %s", pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
							}
							else {
								sprintf(codegen_buf, " %s", pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
							}
							var_decl += codegen_buf;
							/* initial value */
							if (pn->child[i]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
								/* if initial value is not dummy but `exp` */
								var_decl += " = ";
								var_decl += pn->child[i]->child[1]->fs.CurrentTerm.what;
							}
						}
						if (pn->child.size() >= 2)
						{
							/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
							/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
							pn = pn->child[1];
						}
					} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					var_decl += ";";
#ifndef LAZY_GEN
					// sprintf(codegen_buf, "%s %s;", $1.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
#endif // !LAZY_GEN
				}

				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 665 "for90.y"
    {
				/* paramtable is used in function decl */
				/* this paramtable has only one value */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild( new ParseNode((yyvsp[(1) - (1)])) ); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") };
					variablenode->addchild( new ParseNode(fs, newnode) ); // void is dummy initial
					newnode->addchild(variablenode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 682 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s" , (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // type
					variablenode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // initial
					newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 699 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* array initial values */
				ParseNode * newnode = new ParseNode();
				/* 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 */
				sprintf(codegen_buf, "%s.init(%s)", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s.init(%s)", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // type
					variablenode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // initial(array_builder)
				newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 717 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s, %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // type
					FlexState fs; fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, string("void") };
					variablenode->addchild(new ParseNode(fs, newnode)); // void is dummy initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // paramtable
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 734 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s, %s", (yyvsp[(1) - (5)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (5)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (5)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s", (yyvsp[(1) - (5)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode((yyvsp[(1) - (5)]))); // type
					variablenode->addchild(new ParseNode((yyvsp[(3) - (5)]))); // initial
					newnode->addchild(variablenode);
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // paramtable
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 750 "for90.y"
    {
				/* no params */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, "" };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 759 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (7)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(3) - (7)]))); // index variable
				newnode->addchild(new ParseNode((yyvsp[(5) - (7)]))); // exp_from
				newnode->addchild(new ParseNode((yyvsp[(7) - (7)]))); // exp_to
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 770 "for90.y"
    {
				/* give initial value */
				/* NOTE that `B(1:2:3)` can be either a single-element argtable or a exp */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "(%s)", (yyvsp[(2) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(2) - (3)]))); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 781 "for90.y"
    {
				/* give generate stmt */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s)=%s\n}", (yyvsp[(2) - (3)]).child[1]->fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (3)]).child[2]->fs.CurrentTerm.what.c_str() /* exp_from */
					, (yyvsp[(2) - (3)]).child[1]->fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (3)]).child[3]->fs.CurrentTerm.what.c_str() /* exp_to */, (yyvsp[(2) - (3)]).child[1]->fs.CurrentTerm.what.c_str() /* index variable inc */
					, "%s" /* array variable name */, (yyvsp[(2) - (3)]).child[1]->fs.CurrentTerm.what.c_str() /* index variable */, tabber((yyvsp[(2) - (3)]).child[0]->fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
				newnode->addchild(new ParseNode(*(yyvsp[(2) - (3)]).child[0])); // exp
				newnode->addchild(new ParseNode(*(yyvsp[(2) - (3)]).child[1])); // index variable
				newnode->addchild(new ParseNode(*(yyvsp[(2) - (3)]).child[2])); // exp_from
				newnode->addchild(new ParseNode(*(yyvsp[(2) - (3)]).child[3])); // exp_to
				(yyval) = *newnode;
				update_pos((yyval));
				// TODO 
				/* rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule*/
				/* note that this two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict */
				/* note either that `variable '(' dimen_slice ')'` is an `exp` */
				/* give initial value */

				// 
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 803 "for90.y"
    {
				/* give a array slice */
				/* NOTE that `B(1:2:3)` can be either a single-element argtable or a exp */
				ParseNode * newnode = new ParseNode();
				/* assert NT_FUCNTIONARRAY is the only child of $2 */
				ParseNode & expnode = (yyvsp[(2) - (3)]);
 				assert(expnode.child.size() == 1 && expnode.child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY);
				ParseNode * dimen_slice = expnode.child[0]/*NT_FUCNTIONARRAY*/->child[1]/*NT_ARGTABLE_DIMENSLICE*/->child[0]/*NT_DIMENSLICE*/;
				ParseNode * name = expnode.child[0]/*NT_FUCNTIONARRAY*/->child[0];
				string dimenstr = "";
				do {
					// for all non-flatterned dimen_slice
					for (int i = 0; i < dimen_slice->child.size(); i++)
					{
						ParseNode * slice = dimen_slice->child[i];
						if (slice->child.size() == 2) {
							sprintf(codegen_buf, "(%s.slice(%s, %s))", name->fs.CurrentTerm.what.c_str(), slice->child[0]->fs.CurrentTerm.what.c_str(), slice->child[1]->fs.CurrentTerm.what.c_str());
						}
						else if (slice->child.size() == 3) {
							sprintf(codegen_buf, "(%s.slice(%s, %s, %s))", name->fs.CurrentTerm.what.c_str(), slice->child[0]->fs.CurrentTerm.what.c_str()
								, slice->child[1]->fs.CurrentTerm.what.c_str(), slice->child[2]->fs.CurrentTerm.what.c_str());
						}
					}
					if (dimen_slice->child.size() >= 2)
					{
						dimen_slice = dimen_slice->child[1];
					}
				} while (dimen_slice->child.size() == 2 && dimen_slice->child[1]->fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE,  string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(2) - (3)]))); // array slice
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 839 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(5) - (8)]).fs.CurrentTerm.what = tabber((yyvsp[(5) - (8)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}", (yyvsp[(2) - (8)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (8)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (8)]))); // if
				newnode->addchild(new ParseNode((yyvsp[(2) - (8)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (8)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 854 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(5) - (11)]).fs.CurrentTerm.what = tabber((yyvsp[(5) - (11)]).fs.CurrentTerm.what); (yyvsp[(8) - (11)]).fs.CurrentTerm.what = tabber((yyvsp[(8) - (11)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", (yyvsp[(2) - (11)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (11)]).fs.CurrentTerm.what.c_str(), (yyvsp[(8) - (11)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (11)]))); // if
				newnode->addchild(new ParseNode((yyvsp[(2) - (11)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (11)]))); // suite
				newnode->addchild(new ParseNode((yyvsp[(6) - (11)]))); // else
				newnode->addchild(new ParseNode((yyvsp[(8) - (11)]))); // else-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 871 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(5) - (9)]).fs.CurrentTerm.what = tabber((yyvsp[(5) - (9)]).fs.CurrentTerm.what); (yyvsp[(6) - (9)]).fs.CurrentTerm.what = tabber((yyvsp[(6) - (9)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%s", (yyvsp[(2) - (9)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (9)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (9)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (9)]))); // if
				newnode->addchild(new ParseNode((yyvsp[(2) - (9)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (9)]))); // suite
				newnode->addchild(new ParseNode((yyvsp[(6) - (9)]))); // recursive elseif-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 887 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(3) - (11)]).fs.CurrentTerm.what = tabber((yyvsp[(3) - (11)]).fs.CurrentTerm.what); (yyvsp[(6) - (11)]).fs.CurrentTerm.what = tabber((yyvsp[(6) - (11)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n%s}%s", (yyvsp[(1) - (11)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (11)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (11)]).fs.CurrentTerm.what.c_str(), (yyvsp[(9) - (11)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (11)]))); // if
				newnode->addchild(new ParseNode((yyvsp[(2) - (11)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (11)]))); // suite
				newnode->addchild(new ParseNode((yyvsp[(6) - (11)]))); // recursive elseif-stmt
				newnode->addchild(new ParseNode((yyvsp[(9) - (11)]))); // else-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 904 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(5) - (5)]).fs.CurrentTerm.what = tabber((yyvsp[(5) - (5)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if(%s) {\n%s}", (yyvsp[(2) - (5)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (5)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (5)]))); // elseif
				newnode->addchild(new ParseNode((yyvsp[(2) - (5)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 920 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(5) - (6)]).fs.CurrentTerm.what = tabber((yyvsp[(5) - (6)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if{\n%s}\n%s", (yyvsp[(2) - (6)]).fs.CurrentTerm.what.c_str(), (yyvsp[(5) - (6)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (6)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (6)]))); // elseif
				newnode->addchild(new ParseNode((yyvsp[(2) - (6)]))); // exp
				newnode->addchild(new ParseNode((yyvsp[(5) - (6)]))); // suite
				newnode->addchild(new ParseNode((yyvsp[(6) - (6)]))); // another elseif-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 936 "for90.y"
    {
				ParseNode * newnode = new ParseNode(); 
#ifndef LAZY_GEN
			(yyvsp[(3) - (6)]).fs.CurrentTerm.what = tabber((yyvsp[(3) - (6)]).fs.CurrentTerm.what);
			sprintf(codegen_buf, "do{\n%s}", (yyvsp[(3) - (6)]).fs.CurrentTerm.what.c_str());
#endif // !LAZY_GEN

				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (6)]))); // do
				newnode->addchild(new ParseNode((yyvsp[(3) - (6)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 950 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(8) - (10)]).fs.CurrentTerm.what = tabber((yyvsp[(8) - (10)]).fs.CurrentTerm.what); 
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s++){\n%s}", (yyvsp[(2) - (10)]).fs.CurrentTerm.what.c_str(), (yyvsp[(4) - (10)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (10)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (10)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (10)]).fs.CurrentTerm.what.c_str(), (yyvsp[(8) - (10)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (10)]))); // do
				newnode->addchild(new ParseNode((yyvsp[(2) - (10)]))); // varname
				newnode->addchild(new ParseNode((yyvsp[(4) - (10)]))); // begin
				newnode->addchild(new ParseNode((yyvsp[(6) - (10)]))); // end
				newnode->addchild(new ParseNode((yyvsp[(8) - (10)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 967 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(9) - (12)]).fs.CurrentTerm.what = tabber((yyvsp[(9) - (12)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s+=%s){\n%s}", (yyvsp[(2) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(4) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(8) - (12)]).fs.CurrentTerm.what.c_str(), (yyvsp[(9) - (12)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (12)]))); // do
				newnode->addchild(new ParseNode((yyvsp[(2) - (12)]))); // varname
				newnode->addchild(new ParseNode((yyvsp[(4) - (12)]))); // begin
				newnode->addchild(new ParseNode((yyvsp[(6) - (12)]))); // end
				newnode->addchild(new ParseNode((yyvsp[(8) - (12)]))); // step
				newnode->addchild(new ParseNode((yyvsp[(9) - (12)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 986 "for90.y"
    {
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode * newnode = new ParseNode();
				vector<pair<string, string>> param_name_typename; // all params in paramtable of function declare
				vector<ParseNode *> param_definition;
				/* enumerate paramtable */
				ParseNode * prmtbl = &(yyvsp[(5) - (14)]);
				do {
					// for all non-flatterned paramtable
					for (int i = 0; i < prmtbl->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						param_name_typename.push_back(make_pair(prmtbl->child[i]->fs.CurrentTerm.what, "void")); // refer to function suite and determine type of params
					}
					if (prmtbl->child.size() >= 2)
					{
						/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
						/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
						prmtbl = prmtbl->child[1];
					}
				} while (prmtbl->child.size() == 2 && prmtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
				/* result variable */
				param_name_typename.push_back(make_pair((yyvsp[(9) - (14)]).fs.CurrentTerm.what, "void"));
				/* find out all var_def nodes */
				for (int i = 0; i < (yyvsp[(12) - (14)]).child.size(); i++)
				{
					ParseNode * stmti = (yyvsp[(12) - (14)]).child[i];
					/* $12 => suite */
					/* $12.child[i] => stmt */ /*  REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
					if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						/* stmti->child[0] => var_def */
						/* from pn=stmti->child[0].child[0] is typename */
						/* from pn=stmti->child[0].child[1] is all variables of this type */
						ParseNode * pn = stmti->child[0]->child[1];
						do {
							// for all non-flatterned paramtable
							for (int i = 0; i < pn->child.size(); i++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname_i with initial value */
								/* pn->child[i]->child[0] is varname string */
								param_definition.push_back(pn->child[i]->child[0]);
							}
							if (pn->child.size() >= 2)
							{
								/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
								/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
								pn = pn->child[1];
							}
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
				}

				/* set type to all param_name_typename */
				for (int i = 0; i < param_name_typename.size(); i++)
				{
					string varname = param_name_typename[i].first;
					for (int j = 0; j < param_definition.size(); j++)
					{
						ParseNode * varname_node = param_definition[j];
						if (varname_node->fs.CurrentTerm.what == varname) {
							//	father		NT_VARIABLEINITIAL (variable_name, variable_initial_value)
							//	father * 2	NT_PARAMTABLE
							//	father * 3	NT_VARIABLEDEFINE
							param_name_typename[i].second = varname_node->father->father->father->child[0]->fs.CurrentTerm.what;
							/* `delete` ParseNode except return value */
							if (i != param_name_typename.size() - 1) {
								varname_node->father->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
							}
						}
					}
				}

				string argtblstr;
				for (int i = 0; i < param_name_typename.size() - 1 /* exclude YY_RESULT(return value) */; i++)
				{
					if(i != 0)
						argtblstr += ", ";
					argtblstr += param_name_typename[i].second;
					argtblstr += " ";
					argtblstr += param_name_typename[i].first;
				}

				/* generate new paramtable with type */
				ParseNode * newpt; // $5 is raw for90 paramtable without type
				// TODO This is optional so i decide not to implement currently
				/* generate new return with type */
				ParseNode * newrt; // $9 is raw for90 return without type
				// TODO This is optional so i decide not to implement currently
				
				/* re-generated codes of suite */
				string newsuitestr; // $12 is raw for90 suite without type
				ParseNode * oldsuite = & (yyvsp[(12) - (14)]);
				for (int i = 0; i < oldsuite->child.size(); i++)
				{
					if (oldsuite->child[i]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
					{
						// this code is similar to `find out all var_def nodes` code
						ParseNode * pn = (yyvsp[(12) - (14)]).child[0]->child[1];
						do {
							// for all non-flatterned paramtable
							for (int j = 0; j < pn->child.size(); j++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname with initial value */
								/* pn->child[i]->child[0] is varname string */
								if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
									newsuitestr += oldsuite->child[i]->child[0]->fs.CurrentTerm.what;
									newsuitestr += " ";
									newsuitestr += pn->child[j]->fs.CurrentTerm.what;
									newsuitestr += " ;\n";
								}
							}
							pn = pn->child[1];
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
					else {
						newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
					}
				}
				oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
				/* generate function ParseTree */
				newnode->addchild(new ParseNode((yyvsp[(2) - (14)]))); // function
				newnode->addchild(new ParseNode((yyvsp[(3) - (14)]))); // function name
				// argtable
				// TODO 
				// return value
				newnode->addchild(new ParseNode((yyvsp[(12) - (14)]))); // trimed suite

				sprintf(codegen_buf, "%s %s(%s){\n%s\n}"
					, param_name_typename[param_name_typename.size()-1].second.c_str() // return value type
					, (yyvsp[(3) - (14)]).fs.CurrentTerm.what.c_str() // function name
					, argtblstr.c_str()
					, (yyvsp[(12) - (14)]).fs.CurrentTerm.what.c_str()
				);
				/* generate function code */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1128 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1133 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1139 "for90.y"
    { 
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(4) - (8)]))); //wrapper
				program_tree = *newnode;
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1145 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(3) - (6)]))); //wrapper
				program_tree = *newnode;
			}
    break;


/* Line 1792 of yacc.c  */
#line 3082 "for90.tab.cpp"
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
#line 1151 "for90.y"

//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
}
string tabber(string & src) {
	string newline;
	string ans = "";
	std::istringstream f(src);
	while (getline(f, newline) ) {
		ans += '\t';
		ans += newline;
		ans += '\n';
	}
	return ans;
}
ParseNode * flattern_bin(ParseNode * pn) {
	/* it cant work well because it create a whole noew tree copy too much */
	/* THIS ALGORITHM FLATTERNS A RIGHT-RECURSIVE BINARY TREE */
	if (pn->child.size() == 2) {
		ParseNode * newp = new ParseNode();
		/* child[0] is the only data node */
		newp->addchild(new ParseNode(*pn->child[0]));
		/* pn->child[1] is a list of ALREADY flatterned elements */
		//	e.g
		//	child[0] is 1 
		//	child[1] is [2, 3, 4, 5]
		for (int i = 0; i < pn->child[1]->child.size(); i++)
		{
			newp->addchild(new ParseNode(*pn->child[1]->child[i]));
		}
		newp->fs = pn->fs;
		newp->father = pn->father;
		delete pn;
		return newp;
	}
	else {
		return pn;
	}
}
void update_pos(YYSTYPE & current_node) {
	if (current_node.child.size() == 0) {
		/* do nothing */
	}
	else if (current_node.child.size() == 1) {
		current_node.fs.parse_pos = current_node.child[0]->fs.parse_pos;
		current_node.fs.parse_line = current_node.child[0]->fs.parse_line;
		current_node.fs.parse_len = current_node.child[0]->fs.parse_len;
		current_node.fs.line_pos = current_node.child[0]->fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current_node.child.size(); i++)
		{
			tot_len += current_node.child[i]->fs.parse_len;
		}
		current_node.fs.parse_pos = current_node.child[0]->fs.parse_pos;
		current_node.fs.parse_line = current_node.child[0]->fs.parse_line;
		current_node.fs.parse_len = tot_len;
		current_node.fs.parse_len = current_node.child[0]->fs.line_pos;
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
