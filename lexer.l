%{
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sym.h"
#include "y.tab.h"

int line_number = 0;
int fake=0;
// char pr[] = "Line Number      Lexeme             Token Type\n";
// printf(stdout, "%s", pr);

// void printToken(char *lexeme, char *token_type) {
//   printf("%d      %s          %s\n", line_number, lexeme, token_type);
// }

// int sym_hash(char *str)
// {
//     int hash = 5381;
//     int c;

//     while (c = *str++)
//         hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

//     return hash % MAX_SYMBOLS;
// }

%}

%option caseless

%%

"program" { return KEY_PROGRAM;}
"integer" { return KEY_INTEGER;}
"real" { return KEY_REAL;}
"boolean" { return KEY_BOOLEAN;}
"char" { return KEY_CHAR;}
"var" { return KEY_VAR;}
"to" { return KEY_TO;}
"of" { return KEY_OF;}
"downto" { return KEY_DOWNTO;}
"if" { return KEY_IF;}
"then" { return KEY_THEN;}
"else" { return KEY_ELSE;}
"while" { return KEY_WHILE;}
"for" { return KEY_FOR;}
"do" { return KEY_DO;}
"array" { return KEY_ARRAY;}
"and" { return KEY_AND;}
"or" { return KEY_OR;}
"not" { return KEY_NOT;}
"begin" { return KEY_BEGIN;}
"end" { return KEY_END;}
"read" { return KEY_READ;}
"write" { return KEY_WRITE;}
[0-9]+ {
  yylval.ival = atoi(yytext);
  return INT;
}
[0-9]+\.[0-9]+ {
  yylval.rval = atof(yytext);
  return REAL;
}
\"[^\"]*\" {
  yylval.sval = strdup(yytext + 1); // +1 and -1 to strip quotes
  yylval.sval[strlen(yylval.sval) - 1] = 0;
  return STR;
}
[a-zA-Z][a-zA-Z0-9_]* {
  yylval.sIndex = sym_hash(yytext);
  setName(yylval.sIndex, yytext);
  return ID;
}
"+" { return OPR_PLUS;}
"-" { return OPR_MINUS;}
"/" { return OPR_DIV;}
"*" { return OPR_MUL;}
"%" { return OPR_MOD;}

"(" { return LPAREN;}
")" { return RPAREN;}

"[" { return LBRACKET;}
"]" { return RBRACKET;}

"=" { return EQ;}
"<" { return LT;}
">" { return GT;}
"<>" { return NE;}
"<=" { return LE;}
">=" { return GE;}

"\.\." { return TDOT;}
"\." { return DOT;}
"," { return COMMA;}
":" { return COLON;}
";" { return SEMICOLON;}
\n {++line_number;}
[ \t]+       ;
%%