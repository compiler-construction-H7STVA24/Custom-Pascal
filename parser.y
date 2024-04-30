%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "sym.h"

extern int yylex();
extern int yyparse();
extern void yyerror(const char *s);
extern FILE* yyin;
extern FILE* yyout;

int k = 1;
int f = 1;
int w = 1;

void gencode(char *word, char *first, char *op, char *second) {
        char temp[10];
        sprintf(temp, "%d", k++);
        strcat(word, temp);
        fprintf(yyout, "%s = %s %s %s\n", word, first, op, second);
}

unsigned long sym_hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        hash = hash % MAX_SYMBOLS;

    return hash;
}

nodeType *opr(typeEnum oper, int nops, ...);
nodeType *id(int i);
nodeType *conInt(int value);
nodeType *conStr(char *value);

void freeNode(nodeType *p);

void printNode(nodeType *root);

%}

%union {
  char *sval;
  int ival;
  int sIndex;
  nodeType *nPtr;
}

%token KEY_PROGRAM KEY_INTEGER KEY_REAL KEY_BOOLEAN KEY_CHAR KEY_VAR KEY_TO KEY_DOWNTO KEY_THEN
%token KEY_IF KEY_ELSE KEY_WHILE KEY_FOR KEY_DO KEY_ARRAY KEY_AND KEY_OR KEY_NOT KEY_BEGIN 
%token KEY_END KEY_READ KEY_WRITE DOT COMMA COLON SEMICOLON NEWLINE INT ID OPR_PLUS OPR_MINUS 
%token OPR_DIV OPR_MUL OPR_MOD EQ LT GT NE LE GE LPAREN RPAREN STR KEY_OF LBRACKET RBRACKET TDOT

%left OPR_PLUS OPR_MINUS
%left OPR_MUL OPR_DIV
%left OPR_MOD
%left KEY_AND KEY_OR

%type <ival> INT
%type <sval> STR
%type <sIndex> ID
%type <nPtr> int_val str_val identifier array_index atom expr decl_top
%type <nPtr> decls mult_id decl data_type read_write args assignment bool_expr 
%type <nPtr> statement body conditional while_loop for_range for_loop loop program

%start program

%%

str_val : STR {
        $$ = conStr($1);
}

int_val : INT {
        $$ = conInt($1);
}

identifier : ID {
        $$ = id($1);
}

array_index : identifier LBRACKET expr RBRACKET {
        $$ = opr(_typeArrayIndex, 2, $1, $3);
}

atom : int_val {
        $$ = $1;
}
        |
        array_index {
        $$ = $1;
        }
        |
        identifier {
        $$ = $1;
        }

expr : expr OPR_PLUS expr {
        $$ = opr(_typeAdd, 2, $1, $3);
}
      |
      expr OPR_MINUS expr {
        $$ = opr(_typeSub, 2, $1, $3);
      }
      |
      expr OPR_MUL expr {
        $$ = opr(_typeMul, 2, $1, $3);
      }
      |
      expr OPR_MOD expr {
        $$ = opr(_typeMod, 2, $1, $3);
      }
      |
      expr OPR_DIV expr {
        $$ = opr(_typeDiv, 2, $1, $3);
      }
      |
      LPAREN expr RPAREN {
        $$ = $2;
      }
      |
      atom {
        $$ = $1;
      }

decl_top : KEY_VAR decls {
        $$ = $2;
}

decls : decl decls {
        $$ = opr(_typeDecls, 2, $1, $2);
}
        |
        decl {$$ = $1;}

mult_id : identifier COMMA mult_id {
        $$ = opr(_typeMultId, 2, $1, $3);
}
          |
          identifier {
            $$ = $1;
          }

decl : mult_id COLON data_type SEMICOLON {
    $$ = opr(_typeDecl, 2, $1, $3);
}
        |
      mult_id COLON KEY_ARRAY LBRACKET int_val TDOT int_val RBRACKET KEY_OF data_type SEMICOLON {
        $$ = opr(_typeDeclArray, 4, $1, $5, $7, $10);
      }

data_type : KEY_INTEGER {
    $$ = opr(_typeInt, 0);
}
            |
            KEY_CHAR {
    $$ = opr(_typeChar, 0);
            }
            |
            KEY_REAL {
    $$ = opr(_typeReal, 0);
            }
            |
            KEY_BOOLEAN {
    $$ = opr(_typeBoolean, 0);
            
            }


read_write : KEY_READ LPAREN identifier RPAREN SEMICOLON {
        $$ = opr(_typeRead, 1, $3);
}
            |
            KEY_READ LPAREN array_index RPAREN SEMICOLON {
        // fprintf(yyout, "func call read\n");
        $$ = opr(_typeRead, 1, $3);
}
            |
            KEY_WRITE LPAREN args RPAREN SEMICOLON {
        // fprintf(yyout, "func call write\n");
        $$ = opr(_typeWrite, 1, $3);
}

