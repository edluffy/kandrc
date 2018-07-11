#include <stdio.h>
#define LIM 9999
/* removes all comments from a c program */

void decom(char s[], char clips[]);
int main(void)
{
	char text[LIM], sniptext[LIM];
	int i, c;
	for(i = 0; i < LIM; i++) // clear arrays
		text[i] = sniptext[i] = 0;

	for(i = 0; (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';

	decom(text, sniptext);
	printf("%s", sniptext);
}

/* removes comments from string s */
void decom(char s[], char clips[])
{
	int i, j, dqstate, sqstate, scstate, acstate;
	dqstate = sqstate = scstate = acstate = 0;

	for(i = j = 0; s[i] != '\0'; i++){
		if(s[i] == '"')
			dqstate = !dqstate; // double quotes
		else if(s[i] == '\'')
			sqstate = !sqstate; // single quotes

		if(!dqstate && !sqstate){
			// slashed comments
			if(s[i] == '/' && s[i+1] == '/')
				scstate = 1;
			else if (s[i-1] == '\n')
				scstate = 0;
			// asterixed comments
			if(s[i] == '/' && s[i+1] == '*')
				acstate = 1;
			else if(s[i-2] == '*' && s[i-1] == '/')
				acstate = 0;
		}
		if(!acstate && !scstate)
			clips[j++] = s[i];
	}
	clips[j] == '\0';
}
