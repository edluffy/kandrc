#include <stdio.h>
#define MAXLL 99

int main(void)
{
	// read line of input
	// scroll through operations
	// (manipulate stack and print after each line)
	
	while(readline(line, MAXLL) > 0){
		while((type = getop(line, op)) != '\0'){
			switch(op)
			{
			
			}
		}
	}
}

/* collect line of input, return length */
int readline(char *s, maxl)
{
	int c, l;
	for(l = 0; (c = getchar()) != EOF && c != '\n' && l < maxl; l++)
	       *s++ = c;
	*s = '\0';

	return l;
}

int pos = 0;

/* collect next legal operation/operand, return it and its type */
int getop(char s[], int o)
{
}
