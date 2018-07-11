#include <stdio.h>
#define LIM 9999
/* checks a c program for syntax errors such as:
 * unbalanced braces, square braces, curly braces
 * matching single and double quotes
 * escape sequences and comments */
int cmatch(char s[], char c1, char c2);
int main(void)
{
	char text[LIM];
	int c, i;
	for(i = 0; (c = getchar()) != EOF; i++)
		text[i] = c;
	text[i] = '\0';

	printf("Braces: %i\n", cmatch(text, '(', ')'));
	printf("Square braces: %i\n", cmatch(text, '[', ']'));
	printf("Curly braces: %i\n", cmatch(text, '{', '}'));
	printf("Single quotes: %i\n", cmatch(text, '\'', '\''));
	printf("Double quotes: %i\n", cmatch(text, '"', '"'));

}

/* returns remainder if there is an uneven matching of c2 and c1 in string s */
int cmatch(char s[], char c1, char c2)
{
	int i, j, k;
	for(i = j = k = 0; s[i] != '\0'; i++){
		if(!cstate && !sqstate && !dqstate)
			if(s[i] == c1) j++;
			else if(s[i] == c2) k++;
	}
	return (j == k) ? 0 : k - j;
}
