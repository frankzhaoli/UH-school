%{
#include "mypython.tab.h"
void yyerror(char const *s);
int yylex();
int lineno=1;
%}

%%

"return"		{return RETURN;}
"def"			{return DEF;}
"   "			{return INDENT;}
"if"			{return IF;}
"=="			{return EQUALS;}
"equals"		{return EQUALS;}
"!="			{return NOTEQUAL;}
"<"				{return LESSTHAN;}
">"				{return GREATERTHAN;}
<<EOF>> 		{static int once = 0; return once++ ? 0 : '\n';}
(\".*\")		{yylval.id=yytext; return STRING;}
"print"			{return PRINT;}
"exit"			{return EXIT;}
[a-zA-z]+		{yylval.id=yytext; return identifier;}
[0-9]+			{yylval.num=atoi(yytext); return number;}
\n				{lineno++; return END;}
[ \t]+			;
"("				{return LPAR;}
")"				{return RPAR;}
","				{return COMMA;}
[-+*/=;:]		{return yytext[0];}
.				{yyerror("Unexpected character.");}
#.*"\n"			{lineno++;}

%%

int yywrap(void)
{
	exit(0);
	return 1;
}