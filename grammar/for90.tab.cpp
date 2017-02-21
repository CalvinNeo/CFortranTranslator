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
#define YYFINAL  164
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNRULES -- Number of states.  */
#define YYNSTATES  396

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
     101,   102,    98,    96,   103,    97,     2,    99,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   106,   100,
       2,   104,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    87,    91,    93,    97,    99,   103,   107,   111,   116,
     121,   123,   126,   128,   130,   135,   139,   143,   147,   151,
     155,   159,   162,   165,   169,   173,   177,   181,   185,   189,
     192,   196,   200,   204,   208,   210,   212,   214,   216,   219,
     221,   222,   224,   227,   230,   232,   234,   236,   238,   240,
     242,   245,   247,   250,   252,   255,   258,   261,   263,   265,
     267,   270,   273,   277,   282,   286,   288,   291,   293,   296,
     297,   299,   300,   302,   304,   305,   307,   309,   311,   313,
     315,   321,   324,   328,   332,   336,   338,   340,   342,   344,
     346,   348,   353,   358,   363,   368,   373,   378,   382,   384,
     388,   391,   392,   396,   401,   405,   408,   410,   414,   418,
     422,   423,   425,   427,   429,   439,   443,   447,   449,   452,
     453,   456,   458,   467,   479,   489,   502,   508,   513,   519,
     526,   529,   531,   538,   550,   564,   572,   575,   577,   588,
     595,   597,   600,   605,   606,   608,   610,   623,   625,   626,
     635,   643,   645,   647,   649,   651,   654,   664,   666
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,     4,    -1,   100,    -1,    -1,    56,    -1,
      -1,    76,   101,    77,   102,    -1,    76,   101,    78,   102,
      -1,    76,   101,    79,   102,    -1,    73,   101,   118,   102,
      -1,    73,   101,   121,   102,    -1,    80,    -1,    71,    -1,
      83,    -1,   103,   110,    -1,   103,   110,   111,    -1,    -1,
      82,   104,    20,    -1,    81,   104,   121,    -1,    21,    -1,
      20,    -1,    24,    -1,    27,    -1,    28,    -1,    26,    -1,
       1,   105,    -1,    22,    -1,   121,   106,   121,    -1,   121,
     106,   121,   106,   121,    -1,   106,    -1,   121,   104,   121,
      -1,   121,    -1,   117,   103,   121,    -1,   115,    -1,   118,
     103,   115,    -1,   118,   103,   121,    -1,   117,   103,   115,
      -1,   114,   101,   148,   102,    -1,   142,   101,   148,   102,
      -1,   119,    -1,    93,   119,    -1,   120,    -1,   151,    -1,
     121,   101,   121,   102,    -1,   101,   121,   102,    -1,   121,
      96,   121,    -1,   121,    97,   121,    -1,   121,    98,   121,
      -1,   121,    99,   121,    -1,   121,    16,   121,    -1,    97,
     121,    -1,    96,   121,    -1,   121,    10,   121,    -1,   121,
      11,   121,    -1,   121,     7,   121,    -1,   121,    12,   121,
      -1,   121,    13,   121,    -1,   121,    14,   121,    -1,    15,
     121,    -1,   121,     5,   121,    -1,   121,     6,   121,    -1,
     121,     8,   121,    -1,   121,     9,   121,    -1,   149,    -1,
     113,    -1,   114,    -1,   108,    -1,   100,   108,    -1,   100,
      -1,    -1,    30,    -1,   121,   122,    -1,   146,   122,    -1,
     128,    -1,   126,    -1,   127,    -1,   131,    -1,   130,    -1,
     129,    -1,   123,     4,    -1,   145,    -1,    29,   122,    -1,
     124,    -1,   139,   122,    -1,   140,   122,    -1,   141,   122,
      -1,   154,    -1,   157,    -1,   159,    -1,    39,   122,    -1,
      40,   122,    -1,    49,    20,   122,    -1,   121,   104,   121,
     122,    -1,    68,    69,   108,    -1,   125,    -1,   125,   132,
      -1,   169,    -1,   169,   132,    -1,    -1,   101,    -1,    -1,
     102,    -1,   103,    -1,    -1,    98,    -1,    20,    -1,    98,
      -1,    20,    -1,    24,    -1,   101,   136,   103,   137,   102,
      -1,   137,   135,    -1,    90,   138,   148,    -1,    92,   138,
     148,    -1,    91,   138,   148,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    84,   101,
     112,   102,    -1,    85,   101,   112,   102,    -1,    86,   101,
     112,   102,    -1,    87,   101,   112,   102,    -1,    88,   101,
     112,   102,    -1,    89,   101,   112,   102,    -1,   142,    98,
      20,    -1,   142,    -1,    99,   114,    99,    -1,    99,    99,
      -1,    -1,    66,   144,   148,    -1,   143,   111,    17,   148,
      -1,   143,   111,   148,    -1,    73,   148,    -1,   116,    -1,
     147,   103,   116,    -1,   147,   103,   121,    -1,   117,   103,
     116,    -1,    -1,   147,    -1,   117,    -1,   118,    -1,   101,
     117,   103,   114,   104,   121,   103,   121,   102,    -1,    74,
     148,    75,    -1,    74,   149,    75,    -1,   150,    -1,    22,
     106,    -1,    -1,    31,    32,    -1,    36,    -1,   152,    32,
     121,    33,   108,   132,   153,   108,    -1,   152,    32,   121,
      33,   108,   132,    34,   108,   132,   153,   108,    -1,   152,
      32,   121,    33,   108,   132,   155,   153,   108,    -1,   152,
      32,   121,    33,   108,   132,   155,    34,   108,   132,   153,
     108,    -1,   152,    32,   121,    33,   125,    -1,   152,    32,
     121,   125,    -1,    35,   121,    33,   108,   132,    -1,    35,
     121,    33,   108,   132,   155,    -1,    31,    37,    -1,    38,
      -1,   152,    37,   108,   132,   156,   108,    -1,   152,    37,
     114,   104,   121,   103,   121,   108,   132,   156,   108,    -1,
     152,    37,   114,   104,   121,   103,   121,   103,   121,   108,
     132,   156,   108,    -1,   152,    50,   121,   108,   132,   156,
     108,    -1,    31,    47,    -1,    48,    -1,   152,    47,    45,
     133,   121,   134,   108,   161,   158,   108,    -1,    45,   133,
     118,   134,   108,   132,    -1,   160,    -1,   160,   161,    -1,
      57,   101,   114,   102,    -1,    -1,    54,    -1,    58,    -1,
     109,   163,   114,   101,   148,   102,   162,   108,   132,    31,
     163,   108,    -1,    22,    -1,    -1,    52,   165,   108,   132,
      31,    52,   165,   108,    -1,    52,   165,   108,    31,    52,
     165,   108,    -1,   132,    -1,   164,    -1,   166,    -1,   167,
      -1,   167,   168,    -1,    64,   165,   108,   168,   108,    31,
      64,   165,   108,    -1,   168,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    56,    61,    78,    79,    81,    88,    96,
     103,   116,   134,   141,   149,   158,   163,   177,   190,   201,
     215,   220,   224,   229,   233,   237,   244,   246,   260,   269,
     279,   288,   298,   306,   314,   324,   334,   344,   363,   373,
     384,   388,   393,   400,   408,   416,   424,   432,   440,   448,
     456,   464,   471,   478,   486,   495,   503,   512,   520,   528,
     535,   543,   551,   559,   567,   573,   578,   585,   586,   588,
     593,   597,   603,   613,   619,   623,   627,   631,   635,   640,
     645,   650,   655,   660,   668,   669,   671,   673,   674,   675,
     677,   678,   679,   685,   694,   701,   706,   727,   732,   740,
     741,   742,   743,   744,   745,   746,   750,   754,   758,   763,
     770,   781,   795,   803,   812,   820,   825,   830,   835,   840,
     845,   851,   857,   862,   867,   872,   877,   885,   890,   896,
     901,   908,   914,   922,   932,   942,   954,   961,   969,   977,
     986,   993,   994,   995,   997,  1013,  1020,  1031,  1046,  1047,
    1050,  1051,  1054,  1061,  1069,  1077,  1086,  1093,  1101,  1109,
    1118,  1119,  1121,  1127,  1137,  1147,  1155,  1156,  1158,  1166,
    1174,  1182,  1192,  1198,  1204,  1205,  1207,  1220,  1221,  1223,
    1229,  1234,  1247,  1252,  1258,  1267,  1279,  1285,  1289
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
     345,   346,   347,   348,   349,   350,    43,    45,    42,    47,
      59,    40,    41,    44,    61,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   114,   115,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   123,
     123,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   127,   128,   128,   128,
     129,   129,   129,   130,   131,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   139,   140,   141,   142,   142,   142,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   144,   145,   146,   146,   146,   147,   147,   147,   147,
     147,   148,   148,   148,   149,   150,   150,   151,   152,   152,
     153,   153,   154,   154,   154,   154,   154,   154,   155,   155,
     156,   156,   157,   157,   157,   157,   158,   158,   159,   160,
     161,   161,   162,   162,   163,   163,   164,   165,   165,   166,
     166,   166,   167,   167,   168,   168,   169,   170,   170
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
       2,     1,     2,     1,     2,     2,     2,     1,     1,     1,
       2,     2,     3,     4,     3,     1,     2,     1,     2,     0,
       1,     0,     1,     1,     0,     1,     1,     1,     1,     1,
       5,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     3,     1,     3,
       2,     0,     3,     4,     3,     2,     1,     3,     3,     3,
       0,     1,     1,     1,     9,     3,     3,     1,     2,     0,
       2,     1,     8,    11,     9,    12,     5,     4,     5,     6,
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
       4,    71,     4,     4,     0,   178,     5,   178,   131,     0,
       0,     0,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    65,    66,    40,
      42,     4,     0,    83,     0,    75,    76,    74,    79,    78,
      77,   181,     4,     4,     4,   128,    17,    81,     4,    64,
     147,    43,     0,    87,    88,    89,   182,   183,     0,   187,
       0,     0,    26,    27,   115,   116,   117,   118,   119,   120,
      59,     0,   148,     2,     3,    67,    82,    90,    91,     4,
     177,     4,     4,     0,     0,     4,    30,    34,   136,   142,
     143,    32,   141,   135,     0,    64,     0,     0,     0,     0,
       0,     0,   108,   109,   107,     0,   104,     0,     0,     0,
       0,    41,    52,    51,     0,    32,   174,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    80,    96,
      84,    85,    86,     0,     0,     0,     0,    73,     0,     4,
       0,     0,   185,    98,     1,     3,    68,    92,     0,     0,
     130,     0,   132,    94,     0,     0,     0,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     105,     0,   103,   111,   112,   114,   113,     0,    45,     0,
       0,    60,    61,    55,    62,    63,    53,    54,    56,    57,
      58,    50,    46,    47,    48,    49,     0,     4,   127,     0,
      13,     0,     0,    12,    14,    15,     0,   134,     0,     0,
       0,    99,     4,     0,     0,     4,   129,    37,   139,    33,
      35,    36,    31,    28,   137,   138,     0,     0,   121,   122,
     123,   124,   125,   126,     0,    66,    33,     0,    38,    44,
      93,    39,     0,     0,    16,   133,     0,     0,     0,     0,
     157,     0,     0,   100,     0,     0,   178,     0,     0,     0,
      19,    18,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     3,     0,   156,    46,    47,    32,     0,   161,     4,
       0,   101,     0,     4,   178,     0,    29,   110,     0,   173,
       0,    10,    11,     7,     8,     9,     0,    44,   160,   162,
       0,   102,     4,     4,   180,     4,   178,     0,     0,     4,
      33,     0,     4,     0,   151,     4,     0,     4,     0,   165,
     179,     4,     0,     0,     0,   150,     0,     0,   152,     4,
       4,     0,     0,    99,   170,     0,   186,   144,     0,     0,
       0,     4,     0,   154,     4,     0,     0,   171,     0,   167,
       4,   172,     0,     4,     0,     0,     0,     4,   101,    32,
     166,   168,     4,   153,   158,     4,     0,   163,     4,   176,
     159,   155,     4,     0,   164,   169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    36,   225,   156,   183,    37,    38,    97,    98,
      99,   100,    39,    40,    41,    86,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   274,   322,   193,   191,
     116,   117,    52,    53,    54,    81,    56,    94,    57,    58,
     102,   103,    59,    60,    61,    62,   335,    63,   336,   299,
      64,   370,    65,   354,   355,   329,   128,    66,    91,    67,
      68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -307
