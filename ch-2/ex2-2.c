#include <stdio.h>
#define LIM 999
/* rewrite given loop without using
 * && or || operators */
int main(void)
{
	int i, c;
	char s[LIM];

	/* given loop
	for(i = 0; i<LIM-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c; */
	
	for(i = 0; i < LIM-1; ++i){
		if((c = getchar()) == '\n')
			break;
		if(c == EOF)
			break;
		s[i] = c;	
	}

	printf("%s", s);
}
