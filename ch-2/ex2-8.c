#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXINT (4*CHAR_BIT)

/* write a function rightrot(x,n) */
int readbits(char *s, int lim);
int rightrot(int x, int n);

char *itobs(int n);
int bstoi(char s[]);

int main(void)
{
	char bitstr[MAXINT];
	int bits;

//	printf("Enter a string of bits: ");
//	scanf("%s", bitstr);
	
//	printf("As a number: %i\n", bits = bstoi(bitstr));
	printf("Back as a string: %s\n", itobs(5));


}
/* returns value of x rotated right by n bit positions  */
int rightrot(int x, int n)
{
	int mask;	
}

#include <ctype.h>
/* collects input as string of bits only */
int readbits(char *s, int lim)
{
	int c, l;
	for(l = 0; (c = getchar()) != EOF && c != '\n' && l < lim-1; l++)
		if(c == '1' || c == '0') 
			*s++ = c;	
	*s = '\0';

	return l;
}

#include <string.h>
#include <math.h>
/* converts integer to string of bits */
char *itobs(int n)
{
	int i = MAXINT;
	char s[MAXINT+1];
	s[MAXINT+1] = '\0';
	for(i = MAXINT; i > 0; i--){
		if(n-pow(2, i) > 0){
			n -= pow(2, i);
			s[i] = '1';
		}else
			s[i] = '0';
	}

	char *p = malloc(i*sizeof(char));
	strcpy(p, s);
	return p;
}

/* converts bit string to integer value */
int bstoi(char s[])
{
	int i, n;
	strrev(s);
	for(i = n = 0; s[i] != '\0'; i++)
		if(s[i] == '1') 
			n += pow(2, i);
	return n;
}
