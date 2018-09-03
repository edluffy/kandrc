#include <stdio.h>

int minscanf(char *fmt, ...);
int main(void)
{
}

#include <ctype.h>
#include <stdarg.h>
int minscanf(char *fmt, ...)
{
	char *p;
	va_list ap;

	int ival;
	double fval;
	char *sval;

	va_start(ap, fmt);

	for(p = fmt; *p; p++){
		if(*p != '%' || isblank(*p)){
			scanf("%*c");
			continue;
		}

		switch(*++p)
		{
			case 'd':
			case 'i':
				ival = va_arg(ap, int);
				scanf("%i", ival);
				break;
			case 'f':
				fval = va_arg(ap, double);
				scanf("%f", fval);
			        break;
			case 's':
				sval = va_arg(ap, char *);
				scanf("%s", sval);
				break;
			default:
				printf("unknown char: %c", *p);
				break;
		}
	}

	va_end(ap);
}
