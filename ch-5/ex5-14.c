#include <stdio.h>
#include <string.h>

#define MAXNL 5000 // max number of lines to be sorted
#define MAXLL 999 // maximum line length
char *lineptr[MAXNL]; // pointers to lines

int pgetlar(char *lar[], int maxn, int maxl);
int pgetlin(char *plin, int maxl);


void myqsort(char *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if((nlines = pgetlar(lineptr, MAXNL, MAXLL)) >= 0){
		myqsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*,void*))(numeric ? numcmp : strcmp));
		return 0;
	} else {
		printf("Input too large to sort\n");
		return 1;
	}
}

void myqsort(void *v[], int left, int right,
	int (*comp)(void*, void*))
{
	int i, last;
	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; i++){
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

