#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error(char *msg) {
	printf("ERROR: %s\n", msg);
	exit(1);
}

int LA, answer;

int yylex() {
	char chr = getchar();	// chr assign to LA by returning
	
	if(chr == ' ')			//	if current input is space then skip it by read one more time
		chr = getchar();
	
	return chr;
}

int match(int t) {
	if (LA == t)
		LA = yylex();
	else
		error("lexical error");
}

bool eof() {
	return LA == EOF;
}


int E(), T(), F(), E2(), T2();


// E: T E2
int E() {
	if (eof()) {
        puts("E -> eof");
		exit(0);
    }
	else {
		puts("E -> T E'");
		int num1 = T(); 
		int num2 = E2();
		//printf("E -> T E' num1 : %d num2 : %d ans : %d\n",num1,num2,num1+num2);
		
		return num1 + num2;
	}
}

// E': ε | + T E'
int E2() {
	if(LA == '+') {
		puts("+ T E'");
		match('+'); 
		int num1 = T();
		int num2 = E2();
		//printf("+ T E' %d %d\n", num1,num2);
		
		return num1 + num2;
	}
	else {
		return 0;
	}
	
}

// T: F T'
int T() {
    puts("T -> F T'");
	int num1 = F();
	int num2 = T2();
	//printf("T -> F T' %d %d\n", num1,num2);
	return num1 * num2;
}

// T2: ε | * F T' 
int T2() {
	if (LA == '*') {
		puts("* F T'");
		match('*'); 
		int num1 = F();
		int num2 = T2();
		LA = yylex();
		//printf("* F T' %d %d\n",num1,num2);
		
		return num1 * num2;
	}
	else {
		return 1;
	}
	
}


// F: (E) | num
int F() {
	if (LA == '(') {
        puts("F -> (E)");
		match('('); int num = E(); match(')');
		return num;
	}
	else {
		puts("F -> num");
		int num = LA - '0';
		LA = yylex();
		//printf("F -> num %d\n",num);
		return num;
	}
	
}

int main() {
	LA = yylex();	
	printf("%d\n",E());
	return 0;
}

