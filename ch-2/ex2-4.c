#include <stdio.h>
#define LIM 999
/* alternate version of squeeze from p.47 */

void squeeze(char s1[], char s2[]);
int main(void)
{
	char orange[LIM], juicer[LIM];
	int i, c;

	printf("Enter string: ");
	for(i = 0; (c = getchar()) != '\n'; i++)
		orange[i] = c;
	orange[i] = '\0';

	printf("Enter string to compare: ");
	for(i = 0; (c = getchar()) != '\n'; i++)
	       juicer[i] = c;
	juicer[i] = '\0';	
	
	squeeze(orange, juicer);
	printf("Squeezed string: %s", orange);
}

/* delete all chars in s1 that match any char in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k, match;
	for(i = j = 0; s1[i] != '\0'; i++){
		for(k = match = 0; s2[k] != '\0'; k++)
			if(s1[i] == s2[k]) match = 1;
		if(!match) s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
