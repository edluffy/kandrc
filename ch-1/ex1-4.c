#include <stdio.h>
#define UP 300
#define LOW 0
#define STEP 20

/* my temp converter */
int main(void)
{
	printf("Fahr Celsius\n");
	for(float fahr = LOW; fahr <= UP; fahr += STEP)
		printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}
