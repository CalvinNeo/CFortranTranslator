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


// ǰ������, ��Ȼ���벻��
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
     YY_POS = 276,
     _YY_TYPE = 277,
     YY_INTEGER = 278,
     YY_FLOAT = 279,
     YY_WORD = 280,
     YY_OPERATOR = 281,
     YY_STRING = 282,
     YY_ILLEGAL = 283,
     YY_COMPLEX = 284,
     YY_TRUE = 285,
     YY_FALSE = 286,
     _YY_CONTROL = 287,
     YY_END = 288,
     YY_IF = 289,
     YY_THEN = 290,
     YY_ELSE = 291,
     YY_ELSEIF = 292,
     YY_ENDIF = 293,
     YY_DO = 294,
     YY_ENDDO = 295,
     YY_CONTINUE = 296,
     YY_BREAK = 297,
     YY_WHILE = 298,
     YY_ENDWHILE = 299,
     YY_WHERE = 300,
     YY_ENDWHERE = 301,
     YY_CASE = 302,
     YY_ENDCASE = 303,
     YY_SELECT = 304,
     YY_ENDSELECT = 305,
     YY_GOTO = 306,
     YY_DOWHILE = 307,
     YY_DEFAULT = 308,
     _YY_DELIM = 309,
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
     _YY_DESCRIBER = 324,
     YY_IMPLICIT = 325,
     YY_NONE = 326,
     YY_USE = 327,
     YY_PARAMETER = 328,
     YY_FORMAT = 329,
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
     _YY_TYPEDEF = 341,
     YY_INTEGER_T = 342,
     YY_FLOAT_T = 343,
     YY_STRING_T = 344,
     YY_COMPLEX_T = 345,
     YY_BOOL_T = 346,
     YY_CHARACTER_T = 347,
     _YY_COMMAND = 348,
     YY_WRITE = 349,
     YY_READ = 350,
     YY_PRINT = 351,
     YY_CALL = 352
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
#line 258 "for90.tab.cpp"

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
#define YYLAST   1513

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   352

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     107,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     104,   105,   101,    99,   106,   100,     2,   102,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   108,   103,
       2,    98,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97
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
     285,   287,   289,   295,   298,   302,   306,   310,   312,   314,
     316,   318,   320,   322,   327,   332,   337,   342,   347,   352,
     354,   359,   361,   365,   369,   371,   373,   375,   379,   380,
     388,   392,   396,   400,   402,   403,   405,   409,   418,   430,
     440,   453,   458,   464,   471,   478,   490,   504,   512,   523,
     530,   532,   535,   540,   541,   543,   545,   558,   560,   561,
     570,   572,   574,   576,   579,   589,   591
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,     5,    -1,   103,    -1,    -1,    59,    -1,
      -1,    79,   104,    80,   105,    -1,    79,   104,    81,   105,
      -1,    79,   104,    82,   105,    -1,    76,   104,   119,   105,
      -1,    76,   104,   122,   105,    -1,    83,    -1,    73,    -1,
      85,    98,    23,    -1,    84,    98,   122,    -1,   106,   112,
      -1,   106,   112,   114,    -1,    -1,    24,    -1,    23,    -1,
      27,    -1,    30,    -1,    31,    -1,    29,    -1,     1,   107,
      -1,    25,    -1,   116,    -1,   142,    -1,   122,   108,   122,
      -1,   122,   108,   122,   108,   122,    -1,   108,    -1,   118,
      -1,   118,   106,   119,    -1,   122,    -1,   122,   106,   147,
      -1,   117,   104,   147,   105,    -1,   120,    -1,    97,   120,
      -1,   121,    -1,   122,   104,   122,   105,    -1,   104,   122,
     105,    -1,   122,    99,   122,    -1,   122,   100,   122,    -1,
     122,   101,   122,    -1,   122,   102,   122,    -1,   122,    18,
     122,    -1,   100,   122,    -1,    99,   122,    -1,   122,    12,
     122,    -1,   122,    13,   122,    -1,   122,     9,   122,    -1,
     122,    14,   122,    -1,   122,    15,   122,    -1,   122,    16,
     122,    -1,    17,   122,    -1,   122,     7,   122,    -1,   122,
       8,   122,    -1,   122,    10,   122,    -1,   122,    11,   122,
      -1,   149,    -1,   115,    -1,   117,    -1,   110,    -1,   103,
     110,    -1,   103,    -1,    -1,   122,   123,    -1,   144,   123,
      -1,   128,    -1,   126,    -1,   127,    -1,   131,    -1,   130,
      -1,   129,    -1,   166,    -1,   124,     5,    -1,   139,   123,
      -1,   140,   123,    -1,   141,   123,    -1,   153,    -1,   155,
      -1,   156,    -1,    41,   123,    -1,    42,   123,    -1,    51,
      23,   123,    -1,   122,    98,   122,   123,    -1,    70,    71,
     110,    -1,   125,    -1,   125,   132,    -1,   166,    -1,   166,
     132,    -1,    -1,   104,    -1,    -1,   105,    -1,   106,    -1,
      -1,   101,    -1,    23,    -1,   101,    -1,    27,    -1,   104,
     136,   106,   137,   105,    -1,   137,   135,    -1,    94,   138,
     147,    -1,    96,   138,   147,    -1,    95,   138,   147,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    87,   104,   113,   105,    -1,    88,   104,   113,
     105,    -1,    89,   104,   113,   105,    -1,    90,   104,   113,
     105,    -1,    91,   104,   113,   105,    -1,    92,   104,   113,
     105,    -1,   142,    -1,   143,   114,    19,   147,    -1,   116,
      -1,   116,    98,   122,    -1,   116,    98,   152,    -1,   145,
      -1,   119,    -1,   146,    -1,   146,   106,   147,    -1,    -1,
     122,   106,   116,    98,   122,   106,   122,    -1,   104,   148,
     105,    -1,    77,   147,    78,    -1,    77,   148,    78,    -1,
      35,    -1,    -1,   150,    -1,   150,   106,   152,    -1,    34,
     122,    35,   110,   132,    33,    34,   110,    -1,    34,   122,
      35,   110,   132,    36,   110,   132,    33,    34,   110,    -1,
      34,   122,    35,   110,   132,   154,    33,    34,   110,    -1,
      34,   122,    35,   110,   132,   154,    36,   110,   132,    33,
      34,   110,    -1,    34,   122,   151,   125,    -1,    37,   122,
      35,   110,   132,    -1,    37,   122,    35,   110,   132,   154,
      -1,    39,   110,   132,    33,    39,   110,    -1,    39,   116,
      98,   122,   106,   122,   110,   132,    33,    39,   110,    -1,
      39,   116,    98,   122,   106,   122,   106,   122,   110,   132,
      33,    39,   110,    -1,    52,   122,   110,   132,    33,    39,
     110,    -1,    49,    47,   133,   122,   134,   110,   158,    33,
      49,   110,    -1,    47,   133,   119,   134,   110,   132,    -1,
     157,    -1,   157,   158,    -1,    60,   104,   116,   105,    -1,
      -1,    57,    -1,    61,    -1,   111,   160,   116,   104,   147,
     105,   159,   110,   132,    33,   160,   110,    -1,    25,    -1,
      -1,    55,   162,   110,   132,    33,    55,   162,   110,    -1,
     161,    -1,   163,    -1,   164,    -1,   164,   165,    -1,    67,
     162,   110,   165,   110,    33,    67,   162,   110,    -1,   165,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   117,   136,   143,   152,   163,   169,   174,   188,   197,
     202,   206,   211,   215,   219,   226,   229,   236,   242,   249,
     258,   268,   278,   288,   299,   306,   316,   326,   330,   335,
     342,   350,   358,   366,   374,   382,   390,   398,   405,   412,
     420,   428,   436,   444,   452,   460,   467,   475,   483,   491,
     499,   505,   509,   530,   531,   533,   538,   542,   553,   559,
     563,   567,   571,   575,   580,   585,   589,   596,   597,   599,
     601,   602,   603,   605,   606,   607,   613,   622,   629,   634,
     639,   644,   652,   653,   654,   655,   656,   657,   658,   662,
     666,   670,   677,   688,   702,   710,   719,   727,   732,   737,
     742,   747,   752,   758,   765,   770,   775,   780,   785,   790,
     793,   804,   812,   819,   828,   831,   835,   841,   849,   856,
     868,   876,   884,   894,   895,   897,   902,   909,   918,   927,
     936,   946,   953,   961,   970,   976,   986,   996,  1004,  1012,
    1020,  1028,  1039,  1045,  1051,  1052,  1054,  1067,  1068,  1070,
    1081,  1086,  1092,  1101,  1113,  1122,  1126
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
  "YY_DOUBLECOLON", "YY_NEG", "YY_POS", "_YY_TYPE", "YY_INTEGER",
  "YY_FLOAT", "YY_WORD", "YY_OPERATOR", "YY_STRING", "YY_ILLEGAL",
  "YY_COMPLEX", "YY_TRUE", "YY_FALSE", "_YY_CONTROL", "YY_END", "YY_IF",
  "YY_THEN", "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO", "YY_ENDDO",
  "YY_CONTINUE", "YY_BREAK", "YY_WHILE", "YY_ENDWHILE", "YY_WHERE",
  "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT",
  "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT", "_YY_DELIM", "YY_PROGRAM",
  "YY_ENDPROGRAM", "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE",
  "YY_RESULT", "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE",
  "YY_ENDMODULE", "YY_BLOCK", "YY_ENDBLOCK", "YY_INTERFACE",
  "YY_ENDINTERFACE", "_YY_DESCRIBER", "YY_IMPLICIT", "YY_NONE", "YY_USE",
  "YY_PARAMETER", "YY_FORMAT", "YY_ENTRY", "YY_DIMENSION",
  "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN",
  "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN", "YY_KIND", "_YY_TYPEDEF",
  "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "_YY_COMMAND", "YY_WRITE", "YY_READ", "YY_PRINT",
  "YY_CALL", "'='", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','",
  "'\\n'", "':'", "$accept", "crlf", "dummy_function_iden",
  "variable_desc_elem", "typecast_spec", "variable_desc", "literal",
  "variable", "callable_head", "slice", "dimen_slice",
  "function_array_body", "function_array", "exp", "_crlf_semicolon",
  "semicolon", "stmt", "output_stmt", "input_stmt", "compound_stmt",
  "jump_stmt", "let_stmt", "dummy_stmt", "suite", "_optional_lbrace",
  "_optional_rbrace", "_optional_comma", "_optional_device",
  "_optional_formatter", "io_info", "write", "print", "read",
  "type_nospec", "type_spec", "var_def", "keyvalue", "paramtable_elem",
  "paramtable", "_generate_stmt", "hidden_do", "array_builder_elem",
  "_optional_then", "array_builder", "if_stmt", "elseif_stmt", "do_stmt",
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
     345,   346,   347,   348,   349,   350,   351,   352,    61,    43,
      45,    42,    47,    59,    40,    41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   116,   117,   117,   118,
     118,   118,   119,   119,   119,   119,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     128,   128,   128,   129,   129,   129,   130,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   140,   141,   142,   142,   142,
     142,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     144,   145,   145,   145,   146,   146,   147,   147,   147,   148,
     149,   150,   150,   151,   151,   152,   152,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   155,   155,   156,   157,
     158,   158,   159,   159,   160,   160,   161,   162,   162,   163,
     164,   164,   165,   165,   166,   167,   167
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
       1,     1,     5,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     1,
       4,     1,     3,     3,     1,     1,     1,     3,     0,     7,
       3,     3,     3,     1,     0,     1,     3,     8,    11,     9,
      12,     4,     5,     6,     6,    11,    13,     7,    10,     6,
       1,     2,     4,     0,     1,     1,    12,     1,     0,     8,
       1,     1,     1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,   158,     5,     0,   160,   161,   162,   165,     0,   157,
       4,   154,   155,     0,   163,     1,     2,     3,     0,    26,
       0,     0,     0,    20,    19,    21,    24,    22,    23,     0,
       4,     4,     4,     0,     0,     0,   158,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
      65,     0,    61,    27,    62,    37,    39,     4,     0,     0,
      70,    71,    69,    74,    73,    72,     0,     4,     4,     4,
      28,    18,     4,    60,    80,    81,    82,     0,     0,    25,
     107,   108,   109,   110,   111,   112,    55,    28,   134,     0,
       0,     3,    63,    83,    84,    92,     4,     4,     4,     4,
       0,     0,     0,     0,     0,     0,   101,   100,     0,    97,
       0,     0,     0,     0,    38,    48,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    76,    89,
       0,    77,    78,    79,     0,     0,    68,    91,    31,    27,
      32,   125,    34,   124,   126,     0,     4,     0,     0,     0,
      64,    93,     0,    85,     0,     6,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    98,     0,    96,   103,
     104,   106,   105,    41,     0,   130,     0,    56,    57,    51,
      58,    59,    49,    50,    52,    53,    54,    46,     4,    42,
      43,    44,    45,     0,   158,    13,     0,     0,    12,    16,
       0,     0,     0,     0,     0,     0,   153,     0,   141,    75,
       0,     0,    94,     0,     4,     0,     0,   113,   114,   115,
     116,   117,   118,     0,     0,    36,    86,    40,     4,     0,
       0,    17,   120,     0,   122,   135,   123,    33,    35,    29,
     127,     0,     4,     0,     4,     0,    95,     4,     0,     0,
      15,    14,     0,     0,   159,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,   144,     4,     0,     4,     0,   102,     0,    10,    11,
       7,     8,     9,     0,   131,   132,   136,    30,     0,     0,
       4,     0,     0,     0,     4,     0,     0,    92,   150,     0,
     147,   158,     0,    27,   152,     0,   137,     0,     4,     4,
       0,     4,     0,     0,   151,     0,     4,   129,     0,     4,
       0,     0,   139,     0,     0,     0,    94,     4,   164,   122,
     156,     4,   142,     0,     0,     4,     4,   148,   138,   143,
       4,     0,   145,     0,   140,     4,   149,   146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,     3,   209,   169,   145,    52,    53,    54,   150,
     151,    55,    56,    57,    93,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   162,   257,   179,   177,   109,   110,
      67,    68,    69,    87,    71,    72,   153,   154,   248,   118,
      73,   245,   157,   246,    74,   280,    75,    76,   308,   309,
     252,    13,     4,    10,     5,     6,     7,    77,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -206
