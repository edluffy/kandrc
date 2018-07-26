#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char s[]);
void push(double f);
double pop(void);
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF){
		switch(type){
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
	else{
		printf("error: can't pop empty stack\n");
		return 0.0;
	}
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
	if(!isdigit(c) && c != '.' && c != '-')
		return c; // not a number
	
	if(c == '-'){ // sign handling
		if(!isdigit(c = getch())){
			ungetch(c);
			return '-';
		}else
			ungetch(c);
	}
	
	// collect integer and fractional parts
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()));
	if(c == '.')
		while(isdigit(s[++i] = c = getch()));
	s[i] = '\0';

	if(c != EOF)
		ungetch(c); // roll back - encountered char we are not ready for
	return NUMBER;
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
