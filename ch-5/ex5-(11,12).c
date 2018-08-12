#include <stdio.h>
#define LIM 999
#define DTABSTOP 4 // default tabstop
static int tabstop[LIM], *ptabstop = tabstop;
static char text[LIM];
void entab(char *s);

/* modify entab and detab to take a list of tab stops as arguments */
int main(int argc, char *argv[])
{
	for( ; ptabstop - tabstop  < LIM; ptabstop++)
		*ptabstop = DTABSTOP; // set default tabstop
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
	printf("%s", ptext);
}


void entab(char *s)
{
	char res[LIM], *pres = res;
	int nstops;
		for(nstops = 0; *s; s++){
			if(*s == ' ' || *s == '\t') // collect blanks
				nstops = (*s == ' ') ? nstops+1 : nstops+*ptabstop;
			else{
				while(nstops > 0){ // fill blanks
					ptabstop = tabstop;
					*pres++ = (nstops % *ptabstop) ? ' ' : '\t';
					nstops = (nstops % *ptabstop++) ? nstops-1 : nstops-*ptabstop++;
				}
				*pres++ = *s;
			}
		}
	pres = res;
	for( ; (*s = *pres) != '\0'; s++, pres++)
	       ;	
}


