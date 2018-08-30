#include <stdio.h>

void printbasic(char *format, void *arg);
int main(void)
{
	// print arbitrary input in a sensible way
	// handle dec, octal, hexdec, floats
	// handle characters and break long text lines
	
	printbasic("this and that", "nothing");
}

#include <stdlib.h>
#define MAXN 99
void printbasic(char *f, void *arg)
{
	int i;

	i = 0;
	while(f[i++] != '\0'){
		
		// conversion subroutine
		if(f[i] == '%'){
			fconv(f[i], *arg);
		} else
			putchar(f[i]);
	}
}

#include <stdlib.h>
#define MAX 99 // max length

/* formats conversion sequence into string */
void printbasic(char *cs, void *arg)
{
	int nbuf[MAXl], sbuf[MAXL] *stt, fleft, fwidth, fprec;


	// conversion subroutine
	fleft = fwidth = fprec = 0;
	for( ; *cs != '\0'; cs++){
		if(*cs == '%'){
			
			break;
		} else if(*cs == '-'){ // left adjustment
			fleft = 1;
		} else if(isdigit(*cs)){ // min field width
			for(stt = nbuf; isdigit(*cs); cs++, nbuf++)
				*nbuf = *cs;
			*nbuf = '\0';
			fwidth = atoi(stt);
		} else if(*cs == '.'){ // precision
			for(cs++, stt = nbuf; isdigit(*s); cs++, nbuf++)
				*nbuf = *cs;
			*nbuf = '\0';
			fprec = atoi(stt);
		}else if(isalpha(*cs)){ // format
			switch(*cs)
			{
				case 'd':
				case 'i':
					itoa(arg, *sbuf);
					break;
				case 'o':
					otoa(arg, *sbuf);
					break;
				case 'x':
				case 'X':
					htoa(arg, *sbuf);
					break;
				default: 
					printf("unknown conversion char: %c\n", *cs);
					break;
			}
			break;	
		}else
			printf("unknown conversion sequence: %c\n", *cs);
	}


}
