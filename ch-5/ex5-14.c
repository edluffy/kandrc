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

static int pos, dur, numflag, revflag, foldflag, dirflag;

#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	pos = numflag = revflag = foldflag = dirflag = 0;
	dur = 0;

	int nlines;
	int nflag = argc;
	char bufn[999];
	int i = 0;

	while(--nflag){
		if(isdigit(*argv[nflag])){
			//printf("%i", *argv[nflag] - '0');
			while(isdigit(*argv[nflag]++))
				bufn[i++] = *argv[nflag] - '0';
			bufn[i] = '\0';
			pos = atoi(bufn);
			if(*argv[nflag] == '-')
				argv[nflag]++;
			i = 0;
			while(isdigit(*argv[nflag]++))
				bufn[i++] = *argv[nflag] - '0';
			bufn[i] = '\0';
			dur = atoi(bufn);
			printf("%i", pos);			
		}
		else if(strcmp(argv[nflag], "-n") == 0)
			numflag = 1;
		else if(strcmp(argv[nflag], "-r") == 0)
			revflag = 1;
		else if(strcmp(argv[nflag], "-f") == 0)
			foldflag = 1;
		else if(strcmp(argv[nflag], "-d") == 0)
			dirflag = 1;
	}	

	if((nlines = sreadlines(lineptr, MAXNL, MAXLL)) >= 0){
		myqsort((void **) lineptr+pos, 0, (dur > 0 && dur < nlines-1) ? pos+dur : nlines-1,
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
	int i, ns;
	char buf1[MAXLL], buf2[MAXLL];
	char *ps, *pbuf;

	for(ns = 2; ns > 0; ns--){
		ps = (ns == 2) ? s1 : s2;	
		pbuf = (ns == 2) ? buf1 : buf2;
		
		for(i = 0; *ps != '\0'; i++){
			if(foldflag && *ps >= 'A' && *ps <= 'Z')
				*pbuf++ = *ps++ + ('a' - 'A'); 
			else if(dirflag && !isdigit(*ps) && !isalpha(*ps) && !isblank(*ps))
				ps++;
			else
				*pbuf++ = *ps++;
		}
	}

	for(i = 0; buf1[i] != '\0'; i++){
		if(buf2[i] == '\0') return 1;
		if(buf2[i] > buf1[i]) return -1;
		if(buf1[i] > buf2[i]) return 1;
	}
	if(buf2[i] != '\0') return -1;

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
