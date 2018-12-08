%{
void yyerror(char const *s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

unordered_map<string, int> variables={};
vector<string> words;

int findVal(char const *symbol);
void updateSymbolVal(char const *symbol, int val);
int parseExpression(char str, int a, int b);
bool boolExpression(int arg1, char boolOp, int arg2);
void printString(char const *str);
void skipBlock();
void execConditional(bool val);

extern int lineno;
extern int indent_level;

%}

%union {int num; char *id;}
%start line

%token
PRINT
EXIT
END
LPAR
RPAR
COMMA
IF
EQ
NE
LT
GT
DEF
RETURN
COLON
INDENT
UNINDENT
LE
GE
<num> number
<id> identifier STRING
;

%type <num> line exp term BOOL
%type <id> assignment ifelse printer func funcbody

%left '+' '-'
%left '*' '/'

%%

/* descriptions of expected input	corresponding actions in C++ */

line	: assignment END								{;}
		| line assignment END 							{;}
		| INDENT assignment END							{;}
		| line INDENT assignment END 					{;}
		| UNINDENT assignment END						{;}
		| line UNINDENT assignment END 					{;}
		
		| INDENT printer								{;}
		| line INDENT printer							{;}
		| UNINDENT printer								{;}
		| line UNINDENT printer							{;} 
		| printer										{;}
		| line printer									{;}
		
		| ifelse										{;}
		| line ifelse									{;}
		| INDENT ifelse									{;}
		| line INDENT ifelse							{;}
		| UNINDENT ifelse								{;}
		| line UNINDENT ifelse							{;}
		
		| func											{;}
		| line func										{;}
		
		| EXIT END 										{exit(EXIT_SUCCESS);}
		| line EXIT END									{exit(EXIT_SUCCESS);}
		
		| END											{;}
		| line END										{;}
		
;

func 	: DEF identifier LPAR RPAR ':' END				{printf("new func\n");}
		| funcbody										{;}
;

funcbody: INDENT line END								{printf("new line\n");}
/*		| RETURN exp END								{;}*/
;

printer : PRINT LPAR exp RPAR END 						{printf("%d\n", $3);}
		| PRINT LPAR STRING RPAR END 					{printString($3); cout<<endl;}
		| PRINT LPAR STRING COMMA exp RPAR END			{printString($3); printf("%d\n", $5);}
;

ifelse	: IF BOOL COLON						{execConditional($2);}
;
		
BOOL	: exp EQ exp 						{$$ = boolExpression($1, 'e', $3);}
		| exp NE exp						{$$ = boolExpression($1, 'n', $3);}
		| exp LT exp						{$$ = boolExpression($1, 'l', $3);}
		| exp GT exp						{$$ = boolExpression($1, 'g', $3);}
		| exp LE exp						{$$ = boolExpression($1, 'c', $3);}
		| exp GE exp						{$$ = boolExpression($1, 'v', $3);}
		
		| LPAR exp EQ exp RPAR				{$$ = boolExpression($2, 'e', $4);}
		| LPAR exp NE exp RPAR				{$$ = boolExpression($2, 'n', $4);}
		| LPAR exp LT exp RPAR				{$$ = boolExpression($2, 'l', $4);}
		| LPAR exp GT exp RPAR				{$$ = boolExpression($2, 'g', $4);}
		| LPAR exp LE exp RPAR				{$$ = boolExpression($2, 'c', $4);}
		| LPAR exp GE exp RPAR				{$$ = boolExpression($2, 'v', $4);}
;
		
assignment : identifier '=' exp {updateSymbolVal($1, $3);}
;

exp	 : term			{$$=$1;}
	 | exp '+' exp	{$$=parseExpression('+', $1, $3);}
	 | exp '-' exp	{$$=parseExpression('-', $1, $3);}
	 | exp '*' exp 	{$$=parseExpression('*', $1, $3);}
	 | exp '/' exp 	{$$=parseExpression('/', $1, $3);}
;

term : number		{$$=$1;}
	 | identifier	{$$=findVal($1);}
;
	 
%%	/*C++*/

int parseExpression(char str, int a, int b)
{
	int result=0;

	switch(str)
	{
	case '+':
		result=a+b;
		break;
	case '-':
		result=a-b;
		break;
	case '*':
		result=a*b;
		break;
	case '/':
		result=a/b;
		break;
	}
	return result;
}

bool boolExpression(int arg1, char boolOp, int arg2)
{
	switch(boolOp)
	{
	case 'e':
		return arg1 == arg2;
	case 'n':
		return arg1 != arg2;
	case 'l':
		return arg1 < arg2;
	case 'g':
		return arg1 > arg2;
	case 'c':
		return arg1 <= arg2;
	case 'v':
		return arg1 >= arg2;
	}
}

//returns value of given symbol
int findVal(char const *symbol)
{
	//int bucket=computeSymbolIndex(symbol);
	//return symbols[bucket];
	
	string sym=symbol;
	auto found=variables.find(sym);
	
	if(found==variables.end())
	{
		yyerror("Uninitialized variable.");
		return -1;
	}
	else
	{
		return found->second;
	}
}

//update values
void updateSymbolVal(char const *symbol, int val)
{
	string sym(symbol);
	sym.erase(remove(sym.begin(), sym.end(), ' '), sym.end());
	sym=sym.substr(0, sym.find("="));
	variables[sym]=val;
}

void printString(char const *cstr)
{
	
	string str(cstr);
	str=str.substr(0, str.find(','));
	str.erase(remove(str.begin(), str.end(), '"'), str.end());
	str.erase(remove(str.begin(), str.end(), '('), str.end());
	str.erase(remove(str.begin(), str.end(), ')'), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
	
	cout<<str;
}

int main(void)
{
	return yyparse();
}

void yyerror(char const *s)
{
	cout<<"Error on line "<<lineno<<": ";
	fprintf(stderr, "%s Exiting program now.\n", s);
	exit(-1);
}

void skipBlock()
{
	int n = yylex();
	while(n != 273)
	{
		n = yylex();
	}
}

void execConditional(bool val)
{
	if (val == false)
	{
		skipBlock();
	}
}





