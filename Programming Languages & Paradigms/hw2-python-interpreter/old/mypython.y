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
void boolExpression(int arg1, char boolOp, int arg2);
void printString(char const *str);

extern int lineno;

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
EQUALS
NOTEQUAL
LESSTHAN
GREATERTHAN
INDENT
DEF
RETURN
<num> number
<id> identifier STRING
;

%type <num> line exp term
%type <id> assignment ifelse printer func funcbody

%left '+' '-'
%left '*' '/'
%%

/* descriptions of expected input	corresponding actions in C++ */

line	: assignment END								{;}
		| line assignment END 							{;}
		
		| END											{;}
		| line END										{;}
		
		| printer END									{;}
		| line printer									{;}
		
		| INDENT END									{printf("indented");}
		
		| ifelse ':' END								{;}
		| line ifelse ':' END							{;}
		
		| identifier LPAR RPAR END func					{;}
		| line func identifier LPAR RPAR END func		{;}
		
		| EXIT END 										{exit(EXIT_SUCCESS);}
		| line EXIT END									{exit(EXIT_SUCCESS);}
		
;

func 	: DEF identifier LPAR RPAR ':' END				{printf("new func\n");}
		| funcbody										{;}
;

funcbody: INDENT line END								{;}
		| RETURN exp END								{;}

printer : PRINT LPAR exp RPAR END 						{printf("%d\n", $3);}
		| PRINT LPAR STRING RPAR END 					{printString($3); cout<<endl;}
		| PRINT LPAR STRING COMMA exp RPAR END			{printString($3); printf("%d\n", $5);}
		
;

ifelse	: IF exp EQUALS exp								{boolExpression($2, 'e', $4);}
		| IF exp NOTEQUAL exp							{boolExpression($2, 'n', $4);}
		| IF exp LESSTHAN exp							{boolExpression($2, 'l', $4);}
		| IF exp GREATERTHAN exp						{boolExpression($2, 'g', $4);}
		
		| IF LPAR exp EQUALS exp RPAR					{boolExpression($3, 'e', $5);}
		| IF LPAR exp NOTEQUAL exp RPAR					{boolExpression($3, 'n', $5);}
		| IF LPAR exp LESSTHAN exp RPAR					{boolExpression($3, 'l', $5);}
		| IF LPAR exp GREATERTHAN exp RPAR				{boolExpression($3, 'g', $5);}
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

void boolExpression(int arg1, char boolOp, int arg2)
{
	switch(boolOp)
	{
	case 'e':
		if (arg1 == arg2)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
		break;
	case 'n':
		if (arg1 != arg2)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
		break;
	case 'l':
		if (arg1 < arg2)
		{
			printf("true\n");
		}
		else
		{
			printf("fals\ne");
		}
		break;
	case 'g':
		if (arg1 > arg2)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
		break;
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

int main(void)
{
	return yyparse();
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

void yyerror(char const *s)
{
	cout<<"Error on line "<<lineno<<": ";
	fprintf(stderr, "%s Exiting program now.\n", s);
	exit(-1);
}










