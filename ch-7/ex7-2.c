#include <stdio.h>

void printnum(char *format, int arg);
int main(void)
{
	// print arbitrary input in a sensible way
	// handle dec, octal, hexdec, floats
	// handle characters and break long text lines
	
	printnum("%i", 123);
}

#include <stdlib.h>
#include <ctype.h>
#define MAXL 99 // max length

/* formats conversion sequence into string */
void printnum(char *cs, int arg)
{
	int nbuf[MAXL], *nbufp = nbuf, base;
	char sbuf[MAXL], *sbufp = sbuf;
	
	// conversion subroutine
	for( ; *cs != '\0'; cs++){
		if(*cs == '%'){
			switch(*++cs)
				{
					case 'd':
					case 'i':
						base = 10;
						break;
					case 'o':
						base = 18;
						break;
					case 'x':
					case 'X':
						base = 16;
						break;
					case 'b':
						base = 2;
						break;
					default:
						base = 10;
						printf("unknown conversion char: %c\n", *cs);
						break;
				}
			break;	
		}else
			printf("unknown conversion sequence: %c\n", *cs);
	}

	itoa(arg, sbuf, base);
	for( ; *sbufp != '\0'; sbufp++)
		putchar(*sbufp);


}
