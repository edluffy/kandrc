#include <stdio.h>
#include <math.h>
#define LIM 999
// converts n into base b rep. in string s
void itob(int n, char s[], int b);
int main(void)
{
	char string[LIM]; // clear string
	for(int i = 0; i < LIM; i++)
		string[i] = 0;
	itob(25, string, 2);
	printf("%s", string);
}
void itob(int n, char s[], int b)
{

}
