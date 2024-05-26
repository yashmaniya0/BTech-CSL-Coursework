# **Principles of Programming languages**
## **Lexical Analyser:**


## Group Members:
1)  Maniya Yash Rajeshbhai (B20CS033)
2)  Viradiya Dhruvkumar (B20CS079)



## Approach :
* We create a Lexical Analyzer which tokenizes any code into tokens and token_ids (as provided in def.h). 
* Initial step was to read the code from the input file in the form of buffer strings. 
* When we encounter white spaces or newline (\n), we ignore them and tokenize the current buffer.
* We completely ignore the multi-line or inline comments.
* While tokenizing current buffer, we check for the string buffer if it is among the following tokens_categories :

1. Identifier: A string starting with an underscore or a letter and followed by any number
of underscores, letters and digits. Identifiers with two leading underscores (__) are
disallowed.
2. Keywords: short int float double bool char signed unsigned for while do return
void switch break case continue goto long static union default
3. Signed and unsigned Integer constants such as 45, 10, -1234, +5432, 0, -32, etc.
4. Signed and unsigned Floating-point constants such as 1.4, -3.57, 0.72, etc.
5. Arithmetic operators: +, -, *, /, %, ++, --
6. Assignment operators: =, +=, -=, *=, /=
7. Relational operators: <, >, <=, >=, ==
8. Special symbols: ( ) ,(comma) [ ] { } ;

* And then we accordingly write token_ids, token_category in corresponding output files.



## Execution :
For executing the file run the following commands
```console
g++ main.cpp -o main.exe
./main.exe
```
By running the above mentioned commands, the driver main code asks for the input file path, which we will pass as ```./input.in```. In turn it tokenizes the code and creates 2 output files. One is ```pa_1.out``` which contains token_id and tokens. And second one is ```symbol_table_1.out``` which describes whether the token is identifier or keyword.

&rarr; The symbol table represents two fields which are 
the lexeme itself and the marker (keyword or identifier). \
keyword is represented by 0 \
identifier is represented by 1

Symbol table format :
```
int 0
main 1
return 0
```

&rarr; Here pa_1.out stores the output tokens where every token is represented by respective token_ID followed by the value of the attribute

pa_1.out format :
```
423 int
300 main
416 (
417 )
418 {
```
