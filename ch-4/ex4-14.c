#include <stdio.h>
#define swap(t, x, y) t _z; _z=x; x=y; y=_z

/* define a macro swap(t, x, y) */
int main(void)
{
	char var1, var2;
	var1 = 'a';
	var2 = 'z';
	swap(int, var1, var2);
	printf("var1: %c var2: %c\n", var1, var2);
}
