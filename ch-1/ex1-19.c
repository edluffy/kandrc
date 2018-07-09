#include <stdio.h>
#define LIM 999

/* input reverser */
void rev(char s[], int len);
int main(void)
{
	char string[LIM];
	int i, c;

	for(i = 0; (c = getchar()) != '\n'; i++)
		string[i] = c;
	string[i] = '\0';

	rev(string, i-1);
	printf("%s\n", string);
}

/* reverses string up to pos */
void rev(char s[], int pos)
{
	int i, j;
	char c;
	for(i = 0, j = pos; i <= pos/2; i++, j--){
		c = s[i]; 
		s[i] = s[j];
		s[j] = c;
	}
}
