/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mypython.y"

void yyerror(char const *s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int findVal(char const *symbol);
void updateSymbolVal(char const *symbol, int val);
int operation(char op, int a, int b);
bool boolExpression(int arg1, char boolOp, int arg2);
void printString(char const *str);
void skipBlock();
void execConditional(bool val);
void addRecursiveList(string val);
void resetIfElseCount();
void storeFunction();
string runFunction(string funcName, string a, string b);

unordered_map<string, int> variables={};
vector<string> funcinstruct;
list<vector<string>> functions;

int funcflag=0;
static int funcIndent = 0;

extern int lineno;
extern int indent_level;

extern int numIf;
extern int numElse;
extern list<int> ifElseTracker;

extern list<string> mutatedVar;
extern list<string> recursiveEnd;



/* Line 189 of yacc.c  */
#line 121 "mypython.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     END = 259,
     LPAR = 260,
     RPAR = 261,
     LBRA = 262,
     RBRA = 263,
     COMMA = 264,
     IF = 265,
     ELSE = 266,
     EQ = 267,
     NE = 268,
     LT = 269,
     GT = 270,
     DEF = 271,
     RETURN = 272,
     COLON = 273,
     INDENT = 274,
     UNINDENT = 275,
     LE = 276,
     GE = 277,
     OPERATION = 278,
     number = 279,
     identifier = 280,
     STRING = 281
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 49 "mypython.y"
int num; char *id;


/* Line 214 of yacc.c  */
#line 187 "mypython.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "mypython.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    29,    27,     2,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    18,    22,    26,
      28,    31,    33,    36,    39,    43,    46,    50,    53,    57,
      60,    64,    68,    73,    78,    84,    92,    94,    97,   101,
     104,   107,   109,   115,   122,   131,   137,   144,   152,   162,
     168,   176,   186,   190,   200,   210,   220,   230,   240,   250,
     260,   270,   274,   278,   284,   290,   298,   305,   312,   319,
     326,   333,   340,   344,   351,   358,   365,   372,   379,   386,
     391,   393,   397,   401,   405,   409,   411,   413,   415,   419,
     423,   427,   431,   435,   439,   443,   447,   449
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    34,    -1,    41,    -1,    34,    41,    -1,
      34,    19,    41,    -1,    34,    35,    41,    -1,    34,    19,
      39,    -1,    34,    35,    39,    -1,    39,    -1,    34,    39,
      -1,    40,    -1,    34,    40,    -1,    19,    40,    -1,    34,
      19,    40,    -1,    35,    40,    -1,    34,    35,    40,    -1,
      36,     7,    -1,    34,    36,     7,    -1,    34,    37,    -1,
      34,    19,    37,    -1,    34,    35,    37,    -1,    34,    19,
      37,     8,    -1,    34,    25,     5,     6,    -1,    34,    25,
       5,    42,     6,    -1,    34,    25,     5,    42,     9,    42,
       6,    -1,     4,    -1,    34,     4,    -1,    34,     4,     4,
      -1,    34,     8,    -1,    20,    35,    -1,    20,    -1,    16,
      25,     5,     6,     4,    -1,    16,    25,     5,    25,     6,
       4,    -1,    16,    25,     5,    25,     9,    25,     6,     4,
      -1,    17,    25,     5,     6,     4,    -1,    17,    25,     5,
       6,     4,    35,    -1,    17,    25,     5,    25,     6,     4,
      35,    -1,    17,    25,     5,    25,     9,    25,     6,     4,
      35,    -1,    17,     5,    42,     6,     4,    -1,    17,    25,
       5,    38,     6,     4,    35,    -1,    17,    25,     5,    38,
       9,    38,     6,     4,    35,    -1,    17,    44,     4,    -1,
      17,    25,    27,    25,     5,    38,     6,     4,    35,    -1,
      17,    25,     5,    38,     6,    27,    25,     4,    35,    -1,
      17,    25,    28,    25,     5,    38,     6,     4,    35,    -1,
      17,    25,     5,    38,     6,    28,    25,     4,    35,    -1,
      17,    25,    29,    25,     5,    38,     6,     4,    35,    -1,
      17,    25,     5,    38,     6,    29,    25,     4,    35,    -1,
      17,    25,    30,    25,     5,    38,     6,     4,    35,    -1,
      17,    25,     5,    38,     6,    30,    25,     4,    35,    -1,
      25,    27,    24,    -1,    25,    28,    24,    -1,     3,     5,
      42,     6,     4,    -1,     3,     5,    26,     6,     4,    -1,
       3,     5,    26,     9,    42,     6,     4,    -1,    10,    25,
      12,    42,    18,     4,    -1,    10,    25,    13,    42,    18,
       4,    -1,    10,    25,    14,    42,    18,     4,    -1,    10,
      25,    15,    42,    18,     4,    -1,    10,    25,    21,    42,
      18,     4,    -1,    10,    25,    22,    42,    18,     4,    -1,
      11,    18,     4,    -1,    10,    42,    12,    42,    18,     4,
      -1,    10,    42,    13,    42,    18,     4,    -1,    10,    42,
      14,    42,    18,     4,    -1,    10,    42,    15,    42,    18,
       4,    -1,    10,    42,    21,    42,    18,     4,    -1,    10,
      42,    22,    42,    18,     4,    -1,    25,    31,    42,     4,
      -1,    43,    -1,    42,    27,    42,    -1,    42,    28,    42,
      -1,    42,    29,    42,    -1,    42,    30,    42,    -1,    24,
      -1,    25,    -1,    45,    -1,    25,    27,    44,    -1,    25,
      28,    44,    -1,    25,    29,    44,    -1,    25,    30,    44,
      -1,    24,    27,    44,    -1,    24,    28,    44,    -1,    24,
      29,    44,    -1,    24,    30,    44,    -1,    24,    -1,    25,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    93,    94,    95,    96,    99,   100,   101,
     102,   105,   106,   107,   108,   109,   110,   113,   114,   117,
     118,   119,   122,   127,   128,   129,   134,   135,   136,   138,
     144,   145,   148,   149,   150,   153,   154,   155,   156,   157,
     158,   159,   161,   163,   164,   166,   167,   169,   170,   172,
     173,   177,   178,   180,   181,   182,   185,   186,   187,   188,
     189,   190,   191,   193,   194,   195,   196,   197,   198,   201,
     204,   205,   206,   207,   208,   211,   212,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   226,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "END", "LPAR", "RPAR", "LBRA",
  "RBRA", "COMMA", "IF", "ELSE", "EQ", "NE", "LT", "GT", "DEF", "RETURN",
  "COLON", "INDENT", "UNINDENT", "LE", "GE", "OPERATION", "number",
  "identifier", "STRING", "'+'", "'-'", "'*'", "'/'", "'='", "$accept",
  "begin", "line", "unindents", "func", "returnstm", "parameters",
  "printer", "ifelse", "assignment", "exp", "term", "nonevalexp",
  "nonevalterm", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    43,    45,    42,
      47,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      35,    35,    36,    36,    36,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      42,    42,    42,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     3,     1,
       2,     1,     2,     2,     3,     2,     3,     2,     3,     2,
       3,     3,     4,     4,     5,     7,     1,     2,     3,     2,
       2,     1,     5,     6,     8,     5,     6,     7,     9,     5,
       7,     9,     3,     9,     9,     9,     9,     9,     9,     9,
       9,     3,     3,     5,     5,     7,     6,     6,     6,     6,
       6,     6,     3,     6,     6,     6,     6,     6,     6,     4,
       1,     3,     3,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    26,     0,     0,     0,     0,    31,     0,     0,
       2,     0,     0,     9,    11,     3,     0,    75,    76,     0,
      70,     0,     0,    13,    30,     0,     1,    27,    29,     0,
       0,     0,     0,     0,    19,    10,    12,     4,    15,    17,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,    28,     0,    86,    87,     0,    77,    20,     7,
      14,     5,     0,    21,     8,    16,     6,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    22,    23,     0,    54,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,    87,    82,    83,    84,    85,     0,     0,
       0,    87,    78,    87,    79,    87,    80,    87,    81,    24,
       0,     0,    56,    57,    58,    59,    60,    61,    63,    64,
      65,    66,    67,    68,    33,     0,    39,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    36,     0,     0,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    34,    37,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    44,    46,    48,    50,
      41,    43,    45,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    34,   140,    13,    14,    15,
      19,    20,   142,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
     177,     7,  -163,    73,    37,    -4,   137,    41,    40,    68,
     157,   137,    71,  -163,  -163,  -163,   -16,  -163,   210,   206,
    -163,   101,   109,  -163,  -163,   130,  -163,   112,  -163,    62,
       3,    51,     3,   131,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,    48,    97,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,  -163,
      98,    18,  -163,   130,   171,    61,   125,  -163,   145,  -163,
    -163,  -163,    -1,  -163,  -163,  -163,  -163,  -163,   162,   130,
     168,   176,   211,   219,   224,   232,   237,   245,   250,   258,
     263,   271,   276,   133,   133,  -163,  -163,   174,    63,  -163,
     116,   146,   146,   146,   146,   105,   160,   220,   233,   246,
    -163,  -163,  -163,   104,  -163,   122,  -163,   182,   186,   188,
     191,   203,   222,   226,   239,   252,   265,   291,   292,  -163,
     293,   150,   298,   280,  -163,  -163,  -163,  -163,   307,    -2,
     106,    65,  -163,    72,  -163,    79,  -163,    91,  -163,  -163,
     130,   308,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,   278,  -163,   146,   146,   146,
     146,    41,   309,   289,   294,   295,    23,   290,   290,   290,
     290,   290,   129,  -163,   312,  -163,    41,   311,  -163,  -163,
      41,   296,   297,   299,   300,   255,   314,   317,   320,   321,
     322,  -163,  -163,  -163,   325,  -163,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,    -7,   335,    30,  -162,   107,    53,   159,
     -14,  -163,   -28,  -163
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      24,    66,    42,    32,   172,   112,     1,   173,    17,    40,
      41,    61,    16,     3,     4,   196,   197,   198,   199,   200,
      29,    22,    99,    17,    40,   174,   175,   190,     8,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    55,    56,    57,    58,   100,
     191,   192,   193,   194,    78,    21,    72,    79,   113,    23,
      68,     7,    73,    36,    38,   115,   105,    63,    26,   130,
     178,    25,   131,   134,   135,   136,   137,   179,    39,   144,
     146,   148,    25,    70,   180,    75,    64,    65,   106,   107,
     108,   109,   167,   168,   169,   170,   181,    17,    18,   167,
     168,   169,   170,    80,    97,    59,   167,   168,   169,   170,
     149,   138,   176,   150,    60,   177,    62,    35,   167,   168,
     169,   170,   132,    98,    55,    56,    57,    58,   151,   110,
     139,    55,    56,    57,    58,   201,   182,    69,    77,    74,
     144,   146,   148,    55,    56,    57,    58,     3,     4,    55,
      56,    57,    58,   111,    17,    40,    55,    56,    57,    58,
       1,    27,    57,    58,   185,    28,   114,     3,     4,    37,
      64,   133,   116,     5,    29,   165,    30,     7,   129,   203,
       1,     2,    31,   205,    64,   141,   152,     3,     4,    71,
     153,    76,   154,     5,   117,   155,     6,     7,   101,   102,
     103,   104,     8,    55,    56,    57,    58,   156,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    49,    50,
      51,    52,    43,    44,    45,    46,   157,    53,    54,   118,
     158,    47,    48,    55,    56,    57,    58,   119,    55,    56,
      57,    58,   120,   159,    64,   143,    55,    56,    57,    58,
     121,    55,    56,    57,    58,   122,   160,    64,   145,    55,
      56,    57,    58,   123,    55,    56,    57,    58,   124,   161,
      64,   147,    55,    56,    57,    58,   125,    55,    56,    57,
      58,   126,   174,   175,   184,    55,    56,    57,    58,   127,
      55,    56,    57,    58,   128,   162,   163,   164,    55,    56,
      57,    58,   166,    55,    56,    57,    58,   167,   168,   169,
     170,   171,   183,   186,   187,   195,   202,   204,   188,   189,
     210,   206,   207,   211,   208,   209,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,     0,
       0,     0,     0,     0,     0,    33
};

