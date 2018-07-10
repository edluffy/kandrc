#include <stdio.h>
#define LIM 999
#define LINELEN 30
/* folds long input lines into two or more shorter lines */

int getln(char ln[]);
int isABC(char c);
int main(void)
{
	char line[LIM], fstring[LIM];
	int i, j, len;
	j = 0;
	while((len = getln(line)) >= 1){
		for(i = 0; i < len; i++){
			if(i % LINELEN == 0 && i >= LINELEN){ // fold line
				if(isABC(line[i]) && isABC(line[i-1]))
					fstring[j++] = '-';
				fstring[j++] = '\n';
			}
			fstring[j++] = line[i];
		}
		fstring[j++] = '\n';
	}
	fstring[j] = '\0';
	printf("%s", fstring);
}
/* gets line of input and returns length */
int getln(char ln[])
{
	int i, c;
	for(i = 0; i < LIM; i++) // clear line
		ln[i] = 0;

	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
			ln[i] = c;
	
	return i;
}
/* returns 1 if char is in alphabet */
int isABC(char c)
{
	if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}
