#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};


int mgettoken(void);
int tokentype;		// type of last token
char token[MAXTOKEN];	// last token string
char name[MAXTOKEN]; 	// identifier name
char datatype[MAXTOKEN];// data type = char, int, etc
char out[1000]; 	// output string

/* convert word description to declaration */
int main(void)
{
	int type;
	char temp[MAXTOKEN];

	int i = 0;
	while(mgettoken() != EOF){
		strcpy(out, token);
		while((type = mgettoken()) != '\n'){
			switch(type)
			{
				case PARENS: case BRACKETS:
				      strcat(out, token);
				      break;
				case '*':
				      sprintf(temp, "(*%s)", out);
				      strcpy(out, temp);
				      break;
				case NAME:
				      sprintf(temp, "%s %s", token, out);
				      strcpy(out, temp);
				      break;
				default:
				      break;

			}
		}
		printf("%s\n", out);
	}
	return 0;
}

#include <ctype.h>

/* return next token */
int mgettoken(void)
{
	int c, mgetc(void);
	void unmgetc(int);
	char *p = token;

	while((c = mgetc()) == ' ' || c == '\t')
		;
	if(c == '('){
		if((c = mgetc()) == '('){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else{
			unmgetc(c);
			return tokentype = '(';
		}
	} else if(c == '['){
		for(*p++ = c; (*p++ = mgetc()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if(isalpha(c)){
		for(*p++ = c; isalnum(c = mgetc()); )
			*p++ = c;
		*p = '\0';
		unmgetc(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

#define BUFSIZE 999
char buf[BUFSIZE];
int bufp;
int mgetc(void)
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}
void unmgetc(int c)
{
	if(bufp >= BUFSIZE)
		printf("error: cannot push back char %c\n", c);
	else
		buf[bufp++] = c;
}
