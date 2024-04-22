### Group Details:
    Tanmay Srivastava 2021A7PS3196H
    Samarth Nasnodkar 2021A7PS3204H
    Vrihen Arora 2021A7PS3206H
    Harshit Juneja 2021A7PS2946H
    Aditya Kumar Sharma 2021A7PS3112H

### Compilation:
Task 1 (Lexical Analysis)
# Change Directory
1. cd Lexical_Anal

# Compile
2. ./lex.sh (Run the shell file. If permission is denied, Run 3.)
3. lex lexer.l && gcc lex.yy.c -ll 

# Execute
4. ./a.out filename.txt

Task 2 (Syntax Analysis)
# Change Directory
# First make sure you are in the working directory of the project.
1. cd Syntax_Anal

# Compile
2. ./syn.sh (Run the shell file. If permission is denied, Run 3.)
3.  yacc -d parser.y && lex lexer.l && gcc y.tab.c lex.yy.c -ll -ly
(Remove the -ll -ly flag if error compiling)

# Execute
4. ./a.out filename.txt
