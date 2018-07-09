#include <stdio.h>
#include <string.h>
#define TABSTOP 4

/* fill in tabs with amount of blanks
 * required to reach next tab stop */
int main(void)
{
	int c, i, j;

	for(i = 0; (c = getchar()) != '\n'; i++){
		if(c == '\t')
			for(j = 0; j < TABSTOP; j++) putchar(' ');
		else
			putchar(c);
	}

}
