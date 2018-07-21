#include <stdio.h>
#include <string.h>
#define LIM 999
/* write a new version of itoa (from p.64) */
void itoa(int n, char s[], int w);
int main(void)
{
	int number, width;
	char string[LIM];
	
	printf("Enter number: ");
	scanf("%i", &number);
	printf("Enter min field width: ");
	scanf("%i", &width);

	itoa(number, string, width);
	printf("%s", string);
}

/* converts n to chars in s, with min field width of w */
void itoa(int n, char s[], int w)
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;	
	i = 0;
	do
		s[i++] = n % 10 + '0';
	while ((n /= 10) > 0);

	if(sign < 0) s[i++] = '-';
	while(i < w) s[i++] = ' ';
	s[i] = '\0';
	strrev(s);
}
