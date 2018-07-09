#include <stdio.h>
#define MAXCHAR 128

/* print histogram of char freq. from input */
int main(void)
{
	// clear array
	char freq[MAXCHAR];
	for(int i = 0; i < MAXCHAR; i++)
		freq[i] = 0;

	// record char freq.
	for(int c = 0; (c = getchar()) != EOF; freq[c]++)
		;

	// print histogram
	int col, row;
	for(row = 10; row >= 0; row--){
		printf("%2i", row); // row headings
		for(col = 33; col < MAXCHAR; col++){
			if(freq[col] > 0){
				if(row == 0)
					printf(" %c ", col); // col headings
				else if(freq[col] >= row)
					printf(" - ");
				else
					printf("   ");
			}
		}
		putchar('\n');
	}
}
