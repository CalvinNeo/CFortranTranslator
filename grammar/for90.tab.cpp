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
#line 92 "for90.tab.cpp"

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
     YY_SELECT = 303,
     YY_ENDSELECT = 304,
     YY_GOTO = 305,
     YY_DOWHILE = 306,
     YY_DEFAULT = 307,
     _YY_DELIM = 308,
     YY_PROGRAM = 309,
     YY_ENDPROGRAM = 310,
     YY_FUNCTION = 311,
     YY_ENDFUNCTION = 312,
     YY_RECURSIVE = 313,
     YY_RESULT = 314,
     YY_SUBROUTINE = 315,
     YY_ENDSUBROUTINE = 316,
     YY_MODULE = 317,
     YY_ENDMODULE = 318,
     YY_BLOCK = 319,
     YY_ENDBLOCK = 320,
     _YY_DESCRIBER = 321,
     YY_IMPLICIT = 322,
     YY_NONE = 323,
     YY_USE = 324,
     YY_PARAMETER = 325,
     YY_FORMAT = 326,
     YY_ENTRY = 327,
     YY_DIMENSION = 328,
     YY_ARRAYINITIAL_START = 329,
     YY_ARRAYINITIAL_END = 330,
     YY_INTENT = 331,
     YY_IN = 332,
     YY_OUT = 333,
     YY_INOUT = 334,
     YY_OPTIONAL = 335,
     _YY_TYPEDEF = 336,
     YY_INTEGER_T = 337,
     YY_FLOAT_T = 338,
     YY_STRING_T = 339,
     YY_COMPLEX_T = 340,
     YY_BOOL_T = 341,
     _YY_COMMAND = 342,
     YY_WRITE = 343,
     YY_READ = 344,
     YY_PRINT = 345,
     YY_OPEN = 346,
     YY_CLOSE = 347,
     YY_CALL = 348
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
#line 251 "for90.tab.cpp"

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
#define YYLAST   1138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     102,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      99,   100,    97,    95,   101,    96,     2,    98,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,     2,
       2,    94,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    11,    16,    21,
      26,    31,    36,    38,    40,    43,    47,    48,    50,    52,
      54,    56,    58,    60,    63,    65,    67,    69,    73,    79,
      81,    83,    87,    89,    93,    99,   101,   106,   111,   116,
     121,   126,   131,   135,   140,   145,   150,   155,   160,   165,
     169,   174,   179,   184,   189,   192,   195,   197,   198,   201,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   222,
     224,   226,   228,   230,   234,   238,   240,   243,   244,   245,
     247,   248,   250,   252,   254,   256,   258,   262,   268,   274,
     276,   278,   280,   282,   284,   289,   291,   295,   299,   301,
     305,   306,   314,   318,   322,   324,   328,   337,   349,   359,
     371,   377,   384,   391,   402,   415,   422,   437,   439,   441,
     450
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     144,     0,    -1,     5,    -1,    -1,    58,    -1,   106,    -1,
      -1,    76,    99,    77,   100,    -1,    76,    99,    78,   100,
      -1,    76,    99,    79,   100,    -1,    73,    99,   113,   100,
      -1,    73,    99,   115,   100,    -1,    80,    -1,    70,    -1,
     101,   107,    -1,   101,   107,   108,    -1,    -1,    23,    -1,
      22,    -1,    26,    -1,    29,    -1,    30,    -1,    28,    -1,
       1,   102,    -1,    24,    -1,   110,    -1,   132,    -1,   115,
     103,   115,    -1,   115,   103,   115,   103,   115,    -1,   103,
      -1,   112,    -1,   112,   101,   113,    -1,   115,    -1,   115,
     101,   116,    -1,   111,    99,   116,   100,   105,    -1,   114,
      -1,    99,   115,   100,   105,    -1,   115,    95,   115,   105,
      -1,   115,    96,   115,   105,    -1,   115,    97,   115,   105,
      -1,   115,    98,   115,   105,    -1,   115,    18,   115,   105,
      -1,    96,   115,   105,    -1,   115,    12,   115,   105,    -1,
     115,    13,   115,   105,    -1,   115,     9,   115,   105,    -1,
     115,    14,   115,   105,    -1,   115,    15,   115,   105,    -1,
     115,    16,   115,   105,    -1,    17,   115,   105,    -1,   115,
       7,   115,   105,    -1,   115,     8,   115,   105,    -1,   115,
      10,   115,   105,    -1,   115,    11,   115,   105,    -1,   109,
     105,    -1,   111,   105,    -1,   113,    -1,    -1,   115,   105,
      -1,   133,   105,    -1,   120,    -1,   118,    -1,   119,    -1,
     123,    -1,   122,    -1,   121,    -1,   130,    -1,   131,    -1,
     139,    -1,   141,    -1,    40,    -1,    41,    -1,    50,    -1,
     115,    94,   115,    -1,    67,    68,   105,    -1,   117,    -1,
     117,   124,    -1,    -1,    -1,    99,    -1,    -1,   100,    -1,
      97,    -1,    22,    -1,    97,    -1,    26,    -1,   127,   101,
     128,    -1,    88,   125,   129,   126,   116,    -1,    89,   125,
     129,   126,   116,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,   132,   108,    19,   135,    -1,   110,
      -1,   110,    94,   115,    -1,   110,    94,   138,    -1,   134,
      -1,   134,   101,   135,    -1,    -1,   115,   101,   110,    94,
     115,   101,   115,    -1,    74,   116,    75,    -1,    74,   136,
      75,    -1,   137,    -1,   137,   101,   138,    -1,    33,   115,
      34,   105,   124,    32,    33,   105,    -1,    33,   115,    34,
     105,   124,    35,   105,   124,    32,    33,   105,    -1,    33,
     115,    34,   105,   124,   140,    32,    33,   105,    -1,    33,
     115,    34,   105,   124,   140,    35,   105,   124,    32,    33,
      -1,    36,   115,    34,   105,   124,    -1,    36,   115,    34,
     105,   124,   140,    -1,    38,   105,   124,    32,    38,   105,
      -1,    38,   110,    94,   115,   101,   115,   105,   124,    32,
      38,    -1,    38,   110,    94,   115,   101,   115,   101,   115,
     105,   124,    32,    38,    -1,    51,   115,   105,   124,    32,
      38,    -1,   106,    56,   110,    99,   135,   100,    59,    99,
     110,   100,   105,   124,    32,    56,    -1,   124,    -1,   142,
      -1,    54,    24,   105,   143,    32,    54,    24,   105,    -1,
      54,   105,   143,    32,    54,   105,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    56,    61,    62,    63,    65,    75,    86,
      96,   118,   144,   153,   158,   164,   180,   188,   195,   201,
     207,   213,   219,   228,   231,   238,   238,   245,   260,   272,
     287,   306,   328,   340,   356,   392,   406,   420,   433,   446,
     459,   472,   485,   497,   510,   523,   536,   549,   562,   575,
     587,   600,   613,   626,   639,   644,   651,   696,   700,   716,
     729,   730,   731,   732,   733,   743,   754,   755,   757,   757,
     759,   760,   761,   763,   778,   787,   797,   811,   823,   824,
     825,   826,   827,   832,   837,   842,   848,   859,   894,   939,
     946,   951,   956,   961,   968,  1157,  1174,  1191,  1209,  1214,
    1229,  1237,  1249,  1264,  1288,  1297,  1309,  1325,  1344,  1362,
    1383,  1400,  1418,  1432,  1452,  1470,  1518,  1698,  1705,  1713,
    1721
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
  "YY_CASE", "YY_ENDCASE", "YY_SELECT", "YY_ENDSELECT", "YY_GOTO",
  "YY_DOWHILE", "YY_DEFAULT", "_YY_DELIM", "YY_PROGRAM", "YY_ENDPROGRAM",
  "YY_FUNCTION", "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT",
  "YY_SUBROUTINE", "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE",
  "YY_BLOCK", "YY_ENDBLOCK", "_YY_DESCRIBER", "YY_IMPLICIT", "YY_NONE",
  "YY_USE", "YY_PARAMETER", "YY_FORMAT", "YY_ENTRY", "YY_DIMENSION",
  "YY_ARRAYINITIAL_START", "YY_ARRAYINITIAL_END", "YY_INTENT", "YY_IN",
  "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "_YY_TYPEDEF", "YY_INTEGER_T",
  "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T", "_YY_COMMAND",
  "YY_WRITE", "YY_READ", "YY_PRINT", "YY_OPEN", "YY_CLOSE", "YY_CALL",
  "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "','", "'\\n'", "':'",
  "$accept", "crlf", "dummy_function_iden", "dummy_variable_iden_1",
  "dummy_variable_iden", "literal", "variable", "callable", "slice",
  "dimen_slice", "function_array", "exp", "argtable", "stmt",
  "output_stmt", "input_stmt", "compound_stmt", "jump_stmt", "let_stmt",
  "dummy_stmt", "suite", "_optional_lbrace", "_optional_rbrace",
  "_optional_device", "_optional_formatter", "io_info", "write", "read",
  "type_spec", "var_def", "kwargtable", "paramtable", "_generate_stmt",
  "array_builder_elem", "array_builder", "if_stmt", "elseif_stmt",
  "do_stmt", "function_decl", "wrapper", "program", YY_NULL
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
     345,   346,   347,   348,    61,    43,    45,    42,    47,    40,
      41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   110,   111,   111,   112,   112,   112,
     113,   113,   113,   113,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   119,   120,   120,
     121,   121,   121,   122,   123,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   130,   131,   132,
     132,   132,   132,   132,   133,   134,   134,   134,   135,   135,
     135,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     140,   140,   141,   141,   141,   141,   142,   143,   143,   144,
     144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     0,     4,     4,     4,
       4,     4,     1,     1,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     3,     5,     1,
       1,     3,     1,     3,     5,     1,     4,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     2,     2,     1,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     2,     0,     0,     1,
       0,     1,     1,     1,     1,     1,     3,     5,     5,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     1,     3,
       0,     7,     3,     3,     1,     3,     8,    11,     9,    11,
       5,     6,     6,    10,    12,     6,    14,     1,     1,     8,
       6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     2,     3,     0,     1,     0,     0,     0,
      18,    17,    24,    19,    22,    20,    21,     0,     3,    70,
      71,    72,     0,     4,     0,    89,    90,    91,    92,    93,
      78,    78,     0,     0,     0,     3,    25,     3,    35,     3,
       0,    61,    62,    60,    65,    64,    63,   117,    66,    67,
      26,     3,    68,    69,   118,     0,     0,    23,     3,    26,
       0,     0,     0,     3,     3,    79,     0,     0,     3,     0,
       0,    54,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    76,     0,     0,    59,     0,     0,    49,     3,     0,
       0,     0,    74,    83,    82,     0,    80,    80,    42,     3,
       0,    29,    30,    56,    32,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,    73,     3,     3,
       3,     3,    13,     0,     0,    12,    14,   100,     3,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    36,   100,
       0,     0,     0,     3,    50,    51,    45,    52,    53,    43,
      44,    46,    47,    48,    41,    37,    38,    39,    40,     0,
       0,    15,    95,    98,    94,   120,     3,     0,     3,     0,
       0,    85,    84,    86,    87,    88,     0,    31,    33,    27,
      34,     0,     0,     0,     0,     0,     0,   100,   119,     0,
       3,     0,     0,   112,     3,   115,     0,     0,    10,    11,
       7,     8,     9,     0,    96,   104,    97,    99,     3,     0,
       0,     0,     3,     0,     0,     0,    28,    32,     0,     0,
       0,   106,     0,     3,     3,     0,     3,     0,     0,     0,
     102,   103,   105,     0,     0,   108,     0,     0,     0,     0,
      25,     3,   110,     0,     0,   113,     3,     0,   107,   111,
     109,     0,     0,     0,   114,     0,     0,     0,   101,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    34,   136,    93,    35,    36,    37,   112,   113,
      38,    39,   188,    40,    41,    42,    43,    44,    45,    46,
      47,    66,   146,   105,   183,   106,    48,    49,    59,    51,
     173,   174,   229,   215,   216,    52,   202,    53,    54,    55,
       2
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
     -40,     1,    18,  -145,    15,   519,  -145,   519,   -81,   753,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,   753,     6,  -145,
    -145,  -145,   753,  -145,   -41,  -145,  -145,  -145,  -145,  -145,
     -71,   -71,   753,   753,   -25,    15,  -145,     4,  -145,   919,
     597,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     -15,    15,  -145,  -145,  -145,     5,     9,  -145,   965,  -145,
    1011,   705,   -51,   965,    15,  -145,   -12,   -12,   965,   977,
      27,  -145,    16,  -145,   753,   753,   753,   753,   753,   753,
     753,   753,   753,   753,   753,   753,   753,   753,   753,   753,
    -145,  -145,   -54,    39,  -145,     7,     8,  -145,    15,    28,
     753,   705,  -145,  -145,  -145,   -42,   -36,   -36,  -145,    15,
     -10,  -145,   -17,  -145,   810,   -13,   965,   965,   965,   965,
     965,   965,   965,   965,   965,   965,   965,  1040,   965,   965,
     965,   965,  -145,    -7,    -6,  -145,    -5,    27,    15,    64,
     627,    56,   870,    63,   -14,  -145,   411,   411,  -145,    27,
     441,   322,   753,    15,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   441,
     -30,  -145,    10,    12,  -145,  -145,    15,    20,    15,   753,
      67,  -145,  -145,  -145,  -145,  -145,    11,  -145,  -145,   858,
    -145,    14,   798,    17,    22,    23,   675,    27,  -145,    73,
      15,   753,     0,  -145,   319,  -145,    48,   753,  -145,  -145,
    -145,  -145,  -145,   284,  1040,    19,  -145,  -145,    15,   705,
    1023,    75,    15,   753,   705,    25,  1040,   846,    34,    35,
      44,  -145,    93,    15,    15,   705,   965,    94,    27,   284,
    -145,  -145,  -145,    95,   627,  -145,    98,   705,    89,    31,
      38,    15,    99,   101,   107,  -145,    15,   753,  -145,  -145,
    -145,   102,   705,   907,  -145,   112,   753,    90,  1040,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,   143,  -145,  -145,    13,  -145,   -16,  -145,  -145,  -135,
    -145,    -9,   -65,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     -11,   114,    43,  -145,  -145,    84,  -145,  -145,    -4,  -145,
    -145,  -144,  -145,  -145,   -78,  -145,   -99,  -145,  -145,   147,
    -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -78
