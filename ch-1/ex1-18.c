#include <stdio.h>
#define LIM 999

/* remove trailing blanks and tabs from input */
void trailrem(char string[], int len);
int main(void)
{
	int c, i, j;
	char line[LIM];

	for(i = 0; (c = getchar()) != '\n' && i < LIM; i++)
		line[i] = c;
	
	trailrem(line, i);
	printf("%s\n", line);	
}

/* remove blank/tab trails */
void trailrem(char string[], int len)
{
	int i = len;
	for(i--; string[i] == ' ' || string[i] == '\t'; i--)
		;
	string[i+1] = '\0';
}
