#include <stdio.h>
#define LIM 999
/* write the function any(s1, s2)
 * (similar to std lib function strpbrk) */

int any(char s1[], char s2[]);
int main(void)
{
	int i, c;
	char string1[LIM], string2[LIM];

	printf("Enter first string: ");
	for(i = 0; (c = getchar()) != '\n'; i++)
		string1[i] = c;
	string1[i] = '\0';

	printf("Enter second string: ");
	for(i = 0; (c = getchar()) != '\n'; i++)
		string2[i] = c;
	string2[i] = '\0';

	printf("Pos. in first string of first match: %i", any(string1, string2));
}
/* returns the first location in s1 where:
 *  any c from s2 occurs, or -1 if no matches */
int any(char s1[], char s2[])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0'; j++)
			if(s1[i] == s2[j]) return i;
	}
	return -1;
}
