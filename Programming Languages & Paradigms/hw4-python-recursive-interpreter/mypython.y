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
#include <list>
using namespace std;

int findVal(char const *symbol);
void updateSymbolVal(char const *symbol, int val);
int operation(char op, int a, int b);
bool boolExpression(int arg1, char boolOp, int arg2);
void printString(char const *str);
void skipBlock();
void execConditional(bool val);
void addRecursiveList(string val);
void resetIfElseCount();
void storeFunction();
string runFunction(string funcName, string a, string b);

unordered_map<string, int> variables={};
vector<string> funcinstruct;
list<vector<string>> functions;

int funcflag=0;
static int funcIndent = 0;

extern int lineno;
extern int indent_level;

extern int numIf;
extern int numElse;
extern list<int> ifElseTracker;

extern list<string> mutatedVar;
extern list<string> recursiveEnd;

%}

%union {int num; char *id;}
%start begin

%token
PRINT
END
LPAR
RPAR
LBRA
RBRA
COMMA
IF
ELSE
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
OPERATION
<num> number
<id> identifier STRING
;

%type <num> line exp term
%type <id> assignment ifelse printer func returnstm unindents parameters nonevalexp nonevalterm

%left '+' '-'
%left '*' '/'
%error-verbose

%%

/* descriptions of expected input				corresponding actions in C++ */

begin: line													 		{;}
;

		//assignment statements
line	: assignment									{;}
		| line assignment 							{;}
		| line INDENT assignment 				{;}
		| line unindents assignment	 		{;}

		//print statements
		| line INDENT printer						{;}
		| line unindents printer				{;}
		| printer												{;}
		| line printer									{;}

		//if else statements
		| ifelse												{;}
		| line ifelse										{;}
		| INDENT ifelse									{;}
		| line INDENT ifelse						{;}
		| unindents ifelse							{;}
		| line unindents ifelse					{;}

		//function definition
		| func LBRA											{funcflag=1;}
		| line func	LBRA								{funcflag=1;}

		//return statements
		| line returnstm											{;}
		| line INDENT returnstm 							{;}
		| line unindents returnstm			 			{;}

		//| line returnstm RBRA									{funcflag=0; printf("function end1\n");}
		| line INDENT returnstm RBRA						{funcflag=0; storeFunction();}
		//| line returnstm RBRA END								{;}
		//| line unindents returnstm RBRA 				{funcflag=0; printf("function end3\n");}

		//function calls
		| line identifier LPAR RPAR								{recursiveEnd.push_back(runFunction($2, "none", "none"));}
		| line identifier LPAR exp RPAR						{recursiveEnd.push_back(runFunction($2, to_string($4), "none"));}
		| line identifier LPAR exp COMMA exp RPAR {recursiveEnd.push_back(runFunction($2, to_string($4), to_string($6)));}
		//| line unindents identifier LPAR RPAR			{;}
		//| line unindents identifier LPAR exp RPAR {;}

		//newline characters
		| END																{;}
		| line END													{lineno++; resetIfElseCount();}
		| line END END											{resetIfElseCount();}

		| line RBRA													{storeFunction();}


		//|line unindents RBRA END								{;}
;

unindents : UNINDENT unindents					{;}
		  		| UNINDENT										{;}
;

func 	: DEF identifier LPAR RPAR END											    		{funcinstruct.push_back($2);}
		| DEF identifier LPAR identifier RPAR	END											{funcinstruct.push_back($2);}
		| DEF identifier LPAR identifier COMMA identifier RPAR END 		{funcinstruct.push_back($2);}
;

returnstm : RETURN identifier LPAR RPAR END																			{funcinstruct.push_back($2);}
			| RETURN identifier LPAR RPAR END unindents																{funcinstruct.push_back($2);}
		  | RETURN identifier LPAR identifier RPAR END unindents										{funcinstruct.push_back($2);}
		  | RETURN identifier LPAR identifier COMMA identifier RPAR END unindents 	{funcinstruct.push_back($2);}
			| RETURN LPAR exp RPAR END																								{;}
			| RETURN identifier LPAR parameters RPAR END unindents										{funcinstruct.push_back($2);}
			| RETURN identifier LPAR parameters COMMA parameters RPAR END unindents		{funcinstruct.push_back($2);}

			| RETURN nonevalexp END																										{;}

			|	RETURN identifier '+' identifier LPAR parameters RPAR END unindents			{funcinstruct.push_back($2);}
			|	RETURN identifier LPAR parameters RPAR '+' identifier END unindents			{funcinstruct.push_back($2);}

			|	RETURN identifier '-' identifier LPAR parameters RPAR END unindents			{funcinstruct.push_back($2);}
			|	RETURN identifier LPAR parameters RPAR '-' identifier END unindents			{funcinstruct.push_back($2);}

			|	RETURN identifier '*' identifier LPAR parameters RPAR END unindents			{funcinstruct.push_back($2);}
			|	RETURN identifier LPAR parameters RPAR '*' identifier END unindents			{funcinstruct.push_back($2);}

			|	RETURN identifier '/' identifier LPAR parameters RPAR END unindents			{funcinstruct.push_back($2);}
			|	RETURN identifier LPAR parameters RPAR '/' identifier END unindents			{funcinstruct.push_back($2);}

