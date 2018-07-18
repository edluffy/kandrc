#include <stdio.h>
#define LIM 999
/* rewrite the function lower, from p.43 */

int lower(int c);
int main(void)
{
	char string[LIM];
	int c, i;
	for(i = 0; (c = getchar()) != '\n'; i++)
		string[i] = lower(c);
	printf("String in lowercase: %s", string);
}

/* converts c to lowercase, ASCII only */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a'-'A' : c;
}
