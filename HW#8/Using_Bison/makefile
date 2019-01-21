YACC=bison -dy
LEX=flex
a.exe:	lex.yy.c y.tab.c y.tab.h tree.h tree.c
	$(CXX) lex.yy.c y.tab.c tree.c
lex.yy.c:	ast.l
	$(LEX) ast.l
y.tab.c:	ast.y
	$(YACC) ast.y
y.tab.h:	ast.y
	$(YACC) ast.y
clean:
	$(RM) a.exe lex.yy.c y.tab.c y.tab.h
