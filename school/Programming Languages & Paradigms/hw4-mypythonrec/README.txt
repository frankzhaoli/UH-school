-----
PSID: 1478184
Name: Zhao Li
COSC ID: cosc2983

PSID: 1670303
Name:Christian Wilson
COSC ID: cosc3005
-----
COMPILE: Makefile included: "make" without the quotation marks.
-----
RUN: "./mypython <testcase1.py" without the quotation marks.
-----
LIMITATIONS:
-Assume at most 2 input parameters for functions.
-Braces, {}, are used to encapsulate the function, ie
def func()
{
   return func()
}

-Else statements can ONLY have a return statement
-Only 1 base case
-Newline must be present at the end of the file, otherwise last line of code will not be seen by flex/bison.
-NOTE: Test cases MUST be created on the server!!!
-----
IMPLEMENTATION:
-If else: to determine the level of nested if else statements we count the number of ifs and elses and compare them to see if there is an else without a corresponding if. 
In the case of a blank line it finalizes those counts and stores them in a running list to be displayed at the end. 
-Recursion termination: We do the calculation (incrementing or decrementing), and see if the result is closer to the 
base case. If so, we conclude the recursion ends, otherwise, the recursion does not end.