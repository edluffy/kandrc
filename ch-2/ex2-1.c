#include <stdio.h>
#include <math.h>
/* program to determine ranges of:
 * char, short, int and long (unsigned and signed)
 * float, double */
int main(void)
{
	printf("%.0f, %.0f", pow(2, sizeof(char)*7), -pow(2, sizeof(char)*7) + 1);
}
