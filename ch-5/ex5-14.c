#include <stdio.h>
#include <string.h>

#define MAXNL 5000 // max number of lines to be sorted
#define MAXLL 999 // maximum line length
char *lineptr[MAXNL]; // pointers to lines

int sreadlines(char *lar[], int maxn, int maxl);
int sgetline(char *plin, int maxl);


void myqsort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if((nlines = sreadlines(lineptr, MAXNL, MAXLL)) >= 0){
		myqsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*,void*))(numeric ? numcmp : strcmp));
		for(int i = 0; nlines--; i++)
			printf("%s\n", lineptr[i]);
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
	myqsort(v, left, last-1, comp);
	myqsort(v, last+1, right, comp);
}

#include <stdlib.h>

int numcmp(const char *s1, const char *s2)
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

#include <string.h>
char *salloc(int n);

int sreadlines(char *plar[], int maxn, int maxl)
{
	int space, nl;
	char line[maxl], *p;

	nl = 0;
	while((space = sgetline(line, maxl)) > 0 && nl < maxn){
		if((p = salloc(space)) != NULL){
			strcpy(p, line);
			plar[nl++] = p;
		} else
			break;
	}
	return (nl < 1) ? -1 : nl;
}

int sgetline(char *lin, int maxl)
{
	int c, len;

	len = 0;
	while((c = getchar()) != EOF && c != '\n' && len < maxl-1)
		lin[len++] = c;
	lin[len] = '\0';
	
	return (len < 1) ?  -1 : len+1;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *salloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return 0;
}
