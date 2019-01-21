#include <stdio.h>
#include <stdlib.h>
#include "ast.hpp"

void Tree::printtree(Tree *root, int tab) {
    
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
		case TINT : printf("Int(%d)\n",root->ival); break;
		case TID : printf("Id(%s)\n",root->sval); break;
	}
	
	
	if(root->bro != NULL) 
		printtree(root->bro, tab+1);
	
	if(root->son != NULL) 
		printtree(root->son, tab+1);
}

Tree::Tree(NKind kind, Tree *bro, Tree *son)
{
	this->kind = kind;
	this->bro = bro;
	this->son = son;
}

Tree::Tree(NKind kind, Tree *son)
{
	this->kind = kind;
	this->son = son;
}

Tree::Tree(NKind kind, int val)
{
	this->kind = kind;
	this->ival = val;
}

Tree::Tree(NKind kind, char *val)
{
	this->kind = kind;
	this->sval = val;
}

Tree::Tree(const Tree &tree)
{
	this->bro = tree.bro;
	this->son = tree.son;
}



Tree& Tree::operator = (const Tree &tree)
{
	if(&tree != this)
	{
		this->bro = tree.bro;
		this->son = tree.son;
	}
	
	return *this;
}