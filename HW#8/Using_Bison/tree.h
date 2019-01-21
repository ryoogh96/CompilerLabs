#ifndef __TREE_H__
#define __TREE_H__

typedef enum { PLUS, MINUS, MUL, DIV, UMIN, TINT } NKind;

typedef struct _node {
    NKind     kind;
    union { 
	int   ival;
	char *sval;
    };
    struct _node *bro, *son;
} *Tree;

Tree mkleaf(NKind kind, int val);
Tree mknode(NKind kind, int val, Tree bro, Tree son); 
void printtree(Tree root, int tab);

#endif
