#include <stdio.h>

/* prints input one word per line */
int main(void)
{
	int c;
	int state = 0; // true when in word
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else
			putchar(c);
	}

}

