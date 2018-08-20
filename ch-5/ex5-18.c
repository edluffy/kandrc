#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { DATATYPE, NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;		// type of last token
char token[MAXTOKEN];	// last token string
char name[MAXTOKEN]; 	// identifier name
char datatype[MAXTOKEN];// data type = char, int, etc
char out[1000]; 	// output string

/* convert declaration to words */
int main(void)
{
	while(gettoken() != EOF){
		if(tokentype == DATATYPE)
			strcpy(datatype, token); // 1st token is datatype
		else
			continue;
		
		out[0] = '\0';
		dcl(); // parse rest of line
		
		if(tokentype != '\n')
			printf("syntax error\n");

		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* parse a declarator */
void dcl(void)
{
	int ns;
	for(ns = 0; gettoken() == '*'; ns++) // = optional *s direct-dcl
		;
	dirdcl();

	while(ns-- > 0)
		strcat(out, " pointer to");
}

/* parse a direct declarator */
void dirdcl(void)
{
	int type;
	if(tokentype == '('){ // = ( dcl )
		dcl();
		if(tokentype != ')')
			printf("error: missing )\n");
	} else if(tokentype == NAME) // = name
		strcpy(name, token);
	else
		printf("error: expected name or ( dcl )\n");

	while((type = gettoken()) == PARENS || type == BRACKETS){
		if(type == PARENS) // = direct-dcl()
			strcat(out, " fucntion returning");
		else { // = direct-dcl[optional size]
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}

#include <ctype.h>
int bufc; // hold pushed back char

/* return next token */
int gettoken(void)
{
	int c, tgetc(void);
	void untgetc(int);
	char *stt;
	char *p = token;

	while(isblank(c = tgetc()))
		;
	if(c == '('){
		if((c = tgetc()) == '('){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else{
			untgetc(c);
			return tokentype = '(';
		}
	} else if(c == '['){
		for(*p++ = c; (*p++ = tgetc()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if(isalpha(c)){
		for(stt = p, *p++ = c; isalnum(c = tgetc()); )
			*p++ = c;
		*p = '\0';
		untgetc(c);
		if(strcmp(stt, "int") == 0 || strcmp(stt, "char") == 0)
			return tokentype = DATATYPE;
		else
			return tokentype = NAME;
	} else
		return tokentype = c;
}

int tgetc(void)
{
	int c;
	c = (bufc) ? bufc : getchar();
	if(bufc) bufc = '\0';
	return c;
}
void untgetc(int c)
{
	if(bufc)
		printf("error: cannot push back char %c\n", c);
	else
		bufc = c;
}
