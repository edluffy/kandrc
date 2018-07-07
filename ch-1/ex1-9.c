#include <stdio.h>

int main(void)
{
	int c;
	int flag = 0; // true after a blank
	while((c = getchar()) != '\n'){
		if(c == ' ' && !flag){
			putchar(c);
			flag = 1;
		} else if(c != ' '){
			putchar(c);
			flag = 0;
		}
	}	
}
