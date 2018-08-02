#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define COMMAND '1'
#define PI 3.14159265359
/* 4-3 add the modulus operator and provisions for negative numbers 
 * 4-4 add commands for 'top', 'dupe', 'swap' and 'clear' 
 * 4-5 add math.h functions like sin, exp and pow */

int getop(char s[]);
void push(double f);
double pop(void);
void sclear(void);
int main(void)
{
	int type;
	double op2, op1;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type){
			case COMMAND:
				if(!strcmp(s, "top")){
					op1 = pop();
					printf("\t%.8g\n", op1);
					push(op1);
				}
				if(!strcmp(s, "dupe")){
					op1 = pop();
					push(op2);
					push(op2);
				}
				if(!strcmp(s, "swap")){
					op2 = pop();
					op1 = pop();
					push(op2);
					push(op1);
				}
				if(!strcmp(s, "clear"))
					sclear();
				
				// math functions
				if(!strcmp(s, "sin")){
					op1 = PI/180;
					push(sin(op1*pop()));
				}
				if(!strcmp(s, "exp"))
					push(exp(pop()));
				if(!strcmp(s, "pow")){
					op2 = pop();
					push(pow(pop(), op2));
				}
				
				break;
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
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


#define LIM 999
double stack[LIM];
int spos = 0;

/* push f onto stack */
void push(double f)
{
	if(spos < LIM)
		stack[spos++] = f;
	else
		printf("error: can't push full stack\n");
}
/* pop and return top value from stack */
double pop(void)
{
	if(spos > 0)
		return stack[--spos];
	else
		printf("error: can't pop empty stack\n");
}
/* clear stack and start from bottom */
void sclear(void)
{
	int i;
	for(i = 0; i < spos; i++)
		stack[i] = 0;
	spos = 0;
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		; // skip to first non-blank char
	s[1] = '\0';

	i = 0;
	if(!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
		return c; // not a number
	
	if(c == '-'){ // sign handling
		if(!isdigit(c = getch())){
			ungetch(c);
			return '-';
		}else
			ungetch(c);
	}
	
	// collect integer and fractional parts
	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()));
		if(c == '.')
			while(isdigit(s[++i] = c = getch()));
		s[i] = '\0';
		return NUMBER;
	
	// collect alphabet characters
	}else if(isalpha(c)){
		while(isalpha(s[++i] = c = getchar()));
		s[i] = '\0';
		return COMMAND;
	}

	if(c != EOF)
		ungetch(c); // roll back - encountered char unprepared for
}


#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed back) char */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
/* push char back on input */
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("error: can't ungetch, too many characters\n");
	else
		buf[bufp++] = c;
}
