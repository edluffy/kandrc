#include <stdio.h>
#define MAXTEXT 999
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

void getplain(char *ptext, int maxt);
int readkw(char *text, char *w, int maxw);
int bsearch(char *word, struct key tab[], int n);

int main(void)
{
	// count occurences of each c keyword
	// struct of keywords
	// function that gets keywords
	// binsearch function
	
	int n;
	char text[MAXTEXT], word[MAXWORD];

	getplain(text, MAXTEXT);

	while(readkw(text, word, MAXWORD) > 0){
		printf("|%s|", word);
		if((n = bsearch(word, keytab, NKEYS)) >= 0)
			keytab[n].count++;
	}

	for(n = 0; n < NKEYS; n++)
		printf("%s: %i\n", keytab[n].word, keytab[n].count);
}

#include <ctype.h>
int pos;
int readkw(char *text, char *word, int maxw)
{
	int c, i, getch(void);
	void ungetch(int c);

	
	while(text[pos] != '\0' && isblank(text[pos]))
		pos++;
	i = 0;
	while(text[pos] != '\0' && i < maxw){
		if(isblank(text[pos]) || text[pos] == '\n') continue;
		word[i++] = text[pos++];
	}
	word[i] = '\0';

	return i;
}

void getplain(char *ptext, int maxt)
{
	int plain, sqstate, dqstate, acstate, dcstate;
	sqstate = dqstate = acstate = dcstate = 0;	

	char text[maxt];
	int c, i, j;
	
	for(i = 0; (c = getchar()) != EOF && i < maxt; i++)
		text[i] = c;
	text[i] == '\0';
		
	for(j = 0, plain = 1; j < i; j++){
		// check if plaintext
		if(text[j] == '/' && text[j+1] == '*')
			acstate = 1;
		else if(text[j-2] == '*' && text[j-1] == '/')
			acstate = 0;
		else if(text[j] == '/' && text[j+1] == '/')
			dcstate = 1;
		else if(text[j] == '\n')
			dcstate = 0;
		else if(text[j] == '"')
			dqstate = !dqstate;
		else if(text[j] == '\'')
			sqstate = !sqstate;
		plain = (acstate || dcstate || dqstate || sqstate) ? 0 : 1;

		if(plain)
			*ptext++ = text[j];
	}
	*ptext = '\0';

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
		printf("error: char buffer full");
	else
		bufc = c;	
}

#include <string.h>
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
