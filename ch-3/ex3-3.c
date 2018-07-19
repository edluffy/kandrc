#include <stdio.h>
#define LIM 999
/* write a function expand(s1, s2) */

void expand(char s1[], char s2[]);
int main(void)
{
	char string1[LIM], string2[LIM];
	int c, i;
	for(i = 0; i < LIM-1; i++) // clear strings
		string1[i] = string2[LIM] = 0;

	printf("Enter string: ");
	for(i = 0; (c = getchar()) != '\n'; i++)
		string1[i] = c;
	string1[i] = '\0';
	
	expand(string1, string2);
	printf("%s", string2);
}
/* expands notation e.g 'a-z' in s1 into a 
 * complete list e.g. 'abc...xyz' in s2 
 * works backwards too */
void expand(char s1[], char s2[])
{
	int i, j, k, start, end;
	for(i = k = 0; s1[i] != '\0'; i++){
		if((start = s1[i-1]) != '-' && s1[i] == '-' && (end = s1[i+1]) != '-')
			for(j = start+1; j != end; (start < end) ? j++ : j--) s2[k++] = j;
		else
			s2[k++] = s1[i];
	}
	s2[k] = '\0';
}
