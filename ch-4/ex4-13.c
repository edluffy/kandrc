/* write a recursive version of reverse(s) */
#include <stdio.h>
#define LIM 999
void recrev(char s[]);

int main(void)
{
	int i, c;
	char str[LIM];
	printf("Enter a string to reverse: ");
	for(i = 0; (c = getchar()) != '\n' && i < LIM-1; i++)
		str[i] = c;
	str[i] = '\0';

	recrev(str);
	printf("\t%s", str);
}

/* reverse string s in place */
int pos = 0;
void recrev(char s[])
{
	if(s[pos++] != '\0')
		recrev(s);
	putchar(s[pos]);	
}
