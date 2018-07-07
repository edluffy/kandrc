#include <stdio.h>
#define UP 300
#define LOW 0
#define STEP 20

int main(void)
{
	printf("Fahr Celsius\n");
	for(float fahr = UP; fahr >= LOW; fahr -= 20)
		printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
