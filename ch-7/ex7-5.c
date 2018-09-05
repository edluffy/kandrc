#include <stdio.h>

/* rudimentary two operand calculator */
int main(void)
{

	double op1, op2, v;
	char sym;

	v = 0;
	while(scanf("%lf %lf %c", &op1, &op2, &sym) == 3){
		switch(sym)
		{
			case '+':
				v = op1 + op2;
				break;
			case '-':
				v = op1 - op2;
				break;
			case '*':
				v = op1 * op2;
				break;
			case '/':
				v = op1 / op2;
				break;
			case '%':
				v = (int)op1 % (int)op2;
				break;
			default:
				printf("error: unknown sym - %c", sym);
				break;
		}
		printf("\t%lf\n", v);
	}

	return 0;
}

