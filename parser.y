%{

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
int f = 1;
int w = 1;

void gencode(char *word, char *first, char *op, char *second) {
        char temp[10];
        sprintf(temp, "%d", k++);
        strcat(word, temp);
        printf("%s = %s %s %s\n", word, first, op, second);
}

symNode sym_table[MAX_SYMBOLS];

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
void decEx(nodeType *root);

void freeNode(nodeType *p);

nodeType *ex(nodeType *root);

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
        // printf("func call read\n");
        $$ = opr(_typeRead, 1, $3);
}
            |
            KEY_WRITE LPAREN args RPAREN SEMICOLON {
        // printf("func call write\n");
        $$ = opr(_typeWrite, 1, $3);
}

args : atom COMMA args {
//     printf("(Stack push) %s\n", $1);
        $$ = opr(_typeArgs, 2, $1, $3);
}
      |
      atom {
        // printf("(Stack push) %s\n", $1);
        $$ = $1;
      }
      |
      str_val COMMA args {
        // printf("(Stack push) %s\n", $1);
        $$ = opr(_typeArgs, 2, $1, $3);
      }
      |
      str_val {
        // printf("(Stack push) %s\n", $1);
        $$ = $1;
      }

assignment : identifier COLON EQ expr SEMICOLON {
        // printf("%s = %s\n", $1, $4);
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
        // printf("end if\n");
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
        decEx($4);
        printf("Decl done\n");
        ex($6);
}

// demo : expr {
//         printf("%s\n", $1);
// }
%%

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
    if (p->type == _conInt) {
        printf("%d", p->conInt.value);
    } else if (p->type == _conStr) {
        printf("%s", p->conStr.value);
    } else if (p->type == _id) {
        printf("%d", p->id.i);
    } else if (p->type == _opr) {
        switch(p->opr.oper) {
            case _typeAdd: printf("+"); break;
            case _typeSub: printf("-"); break;
            case _typeMul: printf("*"); break;
            case _typeDiv: printf("/"); break;
            case _typeMod: printf("%%"); break;
            case _typeAssign: printf("="); break;
            case _typeEE: printf("=="); break;
            case _typeNE: printf("!="); break;
            case _typeLT: printf("<"); break;
            case _typeLE: printf("<="); break;
            case _typeGT: printf(">"); break;
            case _typeGE: printf(">="); break;
            case _typeAnd: printf("&&"); break;
            case _typeOr: printf("||"); break;
            case _typeIf: printf("if"); break;
            case _typeIfElse: printf("if-else"); break;
            case _typeWhile: printf("while"); break;
            case _typeFor: printf("for"); break;
            case _typeForRange: printf("for-range"); break;
            case _typeRead: printf("read"); break;
            case _typeWrite: printf("write"); break;
            case _typeBody: printf("body"); break;
            case _typeDecls: printf("decls"); break;
            case _typeDecl: printf("decl"); break;
            case _typeDeclArray: printf("decl-array"); break;
            case _typeArgs: printf("args"); break;
            case _typeMultId: printf("mult-id"); break;
            case _typeArrayIndex: printf("array-index"); break;
            case _typeProgram: printf("program"); break;
        }
        printf("(");
        for(int i = 0; i < p->opr.nops; i++) {
            printNode(p->opr.ops[i]);
            if (i < p->opr.nops - 1) {
                printf(", ");
            
            }
        }
        printf(")");
    }
}

int getValue(nodeType *p) {
    if (p->type == _conInt) {
        return p->conInt.value;
    } else if (p->type == _id) {
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
        printNode(p);
        printf("\n");
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


dataType getDt(nodeType *p) {
    if (p == NULL) return _dtEmpty;
    if (p->type == _typeInt) return _dtInt;
    if (p->type == _typeReal) return _dtReal;
    if (p->type == _typeChar) return _dtChar;
    if (p->type == _typeBoolean) return _dtBool;
    return _dtEmpty;
}

dataType getArrDt(dataType dt) {
    if (dt == _dtInt) return _dtIntArr;
    if (dt == _dtReal) return _dtRealArr;
    if (dt == _dtChar) return _dtCharArr;
    if (dt == _dtBool) return _dtBoolArr;
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
    else if (root->type ==  _conStr)
        return root;
    else if (root->type ==  _id)
        return root;
    else if (root->type ==  _opr) {
    // printf("{");
    typeEnum oper = root->opr.oper;
        if (oper == _typeInt) return root;
        if (oper == _typeReal) return root;
        if (oper == _typeChar) return root;
        if (oper == _typeAdd) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conInt(getValue(left) + getValue(right));
        }
        if (oper == _typeSub) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conInt(getValue(left) - getValue(right));
        }
        if (oper == _typeMul) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conInt(getValue(left) * getValue(right));
        }
        if (oper == _typeDiv) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conInt(getValue(left) / getValue(right));
        }
        if (oper == _typeMod) {
            nodeType *left =  ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            return conInt(getValue(left) % getValue(right));
        }
        if (oper == _typeAssign) {
            nodeType *left = ex(root->opr.ops[0]);
            nodeType *right = ex(root->opr.ops[1]);
            // sym_table[left->id.i] = getValue(right);
            setValue(left, getValue(right));
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
                } else if (left->type == _id) {
                    printf("%d ", getValue(left));
                    break;
                } else {
                    if (left->opr.oper == _typeArgs) {
                        nodeType *right = ex(left->opr.ops[0]);
                        if (right->type == _conInt) {
                            printf("%d ", right->conInt.value);
                        } else if (right->type == _conStr) {
                            printf("%s ", right->conStr.value);
                        } else if (right->type == _id) {
                            printf("%d ", getValue(right));
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