# **Compiler Design**

## **Team Members :**
### 1. Maniya Yash Rajeshbhai [B20CS033]
### 2. Viradiya Dhruvkumar [B20CS079]

<br>

## **Phases of Compiler :**

### **1. Lexical Analyzer**
The initial stage of the compiler, commonly referred to as the scanner, is lexical analysis. The input programme is changed into a series of tokens via this process. With the help of deterministic finite automata, it is implementable.

### **2. Syntax Analyzer**
The second phase, i.e., parsing or syntax analysis, lexical analysis follows. It determines whether the provided input has the proper syntax (for the language in which it was written) by examining its syntactical structure. It accomplishes this by constructing a Parse tree or Syntax tree data structure. If the given input string can be produced with the aid of the syntax tree (during the derivation process), the input string is judged to be in the right syntax. The parse tree is constructed by using the input string and the pre-defined grammar of the language. 

### **3. Semantic Analyzer**
The goal of semantic analysis is to make sure that a program's declarations and statements are semantically valid, that is, that their meaning is obvious and compatible with how control structures and data types should be utilised.

### **4. Intermediate Code Generator**
A compiler's front end converts a source programme into an independent intermediate code, which is used by the compiler's back end to create the target code. Language independent or language-specific intermediate code, such as Java's Byte Code, is possible (three-address code).



## **Assignment Implementations :**

### **Q1. Lexical Analysis**
Compilation :
```console
flex lexer1.l
gcc lex.yy.c -o Q1_out.exe
Q1_out.exe input.c
```
- Implemented a lexer which can tokenize the given code in to `output.txt` as mentioned in the assignment.
- Code with Single-line comments can be tokenized
- Code with Multi-line comments can be tokenized

### **Q2. Parse Status**
```console
flex lexer2.l
bison -dy parser2.y
gcc lex.yy.c y.tab.c -w -g
a.exe input.c
```
We have defined Grammar Rules for following C statements:
- if-else statements
- switch-case statements (optional)
- for loop
- while loop
- do while loop (optional)

> Prints Results in Console itself.

### **Q3. Syntax Analysis**
```console
flex lexer3.l
bison -dy parser3.y 
gcc y.tab.c -o Q3_out.exe
Q3_out.exe<input.c
```
Implemented lex and yacc code for printing Symbol Table in `output.txt`

### **Q4. Printing Syntax Tree**
```console
flex lexer4.l
bison -dy parser4.y 
gcc y.tab.c -o Q4_out.exe
Q4_out.exe<input.c
```
Implemented lex and yacc code for generating preorder Traversal of the Syntax Tree in `output.txt`