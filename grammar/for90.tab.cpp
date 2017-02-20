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
     YY_LABEL = 285,
     YY_END = 286,
     YY_IF = 287,
     YY_THEN = 288,
     YY_ELSE = 289,
     YY_ELSEIF = 290,
     YY_ENDIF = 291,
     YY_DO = 292,
     YY_ENDDO = 293,
     YY_CONTINUE = 294,
     YY_BREAK = 295,
     YY_WHILE = 296,
     YY_ENDWHILE = 297,
     YY_WHERE = 298,
     YY_ENDWHERE = 299,
     YY_CASE = 300,
     YY_ENDCASE = 301,
     YY_SELECT = 302,
     YY_ENDSELECT = 303,
     YY_GOTO = 304,
     YY_DOWHILE = 305,
     YY_DEFAULT = 306,
     YY_PROGRAM = 307,
     YY_ENDPROGRAM = 308,
     YY_FUNCTION = 309,
     YY_ENDFUNCTION = 310,
     YY_RECURSIVE = 311,
     YY_RESULT = 312,
     YY_SUBROUTINE = 313,
     YY_ENDSUBROUTINE = 314,
     YY_MODULE = 315,
     YY_ENDMODULE = 316,
     YY_BLOCK = 317,
     YY_ENDBLOCK = 318,
     YY_INTERFACE = 319,
     YY_ENDINTERFACE = 320,
     YY_COMMON = 321,
     YY_DATA = 322,
     YY_IMPLICIT = 323,
     YY_NONE = 324,
     YY_USE = 325,
     YY_PARAMETER = 326,
     YY_ENTRY = 327,
     YY_DIMENSION = 328,
     YY_ARRAYINITIAL_START = 329,
     YY_ARRAYINITIAL_END = 330,
     YY_INTENT = 331,
     YY_IN = 332,
     YY_OUT = 333,
     YY_INOUT = 334,
     YY_OPTIONAL = 335,
     YY_LEN = 336,
     YY_KIND = 337,
     YY_SAVE = 338,
     YY_INTEGER_T = 339,
     YY_FLOAT_T = 340,
     YY_STRING_T = 341,
     YY_COMPLEX_T = 342,
     YY_BOOL_T = 343,
     YY_CHARACTER_T = 344,
     YY_WRITE = 345,
     YY_READ = 346,
     YY_PRINT = 347,
     YY_CALL = 348,
     YY_STOP = 349,
     YY_PAUSE = 350
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
#line 256 "for90.tab.cpp"

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
#define YYLAST   2328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNRULES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   350

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     105,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     102,   103,    99,    97,   104,    98,     2,   100,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   106,   101,
       2,    96,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    11,    16,    21,
      26,    31,    36,    38,    40,    42,    45,    49,    50,    54,
      58,    60,    62,    64,    66,    68,    70,    73,    75,    79,
      85,    87,    89,    93,    95,    99,   104,   109,   111,   114,
     116,   118,   123,   127,   131,   135,   139,   143,   147,   150,
     153,   157,   161,   165,   169,   173,   177,   180,   184,   188,
     192,   196,   198,   200,   202,   204,   207,   209,   210,   212,
     215,   218,   220,   222,   224,   226,   228,   230,   233,   235,
     238,   240,   243,   246,   249,   251,   253,   255,   258,   261,
     265,   270,   274,   276,   279,   281,   284,   285,   287,   288,
     290,   292,   293,   295,   297,   299,   301,   303,   309,   312,
     316,   320,   324,   326,   328,   330,   332,   334,   336,   341,
     346,   351,   356,   361,   366,   370,   372,   376,   379,   380,
     384,   389,   393,   396,   398,   402,   406,   408,   410,   412,
     416,   417,   427,   431,   435,   437,   440,   441,   444,   446,
     455,   467,   477,   490,   496,   501,   507,   514,   517,   519,
     526,   538,   552,   560,   563,   565,   576,   583,   585,   588,
     593,   594,   596,   598,   611,   613,   614,   623,   631,   633,
     635,   637,   639,   642,   652,   654
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     169,     0,    -1,     4,    -1,   101,    -1,    -1,    56,    -1,
      -1,    76,   102,    77,   103,    -1,    76,   102,    78,   103,
      -1,    76,   102,    79,   103,    -1,    73,   102,   116,   103,
      -1,    73,   102,   119,   103,    -1,    80,    -1,    71,    -1,
      83,    -1,   104,   110,    -1,   104,   110,   111,    -1,    -1,
      82,    96,    20,    -1,    81,    96,   119,    -1,    21,    -1,
      20,    -1,    24,    -1,    27,    -1,    28,    -1,    26,    -1,
       1,   105,    -1,    22,    -1,   119,   106,   119,    -1,   119,
     106,   119,   106,   119,    -1,   106,    -1,   115,    -1,   115,
     104,   116,    -1,   119,    -1,   119,   104,   147,    -1,   114,
     102,   147,   103,    -1,   140,   102,   147,   103,    -1,   117,
      -1,    93,   117,    -1,   118,    -1,   150,    -1,   119,   102,
     119,   103,    -1,   102,   119,   103,    -1,   119,    97,   119,
      -1,   119,    98,   119,    -1,   119,    99,   119,    -1,   119,
     100,   119,    -1,   119,    16,   119,    -1,    98,   119,    -1,
      97,   119,    -1,   119,    10,   119,    -1,   119,    11,   119,
      -1,   119,     7,   119,    -1,   119,    12,   119,    -1,   119,
      13,   119,    -1,   119,    14,   119,    -1,    15,   119,    -1,
     119,     5,   119,    -1,   119,     6,   119,    -1,   119,     8,
     119,    -1,   119,     9,   119,    -1,   148,    -1,   113,    -1,
     114,    -1,   108,    -1,   101,   108,    -1,   101,    -1,    -1,
      30,    -1,   119,   120,    -1,   144,   120,    -1,   126,    -1,
     124,    -1,   125,    -1,   129,    -1,   128,    -1,   127,    -1,
     121,     4,    -1,   143,    -1,    29,   120,    -1,   122,    -1,
     137,   120,    -1,   138,   120,    -1,   139,   120,    -1,   153,
      -1,   156,    -1,   158,    -1,    39,   120,    -1,    40,   120,
      -1,    49,    20,   120,    -1,   119,    96,   119,   120,    -1,
      68,    69,   108,    -1,   123,    -1,   123,   130,    -1,   168,
      -1,   168,   130,    -1,    -1,   102,    -1,    -1,   103,    -1,
     104,    -1,    -1,    99,    -1,    20,    -1,    99,    -1,    20,
      -1,    24,    -1,   102,   134,   104,   135,   103,    -1,   135,
     133,    -1,    90,   136,   147,    -1,    92,   136,   147,    -1,
      91,   136,   147,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    84,   102,   112,   103,
      -1,    85,   102,   112,   103,    -1,    86,   102,   112,   103,
      -1,    87,   102,   112,   103,    -1,    88,   102,   112,   103,
      -1,    89,   102,   112,   103,    -1,   140,    99,    20,    -1,
     140,    -1,   100,   114,   100,    -1,   100,   100,    -1,    -1,
      66,   142,   147,    -1,   141,   111,    17,   147,    -1,   141,
     111,   147,    -1,    73,   147,    -1,   114,    -1,   119,    96,
     119,    -1,   119,    96,   150,    -1,   116,    -1,   145,    -1,
     146,    -1,   146,   104,   147,    -1,    -1,   102,   119,   104,
     114,    96,   119,   104,   119,   103,    -1,    74,   147,    75,
      -1,    74,   148,    75,    -1,   149,    -1,    22,   106,    -1,
      -1,    31,    32,    -1,    36,    -1,   151,    32,   119,    33,
     108,   130,   152,   108,    -1,   151,    32,   119,    33,   108,
     130,    34,   108,   130,   152,   108,    -1,   151,    32,   119,
      33,   108,   130,   154,   152,   108,    -1,   151,    32,   119,
      33,   108,   130,   154,    34,   108,   130,   152,   108,    -1,
     151,    32,   119,    33,   123,    -1,   151,    32,   119,   123,
      -1,    35,   119,    33,   108,   130,    -1,    35,   119,    33,
     108,   130,   154,    -1,    31,    37,    -1,    38,    -1,   151,
      37,   108,   130,   155,   108,    -1,   151,    37,   114,    96,
     119,   104,   119,   108,   130,   155,   108,    -1,   151,    37,
     114,    96,   119,   104,   119,   104,   119,   108,   130,   155,
     108,    -1,   151,    50,   119,   108,   130,   155,   108,    -1,
      31,    47,    -1,    48,    -1,   151,    47,    45,   131,   119,
     132,   108,   160,   157,   108,    -1,    45,   131,   116,   132,
     108,   130,    -1,   159,    -1,   159,   160,    -1,    57,   102,
     114,   103,    -1,    -1,    54,    -1,    58,    -1,   109,   162,
     114,   102,   147,   103,   161,   108,   130,    31,   162,   108,
      -1,    22,    -1,    -1,    52,   164,   108,   130,    31,    52,
     164,   108,    -1,    52,   164,   108,    31,    52,   164,   108,
      -1,   130,    -1,   163,    -1,   165,    -1,   166,    -1,   166,
     167,    -1,    64,   164,   108,   167,   108,    31,    64,   164,
     108,    -1,   167,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   118,   136,   143,   151,   160,   165,   179,   192,   203,
     217,   222,   226,   231,   235,   239,   246,   248,   255,   264,
     274,   283,   293,   303,   310,   330,   340,   351,   355,   360,
     367,   375,   383,   391,   399,   407,   415,   423,   431,   438,
     445,   453,   462,   470,   479,   487,   495,   502,   510,   518,
     526,   534,   540,   545,   552,   553,   555,   560,   564,   570,
     580,   586,   590,   594,   598,   602,   607,   612,   617,   622,
     627,   635,   636,   638,   640,   641,   642,   644,   645,   646,
     652,   661,   668,   673,   694,   699,   707,   708,   709,   710,
     711,   712,   713,   717,   721,   725,   730,   737,   748,   762,
     770,   779,   787,   792,   797,   802,   807,   812,   818,   824,
     829,   834,   839,   844,   852,   857,   863,   868,   875,   881,
     889,   899,   909,   920,   925,   934,   943,   947,   951,   958,
     967,   975,   991,   998,  1009,  1024,  1025,  1028,  1029,  1032,
    1039,  1047,  1055,  1064,  1071,  1079,  1087,  1096,  1097,  1099,
    1105,  1115,  1125,  1133,  1134,  1136,  1144,  1152,  1160,  1170,
    1176,  1182,  1183,  1185,  1198,  1199,  1201,  1207,  1212,  1225,
    1230,  1236,  1245,  1257,  1263,  1267
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
  "YY_FORMAT_STMT", "YY_LABEL", "YY_END", "YY_IF", "YY_THEN", "YY_ELSE",
  "YY_ELSEIF", "YY_ENDIF", "YY_DO", "YY_ENDDO", "YY_CONTINUE", "YY_BREAK",
  "YY_WHILE", "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE", "YY_CASE",
  "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE",
  "YY_DEFAULT", "YY_PROGRAM", "YY_ENDPROGRAM", "YY_FUNCTION",
  "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT", "YY_SUBROUTINE",
  "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE", "YY_BLOCK",
  "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE", "YY_COMMON", "YY_DATA",
  "YY_IMPLICIT", "YY_NONE", "YY_USE", "YY_PARAMETER", "YY_ENTRY",
  "YY_DIMENSION", "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END",
  "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN",
  "YY_KIND", "YY_SAVE", "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T",
  "YY_COMPLEX_T", "YY_BOOL_T", "YY_CHARACTER_T", "YY_WRITE", "YY_READ",
  "YY_PRINT", "YY_CALL", "YY_STOP", "YY_PAUSE", "'='", "'+'", "'-'", "'*'",
  "'/'", "';'", "'('", "')'", "','", "'\\n'", "':'", "$accept", "crlf",
  "dummy_function_iden", "variable_desc_elem", "variable_desc",
  "type_selector", "literal", "variable", "slice", "dimen_slice",
  "function_array_body", "function_array", "exp", "_crlf_semicolon",
  "semicolon", "label", "stmt", "output_stmt", "input_stmt",
  "compound_stmt", "jump_stmt", "let_stmt", "dummy_stmt", "suite",
  "_optional_lbrace", "_optional_rbrace", "_optional_comma",
  "_optional_device", "_optional_formatter", "io_info", "write", "print",
  "read", "type_name", "type_spec", "_blockname_or_none", "common_stmt",
  "var_def", "keyvalue", "paramtable_elem", "paramtable", "hidden_do",
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
     345,   346,   347,   348,   349,   350,    61,    43,    45,    42,
      47,    59,    40,    41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   114,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   126,   126,   126,   127,   127,   127,
     128,   129,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   135,   136,   136,   137,
     138,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   142,   142,   143,
     144,   144,   144,   145,   145,   145,   146,   146,   147,   147,
     147,   148,   149,   149,   150,   151,   151,   152,   152,   153,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   156,   156,   157,   157,   158,   159,   160,   160,   161,
     161,   162,   162,   163,   164,   164,   165,   165,   165,   166,
     166,   167,   167,   168,   169,   169
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     0,     4,     4,     4,
       4,     4,     1,     1,     1,     2,     3,     0,     3,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     5,
       1,     1,     3,     1,     3,     4,     4,     1,     2,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     2,     1,     0,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     2,     2,     1,     1,     1,     2,     2,     3,
       4,     3,     1,     2,     1,     2,     0,     1,     0,     1,
       1,     0,     1,     1,     1,     1,     1,     5,     2,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     3,     1,     3,     2,     0,     3,
       4,     3,     2,     1,     3,     3,     1,     1,     1,     3,
       0,     9,     3,     3,     1,     2,     0,     2,     1,     8,
      11,     9,    12,     5,     4,     5,     6,     2,     1,     6,
      11,    13,     7,     2,     1,    10,     6,     1,     2,     4,
       0,     1,     1,    12,     1,     0,     8,     7,     1,     1,
       1,     1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    21,    20,    27,    22,    25,    23,    24,
       4,    68,     4,     4,     0,   175,     5,   175,   128,     0,
       0,     0,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,    66,     0,     0,    62,    63,    37,
      39,     4,     0,    80,     0,    72,    73,    71,    76,    75,
      74,   178,     4,     4,     4,   125,    17,    78,     4,    61,
     144,    40,     0,    84,    85,    86,   179,   180,     0,   184,
       0,     0,    26,    27,   112,   113,   114,   115,   116,   117,
      56,     0,   145,     2,     3,    64,    79,    87,    88,     4,
     174,     4,     4,     0,     0,     4,    30,    63,    31,   136,
      33,   137,   138,   132,     0,    61,     0,     0,     0,     0,
       0,     0,   105,   106,   104,     0,   101,     0,     0,     0,
       0,    38,    49,    48,     0,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    77,    93,    81,
      82,    83,     0,     0,     0,     0,    70,     0,     4,     0,
       0,   182,    95,     1,     3,    65,    89,     0,     0,   127,
       0,   129,    91,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   102,
       0,   100,   108,   109,   111,   110,    42,     0,     0,     0,
      57,    58,    52,    59,    60,    50,    51,    53,    54,    55,
      47,     4,    43,    44,    45,    46,     0,   124,     0,    13,
       0,     0,    12,    14,    15,     0,   131,     0,     0,     0,
      96,     4,     0,     0,     4,   126,    32,    33,   134,    40,
      34,    28,   139,     0,     0,   118,   119,   120,   121,   122,
     123,     0,     0,     0,    35,    90,    41,    36,     0,     0,
      16,   130,     0,     0,     0,     0,   154,     0,     0,    97,
       0,     0,   175,     0,     0,     0,    19,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,   153,    43,
      44,     0,     0,   158,     4,     0,    98,     0,     4,   175,
       0,    29,   107,     0,   170,    10,    11,     7,     8,     9,
       0,    41,   157,   159,     0,    99,     4,     4,   177,     4,
     175,     0,     0,     4,     0,     4,     0,   148,     4,     0,
       4,     0,   162,   176,     4,     0,     0,     0,   147,     0,
       0,   149,     4,     4,     0,     0,    96,   167,     0,   183,
     141,     0,     0,     0,     4,     0,   151,     4,     0,     0,
     168,     0,   164,     4,   169,     0,     4,     0,     0,     0,
       4,    98,   163,   165,     4,   150,   155,     4,     0,   160,
       4,   173,   156,   152,     4,     0,   161,   166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    36,   224,   155,   182,    37,    38,    98,    99,
      39,    40,    41,    86,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   270,   316,   192,   190,   116,   117,
      52,    53,    54,    81,    56,    94,    57,    58,   101,   102,
     103,    59,    60,    61,    62,   328,    63,   329,   294,    64,
     363,    65,   347,   348,   323,   127,    66,    91,    67,    68,
      69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -306