;

parameters	: identifier '+' number {;}
						| identifier '-' number {;}

printer : PRINT LPAR exp RPAR END 						{;}//printf("%d\n", $3);}
		| PRINT LPAR STRING RPAR END 							{;}//printString($3); cout<<endl;}
		| PRINT LPAR STRING COMMA exp RPAR END		{;}//printString($3); printf("%d\n", $5);}
;

ifelse	: IF identifier EQ exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| IF identifier NE exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| IF identifier LT exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| IF identifier GT exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| IF identifier LE exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| IF identifier GE exp COLON	END						{if (funcflag == 0) {numIf++;} else {funcinstruct.push_back($2);} }
				| ELSE COLON END														{if (funcflag == 0) {numElse++;} }

				| IF exp EQ exp COLON	END						{if (funcflag == 0) {numIf++;}}
				| IF exp NE exp COLON	END						{if (funcflag == 0) {numIf++;}}
				| IF exp LT exp COLON	END						{if (funcflag == 0) {numIf++;}}
				| IF exp GT exp COLON	END						{if (funcflag == 0) {numIf++;}}
				| IF exp LE exp COLON	END						{if (funcflag == 0) {numIf++;}}
				| IF exp GE exp COLON	END						{if (funcflag == 0) {numIf++;}}
;

assignment : identifier '=' exp END {updateSymbolVal($1, $3);}
;

exp	 : term				{$$=$1;}
	 | exp '+' exp	{$$=operation('+', $1, $3);}
	 | exp '-' exp	{$$=operation('-', $1, $3);}
	 | exp '*' exp 	{$$=operation('*', $1, $3);}
	 | exp '/' exp 	{$$=operation('/', $1, $3);}
;

term : number		{$$=$1;}
	 | identifier	{$$=findVal($1);}
;

nonevalexp : nonevalterm				{;}
	 | identifier '+' nonevalexp	{;}
	 | identifier '-' nonevalexp	{;}
	 | identifier '*' nonevalexp 	{;}
	 | identifier '/' nonevalexp 	{;}
	 | number '+' nonevalexp	{;}
	 | number '-' nonevalexp	{;}
	 | number '*' nonevalexp 	{;}
	 | number '/' nonevalexp 	{;}
;

nonevalterm : number		{;}
	 | identifier	{;}
;

%%	/*C++*/

int operation(char op, int a, int b)
{
	int result=0;

	switch(op)
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
		//yyerror("Uninitialized variable");
		return -1;
	}
	else
	{
		return found->second;
	}
}

//update variable values in map
void updateSymbolVal(char const *symbol, int val)
{
	string sym(symbol);
	sym.erase(remove(sym.begin(), sym.end(), ' '), sym.end());
	sym=sym.substr(0, sym.find("="));

	auto found=variables.find(sym);
	//cout<<sym<<endl;

	if(found!=variables.end() && funcflag==0)
	{
		//found
		mutatedVar.push_back(sym);
	}
	variables[sym]=val;
}

//print string literals
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
	/*
	printf("END %i \n", END);
	printf("LBRA %i \n", LBRA);
	printf("RBRA %i \n", RBRA);
	printf("INDENT %i \n", INDENT);
	printf("UNINDENT %i \n", UNINDENT);
	printf("RETURN %i \n", RETURN);

	for(int i = 0; i < 100; i++)
	{
		//if(yylex()==274)
		//cout << yylex() << endl;
	}
	*/

	return yyparse();
}

