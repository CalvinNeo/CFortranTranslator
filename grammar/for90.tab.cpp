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
#include "../cgen.h"
#include "../Function.h"

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
#line 93 "for90.tab.cpp"

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
     YY_OPEN = 352,
     YY_CLOSE = 353,
     YY_CALL = 354
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
#define YYLAST   1374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  318

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   354

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     109,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     106,   107,   103,   101,   108,   102,     2,   104,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   105,
       2,   100,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    12,    13,    18,
      23,    28,    33,    38,    40,    42,    46,    50,    53,    57,
      58,    60,    63,    64,    66,    68,    70,    72,    74,    76,
      79,    81,    83,    85,    89,    95,    97,    99,   103,   105,
     109,   114,   116,   120,   124,   128,   132,   136,   140,   143,
     146,   150,   154,   158,   162,   166,   170,   173,   177,   181,
     185,   189,   191,   193,   195,   196,   199,   202,   204,   206,
     208,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   231,   234,   237,   242,   246,   248,   251,   252,   253,
     255,   256,   258,   260,   261,   263,   265,   267,   269,   275,
     278,   283,   288,   293,   297,   298,   301,   304,   307,   310,
     313,   316,   321,   323,   327,   331,   333,   337,   338,   346,
     350,   354,   356,   357,   359,   363,   372,   384,   394,   407,
     412,   418,   425,   432,   444,   458,   466,   477,   484,   486,
     489,   494,   495,   497,   499,   512,   514,   515,   524,   526,
     528,   530,   533,   541
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,     5,    -1,   105,    -1,    -1,    59,    -1,
     113,    -1,    -1,    79,   106,    80,   107,    -1,    79,   106,
      81,   107,    -1,    79,   106,    82,   107,    -1,    76,   106,
     121,   107,    -1,    76,   106,   123,   107,    -1,    83,    -1,
      73,    -1,    84,   100,   123,    -1,    85,   100,    23,    -1,
     108,   114,    -1,   108,   114,   115,    -1,    -1,   114,    -1,
     114,   116,    -1,    -1,    24,    -1,    23,    -1,    27,    -1,
      30,    -1,    31,    -1,    29,    -1,     1,   109,    -1,    25,
      -1,   118,    -1,   143,    -1,   123,   110,   123,    -1,   123,
     110,   123,   110,   123,    -1,   110,    -1,   120,    -1,   120,
     108,   121,    -1,   123,    -1,   123,   108,   124,    -1,   119,
     106,   124,   107,    -1,   122,    -1,   106,   123,   107,    -1,
     123,   101,   123,    -1,   123,   102,   123,    -1,   123,   103,
     123,    -1,   123,   104,   123,    -1,   123,    18,   123,    -1,
     102,   123,    -1,   101,   123,    -1,   123,    12,   123,    -1,
     123,    13,   123,    -1,   123,     9,   123,    -1,   123,    14,
     123,    -1,   123,    15,   123,    -1,   123,    16,   123,    -1,
      17,   123,    -1,   123,     7,   123,    -1,   123,     8,   123,
      -1,   123,    10,   123,    -1,   123,    11,   123,    -1,   117,
      -1,   119,    -1,   121,    -1,    -1,   123,   112,    -1,   144,
     112,    -1,   128,    -1,   126,    -1,   127,    -1,   131,    -1,
     130,    -1,   129,    -1,   164,    -1,   139,    -1,   140,    -1,
     141,    -1,   151,    -1,   153,    -1,   154,    -1,    41,   112,
      -1,    42,   112,    -1,    51,   112,    -1,   123,   100,   123,
     112,    -1,    70,    71,   112,    -1,   125,    -1,   125,   132,
      -1,    -1,    -1,   106,    -1,    -1,   107,    -1,   108,    -1,
      -1,   103,    -1,    23,    -1,   103,    -1,    27,    -1,   106,
     136,   108,   137,   107,    -1,   137,   135,    -1,    94,   138,
     124,   112,    -1,    96,   138,   124,   112,    -1,    95,   138,
     124,   112,    -1,   106,   116,   107,    -1,    -1,    87,   142,
      -1,    88,   142,    -1,    89,   142,    -1,    90,   142,    -1,
      91,   142,    -1,    92,   142,    -1,   143,   115,    19,   146,
      -1,   118,    -1,   118,   100,   123,    -1,   118,   100,   150,
      -1,   145,    -1,   145,   108,   146,    -1,    -1,   123,   108,
     118,   100,   123,   108,   123,    -1,    77,   124,    78,    -1,
      77,   147,    78,    -1,    35,    -1,    -1,   148,    -1,   148,
     108,   150,    -1,    34,   123,    35,   112,   132,    33,    34,
     112,    -1,    34,   123,    35,   112,   132,    36,   112,   132,
      33,    34,   112,    -1,    34,   123,    35,   112,   132,   152,
      33,    34,   112,    -1,    34,   123,    35,   112,   132,   152,
      36,   112,   132,    33,    34,   112,    -1,    34,   123,   149,
     125,    -1,    37,   123,    35,   112,   132,    -1,    37,   123,
      35,   112,   132,   152,    -1,    39,   112,   132,    33,    39,
     112,    -1,    39,   118,   100,   123,   108,   123,   112,   132,
      33,    39,   112,    -1,    39,   118,   100,   123,   108,   123,
     108,   123,   112,   132,    33,    39,   112,    -1,    52,   123,
     112,   132,    33,    39,   112,    -1,    49,    47,   133,   123,
     134,   112,   156,    33,    49,   112,    -1,    47,   133,   121,
     134,   112,   132,    -1,   155,    -1,   155,   156,    -1,    60,
     106,   118,   107,    -1,    -1,    57,    -1,    61,    -1,   113,
     158,   118,   106,   146,   107,   157,   112,   132,    33,   158,
     112,    -1,    25,    -1,    -1,    55,   160,   112,   132,    33,
      55,   160,   112,    -1,   159,    -1,   161,    -1,   162,    -1,
     162,   163,    -1,    67,   112,   163,   112,    33,    67,   112,
      -1,   163,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    57,    63,    68,    69,    70,    72,    82,
      93,   103,   125,   151,   160,   170,   174,   186,   192,   209,
     217,   223,   239,   247,   254,   260,   268,   274,   280,   289,
     292,   299,   299,   306,   321,   333,   348,   367,   389,   401,
     417,   451,   465,   479,   492,   505,   518,   531,   544,   556,
     568,   581,   594,   607,   620,   633,   646,   658,   671,   684,
     697,   710,   716,   724,   769,   779,   796,   809,   810,   811,
     812,   813,   823,   833,   835,   836,   838,   840,   841,   842,
     844,   845,   846,   848,   863,   872,   882,   896,   908,   909,
     910,   911,   912,   913,   914,   919,   924,   929,   937,   949,
     964,  1001,  1045,  1091,  1097,  1105,  1117,  1127,  1137,  1147,
    1157,  1169,  1406,  1423,  1440,  1458,  1463,  1478,  1486,  1498,
    1513,  1536,  1537,  1538,  1547,  1559,  1575,  1594,  1612,  1633,
    1649,  1666,  1684,  1698,  1720,  1738,  1754,  1827,  1843,  1852,
    1863,  1868,  1874,  1875,  1877,  2067,  2068,  2070,  2080,  2086,
    2093,  2101,  2112,  2121
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
  "YY_OPEN", "YY_CLOSE", "YY_CALL", "'='", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "','", "'\\n'", "':'", "$accept", "crlf",
  "dummy_function_iden", "dummy_variable_iden_1", "dummy_variable_iden",
  "dummy_variable_spec", "literal", "variable", "callable", "slice",
  "dimen_slice", "function_array", "exp", "argtable", "stmt",
  "output_stmt", "input_stmt", "compound_stmt", "jump_stmt", "let_stmt",
  "dummy_stmt", "suite", "_optional_lbrace", "_optional_rbrace",
  "_optional_comma", "_optional_device", "_optional_formatter", "io_info",
  "write", "print", "read", "_type_kind", "type_spec", "var_def",
  "kwargtable", "paramtable", "_generate_stmt", "array_builder_elem",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
      61,    43,    45,    42,    47,    59,    40,    41,    44,    10,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   115,
     116,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     118,   119,   119,   120,   120,   120,   121,   121,   121,   121,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   127,   128,   128,   128,
     129,   129,   129,   130,   131,   132,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   140,   141,   142,   142,   143,   143,   143,   143,   143,
     143,   144,   145,   145,   145,   146,   146,   146,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   153,   153,   154,   155,   156,   156,
     157,   157,   158,   158,   159,   160,   160,   161,   162,   162,
     163,   163,   164,   165
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     1,     0,     4,     4,
       4,     4,     4,     1,     1,     3,     3,     2,     3,     0,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     3,     5,     1,     1,     3,     1,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     1,     1,     1,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     3,     1,     2,     0,     0,     1,
       0,     1,     1,     0,     1,     1,     1,     1,     5,     2,
       4,     4,     4,     3,     0,     2,     2,     2,     2,     2,
       2,     4,     1,     3,     3,     1,     3,     0,     7,     3,
       3,     1,     0,     1,     3,     8,    11,     9,    12,     4,
       5,     6,     6,    11,    13,     7,    10,     6,     1,     2,
       4,     0,     1,     1,    12,     1,     0,     8,     1,     1,
       1,     2,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,   146,     5,     0,   148,   149,   150,   153,     0,   145,
       4,   142,   143,     0,   151,     1,     2,     3,     0,    30,
       0,     0,     0,    24,    23,    25,    28,    26,    27,     0,
       4,     4,     4,     0,     4,     0,     4,     0,   104,   104,
     104,   104,   104,   104,     0,     0,     0,     0,     0,     0,
      61,    31,    62,    41,     4,     0,    68,    69,    67,    72,
      71,    70,     0,    74,    75,    76,    32,     4,    77,    78,
      79,    73,   117,    29,    56,    32,   122,     0,     0,    80,
      81,    88,    82,     4,     7,     4,    22,   105,   106,   107,
     108,   109,   110,    97,    96,     0,    93,     0,     0,     0,
      49,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    86,     0,     0,     0,    66,   112,   115,     0,     4,
       0,     0,     0,    89,     0,     0,     4,    84,    14,     0,
       0,    13,     0,     0,    20,     0,    95,    94,     0,    92,
      99,    35,    36,    63,    38,     4,     4,     4,    42,     0,
      57,    58,    52,    59,    60,    50,    51,    53,    54,    55,
      47,     4,    43,    44,    45,    46,   146,    17,   117,     0,
     117,   141,     0,   129,     0,     0,    90,     0,     0,     0,
       0,     0,     0,    21,   103,     0,     0,     0,     0,   100,
     102,   101,    40,    83,     4,    18,   111,     0,   113,   123,
     114,   116,     0,     4,     0,     4,     0,    91,     4,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,    37,
      39,    33,   147,    38,     0,     0,     0,     0,     0,     0,
       4,     0,     0,   132,     4,     0,     4,     4,    11,    12,
       8,     9,    10,    98,     0,     0,   119,   120,   124,     0,
       0,     4,     0,     0,     0,     4,     0,     0,    88,   138,
       0,   135,   152,    34,    31,   140,     0,   125,     0,     4,
       4,     0,     4,     0,     0,   139,     0,     0,     4,     0,
       0,   127,     0,     0,     0,    90,     4,     0,   144,     4,
     130,     0,     0,     4,     4,   136,     0,   126,   131,     4,
       0,   133,     0,   118,   128,     4,   137,   134
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,     3,   144,   124,   145,    50,    51,    52,   152,
     153,    53,    54,   230,    55,    56,    57,    58,    59,    60,
      61,    62,   134,   218,   150,   148,    96,    97,    63,    64,
      65,    87,    75,    67,   127,   128,   235,   209,   130,   210,
      68,   242,    69,    70,   269,   270,   213,    13,     4,    10,
       5,     6,     7,    71,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
     -25,   -15,  -178,   -11,  -178,  -178,    61,  -178,    47,  -178,
      -4,  -178,  -178,     2,  -178,  -178,  -178,  -178,   862,  -178,
     -54,   -48,   994,  -178,  -178,  -178,  -178,  -178,  -178,   994,
      -2,    -4,    -4,    21,    -4,   994,    -4,     5,   -14,   -14,
     -14,   -14,   -14,   -14,    -1,    -1,    -1,   994,   994,   994,
    -178,  -178,     3,  -178,  1094,   622,  -178,  -178,  -178,  -178,
    -178,  -178,    77,  -178,  -178,  -178,   -13,    -4,  -178,  -178,
    -178,  -178,     2,  -178,    27,  -178,  1142,   862,     8,  -178,
    -178,    13,  -178,  1106,   -25,    -4,   -28,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,    -9,    15,   438,   438,   438,
      40,    40,  1118,    48,   994,   994,   994,   994,   994,   994,
     994,   994,   994,   994,   994,   994,   994,   994,   994,   994,
    -178,  -178,    76,   -28,    92,  -178,    45,    22,    39,    -4,
     942,   118,   994,  -178,   994,   862,    -4,  -178,  -178,    46,
      50,  -178,    53,    57,   -28,    58,  -178,  -178,    59,  -178,
    -178,  -178,    60,  -178,   672,    -4,    -4,    -4,  -178,    62,
      40,    40,    25,    40,    40,    25,  1172,  1172,  1270,  1252,
      27,  1106,    11,    11,    56,    56,   -15,    63,     2,   973,
       2,   106,   702,  -178,   134,   488,  1130,   141,   142,   530,
      17,   994,   157,  -178,  -178,     1,   530,   327,   994,  -178,
    -178,  -178,  -178,  -178,    -4,  -178,  -178,   492,  1172,    78,
    -178,  -178,    81,    -4,    30,    -4,   994,  -178,    -4,   145,
     121,    82,    75,    84,    86,    87,  1172,  -178,    89,  -178,
    -178,   832,  -178,   752,   119,   122,   124,     2,   862,   164,
      -4,   994,    88,  -178,   596,   152,    -4,    -4,  -178,  -178,
    -178,  -178,  -178,  -178,   994,   492,  -178,  -178,  -178,    95,
     171,    -4,   862,  1154,   172,    -4,   994,   862,    13,   152,
     174,  -178,  -178,  1172,   105,  -178,   -11,  -178,   175,    -4,
      -4,   862,  1106,   176,   530,  -178,   161,   994,    -4,   177,
     702,  -178,   179,   862,   180,   107,    -4,   912,  -178,    -4,
     178,   182,   185,    -4,    -4,  -178,   994,  -178,  -178,    -4,
     183,  -178,   782,  1172,  -178,    -4,  -178,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   -23,  -178,    90,    51,    91,  -178,    -8,  -178,  -178,
    -177,  -178,   204,   -82,   100,  -178,  -178,  -178,  -178,  -178,
    -178,   -35,   -43,   -64,  -178,  -178,    41,    35,  -178,  -178,
    -178,   120,   -18,  -178,  -178,  -176,  -178,  -178,  -178,     4,
    -178,   -66,  -178,  -178,  -178,   -32,  -178,   -33,  -178,    65,
    -178,  -178,    12,  -178,  -178
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      66,    16,   206,    16,   211,    20,   -19,    77,    79,    80,
       9,    82,   221,    84,   146,   155,   156,   157,    14,   229,
     121,   159,    78,    19,   110,   111,    93,    19,    93,   114,
       1,   120,   104,   105,     2,   107,   108,    66,   110,   111,
     110,   111,   131,   114,   125,   138,    11,    15,   139,    21,
      12,   140,    72,   110,   111,   141,   142,   143,   114,    66,
     135,    73,   137,   239,   126,    22,   240,   241,    81,   110,
     111,    23,    24,    19,   114,    25,    85,    26,    27,    28,
      98,    99,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    86,   114,   147,   123,   136,   223,   224,   225,
     187,    17,    94,    17,    94,    95,   182,   295,   132,   103,
     122,   178,    66,   188,   118,   119,     1,    66,    -7,   133,
       2,   264,    -7,   149,   265,   234,   116,   117,   118,   119,
     180,   176,   199,   200,   201,    38,    39,    40,    41,    42,
      43,   116,   117,   118,   119,   179,   181,   214,   203,    47,
      48,   184,   189,   191,    49,   -64,   190,   192,   151,    88,
      89,    90,    91,    92,    66,   194,   212,   195,   196,   202,
     126,   123,   126,   215,   219,   220,   116,   117,   118,   119,
     227,   232,   249,   197,   246,   198,   236,   237,   247,   248,
     238,   250,   243,   251,   252,   245,   253,   256,   261,   268,
     257,   207,   275,   260,   276,   287,   280,   286,   289,   294,
     296,   299,   301,   177,   217,   241,   309,   262,   310,   303,
      66,   267,   315,   271,   272,   284,    74,   278,   205,   259,
     183,   304,   283,    76,   308,   193,   228,   285,   277,    83,
     258,   204,   281,   288,    66,     0,   292,   274,     0,    66,
       0,   100,   101,   102,     0,   300,   290,   291,   302,   293,
       0,     0,     0,    66,     0,   298,     0,     0,     0,     0,
       0,     0,    66,   305,     0,    66,   307,   316,     0,     0,
     311,   312,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,   317,     0,    66,     0,     0,     0,     0,     0,
       0,   154,   154,   154,     0,     0,     0,   154,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,    21,     0,
       0,     0,   -64,     0,     0,     0,   185,     0,   186,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
      23,    24,    19,     0,    25,     0,    26,    27,    28,     0,
     -64,   -64,     0,   -64,   -64,     0,   -64,     0,   -64,   -64,
       0,     0,     0,     0,   -64,     0,   -64,     0,   -64,   -64,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   -64,   226,     0,   -64,     0,     0,
     154,   154,   231,     0,     0,   -64,     0,     0,     0,     0,
       0,   233,     0,     0,    38,    39,    40,    41,    42,    43,
     244,   -64,   -64,   -64,     0,     0,     0,     0,    47,    48,
       0,     0,   -64,    49,   -64,     0,     0,   151,     0,    21,
       0,     0,     0,   -64,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,   273,   154,
       0,    23,    24,    19,     0,    25,     0,    26,    27,    28,
     282,   -64,   -64,     0,   -64,   -64,     0,   -64,     0,   -64,
     -64,     0,     0,     0,     0,   -64,     0,   -64,   154,   -64,
     -64,   297,     0,    21,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   -64,   114,     0,   -64,    22,
     313,     0,     0,     0,     0,    23,    24,    19,     0,    25,
       0,    26,    27,    28,     0,    38,    39,    40,    41,    42,
      43,    21,   -64,   -64,   -64,     0,     0,     0,     0,    47,
      48,     0,     0,   -64,    49,     0,     0,    22,   151,     0,
       0,     0,     0,    23,    24,    19,     0,    25,     0,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,     0,
     -64,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,     0,     0,     0,   116,
     117,   118,   119,    47,    48,     0,   216,     0,    49,     0,
       0,    16,   151,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,     0,     0,    38,    39,    40,
      41,    42,    43,    21,     0,     0,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,    49,     0,     0,    22,
     151,     0,     0,     0,     0,    23,    24,    19,     0,    25,
       0,    26,    27,    28,     0,   -85,    29,     0,   -85,   -85,
       0,    30,     0,    31,    32,     0,     0,     0,     0,   -85,
       0,    33,     0,    34,    35,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    36,
     114,     0,    37,     0,     0,     0,     0,   116,   117,   118,
     119,    17,     0,    21,   266,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    22,
       0,     0,     0,    47,    48,    23,    24,    19,    49,    25,
       0,    26,    27,    28,     0,   -87,    29,     0,   -87,   -87,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,    33,     0,    34,    35,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    36,
     114,     0,    37,   116,   117,   118,   119,     0,     0,     0,
     197,     0,   198,    21,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    22,
       0,     0,     0,    47,    48,    23,    24,    19,    49,    25,
       0,    26,    27,    28,     0,   -87,    29,     0,     0,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,   -87,
       0,    33,     0,    34,    35,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    36,
     114,     0,    37,   116,   117,   118,   119,     0,     0,     0,
     255,     0,   198,    21,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    22,
       0,     0,     0,    47,    48,    23,    24,    19,    49,    25,
       0,    26,    27,    28,     0,   -87,    29,     0,     0,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,    33,     0,    34,    35,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    36,
     114,     0,    37,   116,   117,   118,   119,     0,     0,     0,
       0,     0,   254,    21,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    22,
       0,     0,     0,    47,    48,    23,    24,    19,    49,    25,
       0,    26,    27,    28,    21,     0,    29,     0,     0,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
      22,    33,     0,    34,    35,    21,    23,    24,    19,     0,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    36,
       0,    22,    37,   116,   117,   118,   119,    23,    24,    19,
     306,    25,     0,    26,    27,    28,     0,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,     0,
       0,     0,     0,    47,    48,     0,     0,     0,    49,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,    49,
       0,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,     0,     0,    16,
      49,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    16,   114,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,   114,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     0,
     114,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,   114,     0,     0,     0,     0,   129,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   279,
     114,     0,     0,     0,   115,   116,   117,   118,   119,    17,
       0,     0,     0,     0,     0,     0,     0,   116,   117,   118,
     119,    17,     0,     0,     0,     0,     0,     0,     0,   116,
     117,   118,   119,     0,     0,   158,     0,     0,     0,     0,
       0,   116,   117,   118,   119,     0,     0,   217,     0,     0,
       0,     0,     0,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,   118,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
     114,     0,     0,   116,   117,   118,   119,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      18,     5,   178,     5,   180,    13,    19,    30,    31,    32,
      25,    34,   189,    36,    23,    97,    98,    99,     6,   196,
      55,   103,    30,    25,    13,    14,    27,    25,    27,    18,
      55,    54,     7,     8,    59,    10,    11,    55,    13,    14,
      13,    14,    77,    18,    67,    73,    57,     0,    76,     1,
      61,    79,   106,    13,    14,    83,    84,    85,    18,    77,
      83,   109,    85,    33,    72,    17,    36,    37,    47,    13,
      14,    23,    24,    25,    18,    27,    71,    29,    30,    31,
      45,    46,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   106,    18,   103,   108,    84,    80,    81,    82,
     135,   105,   103,   105,   103,   106,   129,   284,   100,   106,
      33,    19,   130,   136,   103,   104,    55,   135,    57,   106,
      59,    33,    61,   108,    36,   207,   101,   102,   103,   104,
     108,    55,   155,   156,   157,    87,    88,    89,    90,    91,
      92,   101,   102,   103,   104,   100,   107,   182,   171,   101,
     102,    33,   106,   100,   106,   107,   106,   100,   110,    39,
      40,    41,    42,    43,   182,   107,    60,   108,   108,   107,
     178,   108,   180,    39,    33,    33,   101,   102,   103,   104,
      23,   204,   107,   108,    39,   110,   108,   106,    67,   107,
     213,   107,   215,   107,   107,   218,   107,    78,    34,    47,
      78,    77,   107,   238,    33,   100,    34,    33,    33,    33,
      49,    34,    33,   123,   107,    37,    34,   240,    33,    39,
     238,   244,    39,   246,   247,   268,    22,   262,   177,   237,
     130,   295,   267,    29,   300,   144,   195,   269,   261,    35,
     236,   176,   265,   276,   262,    -1,   281,   255,    -1,   267,
      -1,    47,    48,    49,    -1,   290,   279,   280,   293,   282,
      -1,    -1,    -1,   281,    -1,   288,    -1,    -1,    -1,    -1,
      -1,    -1,   290,   296,    -1,   293,   299,   312,    -1,    -1,
     303,   304,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,
      -1,    -1,   315,    -1,   312,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,   132,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    39,    -1,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    52,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    67,   191,    -1,    70,    -1,    -1,
     196,   197,   198,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    87,    88,    89,    90,    91,    92,
     216,    94,    95,    96,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,   106,   107,    -1,    -1,   110,    -1,     1,
      -1,    -1,    -1,     5,    -1,   241,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,   254,   255,
      -1,    23,    24,    25,    -1,    27,    -1,    29,    30,    31,
     266,    33,    34,    -1,    36,    37,    -1,    39,    -1,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,   284,    51,
      52,   287,    -1,     1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    67,    18,    -1,    70,    17,
     306,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      -1,    29,    30,    31,    -1,    87,    88,    89,    90,    91,
      92,     1,    94,    95,    96,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    17,   110,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   101,   102,    -1,   108,    -1,   106,    -1,
      -1,     5,   110,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    87,    88,    89,
      90,    91,    92,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,    17,
     110,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    67,
      18,    -1,    70,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,    -1,     1,   108,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    17,
      -1,    -1,    -1,   101,   102,    23,    24,    25,   106,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    67,
      18,    -1,    70,   101,   102,   103,   104,    -1,    -1,    -1,
     108,    -1,   110,     1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    17,
      -1,    -1,    -1,   101,   102,    23,    24,    25,   106,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    67,
      18,    -1,    70,   101,   102,   103,   104,    -1,    -1,    -1,
     108,    -1,   110,     1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    17,
      -1,    -1,    -1,   101,   102,    23,    24,    25,   106,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    67,
      18,    -1,    70,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,   110,     1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    17,
      -1,    -1,    -1,   101,   102,    23,    24,    25,   106,    27,
      -1,    29,    30,    31,     1,    -1,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      17,    49,    -1,    51,    52,     1,    23,    24,    25,    -1,
      27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    67,
      -1,    17,    70,   101,   102,   103,   104,    23,    24,    25,
     108,    27,    -1,    29,    30,    31,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,
      -1,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,     5,
     106,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     5,    18,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    35,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    35,
      18,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,   101,   102,   103,   104,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    59,   113,   159,   161,   162,   163,   165,    25,
     160,    57,    61,   158,   163,     0,     5,   105,   112,    25,
     118,     1,    17,    23,    24,    27,    29,    30,    31,    34,
      39,    41,    42,    49,    51,    52,    67,    70,    87,    88,
      89,    90,    91,    92,    94,    95,    96,   101,   102,   106,
     117,   118,   119,   122,   123,   125,   126,   127,   128,   129,
     130,   131,   132,   139,   140,   141,   143,   144,   151,   153,
     154,   164,   106,   109,   123,   143,   123,   112,   118,   112,
     112,    47,   112,   123,   112,    71,   106,   142,   142,   142,
     142,   142,   142,    27,   103,   106,   137,   138,   138,   138,
     123,   123,   123,   106,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    18,   100,   101,   102,   103,   104,
     112,   132,    33,   108,   115,   112,   118,   145,   146,    35,
     149,   132,   100,   106,   133,   112,   163,   112,    73,    76,
      79,    83,    84,    85,   114,   116,    23,   103,   136,   108,
     135,   110,   120,   121,   123,   124,   124,   124,   107,   124,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,    55,   114,    19,   100,
     108,   107,   112,   125,    33,   123,   123,   132,   112,   106,
     106,   100,   100,   116,   107,   108,   108,   108,   110,   112,
     112,   112,   107,   112,   160,   115,   146,    77,   123,   148,
     150,   146,    60,   157,   132,    39,   108,   107,   134,    33,
      33,   121,   123,    80,    81,    82,   123,    23,   137,   121,
     124,   123,   112,   123,   124,   147,   108,   106,   112,    33,
      36,    37,   152,   112,   123,   112,    39,    67,   107,   107,
     107,   107,   107,   107,   110,   108,    78,    78,   150,   118,
     132,    34,   112,   123,    33,    36,   108,   112,    47,   155,
     156,   112,   112,   123,   118,   107,    33,   112,   132,    35,
      34,   112,   123,   132,   133,   156,    33,   100,   158,    33,
     112,   112,   132,   112,    33,   121,    49,   123,   112,    34,
     132,    33,   132,    39,   134,   112,   108,   112,   152,    34,
      33,   112,   112,   123,   112,    39,   132,   112
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
				update_pos((yyval));
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 58 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Semicolon, ";" };
				update_pos((yyval));
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 63 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
				update_pos((yyval));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 73 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(in)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 83 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(out)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = false;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 94 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.reference = true;
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = false;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 104 "for90.y"
    {
				/* if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' */
				/* if is array reduce immediately and goto `var_def` */
				/* do not parse array slices here because it can be dificult */
				ParseNode * newnode = new ParseNode();
				ParseNode * dimen = new ParseNode((yyvsp[(3) - (4)]));
				newnode->addchild(dimen); // def slice
				int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
				for (sliceid = 0; sliceid < dimen->child.size(); sliceid++)
				{
					sprintf(codegen_buf, "(%s, %s)"
						/* from, to */
						, dimen->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
						, dimen->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
					dimen->child[sliceid]->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };
				}
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = dimen;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 126 "for90.y"
    {
				/* define array like a(1) */
				ParseNode * newnode = new ParseNode();
				ParseNode * dimen = new ParseNode();
				ParseNode * slice = new ParseNode();
				ParseNode * exp = new ParseNode();
				exp->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "1" };
				slice->addchild(exp); // slice from 1
				sprintf(codegen_buf, "%s", /* from 1, to */(yyvsp[(3) - (4)]).fs.CurrentTerm.what.c_str());
				slice->addchild(new ParseNode((yyvsp[(3) - (4)]))); // slice to
				dimen->addchild(slice);
				newnode->addchild(dimen); // def slice

				int sliceid = 0; /* only 1 dimension */
				sprintf(codegen_buf, "(%s, %s)"
					/* from 1, to */
					, dimen->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
					, dimen->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
				dimen->child[sliceid]->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, string(codegen_buf) };

				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.slice = dimen;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 152 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.optional = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 161 "for90.y"
    {
				/* const value */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // const
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.constant = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 171 "for90.y"
    {
				// do nothing because we use std::string
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 175 "for90.y"
    {
				int kind;
				sscanf((yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str(), "%d", &kind);
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // kind
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.kind = kind;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 187 "for90.y"
    {
				ParseNode * newnode = new ParseNode((yyvsp[(1) - (2)]));
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 193 "for90.y"
    {				
				ParseNode * newnode = new ParseNode();
				ParseNode * variable_iden = & (yyvsp[(3) - (3)]);
				ParseNode & variable_iden_1 = (yyvsp[(2) - (3)]);
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				newnode->attr = variable_iden_1.attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(variable_iden->attr);
				new_a->merge(*var_a);
				// TODO do not add child
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 209 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 218 "for90.y"
    {
				ParseNode * newnode = new ParseNode((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 224 "for90.y"
    {				
				ParseNode * newnode = new ParseNode();
				ParseNode * variable_iden = & (yyvsp[(2) - (2)]);
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				newnode->attr = (yyvsp[(1) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(variable_iden->attr);
				new_a->merge(*var_a);
				// TODO do not add child
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 239 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; 
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 248 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // float number
				(yyval) = *newnode;
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 255 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // int number
				(yyval) = *newnode;
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 261 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, modified }; // string
				(yyval) = *newnode;
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 269 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "true" }; // bool true
				(yyval) = *newnode;
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 275 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "false" }; // bool false
				(yyval) = *newnode;
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 281 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				newnode->fs.CurrentTerm = Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") "}; // complex
				(yyval) = *newnode;
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 293 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // variant
				(yyval) = *newnode;
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 300 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 307 "for90.y"
    {
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				ParseNode & lb = (yyvsp[(1) - (3)]);
				ParseNode & ub = (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode(lb)); // lower bound
				newnode->addchild(new ParseNode(ub)); // upper bound
				(yyval) = *newnode;
				update_pos((yyval));
				/*
				*/			
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 322 "for90.y"
    {
				/* arr[from : to : step] */
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

  case 35:
/* Line 1792 of yacc.c  */
#line 334 "for90.y"
    {
				/* arr[from : to : step] */
				ParseNode * newnode = new ParseNode();
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "-1" };
					ParseNode * ub = new ParseNode();
					ub->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "-1" };
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SLICE, "" };
				newnode->addchild(new ParseNode(*lb)); // lower bound
				newnode->addchild(new ParseNode(*ub)); // upper bound
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 349 "for90.y"
    {
				/* 1d array */
				/* arr[from : to] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				ParseNode & slice = (yyvsp[(1) - (1)]);
				if (slice.child.size() == 1) {
					slice.child.push_back(nullptr);
					slice.child[1] = slice.child[0];
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "1" };
					slice.child[0] = lb;
				}
				newnode->addchild(new ParseNode(slice)); // only 1 slice
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 368 "for90.y"
    {
				/* multi dimension array */
				/* arr[from:to, from:to, ...] */
				ParseNode * newnode = new ParseNode();
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DIMENSLICE, "" };
				ParseNode & slice = (yyvsp[(1) - (3)]);
				if (slice.child.size() == 1) {
					slice.child.push_back(nullptr);
					slice.child[1] = slice.child[0];
					ParseNode * lb = new ParseNode();
					lb->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, "1" };
					slice.child[0] = lb;
				}
				newnode->addchild(new ParseNode(slice)); // slice
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // dimen_slice
				// attention flattern_bin
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 390 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 402 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(1) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s, %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(argtable)); // argtable
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 418 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode * newnode = new ParseNode();
				ParseNode & callable = (yyvsp[(1) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
#ifndef LAZY_GEN
				string name;
				string x;
				if (funcname_map.find(callable.fs.CurrentTerm.what) != funcname_map.end()) {
					name = funcname_map.at(callable.fs.CurrentTerm.what);
				}
				else {
					name = callable.fs.CurrentTerm.what;
				}
				if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_DIMENSLICE) {
					sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  string(codegen_buf) };
				}
				else {
					x += name;
					x += "(";
					x += argtable.fs.CurrentTerm.what;
					x += ")";
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  x };
				}
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(callable)); // function/array name
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 452 "for90.y"
    {
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
				ParseNode & function_array = (yyvsp[(1) - (1)]);
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION,  function_array.fs.CurrentTerm.what };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(function_array)); // function_array
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 466 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (3)]);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "( %s )", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(exp));
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 480 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s + %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // +
				newnode->addchild(new ParseNode(exp2)); // tight operand exp
				(yyval) = *newnode;
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 493 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s - %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // -
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 506 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s * %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // *
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 519 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s / %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // /
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 532 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "power(%s, %s)", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // **
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 545 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				sprintf(codegen_buf, "(-%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // (-)
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 557 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				sprintf(codegen_buf, "%s", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // (+)
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 569 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 582 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 595 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 608 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 621 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s && %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // &&
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 634 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s || %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ||
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 647 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				sprintf(codegen_buf, "!(%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // !
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 659 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s > %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 672 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s >= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 685 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s <= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 698 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s < %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 711 "for90.y"
    { 
				// 
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 717 "for90.y"
    {
				// may cause reduction-reduction conflict when use `variable` instead of `callable`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 725 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				ParseNode & dimen_slice = (yyvsp[(1) - (1)]);
				bool isdimen = false;
				int sliceid = 0; /* if the array has 2 dimensions, sliceid is 0..1 */
				dimen_slice.fs.CurrentTerm.what = "";
				for (sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
				{
					if (sliceid != 0) {
						dimen_slice.fs.CurrentTerm.what += ", ";
					}
					if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
						// dimen_slice
						isdimen = true;
						newnode->addchild(new ParseNode(*dimen_slice.child[sliceid]));
						sprintf(codegen_buf, "%s, %s"
							/* from, to */
							, dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str()
							, dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
					}
					else {
						// exp
						isdimen = false;
						newnode->addchild(new ParseNode(*dimen_slice.child[sliceid]));
						sprintf(codegen_buf, "%s", dimen_slice.child[sliceid]->fs.CurrentTerm.what.c_str());
					}
					dimen_slice.fs.CurrentTerm.what += codegen_buf;
				}
				if (isdimen) {
					//sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
					sprintf(codegen_buf, "%%s.slice(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_DIMENSLICE, string(codegen_buf) };
				}
				else {
					//sprintf(codegen_buf, "%%s(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
					sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
				}
#endif // !LAZY_GEN
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 769 "for90.y"
    {
				// TODO : argtable can also be empty
				ParseNode * newnode = new ParseNode();
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, "" };
#endif // !LAZY_GEN
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 780 "for90.y"
    {
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(1) - (2)]);
				//(crlf.fs.CurrentTerm.token == TokenMeta::CRLF ? ";" : "")
				sprintf(codegen_buf, "%s ;", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp)); // exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 797 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & var_def = (yyvsp[(1) - (2)]);
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s ", var_def.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(var_def)); // var_def
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 814 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & let = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s ;", let.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(let)); // let
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 824 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & jmp = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s ;", jmp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(jmp)); // jmp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 849 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s = %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::Let, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // =
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 864 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, "" };
				// dummy stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 873 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s\n", stmt.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 883 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = (yyvsp[(1) - (2)]);
				ParseNode & suite = (yyvsp[(2) - (2)]);
				sprintf(codegen_buf, "%s\n%s", stmt.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				newnode->addchild(new ParseNode(suite)); // suite
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 896 "for90.y"
    {
				/* suite can be empty but stmt can not */
				ParseNode * newnode = new ParseNode();
				FlexState fs; fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
				ParseNode & stmt = ParseNode(fs, newnode, nullptr);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, "\n" };
				newnode->addchild(new ParseNode(stmt)); // stmt
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 915 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				update_pos((yyval));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 920 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
				update_pos((yyval));
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 925 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
				update_pos((yyval));
			}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 930 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
				update_pos((yyval));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 938 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & _optional_device = (yyvsp[(2) - (5)]);
				ParseNode & _optional_formatter = (yyvsp[(4) - (5)]);
				/* target code of io_info depend on context, can be either iostream/cstdio */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode(_optional_device)); // _optional_device
				newnode->addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 950 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode _optional_device = ParseNode();
				_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				ParseNode _optional_formatter = (yyvsp[(1) - (2)]);
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode(_optional_device)); // _optional_device
				newnode->addchild(new ParseNode(_optional_formatter)); // _optional_formatter
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 965 "for90.y"
    {
				// brace is forced
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = (yyvsp[(2) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				ParseNode * argtbl = &argtable;
				ParseNode * formatter = io_info.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					sprintf(codegen_buf, "printf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
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
							coutcode += " << ";
							coutcode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					coutcode += " << endl;";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1002 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = (yyvsp[(2) - (4)]);
					//ParseNode & io_info = ParseNode();	
					//ParseNode _optional_device = ParseNode();
					//_optional_device.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
					//ParseNode _optional_formatter = $2;
					//io_info.fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
					//io_info.addchild(new ParseNode(_optional_device));
					//io_info.addchild(new ParseNode(_optional_formatter)); 
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				ParseNode * argtbl = &argtable;
				ParseNode * formatter = io_info.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					sprintf(codegen_buf, "printf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
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
							coutcode += " << ";
							coutcode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					coutcode += " << endl;";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, coutcode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1046 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = (yyvsp[(2) - (4)]);
				ParseNode & argtable = (yyvsp[(3) - (4)]);
				ParseNode * argtbl = &argtable;
				ParseNode * formatter = io_info.child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					string pointer_to;
					for (int i = 0; i < argtbl->child.size(); i++)
					{
						if (i > 0) {
							pointer_to += ",";
						}
						pointer_to += "&";
						pointer_to += argtbl->child[i]->fs.CurrentTerm.what;
					}
					argtbl = argtbl->child[1];
					sprintf(codegen_buf, "scanf(\"%s\", %s) ;", parse_ioformatter(fmt).c_str(), pointer_to.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				}
				else {
					/* NT_AUTOFORMATTER */
					string cincode = "cin";
					/* enumerate argtable */
					// TODO the while loop is wrong, there is need for while loop. ref: var_def code
					//while (argtbl->child.size() == 2 && argtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE) {
						// for all non-flatterned argtable
						for (int i = 0; i < argtbl->child.size(); i++)
						{
							// for each variable in flatterned argtable
							cincode += " >> ";
							cincode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					cincode += ";";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, cincode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1092 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval));
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1097 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				newnode->attr = new VariableDescAttr(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1106 "for90.y"
    {
				// now translated in pre_map
				//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1118 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1128 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1138 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 1148 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1158 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				ParseNode * newnode = &(yyval);
				newnode->attr = (yyvsp[(2) - (2)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>((yyvsp[(2) - (2)]).attr);
				new_a->merge(*var_a);
				update_pos((yyval));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 1170 "for90.y"
    {
				/* array decl */
				string arr_decl = ""; string var_decl = ""; bool do_arr = false;
				ParseNode * newnode = new ParseNode();
				ParseNode & type_spec = (yyvsp[(1) - (4)]);
				ParseNode & dummy_variable_iden = (yyvsp[(2) - (4)]);
				ParseNode * ty = new ParseNode(type_spec); // type
				VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(dummy_variable_iden.attr);
				ParseNode * slice = vardescattr->desc.slice;
				newnode->addchild(ty); // type
				// specify type
				/* merge type_spec and dummy_variable_iden attr */
				VariableDescAttr * ty_a = dynamic_cast<VariableDescAttr *>(type_spec.attr);
				vardescattr->merge(*ty_a);
				if (vardescattr->desc.kind != 0) {
					if (type_spec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
						if (vardescattr->desc.kind == 1) {
							ty->fs.CurrentTerm.what = "char";
						}
						else if (vardescattr->desc.kind == 2) {
							ty->fs.CurrentTerm.what = "int";
						}
						else if (vardescattr->desc.kind == 4) {
							ty->fs.CurrentTerm.what = "int";
						}
						else if (vardescattr->desc.kind == 8) {
							ty->fs.CurrentTerm.what = "long long";
						}
					}
					else if (type_spec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
						if (vardescattr->desc.kind == 1) {
							ty->fs.CurrentTerm.what = "float";
						}
						else if (vardescattr->desc.kind == 2) {
							ty->fs.CurrentTerm.what = "double";
						}
						else if (vardescattr->desc.kind == 4) {
							ty->fs.CurrentTerm.what = "double";
						}
						else if (vardescattr->desc.kind == 8) {
							ty->fs.CurrentTerm.what = "long double";
						}
					}
				}
				if (slice == nullptr) {
					// slice == nullptr if this is not array
					/* must assure no ParseNode * is nullptr */
					slice = new ParseNode();
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VOID, "" };
				}
				else {
					do_arr = true;
				}
				newnode->addchild(slice); 
				ParseNode * pn = new ParseNode((yyvsp[(4) - (4)])); // paramtable
				newnode->addchild(pn); // paramtable
				if (do_arr)
				{
					// ARRAY
					/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
					/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
#define USE_LOOP
						for (int i = 0; i < pn->child.size(); i++)
						{
							// for each variable in flatterned paramtable
							int sliceid = 0;
							sprintf(codegen_buf, "forarray<%s>", ty->fs.CurrentTerm.what.c_str());
							string type_str(codegen_buf);
							// init high dimension array
							/* though using for-loop to init a high-dimension array is verbose comparing to using constructors, i use this form because it is more clear and it can remind users of the cost of using a high dimension array */
							vector<string> this_major; /* if you want to set value of a(i0)(i1)(i2) then this major is a(i0)(i1) */
							this_major.push_back(pn->child[i]->child[0]->fs.CurrentTerm.what /* array name */);
							for (int i = 1; i < slice->child.size(); i++)
							{
								sprintf(codegen_buf, "%s(i%d)", this_major.back().c_str(), i - 1);
								this_major.push_back(string(codegen_buf));
							}
							for (sliceid = slice->child.size() - 2; sliceid >= 0 ; sliceid--)
							{
								string prev_type_str = type_str;
								sprintf(codegen_buf, "forarray< %s >", type_str.c_str());
								type_str = string(codegen_buf);
								sprintf(codegen_buf, "for(int i%d = %s; i%d < %s; i%d++){\n\t%s(i%d) = %s(%s, %s + 1);\n%s\n}\n" /* NOTE fortran is [lower_bound, upper_bound] cpp is [lower_bound, upper_bound) */
									, sliceid, slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), sliceid, slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), sliceid
									, this_major[sliceid].c_str(), sliceid, prev_type_str.c_str(), slice->child[sliceid + 1]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[sliceid + 1]->child[1]->fs.CurrentTerm.what.c_str()
									, sliceid + 1 == slice->child.size() - 1 ? "" : tabber(slice->child[sliceid + 1]->fs.CurrentTerm.what).c_str());
								prev_type_str = type_str;
								slice->child[sliceid]->fs.CurrentTerm.what = string(codegen_buf);
							}
							// use it in fucntion_decl
							string var_pattern;
							if (vardescattr->desc.reference) {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s & %s";
								}
								else {
									var_pattern = "%s & %s";
								}
							}
							else {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s %s";
								}
								else {
									var_pattern = "%s %s";
								}
							}
							// no desc if var_def is not in paramtable
							sprintf(codegen_buf, "%s %s(%s, %s + 1);\n" , type_str.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* array name */
								, slice->child[0]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[0]->child[1]->fs.CurrentTerm.what.c_str() /* slice from to */);
							arr_decl += codegen_buf;
							/* set initial value */
							if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
							{
								for (int abid = 0; abid < pn->child[i]->child[1]->child.size(); abid++)
								{
									ParseNode * ab = pn->child[i]->child[1]->child[abid];
									if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
										std::string vec_size = "std::vector<int>{", vec_lb = "std::vector<int>{";
										for (int sliceid = 0; sliceid < slice->child.size(); sliceid++)
										{
											if (sliceid != 0) {
												vec_lb += ",";
												vec_size += ",";
											}
											vec_lb += slice->child[sliceid]->child[0]->fs.CurrentTerm.what;
											int lb, ub;
											sscanf(slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), "%d", &lb);
											sscanf(slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), "%d", &ub);
											sprintf(codegen_buf, "%d", ub - lb + 1);
											vec_size += codegen_buf;
										}
										vec_size += "}", vec_lb += "}";
										sprintf(codegen_buf, ab->fs.CurrentTerm.what.c_str() /* sth like "init_for1array(%%s, %%s, %%s, %s)\n" */
											, pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* variable name */
											, vec_lb.c_str()
											, vec_size.c_str());
									}
									else if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_EXP) {
										string formatter = (ab->fs.CurrentTerm.what + ";\n");
										sprintf(codegen_buf, formatter.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
									}
									else {
										sprintf(codegen_buf, "");
									}
								}
							}
							else {
								sprintf(codegen_buf, "");
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
					// SCALAR
					sprintf(codegen_buf, "%s ", ty->fs.CurrentTerm.what.c_str());
					var_decl += string(codegen_buf);
					bool hitted = false; // 是否至少有一个变量，因为有的变量定义可能是函数的声明，这在c++规范是不允许的，所以可能出现空int，空逗号的情况。
					/* enumerate paramtable */
					do {
						// for all non-flatterned paramtable
						for (int i = 0; i < pn->child.size(); i++)
						{
							ParseNode * this_variable = pn->child[i];
							// skip if it is a function
							// TODO no module currently
							if (try_get_function("", this_variable->fs.CurrentTerm.what)) {
								continue;
							}
							if (hitted) {
								var_decl += ", ";
							}
							hitted = true;
							// use it in fucntion_decl
							string var_pattern;
							if (vardescattr->desc.reference) {
								if (vardescattr->desc.constant) {
									var_pattern = "const & %s";
								}
								else {
									var_pattern = "& %s";
								}
							}
							else {
								if (vardescattr->desc.constant) {
									var_pattern = "const %s";
								}
								else {
									var_pattern = "%s";
								}
							}
							// no desc if var_def is not in paramtable
							sprintf(codegen_buf, "%s" , this_variable->child[0]->fs.CurrentTerm.what.c_str());

							var_decl += codegen_buf;
							/* initial value */
							if (this_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
								/* if initial value is not dummy but `exp` */
								var_decl += " = ";
								var_decl += this_variable->child[1]->fs.CurrentTerm.what;
							}
							/* desc */
							this_variable->attr = vardescattr->clone();
						}
						if (pn->child.size() >= 2)
						{
							/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
							/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
							pn = pn->child[1];
						}
					} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					var_decl += ";";
					if (!hitted) {
						// all function declarations
						var_decl = "";
					}
					
#ifndef LAZY_GEN
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
#endif // !LAZY_GEN
				} // end if

				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 1407 "for90.y"
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

  case 113:
/* Line 1792 of yacc.c  */
#line 1424 "for90.y"
    {
				/* initial value is required in parse tree because it can be an non-terminal `exp` */
				/* non-array initial values */
				ParseNode * newnode = new ParseNode();
				sprintf(codegen_buf, "%s = %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
					ParseNode * variablenode = new ParseNode();
					sprintf(codegen_buf, "%s" , (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
					variablenode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEINITIAL, string(codegen_buf) };
					variablenode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // variable
					variablenode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // initial
					newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1441 "for90.y"
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
					variablenode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // variable
					variablenode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // initial(array_builder)
				newnode->addchild(variablenode);
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1459 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1464 "for90.y"
    {
				ParseNode * newnode = new ParseNode(); 
				newnode->addchild((yyvsp[(1) - (3)]).child[0]); // kwargtable
				sprintf(codegen_buf, "%s, %s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, string(codegen_buf) };
				ParseNode & pn = (yyvsp[(3) - (3)]);
				for (int i = 0; i < pn.child.size(); i++)
				{
					newnode->addchild(new ParseNode(*pn.child[i])); // paramtable
				}
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1478 "for90.y"
    {
				/* no params */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, "" };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1487 "for90.y"
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

  case 119:
/* Line 1792 of yacc.c  */
#line 1499 "for90.y"
    {
				/* give initial value */
				/* NOTE that `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, NOW we merge rules */
				/* NOTE fortran use a 1d list to initialize a 2d(or higher) array, however, contrary to c++ and most other language does, it store them in a **conlumn - first order**. for a 2d array, it means you a order of a(1)(1)->a(2)(1)->a(lb_1)(1)->a(1)(2) */
				ParseNode * newnode = new ParseNode();
				ParseNode & argtable = (yyvsp[(2) - (3)]); 
				/* for1array<_Container_value_type> & farr, const std::vector<int> & lower_bound
				, const std::vector<int> & size, const std::vector<T> & values */
				sprintf(codegen_buf, "init_for1array(%%s, %%s, %%s, %s);\n", /* value */ argtable.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_VALUE, string(codegen_buf) };
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1514 "for90.y"
    {
				/* give generate stmt */
				ParseNode * newnode = new ParseNode();
				ParseNode * exp = (yyvsp[(2) - (3)]).child[0];
				ParseNode * index = (yyvsp[(2) - (3)]).child[1];
				ParseNode * from = (yyvsp[(2) - (3)]).child[2];
				ParseNode * to = (yyvsp[(2) - (3)]).child[3];
				sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s;\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
					, index->fs.CurrentTerm.what.c_str(), to->fs.CurrentTerm.what.c_str() /* exp_to */, index->fs.CurrentTerm.what.c_str() /* index variable inc */
					, "\t%s" /* array variable name */, index->fs.CurrentTerm.what.c_str() /* index variable */, exp->fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER_EXP, string(codegen_buf) };
				newnode->addchild(new ParseNode(*exp)); // exp
				newnode->addchild(new ParseNode(*index)); // index variable
				newnode->addchild(new ParseNode(*from)); // exp_from
				newnode->addchild(new ParseNode(*to)); // exp_to
				(yyval) = *newnode;
				update_pos((yyval));
				// TODO 
				/* rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule*/
				/* note that this two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict */
				/* note either that `variable '(' dimen_slice ')'` is an `exp` */
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1539 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // array_builder_elem
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1548 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // array_builder_elem
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // array_builder
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (3)]).fs.CurrentTerm.what.c_str(), (yyvsp[(3) - (3)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, string(codegen_buf) };
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1560 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (8)]);
				ParseNode & suite_true = (yyvsp[(5) - (8)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (8)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1576 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & suite_else = (yyvsp[(8) - (11)]); suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\nelse {\n %s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (11)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode((yyvsp[(6) - (11)]))); // else
				newnode->addchild(new ParseNode(suite_else)); // else-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1595 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (9)]);
				ParseNode & suite_true = (yyvsp[(5) - (9)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = (yyvsp[(6) - (9)]);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (9)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // recursive elseif-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1613 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (12)]);
				ParseNode & suite_true = (yyvsp[(5) - (12)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = (yyvsp[(6) - (12)]);
				ParseNode & suite_else = (yyvsp[(9) - (12)]); suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
				
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (12)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // recursive elseif-stmt
				newnode->addchild(new ParseNode(suite_else)); // else-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1634 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) %s", exp.fs.CurrentTerm.what.c_str(), stmt_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (4)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(stmt_true)); // stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1650 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if(%s) {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (5)]))); // elseif
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1667 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "else if{\n%s}\n%s", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ELSEIF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (6)]))); // elseif
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // another elseif-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1685 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & suite = (yyvsp[(3) - (6)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "do{\n%s}", suite.fs.CurrentTerm.what.c_str());
#endif // !LAZY_GEN

				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
				newnode->addchild(new ParseNode((yyvsp[(1) - (6)]))); // do
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1699 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & variable = (yyvsp[(2) - (11)]);
				ParseNode & exp_from = (yyvsp[(4) - (11)]);
				ParseNode & exp_to = (yyvsp[(6) - (11)]);
				ParseNode & suite = (yyvsp[(8) - (11)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s <= %s; %s++){\n%s}", variable.fs.CurrentTerm.what.c_str(), exp_from.fs.CurrentTerm.what.c_str()
					, variable.fs.CurrentTerm.what.c_str(), exp_to.fs.CurrentTerm.what.c_str()
					, variable.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (11)]))); // do
				newnode->addchild(new ParseNode(variable)); // varname
				newnode->addchild(new ParseNode(exp_from)); // begin
				newnode->addchild(new ParseNode(exp_to)); // end
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1721 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				(yyvsp[(9) - (13)]).fs.CurrentTerm.what = tabber((yyvsp[(9) - (13)]).fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s <= %s; %s+=%s){\n%s}", (yyvsp[(2) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(4) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(6) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(8) - (13)]).fs.CurrentTerm.what.c_str(), (yyvsp[(9) - (13)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (13)]))); // do
				newnode->addchild(new ParseNode((yyvsp[(2) - (13)]))); // varname
				newnode->addchild(new ParseNode((yyvsp[(4) - (13)]))); // begin
				newnode->addchild(new ParseNode((yyvsp[(6) - (13)]))); // end
				newnode->addchild(new ParseNode((yyvsp[(8) - (13)]))); // step
				newnode->addchild(new ParseNode((yyvsp[(9) - (13)]))); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1739 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite = (yyvsp[(4) - (7)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "while(%s){\n%s}", exp.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::While, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (7)]))); // while
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1755 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & select = (yyvsp[(1) - (10)]);
				ParseNode & exp = (yyvsp[(4) - (10)]);
				ParseNode & case_stmt = (yyvsp[(7) - (10)]);

#ifndef LAZY_GEN
				string codegen = "";
				for (int i = 0; i < case_stmt.child.size(); i++)
				{
					ParseNode & case_stmt_elem = *case_stmt.child[i];
					ParseNode & dimen_slice = *case_stmt_elem.child[1];
					/*
						0 -- case
						1 -- dimen_slice
						2 -- stmt(case body)
					*/
					if (dimen_slice.fs.CurrentTerm.token == TokenMeta::NT_DIMENSLICE) {
						// NT_DIMENSLICE
						string dsstr;
						for (int sliceid = 0; sliceid < dimen_slice.child.size(); sliceid++)
						{
							if (sliceid == 0) {
								sprintf(codegen_buf, "(%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
							}
							else {
								sprintf(codegen_buf, " || (%s >= %s && %s < %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[sliceid]->child[1]->fs.CurrentTerm.what.c_str());
							}
							dsstr += string(codegen_buf);
						}
						if (i == 0) {
							sprintf(codegen_buf, "if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
						else {
							sprintf(codegen_buf, "else if(%s){\n%s}\n", dsstr.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
					}
					else {
						// NT_ARGTABLE_PURE
						string choice = "";
						if (i == 0) {
							choice = "if(";
							sprintf(codegen_buf, "if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[0]->fs.CurrentTerm.what.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
						else {
							choice = "else if(";
							sprintf(codegen_buf, "else if(%s == %s){\n%s}\n", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[0]->fs.CurrentTerm.what.c_str(), case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						}
						for (int j = 0; j < dimen_slice.child.size(); j++)
						{
							if (j == 0) {
								sprintf(codegen_buf, "%s == %s", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[j]->fs.CurrentTerm.what.c_str());
							}
							else {
								sprintf(codegen_buf, "|| (%s == %s)", exp.fs.CurrentTerm.what.c_str(), dimen_slice.child[j]->fs.CurrentTerm.what.c_str());
							}
							choice += codegen_buf;
						}
						sprintf(codegen_buf, "){\n%s}\n", case_stmt_elem.child[2]->fs.CurrentTerm.what.c_str());
						choice += codegen_buf;
						sprintf(codegen_buf, "%s", choice.c_str());
					}
					codegen += codegen_buf;
				}
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SELECT, codegen };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(select)); // select
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(case_stmt)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1828 "for90.y"
    {
				// one case
				ParseNode * newnode = new ParseNode();
				ParseNode & case_head = (yyvsp[(1) - (6)]);
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASE, "" };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(case_head)); // case
				newnode->addchild(new ParseNode(dimen_slice)); // dimen_slice
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1844 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode->addchild(new ParseNode(case_stmt_elem)); // case_stmt_elem
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1853 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode * newnode = new ParseNode(case_stmt);
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode->addchild(new ParseNode(case_stmt_elem), false); // case_stmt_elem
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1864 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1868 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, "" }; // return nothing
				(yyval) = *newnode;
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1878 "for90.y"
    {
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode * newnode = new ParseNode();
				// all params in paramtable of function declare (var_name, var_type, ParseNode*)
				vector<tuple<string, string, ParseNode *>> param_name_typename;
				vector<ParseNode *> param_definition; // all variables declared in this function
				ParseNode & variable_function = (yyvsp[(3) - (12)]); // function name
				/* enumerate paramtable */
				ParseNode & paramtable = (yyvsp[(5) - (12)]);
				ParseNode * prmtbl = &paramtable; // iterate the paramtable
				ParseNode & variable_result = (yyvsp[(7) - (12)]); // result variable
				ParseNode & suite = (yyvsp[(9) - (12)]);

				bool is_subroutine = variable_result.fs.CurrentTerm.what == "";

				// log function in function table
				add_function("", variable_function.fs.CurrentTerm.what, nullptr);

				do {
					// for all non-flatterned paramtable
					for (int i = 0; i < prmtbl->child.size(); i++)
					{
						// for each variable in flatterned paramtable
						param_name_typename.push_back(make_tuple(prmtbl->child[i]->fs.CurrentTerm.what, "void", nullptr)); // refer to function suite and determine type of params
					}
					if (prmtbl->child.size() >= 2)
					{
						/* if prmtbl->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
						/* if the paramtable is not flatterned prmtbl->child[1] is a right-recursive paramtable node */
						prmtbl = prmtbl->child[1];
					}
				} while (prmtbl->child.size() == 2 && prmtbl->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
				/* result variable */
				// if subroutine get tuple ("", "void")
				param_name_typename.push_back(make_tuple(variable_result.fs.CurrentTerm.what, "void", nullptr));
				/* find out all var_def nodes */
				for (int i = 0; i < suite.child.size(); i++)
				{
					ParseNode * stmti = suite.child[i];
					/* suite.child[i] => stmt */ 
					/*  REF stmt for why stmt is a node always with 1 child(except for dummy stmt) */
					if (stmti->child.size() == 1 && stmti->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE) {
						/* stmti->child[0] => var_def */
						/* from pn=stmti->child[0].child[0] is typename */
						/* from pn=stmti->child[0].child[1] is dimen_slice */
						/* from pn=stmti->child[0].child[2] is all variables of this type */
						ParseNode * pn = stmti->child[0]->child[2];
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
					string varname = get<0>(param_name_typename[i]);
					for (int j = 0; j < param_definition.size(); j++)
					{
						ParseNode * varname_node = param_definition[j];
						if (varname_node->fs.CurrentTerm.what == varname) {
							//	father		NT_VARIABLEINITIAL (variable_name, variable_initial_value)
							//	father * 2	NT_PARAMTABLE
							//	father * 3	NT_VARIABLEDEFINE var_def
							//  param_name_typename[i] = tuple<name, type, ParseNode *>
							get<1>(param_name_typename[i]) = varname_node->father->father->father->child[0]->fs.CurrentTerm.what;
							get<2>(param_name_typename[i]) = varname_node->father;
							/* `delete` ParseNode except return value */
							if (i != param_name_typename.size() - 1) {
								varname_node->father->fs.CurrentTerm.token = TokenMeta::NT_DECLAREDVARIABLE;
							}
						}
					}
				}

				/* generate new paramtable with type */
				string argtblstr;
				for (int i = 0; i < param_name_typename.size() - 1 /* exclude YY_RESULT(return value) */; i++)
				{
					if(i != 0)
						argtblstr += ", ";
					VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>( get<2>(param_name_typename[i])->attr );
					if (vardescattr != nullptr)
					{
						if (vardescattr->desc.constant) {
							argtblstr += "const ";
						}
						else {
						}
					}
					argtblstr += get<1>(param_name_typename[i]);
					argtblstr += " ";
					if (vardescattr != nullptr)
					{
						if (vardescattr->desc.reference) {
							argtblstr += "& ";
						}
						else {
						}
					}
					argtblstr += get<0>(param_name_typename[i]);
				}

				/* add type infomation to paramtable ParseNodes  */
				ParseNode * newpt; // paramtable is raw for90 paramtable without type
				// TODO This is optional so i decide not to implement currently
				/* generate new return with type */
				ParseNode * newrt; // variable_result is raw for90 return without type
				// TODO This is optional so i decide not to implement currently
				
				/* re-generated codes of suite */
				string newsuitestr; // suite is raw for90 suite without type
				ParseNode * oldsuite = &suite;
				for (int i = 0; i < oldsuite->child.size(); i++)
				{
					if (oldsuite->child[i]->child.size() > 0 && oldsuite->child[i]->child[0]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEDEFINE)
					{
						// this code is similar to `find out all var_def nodes` code
						//ParseNode * pn = oldsuite->child[0]->child[1];
						ParseNode * typeinfo = oldsuite->child[i]->child[0]->child[0];
						ParseNode * pn = oldsuite->child[i]->child[0]->child[2];
						do {
							// for all non-flatterned paramtable
							for (int j = 0; j < pn->child.size(); j++)
							{
								// for each variable in flatterned paramtable
								/* pn->child[i] is varname with initial value */
								/* pn->child[i]->child[0] is varname string */
								if (pn->child[j]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIAL) {
									//newsuitestr += oldsuite->child[i]->child[0]->fs.CurrentTerm.what; // deprecated THIS IS NT_VARIABLEDEFINE, but different variables can be different
									newsuitestr += typeinfo->fs.CurrentTerm.what;
									newsuitestr += " ";
									newsuitestr += pn->child[j]->child[0]->fs.CurrentTerm.what;
									if (pn->child[j]->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
										newsuitestr += " = ";
										newsuitestr += pn->child[j]->child[1]->fs.CurrentTerm.what;
									}
									newsuitestr += " ;\n";
								}
							}
							if (pn->child.size() >= 2)
							{
								/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
								/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
								pn = pn->child[1];
							}
						} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
					}
					else {
						newsuitestr += oldsuite->child[i]->fs.CurrentTerm.what;
						newsuitestr += '\n';
					}
				}
				// update oldsuite->fs.CurrentTerm.what
				oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
				/* generate function ParseTree */
				newnode->addchild(new ParseNode((yyvsp[(2) - (12)]))); // function
				newnode->addchild(new ParseNode(variable_function)); // function name
				// argtable
				// TODO 
				// return value
				newnode->addchild(new ParseNode(suite)); // trimed suite

				sprintf(codegen_buf, "%s %s(%s)\n{%s\treturn %s;\n}"
					, get<1>(param_name_typename[param_name_typename.size()-1]).c_str() // return value type, "void" if subroutine
					, variable_function.fs.CurrentTerm.what.c_str() // function name
					, argtblstr.c_str() // argtable
					, oldsuite->fs.CurrentTerm.what.c_str() // code
					, (is_subroutine? "" :variable_result.fs.CurrentTerm.what.c_str()) // add return stmt if not function
				);
				/* generate function code */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 2071 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(4) - (8)]))); //suite
				sprintf(codegen_buf, "int main()\n{%s\treturn 0;\n}", tabber((yyvsp[(4) - (8)]).fs.CurrentTerm.what).c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				(yyval) = *newnode;
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 2081 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 2087 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 2094 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				(yyval) = *newnode;
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 2102 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (2)]))); // wrapper
				newnode->addchild(new ParseNode((yyvsp[(2) - (2)]))); // wrappers
				sprintf(codegen_buf, "%s\n%s", (yyvsp[(1) - (2)]).fs.CurrentTerm.what.c_str(), (yyvsp[(2) - (2)]).fs.CurrentTerm.what.c_str());
				newnode = flattern_bin(newnode);
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				(yyval) = *newnode;
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 2113 "for90.y"
    {
				// drop interface directly
				ParseNode * newnode = new ParseNode();
				// no child
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				(yyval) = *newnode;
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 2122 "for90.y"
    {
				program_tree = (yyvsp[(1) - (1)]);
			}
    break;


/* Line 1792 of yacc.c  */
#line 4453 "for90.tab.cpp"
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
#line 2126 "for90.y"

//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
	printf("line %d from %d len %d, current token is %s(id = %d) : %s \n", get_flex_state().parse_line, get_flex_state().parse_pos, get_flex_state().parse_len, get_intent_name(yylval.fs.CurrentTerm.token).c_str(), yylval.fs.CurrentTerm.token, yylval.fs.CurrentTerm.what.c_str());
	printf("context : %s ^ %s\n", global_code.substr(max(0, get_flex_state().parse_pos - 10), 10).c_str(), global_code.substr(get_flex_state().parse_pos, 10).c_str());
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

		/* pn->child[1] is a **list** of ALREADY flatterned elements */
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
		current_node.fs.line_pos = current_node.child[0]->fs.line_pos;
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
