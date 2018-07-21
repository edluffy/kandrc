#include <stdio.h>
#include <math.h>
#include <string.h>
#define LIM 999
/* write the function itob(n, s, b) */

void itob(int n, char s[], int b);
int main(void)
{
	char nstring[LIM];
	int number, base;

	printf("Enter a number: ");
	scanf("%i", &number);
	printf("Enter a base: ");
	scanf("%i", &base);

	itob(number, nstring, base);
	printf("%s\n", nstring);
}

/* converts n into a base b char representation in s */
void itob(int n, char s[], int b)
{
	int i, j;
	for(i = 0; n >= pow(b, i+1); i++)
		; // find highest digit

	for(j = 0; i >= 0; i--){		
		for(j = 0; n >= pow(b, i) && j <= b; j++)
			n -= pow(b, i);			
		 s[i] = (j <= 9) ? j + '0' : j + 'a'-10;
	}
	strrev(s);
	s[i] = '\0';
}
