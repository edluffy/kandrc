#include <stdio.h>
#include <string.h>

#define MAXNL 5000 // max number of lines to be sorted
#define MAXLL 999 // maximum line length
char *lineptr[MAXNL]; // pointers to lines

void writelines(char *lar[], int nl);
int sreadlines(char *lar[], int maxn, int maxl);
int sgetline(char *plin, int maxl);


void myqsort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(const char *, const char *);

static int numflag, revflag, foldflag;

int main(int argc, char *argv[])
{
	numflag = revflag = foldflag = 0;

	int nlines;
	int nflag = argc;

	while(--nflag){
		if(strcmp(argv[nflag], "-n") == 0)
			numflag = 1;
		else if(strcmp(argv[nflag], "-r") == 0)
			revflag = 1;
		else if(strcmp(argv[nflag], "-f") == 0)
			foldflag = 1;
	}	

	if((nlines = sreadlines(lineptr, MAXNL, MAXLL)) >= 0){
		myqsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*,void*))(numflag ? numcmp : strcmp));
		writelines(lineptr, nlines);
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

void writelines(char *plar[], int nl)
{
	for(int i = 0; nl--; i++)
		printf("%s\n", plar[revflag ? nl : i]);
}

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

#include <ctype.h>
int sgetline(char *lin, int maxl)
{
	int c, len;

	len = 0;
	while((c = getchar()) != EOF && c != '\n' && len < maxl-1){
		if(foldflag)
			if(c >= 'A' && c <= 'Z') c += 'a'-'A';
		lin[len++] = c;
	}
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