static const yytype_int16 yytable[] =
{
      58,    50,    62,    50,   -16,   186,     3,   115,    60,     3,
     103,     3,   181,    63,     1,   187,   132,     8,     6,   133,
       3,    57,   134,    68,    69,     4,   135,    64,    65,    91,
      12,    70,   221,     9,   191,   222,    50,    95,    10,    11,
      12,    96,    13,   100,    14,    15,    16,   193,   194,   195,
      99,    12,   199,   217,   110,   200,   201,    50,   137,   144,
     141,   138,   139,   114,   145,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   184,   185,   182,   150,   104,    92,   153,   176,   149,
     143,   142,   169,   170,   178,   180,    92,    50,    25,    26,
      27,    28,    29,    72,   196,   205,   218,   225,   234,   240,
     241,   206,    32,   197,   208,    33,   -57,   210,   213,   111,
     230,   172,   211,   212,   238,   243,   248,   255,   251,   177,
     253,   256,   257,   172,   260,   201,    50,   114,   114,   261,
     264,   114,   114,   189,   267,    67,   269,     7,   228,   171,
     147,   107,   242,   259,    56,     0,     0,     0,     0,     0,
     192,    61,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,     0,    71,     0,
      73,   172,    90,     0,     0,     0,     0,   214,     0,     0,
       0,     0,   220,     0,    94,     0,     0,     0,   226,     0,
       0,    97,     0,     0,   227,     0,   101,   102,   232,     0,
       0,   108,     0,   237,   236,    50,     0,     0,     0,     0,
      50,     0,   249,   250,   246,     0,     0,     0,     0,     0,
     114,    50,     0,   252,     0,     0,   254,     0,     0,     0,
      50,   140,     0,    50,     0,     0,     0,     0,   263,     0,
       0,   265,   148,     0,     0,     0,     0,   268,    50,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,   165,   166,   167,   168,     0,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     9,     0,     0,     0,     0,    10,    11,    12,     0,
      13,     0,    14,    15,    16,     0,     0,     0,     0,   198,
       0,   203,     0,     8,     3,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,    84,     0,     9,
       0,     0,     0,   219,    10,    11,    12,   224,    13,     0,
      14,    15,    16,     0,   -57,   -57,     0,   -57,   -57,   -57,
     -57,   231,   -57,   -57,     0,   235,    25,    26,    27,    28,
      29,     0,   -57,   -57,     0,     0,   244,   245,     0,   247,
      32,     0,     0,    33,     0,     0,     0,   111,     0,   -57,
       0,     0,     0,     0,   258,     0,     0,   -57,     0,   262,
       0,     0,     0,     0,    25,    26,    27,    28,    29,     0,
     -57,   -57,     8,     0,    86,    87,    88,    89,    32,     0,
     223,    33,   -57,     0,     0,   111,     0,     0,     9,     0,
       0,     0,     0,    10,    11,    12,     0,    13,     0,    14,
      15,    16,     8,   -57,   -57,     0,   -57,   -57,     0,   -57,
       0,   -57,   -57,     0,     0,     0,     0,     0,     9,     0,
       0,   -57,   -57,    10,    11,    12,     0,    13,     0,    14,
      15,    16,     0,     0,     0,     0,     0,     0,   -57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,    29,     0,   -57,
     -57,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      33,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       8,     0,     0,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    32,     0,     0,
      33,    10,    11,    12,   111,    13,     0,    14,    15,    16,
       0,   -77,    17,     0,     0,     0,     0,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,     0,    -6,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,    25,    26,    27,    28,    29,     0,    30,    31,     0,
       0,     0,     0,     0,     9,    32,     0,     0,    33,    10,
      11,    12,     0,    13,     0,    14,    15,    16,     8,   -75,
      17,     0,   -75,   -75,     0,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     9,     0,     0,    21,    22,    10,
      11,    12,     0,    13,     0,    14,    15,    16,     0,   -77,
      17,     0,   -77,   -77,    24,    18,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     8,    21,    22,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     9,    32,    24,     0,    33,    10,    11,    12,
       0,    13,     0,    14,    15,    16,     8,     0,     0,    25,
      26,    27,    28,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     9,    32,     0,     0,    33,    10,    11,    12,
       0,    13,     0,    14,    15,    16,     0,   -77,    17,     0,
       0,     0,     0,    18,     0,    19,    20,     0,     0,   213,
       0,     0,     0,     0,     8,    21,    22,    25,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    32,    24,     0,    33,    10,    11,    12,     0,    13,
       0,    14,    15,    16,     0,     0,     0,    25,    26,    27,
      28,    29,     0,    30,    31,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    33,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,    84,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    33,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,    84,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,    84,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    84,     0,
       0,     0,     0,    86,    87,    88,    89,     0,   209,   151,
       0,   152,     0,     0,     0,    86,    87,    88,    89,     0,
       0,   151,     0,   152,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     3,    84,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,    84,     0,     0,
       0,    86,    87,    88,    89,     0,     0,   239,     0,   152,
       0,     0,     0,    86,    87,    88,    89,     0,     0,     0,
       0,   207,     0,     0,     0,    86,    87,    88,    89,     0,
       3,   179,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    84,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    84,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,     0,   266,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    84,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,    84,     0,     0,     0,    98,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   233,    84,     0,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       9,     5,    18,     7,    19,   149,     5,    72,    17,     5,
      22,     5,    26,    22,    54,   150,    70,     1,     0,    73,
       5,   102,    76,    32,    33,    24,    80,    68,    99,    40,
      24,    56,    32,    17,   169,    35,    40,    32,    22,    23,
      24,    32,    26,    94,    28,    29,    30,    77,    78,    79,
      61,    24,    32,   197,    70,    35,    36,    61,    19,   101,
      32,    54,    54,    72,   100,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   146,   147,    97,   101,    97,   101,   100,    24,    99,
     101,   100,    99,    99,    38,    32,   101,   101,    82,    83,
      84,    85,    86,    99,    94,    38,    33,    59,    33,    75,
      75,   100,    96,   101,   100,    99,   100,   100,    74,   103,
     101,   137,   100,   100,    99,    32,    32,    38,    33,   140,
      32,   100,    94,   149,    33,    36,   140,   146,   147,    32,
      38,   150,   151,   152,    32,    31,    56,     4,   213,   136,
     107,    67,   230,   252,     7,    -1,    -1,    -1,    -1,    -1,
     169,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,   197,    39,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,    -1,    51,    -1,    -1,    -1,   207,    -1,
      -1,    58,    -1,    -1,   213,    -1,    63,    64,   219,    -1,
      -1,    68,    -1,   224,   223,   219,    -1,    -1,    -1,    -1,
     224,    -1,   238,   239,   235,    -1,    -1,    -1,    -1,    -1,
     239,   235,    -1,   244,    -1,    -1,   247,    -1,    -1,    -1,
     244,    98,    -1,   247,    -1,    -1,    -1,    -1,   257,    -1,
      -1,   262,   109,    -1,    -1,    -1,    -1,   266,   262,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,   176,
      -1,   178,    -1,     1,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    17,
      -1,    -1,    -1,   200,    22,    23,    24,   204,    26,    -1,
      28,    29,    30,    -1,    32,    33,    -1,    35,    36,    75,
      38,   218,    40,    41,    -1,   222,    82,    83,    84,    85,
      86,    -1,    50,    51,    -1,    -1,   233,   234,    -1,   236,
      96,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,    67,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    75,    -1,   256,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      88,    89,     1,    -1,    95,    96,    97,    98,    96,    -1,
     101,    99,   100,    -1,    -1,   103,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    30,     1,    32,    33,    -1,    35,    36,    -1,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    50,    51,    22,    23,    24,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    96,    -1,    -1,
      99,    22,    23,    24,   103,    26,    -1,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    17,    96,    -1,    -1,    99,    22,
      23,    24,    -1,    26,    -1,    28,    29,    30,     1,    32,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    50,    51,    22,
      23,    24,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    67,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    50,    51,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    17,    96,    67,    -1,    99,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,     1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    17,    96,    -1,    -1,    99,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,    -1,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    -1,    74,
      -1,    -1,    -1,    -1,     1,    50,    51,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    96,    67,    -1,    99,    22,    23,    24,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,    -1,    -1,    95,    96,    97,    98,    -1,
      -1,   101,    -1,   103,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     5,    18,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    95,    96,    97,    98,    -1,    -1,   101,    -1,   103,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    95,    96,    97,    98,    -1,
       5,   101,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    34,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    34,    18,    -1,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,   144,     5,    24,   105,     0,   105,     1,    17,
      22,    23,    24,    26,    28,    29,    30,    33,    38,    40,
      41,    50,    51,    58,    67,    82,    83,    84,    85,    86,
      88,    89,    96,    99,   106,   109,   110,   111,   114,   115,
     117,   118,   119,   120,   121,   122,   123,   124,   130,   131,
     132,   133,   139,   141,   142,   143,   143,   102,   115,   132,
     115,   105,   110,   115,    68,    99,   125,   125,   115,   115,
      56,   105,    99,   105,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    18,    94,    95,    96,    97,    98,
     105,   124,   101,   108,   105,    32,    32,   105,    34,   124,
      94,   105,   105,    22,    97,   127,   129,   129,   105,   100,
     110,   103,   112,   113,   115,   116,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,    70,    73,    76,    80,   107,    19,    54,    54,
     105,    32,   115,   124,   101,   100,   126,   126,   105,    99,
     101,   101,   103,   100,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,    99,
      99,   108,   110,   134,   135,   105,    24,   124,    38,   101,
      32,    26,    97,   128,   116,   116,   135,   113,   116,   115,
     105,   113,   115,    77,    78,    79,    94,   101,   105,    32,
      35,    36,   140,   105,   115,    38,   100,   103,   100,   100,
     100,   100,   100,    74,   115,   137,   138,   135,    33,   105,
     115,    32,    35,   101,   105,    59,   115,   115,   116,   136,
     101,   105,   124,    34,    33,   105,   115,   124,    99,   101,
      75,    75,   138,    32,   105,   105,   124,   105,    32,   110,
     110,    33,   124,    32,   124,    38,   100,    94,   105,   140,
      33,    32,   105,   115,    38,   124,   101,    32,   115,    56
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
#line 51 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::CRLF, "\n" };
				update_pos((yyval));
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 56 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
				update_pos((yyval));
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 66 "for90.y"
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

  case 8:
/* Line 1792 of yacc.c  */
#line 76 "for90.y"
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

  case 9:
/* Line 1792 of yacc.c  */
#line 87 "for90.y"
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

  case 10:
/* Line 1792 of yacc.c  */
#line 97 "for90.y"
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

  case 11:
/* Line 1792 of yacc.c  */
#line 119 "for90.y"
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

  case 12:
/* Line 1792 of yacc.c  */
#line 145 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" }; // intent(inout)
				newnode->attr = new VariableDescAttr(newnode);
				dynamic_cast<VariableDescAttr *>(newnode->attr)->desc.optional = true;
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 154 "for90.y"
    {
				/* const value */
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 159 "for90.y"
    {
				ParseNode * newnode = new ParseNode((yyvsp[(1) - (2)]));
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 165 "for90.y"
    {				
				ParseNode * newnode = new ParseNode();
				ParseNode * variable_iden = & (yyvsp[(3) - (3)]);
				/* target code of slice depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" };
				/* merge attrs */
				newnode->attr = (yyvsp[(2) - (3)]).attr->clone();
				VariableDescAttr * new_a = dynamic_cast<VariableDescAttr *>(newnode->attr);
				VariableDescAttr * var_a = dynamic_cast<VariableDescAttr *>(variable_iden->attr);
				new_a->merge(*var_a);
				// TODO do not add child
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 180 "for90.y"
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
#line 189 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // float number
				(yyval) = *newnode;
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 196 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // int number
				(yyval) = *newnode;
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 202 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::String, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // string
				(yyval) = *newnode;
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 208 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "true" }; // bool true
				(yyval) = *newnode;
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 214 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::Bool, "false" }; // bool false
				(yyval) = *newnode;
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 220 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				int splitter = strcplx.find_first_of('_', 0);
				newnode->fs.CurrentTerm = Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") "}; // complex
				(yyval) = *newnode;
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 232 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }; // variant
				(yyval) = *newnode;
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 239 "for90.y"
    {
				/* array index and function name and type cast */
				string x = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 246 "for90.y"
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

  case 28:
/* Line 1792 of yacc.c  */
#line 261 "for90.y"
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

  case 29:
/* Line 1792 of yacc.c  */
#line 273 "for90.y"
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

  case 30:
/* Line 1792 of yacc.c  */
#line 288 "for90.y"
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

  case 31:
/* Line 1792 of yacc.c  */
#line 307 "for90.y"
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

  case 32:
/* Line 1792 of yacc.c  */
#line 329 "for90.y"
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

  case 33:
/* Line 1792 of yacc.c  */
#line 341 "for90.y"
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

  case 34:
/* Line 1792 of yacc.c  */
#line 357 "for90.y"
    {
				/* function call OR array index */
				/* NOTE that array index can be A(1:2, 3:4) */
				ParseNode * newnode = new ParseNode();
				ParseNode & callable = (yyvsp[(1) - (5)]);
				ParseNode & argtable = (yyvsp[(3) - (5)]);
				ParseNode & crlf = (yyvsp[(5) - (5)]);
#ifndef LAZY_GEN
				string name;
				string x;
				if (funcname_map.find(callable.fs.CurrentTerm.what) != funcname_map.end()) {
					name = funcname_map.at(callable.fs.CurrentTerm.what);
				}
				else {
					name = callable.fs.CurrentTerm.what;
				}
				if (argtable.fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE) {
					sprintf(codegen_buf, argtable.fs.CurrentTerm.what.c_str(), name.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  string(codegen_buf) };
				}
				else {
					x += name;
					x += "(";
					x += argtable.fs.CurrentTerm.what;
					x += ")";
					x += (crlf.fs.CurrentTerm.token == TokenMeta::CRLF ? ";" : "");
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUCNTIONARRAY,  x };
				}
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(callable)); // function/array name
				newnode->addchild(new ParseNode(argtable)); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 393 "for90.y"
    {
				/* function call OR array index */
				ParseNode * newnode = new ParseNode();
				ParseNode & function_array = (yyvsp[(1) - (1)]);
#ifndef LAZY_GEN
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, function_array.fs.CurrentTerm.what };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(function_array)); // function_array
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 407 "for90.y"
    {
				/* `function_array` rule has priority over this rule  */
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (4)]);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "( %s )", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode(exp));
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 421 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s + %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // +
				newnode->addchild(new ParseNode(exp2)); // tight operand exp
				(yyval) = *newnode;
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 434 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s - %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // -
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 447 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s * %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // *
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 460 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s / %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // /
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 473 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "power(%s, %s)", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // **
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 486 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(2) - (3)]);
				ParseNode & op = (yyvsp[(1) - (3)]);
				sprintf(codegen_buf, "(-%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // (-)
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 498 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 511 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s != %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // !=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 524 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 537 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s == %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ==
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 550 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s && %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // &&
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 563 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s || %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // ||
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 576 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(2) - (3)]);
				ParseNode & op = (yyvsp[(1) - (3)]);
				sprintf(codegen_buf, "!(%s)", exp1.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(op)); // !
				newnode->addchild(new ParseNode(exp1)); // only right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 588 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s > %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 601 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s >= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // >=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 614 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s <= %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <=
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 627 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (4)]);
				ParseNode & op = (yyvsp[(2) - (4)]);
				ParseNode & exp2 = (yyvsp[(3) - (4)]);
				sprintf(codegen_buf, "%s < %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_EXPRESSION, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // <
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 640 "for90.y"
    { 
				// 
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 645 "for90.y"
    {
				// may cause reduction-reduction conflict when use `variable` instead of `callable`
				// TODO : i am a little strange that `integer::a, b, c` works well because i am afraid that callable will reduce to exp from here. however according to LR(1), `::` is not in FOLLOW(exp)
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 652 "for90.y"
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
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_PURE, string(codegen_buf) };
				}
				else {
					//sprintf(codegen_buf, "%%s(%s)", dimen_slice.fs.CurrentTerm.what.c_str());
					sprintf(codegen_buf, "%s", dimen_slice.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARGTABLE_DIMENSLICE, string(codegen_buf) };
				}
#endif // !LAZY_GEN
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 696 "for90.y"
    {
				// TODO : argtable can also be empty
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 701 "for90.y"
    {
				// TODO IMPORTANT
				/*
					一般来说, 可以不单独建立stmt的ParseNode, 再添加唯一的child(exp, var_def, compound_stmt等).
					但是考虑到在cpp等语言中可能出现使用,分隔多个语句的情况(这种情况是有作用的, 表明编译器可以按照自己的顺序求值)
					所以单独建立stmt节点兵添加$1位stmt节点的唯一的儿子
				*/
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(1) - (2)]);
				sprintf(codegen_buf, "%s ;\n", exp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp)); // exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 717 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & var_def = (yyvsp[(1) - (2)]);
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
#ifndef LAZY_GEN
				sprintf(codegen_buf, "%s \n", var_def.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode(var_def)); // var_def
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 734 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & let = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s ;\n", let.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(let)); // let
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 744 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & jmp = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s ;\n", jmp.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, string(codegen_buf) };
				newnode->addchild(new ParseNode(jmp)); // jmp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 764 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp1 = (yyvsp[(1) - (3)]);
				ParseNode & op = (yyvsp[(2) - (3)]);
				ParseNode & exp2 = (yyvsp[(3) - (3)]);
				sprintf(codegen_buf, "%s = %s", exp1.fs.CurrentTerm.what.c_str(), exp2.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::Let, string(codegen_buf) };
				newnode->addchild(new ParseNode(exp1)); // left operand exp
				newnode->addchild(new ParseNode(op)); // =
				newnode->addchild(new ParseNode(exp2)); // right operand exp
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 779 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_STATEMENT, "" };
				// dummy stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 788 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = (yyvsp[(1) - (1)]);
				sprintf(codegen_buf, "%s \n", stmt.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 798 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & stmt = (yyvsp[(1) - (2)]);
				ParseNode & suite = (yyvsp[(2) - (2)]);
				sprintf(codegen_buf, "%s \n %s \n", stmt.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_SUITE, string(codegen_buf) };
				newnode->addchild(new ParseNode(stmt)); // stmt
				newnode->addchild(new ParseNode(suite)); // suite
				newnode = flattern_bin(newnode);
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 811 "for90.y"
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

  case 82:
/* Line 1792 of yacc.c  */
#line 828 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				update_pos((yyval));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 833 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
				update_pos((yyval));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 838 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
				update_pos((yyval));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 843 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
				update_pos((yyval));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 849 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				/* target code of io_info depend on context */
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "" };
				newnode->addchild(new ParseNode((yyvsp[(1) - (3)]))); // _optional_device
				newnode->addchild(new ParseNode((yyvsp[(3) - (3)]))); // _optional_formatter
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 860 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = (yyvsp[(3) - (5)]);
				ParseNode * argtbl = &(yyvsp[(5) - (5)]); 
				ParseNode * formatter = (yyvsp[(3) - (5)]).child[1];
				if (formatter->fs.CurrentTerm.token == TokenMeta::NT_FORMATTER) {
					string fmt = io_info.child[1]->fs.CurrentTerm.what.substr(1, io_info.child[1]->fs.CurrentTerm.what.size() - 1); // strip " 
					sprintf(codegen_buf, "printf(\"%s\", %s) ;\n", parse_ioformatter(fmt).c_str(), argtbl->fs.CurrentTerm.what.c_str());
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
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 895 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & io_info = (yyvsp[(3) - (5)]);
				ParseNode * argtbl = &(yyvsp[(5) - (5)]); 
				ParseNode * formatter = (yyvsp[(3) - (5)]).child[1];
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
					sprintf(codegen_buf, "scanf(\"%s\", %s) ;\n", parse_ioformatter(fmt).c_str(), pointer_to.c_str());
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
							cincode += ">>";
							cincode += argtbl->child[i]->fs.CurrentTerm.what;
						}
						// argtbl = argtbl->child[1];
					//}
					cincode += ";";
					newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, cincode };
				}
				newnode->addchild(new ParseNode(io_info)); // ioinfo
				newnode->addchild(new ParseNode((yyvsp[(5) - (5)]))); // argtable
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 940 "for90.y"
    {
				// now translated in pre_map
				//$1.fs.CurrentTerm.what = typename_map.at($1.fs.CurrentTerm.what);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 947 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 952 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 957 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 962 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 969 "for90.y"
    {
				/* array decl */
				string arr_decl = ""; string var_decl = ""; bool do_arr = false;
				ParseNode * newnode = new ParseNode();
				ParseNode * ty = new ParseNode((yyvsp[(1) - (4)])); // type
				newnode->addchild(ty); // type
				ParseNode * iden = &(yyvsp[(2) - (4)]); // dummy_variable_iden
				VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(iden->attr);
				ParseNode * slice = vardescattr->desc.slice;
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
							ParseNode * this_variable = pn->child[i];
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
#ifndef LAZY_GEN
					// sprintf(codegen_buf, "%s %s;", $1.fs.CurrentTerm.what.c_str(), $4.fs.CurrentTerm.what.c_str());
					newnode->fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
#endif // !LAZY_GEN
				}

				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1158 "for90.y"
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

  case 96:
/* Line 1792 of yacc.c  */
#line 1175 "for90.y"
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

  case 97:
/* Line 1792 of yacc.c  */
#line 1192 "for90.y"
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

  case 98:
/* Line 1792 of yacc.c  */
#line 1210 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1215 "for90.y"
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

  case 100:
/* Line 1792 of yacc.c  */
#line 1229 "for90.y"
    {
				/* no params */
				ParseNode * newnode = new ParseNode();
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_PARAMTABLE, "" };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1238 "for90.y"
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

  case 102:
/* Line 1792 of yacc.c  */
#line 1250 "for90.y"
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

  case 103:
/* Line 1792 of yacc.c  */
#line 1265 "for90.y"
    {
				/* give generate stmt */
				ParseNode * newnode = new ParseNode();
				ParseNode * exp = (yyvsp[(2) - (3)]).child[0];
				ParseNode * index = (yyvsp[(2) - (3)]).child[1];
				ParseNode * from = (yyvsp[(2) - (3)]).child[2];
				ParseNode * to = (yyvsp[(2) - (3)]).child[3];
				sprintf(codegen_buf, "for(int %s = %s; %s < %s; %s++){\n%s(%s) = %s\n}", index->fs.CurrentTerm.what.c_str(), from->fs.CurrentTerm.what.c_str() /* exp_from */
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

  case 104:
/* Line 1792 of yacc.c  */
#line 1289 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(1) - (1)]))); // array_builder_elem
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_ARRAYBUILDER, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1298 "for90.y"
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

  case 106:
/* Line 1792 of yacc.c  */
#line 1310 "for90.y"
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

  case 107:
/* Line 1792 of yacc.c  */
#line 1326 "for90.y"
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

  case 108:
/* Line 1792 of yacc.c  */
#line 1345 "for90.y"
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

  case 109:
/* Line 1792 of yacc.c  */
#line 1363 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]); suite_true.fs.CurrentTerm.what = tabber(suite_true.fs.CurrentTerm.what);
				ParseNode & elseif = (yyvsp[(6) - (11)]);
				ParseNode & suite_else = (yyvsp[(9) - (11)]); suite_else.fs.CurrentTerm.what = tabber(suite_else.fs.CurrentTerm.what);
				
#ifndef LAZY_GEN
				sprintf(codegen_buf, "if (%s) {\n%s}\n%selse {\n%s}", exp.fs.CurrentTerm.what.c_str(), suite_true.fs.CurrentTerm.what.c_str(), elseif.fs.CurrentTerm.what.c_str(), suite_else.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_IF, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (11)]))); // if
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite_true)); // suite
				newnode->addchild(new ParseNode(elseif)); // recursive elseif-stmt
				newnode->addchild(new ParseNode(suite_else)); // else-stmt
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1384 "for90.y"
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

  case 111:
