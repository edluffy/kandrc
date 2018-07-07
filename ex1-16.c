#include <stdio.h>
#define LIM 999
int gline(char s[], int lim);
/* print all input lines > 80 chars */
int main(void)
{
	char line[LIM];
	int c;
	while((c = getchar()) != EOF){
		if(gline(line, LIM) >= 80)
				printf("%s", line);
	}
}

int gline(char s[], int lim)
{
	int i, c;
	for(i = 0; i < lim && (c = getchar()) != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
	return i;
}
