YACC=bison -dy
LEX=flex
a.exe:	lex.yy.c y.tab.c y.tab.h ast.hpp ast.cpp
	$(CXX) lex.yy.c y.tab.c ast.cpp
lex.yy.c:	ast.l
	$(LEX) ast.l
y.tab.c:	ast.y
	$(YACC) ast.y
y.tab.h:	ast.y
	$(YACC) ast.y
clean:
	$(RM) a.exe lex.yy.c y.tab.c y.tab.h
