#include <stdio.h>
#define MAXLL 99 // maximum line length

int readl(char *s, int lim);
void push(double v);
double pop(void);

int main(void)
{
	char line[MAXLL], op;
	double v;

	int pos = 0;
	while(readl(line, MAXLL) > 0){
		while(sscanf(line + pos++, " %lf", &v) == 1)
			printf("|%lf|\n", v);
		while(sscanf(line + pos++, "%c", &op) == 1){
			printf("|%c|\n", op);
			/*switch(op)
			{
				case '+':
					push(pop() + pop());
					break;
				default:
					printf("error: unknown op - %c", op);
					break;
			} */
		}
		printf("\t%lf\n", pop());
	}

	return 0;
}

/* gets next line of input, returns length */
int readl(char *s, int lim)
{
	int len, c;
	
	len = 0;
	while((c = getchar()) != EOF && c != '\n' && len < lim-1)
		s[len++] = c;
	s[len] = '\0';

	return len;
}

/* push and pop - calc stack manipulation */

#define MAXNS 99 // maximum number of items in stack
double nstack[MAXNS];
int sp = 0;

void push(double v)
{
	if(sp < MAXNS)
		nstack[sp++] = v;
	else
		printf("push error: stack full\n");
}

double pop(void)
{
	if(sp > 0)
		return nstack[--sp];
	else{
		printf("pop error: stack empty\n");
		return 0;
	}
	

}
