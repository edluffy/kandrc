#include <stdio.h>
#define SYM 0
#define NUM 1

static int state;
int getops(char *s);
void ppush(int n);
int ppop(void);

/* write the program expr  which evaluates
 * a reverse polish expression from the command line */
int main(int argc, char *argv[])
{
	int op, val;
	while(--argc > 0){
		op = getops(*++argv);
		switch(state)
		{
			case SYM: 
				if(op == '+')
					ppush(ppop() + ppop());
				else if(op == 'x')
					ppush(ppop() * ppop());
				else if(op == '/'){
					val = ppop();
					ppush(ppop() / val);
				}else if(op == '-'){
					val = ppop();
					ppush(ppop() - val);
				}else
					printf("error: unknown op '%c'", op);
			       break;
			
			case NUM:
			       ppush(op);
				break;
		}
	}
       printf("= %i\n", ppop());       
}

#include <ctype.h>
#include <stdlib.h>
#define MAXNL 999 // maximum number length

/* return operation or operand from string of input */
int getops(char *s)
{
	char *nbuf;
	char *start = nbuf;
	
	if(!isdigit(*s)){
		state = SYM; // not number
		return *s;
	}

	if(isdigit(*s)){
		for( ; isdigit(*s) && nbuf-start < MAXNL-1; nbuf++, s++)
			*nbuf = *s;
		*nbuf = '\0';
		state = NUM;
		return atoi(start);
	}
		
}

#define LIM 999 // max number of items in stack
int stack[LIM];
int *stackp = stack;
int *bottom = stack;

/* push an item into the stack */
void ppush(int n)
{
	if(stackp < bottom + LIM)
		*stackp++ = n;
	else
		printf("error: stack full");

}

/* pop the top item from stack and return */
int ppop(void)
{
	if(stackp >= bottom)
		return *--stackp;
	else
		printf("error: stack empty");
	return '\0';
}
