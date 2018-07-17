#include <stdio.h>
#define LIM 999
/* write a functioon invert(x, p, n) */

int invert(int x, int p, int n);
int main(void)
{
	int bits;
	printf("Enter a number: ");
	scanf("%i", &bits);

	printf("Result after bit manipulation: %i", invert(bits, 4, 2));
}
/* returns x with the n bits that begin at
 * pos. p inverted */
int invert(int x, int p, int n)
{
	int mask;
	mask = ~(077 << n) << p;

	return (x & ~mask) | (~x & mask);
}
