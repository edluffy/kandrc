#include <stdio.h>
#define LIM 999

/* print histogram of word length from input */
int main(void)
{
	// clear array
	char len[LIM];
	for(int i = 0; i < LIM; i++)
		len[i] = 0;

	// record word length
	int c, j;
	for(c = j = 0; (c = getchar()) != EOF; j++){
		if(c == ' ' || c == '\t' || c == '\n'){
			len[j]++;
			j = 0;
		}
	}

	// print histogram
	int col, row;
	for(row = 20; row >= 0; row--){
		printf("%2i", row); // row headings
		for(col = 1; col <= 10; col++){
			if(row == 0)
				printf(" %i ", col); // col headings
			else if(len[col] >= row)
				printf(" - ");
			else
				printf("   ");
		}
		putchar('\n');
	}
}
