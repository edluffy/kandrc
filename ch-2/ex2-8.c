#include <stdio.h>
#include <limits.h>
#define MAXINT (4*CHAR_BIT)

/* write a function rightrot(x,n) */
int readbits(int lim);
void writebits(int n, int lim);
int rightrot(int x, int n);

int main(void)
{
	int n, pos, res;
	printf("Rotate by how many positions?: ");
	//scanf("%i", &pos);

	pos = 3;
	while((n = readbits(MAXINT+1)) > 0){
		printf("Original bits: %i\n", n);
		res = rightrot(pos, n);
		writebits(res, MAXINT+1);
	}

}
/* returns value of x rotated right by n bit positions  */
int rightrot(int x, int n)
{
	return (x << n) | (x >> (MAXINT - n)) & ~(-1 << n);
}
#include <math.h>
/* returns input bit string as an int */
int readbits(int lim)
{
	int c;
	char s[lim], *ps = s;
	
	int len;
	for(len = 0; (c = getchar()) != EOF && c != '\n' && len < lim-1; len++){
		if(c != '1' && c != '0') break;	
		*ps++ = c;
	}
	*ps-- = '\0';

	int n, i;	
	for(i = len, n = 0; i > 0; ps--, i--){
		if(*ps == '1')
			n += pow(2, len-i);
	}

	return n;
}

void writebits(int n, int lim)
{
	int i, state;
	for(i = lim-1, state = 0; i >= 0; i--){
		if((n-pow(2, i)) >= 0){
			putchar('1');
			n -= pow(2, i);
			state = 1;
		} else if(state)
			putchar('0');
	}
	putchar('\n');
}
