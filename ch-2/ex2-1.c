#include <stdio.h>
#include <limits.h>
/* program to determine ranges of:
 * char, short, int and long 
 * (unsigned and signed) */
int main(void)
{	
	printf("\nSigned:\n");
	printf("CHAR: %i, %i\n", CHAR_MAX, CHAR_MIN);
	printf("SHRT: %i, %i\n", SHRT_MAX, SHRT_MIN);
	printf("INT: %i, %i\n", INT_MAX, INT_MIN);
	printf("LONG: %i, %i\n", LONG_MAX, LONG_MIN);
	
	printf("\nUnsigned:\n");
	printf("UCHAR: %u, %i\n", UCHAR_MAX, 0);
	printf("USHRT: %u, %i\n", USHRT_MAX, 0);
	printf("UINT: %u, %i\n", UINT_MAX, 0);
	printf("ULONG: %u, %i\n", ULONG_MAX, 0);
}
