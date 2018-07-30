#include <stdio.h>
#define LIM 999
/* rpn calculator using getline() */

int getln(char l[]);
int getop(char s[], int opstr[]);
void push(double n);
double pop(void);

int main(void)
{
	int i, opnumber;
	char line[LIM];
	int op[LIM];
	double op2;


	while(getln(line) != 0){
		opnumber = getop(line, op);
		for(i = 0; i < opnumber; i++){
			switch(op[i])
			{
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
					if(op2 != 0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				default:
					printf("error: unknown command - %c\n", op[i]);
					break;
			}
		}
		printf("\t%.0f\n", pop());
	}
}

/* gets line of input, returns length */
int getln(char l[])
{
	int i, c;
	for(i = 0; (c = getchar()) != '\n' && c != EOF; i++)
		l[i] = c;
	l[i] = '\0';
	return i;
}

#include <ctype.h>
#include <stdlib.h>
#define MAXOP 999 // max size of an operation / operand

/* returns ops collected and their number */ 
int getop(char s[], int opstr[])
{
	int i, j, n;
	char nbuffer[MAXOP];

	i = n = 0;
	while(s[i] != '\0'){
		if(isblank(s[i])) i++; // skip blanks

		j = 0; // number handling
		if(isdigit(s[i]) || s[i] == '-' && isdigit(s[i+1])){
			while(isdigit(s[i]) || s[i] == '.' || s[i] == '-')
				nbuffer[j++] = s[i++];
			nbuffer[j] = '\0';
			push(atof(nbuffer));
			continue;
		}

		// symbol handling
		if(!isdigit(s[i])){
			opstr[n++] = s[i++];
			continue;
		}
	}
	opstr[n] = '\0';
	return n;
}


#define STACKLIM 99 // maximum stack position
double stack[STACKLIM];
int spos = 0;

/* push value into topmost pos of stack */
void push(double n)
{
	if(spos < STACKLIM)
		stack[spos++] = n;
	else
		printf("error: stack full\n");
}
/* pop and return topmost value from stack */
double pop(void)
{
	if(spos > 0)
		return stack[--spos];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}
