#include <stdio.h>

// replace tabs, backspaces, backslashes with \t, \b, \\;
int main(void)
{
	int c;
	while((c = getchar()) != EOF){
		if(c == '\t')
			printf("\\t");
		else if(c == '\b')
			printf("\\b");
		else if(c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
