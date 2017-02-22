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
     YY_WHILE = 297,
     YY_ENDWHILE = 298,
     YY_WHERE = 299,
     YY_ENDWHERE = 300,
     YY_CASE = 301,
     YY_ENDCASE = 302,
     YY_SELECT = 303,
     YY_ENDSELECT = 304,
     YY_GOTO = 305,
     YY_DOWHILE = 306,
     YY_DEFAULT = 307,
     YY_PROGRAM = 308,
     YY_ENDPROGRAM = 309,
     YY_FUNCTION = 310,
     YY_ENDFUNCTION = 311,
     YY_RECURSIVE = 312,
     YY_RESULT = 313,
     YY_SUBROUTINE = 314,
     YY_ENDSUBROUTINE = 315,
     YY_MODULE = 316,
     YY_ENDMODULE = 317,
     YY_BLOCK = 318,
     YY_ENDBLOCK = 319,
     YY_INTERFACE = 320,
     YY_ENDINTERFACE = 321,
     YY_COMMON = 322,
     YY_DATA = 323,
     YY_IMPLICIT = 324,
     YY_NONE = 325,
     YY_USE = 326,
     YY_PARAMETER = 327,
     YY_ENTRY = 328,
     YY_DIMENSION = 329,
     YY_ARRAYINITIAL_START = 330,
     YY_ARRAYINITIAL_END = 331,
     YY_INTENT = 332,
     YY_IN = 333,
     YY_OUT = 334,
     YY_INOUT = 335,
     YY_OPTIONAL = 336,
     YY_LEN = 337,
     YY_KIND = 338,
     YY_SAVE = 339,
     YY_INTEGER_T = 340,
     YY_FLOAT_T = 341,
     YY_STRING_T = 342,
     YY_COMPLEX_T = 343,
     YY_BOOL_T = 344,
     YY_CHARACTER_T = 345,
     YY_WRITE = 346,
     YY_READ = 347,
     YY_PRINT = 348,
     YY_CALL = 349,
     YY_STOP = 350,
     YY_PAUSE = 351
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
#line 257 "for90.tab.cpp"

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
#define YYFINAL  167
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNRULES -- Number of states.  */
#define YYNSTATES  393

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     106,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     102,   103,    99,    97,   104,    98,     2,   100,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   107,   101,
       2,   105,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    11,    16,    21,
      26,    31,    36,    38,    40,    42,    45,    49,    50,    54,
      58,    60,    62,    64,    66,    68,    70,    73,    75,    79,
      85,    87,    91,    93,    97,    99,   103,   107,   111,   116,
     121,   123,   126,   128,   130,   135,   139,   143,   147,   151,
     155,   159,   162,   165,   169,   173,   177,   181,   185,   189,
     192,   196,   200,   204,   208,   210,   212,   214,   216,   219,
     221,   222,   224,   227,   230,   232,   234,   236,   238,   240,
     242,   245,   247,   250,   252,   255,   258,   261,   264,   266,
     268,   270,   273,   276,   280,   285,   289,   291,   294,   296,
     299,   300,   302,   303,   305,   307,   308,   310,   312,   314,
     316,   318,   324,   327,   331,   335,   339,   341,   343,   345,
     347,   349,   351,   356,   361,   366,   371,   376,   381,   385,
     387,   391,   394,   395,   399,   404,   408,   411,   413,   417,
     421,   425,   426,   428,   430,   432,   442,   446,   450,   452,
     455,   456,   459,   461,   469,   478,   490,   500,   513,   519,
     526,   529,   531,   538,   550,   564,   572,   575,   577,   588,
     595,   597,   600,   605,   606,   608,   610,   623,   625,   626,
     635,   643,   645,   647,   649,   651,   654,   664,   666
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     171,     0,    -1,     4,    -1,   101,    -1,    -1,    57,    -1,
      -1,    77,   102,    78,   103,    -1,    77,   102,    79,   103,
      -1,    77,   102,    80,   103,    -1,    74,   102,   119,   103,
      -1,    74,   102,   122,   103,    -1,    81,    -1,    72,    -1,
      84,    -1,   104,   111,    -1,   104,   111,   112,    -1,    -1,
      83,   105,    20,    -1,    82,   105,   122,    -1,    21,    -1,
      20,    -1,    24,    -1,    27,    -1,    28,    -1,    26,    -1,
       1,   106,    -1,    22,    -1,   122,   107,   122,    -1,   122,
     107,   122,   107,   122,    -1,   107,    -1,   122,   105,   122,
      -1,   122,    -1,   118,   104,   122,    -1,   116,    -1,   119,
     104,   116,    -1,   119,   104,   122,    -1,   118,   104,   116,
      -1,   115,   102,   149,   103,    -1,   143,   102,   149,   103,
      -1,   120,    -1,    94,   120,    -1,   121,    -1,   152,    -1,
     122,   102,   122,   103,    -1,   102,   122,   103,    -1,   122,
      97,   122,    -1,   122,    98,   122,    -1,   122,    99,   122,
      -1,   122,   100,   122,    -1,   122,    16,   122,    -1,    98,
     122,    -1,    97,   122,    -1,   122,    10,   122,    -1,   122,
      11,   122,    -1,   122,     7,   122,    -1,   122,    12,   122,
      -1,   122,    13,   122,    -1,   122,    14,   122,    -1,    15,
     122,    -1,   122,     5,   122,    -1,   122,     6,   122,    -1,
     122,     8,   122,    -1,   122,     9,   122,    -1,   150,    -1,
     114,    -1,   115,    -1,   109,    -1,   101,   109,    -1,   101,
      -1,    -1,    31,    -1,   122,   123,    -1,   147,   123,    -1,
     129,    -1,   127,    -1,   128,    -1,   132,    -1,   131,    -1,
     130,    -1,   124,     4,    -1,   146,    -1,    29,   123,    -1,
     125,    -1,    30,   109,    -1,   140,   123,    -1,   141,   123,
      -1,   142,   123,    -1,   155,    -1,   158,    -1,   160,    -1,
      40,   123,    -1,    41,   123,    -1,    50,    20,   123,    -1,
     122,   105,   122,   123,    -1,    69,    70,   109,    -1,   126,
      -1,   126,   133,    -1,   170,    -1,   170,   133,    -1,    -1,
     102,    -1,    -1,   103,    -1,   104,    -1,    -1,    99,    -1,
      20,    -1,    99,    -1,    20,    -1,    24,    -1,   102,   137,
     104,   138,   103,    -1,   138,   136,    -1,    91,   139,   149,
      -1,    93,   139,   149,    -1,    92,   139,   149,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    85,   102,   113,   103,    -1,    86,   102,   113,   103,
      -1,    87,   102,   113,   103,    -1,    88,   102,   113,   103,
      -1,    89,   102,   113,   103,    -1,    90,   102,   113,   103,
      -1,   143,    99,    20,    -1,   143,    -1,   100,   115,   100,
      -1,   100,   100,    -1,    -1,    67,   145,   149,    -1,   144,
     112,    17,   149,    -1,   144,   112,   149,    -1,    74,   149,
      -1,   117,    -1,   148,   104,   117,    -1,   148,   104,   122,
      -1,   118,   104,   117,    -1,    -1,   148,    -1,   118,    -1,
     119,    -1,   102,   118,   104,   115,   105,   122,   104,   122,
     103,    -1,    75,   149,    76,    -1,    75,   150,    76,    -1,
     151,    -1,    22,   107,    -1,    -1,    32,    33,    -1,    37,
      -1,   153,    33,   102,   122,   103,   126,   109,    -1,   153,
      33,   122,    34,     4,   133,   154,   109,    -1,   153,    33,
     122,    34,     4,   133,    35,   109,   133,   154,   109,    -1,
     153,    33,   122,    34,     4,   133,   156,   154,   109,    -1,
     153,    33,   122,    34,     4,   133,   156,    35,   109,   133,
     154,   109,    -1,    36,   122,    34,   109,   133,    -1,    36,
     122,    34,   109,   133,   156,    -1,    32,    38,    -1,    39,
      -1,   153,    38,     4,   133,   157,   109,    -1,   153,    38,
     115,   105,   122,   104,   122,     4,   133,   157,   109,    -1,
     153,    38,   115,   105,   122,   104,   122,   104,   122,     4,
     133,   157,   109,    -1,   153,    51,   122,     4,   133,   157,
     109,    -1,    32,    48,    -1,    49,    -1,   153,    48,    46,
     134,   122,   135,   109,   162,   159,   109,    -1,    46,   134,
     119,   135,   109,   133,    -1,   161,    -1,   161,   162,    -1,
      58,   102,   115,   103,    -1,    -1,    55,    -1,    59,    -1,
     110,   164,   115,   102,   149,   103,   163,   109,   133,    32,
     164,   109,    -1,    22,    -1,    -1,    53,   166,   109,   133,
      32,    53,   166,   109,    -1,    53,   166,   109,    32,    53,
     166,   109,    -1,   133,    -1,   165,    -1,   167,    -1,   168,
      -1,   168,   169,    -1,    65,   166,   109,   169,   109,    32,
      65,   166,   109,    -1,   169,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    75,    80,    97,    98,   100,   107,   115,
     122,   135,   153,   160,   168,   177,   182,   196,   209,   220,
     234,   239,   243,   249,   253,   257,   264,   266,   280,   289,
     299,   308,   318,   326,   334,   344,   354,   364,   383,   393,
     404,   408,   413,   420,   428,   436,   444,   452,   460,   468,
     476,   484,   491,   498,   506,   515,   523,   532,   540,   548,
     555,   563,   571,   579,   587,   593,   598,   605,   606,   608,
     613,   617,   623,   633,   639,   643,   647,   651,   655,   660,
     666,   672,   677,   682,   687,   695,   696,   698,   700,   701,
     702,   704,   705,   706,   712,   721,   728,   734,   754,   759,
     765,   766,   767,   768,   769,   770,   771,   775,   779,   783,
     788,   795,   806,   820,   828,   837,   845,   850,   855,   860,
     865,   870,   876,   882,   887,   892,   897,   902,   910,   915,
     921,   926,   933,   939,   947,   957,   967,   979,   986,   994,
    1002,  1011,  1018,  1019,  1020,  1022,  1038,  1045,  1053,  1068,
    1069,  1072,  1073,  1076,  1083,  1090,  1098,  1106,  1116,  1124,
    1133,  1134,  1136,  1142,  1152,  1162,  1170,  1171,  1173,  1181,
    1189,  1197,  1207,  1213,  1219,  1220,  1222,  1235,  1236,  1238,
    1244,  1250,  1263,  1267,  1273,  1282,  1294,  1300,  1304
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
  "YY_BREAK", "YY_WHILE", "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE",
  "YY_CASE", "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT", "YY_GOTO",
  "YY_DOWHILE", "YY_DEFAULT", "YY_PROGRAM", "YY_ENDPROGRAM", "YY_FUNCTION",
  "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT", "YY_SUBROUTINE",
  "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE", "YY_BLOCK",
  "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE", "YY_COMMON", "YY_DATA",
  "YY_IMPLICIT", "YY_NONE", "YY_USE", "YY_PARAMETER", "YY_ENTRY",
  "YY_DIMENSION", "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END",
  "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN",
  "YY_KIND", "YY_SAVE", "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T",
  "YY_COMPLEX_T", "YY_BOOL_T", "YY_CHARACTER_T", "YY_WRITE", "YY_READ",
  "YY_PRINT", "YY_CALL", "YY_STOP", "YY_PAUSE", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "','", "'='", "'\\n'", "':'", "$accept", "crlf",
  "dummy_function_iden", "variable_desc_elem", "variable_desc",
  "type_selector", "literal", "variable", "slice", "keyvalue", "argtable",
  "dimen_slice", "function_array_body", "function_array", "exp",
  "_crlf_semicolon", "semicolon", "label", "stmt", "output_stmt",
  "input_stmt", "compound_stmt", "jump_stmt", "let_stmt", "dummy_stmt",
  "suite", "_optional_lbrace", "_optional_rbrace", "_optional_comma",
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
     345,   346,   347,   348,   349,   350,   351,    43,    45,    42,
      47,    59,    40,    41,    44,    61,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   115,   116,   116,
     116,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   128,   129,   129,
     129,   130,   130,   130,   131,   132,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   140,   141,   142,   143,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   145,   146,   147,   147,   147,   148,   148,   148,
     148,   148,   149,   149,   149,   150,   151,   151,   152,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   156,   156,
     157,   157,   158,   158,   158,   158,   159,   159,   160,   161,
     162,   162,   163,   163,   164,   164,   165,   166,   166,   167,
     167,   167,   168,   168,   169,   169,   170,   171,   171
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     0,     4,     4,     4,
       4,     4,     1,     1,     1,     2,     3,     0,     3,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     5,
       1,     3,     1,     3,     1,     3,     3,     3,     4,     4,
       1,     2,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     1,
       0,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     3,     4,     3,     1,     2,     1,     2,
       0,     1,     0,     1,     1,     0,     1,     1,     1,     1,
       1,     5,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     3,     1,
       3,     2,     0,     3,     4,     3,     2,     1,     3,     3,
       3,     0,     1,     1,     1,     9,     3,     3,     1,     2,
       0,     2,     1,     7,     8,    11,     9,    12,     5,     6,
       2,     1,     6,    11,    13,     7,     2,     1,    10,     6,
       1,     2,     4,     0,     1,     1,    12,     1,     0,     8,
       7,     1,     1,     1,     1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    21,    20,    27,    22,    25,    23,    24,
       4,     4,    71,     4,     4,     0,   178,     5,   178,   132,
       0,     0,     0,   116,   117,   118,   119,   120,   121,     0,
       0,     0,     0,     0,     0,    69,     0,     0,    65,    66,
      40,    42,     4,     0,    83,     0,    75,    76,    74,    79,
      78,    77,   181,     4,     4,     4,   129,    17,    81,     4,
      64,   148,    43,     0,    88,    89,    90,   182,   183,     0,
     187,     0,     0,    26,    27,   116,   117,   118,   119,   120,
     121,    59,     0,   149,     2,     3,    67,    82,     3,    84,
      91,    92,     4,   177,     4,     4,     0,     0,     4,    30,
      34,   137,   143,   144,    32,   142,   136,     0,    64,     0,
       0,     0,     0,     0,     0,   109,   110,   108,     0,   105,
       0,     0,     0,     0,    41,    52,    51,     0,    32,   174,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    80,    97,    85,    86,    87,     0,     0,     0,     0,
      73,     0,     0,     0,     0,   185,    99,     1,    68,    93,
       0,     0,   131,     0,   133,    95,     0,     0,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   106,     0,   104,   112,   113,   115,   114,     0,
      45,     0,     0,    60,    61,    55,    62,    63,    53,    54,
      56,    57,    58,    50,    46,    47,    48,    49,     0,     4,
     128,     0,    13,     0,     0,    12,    14,    15,     0,   135,
       0,     0,     0,     0,   100,     0,     0,     0,     4,   130,
      37,   140,    33,    35,    36,    31,    28,   138,   139,     0,
       0,   122,   123,   124,   125,   126,   127,     0,    66,    33,
       0,    38,    44,    94,    39,     0,     0,    16,   134,    32,
       0,     0,     0,   101,     0,     0,   178,     0,     0,     0,
      19,    18,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,   161,     4,     0,   102,     0,     4,
     178,     0,    29,   111,     0,   173,     0,    10,    11,     7,
       8,     9,     4,     0,   160,   162,     0,   103,     4,     4,
     180,     4,   178,     0,     0,     4,    33,   153,     0,     4,
       0,   152,     4,     0,     0,     0,   165,   179,     4,     0,
       0,     0,   151,     0,     0,   154,     4,     4,     0,     0,
     100,   170,     0,   186,   145,     0,     0,     0,     4,     0,
     156,     0,     0,     0,   171,     0,   167,     4,   172,     0,
       4,     0,     0,     4,     0,   102,    32,   166,   168,     4,
     155,   158,     4,   163,     0,     4,   176,   159,   157,     4,
       0,   164,   169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    86,    37,   227,   159,   185,    38,    39,   100,   101,
     102,   103,    40,    41,    42,    87,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   274,   318,   195,   193,
     119,   120,    53,    54,    55,    82,    57,    97,    58,    59,
     105,   106,    60,    61,    62,    63,   332,    64,   333,   295,
      65,   367,    66,   351,   352,   325,   131,    67,    94,    68,
      69,    70,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const yytype_int16 yypact[] =
{
    1056,   -74,  1596,  -312,  -312,   -73,  -312,  -312,  -312,  -312,
      10,    11,  -312,    10,    10,    22,    35,  -312,    35,   -34,
      -8,   472,   566,   -28,   -14,   -12,    26,    65,    70,    -3,
      -3,    -3,   134,  1596,  1596,  -312,  1596,   -15,  -312,    91,
    -312,  -312,  1225,    89,  -312,   771,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,    10,    10,    10,    66,   -36,  -312,    10,
    -312,  -312,  -312,    27,  -312,  -312,  -312,  -312,  -312,   961,
    -312,   866,   131,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,    19,    93,  -312,  -312,    11,  -312,  -312,  -312,  -312,
    -312,  -312,    10,  -312,    11,    11,    -6,   472,    11,  -312,
    -312,  -312,    94,    96,   614,    98,  -312,   120,   125,    34,
      34,    34,    34,    34,    34,  -312,  -312,  -312,    -7,    99,
     472,   472,   472,    91,  -312,    61,    61,   111,  1848,  -312,
    -312,   195,   590,  1596,  1596,  1596,  1596,  1596,  1596,  1596,
    1596,  1596,  1596,  1596,  1596,  1596,  1596,  1596,  1596,  1596,
    -312,  -312,  -312,  -312,  -312,  -312,   198,   590,   164,   377,
    -312,  1686,    29,   179,  1596,  -312,  -312,  -312,  -312,  -312,
    1467,  1372,  -312,   127,  -312,  -312,   680,   680,  1596,  1596,
    1596,  -312,  -312,   123,   126,   136,   139,   140,   141,   143,
     144,  -312,  -312,   133,  -312,  -312,  -312,  -312,  -312,  1596,
    -312,   128,   146,    61,    61,    92,    61,    61,    92,  2063,
    2063,   627,   200,    13,     7,     7,    13,    13,  1860,  1836,
    -312,   147,  -312,   150,   151,  -312,  -312,   -36,   472,  -312,
    1596,  2021,  1562,   155,   153,  1885,   203,   219,    11,  -312,
    -312,  -312,   614,  -312,   735,  2063,  1166,  -312,  1723,  1596,
     241,  -312,  -312,  -312,  -312,  -312,  -312,    23,   -38,  2063,
     590,  -312,  -312,  -312,  -312,   680,   108,  -312,  -312,  1897,
     258,    24,  1596,  -312,  1596,  1562,    35,   210,   232,  1596,
    2063,  -312,   163,  1596,   165,   167,   -23,  1154,   166,   169,
     170,  1270,  1562,   229,  -312,    11,  1735,  1909,    24,    11,
      35,   209,  2063,  -312,  1784,   218,   680,  -312,  -312,  -312,
    -312,  -312,    11,    47,  -312,  -312,  1596,  -312,    11,    11,
    -312,    11,    35,  1596,   176,    11,   735,  -312,   247,    11,
    1596,  -312,    11,    97,  1711,   235,  -312,  -312,    11,  1959,
     195,  1562,  -312,  1562,  2033,  -312,    11,    11,  1562,  1596,
     153,   235,     3,  -312,  -312,   182,   250,    21,    11,  1562,
    -312,    24,  2009,   680,  -312,   239,  -312,    11,  -312,   -15,
      11,  1562,    21,    11,  1562,    20,   735,  -312,  -312,    11,
    -312,   253,    11,  -312,    24,    11,  -312,  -312,  -312,    11,
    1562,  -312,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,    -9,  -312,  -312,    67,    64,  -312,   -26,  -173,  -121,
     -31,  -253,   261,  -312,     5,    -5,  -312,  -312,     4,  -312,
    -312,  -312,  -312,  -312,  -312,   -35,   -54,   -71,  -312,  -312,
      44,   149,  -312,  -312,  -312,     0,  -312,  -312,  -312,  -312,
    -312,    -2,   285,  -312,  -312,  -312,  -311,  -312,   -66,  -270,
    -312,  -312,  -312,  -312,   -33,  -312,   -52,  -312,   -17,  -312,
    -312,   -58,  -312,  -312
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -189
static const yytype_int16 yytable[] =
{
      56,    95,    89,   240,   243,   127,   123,    81,    90,    91,
     152,   165,   286,   191,    84,    84,    74,   115,   139,   140,
     107,   116,   347,   143,   139,   140,   104,   104,   319,   143,
     139,   140,    73,   232,    83,   365,   166,   150,   125,   126,
     129,   128,    92,   115,   130,    56,   370,   116,   153,   154,
     155,    74,   366,   328,   160,   241,   293,    93,   331,   247,
     161,   382,    98,   294,   132,   162,    96,   283,   158,    56,
     173,    56,   139,   140,   109,   163,   168,   143,   164,   328,
     307,   177,   329,   330,   331,   170,   171,   169,   110,   175,
     111,   373,   192,   151,   172,   174,   117,   133,   134,   118,
     136,   137,   104,   139,   140,   201,   146,   147,   143,   148,
     375,    85,    88,   238,   389,   148,   183,   184,   196,   197,
     198,   148,   117,   317,   177,   104,   104,   104,   112,   328,
     202,   167,   346,   240,   331,   237,   233,   104,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   221,    74,   229,   144,   145,
     146,   147,   104,   148,   104,   156,   231,   113,   157,   235,
      56,    56,   114,   258,   186,   187,   188,   189,   190,   121,
     122,   242,   244,   245,   246,   248,   288,   289,   290,   144,
     145,   146,   147,   132,   148,   157,   181,   271,   176,   127,
     177,   182,   180,   194,   259,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   263,   199,   143,    74,   220,    75,
      76,    77,    78,    79,    80,   234,   268,   239,   249,   278,
     260,   250,    56,   104,   285,   269,   222,   257,   223,   251,
     298,   224,   252,   253,   254,   225,   255,   256,   226,   261,
     264,   277,   265,   266,   280,   273,   276,   313,   284,   299,
     272,   281,   292,   300,   301,   104,   303,   314,   305,   309,
     287,   306,   310,   311,   322,    56,   324,   296,   340,   297,
     342,   350,   369,   321,   302,   368,   315,   377,   304,   330,
     320,    56,    56,   124,   267,   312,   363,   144,   145,   146,
     147,   282,   148,   327,   385,   338,   356,   108,   357,   335,
     336,   326,   337,   361,   355,   387,   341,   379,   364,     0,
     343,   334,     0,   345,   372,     0,     0,     0,   339,   353,
       0,     0,   285,     0,     0,   344,   381,   359,   360,   384,
       0,    56,     0,    56,     0,     0,     0,     0,    56,   371,
       0,     0,     0,     0,   362,   392,     0,     0,   378,    56,
       0,   380,     0,     0,   383,     0,     0,     0,   376,     0,
     386,    56,     0,   388,    56,     0,   390,  -141,     1,     0,
     391,  -141,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     2,     0,   228,     0,     0,     3,     4,    74,
       0,     6,     0,     7,     8,     9,  -141,  -141,  -141,  -141,
    -141,     0,  -141,  -141,  -141,  -141,  -141,  -141,  -141,     0,
       0,     0,     0,  -141,     0,  -141,  -141,  -141,  -141,     0,
    -141,     0,  -141,     0,  -141,     0,  -141,     0,     0,     0,
       0,     0,  -141,     0,  -141,     0,  -141,     0,     0,     0,
       0,  -141,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,  -141,  -141,
    -141,    32,  -141,     1,    33,    34,  -141,     0,  -141,    36,
       0,  -141,     0,     0,    99,     0,     0,     2,     0,     0,
       0,     0,     3,     4,    74,     0,     6,     0,     7,     8,
       9,  -141,  -141,  -141,  -141,  -141,     0,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,     0,     0,     0,     0,  -141,     0,
    -141,  -141,  -141,  -141,     0,  -141,     0,  -141,     0,  -141,
       0,  -141,     0,     0,     0,     0,     0,  -141,     0,  -141,
       0,  -141,     0,     0,     0,     0,  -141,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,  -141,  -141,  -141,    32,     1,     0,    33,
      34,     0,     0,  -141,    36,     0,  -141,     0,     0,    99,
       0,     2,     0,     0,     0,     0,     3,     4,    74,     0,
       6,     1,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       3,     4,    74,     0,     6,     0,     7,     8,     9,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,     0,   133,   134,   135,   136,   137,   138,   139,   140,
       0,    22,  -141,   143,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      32,     0,     0,    33,    34,    22,     0,     0,    36,     0,
    -141,     0,     0,    99,     0,    75,    76,    77,    78,    79,
      80,     1,     0,     0,    32,     0,     0,    33,    34,     0,
       0,     0,    36,  -141,  -141,     2,     0,    99,     0,     0,
       3,     4,    74,     0,     6,     0,     7,     8,     9,     0,
       0,   144,   145,   146,   147,     0,   148,     0,     0,   178,
       0,   179,     0,     0,   144,   145,   146,   147,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,   -96,     1,     0,    32,   -70,     0,    33,    34,     0,
       0,     0,    36,     0,     0,     0,     2,    99,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -96,   -96,     0,   -96,   -96,   -96,   -96,
     -96,    13,    14,     0,     0,     0,     0,   -96,     0,   -96,
     -96,    15,   -96,     0,   -96,     0,   -96,     0,   -96,     0,
     -96,     0,   144,   145,   146,   147,    18,   148,    19,     0,
      20,     0,   179,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   -98,     1,    33,    34,
     -70,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,   -98,   -98,
       0,   -98,   -98,   -98,   -98,   -98,    13,    14,     0,     0,
       0,     0,   -98,     0,   -98,   -98,    15,   -98,     0,   -98,
       0,   -98,     0,   -98,     0,   -98,     0,     0,     0,     0,
       0,    18,     0,    19,     0,    20,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,  -184,     1,    33,    34,   -70,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,  -184,  -150,     0,     0,     0,     0,  -150,
       0,    13,    14,     0,     0,     0,     0,     0,     0,  -150,
       0,    15,  -150,     0,    16,     0,    -6,     0,    17,     0,
      -6,     0,     0,     0,     0,     0,    18,     0,    19,     0,
      20,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,  -188,     1,    33,    34,
     -70,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -150,
       0,     0,     0,     0,  -150,     0,    13,    14,     0,     0,
       0,     0,     0,     0,  -150,     0,    15,  -150,     0,    16,
       0,    -6,     0,    17,     0,    -6,     0,     0,     0,     0,
       0,    18,     0,    19,     0,    20,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,    33,    34,     0,     0,    35,    36,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,   146,   147,     0,   148,   308,     0,     0,
       0,   179,     0,   144,   145,   146,   147,     0,   148,     0,
       0,     1,     0,   279,   -70,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,     2,   -45,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,     0,  -150,   -45,     0,     0,     0,  -150,     0,
      13,    14,     0,     0,     0,     0,     0,     0,  -150,     0,
      15,  -150,   144,   145,   146,   147,    85,   148,     0,     0,
     149,     0,     0,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,    33,    34,   -45,
     -45,    35,    36,     1,     0,     0,   -70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,     0,  -150,     0,     0,     0,     0,
    -150,     0,    13,    14,     0,     0,     0,     0,     0,     0,
    -150,     0,    15,  -150,     0,    16,     0,    -6,     0,    17,
       0,    -6,     0,     0,     0,     0,     0,    18,     0,    19,
       0,    20,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     1,    33,
      34,   -70,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,    12,   236,
    -150,     0,     0,     0,     0,  -150,     0,    13,    14,     0,
       0,     0,     0,     0,     0,  -150,     0,    15,  -150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,     0,    20,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     1,    33,    34,   -70,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,     0,  -150,     0,     1,     0,     0,
    -150,     0,    13,    14,     0,     0,     0,     0,     0,     0,
    -150,     2,    15,  -150,     0,     0,     3,     4,    74,     0,
       6,     0,     7,     8,     9,     0,     0,    18,     0,    19,
       0,    20,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     0,    33,
      34,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,     1,     0,     0,
      32,     0,     0,    33,    34,     0,     0,     0,    36,     0,
       0,     2,     0,     0,     0,     0,     3,     4,    74,     0,
       6,     0,     7,     8,     9,   348,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      32,     0,     0,    33,    34,     0,     0,     0,   230,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,     0,   148,     0,   349,     0,     0,     0,     0,
     144,   145,   146,   147,     0,   148,     0,     0,   178,     0,
       0,     0,   144,   145,   146,   147,     0,   148,     0,   316,
      84,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   143,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,   143,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,   143,     0,     0,     0,
       0,   144,   145,   146,   147,     0,   148,     0,   323,   275,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,   147,    85,   148,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,     0,
     148,   200,     0,     0,     0,     0,     0,   144,   145,   146,
     147,     0,   148,   262,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,     0,   148,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   147,     0,   148,
     291,     0,     0,     0,     0,     0,   144,   145,   146,   147,
       0,   148,   317,   374,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
       0,     0,     0,     0,     0,   270,   144,   145,   146,   147,
       0,   148,   354,     0,     0,     0,     0,   358,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,   146,   147,
       0,   148,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,     0,   148,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,   148
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-312)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    18,    11,   176,   177,    36,    32,     2,    13,    14,
      45,    69,   265,    20,     4,     4,    22,    20,    11,    12,
      22,    24,   333,    16,    11,    12,    21,    22,   298,    16,
      11,    12,   106,     4,   107,    32,    71,    42,    33,    34,
      55,    36,    20,    20,    59,    45,   357,    24,    53,    54,
      55,    22,    49,    32,    59,   176,    32,    22,    37,   180,
      33,   372,    70,    39,   102,    38,   100,   105,   104,    69,
      96,    71,    11,    12,   102,    48,    85,    16,    51,    32,
     103,   104,    35,    36,    37,    94,    95,    92,   102,    98,
     102,   361,    99,     4,   100,    97,    99,     5,     6,   102,
       8,     9,    97,    11,    12,   131,    99,   100,    16,   102,
     363,   101,   101,   171,   384,   102,    82,    83,   120,   121,
     122,   102,    99,   103,   104,   120,   121,   122,   102,    32,
     132,     0,    35,   306,    37,   170,   162,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   157,    22,   159,    97,    98,
      99,   100,   157,   102,   159,    99,   161,   102,   102,   164,
     170,   171,   102,   199,   110,   111,   112,   113,   114,    30,
      31,   176,   177,   178,   179,   180,    78,    79,    80,    97,
      98,    99,   100,   102,   102,   102,    76,   232,   104,   230,
     104,    76,   104,   104,   199,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   219,   104,    16,    22,    20,    85,
      86,    87,    88,    89,    90,    46,   228,   100,   105,   238,
     102,   105,   232,   228,   265,   230,    72,   104,    74,   103,
     275,    77,   103,   103,   103,    81,   103,   103,    84,   103,
     103,    32,   102,   102,   249,   102,    53,   292,   260,   276,
     105,    20,     4,    53,    32,   260,   103,    38,   103,   103,
     265,   104,   103,   103,    65,   275,    58,   272,   102,   274,
      33,    46,    32,   300,   279,   103,   295,    48,   283,    36,
     299,   291,   292,    32,   227,   291,   350,    97,    98,    99,
     100,   257,   102,   312,   375,   322,   341,    22,   343,   318,
     319,   306,   321,   348,   340,   381,   325,   369,   351,    -1,
     329,   316,    -1,   332,   359,    -1,    -1,    -1,   323,   338,
      -1,    -1,   363,    -1,    -1,   330,   371,   346,   347,   374,
      -1,   341,    -1,   343,    -1,    -1,    -1,    -1,   348,   358,
      -1,    -1,    -1,    -1,   349,   390,    -1,    -1,   367,   359,
      -1,   370,    -1,    -1,   373,    -1,    -1,    -1,   363,    -1,
     379,   371,    -1,   382,   374,    -1,   385,     0,     1,    -1,
     389,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    15,    -1,    17,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    -1,
      53,    -1,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    -1,    69,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     1,    97,    98,     4,    -1,   101,   102,
      -1,   104,    -1,    -1,   107,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      -1,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     1,    -1,    97,
      98,    -1,    -1,   101,   102,    -1,   104,    -1,    -1,   107,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,     1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    75,    76,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    98,    75,    -1,    -1,   102,    -1,
     104,    -1,    -1,   107,    -1,    85,    86,    87,    88,    89,
      90,     1,    -1,    -1,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,    15,    -1,   107,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    -1,
      -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    97,    98,    99,   100,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     0,     1,    -1,    94,     4,    -1,    97,    98,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    15,   107,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      59,    -1,    97,    98,    99,   100,    65,   102,    67,    -1,
      69,    -1,   107,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,     1,    97,    98,
       4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    51,    -1,    53,
      -1,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    -1,    69,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,     1,    97,    98,     4,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    -1,
      69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,     1,    97,    98,
       4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    -1,    69,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,   101,   102,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,   103,    -1,    -1,
      -1,   107,    -1,    97,    98,    99,   100,    -1,   102,    -1,
      -1,     1,    -1,   107,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    99,
     100,   101,   102,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      -1,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,     1,    97,
      98,     4,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    -1,    69,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,     1,    97,    98,     4,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,     1,    -1,    -1,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    15,    50,    51,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    -1,    -1,    65,    -1,    67,
      -1,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     1,    -1,    -1,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    97,    98,    99,   100,    -1,   102,    -1,   104,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,   102,    -1,   104,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
     102,   103,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,   102,   103,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
      -1,   102,   103,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    34,    97,    98,    99,   100,
      -1,   102,   103,    -1,    -1,    -1,    -1,    34,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    30,    31,    40,    41,    50,    53,    57,    65,    67,
      69,    74,    75,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    97,    98,   101,   102,   110,   114,   115,
     120,   121,   122,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   140,   141,   142,   143,   144,   146,   147,
     150,   151,   152,   153,   155,   158,   160,   165,   167,   168,
     169,   170,   171,   106,    22,    85,    86,    87,    88,    89,
      90,   122,   143,   107,     4,   101,   109,   123,   101,   109,
     123,   123,    20,    22,   166,   166,   100,   145,    70,   107,
     116,   117,   118,   119,   122,   148,   149,   149,   150,   102,
     102,   102,   102,   102,   102,    20,    24,    99,   102,   138,
     139,   139,   139,   115,   120,   122,   122,   118,   122,    55,
      59,   164,   102,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    97,    98,    99,   100,   102,   105,
     123,     4,   133,   123,   123,   123,    99,   102,   104,   112,
     123,    33,    38,    48,    51,   169,   133,     0,   109,   123,
     109,   109,   100,   115,   149,   109,   104,   104,   105,   107,
     104,    76,    76,    82,    83,   113,   113,   113,   113,   113,
     113,    20,    99,   137,   104,   136,   149,   149,   149,   104,
     103,   115,   149,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
      20,   149,    72,    74,    77,    81,    84,   111,    17,   149,
     102,   122,     4,   115,    46,   122,    32,   133,   169,   100,
     116,   117,   122,   116,   122,   122,   122,   117,   122,   105,
     105,   103,   103,   103,   103,   103,   103,   104,   115,   122,
     102,   103,   103,   123,   103,   102,   102,   112,   149,   122,
      34,   133,   105,   102,   134,     4,    53,    32,   109,   107,
     122,    20,   138,   105,   149,   118,   119,   122,    78,    79,
      80,   103,     4,    32,    39,   157,   122,   122,   133,   166,
      53,    32,   122,   103,   122,   103,   104,   103,   103,   103,
     103,   103,   126,   133,    38,   109,   104,   103,   135,   157,
     109,   166,    65,   104,    58,   163,   122,   109,    32,    35,
      36,    37,   154,   156,   122,   109,   109,   109,   166,   122,
     102,   109,    33,   109,   122,   109,    35,   154,     4,   104,
      46,   161,   162,   109,   103,   115,   133,   133,    34,   109,
     109,   133,   122,   134,   162,    32,    49,   159,   103,    32,
     154,   109,   133,   157,     4,   119,   122,    48,   109,   164,
     109,   133,   154,   109,   133,   135,   109,   156,   109,   157,
     109,   109,   133
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
#line 72 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 76 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 80 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 101 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 108 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 116 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 123 "for90.y"
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
#line 136 "for90.y"
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
#line 154 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 161 "for90.y"
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
#line 169 "for90.y"
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
#line 178 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 183 "for90.y"
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
#line 196 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 210 "for90.y"
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

  case 19:
/* Line 1792 of yacc.c  */
#line 221 "for90.y"
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

  case 20:
/* Line 1792 of yacc.c  */
#line 235 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).to_string() });// float number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 240 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).to_string() });// int number
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 244 "for90.y"
    {
				// replace `'` with `"`
				std::string s = (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2);
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + s + "\"" }); // string
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 250 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 254 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 258 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).to_string();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 267 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).to_string() });// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 281 "for90.y"
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
#line 290 "for90.y"
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
#line 300 "for90.y"
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
#line 309 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				/* array_builder is exp */
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_keyvalue_from_exp((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 319 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				ParseNode newnode = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 327 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (3)]);
				ParseNode & argtable = (yyvsp[(1) - (3)]);
				(yyval) = gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 335 "for90.y"
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

  case 35:
