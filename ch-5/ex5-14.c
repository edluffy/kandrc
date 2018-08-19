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
int numcmp(char *, char *);
int mystrcmp(char *, char *);

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
				(int (*)(void*,void*))(numflag ? numcmp : mystrcmp));
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

int mystrcmp(char *s1, char *s2)
{
	int i;
	char buf1[MAXLL];
	char buf2[MAXLL];

	strcpy(buf1, s1);
	strcpy(buf2, s2);

	if(foldflag){
		for(i = 0; buf1[i] != '\0'; i++){
			if(buf1[i] >= 'A' && buf1[i] <= 'Z')
				buf1[i] += ('a' - 'A');
		}
		for(i = 0; buf2[i] != '\0'; i++){
			if(buf2[i] >= 'A' && buf2[i] <= 'Z')
				buf2[i] += ('a' - 'A');
		}
	}

	char *p1 = buf1;
	char *p2 = buf2;
	while(*p1 != '\0'){
		if(*p2 == '\0') return 1;
		if(*p2 > *p1) return -1;
		if(*p1 > *p2) return 1;

		p1++;
		p2++;
	}
	if(*p2 != '\0') return -1;

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
