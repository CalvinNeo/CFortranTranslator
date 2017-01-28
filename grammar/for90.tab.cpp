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
     YY_IMPLICIT = 321,
     YY_NONE = 322,
     YY_USE = 323,
     YY_PARAMETER = 324,
     YY_ENTRY = 325,
     YY_DIMENSION = 326,
     YY_ARRAYINITIAL_START = 327,
     YY_ARRAYINITIAL_END = 328,
     YY_INTENT = 329,
     YY_IN = 330,
     YY_OUT = 331,
     YY_INOUT = 332,
     YY_OPTIONAL = 333,
     YY_LEN = 334,
     YY_KIND = 335,
     YY_INTEGER_T = 336,
     YY_FLOAT_T = 337,
     YY_STRING_T = 338,
     YY_COMPLEX_T = 339,
     YY_BOOL_T = 340,
     YY_CHARACTER_T = 341,
     YY_WRITE = 342,
     YY_READ = 343,
     YY_PRINT = 344,
     YY_CALL = 345,
     YY_FORMAT = 346
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
#line 252 "for90.tab.cpp"

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
#define YYLAST   1777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNRULES -- Number of states.  */
#define YYNSTATES  376

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      98,    99,    95,    93,   100,    94,     2,    96,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,    97,
       2,    92,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91
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
     590,   592,   593,   602,   604,   606,   608,   611,   621,   623
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,     4,    -1,    97,    -1,    -1,    55,    -1,
      -1,    74,    98,    75,    99,    -1,    74,    98,    76,    99,
      -1,    74,    98,    77,    99,    -1,    71,    98,   112,    99,
      -1,    71,    98,   115,    99,    -1,    78,    -1,    69,    -1,
     100,   106,    -1,   100,   106,   107,    -1,    -1,    80,    92,
      20,    -1,    79,    92,   115,    -1,    21,    -1,    20,    -1,
      24,    -1,    27,    -1,    28,    -1,    26,    -1,     1,   101,
      -1,    22,    -1,   115,   102,   115,    -1,   115,   102,   115,
     102,   115,    -1,   102,    -1,   111,    -1,   111,   100,   112,
      -1,   115,    -1,   115,   100,   143,    -1,   110,    98,   143,
      99,    -1,   136,    98,   143,    99,    -1,   113,    -1,    90,
     113,    -1,   114,    -1,   147,    -1,   115,    98,   115,    99,
      -1,    98,   115,    99,    -1,   115,    93,   115,    -1,   115,
      94,   115,    -1,   115,    95,   115,    -1,   115,    96,   115,
      -1,   115,    16,   115,    -1,    94,   115,    -1,    93,   115,
      -1,   115,    10,   115,    -1,   115,    11,   115,    -1,   115,
       7,   115,    -1,   115,    12,   115,    -1,   115,    13,   115,
      -1,   115,    14,   115,    -1,    15,   115,    -1,   115,     5,
     115,    -1,   115,     6,   115,    -1,   115,     8,   115,    -1,
     115,     9,   115,    -1,   145,    -1,   109,    -1,   110,    -1,
     104,    -1,    97,   104,    -1,    97,    -1,    -1,    29,    -1,
     115,   116,    -1,   140,   116,    -1,   122,    -1,   120,    -1,
     121,    -1,   125,    -1,   124,    -1,   123,    -1,   117,     4,
      -1,   118,    -1,   139,    -1,   133,   116,    -1,   134,   116,
      -1,   135,   116,    -1,   149,    -1,   152,    -1,   154,    -1,
      38,   116,    -1,    39,   116,    -1,    48,    20,   116,    -1,
     115,    92,   115,   116,    -1,    66,    67,   104,    -1,   119,
      -1,   119,   126,    -1,   164,    -1,   164,   126,    -1,    -1,
      98,    -1,    -1,    99,    -1,   100,    -1,    -1,    95,    -1,
      20,    -1,    95,    -1,    20,    -1,    24,    -1,    98,   130,
     100,   131,    99,    -1,   131,   129,    -1,    87,   132,   143,
      -1,    89,   132,   143,    -1,    88,   132,   143,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    81,    98,   108,    99,    -1,    82,    98,   108,    99,
      -1,    83,    98,   108,    99,    -1,    84,    98,   108,    99,
      -1,    85,    98,   108,    99,    -1,    86,    98,   108,    99,
      -1,   136,    95,    20,    -1,   136,    -1,    96,   110,    96,
      -1,    96,    96,    -1,    -1,    65,   138,   143,    -1,   137,
     107,    17,   143,    -1,   137,   107,   143,    -1,   110,    -1,
     115,    92,   115,    -1,   115,    92,   147,    -1,   112,    -1,
     141,    -1,   142,    -1,   142,   100,   143,    -1,    -1,   115,
     100,   110,    92,   115,   100,   115,    -1,    98,   144,    99,
      -1,    72,   143,    73,    -1,    72,   145,    73,    -1,   146,
      -1,    30,    31,    -1,    35,    -1,    31,   115,    32,   104,
     126,   148,   104,    -1,    31,   115,    32,   104,   126,    33,
     104,   126,   148,   104,    -1,    31,   115,    32,   104,   126,
     150,   148,   104,    -1,    31,   115,    32,   104,   126,   150,
      33,   104,   126,   148,   104,    -1,    31,   115,    32,   119,
      -1,    31,   115,   119,    -1,    34,   115,    32,   104,   126,
      -1,    34,   115,    32,   104,   126,   150,    -1,    30,    36,
      -1,    37,    -1,    36,   104,   126,   151,   104,    -1,    36,
     110,    92,   115,   100,   115,   104,   126,   151,   104,    -1,
      36,   110,    92,   115,   100,   115,   100,   115,   104,   126,
     151,   104,    -1,    49,   115,   104,   126,   151,   104,    -1,
      30,    46,    -1,    47,    -1,    46,    44,   127,   115,   128,
     104,   156,   153,   104,    -1,    44,   127,   112,   128,   104,
     126,    -1,   155,    -1,   155,   156,    -1,    56,    98,   110,
      99,    -1,    -1,    53,    -1,    57,    -1,   105,   158,   110,
      98,   143,    99,   157,   104,   126,    30,   158,   104,    -1,
      22,    -1,    -1,    51,   160,   104,   126,    30,    51,   160,
     104,    -1,   159,    -1,   161,    -1,   162,    -1,   162,   163,
      -1,    63,   160,   104,   163,   104,    30,    63,   160,   104,
      -1,   163,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   117,   135,   142,   151,   156,   170,   178,   189,   203,
     208,   212,   217,   221,   225,   232,   234,   256,   265,   275,
     284,   294,   305,   312,   331,   341,   352,   356,   361,   369,
     377,   385,   393,   401,   409,   417,   425,   433,   440,   447,
     455,   463,   471,   479,   487,   495,   502,   510,   518,   526,
     534,   540,   545,   559,   560,   562,   567,   571,   577,   587,
     593,   597,   601,   605,   609,   614,   619,   624,   628,   634,
     635,   637,   639,   640,   641,   643,   644,   645,   651,   660,
     667,   672,   677,   682,   689,   690,   691,   692,   693,   694,
     695,   699,   703,   707,   712,   719,   730,   744,   752,   761,
     769,   774,   779,   784,   789,   794,   800,   806,   811,   816,
     821,   826,   834,   839,   841,   845,   852,   856,   861,   871,
     882,   887,   896,   905,   909,   913,   920,   929,   936,   948,
     956,   963,   974,  1006,  1007,  1014,  1021,  1029,  1037,  1046,
    1053,  1061,  1069,  1078,  1079,  1081,  1087,  1097,  1107,  1115,
    1116,  1118,  1126,  1134,  1142,  1153,  1159,  1165,  1166,  1168,
    1181,  1182,  1184,  1192,  1197,  1203,  1212,  1224,  1230,  1234
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
  "YY_ENDINTERFACE", "YY_COMMON", "YY_IMPLICIT", "YY_NONE", "YY_USE",
  "YY_PARAMETER", "YY_ENTRY", "YY_DIMENSION", "YY_ARRAYINITIAL_START",
  "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT",
  "YY_OPTIONAL", "YY_LEN", "YY_KIND", "YY_INTEGER_T", "YY_FLOAT_T",
  "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T", "YY_CHARACTER_T", "YY_WRITE",
  "YY_READ", "YY_PRINT", "YY_CALL", "YY_FORMAT", "'='", "'+'", "'-'",
  "'*'", "'/'", "';'", "'('", "')'", "','", "'\\n'", "':'", "$accept",
  "crlf", "dummy_function_iden", "variable_desc_elem", "variable_desc",
  "typecast_spec", "literal", "variable", "slice", "dimen_slice",
  "function_array_body", "function_array", "exp", "_crlf_semicolon",
  "semicolon", "label", "stmt", "output_stmt", "input_stmt",
  "compound_stmt", "jump_stmt", "let_stmt", "dummy_stmt", "suite",
  "_optional_lbrace", "_optional_rbrace", "_optional_comma",
  "_optional_device", "_optional_formatter", "io_info", "write", "print",
  "read", "type_nospec", "type_spec", "_blockname_or_none", "commom_stmt",
  "var_def", "keyvalue", "paramtable_elem", "paramtable", "_generate_stmt",
  "hidden_do", "array_builder_elem", "array_builder", "_yy_endif",
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
     345,   346,    61,    43,    45,    42,    47,    59,    40,    41,
      44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   110,   111,   111,   111,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   121,   122,   122,   122,   123,   123,   123,   124,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   132,   132,   133,   134,   135,
     136,   136,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   139,   140,   140,
     141,   141,   141,   142,   142,   143,   143,   143,   144,   145,
     146,   146,   147,   148,   148,   149,   149,   149,   149,   149,
     149,   150,   150,   151,   151,   152,   152,   152,   152,   153,
     153,   154,   155,   156,   156,   157,   157,   158,   158,   159,
     160,   160,   161,   162,   162,   163,   163,   164,   165,   165
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
       1,     0,     8,     1,     1,     1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,   171,     5,     0,   173,   174,   175,   178,     0,   170,
       4,   167,   168,     0,   176,     1,     2,     3,     0,    26,
       0,     0,     0,    20,    19,    21,    24,    22,    23,    67,
       0,     4,     4,     4,     0,     0,     0,   171,   126,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,    65,     0,    61,    62,    36,    38,     4,
       0,    77,     0,    71,    72,    70,    75,    74,    73,     0,
       4,     4,     4,   123,    16,    78,     4,    60,   142,    39,
      82,    83,    84,     0,     0,    25,   110,   111,   112,   113,
     114,   115,    55,     0,     0,     0,     0,     3,    63,    85,
      86,    94,     4,     4,     4,     0,     0,     4,    29,    62,
      30,   133,    32,   134,   135,     0,    60,     0,     0,     0,
       0,     0,     0,   103,   104,   102,     0,    99,     0,     0,
       0,     0,    37,    48,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    76,    91,     0,    79,
      80,    81,     0,     0,     0,     0,    69,    93,     0,     0,
       0,     0,     0,   150,     0,     0,    64,    95,     0,    87,
       0,     6,   125,     0,   127,    89,     0,     0,     0,     0,
       0,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   100,     0,    98,   106,   107,   109,   108,    41,
       0,   139,     0,    56,    57,    51,    58,    59,    49,    50,
      52,    53,    54,    46,     4,    42,    43,    44,    45,     0,
     171,   122,     0,    13,     0,     0,    12,    14,     0,   129,
     166,     3,     0,   149,    42,    43,     0,     0,   154,     4,
       0,    96,     0,     4,   124,    31,    32,   131,    39,    33,
      27,   136,     0,     0,   116,   117,   118,   119,   120,   121,
       0,     0,    34,    88,    40,     4,    35,     0,     0,    15,
     128,     0,     4,     0,    40,   153,   155,     0,    97,     4,
       4,     0,     0,    18,    17,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,   144,     4,
       0,     4,     0,   158,     0,    28,   105,     0,    10,    11,
       7,     8,     9,     0,     0,   143,     0,     0,   145,     4,
       4,     0,     0,    94,   163,     0,   171,     0,   165,     0,
       0,     4,     0,   147,     4,     0,     0,   164,     0,   160,
       4,     4,   138,     4,     4,     0,     0,     0,     4,    96,
     159,   161,   177,   169,   146,   151,     4,     0,   156,     4,
     152,   148,     4,     0,   157,   162
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    98,     3,   237,   165,   195,    55,    56,   110,   111,
      57,    58,    59,    99,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   178,   289,   205,   203,   127,   128,
      70,    71,    72,    93,    74,   106,    75,    76,   113,   114,
     115,   136,    77,    78,    79,   309,    80,   310,   249,    81,
     350,    82,   334,   335,   282,    13,     4,    10,     5,     6,
       7,    83,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -291
