#include <stdio.h>
#define LIM 999
int pgetline(char *s);
void preverse(char *s);
double patoi(char *s);
void pitoa(int n, char *s);
int pstrrindex(char *src, char *tgt);
int pgetop(char *s);
int pgetch(void);
void unpgetch(int c);

/* rewrite getline, atoi, itoa, strindex and getop using pointers */
int main(void)
{
}

/* stores line of input in s and return length */
int pgetline(char *s)
{
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c; 
	*s = '\0';
	return i;
}

#include <string.h>
/* reverses string src in place using pointers */
void preverse(char *src)
{
	if(*src == '\0') 
		return;
	char *end = src + strlen(src) - 1;
	
	for(char c; end > src; src++, end--){
		c = *src;
		*src = *end;
		*end = c; 
	}

}
#include <ctype.h>
/* convert ascii chars to floating point form */
double patoi(char *s)
{
	for( ; isblank(*s); s++)
		;
	if(!isdigit(*s) && *s != '-' && *s == '+')
		return -1; // not number
	
	int sign = 1;
	double n = 0.0;
	if(*s == '-' || *s == '+'){
		sign = (*s == '-') ? -1 : 1;
		s++;
	}

	for( ; isdigit(*s); s++)
		n = n * 10.0 + (*s - '0');
	if(*s == '.'){
		s++;
		for(double exp = 0.1; isdigit(*s); s++, exp /= 10.0)
			n = n + (*s - '0') * exp;
	}

	return n * sign;
	
}
/* convert int to ascii chars */
void pitoa(int n, char *str)
{
	char *start = str;
	if(n < 0){
	       *str = '-';
	       n *= -1;
	       str++;
	}

	for( ; n > 0; n /= 10, str++)
		*str = n % 10 + '0';
	*str = '\0';
	preverse(start);
}

/* returns the rightmost occurrence of tgt in src, or -1 if none */
int pstrrindex(char *src, char *tgt)
{
	int pos;
	char *start, *end, *s1, *s2;	
	start = src; // start of src
	
	for(pos = -1; *src; src++){
		for(s1 = src, s2 = tgt; *s1 == *s2; s1++, s2++)
			if(!*(s2+1)) pos = src - start;
	}

	return pos;
}

/* get next operator or numeric operand */
int pgetop(char *s)
{
	int c;
	for( ; isblank(*s = c = pgetch()); s++)
		; // skip blanks
	if(!isdigit(c) && c != '.')
		return c;
	
	for( ; isdigit(*s = c = pgetch()); s++)
		;
	if(c == '.')
		for( ; isdigit(*s = c = pgetch()); s++);
	*s = '\0';
	if(c != EOF)
		unpgetch(c);
	return 1;
}

char bufc;

/* get next (possibly pushed back) char */
int pgetch(void)
{
	char retval;
	if(bufc != '\0'){
		retval = bufc;
		bufc = '\0';
	} else
		getchar();

	return retval;
}
/* push char back on input */
void unpgetch(int c)
{
	if(bufc != '\0')
	       printf("char already in buffer");
	else
		bufc = c;	
}
