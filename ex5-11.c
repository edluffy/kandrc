#include <stdio.h>
#define LIM 999
static int tabstop[LIM];
static char text[LIM];

/* modify entab and detab to take a list of tab stops as arguments */
int main(int argc, char *argv[])
{
	int *ptabstop = tabstop;
	for( ; ptabstop - tabstop  < LIM; ptabstop++)
		*ptabstop = 4; // set default tabstop
	ptabstop = tabstop;

	while(--argc){ // grab custom tabstops
		if(**++argv == '-')
			*ptabstop++ = *(*argv + 1) - '0';
	}

	char *ptext = text;
	for(int c; (c = getchar()) != EOF; ptext++)
		*ptext = c;
	*ptext = '\0';
	ptext = text;
	
	entab(ptext);
}


void entab(char *s)
{
	int *start, nstops;
		for( ; *s; s++){
			for(start = *s; *s == ' ' || *s == '\t'; s++)
				nstops = (*s == ' ') ? nstops+1 : nstops+4;
			while(start++ < s && nstops-- > 0)
				start = ' ';
			if(nstops > 0) concat

		}


}


