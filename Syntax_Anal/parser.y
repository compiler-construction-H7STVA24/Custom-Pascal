%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern void yyerror(const char *s);
extern FILE* yyin;

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

// %type <ival> int_val atom expr bool_expr data_type identifier array_index
// %type <sval> args str_val

%start program

%%

int_val : INT

identifier : ID

str_val : STR

array_index : identifier LBRACKET atom RBRACKET

atom : int_val
        |
        array_index
        |
        identifier

expr : expr OPR_PLUS expr 
      |
      expr OPR_MINUS expr 
      |
      expr OPR_MUL expr 
      |
      expr OPR_MOD expr 
      |
      expr OPR_DIV expr 
      |
      LPAREN expr RPAREN
      |
      atom

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

data_type : KEY_INTEGER
            |
            KEY_CHAR
            |
            KEY_REAL
            |
            KEY_BOOLEAN


read_write : KEY_READ LPAREN identifier RPAREN SEMICOLON
            |
            KEY_READ LPAREN array_index RPAREN SEMICOLON
            |
            KEY_WRITE LPAREN args RPAREN SEMICOLON

args : atom COMMA args
      |
      atom
      |
      str_val COMMA args
      |
      str_val

assignment : identifier COLON EQ expr SEMICOLON

bool_expr : expr EQ expr
            |
            expr NE expr
            |
            expr LT expr 
            |
            expr LE expr
            |
            expr GT expr
            |
            expr GE expr
            |
            LPAREN bool_expr RPAREN
            |
            bool_expr KEY_AND bool_expr
            |
            bool_expr KEY_OR bool_expr


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
  printf("valid input\n");
  return 1;
}