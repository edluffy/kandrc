#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXVAR 100 // max length of variable
#define MAXVARN 1000 // max number of variables

struct tnode {
	char *vname;
	int count;
	struct tnode *left;
	struct tnode *right;
};

char variables[MAXVARN][MAXVAR];

int lsearch(char arr[][], int l, int r, char x[]);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getvar(char *, int);

int main(void)
{
	struct tnode *root;
	char vname[MAXVAR];
	int varn = 0;

	root = NULL;
	while(getvar(vname, MAXVAR) != EOF){
		if(isalpha(vname[0]) && lsearch(variables, 0, varn, vname)){
			root = addtree(root, vname);
			variables[varn++] = vname;
		}
	}
	treeprint(root);
	return 0;

}

int lsearch(char arr[][], int l, int r, char x[])
{
	for(int i = 0; l <= r; i++){
		if(strcmp(arr[i], x)
			return 1;
	}
	return -1;
}

int getvar(char *vname, int maxvr)
{
	int c, getch(void);
	void ungetch(int);
	char *v = vname;

	while(isspace(c = getch()))
		;
	if(c != EOF)
		*v++ = c;
	if(!isalpha(c)){
		*v = '\0';
		return c;
	}

	for( ; --maxvr > 0; v++){
		if(!isalnum(*v = getch())){
			ungetch(*v);
			break;
		}
	}

	*v = '\0';
	return vname[0];

}

int bufc;
int state = 0;
int getch(void)
{
	int c;
	if(state != 0){
		c = bufc;
		state = 0;
	} else
		c = getchar();
	return c;
}

void ungetch(int c)
{
	if(state != 0)
		printf("error: char buffer full");
	else{
		bufc = c;
		state = 1;
	}
}

struct tnode *talloc(void);
char *strdupe(char *);

struct tnode *addtree(struct tnode *p, char *v)
{
	int cond;
	if(p == NULL){ // reached empty node
		p = talloc();
		p->vname = strdup(v);
		p->count = 1;
		p->left = p->right = NULL;
	} else if((cond = strcmp(v, p->vname)) == 0) // var matches current node
		return p;
	else if(cond < 0) // continue down left node
		p->left = addtree(p->left, v);
	else // continue down right node
		p->right = addtree(p->right, v);
	return p;
}

void treeprint(struct tnode *p)
{
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->vname);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupe(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
