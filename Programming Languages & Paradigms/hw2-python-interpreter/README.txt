Pt 1
Zhao Li
COSC ID: cosc2983
PSID: 1478184

Christian Wilson
PSID: 1670303

Pt 2
COMPILE: make
RUN: ./mypython <input.py

Pt 3
LIMITATIONS:
-Newline must be present at the end of the file, otherwise last line of code will not be seen by flex/bison.
-No else blocks.
-No functions/function calls.
-NOTE: Files must be in .txt on the computer, and then changed to .py extension on either computer or server 
otherwise there will be an unexpected character error. 

Pt 4
IMPLEMENTATION:
-Parsing: Used flex to tokenize and bison to parse the input.
-Indentation: Implemented in flex.
-Storing: To store the variables an unordered map was used, the variable name is the key, and the variable value 
is the mapped value.

SOURCES:
https://www.youtube.com/watch?v=54bo1qaHAfk
https://github.com/jengelsma/lex-tutorial/

https://www.youtube.com/watch?v=__-wUHG2rfM
https://github.com/jengelsma/yacc-tutorial

https://stackoverflow.com/questions/1413204/how-to-use-indentation-as-block-delimiters-with-bison-and-flex
