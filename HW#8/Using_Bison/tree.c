#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void printtree(Tree root, int tab) {
    
	int tmp = tab;
	
	while(tmp > 0)
	{
		printf("\t");
		tmp--;
	}
	
	switch(root->kind)
	{
		case PLUS : printf("Op(+)\n");  break;
		case MINUS : printf("Op(-)\n");  break;
		case MUL : printf("Op(*)\n");  break;
		case DIV : printf("Op(/)\n"); break;
		case UMIN : printf("Uop(-)\n");  break;
		default : printf("Int(%d)\n",root->ival); break;
	}
	
	
	if(root->son != NULL) 
		printtree(root->son, tab+1);
	
	if(root->bro != NULL) 
		printtree(root->bro, tab);
}

Tree mkleaf(NKind kind, int val) {
    Tree t = (Tree)malloc(sizeof *t);
    t->kind = kind;
    t->ival = val;
    t->bro = t->son = NULL;
    return t;
}

Tree mknode(NKind kind, int val, Tree bro, Tree son) {
    Tree t = (Tree)malloc(sizeof *t);
    t->kind = kind;
    t->ival = val;
    t->bro = bro;
    t->son = son;
    return t;
}
