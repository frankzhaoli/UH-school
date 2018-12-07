%{
#include "mypython.tab.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

void yyerror(char const *s);
int yylex();
extern void resetIfElseCount();
int lineno=0;
bool flag = true;

int current_line_indent = 0; /* indentation of the current line */
int indent_level = 0; /* indentation level passed to the parser */

int numIf = -1;
int numElse = -1;
list<int> ifElseTracker;

list<string> mutatedVar;
list<string> recursiveEnd;

%}

%x indent
%s normal

%%
<indent>"   "    { current_line_indent++; }
<indent>"\n"     { current_line_indent = 0; return END; /*ignoring blank line */ }
<indent>.        {
                   unput(*yytext);
                   if (current_line_indent > indent_level)
				           {
                       indent_level++;
                       return INDENT;
                   }
				           else if(current_line_indent < indent_level)
				           {
                       indent_level--;
                       return UNINDENT;
                   }
				           else
				           {
                       BEGIN normal;
                   }
                 }

"\n"     	{lineno++; current_line_indent = 0; BEGIN indent; return END;}
"return"	{return RETURN;}
"def"			{return DEF;}
"if"			{return IF;}
"else"    {return ELSE;}
"=="			{return EQ;}
"equals"	{return EQ;}
"!="			{return NE;}
"<"				{return LT;}
">"				{return GT;}
"<="			{return LE;}
">="			{return GE;}
":"				{return COLON;}
<<EOF>> 	{static int once = 0; return once++ ? 0 : '\n';}
(\".*\")	{yylval.id=yytext; return STRING;}
"print"		{return PRINT;}
[a-zA-z][a-zA-Z0-9]* {yylval.id=yytext; return identifier;}
[0-9]+		{yylval.num=atoi(yytext); return number;}
[ \t]+		;
"("				{return LPAR;}
")"				{return RPAR;}
"{"       {return LBRA;}
"}"       {return RBRA;}
","				{return COMMA;}
[-+*/=;]	{return yytext[0];}
.				  {ECHO; yyerror("Unexpected character.");}
#.*"\n"		{lineno++;}

%%

int yywrap(void)
{
  resetIfElseCount();
	if(!mutatedVar.empty())
	{
		string mut="Mutated Variables: ";
		mutatedVar.unique();

		for(auto item: mutatedVar)
		{
			mut=mut+item+", ";
		}
		mut=mut.substr(0, mut.size()-2);
		cout<<mut<<endl;
	}

  if(!ifElseTracker.empty())
  {
    string ie = "Nested if/else level: ";
    for (auto item: ifElseTracker)
    {
      ie = ie + to_string(item) + " level, ";
    }
    ie = ie.substr(0, ie.size()-2);
    cout << ie << endl;
  }


	if(!recursiveEnd.empty())
	{
		string recend="Recursive function ends: ";

		for(auto item: recursiveEnd)
		{
			recend=recend+item+", ";
		}
		recend=recend.substr(0, recend.size()-2);
		cout<<recend<<endl;
	}

	exit(0);
	return 1;
}
