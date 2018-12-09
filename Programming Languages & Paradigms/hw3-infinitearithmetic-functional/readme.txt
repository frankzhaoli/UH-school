2
Python 3
Command: python infinitearithmetic.py "input=test.txt;digitsPerNode=3"

3
We used lambda and map.

4
When the expression is read in, errors (missing operands will be checked for), otherwise
the expression will be split by certain delimiters into a list. Then the list is processed
using a stack. Operands are put onto the stack until an operator is seen, then
two values are popped off the stack and the result is calculated based on the operator.
The result is pushed onto the stack, and this cycle continues until the result is the last
element in the stack.

Using lambda and map addList() adds two list's respective entries ignoring carries and 
then again only returning a list of carries. multList() multiplies each list's elements 
against every element of the other list similar to long multiplication. Each time an 
element a new total equals the old total plus this new product. A copy of that new list 
is used in the next recursive call. toString() converts the list data structure into an 
string with proper leading zeroes in certain nodes.