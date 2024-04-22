%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"
extern int yylex();
extern int yyparse();
extern void yyerror(const char *s);
extern FILE* yyin;

HashMap symbol_table[10000];
HashMap temp_store[10000];

%}

%union {
  int ival; 
  char *sval;
}

%token KEY_PROGRAM KEY_INTEGER KEY_REAL KEY_BOOLEAN KEY_CHAR KEY_VAR KEY_TO KEY_DOWNTO KEY_THEN
%token KEY_IF KEY_ELSE KEY_WHILE KEY_FOR KEY_DO KEY_ARRAY KEY_AND KEY_OR KEY_NOT KEY_BEGIN 
%token KEY_END KEY_READ KEY_WRITE DOT COMMA COLON SEMICOLON NEWLINE INT ID OPR_PLUS OPR_MINUS 
%token OPR_DIV OPR_MUL OPR_MOD EQ LT GT NE LE GE LPAREN RPAREN STR KEY_OF LBRACKET RBRACKET TDOT

%left OPR_PLUS OPR_MINUS
%left OPR_MUL OPR_DIV
%left OPR_MOD
%left KEY_AND KEY_OR

%type <ival> int_val atom expr bool_expr data_type identifier array_index
%type <sval> args str_val

%start program

%%

int_val : INT {$$ = $<ival>1;}

identifier : ID {
  if (hash_find(symbol_table, $<sval>1)) {
    $$ = hash_get(symbol_table, $<sval>1, 0);
  } else {
    hash_set(temp_store, $<sval>1, 0);
    $$ = 0;
  }
}

str_val : STR {$$ = $<sval>1;}

array_index : identifier LBRACKET atom RBRACKET

atom : int_val {$$ = $1;} 
        |
        array_index
        |
        identifier {$$ = $1;}

expr : expr OPR_PLUS expr {$$ = $1 + $3;}
      |
      expr OPR_MINUS expr {$$ = $1 - $3;}
      |
      expr OPR_MUL expr {$$ = $1 * $3;}
      |
      expr OPR_MOD expr {$$ = $1 % $3;}
      |
      expr OPR_DIV expr {$$ = $1 / $3;}
      |
      atom {$$ = $1;}

decl_top : KEY_VAR decls

decls : decl decls
        |
        decl

mult_id : identifier COMMA mult_id
          |
          identifier

decl : mult_id COLON data_type SEMICOLON
        |
      mult_id COLON KEY_ARRAY LBRACKET INT TDOT INT RBRACKET KEY_OF data_type SEMICOLON

data_type : KEY_INTEGER {$$ = KEY_INTEGER;}
            |
            KEY_CHAR {$$ = KEY_CHAR;}
            |
            KEY_REAL {$$ = KEY_REAL;}
            |
            KEY_BOOLEAN {$$ = KEY_BOOLEAN;}


read_write : KEY_READ LPAREN identifier RPAREN SEMICOLON
            |
            KEY_READ LPAREN array_index RPAREN SEMICOLON
            |
            KEY_WRITE LPAREN args RPAREN SEMICOLON

args : atom COMMA args {
            $$ = malloc(strlen($3) + 200 + 2);
            sprintf($$, "%d, %s", $1, $3);
            }
      |
      atom {$$ = malloc(200); sprintf($$, "%d", $1);}
      |
      str_val COMMA args {strcpy($$, $1); strcat($$, " "); strcat($$, $1);}
      |
      str_val {strcpy($$, $1);} 

assignment : identifier COLON EQ expr SEMICOLON

bool_expr : expr EQ expr {$$ = $1 == $3;}
            |
            expr NE expr {$$ = $1 != $3;}
            |
            expr LT expr {$$ = $1 < $3;}
            |
            expr LE expr {$$ = $1 <= $3;}
            |
            expr GT expr {$$ = $1 > $3;}
            |
            expr GE expr {$$ = $1 >= $3;}
            |
            LPAREN bool_expr RPAREN {$$ = $2;}
            |
            bool_expr KEY_AND bool_expr {$$ = ($1 && $3);}
            |
            bool_expr KEY_OR bool_expr {$$ = ($1 || $3);}


statement : assignment
            |
            read_write
            |
            conditional
            |
            loop

body : statement body
        |
        statement

conditional : KEY_IF bool_expr KEY_THEN KEY_BEGIN body KEY_END SEMICOLON
              |
              KEY_IF bool_expr KEY_THEN KEY_BEGIN body KEY_END KEY_ELSE KEY_BEGIN body KEY_END SEMICOLON


while_loop : KEY_WHILE bool_expr KEY_DO KEY_BEGIN body KEY_END SEMICOLON

for_loop : KEY_FOR identifier COLON EQ expr KEY_TO expr KEY_DO KEY_BEGIN body KEY_END SEMICOLON

loop : for_loop
        |
        while_loop

program : KEY_PROGRAM identifier SEMICOLON decl_top KEY_BEGIN body KEY_END DOT
%%

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int yywrap() {
  printf("Valid Input.\n");
  return 1;
}