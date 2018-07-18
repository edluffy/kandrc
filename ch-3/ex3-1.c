#include <stdio.h>
#define LIM 999
/* write a version of the bin. search (p.58)
 * with only one test inside the loop */

int binsearch(int x, int v[], int n);
int main(void)
{
	int numbers[LIM], i, n;
	for(i = 0; i < LIM-1; i++)
		numbers[i] = i;
	numbers[i] = '\0';
	
	printf("Enter a number to search: ");
	scanf("%i", &n);
	printf("%i", binsearch(n, numbers, i));
}

/* find x in v[0] <= v[1] <= ... <= [n-1] 
 * (ordered list of numbers up to n) */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
 	low = mid = 0;
 	high = n-1;

	while(low <= high && v[mid] != x){
		mid = (low+high) / 2;
		/* printf("L%i - M%i - H%i\n", low, mid, high); for debugging */
		if(x < v[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return (v[mid] == x) ? mid : -1;
}
