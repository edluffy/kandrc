#include <stdio.h>
#define LIM 9999
/* checks a c program for syntax errors such as:
 * unbalanced braces, square braces, curly braces
 * matching single and double quotes
 * escape sequences and comments */
int cmatch(char s[], char c1, char c2);
int isplain(char s[], int pos);
int main(void)
{
	char text[LIM], stext[LIM];
	int c, i, j;
	for(i = j = 0; (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';

	for(i = 0; text[i] != '\0'; i++)
		if(!isplain(text, i)) stext[j++] = text[i];
	stext[j] = '\0';
	printf("Syntax imbalances: \n");	
	printf("Braces: %i\n", cmatch(stext, '(', ')'));
	printf("Square braces: %i\n", cmatch(stext, '[', ']'));
	printf("Curly braces: %i\n", cmatch(stext, '{', '}'));
	printf("Single quotes: %i\n", cmatch(stext, '\'', '\''));
	printf("Double quotes: %i\n", cmatch(stext, '"', '"'));

}

/* returns remainder if there is an uneven matching of c2 and c1 in string s */
int cmatch(char s[], char c1, char c2)
{
	int i, j, k;
	for(i = j = k = 0; s[i] != '\0'; i++){
		if(s[i] == c1) j++;
		if(s[i] == c2) k++;
	}
	return (c1 == c2) ? j % 2 : k-j;
}
/* returns true if char at s[pos] is in quoted text or a comment */
int isplain(char s[], int pos)
{
	int i, dqstate, sqstate, scstate, acstate;
	dqstate = sqstate = scstate = acstate = 0; // true when inside
	for(i = 0; i <= pos; i++){

		if(s[i-1] == '"' && !dqstate) // quote handling
			dqstate = 1;
		if(s[i] == '"' && s[i-1] != '\\' && dqstate)
			dqstate = 0;
		if(s[i-1] == '\'' && !sqstate) 
			sqstate = 1;
		if(s[i] == '\'' &&  s[i-1] != '\\' && sqstate)
			sqstate = 0;

		if(!dqstate && !sqstate){ // comment handling
			if(s[i] == '/' && s[i+1] == '/') 
				scstate = 1;
			else if(s[i] == '\n') 
				scstate = 0;
			if(s[i] == '/' && s[i+1] == '*') 
				acstate = 1;
			else if(s[i-2] == '*' && s[i-1] == '/') 
				acstate = 0;
		}	
	}

	return (dqstate || sqstate || scstate || acstate);
}