static const yytype_int16 yypact[] =
{
    1217,   -96,  1406,  -306,  -306,   -85,  -306,  -306,  -306,  -306,
      12,  -306,    12,    12,     3,     7,  -306,     7,   -69,   -26,
     631,   724,   -46,   -44,   -31,   -29,   -19,    26,   -12,   -12,
     -12,    -8,  1406,  1406,  -306,  1406,   101,  -306,    27,  -306,
    -306,  1973,    94,  -306,   932,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,    12,    12,    12,   -27,    52,  -306,    12,  -306,
    -306,  -306,    17,  -306,  -306,  -306,  -306,  -306,  1122,  -306,
    1027,   130,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
      30,    29,  -306,  -306,    13,  -306,  -306,  -306,  -306,    12,
    -306,    13,    13,   -11,   631,    13,  -306,    27,    57,  -306,
      95,  -306,    59,  -306,    78,    91,    14,    14,    14,    14,
      14,    14,  -306,  -306,  -306,    16,    65,   631,   631,   631,
      27,  -306,   191,   191,  1872,  -306,  -306,   148,   753,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  1406,  1406,  1406,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  -306,  -306,  -306,  -306,
    -306,  -306,   153,   753,   -14,   536,  -306,  1406,    11,   132,
    1406,  -306,  -306,  -306,  -306,  -306,  -306,  1636,  1541,  -306,
      83,  -306,  -306,   842,  1406,   441,  1406,   441,  -306,  -306,
      88,    89,    84,    85,    87,    97,   103,   113,  -306,  -306,
     115,  -306,  -306,  -306,  -306,  -306,  -306,   148,    96,   117,
     191,   191,   420,   191,   191,   420,  2150,  2150,  2174,  2162,
      49,  1986,   206,   206,    49,    49,  2048,  -306,   118,  -306,
     121,   123,  -306,  -306,    52,   631,  -306,  1439,  1731,   135,
     131,  1999,   180,   203,    13,  -306,  -306,   895,  2150,  -306,
    -306,  1316,  -306,  1406,   215,  -306,  -306,  -306,  -306,  -306,
    -306,    -2,   140,   753,  -306,  -306,  -306,  -306,   842,    42,
    -306,  -306,  1826,  1406,  1406,  1406,  -306,    53,  1406,  -306,
    1406,  1731,     7,   185,   208,  1406,  2150,  -306,   137,  1406,
     138,   139,   777,   141,   143,   144,  -306,  1731,  -306,  1300,
    1339,  1924,   212,  -306,    13,  1936,  2097,    53,    13,     7,
     179,  2150,  -306,  1948,   193,  -306,  -306,  -306,  -306,  -306,
     174,  2232,  -306,  -306,  1406,  -306,    13,    13,  -306,    13,
       7,  1406,   149,    13,   221,    13,  1406,  -306,    13,    19,
    1685,   209,  -306,  -306,    13,  2109,   148,  1731,  -306,  1731,
    2121,  -306,    13,    13,  1406,  1731,   131,   209,     4,  -306,
    -306,   152,   226,    -4,    13,  1731,  -306,  1999,    53,   842,
    -306,   213,  -306,    13,  -306,   101,    13,  1731,    -4,  1731,
      13,   156,  -306,  -306,    13,  -306,   229,    13,    53,  -306,
      13,  -306,  -306,  -306,    13,  1731,  -306,  -306
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -306,    80,  -306,  -306,    37,   104,  -306,    -1,  -306,  -170,
     234,  -306,     5,    -7,  -306,  -306,  -223,  -306,  -306,  -306,
    -306,  -306,  -306,   -42,   -80,  -104,  -306,  -306,    21,    56,
    -306,  -306,  -306,     0,  -306,  -306,  -306,  -306,  -306,  -306,
     205,   253,  -306,   102,  -306,  -305,  -306,   -99,  -284,  -306,
    -306,  -306,  -306,   -68,  -306,   -87,  -306,   -16,  -306,  -306,
     -58,  -306,  -306
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
      55,    92,   148,   236,   266,    87,    88,    80,   112,    72,
     161,    73,   113,   317,    73,    83,    83,    83,   112,    97,
      97,    82,   113,    89,   343,   100,   100,   324,   162,    90,
     120,    93,   327,    73,   146,   361,   188,   122,   123,   288,
     124,   135,   136,    95,    55,   149,   150,   151,   366,   157,
     324,   156,   362,   342,   158,   327,   106,   219,   107,   220,
     135,   136,   221,   377,   159,   139,   222,   160,    55,   223,
      55,   108,   152,   109,   370,   153,    74,    75,    76,    77,
      78,    79,   166,   110,   292,   118,   119,   114,   281,   169,
     115,   293,   170,    97,   384,   180,   181,   114,   147,   100,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     234,   139,   164,    84,   164,   189,    97,    97,    97,   283,
     284,   285,   100,   100,   100,   233,   198,    97,   111,   128,
     163,   153,   145,   100,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   145,    97,   178,    97,   125,   154,   229,   100,   126,
     100,   173,   227,   177,   165,   231,   179,    55,    55,   191,
      73,   167,   168,   217,    97,   172,    97,   230,   237,   238,
     100,   241,   100,   235,   243,   244,   267,   245,   246,   371,
     247,   174,   141,   142,   143,   144,   252,   145,   253,   175,
     248,   176,   135,   136,   255,   324,   249,   139,   325,   326,
     327,   183,   184,   185,   186,   187,   250,   135,   136,   251,
     254,   257,   139,   258,    97,   259,   104,    55,    55,   297,
     100,   268,   272,   269,   273,   277,   279,   299,   228,   300,
     302,   304,   305,   320,   307,   310,   308,   309,   276,   312,
     322,   336,    97,   338,   346,   364,   298,   365,   100,   315,
     372,   260,    55,   282,   326,   121,   359,   380,   289,   290,
     291,    55,   278,   295,   105,   296,   239,   382,   374,   360,
     301,     0,     0,   319,   303,     0,     0,    55,   141,   142,
     143,   144,     0,   145,     0,   352,     0,   353,     0,   171,
       0,     0,     0,   358,   334,   143,   144,     0,   145,     0,
       0,   271,     0,   368,   274,     0,     0,     0,     0,   330,
       0,     0,   193,   194,   195,   376,   335,   378,     0,     0,
       0,   340,     0,   199,     0,   351,     0,    55,     0,    55,
       0,     0,   287,   387,     0,    55,     0,     0,     0,   357,
       0,     0,     0,     0,     0,    55,     0,     0,   218,     0,
     226,     0,     0,     0,   237,     0,     0,    55,     0,    55,
       0,     0,     0,     0,   313,     0,     0,     0,   318,     0,
     240,     0,   242,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   332,     0,   333,
       0,     0,     0,   337,     0,   339,     0,     0,   341,     0,
     345,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,   355,   356,     0,   129,   130,     0,   132,   133,
     261,   135,   136,     0,   367,     0,   139,   369,     0,     0,
       0,  -140,     1,   373,     0,  -140,   375,     0,     0,     0,
     379,     0,     0,     0,   381,     0,     2,   383,   280,     0,
     385,     3,     4,    73,   386,     6,     0,     7,     8,     9,
    -140,  -140,  -140,  -140,     0,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,     0,     0,     0,     0,  -140,     0,  -140,  -140,
    -140,  -140,     0,  -140,     0,  -140,     0,  -140,     0,  -140,
       0,     0,     0,     0,     0,  -140,     0,  -140,     0,  -140,
       0,     0,     0,     0,  -140,    21,  -140,   141,   142,   143,
     144,     0,   145,     0,     0,    74,    75,    76,    77,    78,
      79,  -140,  -140,  -140,    31,     0,  -140,     1,    32,    33,
    -140,     0,  -140,    35,  -140,  -140,     0,    96,     0,     0,
       0,     2,     0,   225,     0,     0,     3,     4,    73,     0,
       6,     0,     7,     8,     9,  -140,  -140,  -140,  -140,     0,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,     0,     0,     0,
       0,  -140,     0,  -140,  -140,  -140,  -140,     0,  -140,     0,
    -140,     0,  -140,     0,  -140,     0,     0,     0,     0,     0,
    -140,     0,  -140,     0,  -140,     0,     0,     0,     0,  -140,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,  -140,  -140,  -140,    31,
       0,  -140,     1,    32,    33,  -140,     0,  -140,    35,     0,
       0,     0,    96,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,    73,     0,     6,     0,     7,     8,     9,
    -140,  -140,  -140,  -140,     0,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,     0,     0,     0,     0,  -140,     0,  -140,  -140,
    -140,  -140,     0,  -140,     0,  -140,     0,  -140,     0,  -140,
       0,     0,     0,     0,     0,  -140,     0,  -140,     0,  -140,
       0,     0,     0,     0,  -140,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,  -140,  -140,  -140,    31,     1,     0,     0,    32,    33,
       0,     0,  -140,    35,     0,     0,     0,    96,     0,     2,
       0,     0,     0,     0,     3,     4,    73,     0,     6,     0,
       7,     8,     9,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     3,     4,    73,     0,     6,     0,     7,
       8,     9,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,   139,     0,     0,     0,     0,    21,  -140,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    31,     0,     0,
       0,    32,    33,     0,     0,     0,    35,    21,     0,     0,
      96,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     1,     0,     0,    31,     0,     0,     0,
      32,    33,     0,     0,     0,    35,  -140,     2,     0,    96,
       0,     0,     3,     4,    73,     0,     6,     0,     7,     8,
       9,     0,     0,     0,   141,   142,   143,   144,     0,   145,
     306,   175,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,   139,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,   -92,     1,     0,    31,   -67,     0,     0,    32,
      33,     0,     0,     0,    35,     0,     0,     2,    96,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,   -92,   -92,     0,   -92,   -92,   -92,   -92,
     -92,    12,    13,     0,     0,     0,     0,   -92,     0,   -92,
     -92,    14,   -92,     0,   -92,     0,   -92,     0,   -92,     0,
     -92,     0,   141,   142,   143,   144,    17,   145,    18,   175,
      19,   176,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,   -94,     1,    32,
      33,   -67,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,   -94,   -94,
       0,   -94,   -94,   -94,   -94,   -94,    12,    13,     0,     0,
       0,     0,   -94,     0,   -94,   -94,    14,   -94,     0,   -94,
       0,   -94,     0,   -94,     0,   -94,     0,     0,     0,     0,
       0,    17,     0,    18,     0,    19,     0,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,  -181,     1,    32,    33,   -67,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,  -181,  -146,     0,     0,     0,     0,  -146,
       0,    12,    13,     0,     0,     0,     0,     0,     0,  -146,
       0,    14,  -146,     0,    15,     0,    -6,     0,    16,     0,
      -6,     0,     0,     0,     0,     0,    17,     0,    18,     0,
      19,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,  -185,     1,    32,
      33,   -67,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,     0,  -146,
       0,     0,     0,     0,  -146,     0,    12,    13,     0,     0,
       0,     0,     0,     0,  -146,     0,    14,  -146,     0,    15,
       0,    -6,     0,    16,     0,    -6,     0,     0,     0,     0,
       0,    17,     0,    18,     0,    19,     0,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
     -49,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   135,   136,     0,    32,    33,   139,     0,    34,    35,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   -49,   139,     0,   -49,   -49,   -49,     0,   -49,   -48,
       0,     0,     0,     0,     0,   -49,     0,     0,   -49,     0,
     135,   136,   -49,     0,   -49,   139,   -49,     0,   -49,     0,
       0,     0,     0,     0,   -49,     0,     0,     0,     0,     0,
     -48,     0,     0,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,     0,     0,   -48,     0,     0,
       0,   -48,     0,   -48,     0,   -48,   -49,   -48,     0,   143,
     144,     0,   145,   -48,     0,     0,     0,     1,     0,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   145,     0,
       0,     2,   275,     0,     0,     0,     3,     4,    73,     0,
       6,     0,     7,     8,     9,   -48,     0,     0,   143,   144,
       1,   145,     0,   -67,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     2,   139,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
       0,  -146,   262,     0,     0,     0,  -146,     0,    12,    13,
      21,     0,     0,     0,     0,     0,  -146,     0,    14,  -146,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    31,
       0,     0,     0,    32,    33,    18,     0,    19,    35,     0,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,   263,   264,   143,   144,
      34,   265,     1,     0,     0,   -67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,     0,  -146,     0,     0,     0,     0,  -146,     0,
      12,    13,     0,     0,     0,     0,     0,     0,  -146,     0,
      14,  -146,     0,    15,     0,    -6,     0,    16,     0,    -6,
       0,     0,     0,     0,     0,    17,     0,    18,     0,    19,
       0,     0,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,     1,    32,    33,
     -67,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,   232,  -146,     0,
       0,     0,     0,  -146,     0,    12,    13,     0,     0,     0,
       0,     0,     0,  -146,     0,    14,  -146,     0,     0,    83,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      17,   139,    18,     0,    19,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     1,    32,    33,   -67,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,     0,  -146,     0,     0,     0,     0,  -146,     0,
      12,    13,     0,     0,     0,     0,     0,     0,  -146,     0,
      14,  -146,   141,   142,   143,   144,   164,   145,     0,   344,
       0,     0,     0,     0,     0,    17,     0,    18,     0,    19,
       0,     0,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,     1,    32,    33,
      83,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,     0,    -4,     0,
       0,     0,     0,    -4,     0,    12,    13,     0,     0,     0,
       0,     0,     0,    -4,     0,    14,    -4,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,   139,     0,
      -4,     0,    18,     0,    19,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     0,    32,    33,     0,     0,   286,    35,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
     139,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,   139,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,   139,     0,     0,     0,     0,   141,
     142,   143,   144,     0,   145,   196,   197,    83,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,   139,
      83,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,   139,    83,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,   139,     0,     0,     0,     0,
       0,   141,   142,   143,   144,     0,   145,   311,   197,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   145,     0,
     314,     0,     0,     0,     0,   141,   142,   143,   144,     0,
     145,     0,   321,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,   139,     0,     0,     0,     0,   140,
     141,   142,   143,   144,    84,   145,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,    84,   145,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     164,   145,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,   139,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,   139,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,   139,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,     0,
     145,   256,     0,     0,   354,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   139,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,   139,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
     139,     0,     0,     0,   141,   142,   143,   144,     0,   145,
     315,     0,     0,     0,     0,     0,   141,   142,   143,   144,
       0,   145,   350,     0,     0,     0,     0,     0,   141,   142,
     143,   144,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,   -42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,     0,   145,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   -42,   145,     0,   -42,   -42,   -42,     0,
     -42,   141,   142,   143,   144,     0,   145,   -42,     0,     0,
     -42,     0,     0,     0,   -42,     0,   -42,     0,   -42,     0,
     -42,     0,     0,     0,     0,     0,   -42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -42
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-306)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    17,    44,   173,   227,    12,    13,     2,    20,   105,
      68,    22,    24,   297,    22,     4,     4,     4,    20,    20,
      21,   106,    24,    20,   329,    20,    21,    31,    70,    22,
      31,   100,    36,    22,    41,    31,    20,    32,    33,   262,
      35,    11,    12,    69,    44,    52,    53,    54,   353,    32,
      31,    58,    48,    34,    37,    36,   102,    71,   102,    73,
      11,    12,    76,   368,    47,    16,    80,    50,    68,    83,
      70,   102,    99,   102,   358,   102,    84,    85,    86,    87,
      88,    89,    89,   102,    31,    29,    30,    99,   258,   100,
     102,    38,    93,    94,   378,    81,    82,    99,     4,    94,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     168,    16,   101,   101,   101,    99,   117,   118,   119,    77,
      78,    79,   117,   118,   119,   167,   127,   128,   102,   102,
       0,   102,   102,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   102,   153,    75,   155,    54,   104,   158,   153,    58,
     155,   104,   157,   104,    84,   160,    75,   167,   168,   104,
      22,    91,    92,    20,   175,    95,   177,    45,   173,   174,
     175,   176,   177,   100,    96,    96,   228,   103,   103,   359,
     103,    96,    97,    98,    99,   100,   197,   102,   102,   104,
     103,   106,    11,    12,   211,    31,   103,    16,    34,    35,
      36,   107,   108,   109,   110,   111,   103,    11,    12,   104,
     103,   103,    16,   102,   225,   102,    21,   227,   228,   271,
     225,    96,    52,   102,    31,    20,    96,    52,   158,    31,
     103,   103,   103,    64,   103,   287,   103,   103,   243,    37,
      57,   102,   253,    32,    45,   103,   272,    31,   253,   103,
      47,   224,   262,   258,    35,    31,   346,   371,   263,   264,
     265,   271,   251,   268,    21,   270,   174,   376,   365,   347,
     275,    -1,    -1,   299,   279,    -1,    -1,   287,    97,    98,
      99,   100,    -1,   102,    -1,   337,    -1,   339,    -1,    94,
      -1,    -1,    -1,   345,   320,    99,   100,    -1,   102,    -1,
      -1,   231,    -1,   355,   234,    -1,    -1,    -1,    -1,   314,
      -1,    -1,   117,   118,   119,   367,   321,   369,    -1,    -1,
      -1,   326,    -1,   128,    -1,   336,    -1,   337,    -1,   339,
      -1,    -1,   262,   385,    -1,   345,    -1,    -1,    -1,   344,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,   153,    -1,
     155,    -1,    -1,    -1,   359,    -1,    -1,   367,    -1,   369,
      -1,    -1,    -1,    -1,   294,    -1,    -1,    -1,   298,    -1,
     175,    -1,   177,    -1,    -1,   385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   316,   317,    -1,   319,
      -1,    -1,    -1,   323,    -1,   325,    -1,    -1,   328,    -1,
     330,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   342,   343,    -1,     5,     6,    -1,     8,     9,
     225,    11,    12,    -1,   354,    -1,    16,   357,    -1,    -1,
      -1,     0,     1,   363,    -1,     4,   366,    -1,    -1,    -1,
     370,    -1,    -1,    -1,   374,    -1,    15,   377,   253,    -1,
     380,    20,    21,    22,   384,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    74,    75,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,     0,     1,    97,    98,
       4,    -1,   101,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,    15,    -1,    17,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    49,    50,    -1,    52,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,     0,     1,    97,    98,     4,    -1,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     1,    -1,    -1,    97,    98,
      -1,    -1,   101,   102,    -1,    -1,    -1,   106,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,    74,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,     1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,    15,    -1,   106,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,     0,     1,    -1,    93,     4,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,    -1,    -1,    15,   106,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    97,    98,    99,   100,    64,   102,    66,   104,
      68,   106,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,     0,     1,    97,
      98,     4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    -1,    52,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,     0,     1,    97,    98,     4,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,     0,     1,    97,
      98,     4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,    52,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    11,    12,    -1,    97,    98,    16,    -1,   101,   102,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    31,    16,    -1,    34,    35,    36,    -1,    38,     0,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    -1,
      11,    12,    52,    -1,    54,    16,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    -1,    -1,
      -1,    52,    -1,    54,    -1,    56,    96,    58,    -1,    99,
     100,    -1,   102,    64,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,    15,   106,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    96,    -1,    -1,    99,   100,
       1,   102,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,    40,
      74,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    98,    66,    -1,    68,   102,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,     1,    97,    98,
       4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      64,    16,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,     1,    97,    98,     4,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    97,    98,    99,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,     1,    97,    98,
       4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    98,    -1,    -1,   101,   102,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    -1,   102,   103,   104,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,   103,   104,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
     102,    -1,   104,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
     102,   103,    -1,    -1,    33,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
      -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    31,   102,    -1,    34,    35,    36,    -1,
      38,    97,    98,    99,   100,    -1,   102,    45,    -1,    -1,
      48,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    30,    39,    40,    49,    52,    56,    64,    66,    68,
      73,    74,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    97,    98,   101,   102,   109,   113,   114,   117,
     118,   119,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   137,   138,   139,   140,   141,   143,   144,   148,
     149,   150,   151,   153,   156,   158,   163,   165,   166,   167,
     168,   169,   105,    22,    84,    85,    86,    87,    88,    89,
     119,   140,   106,     4,   101,   108,   120,   120,   120,    20,
      22,   164,   164,   100,   142,    69,   106,   114,   115,   116,
     119,   145,   146,   147,   147,   148,   102,   102,   102,   102,
     102,   102,    20,    24,    99,   102,   135,   136,   136,   136,
     114,   117,   119,   119,   119,    54,    58,   162,   102,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    16,
      96,    97,    98,    99,   100,   102,   120,     4,   130,   120,
     120,   120,    99,   102,   104,   111,   120,    32,    37,    47,
      50,   167,   130,     0,   101,   108,   120,   108,   108,   100,
     114,   147,   108,   104,    96,   104,   106,   104,    75,    75,
      81,    82,   112,   112,   112,   112,   112,   112,    20,    99,
     134,   104,   133,   147,   147,   147,   103,   104,   114,   147,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,    20,   147,    71,
      73,    76,    80,    83,   110,    17,   147,   119,   108,   114,
      45,   119,    31,   130,   167,   100,   116,   119,   119,   150,
     147,   119,   147,    96,    96,   103,   103,   103,   103,   103,
     103,   104,   114,   102,   103,   120,   103,   103,   102,   102,
     111,   147,    33,    97,    98,   102,   123,   130,    96,   102,
     131,   108,    52,    31,   108,   106,   119,    20,   135,    96,
     147,   116,   119,    77,    78,    79,   101,   108,   123,   119,
     119,   119,    31,    38,   155,   119,   119,   130,   164,    52,
      31,   119,   103,   119,   103,   103,   103,   103,   103,   103,
     130,   103,    37,   108,   104,   103,   132,   155,   108,   164,
      64,   104,    57,   161,    31,    34,    35,    36,   152,   154,
     119,   108,   108,   108,   164,   119,   102,   108,    32,   108,
     119,   108,    34,   152,   104,   108,    45,   159,   160,   108,
     103,   114,   130,   130,    33,   108,   108,   119,   130,   131,
     160,    31,    48,   157,   103,    31,   152,   108,   130,   108,
     155,   116,    47,   108,   162,   108,   130,   152,   130,   108,
     132,   108,   154,   108,   155,   108,   108,   130
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
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 91 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 99 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
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
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				ParseNode & dimen_slice = (yyvsp[(3) - (4)]);
				ParseNode attr = gen_variabledesc_from_dimenslice(dimen_slice);
				newnode.addchild(attr); // def slice
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, attr, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 119 "for90.y"
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

  case 12:
