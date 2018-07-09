#include <stdio.h>
/* replaces string of blanks from input with a single blank */
int main(void)
{
	int c;
	int flag = 0; // true after a blank
	while((c = getchar()) != EOF){
		if(c == ' ' && !flag){
			putchar(c);
			flag = 1;
		} else if(c != ' '){
			putchar(c);
			flag = 0;
		}
	}	
}
