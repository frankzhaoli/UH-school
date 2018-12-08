mypython: lex.yy.c mypython.tab.c
	g++ -static -g lex.yy.c mypython.tab.c -o mypython

lex.yy.c: mypython.tab.c mypython.l
	flex mypython.l

mypython.tab.c: mypython.y
	bison -d mypython.y

clean: 
	rm -rf lex.yy.c mypython.tab.c mypython.tab.h mypython mypython.dSYM