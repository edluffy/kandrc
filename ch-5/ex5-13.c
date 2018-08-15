#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 10
#define MAXNL 99 // maximum number of lines
#define MAXLL 999 // maximum line length

int pgetlar(char *plar[], int maxn, int maxl);
int pgetlin(char *plin, int maxl);

/* write the program tail that prints the last n lines of input */
int main(int argc, char *argv[])
{
	int n = DEFAULT;
	if(argc > 1 && *argv[1] == '-')
		n = atoi(argv[1] + 1);

	int nlines, i;
	char *text[MAXLL];
	nlines = pgetlar(text, MAXNL, MAXLL);

	printf("Printing last %i lines\n", n);	
	i = (n < nlines) ? nlines-n : 0;
	while(i < nlines)	
		printf("%s\n", text[i++]);
}


#include <string.h>
char *alloc(int n);

/* returns array of lines and their number */
int pgetlar(char *plarr[], int maxn, int maxl)
{
	int space, nl;
	char line[maxl], *p;

	nl = 0;
	while((space = pgetlin(line, maxl)) > 0 && nl < maxn){
		if((p = alloc(space)) != NULL){
			strcpy(p, line);
			plarr[nl++] = p;
		} else
			break;
	}

	return (nl < 1) ? -1 : nl;

}

/* returns line and its length */
int pgetlin(char lin[], int maxl)
{
	int c, len;

	len = 0;
	while((c = getchar()) != EOF && c != '\n' && len < maxl-1)
		lin[len++] = c;
	lin[len] = '\0';

	return (len < 1) ? -1 : len+1;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return 0;
}
