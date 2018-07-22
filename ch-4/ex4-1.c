#include <stdio.h>
#include <ctype.h>
#define LIM 999
/* write the function strrindex(s,t) */

int getln(char s[], int lim);
int strrindex(char s[], char t[]);
int strcop(char s1[], char s2[]);

/* returns position of rightmost occurence 
 * of last line in current line */
int main(void)
{
	char line[LIM], oldline[LIM];

	while(getln(line, LIM) > 0){
		printf("Pos: %i\n", strrindex(line, oldline));
		strcop(line, oldline);
	}
}

/* gets line of input and return its length */
int getln(char s[], int lim)
{
	int i, c;
	for(i = 0; (c = getchar()) != EOF && i < lim && c != '\n'; i++)
		s[i] = c;
	if(c == '\n') // keep newline
		s[i++] = c;	
	s[i] = '\0';
	return i;
}

/* returns pos. of rightmost occurence of t in s, or -1 if there is none */
int strrindex(char s[], char t[])
{
	int i, j, pos;
	for(i = 0, pos = -1; s[i] != '\0'; i++){
		for(j = 0; t[j] != '\0'; j++){
			if(!isspace(s[i]) && s[i] == t[j]){ 
				pos = i;
				break;
			}
		}
	}
	return pos;
}

/* copies s1 to s2 and returns length */
int strcop(char s1[], char s2[])
{
	int i;
	for(i = 0; s1[i] != '\0'; i++)
		s2[i] = s1[i];
	s2[i] = '\0';
	return i;
}
