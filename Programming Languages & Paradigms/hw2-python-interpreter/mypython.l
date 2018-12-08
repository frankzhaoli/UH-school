%{
#include "mypython.tab.h"
void yyerror(char const *s);
int yylex();
int lineno=1;
bool flag = true;

int current_line_indent = 0;
int indent_level = 0;
%}

%x indent
%s normal

%%
<indent>"   "    { current_line_indent++; }
<indent>"\n"     { current_line_indent = 0; /*ignoring blank line */ }
<indent>.        {
                   unput(*yytext);
                   if (current_line_indent > indent_level) {
                       indent_level++;
                       return INDENT;
                   } else if (current_line_indent < indent_level) {
                       indent_level--;
                       return UNINDENT;
                   } else {
                       BEGIN normal;
                   }
                 }

"\n"     		{lineno++; current_line_indent = 0; BEGIN indent; return END;}
"return"		{return RETURN;}
"def"			{return DEF;}
"if"			{return IF;}
"=="			{return EQ;}
"equals"		{return EQ;}
"!="			{return NE;}
"<"				{return LT;}
">"				{return GT;}
"<="			{return LE;}
">="			{return GE;}
":"				{return COLON;}
<<EOF>> 		{static int once = 0; return once++ ? 0 : '\n';}
(\".*\")		{yylval.id=yytext; return STRING;}
"print"			{return PRINT;}
"exit"			{return EXIT;}
[a-zA-z][a-zA-Z0-9]* {yylval.id=yytext; return identifier;}
[0-9]+			{yylval.num=atoi(yytext); return number;}
[ \t]+			;
"("				{return LPAR;}
")"				{return RPAR;}
","				{return COMMA;}
[-+*/=;]		{return yytext[0];}
.				{ECHO; yyerror("Unexpected character.");}
#.*"\n"			{lineno++;}

%%

int yywrap(void)
{
	exit(0);
	return 1;
}