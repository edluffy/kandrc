#include <stdio.h>
#define LIM 999
/* write a function escape(s, t) */

void escape(char s[], char t[]);
void descape(char s[], char t[]);
int main(void)
{
	char text1[LIM], text2[LIM], text3[LIM];
	int c, i;
	for(i = 0; i < LIM-1; i++) // clear strings
		text1[i] = text2[i] = text3[i] = 0;

	for(i = 0; (c = getchar()) != EOF; i++)
		text1[i] = c;
	text1[i] = '\0';

	escape(text2, text1);
	descape(text3, text2);
	printf("Escaped:\n%s\nDescaped:\n%s", text2, text3);
}
/* converts chars like newline and tab into '\n' and '\t'
 * as it copies string t to string s */
void escape(char s[], char t[])
{
	int i, j;
	for(i = j = 0; t[i] != '\0'; i++){
		switch(t[i]){
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
		}
	}
	t[i] = '\0';
}
/* converts literal escape sequences int chars
 * as it copies string t to string s */
void descape(char s[], char t[])
{
	int i, j;
	for(i = j = 0; t[i] != '\0'; i++){
		if(t[i] == '\\'){
			switch(t[++i]){
				case 't':
					s[j++] = '\t';
					break;
				case 'n':
					s[j++] = '\n';
					break;
				default:
					s[j++] = '\\';
			}
		} else
			s[j++] = t[i];
	}
}
