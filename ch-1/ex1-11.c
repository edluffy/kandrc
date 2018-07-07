#include <stdio.h>

/* wordcount program snippet */
int main(void)
{
	int c;
	int nw = 0;
	int state = 0; // true when in word
	while((c = getchar()) != EOF){
		if( c == ' ' || c == '\n' || c == '\t')
			state = 0; // outside word
		else if(!state){
			state = 1; // inside word
			nw++;
		}
	}
	printf("Wordcount: %i", nw);
}
