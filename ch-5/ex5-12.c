#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 10
#define MAXNL 999 // max number of lines
#define MAXLL 999 // max line length
int tgetline(char *l, int maxlen);

/* write the program tail that prints the last n lines of input */
int main(int argc, char **argv)
{
	int n = DEFAULT;
	if(argc > 1 && **++argv == '-')
		n = atoi(*argv + 1);
	
	int nl;
	char *linep[MAXLL];
	for(nl = 0; tgetline(*(linep+nl), MAXLL) > 0 && nl < MAXNL;  nl++)
		; // collect lines
printf("got here");
	if(nl >= MAXNL){ // error checking
		printf("error: too many lines of input\n");
		return -1;
	}
	
	//while(nl-- && n--)
	//	*line--;
	int i;
	for(i = 0; *linep; i++)
		printf("%s", linep-i);	


}
 GET LINES
int tgetlines(char *l[], int maxlen)
{
	int len, c;
	for(len = 0; (c = getchar()) != EOF && c != '\n' && len < maxlen-1; len++)
		*l++ = c;
	*l = '\0';

	return (len > 0) ? len : -1;
}
