/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 157 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

