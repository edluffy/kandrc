#include <stdio.h>
/* check if char is EOF or not */
int main(void)
{
	int c;
	while((c = getchar()) != EOF)
		printf("1"); // true
	printf("0"); // false
}
