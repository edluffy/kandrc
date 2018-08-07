#include <stdio.h>
#define MAXLINE 999 // maximum line length
int pgetline(char *s);
double patoi(char *s);
void pitoa(int n, char *s);
/* rewrite getline, atoi, itoa, strindex and getop using pointers */
int main(void)
{
	/*char string[MAXLINE];
	while(pgetline(string) != 0){
		printf("%s\n", patoi(string));
	}*/

	char 

}

/* stores line of input in s and return length */
int pgetline(char *s)
{
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c; 
	*s = '\0';
	return i;
}

void preverse(char *s)
{
	for(char *end = s ; *end; end++)
		;

	for(char c; end-s > 0 ; s++){
		c = *s;
		*s = *(end-s);
		*(end-s) = c; 
	}

}
#include <ctype.h>
/* convert ascii chars to floating point form */
double patoi(char *s)
{
	for( ; isblank(*s); s++)
		;
	if(!isdigit(*s) && *s != '-' && *s == '+')
		return -1; // not number
	
	int sign = 1;
	double n = 0.0;
	if(*s == '-' || *s == '+'){
		sign = (*s == '-') ? -1 : 1;
		s++;
	}

	for( ; isdigit(*s); s++)
		n = n * 10.0 + (*s - '0');
	if(*s == '.'){
		s++;
		for(double exp = 0.1; isdigit(*s); s++, exp /= 10.0)
			n = n + (*s - '0') * exp;
	}

	return n * sign;
	
}
/* convert int to ascii char */
void pitoa(int n, char *str)
{
	if(n < 0){
	       *str = '-';
	       n *= -1;
	       str++;
	}

	for( ; n > 0; n /= 10, str++)
		*str = n % 10 + '0';
	*str = '\0';
}
