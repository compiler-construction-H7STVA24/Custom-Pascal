 yacc -d parser.y && lex lexer.l && gcc-13  y.tab.c lex.yy.c -ll -ly 