/* Line 1792 of yacc.c  */
#line 137 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 144 "for90.y"
    {
				/* const value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 152 "for90.y"
    {
				/* static value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // const
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 161 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 166 "for90.y"
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

  case 17:
/* Line 1792 of yacc.c  */
#line 179 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 193 "for90.y"
    {
				int kind;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 204 "for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 218 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 223 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 227 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 232 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 236 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 240 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 249 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 256 "for90.y"
    {
				/* arr[from : to] */
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				(yyval) = gen_slice(exp1, exp2);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 265 "for90.y"
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

  case 30:
/* Line 1792 of yacc.c  */
#line 275 "for90.y"
    {
				ParseNode & lb = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				ParseNode & ub = gen_promote(TokenMeta::NT_VARIABLEINITIALDUMMY, gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" }));
				/* target code of slice depend on context */
				(yyval) = gen_slice(lb, ub);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 284 "for90.y"
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

  case 32:
/* Line 1792 of yacc.c  */
#line 294 "for90.y"
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

  case 33:
/* Line 1792 of yacc.c  */
#line 304 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 311 "for90.y"
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

  case 35:
/* Line 1792 of yacc.c  */
#line 331 "for90.y"
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
#line 341 "for90.y"
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

  case 37:
/* Line 1792 of yacc.c  */
#line 352 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 356 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 361 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 368 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 376 "for90.y"
    {
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s(%s)");
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 384 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				(yyval) = gen_exp(exp, op, "( %s )");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 392 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 400 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 408 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 416 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 424 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 432 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 439 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 446 "for90.y"
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
#line 454 "for90.y"
    {
				// xor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 463 "for90.y"
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
#line 471 "for90.y"
    {
				// nor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "!(%s == %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:
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

  case 55:
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

  case 56:
/* Line 1792 of yacc.c  */
#line 496 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 57:
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

  case 58:
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

  case 59:
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

  case 60:
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

  case 61:
/* Line 1792 of yacc.c  */
#line 535 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 541 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 546 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 556 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 560 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 565 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 571 "for90.y"
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

  case 70:
/* Line 1792 of yacc.c  */
#line 581 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 587 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 591 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 595 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 599 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 603 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 608 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 613 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 618 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 623 "for90.y"
    {
				(yyval) = gen_format((yyvsp[(1) - (2)]));
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 628 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 647 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 653 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 662 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 669 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 674 "for90.y"
    {

				ParseNode & stmt = (yyvsp[(1) - (2)]); // TokenMeta::NT_LABEL
				ParseNode & suite = (yyvsp[(2) - (2)]);
				if (stmt.fs.CurrentTerm.token == TokenMeta::NT_LABEL)
				{
					ParseNode & label = stmt.get(0); // TokenMeta::Label
					if (suite.child.size() > 0 && suite.get(0).child.size() > 0 && suite.get(0).get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
					{
						log_format_index(label.fs.CurrentTerm.what, suite.get(0));
						(yyval) = suite;
					}
					else {
						(yyval) = gen_flattern(stmt, suite, "%s\n%s", TokenMeta::NT_SUITE);
					}
				}else {
					(yyval) = gen_flattern(stmt, suite, "%s\n%s", TokenMeta::NT_SUITE);
				}
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 695 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 700 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 714 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 718 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 722 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 726 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 731 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 738 "for90.y"
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

  case 108:
/* Line 1792 of yacc.c  */
#line 749 "for90.y"
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

  case 109:
/* Line 1792 of yacc.c  */
#line 763 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 780 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 788 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 793 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 798 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 803 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 808 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 813 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 819 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 825 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 830 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 835 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 840 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 845 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str(), "%d", &len);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 853 "for90.y"
    {
				// $$ = gen_type($1, $3);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 858 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 864 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 869 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 875 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 882 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 890 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 900 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (3)]);
				ParseNode & variable_desc = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 910 "for90.y"
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

  case 133:
/* Line 1792 of yacc.c  */
#line 921 "for90.y"
    { 
				// useless reduction
				/* paramtable is used in function decl */
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 926 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 935 "for90.y"
    {
				// array initial values 
				// USELESS
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 944 "for90.y"
    {
				// from rule ` dimen_slice : exp ',' paramtable `
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 948 "for90.y"
    {
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 952 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 959 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 967 "for90.y"
    {
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE, "" });
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 976 "for90.y"
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

  case 142:
/* Line 1792 of yacc.c  */
#line 992 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 999 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				// rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule because \
				// these two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict 
				// so either that `variable '(' dimen_slice ')'` is an `exp`
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1010 "for90.y"
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

  case 149:
/* Line 1792 of yacc.c  */
#line 1033 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (8)]);
				ParseNode & suite_true = (yyvsp[(6) - (8)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1040 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (11)]);
				ParseNode & suite_true = (yyvsp[(6) - (11)]); 
				ParseNode & suite_else = (yyvsp[(9) - (11)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1048 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (9)]);
				ParseNode & suite_true = (yyvsp[(6) - (9)]);
				ParseNode & elseif = (yyvsp[(7) - (9)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1056 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (12)]);
				ParseNode & suite_true = (yyvsp[(6) - (12)]);
				ParseNode & elseif = (yyvsp[(7) - (12)]);
				ParseNode & suite_else = (yyvsp[(10) - (12)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1065 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (5)]);
				ParseNode & stmt_true = (yyvsp[(5) - (5)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1072 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1080 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1088 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1100 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1106 "for90.y"
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

  case 161:
/* Line 1792 of yacc.c  */
#line 1116 "for90.y"
    {
				ParseNode & loop_variable = (yyvsp[(3) - (13)]);
				ParseNode & exp1 = (yyvsp[(5) - (13)]);
				ParseNode & exp2 = (yyvsp[(7) - (13)]);
				ParseNode & exp3 = (yyvsp[(9) - (13)]);
				ParseNode & suite = (yyvsp[(11) - (13)]);
				(yyval) = gen_do_range(loop_variable, exp1, exp2, exp3, suite);
				update_pos((yyval), (yyvsp[(1) - (13)]), (yyvsp[(12) - (13)]));
			}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1126 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (7)]);
				ParseNode & suite = (yyvsp[(5) - (7)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1137 "for90.y"
    {
				ParseNode & select = (yyvsp[(2) - (10)]);
				ParseNode & exp = (yyvsp[(5) - (10)]);
				ParseNode & case_stmt = (yyvsp[(8) - (10)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1145 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1153 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1161 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem, false /* add to the front of the vector */); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1171 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1176 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1186 "for90.y"
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

  case 176:
/* Line 1792 of yacc.c  */
#line 1202 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1208 "for90.y"
    {
				(yyval) = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1218 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1226 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1231 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1237 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (1)])); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1246 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (2)])); // wrapper
				newnode.addchild((yyvsp[(2) - (2)])); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (2)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (2)]).fs.CurrentTerm.what.c_str());
				newnode = flattern_bin(newnode);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1258 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1264 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 3903 "for90.tab.cpp"
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
#line 1270 "for90.y"

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