/* Line 1792 of yacc.c  */
#line 345 "for90.y"
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

  case 36:
/* Line 1792 of yacc.c  */
#line 355 "for90.y"
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

  case 37:
/* Line 1792 of yacc.c  */
#line 365 "for90.y"
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

  case 38:
/* Line 1792 of yacc.c  */
#line 384 "for90.y"
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

  case 39:
/* Line 1792 of yacc.c  */
#line 394 "for90.y"
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

  case 40:
/* Line 1792 of yacc.c  */
#line 405 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 409 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 414 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 421 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 429 "for90.y"
    {
				/* hyper-function or multi-dimension array like A(2)(3)  */
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s(%s)");
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 437 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode op = gen_token(Term{ TokenMeta::LB, "(" });
				(yyval) = gen_exp(exp, op, "( %s )");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 445 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s + %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 453 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s - %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 461 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s * %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 469 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s / %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 477 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "power(%s, %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 485 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 492 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 499 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s != %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 507 "for90.y"
    {
				// xor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s ^ %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 516 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s == %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 524 "for90.y"
    {
				// nor
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "!(%s ^ %s)");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 533 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s && %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 541 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s || %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 549 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 556 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s > %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 564 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s >= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 572 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s <= %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 580 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s < %s");
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 588 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 594 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 599 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 609 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 613 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 618 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 624 "for90.y"
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

  case 73:
/* Line 1792 of yacc.c  */
#line 634 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 640 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 644 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 648 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 652 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 656 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 661 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 667 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 673 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 678 "for90.y"
    {
				(yyval) = gen_format((yyvsp[(1) - (2)]));
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 683 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 688 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Comments, "/*" + (yyvsp[(1) - (2)]).to_string() + "*/"});
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 707 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).to_string() + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 713 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 722 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 729 "for90.y"
    {
				ParseNode & stmt = (yyvsp[(1) - (1)]); // TokenMeta::NT_LABEL
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, stmt);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 735 "for90.y"
    {
				ParseNode & stmt = (yyvsp[(1) - (2)]); 
				ParseNode & suite = (yyvsp[(2) - (2)]);
				if (stmt.fs.CurrentTerm.token == TokenMeta::NT_LABEL)
				{
					ParseNode & label = stmt.get(0); // TokenMeta::Label
					if (suite.child.size() > 0 && suite.get(0).child.size() > 0 && suite.get(0).get(0).fs.CurrentTerm.token == TokenMeta::NT_FORMAT)
					{
						log_format_index(label.to_string(), suite.get(0));
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

  case 98:
/* Line 1792 of yacc.c  */
#line 755 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 760 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 772 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 776 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).to_string() };
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 780 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 784 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).to_string());
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 789 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 796 "for90.y"
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

  case 112:
/* Line 1792 of yacc.c  */
#line 807 "for90.y"
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

  case 113:
/* Line 1792 of yacc.c  */
#line 821 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 829 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 838 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 846 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 851 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 856 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 861 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 866 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 871 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 877 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 883 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 888 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 893 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 898 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 903 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).to_string().c_str(), "%d", &len);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 911 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 916 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 922 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 927 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 933 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 940 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 948 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 958 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (3)]);
				ParseNode & variable_desc = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 968 "for90.y"
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

  case 137:
/* Line 1792 of yacc.c  */
#line 980 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 987 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 995 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(promote_exp_to_keyvalue(paramtable_elem), paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1003 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1011 "for90.y"
    {
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1023 "for90.y"
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

  case 146:
/* Line 1792 of yacc.c  */
#line 1039 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1046 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1054 "for90.y"
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

  case 153:
/* Line 1792 of yacc.c  */
#line 1077 "for90.y"
    {
				ParseNode & exp = (yyvsp[(4) - (7)]);
				ParseNode & stmt_true = (yyvsp[(6) - (7)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1084 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (8)]);
				ParseNode & suite_true = (yyvsp[(6) - (8)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1091 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (11)]);
				ParseNode & suite_true = (yyvsp[(6) - (11)]); 
				ParseNode & suite_else = (yyvsp[(9) - (11)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1099 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (9)]);
				ParseNode & suite_true = (yyvsp[(6) - (9)]);
				ParseNode & elseif = (yyvsp[(7) - (9)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1107 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (12)]);
				ParseNode & suite_true = (yyvsp[(6) - (12)]);
				ParseNode & elseif = (yyvsp[(7) - (12)]);
				ParseNode & suite_else = (yyvsp[(10) - (12)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1117 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1125 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1137 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1143 "for90.y"
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

  case 164:
/* Line 1792 of yacc.c  */
#line 1153 "for90.y"
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

  case 165:
/* Line 1792 of yacc.c  */
#line 1163 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (7)]);
				ParseNode & suite = (yyvsp[(5) - (7)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1174 "for90.y"
    {
				ParseNode & select = (yyvsp[(2) - (10)]);
				ParseNode & exp = (yyvsp[(5) - (10)]);
				ParseNode & case_stmt = (yyvsp[(8) - (10)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1182 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1190 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1198 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, "" });
				newnode.addchild(case_stmt_elem, false /* add to the front of the vector */); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1208 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1213 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1223 "for90.y"
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

  case 179:
/* Line 1792 of yacc.c  */
#line 1239 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1245 "for90.y"
    {
				(yyval) = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1256 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1264 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1268 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1274 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (1)])); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).to_string().c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1283 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (2)])); // wrapper
				newnode.addchild((yyvsp[(2) - (2)])); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (2)]).to_string().c_str(), (yyvsp[(2) - (2)]).to_string().c_str());
				newnode = flattern_bin_right(newnode);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1295 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1301 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 3885 "for90.tab.cpp"
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
#line 1307 "for90.y"

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
