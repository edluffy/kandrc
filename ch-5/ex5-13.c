#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 10
#define MAXNL 99 // maximum number of lines
#define MAXLL 999 // maximum line length

char *alloc(int n);
int readline(char *pl, int maxlen);

/* write the program tail that prints the last n lines of input */
int main(int argc, char *argv[])
{
	int n = DEFAULT;
	if(argc > 1 && *argv[1] == '-')
		n = atoi(argv[1] + 1);

	char *textp[MAXNL];
	int nl;
	for(nl = 0; readline(textp[nl], MAXLL) > 0 && nl < MAXNL; nl++){
	}
	printf("%s\n", textp[nl-2]);
}


#include <string.h>
/* stores input line and returns length, -1 if no line to read or storage fails */
int readline(char *pl, int maxlen)
{
	int c, len;
	char line[maxlen];
	for(len = 0; (c = getchar()) != EOF && c != '\n' && len < maxlen-1; len++)
		line[len] = c;
	line[len] = '\0';
	
	if(len > 0 && (pl = alloc(len)) != NULL){
		strcpy(pl, line);
		return len;
	}else
		return -1;
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