args : atom COMMA args {
//     fprintf(yyout, "(Stack push) %s\n", $1);
        $$ = opr(_typeArgs, 2, $1, $3);
}
      |
      atom {
        // fprintf(yyout, "(Stack push) %s\n", $1);
        $$ = $1;
      }
      |
      str_val COMMA args {
        // fprintf(yyout, "(Stack push) %s\n", $1);
        $$ = opr(_typeArgs, 2, $1, $3);
      }
      |
      str_val {
        // fprintf(yyout, "(Stack push) %s\n", $1);
        $$ = $1;
      }

assignment : identifier COLON EQ expr SEMICOLON {
        // fprintf(yyout, "%s = %s\n", $1, $4);
        $$ = opr(_typeAssign, 2, $1, $4);
}

bool_expr : expr EQ expr {
        // $$ = strdup("t");
        // gencode($$, $1, "=", $3);
        $$ = opr(_typeEE, 2, $1, $3);
}
            |
            expr NE expr {
        // $$ = strdup("t");
        // gencode($$, $1, "<>", $3);
        $$ = opr(_typeNE, 2, $1, $3);
}
            |
            expr LT expr {
        // $$ = strdup("t");
        // gencode($$, $1, "<", $3);
        $$ = opr(_typeLT, 2, $1, $3);
}
            |
            expr LE expr {
        // $$ = strdup("t");
        // gencode($$, $1, "<=", $3);
        $$ = opr(_typeLE, 2, $1, $3);
}
            |
            expr GT expr {
        // $$ = strdup("t");
        // gencode($$, $1, ">", $3);
        $$ = opr(_typeGT, 2, $1, $3);
}
            |
            expr GE expr {
        // $$ = strdup("t");
        // gencode($$, $1, ">=", $3);
        $$ = opr(_typeGE, 2, $1, $3);
}
            |
            LPAREN bool_expr RPAREN {
        $$ = $2;
}
            |
            bool_expr KEY_AND bool_expr {
        // $$ = strdup("t");
        // gencode($$, $1, "and", $3);
        $$ = opr(_typeAnd, 2, $1, $3);
}
            |
            bool_expr KEY_OR bool_expr {
        // $$ = strdup("t");
        // gencode($$, $1, "or", $3);
        $$ = opr(_typeOr, 2, $1, $3);
}


statement : assignment { $$ = $1;}
            |
            read_write { $$ = $1;}
            |
            conditional { $$ = $1;}
            |
            loop { $$ = $1;}

body : statement body {
        $$ = opr(_typeBody, 2, $1, $2);
}
        |
        statement {
        $$ = $1;
}

conditional : KEY_IF bool_expr KEY_THEN KEY_BEGIN body KEY_END SEMICOLON {
        // fprintf(yyout, "end if\n");
        $$ = opr(_typeIf, 2, $2, $5);
}
              |
              KEY_IF bool_expr KEY_THEN KEY_BEGIN body KEY_END KEY_ELSE KEY_BEGIN body KEY_END SEMICOLON {
        $$ = opr(_typeIfElse, 3, $2, $5, $9);
}


while_loop : KEY_WHILE bool_expr KEY_DO KEY_BEGIN body KEY_END SEMICOLON {
        $$ = opr(_typeWhile, 2, $2, $5);
}

for_range : identifier COLON EQ expr KEY_TO expr {
        $$ = opr(_typeForRange, 3, $1, $4, $6);
}

for_loop : KEY_FOR for_range KEY_DO KEY_BEGIN body KEY_END SEMICOLON {
        $$ = opr(_typeFor, 2, $2, $5);
}

loop : for_loop {$$ = $1;}
        |
        while_loop {$$ = $1;}

program : KEY_PROGRAM identifier SEMICOLON decl_top KEY_BEGIN body KEY_END DOT {
        $$ = opr(_typeProgram, 3, $2, $4, $6);
        printNode($$);
}

// demo : expr {
//         fprintf(yyout, "%s\n", $1);
// }
%%

nodeType *conInt(int value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        yyerror("Out of memory\n");
        exit(0);
    }
    p->type = _typeInt;
    p->conInt.value = value;
    return p;

}

nodeType *conStr(char *value) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        yyerror("Out of memory\n");
        exit(0);
    }
    p->type = _typeStr;
    p->conStr.value = strdup(value);
    return p;

}