static const yytype_int16 yypact[] =
{
      23,   -12,  -206,    13,  -206,  -206,    -2,  -206,    22,  -206,
       6,  -206,  -206,    10,  -206,  -206,  -206,  -206,   944,  -206,
     -68,   -53,   993,  -206,  -206,  -206,  -206,  -206,  -206,   993,
       1,     7,     7,     4,    29,   993,   -12,   -13,   -44,   -27,
     -18,    11,    12,    20,    -8,    -8,    -8,   234,   993,   993,
    -206,   993,  -206,  -206,    25,  -206,  -206,  1115,    64,   750,
    -206,  -206,  -206,  -206,  -206,  -206,    38,     7,     7,     7,
      -3,    -7,     7,  -206,  -206,  -206,  -206,   847,   373,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,    18,  -206,  1299,   944,
       0,     6,  -206,  -206,  -206,    36,     7,  1127,     6,     6,
     -55,   -55,   -55,   -55,   -55,   -55,  -206,  -206,    -6,     5,
     596,   596,   596,    25,  -206,   131,   131,  1139,   -11,   373,
     993,   993,   993,   993,   993,   993,   993,   993,   993,   993,
     993,   993,   993,   993,   993,   993,   993,  -206,  -206,  -206,
      46,  -206,  -206,  -206,   -33,    83,  -206,  -206,  -206,    14,
      42,  -206,   660,  -206,    51,    37,     6,   944,    84,   993,
    -206,  -206,   993,  -206,   944,   -31,  -206,    53,    61,    55,
      57,    58,    60,    62,    65,  -206,  -206,    66,  -206,  -206,
    -206,  -206,  -206,  -206,    10,  -206,    68,   131,   131,    54,
     131,   131,    54,  1329,  1329,  1409,  1341,    18,  1151,   198,
     198,    -4,    -4,  1275,   -12,  -206,    67,    71,  -206,    -7,
     596,   975,   719,   499,   993,   499,   106,   944,  -206,  -206,
     137,  1163,  1287,   144,     6,   993,   155,  -206,  -206,  -206,
    -206,  -206,  -206,    -9,    91,  -206,  -206,  -206,     6,   719,
       3,  -206,  -206,   627,  1329,    75,  -206,  -206,  -206,  1103,
    -206,    78,     6,    43,     6,   993,  -206,     6,   151,   158,
    1329,  -206,    87,   993,  -206,    89,   413,    92,    93,    94,
    1091,   128,   129,   124,   993,    10,   944,   175,     6,   993,
       8,  -206,   123,   166,     6,   148,  -206,  1263,  -206,  -206,
    -206,  -206,  -206,    96,  -206,  -206,  -206,  1329,   112,   185,
       6,   944,  1311,   187,     6,   993,   944,    36,   166,   186,
    -206,   -12,   993,   136,  -206,    13,  -206,   203,     6,     6,
     944,  1127,   204,   719,  -206,   190,     6,  1329,   975,     6,
     206,   944,  -206,   208,   944,   207,   138,     6,  -206,  1263,
    -206,     6,   211,   215,   218,     6,     6,  -206,  -206,  -206,
       6,   213,  -206,   944,  -206,     6,  -206,  -206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,   -10,  -206,  -206,   245,    44,  -206,    -5,   209,  -206,
    -205,   210,  -206,   232,   -30,  -206,    98,  -206,  -206,  -206,
    -206,  -206,  -206,   -56,   -49,   -76,  -206,  -206,    30,    45,
    -206,  -206,  -206,   -14,  -206,  -206,  -206,  -206,   -63,    26,
    -206,  -206,  -206,     9,  -206,   -77,  -206,  -206,  -206,   -42,
    -206,   -38,  -206,   -35,  -206,  -206,    -1,   114,  -206
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -167
static const yytype_int16 yytable[] =
{
      18,    98,    94,   139,    70,    14,    16,   247,    20,   126,
     127,    16,    16,     9,   130,   155,  -119,   175,   106,   106,
      89,   147,    15,  -166,     1,    90,    19,   137,     2,   167,
     168,   126,   127,   158,   265,    19,    78,   141,   142,   143,
     205,   303,   146,   206,   304,    70,   207,   180,   181,   182,
     208,    95,    96,     1,    79,    -6,   186,     2,    99,    -6,
     100,   120,   121,    70,   123,   124,   163,   126,   127,   138,
      11,   140,   130,   149,    12,    70,   277,   101,     1,   278,
     279,   160,     2,   267,   268,   269,   102,   164,   165,   166,
     111,   112,   107,   107,   185,   176,   108,    21,   159,   144,
     136,   204,   210,  -119,    17,   149,   149,   149,   223,    17,
      91,   178,   211,    22,   149,   103,   104,   220,   336,    23,
      24,    19,   136,    25,   105,    26,    27,    28,    16,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     161,   130,   216,    70,   126,   127,   217,   242,   212,   130,
      70,   225,   250,   132,   133,   134,   135,   215,   136,   226,
     227,   253,   228,   229,   224,   230,   251,   231,   236,   238,
     232,   239,   233,   235,  -128,   240,   254,   258,   261,   234,
     271,   273,   275,    80,    81,    82,    83,    84,    85,   263,
     284,   285,   286,    47,   288,    48,    49,   290,   291,   292,
      51,   243,  -128,    70,   148,   149,   294,   295,   149,   300,
     149,   126,   127,   307,   259,   311,   130,   314,   315,   325,
     299,   319,   132,   133,   134,   135,    17,   136,   264,   305,
     132,   133,   134,   135,   328,   136,   330,   335,   149,   337,
     341,   343,   276,   256,   281,   317,   345,   283,   279,   350,
     322,   351,   355,   241,    86,   218,   113,   114,   323,    19,
     346,    88,    70,   262,   333,   349,   324,    97,   301,   272,
     298,   219,   306,     0,   310,   342,   326,   329,   344,     0,
     115,   116,   296,   117,     0,     0,     0,    70,   313,     0,
     316,     0,    70,     0,   320,     0,     0,   356,     0,   134,
     135,     0,   136,     0,     0,     0,    70,     0,   331,   332,
     152,   334,     0,     0,     0,     0,   338,    70,     0,   340,
      70,    80,    81,    82,    83,    84,    85,   347,     0,     0,
       0,   348,     0,     0,     0,   352,   353,     0,     0,    70,
     354,     0,   152,   152,   152,   357,   170,   171,   172,   173,
     174,   152,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,   221,     0,     0,   222,     0,    23,    24,    19,     0,
      25,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   244,   152,   152,   249,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
      47,   266,    48,    49,     0,   270,     0,    51,  -128,     0,
       0,   148,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
      21,     0,     0,     0,  -128,     0,   297,     0,     0,     0,
       0,   302,   132,   133,   134,   135,    22,   136,   289,   213,
       0,   214,    23,    24,    19,   152,    25,     0,    26,    27,
      28,     0,  -128,  -128,     0,  -128,  -128,   321,  -128,     0,
    -128,  -128,     0,     0,   327,     0,  -128,     0,  -128,     0,
    -128,  -128,     0,     0,     0,   152,     0,     0,     0,     0,
     339,     0,     0,     0,     0,     0,  -128,     0,     0,  -128,
       0,     0,     0,     0,     0,     0,     0,  -128,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,     0,  -128,  -128,  -128,    47,    21,    48,    49,
       0,  -128,  -128,    51,  -128,  -128,     0,   148,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,    23,
      24,    19,     0,    25,     0,    26,    27,    28,    21,  -128,
    -128,     0,  -128,  -128,     0,  -128,     0,  -128,  -128,     0,
       0,     0,     0,  -128,    22,  -128,     0,  -128,  -128,     0,
      23,    24,    19,     0,    25,     0,    26,    27,    28,     0,
       0,     0,     0,  -128,     0,     0,  -128,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,   130,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,     0,
    -128,  -128,  -128,    47,     0,    48,    49,     0,     0,  -128,
      51,     0,     0,     0,   148,  -128,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      21,     0,     0,     0,    47,     0,    48,    49,     0,     0,
       0,    51,     0,     0,     0,   148,    22,     0,     0,     0,
       0,     0,    23,    24,    19,     0,    25,     0,    26,    27,
      28,    21,     0,     0,     0,   -66,     0,     0,     0,   132,
     133,   134,   135,     0,   136,     0,   213,    22,   214,     0,
       0,     0,     0,    23,    24,    19,     0,    25,     0,    26,
      27,    28,     0,   -88,    29,     0,   -88,   -88,     0,    30,
       0,    31,    32,     0,     0,     0,     0,   -88,     0,    33,
       0,    34,    35,     0,     0,     0,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    47,    36,    48,    49,
      37,     0,     0,    51,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    21,    48,
      49,     0,   -66,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
      23,    24,    19,     0,    25,     0,    26,    27,    28,     0,
     -75,    29,     0,   -75,   -75,     0,    30,     0,    31,    32,
       0,     0,     0,     0,   -75,     0,    33,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    21,    48,    49,     0,   -66,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,    23,    24,    19,
       0,    25,     0,    26,    27,    28,    21,     0,    29,     0,
       0,     0,     0,    30,     0,    31,    32,     0,     0,     0,
       0,     0,    22,    33,    21,    34,    35,     0,    23,    24,
      19,     0,    25,     0,    26,    27,    28,     0,     0,     0,
      22,    36,     0,     0,    37,     0,    23,    24,    19,     0,
      25,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,     0,     0,    50,    51,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    47,     0,    48,    49,     0,     0,     0,    51,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
      47,     0,    48,    49,     0,     0,     0,    51,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,   130,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      16,   130,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    16,   130,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,   130,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    16,   130,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,   130,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   133,   134,   135,     0,   136,     0,   293,     0,   214,
       0,     0,   132,   133,   134,   135,     0,   136,     0,     0,
       0,   274,     0,   131,   132,   133,   134,   135,    91,   136,
       0,     0,     0,     0,     0,     0,   132,   133,   134,   135,
      17,   136,     0,     0,     0,     0,     0,     0,   132,   133,
     134,   135,     0,   136,   183,   184,     0,     0,     0,     0,
     132,   133,   134,   135,    91,   136,     0,     0,     0,     0,
       0,     0,   132,   133,   134,   135,     0,   136,     0,   255,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,   130,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,   130,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,   130,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,   130,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,   130,
       0,     0,     0,     0,   156,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   318,   130,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,     0,   130,
       0,     0,   132,   133,   134,   135,     0,   136,     0,   312,
       0,     0,     0,     0,   132,   133,   134,   135,     0,   136,
     237,     0,     0,     0,     0,     0,   132,   133,   134,   135,
       0,   136,   256,     0,     0,     0,     0,     0,   132,   133,
     134,   135,     0,   136,     0,     0,     0,     0,     0,     0,
     132,   133,   134,   135,     0,   136,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,   130,   132,   133,
     134,   135,     0,   136,     0,     0,     0,     0,     0,     0,
     132,   133,   134,   135,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   133,
     134,   135,     0,   136
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-206)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,    36,    32,    59,    18,     6,     5,   212,    13,    13,
      14,     5,     5,    25,    18,    78,    19,    23,    27,    27,
      30,    77,     0,     0,    55,    30,    25,    57,    59,    84,
      85,    13,    14,    89,   239,    25,   104,    67,    68,    69,
      73,    33,    72,    76,    36,    59,    79,   110,   111,   112,
      83,    47,    23,    55,   107,    57,   119,    59,    71,    61,
     104,     7,     8,    77,    10,    11,    96,    13,    14,     5,
      57,    33,    18,    78,    61,    89,    33,   104,    55,    36,
      37,    91,    59,    80,    81,    82,   104,    97,    98,    99,
      45,    46,   101,   101,   105,   101,   104,     1,    98,   106,
     104,    55,    19,   106,   103,   110,   111,   112,   164,   103,
     103,   106,    98,    17,   119,   104,   104,    33,   323,    23,
      24,    25,   104,    27,   104,    29,    30,    31,     5,   104,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     104,    18,   105,   157,    13,    14,   156,   210,   106,    18,
     164,    98,   215,    99,   100,   101,   102,   106,   104,    98,
     105,   217,   105,   105,   165,   105,    60,   105,   198,   204,
     105,   104,   106,   105,    78,   104,    39,    33,    23,   184,
     243,   106,   104,    87,    88,    89,    90,    91,    92,    98,
      39,    33,   105,    97,   105,    99,   100,   105,   105,   105,
     104,    77,   106,   217,   108,   210,    78,    78,   213,    34,
     215,    13,    14,    47,   224,    67,    18,   105,    33,    33,
     276,    34,    99,   100,   101,   102,   103,   104,   238,   106,
      99,   100,   101,   102,    98,   104,    33,    33,   243,    49,
      34,    33,   252,   105,   254,   301,    39,   257,    37,    34,
     306,    33,    39,   209,    22,   157,    47,    47,   307,    25,
     336,    29,   276,   233,   320,   342,   308,    35,   278,   243,
     275,   157,   282,    -1,   284,   331,   311,   315,   334,    -1,
      48,    49,   273,    51,    -1,    -1,    -1,   301,   293,    -1,
     300,    -1,   306,    -1,   304,    -1,    -1,   353,    -1,   101,
     102,    -1,   104,    -1,    -1,    -1,   320,    -1,   318,   319,
      78,   321,    -1,    -1,    -1,    -1,   326,   331,    -1,   329,
     334,    87,    88,    89,    90,    91,    92,   337,    -1,    -1,
      -1,   341,    -1,    -1,    -1,   345,   346,    -1,    -1,   353,
     350,    -1,   110,   111,   112,   355,   101,   102,   103,   104,
     105,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,   159,    -1,    -1,   162,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,
      97,   239,    99,   100,    -1,   243,    -1,   104,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     5,    -1,   274,    -1,    -1,    -1,
      -1,   279,    99,   100,   101,   102,    17,   104,   105,   106,
      -1,   108,    23,    24,    25,   293,    27,    -1,    29,    30,
      31,    -1,    33,    34,    -1,    36,    37,   305,    39,    -1,
      41,    42,    -1,    -1,   312,    -1,    47,    -1,    49,    -1,
      51,    52,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,
     328,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,     1,    99,   100,
      -1,     5,   103,   104,   105,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    27,    -1,    29,    30,    31,     1,    33,
      34,    -1,    36,    37,    -1,    39,    -1,    41,    42,    -1,
      -1,    -1,    -1,    47,    17,    49,    -1,    51,    52,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
       1,    -1,    -1,    -1,    97,    -1,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,    -1,   108,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,    30,
      31,     1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,   104,    -1,   106,    17,   108,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    37,    -1,    39,
      -1,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    97,    67,    99,   100,
      70,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,     1,    99,
     100,    -1,     5,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    39,    -1,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,     1,    99,   100,    -1,     5,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    27,    -1,    29,    30,    31,     1,    -1,    34,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    17,    49,     1,    51,    52,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,
      17,    67,    -1,    -1,    70,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    97,    -1,    99,   100,    -1,    -1,    -1,   104,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,
      97,    -1,    99,   100,    -1,    -1,    -1,   104,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       5,    18,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     5,    18,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     5,    18,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,    -1,   106,    -1,   108,
      -1,    -1,    99,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,   108,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,    -1,   104,    -1,   106,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    35,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    35,    18,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    99,   100,   101,   102,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,
     105,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    18,    99,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    59,   111,   161,   163,   164,   165,   167,    25,
     162,    57,    61,   160,   165,     0,     5,   103,   110,    25,
     116,     1,    17,    23,    24,    27,    29,    30,    31,    34,
      39,    41,    42,    49,    51,    52,    67,    70,    87,    88,
      89,    90,    91,    92,    94,    95,    96,    97,    99,   100,
     103,   104,   115,   116,   117,   120,   121,   122,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   139,   140,   141,
     142,   143,   144,   149,   153,   155,   156,   166,   104,   107,
      87,    88,    89,    90,    91,    92,   122,   142,   122,   110,
     116,   103,   110,   123,   123,    47,    23,   122,   162,    71,
     104,   104,   104,   104,   104,   104,    27,   101,   104,   137,
     138,   138,   138,   117,   120,   122,   122,   122,   148,   104,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      18,    98,    99,   100,   101,   102,   104,   123,     5,   132,
      33,   123,   123,   123,   106,   114,   123,   132,   108,   116,
     118,   119,   122,   145,   146,   147,    35,   151,   132,    98,
     110,   104,   133,   123,   110,   110,   110,    84,    85,   113,
     113,   113,   113,   113,   113,    23,   101,   136,   106,   135,
     147,   147,   147,   105,   106,   105,   147,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,    55,    73,    76,    79,    83,   112,
      19,    98,   106,   106,   108,   106,   105,   110,   125,   166,
      33,   122,   122,   132,   165,    98,    98,   105,   105,   105,
     105,   105,   105,   106,   116,   105,   123,   105,   162,   104,
     104,   114,   147,    77,   122,   150,   152,   119,   147,   122,
     147,    60,   159,   132,    39,   106,   105,   134,    33,   110,
     122,    23,   137,    98,   110,   119,   122,    80,    81,    82,
     122,   147,   148,   106,   108,   104,   110,    33,    36,    37,
     154,   110,   122,   110,    39,    33,   105,   122,   105,   105,
     105,   105,   105,   106,    78,    78,   152,   122,   116,   132,
      34,   110,   122,    33,    36,   106,   110,    47,   157,   158,
     110,    67,   106,   116,   105,    33,   110,   132,    35,    34,
     110,   122,   132,   133,   158,    33,   162,   122,    98,   160,
      33,   110,   110,   132,   110,    33,   119,    49,   110,   122,
     110,    34,   132,    33,   132,    39,   134,   110,   110,   154,
      34,    33,   110,   110,   110,    39,   132,   110
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
				// do nothing because we use std::string
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 170 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 175 "for90.y"
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
#line 188 "for90.y"
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
#line 198 "for90.y"
    {
				/* ����Ŀ�µ��Ҳ�ȫ��Ϊ�����ս����(�﷨����Ҷ�ӽڵ�), ���$1ȫ������lex���� */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 203 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 207 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 212 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 216 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 220 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 230 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 237 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 243 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 250 "for90.y"
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
#line 259 "for90.y"
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
#line 269 "for90.y"
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
#line 279 "for90.y"
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
#line 289 "for90.y"
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
#line 300 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_argtable_from_exp(exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 307 "for90.y"
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
#line 317 "for90.y"
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
#line 327 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)])
			;}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 331 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)])
			;}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 336 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_exp(function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 343 "for90.y"
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
#line 351 "for90.y"
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
#line 359 "for90.y"
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
#line 367 "for90.y"
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
#line 375 "for90.y"
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
#line 383 "for90.y"
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
#line 391 "for90.y"
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
#line 399 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 406 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 413 "for90.y"
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
#line 421 "for90.y"
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
#line 429 "for90.y"
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
#line 437 "for90.y"
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
#line 445 "for90.y"
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
#line 453 "for90.y"
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
#line 461 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 468 "for90.y"
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
#line 476 "for90.y"
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
#line 484 "for90.y"
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
#line 492 "for90.y"
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
#line 500 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_exp(hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 506 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 510 "for90.y"
    {
				// may cause reduction-reduction conflict when use `variable` instead of `callable_head`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable_head will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 534 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 538 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 543 "for90.y"
    {
				// TODO IMPORTANT
				/*
					һ����˵, ���Բ���������stmt��ParseNode, �����Ψһ��child(exp, var_def, compound_stmt��).
					���ǿ��ǵ���cpp�������п��ܳ���ʹ��,�ָ�����������(��������������õ�, �������������԰����Լ���˳����ֵ)
					���Ե�������stmt�ڵ�����$1λstmt�ڵ��Ψһ�Ķ���
				*/
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ;");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 554 "for90.y"
    {
				/* ��Ϊvar_def����������ɶ��д���, ��˴˴����ɴ��벻Ӧ�����ֺ�`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 560 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 564 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 568 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 572 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 576 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 581 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 586 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 590 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 608 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 614 "for90.y"
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
#line 623 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 630 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 635 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s\n%s", TokenMeta::NT_SUITE);;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 640 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 645 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				//$$.fs.CurrentTerm.what = $2.fs.CurrentTerm.what;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 659 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 663 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 667 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 671 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 678 "for90.y"
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

  case 103:
/* Line 1792 of yacc.c  */
#line 689 "for90.y"
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

  case 104:
/* Line 1792 of yacc.c  */
#line 703 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 711 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 720 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 728 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 733 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 738 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 743 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 748 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 753 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 759 "for90.y"
    {
				// now translated in pre_map
				//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 766 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 776 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 781 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 786 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 794 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 805 "for90.y"
    {	
				/* paramtable is used in function decl */
				/* this paramtable has only one value */
				ParseNode & variable = (yyvsp[(1) - (1)]);
				(yyval) = gen_keyvalue(variable);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 813 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 820 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* array initial values */;
				/* ��Ϊʹ��forarray��Ϊ����, ����Ҫ֪��������Ϣ, ���ڴ˴���ֵ, ���ϲ��var_def����ֵ */
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 829 "for90.y"
    {
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 832 "for90.y"
    {
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 836 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				(yyval) = gen_paramtable(paramtable_elem);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 842 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_flattern(paramtable_elem, paramtable, "%s, %s", TokenMeta::NT_PARAMTABLE);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 849 "for90.y"
    {
				/* no params */
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PARAMTABLE, "" }), nullptr);
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 857 "for90.y"
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

  case 130:
/* Line 1792 of yacc.c  */
#line 869 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode & _generate_stmt = (yyvsp[(2) - (3)]);
				(yyval) = gen_hiddendo(_generate_stmt);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 877 "for90.y"
    {
				/* give initial value */
				/* `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules */
				/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
				(yyval) = gen_array_generate_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 885 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_generate_stmt((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				/* rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule*/
				/* note that this two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict */
				/* note either that `variable '(' dimen_slice ')'` is an `exp` */
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 898 "for90.y"
    {
				(yyval) = gen_promote("%s", TokenMeta::NT_ARRAYBUILDER, (yyvsp[(1) - (1)])); // array_builder_elem
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 903 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "%s\n%s", TokenMeta::NT_ARRAYBUILDER);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));

			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 910 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (8)]);
				ParseNode & suite_true = (yyvsp[(5) - (8)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());

				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 919 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]); 
				ParseNode & suite_else = (yyvsp[(8) - (11)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 928 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (9)]);
				ParseNode & suite_true = (yyvsp[(5) - (9)]);
				ParseNode & elseif = (yyvsp[(6) - (9)]);
				//sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 937 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (12)]);
				ParseNode & suite_true = (yyvsp[(5) - (12)]);
				ParseNode & elseif = (yyvsp[(6) - (12)]);
				ParseNode & suite_else = (yyvsp[(9) - (12)]); 
				//sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 947 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 954 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 962 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 971 "for90.y"
    {
				ParseNode & suite = (yyvsp[(3) - (6)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 977 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(2) - (11)]);
				ParseNode & exp_from = (yyvsp[(4) - (11)]);
				ParseNode & exp_to = (yyvsp[(6) - (11)]);
				ParseNode & step = gen_exp(gen_token(Term{ TokenMeta::META_INTEGER , "1" }));
				ParseNode & suite = (yyvsp[(8) - (11)]); 
				(yyval) = gen_do_range(loop_variable, exp_from, exp_to, step, suite);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 987 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(2) - (13)]);
				ParseNode & exp1 = (yyvsp[(4) - (13)]);
				ParseNode & exp2 = (yyvsp[(6) - (13)]);
				ParseNode & exp3 = (yyvsp[(8) - (13)]);
				ParseNode & suite = (yyvsp[(10) - (13)]);
				(yyval) = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos((yyval), (yyvsp[(1) - (13)]), (yyvsp[(13) - (13)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 997 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite = (yyvsp[(4) - (7)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1005 "for90.y"
    {
				ParseNode & select = (yyvsp[(1) - (10)]);
				ParseNode & exp = (yyvsp[(4) - (10)]);
				ParseNode & case_stmt = (yyvsp[(7) - (10)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1013 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1021 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_CASES, "" }), nullptr);
				newnode.addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1029 "for90.y"
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

  case 152:
/* Line 1792 of yacc.c  */
#line 1040 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1045 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1055 "for90.y"
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

  case 159:
/* Line 1792 of yacc.c  */
#line 1071 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", tabber(suite.fs.CurrentTerm.what).c_str());
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_PROGRAM, string(codegen_buf) }), nullptr);
				newnode.addchild(new ParseNode(suite)); //suite
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1082 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1087 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1093 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild(new ParseNode((yyvsp[(1) - (1)]))); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1102 "for90.y"
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

  case 164:
/* Line 1792 of yacc.c  */
#line 1114 "for90.y"
    {
				// drop interface directly
				//ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
				// no child
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1123 "for90.y"
    {
				program_tree = (yyvsp[(1) - (1)]);
			}
    break;


/* Line 1792 of yacc.c  */
#line 3534 "for90.tab.cpp"
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
#line 1129 "for90.y"

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
