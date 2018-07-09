#include <stdio.h>
/* count blanks, tabs, and newlines */
int main(void)
{
	int c, nblanks, ntabs, nlines;
	nblanks = ntabs = nlines = 0;

	while((c = getchar()) != EOF){
		if(c == ' ')
			nblanks++;
		else if(c == '\t')
			ntabs++;
		else if(c == '\n')
			nlines++;
	}
	printf("Blanks: %i\nTabs: %i\nLines: %i\n", nblanks, ntabs, nlines);
}
