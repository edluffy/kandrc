#include <stdio.h>
#include <ctype.h>
#define LIM 999
/* extend atof to handle scientific notation */

double atof(char s[]);
int main(void)
{
	char nstring[LIM];
	printf("Enter a number string: ");
	scanf("%s", nstring);

	printf("%f", atof(nstring));
}

/* converts string s to double, handles the form 123.45e-6 */
double atof(char s[])
{
	int i, sign, esign, n, k;
	double val, pow, exp;
	i = 0;

	while(isspace(s[i])) i++;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+') i++;

	for(val = 0.0; isdigit(s[i]); i++) // integer
		val = val*10.0 + (s[i] - '0');

	if(s[i] == '.') i++; // decimal
	for(pow = 1.0; isdigit(s[i]); i++){
		val = val*10.0 + (s[i] - '0');
		pow *= 10.0;
	}

	// signed exponent handling
	if(s[i] == 'e' || s[i] == 'E') i++;
	esign = (s[i] == '-') ? 0 : 1;
	if(s[i] == '-' || s[i] == '+') i++;
	
	for(n = 0; isdigit(s[i]); i++)
		n = n*10 + (s[i] - '0');
	for(k = 0, exp = 1.0; k < n; k++)
	       exp = (esign) ? exp*10.0 : exp/10.0;	

	return (sign * val / pow) * exp;
}
