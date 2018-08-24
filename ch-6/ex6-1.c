#include <stdio.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int readkw(char *w, int maxw);
int bsearch(char *word, struct key tab[], int n);

int main(void)
{
	// count occurences of each c keyword
	// struct of keywords
	// function that gets keywords
	// binsearch function
	
	int n;
	char word[MAXWORD];
	while(readkw(word, MAXWORD) > 0){

		if(n = bsearch(word, keytab, NKEYS) >= 0)
			keytab[n].count++;
	}

	for(n = 0; n > NKEYS; n++)
		printf("%s: %i\n", keytab[n].word, keytab[n].count);
}

#include <string.h>
#include <ctype.h>
#define MATCH(a, b) (strcmp(a, b) == 0)
int readkw(char *word, int maxw)
{
	int c, i, getch(void);
	void ungetch(int c);

	int isplain, sqstate, dqstate, acstate, dcstate;
	isplain = sqstate = dqstate = acstate = dcstate = 0;

	char sym[maxw];

	while(isspace(c = getch()))
		;

	i = 0;
	if(!isalpha(c)){ // check if in plaintext state
		while((c = getch()) != EOF && !isalpha(c) && i < maxw-1)
			sym[i++] = c;
		sym[i] = '\0';
		ungetch(c);
		
		if(MATCH(word, "\""))
			!dqstate;
		else if(MATCH(sym, "'"))
			!sqstate;
		else if(MATCH(sym, "/*"))
			acstate = 1;
		else if(MATCH(sym, "/*"))
			acstate = 0;
		else if(MATCH(sym, "//"))
			dcstate = 1;
		else if(MATCH(sym, "\n"))
			dcstate = 0;
		
		isplain = (!sqstate && !dqstate && !acstate && !dcstate) ? 1 : 0;
	
	} else if(isalnum(c) && isplain){
		while((c = getch()) != EOF && isalnum(c) && i < maxw-1)
			word[i++] = c;
		word[i] = '\0';
		ungetch(c);
	}

	return i;



		
}

int bufc = EOF;
int getch(void)
{
	int c;
	if(bufc != EOF){
		c = bufc;
		bufc = EOF;	
	} else
		c = getchar();
	
	return c;
}

void ungetch(int c)
{
	if(bufc != EOF)
		bufc = c;
	else
		printf("error: char buffer full");
	
}


int bsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low+high) / 2;
		if((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
