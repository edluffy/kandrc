#include <stdio.h>
#define LIM 999
#define TABSTOP 4

/* entab: replaces strings of blanks with strings
 *  of tabs and blanks to reach same spacing. */
void entab(char s[], char ns[]);
int main(void)
{
	char s[LIM], ns[LIM];
	int c, i;
	for(i = 0; i < LIM; i++) // clear strings
		s[i] = ns[i]  = 0;

	for(i = 0; (c = getchar()) != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
	entab(s, ns);
	printf("Old string:%s\nNew string:%s\n", s, ns);
}
void entab(char s[], char ns[])
{
	int i, j, nblanks;
	for(i = j = nblanks = 0; s[i] != '\0'; i++){
		if(s[i] == ' ') // count blanks
			nblanks++;
		else if(s[i] == '\t')
			nblanks += TABSTOP;
		else{
			while(nblanks > 0){ // replace blanks
				if(nblanks - TABSTOP >= 0){
					ns[j++] = 't';
					nblanks -= TABSTOP;
				} else{
					ns[j++] = 'b';
					nblanks--;
				}
			}
			ns[j++] = s[i]; 
		}
	}
	ns[j] == '\0';
}
/* note: when either a tab or a single blank would suffice to
 * reach a tab stop, tabs are given preference. *\
