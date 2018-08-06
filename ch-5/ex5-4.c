#include <stdio.h>

/* write the function strend(s, t) */
int strend(char *s, char *t);
int main(void)
{
	char str1[] = "milkshake";
	char str2[] = "shake";
	char str3[] = "cow";
	
	printf("Does '%s' occur at the end of '%s'?, %s!\n", str2, str1, strend(str1, str2) ? "Yes" : "No");
	printf("Does '%s' occur at the end of '%s'?, %s!\n", str3, str1, strend(str1, str3) ? "Yes" : "No");
}

/* returns 1 if str t occurs at end of str s, 0 if otherwise */
int strend(char *s, char *t)
{
	while(*s) s++;
	while(*t) t++;

	while(*s == *t) s--, t--;
	return (*t) ? 0 : 1;

}
