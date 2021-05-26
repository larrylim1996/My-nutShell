main:
	bison -d nutshell.ypp
	flex -o lex.yy.cpp nutshell.lpp
	g++ -std=c++17 -Wall -Wextra -Wno-unused-function nutshell.cpp nutshell.tab.cpp lex.yy.cpp -o nutshell