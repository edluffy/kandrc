#include <stdio.h>
void minprintf(char *fmt, ...);

int main(void)
{
	minprintf("%i", 123);
}

#include <stdarg.h>
void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for(p = fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p)
		{
			case 'd':
			case 'i':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'o':
				ival = va_arg(ap, int);
				printf("%o", ival);
				break;
			case 'X':
			case 'x':
				ival = va_arg(ap, int);
				printf("%x", ival);
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 'c':
			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
