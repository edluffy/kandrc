#include <stdio.h>
#define LIM 999
/* reverses string s */
void reverser(char s[], int len);
int main(void)
{
	char string[LIM];
	int i, c;

	for(i = 0; (c = getchar()) != EOF; i++)
		string[i] = c;
	reverser(string, LIM);
	printf("%s\n", string);
}

void reverser(char s[], int len)
{
	char olds[len];
	int i, j, nl;
	i = j = 0;

	for(i = 0; s[i] != '\0'; i++)
		olds[i] = s[i];
	while(i >= 0)
		s[j++] = olds[i--];
	       	
}
