#include <stdio.h>
#include <string.h>
#define LIM 999

void itoa(int n, char s[]);
int main(void)
{
	int i, number;
	char string[LIM];
	printf("Enter a number: ");
	scanf("%i", &number);

	itoa(number, string);
	printf("%s", string);
}
/* convert n to characters in s
 * rewritten to handle largest neg. no. */
void itoa( int n, char s[])
{
	int i, sign;
	// n is offset by 1 to fit largest neg. no.
	n = ((sign = n) < 0) ? -n-1 : n-1;
	
	i = 0;
	s[i++] = n % 10 + '1'; // offset is returned to normal
	while((n /= 10) > 0)
		s[i++] = n % 10 + '0';

	if(sign < 0) 
		s[i++] = '-';
	s[i] = '\0';
	strrev(s);
}
