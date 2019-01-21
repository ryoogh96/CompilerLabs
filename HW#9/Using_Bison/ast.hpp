#ifndef __AST_HPP__
#define __AST_HPP__

#include <string.h>

using namespace std;

typedef enum { PLUS, MINUS, MUL, DIV, UMIN, TINT, TID } NKind;

class Tree
{
private:
	NKind kind;
	union {
	int ival;
	char *sval;
	};
public:
	void printtree(Tree *root, int tab);
	Tree *bro = NULL;
	Tree *son = NULL;
	Tree(NKind kind, Tree *bro, Tree *son);
	Tree(NKind kind, Tree *son);
	Tree(NKind kind, int val);
	Tree(NKind kind, char *val);
	Tree(const Tree &tree);
	Tree& operator = (const Tree &tree);
};


#endif
