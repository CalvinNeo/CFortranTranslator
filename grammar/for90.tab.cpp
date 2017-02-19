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
#line 254 "for90.tab.cpp"

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
#define YYLAST   2251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNRULES -- Number of states.  */
#define YYNSTATES  386

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     103,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     100,   101,    97,    95,   102,    96,     2,    98,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   104,    99,
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
     416,   417,   425,   429,   433,   437,   439,   442,   444,   452,
     463,   472,   484,   489,   493,   499,   506,   509,   511,   517,
     528,   541,   548,   551,   553,   563,   570,   572,   575,   580,
     581,   583,   585,   598,   600,   601,   610,   618,   620,   622,
     624,   626,   629,   639,   641
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,     4,    -1,    99,    -1,    -1,    56,    -1,
      -1,    76,   100,    77,   101,    -1,    76,   100,    78,   101,
      -1,    76,   100,    79,   101,    -1,    73,   100,   114,   101,
      -1,    73,   100,   117,   101,    -1,    80,    -1,    71,    -1,
      83,    -1,   102,   108,    -1,   102,   108,   109,    -1,    -1,
      82,    94,    20,    -1,    81,    94,   117,    -1,    21,    -1,
      20,    -1,    24,    -1,    27,    -1,    28,    -1,    26,    -1,
       1,   103,    -1,    22,    -1,   117,   104,   117,    -1,   117,
     104,   117,   104,   117,    -1,   104,    -1,   113,    -1,   113,
     102,   114,    -1,   117,    -1,   117,   102,   145,    -1,   112,
     100,   145,   101,    -1,   138,   100,   145,   101,    -1,   115,
      -1,    93,   115,    -1,   116,    -1,   149,    -1,   117,   100,
     117,   101,    -1,   100,   117,   101,    -1,   117,    95,   117,
      -1,   117,    96,   117,    -1,   117,    97,   117,    -1,   117,
      98,   117,    -1,   117,    16,   117,    -1,    96,   117,    -1,
      95,   117,    -1,   117,    10,   117,    -1,   117,    11,   117,
      -1,   117,     7,   117,    -1,   117,    12,   117,    -1,   117,
      13,   117,    -1,   117,    14,   117,    -1,    15,   117,    -1,
     117,     5,   117,    -1,   117,     6,   117,    -1,   117,     8,
     117,    -1,   117,     9,   117,    -1,   147,    -1,   111,    -1,
     112,    -1,   106,    -1,    99,   106,    -1,    99,    -1,    -1,
      30,    -1,   117,   118,    -1,   142,   118,    -1,   124,    -1,
     122,    -1,   123,    -1,   127,    -1,   126,    -1,   125,    -1,
     119,     4,    -1,   141,    -1,    29,   118,    -1,   120,    -1,
     135,   118,    -1,   136,   118,    -1,   137,   118,    -1,   151,
      -1,   154,    -1,   156,    -1,    39,   118,    -1,    40,   118,
      -1,    49,    20,   118,    -1,   117,    94,   117,   118,    -1,
      68,    69,   106,    -1,   121,    -1,   121,   128,    -1,   166,
      -1,   166,   128,    -1,    -1,   100,    -1,    -1,   101,    -1,
     102,    -1,    -1,    97,    -1,    20,    -1,    97,    -1,    20,
      -1,    24,    -1,   100,   132,   102,   133,   101,    -1,   133,
     131,    -1,    90,   134,   145,    -1,    92,   134,   145,    -1,
      91,   134,   145,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    84,   100,   110,   101,
      -1,    85,   100,   110,   101,    -1,    86,   100,   110,   101,
      -1,    87,   100,   110,   101,    -1,    88,   100,   110,   101,
      -1,    89,   100,   110,   101,    -1,   138,    97,    20,    -1,
     138,    -1,    98,   112,    98,    -1,    98,    98,    -1,    -1,
      66,   140,   145,    -1,   139,   109,    17,   145,    -1,   139,
     109,   145,    -1,    73,   145,    -1,   112,    -1,   117,    94,
     117,    -1,   117,    94,   149,    -1,   114,    -1,   143,    -1,
     144,    -1,   144,   102,   145,    -1,    -1,   117,   102,   112,
      94,   117,   102,   117,    -1,   100,   146,   101,    -1,    74,
     145,    75,    -1,    74,   147,    75,    -1,   148,    -1,    31,
      32,    -1,    36,    -1,    32,   117,    33,   106,   128,   150,
     106,    -1,    32,   117,    33,   106,   128,    34,   106,   128,
     150,   106,    -1,    32,   117,    33,   106,   128,   152,   150,
     106,    -1,    32,   117,    33,   106,   128,   152,    34,   106,
     128,   150,   106,    -1,    32,   117,    33,   121,    -1,    32,
     117,   121,    -1,    35,   117,    33,   106,   128,    -1,    35,
     117,    33,   106,   128,   152,    -1,    31,    37,    -1,    38,
      -1,    37,   106,   128,   153,   106,    -1,    37,   112,    94,
     117,   102,   117,   106,   128,   153,   106,    -1,    37,   112,
      94,   117,   102,   117,   102,   117,   106,   128,   153,   106,
      -1,    50,   117,   106,   128,   153,   106,    -1,    31,    47,
      -1,    48,    -1,    47,    45,   129,   117,   130,   106,   158,
     155,   106,    -1,    45,   129,   114,   130,   106,   128,    -1,
     157,    -1,   157,   158,    -1,    57,   100,   112,   101,    -1,
      -1,    54,    -1,    58,    -1,   107,   160,   112,   100,   145,
     101,   159,   106,   128,    31,   160,   106,    -1,    22,    -1,
      -1,    52,   162,   106,   128,    31,    52,   162,   106,    -1,
      52,   162,   106,    31,    52,   162,   106,    -1,   128,    -1,
     161,    -1,   163,    -1,   164,    -1,   164,   165,    -1,    64,
     162,   106,   165,   106,    31,    64,   162,   106,    -1,   165,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    63,    80,    81,    83,    90,    98,
     105,   118,   136,   143,   151,   157,   162,   176,   183,   194,
     208,   213,   217,   222,   226,   230,   237,   239,   246,   255,
     265,   274,   284,   294,   301,   321,   331,   342,   346,   351,
     358,   366,   374,   382,   390,   398,   406,   414,   422,   429,
     436,   444,   453,   461,   470,   478,   486,   493,   501,   509,
     517,   525,   531,   536,   543,   544,   546,   551,   555,   561,
     571,   577,   581,   585,   589,   593,   598,   603,   608,   613,
     618,   626,   627,   629,   631,   632,   633,   635,   636,   637,
     643,   652,   659,   664,   685,   690,   698,   699,   700,   701,
     702,   703,   704,   708,   712,   716,   721,   728,   739,   753,
     761,   770,   778,   783,   788,   793,   798,   803,   809,   815,
     820,   825,   830,   835,   843,   848,   850,   855,   862,   867,
     875,   885,   895,   906,   911,   920,   929,   933,   937,   944,
     953,   960,   972,   984,   991,  1002,  1034,  1035,  1042,  1049,
    1057,  1065,  1074,  1081,  1089,  1097,  1106,  1107,  1109,  1115,
    1125,  1135,  1143,  1144,  1146,  1154,  1162,  1170,  1181,  1187,
    1193,  1194,  1196,  1209,  1210,  1212,  1218,  1223,  1236,  1241,
    1247,  1256,  1268,  1274,  1278
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
  "YY_PRINT", "YY_CALL", "'='", "'+'", "'-'", "'*'", "'/'", "';'", "'('",
  "')'", "','", "'\\n'", "':'", "$accept", "crlf", "dummy_function_iden",
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
     345,   346,   347,   348,    61,    43,    45,    42,    47,    59,
      40,    41,    44,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   113,
     113,   114,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   119,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   123,   124,   124,   124,   125,   125,   125,
     126,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     136,   137,   138,   138,   138,   138,   138,   138,   139,   139,
     139,   139,   139,   139,   139,   139,   140,   140,   140,   141,
     142,   142,   142,   143,   143,   143,   144,   144,   145,   145,
     145,   146,   147,   148,   148,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   152,   152,   153,   153,   154,   154,
     154,   154,   155,   155,   156,   157,   158,   158,   159,   159,
     160,   160,   161,   162,   162,   163,   163,   163,   164,   164,
     165,   165,   166,   167,   167
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
       0,     7,     3,     3,     3,     1,     2,     1,     7,    10,
       8,    11,     4,     3,     5,     6,     2,     1,     5,    10,
      12,     6,     2,     1,     9,     6,     1,     2,     4,     0,
       1,     1,    12,     1,     0,     8,     7,     1,     1,     1,
       1,     2,     9,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    21,    20,    27,    22,    25,    23,    24,
       4,    68,     0,     4,     4,     4,     0,     0,     0,   174,
       5,   174,   128,     0,     0,     0,   112,   113,   114,   115,
     116,   117,     0,     0,     0,     0,     0,     0,    66,     0,
       0,    62,    63,    37,    39,     4,     0,    80,     0,    72,
      73,    71,    76,    75,    74,   177,     4,     4,     4,   125,
      17,    78,     4,    61,   145,    40,    84,    85,    86,   178,
     179,     0,   183,     0,     0,    26,   112,   113,   114,   115,
     116,   117,    56,     0,     2,     3,    64,    79,     0,     3,
       0,     0,    87,    88,    96,     4,     4,   173,     4,     4,
       0,     0,     4,    30,    63,    31,   136,    33,   137,   138,
     132,     0,    61,     0,     0,     0,     0,     0,     0,   105,
     106,   104,     0,   101,     0,     0,     0,     0,    38,    49,
      48,     0,     0,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    77,    93,    81,    82,    83,
       0,     0,     0,     0,    70,   181,    95,     1,    65,     0,
       0,     0,     0,   153,     0,     0,    97,     0,    89,     0,
       0,     0,   127,     0,   129,    91,     0,     0,     0,     0,
       0,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   102,     0,   100,   108,   109,   111,   110,    42,
       0,   142,     0,     0,    57,    58,    52,    59,    60,    50,
      51,    53,    54,    55,    47,     4,    43,    44,    45,    46,
       0,   124,     0,    13,     0,     0,    12,    14,    15,     0,
     131,     3,     0,   152,    43,    44,     0,     0,   157,     4,
       0,    98,     0,     0,     0,     4,   126,    32,    33,   134,
      40,    34,    28,   139,     0,     0,   118,   119,   120,   121,
     122,   123,     0,     0,     0,    35,    90,    41,    36,     0,
       0,    16,   130,     0,    41,   156,   158,     0,    99,     4,
       4,   174,     0,     0,     0,    19,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,   147,     4,
       0,     4,     0,   161,     4,   174,     0,    29,   107,     0,
     169,    10,    11,     7,     8,     9,   146,     0,     0,   148,
       4,     4,     0,     0,    96,   166,     0,   176,     4,   174,
       0,     0,     4,     0,     4,     0,   150,     4,     0,     0,
     167,     0,   163,     4,   175,     4,   141,     0,     0,     4,
       0,     0,     0,     4,    98,   162,   164,   182,     0,     0,
     149,   154,     4,     0,   159,     4,   168,     0,   155,   151,
       4,     0,     4,   160,   165,   172
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    86,    40,   238,   163,   195,    41,    42,   105,   106,
      43,    44,    45,    87,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   177,   289,   205,   203,   123,   124,
      56,    57,    58,    83,    60,   101,    61,    62,   108,   109,
     110,   132,    63,    64,    65,   309,    66,   310,   249,    67,
     353,    68,   335,   336,   342,   135,    69,    98,    70,    71,
      72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -270
