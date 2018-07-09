#include <stdio.h>

/* prints input one word per line */
int main(void)
{
	int c;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else
			putchar(c);
	}
}

