%{
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int line_number = 0;

#define printToken(x, y) printf("%d      %s                               %s\n", line_number + 1, x, y);
%}

%option caseless

%%

"program" {printToken(yytext, "KEY_PROGRAM");}
"integer" {printToken(yytext, "KEY_INTEGER");}
"real" {printToken(yytext, "KEY_REAL");}
"boolean" {printToken(yytext, "KEY_BOOLEAN");}
"char" {printToken(yytext, "KEY_CHAR");}
"var" {printToken(yytext, "KEY_VAR");}
"to" {printToken(yytext, "KEY_TO");}
"of" {printToken(yytext, "KEY_OF"); }
"downto" {printToken(yytext, "KEY_DOWNTO"); }
"if" {printToken(yytext, "KEY_IF"); }
"then" {printToken(yytext, "KEY_THEN"); }
"else" {printToken(yytext, "KEY_ELSE"); }
"while" {printToken(yytext, "KEY_WHILE"); }
"for" {printToken(yytext, "KEY_FOR"); }
"do" {printToken(yytext, "KEY_DO"); }
"array" {printToken(yytext, "KEY_ARRAY"); }
"and" {printToken(yytext, "KEY_AND"); }
"or" {printToken(yytext, "KEY_OR"); }
"not" {printToken(yytext, "KEY_NOT"); }
"begin" {printToken(yytext, "KEY_BEGIN"); }
"end" {printToken(yytext, "KEY_END"); }
"read" {printToken(yytext, "KEY_READ"); }
"write" {printToken(yytext, "KEY_WRITE"); }
[0-9]+ {
  printToken(yytext, "INT");
}
\"[^\"]*\" {
  printToken(yytext, "STR");
}
[a-zA-Z][a-zA-Z0-9_]* {
  printToken(yytext, "ID");
}
"+" {printToken(yytext, "OPR_PLUS"); }
"-" {printToken(yytext, "OPR_MINUS"); }
"/" {printToken(yytext, "OPR_DIV"); }
"*" {printToken(yytext, "OPR_MUL"); }
"%" {printToken(yytext, "OPR_MOD"); }

"(" {printToken(yytext, "LPAREN"); }
")" {printToken(yytext, "RPAREN"); }

"[" {printToken(yytext, "LBRACKET"); }
"]" {printToken(yytext, "RBRACKET"); }

"=" {printToken(yytext, "EQ"); }
"<" {printToken(yytext, "LT"); }
">" {printToken(yytext, "GT"); }
"<>" {printToken(yytext, "NE"); }
"<=" {printToken(yytext, "LE"); }
">=" {printToken(yytext, "GE"); }

"\.\." {printToken(yytext, "TDOT"); }
"\." {printToken(yytext, "DOT"); }
"," {printToken(yytext, "COMMA"); }
":" {printToken(yytext, "COLON"); }
";" {printToken(yytext, "SEMICOLON"); }
\n {++line_number;}
[ \t]+       ;
%%

int main(int argc, char* argv[]) {
    extern FILE* yyin;
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    // printf("yyin: %p\n", yyin);
    yylex();
    return 0;
}