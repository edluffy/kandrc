/* write a recursive version of itoa */
#include <stdio.h>
#define LIM 999
void ritoa(int n, char s[]);

int main(void)
{
	int num, max;
	char nstring[LIM];
	printf("Enter a number: ");
	scanf("%i", &num);
	
	ritoa(num, nstring);
	printf("int: %i\tascii: %s\n", num, nstring);
}

int pos = 0;
void ritoa(int n, char s[])
{
	if(n < 0){
		s[pos++] = '-';
		n = -n;
	}
	if(n / 10)
		ritoa(n / 10, s);	
	s[pos++] = n % 10 + '0';
}
