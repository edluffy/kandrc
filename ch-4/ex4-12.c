/* write a recursive version of itoa */
#include <stdio.h>
#define LIM 999
char ritoa(int n);

int main(void)
{
	int num, max;
	char nstring[LIM];

	for(num = 0, max = 15; num < max; num++){
		ritoa(num);
		printf("int: %i\tascii: %s\n", num, nstring);
	}
}

int pos = 0;
char ritoa(int n, char s)
{
	char bufc;

	if(n % 10 > 0){
		ritoa(n % 10);
		 s[pos++] = n + '0';
	}else
		s[pos] = '\0';
}
