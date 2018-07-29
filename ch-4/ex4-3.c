#include <stdio.h>
#include <stdlib.h> 
#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define ASIZE 26 // size of the alphabet
/* extend the ch-4 calculator by adding variables */

int getop(char []);
void push(double);
double pop(void);
int main(void)
{
	int i, type;
	double op2;
	char s[MAXOP];
	double var[ASIZE];

	for(i = 0; i < ASIZE; i++)
		var[i] = 0; // clear variables

	while ((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", var['z' - 'a'] = pop());
				break;
			default:
				if(type >= 'a' && type <= 'z'){
					if(var[type - 'a'] > 0)
						push(var[type - 'a']);
					else
						push(var[type - 'a'] = pop());
				}else
					printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100 // max depth of val stack
int sp = 0; // next free stack pos.
double val[MAXVAL]; // value stack

/* push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop and return top value from stack */
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>
int getch(void);
void ungetch(int);

/* get next operator or numeric operand */
int getop(char s[])
{
	int i, c, type;
	type = -1;

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	if(!isdigit(c) && c != '.')
		return c; // not a number

	i = 0;
	if(isdigit(c)){ // collect integer part
		while(isdigit(s[++i] = c = getch()));
		if(c == '.') // collect fraction part
			while(isdigit(s[++i] = c = getch()));
		type = NUMBER;
	}
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return type;
}

int bufc = EOF; // buffer char for ungetch

int getch(void) // get a pushed back char
{
	int n;
	if(bufc != EOF){
		n = bufc;
		bufc = EOF;
	} else
		n = getchar();
	return n;
}

void ungetch(int c) // push char back on input
{
	if(bufc == EOF)
		bufc = c;
	else
		printf("error: attempt to unget multiple chars");
}

void ungets(char s[]) // push back string on input
{
	int i;
	strrev(s);
	for(i = 0; s[i] != '\0'; i++)
		ungetch(s[i]);
}