//print error messages
void yyerror(char const *s)
{
	cout<<"Error on line "<<lineno<<": ";
	fprintf(stderr, "%s. Exiting program now.\n", s);
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

//add to list whether function ends
void addRecursiveList(string val)
{
	recursiveEnd.push_back(val);
}

void resetIfElseCount()
{
	if (numIf >= numElse)
	{
		if (numIf > -1)
		{
			ifElseTracker.push_back(numIf);
		}
	}
	else
	{
		yyerror("'else' without 'if'");
	}
	numIf = -1;
	numElse = -1;
}

//store recursive function into list
void storeFunction()
{
	//cout << "Start store" << endl;
	functions.push_back(funcinstruct);
	funcinstruct.clear();
	//cout << "End store" << endl;

	for(auto item: functions)
	{
		vector<string> func=item;

		for(auto item: func)
		{
			//cout<<"8"<<item<<" ";
		}
		//cout<<endl;
	}
}

//test recursive functions
string runFunction(string funcName, string a, string b)
{
	//find correct function
	funcName=funcName.substr(0, funcName.find("("));

	//search list of functions
	for(auto item: functions)
	{
		vector<string> func=item;
		string definition=func.front();
		//cout<<"="<<definition<<endl;
		string listfuncname=definition.substr(0, definition.find("("));
		string param=definition.substr(definition.find("(")+1, definition.find(")")-2);
		string varA="", varB="";
		int val1=0, val2=0;

		//cout<<"+"<<funcName<<endl;
		//cout<<"+"<<listfuncname<<endl;

		if(funcName==listfuncname)
		{
			//no parameters
			if((a=="none") && (b=="none"))
			{
				string temp=func[1].substr(0, func[1].size()-2);
				//definition.erase(std::remove(definition.begin(), definition.end(), '\n'), definition.end());
				//cout<<temp<<endl;
				definition=definition.substr(0, definition.size()-1);
				//cout<<definition<<endl;

				if(temp.find(definition)!=string::npos)
				{
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			//1 parameter
			else if((a != "none") && (b == "none"))
			{
				val1=stoi(a);
				varA = param.substr(0, param.size()-1);
			}
			//2 parameters
			else if((a != "none") && (b != "none"))
			{
				val1=stoi(a);
				val2=stoi(b);
				varA = param.substr(0, param.find(","));
				varB = param.substr(param.find(",")+1, param.find(")")-2);
				//cout<<":"<<varA<<":"<<varB<<":"<<endl;
			}
			string comparison=func[1];
			string recall=func[2];
			int num2=0;
			string letter="";

			recall=recall.substr(recall.find("(")+1, recall.find(")")-3);
			int adder = 0;
			if (varA != recall)
			{
				adder=stoi(recall.substr(varA.size()+1, recall.size()));
			}

			if(comparison.find("==")!=string::npos)
			{
				//string num2=comparison.substr(comparison.find("==")+2, comparison.find(":")-3);
				letter=comparison.substr(0, comparison.find("=="));
				num2=stoi(comparison.substr(comparison.find("==")+2, comparison.find(":")-3));
				//cout<<letter<<endl;

				if(boolExpression(val1,'e', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
				else
				{
					int distance = abs(val1-num2);
					if (distance%adder != 0)
					{
						return "no";
					}
				}
			}
			else if(comparison.find(">=")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find(">=")+2, comparison.find(":")-3));

				if(boolExpression(val1,'v', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find("<=")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find("<=")+2, comparison.find(":")-3));

				if(boolExpression(val1,'c', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find("<")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find("<")+1, comparison.find(":")-4));
				num2=num2-1;
				if(boolExpression(val1,'c', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}
			else if(comparison.find(">")!=string::npos)
			{
				num2=stoi(comparison.substr(comparison.find(">")+1, comparison.find(":")-4));
				num2=num2+1;
				if(boolExpression(val1,'v', num2))
				{
					return "yes";
				}
				else if (recall == varA)
				{
					return "no";
				}
			}

			if(recall.find(",")!=string::npos)
			{
				string temp=recall.substr(0, recall.find(","));
				//cout<<temp<<endl;

				if(temp.find("+")!=string::npos)
				{
					//increment
					int result=val1+1;

					int delta=abs(val1-num2);
					int delta2=abs(result-num2);

					if(delta2>delta)
					{
						//infinite recursion
						return "no";
					}
					else
					{
						return "yes";
					}
				}
				else if(temp.find("-")!=string::npos)
				{
					//decrement
					adder=stoi(recall.substr(varA.size()+1, recall.size()));
					int result=val1-1;

					int delta=abs(val1-num2);
					int delta2=abs(result-num2);

					if(delta2>delta)
					{
						//infinite recursion
						return "no";
					}
					else
					{
						return "yes";
					}
				}
				//val1=3, val2=4
			}
			else if(recall.find("+")!=string::npos)
			{
				//increment
				int result=val1+1;

				int delta=abs(val1-num2);
				int delta2=abs(result-num2);

				if(delta2>delta)
				{
					//infinite recursion
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			else if(recall.find("-")!=string::npos)
			{
				//decrement
				adder=stoi(recall.substr(varA.size()+1, recall.size()));
				int result=val1-1;

				int delta=abs(val1-num2);
				int delta2=abs(result-num2);

				if(delta2>delta)
				{
					//infinite recursion
					return "no";
				}
				else
				{
					return "yes";
				}
			}
			else
			{
				return "no";
			}
		}
	}
}
