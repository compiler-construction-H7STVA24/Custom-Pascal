### Group Details:
    Tanmay Srivastava 2021A7PS3196H
    Samarth Nasnodkar 2021A7PS3204H
    Vrihen Arora 2021A73206H
    Harshit Juneja 2021A72946H
    Aditya Kumar Sharma 2021A7Ps3112H

### Compilation:
Task 1 (Lexical Analysis)
# Change Directory
1. cd Lexical_Anal

# Compile
run chmod +x lex.sh to give necessary permission to the shell file
2. ./lex.sh (Run the shell file. If permission is denied, Run 3.)
3. lex lexer.l && gcc lex.yy.c -ll 

# Execute
4. ./a.out filename.txt

Task 2 (Syntax Analysis)
# Change Directory
# First make sure you are in the working directory of the project.
1. cd Syntax_Anal

# Compile
run chmod +x syn.sh to give necessary permission to the shell file
2. ./syn.sh (Run the shell file. If permission is denied, Run 3.)
3.  yacc -d parser.y && lex lexer.l && gcc y.tab.c lex.yy.c
(If Error run 4.)
4. yacc -d parser.y && lex lexer.l && gcc y.tab.c lex.yy.c -ll -ly

# Execute
4. ./a.out filename.txt