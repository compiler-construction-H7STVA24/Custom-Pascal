/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KEY_PROGRAM = 258,
     KEY_INTEGER = 259,
     KEY_REAL = 260,
     KEY_BOOLEAN = 261,
     KEY_CHAR = 262,
     KEY_VAR = 263,
     KEY_TO = 264,
     KEY_DOWNTO = 265,
     KEY_THEN = 266,
     KEY_IF = 267,
     KEY_ELSE = 268,
     KEY_WHILE = 269,
     KEY_FOR = 270,
     KEY_DO = 271,
     KEY_ARRAY = 272,
     KEY_AND = 273,
     KEY_OR = 274,
     KEY_NOT = 275,
     KEY_BEGIN = 276,
     KEY_END = 277,
     KEY_READ = 278,
     KEY_WRITE = 279,
     DOT = 280,
     COMMA = 281,
     COLON = 282,
     SEMICOLON = 283,
     NEWLINE = 284,
     INT = 285,
     REAL = 286,
     ID = 287,
     OPR_PLUS = 288,
     OPR_MINUS = 289,
     OPR_DIV = 290,
     OPR_MUL = 291,
     OPR_MOD = 292,
     EQ = 293,
     LT = 294,
     GT = 295,
     NE = 296,
     LE = 297,
     GE = 298,
     LPAREN = 299,
     RPAREN = 300,
     STR = 301,
     KEY_OF = 302,
     LBRACKET = 303,
     RBRACKET = 304,
     TDOT = 305
   };
#endif
/* Tokens.  */
#define KEY_PROGRAM 258
#define KEY_INTEGER 259
#define KEY_REAL 260
#define KEY_BOOLEAN 261
#define KEY_CHAR 262
#define KEY_VAR 263
#define KEY_TO 264
#define KEY_DOWNTO 265
#define KEY_THEN 266
#define KEY_IF 267
#define KEY_ELSE 268
#define KEY_WHILE 269
#define KEY_FOR 270
#define KEY_DO 271
#define KEY_ARRAY 272
#define KEY_AND 273
#define KEY_OR 274
#define KEY_NOT 275
#define KEY_BEGIN 276
#define KEY_END 277
#define KEY_READ 278
#define KEY_WRITE 279
#define DOT 280
#define COMMA 281
#define COLON 282
#define SEMICOLON 283
#define NEWLINE 284
#define INT 285
#define REAL 286
#define ID 287
#define OPR_PLUS 288
#define OPR_MINUS 289
#define OPR_DIV 290
#define OPR_MUL 291
#define OPR_MOD 292
#define EQ 293
#define LT 294
#define GT 295
#define NE 296
#define LE 297
#define GE 298
#define LPAREN 299
#define RPAREN 300
#define STR 301
#define KEY_OF 302
#define LBRACKET 303
#define RBRACKET 304
#define TDOT 305




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "sym.h"

extern int yylex();
extern int yyparse();
extern void yyerror(const char *s);
void cust_err(const char *s);
extern FILE* yyin;
extern FILE* yyout;

int k = 1;
int l = 1;
int w = 1;

int tacLineNo = 1;

void gencode(char *word, char *first, char *op, char *second) {
        char temp[10];
        sprintf(temp, "%d", k++);
        strcat(word, temp);
        fprintf(yyout, "%s %s %s %s\n", op, first, second, word);
}

void onlyGencode(char *word) {
    char temp[10];
    sprintf(temp, "%d", k++);
    strcat(word, temp);
}

void genlabel(char *word) {
    char temp[10];
    sprintf(temp, "%d", l++);
    strcat(word, temp);
}

symNode sym_table[MAX_SYMBOLS];
char *sym_names[MAX_SYMBOLS];

unsigned long sym_hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        hash = hash % MAX_SYMBOLS;

    return hash;
}

void printNode(nodeType *p);
nodeType *opr(typeEnum oper, int nops, ...);
nodeType *id(int i);
nodeType *conInt(int value);
nodeType *conReal(float value);
nodeType *conStr(char *value);
void decEx(nodeType *root);

void freeNode(nodeType *p);

nodeType *ex(nodeType *root);

char* getName(int hash) {
    return sym_names[hash];
}

void setName(int hash, char* name) {
    sym_names[hash] = strdup(name);
} 

void printSymTable();

