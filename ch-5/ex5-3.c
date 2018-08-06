#include <stdio.h>

/* write a pointer version of strcat */
void pstrcat(char *s, char *t);
int main(void)
{
	char string1[] = "an apple and";
	char string2[] = " a banana";

	pstrcat(string1, string2);
	printf("%s", string1);
}

/* copies t to the end of s */
void pstrcat(char *s, char *t)
{
	while(*s++)
		;
	for(s -= 1; *s = *t; s++, t++)
		;
	*s = '\0';
}
