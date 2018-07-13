#include <stdio.h>
#include <limits.h>
/* program to determine ranges of:
 * char, short, int and long (unsigned and signed)
 * float, double */
int main(void)
{	
	printf("\nSigned:\n");
	printf("%i", CHAR_MAX, CHAR_MIN);
	printf("%i", INT_MAX, SHORT_MIN);
	printf("%i", CHAR_MAX, CHAR_MIN);
	printf("%i", CHAR_MAX, CHAR_MIN);
	
	printf("\nUnsigned:\n");
	printf("%i", CHAR_MAX, CHAR_MIN);
	printf("%i", CHAR_MAX, CHAR_MIN);
	printf("%i", CHAR_MAX, CHAR_MIN);
	printf("%i", CHAR_MAX, CHAR_MIN);
