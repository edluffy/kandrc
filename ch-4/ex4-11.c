/* modify getop so that it does not need to use ungetch */
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

static int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type)
		{
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
			default:
				printf("error: unkown command %s\n", s);
				break;
		}
	}
	return 0;
}


#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

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
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


#include <ctype.h>
int getch(void);
void ungetch(int);

/* get next operator or numeric operand */
static int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c  == '\t');
	
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()));
	if(c == '.')
		while(isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}


#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) // get a possibly pushed back char
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) // push character back on input
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
