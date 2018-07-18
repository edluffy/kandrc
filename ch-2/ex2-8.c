#include <stdio.h>
/* write a function rightrot(x,n) */

int rightrot(int x, int n);
int main(void)
{
	int bits;
	printf("Enter a number: ");
	scanf("%i", &bits);

	printf("Result after bit manipulation: %i", rightrot(bits, 4));
}
/* returns value of x rotated right by n bit positions  */
int rightrot(int x, int n)
{
	int mask;
	
}