static const yytype_int16 yypact[] =
{
    1228,   -90,  1411,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
       6,  -270,  1411,     5,     6,     6,   -30,    11,  1411,    22,
    -270,    22,   -36,    16,   754,   133,    -7,    -1,     9,    23,
      25,    27,    35,    35,    35,   160,  1411,  1411,  -270,  1411,
      14,  -270,    28,  -270,  -270,  1994,   104,  -270,   937,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,     6,     6,     6,   -74,
      31,  -270,     6,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  1131,  -270,  1034,   129,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,    13,    36,  -270,     8,  -270,  -270,  1444,  -270,
    1730,    43,  -270,  -270,    44,     6,  2043,  -270,     8,     8,
      20,   754,     8,  -270,    28,    48,  -270,   902,  -270,    49,
    -270,    71,    77,   -44,   -44,   -44,   -44,   -44,   -44,  -270,
    -270,  -270,     1,    60,   754,   754,   754,    28,  -270,    45,
      45,   182,    62,  -270,  -270,   149,   370,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  -270,  -270,  -270,  -270,  -270,  -270,
     158,   370,   -13,   657,  -270,  -270,  -270,  -270,  -270,  1823,
    1411,  1411,  1411,  -270,    12,  1411,  -270,  1411,  -270,  1730,
    1637,  1544,  -270,    86,  -270,  -270,   847,  1411,   552,  1411,
     552,  -270,  -270,    92,   103,    99,   105,   114,   115,   122,
     123,  -270,  -270,   125,  -270,  -270,  -270,  -270,  -270,  -270,
     149,  -270,   130,   131,    45,    45,   535,    45,    45,   535,
     883,   883,  2151,    70,    24,  2091,    17,    17,    24,    24,
    2103,  -270,   134,  -270,   136,   138,  -270,  -270,    31,   754,
    -270,  -270,  1730,  -270,  1295,  1346,  1944,   194,  -270,     8,
    1969,  2115,    12,   187,   209,     8,  -270,  -270,  1869,   883,
    -270,  -270,  1919,  -270,  1411,   221,  -270,  -270,  -270,  -270,
    -270,  -270,    -6,   156,   370,  -270,  -270,  -270,  -270,   847,
     -25,  -270,  -270,   168,   441,  -270,  -270,  1411,  -270,     8,
       8,    22,   191,   220,  1411,   883,  -270,   151,  1411,   153,
     154,  1686,   155,   157,   161,   225,     8,  1411,  -270,     8,
     141,  1932,   216,  -270,     8,    22,   199,   883,  -270,  1981,
     207,  -270,  -270,  -270,  -270,  -270,  -270,  1730,  2139,  -270,
       8,     8,  1411,  1730,    44,   216,    -9,  -270,     8,    22,
    1411,   166,     8,    33,     8,  1730,  -270,  2043,    12,   847,
    -270,   223,  -270,     8,  -270,     8,   883,   149,  1730,     8,
    1730,    33,  1730,     8,   167,  -270,  -270,  -270,   170,   236,
    -270,   238,     8,    12,  -270,     8,  -270,    14,  -270,  -270,
       8,  1730,     8,  -270,  -270,  -270
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,     4,  -270,  -270,    38,    95,  -270,    -5,  -270,  -185,
     239,  -270,   263,   -11,  -270,  -270,   -72,  -270,  -270,  -270,
    -270,  -270,  -270,   -41,   -49,   -75,  -270,  -270,    18,    32,
    -270,  -270,  -270,     0,  -270,  -270,  -270,  -270,  -270,  -270,
     -14,  -270,   266,  -270,   108,  -269,  -270,   -73,  -247,  -270,
    -270,  -270,  -270,   -38,  -270,   -76,  -270,   -19,  -270,  -270,
     -65,  -270,  -270
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -185
static const yytype_int16 yytable[] =
{
      59,   257,    99,    92,    93,   290,   165,   156,    91,    84,
      84,   111,    84,    75,   119,    94,   173,    90,   120,   104,
     104,   201,   351,   160,   143,   144,   161,     5,   143,   144,
     127,    95,   166,   147,   154,   143,   144,   193,   194,   352,
     147,   331,     5,   247,    97,   157,   158,   159,    59,   174,
     248,   164,   302,   303,   304,   119,   143,   144,   233,   120,
     234,   147,   100,   235,   305,   125,   126,   236,   133,   308,
     237,    59,   134,    59,   359,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   178,   102,   147,   184,    59,   168,
      59,   121,   372,   113,   300,   183,   104,   243,   202,   114,
     179,   363,   180,   181,    89,    85,   185,    89,   155,   115,
     206,   207,   208,   153,   151,   152,   255,   153,   182,   104,
     104,   104,   213,   116,   153,   117,   380,   118,   136,   167,
     212,   104,   121,   162,     1,   122,   161,   175,   252,   254,
     149,   150,   151,   152,   176,   153,   191,   232,     2,   240,
     186,   190,   192,     3,     4,     5,   104,     6,   104,     7,
       8,     9,   204,   211,   364,   149,   150,   151,   152,    59,
     153,     5,   305,   242,   261,   330,   263,   308,   231,    59,
      59,    59,     5,   104,   256,   104,   264,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   265,   147,   305,
     266,   283,   306,   307,   308,   273,   267,    25,  -140,   196,
     197,   198,   199,   200,   276,   268,   269,    76,    77,    78,
      79,    80,    81,   270,   271,   282,    35,   272,    36,    37,
     274,   285,   275,    39,   104,   278,   279,   103,   280,   291,
     292,   296,    59,   315,    76,    77,    78,    79,    80,    81,
     298,   316,   318,   286,   320,   321,   323,   326,   324,   293,
     299,   334,   325,   339,   341,    82,   357,   377,   288,   104,
     365,   376,   314,   307,   128,    88,   281,   149,   150,   151,
     152,    96,   153,   209,   210,   349,   343,   107,   107,   375,
     297,   112,   348,   312,   313,   260,   338,   350,   378,   129,
     130,   382,   131,     0,   361,     0,     0,     0,     0,     0,
     327,     0,     0,   329,     0,   333,     0,   369,   337,   371,
     355,   373,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,    59,   345,   346,     0,     0,     0,     0,
     384,     0,   354,     0,     0,    59,   358,     0,   360,     0,
       0,   362,   368,     0,     0,     0,     0,   366,    59,   367,
      59,     0,    59,   370,   107,     0,     0,   374,     0,     0,
       0,     1,     0,     0,     0,     0,   379,     0,     0,   381,
       0,    59,     0,     0,   383,     2,   385,   107,   107,   107,
       3,     4,     5,     0,     6,     0,     7,     8,     9,   107,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,     0,     0,     0,
       0,     0,     0,     0,   107,     0,   107,     0,     0,     0,
       0,     0,     0,   244,   245,   246,     0,     0,   250,     0,
     251,   -42,     0,     0,    25,     0,     0,     0,     0,   258,
     259,   107,   262,   107,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    35,     0,    36,    37,     0,     0,     0,
      39,  -140,   -42,     0,   103,   -42,   -42,   -42,     0,   -42,
       0,     0,     0,     0,     0,     0,   -42,     0,     0,   -42,
       0,     0,     0,   -42,     0,   -42,     0,   -42,     0,   -42,
       0,     0,   107,     0,     0,   -42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,   -42,     0,   107,     0,     0,
     137,   138,   301,   140,   141,     0,   143,   144,     0,     0,
     311,   147,  -140,     1,     0,     0,  -140,   317,     0,     0,
       0,   319,     0,     0,     0,     0,     0,     2,     0,     0,
     328,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,  -140,  -140,  -140,  -140,     0,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,     0,     0,   347,     0,  -140,     0,  -140,
    -140,  -140,  -140,   356,  -140,     0,  -140,     0,  -140,     0,
    -140,     0,   258,     0,     0,     0,  -140,     0,  -140,     0,
    -140,     0,     0,     0,     0,  -140,    25,  -140,     0,     0,
     149,   150,   151,   152,     0,   153,    76,    77,    78,    79,
      80,    81,  -140,  -140,  -140,    35,     0,    36,    37,     0,
       0,  -140,    39,  -140,  -140,     0,   103,  -140,     1,     0,
       0,  -140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,   239,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,  -140,  -140,  -140,  -140,
       0,  -140,  -140,  -140,  -140,  -140,  -140,  -140,     0,     0,
       0,     0,  -140,     0,  -140,  -140,  -140,  -140,     0,  -140,
       0,  -140,     0,  -140,     0,  -140,     0,     0,     0,     0,
       0,  -140,     0,  -140,     0,  -140,     0,     0,     0,     0,
    -140,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,  -140,  -140,  -140,
      35,     0,    36,    37,  -140,     1,  -140,    39,  -140,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,  -140,  -140,  -140,  -140,     0,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,     0,     0,     0,     0,  -140,
       0,  -140,  -140,  -140,  -140,     0,  -140,     0,  -140,     0,
    -140,     0,  -140,     0,     0,     0,     0,     0,  -140,     0,
    -140,     0,  -140,     0,     0,     0,     0,  -140,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,  -140,  -140,  -140,    35,     1,    36,
      37,     0,     0,  -140,    39,     0,     0,     0,   103,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,   -92,     1,     0,
      35,   -67,    36,    37,     0,     0,     0,    39,     0,     0,
       0,   103,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,   -92,    12,
       0,   -92,   -92,   -92,    13,   -92,    14,    15,   149,   150,
     151,   152,   -92,   153,    16,   -92,    17,    18,     0,   -92,
       0,   -92,     0,   -92,     0,   -92,   187,   149,   150,   151,
     152,    21,   153,    22,   188,    23,   189,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,    36,    37,   -94,     1,    38,    39,   -67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,   -94,    12,     0,   -94,   -94,
     -94,    13,   -94,    14,    15,     0,     0,     0,     0,   -94,
       0,    16,   -94,    17,    18,     0,   -94,     0,   -94,     0,
     -94,     0,   -94,     0,     0,     0,     0,     0,    21,     0,
      22,     0,    23,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,    36,
      37,  -180,     1,    38,    39,   -67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,  -180,    12,     0,     0,     0,     0,    13,     0,
      14,    15,     0,     0,     0,     0,     0,     0,    16,     0,
      17,    18,     0,    19,     0,    -6,     0,    20,     0,    -6,
       0,     0,     0,     0,     0,    21,     0,    22,     0,    23,
       0,     0,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,  -184,     1,
      38,    39,   -67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,     0,     0,     0,     0,    16,     0,    17,    18,     0,
      19,     0,    -6,     0,    20,     0,    -6,     0,     0,     0,
       0,     0,    21,     0,    22,   -49,    23,     0,     0,     0,
       0,    24,    25,     0,     0,     0,   143,   144,     0,     0,
       0,   147,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,    36,    37,     0,   -49,    38,    39,   -49,
     -49,   -49,     0,   -49,     0,     0,     0,     0,     0,     0,
     -49,     0,     0,   -49,     0,     0,   -48,   -49,     0,   -49,
       0,   -49,     0,   -49,     0,     0,     0,   143,   144,   -49,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -48,     0,     0,
     -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,   -49,
       0,   -48,   151,   152,   -48,   153,     0,     0,   -48,     0,
     -48,     0,   -48,     0,   -48,     0,     0,     0,     0,     0,
     -48,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
     -48,     0,     0,   151,   152,     1,   153,     0,   -67,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     2,
     147,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,     0,    12,   169,     0,     0,
       0,    13,     0,    14,    15,    25,     0,     0,     0,     0,
       0,    16,     0,    17,    18,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    35,     0,    36,    37,     0,     0,
      22,    39,    23,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,   170,
     171,   151,   152,    38,   172,     1,     0,     0,   -67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
       0,    13,     0,    14,    15,     0,     0,     0,     0,     0,
       0,    16,     0,    17,    18,     0,    19,     0,    -6,     0,
      20,     0,    -6,     0,     0,     0,     0,     0,    21,     0,
      22,     0,    23,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     1,    36,
      37,   -67,     0,    38,    39,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,   253,    12,
       0,     0,     0,     0,    13,     0,    14,    15,     0,     0,
       0,     0,     0,     0,    16,     0,    17,    18,     0,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    21,   147,    22,     0,    23,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     1,    36,    37,   -67,     0,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,    13,     0,    14,
      15,     0,     0,     0,     0,     0,     0,    16,     0,    17,
      18,   149,   150,   151,   152,     0,   153,   322,   188,     0,
     189,     0,     0,     0,    21,     0,    22,     0,    23,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     1,    36,    37,    84,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,     0,
      13,     0,    14,    15,     0,     0,     0,     0,     0,     0,
      16,     0,    17,    18,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,     0,    -4,     0,    22,
       0,    23,     0,     0,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,    36,    37,
       0,     0,   241,    39,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,    84,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     147,     0,     0,     0,   149,   150,   151,   152,     0,   153,
       0,   188,     0,   189,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,    84,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
     147,     0,     0,     0,   149,   150,   151,   152,     0,   153,
       0,     0,     0,   294,     0,     0,     0,   149,   150,   151,
     152,    89,   153,     0,   332,     0,     0,     0,     0,   149,
     150,   151,   152,     0,   153,   284,   210,    84,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
       0,     0,     0,     0,   149,   150,   151,   152,     0,   153,
       0,   287,     0,     0,     0,     0,   149,   150,   151,   152,
       0,   153,     0,   340,     0,     0,     0,     0,   148,   149,
     150,   151,   152,    85,   153,    84,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   147,     0,     0,     0,     0,     0,     0,   149,   150,
     151,   152,    89,   153,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   147,     0,     0,
       0,     0,   344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   151,   152,
      85,   153,     0,     0,     0,     0,     0,     0,   149,   150,
     151,   152,     0,   153,   277,     0,     0,     0,     0,     0,
     149,   150,   151,   152,     0,   153,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   152,     0,   153,
       0,     0,     0,     0,     0,     0,   149,   150,   151,   152,
       0,   153
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-270)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   186,    21,    14,    15,   252,    71,    48,    13,     4,
       4,    25,     4,   103,    20,    45,    88,    13,    24,    24,
      25,    20,    31,    97,    11,    12,   100,    22,    11,    12,
      35,    20,    73,    16,    45,    11,    12,    81,    82,    48,
      16,   310,    22,    31,    22,    56,    57,    58,    48,    90,
      38,    62,    77,    78,    79,    20,    11,    12,    71,    24,
      73,    16,    98,    76,    31,    33,    34,    80,    54,    36,
      83,    71,    58,    73,   343,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    95,    69,    16,   101,    88,    85,
      90,    97,   361,   100,   279,   100,   101,   169,    97,   100,
      96,   348,    98,    99,    99,    99,   102,    99,     4,   100,
     124,   125,   126,   100,    97,    98,   181,   100,    98,   124,
     125,   126,   136,   100,   100,   100,   373,   100,   100,     0,
     135,   136,    97,   102,     1,   100,   100,    94,   179,   180,
      95,    96,    97,    98,   100,   100,    75,   161,    15,   163,
     102,   102,    75,    20,    21,    22,   161,    24,   163,    26,
      27,    28,   102,   101,   349,    95,    96,    97,    98,   169,
     100,    22,    31,   169,   188,    34,   190,    36,    20,   179,
     180,   181,    22,   188,    98,   190,    94,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    94,    16,    31,
     101,   242,    34,    35,    36,   210,   101,    74,    75,   114,
     115,   116,   117,   118,   225,   101,   101,    84,    85,    86,
      87,    88,    89,   101,   101,   239,    93,   102,    95,    96,
     100,    37,   101,   100,   239,   101,   100,   104,   100,    52,
      31,    20,   242,    52,    84,    85,    86,    87,    88,    89,
      94,    31,   101,   249,   101,   101,   101,    32,   101,   255,
     274,    45,   101,    64,    57,     2,   100,    31,   101,   274,
      47,   101,   291,    35,    35,    12,   238,    95,    96,    97,
      98,    18,   100,   101,   102,   334,   327,    24,    25,   364,
     272,    25,   333,   289,   290,   187,   315,   335,   371,    36,
      37,   377,    39,    -1,   345,    -1,    -1,    -1,    -1,    -1,
     306,    -1,    -1,   309,    -1,   311,    -1,   358,   314,   360,
     339,   362,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,
      -1,    -1,    -1,   333,   330,   331,    -1,    -1,    -1,    -1,
     381,    -1,   338,    -1,    -1,   345,   342,    -1,   344,    -1,
      -1,   347,   357,    -1,    -1,    -1,    -1,   353,   358,   355,
     360,    -1,   362,   359,   101,    -1,    -1,   363,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,   372,    -1,    -1,   375,
      -1,   381,    -1,    -1,   380,    15,   382,   124,   125,   126,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,   170,   171,   172,    -1,    -1,   175,    -1,
     177,     0,    -1,    -1,    74,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    93,    -1,    95,    96,    -1,    -1,    -1,
     100,   101,    31,    -1,   104,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,   239,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,   274,    -1,    -1,
       5,     6,   279,     8,     9,    -1,    11,    12,    -1,    -1,
     287,    16,     0,     1,    -1,    -1,     4,   294,    -1,    -1,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
     307,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,   332,    -1,    45,    -1,    47,
      48,    49,    50,   340,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,   349,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    73,    74,    75,    -1,    -1,
      95,    96,    97,    98,    -1,   100,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    -1,
      -1,    99,   100,   101,   102,    -1,   104,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    -1,    52,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,     0,     1,    99,   100,     4,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    -1,    52,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     1,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,     0,     1,    -1,
      93,     4,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
      -1,   104,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    95,    96,
      97,    98,    45,   100,    47,    48,    49,    50,    -1,    52,
      -1,    54,    -1,    56,    -1,    58,    94,    95,    96,    97,
      98,    64,   100,    66,   102,    68,   104,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,     0,     1,    99,   100,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    -1,    52,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,     0,     1,    99,   100,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,     0,     1,
      99,   100,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
      52,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,     0,    68,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    -1,    31,    99,   100,    34,
      35,    36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    48,    -1,    -1,     0,    52,    -1,    54,
      -1,    56,    -1,    58,    -1,    -1,    -1,    11,    12,    64,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    36,    -1,    38,    -1,    -1,    -1,    -1,    94,
      -1,    45,    97,    98,    48,   100,    -1,    -1,    52,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      94,    -1,    -1,    97,    98,     1,   100,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    -1,
      -1,    37,    -1,    39,    40,    74,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    93,    -1,    95,    96,    -1,    -1,
      66,   100,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,   100,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    52,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     1,    95,
      96,     4,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    64,    16,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     1,    95,    96,     4,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     1,    95,    96,     4,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      -1,    -1,    99,   100,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
      -1,   102,    -1,   104,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,   102,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    20,    21,    22,    24,    26,    27,    28,
      29,    30,    32,    37,    39,    40,    47,    49,    50,    52,
      56,    64,    66,    68,    73,    74,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    95,    96,    99,   100,
     107,   111,   112,   115,   116,   117,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   135,   136,   137,   138,
     139,   141,   142,   147,   148,   149,   151,   154,   156,   161,
     163,   164,   165,   166,   167,   103,    84,    85,    86,    87,
      88,    89,   117,   138,     4,    99,   106,   118,   117,    99,
     106,   112,   118,   118,    45,    20,   117,    22,   162,   162,
      98,   140,    69,   104,   112,   113,   114,   117,   143,   144,
     145,   145,   147,   100,   100,   100,   100,   100,   100,    20,
      24,    97,   100,   133,   134,   134,   134,   112,   115,   117,
     117,   117,   146,    54,    58,   160,   100,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    16,    94,    95,
      96,    97,    98,   100,   118,     4,   128,   118,   118,   118,
      97,   100,   102,   109,   118,   165,   128,     0,   106,    33,
      95,    96,   100,   121,   128,    94,   100,   129,   118,   106,
     106,   106,    98,   112,   145,   106,   102,    94,   102,   104,
     102,    75,    75,    81,    82,   110,   110,   110,   110,   110,
     110,    20,    97,   132,   102,   131,   145,   145,   145,   101,
     102,   101,   112,   145,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,    20,   145,    71,    73,    76,    80,    83,   108,    17,
     145,    99,   106,   121,   117,   117,   117,    31,    38,   153,
     117,   117,   128,    31,   128,   165,    98,   114,   117,   117,
     149,   145,   117,   145,    94,    94,   101,   101,   101,   101,
     101,   101,   102,   112,   100,   101,   118,   101,   101,   100,
     100,   109,   145,   128,   101,    37,   106,   102,   101,   130,
     153,    52,    31,   106,   104,   117,    20,   133,    94,   145,
     114,   117,    77,    78,    79,    31,    34,    35,    36,   150,
     152,   117,   106,   106,   162,    52,    31,   117,   101,   117,
     101,   101,   101,   101,   101,   101,    32,   106,   117,   106,
      34,   150,   102,   106,    45,   157,   158,   106,   162,    64,
     102,    57,   159,   128,    33,   106,   106,   117,   128,   129,
     158,    31,    48,   155,   106,   162,   117,   100,   106,   150,
     106,   128,   106,   153,   114,    47,   106,   106,   112,   128,
     106,   128,   150,   128,   106,   130,   101,    31,   152,   106,
     153,   106,   160,   106,   128,   106
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

			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 158 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 163 "for90.y"
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
#line 176 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				newnode.setattr(new VariableDescAttr());
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 184 "for90.y"
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
#line 195 "for90.y"
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
#line 209 "for90.y"
    {
				/* 该条目下的右部全部为单个终结符号(语法树的叶子节点), 因此$1全部来自lex程序 */
				(yyval) = gen_token(Term{ TokenMeta::Float, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// float number
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 214 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Int, (yyvsp[(1) - (1)]).fs.CurrentTerm.what });// int number
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 218 "for90.y"
    {
				// replace `'` with `"`
				(yyval) = gen_token(Term{ TokenMeta::String, "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"" }); // string
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 223 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "true" });// bool true
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 227 "for90.y"
    {
				(yyval) = gen_token(Term{ TokenMeta::Bool, "false" });// bool false
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 231 "for90.y"
    {
				string strcplx = (yyvsp[(1) - (1)]).fs.CurrentTerm.what;
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " }); //complex
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 240 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, (yyvsp[(1) - (1)]).fs.CurrentTerm.what }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 247 "for90.y"
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
#line 256 "for90.y"
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
#line 266 "for90.y"
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
#line 275 "for90.y"
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
#line 285 "for90.y"
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
#line 295 "for90.y"
    {
				/* argtable is used in function call */
				ParseNode & exp = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_ARGTABLE_PURE, exp);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 302 "for90.y"
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
#line 322 "for90.y"
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

  case 37:
/* Line 1792 of yacc.c  */
#line 343 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 347 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 352 "for90.y"
    {
				/* function call OR array index */
				ParseNode & function_array = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, function_array);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 359 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ParseNode & array_builder_elem = (yyvsp[(1) - (1)]);
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 367 "for90.y"
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
#line 375 "for90.y"
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
#line 383 "for90.y"
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
#line 391 "for90.y"
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
#line 399 "for90.y"
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
#line 407 "for90.y"
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
#line 415 "for90.y"
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
#line 423 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "(-%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 430 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op,  "%s");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 437 "for90.y"
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
#line 445 "for90.y"
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
#line 454 "for90.y"
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
#line 462 "for90.y"
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
#line 471 "for90.y"
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
#line 479 "for90.y"
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
#line 487 "for90.y"
    {
				ParseNode & exp1 = (yyvsp[(2) - (2)]);
				ParseNode & op = (yyvsp[(1) - (2)]);
				(yyval) = gen_exp(exp1, op, "!(%s)");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 494 "for90.y"
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
#line 502 "for90.y"
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
#line 510 "for90.y"
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
#line 518 "for90.y"
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
#line 526 "for90.y"
    {
				ParseNode & hidden_do = (yyvsp[(1) - (1)]);
				(yyval) = gen_promote(TokenMeta::NT_EXPRESSION, hidden_do);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 532 "for90.y"
    { 
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 537 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 547 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 551 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::Nop, "" };
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 556 "for90.y"
    {
			(yyval) = gen_label((yyvsp[(1) - (1)]));
			update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
		}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 562 "for90.y"
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
#line 572 "for90.y"
    {
				/* 因为var_def本身可能生成多行代码, 因此此处生成代码不应当带分号`;` */
				(yyval) = gen_stmt((yyvsp[(1) - (2)]), "%s ");
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 578 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 582 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 586 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 590 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 594 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 599 "for90.y"
    {
				(yyval) = gen_stmt((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 604 "for90.y"
    {
				ParseNode & xx = (yyvsp[(1) - (2)]);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 609 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 614 "for90.y"
    {
				(yyval) = gen_format((yyvsp[(1) - (2)]));
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 619 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 638 "for90.y"
    {
				(yyval) = gen_token(Term{TokenMeta::Goto, "goto " + (yyvsp[(1) - (3)]).fs.CurrentTerm.what + ";\n"});
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 644 "for90.y"
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
#line 653 "for90.y"
    {
				// dummy stmt
				(yyval) = gen_token(Term{ TokenMeta::NT_STATEMENT, "" });
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 660 "for90.y"
    {
				(yyval) = gen_promote("%s\n", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 665 "for90.y"
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
#line 686 "for90.y"
    {
				(yyval) = gen_promote("", TokenMeta::NT_SUITE, (yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 691 "for90.y"
    {
				(yyval) = gen_flattern((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), "%s%s", TokenMeta::NT_SUITE);
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 705 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, "-1" }; // -1 stands for stdin/stdout, and will be translated at read/write stmt
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 709 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::META_NONTERMINAL, (yyvsp[(1) - (1)]).fs.CurrentTerm.what };
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 713 "for90.y"
    {
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_AUTOFORMATTER, "" };
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 717 "for90.y"
    {
				// use format stmt at line $1 to format
				require_format_index((yyvsp[(1) - (1)]).fs.CurrentTerm.what);
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 722 "for90.y"
    {
				// replace `'` with `"`
				string modified = "\"" + (yyvsp[(1) - (1)]).fs.CurrentTerm.what.substr(1, (yyvsp[(1) - (1)]).fs.CurrentTerm.what.size() - 2) + "\"";
				(yyval).fs.CurrentTerm = Term{ TokenMeta::NT_FORMATTER, modified };
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 729 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
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
#line 740 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::META_NONTERMINAL, "" }), nullptr);
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
#line 754 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_write(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 762 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_print(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				ParseNode & io_info = (yyvsp[(2) - (3)]);
				ParseNode & argtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_read(io_info, argtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 779 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 784 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 789 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 794 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 799 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 804 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (1)]));
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 810 "for90.y"
    {
				// now translated in pre_map
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 816 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 821 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 826 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 831 "for90.y"
    {
				(yyval) = gen_type((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 836 "for90.y"
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
#line 844 "for90.y"
    {
				// $$ = gen_type($1, $3);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 851 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 856 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 862 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr);// variant
				(yyval) = newnode;
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 868 "for90.y"
    {
				ParseNode & blockname = (yyvsp[(2) - (3)]);
				ParseNode & paramtable = (yyvsp[(3) - (3)]);
				(yyval) = gen_common(blockname, paramtable);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 876 "for90.y"
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
#line 886 "for90.y"
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
#line 896 "for90.y"
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
#line 907 "for90.y"
    { 
				// useless reduction
				/* paramtable is used in function decl */
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 912 "for90.y"
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
#line 921 "for90.y"
    {
				// array initial values 
				// 因为使用forarray作为数组, 故需要知道类型信息, 不在此处赋值, 在上层的var_def赋初值 
				(yyval) = gen_keyvalue_from_arraybuilder((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 930 "for90.y"
    {
				// from rule ` dimen_slice : exp ',' paramtable `
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 934 "for90.y"
    {
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 938 "for90.y"
    {
				ParseNode & paramtable_elem = (yyvsp[(1) - (1)]);
				ParseNode & newnode = gen_paramtable(paramtable_elem);
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 945 "for90.y"
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
#line 953 "for90.y"
    {
				/* no params */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE, "" });
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 961 "for90.y"
    {
				/* something like `abs(i), i=1,4` */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_HIDDENDO, "" });
				newnode.addchild((yyvsp[(1) - (7)])); // exp
				newnode.addchild((yyvsp[(3) - (7)])); // index variable
				newnode.addchild((yyvsp[(5) - (7)])); // exp_from
				newnode.addchild((yyvsp[(7) - (7)])); // exp_to
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 973 "for90.y"
    {
				/*
				R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
				R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ■
				■ scalar - int - expr[, scalar - int - expr]
				*/
				ParseNode & _generate_stmt = (yyvsp[(2) - (3)]);
				(yyval) = gen_hiddendo(_generate_stmt);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 985 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = gen_array_from_paramtable((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 992 "for90.y"
    {
				/* give generate stmt */
				(yyval) = gen_array_from_hiddendo((yyvsp[(2) - (3)]));
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				// rule `YY_ARRAYINITIAL_START variable '(' dimen_slice ')' YY_ARRAYINITIAL_END ` is included in this rule because \
				// these two rules can not be splitted because `exp` and `variable` + '(' can cause reduction conflict 
				// so either that `variable '(' dimen_slice ')'` is an `exp`
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1003 "for90.y"
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

  case 148:
/* Line 1792 of yacc.c  */
#line 1043 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (7)]);
				ParseNode & suite_true = (yyvsp[(5) - (7)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1050 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (10)]);
				ParseNode & suite_true = (yyvsp[(5) - (10)]); 
				ParseNode & suite_else = (yyvsp[(8) - (10)]); 
				(yyval) = gen_if(exp, suite_true, gen_dummy(), suite_else);
				update_pos((yyval), (yyvsp[(1) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1058 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (8)]);
				ParseNode & suite_true = (yyvsp[(5) - (8)]);
				ParseNode & elseif = (yyvsp[(6) - (8)]);
				(yyval) = gen_if(exp, suite_true, elseif, gen_dummy());
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1066 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (11)]);
				ParseNode & suite_true = (yyvsp[(5) - (11)]);
				ParseNode & elseif = (yyvsp[(6) - (11)]);
				ParseNode & suite_else = (yyvsp[(9) - (11)]);
				(yyval) = gen_if(exp, suite_true, elseif, suite_else);
				update_pos((yyval), (yyvsp[(1) - (11)]), (yyvsp[(11) - (11)]));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1075 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (4)]);
				ParseNode & stmt_true = (yyvsp[(4) - (4)]); 
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1082 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (3)]);
				ParseNode & stmt_true = (yyvsp[(3) - (3)]);
				(yyval) = gen_if_oneline(exp, stmt_true);
				update_pos((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1090 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (5)]);
				ParseNode & suite_true = (yyvsp[(5) - (5)]);
				(yyval) = gen_elseif(exp, suite_true, gen_dummy());;
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1098 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite_true = (yyvsp[(5) - (6)]);
				ParseNode & elseif = (yyvsp[(6) - (6)]);
				(yyval) = gen_elseif(exp, suite_true, elseif);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1110 "for90.y"
    {
				ParseNode & suite = (yyvsp[(3) - (5)]); 
				(yyval) = gen_do(suite);
				update_pos((yyval), (yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1116 "for90.y"
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

  case 160:
/* Line 1792 of yacc.c  */
#line 1126 "for90.y"
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

  case 161:
/* Line 1792 of yacc.c  */
#line 1136 "for90.y"
    {
				ParseNode & exp = (yyvsp[(2) - (6)]);
				ParseNode & suite = (yyvsp[(4) - (6)]); 
				(yyval) = gen_do_while(exp, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1147 "for90.y"
    {
				ParseNode & select = (yyvsp[(1) - (9)]);
				ParseNode & exp = (yyvsp[(4) - (9)]);
				ParseNode & case_stmt = (yyvsp[(7) - (9)]);
				(yyval) = gen_select(exp, case_stmt);
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1155 "for90.y"
    {
				// one case
				ParseNode & dimen_slice = (yyvsp[(3) - (6)]);
				ParseNode & suite = (yyvsp[(6) - (6)]); 
				(yyval) = gen_case(dimen_slice, suite);
				update_pos((yyval), (yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1163 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (1)]);
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_CASES, "" }), nullptr);
				newnode.addchild(case_stmt_elem); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1171 "for90.y"
    {
				ParseNode & case_stmt_elem = (yyvsp[(1) - (2)]);
				ParseNode & case_stmt = (yyvsp[(2) - (2)]);
				ParseNode newnode = ParseNode(case_stmt);
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_CASES, "" };
				newnode.addchild(case_stmt_elem, false /* add to the front of the vector */); // case_stmt_elem
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1182 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1187 "for90.y"
    {
				ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::UnknownVariant, "" }), nullptr); // return nothing
				(yyval) = newnode;
				update_pos((yyval));
			}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1197 "for90.y"
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

  case 175:
/* Line 1792 of yacc.c  */
#line 1213 "for90.y"
    {
				ParseNode & suite = (yyvsp[(4) - (8)]);
				(yyval) = gen_program_explicit(suite);
				update_pos((yyval), (yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1219 "for90.y"
    {
				(yyval) = gen_program_explicit(gen_token(Term{TokenMeta::NT_PROGRAM_EXPLICIT , ""}));
				update_pos((yyval), (yyvsp[(1) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1229 "for90.y"
    {
				ParseNode & suite = (yyvsp[(1) - (1)]);
				(yyval) = gen_program(suite);
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1237 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1242 "for90.y"
    {
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1248 "for90.y"
    {
				ParseNode newnode = ParseNode();
				newnode.addchild((yyvsp[(1) - (1)])); // wrapper
				sprintf(codegen_buf, "%s", (yyvsp[(1) - (1)]).fs.CurrentTerm.what.c_str());
				newnode.fs.CurrentTerm = Term{ TokenMeta::NT_WRAPPERS, string(codegen_buf) };
				(yyval) = newnode;
				update_pos((yyval), (yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1257 "for90.y"
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

  case 182:
/* Line 1792 of yacc.c  */
#line 1269 "for90.y"
    {
				(yyval) = gen_interface((yyvsp[(4) - (9)]));
				update_pos((yyval), (yyvsp[(1) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1275 "for90.y"
    {
				gen_fortran_program((yyvsp[(1) - (1)]));
			}
    break;


/* Line 1792 of yacc.c  */
#line 3883 "for90.tab.cpp"
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
#line 1281 "for90.y"

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
