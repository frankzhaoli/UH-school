calc: lex.yy.c calc.tab.c
	gcc -g lex.yy.c calc.tab.c -o calc

lex.yy.c: calc.tab.c calc.l
	flex calc.l

calc.tab.c: calc.y
	bison -d calc.y

clean: 
	rm -rf lex.yy.c calc.tab.c calc.tab.h calc calc.dSYM