/* Line 1792 of yacc.c  */
#line 1401 "for90.y"
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

  case 112:
/* Line 1792 of yacc.c  */
#line 1419 "for90.y"
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

  case 113:
/* Line 1792 of yacc.c  */
#line 1433 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & variable = (yyvsp[(2) - (10)]);
				ParseNode & exp_from = (yyvsp[(4) - (10)]);
				ParseNode & exp_to = (yyvsp[(6) - (10)]);
				ParseNode & suite = (yyvsp[(8) - (10)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "for(%s = %s; %s < %s; %s++){\n%s}", variable.fs.CurrentTerm.what.c_str(), exp_from.fs.CurrentTerm.what.c_str(), variable.fs.CurrentTerm.what.c_str(), exp_to.fs.CurrentTerm.what.c_str(), variable.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_DO, string(codegen_buf) };
#endif // !LAZY_GEN

				newnode->addchild(new ParseNode((yyvsp[(1) - (10)]))); // do
				newnode->addchild(new ParseNode(variable)); // varname
				newnode->addchild(new ParseNode(exp_from)); // begin
				newnode->addchild(new ParseNode(exp_to)); // end
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1453 "for90.y"
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

  case 115:
/* Line 1792 of yacc.c  */
#line 1471 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite = (yyvsp[(4) - (6)]); suite.fs.CurrentTerm.what = tabber(suite.fs.CurrentTerm.what);
#ifndef LAZY_GEN
				sprintf(codegen_buf, "while(%s){\n%s}", exp.fs.CurrentTerm.what.c_str(), suite.fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::While, string(codegen_buf) };
#endif // !LAZY_GEN
				newnode->addchild(new ParseNode((yyvsp[(1) - (6)]))); // while
				newnode->addchild(new ParseNode(exp)); // exp
				newnode->addchild(new ParseNode(suite)); // suite
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1519 "for90.y"
    {
				/* fortran90 does not declare type of arguments in function declaration statement*/
				ParseNode * newnode = new ParseNode();
				vector<tuple<string, string, ParseNode *>> param_name_typename; // all params in paramtable of function declare (var_name, var_type)
				ParseNode & variable_function = (yyvsp[(3) - (14)]);
				/* enumerate paramtable */
				ParseNode & paramtable = (yyvsp[(5) - (14)]);
				ParseNode * prmtbl = &paramtable;
				vector<ParseNode *> param_definition;
				ParseNode & variable_result = (yyvsp[(9) - (14)]);
				ParseNode & suite = (yyvsp[(12) - (14)]);
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
					}
				}
				// update oldsuite->fs.CurrentTerm.what
				oldsuite->fs.CurrentTerm.what = tabber(newsuitestr);
				/* generate function ParseTree */
				newnode->addchild(new ParseNode((yyvsp[(2) - (14)]))); // function
				newnode->addchild(new ParseNode(variable_function)); // function name
				// argtable
				// TODO 
				// return value
				newnode->addchild(new ParseNode(suite)); // trimed suite

				sprintf(codegen_buf, "%s %s(%s){\n%s\n}"
					, get<1>(param_name_typename[param_name_typename.size()-1]).c_str() // return value type
					, variable_function.fs.CurrentTerm.what.c_str() // function name
					, argtblstr.c_str() // argtable
					, oldsuite->fs.CurrentTerm.what.c_str() // code
				);
				/* generate function code */
				newnode->fs.CurrentTerm = Term{ TokenMeta::NT_FUNCTIONDECLARE, string(codegen_buf) };
				(yyval) = *newnode;
				update_pos((yyval));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1699 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				//$$.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPER, string(codegen_buf) };
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1706 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				//$$.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPER, string(codegen_buf) };
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1714 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(4) - (8)]))); //wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(4) - (8)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				program_tree = *newnode;
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1722 "for90.y"
    {
				ParseNode * newnode = new ParseNode();
				newnode->addchild(new ParseNode((yyvsp[(3) - (6)]))); //wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(3) - (6)]).fs.CurrentTerm.what.c_str());
				newnode->fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, string(codegen_buf) };
				program_tree = *newnode;
			}
    break;


/* Line 1792 of yacc.c  */
#line 3864 "for90.tab.cpp"
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
#line 1730 "for90.y"

//extern "C" int yylex();

void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
	printf("from %d len %d, current token %d : %s \n", get_flex_state().parse_pos, get_flex_state().parse_len, yylval.fs.CurrentTerm.token, yylval.fs.CurrentTerm.what.c_str());
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
