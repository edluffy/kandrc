#include <stdio.h>
int getop(char c[]);
void push(double f);
double pop(void);
int main(void)
{
	int s, type;
	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
			case '+':
				push(pop() + pop());
			break;

			case '\n':
				printf("%f", pop());
			break;
		}
	}
}

int getop(char c[])
{
	c = getchar();
}

#define LIM 999
char stack[LIM];
int spos = 0;

void push(double f)
{
	if(spos < LIM)
		stack[spos++] = f;
	else
		printf("error: can't push full stack");
}
double pop(void)
{
	if(spos > 0)
		return stack[--spos];
	else
		printf("error: can't pop empty stack");
}

#include <ctype.h>
int getop(char s[])
{
	while((s[0] = c = getch()) == ' ' || c == '\t')
		; // skip all blank chars
	s[1] = '\0';

	if(!isdigit(c) && c != '.')
		return c; /
}
