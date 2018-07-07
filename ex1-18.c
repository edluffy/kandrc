#include <stdio.h>
#define LIM 999
/* remove trailing blanks and tabs from input */
int main(void)
{
	int c, i, j;
	char line[LIM];

	for(i = 0; (c = getchar()) != '\n' && i < LIM; i++)
		line[i] = c;

	// remove trails
	for(i--; line[i] == ' ' || line[i] == '\t'; i--)
		;
	
	for(j = 0; j <= i; j++)
		putchar(line[j]);	
}
