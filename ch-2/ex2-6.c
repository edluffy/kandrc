#include <stdio.h>
#define LIM 999
/* write a function setbits(x, p, n, y) */

int setbits(int x, int p, int n, int y);
int main(void)
{
	int bits;

	printf("Enter a number: ");
	scanf("%i", &bits);
 	
	printf("Result after bit manipulation: %i", setbits(bits, 3, 2, 4));
}
/* returns x with the n bits that begin at 
 * pos. p set to the rightmost n bits of y */
int setbits(int x, int p, int n, int y)
{
	int mask;
	// copy n bits right of y
	mask = ~(077 << n);

	return (((x >> y-n) & mask) << p) | x;
}

