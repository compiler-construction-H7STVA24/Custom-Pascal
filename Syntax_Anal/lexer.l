%{
#include "y.tab.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int line_number = 0;
int fake=0;
// char pr[] = "Line Number      Lexeme             Token Type\n";
// printf(stdout, "%s", pr);

// void printToken(char *lexeme, char *token_type) {
//   printf("%d      %s          %s\n", line_number, lexeme, token_type);
// }

#define printToken(x, y) fake++;
%}

%option caseless

%%

"program" {printToken(yytext, "KEY_PROGRAM"); return KEY_PROGRAM;}
"integer" {printToken(yytext, "KEY_INTEGER"); return KEY_INTEGER;}
"real" {printToken(yytext, "KEY_REAL"); return KEY_REAL;}
"boolean" {printToken(yytext, "KEY_BOOLEAN"); return KEY_BOOLEAN;}
"char" {printToken(yytext, "KEY_CHAR"); return KEY_CHAR;}
"var" {printToken(yytext, "KEY_VAR"); return KEY_VAR;}
"to" {printToken(yytext, "KEY_TO"); return KEY_TO;}
"of" {printToken(yytext, "KEY_OF"); return KEY_OF;}
"downto" {printToken(yytext, "KEY_DOWNTO"); return KEY_DOWNTO;}
"if" {printToken(yytext, "KEY_IF"); return KEY_IF;}
"then" {printToken(yytext, "KEY_THEN"); return KEY_THEN;}
"else" {printToken(yytext, "KEY_ELSE"); return KEY_ELSE;}
"while" {printToken(yytext, "KEY_WHILE"); return KEY_WHILE;}
"for" {printToken(yytext, "KEY_FOR"); return KEY_FOR;}
"do" {printToken(yytext, "KEY_DO"); return KEY_DO;}
"array" {printToken(yytext, "KEY_ARRAY"); return KEY_ARRAY;}
"and" {printToken(yytext, "KEY_AND"); return KEY_AND;}
"or" {printToken(yytext, "KEY_OR"); return KEY_OR;}
"not" {printToken(yytext, "KEY_NOT"); return KEY_NOT;}
"begin" {printToken(yytext, "KEY_BEGIN"); return KEY_BEGIN;}
"end" {printToken(yytext, "KEY_END"); return KEY_END;}
"read" {printToken(yytext, "KEY_READ"); return KEY_READ;}
"write" {printToken(yytext, "KEY_WRITE"); return KEY_WRITE;}
[0-9]+ {
  printToken(yytext, "INT");
  yylval.ival = atoi(yytext);
  return INT;
}
\"[^\"]*\" {
  printToken(yytext, "STR");
  yylval.sval = strdup(yytext + 1); // +1 and -1 to strip quotes
  yylval.sval[strlen(yylval.sval) - 1] = 0;
  return STR;
}
[a-zA-Z][a-zA-Z0-9_]* {
  printToken(yytext, "ID");
  yylval.sval = strdup(yytext);
  return ID;
}
"+" {printToken(yytext, "OPR_PLUS"); return OPR_PLUS;}
"-" {printToken(yytext, "OPR_MINUS"); return OPR_MINUS;}
"/" {printToken(yytext, "OPR_DIV"); return OPR_DIV;}
"*" {printToken(yytext, "OPR_MUL"); return OPR_MUL;}
"%" {printToken(yytext, "OPR_MOD"); return OPR_MOD;}

"(" {printToken(yytext, "LPAREN"); return LPAREN;}
")" {printToken(yytext, "RPAREN"); return RPAREN;}

"[" {printToken(yytext, "LBRACKET"); return LBRACKET;}
"]" {printToken(yytext, "RBRACKET"); return RBRACKET;}

"=" {printToken(yytext, "EQ"); return EQ;}
"<" {printToken(yytext, "LT"); return LT;}
">" {printToken(yytext, "GT"); return GT;}
"<>" {printToken(yytext, "NE"); return NE;}
"<=" {printToken(yytext, "LE"); return LE;}
">=" {printToken(yytext, "GE"); return GE;}

"\.\." {printToken(yytext, "TDOT"); return TDOT;}
"\." {printToken(yytext, "DOT"); return DOT;}
"," {printToken(yytext, "COMMA"); return COMMA;}
":" {printToken(yytext, "COLON"); return COLON;}
";" {printToken(yytext, "SEMICOLON"); return SEMICOLON;}
\n {++line_number;}
[ \t]+       ;
%%