char *generateTAC(nodeType *, int);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 82 "parser.y"
{
  char *sval;
  int ival;
  int sIndex;
  nodeType *nPtr;
  float rval;
}
/* Line 193 of yacc.c.  */
#line 285 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 298 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    16,    18,    20,
      22,    24,    28,    32,    36,    40,    44,    48,    50,    53,
      56,    58,    62,    64,    69,    81,    83,    85,    87,    89,
      95,   101,   107,   111,   113,   117,   119,   125,   129,   133,
     137,   141,   145,   149,   153,   157,   161,   163,   165,   167,
     169,   172,   174,   182,   194,   202,   209,   217,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    46,    -1,    30,    -1,    31,    -1,    32,
      -1,    55,    48,    58,    49,    -1,    53,    -1,    56,    -1,
      55,    -1,    54,    -1,    58,    33,    58,    -1,    58,    34,
      58,    -1,    58,    36,    58,    -1,    58,    37,    58,    -1,
      58,    35,    58,    -1,    44,    58,    45,    -1,    57,    -1,
       8,    60,    -1,    62,    60,    -1,    62,    -1,    55,    26,
      61,    -1,    55,    -1,    61,    27,    63,    28,    -1,    61,
      27,    17,    48,    53,    50,    53,    49,    47,    63,    28,
      -1,     4,    -1,     7,    -1,     5,    -1,     6,    -1,    23,
      44,    55,    45,    28,    -1,    23,    44,    56,    45,    28,
      -1,    24,    44,    65,    45,    28,    -1,    57,    26,    65,
      -1,    57,    -1,    52,    26,    65,    -1,    52,    -1,    55,
      27,    38,    58,    28,    -1,    58,    38,    58,    -1,    58,
      41,    58,    -1,    58,    39,    58,    -1,    58,    42,    58,
      -1,    58,    40,    58,    -1,    58,    43,    58,    -1,    44,
      67,    45,    -1,    67,    18,    67,    -1,    67,    19,    67,
      -1,    66,    -1,    64,    -1,    70,    -1,    74,    -1,    68,
      69,    -1,    68,    -1,    12,    67,    11,    21,    69,    22,
      28,    -1,    12,    67,    11,    21,    69,    22,    13,    21,
      69,    22,    28,    -1,    14,    67,    16,    21,    69,    22,
      28,    -1,    55,    27,    38,    58,     9,    58,    -1,    15,
      72,    16,    21,    69,    22,    28,    -1,    73,    -1,    71,
      -1,     3,    55,    28,    59,    21,    69,    22,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   116,   119,   122,   126,   130,   134,   138,
     142,   146,   150,   154,   158,   162,   166,   170,   174,   178,
     182,   184,   188,   192,   196,   200,   204,   208,   212,   218,
     222,   227,   232,   237,   242,   247,   252,   257,   263,   269,
     275,   281,   287,   293,   297,   303,   310,   312,   314,   316,
     318,   322,   326,   331,   336,   340,   344,   348,   350,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEY_PROGRAM", "KEY_INTEGER", "KEY_REAL",
  "KEY_BOOLEAN", "KEY_CHAR", "KEY_VAR", "KEY_TO", "KEY_DOWNTO", "KEY_THEN",
  "KEY_IF", "KEY_ELSE", "KEY_WHILE", "KEY_FOR", "KEY_DO", "KEY_ARRAY",
  "KEY_AND", "KEY_OR", "KEY_NOT", "KEY_BEGIN", "KEY_END", "KEY_READ",
  "KEY_WRITE", "DOT", "COMMA", "COLON", "SEMICOLON", "NEWLINE", "INT",
  "REAL", "ID", "OPR_PLUS", "OPR_MINUS", "OPR_DIV", "OPR_MUL", "OPR_MOD",
  "EQ", "LT", "GT", "NE", "LE", "GE", "LPAREN", "RPAREN", "STR", "KEY_OF",
  "LBRACKET", "RBRACKET", "TDOT", "$accept", "str_val", "int_val",
  "real_val", "identifier", "array_index", "atom", "expr", "decl_top",
  "decls", "mult_id", "decl", "data_type", "read_write", "args",
  "assignment", "bool_expr", "statement", "body", "conditional",
  "while_loop", "for_range", "for_loop", "loop", "program", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    65,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    72,    73,    74,    74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       1,     3,     1,     4,    11,     1,     1,     1,     1,     5,
       5,     5,     3,     1,     3,     1,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       2,     1,     7,    11,     7,     6,     7,     1,     1,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,     0,     0,     0,    22,
      18,     0,    20,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    47,    46,    51,     0,    48,    58,    57,
      49,    21,    25,    27,    28,    26,     0,     0,     3,     4,
       0,     7,    10,     9,     8,    17,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    35,    33,     0,     0,    59,     0,    16,    43,     0,
       0,    11,    12,    15,    13,    14,    37,    39,    41,    38,
      40,    42,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,    29,    30,    34,    32,    31,    36,     0,     0,     0,
       0,     0,     0,     0,    52,    54,    55,    56,     0,     0,
       0,     0,    24,     0,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    81,    41,    42,    43,    44,    45,    46,     8,    10,
      11,    12,    37,    23,    83,    24,    47,    25,    26,    27,
      28,    50,    29,    30,     2
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -53
static const yytype_int16 yypact[] =
{
       0,   -22,    21,   -53,    15,   -53,    49,   -22,    42,    46,
     -53,    72,   -22,    41,   -22,    83,   -53,     8,     8,   -22,
      32,    59,    78,   -53,   -53,    41,    94,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,    80,   107,   -53,   -53,
       8,   -53,   -53,    88,   -53,   -53,   110,    40,    61,   112,
     124,   -22,   -23,    99,   -53,   116,   129,   -53,    84,    -3,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,   139,     8,     8,   140,   125,   141,   -31,   119,
     -53,   142,   143,   120,    54,   -53,   117,   -53,   -53,    54,
      33,    77,    77,   133,   133,   -53,   121,   121,   121,   121,
     121,   121,    41,   -53,   -53,    41,    54,    41,   138,   144,
     -23,   -23,   145,    74,   129,    97,   -53,   149,   152,    11,
     153,   -53,   -53,   -53,   -53,   -53,   -53,   127,     9,   150,
      54,   151,   130,   159,   -53,   -53,   121,   -53,    87,    41,
     154,   161,   -53,   156,   -53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -52,   -53,    -1,   134,   -50,   -35,   -53,   169,
     172,   -53,    50,   -53,   -14,   -53,     1,   -53,   -24,   -53,
     -53,   -53,   -53,   -53,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       4,    54,    82,     1,    86,    58,     9,    38,    39,     3,
       3,     9,    22,     9,   108,    73,    74,    60,    49,    48,
     130,     5,   133,    80,    22,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   134,    38,    39,
       3,    59,    88,     6,    61,    62,    63,    64,    65,   113,
      78,    72,    40,    17,   115,    18,    19,     7,    73,    74,
      82,    82,   127,    13,    20,    21,    61,    62,    63,    64,
      65,   119,    14,     3,   103,   104,    51,    75,   117,    73,
      74,   118,   116,   120,    38,    39,     3,    32,    33,    34,
      35,    32,    33,    34,    35,   136,   123,   124,    89,    15,
      36,    22,   126,    52,    22,    53,    22,    61,    62,    63,
      64,    65,    63,    64,    65,   141,    55,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    56,    87,
      61,    62,    63,    64,    65,    57,    60,    84,    22,    76,
      77,    85,    87,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    63,    64,    65,    38,
     102,   105,   107,   106,   109,   112,   121,   114,   110,   111,
      65,   128,   122,   125,   129,   131,   132,   138,   135,   137,
     139,    16,   142,   143,   144,    79,    31,     0,   140
};

static const yytype_int16 yycheck[] =
{
       1,    25,    52,     3,    56,    40,     7,    30,    31,    32,
      32,    12,    13,    14,    45,    18,    19,    48,    19,    18,
       9,     0,    13,    46,    25,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    28,    30,    31,
      32,    40,    45,    28,    33,    34,    35,    36,    37,    84,
      51,    11,    44,    12,    89,    14,    15,     8,    18,    19,
     110,   111,   114,    21,    23,    24,    33,    34,    35,    36,
      37,   106,    26,    32,    73,    74,    44,    16,   102,    18,
      19,   105,    49,   107,    30,    31,    32,     4,     5,     6,
       7,     4,     5,     6,     7,   130,   110,   111,    44,    27,
      17,   102,    28,    44,   105,    27,   107,    33,    34,    35,
      36,    37,    35,    36,    37,   139,    22,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    48,    45,
      33,    34,    35,    36,    37,    28,    48,    38,   139,    27,
      16,    25,    45,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    33,    34,    35,    36,    37,    30,
      21,    21,    21,    38,    45,    45,    28,    50,    26,    26,
      37,    22,    28,    28,    22,    22,    49,    47,    28,    28,
      21,    12,    28,    22,    28,    51,    14,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    75,    32,    55,     0,    28,     8,    59,    55,
      60,    61,    62,    21,    26,    27,    60,    12,    14,    15,
      23,    24,    55,    64,    66,    68,    69,    70,    71,    73,
      74,    61,     4,     5,     6,     7,    17,    63,    30,    31,
      44,    53,    54,    55,    56,    57,    58,    67,    67,    55,
      72,    44,    44,    27,    69,    22,    48,    28,    58,    67,
      48,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    11,    18,    19,    16,    27,    16,    55,    56,
      46,    52,    57,    65,    38,    25,    53,    45,    45,    44,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    21,    67,    67,    21,    38,    21,    45,    45,
      26,    26,    45,    58,    50,    58,    49,    69,    69,    58,
      69,    28,    28,    65,    65,    28,    28,    53,    22,    22,
       9,    22,    49,    13,    28,    28,    58,    28,    47,    21,
      63,    69,    28,    22,    28
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 112 "parser.y"
    {
        (yyval.nPtr) = conStr((yyvsp[(1) - (1)].sval));
}
    break;

  case 3:
#line 116 "parser.y"
    {
        (yyval.nPtr) = conInt((yyvsp[(1) - (1)].ival));
}
    break;

  case 4:
#line 119 "parser.y"
    {
        (yyval.nPtr) = conReal((yyvsp[(1) - (1)].rval));
}
    break;

  case 5:
#line 122 "parser.y"
    {
        (yyval.nPtr) = id((yyvsp[(1) - (1)].sIndex));
}
    break;

  case 6:
#line 126 "parser.y"
    {
        (yyval.nPtr) = opr(_typeArrayIndex, 2, (yyvsp[(1) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
}
    break;

  case 7:
#line 130 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
}
    break;

  case 8:
#line 134 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
        }
    break;

  case 9:
#line 138 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
        }
    break;

  case 10:
#line 142 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
        }
    break;

  case 11:
