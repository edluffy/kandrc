#include <stdio.h>
#define SIZE 999

/* fix getint to push back a single '+' or '-' */
int main(void)
{
	int n, array[SIZE], getint(int *);

	for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	array[n] = '\0';
	for(n = 0; array[n] != '\0'; n++)
		printf("%i\n", array[n]);
}


#include <ctype.h>
int getch(void);
void ungetch(int);

/* get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	while(isspace(c = getch()))
		; // skip white space

	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0; // not a number
	}

	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}


#define BUFSIZE 99
char buf[BUFSIZE];
int bufp = 0;

/* get next (may be pushed back) char from input */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
/* push back char from input */
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("error: ungetch buffer full");
	else
		buf[bufp++] = c;
}
