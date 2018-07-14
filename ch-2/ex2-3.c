#include <stdio.h>
#define LIM 999
/* write a function htoi(s) which converts
 * a string of hex digits into base ten */

int htoi(char s[]);
int main(void)
{
	char hexstr[LIM];
	int i, c;

	printf("Hexadecimal string to convert: ");
	for(int i = 0; i < LIM-1 && (c = getchar()) != '\n'; i++)
		hexstr[i] = c;
	hexstr[i] = '\0';
	printf("Integer form: %i", htoi(hexstr));
}

/* converts string of hex into base ten
 * returns -1 if convert fails */
int htoi(char s[])
{
	int i, sum;
	for(i = 0; s[i] != '\0'; i++)
		;
	printf("%i", i);
	while(i > 0 && s[i] != 'x' && s[i] != 'X'){
		putchar(s[i]);
		i--;
	}
}