#line 146 "parser.y"
    {
        (yyval.nPtr) = opr(_typeAdd, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 12:
#line 150 "parser.y"
    {
        (yyval.nPtr) = opr(_typeSub, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
      }
    break;

  case 13:
#line 154 "parser.y"
    {
        (yyval.nPtr) = opr(_typeMul, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
      }
    break;

  case 14:
#line 158 "parser.y"
    {
        (yyval.nPtr) = opr(_typeMod, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
      }
    break;

  case 15:
#line 162 "parser.y"
    {
        (yyval.nPtr) = opr(_typeDiv, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
      }
    break;

  case 16:
#line 166 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);
      }
    break;

  case 17:
#line 170 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
      }
    break;

  case 18:
#line 174 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(2) - (2)].nPtr);
}
    break;

  case 19:
#line 178 "parser.y"
    {
        (yyval.nPtr) = opr(_typeDecls, 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
}
    break;

  case 20:
#line 182 "parser.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 21:
#line 184 "parser.y"
    {
        (yyval.nPtr) = opr(_typeMultId, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 22:
#line 188 "parser.y"
    {
            (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
          }
    break;

  case 23:
#line 192 "parser.y"
    {
    (yyval.nPtr) = opr(_typeDecl, 2, (yyvsp[(1) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
}
    break;

  case 24:
#line 196 "parser.y"
    {
        (yyval.nPtr) = opr(_typeDeclArray, 4, (yyvsp[(1) - (11)].nPtr), (yyvsp[(5) - (11)].nPtr), (yyvsp[(7) - (11)].nPtr), (yyvsp[(10) - (11)].nPtr));
      }
    break;

  case 25:
#line 200 "parser.y"
    {
    (yyval.nPtr) = opr(_typeInt, 0);
}
    break;

  case 26:
#line 204 "parser.y"
    {
    (yyval.nPtr) = opr(_typeChar, 0);
            }
    break;

  case 27:
#line 208 "parser.y"
    {
    (yyval.nPtr) = opr(_typeReal, 0);
            }
    break;

  case 28:
#line 212 "parser.y"
    {
    (yyval.nPtr) = opr(_typeBoolean, 0);
            
            }
    break;

  case 29:
#line 218 "parser.y"
    {
        (yyval.nPtr) = opr(_typeRead, 1, (yyvsp[(3) - (5)].nPtr));
}
    break;

  case 30:
#line 222 "parser.y"
    {
        // printf("func call read\n");
        (yyval.nPtr) = opr(_typeRead, 1, (yyvsp[(3) - (5)].nPtr));
}
    break;

  case 31:
#line 227 "parser.y"
    {
        // printf("func call write\n");
        (yyval.nPtr) = opr(_typeWrite, 1, (yyvsp[(3) - (5)].nPtr));
}
    break;

  case 32:
#line 232 "parser.y"
    {
//     printf("(Stack push) %s\n", $1);
        (yyval.nPtr) = opr(_typeArgs, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 33:
#line 237 "parser.y"
    {
        // printf("(Stack push) %s\n", $1);
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
      }
    break;

  case 34:
#line 242 "parser.y"
    {
        // printf("(Stack push) %s\n", $1);
        (yyval.nPtr) = opr(_typeArgs, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
      }
    break;

  case 35:
#line 247 "parser.y"
    {
        // printf("(Stack push) %s\n", $1);
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
      }
    break;

  case 36:
#line 252 "parser.y"
    {
        // printf("%s = %s\n", $1, $4);
        (yyval.nPtr) = opr(_typeAssign, 2, (yyvsp[(1) - (5)].nPtr), (yyvsp[(4) - (5)].nPtr));
}
    break;

  case 37:
#line 257 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "=", $3);
        (yyval.nPtr) = opr(_typeEE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 38:
#line 263 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "<>", $3);
        (yyval.nPtr) = opr(_typeNE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 39:
#line 269 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "<", $3);
        (yyval.nPtr) = opr(_typeLT, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 40:
#line 275 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "<=", $3);
        (yyval.nPtr) = opr(_typeLE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 41:
#line 281 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, ">", $3);
        (yyval.nPtr) = opr(_typeGT, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 42:
#line 287 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, ">=", $3);
        (yyval.nPtr) = opr(_typeGE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 43:
#line 293 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);
}
    break;

  case 44:
#line 297 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "and", $3);
        (yyval.nPtr) = opr(_typeAnd, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 45:
#line 303 "parser.y"
    {
        // $$ = strdup("t");
        // gencode($$, $1, "or", $3);
        (yyval.nPtr) = opr(_typeOr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
}
    break;

  case 46:
#line 310 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 47:
#line 312 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 48:
#line 314 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 49:
#line 316 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 50:
#line 318 "parser.y"
    {
        (yyval.nPtr) = opr(_typeBody, 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
}
    break;

  case 51:
#line 322 "parser.y"
    {
        (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
}
    break;

  case 52:
#line 326 "parser.y"
    {
        // printf("end if\n");
        (yyval.nPtr) = opr(_typeIf, 2, (yyvsp[(2) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr));
}
    break;

  case 53:
#line 331 "parser.y"
    {
        (yyval.nPtr) = opr(_typeIfElse, 3, (yyvsp[(2) - (11)].nPtr), (yyvsp[(5) - (11)].nPtr), (yyvsp[(9) - (11)].nPtr));
}
    break;

  case 54:
#line 336 "parser.y"
    {
        (yyval.nPtr) = opr(_typeWhile, 2, (yyvsp[(2) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr));
}
    break;

  case 55:
#line 340 "parser.y"
    {
        (yyval.nPtr) = opr(_typeForRange, 3, (yyvsp[(1) - (6)].nPtr), (yyvsp[(4) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr));
}
    break;

  case 56:
#line 344 "parser.y"
    {
        (yyval.nPtr) = opr(_typeFor, 2, (yyvsp[(2) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr));
}
    break;

  case 57:
#line 348 "parser.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 58:
#line 350 "parser.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 59:
#line 352 "parser.y"
    {
        (yyval.nPtr) = opr(_typeProgram, 3, (yyvsp[(2) - (8)].nPtr), (yyvsp[(4) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr));
        generateTAC((yyvsp[(6) - (8)].nPtr), 0);
        // printNode($$);
        decEx((yyvsp[(4) - (8)].nPtr));
        // printf("Decl done\n");
        ex((yyvsp[(6) - (8)].nPtr));
        printSymTable();
}
    break;


/* Line 1267 of yacc.c.  */
#line 2044 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 365 "parser.y"


nodeType *conInt(int value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("Out of memory\n");
        exit(0);
    }
    p->type = _conInt;
    p->conInt.value = value;
    return p;

}
nodeType *conReal(float value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("Out of memory\n");
        exit(0);
    }
    p->type = _conReal;
    p->conReal.value = value;
    return p;

}
nodeType *conStr(char *value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("Out of memory\n");
        exit(0);
    }
    p->type = _conStr;
    p->conStr.value = strdup(value);
    return p;

}

nodeType *conBool(int value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("Out of memory\n");
        exit(0);
    }
    p->type = _conBool;
    p->conInt.value = value;
    return p;

}

nodeType *id(int i) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("Out of memory\n");
        exit(0);
    }
    p->type = _id;
    p->id.i = i;
    return p;
}

nodeType *opr(typeEnum oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("out of memory");   
    }
    if ((p->opr.ops = malloc(nops * sizeof(nodeType))) == NULL) {
        printf("Out of memory\n");
        cust_err("out of memory"); 
    }
    p->type = _opr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for(i = 0; i < nops; i++) {
        p->opr.ops[i] = va_arg(ap, nodeType *);
    }
    va_end(ap);
    return p;
}

char *generateTAC(nodeType *root, int isBool) {
    if (root == NULL) return "";
    if (root->type == _conInt) {
        char *temp = malloc(10);
        sprintf(temp, "%d", root->conInt.value);
        // ++tacLineNo;
        return temp;
    } else if (root->type == _conReal) {
        char *temp = malloc(10);
        sprintf(temp, "%f", root->conReal.value);
        // ++tacLineNo;
        return temp;
    } else if (root->type == _conStr) {
        return strdup(root->conStr.value);
    } else if (root->type == _id) {
        return getName(root->id.i);
    } else if (root->type == _opr) {
        typeEnum oper = root->opr.oper;
        if (oper == _typeAdd) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            char *temp = strdup("t");
            gencode(temp, arg1, "PLUS", arg2);
            ++tacLineNo;
            return temp;
        } else if (oper == _typeSub) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            char *temp = strdup("t");
            gencode(temp, arg1, "MINUS", arg2);
            ++tacLineNo;
            return temp;
        } else if (oper == _typeMul) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            char *temp = strdup("t");
            gencode(temp, arg1, "MUL", arg2);
            ++tacLineNo;
            return temp;
        } else if (oper == _typeDiv) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            char *temp = strdup("t");
            gencode(temp, arg1, "DIV", arg2);
            ++tacLineNo;
            return temp;
        } else if (oper == _typeMod) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            char *temp = strdup("t");
            gencode(temp, arg1, "MOD", arg2);
            ++tacLineNo;
            return temp;
        } else if (oper == _typeAssign) {
            char *arg1 = generateTAC(root->opr.ops[0], isBool);
            char *arg2 = generateTAC(root->opr.ops[1], isBool);
            // char *temp = strdup("t");
            // gencode(temp, arg1, "ASS", arg2);
            fprintf(yyout, "ASS %s %s\n", arg1, arg2);
            ++tacLineNo;
            return "";
        } else if (oper == _typeEE) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " = ");
            strcat(temp, arg2);
            strcat(temp, " )");
            // gencode(temp, arg1, "EQ", arg2);
            return temp;
        } else if (oper == _typeNE) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " <> ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeLT) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " < ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeLE) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " <= ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeGT) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " > ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeGE) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " >= ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeAnd) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " AND ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeOr) {
            char *arg1 = generateTAC(root->opr.ops[0], 1);
            char *arg2 = generateTAC(root->opr.ops[1], 1);
            char *temp = strdup("( ");
            strcat(temp, arg1);
            strcat(temp, " OR ");
            strcat(temp, arg2);
            strcat(temp, " )");
            return temp;
        } else if (oper == _typeIf) {
            fprintf(yyout, "if %s goto %d\n", generateTAC(root->opr.ops[0], 1), tacLineNo + 2);
            ++tacLineNo;
            char *l = strdup("L");
            genlabel(l);
            fprintf(yyout, "goto %s\n", l);
            ++tacLineNo;
            generateTAC(root->opr.ops[1], 0);
            fprintf(yyout, "%s: \n", l);
            ++tacLineNo;
            return "";
        } else if (oper == _typeIfElse) {
            int currLineNo = tacLineNo;
            fprintf(yyout, "if %s goto %d\n", generateTAC(root->opr.ops[0], 1), tacLineNo + 3);
            ++tacLineNo;
            char *t = strdup("t");
            onlyGencode(t);
            fprintf(yyout, "%s = 0\n", t);
            ++tacLineNo;
            fprintf(yyout, "goto %d\n", tacLineNo + 2);
            ++tacLineNo;
            fprintf(yyout, "%s = 1\n", t);
            ++tacLineNo;
            char *l1 = strdup("L");
            genlabel(l1);
            fprintf(yyout, "if %s = 1 goto %s\n", t, l1);
            ++tacLineNo;
            generateTAC(root->opr.ops[2], 0);
            char *l2 = strdup("L");
            genlabel(l2);
            fprintf(yyout, "goto %s\n", l2);
            ++tacLineNo;
            fprintf(yyout, "%s: ", l1);
            generateTAC(root->opr.ops[1], 0);
            fprintf(yyout, "%s: ", l2);
            ++tacLineNo;
            return "";
        } else if (oper == _typeWhile) {
            char *l = strdup("L");
            genlabel(l);
            fprintf(yyout, "%s: if %s goto %d\n", l, generateTAC(root->opr.ops[0], 1), tacLineNo + 3);
            ++tacLineNo;
            char *t1 = strdup("t");
            onlyGencode(t1);
            fprintf(yyout, "%s = 0\n", t1);
            ++tacLineNo;
            fprintf(yyout, "goto %d\n", tacLineNo + 2);
            ++tacLineNo;
            fprintf(yyout, "%s = 1\n", t1);
            ++tacLineNo;
            char *l1 = strdup("L");
            genlabel(l1);
            fprintf(yyout, "if %s = 0 goto %s\n", t1, l1);
            generateTAC(root->opr.ops[1], 0);
            fprintf(yyout, "goto %s\n", l);
            ++tacLineNo;
            fprintf(yyout, "%s: \n", l1);
            return "";
        } else if (oper == _typeFor) {
            char *left = generateTAC(root->opr.ops[0], 0);
            char i[20], en[20];
            sscanf(left, "%s %s", i, en);
            char *l1 = strdup("L");
            genlabel(l1);
            fprintf(yyout, "%s: if %s < %s goto %d\n", l1, i, en, tacLineNo + 3);
            ++tacLineNo;
            char *t0 = strdup("t");
            onlyGencode(t0);
            fprintf(yyout, "%s = 0\n", t0);
            ++tacLineNo;
            fprintf(yyout, "goto %d\n", tacLineNo + 2);
            ++tacLineNo;
            fprintf(yyout, "%s = 1\n", t0);
            ++tacLineNo;
            char *l2 = strdup("L");
            genlabel(l2);
            fprintf(yyout, "if %s = 0 goto %s\n", t0, l2);
            ++tacLineNo;
            generateTAC(root->opr.ops[1], 0);
            fprintf(yyout, "goto %s\n", l1);
            ++tacLineNo;
            fprintf(yyout, "%s: \n", l2);
            return "";
        } else if (oper == _typeForRange) {
            char *i = generateTAC(root->opr.ops[0], 0);
            char *beg = generateTAC(root->opr.ops[1], 0);
            char *en = generateTAC(root->opr.ops[2], 0);
            fprintf(yyout, "%s = %s\n", i, beg);
            ++tacLineNo;
            char temp[20];
            sprintf(temp, "%s %s", i, en);
            return strdup(temp);
        } else if (oper == _typeRead) {
            return "";
            // return strdup(temp);
        } else if (oper == _typeWrite) {
            // char *arg1 = generateTAC(root->opr.ops[0]);
            // char *arg2 = generateTAC(root->opr.ops[1]);
            // char *temp = strdup("t");
            // gencode(temp, arg1, "EQ", arg2);
            return "";
        } else if (oper == _typeBody) {
            char *arg1 = generateTAC(root->opr.ops[0], 0);
            char *arg2 = generateTAC(root->opr.ops[1], 0);
            // char *temp = strdup("t");
            // gencode(temp, arg1, "EQ", arg2);
            return "";
        } else if (oper == _typeArgs) {
            // char *arg1 = generateTAC(root->opr.ops[0]);
            // char *arg2 = generateTAC(root->opr.ops[1]);
            // char *temp = strdup("t");
            // gencode(temp, arg1, "EQ", arg2);
            return "";
        } else if (oper == _typeArrayIndex) {
            char *left = generateTAC(root->opr.ops[0], isBool);
            char *right = generateTAC(root->opr.ops[1], isBool);
            if (isBool) {
                char temp[50];
                sprintf(temp, "%s[%s]", left, right);
                return strdup(temp);
            }
            char *temp = strdup("t");
            gencode(temp, left, "INDEX", right);
            ++tacLineNo;
            return temp;
        } else {
            return "";
        }
    }
}

void printSymTable() {
    printf("\n\n---------- SYMBOL TABLE ----------\n\n");
    for (int i = 0; i < MAX_SYMBOLS; ++i) {
        if (sym_table[i].declared) {
            printf("%s : ", getName(i));
            if (sym_table[i].dt == _dtInt)
                printf("INT %d\n", sym_table[i].intValue);
            else if (sym_table[i].dt == _dtBool)
                printf("BOOL %d\n", sym_table[i].intValue);
            else if (sym_table[i].dt == _dtChar)
                printf("CHAR %c\n", sym_table[i].charValue);
            else if (sym_table[i].dt == _dtReal)
                printf("REAL %f\n", sym_table[i].realValue);
            else if (sym_table[i].dt == _dtIntArr) {
                printf("ARRAY INT ");
                printf("[");
                for (int j = 0; j < sym_table[i].arrSize; ++j) {
                    printf("%d", sym_table[i].intArrValue[j]);
                    if (j != sym_table[i].arrSize - 1)
                        printf(", ");
                }
                printf("]\n");
            } else if (sym_table[i].dt == _dtRealArr) {
                printf("ARRAY REAL ");
                printf("[");
                for (int j = 0; j < sym_table[i].arrSize; ++j) {
                    printf("%f", sym_table[i].intArrValue[j]);
                    if (j != sym_table[i].arrSize - 1)
                        printf(", ");
                }
                printf("]\n");
            } else if (sym_table[i].dt == _dtCharArr) {
                printf("ARRAY CHAR ");
                printf("[");
                for (int j = 0; j < sym_table[i].arrSize; ++j) {
                    printf("%c", sym_table[i].intArrValue[j]);
                    if (j != sym_table[i].arrSize - 1)
                        printf(", ");
                }
                printf("]\n");
            } else if (sym_table[i].dt == _dtBoolArr) {
                printf("ARRAY BOOL ");
                printf("[");
                for (int j = 0; j < sym_table[i].arrSize; ++j) {
                    printf("%d", sym_table[i].intArrValue[j]);
                    if (j != sym_table[i].arrSize - 1)
                        printf(", ");
                }
                printf("]\n");
            } else {
                printf("UNKNOWN\n");
            }
        }
    }
}

void freeNode(nodeType *p) {
    int i;
    if (!p) return;
    if (p->type == _opr) {
        for (i = 0; i < p->opr.nops; i++)
        freeNode(p->opr.ops[i]);
        free(p->opr.ops);
    }
    free (p);
} 

int getArrValue(nodeType *arr, int index) {
    if (arr->type != _id) {
        cust_err("Invalid array index");
        exit(1);
    }
    if (!sym_table[arr->id.i].declared) {
        // printf("%d not declared\n", arr->id.i);
        cust_err("Variable not declared");
        exit(1);
    }
    if (index < 0 || index > sym_table[arr->id.i].arrSize) {
        cust_err("Array index out of bounds");
        exit(1);
    }
    return sym_table[arr->id.i].intArrValue[index - 1];
}

void setArrValue(nodeType *arr, int index, int value) {
    if (arr->type != _id) {
        cust_err("Invalid array index");
        exit(1);
    }
    if (!sym_table[arr->id.i].declared) {
        // printf("%d not declared\n", arr->id.i);
        cust_err("Variable not declared");
        exit(1);
    }
    if (index < 0 || index > sym_table[arr->id.i].arrSize) {
        cust_err("Array index out of bounds");
        exit(1);
    }
    sym_table[arr->id.i].intArrValue[index - 1] = value;
}

void printNode(nodeType *p) {
    if (!p) return;
    fprintf(yyout, "[");
    if (p->type == _conInt) {
        fprintf(yyout, "%d", p->conInt.value);
    }else if (p->type == _conReal) {
        fprintf(yyout, "%f", p->conReal.value);
    } 
    else if (p->type == _conStr) {
        fprintf(yyout, "%s", p->conStr.value);
    } else if (p->type == _id) {
        fprintf(yyout, "%d", p->id.i);
    } else if (p->type == _opr) {
        switch(p->opr.oper) {
            case _typeAdd: fprintf(yyout, "+"); break;
            case _typeSub: fprintf(yyout, "-"); break;
            case _typeMul: fprintf(yyout, "*"); break;
            case _typeDiv: fprintf(yyout, "/"); break;
            case _typeMod: fprintf(yyout, "%%"); break;
            case _typeAssign: fprintf(yyout, "="); break;
            case _typeEE: fprintf(yyout, "=="); break;
            case _typeNE: fprintf(yyout, "!="); break;
            case _typeLT: fprintf(yyout, "<"); break;
            case _typeLE: fprintf(yyout, "<="); break;
            case _typeGT: fprintf(yyout, ">"); break;
            case _typeGE: fprintf(yyout, ">="); break;
            case _typeAnd: fprintf(yyout, "&&"); break;
            case _typeOr: fprintf(yyout, "||"); break;
            case _typeIf: fprintf(yyout, "if"); break;
            case _typeIfElse: fprintf(yyout, "if-else"); break;
            case _typeWhile: fprintf(yyout, "while"); break;
            case _typeFor: fprintf(yyout, "for"); break;
            case _typeForRange: fprintf(yyout, "for-range"); break;
            case _typeRead: fprintf(yyout, "read"); break;
            case _typeWrite: fprintf(yyout, "write"); break;
            case _typeBody: fprintf(yyout, "body"); break;
            case _typeDecls: fprintf(yyout, "decls"); break;
            case _typeDecl: fprintf(yyout, "decl"); break;
            case _typeDeclArray: fprintf(yyout, "decl-array"); break;
            case _typeArgs: fprintf(yyout, "args"); break;
            case _typeMultId: fprintf(yyout, "mult-id"); break;
            case _typeArrayIndex: fprintf(yyout, "array-index"); break;
            case _typeProgram: fprintf(yyout, "program"); break;
        }
        
        for(int i = 0; i < p->opr.nops; i++) {
            printNode(p->opr.ops[i]);
        }
    }
    fprintf(yyout, "]");
}
float getRealValue(nodeType *p){
    if(p->type == _conReal) {
        return p->conReal.value;
    } else if (p->type == _id) {
        if (!sym_table[p->id.i].declared) {
            // printf("%d not declared\n", p->id.i);
            cust_err("Variable not declared");
            exit(1);
        }
        // printf("%d get\n", p->id.i);
        return sym_table[p->id.i].realValue;
    } else if (p->type == _opr && p->opr.oper == _typeArrayIndex) {
        return (float)getArrValue(p->opr.ops[0], getValue(ex(p->opr.ops[1])));
        // if (!sym_table[p->id.i].declared) {
        //     // printf("%d not declared\n", p->id.i);
        //     cust_err("Variable not declared");
        //     exit(1);
        // }
        // // printf("%d get\n", p->id.i);
        // return sym_table[p->id.i].intValue;
    } else {
        // printNode(p);
        // printf("\n");
        cust_err("Invalid expression");
        exit(1);
    }
}
int getValue(nodeType *p) {
    if (p->type == _conInt) {
        return p->conInt.value;
    }
    // else if (p->type == _conReal) {
    //     return p->conReal.value;
    // } 
    else if (p->type == _id) {
        if (!sym_table[p->id.i].declared) {
            // printf("%d not declared\n", p->id.i);
            cust_err("Variable not declared");
            exit(1);
        }
        // printf("%d get\n", p->id.i);
        return sym_table[p->id.i].intValue;
    } else if (p->type == _opr && p->opr.oper == _typeArrayIndex) {
        return getArrValue(p->opr.ops[0], getValue(ex(p->opr.ops[1])));
        // if (!sym_table[p->id.i].declared) {
        //     // printf("%d not declared\n", p->id.i);
        //     cust_err("Variable not declared");
        //     exit(1);
        // }
        // // printf("%d get\n", p->id.i);
        // return sym_table[p->id.i].intValue;
    } else {
        // printNode(p);
        // printf("\n");
        cust_err("Invalid expression");
        exit(1);
    }
}

void setValue(nodeType *p, int value) {
    if (!sym_table[p->id.i].declared) {
        // printf("%d not declared\n", p->id.i);
        cust_err("Variable not declared");
        exit(1);
    }
    if (p->type == _id) {
        // printf("%d set %d\n", p->id.i, value);
        sym_table[p->id.i].intValue = value;
    } else if (p->type == _opr && p->opr.oper == _typeArrayIndex) {
        // printf("%d set %d\n", p->id.i, value);
        // sym_table[p->id.i].intValue = value;
        setArrValue(ex(p->opr.ops[0]), getValue(ex(p->opr.ops[1])), value);
    } else {
        cust_err("Invalid assignment");
        exit(1);
    }
}

void setRealValue(nodeType *p, float value) {
    if (!sym_table[p->id.i].declared) {
        // printf("%d not declared\n", p->id.i);
        cust_err("Variable not declared");
        exit(1);
    }
    if (p->type == _id) {
        // printf("%d set %d\n", p->id.i, value);
        sym_table[p->id.i].realValue = value;
    } else if (p->type == _opr && p->opr.oper == _typeArrayIndex) {
        // printf("%d set %d\n", p->id.i, value);
        // sym_table[p->id.i].intValue = value;
        setArrValue(ex(p->opr.ops[0]), getValue(ex(p->opr.ops[1])), value);
    } else {
        cust_err("Invalid assignment");
        exit(1);
    }
}

dataType getIdType(nodeType *id) {
    if (id->type != _id) {
        cust_err("Not ID");
        exit(1);
    }

    symNode t = sym_table[id->id.i];
    return t.dt;
}


dataType getDt(nodeType *p) {
    if (p == NULL) return _dtEmpty;
    if (p->type == _conReal) return _dtReal;
    if (p->type == _conInt) return _dtInt;
    if (p->type == _id) return getIdType(p);
    if (p->type != _opr) return _dtEmpty;
    if (p->opr.oper == _typeInt) return _dtInt;
    if (p->opr.oper == _typeReal) return _dtReal;
    if (p->opr.oper == _typeChar) return _dtChar;
    if (p->opr.oper == _typeBoolean) return _dtBool;
    if (p->opr.oper == _typeArrayIndex) return getDt(p->opr.ops[0]);
    return _dtEmpty;
}

dataType getArrDt(dataType dt) {
    if (dt == _dtInt) return _dtIntArr;
    if (dt == _dtReal) return _dtRealArr;
    if (dt == _dtChar) return _dtCharArr;
    if (dt == _dtBool) return _dtBoolArr;
    if (dt == _dtIntArr) return _dtIntArr;
    if (dt == _dtRealArr) return _dtRealArr;
    if (dt == _dtCharArr) return _dtCharArr;
    if (dt == _dtBoolArr) return _dtBoolArr;
    return _dtEmpty;
}


int isArrDt(dataType dt) {
    if (dt == _dtIntArr) return 1;
    if (dt == _dtRealArr) return 1;
    if (dt == _dtCharArr) return 1;
    if (dt == _dtBoolArr) return 1;
    return 0;
}

int getArrElemSize(dataType dt) {
    if (dt == _dtIntArr) return sizeof(int);
    if (dt == _dtRealArr) return sizeof(float);
    if (dt == _dtCharArr) return sizeof(char);
    if (dt == _dtBoolArr) return sizeof(int);
    return 0;
}

void declInt(nodeType *root, int v) {
    if (root == NULL) return;
    if (root->type == _id) {
        sym_table[root->id.i].dt = _dtInt;
        sym_table[root->id.i].declared = 1;
        sym_table[root->id.i].intValue = v;
        return;
    }
}

nodeType *dec(nodeType *root, dataType dt, int __sz) {
    if (root == NULL) return NULL;
    if (root->type == _id) {
        // printf("id\n");
        if (sym_table[root->id.i].declared) {
            cust_err("Variable already declared");
            exit(1);
        }
        sym_table[root->id.i].dt = dt;
        sym_table[root->id.i].declared = 1;
        // printf("%d declared\n", root->id.i);
        if (isArrDt(dt)) {
            sym_table[root->id.i].arrSize = __sz;
            if (dt == _dtIntArr || dt == _dtBoolArr)
                sym_table[root->id.i].intArrValue = calloc(__sz, getArrElemSize(dt));
            else if (dt == _dtRealArr)
                sym_table[root->id.i].realArrValue = calloc(__sz, getArrElemSize(dt));
            else if (dt == _dtCharArr)
                sym_table[root->id.i].charArrValue = calloc(__sz, getArrElemSize(dt));
        } else {
            sym_table[root->id.i].intValue = 0;
        }
        return NULL;
    }
    if (root->opr.oper == _typeDecls) {
        // printf("decls\n");
        dec(root->opr.ops[0], dt, __sz);
        dec(root->opr.ops[1], dt, __sz);
        return NULL;
    }
    if (root->opr.oper == _typeDecl) {
        // printf("decl\n");
        nodeType *l = dec(root->opr.ops[1], dt, __sz);
        dec(root->opr.ops[0], getDt(l), 0);
        return NULL;
    }
    if (root->opr.oper == _typeDeclArray) {
        nodeType *l = dec(root->opr.ops[3], dt, __sz);
        int beg = getValue(root->opr.ops[1]);
        int en = getValue(root->opr.ops[2]);
        // printf("Decl array %d %d\n", beg, en);
        dec(root->opr.ops[0], getArrDt(getDt(l)), en - beg + 1);
        return NULL;
    }
    if (root->opr.oper == _typeMultId) {
        dec(root->opr.ops[0], dt, __sz);
        dec(root->opr.ops[1], dt, __sz);
        return NULL;
    }
    if (root->opr.oper == _typeInt) {
        return root;
    }
    if (root->opr.oper == _typeChar) {
        return root;
    }
    if (root->opr.oper == _typeReal) {
        return root;
    }
    if (root->opr.oper == _typeBoolean) {
        return root;
    }
    return NULL;
}

void decEx(nodeType *root) {
    dec(root, _dtEmpty, 0);
}



nodeType* ex(nodeType *root) {
    // printf("printNode\n");
    if (root == NULL) return NULL;
    if (root->type ==  _conInt)
        return root;
    else if (root->type ==  _conReal)
        return root;
    else if (root->type ==  _conStr)
        return root;
    else if (root->type ==  _id){
         int id_index = root->id.i;
        if (!sym_table[id_index].declared) {
            printf("Error: Undeclared variable %s\n", getName(id_index));
            exit(1);
        }
        return root;
    }
        
    else if (root->type ==  _opr) {
    // printf("{");
    typeEnum oper = root->opr.oper;
        if (oper == _typeInt) return root;
        if (oper == _typeReal) return root;
        if (oper == _typeChar) return root;
        if (oper == _typeAdd) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            if (left == NULL) printf("lnull\n");
            if (right == NULL) printf("rnull\n");
              dataType leftType = getArrDt(getDt(left));
            dataType rightType = getArrDt(getDt(right));
            // printf("rt = %d\n", rightType);
            //  printf("DT = %d %d\n", leftType, rightType);
             if (leftType == _dtIntArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = (float)getValue(left) + getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtIntArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                int result = getValue(left) + getValue(right);
                // printf("%0.2f",result);
                return conInt(result);
             } else if (leftType == _dtRealArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) + (float)getValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtRealArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) + getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else {
                printf("ERRRRRRRR\n");
                // printf("%d\n", right->opr.oper);
                printf("%d %d\n", getValue(left), getValue(right));
                return conInt(getValue(left) + getValue(right));
             }
        }
        if (oper == _typeSub) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            if (left == NULL) printf("lnull\n");
            if (right == NULL) printf("rnull\n");
              dataType leftType = getArrDt(getDt(left));
             dataType rightType = getArrDt(getDt(right));
            //  printf("DT = %d %d\n", leftType, rightType);
             if (leftType == _dtIntArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = (float)getValue(left) - getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtIntArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                int result = getValue(left) - getValue(right);
                // printf("%0.2f",result);
                return conInt(result);
             } else if (leftType == _dtRealArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) - (float)getValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtRealArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) - getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else {
                printf("ERRRRRRRR\n");
                return conInt(getValue(left) - getValue(right));
             }
        }
        if (oper == _typeMul) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            if (left == NULL) printf("lnull\n");
            if (right == NULL) printf("rnull\n");
              dataType leftType = getArrDt(getDt(left));
             dataType rightType = getArrDt(getDt(right));
            //  printf("DT = %d %d\n", leftType, rightType);
             if (leftType == _dtIntArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = (float)getValue(left) * getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtIntArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                int result = getValue(left) * getValue(right);
                // printf("%0.2f",result);
                return conInt(result);
             } else if (leftType == _dtRealArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) * (float)getValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtRealArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) * getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else {
                printf("ERRRRRRRR\n");
                return conInt(getValue(left) - getValue(right));
             }
        }
        if (oper == _typeDiv) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            if (left == NULL) printf("lnull\n");
            if (right == NULL) printf("rnull\n");
              dataType leftType = getArrDt(getDt(left));
             dataType rightType = getArrDt(getDt(right));
            //  printf("DT = %d %d\n", leftType, rightType);
             if (leftType == _dtIntArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = (float)getValue(left) / getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtIntArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                float result = (float)getValue(left) / (float)getValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtRealArr && rightType == _dtIntArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) / (float)getValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else if (leftType == _dtRealArr && rightType == _dtRealArr) {
            // // Convert integer to float and perform addition
                float result = getRealValue(left) / getRealValue(right);
                // printf("%0.2f",result);
                return conReal(result);
             } else {
                printf("ERRRRRRRR\n");
                return conReal((float)getValue(left) / (float)getValue(right));
             }
        }
        if (oper == _typeMod) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
                dataType leftType = getArrDt(getDt(left));
             dataType rightType = getArrDt(getDt(right));
             if(leftType != _dtIntArr || rightType != _dtIntArr) {
                cust_err("Invalid data types for modulo operation");
                exit(1);
             }
            return conInt(getValue(left) % getValue(right));
        }
        if (oper == _typeAssign) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            // sym_table[left->id.i] = getValue(right);
            // printf("ASSIGN\n");
            if (getDt(left) != getDt(right) && getArrDt(getDt(left)) != getArrDt(getDt(right))) {
                cust_err("Invalid data types for assignment\n");
                exit(1);
            }
            if (right->type == _conInt || getDt(right) == _dtIntArr) {
                // printf("right = %i\n", getValue(right));
                setValue(left, getValue(right));
            }
            else if (right->type == _conReal|| getDt(right) == _dtRealArr)
                setRealValue(left, getRealValue(right));
            else {

                cust_err("Assignment Error");
                exit(1);
            }
            return NULL;
        }
        if (oper == _typeEE) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) == getValue(right));
        }
        if (oper == _typeNE) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) != getValue(right));
        }
        if (oper == _typeLT) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) < getValue(right));
        }
        if (oper == _typeLE) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) <= getValue(right));
        }
        if (oper == _typeGT) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            // printf("%d %d", getValue(left), getValue(right));
            return conBool(getValue(left) > getValue(right));
        }
        if (oper == _typeGE) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) >= getValue(right));
        }
        if (oper == _typeAnd) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) && getValue(right));
        }
        if (oper == _typeOr) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conBool(getValue(left) || getValue(right));
        }
        if (oper == _typeIf) {
            nodeType *left = ex(root->opr.ops[0]);
            if (left->conBool.value) {
                ex(root->opr.ops[1]);
            }
            return NULL;
        }
        if (oper == _typeIfElse) {
            nodeType *left = ex(root->opr.ops[0]);
            if (left->conBool.value) {
                ex(root->opr.ops[1]);
            } else {
                ex(root->opr.ops[2]);
            }
            return NULL;
        }
        if (oper == _typeWhile) {
            nodeType *left = ex(root->opr.ops[0]);
            while (left->conBool.value) {
                // printf("while\n");
                // printf("while\n");
                ex(root->opr.ops[1]);
                left = ex(root->opr.ops[0]);
            }
            return NULL;
        }
        if (oper == _typeFor) {
            nodeType *left = ex(root->opr.ops[0]);
            int beg = getValue(left->opr.ops[1]);
            int en = getValue(left->opr.ops[2]);
            nodeType *forIden = left->opr.ops[0];
            declInt(forIden, beg);
            // printf("for %d %d\n", beg, en);
            for (int __i = beg; __i <= en; ++__i) {
                // printf("for\n");
                // sym_table[left->opr.ops[0]->id.i] = __i;
                setValue(left->opr.ops[0], __i);
                ex(root->opr.ops[1]);
            }
            // printNode(root->opr.ops[1]);
            return NULL;
        }
        if (oper == _typeForRange) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *beg = ex(root->opr.ops[1]);
            nodeType *en = ex(root->opr.ops[2]);
            return opr(_typeForRange, 3, left, beg, en);
        }
        if (oper == _typeRead) {
            // printf("read ");
            // printf("read\n");
            // printNode(root);
            // printf("\n");
            if (root->opr.ops[0]->type == _id) {
                nodeType *left = ex(root->opr.ops[0]);
                int __i;
                scanf(" %d", &__i);
                // sym_table[root->opr.ops[0]->id.i] = __i;
                setValue(left, __i);
            } else if (root->opr.ops[0]->opr.oper == _typeArrayIndex) {
                nodeType *arr = ex(root->opr.ops[0]);
                nodeType *arrId = ex(arr->opr.ops[0]);
                nodeType *index = ex(arr->opr.ops[1]);
                int __i;
                scanf(" %d", &__i);
                setArrValue(arrId, getValue(index), __i);
            } else {
                printf("Unknown read : ");
                printNode(root->opr.ops[0]);
            }
            return NULL;
        }
        if (oper == _typeWrite) {
            // printf("write ");
            nodeType *left = ex(root->opr.ops[0]);
            while (left) {
                if (left->type == _conInt) {
                    printf("%d ", left->conInt.value);
                    break;
                } else if (left->type == _conStr) {
                    printf("%s ", left->conStr.value);
                    break;
                } else if (left->type == _conReal) {
                    printf("%f ", left->conReal.value);
                    break;
                } else if (left->type == _id) {
                    dataType id_dt = getIdType(left);
                    if (id_dt == _dtReal)
                        printf("%f ", getRealValue(left));
                    else if (id_dt == _dtInt) {
                        printf("%d ", getValue(left));
                    } else {
                        cust_err("ID of unknown type\n");
                        exit(1);
                    }
                    break;
                } else {
                    if (left->opr.oper == _typeArgs) {
                        nodeType *right = ex(left->opr.ops[0]);
                        if (right->type == _conInt) {
                            printf("%d ", right->conInt.value);
                        } else if (right->type == _conReal) {
                            printf("%s ", right->conReal.value);
                        } else if (right->type == _conStr) {
                            printf("%s ", right->conStr.value);
                        } else if (right->type == _id) {
                            dataType id_dt = getIdType(right);
                            if (id_dt == _dtReal)
                                printf("%f ", getRealValue(right));
                            else if (id_dt == _dtInt) {
                                printf("%d ", getValue(right));
                            } else {
                                cust_err("ID of unknown type\n");
                                exit(1);
                            }
                        } else {
                            printf("Invalid write statement");
                            cust_err("Invalid write statement");
                            exit(1);
                        }
                        left = ex(left->opr.ops[1]);
                    } else if (left->opr.oper == _typeArrayIndex) {
                        nodeType *arrId = ex(left->opr.ops[0]);
                        nodeType *index = ex(left->opr.ops[1]);
                        printf("%d ", getArrValue(arrId, getValue(index)));
                        break;
                    } else {
                        break;
                    }
                }
            }
            return NULL;
        }
        if (oper == _typeBody) {
            ex(root->opr.ops[0]);
            ex(root->opr.ops[1]);
            return NULL;
        }
        // if (oper == _typeDecls) {
        //     // ex(root->opr.ops[0]);
        //     // ex(root->opr.ops[1]);
        //     return NULL;
        // }
        // if (oper == _typeDecl) {
        //     ex(root->opr.ops[0]);
        //     ex(root->opr.ops[1]);
        //     return NULL;
        // }
        // if (oper == _typeDeclArray) {
        //     // printNode(root->opr.ops[0]);
        //     // printf(" : array [");
        //     // printNode(root->opr.ops[1]);
        //     // printf("..");
        //     // printNode(root->opr.ops[2]);
        //     // printf("] of ");
        //     // printNode(root->opr.ops[3]);
        //     return NULL;
        // }
        if (oper == _typeArgs) {
            // nodeType *left = ex(root->opr.ops[0]);
            // nodeType *right = ex(root->opr.ops[1]);
            // return opr(_typeArgs, 2, left, right);
            return root;
        }
        if (oper == _typeMultId) {
            ex(root->opr.ops[0]);
            // printf(", ");
            ex(root->opr.ops[1]);
            return NULL;
        }
        if (oper == _typeArrayIndex) {
            return root;
        }
        if (oper == _typeProgram) {
            // printf("program ");
            nodeType *tid = ex(root->opr.ops[0]);
            // printf(";\n");
            ex(root->opr.ops[1]);
            ex(root->opr.ops[2]);
            // printf("end.\n");
            return NULL;
        // printf("}");
        }
        return NULL;
    }
}

void initSymTable() {
    for (int i = 0; i < MAX_SYMBOLS; ++i) {
        sym_table[i].declared = 0;
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    initSymTable();

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    yyout = fopen("output.txt", "w");
    if(yyout == NULL) {
            printf("Error opening file output.txt\n");
            return 1;
    }
    
    yyparse();
    return 0;
}

void cust_err(const char *s) {
    fprintf(stderr, "cust_err : %s\n", s);
}

void yyerror(const char *s) {
    fprintf(stderr, "cust_err : %s\n", s);
}

int yywrap() {
//   printf("valid input\n");
  return 1;
}