static const yytype_int16 yypact[] =
{
      27,    16,  -291,    17,  -291,  -291,   105,  -291,    57,  -291,
       3,  -291,  -291,    18,  -291,  -291,  -291,  -291,  1126,  -291,
     -27,   -20,  1249,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    1249,     2,     6,     6,    52,    66,  1249,    16,     5,    45,
     127,    25,    39,    41,    48,    54,    59,    13,    13,    13,
      99,  1249,  1249,  -291,  1249,  -291,    65,  -291,  -291,  1417,
     121,  -291,   944,  -291,  -291,  -291,  -291,  -291,  -291,   120,
       6,     6,     6,    75,    64,  -291,     6,  -291,  -291,  -291,
    -291,  -291,  -291,  1035,   433,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,     7,    74,   846,  1126,    82,     3,  -291,  -291,
    -291,    81,     6,  1512,     3,    -7,   747,     3,  -291,    65,
      89,  -291,  1343,  -291,    90,   118,   123,   -31,   -31,   -31,
     -31,   -31,   -31,  -291,  -291,  -291,   -12,   107,   747,   747,
     747,    65,  -291,   108,   108,  1368,    98,   433,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  -291,  -291,  -291,   154,  -291,
    -291,  -291,   195,   433,    97,   656,  -291,  -291,   117,  1217,
    1249,  1249,  1249,  -291,    23,  1249,  -291,  -291,  1249,  -291,
    1126,    71,  -291,   122,  -291,  -291,   470,  1249,   565,  1249,
     565,  -291,  -291,   130,   131,   125,   128,   129,   133,   134,
     135,  -291,  -291,   119,  -291,  -291,  -291,  -291,  -291,  -291,
      18,  -291,   137,   108,   108,    20,   108,   108,    20,  1573,
    1573,  1679,  1667,     0,  1525,    40,    40,     0,     0,  1537,
      16,  -291,   138,  -291,   142,   143,  -291,    64,   747,  -291,
     170,  -291,  1126,  -291,   219,  1133,  1380,   208,  -291,     3,
    1392,  1549,    23,     3,  -291,  -291,   992,  1573,  -291,  -291,
     795,  -291,  1249,   225,  -291,  -291,  -291,  -291,  -291,  -291,
      35,   155,  -291,  -291,  -291,     3,  -291,   470,   111,  -291,
    -291,   148,     3,   110,   432,  -291,  -291,  1249,  -291,     3,
       3,   218,  1249,  1573,  -291,   151,  1249,  -291,   152,   613,
     158,   159,   160,    18,  1126,   229,     3,  1249,  -291,     3,
      42,  1356,   217,  -291,   199,  1573,  -291,  1404,  -291,  -291,
    -291,  -291,  -291,   165,   237,  -291,  1126,  1561,  -291,     3,
       3,  1249,  1126,    81,   217,    -8,    16,  1249,  -291,    17,
      50,     3,  1126,  -291,  1512,    23,   470,  -291,   222,  -291,
       3,     3,  1573,     3,     3,  1126,    50,  1126,     3,   171,
    -291,  -291,  -291,  -291,  -291,   235,     3,    23,  -291,     3,
    -291,  -291,     3,  1126,  -291,  -291
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -291,   -10,  -291,  -291,    34,   -57,  -291,     4,  -291,  -185,
     224,  -291,   251,   -29,  -291,  -291,   -85,  -291,  -291,  -291,
    -291,  -291,  -291,   -49,   -58,   -83,  -291,  -291,     8,    58,
    -291,  -291,  -291,    -4,  -291,  -291,  -291,  -291,  -291,  -291,
     -61,  -291,   244,  -291,   101,  -290,  -291,   -80,  -250,  -291,
    -291,  -291,  -291,   -48,  -291,   -50,  -291,   -32,  -291,  -291,
      -3,  -291,  -291
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -180
static const yytype_int16 yytable[] =
{
      18,   255,   290,    14,   100,   104,    16,    16,   201,   173,
      16,   144,   145,   157,    73,    19,   148,    20,   144,   145,
     330,    95,   348,   168,    19,   138,   139,  -179,   141,   142,
     155,   144,   145,   123,   167,    96,   148,   124,     9,   349,
      19,   159,   160,   161,   109,   184,   174,   166,   193,   194,
     354,   144,   145,   247,   131,   123,   148,    15,    73,   124,
     248,   196,   197,   198,   199,   200,   366,   206,   207,   208,
      11,    84,   305,   179,    12,   329,   212,   308,     1,    73,
     305,    85,     2,   202,   243,   308,   102,   176,   109,   182,
      73,    73,   298,   180,   181,   358,   101,   185,   154,    17,
      17,   105,   232,    97,   239,   154,   129,   130,   125,   183,
     109,   126,   107,   150,   151,   152,   153,   372,   154,   144,
     145,    19,     1,   117,   148,   156,     2,   259,    21,   261,
     125,   252,   109,   109,   109,   152,   153,   118,   154,   119,
     305,   109,    22,   306,   307,   308,   120,    23,    24,    19,
     158,    25,   121,    26,    27,    28,     1,   122,    -6,   242,
       2,   359,    -6,   137,   164,    73,   233,   109,   234,   109,
     162,   235,   163,   163,   175,   236,    73,   280,   253,   177,
      86,    87,    88,    89,    90,    91,   300,   301,   302,   186,
     190,   191,   109,   283,   109,   273,   192,   211,   275,    40,
    -137,   150,   151,   152,   153,   230,   154,   204,    86,    87,
      88,    89,    90,    91,   271,   231,   240,    50,   254,   270,
      51,    52,   262,   263,   264,    54,   281,   265,   266,   108,
     144,   145,   267,   268,   269,   148,   272,   276,    73,   286,
     277,   278,   109,   291,   285,   294,   303,   296,   314,   -48,
     316,   318,   -48,   -48,   -48,   324,   -48,   320,   321,   322,
     325,   333,   336,   -48,   338,   297,   -48,   339,   360,   307,
     288,   279,   304,    92,   132,   346,   369,   340,   295,   312,
     313,    94,   -48,   345,   116,   370,   347,   103,   258,   353,
       0,   112,     0,   356,     0,     0,   326,     0,     0,   328,
      73,   332,   133,   134,   351,   135,   365,   323,   367,     0,
       0,   -48,     0,     0,   152,   153,     0,   154,     0,   342,
     343,     0,    73,     0,   375,     0,     0,     0,    73,     0,
       0,   355,     0,     0,   357,   112,     0,     0,    73,     0,
     361,   362,     0,   363,   364,     0,     0,     0,   368,     0,
       0,    73,     0,    73,     0,     0,   371,   112,     0,   373,
       0,     0,   374,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     112,   112,     0,     0,     0,     0,     0,     0,   112,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,   112,     0,     0,     0,
       0,   244,   245,   246,     0,     0,   250,     0,     0,   251,
       0,     0,     0,     0,    21,     0,     0,   256,   257,   112,
     260,   112,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,    23,    24,    19,     0,    25,     0,    26,
      27,    28,   -41,     0,     0,   -41,   -41,   -41,     0,   -41,
       0,    21,     0,     0,     0,     0,   -41,     0,     0,   -41,
       0,     0,     0,     0,     0,    22,     0,     0,     0,   112,
      23,    24,    19,     0,    25,   -41,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,   293,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    50,   -41,     0,    51,    52,   299,     0,
       0,    54,  -137,     0,     0,   108,     0,     0,   311,     0,
       0,     0,    40,   315,     0,     0,     0,   317,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,   327,     0,
      50,     0,     0,    51,    52,     0,    21,     0,    54,  -137,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
      22,     0,   344,     0,     0,    23,    24,    19,   352,    25,
       0,    26,    27,    28,  -137,  -137,  -137,   256,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,  -137,
       0,  -137,  -137,  -137,  -137,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,  -137,   148,
    -137,  -137,     0,     0,     0,     0,     0,    40,  -137,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,  -137,  -137,  -137,    50,     0,    21,    51,    52,
    -137,     0,  -137,    54,  -137,  -137,     0,   108,     0,     0,
       0,    22,     0,   238,     0,     0,    23,    24,    19,     0,
      25,     0,    26,    27,    28,  -137,  -137,  -137,     0,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,
    -137,     0,  -137,  -137,  -137,  -137,   150,   151,   152,   153,
       0,   154,   319,   188,     0,   189,     0,     0,     0,  -137,
       0,  -137,  -137,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,  -137,  -137,  -137,    50,     0,    21,    51,
      52,  -137,     0,  -137,    54,     0,     0,     0,   108,     0,
       0,     0,    22,     0,     0,     0,     0,    23,    24,    19,
       0,    25,     0,    26,    27,    28,  -137,  -137,  -137,     0,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,
       0,  -137,     0,  -137,  -137,  -137,  -137,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
    -137,   148,  -137,  -137,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,  -137,  -137,  -137,    50,     0,     0,
      51,    52,     0,     0,  -137,    54,     0,    21,     0,   108,
     -66,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    22,   148,     0,     0,     0,    23,    24,    19,     0,
      25,     0,    26,    27,    28,    29,     0,    30,   169,     0,
       0,     0,    31,     0,    32,    33,     0,     0,   150,   151,
     152,   153,    34,   154,    35,    36,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,   170,
     171,   152,   153,    53,   172,    21,     0,     0,   -66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    23,    24,    19,     0,    25,     0,
      26,    27,    28,    29,   -90,    30,     0,   -90,   -90,   -90,
      31,   -90,    32,    33,     0,     0,     0,     0,   -90,     0,
      34,   -90,    35,    36,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    37,   148,    38,
      39,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    21,    51,    52,   -66,
       0,    53,    54,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,    23,    24,    19,     0,    25,
       0,    26,    27,    28,    29,   -92,    30,     0,   -92,   -92,
     -92,    31,   -92,    32,    33,     0,     0,     0,     0,   -92,
       0,    34,   -92,    35,    36,   150,   151,   152,   153,     0,
     154,     0,   188,     0,   189,     0,     0,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    21,    51,    52,
     -66,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,   144,   145,    23,    24,    19,   148,
      25,     0,    26,    27,    28,    29,     0,    30,     0,     0,
       0,     0,    31,   -47,    32,    33,   -47,   -47,   -47,     0,
     -47,     0,    34,     0,    35,    36,     0,   -47,     0,     0,
     -47,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,    39,     0,     0,     0,   -47,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    21,    51,
      52,    16,     0,    53,    54,   -47,     0,     0,   152,   153,
       0,   154,    22,     0,     0,     0,     0,    23,    24,    19,
       0,    25,     0,    26,    27,    28,    29,     0,    30,     0,
      21,     0,     0,    31,     0,    32,    33,     0,     0,     0,
       0,     0,     0,    34,    22,    35,    36,     0,     0,    23,
      24,    19,     0,    25,     0,    26,    27,    28,     0,     0,
      -4,     0,    38,    39,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,     0,     0,   241,    54,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    50,
       0,     0,    51,    52,     0,     0,     0,    54,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,   148,
      16,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,   148,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,   148,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,   148,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,   148,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
     148,    16,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,   148,     0,   187,   150,   151,   152,   153,
       0,   154,     0,   188,     0,   189,     0,     0,     0,   150,
     151,   152,   153,    17,   154,     0,   331,     0,     0,     0,
       0,   150,   151,   152,   153,     0,   154,   209,   210,     0,
       0,     0,     0,   150,   151,   152,   153,     0,   154,   284,
     210,     0,     0,     0,     0,   150,   151,   152,   153,     0,
     154,     0,   287,     0,     0,     0,     0,   150,   151,   152,
     153,     0,   154,     0,   337,     0,     0,     0,     0,   149,
     150,   151,   152,   153,    97,   154,    16,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,   148,    16,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,   148,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,   148,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,   148,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,   148,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,   148,
       0,     0,     0,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,   153,    17,
     154,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,    97,   154,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,     0,   154,   274,     0,     0,     0,
       0,     0,   150,   151,   152,   153,     0,   154,   288,     0,
       0,     0,     0,     0,   150,   151,   152,   153,     0,   154,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
       0,   154,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   148,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,     0,   154,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,     0,   154
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-291)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,   186,   252,     6,    33,    37,     4,     4,    20,    94,
       4,    11,    12,    62,    18,    22,    16,    13,    11,    12,
     310,    31,    30,    84,    22,     5,     6,     0,     8,     9,
      59,    11,    12,    20,    83,    31,    16,    24,    22,    47,
      22,    70,    71,    72,    40,   106,    95,    76,    79,    80,
     340,    11,    12,    30,    50,    20,    16,     0,    62,    24,
      37,   118,   119,   120,   121,   122,   356,   128,   129,   130,
      53,    98,    30,   102,    57,    33,   137,    35,    51,    83,
      30,   101,    55,    95,   169,    35,    20,    97,    84,    96,
      94,    95,   277,   103,   104,   345,    44,   107,    98,    97,
      97,    96,   163,    97,   165,    98,    48,    49,    95,   105,
     106,    98,    67,    93,    94,    95,    96,   367,    98,    11,
      12,    22,    51,    98,    16,     4,    55,   188,     1,   190,
      95,   180,   128,   129,   130,    95,    96,    98,    98,    98,
      30,   137,    15,    33,    34,    35,    98,    20,    21,    22,
      30,    24,    98,    26,    27,    28,    51,    98,    53,   169,
      55,   346,    57,    98,   100,   169,    69,   163,    71,   165,
      95,    74,    98,    98,    92,    78,   180,   238,   181,    98,
      81,    82,    83,    84,    85,    86,    75,    76,    77,   100,
     100,    73,   188,   242,   190,   224,    73,    99,   230,    72,
      73,    93,    94,    95,    96,    51,    98,   100,    81,    82,
      83,    84,    85,    86,   210,    20,    99,    90,    96,   100,
      93,    94,    92,    92,    99,    98,    56,    99,    99,   102,
      11,    12,    99,    99,    99,    16,    99,    99,   242,   249,
      98,    98,   238,   253,    36,    20,    98,    92,    30,    30,
      99,    99,    33,    34,    35,   304,    37,    99,    99,    99,
      31,    44,    63,    44,    99,   275,    47,    30,    46,    34,
      99,   237,   282,    22,    50,   333,   359,   326,   270,   289,
     290,    30,    63,   332,    40,   365,   334,    36,   187,   339,
      -1,    40,    -1,   342,    -1,    -1,   306,    -1,    -1,   309,
     304,   311,    51,    52,   336,    54,   355,   303,   357,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,   329,
     330,    -1,   326,    -1,   373,    -1,    -1,    -1,   332,    -1,
      -1,   341,    -1,    -1,   344,    84,    -1,    -1,   342,    -1,
     350,   351,    -1,   353,   354,    -1,    -1,    -1,   358,    -1,
      -1,   355,    -1,   357,    -1,    -1,   366,   106,    -1,   369,
      -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,     1,    -1,    -1,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    30,    -1,    -1,    33,    34,    35,    -1,    37,
      -1,     1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,   238,
      20,    21,    22,    -1,    24,    63,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    81,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    92,    -1,    93,    94,   277,    -1,
      -1,    98,    99,    -1,    -1,   102,    -1,    -1,   287,    -1,
      -1,    -1,    72,   292,    -1,    -1,    -1,   296,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,   307,    -1,
      90,    -1,    -1,    93,    94,    -1,     1,    -1,    98,     4,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,   331,    -1,    -1,    20,    21,    22,   337,    24,
      -1,    26,    27,    28,    29,    30,    31,   346,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,    49,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    63,    16,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,     1,    93,    94,
       4,    -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,
      -1,    15,    -1,    17,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,    47,    48,    49,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,   102,    -1,    -1,    -1,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,     1,    93,
      94,     4,    -1,    97,    98,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      63,    16,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      93,    94,    -1,    -1,    97,    98,    -1,     1,    -1,   102,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    38,    39,    -1,    -1,    93,    94,
      95,    96,    46,    98,    48,    49,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    93,
      94,    95,    96,    97,    98,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    63,    16,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,     1,    93,    94,     4,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,    49,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,   102,    -1,    -1,    -1,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,     1,    93,    94,
       4,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    11,    12,    20,    21,    22,    16,
      24,    -1,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    36,    30,    38,    39,    33,    34,    35,    -1,
      37,    -1,    46,    -1,    48,    49,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    66,    -1,    -1,    -1,    63,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,     1,    93,
      94,     4,    -1,    97,    98,    92,    -1,    -1,    95,    96,
      -1,    98,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    -1,
       1,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    15,    48,    49,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    -1,    -1,    98,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    92,    93,    94,    95,    96,
      -1,    98,    -1,   100,    -1,   102,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    -1,   100,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    55,   105,   159,   161,   162,   163,   165,    22,
     160,    53,    57,   158,   163,     0,     4,    97,   104,    22,
     110,     1,    15,    20,    21,    24,    26,    27,    28,    29,
      31,    36,    38,    39,    46,    48,    49,    63,    65,    66,
      72,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    94,    97,    98,   109,   110,   113,   114,   115,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     133,   134,   135,   136,   137,   139,   140,   145,   146,   147,
     149,   152,   154,   164,    98,   101,    81,    82,    83,    84,
      85,    86,   115,   136,   115,   104,   110,    97,   104,   116,
     116,    44,    20,   115,   160,    96,   138,    67,   102,   110,
     111,   112,   115,   141,   142,   143,   145,    98,    98,    98,
      98,    98,    98,    20,    24,    95,    98,   131,   132,   132,
     132,   110,   113,   115,   115,   115,   144,    98,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    16,    92,
      93,    94,    95,    96,    98,   116,     4,   126,    30,   116,
     116,   116,    95,    98,   100,   107,   116,   126,   143,    32,
      93,    94,    98,   119,   126,    92,   104,    98,   127,   116,
     104,   104,    96,   110,   143,   104,   100,    92,   100,   102,
     100,    73,    73,    79,    80,   108,   108,   108,   108,   108,
     108,    20,    95,   130,   100,   129,   143,   143,   143,    99,
     100,    99,   143,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
      51,    20,   143,    69,    71,    74,    78,   106,    17,   143,
      99,    97,   104,   119,   115,   115,   115,    30,    37,   151,
     115,   115,   126,   163,    96,   112,   115,   115,   147,   143,
     115,   143,    92,    92,    99,    99,    99,    99,    99,    99,
     100,   110,    99,   116,    99,   160,    99,    98,    98,   107,
     143,    56,   157,   126,    99,    36,   104,   100,    99,   128,
     151,   104,   102,   115,    20,   131,    92,   104,   112,   115,
      75,    76,    77,    98,   104,    30,    33,    34,    35,   148,
     150,   115,   104,   104,    30,   115,    99,   115,    99,    99,
      99,    99,    99,   110,   126,    31,   104,   115,   104,    33,
     148,   100,   104,    44,   155,   156,    63,   100,    99,    30,
     126,    32,   104,   104,   115,   126,   127,   156,    30,    47,
     153,   160,   115,   158,   148,   104,   126,   104,   151,   112,
      46,   104,   104,   104,   104,   126,   148,   126,   104,   128,
     150,   104,   151,   104,   104,   126
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

  case 16:
/* Line 1792 of yacc.c  */
#line 170 "for90.y"
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
#line 179 "for90.y"
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
#line 190 "for90.y"
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
#line 204 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 209 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 213 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 218 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 222 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 226 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 235 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 257 "for90.y"
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
#line 266 "for90.y"
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
#line 276 "for90.y"
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
#line 285 "for90.y"
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
#line 295 "for90.y"
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

  case 32:
/* Line 1792 of yacc.c  */
#line 306 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 313 "for90.y"
    {
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
#line 332 "for90.y"
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
#line 342 "for90.y"
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
#line 353 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 357 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 362 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 370 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 378 "for90.y"
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
#line 386 "for90.y"
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
#line 394 "for90.y"
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
#line 402 "for90.y"
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
#line 410 "for90.y"
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
#line 418 "for90.y"
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
#line 426 "for90.y"
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
#line 434 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 441 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 448 "for90.y"
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
#line 456 "for90.y"
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
#line 464 "for90.y"
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
#line 472 "for90.y"
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
#line 480 "for90.y"
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
#line 488 "for90.y"
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
#line 496 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 503 "for90.y"
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
#line 511 "for90.y"
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
#line 519 "for90.y"
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
#line 527 "for90.y"
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
#line 535 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 541 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 546 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 563 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 567 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 572 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 578 "for90.y"
    {
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ;");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 588 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 594 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 598 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 602 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 606 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 610 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 615 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 620 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 625 "for90.y"
    {
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 629 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 646 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 652 "for90.y"
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
#line 661 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 668 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 673 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s\n%s", TokenMeta::NT_SUITE);;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 678 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 683 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 696 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 700 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 704 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 708 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 713 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 720 "for90.y"
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
#line 731 "for90.y"
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
#line 745 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 753 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 762 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 770 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 775 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 780 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 785 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 790 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 795 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 801 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 807 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 812 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 817 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 822 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 827 "for90.y"
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
#line 835 "for90.y"
    {
				// $$ = gen_type($1, $3);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 842 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 846 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 852 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 857 "for90.y"
    {
				
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 862 "for90.y"
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
#line 872 "for90.y"
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
#line 883 "for90.y"
    { 
				// useless reduction
				/* paramtable is used in function decl */
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 888 "for90.y"
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
#line 897 "for90.y"
    {
				// array initial values 
				// 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 906 "for90.y"
    {
				// from rule ` dimen_slice : exp ',' paramtable `
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 910 "for90.y"
    {
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 914 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 921 "for90.y"
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
#line 929 "for90.y"
    {
				/* no params */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 937 "for90.y"
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
#line 949 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode & _generate_stmt = (yyvsp[(2) - (3)]);
				(yyval) = gen_hiddendo(_generate_stmt);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 957 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 964 "for90.y"
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
#line 975 "for90.y"
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
#line 1015 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite_true = (yyvsp[(5) - (7)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1022 "for90.y"
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
#line 1030 "for90.y"
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
#line 1038 "for90.y"
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
#line 1047 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1054 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode & stmt_true = (yyvsp[(3) - (3)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1062 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1070 "for90.y"
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
#line 1082 "for90.y"
    {
				ParseNode & suite = (yyvsp[(3) - (5)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1088 "for90.y"
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
#line 1098 "for90.y"
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
#line 1108 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1119 "for90.y"
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
#line 1127 "for90.y"
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
#line 1135 "for90.y"
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
#line 1143 "for90.y"
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
#line 1154 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1159 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1169 "for90.y"
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
#line 1185 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1193 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1198 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1204 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild(new ParseNode((yyvsp[(1) - (1)]))); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1213 "for90.y"
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

  case 177:
/* Line 1792 of yacc.c  */
#line 1225 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1231 "for90.y"
    {
				program_tree = (yyvsp[(1) - (1)]);
			}
    break;


/* Line 1792 of yacc.c  */
#line 3696 "for90.tab.cpp"
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
#line 1237 "for90.y"

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