nodeType *id(int i) {
    nodeType *p;
    if((p = (nodeType *)malloc(sizeof(nodeType))) == NULL) {
        yyerror("Out of memory\n");
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
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");   
    if ((p->opr.ops = malloc(nops * sizeof(nodeType))) == NULL)
        yyerror("out of memory"); 
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

void printNode(nodeType *root) {
    // printf("printNode\n");
    if (root == NULL) return;
    if (root->type ==  _conInt)
        fprintf(yyout, "(INT: %d)", root->conInt.value);
    else if (root->type ==  _conStr)
        fprintf(yyout, "(STR: %s)", root->conStr.value);
    else if (root->type ==  _id)
        fprintf(yyout, "(ID: %d)", root->id.i);
    else if (root->type ==  _opr) {
    fprintf(yyout, "{");
    switch(root->opr.oper) {
        case _typeInt:
            fprintf(yyout, "integer");
            break;
        case _typeReal:
            fprintf(yyout, "real");
            break;
        case _typeChar:
            fprintf(yyout, "char");
            break;
        case _typeAdd:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " + ");
            printNode(root->opr.ops[1]);
            break;
        case _typeSub:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " - ");
            printNode(root->opr.ops[1]);
            break;
        case _typeMul:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " * ");
            printNode(root->opr.ops[1]);
            break;
        case _typeDiv:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " / ");
            printNode(root->opr.ops[1]);
            break;
        case _typeMod:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " % ");
            printNode(root->opr.ops[1]);
            break;
        case _typeAssign:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " = ");
            printNode(root->opr.ops[1]);
            break;
        case _typeEE:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " == ");
            printNode(root->opr.ops[1]);
            break;
        case _typeNE:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " != ");
            printNode(root->opr.ops[1]);
            break;
        case _typeLT:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " < ");
            printNode(root->opr.ops[1]);
            break;
        case _typeLE:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " <= ");
            printNode(root->opr.ops[1]);
            break;
        case _typeGT:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " > ");
            printNode(root->opr.ops[1]);
            break;
        case _typeGE:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " >= ");
            printNode(root->opr.ops[1]);
            break;
        case _typeAnd:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " && ");
            printNode(root->opr.ops[1]);
            break;
        case _typeOr:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " || ");
            printNode(root->opr.ops[1]);
            break;
        case _typeIf:
            fprintf(yyout, "if ");
            printNode(root->opr.ops[0]);
            fprintf(yyout, " then\n");
            printNode(root->opr.ops[1]);
            break;
        case _typeIfElse:
            fprintf(yyout, "if ");
            printNode(root->opr.ops[0]);
            fprintf(yyout, " then\n");
            printNode(root->opr.ops[1]);
            fprintf(yyout, "else\n");
            printNode(root->opr.ops[2]);
            break;
        case _typeWhile:
            fprintf(yyout, "while ");
            printNode(root->opr.ops[0]);
            fprintf(yyout, " do\n");
            printNode(root->opr.ops[1]);
            break;
        case _typeFor:
            fprintf(yyout, "for ");
            printNode(root->opr.ops[0]);
            fprintf(yyout, " do\n");
            printNode(root->opr.ops[1]);
            break;
        case _typeForRange:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " = ");
            printNode(root->opr.ops[1]);
            fprintf(yyout, " to ");
            printNode(root->opr.ops[2]);
            break;
        case _typeRead:
            fprintf(yyout, "read ");
            printNode(root->opr.ops[0]);
            break;
        case _typeWrite:
            fprintf(yyout, "write ");
            printNode(root->opr.ops[0]);
            break;
        case _typeBody:
            printNode(root->opr.ops[0]);
            fprintf(yyout, "\n");
            printNode(root->opr.ops[1]);
            break;
        case _typeDecls:
            printNode(root->opr.ops[0]);
            fprintf(yyout, "\n");
            printNode(root->opr.ops[1]);
            break;
        case _typeDecl:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " : ");
            printNode(root->opr.ops[1]);
            break;
        case _typeDeclArray:
            printNode(root->opr.ops[0]);
            fprintf(yyout, " : array [");
            printNode(root->opr.ops[1]);
            fprintf(yyout, "..");
            printNode(root->opr.ops[2]);
            fprintf(yyout, "] of ");
            printNode(root->opr.ops[3]);
            break;
        case _typeArgs:
            printNode(root->opr.ops[0]);
            fprintf(yyout, ", ");
            printNode(root->opr.ops[1]);
            break;
        case _typeMultId:
            printNode(root->opr.ops[0]);
            fprintf(yyout, ", ");
            printNode(root->opr.ops[1]);
            break;
        case _typeArrayIndex:
            printNode(root->opr.ops[0]);
            fprintf(yyout, "[");
            printNode(root->opr.ops[1]);
            fprintf(yyout, "]");
            break;
        case _typeProgram:
            fprintf(yyout, "program ");
            printNode(root->opr.ops[0]);
            fprintf(yyout, ";\n");
            printNode(root->opr.ops[1]);
            fprintf(yyout, "begin\n");
            printNode(root->opr.ops[2]);
            fprintf(yyout, "end.\n");
            break;
        }
        fprintf(yyout, "}");
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(yyout, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(yyout, "Error opening file %s\n", argv[1]);
        return 1;
    }

    yyout = fopen("output.txt", "w");
    if(yyout == NULL) {
            fprintf(yyout, "Error opening file output.txt\n");
            return 1;
    }
    
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int yywrap() {
//   fprintf(yyout, "valid input\n");
  return 1;
}