static const yytype_int16 yycheck[] =
{
       7,    29,    16,    10,     6,     6,     3,     9,    24,    25,
      26,    25,     5,    10,    11,   177,   178,   179,   180,   181,
      17,    25,     4,    24,    25,    27,    28,     4,    25,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    27,    28,    29,    30,    63,
      27,    28,    29,    30,     6,    18,     5,     9,    72,     6,
      30,    20,    32,    10,    11,    79,     5,     5,     0,     6,
       5,    31,     9,   101,   102,   103,   104,     5,     7,   107,
     108,   109,    31,    30,     5,    32,    24,    25,    27,    28,
      29,    30,    27,    28,    29,    30,     5,    24,    25,    27,
      28,    29,    30,     6,     6,     4,    27,    28,    29,    30,
       6,     6,     6,     9,     5,     9,     4,    10,    27,    28,
      29,    30,     6,    25,    27,    28,    29,    30,     6,     4,
      25,    27,    28,    29,    30,     6,   150,    30,     7,    32,
     168,   169,   170,    27,    28,    29,    30,    10,    11,    27,
      28,    29,    30,     8,    24,    25,    27,    28,    29,    30,
       3,     4,    29,    30,   171,     8,     4,    10,    11,    10,
      24,    25,     4,    16,    17,    25,    19,    20,     4,   186,
       3,     4,    25,   190,    24,    25,     4,    10,    11,    30,
       4,    32,     4,    16,    18,     4,    19,    20,    27,    28,
      29,    30,    25,    27,    28,    29,    30,     4,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    12,    13,
      14,    15,    12,    13,    14,    15,     4,    21,    22,    18,
       4,    21,    22,    27,    28,    29,    30,    18,    27,    28,
      29,    30,    18,     4,    24,    25,    27,    28,    29,    30,
      18,    27,    28,    29,    30,    18,     4,    24,    25,    27,
      28,    29,    30,    18,    27,    28,    29,    30,    18,     4,
      24,    25,    27,    28,    29,    30,    18,    27,    28,    29,
      30,    18,    27,    28,     6,    27,    28,    29,    30,    18,
      27,    28,    29,    30,    18,     4,     4,     4,    27,    28,
      29,    30,     4,    27,    28,    29,    30,    27,    28,    29,
      30,     4,     4,     4,    25,    25,     4,     6,    24,    24,
       6,    25,    25,     6,    25,    25,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    10,    11,    16,    19,    20,    25,    33,
      34,    35,    36,    39,    40,    41,     5,    24,    25,    42,
      43,    18,    25,    40,    35,    31,     0,     4,     8,    17,
      19,    25,    35,    36,    37,    39,    40,    41,    40,     7,
      25,    26,    42,    12,    13,    14,    15,    21,    22,    12,
      13,    14,    15,    21,    22,    27,    28,    29,    30,     4,
       5,    42,     4,     5,    24,    25,    44,    45,    37,    39,
      40,    41,     5,    37,    39,    40,    41,     7,     6,     9,
       6,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,     6,    25,     4,
      42,    27,    28,    29,    30,     5,    27,    28,    29,    30,
       4,     8,     6,    42,     4,    42,     4,    18,    18,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,     4,
       6,     9,     6,    25,    44,    44,    44,    44,     6,    25,
      38,    25,    44,    25,    44,    25,    44,    25,    44,     6,
       9,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    25,     4,    27,    28,    29,
      30,     4,     6,     9,    27,    28,     6,     9,     5,     5,
       5,     5,    42,     4,     6,    35,     4,    25,    24,    24,
       4,    27,    28,    29,    30,    25,    38,    38,    38,    38,
      38,     6,     4,    35,     6,    35,    25,    25,    25,    25,
       6,     6,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1464 of yacc.c  */
#line 89 "mypython.y"
    {;;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 93 "mypython.y"
    {;;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 94 "mypython.y"
    {;;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 95 "mypython.y"
    {;;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 96 "mypython.y"
    {;;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 99 "mypython.y"
    {;;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 100 "mypython.y"
    {;;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 101 "mypython.y"
    {;;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 102 "mypython.y"
    {;;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 105 "mypython.y"
    {;;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 106 "mypython.y"
    {;;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 107 "mypython.y"
    {;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 108 "mypython.y"
    {;;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 109 "mypython.y"
    {;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 110 "mypython.y"
    {;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 113 "mypython.y"
    {funcflag=1;;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 114 "mypython.y"
    {funcflag=1;;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 117 "mypython.y"
    {;;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 118 "mypython.y"
    {;;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 119 "mypython.y"
    {;;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 122 "mypython.y"
    {funcflag=0; storeFunction();;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 127 "mypython.y"
    {recursiveEnd.push_back(runFunction((yyvsp[(2) - (4)].id), "none", "none"));;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 128 "mypython.y"
    {recursiveEnd.push_back(runFunction((yyvsp[(2) - (5)].id), to_string((yyvsp[(4) - (5)].num)), "none"));;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 129 "mypython.y"
    {recursiveEnd.push_back(runFunction((yyvsp[(2) - (7)].id), to_string((yyvsp[(4) - (7)].num)), to_string((yyvsp[(6) - (7)].num))));;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 134 "mypython.y"
    {;;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 135 "mypython.y"
    {lineno++; resetIfElseCount();;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 136 "mypython.y"
    {resetIfElseCount();;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 138 "mypython.y"
    {storeFunction();;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 144 "mypython.y"
    {;;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 145 "mypython.y"
    {;;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 148 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (5)].id));;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 149 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (6)].id));;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 150 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (8)].id));;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 153 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (5)].id));;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 154 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (6)].id));;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 155 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (7)].id));;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 156 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 157 "mypython.y"
    {;;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 158 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (7)].id));;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 159 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 161 "mypython.y"
    {;;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 163 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 164 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 166 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 167 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 169 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 170 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 172 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 173 "mypython.y"
    {funcinstruct.push_back((yyvsp[(2) - (9)].id));;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 177 "mypython.y"
    {;;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 178 "mypython.y"
    {;;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 180 "mypython.y"
    {;;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 181 "mypython.y"
    {;;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 182 "mypython.y"
    {;;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 185 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 186 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 187 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 188 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 189 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 190 "mypython.y"
    {if (funcflag == 0) {numIf++;} else {funcinstruct.push_back((yyvsp[(2) - (6)].id));} ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 191 "mypython.y"
    {if (funcflag == 0) {numElse++;} ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 193 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 194 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 195 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 196 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 197 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 198 "mypython.y"
    {if (funcflag == 0) {numIf++;};}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 201 "mypython.y"
    {updateSymbolVal((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].num));;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 204 "mypython.y"
    {(yyval.num)=(yyvsp[(1) - (1)].num);;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 205 "mypython.y"
    {(yyval.num)=operation('+', (yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num));;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 206 "mypython.y"
    {(yyval.num)=operation('-', (yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num));;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 207 "mypython.y"
    {(yyval.num)=operation('*', (yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num));;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 208 "mypython.y"
    {(yyval.num)=operation('/', (yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num));;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 211 "mypython.y"
    {(yyval.num)=(yyvsp[(1) - (1)].num);;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 212 "mypython.y"
    {(yyval.num)=findVal((yyvsp[(1) - (1)].id));;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 215 "mypython.y"
    {;;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 216 "mypython.y"
    {;;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 217 "mypython.y"
    {;;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 218 "mypython.y"
    {;;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 219 "mypython.y"
    {;;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 220 "mypython.y"
    {;;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 221 "mypython.y"
    {;;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 222 "mypython.y"
    {;;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 223 "mypython.y"
    {;;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 226 "mypython.y"
    {;;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 227 "mypython.y"
    {;;}
    break;



/* Line 1464 of yacc.c  */
#line 2214 "mypython.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1684 of yacc.c  */
#line 230 "mypython.y"
	/*C++*/

int operation(char op, int a, int b)
{
	int result=0;

	switch(op)
	{
	case '+':
		result=a+b;
		break;
	case '-':
		result=a-b;
		break;
	case '*':
		result=a*b;
		break;
	case '/':
		result=a/b;
		break;
	}
	return result;
}

bool boolExpression(int arg1, char boolOp, int arg2)
{
	switch(boolOp)
	{
	case 'e':
		return arg1 == arg2;
	case 'n':
		return arg1 != arg2;
	case 'l':
		return arg1 < arg2;
	case 'g':
		return arg1 > arg2;
	case 'c':
		return arg1 <= arg2;
	case 'v':
		return arg1 >= arg2;
	}
}

//returns value of given symbol
int findVal(char const *symbol)
{
	//int bucket=computeSymbolIndex(symbol);
	//return symbols[bucket];

	string sym=symbol;
	auto found=variables.find(sym);

	if(found==variables.end())
	{
		//yyerror("Uninitialized variable");
		return -1;
	}
	else
	{
		return found->second;
	}
}

//update variable values in map
void updateSymbolVal(char const *symbol, int val)
{
	string sym(symbol);
	sym.erase(remove(sym.begin(), sym.end(), ' '), sym.end());
	sym=sym.substr(0, sym.find("="));

	auto found=variables.find(sym);
	//cout<<sym<<endl;

	if(found!=variables.end() && funcflag==0)
	{
		//found
		mutatedVar.push_back(sym);
	}
	variables[sym]=val;
}

//print string literals
void printString(char const *cstr)
{
	string str(cstr);
	str=str.substr(0, str.find(','));
	str.erase(remove(str.begin(), str.end(), '"'), str.end());
	str.erase(remove(str.begin(), str.end(), '('), str.end());
	str.erase(remove(str.begin(), str.end(), ')'), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());

	cout<<str;
}

int main(void)
{
	/*
	printf("END %i \n", END);
	printf("LBRA %i \n", LBRA);
	printf("RBRA %i \n", RBRA);
	printf("INDENT %i \n", INDENT);
	printf("UNINDENT %i \n", UNINDENT);
	printf("RETURN %i \n", RETURN);

	for(int i = 0; i < 100; i++)
	{
		//if(yylex()==274)
		//cout << yylex() << endl;
	}
	*/

	return yyparse();
}

//print error messages
void yyerror(char const *s)
{
	cout<<"Error on line "<<lineno<<": ";
	fprintf(stderr, "%s. Exiting program now.\n", s);
	exit(-1);
}

void skipBlock()
{
	int n = yylex();
	while(n != 273)
	{
		n = yylex();
	}
}

void execConditional(bool val)
{
	if (val == false)
	{
		skipBlock();
	}
}

//add to list whether function ends
void addRecursiveList(string val)
{
	recursiveEnd.push_back(val);
}

void resetIfElseCount()
{
	if (numIf >= numElse)
	{
		if (numIf > -1)
		{
			ifElseTracker.push_back(numIf);
		}
	}
	else
	{
		yyerror("'else' without 'if'");
	}
	numIf = -1;
	numElse = -1;
}

//store recursive function into list
void storeFunction()
{
	//cout << "Start store" << endl;
	functions.push_back(funcinstruct);
	funcinstruct.clear();
	//cout << "End store" << endl;

	for(auto item: functions)
	{
		vector<string> func=item;

		for(auto item: func)
		{
			//cout<<"8"<<item<<" ";
		}
		//cout<<endl;
	}
}

//test recursive functions
string runFunction(string funcName, string a, string b)
{
	//find correct function
	funcName=funcName.substr(0, funcName.find("("));

	//search list of functions
	for(auto item: functions)
	{
		vector<string> func=item;
		string definition=func.front();
		//cout<<"="<<definition<<endl;
		string listfuncname=definition.substr(0, definition.find("("));
		string param=definition.substr(definition.find("(")+1, definition.find(")")-2);
		string varA="", varB="";
		int val1=0, val2=0;

		//cout<<"+"<<funcName<<endl;
		//cout<<"+"<<listfuncname<<endl;

		if(funcName==listfuncname)
		{
			//no parameters
			if((a=="none") && (b=="none"))
			{
				string temp=func[1].substr(0, func[1].size()-2);
				//definition.erase(std::remove(definition.begin(), definition.end(), '\n'), definition.end());
				//cout<<temp<<endl;
				definition=definition.substr(0, definition.size()-1);
				//cout<<definition<<endl;

				if(temp.find(definition)!=string::npos)
				{
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			//1 parameter
			else if((a != "none") && (b == "none"))
			{
				val1=stoi(a);
				varA = param.substr(0, param.size()-1);
			}
			//2 parameters
			else if((a != "none") && (b != "none"))
			{
				val1=stoi(a);
				val2=stoi(b);
				varA = param.substr(0, param.find(","));
				varB = param.substr(param.find(",")+1, param.find(")")-2);
				//cout<<":"<<varA<<":"<<varB<<":"<<endl;
			}
			string comparison=func[1];
			string recall=func[2];
			int num2=0;
			string letter="";

			recall=recall.substr(recall.find("(")+1, recall.find(")")-3);
			int adder = 0;
			if (varA != recall)
			{
				adder=stoi(recall.substr(varA.size()+1, recall.size()));
			}

			if(comparison.find("==")!=string::npos)
			{
				//string num2=comparison.substr(comparison.find("==")+2, comparison.find(":")-3);
				letter=comparison.substr(0, comparison.find("=="));
				num2=stoi(comparison.substr(comparison.find("==")+2, comparison.find(":")-3));
				//cout<<letter<<endl;

				if(boolExpression(val1,'e', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
				else
				{
					int distance = abs(val1-num2);
					if (distance%adder != 0)
					{
						return "no";
					}
				}
			}
			else if(comparison.find(">=")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find(">=")+2, comparison.find(":")-3));

				if(boolExpression(val1,'v', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find("<=")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find("<=")+2, comparison.find(":")-3));

				if(boolExpression(val1,'c', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find("<")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find("<")+1, comparison.find(":")-4));
				num2=num2-1;
				if(boolExpression(val1,'c', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find(">")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find(">")+1, comparison.find(":")-4));
				num2=num2+1;
				if(boolExpression(val1,'v', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}

			if(recall.find(",")!=string::npos)
			{
				string temp=recall.substr(0, recall.find(","));
				//cout<<temp<<endl;

				if(temp.find("+")!=string::npos)
				{
					//increment
					int result=val1+1;

					int delta=abs(val1-num2);
					int delta2=abs(result-num2);

					if(delta2>delta)
					{
						//infinite recursion
						return "no";
					}
					else
					{
						return "yes";
					}
				}
				else if(temp.find("-")!=string::npos)
				{
					//decrement
					adder=stoi(recall.substr(varA.size()+1, recall.size()));
					int result=val1-1;

					int delta=abs(val1-num2);
					int delta2=abs(result-num2);

					if(delta2>delta)
					{
						//infinite recursion
						return "no";
					}
					else
					{
						return "yes";
					}
				}
				//val1=3, val2=4
			}
			else if(recall.find("+")!=string::npos)
			{
				//increment
				int result=val1+1;

				int delta=abs(val1-num2);
				int delta2=abs(result-num2);

				if(delta2>delta)
				{
					//infinite recursion
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			else if(recall.find("-")!=string::npos)
			{
				//decrement
				adder=stoi(recall.substr(varA.size()+1, recall.size()));
				int result=val1-1;

				int delta=abs(val1-num2);
				int delta2=abs(result-num2);

				if(delta2>delta)
				{
					//infinite recursion
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			else
			{
				return "no";
			}
		}
	}
}

