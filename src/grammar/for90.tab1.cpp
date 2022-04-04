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

#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
#include <tuple>
#include <stdint.h>
#include "../parser/attribute.h"
#include "../parser/parser.h"
#include "../target/gen_common.h"
#include "../parser/Function.h"


void yyerror(const char* s); 

#ifdef USE_LEX
int pure_yylex(void);
void set_buff(const std::string & code);
void release_buff();
#else
#include "simple_lexer.h"
#endif

#define YYDEBUG 1
#define YYERROR_VERBOSE
#define YYINITDEPTH 2000

// update pos os non-terminal tokens(terminal tokens have pos updated in flex using update_flex and update_yylval) 
void update_pos(ParseNode & current) {
	if (current.length() == 0) {
		// do nothing 
		current.fs.parse_pos = 0;
		current.fs.parse_line = 0;
		current.fs.parse_len = 0;
		current.fs.line_pos = 0;
	}
	else if (current.length() == 1) {
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = current.get(0).fs.parse_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
	else {
		int tot_len = 0;
		for (int i = 0; i < current.length(); i++)
		{
			tot_len += current.get(i).fs.parse_len;
		}
		current.fs.parse_pos = current.get(0).fs.parse_pos;
		current.fs.parse_line = current.get(0).fs.parse_line;
		current.fs.parse_len = tot_len;
		current.fs.line_pos = current.get(0).fs.line_pos;
	}
}
void update_pos(ParseNode & current, const ParseNode & start, const ParseNode & end) {
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
using namespace std;

/* Line 371 of yacc.c  */
#line 147 "for90.tab.cpp"

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
     YY_EXPONENT = 275,
     YY_INTEGER = 276,
     YY_FLOAT = 277,
     YY_WORD = 278,
     YY_OPERATOR = 279,
     YY_STRING = 280,
     YY_ILLEGAL = 281,
     YY_COMPLEX = 282,
     YY_TRUE = 283,
     YY_FALSE = 284,
     YY_FORMAT_STMT = 285,
     YY_COMMENT = 286,
     YY_LABEL = 287,
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
     YY_EXIT = 298,
     YY_CYCLE = 299,
     YY_WHILE = 300,
     YY_ENDWHILE = 301,
     YY_WHERE = 302,
     YY_ENDWHERE = 303,
     YY_CASE = 304,
     YY_ENDCASE = 305,
     YY_SELECT = 306,
     YY_ENDSELECT = 307,
     YY_GOTO = 308,
     YY_DOWHILE = 309,
     YY_DEFAULT = 310,
     YY_TYPE = 311,
     YY_ENDTYPE = 312,
     YY_PROGRAM = 313,
     YY_ENDPROGRAM = 314,
     YY_FUNCTION = 315,
     YY_ENDFUNCTION = 316,
     YY_RECURSIVE = 317,
     YY_RESULT = 318,
     YY_SUBROUTINE = 319,
     YY_ENDSUBROUTINE = 320,
     YY_MODULE = 321,
     YY_ENDMODULE = 322,
     YY_BLOCK = 323,
     YY_ENDBLOCK = 324,
     YY_INTERFACE = 325,
     YY_ENDINTERFACE = 326,
     YY_COMMON = 327,
     YY_DATA = 328,
     YY_IMPLICIT = 329,
     YY_NONE = 330,
     YY_USE = 331,
     YY_PARAMETER = 332,
     YY_ENTRY = 333,
     YY_DIMENSION = 334,
     YY_ARRAYBUILDER_START = 335,
     YY_ARRAYBUILDER_END = 336,
     YY_INTENT = 337,
     YY_IN = 338,
     YY_OUT = 339,
     YY_INOUT = 340,
     YY_OPTIONAL = 341,
     YY_LEN = 342,
     YY_KIND = 343,
     YY_SAVE = 344,
     YY_ALLOCATABLE = 345,
     YY_TARGET = 346,
     YY_POINTER = 347,
     YY_INTEGER_T = 348,
     YY_FLOAT_T = 349,
     YY_STRING_T = 350,
     YY_COMPLEX_T = 351,
     YY_BOOL_T = 352,
     YY_CHARACTER_T = 353,
     YY_DOUBLE_T = 354,
     YY_WRITE = 355,
     YY_READ = 356,
     YY_PRINT = 357,
     YY_CALL = 358,
     YY_STOP = 359,
     YY_PAUSE = 360,
     YY_RETURN = 361,
     YY_CONFIG_IMPLICIT = 362,
     YY_ALLOCATE = 363
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
#line 321 "for90.tab.cpp"

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
#define YYFINAL  161
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  197
/* YYNRULES -- Number of states.  */
#define YYNSTATES  381

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     118,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     114,   115,   111,   109,   116,   110,     2,   112,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   119,   113,
       2,   117,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    20,    25,    30,    35,    40,    45,    47,    49,    51,
      53,    55,    57,    61,    62,    66,    70,    72,    76,    78,
      80,    82,    84,    86,    89,    91,    95,   101,   103,   107,
     109,   113,   115,   119,   123,   127,   132,   137,   139,   142,
     145,   147,   149,   153,   157,   161,   165,   169,   173,   176,
     179,   183,   187,   191,   195,   199,   203,   206,   210,   214,
     218,   222,   226,   228,   230,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   255,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   284,   287,   289,   292,   294,   298,   301,   307,   310,
     315,   317,   321,   323,   327,   329,   333,   335,   337,   339,
     341,   343,   349,   352,   356,   360,   364,   366,   368,   370,
     372,   374,   376,   378,   383,   387,   389,   393,   396,   397,
     401,   406,   410,   413,   415,   419,   423,   427,   428,   430,
     432,   434,   444,   448,   450,   453,   454,   461,   472,   482,
     495,   506,   520,   528,   537,   539,   540,   547,   560,   575,
     583,   593,   600,   607,   612,   619,   621,   624,   629,   630,
     632,   634,   636,   638,   640,   651,   658,   660,   661,   668,
     670,   672,   674,   676,   678,   680,   684,   692
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     183,     0,    -1,     4,    -1,    -1,   124,    -1,   122,   124,
      -1,   113,    -1,     4,    -1,   123,    -1,    62,    -1,    -1,
      82,   114,    83,   115,    -1,    82,   114,    84,   115,    -1,
      82,   114,    85,   115,    -1,    79,   114,   162,   115,    -1,
      79,   114,   137,   115,    -1,    79,    -1,    86,    -1,    77,
      -1,    89,    -1,    90,    -1,    91,    -1,   116,   126,   127,
      -1,    -1,    88,   117,    21,    -1,    87,   117,   137,    -1,
      22,    -1,    21,    20,    21,    -1,    21,    -1,    25,    -1,
      28,    -1,    29,    -1,    27,    -1,     1,   118,    -1,    23,
      -1,   137,   119,   137,    -1,   137,   119,   137,   119,   137,
      -1,   119,    -1,   137,   117,   137,    -1,   137,    -1,   133,
     116,   137,    -1,   131,    -1,   134,   116,   131,    -1,   134,
     116,   137,    -1,   133,   116,   131,    -1,   130,   114,   162,
     115,    -1,   156,   114,   162,   115,    -1,   135,    -1,   103,
     135,    -1,   103,   130,    -1,   136,    -1,   165,    -1,   114,
     137,   115,    -1,   137,   109,   137,    -1,   137,   110,   137,
      -1,   137,   111,   137,    -1,   137,   112,   137,    -1,   137,
      16,   137,    -1,   110,   137,    -1,   109,   137,    -1,   137,
      10,   137,    -1,   137,    11,   137,    -1,   137,     7,   137,
      -1,   137,    12,   137,    -1,   137,    13,   137,    -1,   137,
      14,   137,    -1,    15,   137,    -1,   137,     5,   137,    -1,
     137,     6,   137,    -1,   137,     8,   137,    -1,   137,     9,
     137,    -1,   137,    24,   137,    -1,   163,    -1,   129,    -1,
     130,    -1,   137,    -1,   160,    -1,   141,    -1,   140,    -1,
     146,    -1,   145,    -1,   159,    -1,    30,    -1,    31,    -1,
     139,    -1,   148,    -1,    -1,   143,    -1,   144,    -1,    41,
      -1,   106,    -1,   142,    -1,   153,    -1,   154,    -1,   155,
      -1,   167,    -1,   170,    -1,   171,    -1,    44,    -1,    43,
      -1,    53,    21,    -1,   105,   129,    -1,   105,    -1,   104,
     129,    -1,   104,    -1,   137,   117,   137,    -1,    74,    75,
      -1,    74,   156,   114,   162,   115,    -1,    32,   138,    -1,
     108,   114,   162,   115,    -1,   147,    -1,   147,   124,   149,
      -1,   138,    -1,   138,   124,   149,    -1,   182,    -1,   182,
     124,   149,    -1,   111,    -1,    21,    -1,   111,    -1,    21,
      -1,    25,    -1,   114,   150,   116,   151,   115,    -1,   151,
     116,    -1,   100,   152,   162,    -1,   102,   152,   162,    -1,
     101,   152,   162,    -1,    93,    -1,    94,    -1,    99,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,   156,   114,
     128,   115,    -1,   156,   111,    21,    -1,   156,    -1,   112,
      23,   112,    -1,   112,   112,    -1,    -1,    72,   158,   162,
      -1,   157,   127,    17,   162,    -1,   157,   127,   162,    -1,
     126,   162,    -1,   132,    -1,   161,   116,   132,    -1,   161,
     116,   137,    -1,   133,   116,   132,    -1,    -1,   161,    -1,
     133,    -1,   134,    -1,   114,   133,   116,   130,   117,   137,
     116,   137,   115,    -1,    80,   162,    81,    -1,   164,    -1,
      23,   119,    -1,    -1,   166,    34,   114,   137,   115,   138,
      -1,   166,    34,   114,   137,   115,    21,   116,    21,   116,
      21,    -1,   166,    34,   114,   137,   115,    35,   122,   149,
      38,    -1,   166,    34,   114,   137,   115,    35,   122,   149,
      36,   122,   149,    38,    -1,   166,    34,   114,   137,   115,
      35,   122,   149,   168,    38,    -1,   166,    34,   114,   137,
     115,    35,   122,   149,   168,    36,   122,   149,    38,    -1,
      37,   114,   137,   115,    35,   122,   149,    -1,    37,   114,
     137,   115,    35,   122,   149,   168,    -1,    21,    -1,    -1,
     166,    39,   122,   149,   121,    40,    -1,   166,    39,   169,
     130,   117,   137,   116,   137,   122,   149,   121,    40,    -1,
     166,    39,   169,   130,   117,   137,   116,   137,   116,   137,
     122,   149,   121,    40,    -1,   166,    54,   137,   122,   149,
     121,    40,    -1,   166,    51,    49,   114,   137,   115,   122,
     173,    52,    -1,    49,   114,   134,   115,   122,   149,    -1,
      49,   114,   133,   115,   122,   149,    -1,    49,    55,   122,
     149,    -1,    49,   114,    55,   115,   122,   149,    -1,   172,
      -1,   172,   173,    -1,    63,   114,   130,   115,    -1,    -1,
      60,    -1,    64,    -1,    61,    -1,    65,    -1,    33,    -1,
     125,   175,    23,   114,   162,   115,   174,   122,   149,   176,
      -1,   125,   175,    23,   122,   149,   176,    -1,    23,    -1,
      -1,    58,   178,   122,   149,    59,   178,    -1,   179,    -1,
     177,    -1,   138,    -1,   147,    -1,    33,    -1,   180,    -1,
     180,   122,   181,    -1,    70,   178,   122,   181,   121,    71,
     178,    -1,   181,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   152,   157,   163,   170,   177,   182,   188,
     194,   199,   207,   216,   224,   236,   250,   259,   267,   276,
     285,   294,   304,   319,   332,   345,   361,   369,   378,   385,
     394,   400,   406,   416,   424,   440,   450,   461,   473,   484,
     493,   511,   524,   546,   568,   592,   603,   615,   620,   626,
     646,   655,   662,   671,   681,   691,   701,   711,   721,   730,
     739,   749,   760,   770,   781,   791,   801,   810,   820,   830,
     839,   849,   869,   876,   896,   902,   914,   920,   926,   932,
     937,   944,   950,   958,   965,   971,   978,   983,   989,   995,
    1001,  1007,  1014,  1019,  1024,  1030,  1035,  1040,  1046,  1052,
    1058,  1066,  1073,  1080,  1087,  1094,  1105,  1112,  1123,  1142,
    1151,  1159,  1173,  1180,  1193,  1201,  1213,  1223,  1230,  1239,
    1248,  1282,  1295,  1310,  1320,  1331,  1341,  1347,  1353,  1359,
    1365,  1371,  1377,  1384,  1391,  1397,  1403,  1409,  1417,  1423,
    1432,  1444,  1454,  1511,  1519,  1527,  1536,  1546,  1553,  1558,
    1563,  1569,  1587,  1597,  1605,  1612,  1620,  1632,  1638,  1647,
    1657,  1667,  1679,  1689,  1700,  1706,  1711,  1719,  1743,  1755,
    1765,  1776,  1787,  1798,  1806,  1816,  1824,  1834,  1841,  1847,
    1852,  1858,  1863,  1868,  1874,  1889,  1902,  1908,  1913,  1921,
    1926,  1936,  1943,  1948,  1956,  1964,  1982,  1990
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
  "YY_POS", "YY_EXPONENT", "YY_INTEGER", "YY_FLOAT", "YY_WORD",
  "YY_OPERATOR", "YY_STRING", "YY_ILLEGAL", "YY_COMPLEX", "YY_TRUE",
  "YY_FALSE", "YY_FORMAT_STMT", "YY_COMMENT", "YY_LABEL", "YY_END",
  "YY_IF", "YY_THEN", "YY_ELSE", "YY_ELSEIF", "YY_ENDIF", "YY_DO",
  "YY_ENDDO", "YY_CONTINUE", "YY_BREAK", "YY_EXIT", "YY_CYCLE", "YY_WHILE",
  "YY_ENDWHILE", "YY_WHERE", "YY_ENDWHERE", "YY_CASE", "YY_ENDCASE",
  "YY_SELECT", "YY_ENDSELECT", "YY_GOTO", "YY_DOWHILE", "YY_DEFAULT",
  "YY_TYPE", "YY_ENDTYPE", "YY_PROGRAM", "YY_ENDPROGRAM", "YY_FUNCTION",
  "YY_ENDFUNCTION", "YY_RECURSIVE", "YY_RESULT", "YY_SUBROUTINE",
  "YY_ENDSUBROUTINE", "YY_MODULE", "YY_ENDMODULE", "YY_BLOCK",
  "YY_ENDBLOCK", "YY_INTERFACE", "YY_ENDINTERFACE", "YY_COMMON", "YY_DATA",
  "YY_IMPLICIT", "YY_NONE", "YY_USE", "YY_PARAMETER", "YY_ENTRY",
  "YY_DIMENSION", "YY_ARRAYBUILDER_START", "YY_ARRAYBUILDER_END",
  "YY_INTENT", "YY_IN", "YY_OUT", "YY_INOUT", "YY_OPTIONAL", "YY_LEN",
  "YY_KIND", "YY_SAVE", "YY_ALLOCATABLE", "YY_TARGET", "YY_POINTER",
  "YY_INTEGER_T", "YY_FLOAT_T", "YY_STRING_T", "YY_COMPLEX_T", "YY_BOOL_T",
  "YY_CHARACTER_T", "YY_DOUBLE_T", "YY_WRITE", "YY_READ", "YY_PRINT",
  "YY_CALL", "YY_STOP", "YY_PAUSE", "YY_RETURN", "YY_CONFIG_IMPLICIT",
  "YY_ALLOCATE", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','",
  "'='", "'\\n'", "':'", "$accept", "crlf_or_not", "at_least_one_end_line",
  "semicolon", "end_of_stmt", "dummy_function_iden", "variable_desc_elem",
  "variable_desc", "type_selector", "literal", "variable", "slice",
  "keyvalue", "argtable", "dimen_slice", "function_array_body",
  "function_array", "exp", "stmt", "control_stmt", "io_stmt",
  "compound_stmt", "jump_stmt", "pause_stmt", "stop_stmt", "let_stmt",
  "implicit_stmt", "labeled_stmts", "allocate_stmt", "suite",
  "_optional_device", "_optional_formatter", "io_info", "write", "print",
  "read", "type_name", "type_spec", "_blockname_or_none", "common_stmt",
  "var_def", "pure_paramtable", "paramtable", "hidden_do",
  "array_builder_elem", "array_builder", "_optional_construct_name",
  "if_stmt", "elseif_stmt", "_optional_label_construct", "do_stmt",
  "select_stmt", "case_stmt_elem", "case_stmt", "_optional_result",
  "_optional_function", "_optional_endfunction", "function_decl",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    43,
      45,    42,    47,    59,    40,    41,    44,    61,    10,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   120,   121,   121,   122,   122,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   131,   131,   131,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   136,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   139,
     139,   139,   140,   140,   140,   141,   141,   141,   142,   142,
     142,   143,   143,   144,   144,   145,   146,   146,   147,   148,
     149,   149,   149,   149,   149,   149,   150,   150,   151,   151,
     151,   152,   152,   153,   154,   155,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   157,   158,   158,   158,   159,
     160,   160,   160,   161,   161,   161,   161,   161,   162,   162,
     162,   163,   164,   165,   166,   166,   167,   167,   167,   167,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   170,
     171,   172,   172,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   176,   177,   177,   178,   178,   179,   180,
     180,   180,   180,   180,   181,   181,   182,   183
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       0,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     3,     0,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     3,     5,     1,     3,     1,
       3,     1,     3,     3,     3,     4,     4,     1,     2,     2,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     1,     3,     2,     5,     2,     4,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     5,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     1,     3,     2,     0,     3,
       4,     3,     2,     1,     3,     3,     3,     0,     1,     1,
       1,     9,     3,     1,     2,     0,     6,    10,     9,    12,
      10,    13,     7,     8,     1,     0,     6,    12,    14,     7,
       9,     6,     6,     4,     6,     1,     2,     4,     0,     1,
       1,     1,     1,     1,    10,     6,     1,     0,     6,     1,
       1,     1,     1,     1,     1,     3,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    28,    26,    34,    29,    32,    30,    31,
      82,    83,     0,   193,    89,    99,    98,     0,   187,     9,
     138,     0,    18,    16,     0,     0,    17,    19,    20,    21,
     126,   127,   129,   130,   131,   132,   128,     0,     0,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
      73,    74,    47,    50,    75,   191,    84,    78,    77,    91,
      87,    88,    80,    79,   192,    85,    92,    93,    94,   135,
      23,    81,    76,    72,   153,    51,     0,    95,    96,    97,
     190,   189,   194,   197,     0,    33,    34,    66,     0,     0,
     154,   108,   100,   186,     0,     0,     0,   106,     0,     0,
      37,    41,   143,   149,   150,    39,   148,     0,     0,   119,
     120,   118,     0,     0,     0,     0,     0,    49,    48,   103,
     101,     0,    59,    58,     0,    39,   179,   180,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     7,     6,     0,     8,
       4,     1,     0,    27,     0,     0,   137,   139,     0,    39,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
     117,   116,     0,   122,   123,   125,   124,     0,     0,    52,
       0,     0,    67,    68,    62,    69,    70,    60,    61,    63,
      64,    65,    57,    71,    53,    54,    55,    56,   105,   134,
       0,     0,     0,     0,    23,     0,   141,     0,   164,     0,
       0,     0,     0,     5,   195,   187,   112,   110,     0,   114,
     136,     0,    15,    14,    44,   146,    40,    42,    43,    38,
      35,   144,   145,    11,    12,    13,     0,   109,    74,    40,
       0,     0,    45,     0,     0,   133,    46,    22,   140,     0,
       3,     0,     0,     0,     0,     0,     0,   187,     0,   107,
       0,     0,     0,     0,     0,    25,    24,     0,     2,     0,
       0,     0,     3,     0,   113,   111,   188,   115,    36,   121,
       0,   178,   183,   181,   182,   185,    28,     0,   156,   166,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,   187,   151,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,   176,   170,   196,   177,   184,
     157,     0,     0,     0,   160,     0,     3,     0,     0,     0,
       0,    39,     0,     0,     0,     0,     0,   173,     0,     0,
       0,     0,   159,     0,     0,     3,   167,     0,     0,    40,
       0,     0,   161,     0,   174,   172,   171,     0,   168,   162,
     163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   279,   158,   159,   160,    48,    49,   151,   212,    50,
      51,   101,   102,   103,   104,    52,    53,    54,   226,    56,
      57,    58,    59,    60,    61,    62,    63,   227,    65,   228,
     182,   113,   114,    66,    67,    68,    88,    70,    96,    71,
      72,   106,   213,    73,    74,    75,    76,    77,   330,   220,
      78,    79,   320,   321,   306,   128,   295,    80,    94,    81,
      82,    83,   229,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -267
static const yytype_int16 yypact[] =
{
    1229,   -84,  2270,    24,  -267,   -64,  -267,  -267,  -267,  -267,
    -267,  -267,  1007,  -267,  -267,  -267,  -267,    39,    56,  -267,
     -31,   -27,  -267,   -26,   629,   -18,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,   132,   132,   132,
     176,  2370,  2411,  -267,   -17,  2270,  2270,  2270,   -35,   588,
    -267,    12,  -267,  -267,   228,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,   -76,
      22,  -267,  -267,  -267,  -267,  -267,   166,  -267,  -267,  -267,
    -267,  -267,    11,  -267,   123,  -267,  -267,  1289,    15,   114,
    -267,  -267,  -267,  -267,    11,    13,   588,  -267,    26,   691,
    -267,  -267,  -267,    25,    30,  1339,    34,    70,    19,  -267,
    -267,  -267,    -1,    36,   588,   588,   588,    12,  -267,  -267,
    -267,   691,    33,    33,    43,  2541,  -267,  -267,   140,  -267,
     691,  2270,  2270,  2270,  2270,  2270,  2270,  2270,  2270,  2270,
    2270,  2270,  2270,  2270,  2270,  2270,  2270,  2270,   146,    18,
     227,   488,    55,     9,   119,  2270,  -267,  -267,  1118,  -267,
    -267,  -267,   691,  -267,  2013,    76,  -267,  -267,   691,   664,
      75,   796,   796,  2270,  2270,  2270,  -267,    77,    78,    83,
    -267,  -267,    85,  -267,  -267,  -267,  -267,    88,  2270,  -267,
       5,    89,    33,    33,   832,    33,    33,   832,  2715,  2715,
    1289,   461,     8,  2703,    37,    37,     8,     8,  2703,  -267,
      90,    92,    91,   101,    22,   588,  -267,  2270,  -267,  2124,
     187,   104,  2674,  -267,  -267,    56,    11,    11,   162,    11,
    -267,   107,  -267,  -267,  -267,  -267,  1339,  -267,   853,  2703,
    1359,  -267,  1404,  -267,  -267,  -267,    -3,  -267,   -55,  2703,
     691,  1680,  -267,  2270,   202,  -267,  -267,  -267,  -267,  2561,
     220,   109,  2270,  2124,    11,  1458,  1458,    56,  1458,  -267,
    2270,   112,  2270,   115,    -7,  2703,  -267,   896,  -267,   191,
    2270,  2592,   220,  1569,  -267,  -267,  -267,  -267,  2703,  -267,
    2501,   169,  -267,  -267,  -267,  -267,   -15,    11,  -267,  -267,
    2521,    11,   205,   220,  2270,   133,    11,   229,  1791,  2270,
       7,  -267,   177,  2633,   187,  1680,   137,    54,  2480,   -32,
     200,   204,    56,  -267,   139,    -7,   237,    11,   145,  -267,
      27,  2270,  2124,    11,   736,  -267,  -267,  -267,  -267,  -267,
    -267,  2235,  2270,    11,  -267,  2674,   220,  1902,   149,   -65,
     -42,   853,   222,  2653,  2235,  2124,   221,  -267,    11,    11,
     796,    11,  -267,   232,   238,   220,  -267,  1902,  1902,   853,
    1902,    11,  -267,   240,  -267,  -267,  -267,  1791,  -267,   241,
    -267
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,  -266,    72,  -267,   165,  -267,   131,    68,  -267,    35,
     -23,  -164,  -144,   -46,   -50,   246,  -267,    40,     2,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,     4,  -267,    95,
    -267,    46,    45,  -267,  -267,  -267,     0,  -267,  -267,  -267,
    -267,  -267,   -21,  -267,  -267,  -267,  -267,  -267,   -90,  -267,
    -267,  -267,  -267,   -25,  -267,  -267,   -29,  -267,  -215,  -267,
    -267,  -152,  -267,  -267
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -156
static const yytype_int16 yytable[] =
{
      69,   124,    55,   107,    64,    89,   224,   234,   237,   156,
     264,   156,    69,   156,    91,   156,   302,   117,   109,     1,
     180,    98,   110,   333,   141,   126,   292,   235,   129,   127,
     218,   241,   142,     2,    85,   148,   165,   312,   149,     3,
       4,    86,    87,     6,    89,     7,     8,     9,    97,   141,
     359,   360,   286,   141,   293,    90,   319,   142,   294,   130,
      92,   142,   272,   343,   105,   344,    30,    31,    32,    33,
      34,    35,    36,   361,   172,   167,   119,   120,   170,    93,
     356,    95,   334,   115,   116,   122,   123,   125,    99,   105,
     327,   328,   329,   184,   185,   186,   108,   121,    24,   373,
     187,   307,   177,   178,   179,   210,   211,   337,   111,   191,
     181,    30,    31,    32,    33,    34,    35,    36,   157,   250,
     157,    40,   157,   161,   157,   166,   130,    45,    46,   162,
     216,   303,    47,  -147,  -147,   163,   105,   100,   150,   169,
     168,   171,   143,   144,   145,   146,   172,   231,   145,   146,
     175,   176,   183,   109,   105,   105,   105,   110,    69,   188,
      55,   105,    64,   190,    69,   248,   164,   209,   221,   217,
     105,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   230,   105,
     233,   105,   243,   244,   258,   222,   234,   261,   245,    86,
     152,   246,   105,   247,   252,   153,   255,   253,   105,   254,
      86,   236,   238,   239,   240,   242,   256,   154,   262,    69,
     155,   267,   269,   276,   278,   219,   280,   289,   249,   273,
     291,   299,   305,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   111,   141,   311,   112,   314,   322,   319,
     316,    69,   142,   326,   338,   105,   336,   259,   340,   342,
     362,   366,   251,    69,   358,    69,    69,   371,    69,    30,
      31,    32,    33,    34,    35,    36,   372,    69,   328,   298,
     378,   214,   257,    69,   350,    55,   118,    64,   349,   380,
     105,   324,   271,   275,   263,   335,   339,     0,     0,     0,
       0,     0,   281,     0,    22,     0,    23,     0,    69,    25,
     288,     0,   290,    26,   260,    69,    27,    28,    29,     0,
     300,     0,     0,   223,     0,     0,     0,     0,     0,   223,
       0,     0,    69,     0,     0,     0,   283,   143,   144,   145,
     146,    69,     0,     0,   313,   147,   274,    69,     0,   318,
       0,     0,     0,     0,    69,    69,     0,     0,   282,     0,
     284,   285,     0,   287,     0,     0,     0,    69,    69,   308,
      69,   345,     0,   310,   351,     0,     0,    69,   315,     0,
       0,     0,   353,     0,   223,     0,     0,     0,     0,     0,
     332,   265,   266,     0,   268,     0,     0,     0,     0,   341,
     369,     0,     0,   317,     0,   347,     0,     0,     0,     0,
     325,     0,     0,     0,     0,   354,   223,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   346,   223,     0,
     367,   368,     0,   370,     0,     0,   352,     0,     0,     0,
       0,     0,   357,   377,     0,     0,     0,     0,   223,   364,
     365,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   374,   375,     0,   376,   131,   132,   133,   134,
     135,   136,   379,   223,   139,   223,     0,   141,     0,     0,
     223,     0,     0,     0,     0,   142,     0,     0,  -147,     1,
       0,     0,  -147,     0,     0,     0,     0,   223,     0,     0,
       0,     0,     0,     2,     0,   215,   223,     0,     0,     3,
       4,    86,   223,     6,     0,     7,     8,     9,     0,   223,
     223,  -147,     0,     0,  -147,  -147,  -147,     0,  -147,     0,
       0,     0,   223,   223,     0,   223,     0,  -147,     0,     0,
    -147,     0,   223,     0,     0,     0,     0,  -147,     0,  -147,
       0,     0,     0,  -147,     0,     0,     0,     0,     0,  -147,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,    36,  -147,     1,
       0,    40,  -147,     0,     0,     0,     0,    45,    46,     0,
       0,  -147,    47,     2,  -147,     0,     0,   100,     0,     3,
       4,    86,     0,     6,     0,     7,     8,     9,     0,     0,
       0,  -147,     0,     0,  -147,  -147,  -147,     0,  -147,     0,
       1,     0,     0,     0,     0,     0,     0,  -147,     0,     0,
    -147,     0,     0,     0,     2,     0,     0,  -147,     0,  -147,
       3,     4,    86,  -147,     6,     0,     7,     8,     9,  -147,
       0,     0,     0,     0,     0,     0,     0,     0,    24,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
     141,    30,    31,    32,    33,    34,    35,    36,   142,     0,
       0,    40,     1,     0,     0,     0,     0,    45,    46,     0,
       0,  -147,    47,     0,  -147,     0,     2,   100,     0,    24,
    -147,     0,     3,     4,    86,     0,     6,     0,     7,     8,
       9,     0,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    40,     0,     0,     0,     0,     1,    45,    46,
       0,     0,     0,    47,     0,  -147,     0,     0,   100,     0,
       0,     2,     0,     0,     0,     0,     0,     3,     4,    86,
       0,     6,     0,     7,     8,     9,     0,     0,     0,     0,
       0,    24,     0,   143,   144,   145,   146,     0,     0,   232,
       0,   173,     0,   174,    30,    31,    32,    33,    34,    35,
      36,   348,     0,     0,    40,     0,     0,     1,     0,     0,
      45,    46,     0,     0,     0,    47,  -147,  -147,     0,     0,
     100,     2,     0,     0,     0,     0,    24,     3,     4,    86,
       0,     6,     0,     7,     8,     9,     0,     0,     0,    30,
      31,    32,    33,    34,    35,    36,     0,   131,   132,    40,
     134,   135,     0,     0,     0,    45,    46,     0,   141,     0,
      47,     0,     0,     0,     0,   100,   142,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
       0,     0,     0,     0,     0,     0,    24,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,    33,    34,    35,    36,   -86,     1,     0,    40,
     -86,     0,     0,     0,     0,    45,    46,     0,     0,     0,
      47,     2,     0,     0,     0,   100,     0,   296,     4,     5,
       0,     6,     0,     7,     8,     9,    10,    11,     0,   -86,
    -155,   297,   -86,   -86,   -86,  -155,   -86,    14,     0,    15,
      16,   143,   144,   145,   146,   -86,     0,  -155,   -86,    17,
    -155,     0,     0,     0,     0,   -86,     0,   -86,     0,     0,
       0,   -86,   143,   144,   145,   146,     0,   -86,    20,     0,
      21,     0,   174,    22,     0,    23,    24,     0,    25,     0,
       0,     0,    26,     0,     0,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   -86,     1,   -86,
      47,   -86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
     -86,  -155,     0,   -86,   -86,   -86,  -155,   -86,    14,     0,
      15,    16,     0,     0,     0,     0,   -86,     0,  -155,   -86,
      17,  -155,     0,     0,     0,     0,   -86,     0,   -86,     0,
       0,     0,   -86,     0,     0,     0,     0,     0,   -86,    20,
       0,    21,     0,     0,    22,     0,    23,    24,     0,    25,
       0,     0,     0,    26,     0,     0,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   -86,     1,
     -86,    47,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
      12,    13,  -155,     0,     0,     0,     0,  -155,     0,    14,
       0,    15,    16,     0,     0,     0,     0,     0,     0,  -155,
       0,    17,  -155,     0,     0,     0,    18,     0,   -10,     0,
      19,     0,   -10,     0,     0,     0,     0,     0,     0,   -86,
      20,     0,    21,     0,     0,    22,     0,    23,    24,     0,
      25,     0,     0,     0,    26,     0,     0,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   -86,
       1,   157,    47,   -86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,  -155,     0,     0,     0,     0,  -155,     0,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
    -155,     0,    17,  -155,     0,     0,     0,    18,     0,   -10,
       0,    19,     0,   -10,   131,   132,   133,   134,   135,   136,
       0,    20,     0,    21,     0,   141,    22,     0,    23,    24,
       0,    25,     0,   142,     0,    26,     0,     0,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
       0,     0,   -86,    47,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,   141,     0,     0,     0,     0,
       0,     0,     0,   142,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,   141,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,     0,     0,     0,     0,   173,     0,   174,     1,
       0,     0,   -86,     0,     0,     0,     0,     0,   143,   144,
     145,   146,     0,     2,     0,     0,     0,     0,   270,     3,
       4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
      12,   -86,  -155,     0,   -86,   -86,   -86,  -155,   -86,    14,
       0,    15,    16,     0,     0,     0,     0,   -86,     0,  -155,
     -86,    17,  -155,   143,   144,   145,   146,   -86,     0,   -86,
       0,   173,     0,   -86,     0,     0,     0,     0,   225,     0,
      20,     0,    21,     0,     0,    22,     0,    23,    24,     0,
      25,     0,     0,     0,    26,     0,     0,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,     0,
       1,   -86,    47,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,  -155,     0,     0,     0,     0,  -155,     0,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
    -155,     0,    17,  -155,     0,     0,     0,    18,     0,   -10,
       0,    19,     0,   -10,     0,     0,     0,     0,     0,     0,
     -86,    20,     0,    21,     0,     0,    22,     0,    23,    24,
       0,    25,     0,     0,     0,    26,     0,     0,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
       0,     1,   157,    47,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
      10,    11,    12,   -86,  -155,     0,     0,     0,     0,  -155,
       0,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,  -155,     0,    17,  -155,     0,     0,     0,     0,     0,
       0,   -86,     0,     0,     0,   -86,     0,     0,     0,     0,
     225,     0,    20,     0,    21,     0,     0,    22,     0,    23,
      24,     0,    25,     0,     0,     0,    26,     0,     0,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,     0,     1,   157,    47,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     7,     8,
       9,    10,    11,    12,     0,  -155,     0,   -86,   -86,   -86,
    -155,     0,    14,     0,    15,    16,     0,     0,     0,     0,
       0,     0,  -155,     0,    17,  -155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,    20,     0,    21,     0,     0,    22,     0,
      23,    24,     0,    25,     0,     0,     0,    26,     0,     0,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,     0,     1,   157,    47,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     7,
       8,     9,    10,    11,    12,     0,  -155,     0,     0,     0,
       0,  -155,     0,    14,     0,    15,    16,     0,     0,     0,
       0,   -86,     0,  -155,   -86,    17,  -155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,     0,    20,     0,    21,     0,     0,    22,
       0,    23,    24,     0,    25,     0,     0,     0,    26,     0,
       0,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,     0,     1,   157,    47,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     0,
       7,     8,     9,    10,    11,    12,     0,  -155,     0,     0,
       0,     0,  -155,     0,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,  -155,     0,    17,  -155,     0,     0,
       0,     0,   -86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,    20,     0,    21,     0,     0,
      22,     0,    23,    24,     0,    25,     0,     0,     0,    26,
       0,     0,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,     0,     1,   157,    47,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       0,     7,     8,     9,    10,    11,    12,     0,  -155,     0,
       0,     0,     0,  -155,   -86,    14,     0,    15,    16,     0,
       0,     0,     0,     0,     0,  -155,     0,    17,  -155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,    20,     0,    21,     0,
       0,    22,     0,    23,    24,     0,    25,     0,     0,     0,
      26,     0,     0,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,     0,     1,   157,    47,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     0,     7,     8,     9,    10,    11,    12,     0,  -155,
       0,     1,     0,   -86,  -155,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     2,  -155,     0,    17,  -155,
       0,     3,     4,    86,     0,     6,     0,     7,     8,     9,
       0,     0,     0,     0,     0,   225,     0,    20,     0,    21,
       0,     0,    22,     0,    23,    24,     0,    25,     0,     0,
       0,    26,     0,     0,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,     0,     0,   157,    47,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    32,    33,    34,    35,    36,
    -104,     1,     0,    40,  -104,     0,     0,     0,     0,    45,
      46,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     6,     0,     7,     8,     9,
       0,     0,     0,  -104,     0,     0,  -104,  -104,  -104,     0,
    -104,  -102,     1,     0,     0,  -102,     0,     0,     0,  -104,
       0,     0,  -104,     0,     0,     0,     0,     0,     0,  -104,
       0,  -104,     3,     4,     0,  -104,     6,     0,     7,     8,
       9,  -104,     0,     0,  -102,     0,     0,  -102,  -102,  -102,
       0,  -102,     0,     0,     0,     0,     0,     0,     0,     0,
    -102,     0,     0,  -102,     0,     0,     0,     0,     0,     0,
    -102,     0,  -102,     0,     0,     0,  -102,     0,     0,     0,
       0,     0,  -102,  -104,   156,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   142,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   141,     0,     0,
       0,     0,     0,     0,  -102,   142,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,   143,
     144,   145,   146,   157,     0,     0,   331,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,   141,     0,
     143,   144,   145,   146,     0,     0,   142,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,     0,     0,     0,   309,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     143,   144,   145,   146,     0,     0,   189,   142,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     143,   144,   145,   146,     0,     0,   277,   142,   156,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,   143,   144,   145,   146,     0,     0,   301,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     131,   132,   133,   134,   135,   136,     0,   142,   139,   140,
       0,   141,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,   143,   144,   145,   146,     0,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,   146,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-267)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    47,     0,    24,     0,    20,   158,   171,   172,     4,
     225,     4,    12,     4,    12,     4,   282,    40,    21,     1,
      21,    21,    25,    55,    16,    60,    33,   171,    49,    64,
      21,   175,    24,    15,   118,   111,    23,   303,   114,    21,
      22,    23,     2,    25,    20,    27,    28,    29,    75,    16,
     115,   116,   267,    16,    61,   119,    49,    24,    65,   114,
      21,    24,   117,    36,    24,    38,    93,    94,    95,    96,
      97,    98,    99,   115,   116,    96,    41,    42,    99,    23,
     346,   112,   114,    38,    39,    45,    46,    47,   114,    49,
      36,    37,    38,   114,   115,   116,   114,   114,    80,   365,
     121,   116,    83,    84,    85,    87,    88,   322,   111,   130,
     111,    93,    94,    95,    96,    97,    98,    99,   113,   114,
     113,   103,   113,     0,   113,   112,   114,   109,   110,   114,
     151,   283,   114,   115,   116,    21,    96,   119,   116,    99,
     114,   116,   109,   110,   111,   112,   116,   168,   111,   112,
     116,    81,   116,    21,   114,   115,   116,    25,   158,   116,
     158,   121,   158,    23,   164,   188,    94,    21,    49,   114,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   112,   149,
     115,   151,   115,   115,   215,   155,   360,   220,   115,    23,
      34,   116,   162,   115,   115,    39,   115,   117,   168,   117,
      23,   171,   172,   173,   174,   175,   115,    51,   114,   219,
      54,    59,   115,    21,     4,   153,   117,   115,   188,   250,
     115,    40,    63,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   111,    16,    40,   114,   114,    71,    49,
      21,   251,    24,   116,   115,   215,    52,   217,    21,   114,
      38,    40,   190,   263,   115,   265,   266,    35,   268,    93,
      94,    95,    96,    97,    98,    99,    38,   277,    37,   277,
      40,   150,   214,   283,   334,   283,    40,   283,   334,   379,
     250,   314,   246,   253,   222,   320,   325,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    77,    -1,    79,    -1,   308,    82,
     270,    -1,   272,    86,   219,   315,    89,    90,    91,    -1,
     280,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,   164,
      -1,    -1,   332,    -1,    -1,    -1,   264,   109,   110,   111,
     112,   341,    -1,    -1,   304,   117,   251,   347,    -1,   309,
      -1,    -1,    -1,    -1,   354,   355,    -1,    -1,   263,    -1,
     265,   266,    -1,   268,    -1,    -1,    -1,   367,   368,   297,
     370,   331,    -1,   301,   334,    -1,    -1,   377,   306,    -1,
      -1,    -1,   342,    -1,   219,    -1,    -1,    -1,    -1,    -1,
     318,   226,   227,    -1,   229,    -1,    -1,    -1,    -1,   327,
     360,    -1,    -1,   308,    -1,   333,    -1,    -1,    -1,    -1,
     315,    -1,    -1,    -1,    -1,   343,   251,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,   263,    -1,
     358,   359,    -1,   361,    -1,    -1,   341,    -1,    -1,    -1,
      -1,    -1,   347,   371,    -1,    -1,    -1,    -1,   283,   354,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   367,   368,    -1,   370,     5,     6,     7,     8,
       9,    10,   377,   308,    13,   310,    -1,    16,    -1,    -1,
     315,    -1,    -1,    -1,    -1,    24,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,   332,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,   341,    -1,    -1,    21,
      22,    23,   347,    25,    -1,    27,    28,    29,    -1,   354,
     355,    33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,   367,   368,    -1,   370,    -1,    49,    -1,    -1,
      52,    -1,   377,    -1,    -1,    -1,    -1,    59,    -1,    61,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,     0,     1,
      -1,   103,     4,    -1,    -1,    -1,    -1,   109,   110,    -1,
      -1,   113,   114,    15,   116,    -1,    -1,   119,    -1,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    15,    -1,    -1,    59,    -1,    61,
      21,    22,    23,    65,    25,    -1,    27,    28,    29,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    93,    94,    95,    96,    97,    98,    99,    24,    -1,
      -1,   103,     1,    -1,    -1,    -1,    -1,   109,   110,    -1,
      -1,   113,   114,    -1,   116,    -1,    15,   119,    -1,    80,
      81,    -1,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,     1,   109,   110,
      -1,    -1,    -1,   114,    -1,   116,    -1,    -1,   119,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    80,    -1,   109,   110,   111,   112,    -1,    -1,   115,
      -1,   117,    -1,   119,    93,    94,    95,    96,    97,    98,
      99,    55,    -1,    -1,   103,    -1,    -1,     1,    -1,    -1,
     109,   110,    -1,    -1,    -1,   114,   115,   116,    -1,    -1,
     119,    15,    -1,    -1,    -1,    -1,    80,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,     5,     6,   103,
       8,     9,    -1,    -1,    -1,   109,   110,    -1,    16,    -1,
     114,    -1,    -1,    -1,    -1,   119,    24,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,     0,     1,    -1,   103,
       4,    -1,    -1,    -1,    -1,   109,   110,    -1,    -1,    -1,
     114,    15,    -1,    -1,    -1,   119,    -1,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,   109,   110,   111,   112,    49,    -1,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    65,   109,   110,   111,   112,    -1,    71,    72,    -1,
      74,    -1,   119,    77,    -1,    79,    80,    -1,    82,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,   108,   109,   110,     0,     1,   113,
     114,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    74,    -1,    -1,    77,    -1,    79,    80,    -1,    82,
      -1,    -1,    -1,    86,    -1,    -1,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,   108,   109,   110,     0,     1,
     113,   114,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    -1,    -1,    -1,    58,    -1,    60,    -1,
      62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    74,    -1,    -1,    77,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,   108,   109,   110,     0,
       1,   113,   114,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62,    -1,    64,     5,     6,     7,     8,     9,    10,
      -1,    72,    -1,    74,    -1,    16,    77,    -1,    79,    80,
      -1,    82,    -1,    24,    -1,    86,    -1,    -1,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,   108,   109,   110,
      -1,    -1,   113,   114,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,   117,    -1,   119,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    -1,    15,    -1,    -1,    -1,    -1,   119,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,   109,   110,   111,   112,    59,    -1,    61,
      -1,   117,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    74,    -1,    -1,    77,    -1,    79,    80,    -1,
      82,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,   108,   109,   110,    -1,
       1,   113,   114,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    74,    -1,    -1,    77,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,   108,   109,   110,
      -1,     1,   113,   114,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      -1,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    74,    -1,    -1,    77,    -1,    79,
      80,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,   108,   109,
     110,    -1,     1,   113,   114,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    -1,    34,    -1,    36,    37,    38,
      39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    74,    -1,    -1,    77,    -1,
      79,    80,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,   108,
     109,   110,    -1,     1,   113,   114,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    74,    -1,    -1,    77,
      -1,    79,    80,    -1,    82,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
     108,   109,   110,    -1,     1,   113,   114,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      -1,    -1,    39,    -1,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    54,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    74,    -1,    -1,
      77,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,   108,   109,   110,    -1,     1,   113,   114,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    74,    -1,
      -1,    77,    -1,    79,    80,    -1,    82,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,   108,   109,   110,    -1,     1,   113,   114,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    -1,    34,
      -1,     1,    -1,    38,    39,    -1,    41,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    15,    51,    -1,    53,    54,
      -1,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    74,
      -1,    -1,    77,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    86,    -1,    -1,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,   108,   109,   110,    -1,    -1,   113,   114,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
       0,     1,    -1,   103,     4,    -1,    -1,    -1,    -1,   109,
     110,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,    -1,
      40,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    61,    21,    22,    -1,    65,    25,    -1,    27,    28,
      29,    71,    -1,    -1,    33,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,   113,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    24,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    -1,    -1,   116,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
     109,   110,   111,   112,    -1,    -1,    24,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,   116,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
     109,   110,   111,   112,    -1,    -1,   115,    24,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
     109,   110,   111,   112,    -1,    -1,   115,    24,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,   109,   110,   111,   112,    -1,    -1,   115,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    -1,    24,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    21,    22,    23,    25,    27,    28,    29,
      30,    31,    32,    33,    41,    43,    44,    53,    58,    62,
      72,    74,    77,    79,    80,    82,    86,    89,    90,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   108,   109,   110,   114,   125,   126,
     129,   130,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   153,   154,   155,   156,
     157,   159,   160,   163,   164,   165,   166,   167,   170,   171,
     177,   179,   180,   181,   183,   118,    23,   137,   156,    20,
     119,   138,    21,    23,   178,   112,   158,    75,   156,   114,
     119,   131,   132,   133,   134,   137,   161,   162,   114,    21,
      25,   111,   114,   151,   152,   152,   152,   130,   135,   129,
     129,   114,   137,   137,   133,   137,    60,    64,   175,   162,
     114,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    16,    24,   109,   110,   111,   112,   117,   111,   114,
     116,   127,    34,    39,    51,    54,     4,   113,   122,   123,
     124,     0,   114,    21,   122,    23,   112,   162,   114,   137,
     162,   116,   116,   117,   119,   116,    81,    83,    84,    85,
      21,   111,   150,   116,   162,   162,   162,   162,   116,   115,
      23,   162,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,    21,
      87,    88,   128,   162,   126,    17,   162,   114,    21,   122,
     169,    49,   137,   124,   181,    70,   138,   147,   149,   182,
     112,   162,   115,   115,   131,   132,   137,   131,   137,   137,
     137,   132,   137,   115,   115,   115,   116,   115,   130,   137,
     114,   122,   115,   117,   117,   115,   115,   127,   162,   137,
     149,   130,   114,   122,   178,   124,   124,    59,   124,   115,
     119,   151,   117,   162,   149,   137,    21,   115,     4,   121,
     117,   137,   149,   122,   149,   149,   178,   149,   137,   115,
     137,   115,    33,    61,    65,   176,    21,    35,   138,    40,
     137,   115,   121,   181,   116,    63,   174,   116,   122,   116,
     122,    40,   121,   137,   114,   122,    21,   149,   137,    49,
     172,   173,    71,   115,   130,   149,   116,    36,    37,    38,
     168,   116,   122,    55,   114,   173,    52,   178,   115,   176,
      21,   122,   114,    36,    38,   137,   149,   122,    55,   133,
     134,   137,   149,   137,   122,   122,   121,   149,   115,   115,
     116,   115,    38,   115,   149,   149,    40,   122,   122,   137,
     122,    35,    38,   121,   149,   149,   149,   122,    40,   149,
     168
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
#line 146 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)]))); 
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 152 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Nop, "" }));
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 158 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 164 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::CRLF, "\n" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 171 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Semicolon, ";" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 178 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 183 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 189 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 194 "for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 200 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(in)
				set_variabledesc_attr(newnode, true, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 208 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(out)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 217 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // intent(inout)
				set_variabledesc_attr(newnode, true, false, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 225 "for90.y"
    {
				// if write `',' YY_DIMENSION` in `var_def` will cause conflict at ',' 
				// if is array reduce immediately and goto `var_def` 
				// do not parse array slices here because this is difficult 
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 237 "for90.y"
    {
				// define array like a(1)
				ARG_OUT exp_to = YY2ARG((yyvsp[(3) - (4)]));

				ParseNode slice = promote_exp_to_slice(exp_to);
				ParseNode dimen_slice = gen_promote("", TokenMeta::NT_DIMENSLICE, slice);
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN VARDEF") }, dimen_slice);
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, dimen_slice, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 251 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 260 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // optional
				set_variabledesc_attr(newnode, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 268 "for90.y"
    {
				// const value
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // const
				set_variabledesc_attr(newnode, boost::none, true, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 277 "for90.y"
    {
				// static value 
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // static
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 286 "for90.y"
    {
				/* allocatable value */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // allocatable
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 295 "for90.y"
    {
				// target value
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") }); // target
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, true, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 305 "for90.y"
    {
				ParseNode variable_elem = YY2ARG((yyvsp[(2) - (3)]));
				ParseNode variable_desc = YY2ARG((yyvsp[(3) - (3)]));
				// target code of slice depend on context
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				// merge attrs 
				newnode.setattr(variable_elem.attr->clone());
				get_variabledesc_attr(newnode).merge(get_variabledesc_attr(variable_desc));
				// TODO do not add child
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 319 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				newnode.setattr(new VariableDescAttr());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 333 "for90.y"
    {
				int kind;
				ARG_OUT integer = YY2ARG((yyvsp[(3) - (3)]));
				sscanf(integer.get_what().c_str(), "%d", &kind);

				/* type size */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, "NT_VARIABLEDESC" });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, kind, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 346 "for90.y"
    {
				// though use std::string
				// still need to initialize the string to YY_LEN
				int len;
				ARG_OUT integer = YY2ARG((yyvsp[(3) - (3)]));
				sscanf(integer.get_what().c_str(), "%d", &len);

				/* string length */
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDESC, WHEN_DEBUG_OR_EMPTY("NT_VARIABLEDESC GENERATED IN") });
				set_variabledesc_attr(newnode, boost::none, boost::none, boost::none, boost::none, len, boost::none, boost::none, boost::none, boost::none, boost::none);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 362 "for90.y"
    {
				// all arguments under `literal` rule is directly from tokenizer
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float, lit.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 370 "for90.y"
    {
				ARG_OUT base = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT expo = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Float,  base.get_what() + "e" + expo.get_what() })); // float number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 379 "for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Int, lit.get_what() })); // int number
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 386 "for90.y"
    {
				// replace `'` with `"`
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				std::string s = lit.get_what().substr(1, lit.get_what().size() - 2);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::String, "\"" + s + "\"" })); // string
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 395 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "true" })); // bool true
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 401 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Bool, "false" })); // bool false
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 407 "for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				string strcplx = lit.get_what();
				auto splitter = strcplx.find_first_of('_', 0);
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Complex, "forcomplex(" + strcplx.substr(0, splitter) + ", " + strcplx.substr(splitter + 1) + ") " })); //complex
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 417 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				print_error("exp parse error");
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 425 "for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, lit.get_what() });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 441 "for90.y"
    {
				// arr[from : to]
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 451 "for90.y"
    {
				// arr[from : to : step]
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (5)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (5)]));
				ARG_OUT exp3 = YY2ARG((yyvsp[(5) - (5)]));
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, exp1, exp2, exp3));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 462 "for90.y"
    {
				ParseNode from = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode to = gen_token(Term{ TokenMeta::META_INTEGER, "foroptional<int>()" });
				ParseNode lb = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, from.get_what() }, from);
				ParseNode ub = gen_token(Term{ TokenMeta::NT_VARIABLEINITIALDUMMY, to.get_what() }, to);
				// target code of slice depend on context
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_SLICE, "" }, lb, ub));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 474 "for90.y"
    {
				// initial value is required in parse tree because it can be an non-terminal `exp` 
				// non-array initial values 
				// array_builder is exp 
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_keyvalue_from_exp(YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 485 "for90.y"
    {
				// argtable is used in function call 
				ARG_OUT exp = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ARGTABLE_PURE , exp.get_what()}, exp);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 494 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(1) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(exp, argtable, "%s, %s", TokenMeta::NT_ARGTABLE_PURE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 512 "for90.y"
    {
				/******************
				* 1d array
				* arr[from : to]
				* target code of slice depend on context
				******************/ 
				ARG_OUT slice = YY2ARG((yyvsp[(1) - (1)]));
				// only 1 slice
				(yyval) = RETURN_NT(gen_promote("", TokenMeta::NT_DIMENSLICE, slice));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 525 "for90.y"
    {
				/******************
				* multi dimension array
				* arr[from:to, from:to, ...]
				* target code of slice depend on context
				******************/
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT slice = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(slice, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 547 "for90.y"
    {
				/******************
				* multi dimension array
				* arr[from:to, index, ...]
				* target code of slice depend on context
				******************/
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(exp, dimen_slice, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 569 "for90.y"
    {
				ARG_OUT argtable = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT slice = YY2ARG((yyvsp[(3) - (3)]));
				if (!argtable.token_equals(TokenMeta::NT_ARGTABLE_PURE))
				{
					print_error("Illegal dimen_slice", argtable);
				}
				// IMPORTANT: can't promote here, or `s(i, 1:j)` cause error, ref `regen_slice`
				//newnode = gen_flatten(slice, promote_argtable_to_dimenslice(argtable), "%s, %s", TokenMeta::NT_DIMENSLICE, true);
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(slice, argtable, "%s, %s", TokenMeta::NT_DIMENSLICE, true));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 593 "for90.y"
    {
				// function call OR array index 
				// NOTE that array index can be A(1:2, 3:4) 
				ARG_OUT callable_head = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 604 "for90.y"
    {
				// function call OR array index 
				// NOTE that array index can be A(1:2, 3:4) 
				ARG_OUT callable_head = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }, callable_head, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 616 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 621 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]));
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 627 "for90.y"
    {
				/******************
				* call-stmt
				* function call can omit trailing `()` if there's no arguments
				* e.g.
				*	```
				*	call func
				*	```
				* `func` is not a variable, but a function
				* SHOULDN"T GENERATE VARDEF FOR `func`
				*******************/
				ARG_OUT callable_head = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_token(Term{TokenMeta::NT_FUCNTIONARRAY, WHEN_DEBUG_OR_EMPTY("FUNCTIONARRAY GENERATED IN REGEN_SUITE") }
					, callable_head, gen_token(Term{TokenMeta::NT_ARGTABLE_PURE, ""}) );
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 647 "for90.y"
    {
				/******************
				* this is sth callable, maybe array section(NT_DIMENSLICE) or function
				******************/
				ARG_OUT function_array = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 656 "for90.y"
    {
				// don't promote to exp, and gen_vardel_array will consider this node as array_builder
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 663 "for90.y"
    {
				// `function_array` rule MUST have priority over this rule 
				ARG_OUT exp = YY2ARG((yyvsp[(2) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LB, "( %s )" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 672 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Add, "%s + %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 682 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Minus, "%s - %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 692 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Multiply, "%s * %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 702 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Divide, "%s / %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 712 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Power, "power(%s, %s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 722 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Neg, "(-%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 731 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Pos, "%s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 740 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::NEQ, "%s != %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 750 "for90.y"
    {
				// xor
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::NEQV, "%s ^ %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 761 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::EQ, "%s == %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 771 "for90.y"
    {
				// nor
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::EQV, "!(%s ^ %s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 782 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::AndAnd, "%s && %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 792 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "%s || %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 802 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(2) - (2)]));
				ARG_OUT op = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::OrOr, "!(%s)" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 811 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::GT, "%s > %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 821 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::GE, "%s >= %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 831 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LE, "%s <= %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 840 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::LT, "%s < %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 850 "for90.y"
    {
				// TODO may have error priority 
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				const string & op_name = op.get_what();
				auto keyword_iter = find_if(keywords.begin(), keywords.end(), [&](const auto & x) {return x.what == op_name; });
				if (keyword_iter != keywords.end())
				{
					// this is a keyword
				}
				else {
					fatal_error("self-defined operator is not supported", op);
				}
				ParseNode opnew = gen_token(Term{ keyword_iter->token, "%s " + op_name + " %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 870 "for90.y"
    {
				ARG_OUT hidden_do = YY2ARG((yyvsp[(1) - (1)]));
				//$$ = RETURN_NT(gen_token(Term{ TokenMeta::NT_EXPRESSION, hidden_do.get_what() }, hidden_do));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 877 "for90.y"
    {
				/******************
				* shouldn't promote literals to NT_EXPRESSION, 
				*	because it can bring trouble to hardcoded dealt values
				* e.g.
				* when generating NT_SLICE, we can set a default lower bound UBOUND_DELTA_STR = `1`, 
				*	and we hard code the UBOUND_DELTA_STR
				*	if we promote  literals to NT_EXPRESSION, we should write
				*	`gen_token(Term{TokenMeta::NT_EXPRESSION, UBOUND_DELTA_STR}, gen_token(Term{TokenMeta::Int, UBOUND_DELTA_STR}))`
				*	it's not elegant
				******************/
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 897 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 903 "for90.y"
    {
				/******************
				* formerly, considering `stmt` are completed by `\n` or certain mark like `end do(enddo)`
				* so `stmt` is used to have a list of children
				* however, now,
				******************/
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 915 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 921 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 927 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 933 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 938 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_STATEMENT, YY2ARG((yyvsp[(1) - (1)]))));
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 945 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 951 "for90.y"
    {
				ARG_OUT format = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FORMAT, "\"" + format.to_string() + "\"" }, format);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 959 "for90.y"
    { 
				ARG_OUT comment = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_comment(comment.get_what()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 966 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 972 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				insert_comments(YY2ARG((yyval)));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 978 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_STATEMENT, "" }));
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 984 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 990 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 996 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1002 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("nop();", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 1008 "for90.y"
    {
				(yyval) = RETURN_NT(gen_promote("%s;", TokenMeta::NT_CONTROL_STMT, YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1015 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1020 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1025 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1031 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1036 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1041 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1047 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Continue, "continue;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1053 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Break, "break;"}));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1059 "for90.y"
    {
				ARG_OUT line = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{TokenMeta::Goto, line.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1067 "for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "printf(" + lit.get_what() + ");stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1074 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop()" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1081 "for90.y"
    {
				ARG_OUT lit = YY2ARG((yyvsp[(2) - (2)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop(" + lit.get_what() + ");" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1088 "for90.y"
    {
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::Stop, "stop();" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1095 "for90.y"
    {
				ARG_OUT exp1 = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT op = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT exp2 = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode opnew = gen_token(Term{ TokenMeta::Let, "%s = %s" });
				(yyval) = RETURN_NT(gen_promote(opnew.get_what(), TokenMeta::NT_EXPRESSION, exp1, exp2, opnew));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1106 "for90.y"
    {
				// dummy stmt
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1113 "for90.y"
    {
				// dummy stmt
				ParseNode & type_name = YY2ARG((yyvsp[(2) - (5)]));
				ParseNode & paramtable = YY2ARG((yyvsp[(4) - (5)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::ConfigImplicit, "" }, type_name, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1124 "for90.y"
    {
				ARG_OUT label = YY2ARG((yyvsp[(1) - (2)])); // TokenMeta::Label
				ARG_OUT stmt = YY2ARG((yyvsp[(2) - (2)]));
				if (stmt.token_equals(TokenMeta::NT_FORMAT))
				{
					//log_format_index(label.get_what(), stmt.get(0)); 
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL FORMAT GENERATED IN REGEN_SUITE") }, label, stmt);
					// do not generate target code of format stmt
					(yyval) = RETURN_NT(newnode);
				}
				else {
					ParseNode newnode = gen_token(Term{ TokenMeta::NT_SUITE , WHEN_DEBUG_OR_EMPTY("LABEL GENERATED IN REGEN_SUITE") }, label, stmt);
					(yyval) = RETURN_NT(newnode);
				}
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 1143 "for90.y"
    {
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ALLOCATE_STMT, "" }, paramtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1152 "for90.y"
    {
				// NT_FORMAT or other stmt node
				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 1160 "for90.y"
    {

				ARG_OUT labeled_stmts = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(labeled_stmts, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 1174 "for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1181 "for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(stmt, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1194 "for90.y"
    {
				// NT_INTERFACE
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(interf, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1202 "for90.y"
    {
				ARG_OUT interf = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT suite = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_suite(interf, suite));
#ifdef USE_REUSE
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#else
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1214 "for90.y"
    {	/******************
				* An asterisk identifies particular processor-dependent external units that are preconnected for formatted sequential access (9.4.4.2).
				*==================
				* -1 stands for stdin/stdout, depending it's in whether a read or a write stmt, ref gen_io.cpp
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, "-1" })); // 
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1224 "for90.y"
    {
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::META_ANY, integer.get_what() }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1231 "for90.y"
    {
				/******************
				* an asterisk (*) which indicates list-directed formatting (10.8).
				******************/
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_AUTOFORMATTER, "" }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1240 "for90.y"
    {
				// use format stmt at line YY2ARG($1) to format
				ARG_OUT integer = YY2ARG((yyvsp[(1) - (1)]));
				std::string location_label = integer.get_what();
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER_LOCATION, location_label }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1249 "for90.y"
    {
				/******************
				* C++ only allows strings wrapped by `"`,
				*	replace `'` string with `"`
				******************/
				ARG_OUT s = YY2ARG((yyvsp[(1) - (1)]));
				string modified = "\"" + s.get_what().substr(1, s.get_what().size() - 2) + "\"";
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_FORMATTER, modified }));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1283 "for90.y"
    {
				/******************
				* target code of io_info depend on context
				*	can be either iostream/cstdio
				******************/
				ARG_OUT _optional_device = YY2ARG((yyvsp[(2) - (5)]));
				ARG_OUT _optional_formatter = YY2ARG((yyvsp[(4) - (5)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (5)])), YY2ARG((yyvsp[(5) - (5)])));
				CLEAN_DELETE((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1296 "for90.y"
    {				
				/******************
				* target code of io_info depend on context
				*	can be either iostream/cstdio
				******************/
				ParseNode _optional_device = gen_token(Term{TokenMeta::META_INTEGER, "-1"});
				ARG_OUT _optional_formatter = YY2ARG((yyvsp[(1) - (2)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::META_NONTERMINAL, "" }, _optional_device, _optional_formatter);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1311 "for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WRITE_STMT, WHEN_DEBUG_OR_EMPTY("WRITE GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1321 "for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PRINT_STMT, WHEN_DEBUG_OR_EMPTY("PRINT GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1332 "for90.y"
    {
				ARG_OUT io_info = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT argtable = YY2ARG((yyvsp[(3) - (3)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_READ_STMT, WHEN_DEBUG_OR_EMPTY("READ GENERATED IN REGEN_SUITE") }, io_info, argtable);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1342 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1348 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1354 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1360 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1366 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1372 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1378 "for90.y"
    {
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (1)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1385 "for90.y"
    {
				// now translated in pre_map
				(yyval) = RETURN_NT(gen_type(YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(3) - (4)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1392 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1398 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1404 "for90.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1410 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1417 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::META_ANY, "" }); // variant
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1424 "for90.y"
    {
				ARG_OUT blockname = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));
				(yyval) = RETURN_NT(gen_common(blockname, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1433 "for90.y"
    {
				// TODO: Here may be a shift-reduce confliction, because `variable_desc` can be empty,
				// when confronting ',', both reducing to variable_desc or shifting may make sense.
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (4)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (4)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(4) - (4)]));
				// get_variabledesc_attr(const_cast<ParseNode &>(variable_desc)).slice.value()
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1445 "for90.y"
    {
				ARG_OUT type_spec = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT variable_desc = YY2ARG((yyvsp[(2) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(3) - (3)]));

				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1455 "for90.y"
    {
				ARG_OUT variable_desc_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode type_spec = gen_token(Term {TokenMeta::Implicit_Decl, ""});
				(yyval) = RETURN_NT(gen_vardef(type_spec, variable_desc_elem, paramtable));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1512 "for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1520 "for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1528 "for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1537 "for90.y"
    {
				ARG_OUT paramtable_elem = YY2ARG((yyvsp[(3) - (3)]));
				ARG_OUT paramtable = YY2ARG((yyvsp[(1) - (3)]));
				ParseNode newnode = gen_pure_paramtable(paramtable_elem, paramtable, true);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1546 "for90.y"
    {
				// empty list
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1554 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1559 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1564 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1570 "for90.y"
    {
				/******************
				* implied do is something like `(abs(i), i=1,4)`
				*==================
				* Standard
					R433 ac - implied - do is(ac - value - list, ac - implied - do - control)
					R434 ac - implied - do - control is ac - do - variable = scalar - int - expr, ��
					�� scalar - int - expr[, scalar - int - expr]
				******************/
				ARG_OUT argtable = YY2ARG((yyvsp[(2) - (9)]));
				ARG_OUT index = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT from = YY2ARG((yyvsp[(6) - (9)]));
				ARG_OUT to = YY2ARG((yyvsp[(8) - (9)]));
				(yyval) = RETURN_NT(gen_hiddendo(argtable, index, from, to));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
			}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1588 "for90.y"
    {
				// give initial value 
				// `B(1:2:3)` can be either a single-element argtable or a exp, this can probably lead to reduction conflicts, so merge rules
				(yyval) = RETURN_NT(gen_arraybuilder_from_paramtable(YY2ARG((yyvsp[(2) - (3)]))));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1598 "for90.y"
    {
				ARG_OUT array_builder_elem = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1606 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(1) - (2)])));
				CLEAN_DELETE((yyvsp[(2) - (2)]));
			}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1612 "for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1621 "for90.y"
    {
				// one line if
				// `IF (e) st` where
				// st can be any executable statement, except a DO block, IF, ELSE IF, ELSE, END IF, END, or another logical IF statement.
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (6)]));
				ARG_OUT stmt_true = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, "" }, exp, stmt_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1633 "for90.y"
    {
				// Arithmetic if
				// `IF (e) s1, s2, s3`, where
				// s1, s2, s3 are labels
			}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1639 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (9)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1648 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (12)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (12)]));
				ARG_OUT suite_else = YY2ARG((yyvsp[(11) - (12)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy(), suite_else);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (12)])), YY2ARG((yyvsp[(12) - (12)])));
				CLEAN_DELETE((yyvsp[(1) - (12)]), (yyvsp[(2) - (12)]), (yyvsp[(3) - (12)]), (yyvsp[(4) - (12)]), (yyvsp[(5) - (12)]), (yyvsp[(6) - (12)]), (yyvsp[(7) - (12)]), (yyvsp[(8) - (12)]), (yyvsp[(9) - (12)]), (yyvsp[(10) - (12)]), (yyvsp[(11) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1658 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (10)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (10)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(9) - (10)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (10)])), YY2ARG((yyvsp[(10) - (10)])));
				CLEAN_DELETE((yyvsp[(1) - (10)]), (yyvsp[(2) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(9) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1668 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(4) - (13)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(8) - (13)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(9) - (13)]));
				ARG_OUT suite_else = YY2ARG((yyvsp[(12) - (13)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_IF, WHEN_DEBUG_OR_EMPTY("IF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif, suite_else);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (13)])), YY2ARG((yyvsp[(13) - (13)])));
				CLEAN_DELETE((yyvsp[(1) - (13)]), (yyvsp[(2) - (13)]), (yyvsp[(3) - (13)]), (yyvsp[(4) - (13)]), (yyvsp[(5) - (13)]), (yyvsp[(6) - (13)]), (yyvsp[(7) - (13)]), (yyvsp[(8) - (13)]), (yyvsp[(9) - (13)]), (yyvsp[(10) - (13)]), (yyvsp[(11) - (13)]), (yyvsp[(12) - (13)]), (yyvsp[(13) - (13)]));
			}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1680 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, gen_dummy());
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1690 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (8)]));
				ARG_OUT suite_true = YY2ARG((yyvsp[(7) - (8)]));
				ARG_OUT elseif = YY2ARG((yyvsp[(8) - (8)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_ELSEIF, WHEN_DEBUG_OR_EMPTY("ELSEIF GENERATED IN REGEN_SUITE") }, exp, suite_true, elseif);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (8)])), YY2ARG((yyvsp[(8) - (8)])));
				CLEAN_DELETE((yyvsp[(1) - (8)]), (yyvsp[(2) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]), (yyvsp[(8) - (8)]));
			}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1701 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1706 "for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1712 "for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DO, WHEN_DEBUG_OR_EMPTY("DO-BARE GENERATED IN REGEN_SUITE") }, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(5) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
			}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1720 "for90.y"
    {
				YYSTYPE X1 = (yyvsp[(1) - (12)]);
				YYSTYPE X2 = (yyvsp[(2) - (12)]);
				YYSTYPE X3 = (yyvsp[(3) - (12)]);
				YYSTYPE X4 = (yyvsp[(4) - (12)]);
				YYSTYPE X5 = (yyvsp[(5) - (12)]);
				YYSTYPE X6 = (yyvsp[(6) - (12)]);
				YYSTYPE X7 = (yyvsp[(7) - (12)]);
				YYSTYPE X8 = (yyvsp[(8) - (12)]);
				YYSTYPE X9 = (yyvsp[(9) - (12)]);
				YYSTYPE X10 = (yyvsp[(10) - (12)]);
				YYSTYPE X11 = (yyvsp[(11) - (12)]);
				YYSTYPE X12 = (yyvsp[(12) - (12)]);
				ARG_OUT loop_variable = YY2ARG((yyvsp[(4) - (12)]));
				ARG_OUT exp_from = YY2ARG((yyvsp[(6) - (12)]));
				ARG_OUT exp_to = YY2ARG((yyvsp[(8) - (12)]));
				ParseNode step = gen_token(Term{ TokenMeta::META_INTEGER , UBOUND_DELTA_STR });
				ARG_OUT suite = YY2ARG((yyvsp[(10) - (12)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (12)])), YY2ARG((yyvsp[(12) - (12)])));
				CLEAN_DELETE((yyvsp[(1) - (12)]), (yyvsp[(2) - (12)]), (yyvsp[(3) - (12)]), (yyvsp[(4) - (12)]), (yyvsp[(5) - (12)]), (yyvsp[(6) - (12)]), (yyvsp[(7) - (12)]), (yyvsp[(8) - (12)]), (yyvsp[(9) - (12)]), (yyvsp[(10) - (12)]), (yyvsp[(11) - (12)]), (yyvsp[(12) - (12)]));
			}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1744 "for90.y"
    {
				ARG_OUT loop_variable = YY2ARG((yyvsp[(4) - (14)]));
				ARG_OUT exp_from = YY2ARG((yyvsp[(6) - (14)]));
				ARG_OUT exp_to = YY2ARG((yyvsp[(8) - (14)]));
				ARG_OUT step = YY2ARG((yyvsp[(10) - (14)]));
				ARG_OUT suite = YY2ARG((yyvsp[(12) - (14)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_DORANGE, WHEN_DEBUG_OR_EMPTY("DO-RANGE-STEP GENERATED IN REGEN_SUITE") }, loop_variable, exp_from, exp_to, step, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (14)])), YY2ARG((yyvsp[(14) - (14)])));
				CLEAN_DELETE((yyvsp[(1) - (14)]), (yyvsp[(2) - (14)]), (yyvsp[(3) - (14)]), (yyvsp[(4) - (14)]), (yyvsp[(5) - (14)]), (yyvsp[(6) - (14)]), (yyvsp[(7) - (14)]), (yyvsp[(8) - (14)]), (yyvsp[(9) - (14)]), (yyvsp[(10) - (14)]), (yyvsp[(11) - (14)]), (yyvsp[(12) - (14)]), (yyvsp[(13) - (14)]), (yyvsp[(14) - (14)]));
			}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1756 "for90.y"
    {
				ARG_OUT exp = YY2ARG((yyvsp[(3) - (7)]));
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (7)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_WHILE, WHEN_DEBUG_OR_EMPTY("DO-WHILE GENERATED IN REGEN_SUITE") }, exp, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(6) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]));
			}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1766 "for90.y"
    {
				ARG_OUT select = YY2ARG((yyvsp[(2) - (9)]));
				ARG_OUT exp = YY2ARG((yyvsp[(5) - (9)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(8) - (9)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_SELECT, WHEN_DEBUG_OR_EMPTY("SELECT GENERATED IN REGEN_SUITE") }, exp, case_stmt);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (9)])), YY2ARG((yyvsp[(9) - (9)])));
				CLEAN_DELETE((yyvsp[(1) - (9)]), (yyvsp[(2) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]));
			}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1777 "for90.y"
    {
				// one case
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (6)]));
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)])); 

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1788 "for90.y"
    {
				// one case
				ARG_OUT dimen_slice = YY2ARG((yyvsp[(3) - (6)]));
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));

				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, dimen_slice, suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1799 "for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(4) - (4)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1807 "for90.y"
    {
				ARG_OUT suite = YY2ARG((yyvsp[(6) - (6)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASE, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, gen_dummy(), suite); 
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1817 "for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_CASES, WHEN_DEBUG_OR_EMPTY("CASE GENERATED IN REGEN_SUITE") }, case_stmt_elem);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1825 "for90.y"
    {
				ARG_OUT case_stmt_elem = YY2ARG((yyvsp[(1) - (2)]));
				ARG_OUT case_stmt = YY2ARG((yyvsp[(2) - (2)]));
				ParseNode newnode = gen_flatten(case_stmt_elem, case_stmt, "%s\n%s", TokenMeta::NT_CASES);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (2)])), YY2ARG((yyvsp[(2) - (2)])));
				CLEAN_DELETE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1835 "for90.y"
    {
				(yyval) = (yyvsp[(3) - (4)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (4)])), YY2ARG((yyvsp[(4) - (4)])));
				CLEAN_DELETE((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1841 "for90.y"
    {
				ParseNode newnode = gen_token(Term{ TokenMeta::UnknownVariant, "" }); // return nothing
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1848 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1853 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1859 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1864 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1869 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1875 "for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (10)])); // function name
				// enumerate parameter list 
				ARG_OUT paramtable = YY2ARG((yyvsp[(5) - (10)]));
				ARG_OUT variable_result = YY2ARG((yyvsp[(7) - (10)])); // result variable
				ARG_OUT suite = YY2ARG((yyvsp[(9) - (10)]));

				ParseNode kvparamtable = promote_argtable_to_paramtable(paramtable); // a flattened parameter list with all keyvalue elements
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, variable_result, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (10)])), YY2ARG((yyvsp[(10) - (10)])));
				CLEAN_DELETE((yyvsp[(1) - (10)]), (yyvsp[(2) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(9) - (10)]), (yyvsp[(10) - (10)]));
			}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1890 "for90.y"
    {
				ARG_OUT variable_function = YY2ARG((yyvsp[(3) - (6)])); // function name
				ARG_OUT suite = YY2ARG((yyvsp[(5) - (6)]));

				ParseNode kvparamtable = gen_token(Term{ TokenMeta::NT_PARAMTABLE_PURE, "" });
				ParseNode void_return = gen_token(Term{ TokenMeta::UnknownVariant, "" });
				ParseNode newnode = gen_token(Term{ TokenMeta::NT_FUNCTIONDECLARE, "" }, gen_dummy(), variable_function, kvparamtable, void_return, suite);
				(yyval) = RETURN_NT(newnode);

				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(1) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1903 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1908 "for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)));
			}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1914 "for90.y"
    {
				ParseNode & suite = YY2ARG((yyvsp[(4) - (6)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_PROGRAM_EXPLICIT, suite.get_what() }, suite));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (6)])), YY2ARG((yyvsp[(6) - (6)])));
				CLEAN_DELETE((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
			}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1922 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1927 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1937 "for90.y"
    {
				ARG_OUT stmt = YY2ARG((yyvsp[(1) - (1)]));
				(yyval) = RETURN_NT(gen_suite(stmt, gen_dummy()));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1944 "for90.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
			}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1949 "for90.y"
    {
				(yyval) = RETURN_NT(gen_dummy());
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1957 "for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (1)]));
				ParseNode newnode = gen_promote("%s", TokenMeta::NT_WRAPPERS, wrapper);
				(yyval) = RETURN_NT(newnode);
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (1)])), YY2ARG((yyvsp[(1) - (1)])));
				CLEAN_DELETE((yyvsp[(1) - (1)]));
			}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1965 "for90.y"
    {
				ARG_OUT wrapper = YY2ARG((yyvsp[(1) - (3)]));
				ARG_OUT wrappers = YY2ARG((yyvsp[(3) - (3)]));
#ifdef USE_REUSE
				ParseNode * newnode = new ParseNode();
				reuse_flatten(*newnode, wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS);
				(yyval) = newnode;
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_REUSE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				CLEAN_DELETE((yyvsp[(2) - (3)]));
#else
				(yyval) = RETURN_NT(gen_flatten(wrapper, wrappers, "%s\n%s", TokenMeta::NT_WRAPPERS));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (3)])), YY2ARG((yyvsp[(3) - (3)])));
				CLEAN_DELETE((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
#endif
			}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1983 "for90.y"
    {
				ARG_OUT wrappers = YY2ARG((yyvsp[(4) - (7)]));
				(yyval) = RETURN_NT(gen_token(Term{ TokenMeta::NT_INTERFACE, wrappers.get_what()}, wrappers));
				update_pos(YY2ARG((yyval)), YY2ARG((yyvsp[(1) - (7)])), YY2ARG((yyvsp[(7) - (7)])));
				CLEAN_DELETE((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
			}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1991 "for90.y"
    {
				gen_fortran_program(YY2ARG((yyvsp[(1) - (1)])));
			}
    break;


/* Line 1792 of yacc.c  */
#line 4854 "for90.tab.cpp"
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
#line 1996 "for90.y"

void update_yylval(Term & current_term) {
	get_tokenizer_state().CurrentTerm = current_term;
	ParseNode newnode{ TokenizerState(get_tokenizer_state()) , nullptr, nullptr };
	yylval = RETURN_NT(newnode);
}
void yyerror(const char* s)
{
	// fprintf(stderr, "%s", s);
	print_error(string(s), YY2ARG(yylval));
}
int parse(std::string code) {
#ifdef USE_YACC
#ifdef USE_LEX
	get_tokenizer_context().load_code = set_buff;
	get_tokenizer_context().unload_code = release_buff;
#else
	get_tokenizer_context().load_code = [&](const std::string & _code) {
		get_simpler_context().reset();
		get_simpler_context().code = _code;
		get_tokenizer_state().parse_line = 1;
	};
	get_tokenizer_context().unload_code = []() {
	
	};
#endif
	get_tokenizer_context().load_code(code);
	yyparse();
	get_tokenizer_context().unload_code();
#endif
	return 0;
}
