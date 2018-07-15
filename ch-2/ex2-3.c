#include <stdio.h>
#include <math.h>
#define LIM 999
/* write a function htoi(s) which converts
 * a string of hex digits into base ten */

int htoi(char s[]);
int ctoi(char c);
int main(void)
{
	char hexstr[LIM];
	int i, c;
	printf("Hexadecimal string to convert: ");
	for(int i = 0; (c = getchar()) != '\n'; i++)
		hexstr[i] = c;
	printf("Integer form: %i", htoi(hexstr));
}

/* converts string of hex into base ten */
int htoi(char s[])
{
	int i, j, start, sum;
	char c;

	// skip 0x or 0X
	start = s[0] == '0' && s[1] == 'x' || s[1] == 'X' ? 2 : 0;
	for(i = 0; s[i] != '\0'; i++); // find end
	
	for(j = sum = 0; i > start; j++, i--){
		c = (s[i-1] >= '0' && s[i-1] <= '9') ? '0' : 'W'; 
		sum += (s[i-1]-c) * pow(16, j);
	}

	return sum;
}

