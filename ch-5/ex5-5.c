#include <stdio.h>
#define LIM 999
void pstrncpy(char *s, char *t, int n);
void pstrncat(char *s, char *t, int n);
int pstrncmp(char *s, char *t, int n);

/* write versions of strncpy, strncat and strncmp using pointers */
int main()
{
	int num;
	char str1[LIM], str2[LIM];

	printf("Enter: 'str1 str2 num'\n");
	scanf("%s %s %i", str1, str2, &num);

	printf("%i\n", pstrncmp(str1, str2, num));
	printf("str1: %s\tstr2: %s\n", str1, str2);
}

/* copy the first n chars of string t to s */
void pstrncpy(char *s, char *t, int n)
{
	for(int i = 0; i < n; s++, t++, i++)
		*s = *t;
}

/* concat. first n chars of string t to end of s */
void pstrncat(char *s, char *t, int n)
{
	for( ; *s; s++)
		;
	for(int i = 0; i < n; s++, t++, i++)
		*s = *t;
	*s = '\0';
}

/* compare s and first n chars of t, return difference */
int pstrncmp(char *s, char *t, int n)
{
	for(int i = 0 ; i < n && *s == *t; s++, t++, i++)
		if(*s == '\0') return 0;
	return *s - *t;

}