static const yytype_int16 yypact[] =
{
    1178,   -83,   327,  -307,  -307,   -73,  -307,  -307,  -307,  -307,
       7,  -307,     7,     7,    23,    35,  -307,    35,   -37,    45,
     572,   363,   -17,   -12,    -4,    55,    86,    92,    28,    28,
      28,    89,   327,   327,  -307,   327,    32,  -307,   100,  -307,
    -307,   875,   116,  -307,   896,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,     7,     7,     7,   -78,   103,  -307,     7,  -307,
    -307,  -307,    41,  -307,  -307,  -307,  -307,  -307,  1084,  -307,
     990,   130,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
       2,   106,  -307,  -307,     8,  -307,  -307,  -307,  -307,     7,
    -307,     8,     8,    -1,   572,     8,  -307,  -307,  -307,   105,
     108,  1275,   109,  -307,   134,   138,   -10,   -10,   -10,   -10,
     -10,   -10,  -307,  -307,  -307,     4,   123,   572,   572,   572,
     100,  -307,    93,    93,   124,   717,  -307,  -307,   211,   665,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,  -307,  -307,  -307,
    -307,  -307,  -307,   214,   665,    84,   478,  -307,   327,     6,
     190,   327,  -307,  -307,  -307,  -307,  -307,  -307,  1609,  1515,
    -307,   137,  -307,  -307,   689,   689,   327,   327,   327,  -307,
    -307,   139,   140,   143,   144,   145,   146,   148,   150,  -307,
    -307,   151,  -307,  -307,  -307,  -307,  -307,   327,  -307,   152,
     154,    93,    93,  2097,    93,    93,  2097,  2064,  2064,  2088,
    2076,    64,    20,    20,    64,    64,  1920,  1895,  -307,   155,
    -307,   157,   158,  -307,  -307,   103,   572,  -307,  1414,  1703,
     156,   163,  1908,   213,   237,     8,  -307,  -307,  -307,  1275,
    -307,  1299,  2064,  1311,  -307,   209,   327,   249,  -307,  -307,
    -307,  -307,  -307,  -307,    15,    27,  2064,   665,  -307,  -307,
    -307,  -307,   689,    17,  -307,  -307,  1797,   327,   327,   327,
    -307,    11,   327,  -307,   327,  1703,    35,   218,   240,   327,
    2064,  -307,   174,   327,   176,   177,    69,  1287,   179,   180,
     181,  -307,  1703,  -307,   772,   811,  1942,   248,  -307,     8,
    1460,  1954,    11,     8,    35,   222,  2064,  -307,  1843,   230,
     689,  -307,  -307,  -307,  -307,  -307,   169,    29,  -307,  -307,
     327,  -307,     8,     8,  -307,     8,    35,   327,   189,     8,
    1299,   259,     8,   327,  -307,     8,    25,  1658,   250,  -307,
    -307,     8,  1966,   211,  1703,  -307,  1703,  2021,  -307,     8,
       8,   327,  1703,   163,   250,    10,  -307,  -307,   191,   263,
      19,     8,  1703,  -307,  1908,    11,   689,  -307,   251,  -307,
       8,  -307,    32,     8,  1703,    19,  1703,     8,    82,  1299,
    -307,  -307,     8,  -307,   261,     8,    11,  -307,     8,  -307,
    -307,  -307,     8,  1703,  -307,  -307
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -307,   104,  -307,  -307,    72,   131,  -307,   -27,  -157,   -16,
     -32,  -254,   268,  -307,     5,    -7,  -307,  -307,  -213,  -307,
    -307,  -307,  -307,  -307,  -307,   -43,   -53,   -76,  -307,  -307,
      50,   168,  -307,  -307,  -307,     0,  -307,  -307,  -307,  -307,
    -307,    -2,   291,  -307,  -307,  -307,  -306,  -307,   -70,  -286,
    -307,  -307,  -307,  -307,   -36,  -307,   -55,  -307,   -15,  -307,
    -307,   -59,  -307,  -307
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -189
static const yytype_int16 yytable[] =
{
      55,   149,    92,   124,   120,    87,    88,    80,   286,   162,
      83,    83,    83,   136,   137,   270,   323,   237,   240,   104,
     153,    73,    72,   154,   189,   101,   101,   163,    73,   -45,
     350,   136,   137,    82,   147,   112,   140,   122,   123,   113,
     125,   368,   297,    89,    55,   150,   151,   152,   112,   298,
     331,   157,   113,   293,   373,   334,   331,    90,   369,   349,
     -45,   334,    93,   -45,   -45,   -45,   171,   -45,    55,   385,
      55,   181,   182,   158,   -45,   136,   137,   -45,   159,   377,
     140,   -45,   167,   -45,   106,   -45,   126,   -45,   160,   107,
     127,   161,   172,   -45,   288,   289,   290,   108,   170,   101,
     392,   199,   190,   145,   136,   137,   165,    84,   165,   140,
     235,    73,   378,   114,    95,   194,   195,   196,   143,   144,
     148,   145,   101,   101,   101,   234,   114,   200,   129,   115,
     164,   283,   230,   -45,   101,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   219,   237,   227,   220,   109,   221,   238,   101,
     222,   101,   244,   228,   223,   145,   232,   224,    55,    55,
     255,   311,   175,    74,    75,    76,    77,    78,    79,   239,
     241,   242,   243,   245,   321,   175,   271,   110,   166,   141,
     142,   143,   144,   111,   145,   168,   169,   118,   119,   173,
     331,   129,   256,   332,   333,   334,   155,   154,   174,   179,
     260,   175,   178,   180,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   265,   140,   192,   197,    55,    55,
     285,   101,   302,    73,   218,   231,   236,   124,   184,   185,
     186,   187,   188,   246,   247,   248,   249,   250,   251,   316,
     252,   280,   253,   257,   254,   284,   258,   261,   262,   263,
     272,   303,   101,   229,   273,   276,    55,   287,   277,   281,
     304,   305,   294,   295,   296,    55,   307,   300,   309,   301,
     310,   313,   314,   315,   306,   318,   326,   328,   308,   325,
     343,   345,    55,   371,   372,   353,   333,   264,   380,   121,
     366,   359,   388,   360,   282,   141,   142,   143,   144,   365,
     145,   341,   105,   176,   390,   330,   358,   382,   367,   375,
       0,     0,     0,     0,     0,   337,     0,     0,     1,     0,
       0,   384,   342,   386,   285,     0,   275,     0,   347,   278,
       0,     0,     2,     0,    55,     0,    55,     3,     4,    73,
     395,     6,    55,     7,     8,     9,   364,     0,     0,     0,
       0,     0,    55,     0,     1,     0,     0,     0,     0,     0,
     292,   379,     0,     0,    55,     0,    55,     0,     2,     0,
       0,     0,     0,     3,     4,    73,     0,     6,     0,     7,
       8,     9,     0,    55,     0,     0,     0,     0,     0,     0,
       0,    21,     0,   319,     0,     0,     0,   324,     0,     0,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      31,     0,     0,    32,    33,     0,   338,   339,    35,   340,
       0,     0,     0,   344,     0,     0,   346,    21,  -140,   348,
       0,   352,     0,     0,     0,   356,     0,    74,    75,    76,
      77,    78,    79,   362,   363,     0,    31,     0,     0,    32,
      33,     0,     0,     0,    35,   374,  -140,     0,   376,    96,
       0,     0,     0,     0,   381,     0,     0,   383,  -140,     1,
       0,   387,  -140,     0,     0,     0,   389,     0,     0,   391,
       0,     0,   393,     2,     0,   226,   394,     0,     3,     4,
      73,     0,     6,     0,     7,     8,     9,  -140,  -140,  -140,
    -140,     0,  -140,  -140,  -140,  -140,  -140,  -140,  -140,     0,
       0,     0,     0,  -140,     0,  -140,  -140,  -140,  -140,     0,
    -140,     0,  -140,     0,  -140,     0,  -140,     0,     0,     0,
       0,     0,  -140,     0,  -140,     0,  -140,     0,     0,     0,
       0,  -140,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,  -140,  -140,
    -140,    31,  -140,     1,    32,    33,  -140,     0,  -140,    35,
       0,  -140,     0,     0,    96,     0,     0,     2,     0,     0,
       0,     0,     3,     4,    73,     0,     6,     0,     7,     8,
       9,  -140,  -140,  -140,  -140,     0,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,     0,     0,     0,     0,  -140,     0,  -140,
    -140,  -140,  -140,     0,  -140,     0,  -140,     0,  -140,     0,
    -140,     0,     0,     0,     0,     0,  -140,     0,  -140,     0,
    -140,     0,     0,     0,     0,  -140,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,  -140,  -140,  -140,    31,     1,     0,    32,    33,
       0,     0,  -140,    35,     0,  -140,     0,     0,    96,     0,
       2,     0,     0,     0,     0,     3,     4,    73,     0,     6,
       1,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,    73,     0,     6,     0,     7,     8,     9,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    31,     0,
       0,    32,    33,    21,     0,     0,    35,  -140,  -140,     0,
       0,    96,   -52,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    31,   136,   137,    32,    33,     0,   140,     0,
      35,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,   -52,     0,     0,   -52,   -52,   -52,     0,
     -52,   -51,     0,   141,   142,   143,   144,   -52,   145,   198,
     -52,     0,   136,   137,   -52,     0,   -52,   140,   -52,     0,
     -52,     0,     0,     0,     0,     0,   -52,     0,     0,     0,
       0,     0,   -51,     0,     0,   -51,   -51,   -51,     0,   -51,
       0,     0,     0,     0,     0,     0,   -51,     0,     0,   -51,
       0,     0,     0,   -51,     0,   -51,     0,   -51,     0,   -51,
     143,   144,     0,   145,     0,   -51,   -52,     0,     0,    83,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,     0,     0,     0,     0,   -95,     1,     0,     0,
     -70,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,     2,   145,     0,     0,   -51,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,   -95,   -95,     0,
     -95,   -95,   -95,   -95,   -95,    12,    13,     0,     0,     0,
       0,   -95,     0,   -95,   -95,    14,   -95,     0,   -95,     0,
     -95,     0,   -95,     0,   -95,     0,     0,     0,     0,     0,
      17,     0,    18,     0,    19,     0,     0,     0,     0,    20,
      21,   141,   142,   143,   144,    84,   145,     0,     0,   146,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     -97,     1,    32,    33,   -70,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,   -97,   -97,     0,   -97,   -97,   -97,   -97,   -97,    12,
      13,     0,     0,     0,     0,   -97,     0,   -97,   -97,    14,
     -97,     0,   -97,     0,   -97,     0,   -97,     0,   -97,     0,
       0,     0,     0,     0,    17,     0,    18,     0,    19,     0,
       0,     0,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,  -184,     1,    32,    33,   -70,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,  -184,  -149,     0,     0,     0,
       0,  -149,     0,    12,    13,     0,     0,     0,     0,     0,
       0,  -149,     0,    14,  -149,     0,    15,     0,    -6,     0,
      16,     0,    -6,     0,     0,     0,     0,     0,    17,     0,
      18,     0,    19,     0,     0,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,  -188,     1,
      32,    33,   -70,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
    -149,     0,     0,     0,     0,  -149,     0,    12,    13,     0,
       0,     0,     0,     0,     0,  -149,     0,    14,  -149,     0,
      15,     0,    -6,     0,    16,     0,    -6,     0,     0,     0,
       0,     0,    17,     0,    18,     0,    19,     0,     0,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,    33,     0,     0,    34,    35,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   140,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,     0,   145,     0,     0,   176,
       0,   177,     0,   141,   142,   143,   144,     0,   145,   312,
       0,     0,     0,   177,     0,   141,   142,   143,   144,     0,
     145,     0,     0,     0,     0,   177,     0,   141,   142,   143,
     144,     0,   145,     0,     0,     1,     0,   279,   -70,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     2,
     140,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,     0,  -149,   266,     0,     0,
       0,  -149,     0,    12,    13,     0,     0,     0,     0,     0,
       0,  -149,     0,    14,  -149,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,     0,     0,     0,
      18,     0,    19,     0,     0,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
     267,   268,   143,   144,    34,   269,     1,     0,     0,   -70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,    10,    11,     0,  -149,     0,     0,
       0,     0,  -149,     0,    12,    13,   141,   142,   143,   144,
       0,   145,  -149,   320,    14,  -149,     0,    15,     0,    -6,
       0,    16,     0,    -6,     0,     0,     0,     0,     0,    17,
       0,    18,     0,    19,     0,     0,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       1,    32,    33,   -70,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
     233,  -149,     0,     0,     0,     0,  -149,     0,    12,    13,
       0,     0,     0,     0,     0,     0,  -149,     0,    14,  -149,
       0,     0,    83,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    17,   140,    18,     0,    19,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     1,    32,    33,   -70,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,     0,  -149,     0,     0,     0,     0,
    -149,     0,    12,    13,     0,     0,     0,     0,     0,     0,
    -149,     0,    14,  -149,   141,   142,   143,   144,   165,   145,
       0,   351,     0,     0,     0,     0,     0,    17,     0,    18,
       0,    19,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     1,    32,
      33,    83,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,     0,    -4,
       0,     0,     0,     0,    -4,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    -4,     0,    14,    -4,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,   140,
       0,    -4,     0,    18,     0,    19,     0,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,     0,     0,   291,    35,    83,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,    83,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,   140,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,     0,     0,   141,
     142,   143,   144,     0,   145,     0,   327,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,   140,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,    84,   145,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   165,   145,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
       0,   145,   259,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   140,   141,   142,
     143,   144,     0,   145,   317,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   361,   145,   321,     0,     0,     0,
       0,     0,   141,   142,   143,   144,     0,   145,   357,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,   140,   130,   131,   132,   133,   134,   135,   136,
     137,     0,   130,   131,   140,   133,   134,     0,   136,   137,
       0,     0,     0,   140,     0,     0,     0,   141,   142,   143,
     144,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,     0,   145,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,     0,   145,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,     0,   145,
       0,     0,     0,   141,   142,   143,   144,     0,   145
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-307)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    44,    17,    35,    31,    12,    13,     2,   262,    68,
       4,     4,     4,    11,    12,   228,   302,   174,   175,    21,
      98,    22,   105,   101,    20,    20,    21,    70,    22,     0,
     336,    11,    12,   106,    41,    20,    16,    32,    33,    24,
      35,    31,    31,    20,    44,    52,    53,    54,    20,    38,
      31,    58,    24,   266,   360,    36,    31,    22,    48,    34,
      31,    36,    99,    34,    35,    36,    93,    38,    68,   375,
      70,    81,    82,    32,    45,    11,    12,    48,    37,   365,
      16,    52,    89,    54,   101,    56,    54,    58,    47,   101,
      58,    50,    94,    64,    77,    78,    79,   101,    99,    94,
     386,   128,    98,   101,    11,    12,   100,   100,   100,    16,
     169,    22,   366,    98,    69,   117,   118,   119,    98,    99,
       4,   101,   117,   118,   119,   168,    98,   129,   101,   101,
       0,   104,   159,   104,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   154,   310,   156,    71,   101,    73,   174,   154,
      76,   156,   178,   158,    80,   101,   161,    83,   168,   169,
     197,   102,   103,    84,    85,    86,    87,    88,    89,   174,
     175,   176,   177,   178,   102,   103,   229,   101,    84,    96,
      97,    98,    99,   101,   101,    91,    92,    29,    30,    95,
      31,   101,   197,    34,    35,    36,   103,   101,   103,    75,
     217,   103,   103,    75,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   226,    16,   103,   103,   228,   229,
     262,   226,   275,    22,    20,    45,    99,   269,   107,   108,
     109,   110,   111,   104,   104,   102,   102,   102,   102,   292,
     102,   246,   102,   101,   103,   257,   102,   102,   101,   101,
     104,   276,   257,   159,   101,    52,   266,   262,    31,    20,
      52,    31,   267,   268,   269,   275,   102,   272,   102,   274,
     103,   102,   102,   102,   279,    37,    64,    57,   283,   304,
     101,    32,   292,   102,    31,    45,    35,   225,    47,    31,
     353,   344,   378,   346,   254,    96,    97,    98,    99,   352,
     101,   326,    21,   104,   384,   310,   343,   372,   354,   362,
      -1,    -1,    -1,    -1,    -1,   320,    -1,    -1,     1,    -1,
      -1,   374,   327,   376,   366,    -1,   232,    -1,   333,   235,
      -1,    -1,    15,    -1,   344,    -1,   346,    20,    21,    22,
     393,    24,   352,    26,    27,    28,   351,    -1,    -1,    -1,
      -1,    -1,   362,    -1,     1,    -1,    -1,    -1,    -1,    -1,
     266,   366,    -1,    -1,   374,    -1,   376,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,   299,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,   322,   323,   101,   325,
      -1,    -1,    -1,   329,    -1,    -1,   332,    74,    75,   335,
      -1,   337,    -1,    -1,    -1,   341,    -1,    84,    85,    86,
      87,    88,    89,   349,   350,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,    -1,   101,   361,   103,    -1,   364,   106,
      -1,    -1,    -1,    -1,   370,    -1,    -1,   373,     0,     1,
      -1,   377,     4,    -1,    -1,    -1,   382,    -1,    -1,   385,
      -1,    -1,   388,    15,    -1,    17,   392,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    -1,    47,    48,    49,    50,    -1,
      52,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,     1,    96,    97,     4,    -1,   100,   101,
      -1,   103,    -1,    -1,   106,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     1,    -1,    96,    97,
      -1,    -1,   100,   101,    -1,   103,    -1,    -1,   106,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
       1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    74,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,     0,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    11,    12,    96,    97,    -1,    16,    -1,
     101,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,    -1,
      38,     0,    -1,    96,    97,    98,    99,    45,   101,   102,
      48,    -1,    11,    12,    52,    -1,    54,    16,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      98,    99,    -1,   101,    -1,    64,   104,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    15,   101,    -1,    -1,   104,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    49,    50,    -1,    52,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      74,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     1,    96,    97,     4,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     1,    96,    97,     4,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    52,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     1,
      96,    97,     4,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
      52,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,   104,
      -1,   106,    -1,    96,    97,    98,    99,    -1,   101,   102,
      -1,    -1,    -1,   106,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,   106,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,     1,    -1,   106,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    -1,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      96,    97,    98,    99,   100,   101,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    96,    97,    98,    99,
      -1,   101,    47,   103,    49,    50,    -1,    52,    -1,    54,
      -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
       1,    96,    97,     4,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    64,    16,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,     1,    96,    97,     4,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,     1,    96,
      97,     4,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    96,
      97,    98,    99,    -1,   101,    -1,   103,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    96,    97,
      98,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    33,   101,   102,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,     5,     6,    16,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    30,    39,    40,    49,    52,    56,    64,    66,    68,
      73,    74,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    96,    97,   100,   101,   109,   113,   114,   119,
     120,   121,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   139,   140,   141,   142,   143,   145,   146,   149,
     150,   151,   152,   154,   157,   159,   164,   166,   167,   168,
     169,   170,   105,    22,    84,    85,    86,    87,    88,    89,
     121,   142,   106,     4,   100,   108,   122,   122,   122,    20,
      22,   165,   165,    99,   144,    69,   106,   115,   116,   117,
     118,   121,   147,   148,   148,   149,   101,   101,   101,   101,
     101,   101,    20,    24,    98,   101,   137,   138,   138,   138,
     114,   119,   121,   121,   117,   121,    54,    58,   163,   101,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    96,    97,    98,    99,   101,   104,   122,     4,   132,
     122,   122,   122,    98,   101,   103,   111,   122,    32,    37,
      47,    50,   168,   132,     0,   100,   108,   122,   108,   108,
      99,   114,   148,   108,   103,   103,   104,   106,   103,    75,
      75,    81,    82,   112,   112,   112,   112,   112,   112,    20,
      98,   136,   103,   135,   148,   148,   148,   103,   102,   114,
     148,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,    20,   148,
      71,    73,    76,    80,    83,   110,    17,   148,   121,   108,
     114,    45,   121,    31,   132,   168,    99,   115,   116,   121,
     115,   121,   121,   121,   116,   121,   104,   104,   102,   102,
     102,   102,   102,   102,   103,   114,   121,   101,   102,   102,
     122,   102,   101,   101,   111,   148,    33,    96,    97,   101,
     125,   132,   104,   101,   133,   108,    52,    31,   108,   106,
     121,    20,   137,   104,   148,   117,   118,   121,    77,    78,
      79,   100,   108,   125,   121,   121,   121,    31,    38,   156,
     121,   121,   132,   165,    52,    31,   121,   102,   121,   102,
     103,   102,   102,   102,   102,   102,   132,   102,    37,   108,
     103,   102,   134,   156,   108,   165,    64,   103,    57,   162,
     121,    31,    34,    35,    36,   153,   155,   121,   108,   108,
     108,   165,   121,   101,   108,    32,   108,   121,   108,    34,
     153,   103,   108,    45,   160,   161,   108,   102,   114,   132,
     132,    33,   108,   108,   121,   132,   133,   161,    31,    48,
     158,   102,    31,   153,   108,   132,   108,   156,   118,   121,
      47,   108,   163,   108,   132,   153,   132,   108,   134,   108,
     155,   108,   156,   108,   108,   132
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
#line 53 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 57 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 61 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 82 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 89 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 97 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 104 "for90.y"
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
#line 117 "for90.y"
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
#line 135 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 142 "for90.y"
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
#line 150 "for90.y"
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
#line 159 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 164 "for90.y"
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
#line 177 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 191 "for90.y"
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
#line 202 "for90.y"
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
#line 216 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).to_string() });// float number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 221 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).to_string() });// int number
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 225 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2) + "\"" }); // string
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 230 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 234 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 238 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).to_string();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 247 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).to_string() });// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 261 "for90.y"
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
#line 270 "for90.y"
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
#line 280 "for90.y"
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
#line 289 "for90.y"
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
#line 299 "for90.y"
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
#line 307 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (3)]);
				ParseNode & argtable = (yyvsp[(1) - (3)]);
				(yyval) = gen_flattern(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 315 "for90.y"
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
#line 325 "for90.y"
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
#line 335 "for90.y"
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
#line 345 "for90.y"
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
#line 364 "for90.y"
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
#line 374 "for90.y"
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
#line 385 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 389 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 394 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 401 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 409 "for90.y"
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
#line 417 "for90.y"
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
#line 425 "for90.y"
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
#line 433 "for90.y"
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
#line 441 "for90.y"
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
#line 449 "for90.y"
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
#line 457 "for90.y"
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
#line 465 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 472 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 479 "for90.y"
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
#line 487 "for90.y"
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
#line 496 "for90.y"
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
#line 504 "for90.y"
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
#line 513 "for90.y"
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
#line 521 "for90.y"
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
#line 529 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 536 "for90.y"
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
#line 544 "for90.y"
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
#line 552 "for90.y"
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
#line 560 "for90.y"
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
#line 568 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 574 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 579 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 589 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 593 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 598 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 604 "for90.y"
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
#line 614 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 620 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 624 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 628 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 632 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 636 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 641 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 646 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 651 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 656 "for90.y"
    {
				(yyval) = gen_format((yyvsp[(1) - (2)]));
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 661 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 680 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).to_string() + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 686 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				(yyval) = gen_exp(exp1, op, exp2, "%s = %s");
				update_pos((yyval));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 695 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 702 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 707 "for90.y"
    {

				ParseNode & stmt = (yyvsp[(1) - (2)]); // TokenMeta::NT_LABEL
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

  case 97:
/* Line 1792 of yacc.c  */
#line 728 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 733 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 747 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 751 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).to_string() };
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 755 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 759 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).to_string());
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 764 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).to_string().substr(1, (yyvsp[(1) - (1)]).to_string().size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
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

  case 111:
/* Line 1792 of yacc.c  */
#line 782 "for90.y"
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

  case 112:
/* Line 1792 of yacc.c  */
#line 796 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 804 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 813 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 821 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 826 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 831 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 836 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 841 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 846 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 852 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 858 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 863 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 868 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 873 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 878 "for90.y"
    {
				ParseNode newnode = gen_type((yyvsp[(1) - (4)]));
				int len;
				sscanf((yyvsp[(3) - (4)]).to_string().c_str(), "%d", &len);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 886 "for90.y"
    {
				// $$ = gen_type($1, $3);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 891 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 897 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 902 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 908 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // variant
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 915 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 923 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & variable_desc = (yyvsp[(2) - (4)]);
				ParseNode & paramtable = (yyvsp[(4) - (4)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 933 "for90.y"
    {
				/* array decl */
				ParseNode & type_spec = (yyvsp[(1) - (3)]);
				ParseNode & variable_desc = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);

				(yyval) = gen_vardef(type_spec, variable_desc, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 943 "for90.y"
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

  case 136:
/* Line 1792 of yacc.c  */
#line 955 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 962 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 970 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(promote_exp_to_keyvalue(paramtable_elem), paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 978 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(3) - (3)]);
				ParseNode & paramtable = (yyvsp[(1) - (3)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem, paramtable);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 986 "for90.y"
    {
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 998 "for90.y"
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

  case 145:
/* Line 1792 of yacc.c  */
#line 1014 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1021 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				// rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule because \
				// these two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict 
				// so either that `variable '(' dimen_slice ')'` is an `exp`
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1032 "for90.y"
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

  case 152:
/* Line 1792 of yacc.c  */
#line 1055 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (8)]);
				ParseNode & suite_true = (yyvsp[(6) - (8)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1062 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (11)]);
				ParseNode & suite_true = (yyvsp[(6) - (11)]); 
				ParseNode & suite_else = (yyvsp[(9) - (11)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1070 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (9)]);
				ParseNode & suite_true = (yyvsp[(6) - (9)]);
				ParseNode & elseif = (yyvsp[(7) - (9)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1078 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (12)]);
				ParseNode & suite_true = (yyvsp[(6) - (12)]);
				ParseNode & elseif = (yyvsp[(7) - (12)]);
				ParseNode & suite_else = (yyvsp[(10) - (12)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1087 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (5)]);
				ParseNode & stmt_true = (yyvsp[(5) - (5)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1094 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1102 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1110 "for90.y"
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
#line 1122 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1128 "for90.y"
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
#line 1138 "for90.y"
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
#line 1148 "for90.y"
    {
				ParseNode & exp = (yyvsp[(3) - (7)]);
				ParseNode & suite = (yyvsp[(5) - (7)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1159 "for90.y"
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
#line 1167 "for90.y"
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
#line 1175 "for90.y"
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
#line 1183 "for90.y"
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
#line 1193 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1198 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1208 "for90.y"
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
#line 1224 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1230 "for90.y"
    {
				(yyval) = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1240 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1248 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).to_string().c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1253 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).to_string().c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1259 "for90.y"
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
#line 1268 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (2)])); // wrapper
				newnode.addchild((yyvsp[(2) - (2)])); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (2)]).to_string().c_str(), (yyvsp[(2) - (2)]).to_string().c_str());
				newnode = flattern_bin(newnode);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1280 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1286 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 3896 "for90.tab.cpp"
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
#line 1292 "for90.y"

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
