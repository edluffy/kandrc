#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 10
#define MAXNL 999 // max number of lines
#define MAXLL 999 // max line length
int tgettext(char **text);

/* write the program tail that prints the last n lines of input */
int main(int argc, char **argv)
{
	int n = DEFAULT;
	if(argc > 1 && **++argv == '-')
		n = atoi(*argv + 1);
	
	int nl;
	char *textp[MAXNL];

	tgettext(textp);
	printf("%s\n", *textp);


}

int tgetline(char *line);

/* returns array of lines and their number */
int tgettext(char *text[])
{
	int n;
	for(n = 0; tgetline(text[n]) > 0 && n < MAXNL; n++)
		;
	return n;
	
}

/* returns line of input and its length */
int tgetline(char *line)
{
	int c, l;
	for(l = 0; l < MAXLL-1 && (c = getchar()) != EOF; l++){
	//	if(c == '\n') break;
		*line++ = c;
	}
	printf("got here");
	*line = '\0';
	printf("got here");
	return l;
}
