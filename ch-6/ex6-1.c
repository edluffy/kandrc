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
//		printf("|%s|\n", word);
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
	int c, i;
	
	while(isblank(text[pos]))
		pos++;
	
	i = 0;
	if(text[pos] != '\0' && !isalnum(text[pos]) && text[pos] != '_')
		word[i++] = text[pos++];
	else if(isalnum(text[pos]) || text[pos] == '_'){
		while(isalnum(text[pos]) || text[pos] == '_' && i < maxw-1)
				word[i++] = text[pos++];
	}
	word[i] = '\0';

	return i;
}

void getplain(char *ptext, int maxt)
{
	int plain, ppstate, sqstate, dqstate, acstate, dcstate;
	ppstate = sqstate = dqstate = acstate = dcstate = 0;	

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
		else if(text[j] == '#')
			ppstate = 1;
		else if(text[j] == '\n')
			dcstate = ppstate = 0;
		else if(text[j] == '"')
			dqstate = !dqstate;
		else if(text[j] == '\'')
			sqstate = !sqstate;
		plain = (acstate || dcstate || dqstate || sqstate || ppstate) ? 0 : 1;

		if(plain)
			*ptext++ = text[j];
	}
	*ptext = '\0';

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
