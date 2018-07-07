#include <stdio.h>
#define UPPER 200
#define LOWER 0
#define STEP 20
/* temp conversion rewritten as function */
float ftoc(float fahr);
int main(void)
{
	printf("Fahr\tCelsius\n");
	for(float fahr = LOWER; fahr <= UPPER; fahr+=STEP)
		printf("%3.0f\t%3.0f\n", fahr, ftoc(fahr));
}

float ftoc(float fahr)
{
	return (fahr - 32.0) * (5.0/9.0);	
}
